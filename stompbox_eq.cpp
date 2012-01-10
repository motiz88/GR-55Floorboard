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

#include "stompbox_eq.h"

stompbox_eq::stompbox_eq(QWidget *parent)
    : stompBox(parent)
{
    /* EQ */
    setImage(":/images/eq.png");
    setLSB("06", "11");
    setSlider1("06", "00", "13");
    setSlider2("06", "00", "16");
    setSlider3("06", "00", "19");
    setSlider4("06", "00", "1B");
    setSlider5("06", "00", "1C");
    setComboBox("06", "00", "1D");
    setSwitch("06", "00", "11");
    editDetails()->patchPos(1428, 26, "06", "11"); //correct
    setEditPages();
};

void stompbox_eq::updateSignal()
{
    updateSlider1("06", "00", "13");
    updateSlider2("06", "00", "16");
    updateSlider3("06", "00", "19");
    updateSlider4("06", "00", "1B");
    updateSlider5("06", "00", "1C");
    updateComboBox("06", "00", "1D");
    updateSwitch("06", "00", "11");
};

void stompbox_eq::setEditPages()
{
    /*editDetails()->page()->newGroupBox("Effect", Qt::AlignTop | Qt::AlignHCenter);
    editDetails()->page()->addSwitch(0, 0, 1, 1, "06", "00", "11", "middle", Qt::AlignCenter);
    editDetails()->page()->addParaEQ(0, 1, 2, 4, "06", "00", "12");
    editDetails()->page()->addGroupBox(0, 0, 2, 4);*/

    editDetails()->page()->newGroupBox("Effect", Qt::AlignTop | Qt::AlignHCenter);
    editDetails()->page()->addSwitch(0, 0, 1, 1, "06", "00", "11", "middle", Qt::AlignCenter);
    editDetails()->page()->addGroupBox(0, 0, 1, 1);

    editDetails()->page()->newGroupBox("Equalizer");
    editDetails()->page()->newGroupBox("Low");
    editDetails()->page()->addKnob(0, 0, 1, 1, "06", "00", "12");
    editDetails()->page()->addKnob(0, 1, 1, 1, "06", "00", "13");
    editDetails()->page()->addGroupBox(0, 0, 1, 1);

    editDetails()->page()->newGroupBox("Low-Middle");
    editDetails()->page()->addKnob(0, 0, 1, 1, "06", "00", "16");
    editDetails()->page()->addKnob(1, 0, 1, 1, "06", "00", "14");
    editDetails()->page()->addKnob(2, 0, 1, 1, "06", "00", "15");
    editDetails()->page()->addGroupBox(0, 1, 1, 1);

    editDetails()->page()->newGroupBox("High-Middle");
    editDetails()->page()->addKnob(0, 0, 1, 1, "06", "00", "19");
    editDetails()->page()->addKnob(1, 0, 1, 1, "06", "00", "17");
    editDetails()->page()->addKnob(2, 0, 1, 1, "06", "00", "18");
    editDetails()->page()->addGroupBox(0, 2, 1, 1);

    editDetails()->page()->newGroupBox("High");
    editDetails()->page()->addKnob(0, 0, 1, 1, "06", "00", "1B");
    editDetails()->page()->addKnob(0, 1, 1, 1, "06", "00", "1A");
    editDetails()->page()->addGroupBox(0, 3, 1, 1);
    editDetails()->page()->addGroupBox(0, 1, 1, 1);

    editDetails()->page()->newGroupBox("Level");
    editDetails()->page()->addKnob(0, 0, 1, 1, "06", "00", "1C");
    editDetails()->page()->addKnob(2, 0, 1, 1, "06", "00", "1D");
    editDetails()->page()->addGroupBox(0, 2, 1, 1);
    editDetails()->addPage();
};
