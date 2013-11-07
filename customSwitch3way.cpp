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

#include <QtWidgets>

#include "customSwitch3way.h"

customSwitch3way::customSwitch3way(int active, QPoint switch3wayPos, QWidget *parent,
					 QString imagePath)
    : QWidget(parent)
{
	this->active = active;
	this->imagePath = imagePath;
	QSize imageSize = QPixmap(imagePath).size();
	this->switch3waySize = QSize(imageSize.width(), imageSize.height()/4);
	this->switch3wayPos = switch3wayPos;

	setOffset(0);
	setGeometry(switch3wayPos.x(), switch3wayPos.y(), switch3waySize.width(), switch3waySize.height());

}

void customSwitch3way::paintEvent(QPaintEvent *)
{
	QRectF target(0.0 , 0.0, switch3waySize.width(), switch3waySize.height());
	QRectF source(0.0, yOffset, switch3waySize.width(), switch3waySize.height());
	QPixmap image(imagePath);
    //image.setMask(image.mask());

	QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing, true);
	painter.drawPixmap(target, image, source);
}

void customSwitch3way::setOffset(signed int imageNr)
{
	this->yOffset = imageNr*switch3waySize.height();
	this->update();
}

void customSwitch3way::setValue(int value)
{
	this->active = value;
	if(active == 2)
	{
                setOffset(2);
	}
	else if(active == 1)
	{
                setOffset(1);
	}
	else
	{
                setOffset(0);
	};
}

void customSwitch3way::changeValue(int value)
{
	setValue(value);
}
