/****************************************************************************
**
** Copyright (C) 2007~2011 Colin Willcocks.
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

#include "soundSource.h"
#include "MidiTable.h"
#include "SysxIO.h"
#include "globalVariables.h"
#include "floorBoardDisplay.h"
#include "floorBoard.h"

soundSource::soundSource(QWidget *parent, unsigned int id, QString imagePath, QPoint stompPos)
    : QWidget(parent)
{
    this->id = id;
    this->imagePath = imagePath;
    this->stompSize = QPixmap(":/images/sourceBG.png").size();
    this->stompPos = stompPos;
    this->setFixedSize(stompSize);
    this->editDialog = new editWindow();
    this->setWhatsThis(tr("StompBox effect<br>a double mouse click will open the effect edit page."));

   // this->pathSwitch = new customButton(tr(""), false, QPoint(60, 60), this, ":/images/pathswitch.png");
   // this->pathSwitch->hide();

    QObject::connect(this, SIGNAL( valueChanged(QString, QString, QString) ), this->parent(), SIGNAL( valueChanged(QString, QString, QString) ));

    QObject::connect(this->parent(), SIGNAL( updateStompOffset(signed int) ), this, SLOT( updatePos(signed int) ));

    QObject::connect(this->parent(), SIGNAL( updateSignal() ), this, SLOT( updateSignal() ));

    QObject::connect(this->editDialog, SIGNAL( updateSignal() ), this, SLOT( updateSignal() ));

    QObject::connect(this, SIGNAL( dialogUpdateSignal() ), this->editDialog, SIGNAL( dialogUpdateSignal() ));

    QObject::connect(this->parent(), SIGNAL( updateSignal() ), this->editDialog, SIGNAL( dialogUpdateSignal() ));

    QObject::connect(this->editDialog, SIGNAL( updateSignal() ), this, SLOT( setDisplayToFxName() ));

    QObject::connect(this, SIGNAL( setEditDialog( editWindow*) ), this->parent(), SLOT( setEditDialog(editWindow*) ));

    //QObject::connect(this, SIGNAL( pathUpdateSignal() ), this, SLOT( updateStompPath() ));

    QObject::connect(this, SIGNAL( updateStompBoxes() ), this->parent(), SLOT( updateStompBoxes() ));

   // QObject::connect(this, SIGNAL( switchSignal() ), this->parent(), SIGNAL( updateSignal() ));

    QObject::connect(this->parent(), SIGNAL(modeling_buttonSignal(bool)), this, SLOT(modeling_ButtonSignal(bool) ));
    QObject::connect(this, SIGNAL(modeling_statusSignal(bool)), this->parent(), SIGNAL(modeling_statusSignal(bool)));
    QObject::connect(this->parent(), SIGNAL(modeling_buttonSignal(bool)), this->parent(), SLOT(menuButtonSignal()));

    QObject::connect(this->parent(), SIGNAL(synth1_buttonSignal(bool)), this, SLOT(synth1_ButtonSignal(bool) ));
    QObject::connect(this, SIGNAL(synth1_statusSignal(bool)), this->parent(), SIGNAL(synth1_statusSignal(bool)));
    QObject::connect(this->parent(), SIGNAL(synth1_buttonSignal(bool)), this->parent(), SLOT(menuButtonSignal()));

    QObject::connect(this->parent(), SIGNAL(synth2_buttonSignal(bool)), this, SLOT(synth2_ButtonSignal(bool) ));
    QObject::connect(this, SIGNAL(synth2_statusSignal(bool)), this->parent(), SIGNAL(synth2_statusSignal(bool)));
    QObject::connect(this->parent(), SIGNAL(synth2_buttonSignal(bool)), this->parent(), SLOT(menuButtonSignal()));
};

void soundSource::paintEvent(QPaintEvent *)
{
    setImage(imagePath);
    QPixmap image(imagePath);
    QRectF target(0.0, 0.0, image.width(), image.height());
    QRectF source(0.0, 0.0, image.width(), image.height());


    this->image = image;

    QPainter painter(this);
    painter.drawPixmap(target, image, source);
};

editWindow* soundSource::editDetails()
{
    return this->editDialog;
};

void soundSource::mousePressEvent(QMouseEvent *event)
{
    this->editDialog->setWindow(this->fxName);
    emit setEditDialog(this->editDialog);
};


void soundSource::mouseDoubleClickEvent(QMouseEvent *event)
{

    this->editDialog->setWindow(this->fxName);
    emit setEditDialog(this->editDialog);
};

void soundSource::mouseMoveEvent(QMouseEvent *event)
{

};

void soundSource::modeling_ButtonSignal(bool value)
{
    if (this->id == 1)
    {
        emitValueChanged(this->hex1, this->hex2, "00", "void");
        this->editDialog->setWindow(this->fxName);
        emit setEditDialog(this->editDialog);
    };
};

void soundSource::synth1_ButtonSignal(bool value)
{
    if (this->id == 2)
    {
        emitValueChanged(this->hex1, this->hex2, "00", "void");
        this->editDialog->setWindow(this->fxName);
        emit setEditDialog(this->editDialog);
    };
};

void soundSource::synth2_ButtonSignal(bool value)
{
    if (this->id == 3)
    {
        emitValueChanged(this->hex1, this->hex2, "00", "void");
        this->editDialog->setWindow(this->fxName);
        emit setEditDialog(this->editDialog);
    };
};

void soundSource::setPos(QPoint newPos)
{
    this->move(newPos);
    this->stompPos = newPos;
    updateStompPath();
};

void soundSource::updatePos(signed int offsetDif)
{
    this->stompPos = this->pos();
    QPoint newPos = stompPos + QPoint(offsetDif, 0);
    this->move(newPos);
    this->stompPos = newPos;
};

void soundSource::setImage(QString imagePath)
{
    this->imagePath = imagePath;
    //this->update();
};

void soundSource::setSize(QSize newSize)
{
    this->stompSize = newSize;
    this->setFixedSize(stompSize);
};

void soundSource::setId(unsigned int id)
{
    this->id = id;
};

unsigned int soundSource::getId()
{
    return this->id;
};


void soundSource::setLSB(QString hex1, QString hex2)
{
    this->hex1 = hex1;
    this->hex2 = hex2;
    this->editDialog->setLSB(hex1, hex2);
};

void soundSource::setComboBox(QString hex1, QString hex2, QString hex3, QRect geometry)
{
    QString type = hex2;
    this->hex1 = hex1;
    if (type == "routeSwitch") { this->hex2 = "00"; } else {
        this->hex2 = hex2; };
    this->hex3 = hex3;

    MidiTable *midiTable = MidiTable::Instance();
    Midi items = midiTable->getMidiMap("Structure", hex1, "00", hex3);

    this->stompComboBox = new customComboBox(this);
    this->stompComboBox->setObjectName("smallcombo");

    int itemcount = 0;
    for(itemcount=0;itemcount<items.level.size();itemcount++ )
    {
        QString item;
        QString desc = items.level.at(itemcount).desc;
        QString customdesc = items.level.at(itemcount).customdesc;
        if(!customdesc.isEmpty())
        {
            item = customdesc;
        }
        else
        {
            item = desc;
        };
        this->stompComboBox->addItem(item);
    };

    this->stompComboBox->setGeometry(geometry);
    this->stompComboBox->setEditable(false);
    this->stompComboBox->setFrame(false);
    this->stompComboBox->setMaxVisibleItems(itemcount);

    QObject::connect(this->stompComboBox, SIGNAL(currentIndexChanged(int)),
                     this, SLOT(valueChanged(int)));
    if (type == "routeSwitch") {
        switch3way = new customSwitch3way(0, QPoint(260, 10), this);

        QObject::connect(this->stompComboBox, SIGNAL(currentIndexChanged(int)),
                         switch3way, SLOT(changeValue(int)));
    };

};

void soundSource::setComboBoxCurrentIndex(int index)
{
    this->stompComboBox->setCurrentIndex(index);
};

void soundSource::setKnob1(QString hex1, QString hex2, QString hex3)
{
    MidiTable *midiTable = MidiTable::Instance();
    int range = midiTable->getRange("Structure", hex1, hex2, hex3);
    //knob1 = new customDial(0, 0, range, 1, 10, QPoint(24, 13), this, hex1, hex2, hex3);
    stompDisplay = new customDisplay(QRect(17, 42, 120, 20), this);
    this->stompDisplay->setAllColor(QColor(185,224,243));
};

void soundSource::setKnob2(QString hex1, QString hex2, QString hex3)
{
    MidiTable *midiTable = MidiTable::Instance();
    int range = midiTable->getRange("Structure", hex1, hex2, hex3);
    knob2 = new customDial(0, 0, range, 1, 10, QPoint(213, 13), this, hex1, hex2, hex3);
};

void soundSource::setButton(QString hex1, QString hex2, QString hex3)
{
    button = new customButton(false, QPoint(4, 102), this, hex1, hex2, hex3);
    led = new customLed(false, QPoint(41, 4), this);

    QObject::connect(button, SIGNAL(valueChanged(bool, QString, QString, QString)),
                     led, SLOT(changeValue(bool)));
};

void soundSource::setButton(QString hex1, QString hex2, QString hex3, QPoint pos, QString imagePath)
{
    button = new customButton(false, pos, this, hex1, hex2, hex3, imagePath);
    led = new customLed(false, QPoint(38, 4), this);

    QObject::connect(button, SIGNAL(valueChanged(bool, QString, QString, QString)),
                     led, SLOT(changeValue(bool)));
};

void soundSource::setSwitch(QString hex1, QString hex2, QString hex3)
{
    switchbutton = new customSwitch(false, this, hex1, hex2, hex3);
    switchbutton->move(QPoint(16, 17));
};


void soundSource::updateComboBox(QString hex1, QString hex2, QString hex3)
{
    QObject::disconnect(this->stompComboBox, SIGNAL(currentIndexChanged(int)), // To prevent sending a signal when loading a patch.
                        this, SLOT(valueChanged(int)));
    QString type = hex2;
    if (type == "routeSwitch") {hex2 = "00"; };
    SysxIO *sysxIO = SysxIO::Instance();
    QString area;
    int value = sysxIO->getSourceValue(area, hex1, "00", hex3);
    setComboBoxCurrentIndex(value);
    if (type == "routeSwitch") {
        switch3way->setValue(value);
        switch3way->update(); };

    QObject::connect(this->stompComboBox, SIGNAL(currentIndexChanged(int)),
                     this, SLOT(valueChanged(int)));
};

void soundSource::updateKnob1(QString hex1, QString hex2, QString hex3)
{
    SysxIO *sysxIO = SysxIO::Instance();
    QString area;
    int index = sysxIO->getSourceValue(area, hex1, hex2, hex3);

    //knob1->setValue(index);


    MidiTable *midiTable = MidiTable::Instance();
    QString valueHex = QString::number(index, 16).toUpper();
    if(valueHex.length() < 2) valueHex.prepend("0");
    QString valueStr = midiTable->getValue("Structure", hex1, hex2, hex3, valueHex);
    this->stompDisplay->setMainText(valueStr);
};

void soundSource::updateKnob2(QString hex1, QString hex2, QString hex3)
{
    SysxIO *sysxIO = SysxIO::Instance();
    QString area;
    knob2->setValue(sysxIO->getSourceValue(area, hex1, hex2, hex3));
};

void soundSource::updateButton(QString hex1, QString hex2, QString hex3)
{
    SysxIO *sysxIO = SysxIO::Instance();
    QString area;
    int value = sysxIO->getSourceValue(area, hex1, hex2, hex3);
    led->setValue((value==1)?true:false);
    button->setValue((value==1)?true:false);

};

void soundSource::updateSwitch(QString hex1, QString hex2, QString hex3)
{

    SysxIO *sysxIO = SysxIO::Instance();
    QString area;
    int value = sysxIO->getSourceValue(area, hex1, hex2, hex3);
    switchbutton->setValue((value==1)?true:false);
    bool set = false;
    if (value == 1) {set = true; };
    if(this->id == 1) { emit modeling_statusSignal(set); };
    if(this->id == 2) { emit synth1_statusSignal(set); };
    if(this->id == 3) { emit synth2_statusSignal(set); };
};

void soundSource::updateSwitch3way(QString hex1, QString hex2, QString hex3)
{
    SysxIO *sysxIO = SysxIO::Instance();
    QString area;
    int value = sysxIO->getSourceValue(area, hex1, hex2, hex3);
    switch3way->setValue(value);
    //emit switchSignal();
    //QApplication::beep();
};

void soundSource::valueChanged(int value, QString hex1, QString hex2, QString hex3)
{
    MidiTable *midiTable = MidiTable::Instance();

    QString valueHex = QString::number(value, 16).toUpper();
    if(valueHex.length() < 2) valueHex.prepend("0");

    SysxIO *sysxIO = SysxIO::Instance(); bool ok;
    if(midiTable->isData("Structure", hex1, hex2, hex3))
    {
        int maxRange = QString("7F").toInt(&ok, 16) + 1;
        int value = valueHex.toInt(&ok, 16);
        int dif = value/maxRange;
        QString valueHex1 = QString::number(dif, 16).toUpper();
        if(valueHex1.length() < 2) valueHex1.prepend("0");
        QString valueHex2 = QString::number(value - (dif * maxRange), 16).toUpper();
        if(valueHex2.length() < 2) valueHex2.prepend("0");

        QString area;
        sysxIO->setFileSource(area, hex1, hex2, hex3, valueHex1, valueHex2);
    }
    else
    {
        QString area;
        sysxIO->setFileSource(area, hex1, hex2, hex3, valueHex);
    };

    emitValueChanged(hex1, hex2, hex3, valueHex);
};

void soundSource::valueChanged(bool value, QString hex1, QString hex2, QString hex3)
{
    int valueInt;
    (value)? valueInt=1: valueInt=0;
    QString valueHex = QString::number(valueInt, 16).toUpper();
    if(valueHex.length() < 2) valueHex.prepend("0");

    SysxIO *sysxIO = SysxIO::Instance();
    QString area;
    sysxIO->setFileSource(area, hex1, hex2, hex3, valueHex);

    emitValueChanged(hex1, hex2, hex3, valueHex);
};

void soundSource::valueChanged(int index)
{
    QString valueHex = QString::number(index, 16).toUpper();
    if(valueHex.length() < 2) valueHex.prepend("0");

    SysxIO *sysxIO = SysxIO::Instance();
    QString area;
    sysxIO->setFileSource(area, this->hex1, this->hex2, this->hex3, valueHex);

    emitValueChanged(this->hex1, this->hex2, this->hex3, valueHex);

    MidiTable *midiTable = MidiTable::Instance();
    Midi items = midiTable->getMidiMap("Structure", this->hex1, this->hex2, this->hex3);

    QString desc = items.level.at(index).desc;
    QString customdesc = items.level.at(index).customdesc;
    if(customdesc.isEmpty())
    {
        customdesc = desc;
    };

    this->stompComboBox->setCurrentIndex(index);
    this->stompComboBox->setEditText(desc);

};

void soundSource::emitValueChanged(QString hex1, QString hex2, QString hex3, QString valueHex)
{
    QString valueName, valueStr;
    if(hex1 != "void" && hex2 != "void")
    {
        MidiTable *midiTable = MidiTable::Instance();
        if(valueHex != "void")
        {
            Midi items = midiTable->getMidiMap("Structure", hex1, hex2, hex3);
            valueName = items.desc;
            valueName.append(" " + items.customdesc);
            //this->fxName = midiTable->getMidiMap("Structure", hex1, hex2, hex3).name;
            valueStr = midiTable->getValue("Structure", hex1, hex2, hex3, valueHex);
            emit dialogUpdateSignal();
        };
    };
    emit valueChanged(this->fxName, valueName, valueStr);
};

void soundSource::setDisplayToFxName()
{
    //emit valueChanged(this->fxName, "", "");
};

void soundSource::updateStompPath()
{
    if (this->id == 0) {this->fxName = tr("Analog PickUp");};
    if (this->id == 1) {this->fxName = tr("Modeling");};
    if (this->id == 2) {this->fxName = tr("PCM Synth A");};
    if (this->id == 3) {this->fxName = tr("PCM Synth B");};
};

void soundSource::getStompOrder()
{

};
