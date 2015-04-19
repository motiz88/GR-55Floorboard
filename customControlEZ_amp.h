/****************************************************************************
**
** Copyright (C) 2007~2015 Colin Willcocks.
** Copyright (C) 2005~2007 Uco Mesdag. 
** All rights reserved.
** This file is part of "GT-100B Fx FloorBoard".
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

#ifndef CUSTOMCONTROLEZ_AMP_H
#define CUSTOMCONTROLEZ_AMP_H

#include <QWidget>
#include <QtWidgets>
#include <QFrame>
#include <QSlider>
#include "customEZ_amp.h"
#include "customKnob.h"
#include "customControlLabel.h"

class customControlEZ_amp : public QWidget
{
    Q_OBJECT

public:
    customControlEZ_amp(QWidget *parent = 0,
                        QString hex1 = "void",
                        QString hex2 = "void",
                        QString hex3 = "void",
                        QString background = "normal",
                        QString direction = "bottom",
                        int lenght = 34);

    QPainter p;

protected:
    void paintEvent(QPaintEvent *event);
    void dataChanged();

public slots:
    void dialogUpdateSignal();
    void y_axisChanged(int iy_axis);
    void x_axisChanged(int ix_axis);

signals:
    void updateSignal();
    void graphUpdateSignal(QString hex_1, QString hex_2);

private:
    customEZ_amp* frame;
    QSlider* v_slider;
    QSlider* h_slider;
    QString hex_1;
    QString hex_2;
    QString hex1;
    QString hex2;
    QString hex3;
    QString hex4;
    QString hex5;
    QString use;
    int y_data;
    int x_data;
    customControlLabel* label_1;
    customControlLabel* label_2;
    customControlLabel* label_3;
    customControlLabel* label_4;
    int toggle;
};

#endif // customControlEZ_amp_H
