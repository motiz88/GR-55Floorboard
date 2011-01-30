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

#include "menuPage_master.h"

menuPage_master::menuPage_master(QWidget *parent)
    : menuPage(parent)
{
  //setImage(":/images/master_pushbutton.png");
 // setLSB("0A", "00");
 // editDetails()->patchPos(2894, 20, "0A", "60");    
	setEditPages();
};

void menuPage_master::updateSignal()
{

};

void menuPage_master::setEditPages()
{
  
	editDetails()->page()->newGroupBox("Master");
  // editDetails()->page()->addMasterEQ(0, 1, 2, 4, "0A", "00", "60");
    /*editDetails()->page()->addKnob(0, 0, 1, 1, "0A", "00", "61");                        // master low
    editDetails()->page()->addKnob(0, 1, 1, 1, "0A", "00", "62");                        // master mid gain
    editDetails()->page()->addKnob(1, 1, 1, 1, "0A", "00", "63");                        // master mid Q
    editDetails()->page()->addKnob(2, 1, 1, 1, "0A", "00", "64");                        // master mid freq
    editDetails()->page()->addKnob(0, 2, 1, 1, "0A", "00", "65");                        // master high
    editDetails()->page()->addKnob(0, 3, 1, 1, "0A", "00", "60");  */                      // master gain
                       // master gain
	editDetails()->page()->addGroupBox(0, 0, 1, 1);

  editDetails()->page()->newGroupBox("Master");
 // editDetails()->page()->addKnob(0, 0, 1, 1, "0A", "00", "66");                         // master BPM
 // editDetails()->page()->addComboBox(1, 0, 1, 1, "0A", "00", "68");                     // master key
	editDetails()->page()->addGroupBox(0, 1, 1, 1);

  editDetails()->page()->newGroupBox("Amp Control Jack");
  //editDetails()->page()->addComboBox(0, 0, 1, 1, "0A", "00", "69");                     // amp control
	editDetails()->page()->addGroupBox(0, 2, 1, 1);

	editDetails()->addPage();      
};
