/****************************************************************************
**
** Copyright (C) 2007~2010 Colin Willcocks.
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

        this->pathSwitch = new customButton(tr(""), false, QPoint(60, 60), this, ":/images/pathswitch.png");
        this->pathSwitch->hide();

        QObject::connect(this, SIGNAL( valueChanged(QString, QString, QString) ), this->parent(), SIGNAL( valueChanged(QString, QString, QString) ));

        QObject::connect(this->parent(), SIGNAL( updateStompOffset(signed int) ), this, SLOT( updatePos(signed int) ));

        QObject::connect(this->parent(), SIGNAL( updateSignal() ), this, SLOT( updateSignal() ));

        QObject::connect(this->editDialog, SIGNAL( updateSignal() ), this, SLOT( updateSignal() ));

        QObject::connect(this, SIGNAL( dialogUpdateSignal() ), this->editDialog, SIGNAL( dialogUpdateSignal() ));

        QObject::connect(this->parent(), SIGNAL( updateSignal() ), this->editDialog, SIGNAL( dialogUpdateSignal() ));

        QObject::connect(this->editDialog, SIGNAL( updateSignal() ), this, SLOT( setDisplayToFxName() ));

        QObject::connect(this, SIGNAL( setEditDialog( editWindow*) ), this->parent(), SLOT( setEditDialog(editWindow*) ));

  QObject::connect(this->pathSwitch, SIGNAL( valueChanged(bool)), this, SLOT( pathSwitchSignal(bool) ));

  QObject::connect(this->parent(), SIGNAL( pathUpdateSignal() ), this, SIGNAL( pathUpdateSignal() ));

  QObject::connect(this, SIGNAL( pathUpdateSignal() ), this, SLOT( updateStompPath() ));

  QObject::connect(this, SIGNAL( updateStompBoxes() ), this->parent(), SLOT( updateStompBoxes() ));

  QObject::connect(this, SIGNAL( switchSignal() ), this->parent(), SIGNAL( updateSignal() ));

  QObject::connect(this->parent(), SIGNAL(ch_mode_buttonSignal(bool)), this, SLOT(ch_mode_ButtonSignal(bool) ));
  QObject::connect(this->parent(), SIGNAL(ch_mode_buttonSignal(bool)), this->parent(), SLOT(menuButtonSignal()));

  QObject::connect(this->parent(), SIGNAL(preamp1_buttonSignal(bool)), this, SLOT(preamp1_ButtonSignal(bool) ));
  QObject::connect(this->parent(), SIGNAL(preamp1_buttonSignal(bool)), this->parent(), SLOT(menuButtonSignal()));

  QObject::connect(this->parent(), SIGNAL(preamp2_buttonSignal(bool)), this, SLOT(preamp2_ButtonSignal(bool) ));
  QObject::connect(this->parent(), SIGNAL(preamp2_buttonSignal(bool)), this->parent(), SLOT(menuButtonSignal()));

  QObject::connect(this->parent(), SIGNAL(distortion_buttonSignal(bool)), this, SLOT(distortion_ButtonSignal(bool) ));
  QObject::connect(this->parent(), SIGNAL(distortion_buttonSignal(bool)), this->parent(), SLOT(menuButtonSignal()));

  QObject::connect(this->parent(), SIGNAL(compressor_buttonSignal(bool)), this, SLOT(compressor_ButtonSignal(bool) ));
  QObject::connect(this->parent(), SIGNAL(compressor_buttonSignal(bool)), this->parent(), SLOT(menuButtonSignal()));

  QObject::connect(this->parent(), SIGNAL(ns1_buttonSignal(bool)), this, SLOT(ns1_ButtonSignal(bool) ));
  QObject::connect(this->parent(), SIGNAL(ns1_buttonSignal(bool)), this->parent(), SLOT(menuButtonSignal()));

  QObject::connect(this->parent(), SIGNAL(ns2_buttonSignal(bool)), this, SLOT(ns2_ButtonSignal(bool) ));
  QObject::connect(this->parent(), SIGNAL(ns2_buttonSignal(bool)), this->parent(), SLOT(menuButtonSignal()));

  QObject::connect(this->parent(), SIGNAL(mod_buttonSignal(bool)), this, SLOT(mod_ButtonSignal(bool) ));
  QObject::connect(this->parent(), SIGNAL(mod_buttonSignal(bool)), this->parent(), SLOT(menuButtonSignal()));

  QObject::connect(this->parent(), SIGNAL(mfx_buttonSignal(bool)), this, SLOT(mfx_ButtonSignal(bool) ));
  QObject::connect(this->parent(), SIGNAL(mfx_buttonSignal(bool)), this->parent(), SLOT(menuButtonSignal()));

  QObject::connect(this->parent(), SIGNAL(reverb_buttonSignal(bool)), this, SLOT(reverb_ButtonSignal(bool) ));
  QObject::connect(this->parent(), SIGNAL(reverb_buttonSignal(bool)), this->parent(), SLOT(menuButtonSignal()));

  QObject::connect(this->parent(), SIGNAL(delay_buttonSignal(bool)), this, SLOT(delay_ButtonSignal(bool) ));
  QObject::connect(this->parent(), SIGNAL(delay_buttonSignal(bool)), this->parent(), SLOT(menuButtonSignal()));

  QObject::connect(this->parent(), SIGNAL(chorus_buttonSignal(bool)), this, SLOT(chorus_ButtonSignal(bool) ));
  QObject::connect(this->parent(), SIGNAL(chorus_buttonSignal(bool)), this->parent(), SLOT(menuButtonSignal()));

  QObject::connect(this->parent(), SIGNAL(sendreturn_buttonSignal(bool)), this, SLOT(sendreturn_ButtonSignal(bool) ));
  QObject::connect(this->parent(), SIGNAL(sendreturn_buttonSignal(bool)), this->parent(), SLOT(menuButtonSignal()));

  QObject::connect(this->parent(), SIGNAL(eq_buttonSignal(bool)), this, SLOT(eq_ButtonSignal(bool) ));
  QObject::connect(this->parent(), SIGNAL(eq_buttonSignal(bool)), this->parent(), SLOT(menuButtonSignal()));

  QObject::connect(this->parent(), SIGNAL(pedal_buttonSignal(bool)), this, SLOT(pedal_ButtonSignal(bool) ));
  QObject::connect(this->parent(), SIGNAL(pedal_buttonSignal(bool)), this->parent(), SLOT(menuButtonSignal()));
};

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
};

editWindow* stompBox::editDetails()
{
        return this->editDialog;
};

void stompBox::mousePressEvent(QMouseEvent *event)
{
   /*     emitValueChanged(this->hex1, this->hex2, "00", "void");

        if (event->button() == Qt::LeftButton)
        {
                this->dragStartPosition = event->pos();
        }
        else if (event->button() == Qt::RightButton)
        {
                this->editDialog->setWindow(this->fxName);
                emit setEditDialog(this->editDialog);
        };*/
};


