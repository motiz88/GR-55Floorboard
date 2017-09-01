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

#include "soundSource_analogPU.h"

soundsource_analogPU::soundsource_analogPU(QWidget *parent)
    : soundSource(parent)
{
    /* ANALOG PICKUP */
    this->setImage(":/images/analogPU.png");
    setLSB("02", "32");
    setComboBox("02", "routeSwitch", "2E");
    setKnob2("02", "00", "33");
    setSwitch("02", "INVERT", "32");
    editDetails()->patchPos(686, 4, "02", "32");
    setEditPages();
}

void soundsource_analogPU::updateSignal()
{
    updateComboBox("02", "routeSwitch", "2E");
    updateKnob2("02", "00", "33");
    updateSwitch("02", "00", "32");
}

void soundsource_analogPU::setEditPages()
{
    editDetails()->page()->newGroupBox(tr("Tone"));
    editDetails()->page()->addSwitch(0, 0, 1, 1, "02", "00", "32", "invert", Qt::AlignCenter);   // off/on effect
    editDetails()->page()->addGroupBox(0, 0, 1, 1);

    editDetails()->page()->newGroupBox(tr("Routing Selection"));
    editDetails()->page()->addComboBox(0, 0, 1, 1, "02", "00", "2E");   //route
    editDetails()->page()->addGroupBox(1, 0, 1, 1);

    editDetails()->page()->newGroupBox(tr("Level"));
    editDetails()->page()->addKnob(0, 0, 1, 1, "02", "00", "33");  //level
    editDetails()->page()->addGroupBox(0, 1, 2, 1);

    editDetails()->addPage();
}
