/****************************************************************************
**
** Copyright (C) 2007~2016 Colin Willcocks.
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

#include "soundSource_synth_a.h"
#include "Preferences.h"

soundsource_synth_a::soundsource_synth_a(QWidget *parent)
    : soundSource(parent)
{
    /* SYNTH_A */
    setImage(":/images/ch_a.png");
    setLSB("20", "00");
    setSwitch("20", "INVERT", "03");
    setComboBox("20", "routeSwitch", "16");
    setKnob1("20", "00", "01");
    setKnob2("20", "00", "04");
    editDetails()->patchPos(2236, 296, "20", "00");
    setEditPages();
}

void soundsource_synth_a::updateSignal()
{
    updateSwitch("20", "00", "03");
    updateComboBox("20", "routeSwitch", "16");
    updateKnob1("20", "00", "01");
    updateKnob2("20", "00", "04");
}

void soundsource_synth_a::setEditPages()
{
    editDetails()->page()->newGroupBox("Tone");
    editDetails()->page()->addSwitch(0, 0, 1, 1, "20", "00", "03", "invert", Qt::AlignCenter);   // off/on effect
    editDetails()->page()->addComboBox(1, 0, 1, 1, "20", "00", "16");           //line route
    editDetails()->page()->addKnob(0, 1, 2, 1, "20", "00", "04");               // tone level
    editDetails()->page()->addKnob(0, 2, 2, 1, "20", "00", "09");               // pan
    editDetails()->page()->addSwitch(0, 3, 1, 1, "20", "00", "08");             //nuance
    editDetails()->page()->addSwitch(1, 3, 1, 1, "20", "00", "07");             //legato
    editDetails()->page()->addGroupBox(0, 0, 1, 4);

    editDetails()->page()->newGroupBox(tr("PCM Synth"));
    editDetails()->page()->addComboBox(0, 1, 1, 1, "20", "00", "01");           // PCM tone
    editDetails()->page()->addGroupBox(0, 4, 1, 3);

    editDetails()->page()->newGroupBox("Pitch");
    editDetails()->page()->addSwitch(0, 0, 1, 1, "20", "00", "06");             //chromatic
    editDetails()->page()->addKnob(0, 1, 1, 1, "20", "00", "05");               //octave
    editDetails()->page()->addKnob(0, 2, 1, 1, "20", "00", "0A");               // pitch shift
    editDetails()->page()->addKnob(0, 3, 1, 1, "20", "00", "0B");               // pitch fine
    editDetails()->page()->addGroupBox(0, 7, 1, 3);

    editDetails()->page()->newGroupBox("Portamento");
    editDetails()->page()->addComboBox(0, 0, 1, 1, "20", "00", "0C", "bottom", Qt::AlignLeft); //portamento sw
    editDetails()->page()->addComboBox(1, 0, 1, 1, "30", "00", "1B");           //portamento type
    editDetails()->page()->addDataKnob(0, 1, 2, 1, "20", "00", "0D", "PORTAMENTO"); // portamento time
    editDetails()->page()->addGroupBox(0, 10, 1, 2);

    editDetails()->page()->newGroupBox(tr("String level"));
    editDetails()->page()->addKnob(0, 0, 1, 1, "20", "00", "10");            //string level 1
    editDetails()->page()->addKnob(0, 1, 1, 1, "20", "00", "11");            //string level 2
    editDetails()->page()->addKnob(0, 2, 1, 1, "20", "00", "12");            //string level 3
    editDetails()->page()->addKnob(0, 3, 1, 1, "20", "00", "13");            //string level 4
    editDetails()->page()->addKnob(0, 4, 1, 1, "20", "00", "14");            //string level 5
    editDetails()->page()->addKnob(0, 5, 1, 1, "20", "00", "15");            //string level 6
    editDetails()->page()->addGroupBox(1, 0, 1, 5);

    editDetails()->page()->newGroupBox(tr("Filter"));
    editDetails()->page()->addComboBox(0, 0, 1, 1, "30", "00", "00");        //filter type
    editDetails()->page()->addKnob(0, 1, 1, 1, "30", "00", "01");            //cutoff
    editDetails()->page()->addKnob(0, 2, 1, 1, "30", "00", "02");            //resonance
    editDetails()->page()->addGroupBox(1, 5, 1, 3);

    editDetails()->page()->newGroupBox(tr("Filter Cutoff"));
    editDetails()->page()->addKnob(0, 0, 1, 1, "30", "00", "03");            //cutoff velo sens
    editDetails()->page()->addComboBox(0, 1, 1, 1, "30", "00", "04");        //cutoff velo curve
    editDetails()->page()->addKnob(0, 2, 1, 1, "30", "00", "05");            //cutoff key follow
    editDetails()->page()->addKnob(0, 3, 1, 1, "30", "00", "06");            //cutoff nuance sens
    editDetails()->page()->addGroupBox(1, 8, 1, 4);

    editDetails()->page()->newGroupBox(tr("Pitch ENV"));
    editDetails()->page()->addKnob(0, 0, 1, 1, "30", "00", "17");            //env vel sens
    editDetails()->page()->addKnob(0, 1, 1, 1, "30", "00", "18");            //env depth
    editDetails()->page()->addKnob(0, 2, 1, 1, "30", "00", "19");            //attack time
    editDetails()->page()->addKnob(0, 3, 1, 1, "30", "00", "1A");            //decay time
    editDetails()->page()->addGroupBox(2, 8, 1, 4);


    editDetails()->page()->newGroupBox(tr("TVF"));
    editDetails()->page()->addKnob(0, 0, 1, 1, "30", "00", "07");            //env depth
    editDetails()->page()->addKnob(0, 1, 1, 1, "30", "00", "08");            //attack time
    editDetails()->page()->addKnob(0, 2, 1, 1, "30", "00", "09");            //decay time
    editDetails()->page()->addKnob(0, 3, 1, 1, "30", "00", "0A");            //sustain level
    editDetails()->page()->addKnob(0, 4, 1, 1, "30", "00", "0B");            //release time
    editDetails()->page()->addKnob(0, 5, 1, 1, "30", "00", "0C");            //attack velocity sens
    editDetails()->page()->addKnob(0, 6, 1, 1, "30", "00", "0D");            //attack nuance sens
    editDetails()->page()->addGroupBox(2, 0, 1, 6);

    editDetails()->page()->newGroupBox(tr("Velocity"));
    editDetails()->page()->addKnob(0, 7, 1, 1, "30", "00", "0E");            //level velocity sens
    editDetails()->page()->addComboBox(0, 8, 1, 1, "30", "00", "0F");        //velocity curve type
    editDetails()->page()->addGroupBox(2, 6, 1, 2);


    Preferences *preferences = Preferences::Instance();
    QString text = tr("detailed settings available in multi-window mode");

    editDetails()->page()->newGroupBox(tr("TVA"));
    editDetails()->page()->addKnob(0, 0, 1, 1, "30", "00", "10");            //attack time
    editDetails()->page()->addKnob(0, 1, 1, 1, "30", "00", "11");            //decay time
    editDetails()->page()->addKnob(0, 2, 1, 1, "30", "00", "12");            //sustain level
    editDetails()->page()->addKnob(0, 3, 1, 1, "30", "00", "13");            //release time
    if(preferences->getPreferences("Window", "Single", "bool")!="true")
    {
        editDetails()->page()->addKnob(1, 0, 1, 1, "30", "00", "14");            //attack velocity sense
        editDetails()->page()->addKnob(1, 1, 1, 1, "30", "00", "15");            //attack nuance sense
        editDetails()->page()->addKnob(1, 2, 1, 1, "30", "00", "16");            //leve; nuance sense
        editDetails()->page()->addComboBox(1, 3, 1, 1, "20", "00", "0F");        //TVA release mode
    };
    editDetails()->page()->addGroupBox(4, 0, 1, 5);

    editDetails()->page()->newGroupBox(tr("LFO 1"));
    editDetails()->page()->addDataKnob(0, 0, 1, 4, "30", "00", "1C", "RATE","right", 120); //Rate
    if(preferences->getPreferences("Window", "Single", "bool")!="true")
    {
        editDetails()->page()->addKnob(1, 0, 1, 1, "30", "00", "1E");            //pitch depth
        editDetails()->page()->addKnob(1, 1, 1, 1, "30", "00", "1F");            //TVF depth
        editDetails()->page()->addKnob(1, 2, 1, 1, "30", "00", "20");            //TVA depth
        editDetails()->page()->addKnob(1, 3, 1, 1, "30", "00", "21");            //pan depth
    } else { editDetails()->page()->addLabel(1, 0, 1, 4, text); };
    editDetails()->page()->addGroupBox(4, 5, 1, 3);

    editDetails()->page()->newGroupBox(tr("LFO 2"));
    editDetails()->page()->addDataKnob(0, 0, 1, 4, "30", "00", "22", "RATE","right", 120); //Rate
    if(preferences->getPreferences("Window", "Single", "bool")!="true")
    {
        editDetails()->page()->addKnob(1, 0, 1, 1, "30", "00", "24");            //pitch depth
        editDetails()->page()->addKnob(1, 1, 1, 1, "30", "00", "25");            //TVF depth
        editDetails()->page()->addKnob(1, 2, 1, 1, "30", "00", "26");            //TVA depth
        editDetails()->page()->addKnob(1, 3, 1, 1, "30", "00", "27");            //pan depth
    } else { editDetails()->page()->addLabel(1, 0, 1, 4, text); };
    editDetails()->page()->addGroupBox(4, 8, 1, 4);

    editDetails()->addPage();
}
