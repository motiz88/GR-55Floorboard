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

#ifndef CUSTOMSLIDER_H
#define CUSTOMSLIDER_H

#include <QWidget>

class customSlider : public QWidget
{
    Q_OBJECT

public:
    customSlider(
		double value = 50,
		double min = 0, 
		double max = 100, 
		double single = 1, 
		double page = 10,
		QPoint sliderPos = QPoint(0, 0), 
		QWidget *parent = 0,
		QString hex1 = "void",
		QString hex2 = "void",
		QString hex3 = "void",
		QString slideImagePath = ":/images/slide.png",
		QString sliderButtonImagePath = ":/images/sliderbutton.png");
	void setValue(int value);
	

signals:
	void valueChanged(int newValue, QString hex1, QString hex2, QString hex3);

protected:
   void paintEvent(QPaintEvent *event);
   void mouseMoveEvent(QMouseEvent *event);
   void mousePressEvent(QMouseEvent *event);
   void wheelEvent(QWheelEvent *event);
   void keyPressEvent(QKeyEvent *event);

private:
	void setOffset(double value);
	void emitValue(double value);
	void mouseTrigger(QPoint mousePos);

	QString hex1;
	QString hex2;
	QString hex3;
	QString valueId;
	double value; 
	double min; 
	double max; 
	double single; 
	double page;
	QString slideImagePath;
	QString sliderButtonImagePath;
	QSize slideSize;
	QSize sliderButtonSize;
	QPoint sliderPos;

	double yOffset;
	double _lastValue;
	QPoint _startpos;
	QPoint _lastpos;

	double m_value;
};

#endif // CUSTOMSLIDER_H
