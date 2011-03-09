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

#include <QtGui>
#include "customSwitch.h"

customSwitch::customSwitch(bool active, QWidget *parent, QString hex1, QString hex2, QString hex3,
                           QString imagePath)
                               : QWidget(parent)
{
    this->hex1 = hex1;
    if(hex2 == "INVERT") {
        this->hex2 = "00";
        this->imagePath = ":/images/switch_invert.png";
    } else {
        this->hex2 = hex2;
        this->imagePath = imagePath;
    };

    this->hex3 = hex3;
    this->active = active;

    QSize imageSize = QPixmap(imagePath).size();
    this->switchSize = QSize(imageSize.width(), imageSize.height()/2);
    this->imageRange = 1;
    this->switchPos = switchPos;
    this->setOffset(0);
    this->setFixedSize(switchSize);

    QObject::connect(this, SIGNAL( valueChanged(bool, QString, QString, QString) ),
                     this->parent(), SLOT( valueChanged(bool, QString, QString, QString) ));
};

void customSwitch::paintEvent(QPaintEvent *)
{
    QRectF target(0.0 , 0.0, switchSize.width(), switchSize.height());
    QRectF source(0.0, yOffset, switchSize.width(), switchSize.height());
    QPixmap image(imagePath);

    QPainter painter(this);
    painter.drawPixmap(target, image, source);
};

void customSwitch::setOffset(signed int imageNr)
{
    this->yOffset = imageNr*switchSize.height();
    this->update();
};

void customSwitch::mousePressEvent(QMouseEvent *event)
{
    if ( event->button() == Qt::LeftButton )
    {
        this->dragStartPosition = event->pos();
        setFocus();
    };
};

void customSwitch::mouseReleaseEvent(QMouseEvent *event)
{
    if ( event->button() == Qt::LeftButton )
    {
        if(active)
        {
            setOffset(0);
            emitValue(false);
        }
        else
        {
            setOffset(1);
            emitValue(true);
        };
        clearFocus();
    };
};

void customSwitch::emitValue(bool value)
{
    this->active = value;
    if (value != m_value) {
        this->m_value = value;
        //moved emit value from here
    };
     emit valueChanged((bool)value, this->hex1, this->hex2, this->hex3);
};

void customSwitch::mouseMoveEvent(QMouseEvent *event)
{
    if (!(event->buttons() == Qt::LeftButton) && (event->pos() - dragStartPosition).manhattanLength() < QApplication::startDragDistance())
    {
        return;
    };
};

void customSwitch::setValue(bool value)
{
    this->active = value;
    if(active)
    {
        setOffset(1);
    }
    else
    {
        setOffset(0);
    };
    clearFocus();
};
