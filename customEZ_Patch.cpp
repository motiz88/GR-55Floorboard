/****************************************************************************
**
** Copyright (C) 2007~2015 Colin Willcocks.
** Copyright (C) 2005~2007 Uco Mesdag.
** All rights reserved.
** This file is part of "GT-100 Fx FloorBoard".
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
#include "customEZ_Patch.h"
#include "Preferences.h"

customEZ_Patch::customEZ_Patch(bool active, QWidget *parent, QString hex1, QString hex2, QString hex3,
                               QString imagePath)
    : QWidget(parent)
{
    Preferences *preferences = Preferences::Instance();
    bool ok;
    const double ratio = preferences->getPreferences("Window", "Scale", "ratio").toDouble(&ok);

    this->hex1 = hex1;
    this->hex2 = hex2;
    this->hex3 = hex3;
    this->active = active;
    this->imagePath = imagePath;
    QSize imageSize = QPixmap(imagePath).size()*ratio;
    this->switchSize = QSize(imageSize.width()/4, imageSize.height()/15);
    this->imageRange = 1;
    this->switchPos = switchPos;
    this->setOffset(0);
    this->setFixedSize(switchSize);
    timer = new QTimer(this);
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(blink()) );
    setBlink(true);
    x_count = 0;
}

void customEZ_Patch::paintEvent(QPaintEvent *)
{
    Preferences *preferences = Preferences::Instance();
    bool ok;
    const double ratio = preferences->getPreferences("Window", "Scale", "ratio").toDouble(&ok);

    QRectF target(0.0 , 0.0, switchSize.width()*ratio, switchSize.height()*ratio);
    QRectF source(xOffset, yOffset, switchSize.width(), switchSize.height());
    QPixmap image(imagePath);

    QPainter painter(this);
    painter.drawPixmap(target, image, source);
}

void customEZ_Patch::setOffset(signed int imageNr)
{
    Preferences *preferences = Preferences::Instance();
    bool ok;
    const double ratio = preferences->getPreferences("Window", "Scale", "ratio").toDouble(&ok);
    this->yOffset = imageNr*switchSize.height()/ratio;
    this->update();
}

void customEZ_Patch::setxOffset(signed int imageNr)
{
    Preferences *preferences = Preferences::Instance();
    bool ok;
    const double ratio = preferences->getPreferences("Window", "Scale", "ratio").toDouble(&ok);
    this->xOffset = imageNr*switchSize.width()/ratio;
    this->update();
}

void customEZ_Patch::setValue(int value)
{
    setOffset(value);
}

void customEZ_Patch::setBlink(bool value)
{
    if(value)
    {
        timer->start(250);
    }
    else
    {
        timer->stop();
        if(active)
        {

            x_count++;
            if(x_count>3) {x_count = 0; };
             setxOffset(x_count);
        }
        else
        {

            x_count++;
            if(x_count>3) {x_count = 0; };
            setxOffset(x_count);
        };
    };
}

void customEZ_Patch::blink()
{
    x_count++;
    if(x_count>3) {x_count = 0; };
     setxOffset(x_count);
    if(on)
    {
        on = false;
        //setxOffset(0);
    }
    else
    {
        on = true;
        //setxOffset(1);
    };
    clearFocus();
}
