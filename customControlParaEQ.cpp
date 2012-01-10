/****************************************************************************
**
** Copyright (C) 2007~2012 Colin Willcocks.
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

#include "customControlParaEQ.h"
#include "MidiTable.h"
#include "SysxIO.h"

customControlParaEQ::customControlParaEQ(QWidget *parent, 
                                 QString hex1, QString hex2, QString hex3,
                                 QString background, QString direction, int lenght)
                                     : QWidget(parent)
{
    this->hex1 = hex1;
    this->hex2 = hex2;
    this->hex3 = hex3;
    this->area = background;
    bool ok;
    int x = hex3.toInt(&ok, 16);
    this->hex_1 = QString::number(x, 16).toUpper();   /**** set EQ address range from hex3 (lowcut address) ****/
    if(hex_1.length() < 2) hex_1.prepend("0");
    this->hex_2 = QString::number(x+1, 16).toUpper();
    if(hex_2.length() < 2) hex_2.prepend("0");
    this->hex_3 = QString::number(x+2, 16).toUpper();
    if(hex_3.length() < 2) hex_3.prepend("0");
    this->hex_4 = QString::number(x+3, 16).toUpper();
    if(hex_4.length() < 2) hex_4.prepend("0");
    this->hex_5 = QString::number(x+4, 16).toUpper();
    if(hex_5.length() < 2) hex_5.prepend("0");
    this->hex_6 = QString::number(x+5, 16).toUpper();
    if(hex_6.length() < 2) hex_6.prepend("0");
    this->hex_7 = QString::number(x+6, 16).toUpper();
    if(hex_7.length() < 2) hex_7.prepend("0");
    this->hex_8 = QString::number(x+7, 16).toUpper();
    if(hex_8.length() < 2) hex_8.prepend("0");
    this->hex_9 = QString::number(x+8, 16).toUpper();
    if(hex_9.length() < 2) hex_9.prepend("0");
    this->hex_10 = QString::number(x+9, 16).toUpper();
    if(hex_10.length() < 2) hex_10.prepend("0");
    this->hex_11 = QString::number(x+10, 16).toUpper();
    if(hex_11.length() < 2) hex_11.prepend("0");

    MidiTable *midiTable = MidiTable::Instance();
    if (this->area != "System") {this->area = "Structure";};

    Midi items = midiTable->getMidiMap(this->area, hex1, hex2, hex_1);
    this->label_1 = new customControlLabel(this);
    this->label_1->setText(items.customdesc);
    this->label_1->setUpperCase(true);
    this->label_1->setAlignment(Qt::AlignCenter);
    this->knob_1 = new customKnob(this, hex1, hex2, hex_1, background, this->area);
    this->display_1 = new QLineEdit(this);
    this->display_1->setObjectName("editdisplay");
    this->display_1->setFixedWidth(lenght);
    this->display_1->setFixedHeight(13);
    this->display_1->setAlignment(Qt::AlignCenter);
    this->display_1->setDisabled(true);
    this->display_1->setFixedWidth(lenght);

    QVBoxLayout *knob_1Layout = new QVBoxLayout;
    knob_1Layout->setMargin(0);
    knob_1Layout->setSpacing(0);
    knob_1Layout->addWidget(this->label_1, 0, Qt::AlignCenter);
    knob_1Layout->addWidget(this->knob_1, 0, Qt::AlignCenter);
    knob_1Layout->addWidget(this->display_1, 0, Qt::AlignCenter);
    knob_1Layout->addStretch(0);

    items = midiTable->getMidiMap(this->area, hex1, hex2, hex_2);
    this->label_2 = new customControlLabel(this);
    this->label_2->setText(items.customdesc);
    this->label_2->setUpperCase(true);
    this->label_2->setAlignment(Qt::AlignCenter);
    this->knob_2 = new customKnob(this, hex1, hex2, hex_2, background, this->area);
    this->display_2 = new QLineEdit(this);
    this->display_2->setObjectName("editdisplay");
    this->display_2->setFixedWidth(lenght);
    this->display_2->setFixedHeight(13);
    this->display_2->setAlignment(Qt::AlignCenter);
    this->display_2->setDisabled(true);
    this->display_2->setFixedWidth(lenght);

    QVBoxLayout *knob_2Layout = new QVBoxLayout;
    knob_2Layout->setMargin(0);
    knob_2Layout->setSpacing(0);
    knob_2Layout->addWidget(this->label_2, 0, Qt::AlignCenter);
    knob_2Layout->addWidget(this->knob_2, 0, Qt::AlignCenter);
    knob_2Layout->addWidget(this->display_2, 0, Qt::AlignCenter);
    knob_2Layout->addStretch(0);

    items = midiTable->getMidiMap(this->area, hex1, hex2, hex_3);
    this->label_3 = new customControlLabel(this);
    this->label_3->setText(items.customdesc);
    this->label_3->setUpperCase(true);
    this->label_3->setAlignment(Qt::AlignCenter);
    this->knob_3 = new customKnob(this, hex1, hex2, hex_3, background, this->area);
    this->display_3 = new QLineEdit(this);
    this->display_3->setObjectName("editdisplay");
    this->display_3->setFixedWidth(lenght);
    this->display_3->setFixedHeight(13);
    this->display_3->setAlignment(Qt::AlignCenter);
    this->display_3->setDisabled(true);
    this->display_3->setFixedWidth(lenght);

    QVBoxLayout *knob_3Layout = new QVBoxLayout;
    knob_3Layout->setMargin(0);
    knob_3Layout->setSpacing(0);
    knob_3Layout->addWidget(this->label_3, 0, Qt::AlignCenter);
    knob_3Layout->addWidget(this->knob_3, 0, Qt::AlignCenter);
    knob_3Layout->addWidget(this->display_3, 0, Qt::AlignCenter);
    knob_3Layout->addStretch(0);

    items = midiTable->getMidiMap(this->area, hex1, hex2, hex_4);
    this->label_4 = new customControlLabel(this);
    this->label_4->setText(items.customdesc);
    this->label_4->setUpperCase(true);
    this->label_4->setAlignment(Qt::AlignCenter);
    this->knob_4 = new customKnob(this, hex1, hex2, hex_4, background, this->area);
    this->display_4 = new QLineEdit(this);
    this->display_4->setObjectName("editdisplay");
    this->display_4->setFixedWidth(lenght);
    this->display_4->setFixedHeight(13);
    this->display_4->setAlignment(Qt::AlignCenter);
    this->display_4->setDisabled(true);
    this->display_4->setFixedWidth(lenght);

    QVBoxLayout *knob_4Layout = new QVBoxLayout;
    knob_4Layout->setMargin(0);
    knob_4Layout->setSpacing(0);
    knob_4Layout->addWidget(this->label_4, 0, Qt::AlignCenter);
    knob_4Layout->addWidget(this->knob_4, 0, Qt::AlignCenter);
    knob_4Layout->addWidget(this->display_4, 0, Qt::AlignCenter);
    knob_4Layout->addStretch(0);

    items = midiTable->getMidiMap(this->area, hex1, hex2, hex_5);
    this->label_5 = new customControlLabel(this);
    this->label_5->setText(items.customdesc);
    this->label_5->setUpperCase(true);
    this->label_5->setAlignment(Qt::AlignCenter);
    this->knob_5 = new customKnob(this, hex1, hex2, hex_5, background, this->area);
    this->display_5 = new QLineEdit(this);
    this->display_5->setObjectName("editdisplay");
    this->display_5->setFixedWidth(lenght);
    this->display_5->setFixedHeight(13);
    this->display_5->setAlignment(Qt::AlignCenter);
    this->display_5->setDisabled(true);
    this->display_5->setFixedWidth(lenght);

    QVBoxLayout *knob_5Layout = new QVBoxLayout;
    knob_5Layout->setMargin(0);
    knob_5Layout->setSpacing(0);
    knob_5Layout->addWidget(this->label_5, 0, Qt::AlignCenter);
    knob_5Layout->addWidget(this->knob_5, 0, Qt::AlignCenter);
    knob_5Layout->addWidget(this->display_5, 0, Qt::AlignCenter);
    knob_5Layout->addStretch(0);

    items = midiTable->getMidiMap(this->area, hex1, hex2, hex_6);
    this->label_6 = new customControlLabel(this);
    this->label_6->setText(items.customdesc);
    this->label_6->setUpperCase(true);
    this->label_6->setAlignment(Qt::AlignCenter);
    this->knob_6 = new customKnob(this, hex1, hex2, hex_6, background, this->area);
    this->display_6 = new QLineEdit(this);
    this->display_6->setObjectName("editdisplay");
    this->display_6->setFixedWidth(lenght);
    this->display_6->setFixedHeight(13);
    this->display_6->setAlignment(Qt::AlignCenter);
    this->display_6->setDisabled(true);
    this->display_6->setFixedWidth(lenght);

    QVBoxLayout *knob_6Layout = new QVBoxLayout;
    knob_6Layout->setMargin(0);
    knob_6Layout->setSpacing(0);
    knob_6Layout->addWidget(this->label_6, 0, Qt::AlignCenter);
    knob_6Layout->addWidget(this->knob_6, 0, Qt::AlignCenter);
    knob_6Layout->addWidget(this->display_6, 0, Qt::AlignCenter);
    knob_6Layout->addStretch(0);

    items = midiTable->getMidiMap(this->area, hex1, hex2, hex_7);
    this->label_7 = new customControlLabel(this);
    this->label_7->setText(items.customdesc);
    this->label_7->setUpperCase(true);
    this->label_7->setAlignment(Qt::AlignCenter);
    this->knob_7 = new customKnob(this, hex1, hex2, hex_7, background, this->area);
    this->display_7 = new QLineEdit(this);
    this->display_7->setObjectName("editdisplay");
    this->display_7->setFixedWidth(lenght);
    this->display_7->setFixedHeight(13);
    this->display_7->setAlignment(Qt::AlignCenter);
    this->display_7->setDisabled(true);
    this->display_7->setFixedWidth(lenght);

    QVBoxLayout *knob_7Layout = new QVBoxLayout;
    knob_7Layout->setMargin(0);
    knob_7Layout->setSpacing(0);
    knob_7Layout->addWidget(this->label_7, 0, Qt::AlignCenter);
    knob_7Layout->addWidget(this->knob_7, 0, Qt::AlignCenter);
    knob_7Layout->addWidget(this->display_7, 0, Qt::AlignCenter);
    knob_7Layout->addStretch(0);

    items = midiTable->getMidiMap(this->area, hex1, hex2, hex_8);
    this->label_8 = new customControlLabel(this);
    this->label_8->setText(items.customdesc);
    this->label_8->setUpperCase(true);
    this->label_8->setAlignment(Qt::AlignCenter);
    this->knob_8 = new customKnob(this, hex1, hex2, hex_8, background, this->area);
    this->display_8 = new QLineEdit(this);
    this->display_8->setObjectName("editdisplay");
    this->display_8->setFixedWidth(lenght);
    this->display_8->setFixedHeight(13);
    this->display_8->setAlignment(Qt::AlignCenter);
    this->display_8->setDisabled(true);
    this->display_8->setFixedWidth(lenght);

    QVBoxLayout *knob_8Layout = new QVBoxLayout;
    knob_8Layout->setMargin(0);
    knob_8Layout->setSpacing(0);
    knob_8Layout->addWidget(this->label_8, 0, Qt::AlignCenter);
    knob_8Layout->addWidget(this->knob_8, 0, Qt::AlignCenter);
    knob_8Layout->addWidget(this->display_8, 0, Qt::AlignCenter);
    knob_8Layout->addStretch(0);

    items = midiTable->getMidiMap(this->area, hex1, hex2, hex_9);
    this->label_9 = new customControlLabel(this);
    this->label_9->setText(items.customdesc);
    this->label_9->setUpperCase(true);
    this->label_9->setAlignment(Qt::AlignCenter);
    this->knob_9 = new customKnob(this, hex1, hex2, hex_9, background, this->area);
    this->display_9 = new QLineEdit(this);
    this->display_9->setObjectName("editdisplay");
    this->display_9->setFixedWidth(lenght);
    this->display_9->setFixedHeight(13);
    this->display_9->setAlignment(Qt::AlignCenter);
    this->display_9->setDisabled(true);
    this->display_9->setFixedWidth(lenght);

    QVBoxLayout *knob_9Layout = new QVBoxLayout;
    knob_9Layout->setMargin(0);
    knob_9Layout->setSpacing(0);
    knob_9Layout->addWidget(this->label_9, 0, Qt::AlignCenter);
    knob_9Layout->addWidget(this->knob_9, 0, Qt::AlignCenter);
    knob_9Layout->addWidget(this->display_9, 0, Qt::AlignCenter);
    knob_9Layout->addStretch(0);

    items = midiTable->getMidiMap(this->area, hex1, hex2, hex_10);
    this->label_10 = new customControlLabel(this);
    this->label_10->setText(items.customdesc);
    this->label_10->setUpperCase(true);
    this->label_10->setAlignment(Qt::AlignCenter);
    this->knob_10 = new customKnob(this, hex1, hex2, hex_10, background, this->area);
    this->display_10 = new QLineEdit(this);
    this->display_10->setObjectName("editdisplay");
    this->display_10->setFixedWidth(lenght);
    this->display_10->setFixedHeight(13);
    this->display_10->setAlignment(Qt::AlignCenter);
    this->display_10->setDisabled(true);
    this->display_10->setFixedWidth(lenght);

    QVBoxLayout *knob_10Layout = new QVBoxLayout;
    knob_10Layout->setMargin(0);
    knob_10Layout->setSpacing(0);
    knob_10Layout->addWidget(this->label_10, 0, Qt::AlignCenter);
    knob_10Layout->addWidget(this->knob_10, 0, Qt::AlignCenter);
    knob_10Layout->addWidget(this->display_10, 0, Qt::AlignCenter);
    knob_10Layout->addStretch(0);

    items = midiTable->getMidiMap(this->area, hex1, hex2, hex_11);
    this->label_11 = new customControlLabel(this);
    this->label_11->setText(items.customdesc);
    this->label_11->setUpperCase(true);
    this->label_11->setAlignment(Qt::AlignCenter);
    this->knob_11 = new customKnob(this, hex1, hex2, hex_11, background, this->area);
    this->display_11 = new QLineEdit(this);
    this->display_11->setObjectName("editdisplay");
    this->display_11->setFixedWidth(lenght);
    this->display_11->setFixedHeight(13);
    this->display_11->setAlignment(Qt::AlignCenter);
    this->display_11->setDisabled(true);
    this->display_11->setFixedWidth(lenght);

    QVBoxLayout *knob_11Layout = new QVBoxLayout;
    knob_11Layout->setMargin(0);
    knob_11Layout->setSpacing(0);
    knob_11Layout->addWidget(this->label_11, 0, Qt::AlignCenter);
    knob_11Layout->addWidget(this->knob_11, 0, Qt::AlignCenter);
    knob_11Layout->addWidget(this->display_11, 0, Qt::AlignCenter);
    knob_11Layout->addStretch(0);



    QHBoxLayout *knobLayout = new QHBoxLayout;
    knobLayout->setMargin(0);
    knobLayout->setSpacing(10);
    knobLayout->addLayout(knob_1Layout);  //LowCut
    knobLayout->addLayout(knob_2Layout);  //LowGain

    knobLayout->addLayout(knob_3Layout);  //LowMidFreq
    knobLayout->addLayout(knob_4Layout);  //LowMidQ
    knobLayout->addLayout(knob_5Layout);  //LowMidGain

    knobLayout->addLayout(knob_6Layout);  //HighMidFreq
    knobLayout->addLayout(knob_7Layout);  //HighMidQ
    knobLayout->addLayout(knob_8Layout);  //HighMidGain
    knobLayout->addLayout(knob_9Layout);  //HighGain
    knobLayout->addLayout(knob_10Layout); //HighCut
    knobLayout->addLayout(knob_11Layout); //Level
    knobLayout->addStretch(0);


    this->frame = new customParaEQGraph(this);
    this->frame->setMinimumSize(QSize(600, 180));

    QVBoxLayout *frameLayout = new QVBoxLayout;
    frameLayout->setMargin(0);
    frameLayout->setSpacing(10);
    frameLayout->addWidget(this->frame, 0, Qt::AlignCenter);
    frameLayout->addLayout(knobLayout);

    this->setLayout(frameLayout);

    QObject::connect(this->parent(), SIGNAL( dialogUpdateSignal() ),
                     this, SLOT( dialogUpdateSignal() ));

    QObject::connect(this, SIGNAL( updateSignal() ),
                     this->parent(), SIGNAL( updateSignal() ));

    QObject::connect(this, SIGNAL( updateDisplay(QString) ),
                      this, SLOT( dialogUpdateSignal() ));

    QObject::connect(this, SIGNAL( updateDisplay_1(QString) ),
                     this->display_1, SLOT( setText(QString) ));

    QObject::connect(this, SIGNAL( updateDisplay_2(QString) ),
                     this->display_2, SLOT( setText(QString) ));

    QObject::connect(this, SIGNAL( updateDisplay_3(QString) ),
                     this->display_3, SLOT( setText(QString) ));

    QObject::connect(this, SIGNAL( updateDisplay_4(QString) ),
                     this->display_4, SLOT( setText(QString) ));

    QObject::connect(this, SIGNAL( updateDisplay_5(QString) ),
                     this->display_5, SLOT( setText(QString) ));

    QObject::connect(this, SIGNAL( updateDisplay_6(QString) ),
                     this->display_6, SLOT( setText(QString) ));

    QObject::connect(this, SIGNAL( updateDisplay_7(QString) ),
                     this->display_7, SLOT( setText(QString) ));

    QObject::connect(this, SIGNAL( updateDisplay_8(QString) ),
                     this->display_8, SLOT( setText(QString) ));

    QObject::connect(this, SIGNAL( updateDisplay_9(QString) ),
                     this->display_9, SLOT( setText(QString) ));

    QObject::connect(this, SIGNAL( updateDisplay_10(QString) ),
                     this->display_10, SLOT( setText(QString) ));

    QObject::connect(this, SIGNAL( updateDisplay_11(QString) ),
                     this->display_11, SLOT( setText(QString) ));

    QObject::connect(this, SIGNAL( graphUpdateSignal(QString, QString, QString, QString, QString,
                                                     QString, QString, QString, QString, QString, QString) ),
                     this->frame, SLOT( updateSlot(QString, QString, QString, QString, QString,
                                                   QString, QString, QString, QString, QString, QString) ));

    QObject::connect(this->frame, SIGNAL(LowCutChanged(unsigned short)),
                     this, SLOT(LowCutChanged(unsigned short) ));

    QObject::connect(this->frame, SIGNAL(LowGainChanged(unsigned short)),
                     this, SLOT(LowGainChanged(unsigned short) ));

    QObject::connect(this->frame, SIGNAL(HighMidFreqChanged(unsigned short)),
                     this, SLOT(HighMidFreqChanged(unsigned short) ));

    QObject::connect(this->frame, SIGNAL(HighMidQChanged(unsigned short)),
                     this, SLOT(HighMidQChanged(unsigned short) ));

    QObject::connect(this->frame, SIGNAL(HighMidGainChanged(unsigned short)),
                     this, SLOT(HighMidGainChanged(unsigned short) ));

    QObject::connect(this->frame, SIGNAL(LowMidFreqChanged(unsigned short)),
                     this, SLOT(LowMidFreqChanged(unsigned short) ));

    QObject::connect(this->frame, SIGNAL(LowMidQChanged(unsigned short)),
                     this, SLOT(LowMidQChanged(unsigned short) ));

    QObject::connect(this->frame, SIGNAL(LowMidGainChanged(unsigned short)),
                     this, SLOT(LowMidGainChanged(unsigned short) ));

    QObject::connect(this->frame, SIGNAL(HighGainChanged(unsigned short)),
                     this, SLOT(HighGainChanged(unsigned short) ));

    QObject::connect(this->frame, SIGNAL(HighCutChanged(unsigned short)),
                     this, SLOT(HighCutChanged(unsigned short) ));

    QObject::connect(this->frame, SIGNAL(LevelChanged(unsigned short)),
                     this, SLOT(LevelChanged(unsigned short) ));

};


