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

#include "stompbox_cs.h"

stompbox_cs::stompbox_cs(QWidget *parent)
    : stompBox(parent)
{
	/* COMP */
	setImage(":/images/cs.png");
	setLSB("00", "00");
	setKnob1("00", "00", "42");
	setKnob2("00", "00", "47");
	setComboBox("00", "00", "41");
	setButton("00", "00", "40");
	editDetails()->patchPos(150, 16, "00", "40"); 
	setEditPages();
};

void stompbox_cs::updateSignal()
{
	updateKnob1("00", "00", "42");
	updateKnob2("00", "00", "47");
	updateComboBox("00", "00", "41");
	updateButton("00", "00", "40");
};

void stompbox_cs::setEditPages()
{
	editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "00", "00", "40", "middle", Qt::AlignCenter);
	editDetails()->page()->newStackControl(0);
	editDetails()->page()->addComboBox(1, 0, 1, 1, "00", "00", "41");
	editDetails()->page()->addStackControl();
	editDetails()->page()->addGroupBox(0, 0, 1, 1);

	// COMPRESSOR 
	editDetails()->page()->insertStackField(0, 0, 1, 1, 1);
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Compressor");
	editDetails()->page()->addKnob(0, 0, 1, 1, "00", "00", "42");
	editDetails()->page()->addKnob(0, 1, 1, 1, "00", "00", "43");
	//editDetails()->page()->addKnob(0, 2, 1, 1, "00", "00", "44");
	editDetails()->page()->addKnob(0, 2, 1, 1, "00", "00", "46");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);

	editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addKnob(0, 0, 1, 1, "00", "00", "47");
	editDetails()->page()->addGroupBox(0, 1, 1, 1);
	editDetails()->page()->addStackField();

	// LIMITER 
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Limiter");
	editDetails()->page()->addKnob(0, 0, 1, 1, "00", "00", "44");
	editDetails()->page()->addKnob(0, 1, 1, 1, "00", "00", "45");
	//editDetails()->page()->addKnob(0, 2, 1, 1, "00", "00", "43");
	editDetails()->page()->addKnob(0, 2, 1, 1, "00", "00", "46");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);

	editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addKnob(0, 0, 1, 1, "00", "00", "47");
	editDetails()->page()->addGroupBox(0, 1, 1, 1);
	editDetails()->page()->addStackField();

	editDetails()->addPage();
};
