
/****************************************************************************
**
** Copyright (C) 2007~2010 Colin Willcocks.
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

#ifndef SOUNDSOURCE_H
#define SOUNDSOURCE_H

#include <QtGui>
#include "MidiTable.h"
#include "editWindow.h"
#include "customButton.h"
#include "customLed.h"
#include "customSwitch3way.h"
#include "customDial.h"
#include "customSlider.h"
#include "customSwitch.h"
#include "customComboBox.h"
#include "customDisplay.h"
#include "editPage.h"

class soundSource : public QWidget
{
    Q_OBJECT

public:
    soundSource(
            QWidget *parent = 0,
            unsigned int id = 0,
            QString imagePath = ":/images/modeling.png",
            QPoint stompPos = QPoint(0, 0));
    void setPos(QPoint newPos);
    void setImage(QString imagePath);
    void setSize(QSize newSize);
    void setId(unsigned int id);


    void setComboBox(QString hex1, QString hex2, QString hex3,
                     QRect geometry = QRect(143, 42, 70, 20));
    void setKnob1(QString hex1, QString hex2, QString hex3);
    void setKnob2(QString hex1, QString hex2, QString hex3);
    void setButton(QString hex1, QString hex2, QString hex3);
    void setButton(QString hex1, QString hex2, QString hex3, QPoint pos, QString imagePath);
    void setSwitch(QString hex1, QString hex2, QString hex3);
    void setLSB(QString hex1, QString hex2);
    void setLed();    
    void updateKnob1(QString hex1, QString hex2, QString hex3);
    void updateKnob2(QString hex1, QString hex2, QString hex3);
    void updateSlider1(QString hex1, QString hex2, QString hex3);
    void updateComboBox(QString hex1, QString hex2, QString hex3);
    void updateButton(QString hex1, QString hex2, QString hex3);
    void updateSwitch(QString hex1, QString hex2, QString hex3);
    void updateSwitch3way(QString hex1, QString hex2, QString hex3);

    void setComboBoxCurrentIndex(int index);
    void setRouteComboBoxCurrentIndex(int index);
    unsigned int getId();
    virtual void setEditPages() {}
    editWindow* editDetails();
    void getStompOrder();
    unsigned int id;


public slots:
    void updatePos(signed int offsetDif);
    void valueChanged(int value, QString hex1, QString hex2, QString hex3);
    void valueChanged(bool value, QString hex1, QString hex2, QString hex3);
    void valueChanged(int index);
    virtual void updateSignal() {}
    void setDisplayToFxName();
    void updateStompPath();
    void modeling_ButtonSignal(bool value);
    void synth1_ButtonSignal(bool value);
    void synth2_ButtonSignal(bool value);


signals:
    void valueChanged(QString fxName, QString valueName, QString valueStr);
    void currentIndexChanged(int index);
    void dialogUpdateSignal();
    void setEditDialog(editWindow* editDialog);
    void notConnectedSignal();
    void pathSwitchSignal();
    void pathUpdateSignal();
    void updateStompBoxes();
    void switchSignal();
    void modeling_statusSignal(bool value);
    void synth1_statusSignal(bool value);
    void synth2_statusSignal(bool value);

protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseDoubleClickEvent(QMouseEvent *event);

private:

    void emitValueChanged(QString hex1, QString hex2, QString hex3, QString valueHex);

    editWindow *editDialog;
    QString imagePath;
    QSize stompSize;
    QPoint stompPos;

    QPoint dragStartPosition;
    QPixmap image;

    customDial *knob1;
    customDial *knob2;
    customButton *button;
    customLed *led;
    customSwitch3way *switch3way;
    customSwitch *switchbutton;
    customComboBox *stompComboBox;
    customDisplay *stompDisplay;

    QString hex1;
    QString hex2;
    QString hex3;
    customButton *pathSwitch;
    bool pathSwitchActive;
    QString fxName;
    QList<QString> stompOrderName;
    QString stompOrderHex;
    QString hexdata_A;
    QString hexdata_B;
    QString namedata;
};

#endif // SOUNDSOURCE_H

