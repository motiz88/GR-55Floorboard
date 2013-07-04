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

#include "customControlKnob.h"
#include "MidiTable.h"
#include "SysxIO.h"

customControlKnob::customControlKnob(QWidget *parent, 
									 QString hex1, QString hex2, QString hex3, 
									 QString background, QString direction, int lenght)
	: QWidget(parent)
{
	this->display = new QLineEdit(this);
	this->label = new customControlLabel(this);
	this->hex1 = hex1;
	this->hex2 = hex2;
	this->hex3 = hex3;
	this->area = background;

	MidiTable *midiTable = MidiTable::Instance();
	if (this->area != "System") {this->area = "Structure";};
	
	Midi items = midiTable->getMidiMap(this->area, hex1, hex2, hex3);
	
	this->label->setText(items.customdesc);
	this->label->setUpperCase(true);
	
	this->knob = new customKnob(this, hex1, hex2, hex3, background, this->area);
        this->knob->setWhatsThis(tr("hold down mouse button and drag up/down for quick adjustment")
                                 + "<br>" + tr("use scroll wheel or up/down arrow keys for fine adjustment"));

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
	};


	QObject::connect(this->parent(), SIGNAL( dialogUpdateSignal() ),
                this, SLOT( dialogUpdateSignal() ));

	QObject::connect(this, SIGNAL( updateSignal() ),
                this->parent(), SIGNAL( updateSignal() ));

	QObject::connect(this, SIGNAL( updateDisplay(QString) ),
                this->display, SLOT( setText(QString) ));

       // QObject::connect(this, SIGNAL( updateDisplay(QString) ),
                //this->parent(), SLOT( updateDisplay(QString) ));
}

void customControlKnob::paintEvent(QPaintEvent *)
{
	/*DRAWS RED BACKGROUND FOR DEBUGGING PURPOSE */
	/*QPixmap image(":images/dragbar.png");
	
	QRectF target(0.0, 0.0, this->width(), this->height());
	QRectF source(0.0, 0.0, this->width(), this->height());

	QPainter painter(this);
	painter.drawPixmap(target, image, source);*/
}

void customControlKnob::dialogUpdateSignal()
{
	SysxIO *sysxIO = SysxIO::Instance();
	
	int value = sysxIO->getSourceValue(this->area, this->hex1, this->hex2, this->hex3);
	this->knob->setValue(value);

	QString valueHex = QString::number(value, 16).toUpper();
	if(valueHex.length() < 2) valueHex.prepend("0");

	MidiTable *midiTable = MidiTable::Instance();
	QString valueStr = midiTable->getValue(this->area, hex1, hex2, hex3, valueHex);
	
	//this->display->setText(valueStr);
	emit updateDisplay(valueStr);
	//this->valueChanged(value, this->hex1, this->hex2, this->hex3);
}
