/****************************************************************************
**
** Copyright (C) 2007~2013 Colin Willcocks.
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

#include "soundSource_modeling_bass.h"

soundsource_modeling_bass::soundsource_modeling_bass(QWidget *parent)
    : soundSource(parent)
{
    /* MODELING */
    this->setImage(":/images/modeling.png");
    setLSB("10", "00");
    setSwitch("10", "INVERT", "0A");
    setComboBox("02", "routeSwitch", "2D");
    setKnob1("10", "00", "05");
    setKnob2("10", "00", "09");
    editDetails()->patchPos(1756, 454, "10", "00");
    setEditPages();
}

void soundsource_modeling_bass::updateSignal()
{
    updateSwitch("10", "00", "0A");
    updateComboBox("02", "routeSwitch", "2D");
    updateKnob1("10", "00", "05");
    updateKnob2("10", "00", "09");
}

void soundsource_modeling_bass::setEditPages()
{
    editDetails()->page()->newGroupBox("Bass Mode Modeling");
    editDetails()->page()->addSwitch(0, 0, 1, 1, "10", "00", "0A", "invert", Qt::AlignCenter);
    editDetails()->page()->addComboBox(0, 1, 1, 1, "02", "00", "2D"); //route switch
    editDetails()->page()->newStackControl(0);
    editDetails()->page()->addComboBox(0, 2, 1, 1, "10", "00", "05"); // Bass select
    editDetails()->page()->addStackControl();
    editDetails()->page()->addKnob(0, 3, 1, 1, "10", "00", "09");  //level
    editDetails()->page()->addGroupBox(0, 0, 1, 1);
    editDetails()->page()->newGroupBox("Pitch");
    editDetails()->page()->addComboBox(0, 0, 1, 1, "10", "00", "11");  //pitch
    editDetails()->page()->addKnob(0, 1, 1, 1, "10", "00", "12");  //pitch fine
    editDetails()->page()->addGroupBox(0, 1, 1, 1);
    editDetails()->page()->newGroupBox("12 String");
    editDetails()->page()->addSwitch(0, 0, 1, 1, "10", "00", "1D", "middle", Qt::AlignCenter); // 12 str sw
    editDetails()->page()->addKnob(1, 0, 1, 1, "10", "00", "1E");  // direct level
    editDetails()->page()->addKnob(0, 1, 1, 1, "10", "00", "1F");  //12 string shift 1
    editDetails()->page()->addKnob(0, 2, 1, 1, "10", "00", "21");  //2
    editDetails()->page()->addKnob(0, 3, 1, 1, "10", "00", "23");  //3
    editDetails()->page()->addKnob(0, 4, 1, 1, "10", "00", "25");  //4
    editDetails()->page()->addKnob(0, 5, 1, 1, "10", "00", "27");  //5
    editDetails()->page()->addKnob(0, 6, 1, 1, "10", "00", "29");  //6
    editDetails()->page()->addKnob(1, 1, 1, 1, "10", "00", "20");  //12 string shift fine 1
    editDetails()->page()->addKnob(1, 2, 1, 1, "10", "00", "22");  //2
    editDetails()->page()->addKnob(1, 3, 1, 1, "10", "00", "24");  //3
    editDetails()->page()->addKnob(1, 4, 1, 1, "10", "00", "26");  //4
    editDetails()->page()->addKnob(1, 5, 1, 1, "10", "00", "28");  //5
    editDetails()->page()->addKnob(1, 6, 1, 1, "10", "00", "2A");  //6
    editDetails()->page()->addGroupBox(0, 2, 2, 1);
    editDetails()->page()->newGroupBox("String Level");
    editDetails()->page()->addKnob(0, 0, 1, 1, "10", "00", "0B");  //string 1
    editDetails()->page()->addKnob(0, 1, 1, 1, "10", "00", "0C");  //2
    editDetails()->page()->addKnob(0, 2, 1, 1, "10", "00", "0D");  //3
    editDetails()->page()->addKnob(0, 3, 1, 1, "10", "00", "0E");  //4
    editDetails()->page()->addKnob(0, 4, 1, 1, "10", "00", "0F");  //5
    editDetails()->page()->addKnob(0, 5, 1, 1, "10", "00", "10");  //6
    editDetails()->page()->addGroupBox(1, 0, 1, 2);
    editDetails()->page()->insertStackField(0, 2, 0, 1, 4);


    editDetails()->page()->newStackField(0);
    editDetails()->page()->newGroupBox("");
    editDetails()->page()->newStackControl(1);
    editDetails()->page()->addComboBox(0, 0, 1, 1, "10", "00", "06"); // Bass select
    editDetails()->page()->addStackControl();
    editDetails()->page()->insertStackField(1, 1, 0, 1, 1);
    editDetails()->page()->addGroupBox(0, 0, 1, 4);
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(0);
    editDetails()->page()->newGroupBox("");
    editDetails()->page()->newStackControl(2);
    editDetails()->page()->addComboBox(0, 0, 1, 1, "10", "00", "08"); // synth select
    editDetails()->page()->addStackControl();
    editDetails()->page()->insertStackField(2, 1, 0, 1, 1);
    editDetails()->page()->addGroupBox(0, 0, 1, 4);
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(0);
    editDetails()->page()->newGroupBox("");
    editDetails()->page()->newStackControl(3);
    editDetails()->page()->addComboBox(0, 0, 1, 1, "10", "00", "07"); // E.guitar select
    editDetails()->page()->addStackControl();
    editDetails()->page()->insertStackField(3, 1, 0, 1, 1);
    editDetails()->page()->addGroupBox(0, 0, 1, 4);
    editDetails()->page()->addStackField();


    // VINT JAZZ
    editDetails()->page()->newStackField(1);
    editDetails()->page()->newGroupBox("Fender Vintage Jazz");
    editDetails()->page()->addKnob(0, 0, 1, 1, "11", "00", "14");  //rear volume
    editDetails()->page()->addKnob(0, 1, 1, 1, "11", "00", "15");  //front volume
    editDetails()->page()->addKnob(0, 2, 1, 1, "11", "00", "16");  //volume
    editDetails()->page()->addKnob(0, 3, 1, 1, "11", "00", "17");  //tone
    editDetails()->page()->addGroupBox(0, 0, 1, 1);
    editDetails()->page()->newGroupBox("Noise Suppressor");
    editDetails()->page()->addSwitch(0, 0, 1, 1, "10", "00", "2B", "middle", Qt::AlignCenter); // NS sw
    editDetails()->page()->addKnob(0, 1, 1, 1, "10", "00", "2C");  //thresh
    editDetails()->page()->addKnob(0, 2, 1, 1, "10", "00", "2D");  //release
    editDetails()->page()->addGroupBox(0, 2, 1, 1);
    editDetails()->page()->addStackField();

    // JAZZ
    editDetails()->page()->newStackField(1);
    editDetails()->page()->newGroupBox("Fender Jazz");
    editDetails()->page()->addKnob(0, 0, 1, 1, "11", "00", "14");  //rear volume
    editDetails()->page()->addKnob(0, 1, 1, 1, "11", "00", "15");  //front volume
    editDetails()->page()->addKnob(0, 2, 1, 1, "11", "00", "16");  //volume
    editDetails()->page()->addKnob(0, 3, 1, 1, "11", "00", "17");  //tone
    editDetails()->page()->addGroupBox(0, 0, 1, 1);
    editDetails()->page()->newGroupBox("Noise Suppressor");
    editDetails()->page()->addSwitch(0, 0, 1, 1, "10", "00", "2B", "middle", Qt::AlignCenter); // NS sw
    editDetails()->page()->addKnob(0, 1, 1, 1, "10", "00", "2C");  //thresh
    editDetails()->page()->addKnob(0, 2, 1, 1, "10", "00", "2D");  //release
    editDetails()->page()->addGroupBox(0, 1, 1, 1);
    editDetails()->page()->addStackField();

    // VINT P BASS
    editDetails()->page()->newStackField(1);
    editDetails()->page()->newGroupBox("Fender Vintage Precision");
    editDetails()->page()->addKnob(0, 0, 1, 1, "11", "00", "16");  //volume
    editDetails()->page()->addKnob(0, 1, 1, 1, "11", "00", "17");  //tone
    editDetails()->page()->addGroupBox(0, 0, 1, 1);
    editDetails()->page()->newGroupBox("Noise Suppressor");
    editDetails()->page()->addSwitch(0, 0, 1, 1, "10", "00", "2B", "middle", Qt::AlignCenter); // NS sw
    editDetails()->page()->addKnob(0, 1, 1, 1, "10", "00", "2C");  //thresh
    editDetails()->page()->addKnob(0, 2, 1, 1, "10", "00", "2D");  //release
    editDetails()->page()->addGroupBox(0, 1, 1, 1);
    editDetails()->page()->addStackField();

    // P BASS
    editDetails()->page()->newStackField(1);
    editDetails()->page()->newGroupBox("Fender Precision");
    editDetails()->page()->addKnob(0, 0, 1, 1, "11", "00", "16");  //volume
    editDetails()->page()->addKnob(0, 1, 1, 1, "11", "00", "17");  //tone
    editDetails()->page()->addGroupBox(0, 0, 1, 1);
    editDetails()->page()->newGroupBox("Noise Suppressor");
    editDetails()->page()->addSwitch(0, 0, 1, 1, "10", "00", "2B", "middle", Qt::AlignCenter); // NS sw
    editDetails()->page()->addKnob(0, 1, 1, 1, "10", "00", "2C");  //thresh
    editDetails()->page()->addKnob(0, 2, 1, 1, "10", "00", "2D");  //release
    editDetails()->page()->addGroupBox(0, 1, 1, 1);
    editDetails()->page()->addStackField();

    // M Man
    editDetails()->page()->newStackField(1);
    editDetails()->page()->newGroupBox("Music Man");
    editDetails()->page()->addKnob(0, 0, 1, 1, "11", "00", "18");  //treble
    editDetails()->page()->addKnob(0, 1, 1, 1, "11", "00", "19");  //bass
    editDetails()->page()->addKnob(0, 2, 1, 1, "11", "00", "16");  //volume
    editDetails()->page()->addGroupBox(0, 0, 1, 1);
    editDetails()->page()->newGroupBox("Noise Suppressor");
    editDetails()->page()->addSwitch(0, 0, 1, 1, "10", "00", "2B", "middle", Qt::AlignCenter); // NS sw
    editDetails()->page()->addKnob(0, 1, 1, 1, "10", "00", "2C");  //thresh
    editDetails()->page()->addKnob(0, 2, 1, 1, "10", "00", "2D");  //release
    editDetails()->page()->addGroupBox(0, 1, 1, 1);
    editDetails()->page()->addStackField();

    // RICK
    editDetails()->page()->newStackField(1);
    editDetails()->page()->newGroupBox("Rickenbacker 4001");
    editDetails()->page()->addComboBox(0, 0, 1, 1, "11", "00", "1E"); //PU select
    editDetails()->page()->addKnob(0, 1, 1, 1, "11", "00", "14");  //rear volume
    editDetails()->page()->addKnob(0, 2, 1, 1, "11", "00", "15");  //front volume
    editDetails()->page()->addKnob(0, 3, 1, 1, "11", "00", "1C");  //rear tone
    editDetails()->page()->addKnob(0, 4, 1, 1, "11", "00", "1D");  //front tone
    editDetails()->page()->addKnob(0, 5, 1, 1, "11", "00", "16");  //volume
    editDetails()->page()->addGroupBox(0, 0, 1, 1);
    editDetails()->page()->newGroupBox("Noise Suppressor");
    editDetails()->page()->addSwitch(0, 0, 1, 1, "10", "00", "2B", "middle", Qt::AlignCenter); // NS sw
    editDetails()->page()->addKnob(0, 1, 1, 1, "10", "00", "2C");  //thresh
    editDetails()->page()->addKnob(0, 2, 1, 1, "10", "00", "2D");  //release
    editDetails()->page()->addGroupBox(0, 1, 1, 1);
    editDetails()->page()->addStackField();

    // T-Bird
    editDetails()->page()->newStackField(1);
    editDetails()->page()->newGroupBox("Gibson ThunderBird");
    editDetails()->page()->addKnob(0, 0, 1, 1, "11", "00", "14");  //rear volume
    editDetails()->page()->addKnob(0, 1, 1, 1, "11", "00", "15");  //front volume
    editDetails()->page()->addKnob(0, 2, 1, 1, "11", "00", "16");  //volume
    editDetails()->page()->addKnob(0, 3, 1, 1, "11", "00", "17");  //tone
    editDetails()->page()->addGroupBox(0, 0, 1, 1);
    editDetails()->page()->newGroupBox("Noise Suppressor");
    editDetails()->page()->addSwitch(0, 0, 1, 1, "10", "00", "2B", "middle", Qt::AlignCenter); // NS sw
    editDetails()->page()->addKnob(0, 1, 1, 1, "10", "00", "2C");  //thresh
    editDetails()->page()->addKnob(0, 2, 1, 1, "10", "00", "2D");  //release
    editDetails()->page()->addGroupBox(0, 1, 1, 1);
    editDetails()->page()->addStackField();

    // Active
    editDetails()->page()->newStackField(1);
    editDetails()->page()->newGroupBox("Active");
    editDetails()->page()->addKnob(0, 1, 1, 1, "11", "00", "14");  //rear volume
    editDetails()->page()->addKnob(0, 2, 1, 1, "11", "00", "15");  //front volume
    editDetails()->page()->addKnob(0, 3, 1, 1, "11", "00", "1C");  //treble
    editDetails()->page()->addKnob(0, 4, 1, 1, "11", "00", "1A");  //bass
    editDetails()->page()->addKnob(0, 5, 1, 1, "11", "00", "1B");  //volume
    editDetails()->page()->addGroupBox(0, 0, 1, 1);
    editDetails()->page()->newGroupBox("Noise Suppressor");
    editDetails()->page()->addSwitch(0, 0, 1, 1, "10", "00", "2B", "middle", Qt::AlignCenter); // NS sw
    editDetails()->page()->addKnob(0, 1, 1, 1, "10", "00", "2C");  //thresh
    editDetails()->page()->addKnob(0, 2, 1, 1, "10", "00", "2D");  //release
    editDetails()->page()->addGroupBox(0, 1, 1, 1);
    editDetails()->page()->addStackField();

    // Violin
    editDetails()->page()->newStackField(1);
    editDetails()->page()->newGroupBox("Hofner Violin");
    editDetails()->page()->addKnob(0, 0, 1, 1, "11", "00", "14");  //rear volume
    editDetails()->page()->addKnob(0, 1, 1, 1, "11", "00", "15");  //front volume
    editDetails()->page()->addKnob(0, 2, 1, 1, "11", "00", "16");  //volume
    editDetails()->page()->addSwitch(0, 3, 1, 1, "11", "00", "1F", "middle", Qt::AlignCenter); //rear ON
    editDetails()->page()->addSwitch(0, 4, 1, 1, "11", "00", "20", "middle", Qt::AlignCenter); //front ON
    editDetails()->page()->addSwitch(0, 5, 1, 1, "11", "00", "21", "middle", Qt::AlignCenter); //SOLO
    editDetails()->page()->addGroupBox(0, 0, 1, 1);
    editDetails()->page()->newGroupBox("Noise Suppressor");
    editDetails()->page()->addSwitch(0, 0, 1, 1, "10", "00", "2B", "middle", Qt::AlignCenter); // NS sw
    editDetails()->page()->addKnob(0, 1, 1, 1, "10", "00", "2C");  //thresh
    editDetails()->page()->addKnob(0, 2, 1, 1, "10", "00", "2D");  //release
    editDetails()->page()->addGroupBox(0, 1, 1, 1);
    editDetails()->page()->addStackField();



    // Analog GR
    editDetails()->page()->newStackField(2);
    editDetails()->page()->newGroupBox("Analog GR");
    editDetails()->page()->addComboBox(0, 0, 1, 1, "11", "00", "22"); //mode
    editDetails()->page()->addSwitch(0, 1, 1, 1, "11", "00", "23", "middle", Qt::AlignCenter); //comp
    editDetails()->page()->addKnob(1, 0, 1, 1, "11", "00", "24");  //filter cutoff
    editDetails()->page()->addKnob(1, 1, 1, 1, "11", "00", "25");  //filter reso
    editDetails()->page()->addGroupBox(0, 1, 1, 1);
    editDetails()->page()->newGroupBox("Envelope Modulation");
    editDetails()->page()->addComboBox(1, 0, 1, 2, "11", "00", "26"); //env mod sw
    editDetails()->page()->addKnob(0, 0, 1, 1, "11", "00", "27");  //env mod sens
    editDetails()->page()->addKnob(0, 1, 1, 1, "11", "00", "28");  //env mod attack
    editDetails()->page()->addGroupBox(0, 2, 1, 1);
    editDetails()->page()->newGroupBox("Pitch");
    editDetails()->page()->addKnob(0, 0, 1, 1, "11", "00", "2A");  //pitch A
    editDetails()->page()->addKnob(0, 1, 1, 1, "11", "00", "2B");  //pitch A fine
    editDetails()->page()->addKnob(0, 2, 1, 1, "11", "00", "2C");  //pitch B
    editDetails()->page()->addKnob(0, 3, 1, 1, "11", "00", "2D");  //pitch B fine
    editDetails()->page()->addKnob(0, 4, 1, 1, "11", "00", "30");  //pitch sweep rise
    editDetails()->page()->addKnob(0, 5, 1, 1, "11", "00", "31");  //pitch sweep fall
    editDetails()->page()->addComboBox(1, 0, 1, 2, "11", "00", "29"); //pitch sw
    editDetails()->page()->addSwitch(1, 2, 1, 2, "11", "00", "2E", "middle", Qt::AlignCenter); //duet
    editDetails()->page()->addSwitch(1, 4, 1, 2, "11", "00", "2F", "middle", Qt::AlignCenter); //pitch sweep
    editDetails()->page()->addGroupBox(0, 3, 1, 1);
    editDetails()->page()->newGroupBox("Vibrato");
    editDetails()->page()->addSwitch(1, 0, 1, 2, "11", "00", "32", "middle", Qt::AlignCenter); //vibrato sw
    editDetails()->page()->addKnob(0, 0, 1, 1, "11", "00", "33");  //vibrato rate
    editDetails()->page()->addKnob(0, 1, 1, 1, "11", "00", "34");  //vibrato depth
    editDetails()->page()->addGroupBox(0, 4, 1, 1);
    editDetails()->page()->addStackField();

    //wave synth
    editDetails()->page()->newStackField(2);
    editDetails()->page()->newGroupBox("Wave Synth");
    editDetails()->page()->addComboBox(0, 0, 1, 1, "11", "00", "35"); //type
    editDetails()->page()->addKnob(0, 1, 1, 1, "11", "00", "36");  //colour
    editDetails()->page()->addGroupBox(0, 0, 1, 1);
    editDetails()->page()->addStackField();

    // filter bass
    editDetails()->page()->newStackField(2);
    editDetails()->page()->newGroupBox("Filter Bass");
    editDetails()->page()->addKnob(0, 0, 1, 1, "11", "00", "37");  //filter cutoff
    editDetails()->page()->addKnob(0, 1, 1, 1, "11", "00", "38");  //filter reso
    editDetails()->page()->addKnob(0, 2, 1, 1, "11", "00", "39");  //filter decay
    editDetails()->page()->addKnob(0, 3, 1, 1, "11", "00", "3A");  //touch sens
    editDetails()->page()->addKnob(0, 4, 1, 1, "11", "00", "3B");  //colour
    editDetails()->page()->addGroupBox(0, 0, 1, 1);
    editDetails()->page()->addStackField();

    // crystal
    editDetails()->page()->newStackField(2);
    editDetails()->page()->newGroupBox("Crystal");
    editDetails()->page()->addKnob(0, 0, 1, 1, "11", "00", "3C");  //attack length
    editDetails()->page()->addKnob(0, 1, 1, 1, "11", "00", "3D");  //mod tune
    editDetails()->page()->addKnob(0, 2, 1, 1, "11", "00", "3E");  //mod depth
    editDetails()->page()->addKnob(0, 3, 1, 1, "11", "00", "3F");  //attack level
    editDetails()->page()->addKnob(0, 4, 1, 1, "11", "00", "40");  //body level
    editDetails()->page()->addKnob(0, 5, 1, 1, "11", "00", "41");  //sustain
    editDetails()->page()->addGroupBox(0, 0, 1, 1);
    editDetails()->page()->addStackField();

    // organ
    editDetails()->page()->newStackField(2);
    editDetails()->page()->newGroupBox("Organ");
    editDetails()->page()->addKnob(0, 0, 1, 1, "11", "00", "42");  //feet16
    editDetails()->page()->addKnob(0, 1, 1, 1, "11", "00", "43");  //feet8
    editDetails()->page()->addKnob(0, 2, 1, 1, "11", "00", "44");  //feet4
    editDetails()->page()->addKnob(0, 3, 1, 1, "11", "00", "45");  //sustain
    editDetails()->page()->addGroupBox(0, 0, 1, 1);
    editDetails()->page()->addStackField();

    // brass
    editDetails()->page()->newStackField(2);
    editDetails()->page()->newGroupBox("Brass");
    editDetails()->page()->addKnob(0, 0, 1, 1, "11", "00", "46");  //filter cutoff
    editDetails()->page()->addKnob(0, 1, 1, 1, "11", "00", "47");  //filter reso
    editDetails()->page()->addKnob(0, 2, 1, 1, "11", "00", "48");  //touch sens
    editDetails()->page()->addKnob(0, 3, 1, 1, "11", "00", "49");  //sustain
    editDetails()->page()->addGroupBox(0, 0, 1, 1);
    editDetails()->page()->addStackField();

    // STRAT
    editDetails()->page()->newStackField(3);
    editDetails()->page()->newGroupBox("Fender Stratocaster");
    editDetails()->page()->addComboBox(0, 0, 1, 1, "11", "00", "11"); //PU select
    editDetails()->page()->addKnob(0, 1, 1, 1, "11", "00", "12");  //volume
    editDetails()->page()->addKnob(0, 2, 1, 1, "11", "00", "13");  //tone
    editDetails()->page()->addGroupBox(0, 0, 1, 1);
    editDetails()->page()->newGroupBox("Noise Suppressor");
    editDetails()->page()->addSwitch(0, 0, 1, 1, "10", "00", "2B", "middle", Qt::AlignCenter); // NS sw
    editDetails()->page()->addKnob(0, 1, 1, 1, "10", "00", "2C");  //thresh
    editDetails()->page()->addKnob(0, 2, 1, 1, "10", "00", "2D");  //release
    editDetails()->page()->addGroupBox(0, 2, 1, 1);
    editDetails()->page()->addStackField();

    // LES PAUL
    editDetails()->page()->newStackField(3);
    editDetails()->page()->newGroupBox("Gibson Les Paul");
    editDetails()->page()->addComboBox(0, 0, 1, 1, "11", "00", "10"); //PU select
    editDetails()->page()->addKnob(0, 1, 1, 1, "11", "00", "12");  //volume
    editDetails()->page()->addKnob(0, 2, 1, 1, "11", "00", "13");  //tone
    editDetails()->page()->addGroupBox(0, 0, 1, 1);
    editDetails()->page()->newGroupBox("Noise Suppressor");
    editDetails()->page()->addSwitch(0, 0, 1, 1, "10", "00", "2B", "middle", Qt::AlignCenter); // NS sw
    editDetails()->page()->addKnob(0, 1, 1, 1, "10", "00", "2C");  //thresh
    editDetails()->page()->addKnob(0, 2, 1, 1, "10", "00", "2D");  //release
    editDetails()->page()->addGroupBox(0, 1, 1, 1);
    editDetails()->page()->addStackField();

    editDetails()->addPage();
}