void customControlParaEQ::paintEvent(QPaintEvent *)
{
    /*DRAWS RED BACKGROUND FOR DEBUGGING PURPOSE */
    /*QPixmap image(":images/dragbar.png");

	QRectF target(0.0, 0.0, this->width(), this->height());
	QRectF source(0.0, 0.0, this->width(), this->height());

	QPainter painter(this);
	painter.drawPixmap(target, image, source);*/


};

void customControlParaEQ::dialogUpdateSignal()
{
    SysxIO *sysxIO = SysxIO::Instance();
    MidiTable *midiTable = MidiTable::Instance();
    int value;
    QString valueHex;
    QString valueStr;

    value = sysxIO->getSourceValue(this->area, this->hex1, this->hex2, this->hex_1);
    this->knob_1->setValue(value);
    valueHex = QString::number(value, 16).toUpper();
    if(valueHex.length() < 2) valueHex.prepend("0");
    QString data_1 = valueHex;
    valueStr = midiTable->getValue(this->area, hex1, hex2, hex_1, valueHex);
    emit updateDisplay_1(valueStr);

    value = sysxIO->getSourceValue(this->area, this->hex1, this->hex2, this->hex_2);
    this->knob_2->setValue(value);
    valueHex = QString::number(value, 16).toUpper();
    if(valueHex.length() < 2) valueHex.prepend("0");
    QString data_2 = valueHex;
    valueStr = midiTable->getValue(this->area, hex1, hex2, hex_2, valueHex);
    emit updateDisplay_2(valueStr);

    value = sysxIO->getSourceValue(this->area, this->hex1, this->hex2, this->hex_3);
    this->knob_3->setValue(value);
    valueHex = QString::number(value, 16).toUpper();
    if(valueHex.length() < 2) valueHex.prepend("0");
    QString data_3 = valueHex;
    valueStr = midiTable->getValue(this->area, hex1, hex2, hex_3, valueHex);
    emit updateDisplay_3(valueStr);

    value = sysxIO->getSourceValue(this->area, this->hex1, this->hex2, this->hex_4);
    this->knob_4->setValue(value);
    valueHex = QString::number(value, 16).toUpper();
    if(valueHex.length() < 2) valueHex.prepend("0");
    QString data_4 = valueHex;
    valueStr = midiTable->getValue(this->area, hex1, hex2, hex_4, valueHex);
    emit updateDisplay_4(valueStr);

    value = sysxIO->getSourceValue(this->area, this->hex1, this->hex2, this->hex_5);
    this->knob_5->setValue(value);
    valueHex = QString::number(value, 16).toUpper();
    if(valueHex.length() < 2) valueHex.prepend("0");
    QString data_5 = valueHex;
    valueStr = midiTable->getValue(this->area, hex1, hex2, hex_5, valueHex);
    emit updateDisplay_5(valueStr);

    value = sysxIO->getSourceValue(this->area, this->hex1, this->hex2, this->hex_6);
    this->knob_6->setValue(value);
    valueHex = QString::number(value, 16).toUpper();
    if(valueHex.length() < 2) valueHex.prepend("0");
    QString data_6 = valueHex;
    valueStr = midiTable->getValue(this->area, hex1, hex2, hex_6, valueHex);
    emit updateDisplay_6(valueStr);

    value = sysxIO->getSourceValue(this->area, this->hex1, this->hex2, this->hex_7);
    this->knob_7->setValue(value);
    valueHex = QString::number(value, 16).toUpper();
    if(valueHex.length() < 2) valueHex.prepend("0");
    QString data_7 = valueHex;
    valueStr = midiTable->getValue(this->area, hex1, hex2, hex_7, valueHex);
    emit updateDisplay_7(valueStr);

    value = sysxIO->getSourceValue(this->area, this->hex1, this->hex2, this->hex_8);
    this->knob_8->setValue(value);
    valueHex = QString::number(value, 16).toUpper();
    if(valueHex.length() < 2) valueHex.prepend("0");
    QString data_8 = valueHex;
    valueStr = midiTable->getValue(this->area, hex1, hex2, hex_8, valueHex);
    emit updateDisplay_8(valueStr);

    value = sysxIO->getSourceValue(this->area, this->hex1, this->hex2, this->hex_9);
    this->knob_9->setValue(value);
    valueHex = QString::number(value, 16).toUpper();
    if(valueHex.length() < 2) valueHex.prepend("0");
    QString data_9 = valueHex;
    valueStr = midiTable->getValue(this->area, hex1, hex2, hex_9, valueHex);
    emit updateDisplay_9(valueStr);

    value = sysxIO->getSourceValue(this->area, this->hex1, this->hex2, this->hex_10);
    this->knob_10->setValue(value);
    valueHex = QString::number(value, 16).toUpper();
    if(valueHex.length() < 2) valueHex.prepend("0");
    QString data_10 = valueHex;
    valueStr = midiTable->getValue(this->area, hex1, hex2, hex_10, valueHex);
    emit updateDisplay_10(valueStr);

    value = sysxIO->getSourceValue(this->area, this->hex1, this->hex2, this->hex_11);
    this->knob_11->setValue(value);
    valueHex = QString::number(value, 16).toUpper();
    if(valueHex.length() < 2) valueHex.prepend("0");
    QString data_11 = valueHex;
    valueStr = midiTable->getValue(this->area, hex1, hex2, hex_11, valueHex);
    emit updateDisplay_11(valueStr);

    emit graphUpdateSignal( data_1, data_2, data_3, data_4, data_5,
                            data_6, data_7, data_8, data_9, data_10, data_11);

};

