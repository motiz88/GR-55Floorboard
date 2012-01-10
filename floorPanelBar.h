/****************************************************************************
**
** Copyright (C) 2007~2012 Colin Willcocks.
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

#ifndef FLOORPANELBAR_H
#define FLOORPANELBAR_H

#include <QtGui>
#include <QWidget>
#include <QPixmap>

class floorPanelBar : public QWidget
{
    Q_OBJECT

public:
	floorPanelBar(
		QWidget *parent = 0,
		QString imagePathPanelBar = ":/images/panelbar.png",
                QSize panelBarSize = QSize(17, 650));
	void setValue(int newValue);

public slots:
	void setPos(QPoint newPos);

signals:
	void resizeSignal(int newValue);
	void collapseSignal();
	void collapseState(bool collapsed);

	void showDragBar(QPoint newpos);
	void hideDragBar();

protected:
	void paintEvent(QPaintEvent *event);
	void mousePressEvent(QMouseEvent *event);
	void mouseDoubleClickEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);	
	void mouseReleaseEvent(QMouseEvent *event);

private:
	QString imagePathPanelBar;
	QSize panelBarSize;
	QPixmap image;

	int r_value;
	bool c_value;

	QPoint dragStartPosition;
};

#endif // FLOORPANELBAR_H
