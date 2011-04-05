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

#include "menuPage_pdl.h"

menuPage_pdl::menuPage_pdl(QWidget *parent)
    : menuPage(parent)
{
    /* PDL */
    setLSB("00", "11");
    editDetails()->patchPos(56, 272, "00", "11"); //correct
    setEditPages();
};

void menuPage_pdl::updateSignal()
{

};

void menuPage_pdl::setEditPages()
{
    editDetails()->page()->newGroupBox("CTL Pedal");
    editDetails()->page()->addSwitch(0, 0, 1, 1, "00", "00", "11", "middle", Qt::AlignCenter);
    editDetails()->page()->newStackControl(0);
    editDetails()->page()->addComboBox(0, 1, 1, 1, "00", "00", "12");
    editDetails()->page()->addStackControl();
    editDetails()->page()->insertStackField(0, 1, 0, 1, 2);
    editDetails()->page()->addGroupBox(0, 0, 1, 1);

    editDetails()->page()->newStackField(0); //off
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(0);
    editDetails()->page()->addComboBox(0, 0, 1, 1, "00", "00", "13");
    editDetails()->page()->addComboBox(0, 1, 1, 1, "00", "00", "14");
    editDetails()->page()->addSwitch(0, 2, 1, 1, "00", "00", "15", "middle", Qt::AlignCenter);
    editDetails()->page()->addSwitch(0, 3, 1, 1, "00", "00", "16", "middle", Qt::AlignCenter);
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(0);  //tap tempo
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(0);
    editDetails()->page()->addLabel(0, 0, 1, 1, "'OFF' action");
    editDetails()->page()->addSwitch(0, 1, 1, 1, "00", "00", "17", "middle", Qt::AlignCenter);
    editDetails()->page()->addSwitch(0, 2, 1, 1, "00", "00", "18", "middle", Qt::AlignCenter);
    editDetails()->page()->addSwitch(0, 3, 1, 1, "00", "00", "19", "middle", Qt::AlignCenter);
    editDetails()->page()->addSwitch(0, 4, 1, 1, "00", "00", "1A", "middle", Qt::AlignCenter);
    editDetails()->page()->addLabel(1, 0, 1, 1, "'ON' action");
    editDetails()->page()->addSwitch(1, 1, 1, 1, "00", "00", "1B", "middle", Qt::AlignCenter);
    editDetails()->page()->addSwitch(1, 2, 1, 1, "00", "00", "1C", "middle", Qt::AlignCenter);
    editDetails()->page()->addSwitch(1, 3, 1, 1, "00", "00", "1D", "middle", Qt::AlignCenter);
    editDetails()->page()->addSwitch(1, 4, 1, 1, "00", "00", "1E", "middle", Qt::AlignCenter);
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(0);  editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(0);  editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(0);  editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(0);  editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(0);  editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(0);  editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(0);  editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(0);  editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(0);  editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(0);  editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(0);  editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(0);  editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(0);  editDetails()->page()->addStackField();



    editDetails()->page()->newGroupBox("EXP Pedal (while EXP Pedal Switch is 'OFF')");
    editDetails()->page()->newStackControl(1);
    editDetails()->page()->addComboBox(0, 0, 1, 1, "00", "00", "1F");
    editDetails()->page()->addStackControl();
    editDetails()->page()->insertStackField(1, 1, 0, 1, 2);
    editDetails()->page()->addGroupBox(1, 0, 1, 1);

    editDetails()->page()->newStackField(1); //off
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(1); //patch volume
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(1); //tone volume
    editDetails()->page()->addSwitch(0, 0, 1, 1, "00", "00", "20", "middle", Qt::AlignCenter);
    editDetails()->page()->addSwitch(0, 1, 1, 1, "00", "00", "21", "middle", Qt::AlignCenter);
    editDetails()->page()->addSwitch(0, 2, 1, 1, "00", "00", "22", "middle", Qt::AlignCenter);
    editDetails()->page()->addSwitch(0, 3, 1, 1, "00", "00", "23", "middle", Qt::AlignCenter);
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(1);  //pitch bend
    editDetails()->page()->addKnob(0, 0, 1, 1, "00", "00", "24");
    editDetails()->page()->addSwitch(0, 1, 1, 1, "00", "00", "25", "middle", Qt::AlignCenter);
    editDetails()->page()->addSwitch(0, 2, 1, 1, "00", "00", "26", "middle", Qt::AlignCenter);
    editDetails()->page()->addSwitch(0, 3, 1, 1, "00", "00", "27", "middle", Qt::AlignCenter);
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(1);  //modulation
    editDetails()->page()->addKnob(0, 0, 1, 1, "00", "00", "28");
    editDetails()->page()->addKnob(0, 1, 1, 1, "00", "00", "29");
    editDetails()->page()->addSwitch(0, 2, 1, 1, "00", "00", "2A", "middle", Qt::AlignCenter);
    editDetails()->page()->addSwitch(0, 3, 1, 1, "00", "00", "2B", "middle", Qt::AlignCenter);
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(1);  //cross fader
    editDetails()->page()->addKnob(0, 0, 1, 1, "00", "00", "2C");
    editDetails()->page()->addKnob(0, 1, 1, 1, "00", "00", "2D");
    editDetails()->page()->addKnob(0, 2, 1, 1, "00", "00", "2E");
    editDetails()->page()->addKnob(0, 3, 1, 1, "00", "00", "2F");
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(1);  //delay
    editDetails()->page()->addKnob(0, 0, 1, 1, "00", "00", "30");
    editDetails()->page()->addKnob(0, 1, 1, 1, "00", "00", "31");
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(1);  //reverb
    editDetails()->page()->addKnob(0, 0, 1, 1, "00", "00", "32");
    editDetails()->page()->addKnob(0, 1, 1, 1, "00", "00", "33");
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(1);  //chorus
    editDetails()->page()->addKnob(0, 0, 1, 1, "00", "00", "34");
    editDetails()->page()->addKnob(0, 1, 1, 1, "00", "00", "35");
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(1);  //mod control
    editDetails()->page()->addKnob(0, 0, 1, 1, "02", "00", "42");
    editDetails()->page()->addKnob(0, 1, 1, 1, "02", "00", "43");
    editDetails()->page()->addStackField();

    editDetails()->page()->newGroupBox("EXP Pedal (while EXP Pedal Switch is 'ON')");
    editDetails()->page()->newStackControl(2);
    editDetails()->page()->addComboBox(0, 0, 1, 1, "00", "00", "36");
    editDetails()->page()->addStackControl();
    editDetails()->page()->insertStackField(2, 1, 0, 1, 1);
    editDetails()->page()->addGroupBox(1, 1, 1, 1);

    editDetails()->page()->newStackField(2); //off
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(2); //patch volume
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(2); //tone volume
    editDetails()->page()->addSwitch(0, 0, 1, 1, "00", "00", "37", "middle", Qt::AlignCenter);
    editDetails()->page()->addSwitch(0, 1, 1, 1, "00", "00", "38", "middle", Qt::AlignCenter);
    editDetails()->page()->addSwitch(0, 2, 1, 1, "00", "00", "39", "middle", Qt::AlignCenter);
    editDetails()->page()->addSwitch(0, 3, 1, 1, "00", "00", "3A", "middle", Qt::AlignCenter);
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(2);  //pitch bend
    editDetails()->page()->addKnob(0, 0, 1, 1, "00", "00", "3B");
    editDetails()->page()->addSwitch(0, 1, 1, 1, "00", "00", "3C", "middle", Qt::AlignCenter);
    editDetails()->page()->addSwitch(0, 2, 1, 1, "00", "00", "3D", "middle", Qt::AlignCenter);
    editDetails()->page()->addSwitch(0, 3, 1, 1, "00", "00", "3E", "middle", Qt::AlignCenter);
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(2);  //modulation
    editDetails()->page()->addKnob(0, 0, 1, 1, "00", "00", "3F");
    editDetails()->page()->addKnob(0, 1, 1, 1, "00", "00", "40");
    editDetails()->page()->addSwitch(0, 2, 1, 1, "00", "00", "41", "middle", Qt::AlignCenter);
    editDetails()->page()->addSwitch(0, 3, 1, 1, "00", "00", "42", "middle", Qt::AlignCenter);
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(2);  //cross fader
    editDetails()->page()->addKnob(0, 0, 1, 1, "00", "00", "43");
    editDetails()->page()->addKnob(0, 1, 1, 1, "00", "00", "44");
    editDetails()->page()->addKnob(0, 2, 1, 1, "00", "00", "45");
    editDetails()->page()->addKnob(0, 3, 1, 1, "00", "00", "46");
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(2);  //delay
    editDetails()->page()->addKnob(0, 0, 1, 1, "00", "00", "47");
    editDetails()->page()->addKnob(0, 1, 1, 1, "00", "00", "48");
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(2);  //reverb
    editDetails()->page()->addKnob(0, 0, 1, 1, "00", "00", "49");
    editDetails()->page()->addKnob(0, 1, 1, 1, "00", "00", "4A");
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(2);  //chorus
    editDetails()->page()->addKnob(0, 0, 1, 1, "00", "00", "4B");
    editDetails()->page()->addKnob(0, 1, 1, 1, "00", "00", "4C");
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(2);  //mod control
    editDetails()->page()->addKnob(0, 0, 1, 1, "02", "00", "44");
    editDetails()->page()->addKnob(0, 1, 1, 1, "02", "00", "45");
    editDetails()->page()->addStackField();


    editDetails()->page()->newGroupBox("EXP Pedal SWITCH");
    editDetails()->page()->addSwitch(0, 0, 1, 1, "00", "00", "4D", "middle", Qt::AlignCenter);
    editDetails()->page()->newStackControl(3);
    editDetails()->page()->addComboBox(0, 1, 1, 1, "00", "00", "4E");
    editDetails()->page()->addStackControl();
    editDetails()->page()->insertStackField(3, 1, 0, 1, 2);
    editDetails()->page()->addGroupBox(0, 1, 1, 1);

    editDetails()->page()->newStackField(3); //off
    editDetails()->page()->addStackField();


    editDetails()->page()->newStackField(3);  //tap tempo
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(3); // tone sw
    editDetails()->page()->addLabel(0, 0, 1, 1, "'OFF' action");
    editDetails()->page()->addSwitch(0, 1, 1, 1, "00", "00", "53", "middle", Qt::AlignCenter);
    editDetails()->page()->addSwitch(0, 2, 1, 1, "00", "00", "54", "middle", Qt::AlignCenter);
    editDetails()->page()->addSwitch(0, 3, 1, 1, "00", "00", "55", "middle", Qt::AlignCenter);
    editDetails()->page()->addSwitch(0, 4, 1, 1, "00", "00", "56", "middle", Qt::AlignCenter);
    editDetails()->page()->addLabel(1, 0, 1, 1, "'ON' action");
    editDetails()->page()->addSwitch(1, 1, 1, 1, "00", "00", "57", "middle", Qt::AlignCenter);
    editDetails()->page()->addSwitch(1, 2, 1, 1, "00", "00", "58", "middle", Qt::AlignCenter);
    editDetails()->page()->addSwitch(1, 3, 1, 1, "00", "00", "59", "middle", Qt::AlignCenter);
    editDetails()->page()->addSwitch(1, 4, 1, 1, "00", "00", "5A", "middle", Qt::AlignCenter);
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(3);  editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(3);  editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(3);  editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(3);  editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(3);  editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(3);  editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(3);  editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(3);  editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(3);  editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(3);  editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(3);  editDetails()->page()->addStackField();


    editDetails()->page()->newGroupBox("GK SWITCH 1");
    editDetails()->page()->newStackControl(4);
    editDetails()->page()->addComboBox(0, 0, 1, 1, "00", "00", "72");
    editDetails()->page()->addStackControl();
    editDetails()->page()->insertStackField(4, 1, 0, 1, 1);
    editDetails()->page()->addGroupBox(2, 0, 1, 1);

    editDetails()->page()->newStackField(4); //off
    editDetails()->page()->addStackField();


    editDetails()->page()->newStackField(4);  //tap tempo
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(4); // tone sw
    editDetails()->page()->addLabel(0, 0, 1, 1, "'OFF' action");
    editDetails()->page()->addSwitch(0, 1, 1, 1, "00", "00", "77", "middle", Qt::AlignCenter);
    editDetails()->page()->addSwitch(0, 2, 1, 1, "00", "00", "78", "middle", Qt::AlignCenter);
    editDetails()->page()->addSwitch(0, 3, 1, 1, "00", "00", "79", "middle", Qt::AlignCenter);
    editDetails()->page()->addSwitch(0, 4, 1, 1, "00", "00", "7A", "middle", Qt::AlignCenter);
    editDetails()->page()->addLabel(1, 0, 1, 1, "'ON' action");
    editDetails()->page()->addSwitch(1, 1, 1, 1, "00", "00", "7B", "middle", Qt::AlignCenter);
    editDetails()->page()->addSwitch(1, 2, 1, 1, "00", "00", "7C", "middle", Qt::AlignCenter);
    editDetails()->page()->addSwitch(1, 3, 1, 1, "00", "00", "7D", "middle", Qt::AlignCenter);
    editDetails()->page()->addSwitch(1, 4, 1, 1, "00", "00", "7E", "middle", Qt::AlignCenter);
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(4);  editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(4);  editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(4);  editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(4);  editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(4);  editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(4);  editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(4);  editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(4);  editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(4);  editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(4);  editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(4);  editDetails()->page()->addStackField();

    editDetails()->page()->newGroupBox("GK SWITCH 2");
    editDetails()->page()->newStackControl(5);
    editDetails()->page()->addComboBox(0, 0, 1, 1, "00", "00", "7F");
    editDetails()->page()->addStackControl();
    editDetails()->page()->insertStackField(5, 1, 0, 1, 1);
    editDetails()->page()->addGroupBox(2, 1, 1, 1);

    editDetails()->page()->newStackField(5); //off
    editDetails()->page()->addStackField();


    editDetails()->page()->newStackField(5);  //tap tempo
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(5); // tone sw
    editDetails()->page()->addLabel(0, 0, 1, 1, "'OFF' action");
    editDetails()->page()->addSwitch(0, 1, 1, 1, "01", "00", "04", "middle", Qt::AlignCenter);
    editDetails()->page()->addSwitch(0, 2, 1, 1, "01", "00", "05", "middle", Qt::AlignCenter);
    editDetails()->page()->addSwitch(0, 3, 1, 1, "01", "00", "06", "middle", Qt::AlignCenter);
    editDetails()->page()->addSwitch(0, 4, 1, 1, "01", "00", "07", "middle", Qt::AlignCenter);
    editDetails()->page()->addLabel(1, 0, 1, 1, "'ON' action");
    editDetails()->page()->addSwitch(1, 1, 1, 1, "01", "00", "08", "middle", Qt::AlignCenter);
    editDetails()->page()->addSwitch(1, 2, 1, 1, "01", "00", "09", "middle", Qt::AlignCenter);
    editDetails()->page()->addSwitch(1, 3, 1, 1, "01", "00", "0A", "middle", Qt::AlignCenter);
    editDetails()->page()->addSwitch(1, 4, 1, 1, "01", "00", "0B", "middle", Qt::AlignCenter);
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(5);  editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(5);  editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(5);  editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(5);  editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(5);  editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(5);  editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(5);  editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(5);  editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(5);  editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(5);  editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(5);  editDetails()->page()->addStackField();

    editDetails()->page()->newGroupBox("GK Volume");
    editDetails()->page()->newStackControl(6);
    editDetails()->page()->addComboBox(0, 0, 1, 1, "00", "00", "5B");
    editDetails()->page()->addStackControl();
    editDetails()->page()->insertStackField(6, 1, 0, 1, 2);
    editDetails()->page()->addGroupBox(0, 2, 3, 1);

    editDetails()->page()->newStackField(6); //off
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(6); //patch volume
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(6); //tone volume
    editDetails()->page()->addSwitch(0, 0, 1, 1, "00", "00", "5C", "middle", Qt::AlignCenter);
    editDetails()->page()->addSwitch(1, 0, 1, 1, "00", "00", "5D", "middle", Qt::AlignCenter);
    editDetails()->page()->addSwitch(2, 0, 1, 1, "00", "00", "5E", "middle", Qt::AlignCenter);
    editDetails()->page()->addSwitch(3, 0, 1, 1, "00", "00", "5F", "middle", Qt::AlignCenter);
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(6);  //pitch bend
    editDetails()->page()->addKnob(0, 0, 1, 1, "00", "00", "60");
    editDetails()->page()->addSwitch(1, 0, 1, 1, "00", "00", "61", "middle", Qt::AlignCenter);
    editDetails()->page()->addSwitch(2, 0, 1, 1, "00", "00", "62", "middle", Qt::AlignCenter);
    editDetails()->page()->addSwitch(3, 0, 1, 1, "00", "00", "63", "middle", Qt::AlignCenter);
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(6);  //modulation
    editDetails()->page()->addKnob(0, 0, 1, 1, "00", "00", "64");
    editDetails()->page()->addKnob(1, 0, 1, 1, "00", "00", "65");
    editDetails()->page()->addSwitch(2, 0, 1, 1, "00", "00", "66", "middle", Qt::AlignCenter);
    editDetails()->page()->addSwitch(3, 0, 1, 1, "00", "00", "67", "middle", Qt::AlignCenter);
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(6);  //cross fader
    editDetails()->page()->addKnob(0, 0, 1, 1, "00", "00", "68");
    editDetails()->page()->addKnob(1, 0, 1, 1, "00", "00", "69");
    editDetails()->page()->addKnob(2, 0, 1, 1, "00", "00", "6A");
    editDetails()->page()->addKnob(3, 0, 1, 1, "00", "00", "6B");
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(6);  //delay
    editDetails()->page()->addKnob(0, 0, 1, 1, "00", "00", "6C");
    editDetails()->page()->addKnob(1, 0, 1, 1, "00", "00", "6D");
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(6);  //reverb
    editDetails()->page()->addKnob(0, 0, 1, 1, "00", "00", "6E");
    editDetails()->page()->addKnob(1, 0, 1, 1, "00", "00", "6F");
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(6);  //chorus
    editDetails()->page()->addKnob(0, 0, 1, 1, "00", "00", "70");
    editDetails()->page()->addKnob(1, 0, 1, 1, "00", "00", "71");
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(6);  //mod control
    editDetails()->page()->addKnob(0, 0, 1, 1, "02", "00", "46");
    editDetails()->page()->addKnob(1, 0, 1, 1, "02", "00", "47");
    editDetails()->page()->addStackField();

    editDetails()->addPage();
};