void stompBox::mouseDoubleClickEvent(QMouseEvent *event)
{

        this->editDialog->setWindow(this->fxName);
        emit setEditDialog(this->editDialog);
};

void stompBox::mouseMoveEvent(QMouseEvent *event)
{

};

void stompBox::ch_mode_ButtonSignal(bool value)
{
    if (this->id == 16)
    {
      emitValueChanged(this->hex1, this->hex2, "00", "void");
            this->editDialog->setWindow(this->fxName);
      emit setEditDialog(this->editDialog);
    };
};

void stompBox::preamp1_ButtonSignal(bool value)
{
    if (this->id == 2)
    {
      emitValueChanged(this->hex1, this->hex2, "00", "void");
            this->editDialog->setWindow(this->fxName);
      emit setEditDialog(this->editDialog);
    };
};

void stompBox::preamp2_ButtonSignal(bool value)
{
    if (this->id == 3)
    {
      emitValueChanged(this->hex1, this->hex2, "00", "void");
            this->editDialog->setWindow(this->fxName);
      emit setEditDialog(this->editDialog);
    };
};

void stompBox::distortion_ButtonSignal(bool value)
{
    if (this->id == 1)
    {
      emitValueChanged(this->hex1, this->hex2, "00", "void");
            this->editDialog->setWindow(this->fxName);
      emit setEditDialog(this->editDialog);
    };
};

