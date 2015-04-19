/****************************************************************************
**
** Copyright (C) 2007~2015 Colin Willcocks.
** Copyright (C) 2005~2007 Uco Mesdag. 
** All rights reserved.
** This file is part of "GR-55B FloorBoard".
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

#ifndef CUSTOMKNOBTARGET_H
#define CUSTOMKNOBTARGET_H

#include <QWidget>
#include <QtWidgets>
#include "customTargetDial.h"


class customKnobTarget : public QWidget
{
    Q_OBJECT

public:
    customKnobTarget(QWidget *parent = 0, 
		QString hex1 = "void",
		QString hex2 = "void",
		QString hex3 = "void",
		QString hexMsb = "void",
		QString hexLsb = "void",
		QString background = "normal");
	void setValue(int value);

public slots:
	void valueChanged(int, QString, QString, QString);
	void knobSignal(QString, QString, QString);

signals:
	void updateSignal();
	void updateDisplayTarget(QString text);
	void updateDisplayMin(QString text);
	void updateDisplayMax(QString text);
	void updateTarget(QString hexMsb, QString hex2, QString hexLsb);
	void updateHex(QString hexMsb, QString hex2, QString hexLsb);

protected:
	void paintEvent(QPaintEvent *event);

private:
	customTargetDial* knob;
	QString hex1;
	QString hex2;
	QString hex3;
	QString hexMsb;
	QString hexLsb;
	QString background;
	int range;
	int rangeMin;
	};

#endif // CUSTOMKNOBTARGET_H