void customControlParaEQ::LowCutChanged(unsigned short iLowCut)
{
    QString hex = QString::number(iLowCut, 16).toUpper();
    if (hex.size() < 2) hex.prepend("0");
    SysxIO *sysxIO = SysxIO::Instance();
    sysxIO->setFileSource(this->area, hex1, hex2, hex_1, hex);
    emit dialogUpdateSignal();
};

void customControlParaEQ::LowGainChanged(unsigned short iLowGain)
{
    QString hex = QString::number(iLowGain, 16).toUpper();
    if (hex.size() < 2) hex.prepend("0");
    SysxIO *sysxIO = SysxIO::Instance();
    sysxIO->setFileSource(this->area, hex1, hex2, hex_2, hex);
    emit dialogUpdateSignal();
};

void customControlParaEQ::LowMidFreqChanged(unsigned short iLowMidFreq)
{
    QString hex = QString::number(iLowMidFreq, 16).toUpper();
    if (hex.size() < 2) hex.prepend("0");
    SysxIO *sysxIO = SysxIO::Instance();
    sysxIO->setFileSource(this->area, hex1, hex2, hex_3, hex);
    emit dialogUpdateSignal();
};

void customControlParaEQ::LowMidQChanged(unsigned short iLowMidQ)
{
    QString hex = QString::number(iLowMidQ, 16).toUpper();
    if (hex.size() < 2) hex.prepend("0");
    SysxIO *sysxIO = SysxIO::Instance();
    sysxIO->setFileSource(this->area, hex1, hex2, hex_4, hex);
    emit dialogUpdateSignal();
};

