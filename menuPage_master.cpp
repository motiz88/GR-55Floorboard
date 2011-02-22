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

#include "menuPage_master.h"

menuPage_master::menuPage_master(QWidget *parent)
    : menuPage(parent)
{
    //setImage(":/images/master_pushbutton.png");
    setLSB("02", "00");
    // editDetails()->patchPos(2894, 20, "0A", "60");
    setEditPages();
};

void menuPage_master::updateSignal()
{

};

void menuPage_master::setEditPages()
{

    editDetails()->page()->newGroupBox("Patch Level");
    editDetails()->page()->addDataKnob(0, 0, 1, 1, "02", "00", "30", "0~100"); // patch level
    editDetails()->page()->addGroupBox(0, 0, 1, 1);

    editDetails()->page()->newGroupBox("Patch Tempo");
    editDetails()->page()->addDataKnob(0, 0, 1, 1, "02", "00", "3C", "BPM"); // master BPM
    editDetails()->page()->addGroupBox(0, 1, 1, 1);

    editDetails()->page()->newGroupBox("Guitar Out Jack");
    editDetails()->page()->addComboBox(0, 0, 1, 1, "02", "00", "25");    // guitar out
    editDetails()->page()->addGroupBox(0, 2, 1, 1);

    editDetails()->page()->newGroupBox("GK SET Select");
    editDetails()->page()->addComboBox(0, 0, 1, 1, "02", "00", "24");    // guitar out
    editDetails()->page()->addGroupBox(0, 3, 1, 1);

    editDetails()->page()->newGroupBox(tr("ALTERNATE TUNING"));
    editDetails()->page()->addSwitch(0, 0, 1, 1, "02", "00", "34", "middle", Qt::AlignCenter);  //sw
    editDetails()->page()->newStackControl(0);
    editDetails()->page()->addComboBox(0, 1, 1, 1, "02", "00", "35");    //type
    editDetails()->page()->addStackControl();
    editDetails()->page()->insertStackField(0, 0, 2, 1, 6);
    editDetails()->page()->addGroupBox(1, 0, 1, 4);

    editDetails()->page()->newStackField(0);
    editDetails()->page()->addStackField();


    editDetails()->page()->newStackField(0);
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(0);
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(0);
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(0);
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(0);
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(0);
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(0);
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(0);
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(0);
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(0);
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(0);
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(0);
    editDetails()->page()->newGroupBox("User Tuning");
    editDetails()->page()->addKnob(0, 0, 1, 1, "02", "00", "36");    //String H
    editDetails()->page()->addKnob(0, 1, 1, 1, "02", "00", "37");    //String 1
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "00", "38");    //String 2
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "00", "39");    //String 3
    editDetails()->page()->addKnob(0, 4, 1, 1, "02", "00", "3A");    //String 4
    editDetails()->page()->addKnob(0, 5, 1, 1, "02", "00", "3B");    //String L
    editDetails()->page()->addGroupBox(0, 0, 1, 1);
    editDetails()->page()->addStackField();

    editDetails()->page()->newGroupBox("V-LINK");
    editDetails()->page()->addKnob(0, 0, 1, 1, "02", "00", "26");       // palette
    editDetails()->page()->addKnob(0, 1, 1, 1, "02", "00", "27");       //clip
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "00", "28");       //note clip change
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "00", "29", "normal","right", 80);       //EXP
    editDetails()->page()->addKnob(0, 4, 1, 1, "02", "00", "2A", "normal","right", 80);       //EXP ON
    editDetails()->page()->addKnob(0, 5, 1, 1, "02", "00", "2B", "normal","right", 80);       //GK VOL
    editDetails()->page()->addGroupBox(2, 0, 1, 4);

    editDetails()->addPage();
};
