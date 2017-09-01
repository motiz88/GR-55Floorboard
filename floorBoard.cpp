/****************************************************************************
**
** Copyright (C) 2007~2016 Colin Willcocks.
** Copyright (C) 2005~2007 Uco Mesdag.
** All rights reserved.
** This file is part of "GR-55 FloorBoard".
**
** This program is free software; you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation; either version 2 of the License, or
** (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License along
** with this program; if not, write to the Free Software Foundation, Inc.,
** 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
**
****************************************************************************/

#include <QList>
#include <QVector>

#include "dragBar.h"
#include "bankTreeList.h"
#include "floorBoardDisplay.h"
#include "floorPanelBar.h"
#include "floorBoard.h"
#include "Preferences.h"
#include "MidiTable.h"
#include "sysxWriter.h"
#include "SysxIO.h"
#include "globalVariables.h"

#include "menuPage_assign1.h"
#include "menuPage_assign2.h"
#include "menuPage_assign3.h"
#include "menuPage_assign4.h"
#include "menuPage_assign5.h"
#include "menuPage_assign6.h"
#include "menuPage_assign7.h"
#include "menuPage_assign8.h"
#include "menuPage_system.h"
#include "menuPage_master.h"
#include "menuPage_pdl.h"
#include "menuPage_EZ_Edit.h"

#include "soundSource_synth_a.h"
#include "soundSource_synth_b.h"

#include "soundSource_analogPU.h"
#include "stompbox_amp.h"
#include "stompbox_mod.h"
#include "stompbox_eq.h"
#include "stompbox_mfx.h"
#include "stompbox_dd.h"
#include "stompbox_ce.h"
#include "stompbox_rv.h"
#include "stompbox_ns.h"

