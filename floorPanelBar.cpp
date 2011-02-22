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

#include "floorPanelBar.h"
#include "floorPanelBarButton.h"

floorPanelBar::floorPanelBar(QWidget *parent, QString imagePathPanelBar, QSize panelBarSize)
    : QWidget(parent)
{
	this->imagePathPanelBar = imagePathPanelBar;
	this->image = QPixmap(imagePathPanelBar);

	int yPos =  panelBarSize.height()/2;
	floorPanelBarButton *button = new floorPanelBarButton(false, QPoint(0, yPos - 22), this);
  button = button;

	this->setFixedSize(panelBarSize);
	this->setCursor(Qt::SplitHCursor);
};

void floorPanelBar::paintEvent(QPaintEvent *)
{
	QRectF target(0.0, 0.0, panelBarSize.width(), panelBarSize.height());
	QRectF source(0.0, 0.0, panelBarSize.width(), panelBarSize.height());

	QPainter painter(this);
	painter.drawPixmap(target, image, source);
};

void floorPanelBar::setPos(QPoint newPos)
{
	this->move(newPos);
};

void floorPanelBar::mousePressEvent(QMouseEvent *event) 
{ 
	if (event->button() == Qt::LeftButton) this->dragStartPosition = event->pos(); 
	QPoint mousePoint = event->pos();
	emit showDragBar( QPoint(this->x() + mousePoint.x(), this->y()) );
};

void floorPanelBar::mouseDoubleClickEvent(QMouseEvent *event) 
{ 
	if (event->button() == Qt::LeftButton) 
	{
		emit collapseSignal();
	}; 
};

void floorPanelBar::mouseMoveEvent(QMouseEvent *event)
{
    if ( event->buttons() == Qt::LeftButton && 
		(event->pos() - dragStartPosition).manhattanLength() > QApplication::startDragDistance() )
	{
		QPoint mousePoint = event->pos();
		emit showDragBar( QPoint(this->x() + mousePoint.x(), this->y()) );
	};
};

void floorPanelBar::mouseReleaseEvent(QMouseEvent *event) 
{ 
	if ( event->button() == Qt::LeftButton && 
		(event->pos() - dragStartPosition).manhattanLength() > QApplication::startDragDistance() ) 
	{
		QPoint mousePoint = event->pos();
		setValue( mousePoint.x() - dragStartPosition.x() );
	}; 
	emit hideDragBar();
};

void floorPanelBar::setValue(int value)
{
    if (value != r_value) {
        this->r_value = value;
		emit resizeSignal((int)(value));
    };
};
