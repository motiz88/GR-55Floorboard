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

#include "stompbox_ce.h"

stompbox_ce::stompbox_ce(QWidget *parent)
    : stompBox(parent)
{
	/* Chorus */
	setImage(":/images/ce.png");
        setLSB("06", "00");
        setKnob1("06", "00", "02");
        setKnob2("06", "00", "03");
        setComboBox("06", "00", "01");
        setSwitch("06", "00", "00");
        editDetails()->patchPos(1394, 10, "06", "00");  //correct
	setEditPages();
};

void stompbox_ce::updateSignal()
{
        updateKnob1("06", "00", "02");
        updateKnob2("06", "00", "03");
        updateComboBox("06", "00", "01");
        updateSwitch("06", "00", "00");
};

void stompbox_ce::setEditPages()
{
  editDetails()->page()->newGroupBox(tr("Effect"));
        editDetails()->page()->addSwitch(0, 0, 1, 1, "06", "00", "00", "middle", Qt::AlignCenter); //sw
        editDetails()->page()->addComboBox(1, 0, 1, 1, "06", "00", "01");                          //type
	editDetails()->page()->addGroupBox(0, 0, 2, 1);

	editDetails()->page()->newGroupBox(tr("Chorus"));
        editDetails()->page()->addKnob(0, 0, 1, 3, "06", "00", "02", "normal","right", 105);//rate
        editDetails()->page()->addKnob(1, 0, 1, 1, "06", "00", "03");                       //depth
	editDetails()->page()->addGroupBox(0, 1, 2, 1);

	editDetails()->page()->newGroupBox(tr("Level"));
        editDetails()->page()->addKnob(0, 0, 1, 1, "06", "00", "04");
	editDetails()->page()->addGroupBox(0, 3, 2, 1);

        editDetails()->page()->newGroupBox(tr("Send Levels"));
        editDetails()->page()->addKnob(0, 0, 1, 1, "07", "00", "11");           //MOD
        editDetails()->page()->addKnob(0, 1, 1, 1, "03", "00", "00");           //MFX
        editDetails()->page()->addKnob(0, 2, 1, 1, "02", "00", "3E");           //bypass
        editDetails()->page()->addGroupBox(2, 0, 1, 4);

	editDetails()->addPage();
  	
};
