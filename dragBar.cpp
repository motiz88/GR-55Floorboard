/****************************************************************************
**
** Copyright (C) 2007~2015 Colin Willcocks.
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

#include "dragBar.h"
#include "Preferences.h"

dragBar::dragBar(QWidget *parent, QString imagePath)
    : QWidget(parent)
{
	QObject::connect(this->parent(), SIGNAL( setCollapseState(bool) ),
                this, SLOT( setCollapseState(bool) ) );
	QObject::connect(this->parent(), SIGNAL( showDragBar(QPoint) ),
                this, SLOT( showDragBar(QPoint) ) );
	QObject::connect(this->parent(), SIGNAL( hideDragBar() ),
                this, SLOT( hideDragBar() ) );

	this->imagePath = imagePath;
	this->image = QPixmap(imagePath);
	this->hide();
}

void dragBar::paintEvent(QPaintEvent *)
{
    Preferences *preferences = Preferences::Instance();
    bool ok;
    const double ratio = preferences->getPreferences("Window", "Scale", "ratio").toDouble(&ok);

    QRectF target(0.0, 0.0, barSize.width()*ratio, (barSize.height())*ratio);
	QRectF source(0.0, 0.0, image.width(), image.height());

	QPainter painter(this);
	painter.drawPixmap(target, image, source);
}

void dragBar::showDragBar(QPoint newpos)
{
    Preferences *preferences = Preferences::Instance();
    bool ok;
    const double ratio = preferences->getPreferences("Window", "Scale", "ratio").toDouble(&ok);

	if(newpos.x() < offsetMin)
	{
        this->barPos = QPoint(offsetMin - (barSize.width()/2*ratio), newpos.y()*ratio);
	}
	else if(newpos.x() > offsetMax)
	{
        this->barPos = QPoint(offsetMax - (barSize.width()/2*ratio), newpos.y()*ratio);
	}
	else
	{
        this->barPos = QPoint(newpos.x() - (barSize.width()/2*ratio), newpos.y()*ratio);
	};
    this->setGeometry(barPos.x(), barPos.y(), barSize.width()*ratio, barSize.height()*ratio);
	this->show();
}

void dragBar::hideDragBar()
{
	this->hide();	
}

void dragBar::setDragBarSize(QSize newsize)
{
	this->barSize = newsize;
}

void dragBar::setDragBarMinOffset(signed int e_offsetMin, signed int c_offsetMin)
{
	this->e_offsetMin = e_offsetMin;
	this->c_offsetMin = c_offsetMin;
	this->offsetMin = e_offsetMin;
}

void dragBar::setDragBarMaxOffset(signed int maxOffset)
{
	this->offsetMax = maxOffset;
}

void dragBar::setCollapseState(bool state)
{
	if(state == false)
	{
		this->offsetMin = c_offsetMin;
	}
	else
	{
		this->offsetMin = e_offsetMin;
	};
}
