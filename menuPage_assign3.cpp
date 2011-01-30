/****************************************************************************
**
** Copyright (C) 2007~2010 Colin Willcocks.
** Copyright (C) 2005~2007 Uco Mesdag.
** All rights reserved.
** This file is part of "GR-55B FloorBoard".
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

#include "menuPage_assign3.h"

menuPage_assign3::menuPage_assign3(QWidget *parent)
    : menuPage(parent)
{
    setLSB("01", "33");
    editDetails()->patchPos(406, 36, "01", "33");    //sysx file offset and data length of parameters x 2.
    setEditPages();
};

void menuPage_assign3::updateSignal()
{

};

void menuPage_assign3::setEditPages()
{
    editDetails()->page()->newGroupBox(tr("Assign 3"));
    editDetails()->page()->newGroupBox(tr(""));
    editDetails()->page()->newStackControl(0);
    editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "33", "middle", Qt::AlignCenter);
    editDetails()->page()->addStackControl();
    editDetails()->page()->addGroupBox(0, 0, 1, 1);
    editDetails()->page()->insertStackField(0, 0, 1, 2, 1);
    editDetails()->page()->addGroupBox(0, 0, 2, 1);

    editDetails()->addPage();

    editDetails()->page()->newStackField(0);
    editDetails()->page()->newGroupBox("Assign 3 Target");
    editDetails()->page()->addTarget(0, 0, 1, 3, "01", "00", "34", "target","target", 120); // Target
    editDetails()->page()->addGroupBox(0, 0, 1, 1);
    editDetails()->page()->newGroupBox("Assign 3 Source");
    editDetails()->page()->newStackControl(1);
    editDetails()->page()->addComboBox(1, 0, 1, 1, "01", "00", "3C");                    // Source
    editDetails()->page()->addStackControl();
    editDetails()->page()->addComboBox(1, 1, 1, 1, "01", "00", "3D");                    // Source Mode
    editDetails()->page()->addRange(1, 2, 1, 2, "01", "00", "3E", "Structure");         // min/max range widget
    editDetails()->page()->addGroupBox(0, 1, 1, 1);
    editDetails()->page()->insertStackField(1, 1, 0, 1, 2);
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(1);
    editDetails()->page()->newGroupBox("Assign 3 Internal Pedal");
    editDetails()->page()->addComboBox(0, 0, 1, 1, "01", "00", "40");                    // Internal Pedal Trigger
    editDetails()->page()->addKnob(0, 1, 1, 1, "01", "00", "41");                        // Internal Pedal Time
    editDetails()->page()->addComboBox(0, 2, 1, 1, "01", "00", "43");                    // Internal Pedal Curve
    editDetails()->page()->addGroupBox(0, 0, 1, 1);
    editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(1);
    editDetails()->page()->newGroupBox("Assign 3 Wave Pedal");
    editDetails()->page()->addKnob(1, 0, 1, 1, "01", "00", "44", "normal","right", 105);// Wave Form Rate
    editDetails()->page()->addComboBox(1, 1, 1, 1, "01", "00", "45");                    // Wave Form
    editDetails()->page()->addGroupBox(0, 0, 1, 1);
    editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(1);
    editDetails()->page()->addStackField();
};
