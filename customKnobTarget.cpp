/****************************************************************************
**
** Copyright (C) 2007~2010 Colin Willcocks.
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

#include "customKnobTarget.h"
#include "MidiTable.h"
#include "SysxIO.h"


customKnobTarget::customKnobTarget(QWidget *parent, 
						 QString hex1, QString hex2, QString hex3, 
						 QString hexMsb, QString hexLsb, QString background)
	: QWidget(parent)
{
	this->hex1 = hex1;
	this->hex2 = hex2;
	this->hex3 = hex3;
	this->hexMsb = hexMsb; 
	this->hexLsb = hexLsb;
	this->background = background;
	
	MidiTable *midiTable = MidiTable::Instance();
  
  QPoint bgPos = QPoint(0, -3); // Correction needed y-3.
	QPoint knobPos = QPoint(5, 4); // Correction needed y+1 x-1.
	QLabel *newBackGround = new QLabel(this);
	this->range = range;
	this->rangeMin = rangeMin;
	//this->range = midiTable->getRange("Structure", hex1, hex2, hex3);
	if (this->background == "target")
	{
                this->range = midiTable->getRange("Structure", "01", "00", "0E");
                this->rangeMin = midiTable->getRangeMinimum("Structure", "01", "00", "0E");
	}
	else 
	{
		this->range = midiTable->getRange("Structure", hexMsb, hex2, hexLsb); 
		this->rangeMin = midiTable->getRangeMinimum("Structure", hexMsb, hex2, hexLsb); 
	};
	
	newBackGround->setPixmap(QPixmap(":/images/knobbgn.png"));
	newBackGround->move(bgPos);

	QString imagePath(":/images/knob.png");
        unsigned int imageRange = 100;
	this->knob = new customTargetDial(0, rangeMin, range, 1, 10, knobPos, this, hex1, hex2, hex3, imagePath, imageRange, background);
	this->setFixedSize(newBackGround->pixmap()->size() - QSize(0, 4)); // Correction needed h-4.


	QObject::connect(this, SIGNAL( updateSignal() ),
                this->parent(), SIGNAL( updateSignal() ));

	QObject::connect(this, SIGNAL( updateDisplayTarget(QString) ),
                this->parent(), SIGNAL( updateDisplayTarget(QString) ));
                
  QObject::connect(this, SIGNAL( updateDisplayMin(QString) ),
                this->parent(), SIGNAL( updateDisplayMin(QString) ));
                
  QObject::connect(this, SIGNAL( updateDisplayMax(QString) ),
                this->parent(), SIGNAL( updateDisplayMax(QString) ));
                
  QObject::connect(this, SIGNAL( updateTarget(QString, QString, QString) ),
                this->parent(), SIGNAL( updateTarget(QString, QString, QString) ));
                
  QObject::connect(this, SIGNAL( updateHex(QString, QString, QString) ),
                this, SLOT( knobSignal(QString, QString, QString) ));
                
  QObject::connect(this->parent(), SIGNAL( updateHex(QString, QString, QString) ),
                this, SIGNAL( updateHex(QString, QString, QString) ));
 
};

void customKnobTarget::paintEvent(QPaintEvent *)
{
	/*DRAWS RED BACKGROUND FOR DEBUGGING PURPOSE */
	/*QPixmap image(":images/dragbar.png");
	
	QRectF target(0.0, 0.0, this->width(), this->height());
	QRectF source(0.0, 0.0, this->width(), this->height());

	QPainter painter(this);
	painter.drawPixmap(target, image, source);*/
};

void customKnobTarget::knobSignal(QString hexMsb, QString hex2, QString hexLsb)
 {
 if (background != "target")
   { 
	  this->hexMsb = hexMsb;
	  this->hexLsb = hexLsb;
	 }; 
 };
 
void customKnobTarget::setValue(int value)
{
	this->knob->setValue(value);     // on initialisation only
};

void customKnobTarget::valueChanged(int value, QString hex1, QString hex2, QString hex3)
{
  if (background != "target")
    {    
     this->knobSignal(hexMsb, hex2, hexLsb);
     this->hexMsb = hexMsb;
	   this->hex2 = hex2;
	   this->hexLsb = hexLsb;
    };
	MidiTable *midiTable = MidiTable::Instance();
	
	QString valueHex = QString::number(value, 16).toUpper();
	if(valueHex.length() < 2) valueHex.prepend("0");
 
	SysxIO *sysxIO = SysxIO::Instance(); bool ok;
	
	  if(midiTable->isData("Structure", hex1, hex2, hex3))
	  {	
		  int maxRange = QString("7F").toInt(&ok, 16) + 1;
		  int value = valueHex.toInt(&ok, 16);
		  int dif = value/maxRange;
		  QString valueHex1 = QString::number(dif, 16).toUpper();
		  if(valueHex1.length() < 2) valueHex1.prepend("0");
		  QString valueHex2 = QString::number(value - (dif * maxRange), 16).toUpper();
		  if(valueHex2.length() < 2) valueHex2.prepend("0");
      QString area;
		  sysxIO->setFileSource(area, hex1, hex2, hex3, valueHex1, valueHex2);		
	  }
	  else
	  {
	    QString area;
		  sysxIO->setFileSource(area, hex1, hex2, hex3, valueHex);
	  };
	
	QString valueStr;
        if (this->background == "target") {valueStr = midiTable->getValue("Structure", "01", "00", "0E", valueHex);
  emit updateDisplayTarget(valueStr);                                                       // updates display values
      } else if (this->background == "min") {
       valueStr = midiTable->getValue("Structure", hexMsb, hex2, hexLsb, valueHex); 
       emit updateDisplayMin(valueStr);
     } else if (this->background == "max") {
     valueStr = midiTable->getValue("Structure", hexMsb, hex2, hexLsb, valueHex); 
	   emit updateDisplayMax(valueStr);     
     };                                                  // updates display values
	emit updateSignal();
	
  if (this->background == "target")   // get the currently selected target value & set min/max address
  { 
  QString area;
	value = sysxIO->getSourceValue(area, this->hex1, this->hex2, this->hex3);        // read target value as integer.
	valueHex = QString::number(value, 16).toUpper();                        // convert to hex qstring.
	if(valueHex.length() < 2) valueHex.prepend("0");  
        valueStr = midiTable->getValue("Structure", "01", "00", "0E", valueHex);  // lookup the target values
		
  	int maxRange = QString("7F").toInt(&ok, 16) + 1;
		value = valueHex.toInt(&ok, 16);
		int dif = value/maxRange;
		QString valueHex1 = QString::number(dif, 16).toUpper();
		if(valueHex1.length() < 2) valueHex1.prepend("0");
		QString valueHex2 = QString::number(value - (dif * maxRange), 16).toUpper();
		if(valueHex2.length() < 2) valueHex2.prepend("0");
		QString hex4 = valueHex1;
		QString hex5 = valueHex2;
	                                                                                   //convert valueStr to 7bit hex4, hex5
        Midi items = midiTable->getMidiMap("Structure", "01", "00", "0E", hex4, hex5);
	this->hexMsb = items.desc;
	this->hexLsb = items.customdesc;  
  
  emit updateTarget(hexMsb, hex2, hexLsb);                       // hexMsb & hexLsb are lookup address for label value
  //emit updateTarget(hexMsb, hex2, hexLsb);   
  };                                                             // updates on knob value change                                            
};

