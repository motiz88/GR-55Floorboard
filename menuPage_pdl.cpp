/****************************************************************************
**
** Copyright (C) 2007~2010 Colin Willcocks.
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
    setLSB("00", "00");
    // editDetails()->patchPos(2830, 60, "0A", "40");
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
    editDetails()->page()->addComboBox(1, 0, 1, 1, "00", "00", "12");
    editDetails()->page()->addStackControl();
    editDetails()->page()->insertStackField(0, 0, 2, 1, 1);
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
    editDetails()->page()->addSwitch(0, 0, 1, 1, "00", "00", "17", "middle", Qt::AlignCenter);
    editDetails()->page()->addSwitch(0, 1, 1, 1, "00", "00", "18", "middle", Qt::AlignCenter);
    editDetails()->page()->addSwitch(0, 2, 1, 1, "00", "00", "19", "middle", Qt::AlignCenter);
    editDetails()->page()->addSwitch(0, 3, 1, 1, "00", "00", "1A", "middle", Qt::AlignCenter);
    editDetails()->page()->addSwitch(1, 0, 1, 1, "00", "00", "1B", "middle", Qt::AlignCenter);
    editDetails()->page()->addSwitch(1, 1, 1, 1, "00", "00", "1C", "middle", Qt::AlignCenter);
    editDetails()->page()->addSwitch(1, 2, 1, 1, "00", "00", "1D", "middle", Qt::AlignCenter);
    editDetails()->page()->addSwitch(1, 3, 1, 1, "00", "00", "1E", "middle", Qt::AlignCenter);
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
    /*

        editDetails()->page()->newStackField(0);
        editDetails()->page()->addStackField();

        editDetails()->page()->newStackField(0);
        editDetails()->page()->newGroupBox("Foot Volume");
        editDetails()->page()->addComboBox(0, 0, 1, 1, "0A", "00", "5D");
        editDetails()->page()->addKnob(0, 1, 1, 1, "0A", "00", "5B");
        editDetails()->page()->addKnob(1, 0, 1, 1, "0A", "00", "5C");
        editDetails()->page()->addKnob(2, 1, 1, 1, "0A", "00", "5A");
        editDetails()->page()->addGroupBox(0, 1, 1, 1);
        editDetails()->page()->addStackField();

        editDetails()->page()->newStackField(0);
        editDetails()->page()->newGroupBox("Pedal Bend");
         editDetails()->page()->addSwitch(0, 0, 1, 1, "0A", "00", "40", "middle", Qt::AlignCenter);
        editDetails()->page()->addKnob(1, 0, 1, 1, "0A", "00", "54");
        editDetails()->page()->addKnob(2, 0, 1, 1, "0A", "00", "57");
        editDetails()->page()->addKnob(0, 1, 1, 1, "0A", "00", "56");
        editDetails()->page()->addKnob(1, 1, 1, 1, "0A", "00", "55");
        editDetails()->page()->addKnob(2, 1, 1, 1, "0A", "00", "58");
        editDetails()->page()->addGroupBox(0, 1, 1, 1);
        editDetails()->page()->addStackField();

  editDetails()->page()->newStackField(0);
        editDetails()->page()->newGroupBox("Wah");
        editDetails()->page()->newStackControl(3);
        editDetails()->page()->addComboBox(0, 0, 1, 1, "0A", "00", "49");
        editDetails()->page()->addStackControl();
        editDetails()->page()->addKnob(1, 0, 1, 1, "0A", "00", "4B");
        editDetails()->page()->addKnob(2, 0, 1, 1, "0A", "00", "4D");
        editDetails()->page()->addKnob(0, 1, 1, 1, "0A", "00", "4A");
        editDetails()->page()->addKnob(1, 1, 1, 1, "0A", "00", "4C");
        editDetails()->page()->addKnob(2, 1, 1, 1, "0A", "00", "4E");
        editDetails()->page()->addGroupBox(0, 1, 1, 1);
        editDetails()->page()->insertStackField(3, 0, 2, 1, 3);
        editDetails()->page()->addStackField();

        editDetails()->page()->newStackField(0);
        editDetails()->page()->newGroupBox("Pedal Bend");
        editDetails()->page()->addKnob(1, 0, 1, 1, "0A", "00", "54");
        editDetails()->page()->addKnob(2, 0, 1, 1, "0A", "00", "57");
        editDetails()->page()->addKnob(0, 1, 1, 1, "0A", "00", "56");
        editDetails()->page()->addKnob(1, 1, 1, 1, "0A", "00", "55");
        editDetails()->page()->addKnob(2, 1, 1, 1, "0A", "00", "58");
        editDetails()->page()->addGroupBox(0, 1, 1, 1);
        editDetails()->page()->newGroupBox("Foot Volume");
        editDetails()->page()->addComboBox(0, 0, 1, 1, "0A", "00", "5D");
        editDetails()->page()->addKnob(2, 1, 1, 1, "0A", "00", "5B");
        editDetails()->page()->addKnob(0, 1, 1, 1, "0A", "00", "5A");
        editDetails()->page()->addKnob(1, 1, 1, 1, "0A", "00", "5C");
        editDetails()->page()->addGroupBox(0, 2, 1, 1);
        editDetails()->page()->addStackField();

        */
    editDetails()->addPage();
};
