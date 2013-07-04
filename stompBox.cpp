/****************************************************************************
**
** Copyright (C) 2007~2013 Colin Willcocks.
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

#include "stompBox.h"
#include "MidiTable.h"
#include "SysxIO.h"
#include "globalVariables.h"
#include "floorBoardDisplay.h"
#include "floorBoard.h"

stompBox::stompBox(QWidget *parent, unsigned int id, QString imagePath, QPoint stompPos)
    : QWidget(parent)
{
    this->id = id;
    this->imagePath = imagePath;
    this->stompSize = QPixmap(":/images/stompbg.png").size();
    this->stompPos = stompPos;
    this->setFixedSize(stompSize);
    this->editDialog = new editWindow();
    this->setWhatsThis(tr("StompBox effect<br>a double mouse click will open the effect edit page."));

    QObject::connect(this, SIGNAL( valueChanged(QString, QString, QString) ), this->parent(), SIGNAL( valueChanged(QString, QString, QString) ));

    QObject::connect(this->parent(), SIGNAL( updateStompOffset(signed int) ), this, SLOT( updatePos(signed int) ));

    QObject::connect(this->parent(), SIGNAL( updateSignal() ), this, SLOT( updateSignal() ));

    QObject::connect(this->editDialog, SIGNAL( updateSignal() ), this, SLOT( updateSignal() ));

    QObject::connect(this, SIGNAL( dialogUpdateSignal() ), this->editDialog, SIGNAL( dialogUpdateSignal() ));

    QObject::connect(this->parent(), SIGNAL( updateSignal() ), this->editDialog, SIGNAL( dialogUpdateSignal() ));

    QObject::connect(this->editDialog, SIGNAL( updateSignal() ), this, SLOT( setDisplayToFxName() ));

    QObject::connect(this, SIGNAL( setEditDialog( editWindow*) ), this->parent(), SLOT( setEditDialog(editWindow*) ));

    //QObject::connect(this->editDialog, SIGNAL( pageUpdateSignal(QString) ), this, SLOT( pageUpdateSignal(QString) ));
    //QObject::connect(this, SIGNAL( pageUpdateSignal() ), this->parent(), SIGNAL( pageUpdateSignal() ));

    QObject::connect(this->parent(), SIGNAL(amp_buttonSignal(bool)), this, SLOT(amp_ButtonSignal(bool) ));
    QObject::connect(this, SIGNAL(amp_statusSignal(bool)), this->parent(), SIGNAL(amp_statusSignal(bool)));
    QObject::connect(this->parent(), SIGNAL(amp_buttonSignal(bool)), this->parent(), SLOT(menuButtonSignal()));

    QObject::connect(this->parent(), SIGNAL(ns1_buttonSignal(bool)), this, SLOT(ns1_ButtonSignal(bool) ));
    QObject::connect(this, SIGNAL(ns1_statusSignal(bool)), this->parent(), SIGNAL(ns1_statusSignal(bool)));
    QObject::connect(this->parent(), SIGNAL(ns1_buttonSignal(bool)), this->parent(), SLOT(menuButtonSignal()));

    QObject::connect(this->parent(), SIGNAL(mod_buttonSignal(bool)), this, SLOT(mod_ButtonSignal(bool) ));
    QObject::connect(this, SIGNAL(mod_statusSignal(bool)), this->parent(), SIGNAL(mod_statusSignal(bool)));
    QObject::connect(this->parent(), SIGNAL(mod_buttonSignal(bool)), this->parent(), SLOT(menuButtonSignal()));

    QObject::connect(this->parent(), SIGNAL(mfx_buttonSignal(bool)), this, SLOT(mfx_ButtonSignal(bool) ));
    QObject::connect(this, SIGNAL(mfx_statusSignal(bool)), this->parent(), SIGNAL(mfx_statusSignal(bool)));
    QObject::connect(this->parent(), SIGNAL(mfx_buttonSignal(bool)), this->parent(), SLOT(menuButtonSignal()));

    QObject::connect(this->parent(), SIGNAL(reverb_buttonSignal(bool)), this, SLOT(reverb_ButtonSignal(bool) ));
    QObject::connect(this, SIGNAL(reverb_statusSignal(bool)), this->parent(), SIGNAL(reverb_statusSignal(bool)));
    QObject::connect(this->parent(), SIGNAL(reverb_buttonSignal(bool)), this->parent(), SLOT(menuButtonSignal()));

    QObject::connect(this->parent(), SIGNAL(delay_buttonSignal(bool)), this, SLOT(delay_ButtonSignal(bool) ));
    QObject::connect(this, SIGNAL(delay_statusSignal(bool)), this->parent(), SIGNAL(delay_statusSignal(bool)));
    QObject::connect(this->parent(), SIGNAL(delay_buttonSignal(bool)), this->parent(), SLOT(menuButtonSignal()));

    QObject::connect(this->parent(), SIGNAL(chorus_buttonSignal(bool)), this, SLOT(chorus_ButtonSignal(bool) ));
    QObject::connect(this, SIGNAL(chorus_statusSignal(bool)), this->parent(), SIGNAL(chorus_statusSignal(bool)));
    QObject::connect(this->parent(), SIGNAL(chorus_buttonSignal(bool)), this->parent(), SLOT(menuButtonSignal()));

    QObject::connect(this->parent(), SIGNAL(eq_buttonSignal(bool)), this, SLOT(eq_ButtonSignal(bool) ));
    QObject::connect(this, SIGNAL(eq_statusSignal(bool)), this->parent(), SIGNAL(eq_statusSignal(bool)));
    QObject::connect(this->parent(), SIGNAL(eq_buttonSignal(bool)), this->parent(), SLOT(menuButtonSignal()));
}

void stompBox::paintEvent(QPaintEvent *)
{
    //QRectF target(0.0, 0.0, stompSize.width(), stompSize.height());
    //QRectF source(0.0, 0.0, stompSize.width(), stompSize.height());
    setImage(imagePath);
    QPixmap image(imagePath);
    QRectF target(0.0, 0.0, image.width(), image.height());
    QRectF source(0.0, 0.0, image.width(), image.height());
    this->image = image;
    QPainter painter(this);
    painter.drawPixmap(target, image, source);
}

editWindow* stompBox::editDetails()
{
    return this->editDialog;
}

void stompBox::mousePressEvent(QMouseEvent *event)
{
    this->editDialog->setWindow(this->fxName);
    emit setEditDialog(this->editDialog);
}

void stompBox::mouseDoubleClickEvent(QMouseEvent *event)
{

    this->editDialog->setWindow(this->fxName);
    emit setEditDialog(this->editDialog);
}

void stompBox::mouseMoveEvent(QMouseEvent *event)
{

}

void stompBox::amp_ButtonSignal(bool value)
{
    if (this->id == 4)
    {
        this->editDialog->setWindow(this->fxName);
        emit setEditDialog(this->editDialog);
    };
}

void stompBox::ns1_ButtonSignal(bool value)
{
    if (this->id == 5)
    {
        this->editDialog->setWindow(this->fxName);
        emit setEditDialog(this->editDialog);
    };
}

void stompBox::mod_ButtonSignal(bool value)
{
    if (this->id == 6)
    {
        this->editDialog->setWindow(this->fxName);
        emit setEditDialog(this->editDialog);
    };
}

void stompBox::mfx_ButtonSignal(bool value)
{
    if (this->id == 7)
    {
        this->editDialog->setWindow(this->fxName);
        emit setEditDialog(this->editDialog);
    };
}

void stompBox::reverb_ButtonSignal(bool value)
{
    if (this->id == 9)
    {
        this->editDialog->setWindow(this->fxName);
        emit setEditDialog(this->editDialog);
    };
}

void stompBox::delay_ButtonSignal(bool value)
{
    if (this->id == 10)
    {
        this->editDialog->setWindow(this->fxName);
        emit setEditDialog(this->editDialog);
    };
}

void stompBox::chorus_ButtonSignal(bool value)
{
    if (this->id == 8)
    {
        this->editDialog->setWindow(this->fxName);
        emit setEditDialog(this->editDialog);
    };
}

void stompBox::eq_ButtonSignal(bool value)
{
    if (this->id == 11)
    {
        this->editDialog->setWindow(this->fxName);
        emit setEditDialog(this->editDialog);
    };
}

void stompBox::setPos(QPoint newPos)
{
    this->move(newPos);
    this->stompPos = newPos;
    updateStompPath();
}

void stompBox::updatePos(signed int offsetDif)
{
    this->stompPos = this->pos();
    QPoint newPos = stompPos + QPoint(offsetDif, 0);
    this->move(newPos);
    this->stompPos = newPos;
}

void stompBox::setImage(QString imagePath)
{
    this->imagePath = imagePath;
}

void stompBox::setSize(QSize newSize)
{
    this->stompSize = newSize;
    this->setFixedSize(stompSize);
}

void stompBox::setId(unsigned int id)
{
    this->id = id;
}

unsigned int stompBox::getId()
{
    return this->id;
}

void stompBox::setLSB(QString hex1, QString hex2)
{
    this->editDialog->setLSB(hex1, hex2);
}

void stompBox::setComboBox(QString hex1, QString hex2, QString hex3, QRect geometry)
{
    this->combo_hex1 = hex1;
    this->combo_hex2 = hex2;
    this->combo_hex3 = hex3;

    MidiTable *midiTable = MidiTable::Instance();
    Midi items = midiTable->getMidiMap("Structure", this->combo_hex1, this->combo_hex2, this->combo_hex3);

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

    QObject::connect(this->stompComboBox, SIGNAL(highlighted(int)),
                     this, SLOT(valueChanged(int)));
}

void stompBox::setComboBoxCurrentIndex(int index)
{
    this->stompComboBox->setCurrentIndex(index);
}

void stompBox::setKnob1(QString hex1, QString hex2, QString hex3)
{
    MidiTable *midiTable = MidiTable::Instance();
    if(hex2 == "CENTER") {
        hex2 = "00";
        int range = midiTable->getRange("Structure", hex1, hex2, hex3);
        knob1 = new customDial(0, 0, range, 1, 10, QPoint(47, 69), this, hex1, hex2, hex3);
    } else {
        int range = midiTable->getRange("Structure", hex1, hex2, hex3);
        knob1 = new customDial(0, 0, range, 1, 10, QPoint(19, 69), this, hex1, hex2, hex3);
    };
    this->knob1->setWhatsThis(tr("hold down mouse button and drag up/down for quick adjustment")
                              + "<br>" + tr("use scroll wheel or up/down arrow keys for fine adjustment"));
}

void stompBox::setKnob2(QString hex1, QString hex2, QString hex3)
{
    MidiTable *midiTable = MidiTable::Instance();
    int range = midiTable->getRange("Structure", hex1, hex2, hex3);
    knob2 = new customDial(0, 0, range, 1, 10, QPoint(71, 69), this, hex1, hex2, hex3);
    this->knob2->setWhatsThis(tr("hold down mouse button and drag up/down for quick adjustment")
                              + "<br>" + tr("use scroll wheel or up/down arrow keys for fine adjustment"));
}

void stompBox::setSlider1(QString hex1, QString hex2, QString hex3)
{
    MidiTable *midiTable = MidiTable::Instance();
    int range = midiTable->getRange("Structure", hex1, hex2, hex3);
    slider1 = new customSlider(0, 0, range, 1, 10, QPoint(15, 70), this, hex1, hex2, hex3);
}

void stompBox::setSlider2(QString hex1, QString hex2, QString hex3)
{
    MidiTable *midiTable = MidiTable::Instance();
    int range = midiTable->getRange("Structure", hex1, hex2, hex3);
    slider2 = new customSlider(0, 0, range, 1, 10, QPoint(35, 70), this, hex1, hex2, hex3);
}

void stompBox::setSlider3(QString hex1, QString hex2, QString hex3)
{
    MidiTable *midiTable = MidiTable::Instance();
    int range = midiTable->getRange("Structure", hex1, hex2, hex3);
    slider3 = new customSlider(0, 0, range, 1, 10, QPoint(55, 70), this, hex1, hex2, hex3);
}

void stompBox::setSlider4(QString hex1, QString hex2, QString hex3)
{
    MidiTable *midiTable = MidiTable::Instance();
    int range = midiTable->getRange("Structure", hex1, hex2, hex3);
    slider4 = new customSlider(0, 0, range, 1, 10, QPoint(75, 70), this, hex1, hex2, hex3);
}

void stompBox::setSlider5(QString hex1, QString hex2, QString hex3)
{
    MidiTable *midiTable = MidiTable::Instance();
    int range = midiTable->getRange("Structure", hex1, hex2, hex3);
    slider5 = new customSlider(0, 0, range, 1, 10, QPoint(103, 70), this, hex1, hex2, hex3);
}

void stompBox::setButton(QString hex1, QString hex2, QString hex3)
{
    button = new customButton(false, QPoint(4, 110), this, hex1, hex2, hex3);
    led = new customLed(false, QPoint(41, 4), this);

    QObject::connect(button, SIGNAL(valueChanged(bool, QString, QString, QString)),
                     led, SLOT(changeValue(bool)));
}

void stompBox::setButton(QString hex1, QString hex2, QString hex3, QPoint pos, QString imagePath)
{
    button = new customButton(false, pos, this, hex1, hex2, hex3, imagePath);
    led = new customLed(false, QPoint(41, 4), this);

    QObject::connect(button, SIGNAL(valueChanged(bool, QString, QString, QString)),
                     led, SLOT(changeValue(bool)));
}

void stompBox::setSwitch(QString hex1, QString hex2, QString hex3)
{
    switchbutton = new customSwitch(false, this, hex1, hex2, hex3);
    switchbutton->move(QPoint(9, 12));
}

void stompBox::updateComboBox(QString hex1, QString hex2, QString hex3)
{
    QObject::disconnect(this->stompComboBox, SIGNAL(currentIndexChanged(int)), // To prevent sending a signal when loading a patch.
                        this, SLOT(valueChanged(int)));

    SysxIO *sysxIO = SysxIO::Instance();
    setComboBoxCurrentIndex(sysxIO->getSourceValue("Structure", this->combo_hex1, this->combo_hex2, this->combo_hex3));
    QObject::connect(this->stompComboBox, SIGNAL(currentIndexChanged(int)),
                     this, SLOT(valueChanged(int)));
}

void stompBox::updateKnob1(QString hex1, QString hex2, QString hex3)
{
    SysxIO *sysxIO = SysxIO::Instance();
    knob1->setValue(sysxIO->getSourceValue("Structure", hex1, hex2, hex3));
}

void stompBox::updateKnob2(QString hex1, QString hex2, QString hex3)
{
    SysxIO *sysxIO = SysxIO::Instance();
    QString area;
    knob2->setValue(sysxIO->getSourceValue(area, hex1, hex2, hex3));
}

void stompBox::updateSlider1(QString hex1, QString hex2, QString hex3)
{
    SysxIO *sysxIO = SysxIO::Instance();
    QString area;
    slider1->setValue(sysxIO->getSourceValue(area, hex1, hex2, hex3));
}

void stompBox::updateSlider2(QString hex1, QString hex2, QString hex3)
{
    SysxIO *sysxIO = SysxIO::Instance();
    QString area;
    slider2->setValue(sysxIO->getSourceValue(area, hex1, hex2, hex3));
}

void stompBox::updateSlider3(QString hex1, QString hex2, QString hex3)
{
    SysxIO *sysxIO = SysxIO::Instance();
    QString area;
    slider3->setValue(sysxIO->getSourceValue(area, hex1, hex2, hex3));
}

void stompBox::updateSlider4(QString hex1, QString hex2, QString hex3)
{
    SysxIO *sysxIO = SysxIO::Instance();
    QString area;
    slider4->setValue(sysxIO->getSourceValue(area, hex1, hex2, hex3));
}

void stompBox::updateSlider5(QString hex1, QString hex2, QString hex3)
{
    SysxIO *sysxIO = SysxIO::Instance();
    QString area;
    slider5->setValue(sysxIO->getSourceValue(area, hex1, hex2, hex3));
}

void stompBox::updateButton(QString hex1, QString hex2, QString hex3)
{
    SysxIO *sysxIO = SysxIO::Instance();
    QString area;
    int value = sysxIO->getSourceValue(area, hex1, hex2, hex3);
    led->setValue((value==1)?true:false);
    button->setValue((value==1)?true:false);
}

void stompBox::updateSwitch(QString hex1, QString hex2, QString hex3)
{
    SysxIO *sysxIO = SysxIO::Instance();
    QString area;
    int value = sysxIO->getSourceValue(area, hex1, hex2, hex3);
    this->switchbutton->setValue((value==1)?true:false);
    bool set = false;
    if (value > 0) {set = true; };
    if (this->id == 4) { emit amp_statusSignal(set); };
    if (this->id == 5) { emit ns1_statusSignal(set); };
    if (this->id == 6) { emit mod_statusSignal(set); };
    if (this->id == 7) { emit mfx_statusSignal(set); };
    if (this->id == 8) { emit chorus_statusSignal(set); };
    if (this->id == 9) { emit reverb_statusSignal(set); };
    if (this->id == 10){ emit delay_statusSignal(set); };
    if (this->id == 11){ emit eq_statusSignal(set); };
}

void stompBox::valueChanged(int value, QString hex1, QString hex2, QString hex3)
{
    QString valueHex = QString::number(value, 16).toUpper();
    if(valueHex.length() < 2) valueHex.prepend("0");
    emitValueChanged(hex1, hex2, hex3, valueHex);
}

void stompBox::valueChanged(bool value, QString hex1, QString hex2, QString hex3)
{
    int valueInt;
    (value)? valueInt=1: valueInt=0;
    QString valueHex = QString::number(valueInt, 16).toUpper();
    if(valueHex.length() < 2) valueHex.prepend("0");
    emitValueChanged(hex1, hex2, hex3, valueHex);
}

void stompBox::valueChanged(int index)
{
    QString valueHex = QString::number(index, 16).toUpper();
    if(valueHex.length() < 2) valueHex.prepend("0");
    emitValueChanged(this->combo_hex1, this->combo_hex2, this->combo_hex3, valueHex);

    MidiTable *midiTable = MidiTable::Instance();
    Midi items = midiTable->getMidiMap("Structure", this->combo_hex1, this->combo_hex2, this->combo_hex3);

    QString desc = items.level.at(index).desc;
    QString customdesc = items.level.at(index).customdesc;
    if(customdesc.isEmpty())
    {
        customdesc = desc;
    };

    this->stompComboBox->setCurrentIndex(index);
    this->stompComboBox->setEditText(desc);
}

void stompBox::emitValueChanged(QString hex1, QString hex2, QString hex3, QString valueHex)
{
    QString valueName, valueStr;
    if(hex1 != "void" && hex2 != "void")
    {
        MidiTable *midiTable = MidiTable::Instance();
        if(valueHex != "void")
        {
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
                sysxIO->setFileSource("Structure", hex1, hex2, hex3, valueHex1, valueHex2);
            }
            else
            {
                sysxIO->setFileSource("Structure", hex1, hex2, hex3, valueHex);
                emit dialogUpdateSignal();
                sysxIO->setFileSource("Structure", hex1, hex2, hex3, valueHex);
            };
            Midi items = midiTable->getMidiMap("Structure", hex1, hex2, hex3);
            valueName = items.customdesc;
            valueStr = midiTable->getValue("Structure", hex1, hex2, hex3, valueHex);
            //emit updateSignal();
            emit valueChanged(this->fxName, valueName, valueStr);
             if(this->id == 11 && hex3 == "11") {updateSwitch(hex1, hex2, hex3); }; //added because these 2 won't change
             if(this->id == 5 && hex3 == "5A") {updateSwitch(hex1, hex2, hex3); };
        };
    };
}

void stompBox::setDisplayToFxName()
{
    emit valueChanged(this->fxName, "", "");
}

void stompBox::updateDisplay(QString text)
{

    emit valueChanged(this->fxName, "", text);
}

void stompBox::updateStompPath()
{
    if (this->id == 4) {this->fxName = tr("Amp/Spkr");};
    if (this->id == 5){this->fxName = tr("Noise Suppressor");};
    if (this->id == 6) {this->fxName = tr("Modulation Effect");};
    if (this->id == 7) {this->fxName = tr("Multi Effect");};
    if (this->id == 8) {this->fxName = tr("Chorus");};
    if (this->id == 9) {this->fxName = tr("Reverb");};
    if (this->id == 10) {this->fxName = tr("Delay");};
    if (this->id == 11) {this->fxName = tr("Equalizer");};
}

void stompBox::getStompOrder()
{

}
