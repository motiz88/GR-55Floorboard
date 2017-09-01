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

#ifndef FLOORBOARD_H
#define FLOORBOARD_H

#include <QWidget>
#include <QPixmap>
#include "soundSource.h"
#include "stompBox.h"
#include "menuPage.h"
#include "editWindow.h"
#include "customStructure.h"
#include "soundSource_modeling.h"
#include "soundSource_modeling_bass.h"

class floorBoard : public QWidget
{
    Q_OBJECT

public:
    floorBoard(
            QWidget *parent = 0,
            QString imagePathFloor = ":/images/floor_blue.png",
            QString imagePathStompBG = ":/images/stompbg.png",
            unsigned int marginStompBoxesTop = 135,
            unsigned int marginStompBoxesBottom = 72,
            unsigned int marginStompBoxesWidth = 25,
            unsigned int panelBarOffset = 10,
            unsigned int borderWidth = 3,
            QPoint pos = QPoint(0, 0));
    ~floorBoard();
    QPoint getStompPos(int id);


public slots:
    void setWidth(int dist);
    void setCollapse();
    void updateStompBoxes();
    void setEditDialog(editWindow* editDialog);
    void menuButtonSignal();
    void structure(bool value);
    void update_structure();

signals:
    void valueChanged(QString fxName, QString valueName, QString value);
    void setDisplayPos(QPoint newpos);
    void setFloorPanelBarPos(QPoint newpos);
    void updateStompOffset(signed int offsetDif);
    void sizeChanged(QSize newsize, QSize oldSize);
    void setCollapseState(bool state);
    void resizeSignal(QRect newrect);
    void showDragBar(QPoint newpos);
    void hideDragBar();
    void updateSignal();
    void pageUpdateSignal();
    void normal_PU_buttonSignal(bool value);
    void structure_1_buttonSignal(bool value);
    void structure_2_buttonSignal(bool value);
    void modeling_buttonSignal(bool value);
    void synth1_buttonSignal(bool value);
    void synth2_buttonSignal(bool value);
    void amp_buttonSignal(bool value);
    void compressor_buttonSignal(bool value);
    void ns1_buttonSignal(bool value);
    void mod_buttonSignal(bool value);
    void mfx_buttonSignal(bool value);
    void reverb_buttonSignal(bool value);
    void delay_buttonSignal(bool value);
    void chorus_buttonSignal(bool value);
    void sendreturn_buttonSignal(bool value);
    void eq_buttonSignal(bool value);
    void pedal_buttonSignal(bool value);
    void master_buttonSignal(bool value);
    void system_buttonSignal(bool value);
    void ez_edit_buttonSignal(bool value);
    void assign1_buttonSignal(bool value);
    void assign2_buttonSignal(bool value);
    void assign3_buttonSignal(bool value);
    void assign4_buttonSignal(bool value);
    void assign5_buttonSignal(bool value);
    void assign6_buttonSignal(bool value);
    void assign7_buttonSignal(bool value);
    void assign8_buttonSignal(bool value);
    void normal_PU_statusSignal(bool value);
    void structure_1_statusSignal(bool value);
    void structure_2_statusSignal(bool value);
    void modeling_statusSignal(bool value);
    void synth1_statusSignal(bool value);
    void synth2_statusSignal(bool value);
    void amp_statusSignal(bool value);
    void compressor_statusSignal(bool value);
    void ns1_statusSignal(bool value);
    void mod_statusSignal(bool value);
    void mfx_statusSignal(bool value);
    void reverb_statusSignal(bool value);
    void delay_statusSignal(bool value);
    void chorus_statusSignal(bool value);
    void sendreturn_statusSignal(bool value);
    void eq_statusSignal(bool value);
    void pedal_statusSignal(bool value);
    void master_statusSignal(bool value);
    void system_statusSignal(bool value);
    void assign1_statusSignal(bool value);
    void assign2_statusSignal(bool value);
    void assign3_statusSignal(bool value);
    void assign4_statusSignal(bool value);
    void assign5_statusSignal(bool value);
    void assign6_statusSignal(bool value);
    void assign7_statusSignal(bool value);
    void assign8_statusSignal(bool value);
    void notConnected();

protected:
    void paintEvent(QPaintEvent *event);

private:
    void initSize(QSize floorSize);
    void setSize(QSize newSize);
    void setFloorBoard();
    void initSoundSource();
    void initStomps();
    void initMenuPages();
    void centerEditDialog();
    QString imagePathFloor;
    QString imagePathStompBG;
    unsigned int offset;
    unsigned int structureWidth;
    unsigned int structureHeight;
    unsigned int panelBarOffset;
    unsigned int borderWidth;
    unsigned int floorHeight;
    QSize minSize;
    QSize maxSize;
    QSize l_floorSize;
    QSize floorSize;
    unsigned int marginStompBoxesTop;
    unsigned int marginStompBoxesBottom;
    unsigned int marginStompBoxesWidth;
    QSize stompSize;
    QPixmap baseImage;
    QPixmap image;
    QPoint pos;
    QPoint displayPos;
    QPoint liberainPos;
    QPoint panelBarPos;
    QList<QPoint> fxPos;
    QList<int> fx;
    QList<int> snd;
    bool colapseState;
    QList<menuPage*> menuPages;
    QList<soundSource*> soundSources;
    QList<stompBox*> stompBoxes;
    QList<QString> stompNames;
    editWindow* editDialog;
    editWindow* oldDialog;
    int pageOffset;
    customStructure* structure_2;
    bool structure_state;
    soundsource_modeling *modeling;
    soundsource_modeling_bass *modeling_bass;
};

#endif // FLOORBOARD_H
