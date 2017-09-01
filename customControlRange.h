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

#ifndef CUSTOMCONTROLRANGE_H
#define CUSTOMCONTROLRANGE_H

#include <QWidget>
#include <QtWidgets>
#include "customKnobRange.h"
#include "customControlLabel.h"

class customControlRange : public QWidget
{
    Q_OBJECT

public:
    customControlRange(QWidget *parent = 0, 
		QString hex1 = "void",
		QString hex2 = "void",
		QString hex3 = "void",
		QString area = "Structure"
	);

protected:
	void paintEvent(QPaintEvent *event);

public slots:
	void dialogUpdateSignal();

signals:
	void updateSignal();
	void updateDisplayMin(QString text);
	void updateDisplayMax(QString text);

private:
	customControlLabel* labelMin;
	QLineEdit* displayMin;
	customKnobRange* knobMin;
	customControlLabel* labelMax;
	QLineEdit* displayMax;
	customKnobRange* knobMax;
	QString hex1;
	QString hex2;
	QString hex3;
	QString area;
	QString hexMin;
	QString hexMax;
};

#endif // CUSTOMCONTROLKNOB_H
