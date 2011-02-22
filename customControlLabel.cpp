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

#include "customControlLabel.h"

customControlLabel::customControlLabel(QWidget *parent)
	: QWidget(parent)
{
	this->label = new QLabel(this);
	this->uppercase = false;
	this->button = false;
	this->isImage = false;
	this->offset = 0;

	this->label->setObjectName("customlabel");

	QHBoxLayout *layout = new QHBoxLayout;
	layout->addWidget(this->label);

	QVBoxLayout *mainLayout = new QVBoxLayout;
	mainLayout->addLayout(layout );
	mainLayout->setMargin(0);
	this->setLayout(mainLayout);
	this->setFixedHeight(10);
};

void customControlLabel::paintEvent(QPaintEvent *)
{
	if(button && isImage)
	{
		QRectF target(0.0, 0.0, this->image.width(), this->height());
		QRectF source(0.0, this->offset, this->image.width(), this->height());

		QPainter painter(this);
		painter.drawPixmap(target, this->image, source);
	}
	/*DRAWS RED BACKGROUND FOR DEBUGGING PURPOSE */
	/*else 
	{
		QPixmap image(":images/dragbar.png");
	
		QRectF target(0.0, 0.0, this->width(), this->height());
		QRectF source(0.0, 0.0, this->width(), this->height());

		QPainter painter(this);
		painter.drawPixmap(target, image, source);
	}*/;
};

void customControlLabel::setOffset(int imageNr)
{
	this->offset = imageNr * this->height();
	this->update();
};

void customControlLabel::setUpperCase(bool active)
{
	this->uppercase = active;
	this->setText(this->label->text());
};

void customControlLabel::setAlignment(Qt::Alignment flag)
{
	this->label->setAlignment(flag);
};

void customControlLabel::setText(QString text)
{
	if(this->uppercase)
	{
		this->label->setText(text.toUpper());
	}
	else
	{
		this->label->setText(text);
	};

	setSize();
};

void customControlLabel::setSize()
{
	int pixelWidth = QFontMetrics(this->label->font()).width(this->label->text());
	this->labelWidth = pixelWidth;
};

int customControlLabel::getLabelWidth()
{
	return this->labelWidth;
};

void customControlLabel::setButton(bool button)
{
	this->button = button;
};

void customControlLabel::setImage(QString imagePath)
{
	this->image = QPixmap(imagePath);
	this->isImage = true;
	this->imageHeight = this->image.height() / 4;
	if(button)
	{
		this->setFixedSize(this->image.width(), this->imageHeight);
		setOffset(0);
	}
	else
	{
		this->setFixedSize(this->image.width(), this->image.height());
		this->label->setPixmap(this->image);
	};
};

void customControlLabel::mousePressEvent(QMouseEvent *event)
{
	//event;
	if(isImage && button)
	{
		setOffset(3);
	}
	emit mousePressed();
};

void customControlLabel::mouseReleaseEvent(QMouseEvent *event)
{
	//event;
	if(isImage && button)
	{
		setOffset(2);
	}
	emit mouseReleased();
};

void customControlLabel::enterEvent(QEvent *event)
{
	//event;
	if(button)
	{
		if(isImage)
		{
			setOffset(1);
		}
		else
		{
			//this->labelPal.setColor(this->label->foregroundRole(), Qt::white);
			//this->label->setPalette(labelPal);
			//this->labelFont.setUnderline(true);
			//this->label->setFont(this->labelFont);
		};
	};
};

void customControlLabel::leaveEvent( QEvent *event)
{
	//event;
	if(button)
	{
		if(isImage)
		{
			setOffset(0);
		}
		else
		{
			//this->labelPal.setColor(this->label->foregroundRole(), Qt::white);
			//this->label->setPalette(labelPal);
			//this->labelFont.setUnderline(false);
			//this->label->setFont(this->labelFont);
		};
	};
};
