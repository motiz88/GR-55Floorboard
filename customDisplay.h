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

#ifndef CUSTOMDISPLAY_H
#define CUSTOMDISPLAY_H

#include <QtGui>
#include <QWidget>

class customDisplay : public QWidget
{
	Q_OBJECT

public:
	customDisplay(QRect geometry, QWidget *parent = 0);
	void setLabelPosition(bool invert = false);
	void setMainText(QString mainText, Qt::Alignment alignment = Qt::AlignLeft);
	void setSubText(QString subTextLeft, QString subTextRight = "");
	void clearAll();
	void setMainObjectName(QString name);
	void setSubObjectName(QString name);
	void setAllColor(QColor color);
	void resetAllColor();

protected:
	void paintEvent(QPaintEvent *event);

public slots:

signals:

private:
	QRect geometry;
	QFont font;
	QPalette mainPal;
	QPalette subPal;
	QLabel *mainLabel;
	QLabel *subLabelLeft;
	QLabel *subLabelRight;
};

#endif // CUSTOMDISPLAY_H
