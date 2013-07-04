/****************************************************************************
**
** Copyright (C) 2007~2013 Colin Willcocks.
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

#include <QtGui>

#include "customSlider.h"

customSlider::customSlider(double value, double min, double max, double single, double page, 
						QPoint sliderPos, QWidget *parent, QString hex1, QString hex2, QString hex3, 
						QString slideImagePath, QString sliderButtonImagePath)
    : QWidget(parent)
{
	this->hex1 = hex1;
	this->hex2 = hex2;
	this->hex3 = hex3;	
	this->value = value;
	this->min = min;
	this->max = max;
	this->single = single;
	this->page = page;
	this->slideImagePath = slideImagePath;
	this->sliderButtonImagePath = sliderButtonImagePath;
	this->slideSize = QPixmap(slideImagePath).size();
	this->sliderButtonSize = QPixmap(sliderButtonImagePath).size();
	this->sliderPos = sliderPos;

	setOffset(value);
    setGeometry(sliderPos.x(), sliderPos.y(), slideSize.width(), slideSize.height());

	QObject::connect(this, SIGNAL( valueChanged(int, QString, QString, QString) ),
                this->parent(), SLOT( valueChanged(int, QString, QString, QString) ));
}

void customSlider::paintEvent(QPaintEvent *)
{
	QPixmap slide(slideImagePath);
	QPixmap sliderButton(sliderButtonImagePath);

	QRectF target(0.0 , yOffset, sliderButtonSize.width(), sliderButtonSize.height());
	QRectF source(0.0 , 0.0, sliderButtonSize.width(), sliderButtonSize.height());
	QRectF screen(0.0 , 0.0, slideSize.width(), slideSize.height());

	QPixmap buffer = slide;
	QPainter painterBuffer(&buffer);
	painterBuffer.drawPixmap(target, sliderButton, source);
	painterBuffer.end();

	QPainter painter(this);
	painter.drawPixmap(screen, buffer, screen);
}

void customSlider::setOffset(double _newValue)
{
	double dataRange = max - min;
	double range = slideSize.height()  - sliderButtonSize.height();
	double result = (max - _newValue) * (range / dataRange); 
	
	this->value = _newValue;	
	this->yOffset = result;
	this->update();
}

void customSlider::mouseTrigger(QPoint mousePos)
{
	this->_lastValue = value;
	
	double dataRange = max - min;
	double range = slideSize.height() - sliderButtonSize.height();
	double result = mousePos.y() - (sliderButtonSize.height() / 2);
	double _newValue = max - (result / (range / dataRange));

	QPoint buttonCenter = QPoint(0, (sliderButtonSize.height()/2));
	QPoint relativePos = mousePos - buttonCenter;
	int minY = 0;
	int maxY = slideSize.height() - sliderButtonSize.height();
	
	if(relativePos.y() <= minY)
	{
		_newValue = max;		
	}
	else if(relativePos.y() >= maxY)
	{
		_newValue = min;
				
	};
	setOffset(_newValue);
	emitValue(_newValue);
}

void customSlider::mousePressEvent(QMouseEvent *event)
{
	if ( event->button() == Qt::LeftButton )
	{	
		setFocus();
		mouseTrigger(event->pos());
		emitValue(value);
	};
}

void customSlider::mouseMoveEvent(QMouseEvent *event)
{
	mouseTrigger(event->pos());
}

void customSlider::wheelEvent(QWheelEvent *event)
{
    double numDegrees = (double)(event->delta() / 8);
    double numSteps = numDegrees / 15;

    if (event->orientation() == Qt::Vertical) 
	{
		this->_lastValue = value;
		
		double _newValue = _lastValue + (numSteps * single);

		if(_newValue < min)
		{
			_newValue = min;
		}
		else if(_newValue > max)
		{
			_newValue = max;
		};
		setOffset(_newValue);
		emitValue(_newValue);	
    };
}

void customSlider::keyPressEvent(QKeyEvent *event)
{
	double numSteps = 0;
	this->_lastValue = value;
	
	switch(event->key())
	{
		case Qt::Key_Up: numSteps = -single;break;
		case Qt::Key_Down: numSteps = single;break;
		case Qt::Key_Plus: numSteps = -single;break;
		case Qt::Key_Minus: numSteps = single;break;

		case Qt::Key_PageUp: numSteps = -page;break;
		case Qt::Key_PageDown: numSteps = page;break;

		case Qt::Key_Right: numSteps = -(max-min);break;
		case Qt::Key_Left: numSteps = max-min;break;
	};

	if (numSteps!=0) 
	{
		double _newValue = _lastValue - numSteps;
		if(_newValue < min)
		{
			_newValue = min;
			this->_lastValue = value;
		}
		else if(_newValue > max)
		{
			_newValue = max;
			this->_lastValue = value;
		};
		setOffset(_newValue);
		emitValue(_newValue);
	};
}

void customSlider::emitValue(double value)
{
    if (value != m_value) {
        this->m_value = value;
    };
	emit valueChanged((int)value, this->hex1, this->hex2, this->hex3);
}

void customSlider::setValue(int value)
{
	setOffset((double)value);
}
