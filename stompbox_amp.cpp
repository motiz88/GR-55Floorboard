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

#include "stompbox_amp.h"

stompbox_amp::stompbox_amp(QWidget *parent)
    : stompBox(parent)
{
    /* AMP */
    setImage(":/images/amp.png");
    setLSB("07", "00");
    setKnob1("07", "00", "02");
    setKnob2("07", "00", "03");
    setComboBox("07", "00", "01");
    setSwitch("07", "00", "00");
    editDetails()->patchPos(1480, 34, "07", "00");  //correct
    setEditPages();
};

void stompbox_amp::updateSignal()
{
    updateKnob1("07", "00", "02");
    updateKnob2("07", "00", "03");
    updateComboBox("07", "00", "01");
    updateSwitch("07", "00", "00");
};

void stompbox_amp::setEditPages()
{
    editDetails()->page()->newGroupBox("Effect");
    editDetails()->page()->addSwitch(0, 0, 1, 1, "07", "00", "00");   // off/on effect
    editDetails()->page()->addGroupBox(0, 0, 2, 1);

    //AMP


    //editDetails()->page()->newGroupBox(tr("Amp/Spkr"));

    editDetails()->page()->newGroupBox(tr("PreAmp"));
    editDetails()->page()->newStackControl(0);
    editDetails()->page()->addComboBox(0, 0, 1, 1, "07", "00", "01", "large");        //pre type
    editDetails()->page()->addStackControl();
    editDetails()->page()->addComboBox(0, 1, 1, 1, "07", "00", "04", "bottom", Qt::AlignLeft); //gain sw
    editDetails()->page()->addKnob(0, 2, 1, 1, "07", "00", "02", "turbo");   // gain
    editDetails()->page()->addKnob(0, 3, 1, 1, "07", "00", "07");            //bass
    editDetails()->page()->addKnob(0, 4, 1, 1, "07", "00", "08");            // mid
    editDetails()->page()->addKnob(0, 5, 1, 1, "07", "00", "09");            // treble
    editDetails()->page()->addKnob(0, 6, 1, 1, "07", "00", "0A");            // presence
    editDetails()->page()->addKnob(0, 7, 1, 1, "07", "00", "03");            // effect level
    editDetails()->page()->insertStackField(0, 0, 8, 1, 1);                 // bright button
    editDetails()->page()->addGroupBox(0, 1, 1, 1);



    editDetails()->page()->newGroupBox(tr("Speaker"));
    editDetails()->page()->addComboBox(0, 0, 1, 1, "07", "00", "0C", "large");       //spkr type
    editDetails()->page()->addComboBox(0, 1, 1, 1, "07", "00", "0D", "bottom", Qt::AlignRight); //mic type
    editDetails()->page()->addComboBox(0, 2, 1, 1, "07", "00", "0E");       //mic distance
    editDetails()->page()->addKnob(0, 3, 1, 1, "07", "00", "0F");           //mic position
    editDetails()->page()->addKnob(0, 4, 1, 1, "07", "00", "10");           // mic level
    editDetails()->page()->addGroupBox(1, 1, 1, 1);

    editDetails()->page()->newGroupBox(tr("Solo"));
    editDetails()->page()->addSwitch(0, 0, 1, 1, "07", "00", "05", "middle", Qt::AlignLeft | Qt::AlignTop);  //solo sw
    editDetails()->page()->addKnob(1, 0, 1, 1, "07", "00", "06");           // solo level
    editDetails()->page()->addGroupBox(0, 2, 2, 1);

    //editDetails()->page()->addGroupBox(0, 1, 1, 1);




    // Bright Button stack fields
    editDetails()->page()->newStackField(0);  //Boss clean
    editDetails()->page()->addSwitch(0, 0, 1, 1, "07", "00", "0B", "middle", Qt::AlignCenter);
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(0); // jc-120
    editDetails()->page()->addSwitch(0, 0, 1, 1, "07", "00", "0B", "middle", Qt::AlignCenter);
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(0);  //jazz combo
    editDetails()->page()->addSwitch(0, 0, 1, 1, "07", "00", "0B", "middle", Qt::AlignCenter);
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(0); // full range
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(0); //clean twin
    editDetails()->page()->addSwitch(0, 0, 1, 1, "07", "00", "0B", "middle", Qt::AlignCenter);
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(0); // pro crunch
    editDetails()->page()->addSwitch(0, 0, 1, 1, "07", "00", "0B", "middle", Qt::AlignCenter);
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(0); // tweed
    editDetails()->page()->addSwitch(0, 0, 1, 1, "07", "00", "0B", "middle", Qt::AlignCenter);
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(0); //delux crunch
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(0); //Boss crunch
    editDetails()->page()->addSwitch(0, 0, 1, 1, "07", "00", "0B", "middle", Qt::AlignCenter);
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(0);  //blues
    editDetails()->page()->addSwitch(0, 0, 1, 1, "07", "00", "0B", "middle", Qt::AlignCenter);
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(0); //wild crunch
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(0); //stack crunch
    editDetails()->page()->addSwitch(0, 0, 1, 1, "07", "00", "0B", "middle", Qt::AlignCenter);
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
    editDetails()->page()->addSwitch(0, 0, 1, 1, "07", "00", "0B", "middle", Qt::AlignCenter);
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(0); // bg drive
    editDetails()->page()->addSwitch(0, 0, 1, 1, "07", "00", "0B", "middle", Qt::AlignCenter);
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(0);  // bg rhythm
    editDetails()->page()->addSwitch(0, 0, 1, 1, "07", "00", "0B", "middle", Qt::AlignCenter);
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

    editDetails()->page()->newStackField(0); // Boss drive
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(0);  //SLDN
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(0);  // lead stack
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(0); // heavy lead
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(0);  // Boss metal
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(0); // 5150 drive
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(0); // metal lead
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(0); // edge lead
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(0); // Bass Clean
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(0); // Bass Crunch
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(0); // Bass HiGain
    editDetails()->page()->addStackField();



    editDetails()->addPage();
};
