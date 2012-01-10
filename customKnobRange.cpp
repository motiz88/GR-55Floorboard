/****************************************************************************
**
** Copyright (C) 2007~2012 Colin Willcocks.
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

#include "customKnobRange.h"
#include "MidiTable.h"
#include "SysxIO.h"

customKnobRange::customKnobRange(QWidget *parent, QString area, QString hex1, QString hex2, QString hexMin, QString hexMax, QString type) : QWidget(parent)
{
    this->area = area;
    this->hex1 = hex1;
    this->hex2 = hex2;
    this->hexMin = hexMin;
    this->hexMax = hexMax;
    this->type = type;
    bool ok;
    int range;
    int rangeMin;
    MidiTable *midiTable = MidiTable::Instance();
    if (this->area != "System"){this->area = "Structure";};
    if (this->type == "Min")
    {
        hex3 = hexMin;
        range = QString(this->hexMax).toInt(&ok, 16) - 1;
        rangeMin = midiTable->getRangeMinimum(this->area, hex1, hex2, hex3);
    }
    else
    {
        hex3 = hexMax;
        range = midiTable->getRange(this->area, hex1, hex2, hex3);
        rangeMin = QString(this->hexMin).toInt(&ok, 16) + 1;
    };



    QPoint bgPos = QPoint(0, -3); // Correction needed y-3.
    QPoint knobPos = QPoint(5, 4); // Correction needed y+1 x-1.

    QLabel *newBackGround = new QLabel(this);
    newBackGround->setPixmap(QPixmap(":/images/knobbgn.png"));
    newBackGround->move(bgPos);

    QString imagePath(":/images/knob.png");
    unsigned int imageRange = 100;
    this->knob = new customRangeDial(0, rangeMin, range, 1, 10, knobPos, this, this->area, hex1, hex2, hex3, this->type, imagePath, imageRange);
    this->setFixedSize(newBackGround->pixmap()->size() - QSize(0, 4)); // Correction needed h-4.

    QObject::connect(this, SIGNAL( updateSignal() ),
                     this->parent(), SIGNAL( updateSignal() ));

    QObject::connect(this, SIGNAL( updateDisplayMin(QString) ),
                     this->parent(), SIGNAL( updateDisplayMin(QString) ));

    QObject::connect(this, SIGNAL( updateDisplayMax(QString) ),
                     this->parent(), SIGNAL( updateDisplayMax(QString) ));
};

void customKnobRange::paintEvent(QPaintEvent *)
{
    /*DRAWS RED BACKGROUND FOR DEBUGGING PURPOSE */
    /*QPixmap image(":images/dragbar.png");

	QRectF target(0.0, 0.0, this->width(), this->height());
	QRectF source(0.0, 0.0, this->width(), this->height());

	QPainter painter(this);
	painter.drawPixmap(target, image, source);*/
};

void customKnobRange::setValue(int value)
{
    this->knob->setValue(value);
};

void customKnobRange::valueChanged(int value, QString hex1, QString hex2, QString hex3)
{
    MidiTable *midiTable = MidiTable::Instance();

    QString valueHex = QString::number(value, 16).toUpper();
    if(valueHex.length() < 2) valueHex.prepend("0");

    SysxIO *sysxIO = SysxIO::Instance(); bool ok;
    if(midiTable->isData(this->area, hex1, hex2, hex3))
    {
        int maxRange = QString("7F").toInt(&ok, 16) + 1;
        int value = valueHex.toInt(&ok, 16);
        int dif = value/maxRange;
        QString valueHex1 = QString::number(dif, 16).toUpper();
        if(valueHex1.length() < 2) valueHex1.prepend("0");
        QString valueHex2 = QString::number(value - (dif * maxRange), 16).toUpper();
        if(valueHex2.length() < 2) valueHex2.prepend("0");
	
        sysxIO->setFileSource(this->area, hex1, hex2, hex3, valueHex1, valueHex2);
    }
    else
    {

        sysxIO->setFileSource(this->area, hex1, hex2, hex3, valueHex);
    };

    QString valueStr = midiTable->getValue(this->area, hex1, hex2, hex3, valueHex);
    if (this->type == "Min"){	emit updateDisplayMin(valueStr);} else { emit updateDisplayMax(valueStr); };
    emit updateSignal();
};