floorBoard::floorBoard(QWidget *parent,
                       QString imagePathFloor,
                       QString imagePathStompBG,
                       unsigned int marginStompBoxesTop,
                       unsigned int marginStompBoxesBottom,
                       unsigned int marginStompBoxesWidth,
                       unsigned int panelBarOffset,
                       unsigned int borderWidth,
                       QPoint pos)
                           : QWidget(parent)
{
    Preferences *preferences = Preferences::Instance();
    bool ok;
    const double ratio = preferences->getPreferences("Window", "Scale", "ratio").toDouble(&ok);

    QString setting = preferences->getPreferences("Scheme", "Colour", "select");
    //bool ok;
    int choice = setting.toInt(&ok, 16);
    if(choice == 4) { imagePathFloor = "images/floor_white.png"; }
    else if(choice == 3) { imagePathFloor = "images/floor_green.png"; }
    else if(choice == 2) { imagePathFloor = "images/floor_aqua.png"; }
    else if(choice == 1) { imagePathFloor = "images/floor_black.png"; }
    else { imagePathFloor = ":images/floor_blue.png"; };
    this->imagePathFloor = imagePathFloor;
    this->imagePathStompBG = imagePathStompBG;

    marginStompBoxesTop = 135*ratio;
    marginStompBoxesBottom = 72*ratio;
    marginStompBoxesWidth = 25*ratio;
    panelBarOffset = 10*ratio;
    borderWidth = 3*ratio;

    this->marginStompBoxesTop = marginStompBoxesTop;
    this->marginStompBoxesBottom = marginStompBoxesBottom;
    this->marginStompBoxesWidth = marginStompBoxesWidth;
    this->panelBarOffset = panelBarOffset;
    this->borderWidth = borderWidth;
    this->pos = pos;

    bankTreeList *bankList = new bankTreeList(this);

    setFloorBoard();

    floorBoardDisplay *display = new floorBoardDisplay(this);
    display->setPos(displayPos);

    floorPanelBar *panelBar = new floorPanelBar(this);
    panelBar->setPos(panelBarPos);

    dragBar *bar = new dragBar(this);
    bar->setDragBarSize(QSize(4*ratio, panelBar->height()*ratio ));
    bar->setDragBarMinOffset(2*ratio, 8*ratio);
    bar->setDragBarMaxOffset(offset - panelBarOffset + (5*ratio));

    initSoundSource();
    initStomps();
    initMenuPages();

    this->editDialog = new editWindow(this);
    this->editDialog->hide();
    this->oldDialog = this->editDialog;
    //QObject::connect(this, SIGNAL( pageUpdateSignal() ), this->editDialog, SIGNAL(  update() ));
     SysxIO *sysxIO = SysxIO::Instance();
    QObject::connect(sysxIO, SIGNAL(updateSignal()), this, SIGNAL(updateSignal()));

    QObject::connect(this, SIGNAL( resizeSignal(QRect) ), bankList, SLOT( updateSize(QRect) ) );
    QObject::connect(display, SIGNAL(connectedSignal()), bankList, SLOT(connectedSignal()));
    QObject::connect(this, SIGNAL(valueChanged(QString, QString, QString)), display, SLOT(setValueDisplay(QString, QString, QString)));
    QObject::connect(panelBar, SIGNAL(resizeSignal(int)), this, SLOT(setWidth(int)));
    QObject::connect(panelBar, SIGNAL(collapseSignal()), this, SLOT(setCollapse()));
    QObject::connect(this, SIGNAL(setCollapseState(bool)), panelBar, SIGNAL(collapseState(bool)));
    QObject::connect(this, SIGNAL(setDisplayPos(QPoint)), display, SLOT(setPos(QPoint)));
    QObject::connect(this, SIGNAL(setFloorPanelBarPos(QPoint)), panelBar, SLOT(setPos(QPoint)));
    QObject::connect(this->parent(), SIGNAL(updateSignal()), this, SIGNAL(updateSignal()));
    QObject::connect(this, SIGNAL(updateSignal()), this, SLOT(updateStompBoxes()));
    QObject::connect(this, SIGNAL(updateSignal()), this, SLOT(update_structure()));
    QObject::connect(this, SIGNAL(updateSignal()), bankList, SLOT(updateTreeMode()));
    QObject::connect(bankList, SIGNAL(patchSelectSignal(int, int)), display, SLOT(patchSelectSignal(int, int)));
    QObject::connect(bankList, SIGNAL(patchLoadSignal(int, int)), display, SLOT(patchLoadSignal(int, int)));
    QObject::connect(panelBar, SIGNAL(showDragBar(QPoint)), this, SIGNAL(showDragBar(QPoint)));
    QObject::connect(panelBar, SIGNAL(hideDragBar()), this, SIGNAL(hideDragBar()));
    QObject::connect(this, SIGNAL(notConnected()), display, SLOT(notConnected()));

    QString collapseState = preferences->getPreferences("Window", "Collapsed", "bool");
    QString width = preferences->getPreferences("Window", "Collapsed", "width");
    QString defaultwidth = preferences->getPreferences("Window", "Collapsed", "defaultwidth");
    if(width.isEmpty()){ width = defaultwidth; }

    this->l_floorSize = QSize(width.toInt(&ok, 10), floorSize.height());

    if(preferences->getPreferences("Window", "Restore", "sidepanel")=="true")
    {
        if(collapseState=="true")
        {
            this->setSize(l_floorSize);
            this->colapseState = true;
            emit setCollapseState(true);
        }
        else
        {
            this->setSize(minSize);
            this->colapseState = false;
            emit setCollapseState(false);
        };
    }
    else
    {
        this->setSize(minSize);
        this->colapseState = false;
        emit setCollapseState(false);
    };

    emit updateSignal();
}

floorBoard::~floorBoard()
{
    emit notConnected();
    Preferences *preferences = Preferences::Instance();
    if(preferences->getPreferences("Window", "Restore", "sidepanel")=="true")
    {
        preferences->setPreferences("Window", "Collapsed", "width", QString::number(this->l_floorSize.width(), 10));
    }
    else
    {
        preferences->setPreferences("Window", "Collapsed", "width", "");
    };
    preferences->setPreferences("Window", "Collapsed", "bool", QString(this->colapseState?"true":"false"));
    preferences->savePreferences();
}

void floorBoard::paintEvent(QPaintEvent *)
{
    Preferences *preferences = Preferences::Instance();
    bool ok;
    const double ratio = preferences->getPreferences("Window", "Scale", "ratio").toDouble(&ok);

    QRectF target(pos.x(), pos.y(), floorSize.width()*ratio, floorSize.height()*ratio);
    QRectF source(0.0, 0.0, floorSize.width(), floorSize.height());

    QPainter painter(this);
    painter.drawPixmap(target, image, source);
    //this->setAcceptDrops(true);
}

