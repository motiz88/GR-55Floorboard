/****************************************************************************
**
** Copyright (C) 2007~2011 Colin Willcocks.
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

#ifndef customControlTarget_H
#define customControlTarget_H

#include <QWidget>
#include <QtGui>
#include "customKnobTarget.h"
#include "customControlLabel.h"
#include "customTargetListMenu.h"

class customControlTarget : public QWidget
{
    Q_OBJECT

public:
    customControlTarget(QWidget *parent = 0,
                QString hex1 = "void",
                QString hex2 = "void",
                QString hex3 = "void",
                QString background = "normal",
                QString direction = "min",
                int lenght = 40);

protected:
        void paintEvent(QPaintEvent *event);

public slots:
        void knobSignal(QString, QString, QString);
        void dialogUpdateSignal();


signals:
        void updateSignal();
        void updateDisplayTarget(QString text);
        void updateDisplayMin(QString text);
        void updateDisplayMax(QString text);
        void updateTarget(QString hexMsb, QString hex2, QString hexLsb);
        void updateHex(QString hexMsb, QString hex2, QString hexLsb);

private:
        customControlLabel* label;
        customControlLabel* labelMin;
        customControlLabel* labelMax;
        //QLineEdit* display;
        customTargetListMenu* displayCombo;
        QLineEdit* displayMin;
        QLineEdit* displayMax;
        customKnobTarget* knobTarget;
        customKnobTarget* knobMin;
        customKnobTarget* knobMax;
        QString hex1;
        QString hex2;
        QString hex3;
        QString hex4;
        QString hex5;
        QString hexMin;
        QString hexMax;
        QString hexMsb;
        QString hexLsb;
        QString hexTarget;
        QString hexTemp1;
        QString hexTemp2;
        QString direction;
        QString hex3_msb;
        QString hex3_lsb;
};

#endif // customControlTarget_H

