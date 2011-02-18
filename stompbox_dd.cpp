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

#include "stompbox_dd.h"

stompbox_dd::stompbox_dd(QWidget *parent)
    : stompBox(parent)
{
    /* DELAY */
    setImage(":/images/dd.png");
    setLSB("06", "00");
    setKnob1("06", "00", "09");
    setKnob2("06", "00", "0A");
    setComboBox("06", "00", "06");
    setSwitch("06", "00", "05");
    // editDetails()->patchPos(2702, 50, "0A", "00");
    setEditPages();
};

void stompbox_dd::updateSignal()
{
    updateKnob1("06", "00", "09");
    updateKnob2("06", "00", "0A");
    updateComboBox("06", "00", "06");
    updateSwitch("06", "00", "05");
};

void stompbox_dd::setEditPages()
{
    editDetails()->page()->newGroupBox("Effect");
    editDetails()->page()->addSwitch(0, 0, 1, 1, "06", "00", "05", "middle", Qt::AlignCenter); //sw
    editDetails()->page()->addComboBox(1, 0, 1, 1, "06", "00", "06"); //type
    editDetails()->page()->addGroupBox(0, 0, 1, 1);

    editDetails()->page()->newGroupBox("Delay");
    editDetails()->page()->addKnob(0, 0, 1, 1, "06", "00", "09", "normal","right", 105); // 3 byte time
    editDetails()->page()->addKnob(0, 1, 1, 1, "06", "00", "0A");  //feedback
    editDetails()->page()->addGroupBox(0, 1, 1, 1);

    editDetails()->page()->newGroupBox("Level");
    editDetails()->page()->addKnob(0, 0, 1, 1, "06", "00", "0B", "turbo"); //level
    editDetails()->page()->addGroupBox(0, 2, 1, 1);

    editDetails()->page()->newGroupBox(tr("Send Levels"));
    editDetails()->page()->addKnob(0, 0, 1, 1, "07", "00", "12");           //MOD
    editDetails()->page()->addKnob(0, 1, 1, 1, "03", "00", "01");           //MFX
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "00", "3F");           //bypass
    editDetails()->page()->addGroupBox(2, 0, 1, 4);

    editDetails()->addPage();
};