void floorBoard::setFloorBoard() {

    Preferences *preferences = Preferences::Instance();
    bool ok;
    const double ratio = preferences->getPreferences("Window", "Scale", "ratio").toDouble(&ok);

    QPixmap imageFloor(imagePathFloor);
    QPixmap imagestompBG(imagePathStompBG);
    QPixmap buffer = imageFloor;
    QPainter painter(&buffer);

    this->offset = imageFloor.width()*ratio - (997*ratio);
    this->structureWidth = 997*ratio;
    this->stompSize = imagestompBG.size()*ratio;
    this->structureHeight = 44*ratio;

    initSize(imageFloor.size());
    this->maxSize = floorSize;
    this->minSize = QSize(997 + borderWidth + panelBarOffset, imageFloor.height());

    // Draw Structure 2
    structure_state = false;
    this->structure_2 = new customStructure(structure_state, QPoint(0, 0), this);
    this->structure_2->move(offset + (132*ratio), 144*ratio);
    QObject::connect(this, SIGNAL( structure_1_buttonSignal(bool)), this, SLOT( structure(bool) ) );
    QObject::connect(this, SIGNAL( structure_2_buttonSignal(bool)), this, SLOT( structure(bool) ) );

    painter.end();

    this->baseImage = buffer;
    this->image = buffer;
    this->floorHeight = imageFloor.height()*ratio;

    QPoint newPanelBarPos = QPoint(offset - panelBarOffset, borderWidth);
    this->panelBarPos = newPanelBarPos;

    QPoint newDisplayPos = QPoint(offset, 0);
    this->displayPos = newDisplayPos;

    QRect newBankListRect = QRect(borderWidth, borderWidth, offset - panelBarOffset - (borderWidth*2), floorHeight - (borderWidth*2));
    emit resizeSignal(newBankListRect);
}

void floorBoard::initSize(QSize floorSize)
{
    this->floorSize = floorSize;
    this->l_floorSize = floorSize;
    //this->setFixedSize(floorSize);
}

QPoint floorBoard::getStompPos(int id)
{
    return QPoint(0.0, 0.0);
}

void floorBoard::setCollapse()
{
    if(floorSize.width() > minSize.width())
    {
        this->l_floorSize = floorSize;
        this->setSize(minSize);
        this->colapseState = false;
        emit setCollapseState(false);
    }
    else
    {
        this->setSize(l_floorSize);
        emit setCollapseState(true);
        this->colapseState = true;
    };
}

void floorBoard::setSize(QSize newSize)
{
    Preferences *preferences = Preferences::Instance();
    bool ok;
    const double ratio = preferences->getPreferences("Window", "Scale", "ratio").toDouble(&ok);

    unsigned int oldOffset = offset;
    this->offset = newSize.width()*ratio - (997*ratio);
    QSize oldFloorSize = this->floorSize;
    this->floorSize = newSize;

    for(int i=0;i<fxPos.size();i++)
    {
        fxPos[i] = fxPos[i] + QPoint(offset - oldOffset, 0);
    };
    emit updateStompOffset(offset - oldOffset);

    QPoint newPanelBarPos = QPoint(offset - panelBarOffset, panelBarPos.y());
    emit setFloorPanelBarPos(newPanelBarPos);
    this->panelBarPos = newPanelBarPos;

    QPoint newDisplayPos = QPoint(offset, displayPos.y());
    emit setDisplayPos(newDisplayPos);
    this->displayPos = newDisplayPos;

    QPixmap buffer = QPixmap(floorSize);
    QPainter painter(&buffer);

    // Redraw new resized floor
    QRectF source(maxSize.width() - floorSize.width(), 0.0, floorSize.width(), floorSize.height());
    QRectF target(0.0, 0.0, floorSize.width(), floorSize.height());
    painter.drawPixmap(target, baseImage, source);

    painter.end();

    this->image = buffer;
    //this->setFixedSize(floorSize);

    QRect newBankListRect = QRect(borderWidth, borderWidth, offset - panelBarOffset - (borderWidth*2), floorHeight - (borderWidth*2));
    emit resizeSignal(newBankListRect);

    emit sizeChanged(floorSize, oldFloorSize);
    this->centerEditDialog();
    update_structure();
}

