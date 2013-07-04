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

#include "customControlDataKnob.h"
#include "MidiTable.h"
#include "SysxIO.h"

customControlDataKnob::customControlDataKnob(QWidget *parent,
                                             QString hex1, QString hex2, QString hex3,
                                             QString background, QString direction, int lenght)
                                                 : QWidget(parent)
{
    this->display = new QLineEdit(this);
    this->label = new customControlLabel(this);
    this->hex1 = hex1;
    this->hex2 = hex2;
    this->hex3 = hex3;
    this->area = "Structure";

    MidiTable *midiTable = MidiTable::Instance();
    this->hex_a = "00";
    this->hex_b = "00";
    this->hex_c = "00";
    this->byteSize = "3";

    if (background == "DELAY3400") { this->hex_c = "04"; };
    if (background == "DELAY2600") { this->hex_c = "09"; };
    if (background == "DELAY1300") { this->hex_c = "0B"; };
    if (background == "BPM")       { this->hex_c = "06";   this->byteSize = "2"; };
    if (background == "0~100")     { this->hex_c = "07";   this->byteSize = "2"; };
    if (background == "0~200")     { this->hex_c = "14";   this->byteSize = "2"; };
    if (background == "RATE")      { this->hex_c = "08";   this->byteSize = "2"; };
    if (background == "PORTAMENTO") {this->hex_c = "11";   this->byteSize = "2"; };
    if (background == "SCALE") {this->hex_c = "15";   this->byteSize = "2"; this->area = "System"; };
    if (background == "SCALE_BASS") {this->hex_c = "16";   this->byteSize = "2"; this->area = "System"; };

    Midi items = midiTable->getMidiMap(this->area, hex1, hex2, hex3);

    this->label->setText(items.customdesc);
    this->label->setUpperCase(true);

    this->knob = new customDataKnob(this, hex1, hex2, hex3, background, this->area);

    this->display->setObjectName("editdisplay");
    this->display->setFixedWidth(lenght);
    this->display->setFixedHeight(16);
    this->display->setAlignment(Qt::AlignCenter);
    this->display->setDisabled(true);

    if(direction == "left")
    {
	
    }
    else if(direction == "right")
    {
        this->label->setAlignment(Qt::AlignLeft);
        this->display->setFixedWidth(lenght);

        QVBoxLayout *displayLayout = new QVBoxLayout;
        displayLayout->setMargin(0);
        displayLayout->setSpacing(0);
        displayLayout->addStretch(0);
        displayLayout->addWidget(this->label, 0, Qt::AlignLeft);
        displayLayout->addWidget(this->display, 0, Qt::AlignLeft);
        displayLayout->addStretch(0);

        QHBoxLayout *mainLayout = new QHBoxLayout;
        mainLayout->setMargin(0);
        mainLayout->setSpacing(0);
        mainLayout->addWidget(this->knob, 0, Qt::AlignCenter);
        mainLayout->addLayout(displayLayout);


        this->setLayout(mainLayout);
        this->setFixedHeight(this->knob->height());

    }
    else if(direction == "top")
    {
	
    }
    else if(direction == "bottom")
    {
        this->label->setAlignment(Qt::AlignCenter);
        this->display->setFixedWidth(lenght);

        QVBoxLayout *mainLayout = new QVBoxLayout;
        mainLayout->setMargin(0);
        mainLayout->setSpacing(0);
        mainLayout->addWidget(this->label, 0, Qt::AlignCenter);
        mainLayout->addWidget(this->knob, 0, Qt::AlignCenter);
        mainLayout->addWidget(this->display, 0, Qt::AlignCenter);
        mainLayout->addStretch(0);

        this->setLayout(mainLayout);
        this->setFixedHeight(this->knob->height() + 16 + 12);

    }
    else if(direction == "System")
    {
        this->label->setAlignment(Qt::AlignCenter);
        this->display->setFixedWidth(lenght);

        QVBoxLayout *mainLayout = new QVBoxLayout;
        mainLayout->setMargin(0);
        mainLayout->setSpacing(0);
        mainLayout->addWidget(this->label, 0, Qt::AlignCenter);
        mainLayout->addWidget(this->knob, 0, Qt::AlignCenter);
        mainLayout->addWidget(this->display, 0, Qt::AlignCenter);
        mainLayout->addStretch(0);

        this->setLayout(mainLayout);
        this->setFixedHeight(this->knob->height() + 16 + 12);
        //this->area = "System";
    };


    QObject::connect(this->parent(), SIGNAL( dialogUpdateSignal() ),
                     this, SLOT( dialogUpdateSignal() ));

    QObject::connect(this, SIGNAL( updateSignal() ),
                     this->parent(), SIGNAL( updateSignal() ));

    QObject::connect(this, SIGNAL( updateDisplay(QString) ),
                     this->display, SLOT( setText(QString) ));
}

void customControlDataKnob::paintEvent(QPaintEvent *)
{
    /*DRAWS RED BACKGROUND FOR DEBUGGING PURPOSE */
    /*QPixmap image(":images/dragbar.png");

	QRectF target(0.0, 0.0, this->width(), this->height());
	QRectF source(0.0, 0.0, this->width(), this->height());

	QPainter painter(this);
	painter.drawPixmap(target, image, source);*/
}

void customControlDataKnob::dialogUpdateSignal()
{
    SysxIO *sysxIO = SysxIO::Instance();
    bool ok;
    QString hex3_msb = QString::number((hex3.toInt(&ok, 16) + 1), 16).toUpper();                // go forward 1 to select target MSB address
    if(hex3_msb.length() < 2) hex3_msb.prepend("0");                                            // prepend with "0" if single digit.
    QString hex3_lsb;
    if (this->byteSize == "3") { hex3_lsb = QString::number((hex3.toInt(&ok, 16) + 2), 16).toUpper();           // go forward 2 to select target LSB address
        if(hex3_lsb.length() < 2) hex3_lsb.prepend("0");   };                                   // prepend with "0" if single digit.

    int value = sysxIO->getSourceValue(this->area, this->hex1, this->hex2, this->hex3);        // read target value as integer from sysx.
    QString valueHex = QString::number(value, 16).toUpper();                                    // convert to hex qstring.
    value = sysxIO->getSourceValue(this->area, this->hex1, this->hex2, hex3_msb);              // read target value as integer from sysx.
    valueHex.append(QString::number(value, 16).toUpper());
    if (this->byteSize == "3") { value = sysxIO->getSourceValue(this->area, this->hex1, this->hex2, hex3_lsb);  // read target value as integer from sysx.
        valueHex.append(QString::number(value, 16).toUpper());  };

    value = valueHex.toInt(&ok, 16);
    this->knob->setValue(value);

    MidiTable *midiTable = MidiTable::Instance();
    QString valueStr = midiTable->getValue("Tables", hex_a, hex_b, hex_c, valueHex);
    emit updateDisplay(valueStr);
}