void customControlParaEQ::LowMidGainChanged(unsigned short iLowMidGain)
{
    QString hex = QString::number(iLowMidGain, 16).toUpper();
    if (hex.size() < 2) hex.prepend("0");
    SysxIO *sysxIO = SysxIO::Instance();
    sysxIO->setFileSource(this->area, hex1, hex2, hex_5, hex);
    emit dialogUpdateSignal();
};

void customControlParaEQ::HighMidFreqChanged(unsigned short iHighMidFreq)
{
    QString hex = QString::number(iHighMidFreq, 16).toUpper();
    if (hex.size() < 2) hex.prepend("0");
    SysxIO *sysxIO = SysxIO::Instance();
    sysxIO->setFileSource(this->area, hex1, hex2, hex_6, hex);
    emit dialogUpdateSignal();
};

void customControlParaEQ::HighMidQChanged(unsigned short iHighMidQ)
{
    QString hex = QString::number(iHighMidQ, 16).toUpper();
    if (hex.size() < 2) hex.prepend("0");
    SysxIO *sysxIO = SysxIO::Instance();
    sysxIO->setFileSource(this->area, hex1, hex2, hex_7, hex);
    emit dialogUpdateSignal();
};

void customControlParaEQ::HighMidGainChanged(unsigned short iHighMidGain)
{
    QString hex = QString::number(iHighMidGain, 16).toUpper();
    if (hex.size() < 2) hex.prepend("0");
    SysxIO *sysxIO = SysxIO::Instance();
    sysxIO->setFileSource(this->area, hex1, hex2, hex_8, hex);
    emit dialogUpdateSignal();
};

void customControlParaEQ::HighGainChanged(unsigned short iHighGain)
{
    QString hex = QString::number(iHighGain, 16).toUpper();
    if (hex.size() < 2) hex.prepend("0");
    SysxIO *sysxIO = SysxIO::Instance();
    sysxIO->setFileSource(this->area, hex1, hex2, hex_9, hex);
    emit dialogUpdateSignal();
};

void customControlParaEQ::HighCutChanged(unsigned short iHighCut)
{
    QString hex = QString::number(iHighCut, 16).toUpper();
    if (hex.size() < 2) hex.prepend("0");
    SysxIO *sysxIO = SysxIO::Instance();
    sysxIO->setFileSource(this->area, hex1, hex2, hex_10, hex);
    emit dialogUpdateSignal();
};

void customControlParaEQ::LevelChanged(unsigned short iLevel)
{
    QString hex = QString::number(iLevel, 16).toUpper();
    if (hex.size() < 2) hex.prepend("0");
    SysxIO *sysxIO = SysxIO::Instance();
    sysxIO->setFileSource(this->area, hex1, hex2, hex_11, hex);
    emit dialogUpdateSignal();
};