void floorBoard::setWidth(int dist)
{
    QSize newSize;
    if(floorSize.width() + dist < minSize.width())
    {
        newSize = minSize;
        this->colapseState = false;
        emit setCollapseState(false);
    }
    else if(floorSize.width() + dist > maxSize.width())
    {
        newSize = maxSize;
        this->l_floorSize = newSize;
        this->colapseState = true;
        emit setCollapseState(true);
    }
    else
    {
        newSize = QSize(floorSize.width() + dist, floorSize.height());
        this->l_floorSize = newSize;
        this->colapseState = true;
        emit setCollapseState(true);
    };
    this->setSize(newSize);
}


void floorBoard::initSoundSource()
{
    Preferences *preferences = Preferences::Instance();
    bool ok;
    const double ratio = preferences->getPreferences("Window", "Scale", "ratio").toDouble(&ok);


    QVector<soundSource *> initSoundSources(5);
    this->soundSources = initSoundSources.toList();;

    //Analog Pick Up
    soundSource *analogPU = new soundsource_analogPU(this);
    analogPU->setId(0);
    analogPU->setPos(QPoint(offset+(20*ratio), 480*ratio));

    //Guitar Modeling
    this->modeling = new soundsource_modeling(this);
    modeling->setId(1);
    modeling->setPos(QPoint(offset+(20*ratio), 370*ratio));

    //Bass Modeling
    this->modeling_bass = new soundsource_modeling_bass(this);
    modeling_bass->setId(25);
    modeling_bass->setPos(QPoint(offset+(20*ratio), 370*ratio));
    modeling_bass->hide();

    //Synth A
    soundSource *synth_a = new soundsource_synth_a(this);
    synth_a->setId(2);
    synth_a->setPos(QPoint(offset+(20*ratio), 150*ratio));

    //Synth B
    soundSource *synth_b = new soundsource_synth_b(this);
    synth_b->setId(3);
    synth_b->setPos(QPoint(offset+(20*ratio), 260*ratio));

}

void floorBoard::initStomps()
{

    Preferences *preferences = Preferences::Instance();
    bool ok;
    const double ratio = preferences->getPreferences("Window", "Scale", "ratio").toDouble(&ok);

    QList<signed int> fx;
    fx << 0 << 1 << 2 << 3 << 4 << 5 << 6 << 7;
    this->fx = fx;

    //Amp
    stompBox *amp = new stompbox_amp(this);
    amp->setId(4);
    amp->setPos(QPoint(offset + (370*ratio), 410*ratio));

    //Noise suppressor
    stompBox *ns = new stompbox_ns(this);
    ns->setId(5);
    ns->setPos(QPoint(offset + (516*ratio), 410*ratio));

    //MOD
    stompBox *mod = new stompbox_mod(this);
    mod->setId(6);
    mod->setPos(QPoint(offset + (663*ratio), 410*ratio));

    //MFX
    stompBox *mfx = new stompbox_mfx(this);
    mfx->setId(7);
    mfx->setPos(QPoint(offset + (370*ratio), 180*ratio));

    //Chorus
    stompBox *ce = new stompbox_ce(this);
    ce->setId(8);
    ce->setPos(QPoint(offset + (695*ratio), 180*ratio));

    //Reverb
    stompBox *rv = new stompbox_rv(this);
    rv->setId(9);
    rv->setPos(QPoint(offset + (840*ratio), 180*ratio));

    // Delay
    stompBox *dd = new stompbox_dd(this);
    dd->setId(10);
    dd->setPos(QPoint(offset + (550*ratio), 180*ratio));

    //Equalizer
    stompBox *eq = new stompbox_eq(this);
    eq->setId(11);
    eq->setPos(QPoint(offset + (840*ratio), 410*ratio));

}

void floorBoard::updateStompBoxes()
{

}