void stompBox::compressor_ButtonSignal(bool value)
{
    if (this->id == 0)
    {
      emitValueChanged(this->hex1, this->hex2, "00", "void");
            this->editDialog->setWindow(this->fxName);
      emit setEditDialog(this->editDialog);
    };
};

void stompBox::ns1_ButtonSignal(bool value)
{
    if (this->id == 12)
    {
      emitValueChanged(this->hex1, this->hex2, "00", "void");
            this->editDialog->setWindow(this->fxName);
      emit setEditDialog(this->editDialog);
    };
};

void stompBox::ns2_ButtonSignal(bool value)
{
    if (this->id == 13)
    {
      emitValueChanged(this->hex1, this->hex2, "00", "void");
            this->editDialog->setWindow(this->fxName);
      emit setEditDialog(this->editDialog);
    };
};

void stompBox::mod_ButtonSignal(bool value)
{
    if (this->id == 5)
    {
      emitValueChanged(this->hex1, this->hex2, "00", "void");
            this->editDialog->setWindow(this->fxName);
      emit setEditDialog(this->editDialog);
    };
};

void stompBox::mfx_ButtonSignal(bool value)
{
    if (this->id == 6)
    {
      emitValueChanged(this->hex1, this->hex2, "00", "void");
            this->editDialog->setWindow(this->fxName);
      emit setEditDialog(this->editDialog);
    };
};

void stompBox::reverb_ButtonSignal(bool value)
{
    if (this->id == 9)
    {
      emitValueChanged(this->hex1, this->hex2, "00", "void");
            this->editDialog->setWindow(this->fxName);
      emit setEditDialog(this->editDialog);
    };
};

void stompBox::delay_ButtonSignal(bool value)
{
    if (this->id == 7)
    {
      emitValueChanged(this->hex1, this->hex2, "00", "void");
            this->editDialog->setWindow(this->fxName);
      emit setEditDialog(this->editDialog);
    };
};

void stompBox::chorus_ButtonSignal(bool value)
{
    if (this->id == 8)
    {
      emitValueChanged(this->hex1, this->hex2, "00", "void");
            this->editDialog->setWindow(this->fxName);
      emit setEditDialog(this->editDialog);
    };
};

void stompBox::sendreturn_ButtonSignal(bool value)
{
    if (this->id == 14)
    {
      emitValueChanged(this->hex1, this->hex2, "00", "void");
            this->editDialog->setWindow(this->fxName);
      emit setEditDialog(this->editDialog);
    };
};

void stompBox::eq_ButtonSignal(bool value)
{
    if (this->id == 4)
    {
      emitValueChanged(this->hex1, this->hex2, "00", "void");
            this->editDialog->setWindow(this->fxName);
      emit setEditDialog(this->editDialog);
    };
};

void stompBox::pedal_ButtonSignal(bool value)
{
    if (this->id == 10)
    {
      emitValueChanged(this->hex1, this->hex2, "00", "void");
            this->editDialog->setWindow(this->fxName);
      emit setEditDialog(this->editDialog);
    };
};

void stompBox::pathSwitchSignal(bool value)
{

};

void stompBox::setPos(QPoint newPos)
{
        this->move(newPos);
        this->stompPos = newPos;
        updateStompPath();
};

void stompBox::updatePos(signed int offsetDif)
{
        this->stompPos = this->pos();
        QPoint newPos = stompPos + QPoint(offsetDif, 0);
        this->move(newPos);
        this->stompPos = newPos;
};

void stompBox::setImage(QString imagePath)
{
        this->imagePath = imagePath;
        this->update();
};

void stompBox::setSize(QSize newSize)
{
        this->stompSize = newSize;
        this->setFixedSize(stompSize);
};

void stompBox::setId(unsigned int id)
{
        this->id = id;
};

unsigned int stompBox::getId()
{
        return this->id;
};


void stompBox::setLSB(QString hex1, QString hex2)
{
        this->hex1 = hex1;
        this->hex2 = hex2;
        this->editDialog->setLSB(hex1, hex2);
};

void stompBox::setComboBox(QString hex1, QString hex2, QString hex3, QRect geometry)
{
        this->hex1 = hex1;
        this->hex2 = hex2;
        this->hex3 = hex3;

        MidiTable *midiTable = MidiTable::Instance();
        Midi items = midiTable->getMidiMap("Structure", hex1, hex2, hex3);

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
};

