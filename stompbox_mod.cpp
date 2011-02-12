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

#include "stompbox_mod.h"

stompbox_mod::stompbox_mod(QWidget *parent)
    : stompBox(parent)
{
    /* MOD */
    setImage(":/images/mod.png");
    setLSB("03", "00");
    setComboBox("03", "00", "02");
    setSwitch("03", "00", "00");
    //editDetails()->patchPos(586, 1018, "02", "00");
    setEditPages();
};

void stompbox_mod::updateSignal()
{
    updateComboBox("03", "00", "02");
    updateSwitch("03", "00", "00");
};

void stompbox_mod::setEditPages()
{
    editDetails()->page()->newGroupBox("MOD");
    editDetails()->page()->addSwitch(0, 0, 1, 1, "03", "00", "00", "middle", Qt::AlignCenter);
    editDetails()->page()->newStackControl(0);
    editDetails()->page()->addComboBox(1, 0, 1, 1, "03", "00", "02");
    editDetails()->page()->addStackControl();
    editDetails()->page()->addGroupBox(0, 0, 2, 1);
    editDetails()->page()->insertStackField(0, 0, 1, 3, 1);

    // ODDS
    editDetails()->page()->newStackField(0);
    editDetails()->page()->newGroupBox("Distortion");
    editDetails()->page()->addComboBox(0, 0, 1, 1, "03", "00", "06");
    editDetails()->page()->addKnob(0, 1, 1, 1, "03", "00", "07");
    editDetails()->page()->addKnob(0, 2, 1, 1, "03", "00", "08");
    editDetails()->page()->addKnob(0, 3, 1, 1, "03", "00", "09");
    editDetails()->page()->addGroupBox(1, 2, 1, 1);
    editDetails()->page()->addStackField();

    // WAH
    editDetails()->page()->newStackField(0);
    editDetails()->page()->newGroupBox("Wah");
     editDetails()->page()->newStackControl(1);
    editDetails()->page()->addComboBox(0, 0, 1, 1, "03", "00", "0A");
    editDetails()->page()->addStackControl();
    editDetails()->page()->insertStackField(1, 0, 1, 1, 1);
    editDetails()->page()->addGroupBox(0, 1, 1, 1);
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(1);
    editDetails()->page()->addComboBox(0, 0, 1, 1, "03", "00", "0B"); //type
    editDetails()->page()->addKnob(0, 1, 1, 1, "03", "00", "0C");     //position
    editDetails()->page()->addKnob(0, 2, 1, 1, "03", "00", "10");     //level
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(1);
    editDetails()->page()->addKnob(0, 2, 1, 1, "03", "00", "0D");     //sens
    editDetails()->page()->addKnob(0, 3, 1, 1, "03", "00", "0E");     //freq
    editDetails()->page()->addKnob(0, 4, 1, 1, "03", "00", "0F");     //peak
    editDetails()->page()->addKnob(0, 5, 1, 1, "03", "00", "10");     //level
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(1);
    editDetails()->page()->addKnob(0, 2, 1, 1, "03", "00", "0D");     //sens
    editDetails()->page()->addKnob(0, 3, 1, 1, "03", "00", "0E");     //freq
    editDetails()->page()->addKnob(0, 4, 1, 1, "03", "00", "0F");     //peak
    editDetails()->page()->addKnob(0, 5, 1, 1, "03", "00", "10");     //level
    editDetails()->page()->addStackField();

    // Compressor
    editDetails()->page()->newStackField(0);
    editDetails()->page()->newGroupBox("Compressor");
    editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "11");
    editDetails()->page()->addKnob(0, 1, 1, 1, "03", "00", "12");
    editDetails()->page()->addKnob(0, 2, 1, 1, "03", "00", "13");
    editDetails()->page()->addGroupBox(0, 1, 1, 1);
    editDetails()->page()->addStackField();

    // Limiter
    editDetails()->page()->newStackField(0);
    editDetails()->page()->newGroupBox("Limitter");
    editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "14");
    editDetails()->page()->addKnob(0, 1, 1, 1, "03", "00", "15");
    editDetails()->page()->addKnob(0, 2, 1, 1, "03", "00", "16");
    editDetails()->page()->addGroupBox(0, 1, 1, 1);
    editDetails()->page()->addStackField();

    // Octave
    editDetails()->page()->newStackField(0);
    editDetails()->page()->newGroupBox("Octave");
    editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "17");
    editDetails()->page()->addKnob(0, 1, 1, 1, "03", "00", "18");
    editDetails()->page()->addGroupBox(0, 1, 1, 1);
    editDetails()->page()->addStackField();

    // Phaser
    editDetails()->page()->newStackField(0);
    editDetails()->page()->newGroupBox("Phaser");
    editDetails()->page()->addComboBox(0, 0, 1, 1, "03", "00", "19");
    editDetails()->page()->addKnob(0, 1, 1, 1, "03", "00", "1A");
    editDetails()->page()->addKnob(0, 2, 1, 1, "03", "00", "1B");
    editDetails()->page()->addKnob(0, 3, 1, 1, "03", "00", "1C");
    editDetails()->page()->addKnob(0, 4, 1, 1, "03", "00", "1D");
    editDetails()->page()->addGroupBox(0, 1, 1, 1);
    editDetails()->page()->addStackField();

    // Flanger
    editDetails()->page()->newStackField(0);
    editDetails()->page()->newGroupBox("Flanger");
    editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "1E");
    editDetails()->page()->addKnob(0, 1, 1, 1, "03", "00", "1F");
    editDetails()->page()->addKnob(0, 2, 1, 1, "03", "00", "20");
    editDetails()->page()->addKnob(0, 3, 1, 1, "03", "00", "21");
    editDetails()->page()->addKnob(0, 4, 1, 1, "03", "00", "22");
    editDetails()->page()->addGroupBox(0, 1, 1, 1);
    editDetails()->page()->addStackField();


    // Tremolo
    editDetails()->page()->newStackField(0);
    editDetails()->page()->newGroupBox("Tremolo");
    editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "23");
    editDetails()->page()->addKnob(0, 1, 1, 1, "03", "00", "24");
    editDetails()->page()->addKnob(0, 2, 1, 1, "03", "00", "25");
    editDetails()->page()->addKnob(0, 3, 1, 1, "03", "00", "26");
    editDetails()->page()->addGroupBox(0, 1, 1, 1);
    editDetails()->page()->addStackField();

    // Rotary
    editDetails()->page()->newStackField(0);
    editDetails()->page()->newGroupBox("Rotary");
    editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "27");
    editDetails()->page()->addKnob(0, 1, 1, 1, "03", "00", "28");
    editDetails()->page()->addKnob(0, 2, 1, 1, "03", "00", "29");
    editDetails()->page()->addComboBox(0, 3, 1, 1, "03", "00", "2A");
    editDetails()->page()->addKnob(0, 4, 1, 1, "03", "00", "2B");
    editDetails()->page()->addGroupBox(0, 1, 1, 1);
    editDetails()->page()->addStackField();

    // Uni V
    editDetails()->page()->newStackField(0);
    editDetails()->page()->newGroupBox("Uni-Vibe");
    editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "2C");
    editDetails()->page()->addKnob(0, 1, 1, 1, "03", "00", "2D");
    editDetails()->page()->addKnob(0, 2, 1, 1, "03", "00", "2E");
    editDetails()->page()->addGroupBox(0, 1, 1, 1);
    editDetails()->page()->addStackField();


    // Panner
    editDetails()->page()->newStackField(0);
    editDetails()->page()->newGroupBox("Panner");
    editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "2F");
    editDetails()->page()->addKnob(0, 1, 1, 1, "03", "00", "30");
    editDetails()->page()->addKnob(0, 2, 1, 1, "03", "00", "31");
    editDetails()->page()->addKnob(0, 3, 1, 1, "03", "00", "32");
    editDetails()->page()->addGroupBox(0, 1, 1, 1);
    editDetails()->page()->addStackField();


    // Delay
    editDetails()->page()->newStackField(0);
    editDetails()->page()->newGroupBox("Delay");
    editDetails()->page()->addComboBox(0, 0, 1, 1, "03", "00", "33");;
    //editDetails()->page()->addKnob(0, 1, 1, 1, "03", "00", "34");
    editDetails()->page()->addKnob(0, 2, 1, 1, "03", "00", "36");
    editDetails()->page()->addKnob(0, 3, 1, 1, "03", "00", "37");
    editDetails()->page()->addGroupBox(0, 1, 1, 1);
    editDetails()->page()->addStackField();

    // Chorus
    editDetails()->page()->newStackField(0);
    editDetails()->page()->newGroupBox("Chorus");
    editDetails()->page()->addComboBox(0, 0, 1, 1, "03", "00", "38");;
    editDetails()->page()->addKnob(0, 1, 1, 1, "03", "00", "39");
    editDetails()->page()->addKnob(0, 2, 1, 1, "03", "00", "3A");
    editDetails()->page()->addKnob(0, 3, 1, 1, "03", "00", "3B");
    editDetails()->page()->addGroupBox(0, 1, 1, 1);
    editDetails()->page()->addStackField();

    // Equalizer
    editDetails()->page()->newStackField(0);
    editDetails()->page()->newGroupBox("Equalizer");
    editDetails()->page()->newGroupBox("Low");
    editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "3C");
    editDetails()->page()->addKnob(0, 1, 1, 1, "03", "00", "3D");
    editDetails()->page()->addGroupBox(0, 0, 1, 1);

    editDetails()->page()->newGroupBox("Low-Middle");
    editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "40");
    editDetails()->page()->addKnob(1, 0, 1, 1, "03", "00", "3E");
    editDetails()->page()->addKnob(2, 0, 1, 1, "03", "00", "3F");
    editDetails()->page()->addGroupBox(0, 1, 1, 1);

    editDetails()->page()->newGroupBox("High-Middle");
    editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "43");
    editDetails()->page()->addKnob(1, 0, 1, 1, "03", "00", "41");
    editDetails()->page()->addKnob(2, 0, 1, 1, "03", "00", "42");
    editDetails()->page()->addGroupBox(0, 2, 1, 1);

    editDetails()->page()->newGroupBox("High");
    editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "45");
    editDetails()->page()->addKnob(0, 1, 1, 1, "03", "00", "44");
    editDetails()->page()->addGroupBox(0, 3, 1, 1);
    editDetails()->page()->addGroupBox(0, 1, 1, 1);

    editDetails()->page()->newGroupBox("Level");
    editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "46");
    editDetails()->page()->addKnob(2, 0, 1, 1, "03", "00", "47");
    editDetails()->page()->addGroupBox(0, 2, 1, 1);
    editDetails()->page()->addStackField();

editDetails()->addPage();
};
