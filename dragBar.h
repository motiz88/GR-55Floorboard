/****************************************************************************
**
** Copyright (C) 2007~2010 Colin Willcocks.
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

#ifndef DRAGBAR_H
#define DRAGBAR_H

#include <QtGui>
#include <QWidget>

class dragBar : public QWidget
{
    Q_OBJECT

public:
	dragBar(QWidget *parent = 0,
		QString imagePath = ":/images/dragbar.png");
	void setDragBarSize(QSize newsize);
	void setDragBarMinOffset(signed int e_offsetMin, signed int c_offsetMin);
	void setDragBarMaxOffset(signed int offsetMax);

public slots:
	void showDragBar(QPoint newpos);
	void hideDragBar();
	void setCollapseState(bool state);

protected:
	void paintEvent(QPaintEvent *event);

private:
	QSize barSize;
	QPoint barPos;
	signed int c_offsetMin;
	signed int e_offsetMin;
	signed int offsetMin;
	signed int offsetMax;

	QString imagePath;
	QPixmap image;
};

#endif // DRAGBAR_H
