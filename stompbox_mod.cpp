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

#include "stompbox_mod.h"

stompbox_mod::stompbox_mod(QWidget *parent)
    : stompBox(parent)
{
    /* MOD */
    setImage(":/images/mod.png");
    setLSB("07", "15");
    setComboBox("07", "00", "16");
    setKnob1("07", "CENTER", "17");
    setSwitch("07", "00", "15");
    editDetails()->patchPos(1522, 138, "07", "15"); //correct
    setEditPages();
};

void stompbox_mod::updateSignal()
{
    updateComboBox("07", "00", "16");
    updateKnob1("07", "00", "17");
    updateSwitch("07", "00", "15");
};

void stompbox_mod::setEditPages()
{
    editDetails()->page()->newGroupBox("MOD");
    editDetails()->page()->addSwitch(0, 0, 1, 1, "07", "00", "15", "middle", Qt::AlignCenter);
    editDetails()->page()->newStackControl(0);  
    editDetails()->page()->addComboBox(1, 0, 1, 1, "07", "00", "16"); //type
    editDetails()->page()->addStackControl();
     editDetails()->page()->addKnob(2, 0, 1, 1, "07", "00", "17");   //pan
    editDetails()->page()->addGroupBox(0, 0, 2, 1);
    editDetails()->page()->insertStackField(0, 0, 1, 3, 1);

    // ODDS
    editDetails()->page()->newStackField(0);
    editDetails()->page()->newGroupBox("Distortion");
    editDetails()->page()->addComboBox(0, 0, 1, 1, "07", "00", "18");
    editDetails()->page()->addKnob(0, 1, 1, 1, "07", "00", "19", "turbo");
    editDetails()->page()->addKnob(0, 2, 1, 1, "07", "00", "1A");
    editDetails()->page()->addKnob(0, 3, 1, 1, "07", "00", "1B");
    editDetails()->page()->addGroupBox(1, 2, 1, 1);
    editDetails()->page()->addStackField();

    // WAH
    editDetails()->page()->newStackField(0);
    editDetails()->page()->newGroupBox("Wah");
     editDetails()->page()->newStackControl(1);
    editDetails()->page()->addComboBox(0, 0, 1, 1, "07", "00", "1C");
    editDetails()->page()->addStackControl();
    editDetails()->page()->insertStackField(1, 0, 1, 1, 1);
    editDetails()->page()->addGroupBox(0, 1, 1, 1);
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(1);
    editDetails()->page()->addComboBox(0, 0, 1, 1, "07", "00", "1D"); //type
    editDetails()->page()->addKnob(0, 1, 1, 1, "07", "00", "1E");     //position
    editDetails()->page()->addKnob(0, 2, 1, 1, "07", "00", "22");     //level
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(1);
    editDetails()->page()->addKnob(0, 2, 1, 1, "07", "00", "1F");     //sens
    editDetails()->page()->addKnob(0, 3, 1, 1, "07", "00", "20");     //freq
    editDetails()->page()->addKnob(0, 4, 1, 1, "07", "00", "21");     //peak
    editDetails()->page()->addKnob(0, 5, 1, 1, "07", "00", "22");     //level
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(1);
    editDetails()->page()->addKnob(0, 2, 1, 1, "07", "00", "1F");     //sens
    editDetails()->page()->addKnob(0, 3, 1, 1, "07", "00", "20");     //freq
    editDetails()->page()->addKnob(0, 4, 1, 1, "07", "00", "21");     //peak
    editDetails()->page()->addKnob(0, 5, 1, 1, "07", "00", "22");     //level
    editDetails()->page()->addStackField();

    // Compressor
    editDetails()->page()->newStackField(0);
    editDetails()->page()->newGroupBox("Compressor");
    editDetails()->page()->addKnob(0, 0, 1, 1, "07", "00", "23");
    editDetails()->page()->addKnob(0, 1, 1, 1, "07", "00", "24");
    editDetails()->page()->addKnob(0, 2, 1, 1, "07", "00", "25");
    editDetails()->page()->addGroupBox(0, 1, 1, 1);
    editDetails()->page()->addStackField();

    // Limiter
    editDetails()->page()->newStackField(0);
    editDetails()->page()->newGroupBox("Limitter");
    editDetails()->page()->addKnob(0, 0, 1, 1, "07", "00", "26");
    editDetails()->page()->addKnob(0, 1, 1, 1, "07", "00", "27");
    editDetails()->page()->addKnob(0, 2, 1, 1, "07", "00", "28");
    editDetails()->page()->addGroupBox(0, 1, 1, 1);
    editDetails()->page()->addStackField();

    // Octave
    editDetails()->page()->newStackField(0);
    editDetails()->page()->newGroupBox("Octave");
    editDetails()->page()->addKnob(0, 0, 1, 1, "07", "00", "29");
    editDetails()->page()->addKnob(0, 1, 1, 1, "07", "00", "2A");
    editDetails()->page()->addGroupBox(0, 1, 1, 1);
    editDetails()->page()->addStackField();

    // Phaser
    editDetails()->page()->newStackField(0);
    editDetails()->page()->newGroupBox("Phaser");
    editDetails()->page()->addComboBox(0, 0, 1, 1, "07", "00", "2B");
    editDetails()->page()->addKnob(0, 1, 1, 1, "07", "00", "2C", "normal","right", 120);
    editDetails()->page()->addKnob(0, 2, 1, 1, "07", "00", "2D");
    editDetails()->page()->addKnob(0, 3, 1, 1, "07", "00", "2E");
    editDetails()->page()->addKnob(0, 4, 1, 1, "07", "00", "2F");
    editDetails()->page()->addGroupBox(0, 1, 1, 1);
    editDetails()->page()->addStackField();

    // Flanger
    editDetails()->page()->newStackField(0);
    editDetails()->page()->newGroupBox("Flanger");
    editDetails()->page()->addKnob(0, 0, 1, 1, "07", "00", "30", "normal","right", 120);
    editDetails()->page()->addKnob(0, 1, 1, 1, "07", "00", "31");
    editDetails()->page()->addKnob(0, 2, 1, 1, "07", "00", "32");
    editDetails()->page()->addKnob(0, 3, 1, 1, "07", "00", "33");
    editDetails()->page()->addKnob(0, 4, 1, 1, "07", "00", "34");
    editDetails()->page()->addGroupBox(0, 1, 1, 1);
    editDetails()->page()->addStackField();


    // Tremolo
    editDetails()->page()->newStackField(0);
    editDetails()->page()->newGroupBox("Tremolo");
    editDetails()->page()->addKnob(0, 0, 1, 1, "07", "00", "35", "normal","right", 120);
    editDetails()->page()->addKnob(0, 1, 1, 1, "07", "00", "36");
    editDetails()->page()->addKnob(0, 2, 1, 1, "07", "00", "37");
    editDetails()->page()->addKnob(0, 3, 1, 1, "07", "00", "38");
    editDetails()->page()->addGroupBox(0, 1, 1, 1);
    editDetails()->page()->addStackField();

    // Rotary
    editDetails()->page()->newStackField(0);
    editDetails()->page()->newGroupBox("Rotary");
    editDetails()->page()->addKnob(0, 0, 1, 1, "07", "00", "39", "normal","right", 120);
    editDetails()->page()->addKnob(1, 0, 1, 1, "07", "00", "3A", "normal","right", 120);
    editDetails()->page()->addKnob(0, 2, 1, 1, "07", "00", "3B");
    editDetails()->page()->addComboBox(0, 3, 1, 1, "07", "00", "3C");
    editDetails()->page()->addKnob(0, 4, 1, 1, "07", "00", "3D");
    editDetails()->page()->addGroupBox(0, 1, 1, 1);
    editDetails()->page()->addStackField();

    // Uni V
    editDetails()->page()->newStackField(0);
    editDetails()->page()->newGroupBox("Uni-Vibe");
    editDetails()->page()->addKnob(0, 0, 1, 1, "07", "00", "3E", "normal","right", 120);
    editDetails()->page()->addKnob(0, 1, 1, 1, "07", "00", "3F");
    editDetails()->page()->addKnob(0, 2, 1, 1, "07", "00", "40");
    editDetails()->page()->addGroupBox(0, 1, 1, 1);
    editDetails()->page()->addStackField();


    // Panner
    editDetails()->page()->newStackField(0);
    editDetails()->page()->newGroupBox("Panner");
    editDetails()->page()->addKnob(0, 0, 1, 1, "07", "00", "41", "normal","right", 120);
    editDetails()->page()->addKnob(0, 1, 1, 1, "07", "00", "42");
    editDetails()->page()->addKnob(0, 2, 1, 1, "07", "00", "43");
    editDetails()->page()->addKnob(0, 3, 1, 1, "07", "00", "44");
    editDetails()->page()->addGroupBox(0, 1, 1, 1);
    editDetails()->page()->addStackField();


    // Delay
    editDetails()->page()->newStackField(0);
    editDetails()->page()->newGroupBox("Delay");
    editDetails()->page()->addComboBox(0, 0, 1, 1, "07", "00", "45"); //type
    editDetails()->page()->addDataKnob(0, 1, 1, 1, "07", "00", "46", "DELAY3400","right", 120);       //time
    editDetails()->page()->addKnob(0, 2, 1, 1, "07", "00", "49");       //feedback
    editDetails()->page()->addKnob(0, 3, 1, 1, "07", "00", "4A");       //level
    editDetails()->page()->addGroupBox(0, 1, 1, 1);
    editDetails()->page()->addStackField();

    // Chorus
    editDetails()->page()->newStackField(0);
    editDetails()->page()->newGroupBox("Chorus");
    editDetails()->page()->addComboBox(0, 0, 1, 1, "07", "00", "4B");;
    editDetails()->page()->addKnob(0, 1, 1, 1, "07", "00", "4C", "normal","right", 120);
    editDetails()->page()->addKnob(0, 2, 1, 1, "07", "00", "4D");
    editDetails()->page()->addKnob(0, 3, 1, 1, "07", "00", "4E");
    editDetails()->page()->addGroupBox(0, 1, 1, 1);
    editDetails()->page()->addStackField();

    // Equalizer
    editDetails()->page()->newStackField(0);
    editDetails()->page()->newGroupBox("Equalizer");
    editDetails()->page()->newGroupBox("Low");
    editDetails()->page()->addKnob(0, 0, 1, 1, "07", "00", "4F");
    editDetails()->page()->addKnob(0, 1, 1, 1, "07", "00", "50");
    editDetails()->page()->addGroupBox(0, 0, 1, 1);

    editDetails()->page()->newGroupBox("Low-Middle");
    editDetails()->page()->addKnob(0, 0, 1, 1, "07", "00", "53");
    editDetails()->page()->addKnob(1, 0, 1, 1, "07", "00", "51");
    editDetails()->page()->addKnob(2, 0, 1, 1, "07", "00", "52");
    editDetails()->page()->addGroupBox(0, 1, 1, 1);

    editDetails()->page()->newGroupBox("High-Middle");
    editDetails()->page()->addKnob(0, 0, 1, 1, "07", "00", "56");
    editDetails()->page()->addKnob(1, 0, 1, 1, "07", "00", "54");
    editDetails()->page()->addKnob(2, 0, 1, 1, "07", "00", "55");
    editDetails()->page()->addGroupBox(0, 2, 1, 1);

    editDetails()->page()->newGroupBox("High");
    editDetails()->page()->addKnob(0, 0, 1, 1, "07", "00", "58");
    editDetails()->page()->addKnob(0, 1, 1, 1, "07", "00", "57");
    editDetails()->page()->addGroupBox(0, 3, 1, 1);
    editDetails()->page()->addGroupBox(0, 1, 1, 1);

    editDetails()->page()->newGroupBox("Level");
    editDetails()->page()->addKnob(0, 0, 1, 1, "07", "00", "59");
    editDetails()->page()->addGroupBox(0, 2, 1, 1);
    editDetails()->page()->addStackField();

editDetails()->addPage();
};
