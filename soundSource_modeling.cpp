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

#include "soundSource_modeling.h"

soundsource_modeling::soundsource_modeling(QWidget *parent)
    : soundSource(parent)
{
    /* MODELING */
    this->setImage(":/images/modeling.png");
    setLSB("10", "00");
    setSwitch("10", "INVERT", "0A");
    setComboBox("02", "routeSwitch", "2D");
    setKnob1("10", "00", "00");
    setKnob2("10", "00", "09");
    //editDetails()->patchPos(400, 58, "01", "30");
    setEditPages();
};

void soundsource_modeling::updateSignal()
{
    updateSwitch("10", "00", "0A");
    updateComboBox("02", "routeSwitch", "2D");
    updateKnob1("10", "00", "00");
    updateKnob2("10", "00", "09");
};

void soundsource_modeling::setEditPages()
{
    editDetails()->page()->newGroupBox("Modeling");
    editDetails()->page()->addSwitch(0, 0, 1, 1, "10", "00", "0A", "invert", Qt::AlignCenter);
     editDetails()->page()->addComboBox(0, 1, 1, 1, "02", "00", "2D"); //route switch
    editDetails()->page()->newStackControl(0);
    editDetails()->page()->addComboBox(0, 2, 1, 1, "10", "00", "00"); // guitar select
    editDetails()->page()->addStackControl();  
    editDetails()->page()->addKnob(0, 3, 1, 1, "10", "00", "09");  //level
    editDetails()->page()->addGroupBox(0, 0, 1, 1);
    editDetails()->page()->newGroupBox("Pitch");
    editDetails()->page()->addKnob(0, 0, 1, 1, "10", "00", "11");  //pitch
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
    editDetails()->page()->addComboBox(0, 0, 1, 1, "10", "00", "01"); // guitar select
    editDetails()->page()->addStackControl();
    editDetails()->page()->insertStackField(1, 1, 0, 1, 1);
    editDetails()->page()->addGroupBox(0, 0, 1, 4);
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(0);
    editDetails()->page()->newGroupBox("");
    editDetails()->page()->newStackControl(2);
    editDetails()->page()->addComboBox(0, 0, 1, 1, "10", "00", "02"); // acoustic select
    editDetails()->page()->addStackControl();
    editDetails()->page()->insertStackField(2, 1, 0, 1, 1);
    editDetails()->page()->addGroupBox(0, 0, 1, 4);
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(0);
    editDetails()->page()->newGroupBox("");
    editDetails()->page()->newStackControl(3);
    editDetails()->page()->addComboBox(0, 0, 1, 1, "10", "00", "03"); // E.bass select
    editDetails()->page()->addStackControl();
    editDetails()->page()->insertStackField(3, 1, 0, 1, 1);
    editDetails()->page()->addGroupBox(0, 0, 1, 4);
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(0);
    editDetails()->page()->newGroupBox("");
     editDetails()->page()->newStackControl(4);
    editDetails()->page()->addComboBox(0, 0, 1, 1, "10", "00", "04"); // synth select
    editDetails()->page()->addStackControl();
    editDetails()->page()->insertStackField(4, 1, 0, 1, 1);
    editDetails()->page()->addGroupBox(0, 0, 1, 4);
    editDetails()->page()->addStackField();

    // CLA ST
    editDetails()->page()->newStackField(1);
    editDetails()->page()->newGroupBox("Fender Classic Strat");
    editDetails()->page()->addComboBox(0, 0, 1, 1, "10", "00", "2F"); //PU select
    editDetails()->page()->addKnob(0, 1, 1, 1, "10", "00", "31");  //volume
    editDetails()->page()->addKnob(0, 2, 1, 1, "10", "00", "32");  //tone
    editDetails()->page()->addGroupBox(0, 0, 1, 1);
    editDetails()->page()->newGroupBox("Noise Suppressor");
    editDetails()->page()->addSwitch(0, 0, 1, 1, "10", "00", "2B", "middle", Qt::AlignCenter); // NS sw
    editDetails()->page()->addKnob(0, 1, 1, 1, "10", "00", "2C");  //thresh
    editDetails()->page()->addKnob(0, 2, 1, 1, "10", "00", "2D");  //release
    editDetails()->page()->addGroupBox(0, 2, 1, 1);
    editDetails()->page()->addStackField();

    // MOD ST
    editDetails()->page()->newStackField(1);
    editDetails()->page()->newGroupBox("Fender Modern Strat");
    editDetails()->page()->addComboBox(0, 0, 1, 1, "10", "00", "2F"); //PU select
    editDetails()->page()->addKnob(0, 1, 1, 1, "10", "00", "31");  //volume
    editDetails()->page()->addKnob(0, 2, 1, 1, "10", "00", "32");  //tone
    editDetails()->page()->addGroupBox(0, 0, 1, 1);
    editDetails()->page()->newGroupBox("Noise Suppressor");
    editDetails()->page()->addSwitch(0, 0, 1, 1, "10", "00", "2B", "middle", Qt::AlignCenter); // NS sw
    editDetails()->page()->addKnob(0, 1, 1, 1, "10", "00", "2C");  //thresh
    editDetails()->page()->addKnob(0, 2, 1, 1, "10", "00", "2D");  //release
    editDetails()->page()->addGroupBox(0, 1, 1, 1);
    editDetails()->page()->addStackField();

    // H+H ST
    editDetails()->page()->newStackField(1);
    editDetails()->page()->newGroupBox("Fender Humbucker Strat");
    editDetails()->page()->addComboBox(0, 0, 1, 1, "10", "00", "2E"); //PU select
    editDetails()->page()->addKnob(0, 1, 1, 1, "10", "00", "31");  //volume
    editDetails()->page()->addKnob(0, 2, 1, 1, "10", "00", "32");  //tone
    editDetails()->page()->addGroupBox(0, 0, 1, 1);
    editDetails()->page()->newGroupBox("Noise Suppressor");
    editDetails()->page()->addSwitch(0, 0, 1, 1, "10", "00", "2B", "middle", Qt::AlignCenter); // NS sw
    editDetails()->page()->addKnob(0, 1, 1, 1, "10", "00", "2C");  //thresh
    editDetails()->page()->addKnob(0, 2, 1, 1, "10", "00", "2D");  //release
    editDetails()->page()->addGroupBox(0, 1, 1, 1);
    editDetails()->page()->addStackField();

    // TELE
    editDetails()->page()->newStackField(1);
    editDetails()->page()->newGroupBox("Fender Telecaster");
    editDetails()->page()->addComboBox(0, 0, 1, 1, "10", "00", "2E"); //PU select
    editDetails()->page()->addKnob(0, 1, 1, 1, "10", "00", "31");  //volume
    editDetails()->page()->addKnob(0, 2, 1, 1, "10", "00", "32");  //tone
    editDetails()->page()->addGroupBox(0, 0, 1, 1);
    editDetails()->page()->newGroupBox("Noise Suppressor");
    editDetails()->page()->addSwitch(0, 0, 1, 1, "10", "00", "2B", "middle", Qt::AlignCenter); // NS sw
    editDetails()->page()->addKnob(0, 1, 1, 1, "10", "00", "2C");  //thresh
    editDetails()->page()->addKnob(0, 2, 1, 1, "10", "00", "2D");  //release
    editDetails()->page()->addGroupBox(0, 1, 1, 1);
    editDetails()->page()->addStackField();

    // LP
    editDetails()->page()->newStackField(1);
    editDetails()->page()->newGroupBox("Gibson Les Paul");
    editDetails()->page()->addComboBox(0, 0, 1, 1, "10", "00", "2E"); //PU select
    editDetails()->page()->addKnob(0, 1, 1, 1, "10", "00", "31");  //volume
    editDetails()->page()->addKnob(0, 2, 1, 1, "10", "00", "32");  //tone
    editDetails()->page()->addGroupBox(0, 0, 1, 1);
    editDetails()->page()->newGroupBox("Noise Suppressor");
    editDetails()->page()->addSwitch(0, 0, 1, 1, "10", "00", "2B", "middle", Qt::AlignCenter); // NS sw
    editDetails()->page()->addKnob(0, 1, 1, 1, "10", "00", "2C");  //thresh
    editDetails()->page()->addKnob(0, 2, 1, 1, "10", "00", "2D");  //release
    editDetails()->page()->addGroupBox(0, 1, 1, 1);
    editDetails()->page()->addStackField();

    // P90
    editDetails()->page()->newStackField(1);
    editDetails()->page()->newGroupBox("Gibson Les Paul P90");
    editDetails()->page()->addComboBox(0, 0, 1, 1, "10", "00", "2E"); //PU select
    editDetails()->page()->addKnob(0, 1, 1, 1, "10", "00", "31");  //volume
    editDetails()->page()->addKnob(0, 2, 1, 1, "10", "00", "32");  //tone
    editDetails()->page()->addGroupBox(0, 0, 1, 1);
    editDetails()->page()->newGroupBox("Noise Suppressor");
    editDetails()->page()->addSwitch(0, 0, 1, 1, "10", "00", "2B", "middle", Qt::AlignCenter); // NS sw
    editDetails()->page()->addKnob(0, 1, 1, 1, "10", "00", "2C");  //thresh
    editDetails()->page()->addKnob(0, 2, 1, 1, "10", "00", "2D");  //release
    editDetails()->page()->addGroupBox(0, 1, 1, 1);
    editDetails()->page()->addStackField();

    // LIPS
    editDetails()->page()->newStackField(1);
    editDetails()->page()->newGroupBox("Danelectro 56-U3");
    editDetails()->page()->addComboBox(0, 0, 1, 1, "10", "00", "30"); //PU select
    editDetails()->page()->addKnob(0, 1, 1, 1, "10", "00", "31");  //volume
    editDetails()->page()->addKnob(0, 2, 1, 1, "10", "00", "32");  //tone
    editDetails()->page()->addGroupBox(0, 0, 1, 1);
    editDetails()->page()->newGroupBox("Noise Suppressor");
    editDetails()->page()->addSwitch(0, 0, 1, 1, "10", "00", "2B", "middle", Qt::AlignCenter); // NS sw
    editDetails()->page()->addKnob(0, 1, 1, 1, "10", "00", "2C");  //thresh
    editDetails()->page()->addKnob(0, 2, 1, 1, "10", "00", "2D");  //release
    editDetails()->page()->addGroupBox(0, 1, 1, 1);
    editDetails()->page()->addStackField();

    // RICK
    editDetails()->page()->newStackField(1);
    editDetails()->page()->newGroupBox("Rickenbacker 360");
    editDetails()->page()->addComboBox(0, 0, 1, 1, "10", "00", "2E"); //PU select
    editDetails()->page()->addKnob(0, 1, 1, 1, "10", "00", "31");  //volume
    editDetails()->page()->addKnob(0, 2, 1, 1, "10", "00", "32");  //tone
    editDetails()->page()->addGroupBox(0, 0, 1, 1);
    editDetails()->page()->newGroupBox("Noise Suppressor");
    editDetails()->page()->addSwitch(0, 0, 1, 1, "10", "00", "2B", "middle", Qt::AlignCenter); // NS sw
    editDetails()->page()->addKnob(0, 1, 1, 1, "10", "00", "2C");  //thresh
    editDetails()->page()->addKnob(0, 2, 1, 1, "10", "00", "2D");  //release
    editDetails()->page()->addGroupBox(0, 1, 1, 1);
    editDetails()->page()->addStackField();

    // 335
    editDetails()->page()->newStackField(1);
    editDetails()->page()->newGroupBox("Gibson ES-335");
    editDetails()->page()->addComboBox(0, 0, 1, 1, "10", "00", "2E"); //PU select
    editDetails()->page()->addKnob(0, 1, 1, 1, "10", "00", "31");  //volume
    editDetails()->page()->addKnob(0, 2, 1, 1, "10", "00", "32");  //tone
    editDetails()->page()->addGroupBox(0, 0, 1, 1);
    editDetails()->page()->newGroupBox("Noise Suppressor");
    editDetails()->page()->addSwitch(0, 0, 1, 1, "10", "00", "2B", "middle", Qt::AlignCenter); // NS sw
    editDetails()->page()->addKnob(0, 1, 1, 1, "10", "00", "2C");  //thresh
    editDetails()->page()->addKnob(0, 2, 1, 1, "10", "00", "2D");  //release
    editDetails()->page()->addGroupBox(0, 1, 1, 1);
    editDetails()->page()->addStackField();

    // L4
    editDetails()->page()->newStackField(1);
    editDetails()->page()->newGroupBox("Gibson L4-CES");
    editDetails()->page()->addComboBox(0, 0, 1, 1, "10", "00", "2E"); //PU select
    editDetails()->page()->addKnob(0, 1, 1, 1, "10", "00", "31");  //volume
    editDetails()->page()->addKnob(0, 2, 1, 1, "10", "00", "32");  //tone
    editDetails()->page()->addGroupBox(0, 0, 1, 1);
    editDetails()->page()->newGroupBox("Noise Suppressor");
    editDetails()->page()->addSwitch(0, 0, 1, 1, "10", "00", "2B", "middle", Qt::AlignCenter); // NS sw
    editDetails()->page()->addKnob(0, 1, 1, 1, "10", "00", "2C");  //thresh
    editDetails()->page()->addKnob(0, 2, 1, 1, "10", "00", "2D");  //release
    editDetails()->page()->addGroupBox(0, 1, 1, 1);
    editDetails()->page()->addStackField();

    // STEEL
    editDetails()->page()->newStackField(2);
    editDetails()->page()->newGroupBox("Acoustic Steel");
    editDetails()->page()->addComboBox(0, 0, 1, 1, "10", "00", "33"); //PU select
    editDetails()->page()->addKnob(0, 1, 1, 1, "10", "00", "34");  //body
    editDetails()->page()->addKnob(0, 2, 1, 1, "10", "00", "35");  //tone - steel
    editDetails()->page()->addGroupBox(0, 0, 1, 1);
    editDetails()->page()->newGroupBox("Noise Suppressor");
    editDetails()->page()->addSwitch(0, 0, 1, 1, "10", "00", "2B", "middle", Qt::AlignCenter); // NS sw
    editDetails()->page()->addKnob(0, 1, 1, 1, "10", "00", "2C");  //thresh
    editDetails()->page()->addKnob(0, 2, 1, 1, "10", "00", "2D");  //release
    editDetails()->page()->addGroupBox(0, 1, 1, 1);
    editDetails()->page()->addStackField();

    // NYLON
    editDetails()->page()->newStackField(2);
    editDetails()->page()->newGroupBox("Acoustic Nylon");
    editDetails()->page()->addKnob(0, 0, 1, 1, "10", "00", "36");  //body
    editDetails()->page()->addKnob(0, 1, 1, 1, "10", "00", "37");  //attack
    editDetails()->page()->addKnob(0, 2, 1, 1, "10", "00", "38");  //tone
    editDetails()->page()->addGroupBox(0, 0, 1, 1);
    editDetails()->page()->addStackField();

    // Sitar
    editDetails()->page()->newStackField(2);
    editDetails()->page()->newGroupBox("Sitar");
    editDetails()->page()->addComboBox(0, 0, 1, 1, "10", "00", "39"); //PU select
    editDetails()->page()->addKnob(0, 1, 1, 1, "10", "00", "3A");  //sens
    editDetails()->page()->addKnob(0, 2, 1, 1, "10", "00", "3B");  //body
    editDetails()->page()->addKnob(0, 3, 1, 1, "10", "00", "3C");   //color
    editDetails()->page()->addKnob(0, 4, 1, 1, "10", "00", "3D");   //decay
    editDetails()->page()->addKnob(0, 5, 1, 1, "10", "00", "3E");   //buzz
    editDetails()->page()->addKnob(0, 6, 1, 1, "10", "00", "3F");   //attack level
    editDetails()->page()->addGroupBox(0, 0, 1, 1);
    editDetails()->page()->addStackField();

    // Banjo
    editDetails()->page()->newStackField(2);
    editDetails()->page()->newGroupBox("Banjo");
    editDetails()->page()->addKnob(0, 0, 1, 1, "10", "00", "41");  //attack
    editDetails()->page()->addKnob(0, 1, 1, 1, "10", "00", "42");  //reso
    editDetails()->page()->addKnob(0, 2, 1, 1, "10", "00", "43");  //tone
    editDetails()->page()->addGroupBox(0, 0, 1, 1);
    editDetails()->page()->newGroupBox("Noise Suppressor");
    editDetails()->page()->addSwitch(0, 0, 1, 1, "10", "00", "2B", "middle", Qt::AlignCenter); // NS sw
    editDetails()->page()->addKnob(0, 1, 1, 1, "10", "00", "2C");  //thresh
    editDetails()->page()->addKnob(0, 2, 1, 1, "10", "00", "2D");  //release
    editDetails()->page()->addGroupBox(0, 1, 1, 1);
    editDetails()->page()->addStackField();

    // Reso
    editDetails()->page()->newStackField(2);
    editDetails()->page()->newGroupBox("dobro Resonator");
    editDetails()->page()->addKnob(0, 0, 1, 1, "10", "00", "34");  //sustain
    editDetails()->page()->addKnob(0, 1, 1, 1, "10", "00", "35");  //reso
    editDetails()->page()->addKnob(0, 2, 1, 1, "10", "00", "36");  //tone
    editDetails()->page()->addGroupBox(0, 0, 1, 1);
    editDetails()->page()->newGroupBox("Noise Suppressor");
    editDetails()->page()->addSwitch(0, 0, 1, 1, "10", "00", "2B", "middle", Qt::AlignCenter); // NS sw
    editDetails()->page()->addKnob(0, 1, 1, 1, "10", "00", "2C");  //thresh
    editDetails()->page()->addKnob(0, 2, 1, 1, "10", "00", "2D");  //release
    editDetails()->page()->addGroupBox(0, 1, 1, 1);
    editDetails()->page()->addStackField();

    // Jazz Bass
    editDetails()->page()->newStackField(3);
    editDetails()->page()->newGroupBox("Fender Jazz Bass");
    editDetails()->page()->addKnob(0, 0, 1, 1, "10", "00", "47");  //front Vol
    editDetails()->page()->addKnob(0, 1, 1, 1, "10", "00", "48");  //rear Vol
    editDetails()->page()->addKnob(0, 2, 1, 1, "10", "00", "49");  //Volume
    editDetails()->page()->addKnob(0, 3, 1, 1, "10", "00", "4A");  //Tone
    editDetails()->page()->addGroupBox(0, 0, 1, 1);
    editDetails()->page()->newGroupBox("Noise Suppressor");
    editDetails()->page()->addSwitch(0, 0, 1, 1, "10", "00", "2B", "middle", Qt::AlignCenter); // NS sw
    editDetails()->page()->addKnob(0, 1, 1, 1, "10", "00", "2C");  //thresh
    editDetails()->page()->addKnob(0, 2, 1, 1, "10", "00", "2D");  //release
    editDetails()->page()->addGroupBox(0, 1, 1, 1);
    editDetails()->page()->addStackField();

    // P Bass
    editDetails()->page()->newStackField(3);
    editDetails()->page()->newGroupBox("Fender P Bass");
    editDetails()->page()->addKnob(0, 0, 1, 1, "10", "00", "49");  //volume
    editDetails()->page()->addKnob(0, 1, 1, 1, "10", "00", "4A");  //tone
    editDetails()->page()->addGroupBox(0, 0, 1, 1);
    editDetails()->page()->newGroupBox("Noise Suppressor");
    editDetails()->page()->addSwitch(0, 0, 1, 1, "10", "00", "2B", "middle", Qt::AlignCenter); // NS sw
    editDetails()->page()->addKnob(0, 1, 1, 1, "10", "00", "2C");  //thresh
    editDetails()->page()->addKnob(0, 2, 1, 1, "10", "00", "2D");  //release
    editDetails()->page()->addGroupBox(0, 1, 1, 1);
    editDetails()->page()->addStackField();

    // Analog GR
    editDetails()->page()->newStackField(4);
    editDetails()->page()->newGroupBox("Analog GR");
    editDetails()->page()->addComboBox(0, 0, 1, 1, "10", "00", "4B"); //mode
    editDetails()->page()->addSwitch(1, 0, 1, 1, "10", "00", "4C", "middle", Qt::AlignCenter); //comp
    editDetails()->page()->addGroupBox(0, 0, 1, 1);
    editDetails()->page()->newGroupBox("Filter");
    editDetails()->page()->addKnob(0, 0, 1, 1, "10", "00", "4D");  //filter cutoff
    editDetails()->page()->addKnob(1, 0, 1, 1, "10", "00", "4E");  //filter reso
    editDetails()->page()->addGroupBox(0, 1, 1, 1);
    editDetails()->page()->newGroupBox("Envelope");
    editDetails()->page()->addComboBox(0, 0, 1, 1, "10", "00", "4F"); //env mod sw
    editDetails()->page()->addKnob(0, 1, 1, 1, "10", "00", "50");  //env mod sens
    editDetails()->page()->addKnob(1, 1, 1, 1, "10", "00", "51");  //env mod attack
    editDetails()->page()->addGroupBox(0, 2, 1, 1);
    editDetails()->page()->newGroupBox("Pitch");
    editDetails()->page()->addComboBox(0, 0, 1, 1, "10", "00", "52"); //pitch sw
    editDetails()->page()->addKnob(0, 1, 1, 1, "10", "00", "53");  //pitch A
    editDetails()->page()->addKnob(1, 1, 1, 1, "10", "00", "54");  //pitch A fine
    editDetails()->page()->addKnob(0, 2, 1, 1, "10", "00", "55");  //pitch B
    editDetails()->page()->addKnob(1, 2, 1, 1, "10", "00", "56");  //pitch B fine
    editDetails()->page()->addSwitch(0, 3, 1, 1, "10", "00", "57", "middle", Qt::AlignCenter); //duet
    editDetails()->page()->addSwitch(1, 3, 1, 1, "10", "00", "58", "middle", Qt::AlignCenter); //pitch sweep
    editDetails()->page()->addKnob(0, 4, 1, 1, "10", "00", "59");  //pitch sweep rise
    editDetails()->page()->addKnob(1, 4, 1, 1, "10", "00", "5A");  //pitch sweep fall
    editDetails()->page()->addGroupBox(0, 3, 1, 1);
    editDetails()->page()->newGroupBox("Vibrato");
    editDetails()->page()->addSwitch(0, 0, 1, 1, "10", "00", "5B", "middle", Qt::AlignCenter); //vibrato sw
    editDetails()->page()->addKnob(0, 1, 1, 1, "10", "00", "5C");  //vibrato rate
    editDetails()->page()->addKnob(1, 1, 1, 1, "10", "00", "5D");  //vibrato depth
    editDetails()->page()->addGroupBox(0, 4, 1, 1);
    editDetails()->page()->addStackField();

    //wave synth
    editDetails()->page()->newStackField(4);
    editDetails()->page()->newGroupBox("Wave Synth");
    editDetails()->page()->addComboBox(0, 0, 1, 1, "10", "00", "5E"); //type
    editDetails()->page()->addKnob(0, 1, 1, 1, "10", "00", "5F");  //colour
    editDetails()->page()->addGroupBox(0, 0, 1, 1);
    editDetails()->page()->addStackField();

    // filter bass
    editDetails()->page()->newStackField(4);
    editDetails()->page()->newGroupBox("Filter Bass");
    editDetails()->page()->addKnob(0, 0, 1, 1, "10", "00", "60");  //filter cutoff
    editDetails()->page()->addKnob(0, 1, 1, 1, "10", "00", "61");  //filter reso
    editDetails()->page()->addKnob(0, 2, 1, 1, "10", "00", "62");  //filter decay
    editDetails()->page()->addKnob(0, 3, 1, 1, "10", "00", "63");  //touch sens
    editDetails()->page()->addKnob(0, 4, 1, 1, "10", "00", "64");  //colour
    editDetails()->page()->addGroupBox(0, 0, 1, 1);
    editDetails()->page()->addStackField();

    // crystal
    editDetails()->page()->newStackField(4);
    editDetails()->page()->newGroupBox("Crystal");
    editDetails()->page()->addKnob(0, 0, 1, 1, "10", "00", "65");  //attack length
    editDetails()->page()->addKnob(0, 1, 1, 1, "10", "00", "66");  //mod tune
    editDetails()->page()->addKnob(0, 2, 1, 1, "10", "00", "67");  //mod depth
    editDetails()->page()->addKnob(0, 3, 1, 1, "10", "00", "68");  //attack level
    editDetails()->page()->addKnob(0, 4, 1, 1, "10", "00", "69");  //body level
    editDetails()->page()->addKnob(0, 5, 1, 1, "10", "00", "6A");  //sustain
    editDetails()->page()->addGroupBox(0, 0, 1, 1);
    editDetails()->page()->addStackField();

    // organ
    editDetails()->page()->newStackField(4);
    editDetails()->page()->newGroupBox("Organ");
    editDetails()->page()->addKnob(0, 0, 1, 1, "10", "00", "6B");  //feet16
    editDetails()->page()->addKnob(0, 1, 1, 1, "10", "00", "6C");  //feet8
    editDetails()->page()->addKnob(0, 2, 1, 1, "10", "00", "6D");  //feet4
    editDetails()->page()->addKnob(0, 3, 1, 1, "10", "00", "6E");  //sustain
    editDetails()->page()->addGroupBox(0, 0, 1, 1);
    editDetails()->page()->addStackField();

    // brass
    editDetails()->page()->newStackField(4);
    editDetails()->page()->newGroupBox("Brass");
    editDetails()->page()->addKnob(0, 0, 1, 1, "10", "00", "6F");  //filter cutoff
    editDetails()->page()->addKnob(0, 1, 1, 1, "10", "00", "70");  //filter reso
    editDetails()->page()->addKnob(0, 2, 1, 1, "10", "00", "71");  //touch sens
    editDetails()->page()->addKnob(0, 3, 1, 1, "10", "00", "72");  //sustain
    editDetails()->page()->addGroupBox(0, 0, 1, 1);
    editDetails()->page()->addStackField();

    editDetails()->addPage();
};
