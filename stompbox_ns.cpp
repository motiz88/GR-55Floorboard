/****************************************************************************
**
** Copyright (C) 2007~2012 Colin Willcocks.
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

#include "stompbox_ns.h"

stompbox_ns::stompbox_ns(QWidget *parent)
    : stompBox(parent)
{
    /* ns */
    setImage(":/images/ns.png");
    setLSB("07", "5A");
    setKnob1("07", "00", "5B");
    setKnob2("07", "00", "5C");
    setSwitch("07", "00", "5A");
    editDetails()->patchPos(1660, 6, "07", "5A"); //correct
    setEditPages();
};

void stompbox_ns::updateSignal()
{
    updateKnob1("07", "00", "5B");
    updateKnob2("07", "00", "5C");
    updateSwitch("07", "00", "5A");
};

void stompbox_ns::setEditPages()
{
    editDetails()->page()->newGroupBox("Effect");
    editDetails()->page()->addSwitch(0, 0, 1, 1, "07", "00", "5A", "middle", Qt::AlignCenter);
    editDetails()->page()->addGroupBox(0, 0, 1, 1);

    editDetails()->page()->newGroupBox("Noise Suppressor");
    editDetails()->page()->addKnob(0, 0, 1, 1, "07", "00", "5B");
    editDetails()->page()->addKnob(0, 1, 1, 1, "07", "00", "5C");
    editDetails()->page()->addGroupBox(0, 1, 1, 1);
    editDetails()->addPage();

};