void stompBox::setComboBoxCurrentIndex(int index)
{
        this->stompComboBox->setCurrentIndex(index);
};

void stompBox::setKnob1(QString hex1, QString hex2, QString hex3)
{
        MidiTable *midiTable = MidiTable::Instance();
        int range = midiTable->getRange("Structure", hex1, hex2, hex3);
        knob1 = new customDial(0, 0, range, 1, 10, QPoint(6, 9), this, hex1, hex2, hex3);
};

void stompBox::setKnob2(QString hex1, QString hex2, QString hex3)
{
        MidiTable *midiTable = MidiTable::Instance();
        int range = midiTable->getRange("Structure", hex1, hex2, hex3);
        knob2 = new customDial(0, 0, range, 1, 10, QPoint(53, 9), this, hex1, hex2, hex3);
};

void stompBox::setSlider1(QString hex1, QString hex2, QString hex3)
{
        MidiTable *midiTable = MidiTable::Instance();
        int range = midiTable->getRange("Structure", hex1, hex2, hex3);
        slider1 = new customSlider(0, 0, range, 1, 10, QPoint(8, 17), this, hex1, hex2, hex3);
};

void stompBox::setSlider2(QString hex1, QString hex2, QString hex3)
{
        MidiTable *midiTable = MidiTable::Instance();
        int range = midiTable->getRange("Structure", hex1, hex2, hex3);
        slider2 = new customSlider(0, 0, range, 1, 10, QPoint(24, 17), this, hex1, hex2, hex3);
};

void stompBox::setSlider3(QString hex1, QString hex2, QString hex3)
{
        MidiTable *midiTable = MidiTable::Instance();
        int range = midiTable->getRange("Structure", hex1, hex2, hex3);
        slider3 = new customSlider(0, 0, range, 1, 10, QPoint(40, 17), this, hex1, hex2, hex3);
};

void stompBox::setSlider4(QString hex1, QString hex2, QString hex3)
{
        MidiTable *midiTable = MidiTable::Instance();
        int range = midiTable->getRange("Structure", hex1, hex2, hex3);
        slider4 = new customSlider(0, 0, range, 1, 10, QPoint(56, 17), this, hex1, hex2, hex3);
};

void stompBox::setSlider5(QString hex1, QString hex2, QString hex3)
{
        MidiTable *midiTable = MidiTable::Instance();
        int range = midiTable->getRange("Structure", hex1, hex2, hex3);
        slider5 = new customSlider(0, 0, range, 1, 10, QPoint(79, 17), this, hex1, hex2, hex3);
};

void stompBox::setButton(QString hex1, QString hex2, QString hex3)
{
        button = new customButton(false, QPoint(4, 110), this, hex1, hex2, hex3);
        led = new customLed(false, QPoint(41, 4), this);

        QObject::connect(button, SIGNAL(valueChanged(bool, QString, QString, QString)),
                                led, SLOT(changeValue(bool)));
};

void stompBox::setButton(QString hex1, QString hex2, QString hex3, QPoint pos, QString imagePath)
{
        button = new customButton(false, pos, this, hex1, hex2, hex3, imagePath);
        led = new customLed(false, QPoint(41, 4), this);

        QObject::connect(button, SIGNAL(valueChanged(bool, QString, QString, QString)),
                                led, SLOT(changeValue(bool)));
};

void stompBox::setSwitch(QString hex1, QString hex2, QString hex3)
{
        switchbutton = new customSwitch(false, this, hex1, hex2, hex3);
        switchbutton->move(QPoint(15, 45));
};

void stompBox::updateComboBox(QString hex1, QString hex2, QString hex3)
{
        QObject::disconnect(this->stompComboBox, SIGNAL(currentIndexChanged(int)), // To prevent sending a signal when loading a patch.
                this, SLOT(valueChanged(int)));

        SysxIO *sysxIO = SysxIO::Instance();
        QString area;
        setComboBoxCurrentIndex(sysxIO->getSourceValue(area, hex1, hex2, hex3));

        QObject::connect(this->stompComboBox, SIGNAL(currentIndexChanged(int)),
                this, SLOT(valueChanged(int)));
};

