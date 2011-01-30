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

#include "menuPage_assign5.h"

menuPage_assign5::menuPage_assign5(QWidget *parent)
    : menuPage(parent)
{
    setLSB("01", "59");
    editDetails()->patchPos(482, 36, "01", "59");    //sysx file offset and data length of parameters x 2,
    setEditPages();
};

void menuPage_assign5::updateSignal()
{

};

void menuPage_assign5::setEditPages()
{
    editDetails()->page()->newGroupBox(tr("Assign 5"));
    editDetails()->page()->newGroupBox(tr(""));
    editDetails()->page()->newStackControl(0);
    editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "59", "middle", Qt::AlignCenter);
    editDetails()->page()->addStackControl();
    editDetails()->page()->addGroupBox(0, 0, 1, 1);
    editDetails()->page()->insertStackField(0, 0, 1, 2, 1);
    editDetails()->page()->addGroupBox(0, 0, 2, 1);

    editDetails()->addPage();

    editDetails()->page()->newStackField(0);
    editDetails()->page()->newGroupBox("Assign 5 Target");
    editDetails()->page()->addTarget(0, 0, 1, 3, "01", "00", "5A", "target","target", 120); // Target
    editDetails()->page()->addGroupBox(0, 0, 1, 1);
    editDetails()->page()->newGroupBox("Assign 5 Source");
    editDetails()->page()->newStackControl(1);
    editDetails()->page()->addComboBox(1, 0, 1, 1, "01", "00", "62");                    // Source
    editDetails()->page()->addStackControl();
    editDetails()->page()->addComboBox(1, 1, 1, 1, "01", "00", "63");                    // Source Mode
    editDetails()->page()->addRange(1, 2, 1, 2, "01", "00", "64", "Structure");         // min/max range widget
    editDetails()->page()->addGroupBox(0, 1, 1, 1);
    editDetails()->page()->insertStackField(1, 1, 0, 1, 2);
    editDetails()->page()->addStackField();

    editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(1);
    editDetails()->page()->newGroupBox("Assign 5 Internal Pedal");
    editDetails()->page()->addComboBox(0, 0, 1, 1, "01", "00", "66");                    // Internal Pedal Trigger
    editDetails()->page()->addKnob(0, 1, 1, 1, "01", "00", "67");                        // Internal Pedal Time
    editDetails()->page()->addComboBox(0, 2, 1, 1, "01", "00", "69");                    // Internal Pedal Curve
    editDetails()->page()->addGroupBox(0, 0, 1, 1);
    editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(1);
    editDetails()->page()->newGroupBox("Assign 5 Wave Pedal");
    editDetails()->page()->addKnob(1, 0, 1, 1, "01", "00", "6A", "normal","right", 105);// Wave Form Rate
    editDetails()->page()->addComboBox(1, 1, 1, 1, "01", "00", "6B");                    // Wave Form
    editDetails()->page()->addGroupBox(0, 0, 1, 1);
    editDetails()->page()->addStackField();
    editDetails()->page()->newStackField(1);
    editDetails()->page()->addStackField();


};
