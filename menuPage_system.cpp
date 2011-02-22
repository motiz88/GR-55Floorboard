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

#include "menuPage_system.h"

menuPage_system::menuPage_system(QWidget *parent)
    : menuPage(parent)
{ 
  //setImage(":/images/system_pushbutton.png");
  //setLSB("00", "00");
	setEditPages();
};

void menuPage_system::updateSignal()
{

};

void menuPage_system::setEditPages()
{ 
  QString text = tr("***CAUTION*** Settings changes are automatically written to GR-55 when changed");         
/*	editDetails()->page()->addLabel(0, 0, 1, 1, text);
  editDetails()->page()->newGroupBox("settings");
  editDetails()->page()->addKnob(0, 0, 1, 1, "00", "00", "00", "System"); // lcd contrast
  editDetails()->page()->addLabel(0, 1, 1, 1, "     ");
	editDetails()->page()->addComboBox(0, 2, 1, 1, "00", "00", "10", "System"); // preamp mode
	editDetails()->page()->addLabel(0, 3, 1, 1, "     ");
	editDetails()->page()->addComboBox(0, 4, 1, 1, "00", "00", "17", "System"); //exp hold
	editDetails()->page()->addLabel(0, 5, 1, 1, "     ");
	editDetails()->page()->addComboBox(0, 6, 1, 1, "00", "00", "18", "System"); //exp indication
	editDetails()->page()->addLabel(0, 7, 1, 1, "     ");
	editDetails()->page()->addComboBox(0, 8, 1, 1, "00", "00", "70", "System"); // sys num pdl ctrl
	editDetails()->page()->addLabel(0, 9, 1, 1, "     ");
	editDetails()->page()->addComboBox(0, 10, 1, 1, "00", "00", "71", "System"); // dial function         
	editDetails()->page()->addGroupBox(1, 0, 1, 2);
	  
	editDetails()->page()->newGroupBox("USB settings");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "00", "00", "20", "System"); //usb driver mode
	editDetails()->page()->addLabel(0, 1, 1, 1, "     ");
	editDetails()->page()->addComboBox(0, 2, 1, 1, "00", "00", "21", "System"); //usb monitor cmd
	editDetails()->page()->addKnob(0, 3, 1, 1, "00", "00", "22", "System"); //dgt out level
	editDetails()->page()->addKnob(0, 4, 1, 1, "00", "00", "23", "System"); //usb mix level
	editDetails()->page()->addGroupBox(2, 0, 1, 1);
	
	editDetails()->page()->newGroupBox("Tuner");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "00", "00", "30", "System"); // tuner pitch
	editDetails()->page()->addLabel(0, 1, 1, 1, "               ");
	editDetails()->page()->addComboBox(0, 2, 1, 1, "00", "00", "31", "System"); //tuner bypass
	editDetails()->page()->addGroupBox(2, 1, 1, 1);
	
	editDetails()->page()->newGroupBox("Patch Change");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "00", "00", "11", "System"); // patch change mode
	editDetails()->page()->addComboBox(0, 1, 1, 1, "00", "00", "12", "System"); // bank change mode
	editDetails()->page()->addKnob(0, 2, 1, 1, "00", "00", "13", "System"); // bank extent min
	editDetails()->page()->addKnob(0, 3, 1, 1, "00", "00", "15", "System"); // bank extent max
	editDetails()->page()->addGroupBox(3, 1, 1, 1);
	
	editDetails()->page()->newGroupBox("Input settings and Global NS/Reverb");
	editDetails()->page()->newStackControl(0);
	editDetails()->page()->addComboBox(0, 0, 1, 1, "00", "00", "4D", "System"); // input select
	editDetails()->page()->addStackControl();
	editDetails()->page()->insertStackField(0, 0, 1, 1, 1);
	editDetails()->page()->addKnob(0, 3, 1, 1, "00", "00", "50", "System"); // NS threshold
  editDetails()->page()->addKnob(0, 4, 1, 1, "00", "00", "51", "System"); // revberb level
	editDetails()->page()->addGroupBox(3, 0, 1, 1);
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->addKnob(0, 0, 1, 1, "00", "00", "40", "System"); // gat 1 input level
	editDetails()->page()->addKnob(0, 1, 1, 1, "00", "00", "41", "System"); // gat 1 input pres
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->addKnob(0, 0, 1, 1, "00", "00", "42", "System"); // gat 2 input level
	editDetails()->page()->addKnob(0, 1, 1, 1, "00", "00", "43", "System"); // gat 2 input pres
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->addKnob(0, 0, 1, 1, "00", "00", "44", "System"); // gat 3 input level
	editDetails()->page()->addKnob(0, 1, 1, 1, "00", "00", "45", "System"); // gat 3 input pres
	editDetails()->page()->addStackField();

	editDetails()->page()->newStackField(0);
	editDetails()->page()->addKnob(0, 0, 1, 1, "00", "00", "46", "System"); // usb input level
	editDetails()->page()->addKnob(0, 1, 1, 1, "00", "00", "47", "System"); // usb input pres
	editDetails()->page()->addStackField();
  editDetails()->addPage("00", "00", "01", "00", "System");


	
	editDetails()->page()->newGroupBox("User Options " + text);
	editDetails()->page()->newGroupBox("Output");
  editDetails()->page()->addComboBox(0, 0, 1, 1, "00", "00", "4E", "System"); // output mode
  editDetails()->page()->addLabel(0, 1, 1, 1, "     ");
  editDetails()->page()->addComboBox(0, 2, 1, 1, "00", "00", "4F", "System"); // output select
	editDetails()->page()->addKnob(0, 3, 1, 1, "00", "00", "52", "System"); // main out
	editDetails()->page()->addGroupBox(0, 0, 1, 1);

	editDetails()->page()->newGroupBox("Phrase Looper");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "00", "00", "60", "System"); // PH LOOP mode
	editDetails()->page()->addComboBox(1, 0, 1, 1, "00", "00", "61", "System"); // record mode
	editDetails()->page()->addComboBox(2, 0, 1, 1, "00", "00", "62", "System"); // pedal mode
	editDetails()->page()->addComboBox(3, 0, 1, 1, "00", "00", "63", "System"); // clear pdl
	editDetails()->page()->addKnob(4, 0, 1, 1, "00", "00", "64", "System"); // play level 
	editDetails()->page()->addGroupBox(0, 1, 4, 1);
	
	editDetails()->page()->newGroupBox("Knob Function");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "00", "00", "72", "System"); // knob P1
	editDetails()->page()->addComboBox(0, 1, 1, 1, "00", "00", "74", "System"); // knob P2
	editDetails()->page()->addComboBox(0, 2, 1, 1, "00", "00", "76", "System"); // knob P3
	editDetails()->page()->addComboBox(0, 3, 1, 1, "00", "00", "78", "System"); // knob P4
	editDetails()->page()->addGroupBox(2, 0, 1, 1);
	
	editDetails()->page()->newGroupBox("Global Equalizer");
	editDetails()->page()->addKnob(0, 0, 1, 1, "00", "00", "48", "System"); // eq low
	editDetails()->page()->addLabel(0, 1, 1, 1, "       ");
  editDetails()->page()->addKnob(0, 2, 1, 1, "00", "00", "49", "System"); // eq mid gain
  editDetails()->page()->addKnob(0, 3, 1, 1, "00", "00", "4A", "System"); // eq mid Q
  editDetails()->page()->addKnob(0, 4, 1, 1, "00", "00", "4B", "System"); // eq mid freq
  editDetails()->page()->addLabel(0, 5, 1, 1, "       ");
  editDetails()->page()->addKnob(0, 6, 1, 1, "00", "00", "4C", "System"); // eq high
	editDetails()->page()->addGroupBox(3, 0, 1, 1);
	
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->addPage("00", "00", "01", "01", "System");
	
	editDetails()->page()->newGroupBox("Internal Pedals " + text);
	editDetails()->page()->addComboBox(0, 0, 1, 1, "00", "00", "7A", "System"); // exp1 pdl
	editDetails()->page()->addComboBox(0, 1, 1, 1, "00", "01", "10", "System"); // exp1 setting
	editDetails()->page()->addComboBox(0, 2, 1, 1, "00", "01", "11", "System"); // exp1 function
	editDetails()->page()->addKnob(0, 3, 1, 1, "00", "01", "13", "System"); // exp1 min
	editDetails()->page()->addKnob(0, 4, 1, 1, "00", "01", "15", "System"); // exp1 max
	editDetails()->page()->addComboBox(0, 5, 1, 1, "00", "01", "17", "System"); // exp1 src mode
	editDetails()->page()->addRange(0, 6, 1, 2, "00", "01", "18", "System");         // min/max range widget
	
	editDetails()->page()->addComboBox(1, 0, 1, 1, "00", "00", "7B", "System"); // exp1 pdl sw
	editDetails()->page()->addComboBox(1, 1, 1, 1, "00", "01", "20", "System"); // exp1 sw setting
	editDetails()->page()->addComboBox(1, 2, 1, 1, "00", "01", "21", "System"); // exp1 sw function
	editDetails()->page()->addKnob(1, 3, 1, 1, "00", "01", "23", "System"); // exp1 sw min
	editDetails()->page()->addKnob(1, 4, 1, 1, "00", "01", "25", "System"); // exp1 sw max
	editDetails()->page()->addComboBox(1, 5, 1, 1, "00", "01", "27", "System"); // exp1 sw src mode
	editDetails()->page()->addRange(1, 6, 1, 2, "00", "01", "28", "System");         // min/max range widget
	
	editDetails()->page()->addComboBox(2, 0, 1, 1, "00", "00", "7C", "System"); // ctrl 1
  editDetails()->page()->addComboBox(2, 1, 1, 1, "00", "01", "30", "System"); // ctl1 setting
	editDetails()->page()->addComboBox(2, 2, 1, 1, "00", "01", "31", "System"); // ctl1 function
	editDetails()->page()->addKnob(2, 3, 1, 1, "00", "01", "33", "System"); // ctl1 min
	editDetails()->page()->addKnob(2, 4, 1, 1, "00", "01", "35", "System"); // ctl1 max
	editDetails()->page()->addComboBox(2, 5, 1, 1, "00", "01", "37", "System"); // ctl1 src mode
	editDetails()->page()->addRange(2, 6, 1, 2, "00", "01", "38", "System");         // min/max range widget
	
	editDetails()->page()->addComboBox(3, 0, 1, 1, "00", "00", "7D", "System"); // ctrl 2
	editDetails()->page()->addComboBox(3, 1, 1, 1, "00", "01", "40", "System"); // ctl2 setting
	editDetails()->page()->addComboBox(3, 2, 1, 1, "00", "01", "41", "System"); // ctl2 function
	editDetails()->page()->addKnob(3, 3, 1, 1, "00", "01", "43", "System"); // ctl2 min
	editDetails()->page()->addKnob(3, 4, 1, 1, "00", "01", "45", "System"); // ctl2 max
	editDetails()->page()->addComboBox(3, 5, 1, 1, "00", "01", "47", "System"); // ctl2 src mode
	editDetails()->page()->addRange(3, 6, 1, 2, "00", "01", "48", "System");         // min/max range widget
	
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->addPage("00", "00", "01", "02", "System");
	
	editDetails()->page()->newGroupBox("External pedals " + text);
	editDetails()->page()->addComboBox(0, 0, 1, 1, "00", "00", "7E", "System"); // exp2 pdl
  editDetails()->page()->addComboBox(0, 1, 1, 1, "00", "01", "50", "System"); // exp2 setting
	editDetails()->page()->addComboBox(0, 2, 1, 1, "00", "01", "51", "System"); // exp2 function
	editDetails()->page()->addKnob(0, 3, 1, 1, "00", "01", "53", "System"); // exp2 min
	editDetails()->page()->addKnob(0, 4, 1, 1, "00", "01", "55", "System"); // exp2 max
	editDetails()->page()->addComboBox(0, 5, 1, 1, "00", "01", "57", "System"); // exp2 src mode
	editDetails()->page()->addRange(0, 6, 1, 2, "00", "01", "58", "System");         // min/max range widget
	
	editDetails()->page()->addComboBox(1, 0, 1, 1, "00", "00", "7F", "System"); // ctrl 3
	editDetails()->page()->addComboBox(1, 1, 1, 1, "00", "01", "60", "System"); // ctl3 setting
	editDetails()->page()->addComboBox(1, 2, 1, 1, "00", "01", "61", "System"); // ctl3 function
	editDetails()->page()->addKnob(1, 3, 1, 1, "00", "01", "63", "System"); // ctl3 min
	editDetails()->page()->addKnob(1, 4, 1, 1, "00", "01", "65", "System"); // ctl3 max
	editDetails()->page()->addComboBox(1, 5, 1, 1, "00", "01", "67", "System"); // ctl3 src mode
	editDetails()->page()->addRange(1, 6, 1, 2, "00", "01", "68", "System");         // min/max range widget
	
	editDetails()->page()->addComboBox(2, 0, 1, 1, "00", "01", "00", "System"); // ctrl 4
	editDetails()->page()->addComboBox(2, 1, 1, 1, "00", "01", "70", "System"); // ctl4 setting
	editDetails()->page()->addComboBox(2, 2, 1, 1, "00", "01", "71", "System"); // ctl4 function
	editDetails()->page()->addKnob(2, 3, 1, 1, "00", "01", "73", "System"); // ctl4 min
	editDetails()->page()->addKnob(2, 4, 1, 1, "00", "01", "75", "System"); // ctl4 max
	editDetails()->page()->addComboBox(2, 5, 1, 1, "00", "01", "77", "System"); // ctl4 src mode
	editDetails()->page()->addRange(2, 6, 1, 2, "00", "01", "78", "System");         // min/max range widget
	
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->addPage("00", "00", "01", "03", "System"); 
  
  
  editDetails()->page()->newGroupBox("User Category Names " + text);
 
  editDetails()->page()->addNameEdit(0, 0, 1, 1, "00", "02", "00", "System", "8"); //user catagory #1
  editDetails()->page()->addLabel(0, 1, 1, 1, "     ");
  editDetails()->page()->addNameEdit(0, 2, 1, 1, "00", "02", "08", "System", "8"); //user catagory #2
  editDetails()->page()->addLabel(0, 3, 1, 1, "     ");
  editDetails()->page()->addNameEdit(0, 4, 1, 1, "00", "02", "10", "System", "8"); //user catagory #3
  editDetails()->page()->addLabel(0, 5, 1, 1, "     ");
  editDetails()->page()->addNameEdit(0, 6, 1, 1, "00", "02", "18", "System", "8"); //user catagory #4
  editDetails()->page()->addNameEdit(1, 0, 1, 1, "00", "02", "20", "System", "8"); //user catagory #5
  editDetails()->page()->addNameEdit(1, 2, 1, 1, "00", "02", "28", "System", "8"); //user catagory #6
  editDetails()->page()->addNameEdit(1, 4, 1, 1, "00", "02", "30", "System", "8"); //user catagory #7
  editDetails()->page()->addNameEdit(1, 6, 1, 1, "00", "02", "38", "System", "8"); //user catagory #8
  editDetails()->page()->addNameEdit(2, 2, 1, 1, "00", "02", "40", "System", "8"); //user catagory #9
  editDetails()->page()->addNameEdit(2, 4, 1, 1, "00", "02", "48", "System", "8"); //user catagory #10
  editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->addPage("00", "00", "01", "04", "System"); 
  
  editDetails()->page()->newGroupBox("MANUAL and OD/DS variations " + text);
  editDetails()->page()->newGroupBox("MANUAL settings");
  editDetails()->page()->addComboBox(1, 0, 1, 1, "00", "02", "50", "System"); // manual pedal 1
	editDetails()->page()->addComboBox(1, 1, 1, 1, "00", "02", "51", "System"); // manual pedal 2
	editDetails()->page()->addComboBox(1, 2, 1, 1, "00", "02", "52", "System"); // manual pedal 3
	editDetails()->page()->addComboBox(1, 3, 1, 1, "00", "02", "53", "System"); // manual pedal 4
	editDetails()->page()->addComboBox(0, 2, 1, 1, "00", "02", "55", "System"); // manual bank down
	editDetails()->page()->addComboBox(0, 3, 1, 1, "00", "02", "54", "System"); // manual bank up
  editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->newGroupBox("Distortion variations");
  editDetails()->page()->addComboBox(0, 0, 1, 1, "00", "02", "60", "System"); // booster
	editDetails()->page()->addComboBox(0, 1, 1, 1, "00", "02", "61", "System"); // blues
	editDetails()->page()->addComboBox(0, 2, 1, 1, "00", "02", "62", "System"); // od
	editDetails()->page()->addComboBox(0, 3, 1, 1, "00", "02", "63", "System"); // dist
	editDetails()->page()->addComboBox(1, 0, 1, 1, "00", "02", "64", "System"); // classic
	editDetails()->page()->addComboBox(1, 1, 1, 1, "00", "02", "65", "System"); // modern
	editDetails()->page()->addComboBox(1, 2, 1, 1, "00", "02", "66", "System"); // metal
	editDetails()->page()->addComboBox(1, 3, 1, 1, "00", "02", "67", "System"); // fuzz
	//editDetails()->page()->addComboBox(1, 4, 1, 1, "00", "02", "68", "System"); // custom
  editDetails()->page()->addGroupBox(1, 0, 1, 1);
  editDetails()->page()->newGroupBox("PreAmp Variations");
  editDetails()->page()->addComboBox(0, 0, 1, 1, "00", "02", "70", "System"); // jc clean
	editDetails()->page()->addComboBox(0, 1, 1, 1, "00", "02", "71", "System"); // tw clean
	editDetails()->page()->addComboBox(0, 2, 1, 1, "00", "02", "72", "System"); // crunch
	editDetails()->page()->addComboBox(0, 3, 1, 1, "00", "02", "73", "System"); // vo combo
	editDetails()->page()->addComboBox(1, 0, 1, 1, "00", "02", "74", "System"); // match combo
	editDetails()->page()->addComboBox(1, 1, 1, 1, "00", "02", "75", "System"); // bg lead
	editDetails()->page()->addComboBox(1, 2, 1, 1, "00", "02", "76", "System"); // ms classic
	editDetails()->page()->addComboBox(1, 3, 1, 1, "00", "02", "77", "System"); // ms modern
	editDetails()->page()->addComboBox(2, 0, 1, 1, "00", "02", "78", "System"); // r fier
	editDetails()->page()->addComboBox(2, 1, 1, 1, "00", "02", "79", "System"); // t amp
	editDetails()->page()->addComboBox(2, 2, 1, 1, "00", "02", "7A", "System"); // hi gain
	editDetails()->page()->addComboBox(2, 3, 1, 1, "00", "02", "7B", "System"); // metal
  editDetails()->page()->addGroupBox(2, 0, 1, 1);
  editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->addPage("00", "00", "01", "05", "System"); 
  
  
  editDetails()->page()->addLabel(0, 0, 1, 3, "System PreAmp Common settings " + text);
  editDetails()->page()->newGroupBox("System PreAmp 1");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "00", "System", Qt::AlignCenter);   // off/on effect
	editDetails()->page()->newStackControl(0);
	editDetails()->page()->addComboBox(1, 0, 1, 1, "01", "00", "01", "System");   //mode
	editDetails()->page()->addStackControl();
	editDetails()->page()->insertStackField(0, 2, 0, 1, 1);
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	
  editDetails()->page()->newGroupBox("System PreAmp 2");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "01", "00", "System", Qt::AlignCenter);   // off/on effect
	editDetails()->page()->newStackControl(1);
	editDetails()->page()->addComboBox(1, 0, 1, 1, "01", "01", "01", "System");   //mode
	editDetails()->page()->addStackControl();
	editDetails()->page()->insertStackField(1, 2, 0, 1, 1);
	editDetails()->page()->addGroupBox(1, 1, 1, 1);
	
	editDetails()->page()->newGroupBox("System PreAmp 3");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "02", "00", "System", Qt::AlignCenter);   // off/on effect
	editDetails()->page()->newStackControl(2);
	editDetails()->page()->addComboBox(1, 0, 1, 1, "01", "02", "01", "System");   //mode
	editDetails()->page()->addStackControl();
	editDetails()->page()->insertStackField(2, 2, 0, 1, 1);
	editDetails()->page()->addGroupBox(1, 2, 1, 1);
	
	//#1 TYPE SETTINGS 
	editDetails()->page()->newStackField(0);
	editDetails()->page()->addComboBox(0, 0, 1, 1, "01", "00", "02", "System"); // channel select
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0, Qt::AlignCenter);
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "03", "System");
	editDetails()->page()->addStackField();

	editDetails()->page()->newStackField(0, Qt::AlignCenter);
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "03", "System");
	editDetails()->page()->addStackField();

	editDetails()->page()->newStackField(0, Qt::AlignCenter);
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "04", "System");
	editDetails()->page()->addStackField();
	
	//#2 TYPE SETTINGS 
	editDetails()->page()->newStackField(1);
	editDetails()->page()->addComboBox(0, 0, 1, 1, "01", "01", "02", "System"); // channel select
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(1, Qt::AlignCenter);
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "01", "03", "System");
	editDetails()->page()->addStackField();

	editDetails()->page()->newStackField(1, Qt::AlignCenter);
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "01", "03", "System");
	editDetails()->page()->addStackField();

	editDetails()->page()->newStackField(1, Qt::AlignCenter);
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "01", "04", "System");
	editDetails()->page()->addStackField();
	
	//#3 TYPE SETTINGS 
	editDetails()->page()->newStackField(2);
	editDetails()->page()->addComboBox(0, 0, 1, 1, "01", "02", "02", "System"); // channel select
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(2, Qt::AlignCenter);
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "02", "03", "System");
	editDetails()->page()->addStackField();

	editDetails()->page()->newStackField(2, Qt::AlignCenter);
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "02", "03", "System");
	editDetails()->page()->addStackField();

	editDetails()->page()->newStackField(2, Qt::AlignCenter);
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "02", "04", "System");
	editDetails()->page()->addStackField();
  
  editDetails()->addPage("00", "00", "01", "06", "System"); 
  
  
 /////////////////////////////////// preamp A #1 ///////////////////////////////////////////
  	
	//editDetails()->page()->newGroupBox("Channel A");
	editDetails()->page()->addLabel(0, 0, 1, 3, "System PreAmp " + text);
	editDetails()->page()->newGroupBox("Pre Amp 1 Channel A");
	editDetails()->page()->newStackControl(0);
	editDetails()->page()->addComboBox(0, 0, 1, 1, "01", "00", "10");        //pre type
	editDetails()->page()->addStackControl();
	editDetails()->page()->addComboBox(0, 1, 1, 1, "01", "00", "18", "System"); //gain sw
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "00", "11", "System");   // gain
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "00", "12", "System");            //bass
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "00", "13", "System");            // mid
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "00", "14", "System");            // treble
	editDetails()->page()->addKnob(0, 6, 1, 1, "01", "00", "15", "System");            // presence
	editDetails()->page()->addKnob(0, 7, 1, 1, "01", "00", "16", "System");            // effect level
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
 
  editDetails()->page()->insertStackField(0, 1, 0, 1, 1);                // bright button

	editDetails()->page()->newGroupBox("Speaker 1 Channel A");
	editDetails()->page()->newStackControl(1);
	editDetails()->page()->addComboBox(0, 0, 1, 1, "01", "00", "1B", "System");
	editDetails()->page()->addStackControl();
	editDetails()->page()->addComboBox(0, 1, 1, 1, "01", "00", "1C", "System");
	editDetails()->page()->addComboBox(0, 2, 1, 1, "01", "00", "1D", "System");
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "00", "1E", "System");
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "00", "1F", "System");
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "00", "20", "System");            // direct level
	editDetails()->page()->addGroupBox(2, 0, 1, 1);
	
	editDetails()->page()->newGroupBox("Solo");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "19", "System", Qt::AlignCenter);
	editDetails()->page()->addKnob(1, 0, 1, 1, "01", "00", "1A", "System");
	editDetails()->page()->addGroupBox(0, 1, 3, 1);	
	
	editDetails()->page()->insertStackField(1, 0, 2, 4, 1);
	
	//editDetails()->page()->addGroupBox(0, 1, 1, 1);
	

	// Bright Button stack fields
	editDetails()->page()->newStackField(0);  //ROLAND clean
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "17", "System", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0); // jc-120
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "17", "System", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0);  //jazz combo
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "17", "System", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0); // full range
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); //clean twin
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "17", "System", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // pro crunch
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "17", "System", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0); // tweed
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "17", "System", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0); //delux crunch
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0); //ROLAND crunch
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "17", "System", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0);  //blues
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "17", "System", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0); //wild crunch
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0); //stack crunch
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "17", "System", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); //VO drive
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0); //VO lead
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // VO clean
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0);  // match drive
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0);  //fat match
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0);  // match lead
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // bg lead
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "17", "System", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // bg drive
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "17", "System", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0);  // bg rhythm
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "17", "System", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0); // ms1959 I
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0); // ms1959 II
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // MS hi gain
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0);  // ms scoop
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // r-fier vint
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // r-fier mdn
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0);  // r-fier cln
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // t-amp lead
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // t-amp crunch
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // t-amp clean
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // ROLAND drive
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0);  //SLDN
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0);  // lead stack
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // heavy lead
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0);  // ROLAND metal
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // 5150 drive
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // metal lead
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // edge lead
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // custom
	editDetails()->page()->newGroupBox("Custom System PreAmp");
	editDetails()->page()->newStackControl(2);
	editDetails()->page()->addComboBox(0, 0, 1, 1, "01", "00", "21", "System");
	editDetails()->page()->addStackControl();
	editDetails()->page()->insertStackField(2, 0, 1, 1, 1);
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "00", "22", "System");
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "00", "23", "System");
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "00", "24", "System");
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "00", "25", "System");
	editDetails()->page()->addKnob(0, 6, 1, 1, "01", "00", "26", "System");
	editDetails()->page()->addKnob(0, 7, 1, 1, "01", "00", "27", "System");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // through
  editDetails()->page()->addStackField();
  
	
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);
  editDetails()->page()->newGroupBox("Custom System Speaker");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "2A", "System");
	editDetails()->page()->addKnob(1, 0, 1, 1, "01", "00", "29", "System");
	editDetails()->page()->addKnob(2, 0, 1, 2, "01", "00", "28", "System");
	editDetails()->page()->addComboBox(3, 0, 1, 1, "01", "00", "2B", "System");
	editDetails()->page()->addComboBox(4, 0, 1, 1, "01", "00", "2C", "System");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
  
  editDetails()->page()->newStackField(2);
  editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "17", "System", Qt::AlignCenter);
  editDetails()->page()->addStackField();
  editDetails()->page()->newStackField(2);
  editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "17", "System", Qt::AlignCenter);
  editDetails()->page()->addStackField();
  editDetails()->page()->newStackField(2);
  editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "17", "System", Qt::AlignCenter);
  editDetails()->page()->addStackField();
  editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
  editDetails()->page()->newStackField(2);
  editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "17", "System", Qt::AlignCenter);
  editDetails()->page()->addStackField();
  editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
  editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
  editDetails()->addPage("00", "00", "01", "07", "System"); 
  
  /////////////////////////////////////////////////// preamp B #1 //////////////////////////////////////////////
  //editDetails()->page()->newGroupBox("Channel B");
  editDetails()->page()->addLabel(0, 0, 1, 3, "System PreAmp " + text);
	editDetails()->page()->newGroupBox("Pre Amp 1 Channel B");
	editDetails()->page()->newStackControl(0); 
	editDetails()->page()->addComboBox(0, 0, 1, 1, "01", "00", "30", "System");  // pre type
	editDetails()->page()->addStackControl();
 	editDetails()->page()->addComboBox(0, 1, 1, 1, "01", "00", "38", "System"); // gain sw	
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "00", "31", "System");  //gain
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "00", "32", "System");            // bass
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "00", "33", "System");           // mid
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "00", "34", "System");           // treble
	editDetails()->page()->addKnob(0, 6, 1, 1, "01", "00", "35", "System");           //presence
	editDetails()->page()->addKnob(0, 7, 1, 1, "01", "00", "36", "System");          //effect level
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	
  editDetails()->page()->insertStackField(0, 1, 0, 1, 1);                 // bright switch
  	
	editDetails()->page()->newGroupBox("Speaker 1 Channel B");
	editDetails()->page()->newStackControl(1);
	editDetails()->page()->addComboBox(0, 0, 1, 1, "01", "00", "3B", "System");   // speaker type
	editDetails()->page()->addStackControl();
	editDetails()->page()->addComboBox(0, 1, 1, 1, "01", "00", "3C", "System");  // mic type
	editDetails()->page()->addComboBox(0, 2, 1, 1, "01", "00", "3D", "System");  // mic dis
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "00", "3E", "System");   // mic pos
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "00", "3F", "System");    // mic level
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "00", "40", "System");   // direct level
	editDetails()->page()->addGroupBox(2, 0, 1, 1);

	editDetails()->page()->newGroupBox("Solo");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "39", "System", Qt::AlignCenter);
	editDetails()->page()->addKnob(1, 0, 1, 1, "01", "00", "3A", "System");
	editDetails()->page()->addGroupBox(0, 1, 3, 1);
	
	
  editDetails()->page()->insertStackField(1, 0, 2, 4, 1);
    
  

	//editDetails()->page()->addGroupBox(0, 1, 1, 1);



	
  // Bright Button stack fields
	editDetails()->page()->newStackField(0);  //ROLAND clean
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "37", "System", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0); // jc-120
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "37", "System", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0);  //jazz combo
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "37", "System", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0); // full range
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); //clean twin
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "37", "System", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // pro crunch
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "37", "System", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0); // tweed
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "37", "System", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0); //delux crunch
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0); //ROLAND crunch
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "37", "System", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0);  //blues
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "37", "System", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0); //wild crunch
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0); //stack crunch
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "37", "System", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); //VO drive
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0); //VO lead
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // VO clean
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0);  // match drive
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0);  //fat match
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0);  // match lead
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // bg lead
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "37", "System", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // bg drive
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "37", "System", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0);  // bg rhythm
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "37", "System", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0); // ms1959 I
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0); // ms1959 II
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // MS hi gain
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0);  // ms scoop
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // r-fier vint
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // r-fier mdn
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0);  // r-fier cln
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // t-amp lead
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // t-amp crunch
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // t-amp clean
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // ROLAND drive
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0);  //SLDN
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0);  // lead stack
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // heavy lead
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0);  // ROLAND metal
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // 5150 drive
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // metal lead
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // edge lead
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // custom
	editDetails()->page()->newGroupBox("Custom System PreAmp");
	editDetails()->page()->newStackControl(2);
	editDetails()->page()->addComboBox(0, 0, 1, 1, "01", "00", "41", "System");
	editDetails()->page()->addStackControl();
	editDetails()->page()->insertStackField(2, 0, 1, 1, 1);
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "00", "42", "System");
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "00", "43", "System");
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "00", "44", "System");
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "00", "45", "System");
	editDetails()->page()->addKnob(0, 6, 1, 1, "01", "00", "46", "System");
	editDetails()->page()->addKnob(0, 7, 1, 1, "01", "00", "47", "System");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // through
  editDetails()->page()->addStackField();
  

	
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);
  editDetails()->page()->newGroupBox("Custom System Speaker");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "4A", "System");
	editDetails()->page()->addKnob(1, 0, 1, 1, "01", "00", "49", "System");
	editDetails()->page()->addKnob(2, 0, 1, 2, "01", "00", "48", "System");
	editDetails()->page()->addComboBox(3, 0, 1, 1, "01", "00", "4B", "System");
	editDetails()->page()->addComboBox(4, 0, 1, 1, "01", "00", "4C", "System");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();

  editDetails()->page()->newStackField(2);
  editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "37", "System", Qt::AlignCenter);
  editDetails()->page()->addStackField();
  editDetails()->page()->newStackField(2);
  editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "37", "System", Qt::AlignCenter);
  editDetails()->page()->addStackField();
  editDetails()->page()->newStackField(2);
  editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "37", "System", Qt::AlignCenter);
  editDetails()->page()->addStackField();
  editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
  editDetails()->page()->newStackField(2);
  editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "37", "System", Qt::AlignCenter);
  editDetails()->page()->addStackField();
  editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
  editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
  editDetails()->addPage("00", "00", "01", "08", "System"); 
  
  /////////////////////////////////// preamp A #2 ///////////////////////////////////////////
  	
	//editDetails()->page()->newGroupBox("Channel A");
	editDetails()->page()->addLabel(0, 0, 1, 3, "System PreAmp " + text);
	editDetails()->page()->newGroupBox("Pre Amp 2 Channel A");
	editDetails()->page()->newStackControl(0);
	editDetails()->page()->addComboBox(0, 0, 1, 1, "01", "01", "10", "System");        //pre type
	editDetails()->page()->addStackControl();
	editDetails()->page()->addComboBox(0, 1, 1, 1, "01", "01", "18", "System"); //gain sw
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "01", "11", "System");   // gain
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "01", "12", "System");            //bass
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "01", "13", "System");            // mid
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "01", "14", "System");            // treble
	editDetails()->page()->addKnob(0, 6, 1, 1, "01", "01", "15", "System");            // presence
	editDetails()->page()->addKnob(0, 7, 1, 1, "01", "01", "16", "System");            // effect level
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
 
  editDetails()->page()->insertStackField(0, 1, 0, 1, 1);                // bright button

	editDetails()->page()->newGroupBox("Speaker 2 Channel A");
	editDetails()->page()->newStackControl(1);
	editDetails()->page()->addComboBox(0, 0, 1, 1, "01", "01", "1B", "System");
	editDetails()->page()->addStackControl();
	editDetails()->page()->addComboBox(0, 1, 1, 1, "01", "01", "1C", "System");
	editDetails()->page()->addComboBox(0, 2, 1, 1, "01", "01", "1D", "System");
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "01", "1E", "System");
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "01", "1F", "System");
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "01", "20", "System");            // direct level
	editDetails()->page()->addGroupBox(2, 0, 1, 1);
	
	editDetails()->page()->newGroupBox("Solo");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "01", "19", "System", Qt::AlignCenter);
	editDetails()->page()->addKnob(1, 0, 1, 1, "01", "01", "1A", "System");
	editDetails()->page()->addGroupBox(0, 1, 3, 1);	
	
	editDetails()->page()->insertStackField(1, 0, 2, 4, 1);
	
	//editDetails()->page()->addGroupBox(0, 1, 1, 1);
	

	// Bright Button stack fields
	editDetails()->page()->newStackField(0);  //ROLAND clean
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "01", "17", "System", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0); // jc-120
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "01", "17", "System", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0);  //jazz combo
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "01", "17", "System", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0); // full range
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); //clean twin
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "01", "17", "System", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // pro crunch
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "01", "17", "System", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0); // tweed
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "01", "17", "System", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0); //delux crunch
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0); //ROLAND crunch
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "01", "17", "System", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0);  //blues
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "01", "17", "System", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0); //wild crunch
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0); //stack crunch
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "01", "17", "System", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); //VO drive
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0); //VO lead
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // VO clean
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0);  // match drive
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0);  //fat match
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0);  // match lead
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // bg lead
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "01", "17", "System", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // bg drive
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "01", "17", "System", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0);  // bg rhythm
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "01", "17", "System", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0); // ms1959 I
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0); // ms1959 II
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // MS hi gain
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0);  // ms scoop
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // r-fier vint
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // r-fier mdn
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0);  // r-fier cln
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // t-amp lead
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // t-amp crunch
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // t-amp clean
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // ROLAND drive
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0);  //SLDN
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0);  // lead stack
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // heavy lead
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0);  // ROLAND metal
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // 5150 drive
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // metal lead
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // edge lead
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // custom
	editDetails()->page()->newGroupBox("Custom System PreAmp");
	editDetails()->page()->newStackControl(2);
	editDetails()->page()->addComboBox(0, 0, 1, 1, "01", "01", "21", "System");
	editDetails()->page()->addStackControl();
	editDetails()->page()->insertStackField(2, 0, 1, 1, 1);
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "01", "22", "System");
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "01", "23", "System");
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "01", "24", "System");
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "01", "25", "System");
	editDetails()->page()->addKnob(0, 6, 1, 1, "01", "01", "26", "System");
	editDetails()->page()->addKnob(0, 7, 1, 1, "01", "01", "27", "System");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // through
  editDetails()->page()->addStackField();
  
	
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);
  editDetails()->page()->newGroupBox("Custom System Speaker");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "01", "2A", "System");
	editDetails()->page()->addKnob(1, 0, 1, 1, "01", "01", "29", "System");
	editDetails()->page()->addKnob(2, 0, 1, 2, "01", "01", "28", "System");
	editDetails()->page()->addComboBox(3, 0, 1, 1, "01", "01", "2B", "System");
	editDetails()->page()->addComboBox(4, 0, 1, 1, "01", "01", "2C", "System");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
  
  editDetails()->page()->newStackField(2);
  editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "01", "17", "System", Qt::AlignCenter);
  editDetails()->page()->addStackField();
  editDetails()->page()->newStackField(2);
  editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "01", "17", "System", Qt::AlignCenter);
  editDetails()->page()->addStackField();
  editDetails()->page()->newStackField(2);
  editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "01", "17", "System", Qt::AlignCenter);
  editDetails()->page()->addStackField();
  editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
  editDetails()->page()->newStackField(2);
  editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "01", "17", "System", Qt::AlignCenter);
  editDetails()->page()->addStackField();
  editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
  editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();  
  editDetails()->addPage("00", "00", "01", "09", "System"); 
  
  
  /////////////////////////////////////////////////// preamp B #2 //////////////////////////////////////////////
  //editDetails()->page()->newGroupBox("Channel B");
  editDetails()->page()->addLabel(0, 0, 1, 3, "System PreAmp " + text);
	editDetails()->page()->newGroupBox("Pre Amp 2 Channel B");
	editDetails()->page()->newStackControl(0); 
	editDetails()->page()->addComboBox(0, 0, 1, 1, "01", "01", "30", "System");  // pre type
	editDetails()->page()->addStackControl();
 	editDetails()->page()->addComboBox(0, 1, 1, 1, "01", "01", "38", "System"); // gain sw	
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "01", "31", "System");  //gain
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "01", "32", "System");            // bass
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "01", "33", "System");           // mid
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "01", "34", "System");           // treble
	editDetails()->page()->addKnob(0, 6, 1, 1, "01", "01", "35", "System");           //presence
	editDetails()->page()->addKnob(0, 7, 1, 1, "01", "01", "36", "System");          //effect level
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	
  editDetails()->page()->insertStackField(0, 1, 0, 1, 1);                 // bright switch
  	
	editDetails()->page()->newGroupBox("Speaker 2 Channel B");
	editDetails()->page()->newStackControl(1);
	editDetails()->page()->addComboBox(0, 0, 1, 1, "01", "01", "3B", "System");   // speaker type
	editDetails()->page()->addStackControl();
	editDetails()->page()->addComboBox(0, 1, 1, 1, "01", "01", "3C", "System");  // mic type
	editDetails()->page()->addComboBox(0, 2, 1, 1, "01", "01", "3D", "System");  // mic dis
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "01", "3E", "System");   // mic pos
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "01", "3F", "System");    // mic level
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "01", "40", "System");   // direct level
	editDetails()->page()->addGroupBox(2, 0, 1, 1);

	editDetails()->page()->newGroupBox("Solo");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "01", "39", "System", Qt::AlignCenter);
	editDetails()->page()->addKnob(1, 0, 1, 1, "01", "01", "3A", "System");
	editDetails()->page()->addGroupBox(0, 1, 3, 1);
	
	
  editDetails()->page()->insertStackField(1, 0, 2, 4, 1);
    
  

	//editDetails()->page()->addGroupBox(0, 1, 1, 1);



	
  // Bright Button stack fields
	editDetails()->page()->newStackField(0);  //ROLAND clean
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "01", "37", "System", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0); // jc-120
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "01", "37", "System", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0);  //jazz combo
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "01", "37", "System", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0); // full range
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); //clean twin
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "01", "37", "System", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // pro crunch
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "01", "37", "System", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0); // tweed
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "01", "37", "System", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0); //delux crunch
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0); //ROLAND crunch
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "01", "37", "System", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0);  //blues
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "01", "37", "System", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0); //wild crunch
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0); //stack crunch
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "01", "37", "System", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); //VO drive
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0); //VO lead
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // VO clean
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0);  // match drive
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0);  //fat match
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0);  // match lead
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // bg lead
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "01", "37", "System", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // bg drive
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "01", "37", "System", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0);  // bg rhythm
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "01", "37", "System", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0); // ms1959 I
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0); // ms1959 II
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // MS hi gain
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0);  // ms scoop
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // r-fier vint
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // r-fier mdn
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0);  // r-fier cln
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // t-amp lead
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // t-amp crunch
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // t-amp clean
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // ROLAND drive
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0);  //SLDN
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0);  // lead stack
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // heavy lead
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0);  // ROLAND metal
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // 5150 drive
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // metal lead
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // edge lead
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // custom
	editDetails()->page()->newGroupBox("Custom System PreAmp");
	editDetails()->page()->newStackControl(2);
	editDetails()->page()->addComboBox(0, 0, 1, 1, "01", "01", "41", "System");
	editDetails()->page()->addStackControl();
	editDetails()->page()->insertStackField(2, 0, 1, 1, 1);
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "01", "42", "System");
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "01", "43", "System");
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "01", "44", "System");
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "01", "45", "System");
	editDetails()->page()->addKnob(0, 6, 1, 1, "01", "01", "46", "System");
	editDetails()->page()->addKnob(0, 7, 1, 1, "01", "01", "47", "System");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // through
  editDetails()->page()->addStackField();
  

	
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);
  editDetails()->page()->newGroupBox("Custom System Speaker");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "01", "4A", "System");
	editDetails()->page()->addKnob(1, 0, 1, 1, "01", "01", "49", "System");
	editDetails()->page()->addKnob(2, 0, 1, 2, "01", "01", "48", "System");
	editDetails()->page()->addComboBox(3, 0, 1, 1, "01", "01", "4B", "System");
	editDetails()->page()->addComboBox(4, 0, 1, 1, "01", "01", "4C", "System");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();

  editDetails()->page()->newStackField(2);
  editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "01", "37", "System", Qt::AlignCenter);
  editDetails()->page()->addStackField();
  editDetails()->page()->newStackField(2);
  editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "01", "37", "System", Qt::AlignCenter);
  editDetails()->page()->addStackField();
  editDetails()->page()->newStackField(2);
  editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "01", "37", "System", Qt::AlignCenter);
  editDetails()->page()->addStackField();
  editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
  editDetails()->page()->newStackField(2);
  editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "01", "37", "System", Qt::AlignCenter);
  editDetails()->page()->addStackField();
  editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
  editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
  editDetails()->addPage("00", "00", "01", "0A", "System"); 
  
 /////////////////////////////////// preamp A #3 ///////////////////////////////////////////
  	
	//editDetails()->page()->newGroupBox("Channel A");
	editDetails()->page()->addLabel(0, 0, 1, 3, "System PreAmp " + text);
	editDetails()->page()->newGroupBox("Pre Amp 3 Channel A");
	editDetails()->page()->newStackControl(0);
	editDetails()->page()->addComboBox(0, 0, 1, 1, "01", "02", "10", "System");        //pre type
	editDetails()->page()->addStackControl();
	editDetails()->page()->addComboBox(0, 1, 1, 1, "01", "02", "18", "System"); //gain sw
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "02", "11", "System");   // gain
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "02", "12", "System");            //bass
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "02", "13", "System");            // mid
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "02", "14", "System");            // treble
	editDetails()->page()->addKnob(0, 6, 1, 1, "01", "02", "15", "System");            // presence
	editDetails()->page()->addKnob(0, 7, 1, 1, "01", "02", "16", "System");            // effect level
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
 
  editDetails()->page()->insertStackField(0, 1, 0, 1, 1);                // bright button

	editDetails()->page()->newGroupBox("Speaker 3 Channel A");
	editDetails()->page()->newStackControl(1);
	editDetails()->page()->addComboBox(0, 0, 1, 1, "01", "02", "1B", "System");
	editDetails()->page()->addStackControl();
	editDetails()->page()->addComboBox(0, 1, 1, 1, "01", "02", "1C", "System");
	editDetails()->page()->addComboBox(0, 2, 1, 1, "01", "02", "1D", "System");
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "02", "1E", "System");
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "02", "1F", "System");
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "02", "20", "System");            // direct level
	editDetails()->page()->addGroupBox(2, 0, 1, 1);
	
	editDetails()->page()->newGroupBox("Solo");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "02", "19", "System", Qt::AlignCenter);
	editDetails()->page()->addKnob(1, 0, 1, 1, "01", "02", "1A", "System");
	editDetails()->page()->addGroupBox(0, 1, 3, 1);	
	
	editDetails()->page()->insertStackField(1, 0, 2, 4, 1);
	
	//editDetails()->page()->addGroupBox(0, 1, 1, 1);
	

	// Bright Button stack fields
	editDetails()->page()->newStackField(0);  //ROLAND clean
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "02", "17", "System", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0); // jc-120
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "02", "17", "System", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0);  //jazz combo
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "02", "17", "System", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0); // full range
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); //clean twin
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "02", "17", "System", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // pro crunch
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "02", "17", "System", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0); // tweed
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "02", "17", "System", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0); //delux crunch
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0); //ROLAND crunch
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "02", "17", "System", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0);  //blues
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "02", "17", "System", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0); //wild crunch
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0); //stack crunch
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "02", "17", "System", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); //VO drive
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0); //VO lead
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // VO clean
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0);  // match drive
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0);  //fat match
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0);  // match lead
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // bg lead
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "02", "17", "System", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // bg drive
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "02", "17", "System", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0);  // bg rhythm
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "02", "17", "System", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0); // ms1959 I
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0); // ms1959 II
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // MS hi gain
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0);  // ms scoop
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // r-fier vint
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // r-fier mdn
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0);  // r-fier cln
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // t-amp lead
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // t-amp crunch
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // t-amp clean
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // ROLAND drive
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0);  //SLDN
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0);  // lead stack
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // heavy lead
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0);  // ROLAND metal
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // 5150 drive
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // metal lead
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // edge lead
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // custom
	editDetails()->page()->newGroupBox("Custom System PreAmp");
	editDetails()->page()->newStackControl(2);
	editDetails()->page()->addComboBox(0, 0, 1, 1, "01", "02", "21", "System");
	editDetails()->page()->addStackControl();
	editDetails()->page()->insertStackField(2, 0, 1, 1, 1);
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "02", "22", "System");
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "02", "23", "System");
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "02", "24", "System");
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "02", "25", "System");
	editDetails()->page()->addKnob(0, 6, 1, 1, "01", "02", "26", "System");
	editDetails()->page()->addKnob(0, 7, 1, 1, "01", "02", "27", "System");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // through
  editDetails()->page()->addStackField();
  
	
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);
  editDetails()->page()->newGroupBox("Custom System Speaker");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "02", "2A", "System");
	editDetails()->page()->addKnob(1, 0, 1, 1, "01", "02", "29", "System");
	editDetails()->page()->addKnob(2, 0, 1, 2, "01", "02", "28", "System");
	editDetails()->page()->addComboBox(3, 0, 1, 1, "01", "02", "2B", "System");
	editDetails()->page()->addComboBox(4, 0, 1, 1, "01", "02", "2C", "System");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
  
  editDetails()->page()->newStackField(2);
  editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "02", "17", "System", Qt::AlignCenter);
  editDetails()->page()->addStackField();
  editDetails()->page()->newStackField(2);
  editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "02", "17", "System", Qt::AlignCenter);
  editDetails()->page()->addStackField();
  editDetails()->page()->newStackField(2);
  editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "02", "17", "System", Qt::AlignCenter);
  editDetails()->page()->addStackField();
  editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
  editDetails()->page()->newStackField(2);
  editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "02", "17", "System", Qt::AlignCenter);
  editDetails()->page()->addStackField();
  editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
  editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
  editDetails()->addPage("00", "00", "01", "0B", "System"); 
  
  /////////////////////////////////////////////////// preamp B #3 //////////////////////////////////////////////
  //editDetails()->page()->newGroupBox("Channel B");
  editDetails()->page()->addLabel(0, 0, 1, 3, "System PreAmp " + text);
	editDetails()->page()->newGroupBox("Pre Amp 3 Channel B");
	editDetails()->page()->newStackControl(0); 
	editDetails()->page()->addComboBox(0, 0, 1, 1, "01", "02", "30", "System");  // pre type
	editDetails()->page()->addStackControl();
 	editDetails()->page()->addComboBox(0, 1, 1, 1, "01", "02", "38", "System"); // gain sw	
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "02", "31", "System");  //gain
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "02", "32", "System");            // bass
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "02", "33", "System");           // mid
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "02", "34", "System");           // treble
	editDetails()->page()->addKnob(0, 6, 1, 1, "01", "02", "35", "System");           //presence
	editDetails()->page()->addKnob(0, 7, 1, 1, "01", "02", "36", "System");          //effect level
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	
  editDetails()->page()->insertStackField(0, 1, 0, 1, 1);                 // bright switch
  	
	editDetails()->page()->newGroupBox("Speaker 3 Channel B");
	editDetails()->page()->newStackControl(1);
	editDetails()->page()->addComboBox(0, 0, 1, 1, "01", "02", "3B", "System");   // speaker type
	editDetails()->page()->addStackControl();
	editDetails()->page()->addComboBox(0, 1, 1, 1, "01", "02", "3C", "System");  // mic type
	editDetails()->page()->addComboBox(0, 2, 1, 1, "01", "02", "3D", "System");  // mic dis
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "02", "3E", "System");   // mic pos
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "02", "3F", "System");    // mic level
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "02", "40", "System");   // direct level
	editDetails()->page()->addGroupBox(2, 0, 1, 1);

	editDetails()->page()->newGroupBox("Solo");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "02", "39", "System", Qt::AlignCenter);
	editDetails()->page()->addKnob(1, 0, 1, 1, "01", "02", "3A", "System");
	editDetails()->page()->addGroupBox(0, 1, 3, 1);
	
	
  editDetails()->page()->insertStackField(1, 0, 2, 4, 1);
    
  

	//editDetails()->page()->addGroupBox(0, 1, 1, 1);



	
  // Bright Button stack fields
	editDetails()->page()->newStackField(0);  //ROLAND clean
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "02", "37", "System", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0); // jc-120
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "02", "37", "System", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0);  //jazz combo
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "02", "37", "System", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0); // full range
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); //clean twin
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "02", "37", "System", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // pro crunch
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "02", "37", "System", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0); // tweed
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "02", "37", "System", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0); //delux crunch
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0); //ROLAND crunch
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "02", "37", "System", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0);  //blues
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "02", "37", "System", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0); //wild crunch
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0); //stack crunch
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "02", "37", "System", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); //VO drive
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0); //VO lead
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // VO clean
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0);  // match drive
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0);  //fat match
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0);  // match lead
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // bg lead
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "02", "37", "System", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // bg drive
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "02", "37", "System", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0);  // bg rhythm
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "02", "37", "System", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0); // ms1959 I
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0); // ms1959 II
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // MS hi gain
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0);  // ms scoop
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // r-fier vint
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // r-fier mdn
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0);  // r-fier cln
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // t-amp lead
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // t-amp crunch
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // t-amp clean
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // ROLAND drive
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0);  //SLDN
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0);  // lead stack
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // heavy lead
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0);  // ROLAND metal
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // 5150 drive
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // metal lead
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // edge lead
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // custom
	editDetails()->page()->newGroupBox("Custom System PreAmp");
	editDetails()->page()->newStackControl(2);
	editDetails()->page()->addComboBox(0, 0, 1, 1, "01", "02", "41", "System");
	editDetails()->page()->addStackControl();
	editDetails()->page()->insertStackField(2, 0, 1, 1, 1);
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "02", "42", "System");
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "02", "43", "System");
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "02", "44", "System");
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "02", "45", "System");
	editDetails()->page()->addKnob(0, 6, 1, 1, "01", "02", "46", "System");
	editDetails()->page()->addKnob(0, 7, 1, 1, "01", "02", "47", "System");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // through
  editDetails()->page()->addStackField();
  

	
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);
  editDetails()->page()->newGroupBox("Custom System Speaker");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "02", "4A", "System");
	editDetails()->page()->addKnob(1, 0, 1, 1, "01", "02", "49", "System");
	editDetails()->page()->addKnob(2, 0, 1, 2, "01", "02", "48", "System");
	editDetails()->page()->addComboBox(3, 0, 1, 1, "01", "02", "4B", "System");
	editDetails()->page()->addComboBox(4, 0, 1, 1, "01", "02", "4C", "System");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();

  editDetails()->page()->newStackField(2);
  editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "02", "37", "System", Qt::AlignCenter);
  editDetails()->page()->addStackField();
  editDetails()->page()->newStackField(2);
  editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "02", "37", "System", Qt::AlignCenter);
  editDetails()->page()->addStackField();
  editDetails()->page()->newStackField(2);
  editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "02", "37", "System", Qt::AlignCenter);
  editDetails()->page()->addStackField();
  editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
  editDetails()->page()->newStackField(2);
  editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "02", "37", "System", Qt::AlignCenter);
  editDetails()->page()->addStackField();
  editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
  editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
  editDetails()->addPage("00", "00", "01", "0C", "System"); 
  */
  
	//editDetails()->addPage();
              
};
