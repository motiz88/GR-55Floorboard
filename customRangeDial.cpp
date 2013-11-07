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

#include <QtWidgets>
#include "customRangeDial.h"
#include "SysxIO.h"

customRangeDial::customRangeDial(double value, double min, double max, double single, double page, 
					   QPoint dialPos, QWidget *parent, QString area, QString hex1, QString hex2, QString hex3, 
					   QString type, QString imagePath, unsigned int imageRange)
    : QWidget(parent)
{
    this->area = area;
	this->hex1 = hex1;
	this->hex2 = hex2;
	this->hex3 = hex3;
	this->type = type;
	this->value = value;
	this->min = min;
	this->max = max;
	this->single = single;
	this->page = page;
	this->imageRange = imageRange;
	this->imagePath = imagePath;
	QSize imageSize = QPixmap(imagePath).size();
	this->dialSize = QSize(imageSize.width()/(imageRange+1), imageSize.height());
	this->dialPos = dialPos;

	setOffset(value);
    setGeometry(dialPos.x(), dialPos.y(), dialSize.width(), dialSize.height());

	QObject::connect(this, SIGNAL( valueChanged(int, QString, QString, QString) ),
                this->parent(), SLOT( valueChanged(int, QString, QString, QString) )); 
}

void customRangeDial::paintEvent(QPaintEvent *)
{
	QRectF target(0.0 , 0.0, dialSize.width(), dialSize.height());
	QRectF source(xOffset, 0.0, dialSize.width(), dialSize.height());
	QPixmap image(imagePath);
	//image.setMask(image.mask());

	QPainter painter(this);
	//painter.setRenderHint(QPainter::Antialiasing, true);
	painter.drawPixmap(target, image, source);
}

void customRangeDial::setOffset(double _newValue)
{  

        double result = _newValue/1.3 - 1;
	
	int imageNr = (int)(result + 0.5);
	if(imageNr < 0)
	{
		imageNr = 0;
	}
	else if(imageNr > (int)(imageRange*dialSize.width()))
	{
		imageNr = (int)(imageRange*dialSize.width());
	};
	
	this->value = _newValue;	
        this->xOffset = imageNr*dialSize.width();
	this->update();
}

void customRangeDial::mousePressEvent(QMouseEvent *event)
{
	if ( event->button() == Qt::LeftButton )
	{	
		this->_lastpos = event->pos();
		this->_startpos = event->pos();
		this->_lastValue = value;
		setFocus();
		emitValue(value);
	};
}

void customRangeDial::mouseMoveEvent(QMouseEvent *event)
{
	double dataRange = max - min;
	//double range = imageRange - 0;
	double distY = (double)event->pos().y() - (double)_startpos.y();
	double numSteps = (int)((distY/1.5) + 0.5);
        double relativeSteps = numSteps * (dataRange / 100); // To make the mousing distance the same for all.
	numSteps = relativeSteps;
	
	double _newValue = _lastValue - (numSteps * single);
	
	if( (_startpos.y() < _lastpos.y() && _newValue < min)
		|| (_startpos.y() > _lastpos.y() && _newValue > max) ) 
	{
		this->_startpos =  _lastpos;
	};
	
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
	
	this->_lastpos = event->pos();
	setOffset(_newValue);
	emitValue(_newValue);
}

void customRangeDial::wheelEvent(QWheelEvent *event)
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

void customRangeDial::keyPressEvent(QKeyEvent *event)
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

void customRangeDial::emitValue(double value)
{
    if (value != m_value) {
        this->m_value = value;
    };
	emit valueChanged((int)value, this->hex1, this->hex2, this->hex3);
	knobSignal(hex1, hex2, hex3);
}

void customRangeDial::setValue(int value)
{
	setOffset((double)value);
}

void customRangeDial::knobSignal(QString hex1, QString hex2, QString hex3)
{
    SysxIO *sysxIO = SysxIO::Instance();
    QString valueStr;
	  QString valueHex;
	  int value;
	  bool ok;
    if (this->type == "Min")
  {
    valueHex = QString::number((hex3.toInt(&ok, 16) + 1), 16).toUpper();
    if(valueHex.length() < 2) valueHex.prepend("0");
    value = sysxIO->getSourceValue(this->area, this->hex1, this->hex2, valueHex);
    valueHex = QString::number(value, 16).toUpper();
    if(valueHex.length() < 2) valueHex.prepend("0");  
    this->max = QString(valueHex).toInt(&ok, 16) - 1;
  }
   else 
  {
    valueHex = QString::number((hex3.toInt(&ok, 16) - 1), 16).toUpper();
    if(valueHex.length() < 2) valueHex.prepend("0");
    value = sysxIO->getSourceValue(this->area, this->hex1, this->hex2, valueHex);
    valueHex = QString::number(value, 16).toUpper();
    if(valueHex.length() < 2) valueHex.prepend("0");  
    this->min = QString(valueHex).toInt(&ok, 16) + 1;
  };
}