void floorBoard::setEditDialog(editWindow* editDialog)
{
    this->oldDialog = this->editDialog;
    this->editDialog = editDialog;
    this->editDialog->setParent(this);
    Preferences *preferences = Preferences::Instance();
    if(preferences->getPreferences("Window", "Single", "bool")!="true")
    {
        this->editDialog->setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
        //this->editDialog->setStyleSheet(styleSheet);
    };
    this->centerEditDialog();
    this->editDialog->pageUpdateSignal();
    this->editDialog->show();
}

void floorBoard::centerEditDialog()
{
    Preferences *preferences = Preferences::Instance();
    bool ok;
    const double ratio = preferences->getPreferences("Window", "Scale", "ratio").toDouble(&ok);

    //Preferences *preferences = Preferences::Instance();
    if(preferences->getPreferences("Window", "Single", "bool")=="true")
    {
    int x = this->displayPos.x() + (((this->floorSize.width()*ratio - this->displayPos.x()) - this->editDialog->width()) / 2);
        int y = this->pos.y() + ((((this->floorSize.height()*ratio) + (40*ratio)) - this->editDialog->height()) / 2);
        this->editDialog->move(x, y);
    };
}

void floorBoard::initMenuPages()
{
    QVector<menuPage *> initMenuPages(11);
    this->menuPages = initMenuPages.toList();;

    /* MENU_PAGES */  
    menuPage *ez_edit = new menuPage_ez_edit(this);
    ez_edit->setId(23);
    
    menuPage *assign8 = new menuPage_assign8(this);
    assign8->setId(22);

    menuPage *assign7 = new menuPage_assign7(this);
    assign7->setId(21);

    menuPage *assign6 = new menuPage_assign6(this);
    assign6->setId(20);

    menuPage *assign5 = new menuPage_assign5(this);
    assign5->setId(19);

    menuPage *assign4 = new menuPage_assign4(this);
    assign4->setId(18);

    menuPage *assign3 = new menuPage_assign3(this);
    assign3->setId(17);

    menuPage *assign2 = new menuPage_assign2(this);
    assign2->setId(16);

    menuPage *assign1 = new menuPage_assign1(this);
    assign1->setId(15);

    menuPage *pdl = new menuPage_pdl(this);
    pdl->setId(12);

    menuPage *master = new menuPage_master(this);
    master->setId(13);

    menuPage *system = new menuPage_system(this);
    system->setId(14);

}

void floorBoard::menuButtonSignal()
{
    Preferences *preferences = Preferences::Instance();
    if(preferences->getPreferences("Window", "Single", "bool")=="true")
    { this->oldDialog->hide();
    this->editDialog->show();};
}

void floorBoard::structure(bool value)
{
    SysxIO *sysxIO = SysxIO::Instance();
        if(structure_state == false)
        { sysxIO->setFileSource("Structure", "02", "00", "2C", "01");
            structure_state = true;
            emit valueChanged("Structure", "Structure", "2");
            emit structure_2_statusSignal(true);
            emit structure_1_statusSignal(false);
        }
        else
        {sysxIO->setFileSource("Structure", "02", "00", "2C", "00");
            structure_state = false;
            emit valueChanged("Structure", "Structure", "1");
            emit structure_1_statusSignal(true);
            emit structure_2_statusSignal(false);
        };
   update_structure();
}

void floorBoard::update_structure()
{
    Preferences *preferences = Preferences::Instance();
    bool ok;
    const double ratio = preferences->getPreferences("Window", "Scale", "ratio").toDouble(&ok);

    this->structure_2->move(offset + (421*ratio), 144*ratio);
    SysxIO *sysxIO = SysxIO::Instance();
    int value2 = sysxIO->getSourceValue("Structure", "02", "00", "2C");
    this->structure_2->changeValue((value2==0)?true:false);
    emit structure_1_statusSignal((value2==1)?true:false);
    emit structure_2_statusSignal((value2==1)?false:true);
    value2 = sysxIO->getSourceValue("Structure", "00", "00", "00");
    if(value2 == 0)
    {
    emit valueChanged("Modeling", "Mode", "Guitar");
    modeling_bass->setId(25);
    modeling->setId(1);
    modeling_bass->hide();
    modeling->show();
    } else {
    emit valueChanged("Modeling", "Mode", "Bass");
    modeling_bass->setId(1);
    modeling->setId(25);
    modeling_bass->show();
    modeling->hide();
    };
}

