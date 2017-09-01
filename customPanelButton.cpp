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
#include "customPanelButton.h"
#include "globalVariables.h"
#include "Preferences.h"

customPanelButton::customPanelButton(bool active, QPoint buttonPos, QWidget *parent, QString hex1, QString hex2, QString hex3,
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
    QSize imageSize = QPixmap(imagePath).size();
    this->buttonSize =  QSize(imageSize.width(), imageSize.height()/4);
    this->buttonPos = buttonPos;
    setOffset(0);
    setGeometry(buttonPos.x(), buttonPos.y(), buttonSize.width()*ratio, buttonSize.height()*ratio);

    timer = new QTimer(this);
    QObject::connect(this, SIGNAL( valueChanged(bool, QString, QString, QString) ),
                     this->parent(), SLOT( valueChanged(bool, QString, QString, QString) ));

}

customPanelButton::customPanelButton(QString text, bool active, QPoint buttonPos, QWidget *parent,
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
    this->text = text;
    this->imagePath = imagePath;
    QSize imageSize = QPixmap(imagePath).size();
    this->buttonSize =  QSize(imageSize.width(), imageSize.height()/2);
    this->buttonPos = buttonPos;
    setOffset(0);
    setGeometry(buttonPos.x(), buttonPos.y(), buttonSize.width()*ratio, buttonSize.height()*ratio);

    timer = new QTimer(this);
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(blink()) );

    QObject::connect(this, SIGNAL( valueChanged(bool, QString, QString, QString) ),
                     this->parent(), SLOT( valueChanged(bool, QString, QString, QString) ));
}

void customPanelButton::paintEvent(QPaintEvent *)
{

    Preferences *preferences = Preferences::Instance();
    bool ok;
    const double ratio = preferences->getPreferences("Window", "Scale", "ratio").toDouble(&ok);

    QRectF target(0.0 , 0.0, buttonSize.width()*ratio, buttonSize.height()*ratio);
    QRectF source(0.0, yOffset, buttonSize.width(), buttonSize.height());
    QPixmap image(imagePath);

    QPainter painter(this);
    painter.drawPixmap(target, image, source);
}

void customPanelButton::setOffset(signed int imageNr)
{
    this->yOffset = imageNr*buttonSize.height();
    this->update();
}

void customPanelButton::mousePressEvent(QMouseEvent *event)
{
    if ( event->button() == Qt::LeftButton )
    {
        this->dragStartPosition = event->pos();
        if(active)
        {
            //setOffset(1);
        }
        else
        {
            //setOffset(0);
        };
        setFocus();
        emitValue(true);
    };
}

void customPanelButton::mouseReleaseEvent(QMouseEvent *event)
{
    if ( event->button() == Qt::LeftButton )
    {
        clearFocus();
    };
}

void customPanelButton::emitValue(bool value)
{
    this->active = value;
    if(this->hex1.isEmpty() && this->hex2.isEmpty() && this->hex3.isEmpty())
    {
        emit valueChanged((bool)value);
    }
    else
    {
        emit valueChanged((bool)value, this->hex1, this->hex2, this->hex3);
    };
}

void customPanelButton::mouseMoveEvent(QMouseEvent *event)
{
    if (!(event->buttons() == Qt::LeftButton) && (event->pos() - dragStartPosition).manhattanLength() < QApplication::startDragDistance())
    {
        return;
    };
    /*if(active)
    {
        setOffset(2);
    }
    else
    {
        setOffset(0);
    };*/
}

void customPanelButton::setValue(bool value)
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
}

void customPanelButton::setBlink(bool value)
{
    if(value)
    {
        timer->start(buttonBlinkInterval);
    }
    else
    {
        timer->stop();
        if(active)
        {
            setOffset(1);
        }
        else
        {
            setOffset(0);
        };
    };
}

void customPanelButton::blink()
{
    if(on)
    {
        on = false;
        setOffset(0);
    }
    else
    {
        on = true;
        setOffset(1);
    };
    clearFocus();
}
