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
        setLSB("00", "00");
        setKnob1("00", "00", "00");
        setKnob2("00", "00", "00");
        setComboBox("00", "00", "00");
        setSwitch("00", "00", "00");
        editDetails()->patchPos(2702, 50, "0A", "00");
	setEditPages();
};

void stompbox_dd::updateSignal()
{
        updateKnob1("00", "00", "00");
        updateKnob2("00", "00", "00");
        updateComboBox("00", "00", "00");
        updateSwitch("00", "00", "00");
};

void stompbox_dd::setEditPages()
{
    editDetails()->page()->newGroupBox("Effect");
/*	editDetails()->page()->addSwitch(0, 0, 1, 1, "0A", "00", "00", "middle", Qt::AlignCenter);
	editDetails()->page()->newStackControl(0);
	editDetails()->page()->addComboBox(1, 0, 1, 1, "0A", "00", "01");
	editDetails()->page()->addStackControl();    */
	editDetails()->page()->addGroupBox(0, 0, 2, 1);

	
/*	editDetails()->page()->insertStackField(0, 0, 1, 2, 1);
	// SINGLE 
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Delay");
	editDetails()->page()->addKnob(0, 0, 1, 1, "0A", "00", "02", "normal","right", 105);
	editDetails()->page()->addKnob(0, 1, 1, 1, "0A", "00", "05");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);

	editDetails()->page()->newGroupBox("Filter");
	editDetails()->page()->addKnob(0, 0, 1, 1, "0A", "00", "06");
	editDetails()->page()->addGroupBox(0, 1, 1, 1);

	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "0A", "00", "17");
	editDetails()->page()->addKnob(0, 1, 1, 1, "0A", "00", "18");
	editDetails()->page()->addGroupBox(0, 2, 1, 1);
	editDetails()->page()->addStackField();

	// PAN 
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Delay");
	editDetails()->page()->addKnob(0, 0, 1, 1, "0A", "00", "02", "normal","right", 105);
	editDetails()->page()->addKnob(0, 1, 1, 1, "0A", "00", "04");
	editDetails()->page()->addKnob(0, 2, 1, 1, "0A", "00", "05");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);

	editDetails()->page()->newGroupBox("Filter");
	editDetails()->page()->addKnob(0, 0, 1, 1, "0A", "00", "06");
	editDetails()->page()->addGroupBox(0, 1, 1, 1);

	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "0A", "00", "17");
	editDetails()->page()->addKnob(0, 1, 1, 1, "0A", "00", "18");
	editDetails()->page()->addGroupBox(0, 2, 1, 1);
	editDetails()->page()->addStackField();

	// STEREO 
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Delay");
	editDetails()->page()->addKnob(0, 0, 1, 1, "0A", "00", "02", "normal","right", 105);
	editDetails()->page()->addKnob(0, 1, 1, 1, "0A", "00", "05");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);

	editDetails()->page()->newGroupBox("Filter");
	editDetails()->page()->addKnob(0, 0, 1, 1, "0A", "00", "06");
	editDetails()->page()->addGroupBox(0, 1, 1, 1);

	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "0A", "00", "17");
	editDetails()->page()->addKnob(0, 1, 1, 1, "0A", "00", "18");
	editDetails()->page()->addGroupBox(0, 2, 1, 1);
	editDetails()->page()->addStackField();

	// DUAL SERIES 
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Delay 1");
	editDetails()->page()->addKnob(0, 0, 1, 1, "0A", "00", "07", "normal","right", 105);
	editDetails()->page()->addKnob(0, 1, 1, 1, "0A", "00", "09");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);

	editDetails()->page()->newGroupBox("Delay 2");
	editDetails()->page()->addKnob(0, 0, 1, 1, "0A", "00", "0C", "normal","right", 105);
	editDetails()->page()->addKnob(0, 1, 1, 1, "0A", "00", "0E");
	editDetails()->page()->addGroupBox(1, 0, 1, 1);

	editDetails()->page()->newGroupBox("Filter 1");
	editDetails()->page()->addKnob(0, 0, 1, 1, "0A", "00", "0A");          //#
	editDetails()->page()->addGroupBox(0, 1, 1, 1);

	editDetails()->page()->newGroupBox("Filter 2");
	editDetails()->page()->addKnob(0, 0, 1, 1, "0A", "00", "0F");
	editDetails()->page()->addGroupBox(1, 1, 1, 1);

	editDetails()->page()->newGroupBox("Level 1");
	editDetails()->page()->addKnob(0, 0, 1, 1, "0A", "00", "0B");
	editDetails()->page()->addGroupBox(0, 2, 1, 1);

	editDetails()->page()->newGroupBox("Level 2");
	editDetails()->page()->addKnob(0, 0, 1, 1, "0A", "00", "10");
	editDetails()->page()->addGroupBox(1, 2, 1, 1);

	editDetails()->page()->newGroupBox("Direct");
	editDetails()->page()->addKnob(0, 0, 1, 1, "0A", "00", "18");
	editDetails()->page()->addGroupBox(0, 3, 2, 1);
	editDetails()->page()->addStackField();

	// DUAL PARALLEL 
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Delay 1");
	editDetails()->page()->addKnob(0, 0, 1, 1, "0A", "00", "07", "normal","right", 105);
	editDetails()->page()->addKnob(0, 1, 1, 1, "0A", "00", "09");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);

	editDetails()->page()->newGroupBox("Delay 2");
	editDetails()->page()->addKnob(0, 0, 1, 1, "0A", "00", "0C", "normal","right", 105);
	editDetails()->page()->addKnob(0, 1, 1, 1, "0A", "00", "0E");
	editDetails()->page()->addGroupBox(1, 0, 1, 1);

	editDetails()->page()->newGroupBox("Filter 1");
	editDetails()->page()->addKnob(0, 0, 1, 1, "0A", "00", "0A");                      //#
	editDetails()->page()->addGroupBox(0, 1, 1, 1);

	editDetails()->page()->newGroupBox("Filter 2");
	editDetails()->page()->addKnob(0, 0, 1, 1, "0A", "00", "0F");
	editDetails()->page()->addGroupBox(1, 1, 1, 1);

	editDetails()->page()->newGroupBox("Level 1");
	editDetails()->page()->addKnob(0, 0, 1, 1, "0A", "00", "0B");
	editDetails()->page()->addGroupBox(0, 2, 1, 1);

	editDetails()->page()->newGroupBox("Level 2");
	editDetails()->page()->addKnob(0, 0, 1, 1, "0A", "00", "10");
	editDetails()->page()->addGroupBox(1, 2, 1, 1);

	editDetails()->page()->newGroupBox("Direct");
	editDetails()->page()->addKnob(0, 0, 1, 1, "0A", "00", "18");
	editDetails()->page()->addGroupBox(0, 3, 2, 1);
	editDetails()->page()->addStackField();

	// DUAL L/R 
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Delay 1");
	editDetails()->page()->addKnob(0, 0, 1, 1, "0A", "00", "07", "normal","right", 105);
	editDetails()->page()->addKnob(0, 1, 1, 1, "0A", "00", "09");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);

	editDetails()->page()->newGroupBox("Delay 2");
	editDetails()->page()->addKnob(0, 0, 1, 1, "0A", "00", "0C", "normal","right", 105);
	editDetails()->page()->addKnob(0, 1, 1, 1, "0A", "00", "0E");
	editDetails()->page()->addGroupBox(1, 0, 1, 1);

	editDetails()->page()->newGroupBox("Filter 1");
	editDetails()->page()->addKnob(0, 0, 1, 1, "0A", "00", "0A");                                //#
	editDetails()->page()->addGroupBox(0, 1, 1, 1);

	editDetails()->page()->newGroupBox("Filter 2");
	editDetails()->page()->addKnob(0, 0, 1, 1, "0A", "00", "0F");
	editDetails()->page()->addGroupBox(1, 1, 1, 1);

	editDetails()->page()->newGroupBox("Level 1");
	editDetails()->page()->addKnob(0, 0, 1, 1, "0A", "00", "0B");
	editDetails()->page()->addGroupBox(0, 2, 1, 1);

	editDetails()->page()->newGroupBox("Level 2");
	editDetails()->page()->addKnob(0, 0, 1, 1, "0A", "00", "10");
	editDetails()->page()->addGroupBox(1, 2, 1, 1);

	editDetails()->page()->newGroupBox("Direct");
	editDetails()->page()->addKnob(0, 0, 1, 1, "0A", "00", "18");
	editDetails()->page()->addGroupBox(0, 3, 2, 1);
	editDetails()->page()->addStackField();

	// REVERSE 
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Delay");
	editDetails()->page()->addKnob(0, 0, 1, 1, "0A", "00", "02", "normal","right", 105);
	editDetails()->page()->addKnob(0, 1, 1, 1, "0A", "00", "05");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);

	editDetails()->page()->newGroupBox("Filter");
	editDetails()->page()->addKnob(0, 0, 1, 1, "0A", "00", "06");
	editDetails()->page()->addGroupBox(0, 1, 1, 1);

	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "0A", "00", "17");
	editDetails()->page()->addKnob(0, 1, 1, 1, "0A", "00", "18");
	editDetails()->page()->addGroupBox(0, 2, 1, 1);
	editDetails()->page()->addStackField();

	// ANALOG 
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Delay");
	editDetails()->page()->addKnob(0, 0, 1, 1, "0A", "00", "02", "normal","right", 105);
	editDetails()->page()->addKnob(0, 1, 1, 1, "0A", "00", "05");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);

	editDetails()->page()->newGroupBox("Filter");
	editDetails()->page()->addKnob(0, 0, 1, 1, "0A", "00", "06");
	editDetails()->page()->addGroupBox(0, 1, 1, 1);

	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "0A", "00", "17");
	editDetails()->page()->addKnob(0, 1, 1, 1, "0A", "00", "18");
	editDetails()->page()->addGroupBox(0, 2, 1, 1);
	editDetails()->page()->addStackField();

	// TAPE 
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Delay");
	editDetails()->page()->addKnob(0, 0, 1, 1, "0A", "00", "02", "normal","right", 105);
	editDetails()->page()->addKnob(0, 1, 1, 1, "0A", "00", "05");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);

	editDetails()->page()->newGroupBox("Filter");
	editDetails()->page()->addKnob(0, 0, 1, 1, "0A", "00", "06");
	editDetails()->page()->addGroupBox(0, 1, 1, 1);

	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "0A", "00", "17");
	editDetails()->page()->addKnob(0, 1, 1, 1, "0A", "00", "18");
	editDetails()->page()->addGroupBox(0, 2, 1, 1);
	editDetails()->page()->addStackField();

	// WARP 
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Delay");
	editDetails()->page()->addKnob(0, 0, 1, 1, "0A", "00", "02", "normal","right", 105);
	editDetails()->page()->addKnob(0, 1, 1, 1, "0A", "00", "05");
	editDetails()->page()->addGroupBox(0, 0, 1, 3);

	editDetails()->page()->newGroupBox("Warp", Qt::AlignTop | Qt::AlignHCenter);
	editDetails()->page()->addSwitch(0, 0, 1, 1, "0A", "00", "11", "middle", Qt::AlignCenter);
	editDetails()->page()->addKnob(0, 1, 1, 1, "0A", "00", "12");
	editDetails()->page()->addGroupBox(1, 0, 1, 1);

	editDetails()->page()->newGroupBox("Depth");
	editDetails()->page()->addKnob(0, 0, 1, 1, "0A", "00", "13");
	editDetails()->page()->addKnob(0, 1, 1, 1, "0A", "00", "14");
	editDetails()->page()->addGroupBox(1, 1, 1, 1);

	editDetails()->page()->newGroupBox("Filter");
	editDetails()->page()->addKnob(0, 0, 1, 1, "0A", "00", "06");
	editDetails()->page()->addGroupBox(0, 3, 2, 1);

	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "0A", "00", "17");
	editDetails()->page()->addKnob(0, 1, 1, 1, "0A", "00", "18");
	editDetails()->page()->addGroupBox(0, 4, 2, 1);
	editDetails()->page()->addStackField();

	// MODULATE 
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Delay");
	editDetails()->page()->addKnob(0, 0, 1, 1, "0A", "00", "02", "normal","right", 105);
	editDetails()->page()->addKnob(0, 1, 1, 1, "0A", "00", "05");
	editDetails()->page()->addGroupBox(0, 0, 1, 2);

	editDetails()->page()->newGroupBox("Modulate");
	editDetails()->page()->addKnob(0, 0, 1, 1, "0A", "00", "15");
	editDetails()->page()->addKnob(0, 1, 1, 1, "0A", "00", "16");
	editDetails()->page()->addGroupBox(1, 0, 1, 2);

	editDetails()->page()->newGroupBox("Filter");
	editDetails()->page()->addKnob(0, 0, 1, 1, "0A", "00", "06");
	editDetails()->page()->addGroupBox(0, 2, 2, 1);

	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "0A", "00", "17");
	editDetails()->page()->addKnob(0, 1, 1, 1, "0A", "00", "18");
	editDetails()->page()->addGroupBox(0, 3, 2, 1);
	editDetails()->page()->addStackField();       */

	editDetails()->addPage();
};
