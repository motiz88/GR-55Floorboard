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

#include "stompbox_ce.h"

stompbox_ce::stompbox_ce(QWidget *parent)
    : stompBox(parent)
{
	/* Chorus */
	setImage(":/images/ce.png");
        setLSB("07", "00");
        setKnob1("07", "00", "00");
        setKnob2("07", "00", "00");
        setComboBox("07", "00", "00");
        setButton("00", "00", "00");
        //editDetails()->patchPos(2766, 16, "0A", "20");  */
	setEditPages();
};

void stompbox_ce::updateSignal()
{
        updateKnob1("00", "00", "00");
        updateKnob2("00", "00", "00");
        updateComboBox("00", "00", "00");
        updateButton("00", "00", "00");
};

void stompbox_ce::setEditPages()
{
  editDetails()->page()->newGroupBox(tr("Effect"));
/*	editDetails()->page()->addSwitch(0, 0, 1, 1, "0A", "00", "20", "middle", Qt::AlignCenter);
	editDetails()->page()->addComboBox(1, 0, 1, 1, "0A", "00", "21");     */
	editDetails()->page()->addGroupBox(0, 0, 2, 1);

	editDetails()->page()->newGroupBox(tr("Chorus"));
/*	editDetails()->page()->addKnob(0, 0, 1, 3, "0A", "00", "22", "normal","right", 105);
	editDetails()->page()->addKnob(1, 0, 1, 1, "0A", "00", "23");
	editDetails()->page()->addKnob(1, 2, 1, 1, "0A", "00", "24");   */
	editDetails()->page()->addGroupBox(0, 1, 2, 1);

	editDetails()->page()->newGroupBox(tr("Filter"));
/*	editDetails()->page()->addKnob(0, 0, 1, 1, "0A", "00", "25");
	editDetails()->page()->addKnob(0, 1, 1, 1, "0A", "00", "26");     */
	editDetails()->page()->addGroupBox(0, 2, 2, 1);

	editDetails()->page()->newGroupBox(tr("Level"));
	//editDetails()->page()->addKnob(0, 0, 1, 1, "0A", "00", "27");
	editDetails()->page()->addGroupBox(0, 3, 2, 1);

	editDetails()->addPage();
  	
};
