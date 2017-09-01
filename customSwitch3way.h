/****************************************************************************
**
** Copyright (C) 2007~2016 Colin Willcocks.
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

#ifndef CUSTOMSWITCH3WAY_H
#define CUSTOMSWITCH3WAY_H

#include <QWidget>

class customSwitch3way : public QWidget
{
    Q_OBJECT

public:
    customSwitch3way(
		int active = 0,
		QPoint switch3wayPos = QPoint(0, 0), 
		QWidget *parent = 0,
		QString imagePath = ":/images/switch3way.png");
	void setValue(int value);

public slots:
	void changeValue(int value);

protected:
   void paintEvent(QPaintEvent *event);

private:
	void setOffset(signed int imageNr);

	int active;
	QString imagePath;
	QSize switch3waySize;
	QPoint switch3wayPos; 
	signed int yOffset;
};

#endif // CUSTOMSWITCH3WAY_H
