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

#include "stompbox_rv.h"

stompbox_rv::stompbox_rv(QWidget *parent)
    : stompBox(parent)
{
    /* REVERB */
    setImage(":/images/rv.png");
    setLSB("06", "0C");
    setKnob1("06", "00", "0E");
    setKnob2("06", "00", "10");
    setComboBox("06", "00", "0D");
    setSwitch("06", "00", "0C");
    editDetails()->patchPos(1418, 10, "06", "0C"); //correct
    setEditPages();
}

void stompbox_rv::updateSignal()
{
    updateKnob1("06", "00", "0E");
    updateKnob2("06", "00", "10");
    updateComboBox("06", "00", "0D");
    updateSwitch("06", "00", "0C");
}

void stompbox_rv::setEditPages()
{
    editDetails()->page()->newGroupBox("Effect");
    editDetails()->page()->addSwitch(0, 0, 1, 1, "06", "00", "0C", "middle", Qt::AlignCenter); //sw
    editDetails()->page()->addComboBox(1, 0, 1, 1, "06", "00", "0D");   //type
    editDetails()->page()->addGroupBox(0, 0, 1, 1);

    editDetails()->page()->newGroupBox("Reverb");
    editDetails()->page()->addKnob(0, 1, 1, 1, "06", "00", "0E");  //time
    editDetails()->page()->addGroupBox(0, 1, 1, 1);

    editDetails()->page()->newGroupBox("Filter");
    editDetails()->page()->addKnob(0, 1, 1, 1, "06", "00", "0F");
    editDetails()->page()->addGroupBox(0, 2, 1, 1);

    editDetails()->page()->newGroupBox("Level");
    editDetails()->page()->addKnob(0, 0, 1, 1, "06", "00", "10");
    editDetails()->page()->addGroupBox(0, 3, 1, 1);

    editDetails()->page()->newGroupBox(tr("Send Levels"));
    editDetails()->page()->addKnob(0, 0, 1, 1, "07", "00", "13");           //MOD
    editDetails()->page()->addKnob(0, 1, 1, 1, "03", "00", "02");           //MFX
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "00", "40");           //bypass
    editDetails()->page()->addGroupBox(2, 0, 1, 4);

    editDetails()->addPage();
}
