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
    editDetails()->page()->addLabel(0, 0, 1, 1, text);
    editDetails()->page()->newGroupBox("settings");

    editDetails()->page()->newGroupBox("Patch");
    editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "00", "System", "right", 120); //current patch
    editDetails()->page()->addGroupBox(0, 0, 1, 1);

    editDetails()->page()->newGroupBox("Output Select");
    editDetails()->page()->addComboBox(0, 0, 1, 1, "02", "00", "01", "System",  Qt::AlignCenter); // output select
    editDetails()->page()->addComboBox(0, 1, 1, 1, "02", "00", "16", "System"); // guitar out source
    editDetails()->page()->addGroupBox(1, 0, 1, 1);

    editDetails()->page()->newGroupBox("Guitar Mode - GK setup");
    editDetails()->page()->newStackControl(0);
    editDetails()->page()->addComboBox(0, 0, 1, 1, "02", "00", "00", "System"); //guitar mode GK Set
    editDetails()->page()->addStackControl();
    editDetails()->page()->insertStackField(0, 1, 0, 1, 4);
    editDetails()->page()->addGroupBox(0, 1, 4, 6);



    editDetails()->page()->newGroupBox("System");
    editDetails()->page()->addComboBox(0, 0, 1, 1, "02", "00", "17", "System"); //master tune
    editDetails()->page()->addComboBox(1, 0, 1, 1, "02", "00", "02", "System"); // Assign Hold
    editDetails()->page()->addComboBox(0, 1, 1, 1, "02", "00", "0E", "System"); // EXP PDL Bend range
    editDetails()->page()->addComboBox(1, 1, 1, 1, "02", "00", "15", "System"); // monitor direct
    editDetails()->page()->addGroupBox(2, 0, 1, 1);

    editDetails()->page()->newGroupBox("I/O levels");
    editDetails()->page()->addKnob(0, 0, 1, 1, "02", "00", "1D", "System");     //USB input level
    editDetails()->page()->addKnob(0, 1, 1, 1, "02", "00", "1F", "System");     //USB output level
    editDetails()->page()->addKnob(0, 2, 1, 1, "02", "00", "1B", "System");     //player level
    editDetails()->page()->addGroupBox(3, 0, 1, 1);

    editDetails()->page()->newGroupBox("Midi");
    editDetails()->page()->addComboBox(0, 0, 1, 1, "02", "00", "03", "System"); // midi patch channel
    editDetails()->page()->addComboBox(0, 1, 1, 1, "02", "00", "04", "System"); // PC RX Sw
    editDetails()->page()->addComboBox(0, 2, 1, 1, "02", "00", "05", "System"); // PC TX Sw
    editDetails()->page()->addComboBox(0, 3, 1, 1, "02", "00", "06", "System"); // VLINK TX Channel
    editDetails()->page()->addComboBox(0, 4, 1, 1, "02", "00", "07", "System"); // guitar midi out
    editDetails()->page()->addComboBox(0, 5, 1, 1, "02", "00", "08", "System"); // poly mode
    editDetails()->page()->addComboBox(0, 6, 1, 1, "02", "00", "09", "System"); // chromatic
    editDetails()->page()->addComboBox(0, 7, 1, 1, "02", "00", "0A", "System"); // string channel
    editDetails()->page()->addComboBox(0, 8, 1, 1, "02", "00", "0B", "System"); // data thin
    editDetails()->page()->addComboBox(0, 9, 1, 1, "02", "00", "12", "System"); //midi map
    editDetails()->page()->addGroupBox(4, 0, 1, 7);

    editDetails()->page()->newGroupBox("Pedal Control Data");
    editDetails()->page()->addComboBox(0, 0, 1, 1, "02", "00", "0C", "System"); // CTL cc#
    editDetails()->page()->addComboBox(0, 1, 1, 1, "02", "00", "0D", "System"); // EXP cc#
    editDetails()->page()->addComboBox(0, 2, 1, 1, "02", "00", "0F", "System"); //GK VOL cc#
    editDetails()->page()->addComboBox(0, 3, 1, 1, "02", "00", "10", "System"); //GK S1 cc#
    editDetails()->page()->addComboBox(0, 4, 1, 1, "02", "00", "11", "System"); //GK S2 cc#
    editDetails()->page()->addGroupBox(5, 0, 1, 7);

    editDetails()->page()->addGroupBox(1, 0, 1, 1);

    editDetails()->page()->newStackField(0);
    editDetails()->page()->addNameEdit(0, 0, 1, 1, "02", "04", "00", "System", "8"); //GK catagory #1
    editDetails()->page()->addComboBox(0, 1, 1, 1, "02", "04", "08", "System"); // PU select
    editDetails()->page()->addDataKnob(0, 2, 1, 1, "02", "04", "09", "SCALE");     //scale
    editDetails()->page()->addComboBox(0, 3, 1, 1, "02", "04", "0B", "System"); // pu phase
    editDetails()->page()->addComboBox(0, 4, 1, 1, "02", "04", "0C", "System"); // pu direction
    editDetails()->page()->addComboBox(0, 5, 1, 1, "02", "04", "0D", "System"); // s1/s2 position
    editDetails()->page()->addComboBox(0, 6, 1, 1, "02", "04", "0E", "System"); // normal pu gain
    editDetails()->page()->addComboBox(1, 0, 1, 1, "02", "04", "11", "System"); // string distance 1
    editDetails()->page()->addComboBox(1, 1, 1, 1, "02", "04", "12", "System"); // string distance 2
    editDetails()->page()->addComboBox(1, 2, 1, 1, "02", "04", "13", "System"); // string distance 3
    editDetails()->page()->addComboBox(1, 3, 1, 1, "02", "04", "14", "System"); // string distance 4
    editDetails()->page()->addComboBox(1, 4, 1, 1, "02", "04", "15", "System"); // string distance 5
    editDetails()->page()->addComboBox(1, 5, 1, 1, "02", "04", "16", "System"); // string distance 6
    editDetails()->page()->addKnob(2, 0, 1, 1, "02", "04", "17", "System"); // string sense 1
    editDetails()->page()->addKnob(2, 1, 1, 1, "02", "04", "18", "System"); // string sense 1
    editDetails()->page()->addKnob(2, 2, 1, 1, "02", "04", "19", "System"); // string sense 1
    editDetails()->page()->addKnob(2, 3, 1, 1, "02", "04", "1A", "System"); // string sense 1
    editDetails()->page()->addKnob(2, 4, 1, 1, "02", "04", "1B", "System"); // string sense 1
    editDetails()->page()->addKnob(2, 5, 1, 1, "02", "04", "1C", "System"); // string sense 1
    editDetails()->page()->addKnob(3, 0, 1, 1, "02", "04", "1D", "System"); // play feel
    editDetails()->page()->addKnob(3, 1, 1, 1, "02", "04", "1E", "System"); // low velo cut
    editDetails()->page()->addKnob(3, 2, 1, 1, "02", "04", "1F", "System"); // velocity dynamics
    editDetails()->page()->addKnob(3, 3, 1, 1, "02", "04", "20", "System"); // nuance dynamics
    editDetails()->page()->addKnob(3, 4, 1, 1, "02", "04", "21", "System"); // nuance trim
    editDetails()->page()->addKnob(3, 5, 1, 1, "02", "04", "22", "System"); // down shift
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(0);
    editDetails()->page()->addNameEdit(0, 0, 1, 1, "02", "05", "00", "System", "8"); //GK catagory #2
    editDetails()->page()->addComboBox(0, 1, 1, 1, "02", "05", "08", "System"); // PU select
    editDetails()->page()->addDataKnob(0, 2, 1, 1, "02", "05", "09", "SCALE");     //scale
    editDetails()->page()->addComboBox(0, 3, 1, 1, "02", "05", "0B", "System"); // pu phase
    editDetails()->page()->addComboBox(0, 4, 1, 1, "02", "05", "0C", "System"); // pu direction
    editDetails()->page()->addComboBox(0, 5, 1, 1, "02", "05", "0D", "System"); // s1/s2 position
    editDetails()->page()->addComboBox(0, 6, 1, 1, "02", "05", "0E", "System"); // normal pu gain
    editDetails()->page()->addComboBox(1, 0, 1, 1, "02", "05", "11", "System"); // string distance 1
    editDetails()->page()->addComboBox(1, 1, 1, 1, "02", "05", "12", "System"); // string distance 2
    editDetails()->page()->addComboBox(1, 2, 1, 1, "02", "05", "13", "System"); // string distance 3
    editDetails()->page()->addComboBox(1, 3, 1, 1, "02", "05", "14", "System"); // string distance 4
    editDetails()->page()->addComboBox(1, 4, 1, 1, "02", "05", "15", "System"); // string distance 5
    editDetails()->page()->addComboBox(1, 5, 1, 1, "02", "05", "16", "System"); // string distance 6
    editDetails()->page()->addKnob(2, 0, 1, 1, "02", "05", "17", "System"); // string sense 1
    editDetails()->page()->addKnob(2, 1, 1, 1, "02", "05", "18", "System"); // string sense 1
    editDetails()->page()->addKnob(2, 2, 1, 1, "02", "05", "19", "System"); // string sense 1
    editDetails()->page()->addKnob(2, 3, 1, 1, "02", "05", "1A", "System"); // string sense 1
    editDetails()->page()->addKnob(2, 4, 1, 1, "02", "05", "1B", "System"); // string sense 1
    editDetails()->page()->addKnob(2, 5, 1, 1, "02", "05", "1C", "System"); // string sense 1
    editDetails()->page()->addKnob(3, 0, 1, 1, "02", "05", "1D", "System"); // play feel
    editDetails()->page()->addKnob(3, 1, 1, 1, "02", "05", "1E", "System"); // low velo cut
    editDetails()->page()->addKnob(3, 2, 1, 1, "02", "05", "1F", "System"); // velocity dynamics
    editDetails()->page()->addKnob(3, 3, 1, 1, "02", "05", "20", "System"); // nuance dynamics
    editDetails()->page()->addKnob(3, 4, 1, 1, "02", "05", "21", "System"); // nuance trim
    editDetails()->page()->addKnob(3, 5, 1, 1, "02", "05", "22", "System"); // down shift
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(0);
    editDetails()->page()->addNameEdit(0, 0, 1, 1, "02", "06", "00", "System", "8"); //GK catagory #3
    editDetails()->page()->addComboBox(0, 1, 1, 1, "02", "06", "08", "System"); // PU select
    editDetails()->page()->addDataKnob(0, 2, 1, 1, "02", "06", "09", "SCALE");     //scale
    editDetails()->page()->addComboBox(0, 3, 1, 1, "02", "06", "0B", "System"); // pu phase
    editDetails()->page()->addComboBox(0, 4, 1, 1, "02", "06", "0C", "System"); // pu direction
    editDetails()->page()->addComboBox(0, 5, 1, 1, "02", "06", "0D", "System"); // s1/s2 position
    editDetails()->page()->addComboBox(0, 6, 1, 1, "02", "06", "0E", "System"); // normal pu gain
    editDetails()->page()->addComboBox(1, 0, 1, 1, "02", "06", "11", "System"); // string distance 1
    editDetails()->page()->addComboBox(1, 1, 1, 1, "02", "06", "12", "System"); // string distance 2
    editDetails()->page()->addComboBox(1, 2, 1, 1, "02", "06", "13", "System"); // string distance 3
    editDetails()->page()->addComboBox(1, 3, 1, 1, "02", "06", "14", "System"); // string distance 4
    editDetails()->page()->addComboBox(1, 4, 1, 1, "02", "06", "15", "System"); // string distance 5
    editDetails()->page()->addComboBox(1, 5, 1, 1, "02", "06", "16", "System"); // string distance 6
    editDetails()->page()->addKnob(2, 0, 1, 1, "02", "06", "17", "System"); // string sense 1
    editDetails()->page()->addKnob(2, 1, 1, 1, "02", "06", "18", "System"); // string sense 1
    editDetails()->page()->addKnob(2, 2, 1, 1, "02", "06", "19", "System"); // string sense 1
    editDetails()->page()->addKnob(2, 3, 1, 1, "02", "06", "1A", "System"); // string sense 1
    editDetails()->page()->addKnob(2, 4, 1, 1, "02", "06", "1B", "System"); // string sense 1
    editDetails()->page()->addKnob(2, 5, 1, 1, "02", "06", "1C", "System"); // string sense 1
    editDetails()->page()->addKnob(3, 0, 1, 1, "02", "06", "1D", "System"); // play feel
    editDetails()->page()->addKnob(3, 1, 1, 1, "02", "06", "1E", "System"); // low velo cut
    editDetails()->page()->addKnob(3, 2, 1, 1, "02", "06", "1F", "System"); // velocity dynamics
    editDetails()->page()->addKnob(3, 3, 1, 1, "02", "06", "20", "System"); // nuance dynamics
    editDetails()->page()->addKnob(3, 4, 1, 1, "02", "06", "21", "System"); // nuance trim
    editDetails()->page()->addKnob(3, 5, 1, 1, "02", "06", "22", "System"); // down shift
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(0);
    editDetails()->page()->addNameEdit(0, 0, 1, 1, "02", "07", "00", "System", "8"); //GK catagory #4
    editDetails()->page()->addComboBox(0, 1, 1, 1, "02", "07", "08", "System"); // PU select
    editDetails()->page()->addDataKnob(0, 2, 1, 1, "02", "07", "09", "SCALE");     //scale
    editDetails()->page()->addComboBox(0, 3, 1, 1, "02", "07", "0B", "System"); // pu phase
    editDetails()->page()->addComboBox(0, 4, 1, 1, "02", "07", "0C", "System"); // pu direction
    editDetails()->page()->addComboBox(0, 5, 1, 1, "02", "07", "0D", "System"); // s1/s2 position
    editDetails()->page()->addComboBox(0, 6, 1, 1, "02", "07", "0E", "System"); // normal pu gain
    editDetails()->page()->addComboBox(1, 0, 1, 1, "02", "07", "11", "System"); // string distance 1
    editDetails()->page()->addComboBox(1, 1, 1, 1, "02", "07", "12", "System"); // string distance 2
    editDetails()->page()->addComboBox(1, 2, 1, 1, "02", "07", "13", "System"); // string distance 3
    editDetails()->page()->addComboBox(1, 3, 1, 1, "02", "07", "14", "System"); // string distance 4
    editDetails()->page()->addComboBox(1, 4, 1, 1, "02", "07", "15", "System"); // string distance 5
    editDetails()->page()->addComboBox(1, 5, 1, 1, "02", "07", "16", "System"); // string distance 6
    editDetails()->page()->addKnob(2, 0, 1, 1, "02", "07", "17", "System"); // string sense 1
    editDetails()->page()->addKnob(2, 1, 1, 1, "02", "07", "18", "System"); // string sense 1
    editDetails()->page()->addKnob(2, 2, 1, 1, "02", "07", "19", "System"); // string sense 1
    editDetails()->page()->addKnob(2, 3, 1, 1, "02", "07", "1A", "System"); // string sense 1
    editDetails()->page()->addKnob(2, 4, 1, 1, "02", "07", "1B", "System"); // string sense 1
    editDetails()->page()->addKnob(2, 5, 1, 1, "02", "07", "1C", "System"); // string sense 1
    editDetails()->page()->addKnob(3, 0, 1, 1, "02", "07", "1D", "System"); // play feel
    editDetails()->page()->addKnob(3, 1, 1, 1, "02", "07", "1E", "System"); // low velo cut
    editDetails()->page()->addKnob(3, 2, 1, 1, "02", "07", "1F", "System"); // velocity dynamics
    editDetails()->page()->addKnob(3, 3, 1, 1, "02", "07", "20", "System"); // nuance dynamics
    editDetails()->page()->addKnob(3, 4, 1, 1, "02", "07", "21", "System"); // nuance trim
    editDetails()->page()->addKnob(3, 5, 1, 1, "02", "07", "22", "System"); // down shift
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(0);
    editDetails()->page()->addNameEdit(0, 0, 1, 1, "02", "08", "00", "System", "8"); //GK catagory #5
    editDetails()->page()->addComboBox(0, 1, 1, 1, "02", "08", "08", "System"); // PU select
    editDetails()->page()->addDataKnob(0, 2, 1, 1, "02", "08", "09", "SCALE");     //scale
    editDetails()->page()->addComboBox(0, 3, 1, 1, "02", "08", "0B", "System"); // pu phase
    editDetails()->page()->addComboBox(0, 4, 1, 1, "02", "08", "0C", "System"); // pu direction
    editDetails()->page()->addComboBox(0, 5, 1, 1, "02", "08", "0D", "System"); // s1/s2 position
    editDetails()->page()->addComboBox(0, 6, 1, 1, "02", "08", "0E", "System"); // normal pu gain
    editDetails()->page()->addComboBox(1, 0, 1, 1, "02", "08", "11", "System"); // string distance 1
    editDetails()->page()->addComboBox(1, 1, 1, 1, "02", "08", "12", "System"); // string distance 2
    editDetails()->page()->addComboBox(1, 2, 1, 1, "02", "08", "13", "System"); // string distance 3
    editDetails()->page()->addComboBox(1, 3, 1, 1, "02", "08", "14", "System"); // string distance 4
    editDetails()->page()->addComboBox(1, 4, 1, 1, "02", "08", "15", "System"); // string distance 5
    editDetails()->page()->addComboBox(1, 5, 1, 1, "02", "08", "16", "System"); // string distance 6
    editDetails()->page()->addKnob(2, 0, 1, 1, "02", "08", "17", "System"); // string sense 1
    editDetails()->page()->addKnob(2, 1, 1, 1, "02", "08", "18", "System"); // string sense 1
    editDetails()->page()->addKnob(2, 2, 1, 1, "02", "08", "19", "System"); // string sense 1
    editDetails()->page()->addKnob(2, 3, 1, 1, "02", "08", "1A", "System"); // string sense 1
    editDetails()->page()->addKnob(2, 4, 1, 1, "02", "08", "1B", "System"); // string sense 1
    editDetails()->page()->addKnob(2, 5, 1, 1, "02", "08", "1C", "System"); // string sense 1
    editDetails()->page()->addKnob(3, 0, 1, 1, "02", "08", "1D", "System"); // play feel
    editDetails()->page()->addKnob(3, 1, 1, 1, "02", "08", "1E", "System"); // low velo cut
    editDetails()->page()->addKnob(3, 2, 1, 1, "02", "08", "1F", "System"); // velocity dynamics
    editDetails()->page()->addKnob(3, 3, 1, 1, "02", "08", "20", "System"); // nuance dynamics
    editDetails()->page()->addKnob(3, 4, 1, 1, "02", "08", "21", "System"); // nuance trim
    editDetails()->page()->addKnob(3, 5, 1, 1, "02", "08", "22", "System"); // down shift
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(0);
    editDetails()->page()->addNameEdit(0, 0, 1, 1, "02", "09", "00", "System", "8"); //GK catagory #6
    editDetails()->page()->addComboBox(0, 1, 1, 1, "02", "09", "08", "System"); // PU select
    editDetails()->page()->addDataKnob(0, 2, 1, 1, "02", "09", "09", "SCALE");     //scale
    editDetails()->page()->addComboBox(0, 3, 1, 1, "02", "09", "0B", "System"); // pu phase
    editDetails()->page()->addComboBox(0, 4, 1, 1, "02", "09", "0C", "System"); // pu direction
    editDetails()->page()->addComboBox(0, 5, 1, 1, "02", "09", "0D", "System"); // s1/s2 position
    editDetails()->page()->addComboBox(0, 6, 1, 1, "02", "09", "0E", "System"); // normal pu gain
    editDetails()->page()->addComboBox(1, 0, 1, 1, "02", "09", "11", "System"); // string distance 1
    editDetails()->page()->addComboBox(1, 1, 1, 1, "02", "09", "12", "System"); // string distance 2
    editDetails()->page()->addComboBox(1, 2, 1, 1, "02", "09", "13", "System"); // string distance 3
    editDetails()->page()->addComboBox(1, 3, 1, 1, "02", "09", "14", "System"); // string distance 4
    editDetails()->page()->addComboBox(1, 4, 1, 1, "02", "09", "15", "System"); // string distance 5
    editDetails()->page()->addComboBox(1, 5, 1, 1, "02", "09", "16", "System"); // string distance 6
    editDetails()->page()->addKnob(2, 0, 1, 1, "02", "09", "17", "System"); // string sense 1
    editDetails()->page()->addKnob(2, 1, 1, 1, "02", "09", "18", "System"); // string sense 1
    editDetails()->page()->addKnob(2, 2, 1, 1, "02", "09", "19", "System"); // string sense 1
    editDetails()->page()->addKnob(2, 3, 1, 1, "02", "09", "1A", "System"); // string sense 1
    editDetails()->page()->addKnob(2, 4, 1, 1, "02", "09", "1B", "System"); // string sense 1
    editDetails()->page()->addKnob(2, 5, 1, 1, "02", "09", "1C", "System"); // string sense 1
    editDetails()->page()->addKnob(3, 0, 1, 1, "02", "09", "1D", "System"); // play feel
    editDetails()->page()->addKnob(3, 1, 1, 1, "02", "09", "1E", "System"); // low velo cut
    editDetails()->page()->addKnob(3, 2, 1, 1, "02", "09", "1F", "System"); // velocity dynamics
    editDetails()->page()->addKnob(3, 3, 1, 1, "02", "09", "20", "System"); // nuance dynamics
    editDetails()->page()->addKnob(3, 4, 1, 1, "02", "09", "21", "System"); // nuance trim
    editDetails()->page()->addKnob(3, 5, 1, 1, "02", "09", "22", "System"); // down shift
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(0);
    editDetails()->page()->addNameEdit(0, 0, 1, 1, "02", "0A", "00", "System", "8"); //GK catagory #7
    editDetails()->page()->addComboBox(0, 1, 1, 1, "02", "0A", "08", "System"); // PU select
    editDetails()->page()->addDataKnob(0, 2, 1, 1, "02", "0A", "09", "SCALE");     //scale
    editDetails()->page()->addComboBox(0, 3, 1, 1, "02", "0A", "0B", "System"); // pu phase
    editDetails()->page()->addComboBox(0, 4, 1, 1, "02", "0A", "0C", "System"); // pu direction
    editDetails()->page()->addComboBox(0, 5, 1, 1, "02", "0A", "0D", "System"); // s1/s2 position
    editDetails()->page()->addComboBox(0, 6, 1, 1, "02", "0A", "0E", "System"); // normal pu gain
    editDetails()->page()->addComboBox(1, 0, 1, 1, "02", "0A", "11", "System"); // string distance 1
    editDetails()->page()->addComboBox(1, 1, 1, 1, "02", "0A", "12", "System"); // string distance 2
    editDetails()->page()->addComboBox(1, 2, 1, 1, "02", "0A", "13", "System"); // string distance 3
    editDetails()->page()->addComboBox(1, 3, 1, 1, "02", "0A", "14", "System"); // string distance 4
    editDetails()->page()->addComboBox(1, 4, 1, 1, "02", "0A", "15", "System"); // string distance 5
    editDetails()->page()->addComboBox(1, 5, 1, 1, "02", "0A", "16", "System"); // string distance 6
    editDetails()->page()->addKnob(2, 0, 1, 1, "02", "0A", "17", "System"); // string sense 1
    editDetails()->page()->addKnob(2, 1, 1, 1, "02", "0A", "18", "System"); // string sense 1
    editDetails()->page()->addKnob(2, 2, 1, 1, "02", "0A", "19", "System"); // string sense 1
    editDetails()->page()->addKnob(2, 3, 1, 1, "02", "0A", "1A", "System"); // string sense 1
    editDetails()->page()->addKnob(2, 4, 1, 1, "02", "0A", "1B", "System"); // string sense 1
    editDetails()->page()->addKnob(2, 5, 1, 1, "02", "0A", "1C", "System"); // string sense 1
    editDetails()->page()->addKnob(3, 0, 1, 1, "02", "0A", "1D", "System"); // play feel
    editDetails()->page()->addKnob(3, 1, 1, 1, "02", "0A", "1E", "System"); // low velo cut
    editDetails()->page()->addKnob(3, 2, 1, 1, "02", "0A", "1F", "System"); // velocity dynamics
    editDetails()->page()->addKnob(3, 3, 1, 1, "02", "0A", "20", "System"); // nuance dynamics
    editDetails()->page()->addKnob(3, 4, 1, 1, "02", "0A", "21", "System"); // nuance trim
    editDetails()->page()->addKnob(3, 5, 1, 1, "02", "0A", "22", "System"); // down shift
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(0);
    editDetails()->page()->addNameEdit(0, 0, 1, 1, "02", "0B", "00", "System", "8"); //GK catagory #8
    editDetails()->page()->addComboBox(0, 1, 1, 1, "02", "0B", "08", "System"); // PU select
    editDetails()->page()->addDataKnob(0, 2, 1, 1, "02", "0B", "09", "SCALE");     //scale
    editDetails()->page()->addComboBox(0, 3, 1, 1, "02", "0B", "0B", "System"); // pu phase
    editDetails()->page()->addComboBox(0, 4, 1, 1, "02", "0B", "0C", "System"); // pu direction
    editDetails()->page()->addComboBox(0, 5, 1, 1, "02", "0B", "0D", "System"); // s1/s2 position
    editDetails()->page()->addComboBox(0, 6, 1, 1, "02", "0B", "0E", "System"); // normal pu gain
    editDetails()->page()->addComboBox(1, 0, 1, 1, "02", "0B", "11", "System"); // string distance 1
    editDetails()->page()->addComboBox(1, 1, 1, 1, "02", "0B", "12", "System"); // string distance 2
    editDetails()->page()->addComboBox(1, 2, 1, 1, "02", "0B", "13", "System"); // string distance 3
    editDetails()->page()->addComboBox(1, 3, 1, 1, "02", "0B", "14", "System"); // string distance 4
    editDetails()->page()->addComboBox(1, 4, 1, 1, "02", "0B", "15", "System"); // string distance 5
    editDetails()->page()->addComboBox(1, 5, 1, 1, "02", "0B", "16", "System"); // string distance 6
    editDetails()->page()->addKnob(2, 0, 1, 1, "02", "0B", "17", "System"); // string sense 1
    editDetails()->page()->addKnob(2, 1, 1, 1, "02", "0B", "18", "System"); // string sense 1
    editDetails()->page()->addKnob(2, 2, 1, 1, "02", "0B", "19", "System"); // string sense 1
    editDetails()->page()->addKnob(2, 3, 1, 1, "02", "0B", "1A", "System"); // string sense 1
    editDetails()->page()->addKnob(2, 4, 1, 1, "02", "0B", "1B", "System"); // string sense 1
    editDetails()->page()->addKnob(2, 5, 1, 1, "02", "0B", "1C", "System"); // string sense 1
    editDetails()->page()->addKnob(3, 0, 1, 1, "02", "0B", "1D", "System"); // play feel
    editDetails()->page()->addKnob(3, 1, 1, 1, "02", "0B", "1E", "System"); // low velo cut
    editDetails()->page()->addKnob(3, 2, 1, 1, "02", "0B", "1F", "System"); // velocity dynamics
    editDetails()->page()->addKnob(3, 3, 1, 1, "02", "0B", "20", "System"); // nuance dynamics
    editDetails()->page()->addKnob(3, 4, 1, 1, "02", "0B", "21", "System"); // nuance trim
    editDetails()->page()->addKnob(3, 5, 1, 1, "02", "0B", "22", "System"); // down shift
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(0);
    editDetails()->page()->addNameEdit(0, 0, 1, 1, "02", "0C", "00", "System", "8"); //GK catagory #9
    editDetails()->page()->addComboBox(0, 1, 1, 1, "02", "0C", "08", "System"); // PU select
    editDetails()->page()->addDataKnob(0, 2, 1, 1, "02", "0C", "09", "SCALE");     //scale
    editDetails()->page()->addComboBox(0, 3, 1, 1, "02", "0C", "0B", "System"); // pu phase
    editDetails()->page()->addComboBox(0, 4, 1, 1, "02", "0C", "0C", "System"); // pu direction
    editDetails()->page()->addComboBox(0, 5, 1, 1, "02", "0C", "0D", "System"); // s1/s2 position
    editDetails()->page()->addComboBox(0, 6, 1, 1, "02", "0C", "0E", "System"); // normal pu gain
    editDetails()->page()->addComboBox(1, 0, 1, 1, "02", "0C", "11", "System"); // string distance 1
    editDetails()->page()->addComboBox(1, 1, 1, 1, "02", "0C", "12", "System"); // string distance 2
    editDetails()->page()->addComboBox(1, 2, 1, 1, "02", "0C", "13", "System"); // string distance 3
    editDetails()->page()->addComboBox(1, 3, 1, 1, "02", "0C", "14", "System"); // string distance 4
    editDetails()->page()->addComboBox(1, 4, 1, 1, "02", "0C", "15", "System"); // string distance 5
    editDetails()->page()->addComboBox(1, 5, 1, 1, "02", "0C", "16", "System"); // string distance 6
    editDetails()->page()->addKnob(2, 0, 1, 1, "02", "0C", "17", "System"); // string sense 1
    editDetails()->page()->addKnob(2, 1, 1, 1, "02", "0C", "18", "System"); // string sense 1
    editDetails()->page()->addKnob(2, 2, 1, 1, "02", "0C", "19", "System"); // string sense 1
    editDetails()->page()->addKnob(2, 3, 1, 1, "02", "0C", "1A", "System"); // string sense 1
    editDetails()->page()->addKnob(2, 4, 1, 1, "02", "0C", "1B", "System"); // string sense 1
    editDetails()->page()->addKnob(2, 5, 1, 1, "02", "0C", "1C", "System"); // string sense 1
    editDetails()->page()->addKnob(3, 0, 1, 1, "02", "0C", "1D", "System"); // play feel
    editDetails()->page()->addKnob(3, 1, 1, 1, "02", "0C", "1E", "System"); // low velo cut
    editDetails()->page()->addKnob(3, 2, 1, 1, "02", "0C", "1F", "System"); // velocity dynamics
    editDetails()->page()->addKnob(3, 3, 1, 1, "02", "0C", "20", "System"); // nuance dynamics
    editDetails()->page()->addKnob(3, 4, 1, 1, "02", "0C", "21", "System"); // nuance trim
    editDetails()->page()->addKnob(3, 5, 1, 1, "02", "0C", "22", "System"); // down shift
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(0);
    editDetails()->page()->addNameEdit(0, 0, 1, 1, "02", "0D", "00", "System", "8"); //GK catagory #10
    editDetails()->page()->addComboBox(0, 1, 1, 1, "02", "0D", "08", "System"); // PU select
    editDetails()->page()->addDataKnob(0, 2, 1, 1, "02", "0D", "09", "SCALE");     //scale
    editDetails()->page()->addComboBox(0, 3, 1, 1, "02", "0D", "0B", "System"); // pu phase
    editDetails()->page()->addComboBox(0, 4, 1, 1, "02", "0D", "0C", "System"); // pu direction
    editDetails()->page()->addComboBox(0, 5, 1, 1, "02", "0D", "0D", "System"); // s1/s2 position
    editDetails()->page()->addComboBox(0, 6, 1, 1, "02", "0D", "0E", "System"); // normal pu gain
    editDetails()->page()->addComboBox(1, 0, 1, 1, "02", "0D", "11", "System"); // string distance 1
    editDetails()->page()->addComboBox(1, 1, 1, 1, "02", "0D", "12", "System"); // string distance 2
    editDetails()->page()->addComboBox(1, 2, 1, 1, "02", "0D", "13", "System"); // string distance 3
    editDetails()->page()->addComboBox(1, 3, 1, 1, "02", "0D", "14", "System"); // string distance 4
    editDetails()->page()->addComboBox(1, 4, 1, 1, "02", "0D", "15", "System"); // string distance 5
    editDetails()->page()->addComboBox(1, 5, 1, 1, "02", "0D", "16", "System"); // string distance 6
    editDetails()->page()->addKnob(2, 0, 1, 1, "02", "0D", "17", "System"); // string sense 1
    editDetails()->page()->addKnob(2, 1, 1, 1, "02", "0D", "18", "System"); // string sense 1
    editDetails()->page()->addKnob(2, 2, 1, 1, "02", "0D", "19", "System"); // string sense 1
    editDetails()->page()->addKnob(2, 3, 1, 1, "02", "0D", "1A", "System"); // string sense 1
    editDetails()->page()->addKnob(2, 4, 1, 1, "02", "0D", "1B", "System"); // string sense 1
    editDetails()->page()->addKnob(2, 5, 1, 1, "02", "0D", "1C", "System"); // string sense 1
    editDetails()->page()->addKnob(3, 0, 1, 1, "02", "0D", "1D", "System"); // play feel
    editDetails()->page()->addKnob(3, 1, 1, 1, "02", "0D", "1E", "System"); // low velo cut
    editDetails()->page()->addKnob(3, 2, 1, 1, "02", "0D", "1F", "System"); // velocity dynamics
    editDetails()->page()->addKnob(3, 3, 1, 1, "02", "0D", "20", "System"); // nuance dynamics
    editDetails()->page()->addKnob(3, 4, 1, 1, "02", "0D", "21", "System"); // nuance trim
    editDetails()->page()->addKnob(3, 5, 1, 1, "02", "0D", "22", "System"); // down shift
    editDetails()->page()->addStackField();



    editDetails()->addPage();

};
