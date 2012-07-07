/****************************************************************************
**
** Copyright (C) 2007~2012 Colin Willcocks.
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

#include "menuPage_ez_edit.h"

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
    //editDetails()->page()->newGroupBox("Patch & PreAmp Creator");
    editDetails()->page()->newGroupBox("Style");
    editDetails()->page()->addEZ_Patch(0, 0, 1, 1, "00", "00", "1B", "middle", Qt::AlignCenter);
    editDetails()->page()->addGroupBox(0, 0, 1, 1);
    editDetails()->page()->newGroupBox("Preamp");
    editDetails()->page()->addEZ_amp(0, 0, 1, 1, "07", "00", "02", "Preamp");
    editDetails()->page()->addGroupBox(0, 1, 1, 1);
    editDetails()->addPage("00", "00", "1A", "00", "Tables");

    editDetails()->page()->newGroupBox("Speaker & Cabinet");
    //editDetails()->page()->addComboBox(0, 0, 1, 1, "00", "00", "6F", "large");   // custom spkr A type
    editDetails()->page()->addEZ_amp(0, 0, 1, 1, "07", "00", "0C", "Speaker");
    editDetails()->page()->addGroupBox(0, 0, 1, 1);
    editDetails()->addPage("00", "00", "1A", "01", "Tables");

    editDetails()->page()->newGroupBox("OD/DS Customiser");
    //editDetails()->page()->addComboBox(0, 0, 1, 1, "00", "00", "39", "large");   // custom
    editDetails()->page()->addEZ_amp(1, 0, 1, 1, "07", "00", "19", "Distortion");
    editDetails()->page()->addGroupBox(0, 1, 1, 1);
    editDetails()->addPage("00", "00", "1A", "02", "Tables");

    editDetails()->page()->newGroupBox("Ambience");
    //editDetails()->page()->addComboBox(0, 0, 1, 1, "00", "00", "39", "large");   // custom
    editDetails()->page()->addEZ_amp(1, 0, 1, 1, "07", "00", "11", "Ambience");
    editDetails()->page()->addGroupBox(0, 1, 1, 1);
    editDetails()->addPage("00", "00", "1A", "03", "Tables");
}
