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

#include "customSystemOverride.h"
#include "MidiTable.h"
#include "SysxIO.h"

customSystemOverride::customSystemOverride(QWidget *parent,
                                           QString hex1, QString hex2, QString hex3,
                                           QString index, int rowSpan, int columnSpan)
    : QWidget(parent)
{
    this->label = new customControlLabel(this);
    this->label2 = new customControlLabel(this);
    this->hex1 = hex1;
    this->hex2 = hex2;
    this->hex3 = hex3;
    this->index = index;
    this->rowSpan =rowSpan;
    this->columnSpan = columnSpan;

    this->label->setText("OVERRIDE BY");
    this->label2->setText("SYSTEM SETTING");

    this->label->setAlignment(Qt::AlignTop);
    this->label2->setAlignment(Qt::AlignTop);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->setMargin(20);
    mainLayout->setSpacing(0);
    mainLayout->addStretch(0);
    mainLayout->addWidget(this->label, 0, Qt::AlignTop);
    mainLayout->addWidget(this->label2, 0, Qt::AlignTop);
    mainLayout->setSpacing(20);

    this->setLayout(mainLayout);

    QObject::connect(this->parent(), SIGNAL( dialogUpdateSignal() ),
                     this, SLOT( dialogUpdateSignal() ));

    QObject::connect(this->parent(), SIGNAL( updateSignal() ),
                     this, SLOT( dialogUpdateSignal() ));

    QObject::connect(this->parent(), SIGNAL( timerUpdateSignal() ),
                     this, SLOT( dialogUpdateSignal() ));

}

void customSystemOverride::paintEvent(QPaintEvent *)
{
    /*DRAWS BLACK BACKGROUND FOR MASKING */
    QPixmap image(":images/override.png");

    QRectF target(0.0, 0.0, (this->width()*this->columnSpan)/2, (this->height()*this->rowSpan)/2);
    QRectF source(0.0, 0.0, this->width(), this->height());

    QPainter painter(this);
    painter.drawPixmap(target, image, source);
}

void customSystemOverride::dialogUpdateSignal()
{
    SysxIO *sysxIO = SysxIO::Instance();
    bool ok;
    int value = sysxIO->getSourceValue("System", this->hex1, this->hex2, this->hex3);
    int indexValue = this->index.toInt(&ok, 16);
    if(value == indexValue)
    {
        this->hide();
    }
    else
    {
        this->show();
    };
}
