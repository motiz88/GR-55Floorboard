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
    editDetails()->page()->addLabel(0, 0, 1, 1, text);
    editDetails()->page()->newGroupBox("settings");

    editDetails()->page()->newGroupBox("Patch");
    editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "00", "System", "right", 300); //current patch
    editDetails()->page()->addGroupBox(0, 0, 1, 3);

    editDetails()->page()->newGroupBox("Output");
    editDetails()->page()->addComboBox(0, 0, 1, 1, "02", "00", "01", "System",  Qt::AlignCenter); // output select
    editDetails()->page()->addComboBox(0, 1, 1, 1, "02", "00", "16", "System"); // guitar out source
    editDetails()->page()->addGroupBox(0, 3, 1, 2);

    editDetails()->page()->newGroupBox("Mode on next Startup");
    editDetails()->page()->addComboBox(0, 0, 1, 1, "02", "00", "1A", "System",  Qt::AlignCenter); // Mode select
    //editDetails()->page()->addComboBox(0, 1, 1, 1, "02", "00", "19", "System",  Qt::AlignCenter); // test
    editDetails()->page()->addGroupBox(0, 5, 1, 1);

    editDetails()->page()->newGroupBox("Tuner");
    editDetails()->page()->addComboBox(0, 0, 1, 1, "02", "00", "17", "System"); //master tune
    editDetails()->page()->addComboBox(0, 1, 1, 1, "02", "00", "18", "System"); //tuner mute


    editDetails()->page()->addGroupBox(1, 0, 1, 2);

    editDetails()->page()->newGroupBox("USB Audio");
    editDetails()->page()->addKnob(0, 0, 1, 1, "02", "00", "1D", "System");     //USB input level
    editDetails()->page()->addKnob(0, 1, 1, 1, "02", "00", "1F", "System");     //USB output level
    editDetails()->page()->addComboBox(0, 2, 1, 1, "02", "00", "15", "System"); // monitor direct
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "00", "1B", "System");     //player level
    editDetails()->page()->addGroupBox(1, 3, 1, 4);

    editDetails()->page()->newGroupBox("General Midi");
    editDetails()->page()->addComboBox(0, 0, 1, 1, "02", "00", "03", "System"); // midi patch channel
    editDetails()->page()->addComboBox(0, 1, 1, 1, "02", "00", "06", "System"); // VLINK TX Channel
    editDetails()->page()->addComboBox(0, 2, 1, 1, "02", "00", "12", "System"); //midi map
    editDetails()->page()->addComboBox(1, 0, 1, 1, "02", "00", "04", "System"); // PC RX Sw
    editDetails()->page()->addComboBox(1, 1, 1, 1, "02", "00", "05", "System"); // PC TX Sw
    editDetails()->page()->addComboBox(1, 2, 1, 1, "02", "00", "02", "System"); // Assign Hold
    editDetails()->page()->addGroupBox(2, 0, 1, 3);

    editDetails()->page()->newGroupBox("Guitar > Midi Output");
    editDetails()->page()->addComboBox(0, 0, 1, 1, "02", "00", "07", "System"); // guitar midi out
    editDetails()->page()->addComboBox(0, 1, 1, 1, "02", "00", "08", "System"); // poly mode
    editDetails()->page()->addComboBox(0, 2, 1, 1, "02", "00", "0E", "System"); // EXP PDL Bend range
    editDetails()->page()->addComboBox(1, 0, 1, 1, "02", "00", "09", "System"); // chromatic
    editDetails()->page()->addComboBox(1, 1, 1, 1, "02", "00", "0A", "System"); // string channel
    editDetails()->page()->addComboBox(1, 2, 1, 1, "02", "00", "0B", "System"); // data thin
    editDetails()->page()->addGroupBox(2, 3, 1, 3);

    editDetails()->page()->newGroupBox("Pedal Control Data Output");
    editDetails()->page()->addComboBox(0, 0, 1, 1, "02", "00", "0C", "System"); // CTL cc#
    editDetails()->page()->addComboBox(0, 1, 1, 1, "02", "00", "0D", "System"); // EXP cc#
    editDetails()->page()->addComboBox(0, 2, 1, 1, "02", "00", "0F", "System"); //GK VOL cc#
    editDetails()->page()->addComboBox(0, 3, 1, 1, "02", "00", "10", "System"); //GK S1 cc#
    editDetails()->page()->addComboBox(0, 4, 1, 1, "02", "00", "11", "System"); //GK S2 cc#
    editDetails()->page()->addGroupBox(3, 0, 1, 6);

    editDetails()->page()->addGroupBox(1, 0, 1, 1);
    editDetails()->addPage("00", "00", "17", "00", "Tables");


    editDetails()->page()->addLabel(0, 0, 1, 2, text);
    editDetails()->page()->newGroupBox("CTL Pedal");
    editDetails()->page()->newStackControl(0);
    editDetails()->page()->addComboBox(0, 1, 1, 1, "02", "02", "00", "System");
    editDetails()->page()->addStackControl();
    editDetails()->page()->insertStackField(0, 1, 0, 1, 2);
    editDetails()->page()->addGroupBox(1, 0, 1, 1);

    editDetails()->page()->newStackField(0); //off
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(0); //patch setting
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(0);
    editDetails()->page()->addComboBox(0, 0, 1, 1, "02", "02", "01", "System");  //hold
    editDetails()->page()->addComboBox(0, 1, 1, 1, "02", "02", "02", "System");
    editDetails()->page()->addSwitch(0, 2, 1, 1, "02", "02", "03", "System", Qt::AlignCenter);
    editDetails()->page()->addSwitch(0, 3, 1, 1, "02", "02", "04", "System", Qt::AlignCenter);
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(0);  //tap tempo
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(0);
    editDetails()->page()->addLabel(0, 0, 1, 1, "'OFF' action");
    editDetails()->page()->addSwitch(0, 1, 1, 1, "02", "02", "05", "System", Qt::AlignCenter);
    editDetails()->page()->addSwitch(0, 2, 1, 1, "02", "02", "06", "System", Qt::AlignCenter);
    editDetails()->page()->addSwitch(0, 3, 1, 1, "02", "02", "07", "System", Qt::AlignCenter);
    editDetails()->page()->addSwitch(0, 4, 1, 1, "02", "02", "08", "System", Qt::AlignCenter);
    editDetails()->page()->addLabel(1, 0, 1, 1, "'ON' action");
    editDetails()->page()->addSwitch(1, 1, 1, 1, "02", "02", "09", "System", Qt::AlignCenter);
    editDetails()->page()->addSwitch(1, 2, 1, 1, "02", "02", "0A", "System", Qt::AlignCenter);
    editDetails()->page()->addSwitch(1, 3, 1, 1, "02", "02", "0B", "System", Qt::AlignCenter);
    editDetails()->page()->addSwitch(1, 4, 1, 1, "02", "02", "0C", "System", Qt::AlignCenter);
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
    editDetails()->page()->newStackField(0);  editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(0);  editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(0);  editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(0);  editDetails()->page()->addStackField();



    editDetails()->page()->newGroupBox("EXP Pedal (while EXP Pedal Switch is 'OFF')");
    editDetails()->page()->newStackControl(1);
    editDetails()->page()->addComboBox(0, 0, 1, 1, "02", "02", "0D", "System");
    editDetails()->page()->addStackControl();
    editDetails()->page()->insertStackField(1, 1, 0, 1, 2);
    editDetails()->page()->addGroupBox(2, 0, 1, 1);

    editDetails()->page()->newStackField(1); //off
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(1); //patch setting
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(1); //patch volume
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(1); //tone volume
    editDetails()->page()->addSwitch(0, 0, 1, 1, "02", "02", "0E", "System", Qt::AlignCenter);
    editDetails()->page()->addSwitch(0, 1, 1, 1, "02", "02", "0F", "System", Qt::AlignCenter);
    editDetails()->page()->addSwitch(0, 2, 1, 1, "02", "02", "10", "System", Qt::AlignCenter);
    editDetails()->page()->addSwitch(0, 3, 1, 1, "02", "02", "11", "System", Qt::AlignCenter);
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(1);  //pitch bend
    editDetails()->page()->addKnob(0, 0, 1, 1, "02", "02", "12", "System");
    editDetails()->page()->addSwitch(0, 1, 1, 1, "02", "02", "13", "System", Qt::AlignCenter);
    editDetails()->page()->addSwitch(0, 2, 1, 1, "02", "02", "14", "System", Qt::AlignCenter);
    editDetails()->page()->addSwitch(0, 3, 1, 1, "02", "02", "15", "System", Qt::AlignCenter);
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(1);  //modulation
    editDetails()->page()->addKnob(0, 0, 1, 1, "02", "02", "16", "System");
    editDetails()->page()->addKnob(0, 1, 1, 1, "02", "02", "17", "System");
    editDetails()->page()->addSwitch(0, 2, 1, 1, "02", "02", "18", "System", Qt::AlignCenter);
    editDetails()->page()->addSwitch(0, 3, 1, 1, "02", "02", "19", "System", Qt::AlignCenter);
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(1);  //cross fader
    editDetails()->page()->addKnob(0, 0, 1, 1, "02", "02", "1A", "System");
    editDetails()->page()->addKnob(0, 1, 1, 1, "02", "02", "1B", "System");
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "02", "1C", "System");
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "02", "1D", "System");
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(1);  //delay
    editDetails()->page()->addKnob(0, 0, 1, 1, "02", "02", "1E", "System");
    editDetails()->page()->addKnob(0, 1, 1, 1, "02", "02", "1F", "System");
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(1);  //reverb
    editDetails()->page()->addKnob(0, 0, 1, 1, "02", "02", "20", "System");
    editDetails()->page()->addKnob(0, 1, 1, 1, "02", "02", "21", "System");
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(1);  //chorus
    editDetails()->page()->addKnob(0, 0, 1, 1, "02", "02", "22", "System");
    editDetails()->page()->addKnob(0, 1, 1, 1, "02", "02", "23", "System");
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(1);  //mod control
    editDetails()->page()->addKnob(0, 0, 1, 1, "02", "02", "79", "System");
    editDetails()->page()->addKnob(0, 1, 1, 1, "02", "02", "7A", "System");
    editDetails()->page()->addStackField();

    editDetails()->page()->newGroupBox("EXP Pedal (while EXP Pedal Switch is 'ON')");
    editDetails()->page()->newStackControl(2);
    editDetails()->page()->addComboBox(0, 0, 1, 1, "02", "02", "24", "System");
    editDetails()->page()->addStackControl();
    editDetails()->page()->insertStackField(2, 1, 0, 1, 1);
    editDetails()->page()->addGroupBox(2, 1, 1, 1);

    editDetails()->page()->newStackField(2); //off
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(2); //patch setting
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(2); //patch volume
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(2); //tone volume
    editDetails()->page()->addSwitch(0, 0, 1, 1, "02", "02", "25", "System", Qt::AlignCenter);
    editDetails()->page()->addSwitch(0, 1, 1, 1, "02", "02", "26", "System", Qt::AlignCenter);
    editDetails()->page()->addSwitch(0, 2, 1, 1, "02", "02", "27", "System", Qt::AlignCenter);
    editDetails()->page()->addSwitch(0, 3, 1, 1, "02", "02", "28", "System", Qt::AlignCenter);
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(2);  //pitch bend
    editDetails()->page()->addKnob(0, 0, 1, 1, "02", "02", "29", "System");
    editDetails()->page()->addSwitch(0, 1, 1, 1, "02", "02", "2A", "System", Qt::AlignCenter);
    editDetails()->page()->addSwitch(0, 2, 1, 1, "02", "02", "2B", "System", Qt::AlignCenter);
    editDetails()->page()->addSwitch(0, 3, 1, 1, "02", "02", "2C", "System", Qt::AlignCenter);
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(2);  //modulation
    editDetails()->page()->addKnob(0, 0, 1, 1, "02", "02", "2D", "System");
    editDetails()->page()->addKnob(0, 1, 1, 1, "02", "02", "2E", "System");
    editDetails()->page()->addSwitch(0, 2, 1, 1, "02", "02", "2F", "System", Qt::AlignCenter);
    editDetails()->page()->addSwitch(0, 3, 1, 1, "02", "02", "30", "System", Qt::AlignCenter);
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(2);  //cross fader
    editDetails()->page()->addKnob(0, 0, 1, 1, "02", "02", "31", "System");
    editDetails()->page()->addKnob(0, 1, 1, 1, "02", "02", "32", "System");
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "02", "33", "System");
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "02", "34", "System");
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(2);  //delay
    editDetails()->page()->addKnob(0, 0, 1, 1, "02", "02", "35", "System");
    editDetails()->page()->addKnob(0, 1, 1, 1, "02", "02", "36", "System");
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(2);  //reverb
    editDetails()->page()->addKnob(0, 0, 1, 1, "02", "02", "37", "System");
    editDetails()->page()->addKnob(0, 1, 1, 1, "02", "02", "38", "System");
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(2);  //chorus
    editDetails()->page()->addKnob(0, 0, 1, 1, "02", "02", "39", "System");
    editDetails()->page()->addKnob(0, 1, 1, 1, "02", "02", "3A", "System");
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(2);  //mod control
    editDetails()->page()->addKnob(0, 0, 1, 1, "02", "02", "7B", "System");
    editDetails()->page()->addKnob(0, 1, 1, 1, "02", "02", "7C", "System");
    editDetails()->page()->addStackField();


    editDetails()->page()->newGroupBox("EXP Pedal SWITCH");
    editDetails()->page()->newStackControl(3);
    editDetails()->page()->addComboBox(0, 1, 1, 1, "02", "02", "3B", "System");
    editDetails()->page()->addStackControl();
    editDetails()->page()->insertStackField(3, 1, 0, 1, 2);
    editDetails()->page()->addGroupBox(1, 1, 1, 1);

    editDetails()->page()->newStackField(3); //off
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(3); //patch setting
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(3);  //tap tempo
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(3); // tone sw
    editDetails()->page()->addLabel(0, 0, 1, 1, "'OFF' action");
    editDetails()->page()->addSwitch(0, 1, 1, 1, "02", "02", "40", "System", Qt::AlignCenter);
    editDetails()->page()->addSwitch(0, 2, 1, 1, "02", "02", "41", "System", Qt::AlignCenter);
    editDetails()->page()->addSwitch(0, 3, 1, 1, "02", "02", "42", "System", Qt::AlignCenter);
    editDetails()->page()->addSwitch(0, 4, 1, 1, "02", "02", "43", "System", Qt::AlignCenter);
    editDetails()->page()->addLabel(1, 0, 1, 1, "'ON' action");
    editDetails()->page()->addSwitch(1, 1, 1, 1, "02", "02", "44", "System", Qt::AlignCenter);
    editDetails()->page()->addSwitch(1, 2, 1, 1, "02", "02", "45", "System", Qt::AlignCenter);
    editDetails()->page()->addSwitch(1, 3, 1, 1, "02", "02", "46", "System", Qt::AlignCenter);
    editDetails()->page()->addSwitch(1, 4, 1, 1, "02", "02", "47", "System", Qt::AlignCenter);
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
    editDetails()->page()->newStackField(3);  editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(3);  editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(3);  editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(3);  editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(3);  editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(3);  editDetails()->page()->addStackField();


    editDetails()->page()->newGroupBox("GK SWITCH 1");
    editDetails()->page()->newStackControl(4);
    editDetails()->page()->addComboBox(0, 0, 1, 1, "02", "02", "5F", "System");
    editDetails()->page()->addStackControl();
    editDetails()->page()->insertStackField(4, 1, 0, 1, 1);
    editDetails()->page()->addGroupBox(3, 0, 1, 1);

    editDetails()->page()->newStackField(4); //off
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(4); //patch setting
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(4);  //tap tempo
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(4); // tone sw
    editDetails()->page()->addLabel(0, 0, 1, 1, "'OFF' action");
    editDetails()->page()->addSwitch(0, 1, 1, 1, "02", "02", "64", "System", Qt::AlignCenter);
    editDetails()->page()->addSwitch(0, 2, 1, 1, "02", "02", "65", "System", Qt::AlignCenter);
    editDetails()->page()->addSwitch(0, 3, 1, 1, "02", "02", "66", "System", Qt::AlignCenter);
    editDetails()->page()->addSwitch(0, 4, 1, 1, "02", "02", "67", "System", Qt::AlignCenter);
    editDetails()->page()->addLabel(1, 0, 1, 1, "'ON' action");
    editDetails()->page()->addSwitch(1, 1, 1, 1, "02", "02", "68", "System", Qt::AlignCenter);
    editDetails()->page()->addSwitch(1, 2, 1, 1, "02", "02", "69", "System", Qt::AlignCenter);
    editDetails()->page()->addSwitch(1, 3, 1, 1, "02", "02", "6A", "System", Qt::AlignCenter);
    editDetails()->page()->addSwitch(1, 4, 1, 1, "02", "02", "6B", "System", Qt::AlignCenter);
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
    editDetails()->page()->newStackField(4);  editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(4);  editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(4);  editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(4);  editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(4);  editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(4);  editDetails()->page()->addStackField();

    editDetails()->page()->newGroupBox("GK SWITCH 2");
    editDetails()->page()->newStackControl(5);
    editDetails()->page()->addComboBox(0, 0, 1, 1, "02", "02", "6C", "System");
    editDetails()->page()->addStackControl();
    editDetails()->page()->insertStackField(5, 1, 0, 1, 1);
    editDetails()->page()->addGroupBox(3, 1, 1, 1);

    editDetails()->page()->newStackField(5); //off
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(5); //patch setting
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(5);  //tap tempo
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(5); // tone sw
    editDetails()->page()->addLabel(0, 0, 1, 1, "'OFF' action");
    editDetails()->page()->addSwitch(0, 1, 1, 1, "02", "02", "71", "System", Qt::AlignCenter);
    editDetails()->page()->addSwitch(0, 2, 1, 1, "02", "02", "72", "System", Qt::AlignCenter);
    editDetails()->page()->addSwitch(0, 3, 1, 1, "02", "02", "73", "System", Qt::AlignCenter);
    editDetails()->page()->addSwitch(0, 4, 1, 1, "02", "02", "74", "System", Qt::AlignCenter);
    editDetails()->page()->addLabel(1, 0, 1, 1, "'ON' action");
    editDetails()->page()->addSwitch(1, 1, 1, 1, "02", "02", "75", "System", Qt::AlignCenter);
    editDetails()->page()->addSwitch(1, 2, 1, 1, "02", "02", "76", "System", Qt::AlignCenter);
    editDetails()->page()->addSwitch(1, 3, 1, 1, "02", "02", "77", "System", Qt::AlignCenter);
    editDetails()->page()->addSwitch(1, 4, 1, 1, "02", "02", "78", "System", Qt::AlignCenter);
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
    editDetails()->page()->newStackField(5);  editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(5);  editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(5);  editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(5);  editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(5);  editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(5);  editDetails()->page()->addStackField();

    editDetails()->page()->newGroupBox("GK Volume");
    editDetails()->page()->newStackControl(6);
    editDetails()->page()->addComboBox(0, 0, 1, 1, "02", "02", "48", "System");
    editDetails()->page()->addStackControl();
    editDetails()->page()->insertStackField(6, 1, 0, 1, 2);
    editDetails()->page()->addGroupBox(1, 2, 3, 1);

    editDetails()->page()->newStackField(6); //off
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(6); //patch setting
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(6); //patch volume
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(6); //tone volume
    editDetails()->page()->addSwitch(0, 0, 1, 1, "02", "02", "49", "System", Qt::AlignCenter);
    editDetails()->page()->addSwitch(1, 0, 1, 1, "02", "02", "4A", "System", Qt::AlignCenter);
    editDetails()->page()->addSwitch(2, 0, 1, 1, "02", "02", "4B", "System", Qt::AlignCenter);
    editDetails()->page()->addSwitch(3, 0, 1, 1, "02", "02", "4C", "System", Qt::AlignCenter);
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(6);  //pitch bend
    editDetails()->page()->addKnob(0, 0, 1, 1, "02", "02", "4D", "System");
    editDetails()->page()->addSwitch(1, 0, 1, 1, "02", "02", "4E", "System", Qt::AlignCenter);
    editDetails()->page()->addSwitch(2, 0, 1, 1, "02", "02", "4F", "System", Qt::AlignCenter);
    editDetails()->page()->addSwitch(3, 0, 1, 1, "02", "02", "50", "System", Qt::AlignCenter);
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(6);  //modulation
    editDetails()->page()->addKnob(0, 0, 1, 1, "02", "02", "51", "System");
    editDetails()->page()->addKnob(1, 0, 1, 1, "02", "02", "52", "System");
    editDetails()->page()->addSwitch(2, 0, 1, 1, "02", "02", "53", "System", Qt::AlignCenter);
    editDetails()->page()->addSwitch(3, 0, 1, 1, "02", "02", "54", "System", Qt::AlignCenter);
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(6);  //cross fader
    editDetails()->page()->addKnob(0, 0, 1, 1, "02", "02", "55", "System");
    editDetails()->page()->addKnob(1, 0, 1, 1, "02", "02", "56", "System");
    editDetails()->page()->addKnob(2, 0, 1, 1, "02", "02", "57", "System");
    editDetails()->page()->addKnob(3, 0, 1, 1, "02", "02", "58", "System");
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(6);  //delay
    editDetails()->page()->addKnob(0, 0, 1, 1, "02", "02", "59", "System");
    editDetails()->page()->addKnob(1, 0, 1, 1, "02", "02", "5A", "System");
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(6);  //reverb
    editDetails()->page()->addKnob(0, 0, 1, 1, "02", "02", "5B", "System");
    editDetails()->page()->addKnob(1, 0, 1, 1, "02", "02", "5C", "System");
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(6);  //chorus
    editDetails()->page()->addKnob(0, 0, 1, 1, "02", "02", "5D", "System");
    editDetails()->page()->addKnob(1, 0, 1, 1, "02", "02", "5E", "System");
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(6);  //mod control
    editDetails()->page()->addKnob(0, 0, 1, 1, "02", "02", "7D", "System");
    editDetails()->page()->addKnob(1, 0, 1, 1, "02", "02", "7E", "System");
    editDetails()->page()->addStackField();

    editDetails()->addPage("00", "00", "17", "01", "Tables");


    editDetails()->page()->addLabel(0, 0, 1, 1, text);
    editDetails()->page()->newGroupBox("Guitar Mode - GK setup");
    editDetails()->page()->newStackControl(0);
    editDetails()->page()->addComboBox(0, 0, 1, 1, "02", "00", "00", "System"); //guitar mode GK Set
    editDetails()->page()->addStackControl();
    editDetails()->page()->insertStackField(0, 1, 0, 1, 4);
    editDetails()->page()->addGroupBox(1, 0, 1, 1);

    editDetails()->page()->newStackField(0);
    editDetails()->page()->addNameEdit(0, 0, 1, 1, "02", "04", "00", "System", "8"); //GK catagory #1
    editDetails()->page()->newStackControl(1);
    editDetails()->page()->addComboBox(0, 1, 1, 1, "02", "04", "08", "System"); // PU select
    editDetails()->page()->addStackControl();
    editDetails()->page()->insertStackField(1, 0, 2, 1, 2);
    editDetails()->page()->addDataKnob(0, 4, 1, 1, "02", "04", "09", "SCALE", "right", 120);     //scale
    editDetails()->page()->addComboBox(0, 5, 1, 1, "02", "04", "0B", "System"); // pu phase
    editDetails()->page()->addComboBox(0, 6, 1, 1, "02", "04", "0C", "System"); // pu direction
    editDetails()->page()->addComboBox(0, 7, 1, 1, "02", "04", "0D", "System"); // s1/s2 position
    editDetails()->page()->newGroupBox("String distance bridge <> PU [mm]");
    editDetails()->page()->addKnob(0, 0, 1, 1, "02", "04", "11", "System"); // string distance 1
    editDetails()->page()->addKnob(0, 1, 1, 1, "02", "04", "12", "System"); // string distance 2
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "04", "13", "System"); // string distance 3
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "04", "14", "System"); // string distance 4
    editDetails()->page()->addKnob(0, 4, 1, 1, "02", "04", "15", "System"); // string distance 5
    editDetails()->page()->addKnob(0, 5, 1, 1, "02", "04", "16", "System"); // string distance 6
    editDetails()->page()->addGroupBox(1, 0, 1, 4);
    editDetails()->page()->newGroupBox("String sensitivity");
    editDetails()->page()->addKnob(0, 0, 1, 1, "02", "04", "17", "System"); // string sense 1
    editDetails()->page()->addKnob(0, 1, 1, 1, "02", "04", "18", "System"); // string sense 2
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "04", "19", "System"); // string sense 3
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "04", "1A", "System"); // string sense 4
    editDetails()->page()->addKnob(0, 4, 1, 1, "02", "04", "1B", "System"); // string sense 5
    editDetails()->page()->addKnob(0, 5, 1, 1, "02", "04", "1C", "System"); // string sense 6
    editDetails()->page()->addGroupBox(1, 4, 1, 4);
    editDetails()->page()->addKnob(2, 0, 1, 1, "02", "04", "1D", "System"); // play feel
    editDetails()->page()->addKnob(2, 1, 1, 1, "02", "04", "1E", "System"); // low velo cut
    editDetails()->page()->addKnob(2, 2, 1, 1, "02", "04", "1F", "System"); // velocity dynamics
    editDetails()->page()->addKnob(2, 3, 1, 1, "02", "04", "20", "System"); // nuance dynamics
    editDetails()->page()->addKnob(2, 4, 1, 1, "02", "04", "21", "System"); // nuance trim
    editDetails()->page()->addKnob(2, 5, 1, 1, "02", "04", "22", "System"); // down shift
    editDetails()->page()->addKnob(2, 6, 1, 1, "02", "04", "0E", "System"); // normal pu gain
    editDetails()->page()->addKnob(2, 7, 1, 1, "02", "04", "51", "System"); // DevelopLowCut
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(0);
    editDetails()->page()->addNameEdit(0, 0, 1, 1, "02", "05", "00", "System", "8"); //GK catagory #2
    editDetails()->page()->newStackControl(2);
    editDetails()->page()->addComboBox(0, 1, 1, 1, "02", "05", "08", "System"); // PU select
    editDetails()->page()->addStackControl();
    editDetails()->page()->insertStackField(2, 0, 2, 1, 2);
    editDetails()->page()->addDataKnob(0, 4, 1, 1, "02", "05", "09", "SCALE", "right", 120);     //scale
    editDetails()->page()->addComboBox(0, 5, 1, 1, "02", "05", "0B", "System"); // pu phase
    editDetails()->page()->addComboBox(0, 6, 1, 1, "02", "05", "0C", "System"); // pu direction
    editDetails()->page()->addComboBox(0, 7, 1, 1, "02", "05", "0D", "System"); // s1/s2 position
    editDetails()->page()->newGroupBox("String distance bridge <> PU [mm]");
    editDetails()->page()->addKnob(0, 0, 1, 1, "02", "05", "11", "System"); // string distance 1
    editDetails()->page()->addKnob(0, 1, 1, 1, "02", "05", "12", "System"); // string distance 2
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "05", "13", "System"); // string distance 3
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "05", "14", "System"); // string distance 4
    editDetails()->page()->addKnob(0, 4, 1, 1, "02", "05", "15", "System"); // string distance 5
    editDetails()->page()->addKnob(0, 5, 1, 1, "02", "05", "16", "System"); // string distance 6
    editDetails()->page()->addGroupBox(1, 0, 1, 4);
    editDetails()->page()->newGroupBox("String sensitivity");
    editDetails()->page()->addKnob(0, 0, 1, 1, "02", "05", "17", "System"); // string sense 1
    editDetails()->page()->addKnob(0, 1, 1, 1, "02", "05", "18", "System"); // string sense 2
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "05", "19", "System"); // string sense 3
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "05", "1A", "System"); // string sense 4
    editDetails()->page()->addKnob(0, 4, 1, 1, "02", "05", "1B", "System"); // string sense 5
    editDetails()->page()->addKnob(0, 5, 1, 1, "02", "05", "1C", "System"); // string sense 6
    editDetails()->page()->addGroupBox(1, 4, 1, 4);
    editDetails()->page()->addKnob(2, 0, 1, 1, "02", "05", "1D", "System"); // play feel
    editDetails()->page()->addKnob(2, 1, 1, 1, "02", "05", "1E", "System"); // low velo cut
    editDetails()->page()->addKnob(2, 2, 1, 1, "02", "05", "1F", "System"); // velocity dynamics
    editDetails()->page()->addKnob(2, 3, 1, 1, "02", "05", "20", "System"); // nuance dynamics
    editDetails()->page()->addKnob(2, 4, 1, 1, "02", "05", "21", "System"); // nuance trim
    editDetails()->page()->addKnob(2, 5, 1, 1, "02", "05", "22", "System"); // down shift
    editDetails()->page()->addKnob(2, 6, 1, 1, "02", "05", "0E", "System"); // normal pu gain
    editDetails()->page()->addKnob(2, 7, 1, 1, "02", "05", "51", "System"); // DevelopLowCut
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(0);
    editDetails()->page()->addNameEdit(0, 0, 1, 1, "02", "06", "00", "System", "8"); //GK catagory #3
    editDetails()->page()->newStackControl(3);
    editDetails()->page()->addComboBox(0, 1, 1, 1, "02", "06", "08", "System"); // PU select
    editDetails()->page()->addStackControl();
    editDetails()->page()->insertStackField(3, 0, 2, 1, 2);
    editDetails()->page()->addDataKnob(0, 4, 1, 1, "02", "06", "09", "SCALE", "right", 120);     //scale
    editDetails()->page()->addComboBox(0, 5, 1, 1, "02", "06", "0B", "System"); // pu phase
    editDetails()->page()->addComboBox(0, 6, 1, 1, "02", "06", "0C", "System"); // pu direction
    editDetails()->page()->addComboBox(0, 7, 1, 1, "02", "06", "0D", "System"); // s1/s2 position
    editDetails()->page()->newGroupBox("String distance bridge <> PU [mm]");
    editDetails()->page()->addKnob(0, 0, 1, 1, "02", "06", "11", "System"); // string distance 1
    editDetails()->page()->addKnob(0, 1, 1, 1, "02", "06", "12", "System"); // string distance 2
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "06", "13", "System"); // string distance 3
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "06", "14", "System"); // string distance 4
    editDetails()->page()->addKnob(0, 4, 1, 1, "02", "06", "15", "System"); // string distance 5
    editDetails()->page()->addKnob(0, 5, 1, 1, "02", "06", "16", "System"); // string distance 6
    editDetails()->page()->addGroupBox(1, 0, 1, 4);
    editDetails()->page()->newGroupBox("String sensitivity");
    editDetails()->page()->addKnob(0, 0, 1, 1, "02", "06", "17", "System"); // string sense 1
    editDetails()->page()->addKnob(0, 1, 1, 1, "02", "06", "18", "System"); // string sense 2
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "06", "19", "System"); // string sense 3
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "06", "1A", "System"); // string sense 4
    editDetails()->page()->addKnob(0, 4, 1, 1, "02", "06", "1B", "System"); // string sense 5
    editDetails()->page()->addKnob(0, 5, 1, 1, "02", "06", "1C", "System"); // string sense 6
    editDetails()->page()->addGroupBox(1, 4, 1, 4);
    editDetails()->page()->addKnob(2, 0, 1, 1, "02", "06", "1D", "System"); // play feel
    editDetails()->page()->addKnob(2, 1, 1, 1, "02", "06", "1E", "System"); // low velo cut
    editDetails()->page()->addKnob(2, 2, 1, 1, "02", "06", "1F", "System"); // velocity dynamics
    editDetails()->page()->addKnob(2, 3, 1, 1, "02", "06", "20", "System"); // nuance dynamics
    editDetails()->page()->addKnob(2, 4, 1, 1, "02", "06", "21", "System"); // nuance trim
    editDetails()->page()->addKnob(2, 5, 1, 1, "02", "06", "22", "System"); // down shift
    editDetails()->page()->addKnob(2, 6, 1, 1, "02", "06", "0E", "System"); // normal pu gain
    editDetails()->page()->addKnob(2, 7, 1, 1, "02", "06", "51", "System"); // DevelopLowCut
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(0);
    editDetails()->page()->addNameEdit(0, 0, 1, 1, "02", "07", "00", "System", "8"); //GK catagory #4
    editDetails()->page()->newStackControl(4);
    editDetails()->page()->addComboBox(0, 1, 1, 1, "02", "07", "08", "System"); // PU select
    editDetails()->page()->addStackControl();
    editDetails()->page()->insertStackField(4, 0, 2, 1, 2);
    editDetails()->page()->addDataKnob(0, 4, 1, 1, "02", "07", "09", "SCALE", "right", 120);     //scale
    editDetails()->page()->addComboBox(0, 5, 1, 1, "02", "07", "0B", "System"); // pu phase
    editDetails()->page()->addComboBox(0, 6, 1, 1, "02", "07", "0C", "System"); // pu direction
    editDetails()->page()->addComboBox(0, 7, 1, 1, "02", "07", "0D", "System"); // s1/s2 position
    editDetails()->page()->newGroupBox("String distance bridge <> PU [mm]");
    editDetails()->page()->addKnob(0, 0, 1, 1, "02", "07", "11", "System"); // string distance 1
    editDetails()->page()->addKnob(0, 1, 1, 1, "02", "07", "12", "System"); // string distance 2
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "07", "13", "System"); // string distance 3
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "07", "14", "System"); // string distance 4
    editDetails()->page()->addKnob(0, 4, 1, 1, "02", "07", "15", "System"); // string distance 5
    editDetails()->page()->addKnob(0, 5, 1, 1, "02", "07", "16", "System"); // string distance 6
    editDetails()->page()->addGroupBox(1, 0, 1, 4);
    editDetails()->page()->newGroupBox("String sensitivity");
    editDetails()->page()->addKnob(0, 0, 1, 1, "02", "07", "17", "System"); // string sense 1
    editDetails()->page()->addKnob(0, 1, 1, 1, "02", "07", "18", "System"); // string sense 2
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "07", "19", "System"); // string sense 3
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "07", "1A", "System"); // string sense 4
    editDetails()->page()->addKnob(0, 4, 1, 1, "02", "07", "1B", "System"); // string sense 5
    editDetails()->page()->addKnob(0, 5, 1, 1, "02", "07", "1C", "System"); // string sense 6
    editDetails()->page()->addGroupBox(1, 4, 1, 4);
    editDetails()->page()->addKnob(2, 0, 1, 1, "02", "07", "1D", "System"); // play feel
    editDetails()->page()->addKnob(2, 1, 1, 1, "02", "07", "1E", "System"); // low velo cut
    editDetails()->page()->addKnob(2, 2, 1, 1, "02", "07", "1F", "System"); // velocity dynamics
    editDetails()->page()->addKnob(2, 3, 1, 1, "02", "07", "20", "System"); // nuance dynamics
    editDetails()->page()->addKnob(2, 4, 1, 1, "02", "07", "21", "System"); // nuance trim
    editDetails()->page()->addKnob(2, 5, 1, 1, "02", "07", "22", "System"); // down shift
    editDetails()->page()->addKnob(2, 6, 1, 1, "02", "07", "0E", "System"); // normal pu gain
    editDetails()->page()->addKnob(2, 7, 1, 1, "02", "07", "51", "System"); // DevelopLowCut
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(0);
    editDetails()->page()->addNameEdit(0, 0, 1, 1, "02", "08", "00", "System", "8"); //GK catagory #5
    editDetails()->page()->newStackControl(5);
    editDetails()->page()->addComboBox(0, 1, 1, 1, "02", "08", "08", "System"); // PU select
    editDetails()->page()->addStackControl();
    editDetails()->page()->insertStackField(5, 0, 2, 1, 2);
    editDetails()->page()->addDataKnob(0, 4, 1, 1, "02", "08", "09", "SCALE", "right", 120);     //scale
    editDetails()->page()->addComboBox(0, 5, 1, 1, "02", "08", "0B", "System"); // pu phase
    editDetails()->page()->addComboBox(0, 6, 1, 1, "02", "08", "0C", "System"); // pu direction
    editDetails()->page()->addComboBox(0, 7, 1, 1, "02", "08", "0D", "System"); // s1/s2 position
    editDetails()->page()->newGroupBox("String distance bridge <> PU [mm]");
    editDetails()->page()->addKnob(0, 0, 1, 1, "02", "08", "11", "System"); // string distance 1
    editDetails()->page()->addKnob(0, 1, 1, 1, "02", "08", "12", "System"); // string distance 2
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "08", "13", "System"); // string distance 3
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "08", "14", "System"); // string distance 4
    editDetails()->page()->addKnob(0, 4, 1, 1, "02", "08", "15", "System"); // string distance 5
    editDetails()->page()->addKnob(0, 5, 1, 1, "02", "08", "16", "System"); // string distance 6
    editDetails()->page()->addGroupBox(1, 0, 1, 4);
    editDetails()->page()->newGroupBox("String sensitivity");
    editDetails()->page()->addKnob(0, 0, 1, 1, "02", "08", "17", "System"); // string sense 1
    editDetails()->page()->addKnob(0, 1, 1, 1, "02", "08", "18", "System"); // string sense 2
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "08", "19", "System"); // string sense 3
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "08", "1A", "System"); // string sense 4
    editDetails()->page()->addKnob(0, 4, 1, 1, "02", "08", "1B", "System"); // string sense 5
    editDetails()->page()->addKnob(0, 5, 1, 1, "02", "08", "1C", "System"); // string sense 6
    editDetails()->page()->addGroupBox(1, 4, 1, 4);
    editDetails()->page()->addKnob(2, 0, 1, 1, "02", "08", "1D", "System"); // play feel
    editDetails()->page()->addKnob(2, 1, 1, 1, "02", "08", "1E", "System"); // low velo cut
    editDetails()->page()->addKnob(2, 2, 1, 1, "02", "08", "1F", "System"); // velocity dynamics
    editDetails()->page()->addKnob(2, 3, 1, 1, "02", "08", "20", "System"); // nuance dynamics
    editDetails()->page()->addKnob(2, 4, 1, 1, "02", "08", "21", "System"); // nuance trim
    editDetails()->page()->addKnob(2, 5, 1, 1, "02", "08", "22", "System"); // down shift
    editDetails()->page()->addKnob(2, 6, 1, 1, "02", "08", "0E", "System"); // normal pu gain
    editDetails()->page()->addKnob(2, 7, 1, 1, "02", "08", "51", "System"); // DevelopLowCut
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(0);
    editDetails()->page()->addNameEdit(0, 0, 1, 1, "02", "09", "00", "System", "8"); //GK catagory #6
    editDetails()->page()->newStackControl(6);
    editDetails()->page()->addComboBox(0, 1, 1, 1, "02", "09", "08", "System"); // PU select
    editDetails()->page()->addStackControl();
    editDetails()->page()->insertStackField(6, 0, 2, 1, 2);
    editDetails()->page()->addDataKnob(0, 4, 1, 1, "02", "09", "09", "SCALE", "right", 120);     //scale
    editDetails()->page()->addComboBox(0, 5, 1, 1, "02", "09", "0B", "System"); // pu phase
    editDetails()->page()->addComboBox(0, 6, 1, 1, "02", "09", "0C", "System"); // pu direction
    editDetails()->page()->addComboBox(0, 7, 1, 1, "02", "09", "0D", "System"); // s1/s2 position
    editDetails()->page()->newGroupBox("String distance bridge <> PU [mm]");
    editDetails()->page()->addKnob(0, 0, 1, 1, "02", "09", "11", "System"); // string distance 1
    editDetails()->page()->addKnob(0, 1, 1, 1, "02", "09", "12", "System"); // string distance 2
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "09", "13", "System"); // string distance 3
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "09", "14", "System"); // string distance 4
    editDetails()->page()->addKnob(0, 4, 1, 1, "02", "09", "15", "System"); // string distance 5
    editDetails()->page()->addKnob(0, 5, 1, 1, "02", "09", "16", "System"); // string distance 6
    editDetails()->page()->addGroupBox(1, 0, 1, 4);
    editDetails()->page()->newGroupBox("String sensitivity");
    editDetails()->page()->addKnob(0, 0, 1, 1, "02", "09", "17", "System"); // string sense 1
    editDetails()->page()->addKnob(0, 1, 1, 1, "02", "09", "18", "System"); // string sense 2
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "09", "19", "System"); // string sense 3
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "09", "1A", "System"); // string sense 4
    editDetails()->page()->addKnob(0, 4, 1, 1, "02", "09", "1B", "System"); // string sense 5
    editDetails()->page()->addKnob(0, 5, 1, 1, "02", "09", "1C", "System"); // string sense 6
    editDetails()->page()->addGroupBox(1, 4, 1, 4);
    editDetails()->page()->addKnob(2, 0, 1, 1, "02", "09", "1D", "System"); // play feel
    editDetails()->page()->addKnob(2, 1, 1, 1, "02", "09", "1E", "System"); // low velo cut
    editDetails()->page()->addKnob(2, 2, 1, 1, "02", "09", "1F", "System"); // velocity dynamics
    editDetails()->page()->addKnob(2, 3, 1, 1, "02", "09", "20", "System"); // nuance dynamics
    editDetails()->page()->addKnob(2, 4, 1, 1, "02", "09", "21", "System"); // nuance trim
    editDetails()->page()->addKnob(2, 5, 1, 1, "02", "09", "22", "System"); // down shift
    editDetails()->page()->addKnob(2, 6, 1, 1, "02", "09", "0E", "System"); // normal pu gain
    editDetails()->page()->addKnob(2, 7, 1, 1, "02", "09", "51", "System"); // DevelopLowCut
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(0);
    editDetails()->page()->addNameEdit(0, 0, 1, 1, "02", "0A", "00", "System", "8"); //GK catagory #7
    editDetails()->page()->newStackControl(7);
    editDetails()->page()->addComboBox(0, 1, 1, 1, "02", "0A", "08", "System"); // PU select
    editDetails()->page()->addStackControl();
    editDetails()->page()->insertStackField(7, 0, 2, 1, 2);
    editDetails()->page()->addDataKnob(0, 4, 1, 1, "02", "0A", "09", "SCALE", "right", 120);     //scale
    editDetails()->page()->addComboBox(0, 5, 1, 1, "02", "0A", "0B", "System"); // pu phase
    editDetails()->page()->addComboBox(0, 6, 1, 1, "02", "0A", "0C", "System"); // pu direction
    editDetails()->page()->addComboBox(0, 7, 1, 1, "02", "0A", "0D", "System"); // s1/s2 position
    editDetails()->page()->newGroupBox("String distance bridge <> PU [mm]");
    editDetails()->page()->addKnob(0, 0, 1, 1, "02", "0A", "11", "System"); // string distance 1
    editDetails()->page()->addKnob(0, 1, 1, 1, "02", "0A", "12", "System"); // string distance 2
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "0A", "13", "System"); // string distance 3
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "0A", "14", "System"); // string distance 4
    editDetails()->page()->addKnob(0, 4, 1, 1, "02", "0A", "15", "System"); // string distance 5
    editDetails()->page()->addKnob(0, 5, 1, 1, "02", "0A", "16", "System"); // string distance 6
    editDetails()->page()->addGroupBox(1, 0, 1, 4);
    editDetails()->page()->newGroupBox("String sensitivity");
    editDetails()->page()->addKnob(0, 0, 1, 1, "02", "0A", "17", "System"); // string sense 1
    editDetails()->page()->addKnob(0, 1, 1, 1, "02", "0A", "18", "System"); // string sense 2
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "0A", "19", "System"); // string sense 3
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "0A", "1A", "System"); // string sense 4
    editDetails()->page()->addKnob(0, 4, 1, 1, "02", "0A", "1B", "System"); // string sense 5
    editDetails()->page()->addKnob(0, 5, 1, 1, "02", "0A", "1C", "System"); // string sense 6
    editDetails()->page()->addGroupBox(1, 4, 1, 4);
    editDetails()->page()->addKnob(2, 0, 1, 1, "02", "0A", "1D", "System"); // play feel
    editDetails()->page()->addKnob(2, 1, 1, 1, "02", "0A", "1E", "System"); // low velo cut
    editDetails()->page()->addKnob(2, 2, 1, 1, "02", "0A", "1F", "System"); // velocity dynamics
    editDetails()->page()->addKnob(2, 3, 1, 1, "02", "0A", "20", "System"); // nuance dynamics
    editDetails()->page()->addKnob(2, 4, 1, 1, "02", "0A", "21", "System"); // nuance trim
    editDetails()->page()->addKnob(2, 5, 1, 1, "02", "0A", "22", "System"); // down shift
    editDetails()->page()->addKnob(2, 6, 1, 1, "02", "0A", "0E", "System"); // normal pu gain
    editDetails()->page()->addKnob(2, 7, 1, 1, "02", "0A", "51", "System"); // DevelopLowCut
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(0);
    editDetails()->page()->addNameEdit(0, 0, 1, 1, "02", "0B", "00", "System", "8"); //GK catagory #8
    editDetails()->page()->newStackControl(8);
    editDetails()->page()->addComboBox(0, 1, 1, 1, "02", "0B", "08", "System"); // PU select
    editDetails()->page()->addStackControl();
    editDetails()->page()->insertStackField(8, 0, 2, 1, 2);
    editDetails()->page()->addDataKnob(0, 4, 1, 1, "02", "0B", "09", "SCALE", "right", 120);     //scale
    editDetails()->page()->addComboBox(0, 5, 1, 1, "02", "0B", "0B", "System"); // pu phase
    editDetails()->page()->addComboBox(0, 6, 1, 1, "02", "0B", "0C", "System"); // pu direction
    editDetails()->page()->addComboBox(0, 7, 1, 1, "02", "0B", "0D", "System"); // s1/s2 position
    editDetails()->page()->newGroupBox("String distance bridge <> PU [mm]");
    editDetails()->page()->addKnob(0, 0, 1, 1, "02", "0B", "11", "System"); // string distance 1
    editDetails()->page()->addKnob(0, 1, 1, 1, "02", "0B", "12", "System"); // string distance 2
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "0B", "13", "System"); // string distance 3
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "0B", "14", "System"); // string distance 4
    editDetails()->page()->addKnob(0, 4, 1, 1, "02", "0B", "15", "System"); // string distance 5
    editDetails()->page()->addKnob(0, 5, 1, 1, "02", "0B", "16", "System"); // string distance 6
    editDetails()->page()->addGroupBox(1, 0, 1, 4);
    editDetails()->page()->newGroupBox("String sensitivity");
    editDetails()->page()->addKnob(0, 0, 1, 1, "02", "0B", "17", "System"); // string sense 1
    editDetails()->page()->addKnob(0, 1, 1, 1, "02", "0B", "18", "System"); // string sense 2
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "0B", "19", "System"); // string sense 3
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "0B", "1A", "System"); // string sense 4
    editDetails()->page()->addKnob(0, 4, 1, 1, "02", "0B", "1B", "System"); // string sense 5
    editDetails()->page()->addKnob(0, 5, 1, 1, "02", "0B", "1C", "System"); // string sense 6
    editDetails()->page()->addGroupBox(1, 4, 1, 4);
    editDetails()->page()->addKnob(2, 0, 1, 1, "02", "0B", "1D", "System"); // play feel
    editDetails()->page()->addKnob(2, 1, 1, 1, "02", "0B", "1E", "System"); // low velo cut
    editDetails()->page()->addKnob(2, 2, 1, 1, "02", "0B", "1F", "System"); // velocity dynamics
    editDetails()->page()->addKnob(2, 3, 1, 1, "02", "0B", "20", "System"); // nuance dynamics
    editDetails()->page()->addKnob(2, 4, 1, 1, "02", "0B", "21", "System"); // nuance trim
    editDetails()->page()->addKnob(2, 5, 1, 1, "02", "0B", "22", "System"); // down shift
    editDetails()->page()->addKnob(2, 6, 1, 1, "02", "0B", "0E", "System"); // normal pu gain
    editDetails()->page()->addKnob(2, 7, 1, 1, "02", "0B", "51", "System"); // DevelopLowCut
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(0);
    editDetails()->page()->addNameEdit(0, 0, 1, 1, "02", "0C", "00", "System", "8"); //GK catagory #9
    editDetails()->page()->newStackControl(9);
    editDetails()->page()->addComboBox(0, 1, 1, 1, "02", "0C", "08", "System"); // PU select
    editDetails()->page()->addStackControl();
    editDetails()->page()->insertStackField(9, 0, 2, 1, 2);
    editDetails()->page()->addDataKnob(0, 4, 1, 1, "02", "0C", "09", "SCALE", "right", 120);     //scale
    editDetails()->page()->addComboBox(0, 5, 1, 1, "02", "0C", "0B", "System"); // pu phase
    editDetails()->page()->addComboBox(0, 6, 1, 1, "02", "0C", "0C", "System"); // pu direction
    editDetails()->page()->addComboBox(0, 7, 1, 1, "02", "0C", "0D", "System"); // s1/s2 position
    editDetails()->page()->newGroupBox("String distance bridge <> PU [mm]");
    editDetails()->page()->addKnob(0, 0, 1, 1, "02", "0C", "11", "System"); // string distance 1
    editDetails()->page()->addKnob(0, 1, 1, 1, "02", "0C", "12", "System"); // string distance 2
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "0C", "13", "System"); // string distance 3
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "0C", "14", "System"); // string distance 4
    editDetails()->page()->addKnob(0, 4, 1, 1, "02", "0C", "15", "System"); // string distance 5
    editDetails()->page()->addKnob(0, 5, 1, 1, "02", "0C", "16", "System"); // string distance 6
    editDetails()->page()->addGroupBox(1, 0, 1, 4);
    editDetails()->page()->newGroupBox("String sensitivity");
    editDetails()->page()->addKnob(0, 0, 1, 1, "02", "0C", "17", "System"); // string sense 1
    editDetails()->page()->addKnob(0, 1, 1, 1, "02", "0C", "18", "System"); // string sense 2
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "0C", "19", "System"); // string sense 3
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "0C", "1A", "System"); // string sense 4
    editDetails()->page()->addKnob(0, 4, 1, 1, "02", "0C", "1B", "System"); // string sense 5
    editDetails()->page()->addKnob(0, 5, 1, 1, "02", "0C", "1C", "System"); // string sense 6
    editDetails()->page()->addGroupBox(1, 4, 1, 4);
    editDetails()->page()->addKnob(2, 0, 1, 1, "02", "0C", "1D", "System"); // play feel
    editDetails()->page()->addKnob(2, 1, 1, 1, "02", "0C", "1E", "System"); // low velo cut
    editDetails()->page()->addKnob(2, 2, 1, 1, "02", "0C", "1F", "System"); // velocity dynamics
    editDetails()->page()->addKnob(2, 3, 1, 1, "02", "0C", "20", "System"); // nuance dynamics
    editDetails()->page()->addKnob(2, 4, 1, 1, "02", "0C", "21", "System"); // nuance trim
    editDetails()->page()->addKnob(2, 5, 1, 1, "02", "0C", "22", "System"); // down shift
    editDetails()->page()->addKnob(2, 6, 1, 1, "02", "0C", "0E", "System"); // normal pu gain
    editDetails()->page()->addKnob(2, 7, 1, 1, "02", "0C", "51", "System"); // DevelopLowCut
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(0);
    editDetails()->page()->addNameEdit(0, 0, 1, 1, "02", "0D", "00", "System", "8"); //GK catagory #10
    editDetails()->page()->newStackControl(10);
    editDetails()->page()->addComboBox(0, 1, 1, 1, "02", "0D", "08", "System"); // PU select
    editDetails()->page()->addStackControl();
    editDetails()->page()->insertStackField(10, 0, 2, 1, 2);
    editDetails()->page()->addDataKnob(0, 4, 1, 1, "02", "0D", "09", "SCALE", "right", 120);     //scale
    editDetails()->page()->addComboBox(0, 5, 1, 1, "02", "0D", "0B", "System"); // pu phase
    editDetails()->page()->addComboBox(0, 6, 1, 1, "02", "0D", "0C", "System"); // pu direction
    editDetails()->page()->addComboBox(0, 7, 1, 1, "02", "0D", "0D", "System"); // s1/s2 position
    editDetails()->page()->newGroupBox("String distance bridge <> PU [mm]");
    editDetails()->page()->addKnob(0, 0, 1, 1, "02", "0D", "11", "System"); // string distance 1
    editDetails()->page()->addKnob(0, 1, 1, 1, "02", "0D", "12", "System"); // string distance 2
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "0D", "13", "System"); // string distance 3
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "0D", "14", "System"); // string distance 4
    editDetails()->page()->addKnob(0, 4, 1, 1, "02", "0D", "15", "System"); // string distance 5
    editDetails()->page()->addKnob(0, 5, 1, 1, "02", "0D", "16", "System"); // string distance 6
    editDetails()->page()->addGroupBox(1, 0, 1, 4);
    editDetails()->page()->newGroupBox("String sensitivity");
    editDetails()->page()->addKnob(0, 0, 1, 1, "02", "0D", "17", "System"); // string sense 1
    editDetails()->page()->addKnob(0, 1, 1, 1, "02", "0D", "18", "System"); // string sense 2
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "0D", "19", "System"); // string sense 3
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "0D", "1A", "System"); // string sense 4
    editDetails()->page()->addKnob(0, 4, 1, 1, "02", "0D", "1B", "System"); // string sense 5
    editDetails()->page()->addKnob(0, 5, 1, 1, "02", "0D", "1C", "System"); // string sense 6
    editDetails()->page()->addGroupBox(1, 4, 1, 4);
    editDetails()->page()->addKnob(2, 0, 1, 1, "02", "0D", "1D", "System"); // play feel
    editDetails()->page()->addKnob(2, 1, 1, 1, "02", "0D", "1E", "System"); // low velo cut
    editDetails()->page()->addKnob(2, 2, 1, 1, "02", "0D", "1F", "System"); // velocity dynamics
    editDetails()->page()->addKnob(2, 3, 1, 1, "02", "0D", "20", "System"); // nuance dynamics
    editDetails()->page()->addKnob(2, 4, 1, 1, "02", "0D", "21", "System"); // nuance trim
    editDetails()->page()->addKnob(2, 5, 1, 1, "02", "0D", "22", "System"); // down shift
    editDetails()->page()->addKnob(2, 6, 1, 1, "02", "0D", "0E", "System"); // normal pu gain
    editDetails()->page()->addKnob(2, 7, 1, 1, "02", "0D", "51", "System"); // DevelopLowCut
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(1);
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "04", "0F", "System"); // piezo low
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "04", "10", "System"); // piezo high
    editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(1);
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "04", "0F", "System"); // piezo low
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "04", "10", "System"); // piezo high
    editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(1);
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "04", "0F", "System"); // piezo low
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "04", "10", "System"); // piezo high
    editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(1);
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "04", "0F", "System"); // piezo low
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "04", "10", "System"); // piezo high
    editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(1);
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "04", "0F", "System"); // piezo low
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "04", "10", "System"); // piezo high
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(2);
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "05", "0F", "System"); // piezo low
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "05", "10", "System"); // piezo high
    editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(2);
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "05", "0F", "System"); // piezo low
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "05", "10", "System"); // piezo high
    editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(2);
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "05", "0F", "System"); // piezo low
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "05", "10", "System"); // piezo high
    editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(2);
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "05", "0F", "System"); // piezo low
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "05", "10", "System"); // piezo high
    editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(2);
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "05", "0F", "System"); // piezo low
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "05", "10", "System"); // piezo high
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(3);
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "06", "0F", "System"); // piezo low
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "06", "10", "System"); // piezo high
    editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(3);
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "06", "0F", "System"); // piezo low
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "06", "10", "System"); // piezo high
    editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(3);
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "06", "0F", "System"); // piezo low
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "06", "10", "System"); // piezo high
    editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(3);
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "06", "0F", "System"); // piezo low
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "06", "10", "System"); // piezo high
    editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(3);
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "06", "0F", "System"); // piezo low
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "06", "10", "System"); // piezo high
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(4);
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "07", "0F", "System"); // piezo low
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "07", "10", "System"); // piezo high
    editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(4);
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "07", "0F", "System"); // piezo low
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "07", "10", "System"); // piezo high
    editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(4);
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "07", "0F", "System"); // piezo low
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "07", "10", "System"); // piezo high
    editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(4);
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "07", "0F", "System"); // piezo low
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "07", "10", "System"); // piezo high
    editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(4);
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "07", "0F", "System"); // piezo low
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "07", "10", "System"); // piezo high
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(5);editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(5);editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(5);
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "08", "0F", "System"); // piezo low
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "08", "10", "System"); // piezo high
    editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(5);
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "08", "0F", "System"); // piezo low
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "08", "10", "System"); // piezo high
    editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(5);
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "08", "0F", "System"); // piezo low
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "08", "10", "System"); // piezo high
    editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(5);
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "08", "0F", "System"); // piezo low
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "08", "10", "System"); // piezo high
    editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(5);
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "08", "0F", "System"); // piezo low
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "08", "10", "System"); // piezo high
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(6);editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(6);editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(6);
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "09", "0F", "System"); // piezo low
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "09", "10", "System"); // piezo high
    editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(6);
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "09", "0F", "System"); // piezo low
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "09", "10", "System"); // piezo high
    editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(6);
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "09", "0F", "System"); // piezo low
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "09", "10", "System"); // piezo high
    editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(6);
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "09", "0F", "System"); // piezo low
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "09", "10", "System"); // piezo high
    editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(6);
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "09", "0F", "System"); // piezo low
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "09", "10", "System"); // piezo high
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(7);editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(7);editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(7);
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "0A", "0F", "System"); // piezo low
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "0A", "10", "System"); // piezo high
    editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(7);
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "0A", "0F", "System"); // piezo low
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "0A", "10", "System"); // piezo high
    editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(7);
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "0A", "0F", "System"); // piezo low
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "0A", "10", "System"); // piezo high
    editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(7);
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "0A", "0F", "System"); // piezo low
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "0A", "10", "System"); // piezo high
    editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(7);
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "0A", "0F", "System"); // piezo low
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "0A", "10", "System"); // piezo high
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(8);editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(8);editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(8);
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "0B", "0F", "System"); // piezo low
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "0B", "10", "System"); // piezo high
    editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(8);
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "0B", "0F", "System"); // piezo low
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "0B", "10", "System"); // piezo high
    editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(8);
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "0B", "0F", "System"); // piezo low
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "0B", "10", "System"); // piezo high
    editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(8);
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "0B", "0F", "System"); // piezo low
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "0B", "10", "System"); // piezo high
    editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(8);
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "0B", "0F", "System"); // piezo low
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "0B", "10", "System"); // piezo high
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(9);editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(9);editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(9);
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "0C", "0F", "System"); // piezo low
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "0C", "10", "System"); // piezo high
    editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(9);
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "0C", "0F", "System"); // piezo low
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "0C", "10", "System"); // piezo high
    editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(9);
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "0C", "0F", "System"); // piezo low
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "0C", "10", "System"); // piezo high
    editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(9);
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "0C", "0F", "System"); // piezo low
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "0C", "10", "System"); // piezo high
    editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(9);
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "0C", "0F", "System"); // piezo low
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "0C", "10", "System"); // piezo high
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(10);editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(10);editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(10);
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "0D", "0F", "System"); // piezo low
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "0D", "10", "System"); // piezo high
    editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(10);
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "0D", "0F", "System"); // piezo low
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "0D", "10", "System"); // piezo high
    editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(10);
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "0D", "0F", "System"); // piezo low
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "0D", "10", "System"); // piezo high
    editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(10);
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "0D", "0F", "System"); // piezo low
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "0D", "10", "System"); // piezo high
    editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(10);
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "0D", "0F", "System"); // piezo low
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "0D", "10", "System"); // piezo high
    editDetails()->page()->addStackField();

    editDetails()->addPage("00", "00", "17", "02", "Tables");


    editDetails()->page()->addLabel(0, 0, 1, 1, text);
    editDetails()->page()->newGroupBox("Bass Mode - GK setup");
    editDetails()->page()->newStackControl(0);
    editDetails()->page()->addComboBox(0, 0, 1, 1, "02", "00", "00", "System"); //bass mode GK Set
    editDetails()->page()->addStackControl();
    editDetails()->page()->insertStackField(0, 1, 0, 1, 4);
    editDetails()->page()->addGroupBox(1, 0, 1, 1);


    editDetails()->page()->newStackField(0);
    editDetails()->page()->addNameEdit(0, 0, 1, 1, "02", "04", "23", "System", "8"); //GK catagory #1
    editDetails()->page()->newStackControl(1);
    editDetails()->page()->addComboBox(0, 1, 1, 1, "02", "04", "2B", "System"); // PU select
    editDetails()->page()->addStackControl();
    editDetails()->page()->insertStackField(1, 0, 2, 1, 2);
    editDetails()->page()->addDataKnob(0, 4, 1, 1, "02", "04", "2C", "SCALE_BASS", "right", 80); //scale
    editDetails()->page()->addComboBox(0, 5, 1, 1, "02", "04", "2E", "System"); //GK pu position
    editDetails()->page()->addComboBox(0, 6, 1, 1, "02", "04", "2F", "System"); // pu phase
    editDetails()->page()->addComboBox(0, 7, 1, 1, "02", "04", "30", "System"); // pu direction
    editDetails()->page()->addComboBox(0, 8, 1, 1, "02", "04", "31", "System"); // s1/s2 position
    editDetails()->page()->newGroupBox("String distance bridge <> PU [mm]");
    editDetails()->page()->addKnob(0, 0, 1, 1, "02", "04", "35", "System"); // string distance 1
    editDetails()->page()->addKnob(0, 1, 1, 1, "02", "04", "36", "System"); // string distance 2
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "04", "37", "System"); // string distance 3
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "04", "38", "System"); // string distance 4
    editDetails()->page()->addKnob(0, 4, 1, 1, "02", "04", "39", "System"); // string distance 5
    editDetails()->page()->addKnob(0, 5, 1, 1, "02", "04", "3A", "System"); // string distance 6
    editDetails()->page()->addGroupBox(1, 0, 1, 4);
    editDetails()->page()->newGroupBox("String sensitivity");
    editDetails()->page()->addKnob(0, 0, 1, 1, "02", "04", "3B", "System"); // string sense 1
    editDetails()->page()->addKnob(0, 1, 1, 1, "02", "04", "3C", "System"); // string sense 1
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "04", "3D", "System"); // string sense 1
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "04", "3E", "System"); // string sense 1
    editDetails()->page()->addKnob(0, 4, 1, 1, "02", "04", "3F", "System"); // string sense 1
    editDetails()->page()->addKnob(0, 5, 1, 1, "02", "04", "40", "System"); // string sense 1
    editDetails()->page()->addGroupBox(1, 4, 1, 5);
    editDetails()->page()->addKnob(2, 0, 1, 1, "02", "04", "41", "System"); // play feel
    editDetails()->page()->addKnob(2, 1, 1, 1, "02", "04", "42", "System"); // low velo cut
    editDetails()->page()->addKnob(2, 2, 1, 1, "02", "04", "43", "System"); // velocity dynamics
    editDetails()->page()->addKnob(2, 3, 1, 1, "02", "04", "44", "System"); // nuance dynamics
    editDetails()->page()->addKnob(2, 4, 1, 1, "02", "04", "45", "System"); // nuance trim
    editDetails()->page()->addKnob(2, 5, 1, 1, "02", "04", "46", "System"); // down shift
    editDetails()->page()->addKnob(2, 6, 1, 1, "02", "04", "32", "System"); // normal pu gain
    editDetails()->page()->addKnob(2, 7, 1, 1, "02", "04", "52", "System"); // DevelopLowCut
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(0);
    editDetails()->page()->addNameEdit(0, 0, 1, 1, "02", "05", "23", "System", "8"); //GK catagory #2
    editDetails()->page()->newStackControl(2);
    editDetails()->page()->addComboBox(0, 1, 1, 1, "02", "05", "2B", "System"); // PU select
    editDetails()->page()->addStackControl();
    editDetails()->page()->insertStackField(2, 0, 2, 1, 2);
    editDetails()->page()->addDataKnob(0, 4, 1, 1, "02", "05", "2C", "SCALE_BASS", "right", 80); //scale
    editDetails()->page()->addComboBox(0, 5, 1, 1, "02", "05", "2E", "System"); //GK pu position
    editDetails()->page()->addComboBox(0, 6, 1, 1, "02", "05", "2F", "System"); // pu phase
    editDetails()->page()->addComboBox(0, 7, 1, 1, "02", "05", "30", "System"); // pu direction
    editDetails()->page()->addComboBox(0, 8, 1, 1, "02", "05", "31", "System"); // s1/s2 position
    editDetails()->page()->newGroupBox("String distance bridge <> PU [mm]");
    editDetails()->page()->addKnob(0, 0, 1, 1, "02", "05", "35", "System"); // string distance 1
    editDetails()->page()->addKnob(0, 1, 1, 1, "02", "05", "36", "System"); // string distance 2
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "05", "37", "System"); // string distance 3
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "05", "38", "System"); // string distance 4
    editDetails()->page()->addKnob(0, 4, 1, 1, "02", "05", "39", "System"); // string distance 5
    editDetails()->page()->addKnob(0, 5, 1, 1, "02", "05", "3A", "System"); // string distance 6
    editDetails()->page()->addGroupBox(1, 0, 1, 4);
    editDetails()->page()->newGroupBox("String sensitivity");
    editDetails()->page()->addKnob(0, 0, 1, 1, "02", "05", "3B", "System"); // string sense 1
    editDetails()->page()->addKnob(0, 1, 1, 1, "02", "05", "3C", "System"); // string sense 1
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "05", "3D", "System"); // string sense 1
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "05", "3E", "System"); // string sense 1
    editDetails()->page()->addKnob(0, 4, 1, 1, "02", "05", "3F", "System"); // string sense 1
    editDetails()->page()->addKnob(0, 5, 1, 1, "02", "05", "40", "System"); // string sense 1
    editDetails()->page()->addGroupBox(1, 4, 1, 5);
    editDetails()->page()->addKnob(2, 0, 1, 1, "02", "05", "41", "System"); // play feel
    editDetails()->page()->addKnob(2, 1, 1, 1, "02", "05", "42", "System"); // low velo cut
    editDetails()->page()->addKnob(2, 2, 1, 1, "02", "05", "43", "System"); // velocity dynamics
    editDetails()->page()->addKnob(2, 3, 1, 1, "02", "05", "44", "System"); // nuance dynamics
    editDetails()->page()->addKnob(2, 4, 1, 1, "02", "05", "45", "System"); // nuance trim
    editDetails()->page()->addKnob(2, 5, 1, 1, "02", "05", "46", "System"); // down shift
    editDetails()->page()->addKnob(2, 6, 1, 1, "02", "05", "32", "System"); // normal pu gain
    editDetails()->page()->addKnob(2, 7, 1, 1, "02", "05", "52", "System"); // DevelopLowCut
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(0);
    editDetails()->page()->addNameEdit(0, 0, 1, 1, "02", "06", "23", "System", "8"); //GK catagory #3
    editDetails()->page()->newStackControl(3);
    editDetails()->page()->addComboBox(0, 1, 1, 1, "02", "06", "2B", "System"); // PU select
    editDetails()->page()->addStackControl();
    editDetails()->page()->insertStackField(3, 0, 2, 1, 2);
    editDetails()->page()->addDataKnob(0, 4, 1, 1, "02", "06", "2C", "SCALE_BASS", "right", 80); //scale
    editDetails()->page()->addComboBox(0, 5, 1, 1, "02", "06", "2E", "System"); //GK pu position
    editDetails()->page()->addComboBox(0, 6, 1, 1, "02", "06", "2F", "System"); // pu phase
    editDetails()->page()->addComboBox(0, 7, 1, 1, "02", "06", "30", "System"); // pu direction
    editDetails()->page()->addComboBox(0, 8, 1, 1, "02", "06", "31", "System"); // s1/s2 position
    editDetails()->page()->newGroupBox("String distance bridge <> PU [mm]");
    editDetails()->page()->addKnob(0, 0, 1, 1, "02", "06", "35", "System"); // string distance 1
    editDetails()->page()->addKnob(0, 1, 1, 1, "02", "06", "36", "System"); // string distance 2
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "06", "37", "System"); // string distance 3
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "06", "38", "System"); // string distance 4
    editDetails()->page()->addKnob(0, 4, 1, 1, "02", "06", "39", "System"); // string distance 5
    editDetails()->page()->addKnob(0, 5, 1, 1, "02", "06", "3A", "System"); // string distance 6
    editDetails()->page()->addGroupBox(1, 0, 1, 4);
    editDetails()->page()->newGroupBox("String sensitivity");
    editDetails()->page()->addKnob(0, 0, 1, 1, "02", "06", "3B", "System"); // string sense 1
    editDetails()->page()->addKnob(0, 1, 1, 1, "02", "06", "3C", "System"); // string sense 1
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "06", "3D", "System"); // string sense 1
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "06", "3E", "System"); // string sense 1
    editDetails()->page()->addKnob(0, 4, 1, 1, "02", "06", "3F", "System"); // string sense 1
    editDetails()->page()->addKnob(0, 5, 1, 1, "02", "06", "40", "System"); // string sense 1
    editDetails()->page()->addGroupBox(1, 4, 1, 5);
    editDetails()->page()->addKnob(2, 0, 1, 1, "02", "06", "41", "System"); // play feel
    editDetails()->page()->addKnob(2, 1, 1, 1, "02", "06", "42", "System"); // low velo cut
    editDetails()->page()->addKnob(2, 2, 1, 1, "02", "06", "43", "System"); // velocity dynamics
    editDetails()->page()->addKnob(2, 3, 1, 1, "02", "06", "44", "System"); // nuance dynamics
    editDetails()->page()->addKnob(2, 4, 1, 1, "02", "06", "45", "System"); // nuance trim
    editDetails()->page()->addKnob(2, 5, 1, 1, "02", "06", "46", "System"); // down shift
    editDetails()->page()->addKnob(2, 6, 1, 1, "02", "06", "32", "System"); // normal pu gain
    editDetails()->page()->addKnob(2, 7, 1, 1, "02", "07", "52", "System"); // DevelopLowCut
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(0);
    editDetails()->page()->addNameEdit(0, 0, 1, 1, "02", "07", "23", "System", "8"); //GK catagory #4
    editDetails()->page()->newStackControl(4);
    editDetails()->page()->addComboBox(0, 1, 1, 1, "02", "07", "2B", "System"); // PU select
    editDetails()->page()->addStackControl();
    editDetails()->page()->insertStackField(4, 0, 2, 1, 2);
    editDetails()->page()->addDataKnob(0, 4, 1, 1, "02", "07", "2C", "SCALE_BASS", "right", 80); //scale
    editDetails()->page()->addComboBox(0, 5, 1, 1, "02", "07", "2E", "System"); //GK pu position
    editDetails()->page()->addComboBox(0, 6, 1, 1, "02", "07", "2F", "System"); // pu phase
    editDetails()->page()->addComboBox(0, 7, 1, 1, "02", "07", "30", "System"); // pu direction
    editDetails()->page()->addComboBox(0, 8, 1, 1, "02", "07", "31", "System"); // s1/s2 position
    editDetails()->page()->newGroupBox("String distance bridge <> PU [mm]");
    editDetails()->page()->addKnob(0, 0, 1, 1, "02", "07", "35", "System"); // string distance 1
    editDetails()->page()->addKnob(0, 1, 1, 1, "02", "07", "36", "System"); // string distance 2
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "07", "37", "System"); // string distance 3
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "07", "38", "System"); // string distance 4
    editDetails()->page()->addKnob(0, 4, 1, 1, "02", "07", "39", "System"); // string distance 5
    editDetails()->page()->addKnob(0, 5, 1, 1, "02", "07", "3A", "System"); // string distance 6
    editDetails()->page()->addGroupBox(1, 0, 1, 4);
    editDetails()->page()->newGroupBox("String sensitivity");
    editDetails()->page()->addKnob(0, 0, 1, 1, "02", "07", "3B", "System"); // string sense 1
    editDetails()->page()->addKnob(0, 1, 1, 1, "02", "07", "3C", "System"); // string sense 1
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "07", "3D", "System"); // string sense 1
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "07", "3E", "System"); // string sense 1
    editDetails()->page()->addKnob(0, 4, 1, 1, "02", "07", "3F", "System"); // string sense 1
    editDetails()->page()->addKnob(0, 5, 1, 1, "02", "07", "40", "System"); // string sense 1
    editDetails()->page()->addGroupBox(1, 4, 1, 5);
    editDetails()->page()->addKnob(2, 0, 1, 1, "02", "07", "41", "System"); // play feel
    editDetails()->page()->addKnob(2, 1, 1, 1, "02", "07", "42", "System"); // low velo cut
    editDetails()->page()->addKnob(2, 2, 1, 1, "02", "07", "43", "System"); // velocity dynamics
    editDetails()->page()->addKnob(2, 3, 1, 1, "02", "07", "44", "System"); // nuance dynamics
    editDetails()->page()->addKnob(2, 4, 1, 1, "02", "07", "45", "System"); // nuance trim
    editDetails()->page()->addKnob(2, 5, 1, 1, "02", "07", "46", "System"); // down shift
    editDetails()->page()->addKnob(2, 6, 1, 1, "02", "07", "32", "System"); // normal pu gain
    editDetails()->page()->addKnob(2, 7, 1, 1, "02", "07", "52", "System"); // DevelopLowCut
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(0);
    editDetails()->page()->addNameEdit(0, 0, 1, 1, "02", "08", "23", "System", "8"); //GK catagory #5
    editDetails()->page()->newStackControl(5);
    editDetails()->page()->addComboBox(0, 1, 1, 1, "02", "08", "2B", "System"); // PU select
    editDetails()->page()->addStackControl();
    editDetails()->page()->insertStackField(5, 0, 2, 1, 2);
    editDetails()->page()->addDataKnob(0, 4, 1, 1, "02", "08", "2C", "SCALE_BASS", "right", 80); //scale
    editDetails()->page()->addComboBox(0, 5, 1, 1, "02", "08", "2E", "System"); //GK pu position
    editDetails()->page()->addComboBox(0, 6, 1, 1, "02", "08", "2F", "System"); // pu phase
    editDetails()->page()->addComboBox(0, 7, 1, 1, "02", "08", "30", "System"); // pu direction
    editDetails()->page()->addComboBox(0, 8, 1, 1, "02", "08", "31", "System"); // s1/s2 position
    editDetails()->page()->newGroupBox("String distance bridge <> PU [mm]");
    editDetails()->page()->addKnob(0, 0, 1, 1, "02", "08", "35", "System"); // string distance 1
    editDetails()->page()->addKnob(0, 1, 1, 1, "02", "08", "36", "System"); // string distance 2
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "08", "37", "System"); // string distance 3
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "08", "38", "System"); // string distance 4
    editDetails()->page()->addKnob(0, 4, 1, 1, "02", "08", "39", "System"); // string distance 5
    editDetails()->page()->addKnob(0, 5, 1, 1, "02", "08", "3A", "System"); // string distance 6
    editDetails()->page()->addGroupBox(1, 0, 1, 4);
    editDetails()->page()->newGroupBox("String sensitivity");
    editDetails()->page()->addKnob(0, 0, 1, 1, "02", "08", "3B", "System"); // string sense 1
    editDetails()->page()->addKnob(0, 1, 1, 1, "02", "08", "3C", "System"); // string sense 1
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "08", "3D", "System"); // string sense 1
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "08", "3E", "System"); // string sense 1
    editDetails()->page()->addKnob(0, 4, 1, 1, "02", "08", "3F", "System"); // string sense 1
    editDetails()->page()->addKnob(0, 5, 1, 1, "02", "08", "40", "System"); // string sense 1
    editDetails()->page()->addGroupBox(1, 4, 1, 5);
    editDetails()->page()->addKnob(2, 0, 1, 1, "02", "08", "41", "System"); // play feel
    editDetails()->page()->addKnob(2, 1, 1, 1, "02", "08", "42", "System"); // low velo cut
    editDetails()->page()->addKnob(2, 2, 1, 1, "02", "08", "43", "System"); // velocity dynamics
    editDetails()->page()->addKnob(2, 3, 1, 1, "02", "08", "44", "System"); // nuance dynamics
    editDetails()->page()->addKnob(2, 4, 1, 1, "02", "08", "45", "System"); // nuance trim
    editDetails()->page()->addKnob(2, 5, 1, 1, "02", "08", "46", "System"); // down shift
    editDetails()->page()->addKnob(2, 6, 1, 1, "02", "08", "32", "System"); // normal pu gain
    editDetails()->page()->addKnob(2, 7, 1, 1, "02", "08", "52", "System"); // DevelopLowCut
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(0);
    editDetails()->page()->addNameEdit(0, 0, 1, 1, "02", "09", "23", "System", "8"); //GK catagory #6
    editDetails()->page()->newStackControl(6);
    editDetails()->page()->addComboBox(0, 1, 1, 1, "02", "09", "2B", "System"); // PU select
    editDetails()->page()->addStackControl();
    editDetails()->page()->insertStackField(6, 0, 2, 1, 2);
    editDetails()->page()->addDataKnob(0, 4, 1, 1, "02", "09", "2C", "SCALE_BASS", "right", 80); //scale
    editDetails()->page()->addComboBox(0, 5, 1, 1, "02", "09", "2E", "System"); //GK pu position
    editDetails()->page()->addComboBox(0, 6, 1, 1, "02", "09", "2F", "System"); // pu phase
    editDetails()->page()->addComboBox(0, 7, 1, 1, "02", "09", "30", "System"); // pu direction
    editDetails()->page()->addComboBox(0, 8, 1, 1, "02", "09", "31", "System"); // s1/s2 position
    editDetails()->page()->newGroupBox("String distance bridge <> PU [mm]");
    editDetails()->page()->addKnob(0, 0, 1, 1, "02", "09", "35", "System"); // string distance 1
    editDetails()->page()->addKnob(0, 1, 1, 1, "02", "09", "36", "System"); // string distance 2
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "09", "37", "System"); // string distance 3
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "09", "38", "System"); // string distance 4
    editDetails()->page()->addKnob(0, 4, 1, 1, "02", "09", "39", "System"); // string distance 5
    editDetails()->page()->addKnob(0, 5, 1, 1, "02", "09", "3A", "System"); // string distance 6
    editDetails()->page()->addGroupBox(1, 0, 1, 4);
    editDetails()->page()->newGroupBox("String sensitivity");
    editDetails()->page()->addKnob(0, 0, 1, 1, "02", "09", "3B", "System"); // string sense 1
    editDetails()->page()->addKnob(0, 1, 1, 1, "02", "09", "3C", "System"); // string sense 1
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "09", "3D", "System"); // string sense 1
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "09", "3E", "System"); // string sense 1
    editDetails()->page()->addKnob(0, 4, 1, 1, "02", "09", "3F", "System"); // string sense 1
    editDetails()->page()->addKnob(0, 5, 1, 1, "02", "09", "40", "System"); // string sense 1
    editDetails()->page()->addGroupBox(1, 4, 1, 5);
    editDetails()->page()->addKnob(2, 0, 1, 1, "02", "09", "41", "System"); // play feel
    editDetails()->page()->addKnob(2, 1, 1, 1, "02", "09", "42", "System"); // low velo cut
    editDetails()->page()->addKnob(2, 2, 1, 1, "02", "09", "43", "System"); // velocity dynamics
    editDetails()->page()->addKnob(2, 3, 1, 1, "02", "09", "44", "System"); // nuance dynamics
    editDetails()->page()->addKnob(2, 4, 1, 1, "02", "09", "45", "System"); // nuance trim
    editDetails()->page()->addKnob(2, 5, 1, 1, "02", "09", "46", "System"); // down shift
    editDetails()->page()->addKnob(2, 6, 1, 1, "02", "09", "32", "System"); // normal pu gain
    editDetails()->page()->addKnob(2, 7, 1, 1, "02", "09", "52", "System"); // DevelopLowCut
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(0);
    editDetails()->page()->addNameEdit(0, 0, 1, 1, "02", "0A", "23", "System", "8"); //GK catagory #7
    editDetails()->page()->newStackControl(7);
    editDetails()->page()->addComboBox(0, 1, 1, 1, "02", "0A", "2B", "System"); // PU select
    editDetails()->page()->addStackControl();
    editDetails()->page()->insertStackField(7, 0, 2, 1, 2);
    editDetails()->page()->addDataKnob(0, 4, 1, 1, "02", "0A", "2C", "SCALE_BASS", "right", 80); //scale
    editDetails()->page()->addComboBox(0, 5, 1, 1, "02", "0A", "2E", "System"); //GK pu position
    editDetails()->page()->addComboBox(0, 6, 1, 1, "02", "0A", "2F", "System"); // pu phase
    editDetails()->page()->addComboBox(0, 7, 1, 1, "02", "0A", "30", "System"); // pu direction
    editDetails()->page()->addComboBox(0, 8, 1, 1, "02", "0A", "31", "System"); // s1/s2 position
    editDetails()->page()->newGroupBox("String distance bridge <> PU [mm]");
    editDetails()->page()->addKnob(0, 0, 1, 1, "02", "0A", "35", "System"); // string distance 1
    editDetails()->page()->addKnob(0, 1, 1, 1, "02", "0A", "36", "System"); // string distance 2
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "0A", "37", "System"); // string distance 3
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "0A", "38", "System"); // string distance 4
    editDetails()->page()->addKnob(0, 4, 1, 1, "02", "0A", "39", "System"); // string distance 5
    editDetails()->page()->addKnob(0, 5, 1, 1, "02", "0A", "3A", "System"); // string distance 6
    editDetails()->page()->addGroupBox(1, 0, 1, 4);
    editDetails()->page()->newGroupBox("String sensitivity");
    editDetails()->page()->addKnob(0, 0, 1, 1, "02", "0A", "3B", "System"); // string sense 1
    editDetails()->page()->addKnob(0, 1, 1, 1, "02", "0A", "3C", "System"); // string sense 1
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "0A", "3D", "System"); // string sense 1
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "0A", "3E", "System"); // string sense 1
    editDetails()->page()->addKnob(0, 4, 1, 1, "02", "0A", "3F", "System"); // string sense 1
    editDetails()->page()->addKnob(0, 5, 1, 1, "02", "0A", "40", "System"); // string sense 1
    editDetails()->page()->addGroupBox(1, 4, 1, 5);
    editDetails()->page()->addKnob(2, 0, 1, 1, "02", "0A", "41", "System"); // play feel
    editDetails()->page()->addKnob(2, 1, 1, 1, "02", "0A", "42", "System"); // low velo cut
    editDetails()->page()->addKnob(2, 2, 1, 1, "02", "0A", "43", "System"); // velocity dynamics
    editDetails()->page()->addKnob(2, 3, 1, 1, "02", "0A", "44", "System"); // nuance dynamics
    editDetails()->page()->addKnob(2, 4, 1, 1, "02", "0A", "45", "System"); // nuance trim
    editDetails()->page()->addKnob(2, 5, 1, 1, "02", "0A", "46", "System"); // down shift
    editDetails()->page()->addKnob(2, 6, 1, 1, "02", "0A", "32", "System"); // normal pu gain
    editDetails()->page()->addKnob(2, 7, 1, 1, "02", "0A", "52", "System"); // DevelopLowCut
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(0);
    editDetails()->page()->addNameEdit(0, 0, 1, 1, "02", "0B", "23", "System", "8"); //GK catagory #8
    editDetails()->page()->newStackControl(8);
    editDetails()->page()->addComboBox(0, 1, 1, 1, "02", "0B", "2B", "System"); // PU select
    editDetails()->page()->addStackControl();
    editDetails()->page()->insertStackField(8, 0, 2, 1, 2);
    editDetails()->page()->addDataKnob(0, 4, 1, 1, "02", "0B", "2C", "SCALE_BASS", "right", 80); //scale
    editDetails()->page()->addComboBox(0, 5, 1, 1, "02", "0B", "2E", "System"); //GK pu position
    editDetails()->page()->addComboBox(0, 6, 1, 1, "02", "0B", "2F", "System"); // pu phase
    editDetails()->page()->addComboBox(0, 7, 1, 1, "02", "0B", "30", "System"); // pu direction
    editDetails()->page()->addComboBox(0, 8, 1, 1, "02", "0B", "31", "System"); // s1/s2 position
    editDetails()->page()->newGroupBox("String distance bridge <> PU [mm]");
    editDetails()->page()->addKnob(0, 0, 1, 1, "02", "0B", "35", "System"); // string distance 1
    editDetails()->page()->addKnob(0, 1, 1, 1, "02", "0B", "36", "System"); // string distance 2
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "0B", "37", "System"); // string distance 3
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "0B", "38", "System"); // string distance 4
    editDetails()->page()->addKnob(0, 4, 1, 1, "02", "0B", "39", "System"); // string distance 5
    editDetails()->page()->addKnob(0, 5, 1, 1, "02", "0B", "3A", "System"); // string distance 6
    editDetails()->page()->addGroupBox(1, 0, 1, 4);
    editDetails()->page()->newGroupBox("String sensitivity");
    editDetails()->page()->addKnob(0, 0, 1, 1, "02", "0B", "3B", "System"); // string sense 1
    editDetails()->page()->addKnob(0, 1, 1, 1, "02", "0B", "3C", "System"); // string sense 1
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "0B", "3D", "System"); // string sense 1
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "0B", "3E", "System"); // string sense 1
    editDetails()->page()->addKnob(0, 4, 1, 1, "02", "0B", "3F", "System"); // string sense 1
    editDetails()->page()->addKnob(0, 5, 1, 1, "02", "0B", "40", "System"); // string sense 1
    editDetails()->page()->addGroupBox(1, 4, 1, 5);
    editDetails()->page()->addKnob(2, 0, 1, 1, "02", "0B", "41", "System"); // play feel
    editDetails()->page()->addKnob(2, 1, 1, 1, "02", "0B", "42", "System"); // low velo cut
    editDetails()->page()->addKnob(2, 2, 1, 1, "02", "0B", "43", "System"); // velocity dynamics
    editDetails()->page()->addKnob(2, 3, 1, 1, "02", "0B", "44", "System"); // nuance dynamics
    editDetails()->page()->addKnob(2, 4, 1, 1, "02", "0B", "45", "System"); // nuance trim
    editDetails()->page()->addKnob(2, 5, 1, 1, "02", "0B", "46", "System"); // down shift
    editDetails()->page()->addKnob(2, 6, 1, 1, "02", "0B", "32", "System"); // normal pu gain
    editDetails()->page()->addKnob(2, 7, 1, 1, "02", "0B", "52", "System"); // DevelopLowCut

    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(0);
    editDetails()->page()->addNameEdit(0, 0, 1, 1, "02", "0C", "23", "System", "8"); //GK catagory #9
    editDetails()->page()->newStackControl(9);
    editDetails()->page()->addComboBox(0, 1, 1, 1, "02", "0C", "2B", "System"); // PU select
    editDetails()->page()->addStackControl();
    editDetails()->page()->insertStackField(9, 0, 2, 1, 2);
    editDetails()->page()->addDataKnob(0, 4, 1, 1, "02", "0C", "2C", "SCALE_BASS", "right", 80); //scale
    editDetails()->page()->addComboBox(0, 5, 1, 1, "02", "0C", "2E", "System"); //GK pu position
    editDetails()->page()->addComboBox(0, 6, 1, 1, "02", "0C", "2F", "System"); // pu phase
    editDetails()->page()->addComboBox(0, 7, 1, 1, "02", "0C", "30", "System"); // pu direction
    editDetails()->page()->addComboBox(0, 8, 1, 1, "02", "0C", "31", "System"); // s1/s2 position
    editDetails()->page()->newGroupBox("String distance bridge <> PU [mm]");
    editDetails()->page()->addKnob(0, 0, 1, 1, "02", "0C", "35", "System"); // string distance 1
    editDetails()->page()->addKnob(0, 1, 1, 1, "02", "0C", "36", "System"); // string distance 2
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "0C", "37", "System"); // string distance 3
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "0C", "38", "System"); // string distance 4
    editDetails()->page()->addKnob(0, 4, 1, 1, "02", "0C", "39", "System"); // string distance 5
    editDetails()->page()->addKnob(0, 5, 1, 1, "02", "0C", "3A", "System"); // string distance 6
    editDetails()->page()->addGroupBox(1, 0, 1, 4);
    editDetails()->page()->newGroupBox("String sensitivity");
    editDetails()->page()->addKnob(0, 0, 1, 1, "02", "0C", "3B", "System"); // string sense 1
    editDetails()->page()->addKnob(0, 1, 1, 1, "02", "0C", "3C", "System"); // string sense 1
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "0C", "3D", "System"); // string sense 1
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "0C", "3E", "System"); // string sense 1
    editDetails()->page()->addKnob(0, 4, 1, 1, "02", "0C", "3F", "System"); // string sense 1
    editDetails()->page()->addKnob(0, 5, 1, 1, "02", "0C", "40", "System"); // string sense 1
    editDetails()->page()->addGroupBox(1, 4, 1, 5);
    editDetails()->page()->addKnob(2, 0, 1, 1, "02", "0C", "41", "System"); // play feel
    editDetails()->page()->addKnob(2, 1, 1, 1, "02", "0C", "42", "System"); // low velo cut
    editDetails()->page()->addKnob(2, 2, 1, 1, "02", "0C", "43", "System"); // velocity dynamics
    editDetails()->page()->addKnob(2, 3, 1, 1, "02", "0C", "44", "System"); // nuance dynamics
    editDetails()->page()->addKnob(2, 4, 1, 1, "02", "0C", "45", "System"); // nuance trim
    editDetails()->page()->addKnob(2, 5, 1, 1, "02", "0C", "46", "System"); // down shift
    editDetails()->page()->addKnob(2, 6, 1, 1, "02", "0C", "32", "System"); // normal pu gain
    editDetails()->page()->addKnob(2, 7, 1, 1, "02", "0C", "52", "System"); // DevelopLowCut
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(0);
    editDetails()->page()->addNameEdit(0, 0, 1, 1, "02", "0D", "23", "System", "8"); //GK catagory #10
    editDetails()->page()->newStackControl(10);
    editDetails()->page()->addComboBox(0, 1, 1, 1, "02", "0D", "2B", "System"); // PU select
    editDetails()->page()->addStackControl();
    editDetails()->page()->insertStackField(10, 0, 2, 1, 2);
    editDetails()->page()->addDataKnob(0, 4, 1, 1, "02", "0D", "2C", "SCALE_BASS", "right", 80); //scale
    editDetails()->page()->addComboBox(0, 5, 1, 1, "02", "0D", "2E", "System"); //GK pu position
    editDetails()->page()->addComboBox(0, 6, 1, 1, "02", "0D", "2F", "System"); // pu phase
    editDetails()->page()->addComboBox(0, 7, 1, 1, "02", "0D", "30", "System"); // pu direction
    editDetails()->page()->addComboBox(0, 8, 1, 1, "02", "0D", "31", "System"); // s1/s2 position
    editDetails()->page()->newGroupBox("String distance bridge <> PU [mm]");
    editDetails()->page()->addKnob(0, 0, 1, 1, "02", "0D", "35", "System"); // string distance 1
    editDetails()->page()->addKnob(0, 1, 1, 1, "02", "0D", "36", "System"); // string distance 2
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "0D", "37", "System"); // string distance 3
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "0D", "38", "System"); // string distance 4
    editDetails()->page()->addKnob(0, 4, 1, 1, "02", "0D", "39", "System"); // string distance 5
    editDetails()->page()->addKnob(0, 5, 1, 1, "02", "0D", "3A", "System"); // string distance 6
    editDetails()->page()->addGroupBox(1, 0, 1, 4);
    editDetails()->page()->newGroupBox("String sensitivity");
    editDetails()->page()->addKnob(0, 0, 1, 1, "02", "0D", "3B", "System"); // string sense 1
    editDetails()->page()->addKnob(0, 1, 1, 1, "02", "0D", "3C", "System"); // string sense 1
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "0D", "3D", "System"); // string sense 1
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "0D", "3E", "System"); // string sense 1
    editDetails()->page()->addKnob(0, 4, 1, 1, "02", "0D", "3F", "System"); // string sense 1
    editDetails()->page()->addKnob(0, 5, 1, 1, "02", "0D", "40", "System"); // string sense 1
    editDetails()->page()->addGroupBox(1, 4, 1, 5);
    editDetails()->page()->addKnob(2, 0, 1, 1, "02", "0D", "41", "System"); // play feel
    editDetails()->page()->addKnob(2, 1, 1, 1, "02", "0D", "42", "System"); // low velo cut
    editDetails()->page()->addKnob(2, 2, 1, 1, "02", "0D", "43", "System"); // velocity dynamics
    editDetails()->page()->addKnob(2, 3, 1, 1, "02", "0D", "44", "System"); // nuance dynamics
    editDetails()->page()->addKnob(2, 4, 1, 1, "02", "0D", "45", "System"); // nuance trim
    editDetails()->page()->addKnob(2, 5, 1, 1, "02", "0D", "46", "System"); // down shift
    editDetails()->page()->addKnob(2, 6, 1, 1, "02", "0D", "32", "System"); // normal pu gain
    editDetails()->page()->addKnob(2, 7, 1, 1, "02", "0D", "52", "System"); // DevelopLowCut
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(1);
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "04", "33", "System"); // piezo low
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "04", "34", "System"); // piezo high
    editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(1);
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "04", "33", "System"); // piezo low
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "04", "34", "System"); // piezo high
    editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(1);
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "04", "33", "System"); // piezo low
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "04", "34", "System"); // piezo high
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(2);
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "05", "33", "System"); // piezo low
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "05", "34", "System"); // piezo high
    editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(2);
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "05", "33", "System"); // piezo low
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "05", "34", "System"); // piezo high
    editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(2);
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "05", "33", "System"); // piezo low
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "05", "34", "System"); // piezo high
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(3);
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "06", "33", "System"); // piezo low
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "06", "34", "System"); // piezo high
    editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(3);
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "06", "33", "System"); // piezo low
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "06", "34", "System"); // piezo high
    editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(3);
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "06", "33", "System"); // piezo low
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "06", "34", "System"); // piezo high
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(4);
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "07", "33", "System"); // piezo low
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "07", "34", "System"); // piezo high
    editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(4);
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "07", "33", "System"); // piezo low
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "07", "34", "System"); // piezo high
    editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(4);
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "07", "33", "System"); // piezo low
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "07", "34", "System"); // piezo high
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(5);editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(5);editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(5);
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "08", "33", "System"); // piezo low
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "08", "34", "System"); // piezo high
    editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(5);
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "08", "33", "System"); // piezo low
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "08", "34", "System"); // piezo high
    editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(5);
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "08", "33", "System"); // piezo low
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "08", "34", "System"); // piezo high
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(6);editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(6);editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(6);
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "09", "33", "System"); // piezo low
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "09", "34", "System"); // piezo high
    editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(6);
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "09", "33", "System"); // piezo low
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "09", "34", "System"); // piezo high
    editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(6);
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "09", "33", "System"); // piezo low
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "09", "34", "System"); // piezo high
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(7);editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(7);editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(7);
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "0A", "33", "System"); // piezo low
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "0A", "34", "System"); // piezo high
    editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(7);
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "0A", "33", "System"); // piezo low
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "0A", "34", "System"); // piezo high
    editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(7);
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "0A", "33", "System"); // piezo low
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "0A", "34", "System"); // piezo high
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(8);editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(8);editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(8);
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "0B", "33", "System"); // piezo low
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "0B", "34", "System"); // piezo high
    editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(8);
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "0B", "33", "System"); // piezo low
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "0B", "34", "System"); // piezo high
    editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(8);
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "0B", "33", "System"); // piezo low
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "0B", "34", "System"); // piezo high
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(9);editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(9);editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(9);
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "0C", "33", "System"); // piezo low
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "0C", "34", "System"); // piezo high
    editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(9);
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "0C", "33", "System"); // piezo low
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "0C", "34", "System"); // piezo high
    editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(9);
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "0C", "33", "System"); // piezo low
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "0C", "34", "System"); // piezo high
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(10);editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(10);editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(10);
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "0D", "33", "System"); // piezo low
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "0D", "34", "System"); // piezo high
    editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(10);
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "0D", "33", "System"); // piezo low
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "0D", "34", "System"); // piezo high
    editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(10);
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "0D", "33", "System"); // piezo low
    editDetails()->page()->addKnob(0, 3, 1, 1, "02", "0D", "34", "System"); // piezo high
    editDetails()->page()->addStackField();

    editDetails()->addPage("00", "00", "17", "03", "Tables");

    editDetails()->page()->newGroupBox("MIDI PROGRAM TABLE - BANK 0.            Caution: Changes are automatically written to the GR-55.");
    //editDetails()->page()->addMultiComboBox(0, 0, 1, 1, "02", "01", "00", "System");
    editDetails()->page()->addGroupBox(0, 0, 1, 1);
    editDetails()->addPage("00", "00", "17", "04", "Tables");
};
