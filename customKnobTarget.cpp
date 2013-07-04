/****************************************************************************
**
** Copyright (C) 2007~2013 Colin Willcocks.
** Copyright (C) 2005~2007 Uco Mesdag. 
** All rights reserved.
** This file is part of "GR-55B FloorBoard".
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

#include "customKnobTarget.h"
#include "MidiTable.h"
#include "SysxIO.h"


customKnobTarget::customKnobTarget(QWidget *parent, 
                                   QString hex1, QString hex2, QString hex3,
                                   QString hexMsb, QString hexLsb, QString background)
    : QWidget(parent)
{
    this->hex1 = hex1;
    this->hex2 = hex2;
    this->hex3 = hex3;
    this->hexMsb = hexMsb;
    this->hexLsb = hexLsb;
    this->background = background;

    SysxIO *sysxIO = SysxIO::Instance();
    QString mode_hex = "00";
    int mode_value = sysxIO->getSourceValue("Structure", "00", "00", "00");   //check for guitar mode
    if(mode_value != 0) {mode_hex = "0D"; };

    MidiTable *midiTable = MidiTable::Instance();

    QPoint bgPos = QPoint(0, -3); // Correction needed y-3.
    QPoint knobPos = QPoint(5, 4); // Correction needed y+1 x-1.
    QLabel *newBackGround = new QLabel(this);
    if (this->background == "target")
    {
        this->range = midiTable->getRange("Tables", "00", "00", mode_hex);
        this->rangeMin = midiTable->getRangeMinimum("Tables", "00", "00", mode_hex);
    }
    else
    {
        this->range = midiTable->getRange("Tables", "00", "00", hexLsb);
        this->rangeMin = midiTable->getRangeMinimum("Tables", "00", "00", hexLsb);
    };

    newBackGround->setPixmap(QPixmap(":/images/knobbgn.png"));
    newBackGround->move(bgPos);

    QString imagePath(":/images/knob.png");
    unsigned int imageRange = 100;
    this->knob = new customTargetDial(0, rangeMin, range, 1, 10, knobPos, this, hex1, hex2, hex3, imagePath, imageRange, background);
    this->setFixedSize(newBackGround->pixmap()->size() - QSize(0, 4)); // Correction needed h-4.


    QObject::connect(this, SIGNAL( updateSignal() ),
                     this->parent(), SIGNAL( updateSignal() ));

    QObject::connect(this, SIGNAL( updateDisplayTarget(QString) ),
                     this->parent(), SIGNAL( updateDisplayTarget(QString) ));

    QObject::connect(this, SIGNAL( updateDisplayMin(QString) ),
                     this->parent(), SIGNAL( updateDisplayMin(QString) ));

    QObject::connect(this, SIGNAL( updateDisplayMax(QString) ),
                     this->parent(), SIGNAL( updateDisplayMax(QString) ));

    QObject::connect(this, SIGNAL( updateTarget(QString, QString, QString) ),
                     this->parent(), SIGNAL( updateTarget(QString, QString, QString) ));

    QObject::connect(this, SIGNAL( updateHex(QString, QString, QString) ),
                     this, SLOT( knobSignal(QString, QString, QString) ));

    QObject::connect(this->parent(), SIGNAL( updateHex(QString, QString, QString) ),
                     this, SIGNAL( updateHex(QString, QString, QString) ));

}

void customKnobTarget::paintEvent(QPaintEvent *)
{
    /*DRAWS RED BACKGROUND FOR DEBUGGING PURPOSE */
    /*QPixmap image(":images/dragbar.png");

    QRectF target(0.0, 0.0, this->width(), this->height());
    QRectF source(0.0, 0.0, this->width(), this->height());

    QPainter painter(this);
    painter.drawPixmap(target, image, source);*/
}

void customKnobTarget::knobSignal(QString hexMsb, QString hex2, QString hexLsb)
{
    if (background != "target")
    {
        this->hexMsb = hexMsb;
        this->hexLsb = hexLsb;
    };
}

void customKnobTarget::setValue(int value)
{
    this->knob->setValue(value);     // on initialisation only
}

