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

#include <QtWidgets>
#include "statusBarSymbol.h"
#include "globalVariables.h"
#include "Preferences.h"

statusBarSymbol::statusBarSymbol(QWidget *parent, QString imagePath)
    : QWidget(parent)
{
    Preferences *preferences = Preferences::Instance();
    bool ok;
    const double ratio = preferences->getPreferences("Window", "Scale", "ratio").toDouble(&ok);
	this->imagePath = imagePath;
    QSize imageSize = QPixmap(imagePath).size();
    this->symbolSize =  QSize((imageSize.width()/4), imageSize.height());
    this->setFixedSize(symbolSize*ratio);

	setOffset(0);
}

void statusBarSymbol::paintEvent(QPaintEvent *)
{
    Preferences *preferences = Preferences::Instance();
    bool ok;
    const double ratio = preferences->getPreferences("Window", "Scale", "ratio").toDouble(&ok);
    QRectF target(0.0 , 0.0, symbolSize.width()*ratio, symbolSize.height()*ratio);
    QRectF source(xOffset, 0.0, symbolSize.width(), symbolSize.height());
	QPixmap image(imagePath);

	QPainter painter(this);
	painter.drawPixmap(target, image, source);
}

void statusBarSymbol::setOffset(int imageNr)
{
    Preferences *preferences = Preferences::Instance();
    bool ok;
    const double ratio = preferences->getPreferences("Window", "Scale", "ratio").toDouble(&ok);
    this->xOffset = imageNr*symbolSize.width();
	this->update();
}

void statusBarSymbol::setValue(int value)
{
	setOffset(value);
}

