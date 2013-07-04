/****************************************************************************
**
** Copyright (C) 2007~2013 Colin Willcocks.
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

#ifndef CUSTOMEZ_PATCH_H
#define CUSTOMEZ_PATCH_H

#include <QWidget>
#include <QTimer>

class customEZ_Patch : public QWidget
{
    Q_OBJECT

public:
    customEZ_Patch(
        bool active = false,
        QWidget *parent = 0,
        QString hex1 = "void",
        QString hex2 = "void",
        QString hex3 = "void",
        QString imagePath = ":/images/ampswitch.png");

    void setBlink(bool value);

public slots:
    void setValue(int value);
    void blink();

signals:
    void valueChanged(int newValue);

protected:
    void paintEvent(QPaintEvent *event);

private:
    void setOffset(signed int imageNr);
    void setxOffset(signed int imageNr);
    void emitValue(int value);

    QString hex1;
    QString hex2;
    QString hex3;

    bool active;
    bool m_value;
    QString imagePath;
    QSize switchSize;
    unsigned int imageRange;
    QPoint switchPos;
    signed int yOffset;
    signed int xOffset;
    QTimer* timer;
    bool on;
    unsigned int count;
    int x_count;
};

#endif // CUSTOMEZ_PATCH_H
