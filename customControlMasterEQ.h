/****************************************************************************
**
** Copyright (C) 2007~2013 Colin Willcocks.
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

#ifndef CUSTOMCONTROLMASTEREQ_H
#define CUSTOMCONTROLMASTEREQ_H

#include <QWidget>
#include <QtGui>
#include <QFrame>
#include "customMasterEQGraph.h"
#include "customKnob.h"
#include "customControlLabel.h"

class customControlMasterEQ : public QWidget
{
    Q_OBJECT

public:
    customControlMasterEQ(QWidget *parent = 0,
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
        void LowGainChanged(unsigned short iLowGain);
        void MidFreqChanged(unsigned short iMidFreq);
        void MidQChanged(unsigned short iMidQ);
        void MidGainChanged(unsigned short iMidGain);
        void HighGainChanged(unsigned short iHighGain);
        void LevelChanged(unsigned short iLevel);

signals:
	void updateSignal();
        void updateDisplay(QString text);
        void updateDisplay_1(QString text);
        void updateDisplay_2(QString text);
        void updateDisplay_3(QString text);
        void updateDisplay_4(QString text);
        void updateDisplay_5(QString text);
        void updateDisplay_6(QString text);
        void graphUpdateSignal(QString hex_1, QString hex_2, QString hex_3, QString hex_4, QString hex_5, QString hex_6 );

private:
  customMasterEQGraph* frame;
	customControlLabel* label_1;
	customControlLabel* label_2;
	customControlLabel* label_3;
	customControlLabel* label_4;
	customControlLabel* label_5;
	customControlLabel* label_6;
	QLineEdit* display_1;
	QLineEdit* display_2;
	QLineEdit* display_3;
	QLineEdit* display_4;
	QLineEdit* display_5;
	QLineEdit* display_6;
	customKnob* knob_1;
	customKnob* knob_2;
	customKnob* knob_3;
	customKnob* knob_4;
	customKnob* knob_5;
	customKnob* knob_6;
	QString hex_1;
	QString hex_2;
	QString hex_3;
	QString hex_4;
	QString hex_5;
	QString hex_6;
	QString hex1;
	QString hex2;
	QString hex3;
	QString area;
};

#endif // customControlMasterEQ_H
