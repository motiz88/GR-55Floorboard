/****************************************************************************
**
** Copyright (C) 2007~2013 Colin Willcocks.
** All rights reserved.
** This file is part of "GT-100 Fx FloorBoard".
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

#include "customControlMidiTable.h"
#include "MidiTable.h"
#include "SysxIO.h"

customControlMidiTable::customControlMidiTable(QWidget *parent,
                                               QString hex1, QString hex2, QString hex3,
                                               QString direction, QString list)
    : QWidget(parent)
{
    this->hex1 = hex1;
    this->hex2 = hex2;
    this->hex3 = hex3;
    this->text = direction;
    this->list = list;

    if(list == "label")
    {
        this->label = new customControlLabel(this);
        this->label->setAlignment(Qt::AlignCenter);
        this->label->setUpperCase(true);

        this->display = new QLineEdit();
        this->display->setObjectName("editdisplay");
        this->display->setFixedWidth(850);
        this->display->setFixedHeight(16);
        this->display->setAlignment(Qt::AlignLeft);
        this->display->setDisabled(true);

        QVBoxLayout *labelLayout = new QVBoxLayout;
        labelLayout->setMargin(0);
        labelLayout->setSpacing(0);
        labelLayout->addStretch(0);
        labelLayout->addWidget(this->label, 0, Qt::AlignCenter);
        labelLayout->addWidget(this->display, 0, Qt::AlignCenter);
        this->setLayout(labelLayout);
        this->setFixedHeight(28);
    }
    else
    {
        setComboBox();
    };
}

void customControlMidiTable::paintEvent(QPaintEvent *)
{
    /*DRAWS RED BACKGROUND FOR DeBugGING PURPOSE */
    /*QPixmap image(":images/dragbar.png");

        QRectF target(0.0, 0.0, this->width(), this->height());
        QRectF source(0.0, 0.0, this->width(), this->height());

        QPainter painter(this);
        painter.drawPixmap(target, image, source);*/
}

void customControlMidiTable::setComboBox()
{
    comboList = list.split(" ");
    comboList.removeLast();

    this->label = new customControlLabel(this);
    this->controlMidiComboBox = new customComboBox(this);
    this->controlMidiComboBox->setObjectName("largecombo");
    this->controlMidiComboBox->setFixedWidth(90);
    this->controlMidiComboBox->setFixedHeight(25);
    this->controlMidiComboBox->setEditable(false);
    this->controlMidiComboBox->setFrame(false);
    this->controlMidiComboBox->setMaxVisibleItems(200);
    this->controlMidiComboBox->addItems(comboList);

    this->label->setUpperCase(true);
    this->label->setText(this->text);
    this->label->setAlignment(Qt::AlignLeft);

    QVBoxLayout *comboLayout = new QVBoxLayout;
    comboLayout->setMargin(0);
    comboLayout->setSpacing(0);
    comboLayout->addStretch(0);
    comboLayout->addWidget(this->label, 0, Qt::AlignCenter);
    comboLayout->addWidget(this->controlMidiComboBox, 0, Qt::AlignCenter);
    this->setLayout(comboLayout);

    QObject::connect(this->parent()->parent(), SIGNAL( dialogUpdateSignal() ), this, SLOT( dialogUpdateSignal() ));

    QObject::connect(this, SIGNAL( updateSignal() ), this->parent(), SIGNAL( updateSignal() ));

    QObject::connect(this->controlMidiComboBox, SIGNAL(currentIndexChanged(int)), this, SIGNAL(currentIndexChanged(int)));

    //QObject::connect(this->controlMidiComboBox, SIGNAL(highlighted(int)), this, SIGNAL(currentIndexChanged(int)));

    if(text != "GR-55 Patch") {
      QObject::connect(this->controlMidiComboBox, SIGNAL(currentIndexChanged(int)), this->parent(), SLOT(changedIndex(int)));

      //QObject::connect(this->controlMidiComboBox, SIGNAL(highlighted(int)), this->parent(), SLOT(changedIndex(int)));
        } else {
      QObject::connect(this->controlMidiComboBox, SIGNAL(currentIndexChanged(int)), this->parent(), SLOT(valueChanged(int)));

      //QObject::connect(this->controlMidiComboBox, SIGNAL(highlighted(int)), this->parent(), SLOT(valueChanged(int)));
     };
}

void customControlMidiTable::valueChanged(int index)
{

}

void customControlMidiTable::dialogUpdateSignal()
{
    if(text == "GR-55 Patch")
    {
        //SysxIO *sysxIO = SysxIO::Instance();
        int index = 1;//sysxIO->getSourceValue("MidiT", hex1, hex2, hex3);
        this->controlMidiComboBox->setCurrentIndex(index);
        this->valueChanged(index);
    };
}






