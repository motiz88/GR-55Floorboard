/****************************************************************************
**
** Copyright (C) 2007~2016 Colin Willcocks.
** Copyright (C) 2005~2007 Uco Mesdag. 
** All rights reserved.
** This file is part of "GT-100 Fx FloorBoard".
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

#include "menuPage_EZ_Edit.h"

menuPage_ez_edit::menuPage_ez_edit(QWidget *parent)
    : menuPage(parent)
{
    setLSB("00", "00");
    setEditPages();
}

void menuPage_ez_edit::updateSignal()
{

}

void menuPage_ez_edit::setEditPages()
{
    //editDetails()->page()->newGroupBox("Patch Creator");
    editDetails()->page()->newGroupBox("Style");
    editDetails()->page()->addEZ_Patch(0, 0, 1, 1, "00", "00", "1B", "middle", Qt::AlignCenter);
    editDetails()->page()->addGroupBox(0, 0, 1, 1);
    editDetails()->addPage("00", "00", "1A", "00", "Tables");

    editDetails()->page()->newGroupBox("Preamp");
    editDetails()->page()->addEZ_amp(0, 0, 1, 1, "07", "00", "02", "Preamp");
    editDetails()->page()->addGroupBox(0, 0, 1, 1);

    editDetails()->page()->newGroupBox("Speaker & Cabinet");
    editDetails()->page()->addEZ_amp(0, 0, 1, 1, "07", "00", "0C", "Speaker");
    editDetails()->page()->addGroupBox(0, 1, 1, 1);
    editDetails()->addPage("00", "00", "1A", "01", "Tables");

    editDetails()->page()->newGroupBox("Distortion Select");
    editDetails()->page()->addSwitch(0, 0, 1, 1, "07", "00", "15", "middle", Qt::AlignCenter);
    editDetails()->page()->addComboBox(1, 0, 1, 1, "07", "00", "18");
    editDetails()->page()->addGroupBox(0, 0, 1, 1);
    editDetails()->page()->newGroupBox("OD/DS Customiser");
    editDetails()->page()->addEZ_amp(1, 0, 1, 1, "07", "00", "18", "Distortion");
    editDetails()->page()->addGroupBox(0, 1, 1, 1);
    editDetails()->addPage("00", "00", "1A", "02", "Tables");

    editDetails()->page()->newGroupBox(tr("Chorus Select"));
    editDetails()->page()->addSwitch(0, 0, 1, 1, "06", "00", "00", "middle", Qt::AlignCenter); //sw
    editDetails()->page()->addComboBox(1, 0, 1, 1, "06", "00", "01");                          //type
    editDetails()->page()->addGroupBox(0, 0, 1, 1);
    editDetails()->page()->newGroupBox("Reverb Select");
    editDetails()->page()->addSwitch(0, 0, 1, 1, "06", "00", "0C", "middle", Qt::AlignCenter); //sw
    editDetails()->page()->addComboBox(1, 0, 1, 1, "06", "00", "0D");   //type
    editDetails()->page()->addGroupBox(1, 0, 1, 1);
    editDetails()->page()->newGroupBox("Delay Select");
    editDetails()->page()->addSwitch(0, 0, 1, 1, "06", "00", "05", "middle", Qt::AlignCenter); //sw
    editDetails()->page()->addComboBox(1, 0, 1, 1, "06", "00", "06"); //type
    editDetails()->page()->addGroupBox(2, 0, 1, 1);
    editDetails()->page()->newGroupBox("Ambience");
    editDetails()->page()->addEZ_amp(0, 0, 1, 1, "07", "00", "11", "Ambience");
    editDetails()->page()->addGroupBox(0, 1, 3, 1);
    editDetails()->addPage("00", "00", "1A", "03", "Tables");

    /*editDetails()->page()->newGroupBox("PCM Tone");
    editDetails()->page()->addEZ_Patch(0, 0, 1, 1, "00", "00", "1B", "middle", Qt::AlignCenter);
    editDetails()->page()->addGroupBox(0, 0, 1, 1);

    editDetails()->page()->newGroupBox("Synth");
    editDetails()->page()->addEZ_amp(0, 0, 1, 1, "07", "00", "02", "Preamp");
    editDetails()->page()->addGroupBox(0, 1, 1, 1);
    editDetails()->addPage("00", "00", "1A", "04", "Tables");*/
}
