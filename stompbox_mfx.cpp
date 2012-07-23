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

#include "stompbox_mfx.h"

stompbox_mfx::stompbox_mfx(QWidget *parent)
    : stompBox(parent)
{
    /* MFX */
    setImage(":/images/mfx.png");
    setLSB("03", "04");
    setComboBox("03", "00", "05");
    setSwitch("03", "00", "04");
    setKnob1("03", "CENTER", "06");
    editDetails()->patchPos(776, 530, "03", "04"); //correct
    setEditPages();
}

void stompbox_mfx::updateSignal()
{
    updateComboBox("03", "00", "05");
    updateSwitch("03", "00", "04");
    updateKnob1("03", "00", "06");
}

void stompbox_mfx::setEditPages()
{
    editDetails()->page()->newGroupBox("Select");
    editDetails()->page()->addSwitch(0, 0, 1, 1, "03", "00", "04", "middle", Qt::AlignCenter);
    editDetails()->page()->newStackControl(0);
    editDetails()->page()->addComboBox(1, 0, 1, 1, "03", "00", "05", "large");  //type
    editDetails()->page()->addStackControl();
    editDetails()->page()->addKnob(2, 0, 1, 1, "03", "00", "06");   // pan
    editDetails()->page()->addGroupBox(0, 0, 2, 1);
    editDetails()->page()->insertStackField(0, 0, 1, 3, 1);

    // EQ
    editDetails()->page()->newStackField(0);
    editDetails()->page()->newGroupBox("Equalizer");
    editDetails()->page()->addParaEQ(0, 1, 2, 4, "03", "00", "07", "MFX");
    editDetails()->page()->addGroupBox(0, 1, 1, 1);
   /* editDetails()->page()->newGroupBox("Low");
    editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "07");
    editDetails()->page()->addKnob(0, 1, 1, 1, "03", "00", "08");
    editDetails()->page()->addGroupBox(0, 0, 1, 1);

    editDetails()->page()->newGroupBox("Middle 1");
    editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "0A");
    editDetails()->page()->addKnob(1, 0, 1, 1, "03", "00", "09");
    editDetails()->page()->addKnob(2, 0, 1, 1, "03", "00", "0B");
    editDetails()->page()->addGroupBox(0, 1, 1, 1);

    editDetails()->page()->newGroupBox("Middle 2");
    editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "0D");
    editDetails()->page()->addKnob(1, 0, 1, 1, "03", "00", "0C");
    editDetails()->page()->addKnob(2, 0, 1, 1, "03", "00", "0E");
    editDetails()->page()->addGroupBox(0, 2, 1, 1);

    editDetails()->page()->newGroupBox("High");
    editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "10");
    editDetails()->page()->addKnob(0, 1, 1, 1, "03", "00", "0F");
    editDetails()->page()->addGroupBox(0, 3, 1, 1);
    editDetails()->page()->addGroupBox(0, 1, 1, 1);

    editDetails()->page()->newGroupBox("Level");
    editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "11");
    editDetails()->page()->addGroupBox(0, 2, 1, 1);*/
    editDetails()->page()->addStackField();

    // Filter
    editDetails()->page()->newStackField(0);
    editDetails()->page()->newGroupBox("Super Filter");
    editDetails()->page()->addComboBox(0, 0, 1, 1, "03", "00", "12");  // type
    editDetails()->page()->addComboBox(1, 0, 1, 1, "03", "00", "13");  // slope
    editDetails()->page()->addKnob(0, 1, 1, 1, "03", "00", "14");       //cutoff
    editDetails()->page()->addKnob(0, 2, 1, 1, "03", "00", "15");       //resonance
    editDetails()->page()->addKnob(0, 3, 1, 1, "03", "00", "16");        // gain
    editDetails()->page()->addComboBox(0, 4, 1, 1, "03", "00", "17");  // modulation
    editDetails()->page()->addComboBox(1, 4, 1, 1, "03", "00", "18");  // mod wave
    editDetails()->page()->addGroupBox(0, 0, 1, 1);

    editDetails()->page()->newGroupBox("Super Filter");
    editDetails()->page()->newStackControl(1);
    editDetails()->page()->addComboBox(0, 0, 1, 1, "03", "00", "19");  //Rate type
    editDetails()->page()->addStackControl();
    editDetails()->page()->insertStackField(1, 0, 1, 1, 1);
    editDetails()->page()->addKnob(0, 2, 1, 1, "03", "00", "1C");  //depth
    editDetails()->page()->addKnob(0, 3, 1, 1, "03", "00", "1D");  // attack
    editDetails()->page()->addKnob(0, 4, 1, 1, "03", "00", "1E");   // level
    editDetails()->page()->addGroupBox(1, 0, 1, 1);
    editDetails()->page()->addStackField();


    editDetails()->page()->newStackField(1);
    editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "1A", "normal","right", 120);   // rate
    editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(1);
    editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "1B", "normal","right", 120);   // rate
    editDetails()->page()->addStackField();

    // Phaser
    editDetails()->page()->newStackField(0);
    editDetails()->page()->newGroupBox("Phaser");
    editDetails()->page()->addComboBox(0, 0, 1, 1, "03", "00", "1F", "bottom", Qt::AlignRight);//mode
    editDetails()->page()->addKnob(0, 1, 1, 1, "03", "00", "20");   //manual
    editDetails()->page()->newStackControl(2);
    editDetails()->page()->addComboBox(0, 2, 1, 1, "03", "00", "21");  //Rate type
    editDetails()->page()->addStackControl();
    editDetails()->page()->insertStackField(2, 0, 3, 1, 1);
    editDetails()->page()->addKnob(0, 4, 1, 1, "03", "00", "24");    //depth
    editDetails()->page()->addGroupBox(0, 0, 1, 2);

    editDetails()->page()->newGroupBox("Phaser");
    editDetails()->page()->addComboBox(0, 0, 1, 1, "03", "00", "25", "bottom", Qt::AlignRight);//polarity
    editDetails()->page()->addKnob(0, 1, 1, 1, "03", "00", "26");    //reso
    editDetails()->page()->addKnob(0, 2, 1, 1, "03", "00", "27");   //cross fb
    editDetails()->page()->addKnob(0, 3, 1, 1, "03", "00", "28");     //mix
    editDetails()->page()->addGroupBox(1, 0, 1, 1);

    editDetails()->page()->newGroupBox("Level");
    editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "29");     // low gain
    editDetails()->page()->addKnob(0, 1, 1, 1, "03", "00", "2A");     //high gain
    editDetails()->page()->addKnob(0, 2, 1, 1, "03", "00", "2B");     //level
    editDetails()->page()->addGroupBox(1, 1, 1, 1);
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(2);
    editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "22", "normal","right", 120);   // rate
    editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(2);
    editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "23", "normal","right", 120);   // rate
    editDetails()->page()->addStackField();

    // Step Phaser
    editDetails()->page()->newStackField(0);
    editDetails()->page()->newGroupBox("Step Phaser");
    editDetails()->page()->addComboBox(0, 0, 1, 1, "03", "00", "2C", "bottom", Qt::AlignRight);//mode
    editDetails()->page()->addKnob(0, 1, 1, 1, "03", "00", "2D");   //manual
    editDetails()->page()->newStackControl(3);
    editDetails()->page()->addComboBox(0, 2, 1, 1, "03", "00", "2E");  //Rate type
    editDetails()->page()->addStackControl();
    editDetails()->page()->insertStackField(3, 0, 3, 1, 1);
    editDetails()->page()->addKnob(0, 4, 1, 1, "03", "00", "31");    //depth
    editDetails()->page()->addGroupBox(0, 0, 1, 2);

    editDetails()->page()->newGroupBox("Step Phaser");
    editDetails()->page()->addComboBox(0, 0, 1, 1, "03", "00", "32", "bottom", Qt::AlignRight);//polarity
    editDetails()->page()->addKnob(0, 1, 1, 1, "03", "00", "33");    //reso
    editDetails()->page()->addKnob(0, 2, 1, 1, "03", "00", "34");   //cross fb
    editDetails()->page()->newStackControl(4);
    editDetails()->page()->addComboBox(0, 3, 1, 1, "03", "00", "35");  //Rate type
    editDetails()->page()->addStackControl();
    editDetails()->page()->insertStackField(4, 0, 4, 1, 1);
    editDetails()->page()->addKnob(0, 5, 1, 1, "03", "00", "38");     //mix
    editDetails()->page()->addGroupBox(1, 0, 1, 1);

    editDetails()->page()->newGroupBox("Level");
    editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "39");     // low gain
    editDetails()->page()->addKnob(0, 1, 1, 1, "03", "00", "3A");     //high gain
    editDetails()->page()->addKnob(0, 2, 1, 1, "03", "00", "3B");     //level
    editDetails()->page()->addGroupBox(1, 1, 1, 1);
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(3);
    editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "2F", "normal","right", 120);   // rate
    editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(3);
    editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "30", "normal","right", 120);   // rate
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(4);
    editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "36", "normal","right", 120);   // rate
    editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(4);
    editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "37", "normal","right", 120);   // rate
    editDetails()->page()->addStackField();

    // Ring Modulator
    editDetails()->page()->newStackField(0);
    editDetails()->page()->newGroupBox("Ring Modulator");
    editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "3C");    // freq
    editDetails()->page()->addKnob(0, 1, 1, 1, "03", "00", "3D");    //sens
    editDetails()->page()->addComboBox(0, 3, 1, 1, "03", "00", "3E");  //polarity
    editDetails()->page()->addGroupBox(0, 0, 1, 1);

    editDetails()->page()->newGroupBox("Level");
    editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "3F");  //lo gain
    editDetails()->page()->addKnob(0, 1, 1, 1, "03", "00", "40");    //hi gain
    editDetails()->page()->addKnob(0, 2, 1, 1, "03", "00", "41");    //balance
    editDetails()->page()->addKnob(0, 3, 1, 1, "03", "00", "42");    //level
    editDetails()->page()->addGroupBox(0, 1, 1, 1);
    editDetails()->page()->addStackField();

    // Tremolo
    editDetails()->page()->newStackField(0);
    editDetails()->page()->newGroupBox("Tremolo");
    editDetails()->page()->addComboBox(0, 0, 1, 1, "03", "00", "43", "bottom", Qt::AlignRight);//mod wave
    editDetails()->page()->newStackControl(5);
    editDetails()->page()->addComboBox(0, 1, 1, 1, "03", "00", "44");  //Rate type
    editDetails()->page()->addStackControl();
    editDetails()->page()->insertStackField(5, 0, 2, 1, 1);
    editDetails()->page()->addKnob(0, 3, 1, 1, "03", "00", "47");    //depth
    editDetails()->page()->addGroupBox(0, 0, 1, 1);

    editDetails()->page()->newGroupBox("Level");
    editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "48");  //lo gain
    editDetails()->page()->addKnob(0, 1, 1, 1, "03", "00", "49");    //hi gain
    editDetails()->page()->addKnob(0, 2, 1, 1, "03", "00", "4A");    //level
    editDetails()->page()->addGroupBox(0, 1, 1, 1);
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(5);
    editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "45", "normal","right", 120);   // rate
    editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(5);
    editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "46", "normal","right", 120);   // rate
    editDetails()->page()->addStackField();


    // Auto Pan
    editDetails()->page()->newStackField(0);
    editDetails()->page()->newGroupBox("Auto Pan");
    editDetails()->page()->addComboBox(0, 0, 1, 1, "03", "00", "4B", "bottom", Qt::AlignRight);//mod wave
    editDetails()->page()->newStackControl(6);
    editDetails()->page()->addComboBox(0, 1, 1, 1, "03", "00", "4C");  //Rate type
    editDetails()->page()->addStackControl();
    editDetails()->page()->insertStackField(6, 0, 2, 1, 1);
    editDetails()->page()->addKnob(0, 3, 1, 1, "03", "00", "4F");    //depth
    editDetails()->page()->addGroupBox(0, 0, 1, 1);

    editDetails()->page()->newGroupBox("Level");
    editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "50");  //lo gain
    editDetails()->page()->addKnob(0, 1, 1, 1, "03", "00", "51");    //hi gain
    editDetails()->page()->addKnob(0, 2, 1, 1, "03", "00", "52");    //level
    editDetails()->page()->addGroupBox(0, 1, 1, 1);
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(6);
    editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "4D", "normal","right", 120);   // rate
    editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(6);
    editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "4E", "normal","right", 120);   // rate
    editDetails()->page()->addStackField();

    // Slicer
    editDetails()->page()->newStackField(0);
    editDetails()->page()->newGroupBox("Slicer");
    editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "53", "normal","right", 105);    //pattern
    editDetails()->page()->newStackControl(7);
    editDetails()->page()->addComboBox(0, 1, 1, 1, "03", "00", "54");  //Rate type
    editDetails()->page()->addStackControl();
    editDetails()->page()->insertStackField(7, 0, 2, 1, 1);
    editDetails()->page()->addGroupBox(0, 0, 1, 1);

    editDetails()->page()->newGroupBox("Slicer");
    editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "57");  //attack
    editDetails()->page()->addKnob(0, 1, 1, 1, "03", "00", "58");    //input sync
    editDetails()->page()->addKnob(0, 2, 1, 1, "03", "00", "59");    //sync thresh
    editDetails()->page()->addKnob(0, 3, 1, 1, "03", "00", "5A");    //level
    editDetails()->page()->addGroupBox(0, 1, 1, 1);
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(7);
    editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "55", "normal","right", 120);   // rate
    editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(7);
    editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "56", "normal","right", 120);   // rate
    editDetails()->page()->addStackField();

    // VK Rotary
    editDetails()->page()->newStackField(0);
    editDetails()->page()->newGroupBox("VK Rotary");
    editDetails()->page()->addComboBox(0, 0, 1, 1, "03", "00", "5B");  //speed
    editDetails()->page()->addComboBox(1, 0, 1, 1, "03", "00", "5C");  //brake
    editDetails()->page()->addGroupBox(0, 0, 2, 1);

    editDetails()->page()->newGroupBox("Wooofer");
    editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "5D");  //
    editDetails()->page()->addKnob(0, 1, 1, 1, "03", "00", "5E");    //
    editDetails()->page()->addKnob(0, 2, 1, 1, "03", "00", "5F");    //
    editDetails()->page()->addKnob(0, 3, 1, 1, "03", "00", "60");    //
    editDetails()->page()->addKnob(0, 4, 1, 1, "03", "00", "61");    //
    editDetails()->page()->addGroupBox(1, 1, 1, 1);

    editDetails()->page()->newGroupBox("Tweeter");
    editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "62");  //
    editDetails()->page()->addKnob(0, 1, 1, 1, "03", "00", "63");    //
    editDetails()->page()->addKnob(0, 2, 1, 1, "03", "00", "64");    //
    editDetails()->page()->addKnob(0, 3, 1, 1, "03", "00", "65");    //
    editDetails()->page()->addKnob(0, 4, 1, 1, "03", "00", "66");    //
    editDetails()->page()->addGroupBox(0, 1, 1, 1);

    editDetails()->page()->newGroupBox("VK Rotary");
    editDetails()->page()->addKnob(0, 1, 1, 1, "03", "00", "67");  //spread
    editDetails()->page()->addKnob(1, 0, 1, 1, "03", "00", "68");    //
    editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "69");    //
    editDetails()->page()->addKnob(1, 1, 1, 1, "03", "00", "6A");    //level
    editDetails()->page()->addGroupBox(0, 3, 2, 1);
    editDetails()->page()->addStackField();

    // Hexa chorus
    editDetails()->page()->newStackField(0);
    editDetails()->page()->newGroupBox("Hexa-Chorus");
    editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "6B", "normal","right", 60);    //predelay
    editDetails()->page()->newStackControl(8);
    editDetails()->page()->addComboBox(0, 1, 1, 1, "03", "00", "6C");  //Rate type
    editDetails()->page()->addStackControl();
    editDetails()->page()->insertStackField(8, 0, 2, 1, 1);
    editDetails()->page()->addKnob(0, 3, 1, 1, "03", "00", "6F");  //depth
    editDetails()->page()->addGroupBox(0, 0, 1, 2);

    editDetails()->page()->newGroupBox("Deviation");
    editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "70", "normal","right", 60);    //pre del dev
    editDetails()->page()->addKnob(0, 1, 1, 1, "03", "00", "71");    //depth dev
    editDetails()->page()->addKnob(0, 2, 1, 1, "03", "00", "72");    //pan dev
    editDetails()->page()->addGroupBox(1, 0, 1, 1);

    editDetails()->page()->newGroupBox("Output");
    editDetails()->page()->addKnob(0, 1, 1, 1, "03", "00", "73");    //balance
    editDetails()->page()->addKnob(0, 2, 1, 1, "03", "00", "74");    //output
    editDetails()->page()->addGroupBox(1, 1, 1, 1);
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(8);
    editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "6D", "normal","right", 120);   // rate
    editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(8);
    editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "6E", "normal","right", 120);   // rate
    editDetails()->page()->addStackField();

    // Space-D
    editDetails()->page()->newStackField(0);
    editDetails()->page()->newGroupBox("Space-D");
    editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "75", "normal","right", 60);    //predelay
    editDetails()->page()->newStackControl(9);
    editDetails()->page()->addComboBox(0, 1, 1, 1, "03", "00", "76");  //Rate type
    editDetails()->page()->addStackControl();
    editDetails()->page()->insertStackField(9, 0, 2, 1, 1);
    editDetails()->page()->addKnob(0, 3, 1, 1, "03", "00", "79");  //depth
    editDetails()->page()->addKnob(0, 4, 1, 1, "03", "00", "7A");  //phase
    editDetails()->page()->addGroupBox(0, 0, 1, 1);

    editDetails()->page()->newGroupBox("Output");
    editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "7B");    //low gain
    editDetails()->page()->addKnob(0, 1, 1, 1, "03", "00", "7C");    //high gain
    editDetails()->page()->addKnob(0, 2, 1, 1, "03", "00", "7D");    //balance
    editDetails()->page()->addKnob(0, 3, 1, 1, "03", "00", "7E");    //level
    editDetails()->page()->addGroupBox(1, 0, 1, 1);
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(9);
    editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "77", "normal","right", 120);   // rate
    editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(9);
    editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "78", "normal","right", 120);   // rate
    editDetails()->page()->addStackField();


    // Flanger
    editDetails()->page()->newStackField(0);
    editDetails()->page()->newGroupBox("Flanger");
    editDetails()->page()->addComboBox(0, 0, 1, 1, "03", "00", "7F");// filter type
    editDetails()->page()->addKnob(1, 0, 1, 1, "04", "00", "00");  // cutoff freq
    editDetails()->page()->addKnob(0, 1, 1, 1, "04", "00", "01", "normal","right", 60);    //predelay
    editDetails()->page()->newStackControl(10);
    editDetails()->page()->addComboBox(0, 2, 1, 1, "04", "00", "02");  //Rate type
    editDetails()->page()->addStackControl();
    editDetails()->page()->insertStackField(10, 0, 3, 1, 1);
    editDetails()->page()->addKnob(1, 1, 1, 1, "04", "00", "05");
    editDetails()->page()->addKnob(1, 2, 1, 1, "04", "00", "06");
    editDetails()->page()->addKnob(1, 3, 1, 1, "04", "00", "07");
    editDetails()->page()->addGroupBox(0, 0, 1, 1);

    editDetails()->page()->newGroupBox("Level");
    editDetails()->page()->addKnob(1, 0, 1, 1, "04", "00", "08");
    editDetails()->page()->addKnob(0, 0, 1, 1, "04", "00", "09");
    editDetails()->page()->addKnob(0, 1, 1, 1, "04", "00", "0A");
    editDetails()->page()->addKnob(1, 1, 1, 1, "04", "00", "0B");
    editDetails()->page()->addGroupBox(0, 1, 1, 1);
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(10);
    editDetails()->page()->addKnob(0, 0, 1, 1, "04", "00", "03", "normal","right", 120);   // rate
    editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(10);
    editDetails()->page()->addKnob(0, 0, 1, 1, "04", "00", "04", "normal","right", 120);   // rate
    editDetails()->page()->addStackField();

    // Step Flanger
    editDetails()->page()->newStackField(0);
    editDetails()->page()->newGroupBox("Step Flanger");
    editDetails()->page()->addComboBox(0, 0, 1, 1, "04", "00", "0C");// filter type
    editDetails()->page()->addKnob(1, 0, 1, 1, "04", "00", "0D");  // cutoff freq
    editDetails()->page()->addKnob(0, 1, 1, 1, "04", "00", "0E", "normal","right", 60);    //predelay
    editDetails()->page()->newStackControl(11);
    editDetails()->page()->addComboBox(0, 2, 1, 1, "04", "00", "0F");  //Rate type
    editDetails()->page()->addStackControl();
    editDetails()->page()->insertStackField(11, 0, 3, 1, 1);
    editDetails()->page()->addKnob(1, 1, 1, 1, "04", "00", "12"); //depth
    editDetails()->page()->addKnob(0, 4, 1, 1, "04", "00", "13"); //phase
    editDetails()->page()->addKnob(1, 4, 1, 1, "04", "00", "14"); //feedback
    editDetails()->page()->newStackControl(12);
    editDetails()->page()->addComboBox(1, 2, 1, 1, "04", "00", "15");  //step Rate type
    editDetails()->page()->addStackControl();
    editDetails()->page()->insertStackField(12, 1, 3, 1, 1);
    editDetails()->page()->addGroupBox(0, 0, 1, 1);

    editDetails()->page()->newGroupBox("Level");
    editDetails()->page()->addKnob(1, 0, 1, 1, "04", "00", "18");
    editDetails()->page()->addKnob(0, 0, 1, 1, "04", "00", "19");
    editDetails()->page()->addKnob(0, 1, 1, 1, "04", "00", "1A");
    editDetails()->page()->addKnob(1, 1, 1, 1, "04", "00", "1B");
    editDetails()->page()->addGroupBox(0, 2, 1, 1);
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(11);
    editDetails()->page()->addKnob(0, 0, 1, 1, "04", "00", "10", "normal","right", 120);   // rate
    editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(11);
    editDetails()->page()->addKnob(0, 0, 1, 1, "04", "00", "11", "normal","right", 120);   // rate
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(12);
    editDetails()->page()->addKnob(0, 0, 1, 1, "04", "00", "16", "normal","right", 120);   // rate
    editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(12);
    editDetails()->page()->addKnob(0, 0, 1, 1, "04", "00", "17", "normal","right", 120);   // rate
    editDetails()->page()->addStackField();


    // Amp Spkr
    editDetails()->page()->newStackField(0);
    editDetails()->page()->newGroupBox("Amp", Qt::AlignTop | Qt::AlignHCenter);
    editDetails()->page()->addSwitch(0, 0, 1, 1, "04", "00", "1C", "middle", Qt::AlignCenter); //sw
    editDetails()->page()->newStackControl(13);
    editDetails()->page()->addComboBox(1, 0, 1, 1, "04", "00", "1D");// type
    editDetails()->page()->addStackControl();
    editDetails()->page()->addKnob(0, 1, 1, 1, "04", "00", "1E");   //pre vol
    editDetails()->page()->addKnob(0, 2, 1, 1, "04", "00", "1F");   // pre master
    editDetails()->page()->addKnob(0, 3, 1, 1, "04", "00", "20");   //gain
    editDetails()->page()->addKnob(0, 4, 1, 1, "04", "00", "21");   //bass
    editDetails()->page()->addKnob(0, 5, 1, 1, "04", "00", "22");    //middle
    editDetails()->page()->addKnob(0, 6, 1, 1, "04", "00", "23");    //treble
    editDetails()->page()->addKnob(0, 7, 1, 1, "04", "00", "24");    //presence
    editDetails()->page()->insertStackField(13, 0, 8, 1, 1);
    editDetails()->page()->addGroupBox(0, 0, 1, 1);

    editDetails()->page()->newGroupBox("Speaker", Qt::AlignTop | Qt::AlignHCenter);
    editDetails()->page()->addSwitch(0, 0, 1, 1, "04", "00", "26", "middle", Qt::AlignCenter); //sw
    editDetails()->page()->addComboBox(1, 0, 1, 1, "04", "00", "27");// type
    editDetails()->page()->addKnob(0, 1, 1, 1, "04", "00", "28");   //mic setting
    editDetails()->page()->addKnob(0, 2, 1, 1, "04", "00", "29");   //mic level
    editDetails()->page()->addKnob(0, 3, 1, 1, "04", "00", "2A");   // direct
    editDetails()->page()->addKnob(0, 4, 1, 1, "04", "00", "2B");   //pan
    editDetails()->page()->addKnob(0, 5, 1, 1, "04", "00", "2C");   //level
    editDetails()->page()->addGroupBox(1, 0, 1, 1);
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(13);
    editDetails()->page()->addSwitch(0, 8, 1, 1, "04", "00", "25", "middle", Qt::AlignCenter); //bright sw
    editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(13);
    editDetails()->page()->addSwitch(0, 8, 1, 1, "04", "00", "25", "middle", Qt::AlignCenter); //bright sw
    editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(13);
    editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(13);
    editDetails()->page()->addSwitch(0, 8, 1, 1, "04", "00", "25", "middle", Qt::AlignCenter); //bright sw
    editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(13);
    editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(13);
    editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(13);
    editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(13);
    editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(13);
    editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(13);
    editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(13);
    editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(13);
    editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(13);
    editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(13);
    editDetails()->page()->addStackField();


    // Compressor
    editDetails()->page()->newStackField(0);
    editDetails()->page()->newGroupBox("Compressor", Qt::AlignTop | Qt::AlignHCenter);
    editDetails()->page()->addKnob(0, 0, 1, 1, "04", "00", "2D");   //attack
    editDetails()->page()->addKnob(0, 1, 1, 1, "04", "00", "2E");   //threshold
    editDetails()->page()->addKnob(0, 2, 1, 1, "04", "00", "2F");   //post gain
    editDetails()->page()->addKnob(0, 3, 1, 1, "04", "00", "30");   //low gain
    editDetails()->page()->addKnob(0, 4, 1, 1, "04", "00", "31");    //high gain
    editDetails()->page()->addKnob(0, 5, 1, 1, "04", "00", "32");    //level
    editDetails()->page()->addGroupBox(0, 0, 1, 1);
    editDetails()->page()->addStackField();

    // Limiter
    editDetails()->page()->newStackField(0);
    editDetails()->page()->newGroupBox("Limiter", Qt::AlignTop | Qt::AlignHCenter);
    editDetails()->page()->addKnob(0, 0, 1, 1, "04", "00", "33");   //attack
    editDetails()->page()->addKnob(0, 1, 1, 1, "04", "00", "34");   //threshold
    editDetails()->page()->addKnob(0, 2, 1, 1, "04", "00", "35");   //ratio
    editDetails()->page()->addKnob(0, 3, 1, 1, "04", "00", "36");   //post gain
    editDetails()->page()->addKnob(0, 4, 1, 1, "04", "00", "37");    //low gain
    editDetails()->page()->addKnob(0, 5, 1, 1, "04", "00", "38");    //high gain
    editDetails()->page()->addKnob(0, 6, 1, 1, "04", "00", "39");    //level
    editDetails()->page()->addGroupBox(0, 0, 1, 1);
    editDetails()->page()->addStackField();

    // 3Tap pan delay
    editDetails()->page()->newStackField(0);
    editDetails()->page()->newGroupBox("3Tap Pan Delay Left", Qt::AlignTop | Qt::AlignHCenter);
    editDetails()->page()->newStackControl(14);
    editDetails()->page()->addComboBox(0, 0, 1, 1, "04", "00", "3A");// left type
    editDetails()->page()->addStackControl();
    editDetails()->page()->insertStackField(14, 1, 0, 1, 1);
    editDetails()->page()->addKnob(3, 0, 1, 1, "04", "00", "4B");   //left level
    editDetails()->page()->addGroupBox(0, 0, 1, 1);
    editDetails()->page()->newGroupBox("3Tap Pan Delay Center", Qt::AlignTop | Qt::AlignHCenter);
    editDetails()->page()->newStackControl(15);
    editDetails()->page()->addComboBox(0, 0, 1, 1, "04", "00", "44");// center type
    editDetails()->page()->addStackControl();
    editDetails()->page()->insertStackField(15, 1, 0, 1, 1);
    editDetails()->page()->addKnob(2, 0, 1, 1, "04", "00", "49");   //center fback
    editDetails()->page()->addKnob(3, 0, 1, 1, "04", "00", "4D");   //center level
    editDetails()->page()->addGroupBox(0, 1, 1, 1);
    editDetails()->page()->newGroupBox("3Tap Pan Delay Right", Qt::AlignTop | Qt::AlignHCenter);
    editDetails()->page()->newStackControl(16);
    editDetails()->page()->addComboBox(0, 0, 1, 1, "04", "00", "3F");// right type
    editDetails()->page()->addStackControl();
    editDetails()->page()->insertStackField(16, 1, 0, 1, 1);
    editDetails()->page()->addKnob(3, 0, 1, 1, "04", "00", "4C");    //right level
    editDetails()->page()->addGroupBox(0, 2, 1, 1);
    editDetails()->page()->newGroupBox("Level");
    editDetails()->page()->addKnob(0, 0, 1, 1, "04", "00", "4A");   //hf damp
    editDetails()->page()->addKnob(0, 1, 1, 1, "04", "00", "4E");   // low gain
    editDetails()->page()->addKnob(0, 2, 1, 1, "04", "00", "4F");   // high gain
    editDetails()->page()->addKnob(0, 3, 1, 1, "04", "00", "50");   //balance
    editDetails()->page()->addKnob(0, 4, 1, 1, "04", "00", "51");   //level
    editDetails()->page()->addGroupBox(1, 0, 1, 3);
    editDetails()->page()->addStackField();


     editDetails()->page()->newStackField(14);
     editDetails()->page()->addDataKnob(0, 0, 1, 1, "04", "00", "3B", "DELAY2600", "right", 120); // left time
     editDetails()->page()->addStackField();

     editDetails()->page()->newStackField(14);
     editDetails()->page()->addKnob(0, 0, 1, 1, "04", "00", "3E", "normal", "right", 120);   // left Rate
     editDetails()->page()->addStackField();

     editDetails()->page()->newStackField(15);
     editDetails()->page()->addDataKnob(0, 0, 1, 1, "04", "00", "45", "DELAY2600", "right", 120); // center time
     editDetails()->page()->addStackField();

     editDetails()->page()->newStackField(15);
     editDetails()->page()->addKnob(0, 0, 1, 1, "04", "00", "48", "normal", "right", 120);   // center Rate
     editDetails()->page()->addStackField();

     editDetails()->page()->newStackField(16);
     editDetails()->page()->addDataKnob(0, 0, 1, 1, "04", "00", "40", "DELAY2600", "right", 120); // right time
     editDetails()->page()->addStackField();

     editDetails()->page()->newStackField(16);
     editDetails()->page()->addKnob(0, 0, 1, 1, "04", "00", "43", "normal", "right", 120);   // right Rate
     editDetails()->page()->addStackField();

    // Time CTRL delay
    editDetails()->page()->newStackField(0);
    editDetails()->page()->newGroupBox("Time Based Delay", Qt::AlignTop | Qt::AlignHCenter);
    editDetails()->page()->newStackControl(17);
    editDetails()->page()->addComboBox(0, 0, 1, 1, "04", "00", "52");// time type
    editDetails()->page()->addStackControl();
    editDetails()->page()->insertStackField(17, 0, 1, 1, 1);
    editDetails()->page()->addKnob(0, 2, 1, 1, "04", "00", "57");   //acceleration
    editDetails()->page()->addKnob(0, 3, 1, 1, "04", "00", "58");   //feedback
    editDetails()->page()->addKnob(0, 4, 1, 1, "04", "00", "59");   //hf damp
    editDetails()->page()->addGroupBox(0, 0, 1, 1);
    editDetails()->page()->newGroupBox("Level");
    editDetails()->page()->addKnob(0, 0, 1, 1, "04", "00", "5A");   // low gain
    editDetails()->page()->addKnob(0, 1, 1, 1, "04", "00", "5B");   // high gain
    editDetails()->page()->addKnob(0, 2, 1, 1, "04", "00", "5C");   //balance
    editDetails()->page()->addKnob(0, 3, 1, 1, "04", "00", "5D");   //level
    editDetails()->page()->addGroupBox(1, 0, 1, 1);
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(17);
    editDetails()->page()->addDataKnob(0, 0, 1, 1, "04", "00", "53", "DELAY1300", "right", 120); // time
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(17);
    editDetails()->page()->addKnob(0, 0, 1, 1, "04", "00", "56", "normal", "right", 120);   // Rate
    editDetails()->page()->addStackField();

    // LoFi Compressor
    editDetails()->page()->newStackField(0);
    editDetails()->page()->newGroupBox("LoFi Compressor", Qt::AlignTop | Qt::AlignHCenter);
    editDetails()->page()->addKnob(0, 0, 1, 1, "04", "00", "5E");   //pre filt type
    editDetails()->page()->addKnob(0, 1, 1, 1, "04", "00", "5F");   //lofi type
    editDetails()->page()->addKnob(0, 2, 1, 1, "04", "00", "60", "normal","right", 105);   //filter type
    editDetails()->page()->addKnob(0, 3, 1, 1, "04", "00", "61");   //post filter cut
    editDetails()->page()->addGroupBox(0, 0, 1, 1);
    editDetails()->page()->newGroupBox("Level");
    editDetails()->page()->addKnob(0, 0, 1, 1, "04", "00", "62");   // low gain
    editDetails()->page()->addKnob(0, 1, 1, 1, "04", "00", "63");   // high gain
    editDetails()->page()->addKnob(0, 2, 1, 1, "04", "00", "64");   //balance
    editDetails()->page()->addKnob(0, 3, 1, 1, "04", "00", "65");   //level
    editDetails()->page()->addGroupBox(1, 0, 1, 1);
    editDetails()->page()->addStackField();

    // Pitch Shifter
    editDetails()->page()->newStackField(0);
    editDetails()->page()->newGroupBox("Pitch Shifter", Qt::AlignTop | Qt::AlignHCenter);
    editDetails()->page()->addKnob(0, 0, 1, 1, "04", "00", "66", "normal", "right", 120);   //pitch coarse
    editDetails()->page()->addKnob(0, 1, 1, 1, "04", "00", "67", "normal", "right", 120);   //pitch fine
    editDetails()->page()->newStackControl(18);
    editDetails()->page()->addComboBox(0, 2, 1, 1, "04", "00", "68");// time type
    editDetails()->page()->addStackControl();
    editDetails()->page()->insertStackField(18, 0, 3, 1, 1);
    editDetails()->page()->addKnob(0, 4, 1, 1, "04", "00", "6D");   //feedback
    editDetails()->page()->addGroupBox(0, 0, 1, 1);
    editDetails()->page()->newGroupBox("Level");
    editDetails()->page()->addKnob(0, 0, 1, 1, "04", "00", "6E");   // low gain
    editDetails()->page()->addKnob(0, 1, 1, 1, "04", "00", "6F");   // high gain
    editDetails()->page()->addKnob(0, 2, 1, 1, "04", "00", "70");   //balance
    editDetails()->page()->addKnob(0, 3, 1, 1, "04", "00", "71");   //level
    editDetails()->page()->addGroupBox(1, 0, 1, 1);
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(18);
    editDetails()->page()->addDataKnob(0, 0, 1, 1, "04", "00", "69", "DELAY1300", "right", 120); // time
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(18);
    editDetails()->page()->addKnob(0, 0, 1, 1, "04", "00", "6C", "normal", "right", 120);   // Rate
    editDetails()->page()->addStackField();


    editDetails()->addPage();
}
