/****************************************************************************
**
** Copyright (C) 2007~2013 Colin Willcocks.
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

#include "menuPage_assign.h"

menuPage_assign::menuPage_assign(QWidget *parent)
    : menuPage(parent)
{
  //this->setImage(":/images/assigns_pushbutton.png");
  setLSB("0B", "00");
  editDetails()->patchPos(3048, 284, "0B", "20"); 
	setEditPages();
};

void menuPage_assign::updateSignal()
{

};

void menuPage_assign::setEditPages()
{
	editDetails()->page()->newGroupBox(tr("Assigns"));
	editDetails()->page()->newGroupBox(tr("Assign 1-8"));
	editDetails()->page()->newStackControl(0);
	editDetails()->page()->addComboBox(0, 0, 1, 1, "0C", "00", "23");	
	editDetails()->page()->addStackControl();
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->newGroupBox("Assign 1");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "0B", "00", "20", "middle", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 1, 1, 1);
	editDetails()->page()->newGroupBox("Assign 2");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "0B", "00", "30", "middle", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 2, 1, 1);
	editDetails()->page()->newGroupBox("Assign 3");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "0B", "00", "40", "middle", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 3, 1, 1);
	editDetails()->page()->newGroupBox("Assign 4");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "0B", "00", "50", "middle", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 4, 1, 1);
	editDetails()->page()->newGroupBox("Assign 5");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "0B", "00", "60", "middle", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 5, 1, 1);
	editDetails()->page()->newGroupBox("Assign 6");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "0B", "00", "70", "middle", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 6, 1, 1);
	editDetails()->page()->newGroupBox("Assign 7");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "0C", "00", "00", "middle", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 7, 1, 1);
	editDetails()->page()->newGroupBox("Assign 8");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "0C", "00", "10", "middle", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 8, 1, 1);
	
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	//editDetails()->page()->newGroupBox("");
	editDetails()->page()->insertStackField(0, 1, 0, 1, 1);
	//editDetails()->page()->addGroupBox(1, 0, 1, 1);	
	editDetails()->addPage();
  
 
  editDetails()->page()->newStackField(0);
  editDetails()->page()->newGroupBox("Assign 1 Target");
	editDetails()->page()->addTarget(0, 0, 1, 3, "0B", "00", "21", "target","target", 120); // Target
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->newGroupBox("Assign 1 Source");
	editDetails()->page()->newStackControl(1);
	editDetails()->page()->addComboBox(1, 0, 1, 1, "0B", "00", "27");                    // Source
	editDetails()->page()->addStackControl();
  editDetails()->page()->addComboBox(1, 1, 1, 1, "0B", "00", "28");                    // Source Mode
  editDetails()->page()->addRange(1, 2, 1, 2, "0B", "00", "29", "Structure");         // min/max range widget
	//editDetails()->page()->addKnob(1, 2, 1, 1, "0B", "00", "29");                        // Active Range High
	//editDetails()->page()->addKnob(1, 3, 1, 1, "0B", "00", "2A");                        // Active Range Low
  editDetails()->page()->addGroupBox(0, 1, 1, 1);
  editDetails()->page()->insertStackField(1, 1, 0, 1, 2);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);
  editDetails()->page()->newGroupBox("Assign 1 Internal Pedal");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "0B", "00", "2B");                    // Internal Pedal Trigger
  editDetails()->page()->addKnob(0, 1, 1, 1, "0B", "00", "2C");                        // Internal Pedal Time
	editDetails()->page()->addComboBox(0, 2, 1, 1, "0B", "00", "2D");                    // Internal Pedal Curve
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);
  editDetails()->page()->newGroupBox("Assign 1 Wave Pedal");
	editDetails()->page()->addKnob(1, 0, 1, 1, "0B", "00", "2E", "normal","right", 105);// Wave Form Rate
	editDetails()->page()->addComboBox(1, 1, 1, 1, "0B", "00", "2F");                    // Wave Form
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);
  editDetails()->page()->newGroupBox("Input");
	editDetails()->page()->addKnob(0, 0, 1, 1, "0C", "00", "20", "normal","right", 85);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);	
  editDetails()->page()->addStackField();
	
	
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Assign 2 Target");
	editDetails()->page()->addTarget(0, 0, 1, 3, "0B", "00", "31", "target","target", 120); // Target
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->newGroupBox("Assign 2 Source");
	editDetails()->page()->newStackControl(2);
	editDetails()->page()->addComboBox(1, 0, 1, 1, "0B", "00", "37");                    // Source
	editDetails()->page()->addStackControl();
  editDetails()->page()->addComboBox(1, 1, 1, 1, "0B", "00", "38");                    // Source Mode
  editDetails()->page()->addRange(1, 2, 1, 2, "0B", "00", "39", "Structure");         // min/max range widget
	//editDetails()->page()->addKnob(1, 2, 1, 1, "0B", "00", "39");                        // Active Range High
	//editDetails()->page()->addKnob(1, 3, 1, 1, "0B", "00", "3A");                        // Active Range Low
  editDetails()->page()->addGroupBox(0, 1, 1, 1);
  editDetails()->page()->insertStackField(2, 1, 0, 1, 2);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);
  editDetails()->page()->newGroupBox("Assign 2 Internal Pedal");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "0B", "00", "3B");                    // Internal Pedal Trigger
  editDetails()->page()->addKnob(0, 1, 1, 1, "0B", "00", "3C");                        // Internal Pedal Time
	editDetails()->page()->addComboBox(0, 2, 1, 1, "0B", "00", "3D");                    // Internal Pedal Curve
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);
  editDetails()->page()->newGroupBox("Assign 2 Wave Pedal");
	editDetails()->page()->addKnob(1, 0, 1, 1, "0B", "00", "3E", "normal","right", 105);// Wave Form Rate
	editDetails()->page()->addComboBox(1, 1, 1, 1, "0B", "00", "3F");                    // Wave Form
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);
  editDetails()->page()->newGroupBox("Input");
	editDetails()->page()->addKnob(0, 0, 1, 1, "0C", "00", "20", "normal","right", 85);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);	
  editDetails()->page()->addStackField();
  
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Assign 3 Target");
	editDetails()->page()->addTarget(0, 0, 1, 3, "0B", "00", "41", "target","target", 120); // Target
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->newGroupBox("Assign 3 Source");
	editDetails()->page()->newStackControl(3);
	editDetails()->page()->addComboBox(1, 0, 1, 1, "0B", "00", "47");                    // Source
	editDetails()->page()->addStackControl();
  editDetails()->page()->addComboBox(1, 1, 1, 1, "0B", "00", "48");                    // Source Mode
  editDetails()->page()->addRange(1, 2, 1, 2, "0B", "00", "49", "Structure");         // min/max range widget
	//editDetails()->page()->addKnob(1, 2, 1, 1, "0B", "00", "49");                        // Active Range High
	//editDetails()->page()->addKnob(1, 3, 1, 1, "0B", "00", "4A");                        // Active Range Low
  editDetails()->page()->addGroupBox(0, 1, 1, 1);
  editDetails()->page()->insertStackField(3, 1, 0, 1, 2);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);
  editDetails()->page()->newGroupBox("Assign 3 Internal Pedal");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "0B", "00", "4B");                    // Internal Pedal Trigger
  editDetails()->page()->addKnob(0, 1, 1, 1, "0B", "00", "4C");                        // Internal Pedal Time
	editDetails()->page()->addComboBox(0, 2, 1, 1, "0B", "00", "4D");                    // Internal Pedal Curve
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);
  editDetails()->page()->newGroupBox("Assign 3 Wave Pedal");
	editDetails()->page()->addKnob(1, 0, 1, 1, "0B", "00", "4E", "normal","right", 105);// Wave Form Rate
	editDetails()->page()->addComboBox(1, 1, 1, 1, "0B", "00", "4F");                    // Wave Form
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);
  editDetails()->page()->newGroupBox("Input");
	editDetails()->page()->addKnob(0, 0, 1, 1, "0C", "00", "20", "normal","right", 85);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);	
  editDetails()->page()->addStackField();
  
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Assign 4 Target");
	editDetails()->page()->addTarget(0, 0, 1, 3, "0B", "00", "51", "target","target", 120); // Target
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->newGroupBox("Assign 4 Source");
	editDetails()->page()->newStackControl(4);
	editDetails()->page()->addComboBox(1, 0, 1, 1, "0B", "00", "57");                    // Source
	editDetails()->page()->addStackControl();
  editDetails()->page()->addComboBox(1, 1, 1, 1, "0B", "00", "58");                    // Source Mode
  editDetails()->page()->addRange(1, 2, 1, 2, "0B", "00", "59", "Structure");         // min/max range widget
	//editDetails()->page()->addKnob(1, 2, 1, 1, "0B", "00", "59");                        // Active Range High
	//editDetails()->page()->addKnob(1, 3, 1, 1, "0B", "00", "5A");                        // Active Range Low
  editDetails()->page()->addGroupBox(0, 1, 1, 1);
  editDetails()->page()->insertStackField(4, 1, 0, 1, 2);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);
  editDetails()->page()->newGroupBox("Assign 4 Internal Pedal");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "0B", "00", "5B");                    // Internal Pedal Trigger
  editDetails()->page()->addKnob(0, 1, 1, 1, "0B", "00", "5C");                        // Internal Pedal Time
	editDetails()->page()->addComboBox(0, 2, 1, 1, "0B", "00", "5D");                    // Internal Pedal Curve
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);
  editDetails()->page()->newGroupBox("Assign 4 Wave Pedal");
	editDetails()->page()->addKnob(1, 0, 1, 1, "0B", "00", "5E", "normal","right", 105);// Wave Form Rate
	editDetails()->page()->addComboBox(1, 1, 1, 1, "0B", "00", "5F");                    // Wave Form
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);
  editDetails()->page()->newGroupBox("Input");
	editDetails()->page()->addKnob(0, 0, 1, 1, "0C", "00", "20", "normal","right", 85);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);	
  editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Assign 5 Target");
	editDetails()->page()->addTarget(0, 0, 1, 3, "0B", "00", "61", "target","target", 120); // Target
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->newGroupBox("Assign 5 Source");
	editDetails()->page()->newStackControl(5);
	editDetails()->page()->addComboBox(1, 0, 1, 1, "0B", "00", "67");                    // Source
	editDetails()->page()->addStackControl();
  editDetails()->page()->addComboBox(1, 1, 1, 1, "0B", "00", "68");                    // Source Mode
  editDetails()->page()->addRange(1, 2, 1, 2, "0B", "00", "69", "Structure");         // min/max range widget
	//editDetails()->page()->addKnob(1, 2, 1, 1, "0B", "00", "69");                        // Active Range High
	//editDetails()->page()->addKnob(1, 3, 1, 1, "0B", "00", "6A");                        // Active Range Low
  editDetails()->page()->addGroupBox(0, 1, 1, 1);
  editDetails()->page()->insertStackField(5, 1, 0, 1, 2);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(5);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(5);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(5);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(5);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(5);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(5);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(5);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(5);
  editDetails()->page()->newGroupBox("Assign 5 Internal Pedal");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "0B", "00", "6B");                    // Internal Pedal Trigger
  editDetails()->page()->addKnob(0, 1, 1, 1, "0B", "00", "6C");                        // Internal Pedal Time
	editDetails()->page()->addComboBox(0, 2, 1, 1, "0B", "00", "6D");                    // Internal Pedal Curve
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(5);
  editDetails()->page()->newGroupBox("Assign 5 Wave Pedal");
	editDetails()->page()->addKnob(1, 0, 1, 1, "0B", "00", "6E", "normal","right", 105);// Wave Form Rate
	editDetails()->page()->addComboBox(1, 1, 1, 1, "0B", "00", "6F");                    // Wave Form
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(5);
  editDetails()->page()->newGroupBox("Input");
	editDetails()->page()->addKnob(0, 0, 1, 1, "0C", "00", "20", "normal","right", 85);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);	
  editDetails()->page()->addStackField();
  
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Assign 6 Target");
	editDetails()->page()->addTarget(0, 0, 1, 3, "0B", "00", "71", "target","target", 120); // Target
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->newGroupBox("Assign 6 Source");
	editDetails()->page()->newStackControl(6);
	editDetails()->page()->addComboBox(1, 0, 1, 1, "0B", "00", "77");                    // Source
	editDetails()->page()->addStackControl();
  editDetails()->page()->addComboBox(1, 1, 1, 1, "0B", "00", "78");                    // Source Mode
  editDetails()->page()->addRange(1, 2, 1, 2, "0B", "00", "79", "Structure");         // min/max range widget
	//editDetails()->page()->addKnob(1, 2, 1, 1, "0B", "00", "79");                        // Active Range High
	//editDetails()->page()->addKnob(1, 3, 1, 1, "0B", "00", "7A");                        // Active Range Low
  editDetails()->page()->addGroupBox(0, 1, 1, 1);
  editDetails()->page()->insertStackField(6, 1, 0, 1, 2);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(6);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(6);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(6);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(6);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(6);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(6);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(6);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(6);
  editDetails()->page()->newGroupBox("Assign 6 Internal Pedal");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "0B", "00", "7B");                    // Internal Pedal Trigger
  editDetails()->page()->addKnob(0, 1, 1, 1, "0B", "00", "7C");                        // Internal Pedal Time
	editDetails()->page()->addComboBox(0, 2, 1, 1, "0B", "00", "7D");                    // Internal Pedal Curve
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(6);
  editDetails()->page()->newGroupBox("Assign 6 Wave Pedal");
	editDetails()->page()->addKnob(1, 0, 1, 1, "0B", "00", "7E", "normal","right", 105);// Wave Form Rate
	editDetails()->page()->addComboBox(1, 1, 1, 1, "0B", "00", "7F");                    // Wave Form
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(6);
  editDetails()->page()->newGroupBox("Input");
	editDetails()->page()->addKnob(0, 0, 1, 1, "0C", "00", "20", "normal","right", 85);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);	
  editDetails()->page()->addStackField();
  

	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Assign 7 Target");
	editDetails()->page()->addTarget(0, 0, 1, 3, "0C", "00", "01", "target","target", 120); // Target
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->newGroupBox("Assign 7 Source");
	editDetails()->page()->newStackControl(7);
	editDetails()->page()->addComboBox(1, 0, 1, 1, "0C", "00", "07");                    // Source
	editDetails()->page()->addStackControl();
  editDetails()->page()->addComboBox(1, 1, 1, 1, "0C", "00", "08");                    // Source Mode
  editDetails()->page()->addRange(1, 2, 1, 2, "0C", "00", "09", "Structure");         // min/max range widget
	//editDetails()->page()->addKnob(1, 2, 1, 1, "0C", "00", "09");                        // Active Range High
	//editDetails()->page()->addKnob(1, 3, 1, 1, "0C", "00", "0A");                        // Active Range Low
  editDetails()->page()->addGroupBox(0, 1, 1, 1);
  editDetails()->page()->insertStackField(7, 1, 0, 1, 2);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(7);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(7);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(7);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(7);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(7);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(7);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(7);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(7);
  editDetails()->page()->newGroupBox("Assign 7 Internal Pedal");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "0C", "00", "0B");                    // Internal Pedal Trigger
  editDetails()->page()->addKnob(0, 1, 1, 1, "0C", "00", "0C");                        // Internal Pedal Time
	editDetails()->page()->addComboBox(0, 2, 1, 1, "0C", "00", "0D");                    // Internal Pedal Curve
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(7);
  editDetails()->page()->newGroupBox("Assign 7 Wave Pedal");
	editDetails()->page()->addKnob(1, 0, 1, 1, "0C", "00", "0E", "normal","right", 105);// Wave Form Rate
	editDetails()->page()->addComboBox(1, 1, 1, 1, "0C", "00", "0F");                    // Wave Form
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(7);
  editDetails()->page()->newGroupBox("Input");
	editDetails()->page()->addKnob(0, 0, 1, 1, "0C", "00", "20", "normal","right", 85);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);	
  editDetails()->page()->addStackField();
  
	
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Assign 8 Target");
	editDetails()->page()->addTarget(0, 0, 1, 3, "0C", "00", "11", "target","target", 120); // Target
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->newGroupBox("Assign 8 Source");
	editDetails()->page()->newStackControl(8);
	editDetails()->page()->addComboBox(1, 0, 1, 1, "0C", "00", "17");                    // Source
	editDetails()->page()->addStackControl();
  editDetails()->page()->addComboBox(1, 1, 1, 1, "0C", "00", "18");                    // Source Mode
  editDetails()->page()->addRange(1, 2, 1, 2, "0C", "00", "19", "Structure");         // min/max range widget
	//editDetails()->page()->addKnob(1, 2, 1, 1, "0C", "00", "19");                        // Active Range High
	//editDetails()->page()->addKnob(1, 3, 1, 1, "0C", "00", "1A");                        // Active Range Low
  editDetails()->page()->addGroupBox(0, 1, 1, 1);
  editDetails()->page()->insertStackField(8, 1, 0, 1, 2);
  editDetails()->page()->addStackField();
  
  editDetails()->page()->newStackField(8);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(8);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(8);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(8);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(8);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(8);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(8);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(8);
  editDetails()->page()->newGroupBox("Assign 8 Internal Pedal");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "0C", "00", "1B");                    // Internal Pedal Trigger
  editDetails()->page()->addKnob(0, 1, 1, 1, "0C", "00", "1C");                        // Internal Pedal Time
	editDetails()->page()->addComboBox(0, 2, 1, 1, "0C", "00", "1D");                    // Internal Pedal Curve
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(8);
  editDetails()->page()->newGroupBox("Assign 8 Wave Pedal");
	editDetails()->page()->addKnob(1, 0, 1, 1, "0C", "00", "1E", "normal","right", 105);// Wave Form Rate
	editDetails()->page()->addComboBox(1, 1, 1, 1, "0C", "00", "1F");                    // Wave Form
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(8);
  editDetails()->page()->newGroupBox("Input");
	editDetails()->page()->addKnob(0, 0, 1, 1, "0C", "00", "20", "normal","right", 85);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);	
  editDetails()->page()->addStackField();
  

};
