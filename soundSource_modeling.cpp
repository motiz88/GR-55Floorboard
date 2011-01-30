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

#include "soundsource_modeling.h"

soundsource_modeling::soundsource_modeling(QWidget *parent)
    : soundSource(parent)
{
        /* MODELING */
	this->setImage(":/images/modeling.png");
        setLSB("00", "00");
        setSwitch("00", "00", "12");
        setComboBox("00", "routeSwitch", "22");
        setKnob1("00", "00", "00");
        //setKnob2("01", "00", "36");
        //editDetails()->patchPos(400, 58, "01", "30");
	setEditPages();
};

void soundsource_modeling::updateSignal()
{
    updateSwitch("00", "00", "12");
    updateComboBox("00", "routeSwitch", "22");
    updateKnob1("00", "00", "00");
    //updateKnob2("01", "00", "36");
};

void soundsource_modeling::setEditPages()
{
  editDetails()->addPage();
  //editDetails()->patchPos(-1, -1, "void", "void");
};
