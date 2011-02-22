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

#ifndef CUSTOMCONTROLKNOB_H
#define CUSTOMCONTROLKNOB_H

#include <QWidget>
#include <QtGui>
#include "customKnob.h"
#include "customControlLabel.h"

class customControlKnob : public QWidget
{
    Q_OBJECT

public:
    customControlKnob(QWidget *parent = 0, 
		QString hex1 = "void",
		QString hex2 = "void",
		QString hex3 = "void",
		QString background = "normal", 
		QString direction = "bottom", 
		int lenght = 34);

protected:
	void paintEvent(QPaintEvent *event);

public slots:
	void dialogUpdateSignal();

signals:
	void updateSignal();
	void updateDisplay(QString text);

private:
	customControlLabel* label;
	QLineEdit* display;
	customKnob* knob;
	QString hex1;
	QString hex2;
	QString hex3;
	QString area;
};

#endif // CUSTOMCONTROLKNOB_H
