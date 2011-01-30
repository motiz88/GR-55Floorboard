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

#include "soundsource_analogPU.h"

soundsource_analogPU::soundsource_analogPU(QWidget *parent)
    : soundSource(parent)
{
        /* ANALOG PICKUP */
	this->setImage(":/images/analogPU.png");
        setLSB("00", "00");
        setComboBox("00", "routeSwitch", "23");
	//setComboBox2("01", "00", "02", QRect(8, 98, 79, 13));
        setSwitch("00", "00", "12");
	//editDetails()->patchPos(304, 10, "01", "00"); 
	setEditPages();
};

void soundsource_analogPU::updateSignal()
{
        updateComboBox("00", "routeSwitch", "23");
	//updateComboBox2("01", "00", "02");
        updateSwitch("00", "00", "12");
};

void soundsource_analogPU::setEditPages()
{
  editDetails()->page()->newGroupBox(tr("PreAmp Effect"));
        editDetails()->page()->addSwitch(0, 0, 1, 1, "00", "00", "12", "middle", Qt::AlignCenter);   // off/on effect
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	
  editDetails()->page()->newGroupBox(tr("Channel"));
	//editDetails()->page()->newStackControl(0);
        editDetails()->page()->addComboBox(2, 0, 1, 1, "00", "00", "23");   //mode
	//editDetails()->page()->addStackControl();
	editDetails()->page()->addGroupBox(1, 0, 1, 1);

	// TYPE SETTINGS 
	/*editDetails()->page()->insertStackField(0, 2, 0, 1, 1);

	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox(tr("Channel select"));
	editDetails()->page()->addComboBox(1, 0, 1, 1, "01", "00", "02"); // channel select
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0, Qt::AlignCenter);
	editDetails()->page()->newGroupBox(tr("Channel Delay"));
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "03");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addStackField();

	editDetails()->page()->newStackField(0, Qt::AlignCenter);
	editDetails()->page()->newGroupBox(tr("Channel Delay"));
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "03");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addStackField();

	editDetails()->page()->newStackField(0, Qt::AlignCenter);
	editDetails()->page()->newGroupBox(tr("Dynamic switching"));
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "04");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addStackField();         */
    
	editDetails()->addPage();	
};