void customKnobTarget::valueChanged(int value, QString hex1, QString hex2, QString hex3)
{

    MidiTable *midiTable = MidiTable::Instance();

    QString valueHex = QString::number(value, 16).toUpper();
    if(valueHex.length() < 2) { valueHex.prepend("00"); }
    else if(valueHex.length() < 3) { valueHex.prepend("0"); };

    QList<QString> valueString;
    QString lsb_a = valueHex.at(0);
    lsb_a.prepend("0");
    valueString.append(lsb_a);
    QString lsb_b = valueHex.at(1);
    lsb_b.prepend("0");
    valueString.append(lsb_b);
    QString lsb_c = valueHex.at(2);
    lsb_c.prepend("0");
    valueString.append(lsb_c);

    SysxIO *sysxIO = SysxIO::Instance();
    sysxIO->setFileSource("Structure", hex1, hex2, hex3, valueString);
    QString mode_hex = "00";
    int mode_value = sysxIO->getSourceValue("Structure", "00", "00", "00");    //check for guitar mode
    if(mode_value != 0) {mode_hex = "0D"; };

    QString valueStr;
    if (this->background == "target") {
        valueStr = midiTable->getValue("Tables", "00", "00", mode_hex, valueHex);
        emit updateDisplayTarget(valueStr);                                          // updates display values
    } else if (this->background == "min") {
        valueStr = midiTable->getValue("Tables", "00", "00", hexLsb, valueHex);
        emit updateDisplayMin(valueStr);
    } else if (this->background == "max") {
        valueStr = midiTable->getValue("Tables", "00", "00", hexLsb, valueHex);
        emit updateDisplayMax(valueStr);
    };                                                  // updates display values

    if (this->background == "target")                                                   // get the currently selected target value & set min/max address
    {
        bool ok;
        QString hex3_msb = QString::number((hex3.toInt(&ok, 16) + 1), 16).toUpper();    // go forward 1 to select target MSB address
        if(hex3_msb.length() < 2) hex3_msb.prepend("0");                                // prepend with "0" if single digit.

        QString hex3_lsb = QString::number((hex3.toInt(&ok, 16) + 2), 16).toUpper();    // go forward 2 to select target LSB address
        if(hex3_lsb.length() < 2) hex3_lsb.prepend("0");
        QString hex_a = hex1;
        if(hex3 == "7F") {hex_a = "02"; hex3_msb = "00"; hex3_lsb = "01"; };

        int value = sysxIO->getSourceValue("Structure", this->hex1, this->hex2, this->hex3);        // read target value as integer from sysx.
        QString valueHex = QString::number(value, 16).toUpper();                        // convert to hex qstring.
        value = sysxIO->getSourceValue("Structure", hex_a, this->hex2, hex3_msb);        // read target value as integer from sysx.
        valueHex.append(QString::number(value, 16).toUpper());
        value = sysxIO->getSourceValue("Structure", hex_a, this->hex2, hex3_lsb);        // read target value as integer from sysx.
        valueHex.append(QString::number(value, 16).toUpper());

        valueStr = midiTable->getValue("Tables", "00", "00", mode_hex, valueHex);           // lookup the target values

        int maxRange = 256;
        value = valueHex.toInt(&ok, 16);
        int dif = value/maxRange;
        QString valueHex1 = QString::number(dif, 16).toUpper();
        if(valueHex1.length() < 2) valueHex1.prepend("0");
        QString valueHex2 = QString::number(value - (dif * maxRange), 16).toUpper();
        if(valueHex2.length() < 2) valueHex2.prepend("0");
        QString hex4 = valueHex1;
        QString hex5 = valueHex2;                                                       //convert valueStr to 7bit hex4, hex5
        Midi items = midiTable->getMidiMap("Tables", "00", "00", mode_hex, hex4, hex5);
        this->hexMsb = items.desc;
        this->hexLsb = items.customdesc;

        emit updateTarget(hexMsb, hex2, hexLsb);                                        // hexMsb & hexLsb are lookup address for label value
        emit updateTarget(hexMsb, hex2, hexLsb);
    };                                                            // updates on knob value change
}

