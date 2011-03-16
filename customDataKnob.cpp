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

#include "customDataKnob.h"
#include "MidiTable.h"
#include "SysxIO.h"

customDataKnob::customDataKnob(QWidget *parent, QString hex1, QString hex2, QString hex3, QString background, QString direction) : QWidget(parent)
{
    this->hex1 = hex1;
    this->hex2 = hex2;
    this->hex3 = hex3;
    this->area = direction;
    this->hex_a ="00";
    this->hex_b ="00";
    this->hex_c ="00";
    this->byteSize = "3";
    this->dataRange = 1;
    MidiTable *midiTable = MidiTable::Instance();
    if (this->area != "System"){ this->area = "Structure"; };
    if (background == "DELAY3400") { this->hex_c = "04"; };
    if (background == "DELAY2600") { this->hex_c = "09"; };
    if (background == "DELAY1300") { this->hex_c = "0B"; };
    if (background == "BPM") { this->hex_c = "06"; this->byteSize == "2"; };
    if (background == "0~100") {this->hex_c = "07"; this->byteSize = "2"; };
    if (background == "RATE") {this->hex_c = "08"; this->byteSize = "2"; };
    if (background == "PORTAMENTO") {this->hex_c = "11"; this->byteSize = "2"; };

    int range = midiTable->getRange("Tables", hex_a, hex_b, hex_c);
    int rangeMin = midiTable->getRangeMinimum("Tables", hex_a, hex_b, hex_c);

    QPoint bgPos = QPoint(0, -3); // Correction needed y-3.
    QPoint knobPos = QPoint(5, 4); // Correction needed y+1 x-1.

    QLabel *newBackGround = new QLabel(this);
    newBackGround->setPixmap(QPixmap(":/images/knobbgn.png"));

    newBackGround->move(bgPos);
    QString imagePath_knob(":/images/knob.png");

    unsigned int imageRange = 100;
    this->knob = new customDial(0, rangeMin, range, 1, 10, knobPos, this, hex1, hex2, hex3, imagePath_knob, imageRange);
    this->setFixedSize(newBackGround->pixmap()->size() - QSize(0, 4)); // Correction needed h-4.

    QObject::connect(this, SIGNAL( updateSignal() ),
                     this->parent(), SIGNAL( updateSignal() ));

    QObject::connect(this, SIGNAL( updateDisplay(QString) ),
                     this->parent(), SIGNAL( updateDisplay(QString) ));
};

void customDataKnob::paintEvent(QPaintEvent *)
{
    /*DRAWS RED BACKGROUND FOR DEBUGGING PURPOSE */
    /*QPixmap image(":images/dragbar.png");

	QRectF target(0.0, 0.0, this->width(), this->height());
	QRectF source(0.0, 0.0, this->width(), this->height());

	QPainter painter(this);
	painter.drawPixmap(target, image, source);*/
};

void customDataKnob::setValue(int value)
{
    this->knob->setValue(value);
};

void customDataKnob::valueChanged(int value, QString hex1, QString hex2, QString hex3)
{
    MidiTable *midiTable = MidiTable::Instance();
    QString valueHex = QString::number(value, 16).toUpper();
    if (this->byteSize == "3") {
        if(valueHex.length() < 2) { valueHex.prepend("00"); }
        else if(valueHex.length() < 3) { valueHex.prepend("0"); };
    } else { if(valueHex.length() < 2) { valueHex.prepend("0"); }; };

    QList<QString> valueString;
    QString lsb = valueHex.at(0);
    lsb.prepend("0");
    valueString.append(lsb);
    lsb = valueHex.at(1);
    lsb.prepend("0");
    valueString.append(lsb);
    if (this->byteSize == "3") { lsb = valueHex.at(2);
    lsb.prepend("0");
    valueString.append(lsb); };

    SysxIO *sysxIO = SysxIO::Instance();
    sysxIO->setFileSource("Structure", hex1, hex2, hex3, valueString);;
    QString valueStr = midiTable->getValue("Tables", hex_a, hex_b, hex_c, valueHex);

    emit updateDisplay(valueStr);
    emit updateSignal();
};
