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

#include "soundsource_synth_a.h"

soundsource_synth_a::soundsource_synth_a(QWidget *parent)
    : soundSource(parent)
{
	/* CHANNEL_A */
	setImage(":/images/ch_a.png");
        setLSB("00", "00");
        setSwitch("00", "00", "12");
        setComboBox("00", "routeSwitch", "20");
        setKnob1("20", "00", "02");

        setKnob2("20", "00", "00");
        //editDetails()->patchPos(336, 58, "01", "10");
	setEditPages();
};

void soundsource_synth_a::updateSignal()
{
        updateSwitch("00", "00", "12");
        updateComboBox("00", "routeSwitch", "20");
        updateKnob1("20", "00", "02");

        updateKnob2("20", "00", "00");
};

void soundsource_synth_a::setEditPages()
{
        editDetails()->page()->newGroupBox("Effect");
        editDetails()->page()->addSwitch(0, 0, 1, 1, "00", "00", "12");   // off/on effect
        editDetails()->page()->addGroupBox(0, 0, 1, 1);

	// CHANNEL A 
	
	
	editDetails()->page()->newGroupBox(tr("Channel A"));

        /*editDetails()->page()->newGroupBox(tr("Pre Amp"));
        editDetails()->page()->newStackControl(0);*/
        editDetails()->page()->addComboBox(0, 0, 1, 1, "00", "00", "20");        //pre type
        //editDetails()->page()->addStackControl();
        //editDetails()->page()->addComboBox(0, 1, 1, 1, "01", "00", "18", "bottom", Qt::AlignLeft); //gain sw
        editDetails()->page()->addKnob(0, 2, 1, 1, "20", "00", "02", "normal","right", 120);   // gain
        editDetails()->page()->addKnob(0, 3, 1, 1, "20", "00", "00");            //bass
        /*editDetails()->page()->addKnob(0, 4, 1, 1, "01", "00", "13");            // mid
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "00", "14");            // treble
	editDetails()->page()->addKnob(0, 6, 1, 1, "01", "00", "15");            // presence
        editDetails()->page()->addKnob(0, 7, 1, 1, "01", "00", "16");            // effect level*/
        editDetails()->page()->addGroupBox(0, 1, 1, 1);
 
/*  editDetails()->page()->insertStackField(0, 1, 0, 1, 1);                // bright button

	editDetails()->page()->newGroupBox(tr("Speaker"));
	editDetails()->page()->newStackControl(1);
	editDetails()->page()->addComboBox(0, 0, 1, 1, "01", "00", "1B");
	editDetails()->page()->addStackControl();
	editDetails()->page()->addComboBox(0, 1, 1, 1, "01", "00", "1C", "bottom", Qt::AlignRight);
	editDetails()->page()->addComboBox(0, 2, 1, 1, "01", "00", "1D");
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "00", "1E");
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "00", "1F");
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "00", "20");            // direct level
	editDetails()->page()->addGroupBox(2, 0, 1, 1);
	
	editDetails()->page()->newGroupBox(tr("Solo"));
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "19", "middle", Qt::AlignLeft | Qt::AlignTop);
	editDetails()->page()->addKnob(1, 0, 1, 1, "01", "00", "1A");
	editDetails()->page()->addGroupBox(0, 1, 3, 1);	
	
	editDetails()->page()->insertStackField(1, 0, 2, 4, 1);
	
	editDetails()->page()->addGroupBox(0, 1, 1, 1);
	
	
	

	// Bright Button stack fields
	editDetails()->page()->newStackField(0);  //ROLAND clean
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "17", "middle", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0); // jc-120
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "17", "middle", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0);  //jazz combo
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "17", "middle", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0); // full range
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); //clean twin
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "17", "middle", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // pro crunch
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "17", "middle", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0); // tweed
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "17", "middle", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0); //delux crunch
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0); //ROLAND crunch
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "17", "middle", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0);  //blues
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "17", "middle", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0); //wild crunch
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0); //stack crunch
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "17", "middle", Qt::AlignCenter);
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
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "17", "middle", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // bg drive
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "17", "middle", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0);  // bg rhythm
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "17", "middle", Qt::AlignCenter);
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
	editDetails()->page()->newGroupBox(tr("Custom PreAmp"));
	editDetails()->page()->newStackControl(2);
	editDetails()->page()->addComboBox(0, 0, 1, 1, "01", "00", "21");
	editDetails()->page()->addStackControl();
	editDetails()->page()->insertStackField(2, 0, 1, 1, 1);
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "00", "22");
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "00", "23");
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "00", "24");
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "00", "25");
	editDetails()->page()->addKnob(0, 6, 1, 1, "01", "00", "26");
	editDetails()->page()->addKnob(0, 7, 1, 1, "01", "00", "27");
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
  editDetails()->page()->newGroupBox(tr("Custom Speaker"));
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "2A", "normal","right", 40);
	editDetails()->page()->addKnob(1, 0, 1, 1, "01", "00", "29", "normal","right", 40);
	editDetails()->page()->addKnob(2, 0, 1, 2, "01", "00", "28", "normal","right", 40);
	editDetails()->page()->addComboBox(3, 0, 1, 1, "01", "00", "2B", "bottom", Qt::AlignHCenter);
	editDetails()->page()->addComboBox(4, 0, 1, 1, "01", "00", "2C", "bottom", Qt::AlignHCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
  
  editDetails()->page()->newStackField(2);
  editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "17", "middle", Qt::AlignCenter);
  editDetails()->page()->addStackField();
  editDetails()->page()->newStackField(2);
  editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "17", "middle", Qt::AlignCenter);
  editDetails()->page()->addStackField();
  editDetails()->page()->newStackField(2);
  editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "17", "middle", Qt::AlignCenter);
  editDetails()->page()->addStackField();
  editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
  editDetails()->page()->newStackField(2);
  editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "17", "middle", Qt::AlignCenter);
  editDetails()->page()->addStackField();
  editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
  editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
  */

	editDetails()->addPage();	
};