void stompBox::updateKnob1(QString hex1, QString hex2, QString hex3)
{
        SysxIO *sysxIO = SysxIO::Instance();
  QString area;
        knob1->setValue(sysxIO->getSourceValue(area, hex1, hex2, hex3));
};

void stompBox::updateKnob2(QString hex1, QString hex2, QString hex3)
{
        SysxIO *sysxIO = SysxIO::Instance();
        QString area;
        knob2->setValue(sysxIO->getSourceValue(area, hex1, hex2, hex3));
};

void stompBox::updateSlider1(QString hex1, QString hex2, QString hex3)
{
        SysxIO *sysxIO = SysxIO::Instance();
        QString area;
        slider1->setValue(sysxIO->getSourceValue(area, hex1, hex2, hex3));
};

void stompBox::updateSlider2(QString hex1, QString hex2, QString hex3)
{
        SysxIO *sysxIO = SysxIO::Instance();
        QString area;
        slider2->setValue(sysxIO->getSourceValue(area, hex1, hex2, hex3));
};

void stompBox::updateSlider3(QString hex1, QString hex2, QString hex3)
{
        SysxIO *sysxIO = SysxIO::Instance();
        QString area;
        slider3->setValue(sysxIO->getSourceValue(area, hex1, hex2, hex3));
};

void stompBox::updateSlider4(QString hex1, QString hex2, QString hex3)
{
        SysxIO *sysxIO = SysxIO::Instance();
        QString area;
        slider4->setValue(sysxIO->getSourceValue(area, hex1, hex2, hex3));
};

void stompBox::updateSlider5(QString hex1, QString hex2, QString hex3)
{
        SysxIO *sysxIO = SysxIO::Instance();
        QString area;
        slider5->setValue(sysxIO->getSourceValue(area, hex1, hex2, hex3));
};

void stompBox::updateButton(QString hex1, QString hex2, QString hex3)
{
        SysxIO *sysxIO = SysxIO::Instance();
        QString area;
        int value = sysxIO->getSourceValue(area, hex1, hex2, hex3);
        led->setValue((value==1)?true:false);
        button->setValue((value==1)?true:false);
};

void stompBox::updateSwitch(QString hex1, QString hex2, QString hex3)
{
        SysxIO *sysxIO = SysxIO::Instance();
        QString area;
        int value = sysxIO->getSourceValue(area, hex1, hex2, hex3);
        switchbutton->setValue((value==1)?true:false);
        //emit switchSignal();
        //QApplication::beep();
};

void stompBox::valueChanged(int value, QString hex1, QString hex2, QString hex3)
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

void stompBox::valueChanged(bool value, QString hex1, QString hex2, QString hex3)
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

void stompBox::valueChanged(int index)
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

void stompBox::emitValueChanged(QString hex1, QString hex2, QString hex3, QString valueHex)
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

void stompBox::setDisplayToFxName()
{
        //emit valueChanged(this->fxName, "", "");
};

void stompBox::updateStompPath()
{
        if (this->id == 0) {this->fxName = tr("Compressor");};
        if (this->id == 1) {this->fxName = tr("Amp/Spkr");};
        if (this->id == 2) {this->fxName = tr("PCM Synth A");};
        if (this->id == 3) {this->fxName = tr("PCM Synth B");};
        if (this->id == 4) {this->fxName = tr("Equalizer");};
        if (this->id == 5) {this->fxName = tr("Modulation Effect");};
        if (this->id == 6) {this->fxName = tr("Multi Effect");};
        if (this->id == 7) {this->fxName = tr("Delay");};
        if (this->id == 8) {this->fxName = tr("Chorus");};
        if (this->id == 9) {this->fxName = tr("Reverb");};
        if (this->id == 10){this->fxName = tr("Pedal/GK");};
        if (this->id == 11){this->fxName = tr("Volume");};
        if (this->id == 12){this->fxName = tr("Noise Suppressor");};
        if (this->id == 13){this->fxName = tr("Noise Suppressor 2");};
        if (this->id == 14){this->fxName = tr("Send/Return");};
        if (this->id == 15){this->fxName = tr("Analog Pickup");};
        if (this->id == 16){this->fxName = tr("COSM Modeling");};
        if (this->id == 17){this->fxName = tr("Chain Merge");};

};

void stompBox::getStompOrder()
{

};
