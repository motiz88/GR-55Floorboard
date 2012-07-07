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

#include <QChar>
#include "floorBoardDisplay.h"
#include "Preferences.h"
#include "MidiTable.h"
#include "SysxIO.h"
#include "midiIO.h"
#include "renameWidget.h"
#include "customRenameWidget.h"
#include "customComboBox.h"
#include "globalVariables.h"

// Platform-dependent sleep routines.
#ifdef Q_OS_WIN
#include <windows.h>
#define SLEEP( milliseconds ) Sleep( (DWORD) milliseconds )
#else // Unix variants & Mac
#include <unistd.h>
#define SLEEP( milliseconds ) usleep( (unsigned long) (milliseconds * 1000.0) )
#endif


floorBoardDisplay::floorBoardDisplay(QWidget *parent, QPoint pos)
    : QWidget(parent)
{
    this->pos = pos;
    this->timer = new QTimer(this);
    this->patchLoadError = false;
    this->blinkCount = 0;    
    this->autosyncTimer = new QTimer(this);
    connect(autosyncTimer, SIGNAL(timeout()), this, SLOT(autosync()));

    int patchDisplayRowOffset = 9;
    int editButtonRowOffset = 75;
    int assignButtonRowOffset = 32;
    int tempRowOffset = 597;
    this->patchNumDisplay = new customDisplay(QRect(8, patchDisplayRowOffset, 50, 34), this);
    this->patchNumDisplay->setLabelPosition(true);
    this->patchNumDisplay->setMainObjectName("bankMain");
    this->patchNumDisplay->setSubObjectName("bankSub");
    this->patchNumDisplay->setWhatsThis(tr("Patch Number Display.<br>displays the currently selected patch<br>and patch write memory location."));
    this->patchDisplay = new customDisplay(QRect(73, patchDisplayRowOffset, 145, 34), this);
    this->patchDisplay->setMainObjectName("nameMain");
    this->patchDisplay->setSubObjectName("nameSub");
    this->valueDisplay = new customDisplay(QRect(230, patchDisplayRowOffset, 150, 34), this);
    this->valueDisplay->setMainObjectName("valueMain");
    this->valueDisplay->setSubObjectName("valueSub");

    this->temp1Display = new customLabelDisplay(QRect(28, tempRowOffset+22, 166, 18), this);
    this->temp1Display->setLabelPosition(true);
    this->temp1Display->setMainObjectName("nameMain");
    this->temp1Display->setMainText(tr("Empty"), Qt::AlignCenter);
    this->temp1Display->setWhatsThis(tr("Name of the currently stored patch in the clipboard."));
    this->temp2Display = new customLabelDisplay(QRect(222, tempRowOffset+22, 166, 18), this);
    this->temp2Display->setLabelPosition(true);
    this->temp2Display->setMainObjectName("nameMain");
    this->temp2Display->setMainText(tr("Empty"), Qt::AlignCenter);
    this->temp2Display->setWhatsThis(tr("Name of the currently stored patch in the clipboard."));
    this->temp3Display = new customLabelDisplay(QRect(417, tempRowOffset+22, 166, 18), this);
    this->temp3Display->setLabelPosition(true);
    this->temp3Display->setMainObjectName("nameMain");
    this->temp3Display->setMainText(tr("Empty"), Qt::AlignCenter);
    this->temp3Display->setWhatsThis(tr("Name of the currently stored patch in the clipboard."));
    this->temp4Display = new customLabelDisplay(QRect(611, tempRowOffset+22, 166, 18), this);
    this->temp4Display->setLabelPosition(true);
    this->temp4Display->setMainObjectName("nameMain");
    this->temp4Display->setMainText(tr("Empty"), Qt::AlignCenter);
    this->temp4Display->setWhatsThis(tr("Name of the currently stored patch in the clipboard."));
    this->temp5Display = new customLabelDisplay(QRect(804, tempRowOffset+22, 166, 18), this);
    this->temp5Display->setLabelPosition(true);
    this->temp5Display->setMainObjectName("nameMain");
    this->temp5Display->setMainText(tr("Empty"), Qt::AlignCenter);
    this->temp5Display->setWhatsThis(tr("Name of the currently stored patch in the clipboard."));

    Preferences *preferences = Preferences::Instance();
    QString version = preferences->getPreferences("General", "Application", "version");
    this->patchDisplay->setMainText(deviceType + tr(" FloorBoard"));
    this->patchDisplay->setSubText(tr("version"), version);

    initPatch = new initPatchListMenu(QRect(390, patchDisplayRowOffset+19, 168, 15), this);
    initPatch->setWhatsThis(tr("Clicking on this will load a patch from a predefined selection.<br>patches place in the Init Patches folder will appear in this list at the start of the next session."));
    renameWidget *nameEdit = new renameWidget(this);
    nameEdit->setGeometry(70, patchDisplayRowOffset, 150, 34);
    nameEdit->setWhatsThis(tr("Clicking on this will open<br>a text dialog window<br>allowing user text input."));
    
    this->autoButton = new customButton(tr("Auto Sync"), false, QPoint(440, editButtonRowOffset+50), this, ":/images/greenledbutton.png");
    this->autoButton->setWhatsThis(tr("Auto refresh<br>used to automatically update editor settings changes made on the GR-55"));
    this->connectButton = new customButton(tr("Connect"), false, QPoint(390, patchDisplayRowOffset), this, ":/images/greenledbutton.png");
    this->connectButton->setWhatsThis(tr("Connect Button<br>used to establish a continuous midi connection<br>when lit green, the connection is valid"));
    this->writeButton = new customButton(tr("Write"), false, QPoint(476, patchDisplayRowOffset), this, ":/images/ledbutton.png");
    this->writeButton->setWhatsThis(tr("Write Button<br>if the patch number displays [temp buffer]<br>the current patch is sent to the GR-55 temporary memory only<br>or else the patch will be written to the displayed patch memory location."));
    this->system_Button = new customPanelButton(tr("System"), false, QPoint(580, patchDisplayRowOffset+18), this, ":/images/switch.png");
    this->system_Button->setWhatsThis(tr("Deep editing of the selected effect<br>pressing this button will open an edit page<br>allowing detailed setting of this effects parameters."));
    this->master_Button = new customPanelButton(tr("Master"), false, QPoint(640, patchDisplayRowOffset+18), this, ":/images/switch.png");
    this->master_Button->setWhatsThis(tr("Deep editing of the selected effect<br>pressing this button will open an edit page<br>allowing detailed setting of this effects parameters."));
    this->ez_edit_Button = new customPanelButton(tr("EZ-EDIT"), false, QPoint(550, editButtonRowOffset+52), this, ":/images/switch.png");
    this->ez_edit_Button->setWhatsThis(tr("Deep editing of the selected effect<br>pressing this button will open an edit page<br>allowing detailed setting of this effects parameters."));
    this->pedal_Button = new customPanelButton(tr("Pedal/GK"), false, QPoint(700, patchDisplayRowOffset+18), this, ":/images/switch.png");
    this->pedal_Button->setWhatsThis(tr("Deep editing of the selected effect<br>pressing this button will open an edit page<br>allowing detailed setting of this effects parameters."));

    this->normal_PU_Button = new customPanelButton(tr("Normal PU"), false, QPoint(40, editButtonRowOffset), this,  ":/images/switch.png");
    this->normal_PU_Button->setWhatsThis(tr("Deep editing of the selected effect<br>pressing this button will open an edit page<br>allowing detailed setting of this effects parameters."));
    this->structure_1_Button = new customPanelButton(tr("Structure 1"), false, QPoint(323, editButtonRowOffset+52), this,  ":/images/switch_invert.png");
    this->structure_1_Button->setWhatsThis(tr("Deep editing of the selected effect<br>pressing this button will open an edit page<br>allowing detailed setting of this effects parameters."));
    this->structure_2_Button = new customPanelButton(tr("Structure 2"), false, QPoint(373, editButtonRowOffset+52), this,  ":/images/switch_invert.png");
    this->structure_2_Button->setWhatsThis(tr("Deep editing of the selected effect<br>pressing this button will open an edit page<br>allowing detailed setting of this effects parameters."));
    this->modeling_Button = new customPanelButton(tr("Modeling"), false, QPoint(100, editButtonRowOffset), this,  ":/images/switch_invert.png");
    this->modeling_Button->setWhatsThis(tr("Deep editing of the selected effect<br>pressing this button will open an edit page<br>allowing detailed setting of this effects parameters."));
    this->synth1_Button = new customPanelButton(tr("Synth A"), false, QPoint(160, editButtonRowOffset), this, ":/images/switch_invert.png");
    this->synth1_Button->setWhatsThis(tr("Deep editing of the selected effect<br>pressing this button will open an edit page<br>allowing detailed setting of this effects parameters."));
    this->synth2_Button = new customPanelButton(tr("Synth B"), false, QPoint(220, editButtonRowOffset), this, ":/images/switch_invert.png");
    this->synth2_Button->setWhatsThis(tr("Deep editing of the selected effect<br>pressing this button will open an edit page<br>allowing detailed setting of this effects parameters."));
    this->amp_Button = new customPanelButton(tr("Amp"), false, QPoint(280,editButtonRowOffset), this, ":/images/switch.png");
    this->amp_Button->setWhatsThis(tr("Deep editing of the selected effect<br>pressing this button will open an edit page<br>allowing detailed setting of this effects parameters."));
    this->ns1_Button = new customPanelButton(tr("NS"), false, QPoint(340, editButtonRowOffset), this, ":/images/switch.png");
    this->ns1_Button->setWhatsThis(tr("Deep editing of the selected effect<br>pressing this button will open an edit page<br>allowing detailed setting of this effects parameters."));
    this->mod_Button = new customPanelButton(tr("MOD"), false, QPoint(400, editButtonRowOffset), this, ":/images/switch.png");
    this->mod_Button->setWhatsThis(tr("Deep editing of the selected effect<br>pressing this button will open an edit page<br>allowing detailed setting of this effects parameters."));
    this->mfx_Button = new customPanelButton(tr("MFX"), false, QPoint(460, editButtonRowOffset), this, ":/images/switch.png");
    this->mfx_Button->setWhatsThis(tr("Deep editing of the selected effect<br>pressing this button will open an edit page<br>allowing detailed setting of this effects parameters."));
    this->reverb_Button = new customPanelButton(tr("Reverb"), false, QPoint(520, editButtonRowOffset), this, ":/images/switch.png");
    this->reverb_Button->setWhatsThis(tr("Deep editing of the selected effect<br>pressing this button will open an edit page<br>allowing detailed setting of this effects parameters."));
    this->delay_Button = new customPanelButton(tr("Delay"), false, QPoint(580, editButtonRowOffset), this, ":/images/switch.png");
    this->delay_Button->setWhatsThis(tr("Deep editing of the selected effect<br>pressing this button will open an edit page<br>allowing detailed setting of this effects parameters."));
    this->chorus_Button = new customPanelButton(tr("Chorus"), false, QPoint(640, editButtonRowOffset), this, ":/images/switch.png");
    this->chorus_Button->setWhatsThis(tr("Deep editing of the selected effect<br>pressing this button will open an edit page<br>allowing detailed setting of this effects parameters."));
    this->eq_Button = new customPanelButton(tr("Equalizer"), false, QPoint(700, editButtonRowOffset), this, ":/images/switch.png");
    this->eq_Button->setWhatsThis(tr("Deep editing of the selected effect<br>pressing this button will open an edit page<br>allowing detailed setting of this effects parameters."));

    this->assign1_Button = new customPanelButton(tr("Assign 1"), false, QPoint(778, assignButtonRowOffset), this, ":/images/switch.png");
    this->assign1_Button->setWhatsThis(tr("Deep editing of the selected effect<br>pressing this button will open an edit page<br>allowing detailed setting of this effects parameters."));
    this->assign2_Button = new customPanelButton(tr("Assign 2"), false, QPoint(828, assignButtonRowOffset), this, ":/images/switch.png");
    this->assign2_Button->setWhatsThis(tr("Deep editing of the selected effect<br>pressing this button will open an edit page<br>allowing detailed setting of this effects parameters."));
    this->assign3_Button = new customPanelButton(tr("Assign 3"), false, QPoint(878, assignButtonRowOffset), this, ":/images/switch.png");
    this->assign3_Button->setWhatsThis(tr("Deep editing of the selected effect<br>pressing this button will open an edit page<br>allowing detailed setting of this effects parameters."));
    this->assign4_Button = new customPanelButton(tr("Assign 4"), false, QPoint(928, assignButtonRowOffset), this, ":/images/switch.png");
    this->assign4_Button->setWhatsThis(tr("Deep editing of the selected effect<br>pressing this button will open an edit page<br>allowing detailed setting of this effects parameters."));
    this->assign5_Button = new customPanelButton(tr("Assign 5"), false, QPoint(778, assignButtonRowOffset+33), this, ":/images/switch.png");
    this->assign5_Button->setWhatsThis(tr("Deep editing of the selected effect<br>pressing this button will open an edit page<br>allowing detailed setting of this effects parameters."));
    this->assign6_Button = new customPanelButton(tr("Assign 6"), false, QPoint(828, assignButtonRowOffset+33), this, ":/images/switch.png");
    this->assign6_Button->setWhatsThis(tr("Deep editing of the selected effect<br>pressing this button will open an edit page<br>allowing detailed setting of this effects parameters."));
    this->assign7_Button = new customPanelButton(tr("Assign 7"), false, QPoint(878, assignButtonRowOffset+33), this, ":/images/switch.png");
    this->assign7_Button->setWhatsThis(tr("Deep editing of the selected effect<br>pressing this button will open an edit page<br>allowing detailed setting of this effects parameters."));
    this->assign8_Button = new customPanelButton(tr("Assign 8"), false, QPoint(928, assignButtonRowOffset+33), this, ":/images/switch.png");
    this->assign8_Button->setWhatsThis(tr("Deep editing of the selected effect<br>pressing this button will open an edit page<br>allowing detailed setting of this effects parameters."));

    this->temp1_copy_Button = new customButton(tr("Patch Copy"), false, QPoint(26, tempRowOffset), this, ":/images/pushbutton.png");
    this->temp1_copy_Button->setWhatsThis(tr("Copy current patch to clipboard<br>pressing this button will save the current patch to a clipboard<br>the clipboard is saved to file and is re-loaded<br>on the next session startup."));
    this->temp1_paste_Button = new customButton(tr("Patch Paste"), false, QPoint(112, tempRowOffset), this, ":/images/pushbutton.png");
    this->temp1_paste_Button->setWhatsThis(tr("Paste current patch from clipboard<br>pressing this button will load the current patch to a clipboard<br>the clipboard is re-loaded<br>from the previous session copy."));
    this->temp2_copy_Button = new customButton(tr("Patch Copy"), false, QPoint(222, tempRowOffset), this, ":/images/pushbutton.png");
    this->temp2_copy_Button->setWhatsThis(tr("Copy current patch to clipboard<br>pressing this button will save the current patch to a clipboard<br>the clipboard is saved to file and is re-loaded<br>on the next session startup."));
    this->temp2_paste_Button = new customButton(tr("Patch Paste"), false, QPoint(306, tempRowOffset), this, ":/images/pushbutton.png");
    this->temp2_paste_Button->setWhatsThis(tr("Paste current patch from clipboard<br>pressing this button will load the current patch to a clipboard<br>the clipboard is re-loaded<br>from the previous session copy."));
    this->temp3_copy_Button = new customButton(tr("Patch Copy"), false, QPoint(417, tempRowOffset), this, ":/images/pushbutton.png");
    this->temp3_copy_Button->setWhatsThis(tr("Copy current patch to clipboard<br>pressing this button will save the current patch to a clipboard<br>the clipboard is saved to file and is re-loaded<br>on the next session startup."));
    this->temp3_paste_Button = new customButton(tr("Patch Paste"), false, QPoint(501, tempRowOffset), this, ":/images/pushbutton.png");
    this->temp3_paste_Button->setWhatsThis(tr("Paste current patch from clipboard<br>pressing this button will load the current patch to a clipboard<br>the clipboard is re-loaded<br>from the previous session copy."));
    this->temp4_copy_Button = new customButton(tr("Patch Copy"), false, QPoint(612, tempRowOffset), this, ":/images/pushbutton.png");
    this->temp4_copy_Button->setWhatsThis(tr("Copy current patch to clipboard<br>pressing this button will save the current patch to a clipboard<br>the clipboard is saved to file and is re-loaded<br>on the next session startup."));
    this->temp4_paste_Button = new customButton(tr("Patch Paste"), false, QPoint(696, tempRowOffset), this, ":/images/pushbutton.png");
    this->temp4_paste_Button->setWhatsThis(tr("Paste current patch from clipboard<br>pressing this button will load the current patch to a clipboard<br>the clipboard is re-loaded<br>from the previous session copy."));
    this->temp5_copy_Button = new customButton(tr("Patch Copy"), false, QPoint(805, tempRowOffset), this, ":/images/pushbutton.png");
    this->temp5_copy_Button->setWhatsThis(tr("Copy current patch to clipboard<br>pressing this button will save the current patch to a clipboard<br>the clipboard is saved to file and is re-loaded<br>on the next session startup."));
    this->temp5_paste_Button = new customButton(tr("Patch Paste"), false, QPoint(889, tempRowOffset), this, ":/images/pushbutton.png");
    this->temp5_paste_Button->setWhatsThis(tr("Paste current patch from clipboard<br>pressing this button will load the current patch to a clipboard<br>the clipboard is re-loaded<br>from the previous session copy."));

    SysxIO *sysxIO = SysxIO::Instance();
    QObject::connect(this, SIGNAL(setStatusSymbol(int)), sysxIO, SIGNAL(setStatusSymbol(int)));
    QObject::connect(this, SIGNAL(setStatusProgress(int)), sysxIO, SIGNAL(setStatusProgress(int)));
    QObject::connect(this, SIGNAL(setStatusMessage(QString)), sysxIO, SIGNAL(setStatusMessage(QString)));

    QObject::connect(sysxIO, SIGNAL(notConnectedSignal()), this, SLOT(notConnected()));
    QObject::connect(this, SIGNAL(notConnectedSignal()), this, SLOT(notConnected()));

    QObject::connect(this->parent(), SIGNAL(updateSignal()), this, SLOT(updateDisplay()));
    QObject::connect(this, SIGNAL(updateSignal()), this->parent(), SIGNAL(updateSignal()));

    QObject::connect(this->connectButton, SIGNAL(valueChanged(bool)), this, SLOT(connectSignal(bool)));
    QObject::connect(this->writeButton, SIGNAL(valueChanged(bool)), this, SLOT(writeSignal(bool)));
    QObject::connect(this->autoButton, SIGNAL(valueChanged(bool)), this, SLOT(autosyncSignal(bool)));

    QObject::connect(this->normal_PU_Button, SIGNAL(valueChanged(bool)), this->parent(), SIGNAL(normal_PU_buttonSignal(bool)));
    QObject::connect(this->structure_1_Button, SIGNAL(valueChanged(bool)), this->parent(), SIGNAL(structure_1_buttonSignal(bool)));
    QObject::connect(this->structure_2_Button, SIGNAL(valueChanged(bool)), this->parent(), SIGNAL(structure_2_buttonSignal(bool)));
    QObject::connect(this->modeling_Button, SIGNAL(valueChanged(bool)), this->parent(), SIGNAL(modeling_buttonSignal(bool)));
    QObject::connect(this->synth1_Button, SIGNAL(valueChanged(bool)), this->parent(), SIGNAL(synth1_buttonSignal(bool)));
    QObject::connect(this->synth2_Button, SIGNAL(valueChanged(bool)), this->parent(), SIGNAL(synth2_buttonSignal(bool)));
    QObject::connect(this->amp_Button, SIGNAL(valueChanged(bool)), this->parent(), SIGNAL(amp_buttonSignal(bool)));
    QObject::connect(this->ns1_Button, SIGNAL(valueChanged(bool)), this->parent(), SIGNAL(ns1_buttonSignal(bool)));
    QObject::connect(this->mod_Button, SIGNAL(valueChanged(bool)), this->parent(), SIGNAL(mod_buttonSignal(bool)));
    QObject::connect(this->mfx_Button, SIGNAL(valueChanged(bool)), this->parent(), SIGNAL(mfx_buttonSignal(bool)));
    QObject::connect(this->reverb_Button, SIGNAL(valueChanged(bool)), this->parent(), SIGNAL(reverb_buttonSignal(bool)));
    QObject::connect(this->delay_Button, SIGNAL(valueChanged(bool)), this->parent(), SIGNAL(delay_buttonSignal(bool)));
    QObject::connect(this->chorus_Button, SIGNAL(valueChanged(bool)), this->parent(), SIGNAL(chorus_buttonSignal(bool)));
    QObject::connect(this->eq_Button, SIGNAL(valueChanged(bool)), this->parent(), SIGNAL(eq_buttonSignal(bool)));
    QObject::connect(this->pedal_Button, SIGNAL(valueChanged(bool)), this->parent(), SIGNAL(pedal_buttonSignal(bool)));
    QObject::connect(this->master_Button, SIGNAL(valueChanged(bool)), this->parent(), SIGNAL(master_buttonSignal(bool)));
    QObject::connect(this->system_Button, SIGNAL(valueChanged(bool)), this->parent(), SIGNAL(system_buttonSignal(bool)));
    QObject::connect(this->ez_edit_Button, SIGNAL(valueChanged(bool)), this->parent(), SIGNAL(ez_edit_buttonSignal(bool)));
    QObject::connect(this->assign1_Button, SIGNAL(valueChanged(bool)), this->parent(), SIGNAL(assign1_buttonSignal(bool)));
    QObject::connect(this->assign2_Button, SIGNAL(valueChanged(bool)), this->parent(), SIGNAL(assign2_buttonSignal(bool)));
    QObject::connect(this->assign3_Button, SIGNAL(valueChanged(bool)), this->parent(), SIGNAL(assign3_buttonSignal(bool)));
    QObject::connect(this->assign4_Button, SIGNAL(valueChanged(bool)), this->parent(), SIGNAL(assign4_buttonSignal(bool)));
    QObject::connect(this->assign5_Button, SIGNAL(valueChanged(bool)), this->parent(), SIGNAL(assign5_buttonSignal(bool)));
    QObject::connect(this->assign6_Button, SIGNAL(valueChanged(bool)), this->parent(), SIGNAL(assign6_buttonSignal(bool)));
    QObject::connect(this->assign7_Button, SIGNAL(valueChanged(bool)), this->parent(), SIGNAL(assign7_buttonSignal(bool)));
    QObject::connect(this->assign8_Button, SIGNAL(valueChanged(bool)), this->parent(), SIGNAL(assign8_buttonSignal(bool)));

    QObject::connect(this->parent(), SIGNAL(normal_PU_statusSignal(bool)), this->normal_PU_Button, SLOT(setValue(bool)));
    QObject::connect(this->parent(), SIGNAL(structure_1_statusSignal(bool)), this->structure_1_Button, SLOT(setValue(bool)));
    QObject::connect(this->parent(), SIGNAL(structure_2_statusSignal(bool)), this->structure_2_Button, SLOT(setValue(bool)));
    QObject::connect(this->parent(), SIGNAL(modeling_statusSignal(bool)), this->modeling_Button, SLOT(setValue(bool)));
    QObject::connect(this->parent(), SIGNAL(synth1_statusSignal(bool)), this->synth1_Button, SLOT(setValue(bool)));
    QObject::connect(this->parent(), SIGNAL(synth2_statusSignal(bool)), this->synth2_Button, SLOT(setValue(bool)));
    QObject::connect(this->parent(), SIGNAL(amp_statusSignal(bool)), this->amp_Button, SLOT(setValue(bool)));
    QObject::connect(this->parent(), SIGNAL(ns1_statusSignal(bool)), this->ns1_Button, SLOT(setValue(bool)));
    QObject::connect(this->parent(), SIGNAL(mod_statusSignal(bool)), this->mod_Button, SLOT(setValue(bool)));
    QObject::connect(this->parent(), SIGNAL(mfx_statusSignal(bool)), this->mfx_Button, SLOT(setValue(bool)));
    QObject::connect(this->parent(), SIGNAL(reverb_statusSignal(bool)), this->reverb_Button, SLOT(setValue(bool)));
    QObject::connect(this->parent(), SIGNAL(delay_statusSignal(bool)), this->delay_Button, SLOT(setValue(bool)));
    QObject::connect(this->parent(), SIGNAL(chorus_statusSignal(bool)), this->chorus_Button, SLOT(setValue(bool)));
    QObject::connect(this->parent(), SIGNAL(eq_statusSignal(bool)), this->eq_Button, SLOT(setValue(bool)));
    QObject::connect(this->parent(), SIGNAL(assign1_statusSignal(bool)), this->assign1_Button, SLOT(setValue(bool)));
    QObject::connect(this->parent(), SIGNAL(assign2_statusSignal(bool)), this->assign2_Button, SLOT(setValue(bool)));
    QObject::connect(this->parent(), SIGNAL(assign3_statusSignal(bool)), this->assign3_Button, SLOT(setValue(bool)));
    QObject::connect(this->parent(), SIGNAL(assign4_statusSignal(bool)), this->assign4_Button, SLOT(setValue(bool)));
    QObject::connect(this->parent(), SIGNAL(assign5_statusSignal(bool)), this->assign5_Button, SLOT(setValue(bool)));
    QObject::connect(this->parent(), SIGNAL(assign6_statusSignal(bool)), this->assign6_Button, SLOT(setValue(bool)));
    QObject::connect(this->parent(), SIGNAL(assign7_statusSignal(bool)), this->assign7_Button, SLOT(setValue(bool)));
    QObject::connect(this->parent(), SIGNAL(assign8_statusSignal(bool)), this->assign8_Button, SLOT(setValue(bool)));
    QObject::connect(this->temp1_copy_Button, SIGNAL(valueChanged(bool)),  this, SLOT(temp1_copy(bool)));
    QObject::connect(this->temp1_paste_Button, SIGNAL(valueChanged(bool)), this, SLOT(temp1_paste(bool)));
    QObject::connect(this->temp2_copy_Button, SIGNAL(valueChanged(bool)),  this, SLOT(temp2_copy(bool)));
    QObject::connect(this->temp2_paste_Button, SIGNAL(valueChanged(bool)), this, SLOT(temp2_paste(bool)));
    QObject::connect(this->temp3_copy_Button, SIGNAL(valueChanged(bool)),  this, SLOT(temp3_copy(bool)));
    QObject::connect(this->temp3_paste_Button, SIGNAL(valueChanged(bool)), this, SLOT(temp3_paste(bool)));
    QObject::connect(this->temp4_copy_Button, SIGNAL(valueChanged(bool)),  this, SLOT(temp4_copy(bool)));
    QObject::connect(this->temp4_paste_Button, SIGNAL(valueChanged(bool)), this, SLOT(temp4_paste(bool)));
    QObject::connect(this->temp5_copy_Button, SIGNAL(valueChanged(bool)),  this, SLOT(temp5_copy(bool)));
    QObject::connect(this->temp5_paste_Button, SIGNAL(valueChanged(bool)), this, SLOT(temp5_paste(bool)));


    set_temp();

    QString midiIn = preferences->getPreferences("Midi", "MidiIn", "device");
    QString midiOut = preferences->getPreferences("Midi", "MidiOut", "device");
    if(!midiIn.isEmpty() && !midiOut.isEmpty())
    {autoconnect(); } else {
        QMessageBox *msgBox = new QMessageBox();
        msgBox->isTopLevel();
        msgBox->setWindowTitle(deviceType + tr(" FloorBoard"));
        msgBox->setIcon(QMessageBox::Warning);
        msgBox->setTextFormat(Qt::RichText);
        QString msgText;
        msgText.append("<font size='+1'><b>");
        msgText.append(tr("Midi device not selected in Preferences Menu."));
        msgText.append("<b></font><br>");
        msgText.append(tr("Select the GR-55 or a midi adapter from the Preferences USB/Midi menu and press the 'Connect' button"));
        msgBox->setText(msgText);
        msgBox->setStandardButtons(QMessageBox::Ok);
        msgBox->exec();
        };
}

QPoint floorBoardDisplay::getPos()
{
    return this->pos;
}

void floorBoardDisplay::setPos(QPoint newPos)
{
    this->move(newPos);
    this->pos = newPos;
}

void floorBoardDisplay::setValueDisplay(QString fxName, QString valueName, QString value)
{
    this->valueDisplay->setMainText(fxName);
    this->valueDisplay->setSubText(valueName, value);
}

void floorBoardDisplay::setPatchDisplay(QString patchName)
{
    SysxIO *sysxIO = SysxIO::Instance();
    if(sysxIO->getFileName() != ":default.syx") // Keep the initial version display if the default.syx is loaded at startup.
    {
        QString fileName = sysxIO->getFileName();
        this->patchDisplay->setMainText(patchName);
        this->patchDisplay->setSubText(fileName.section('/', -1, -1));
        this->patchName = patchName;
    };
    if(sysxIO->getFileName() == tr("init patch") || sysxIO->getFileName() == ":default.syx")
    {
        sysxIO->setFileName("");
        this->patchName = tr("Empty");
    }
    else
    {
        if(sysxIO->getFileName() == deviceType + tr(" patch"))
        {
            sysxIO->setFileName("");
            if(this->patchLoadError)
            {
                QMessageBox *msgBox = new QMessageBox();
                msgBox->setWindowTitle(deviceType + tr(" FloorBoard"));
                msgBox->setIcon(QMessageBox::Warning);
                msgBox->setTextFormat(Qt::RichText);
                QString msgText;
                msgText.append("<font size='+1'><b>");
                msgText.append(tr("Error while changing banks."));
                msgText.append("<b></font><br>");
                msgText.append(tr("An incorrect patch has been loaded. Please try to load the patch again."));
                msgBox->setText(msgText);
                msgBox->setStandardButtons(QMessageBox::Ok);
                msgBox->exec();

                sysxIO->setBank(0);
                sysxIO->setPatch(0);
            };
        };
        this->initPatch->setIndex(0);
    };
}

void floorBoardDisplay::setPatchNumDisplay(int bank, int patch)
{
    if(bank > 0)
    {
        SysxIO *sysxIO = SysxIO::Instance();
        if(bank <= bankTotalUser)
        {
            this->patchNumDisplay->resetAllColor();
            this->patchNumDisplay->setSubText(tr("User"));
        }
        else if (bank > bankTotalUser)
        {
            //this->patchNumDisplay->setAllColor(QColor(255,0,0));
            int mode_check = sysxIO->getSourceValue("Structure", "00", "00", "00");     //check for guitar mode
            if(mode_check > 0)
            {
                if(bank>99 && bank<112){ this->patchNumDisplay->setSubText(tr("Lead")); };
                if(bank>111 && bank<124){ this->patchNumDisplay->setSubText(tr("Rhythm")); };
                if(bank>123){ this->patchNumDisplay->setSubText(tr("Other")); };
            }
            else
            {   if(bank>99 && bank<140){ this->patchNumDisplay->setSubText(tr("Lead")); };
                if(bank>139 && bank<180){ this->patchNumDisplay->setSubText(tr("Rhythm")); };
                if(bank>179){ this->patchNumDisplay->setSubText(tr("Other")); };
            };
        };

        QString str;
        if(bank < 100)
        {
            str.append("U");
            if(bank < 10) {	str.append("0"); };
            str.append(QString::number(bank, 10));
        }
        else
        {
            int mode_check = sysxIO->getSourceValue("Structure", "00", "00", "00");     //check for guitar mode
            if(mode_check > 0)
            {
            if(bank>99 && bank<112){ bank=bank-99; };
            if(bank>111 && bank<124){ bank=bank-111; };
            if(bank>123){ bank=bank-123; };
            }
            else
            {
                if(bank>99 && bank<140){ bank=bank-99; };
                if(bank>139 && bank<180){ bank=bank-139; };
                if(bank>179){ bank=bank-179; };
            };
            str.append("P");
            if(bank < 10) {	str.append("0"); };
            str.append(QString::number(bank, 10));
        };
        str.append(":");
        str.append(QString::number(patch, 10));
        this->patchNumDisplay->setMainText(str, Qt::AlignCenter);
    }
    else
    {
        //this->patchNumDisplay->clearAll();
        this->patchNumDisplay->setSubText(tr("Temp"));
        QString str = tr("Buffer");
        this->patchNumDisplay->setMainText(str, Qt::AlignCenter);
    };
}

void floorBoardDisplay::updateDisplay()
{
    SysxIO *sysxIO = SysxIO::Instance();
    QString area = "Structure";
    QList<QString> nameArray = sysxIO->getFileSource(area, nameAddress, "00");
    QString name;
    for(int i=sysxNameOffset;i<(sysxNameOffset+nameLength);i++ )
    {

        QString hexStr = nameArray.at(i);
        bool ok;
        name.append( (char)(hexStr.toInt(&ok, 16)) );
    };

    QString patchName = name.trimmed();
    sysxIO->setCurrentPatchName(patchName);
    if(sysxIO->getRequestName().trimmed() != patchName.trimmed())
    {
        this->patchLoadError = true;
    }
    else
    {
        this->patchLoadError = false;
    };


    this->setPatchDisplay(patchName);
    if(sysxIO->isDevice())
    {
        int bank = sysxIO->getBank();
        int patch = sysxIO->getPatch();
        this->setPatchNumDisplay(bank, patch);
    }
    else
    {
        this->patchNumDisplay->clearAll();
    };
    this->valueDisplay->clearAll();

    if(sysxIO->isDevice() )  // comment out from here
    {
        if(sysxIO->getBank() > 99)
        {
            this->writeButton->setBlink(false);
            this->writeButton->setValue(true);
        }
        else
        {
            this->writeButton->setBlink(false);
            this->writeButton->setValue(true);
        };
        int bank = sysxIO->getBank();
        int patch = sysxIO->getPatch();
        this->setPatchNumDisplay(bank, patch);
    }
    else if(sysxIO->getBank() != 0)
    {
        if(sysxIO->isConnected())
        {
            this->writeButton->setBlink(false);
            this->writeButton->setValue(false);
        };
        int bank = sysxIO->getBank();
        int patch = sysxIO->getPatch();
        this->setPatchNumDisplay(bank, patch);
    }
    else
    {
        patchNumDisplay->clearAll();
        this->writeButton->setBlink(false);
        this->writeButton->setValue(false);
    };
}

void floorBoardDisplay::autoconnect()
{
    QString sysxMsg;
    SysxIO *sysxIO = SysxIO::Instance();
    //this->connectButtonActive = value;
    if(!sysxIO->isConnected() && sysxIO->deviceReady())
    {
        emit setStatusSymbol(2);
        emit setStatusMessage(tr("Connecting"));

        this->connectButton->setBlink(true);
        sysxIO->setDeviceReady(false); // Reserve the device for interaction.

        QObject::disconnect(sysxIO, SIGNAL(sysxReply(QString)));
        QObject::connect(sysxIO, SIGNAL(sysxReply(QString)),
                         this, SLOT(autoConnectionResult(QString)));

        sysxIO->sendSysx(idRequestString); // GR-55 Identity Request.
    }
    else
    {
        emit notConnected();
        sysxIO->setNoError(true);		// Reset the error status (else we could never retry :) ).
    };
}

void floorBoardDisplay::autoConnectionResult(QString sysxMsg)
{
    SysxIO *sysxIO = SysxIO::Instance();
    QObject::disconnect(sysxIO, SIGNAL(sysxReply(QString)),
                        this, SLOT(autoConnectionResult(QString)));

    sysxIO->setDeviceReady(true); // Free the device after finishing interaction.
    if(sysxIO->noError())
    {
        if(sysxMsg.contains(idReplyPatern))
        {
            this->connectButton->setBlink(false);
            this->connectButton->setValue(true);
            sysxIO->setConnected(true);
            emit connectedSignal();

            if(sysxIO->getBank() != 0)
            {
                this->writeButton->setBlink(false);
                this->writeButton->setValue(false);
            };
        }else
        {
            this->connectButton->setBlink(false);
            this->connectButton->setValue(false);
            sysxIO->setConnected(false);
        };
    }
    else
    {
        notConnected();
        sysxIO->setNoError(true);		// Reset the error status (else we could never retry :) ).
    };
}

void floorBoardDisplay::set_temp()
{

    SysxIO *sysxIO = SysxIO::Instance();
    QByteArray data;

    QFile file1("temp-1.syx");   // Read the sysx file .
    if (file1.open(QIODevice::ReadOnly))
    {	data = file1.readAll(); };

    QString sysxBuffer;
    for(int i=0;i<data.size();i++)
    {
        unsigned char byte = (char)data[i];
        unsigned int n = (int)byte;
        QString hex = QString::number(n, 16).toUpper();     // convert QByteArray to QString
        if (hex.length() < 2) hex.prepend("0");
        sysxBuffer.append(hex);
    };
    if( data.size() == fullPatchSize)
    {
        QString patchText;
        unsigned char r;
        unsigned int a = sysxNameOffset; // locate patch text start position from the start of the file
        for (int b=0;b<nameLength;b++)
        {
            r = (char)data[a+b];
            patchText.append(r);         // extract the text characters from the current patch name.
        };
        this->temp1Display->setMainText(patchText, Qt::AlignCenter);
        sysxIO->temp1_sysxMsg = sysxBuffer;
    };

    data.clear();
    QFile file2("temp-2.syx");   // Read the sysx file .
    if (file2.open(QIODevice::ReadOnly))
    {	data = file2.readAll(); };

    sysxBuffer.clear();
    for(int i=0;i<data.size();i++)
    {
        unsigned char byte = (char)data[i];
        unsigned int n = (int)byte;
        QString hex = QString::number(n, 16).toUpper();     // convert QByteArray to QString
        if (hex.length() < 2) hex.prepend("0");
        sysxBuffer.append(hex);
    };
    if( data.size() == fullPatchSize)
    {
        QString patchText;
        unsigned char r;
        unsigned int a = sysxNameOffset; // locate patch text start position from the start of the file
        for (int b=0;b<nameLength;b++)
        {
            r = (char)data[a+b];
            patchText.append(r);         // extract the text characters from the current patch name.
        };
        this->temp2Display->setMainText(patchText, Qt::AlignCenter);
        sysxIO->temp2_sysxMsg = sysxBuffer;
    };

    data.clear();
    QFile file3("temp-3.syx");   // Read the default GT-3 sysx file so we don't start empty handed.
    if (file3.open(QIODevice::ReadOnly))
    {	data = file3.readAll(); };


    sysxBuffer.clear();
    for(int i=0;i<data.size();i++)
    {
        unsigned char byte = (char)data[i];
        unsigned int n = (int)byte;
        QString hex = QString::number(n, 16).toUpper();     // convert QByteArray to QString
        if (hex.length() < 2) hex.prepend("0");
        sysxBuffer.append(hex);
    };
    if( data.size() == fullPatchSize)
    {
        QString patchText;
        unsigned char r;
        unsigned int a = sysxNameOffset; // locate patch text start position from the start of the file
        for (int b=0;b<nameLength;b++)
        {
            r = (char)data[a+b];
            patchText.append(r);         // extract the text characters from the current patch name.
        };
        this->temp3Display->setMainText(patchText, Qt::AlignCenter);
        sysxIO->temp3_sysxMsg = sysxBuffer;
    };

    data.clear();
    QFile file4("temp-4.syx");   // Read the sysx file .
    if (file4.open(QIODevice::ReadOnly))
    {	data = file4.readAll(); };

    sysxBuffer.clear();
    for(int i=0;i<data.size();i++)
    {
        unsigned char byte = (char)data[i];
        unsigned int n = (int)byte;
        QString hex = QString::number(n, 16).toUpper();     // convert QByteArray to QString
        if (hex.length() < 2) hex.prepend("0");
        sysxBuffer.append(hex);
    };
    if( data.size() == fullPatchSize)

    {
        QString patchText;
        unsigned char r;
        unsigned int a = sysxNameOffset; // locate patch text start position from the start of the file
        for (int b=0;b<nameLength;b++)
        {
            r = (char)data[a+b];
            patchText.append(r);         // extract the text characters from the current patch name.
        };
        this->temp4Display->setMainText(patchText, Qt::AlignCenter);
        sysxIO->temp4_sysxMsg = sysxBuffer;
    };

    data.clear();
    QFile file5("temp-5.syx");   // Read the sysx file .
    if (file5.open(QIODevice::ReadOnly))
    {	data = file5.readAll(); };

    sysxBuffer.clear();
    for(int i=0;i<data.size();i++)
    {
        unsigned char byte = (char)data[i];
        unsigned int n = (int)byte;
        QString hex = QString::number(n, 16).toUpper();     // convert QByteArray to QString
        if (hex.length() < 2) hex.prepend("0");
        sysxBuffer.append(hex);
    };
    if( data.size() == fullPatchSize)

    {
        QString patchText;
        unsigned char r;
        unsigned int a = sysxNameOffset; // locate patch text start position from the start of the file
        for (int b=0;b<nameLength;b++)
        {
            r = (char)data[a+b];
            patchText.append(r);         // extract the text characters from the current patch name.
        };
        this->temp5Display->setMainText(patchText, Qt::AlignCenter);
        sysxIO->temp5_sysxMsg = sysxBuffer;
    };
}

void floorBoardDisplay::temp1_copy(bool value)
{
    SysxIO *sysxIO = SysxIO::Instance();

    QString sysxMsg;
    QList< QList<QString> > patchData = sysxIO->getFileSource().hex; // Get the loaded patch data.
    //QList<QString> patchAddress = sysxIO->getFileSource().address;
    QString addr1 = tempBulkWrite;  // temp address
    QString addr2 = QString::number(0, 16).toUpper();

    for(int i=0;i<patchData.size();++i)
    {
        QList<QString> data = patchData.at(i);
        for(int x=0;x<data.size();++x)
        {
            QString hex;
            if(x == sysxAddressOffset)
            { hex = addr1; }
            else if(x == sysxAddressOffset + 1)
            {	hex = addr2; }
            else
            {	hex = data.at(x);	};
            if (hex.length() < 2) hex.prepend("0");
            sysxMsg.append(hex);
        };
    };
    if( sysxMsg.size()/2 == fullPatchSize)
    {
        this->patchName = sysxIO->getCurrentPatchName();
        this->temp1Display->setMainText(patchName, Qt::AlignCenter);
        sysxIO->temp1_sysxMsg = sysxMsg;
        save_temp("temp-1.syx", sysxMsg);
    } else {
        QApplication::beep();
        QString size = QString::number(sysxMsg.size()/2, 10);
        sysxIO->emitStatusdBugMessage(tr("in-consistant patch data detected ") + size + tr("bytes: re-save or re-load file to correct"));
    };
}

void floorBoardDisplay::temp1_paste(bool value)
{
    SysxIO *sysxIO = SysxIO::Instance();
    this->temp1_sysxMsg = sysxIO->temp1_sysxMsg;
    if (!temp1_sysxMsg.isEmpty() && sysxIO->deviceReady() )
    {
        SysxIO *sysxIO = SysxIO::Instance();
        sysxIO->setFileSource("patch", temp1_sysxMsg);
        emit updateSignal();
        sysxIO->writeToBuffer();
    }
    else
    {
        QApplication::beep();
        sysxIO->emitStatusdBugMessage(tr("patch must be copied to clipboard first"));
    };
}

void floorBoardDisplay::temp2_copy(bool value)
{
    SysxIO *sysxIO = SysxIO::Instance();

    QString sysxMsg;
    QList< QList<QString> > patchData = sysxIO->getFileSource().hex; // Get the loaded patch data.
    //QList<QString> patchAddress = sysxIO->getFileSource().address;
    QString addr1 = tempBulkWrite;  // temp address
    QString addr2 = QString::number(0, 16).toUpper();

    for(int i=0;i<patchData.size();++i)
    {
        QList<QString> data = patchData.at(i);
        for(int x=0;x<data.size();++x)
        {
            QString hex;
            if(x == sysxAddressOffset)
            { hex = addr1; }
            else if(x == sysxAddressOffset + 1)
            {	hex = addr2; }
            else
            {	hex = data.at(x);	};
            if (hex.length() < 2) hex.prepend("0");
            sysxMsg.append(hex);
        };
    };
    if( sysxMsg.size()/2 == fullPatchSize)
    {
        this->patchName = sysxIO->getCurrentPatchName();
        this->temp2Display->setMainText(patchName, Qt::AlignCenter);
        sysxIO->temp2_sysxMsg = sysxMsg;
        save_temp("temp-2.syx", sysxMsg);
    } else {
        QApplication::beep();
        QString size = QString::number(sysxMsg.size()/2, 10);
        sysxIO->emitStatusdBugMessage(tr("in-consistant patch data detected ") + size + tr("bytes: re-save or re-load file to correct"));
    };
}

void floorBoardDisplay::temp2_paste(bool value)
{
    SysxIO *sysxIO = SysxIO::Instance();
    this->temp2_sysxMsg = sysxIO->temp2_sysxMsg;
    if (!temp2_sysxMsg.isEmpty() && sysxIO->deviceReady() )
    {
        SysxIO *sysxIO = SysxIO::Instance();
        sysxIO->setFileSource("patch", temp2_sysxMsg);
        emit updateSignal();
        sysxIO->writeToBuffer();
    }else
    {
        QApplication::beep();
        sysxIO->emitStatusdBugMessage(tr("patch must be copied to clipboard first"));
    };
}

void floorBoardDisplay::temp3_copy(bool value)
{
    SysxIO *sysxIO = SysxIO::Instance();

    QString sysxMsg;
    QList< QList<QString> > patchData = sysxIO->getFileSource().hex; // Get the loaded patch data.
    //QList<QString> patchAddress = sysxIO->getFileSource().address;
    QString addr1 = tempBulkWrite;  // temp address
    QString addr2 = QString::number(0, 16).toUpper();

    for(int i=0;i<patchData.size();++i)
    {
        QList<QString> data = patchData.at(i);
        for(int x=0;x<data.size();++x)
        {
            QString hex;
            if(x == sysxAddressOffset)
            { hex = addr1; }
            else if(x == sysxAddressOffset + 1)
            {	hex = addr2; }
            else
            {	hex = data.at(x);	};
            if (hex.length() < 2) hex.prepend("0");
            sysxMsg.append(hex);
        };
    };
    if( sysxMsg.size()/2 == fullPatchSize)
    {
        this->patchName = sysxIO->getCurrentPatchName();
        this->temp3Display->setMainText(patchName, Qt::AlignCenter);
        sysxIO->temp3_sysxMsg = sysxMsg;
        save_temp("temp-3.syx", sysxMsg);
    } else {
        QApplication::beep();
        QString size = QString::number(sysxMsg.size()/2, 10);
        sysxIO->emitStatusdBugMessage(tr("in-consistant patch data detected ") + size + tr("bytes: re-save or re-load file to correct"));
    };
}

void floorBoardDisplay::temp3_paste(bool value)
{
    SysxIO *sysxIO = SysxIO::Instance();
    this->temp3_sysxMsg = sysxIO->temp3_sysxMsg;
    if (!temp3_sysxMsg.isEmpty() && sysxIO->deviceReady() )
    {
        SysxIO *sysxIO = SysxIO::Instance();
        sysxIO->setFileSource("patch", temp3_sysxMsg);
        emit updateSignal();
        sysxIO->writeToBuffer();
    }else
    {
        QApplication::beep();
        sysxIO->emitStatusdBugMessage(tr("patch must be copied to clipboard first"));
    };
}

void floorBoardDisplay::temp4_copy(bool value)
{
    SysxIO *sysxIO = SysxIO::Instance();

    QString sysxMsg;
    QList< QList<QString> > patchData = sysxIO->getFileSource().hex; // Get the loaded patch data.
    //QList<QString> patchAddress = sysxIO->getFileSource().address;
    QString addr1 = tempBulkWrite;  // temp address
    QString addr2 = QString::number(0, 16).toUpper();

    for(int i=0;i<patchData.size();++i)
    {
        QList<QString> data = patchData.at(i);
        for(int x=0;x<data.size();++x)
        {
            QString hex;
            if(x == sysxAddressOffset)
            { hex = addr1; }
            else if(x == sysxAddressOffset + 1)
            {	hex = addr2; }
            else
            {	hex = data.at(x);	};
            if (hex.length() < 2) hex.prepend("0");
            sysxMsg.append(hex);
        };
    };
    if( sysxMsg.size()/2 == fullPatchSize)
    {
        this->patchName = sysxIO->getCurrentPatchName();
        this->temp4Display->setMainText(patchName, Qt::AlignCenter);
        sysxIO->temp4_sysxMsg = sysxMsg;
        save_temp("temp-4.syx", sysxMsg);
    } else {
        QApplication::beep();
        QString size = QString::number(sysxMsg.size()/2, 10);
        sysxIO->emitStatusdBugMessage(tr("in-consistant patch data detected ") + size + tr("bytes: re-save or re-load file to correct"));
    };
}

void floorBoardDisplay::temp4_paste(bool value)
{
    SysxIO *sysxIO = SysxIO::Instance();
    this->temp4_sysxMsg = sysxIO->temp4_sysxMsg;
    if (!temp4_sysxMsg.isEmpty() && sysxIO->deviceReady() )
    {
        SysxIO *sysxIO = SysxIO::Instance();
        sysxIO->setFileSource("patch", temp4_sysxMsg);
        emit updateSignal();
        sysxIO->writeToBuffer();
    }else
    {
        QApplication::beep();
        sysxIO->emitStatusdBugMessage(tr("patch must be copied to clipboard first"));
    };
}

void floorBoardDisplay::temp5_copy(bool value)
{
    SysxIO *sysxIO = SysxIO::Instance();

    QString sysxMsg;
    QList< QList<QString> > patchData = sysxIO->getFileSource().hex; // Get the loaded patch data.
    //QList<QString> patchAddress = sysxIO->getFileSource().address;
    QString addr1 = tempBulkWrite;  // temp address
    QString addr2 = QString::number(0, 16).toUpper();

    for(int i=0;i<patchData.size();++i)
    {
        QList<QString> data = patchData.at(i);
        for(int x=0;x<data.size();++x)
        {
            QString hex;
            if(x == sysxAddressOffset)
            { hex = addr1; }
            else if(x == sysxAddressOffset + 1)
            {	hex = addr2; }
            else
            {	hex = data.at(x);	};
            if (hex.length() < 2) hex.prepend("0");
            sysxMsg.append(hex);
        };
    };
    if( sysxMsg.size()/2 == fullPatchSize)
    {
        this->patchName = sysxIO->getCurrentPatchName();
        this->temp5Display->setMainText(patchName, Qt::AlignCenter);
        sysxIO->temp5_sysxMsg = sysxMsg;
        save_temp("temp-5.syx", sysxMsg);
    } else {
        QApplication::beep();
        QString size = QString::number(sysxMsg.size()/2, 10);
        sysxIO->emitStatusdBugMessage(tr("in-consistant patch data detected ") + size + tr("bytes: re-save or re-load file to correct"));
    };
}

void floorBoardDisplay::temp5_paste(bool value)
{
    SysxIO *sysxIO = SysxIO::Instance();
    this->temp5_sysxMsg = sysxIO->temp5_sysxMsg;
    if (!temp5_sysxMsg.isEmpty() && sysxIO->deviceReady() )
    {
        SysxIO *sysxIO = SysxIO::Instance();
        sysxIO->setFileSource("patch", temp5_sysxMsg);
        emit updateSignal();
        sysxIO->writeToBuffer();
    }else
    {
        QApplication::beep();
        sysxIO->emitStatusdBugMessage(tr("patch must be copied to clipboard first"));
    };
}

void floorBoardDisplay::save_temp(QString fileName, QString sysxMsg)
{
    QFile file(fileName);
    if (file.open(QIODevice::WriteOnly))
    {
        QByteArray out;
        unsigned int count=0;
        QString data = sysxMsg;
        int x = data.size()/2;
        for (int a=0;a<x;++a)
        {
            QString str = data.at(a*2);
            str.append(data.at((a*2)+1));
            bool ok;
            unsigned int n = str.toInt(&ok, 16);
            out[count] = (char)n;
            count++;
        };
        file.write(out);
    };
}

void floorBoardDisplay::connectSignal(bool value)
{
    QString sysxMsg;
    SysxIO *sysxIO = SysxIO::Instance();
    this->connectButtonActive = value;
    if(connectButtonActive == true && sysxIO->deviceReady())
    {
        emit setStatusSymbol(2);
        emit setStatusMessage(tr("Connecting"));

        this->connectButton->setBlink(true);
        sysxIO->setDeviceReady(false); // Reserve the device for interaction.

        QObject::disconnect(sysxIO, SIGNAL(sysxReply(QString)));
        QObject::connect(sysxIO, SIGNAL(sysxReply(QString)),
                         this, SLOT(connectionResult(QString)));

        sysxIO->sendSysx(idRequestString); // GR55 Identity Request.
    }
    else
    {
        emit notConnected();
        sysxIO->setNoError(true);		// Reset the error status (else we could never retry :) ).
    };
}

void floorBoardDisplay::connectionResult(QString sysxMsg)
{
    SysxIO *sysxIO = SysxIO::Instance();
    QObject::disconnect(sysxIO, SIGNAL(sysxReply(QString)),
                        this, SLOT(connectionResult(QString)));

    sysxIO->setDeviceReady(true); // Free the device after finishing interaction.

    //DeBugGING OUTPUT
    Preferences *preferences = Preferences::Instance(); // Load the preferences.
    if(preferences->getPreferences("Midi", "DBug", "bool")=="true")
    {
        this->connectButton->setBlink(false);
        this->connectButton->setValue(true);
        sysxIO->setConnected(true);
        emit connectedSignal();
        emit setStatusMessage(tr("Ready"));

        if(sysxIO->getBank() != 0)
        {
            this->writeButton->setBlink(true);
            this->writeButton->setValue(false);
        };
    }

    else if(sysxIO->noError())
    {
        if(sysxMsg.contains(idReplyPatern) && connectButtonActive == true)
        {
            this->connectButton->setBlink(false);
            this->connectButton->setValue(true);
            sysxIO->setConnected(true);
            emit connectedSignal();

            if(sysxIO->getBank() != 0)
            {
                this->writeButton->setBlink(true);
                this->writeButton->setValue(false);
            };
        }
        else if(!sysxMsg.isEmpty())
        {
            this->connectButton->setBlink(false);
            this->connectButton->setValue(false);
            sysxIO->setConnected(false);

            QMessageBox *msgBox = new QMessageBox();
            msgBox->setWindowTitle(deviceType + tr(" FloorBoard connection Error !!"));
            msgBox->setIcon(QMessageBox::Warning);
            msgBox->setTextFormat(Qt::RichText);
            QString msgText;
            msgText.append("<font size='+1'><b>");
            msgText.append(tr("The device connected is not a ROLAND ") + deviceType + tr(" Guitar Synthesizer."));
            if (sysxMsg.contains(idRequestString))
            {msgText.append(tr("<br>Midi loopback detected, ensure midi device 'thru' is switched off.")); };
            msgText.append("<b></font>");
            msgBox->setText(msgText);
            msgBox->setStandardButtons(QMessageBox::Ok);
            msgBox->exec();

            notConnected();

            emit setStatusSymbol(0);
            emit setStatusProgress(0);
            emit setStatusMessage(tr("Not connected"));
        }
        else
        {
            this->connectButton->setBlink(false);
            this->connectButton->setValue(false);
            sysxIO->setConnected(false);

            QMessageBox *msgBox = new QMessageBox();
            msgBox->setWindowTitle(deviceType + tr(" FloorBoard connection Error !!"));
            msgBox->setIcon(QMessageBox::Warning);
            msgBox->setTextFormat(Qt::RichText);
            QString msgText;
            msgText.append("<font size='+1'><b>");
            msgText.append(tr("The ROLAND ") + deviceType + tr(" Guitar Synth was not found."));
            msgText.append(tr("<br><br>Ensure correct midi device is selected in Menu, "));
            msgText.append(tr("<br>ROLAND drivers are installed and the GR-55 is switched on,"));
            msgText.append("<b></font><br>");
            msgBox->setText(msgText);
            msgBox->setStandardButtons(QMessageBox::Ok);
            msgBox->exec();

            notConnected();

            emit setStatusSymbol(0);
            emit setStatusProgress(0);
            emit setStatusMessage(tr("Not connected"));
        };
    }
    else
    {
        notConnected();
        sysxIO->setNoError(true);		// Reset the error status (else we could never retry :) ).
    };
}

void floorBoardDisplay::writeSignal(bool)
{
    SysxIO *sysxIO = SysxIO::Instance();
    if(sysxIO->isConnected() && sysxIO->deviceReady()) /* Check if we are connected and if the device is free. */
    {
        this->writeButton->setBlink(true);

        if(sysxIO->getBank() == 0) // Check if a bank is sellected.
        {
            sysxIO->setDeviceReady(false);			// Reserve the device for interaction.
            writeToBuffer();
        }
        else // Bank is sellected.
        {
            sysxIO->setDeviceReady(false);			// Reserve the device for interaction.
            {
                if(sysxIO->getBank() > bankTotalUser) // Preset banks are NOT writable so we check.
                {
                    QMessageBox *msgBox = new QMessageBox();
                    msgBox->setWindowTitle(deviceType + tr(" FloorBoard"));
                    msgBox->setIcon(QMessageBox::Warning);
                    msgBox->setTextFormat(Qt::RichText);
                    QString msgText;
                    msgText.append("<font size='+1'><b>");
                    msgText.append(tr("You can't write to the preset banks."));
                    msgText.append("<b></font><br>");
                    msgText.append(tr("Please select a user bank to write this patch to and try again."));
                    msgBox->setText(msgText);
                    msgBox->setStandardButtons(QMessageBox::Ok);
                    msgBox->exec();
                    this->writeButton->setBlink(false); // Allready sync with the buffer so no blinking
                    this->writeButton->setValue(true);	// and so we will also leave the write button active.
                    sysxIO->setDeviceReady(true);
                }
                else /* User bank so we can write to it after confirmation to overwrite stored data. */
                {
                    QString bankNum;
                    QString patchNum;
                    int bank = sysxIO->getBank();
                    int patch = sysxIO->getPatch();
                    bankNum.append(QString::number(bank, 10));
                    if (bankNum.size() < 2){ bankNum.prepend("0"); };
                    bankNum.prepend(" U");
                    patchNum.append(QString::number(patch, 10));

                    QMessageBox *msgBox = new QMessageBox();
                    msgBox->setWindowTitle(deviceType + tr(" FloorBoard"));
                    msgBox->setIcon(QMessageBox::Warning);
                    msgBox->setTextFormat(Qt::RichText);
                    QString msgText;
                    msgText.append("<font size='+1'><b>");
                    msgText.append(tr("You have chosen to write the patch into ") + deviceType + (" memory."));
                    msgText.append("<b></font><br>");
                    msgText.append(tr("This will overwrite the patch currently stored at patch location<br>"));
                    msgText.append("<font size='+2'><b>");
                    if (bank == 101){ msgText.append(("Quick Effects ") + patchNum); }
                    else { msgText.append(bankNum +(":") +patchNum	); };
                    msgText.append("<b></font><br>");
                    msgText.append(tr (" and can't be undone. "));
                    msgBox->setInformativeText(tr("Are you sure you want to continue?"));
                    msgBox->setText(msgText);
                    msgBox->setStandardButtons(QMessageBox::Yes | QMessageBox::No);

                    if(msgBox->exec() == QMessageBox::Yes)
                    {	/* Accepted to overwrite data. So now we have to set destination address by replacing the default (buffer). */

                        writeToMemory();
                        sysxIO->setSyncStatus(true);
                    }
                    else if(sysxIO->isConnected())
                    {
                        sysxIO->setDeviceReady(true);
                        this->writeButton->setBlink(false);
                        //this->writeButton->setValue(true);
                    };
                };
            };
        };
    };
    this->writeButton->setValue(false);
}

void floorBoardDisplay::writeToBuffer()
{
    SysxIO *sysxIO = SysxIO::Instance();
    QMessageBox *msgBox = new QMessageBox();
    msgBox->setWindowTitle(deviceType + tr(" FloorBoard"));
    msgBox->setIcon(QMessageBox::Warning);
    msgBox->setTextFormat(Qt::RichText);
    QString msgText;
    msgText.append("<font size='+1'><b>");
    msgText.append(tr("You have not chosen a User Patch address to Write the patch to"));
    msgText.append("<b></font><br>");
    msgText.append(tr("This will only update the GR-55 Temporary Buffer memory<br>"));
    msgText.append(tr (" with the editor patch. "));
    msgBox->setInformativeText(tr("Select the required destination patch <br>by a single-click on the left panel Patch-Tree"));
    msgBox->setText(msgText);
    msgBox->setStandardButtons(QMessageBox::Close);

    msgBox->exec();
    sysxIO->writeToBuffer();
    sysxIO->setSyncStatus(true);

    this->writeButton->setBlink(false);	// Sync so we stop blinking the button
    this->writeButton->setValue(false);	// and activate the write button.
}

void floorBoardDisplay::writeToMemory()
{
    SysxIO *sysxIO = SysxIO::Instance();

    QString sysxMsg; bool ok;
    QList< QList<QString> > patchData = sysxIO->getFileSource().hex; // Get the loaded patch data.
    emit setStatusSymbol(2);
    emit setStatusMessage(tr("Writing to Patch"));

    int bank = sysxIO->getBank();
    int patch = sysxIO->getPatch();
    QString addr1;
    QString addr2;
    if (bank < 100)
    {
        int patchOffset = (((bank - 1 ) * patchPerBank) + patch) - 1;
        int memmorySize = QString("7F").toInt(&ok, 16) + 1;
        int emptyAddresses = (memmorySize) - ((bankTotalUser * patchPerBank) - (memmorySize));
        if(bank > bankTotalUser) patchOffset += emptyAddresses; //System patches start at a new memmory range.
        int addrMaxSize = QString("80").toInt(&ok, 16);
        int n = (int)(patchOffset / addrMaxSize);

        addr1 = QString::number(32 + n, 16).toUpper();
        addr2 = QString::number(patchOffset - (addrMaxSize * n), 16).toUpper();
    };
    if (addr1.length() < 2) addr1.prepend("0");
    if (addr2.length() < 2) addr2.prepend("0");
    for(int i=0;i<patchData.size();++i)
    {
        QList<QString> data = patchData.at(i);
        for(int x=0;x<data.size();++x)
        {
            QString hex;
            if(x == sysxAddressOffset)
            {
                hex = addr1;
            }
            else if(x == sysxAddressOffset + 1)
            {
                hex = addr2;
            }
            else
            {
                hex = data.at(x);
            };
            if (hex.length() < 2) hex.prepend("0");
            sysxMsg.append(hex);
        };
    };
    sysxIO->setSyncStatus(true);		// Still in sync
    this->writeButton->setBlink(false); // so no blinking here either...
    this->writeButton->setValue(false);	// ... and still the button will be active also ...

    QObject::connect(sysxIO, SIGNAL(sysxReply(QString)), this, SLOT(resetDevice(QString))); // Connect the result signal to a slot that will reset the device after sending.
    sysxMsg.append("F04110000053120F000001016FF7");   // key code to write data to GR-55 memory
    sysxIO->sendSysx(sysxMsg);	                      // Send the data.
    set_bank = bank;
    set_patch = patch;
}

void floorBoardDisplay::autosyncSignal(bool value)
{
    SysxIO *sysxIO = SysxIO::Instance();
    this->autosyncButtonActive = value;
    if(autosyncButtonActive == true  && sysxIO->isConnected())
    {
        autosyncTimer->start(5000);
        autosync();
    }
    else
    {
        autosyncTimer->stop();
        this->autoButton->setBlink(false);
        this->autoButton->setValue(false);
        emit setStatusMessage(tr("Ready"));
    };
}

void floorBoardDisplay::autosync()
{
    SysxIO *sysxIO = SysxIO::Instance();
    //if(autosyncButtonActive == true) { emit sysxIO->relayUpdateSignal(); };
    if(autosyncButtonActive == true && sysxIO->deviceReady() && sysxIO->isConnected())
    {

        emit setStatusSymbol(2);
        emit setStatusMessage(tr("Auto Sync"));

        this->autoButton->setBlink(true);
        sysxIO->setDeviceReady(false); // Reserve the device for interaction.

        QObject::disconnect(sysxIO, SIGNAL(sysxReply(QString)));
        QObject::connect(sysxIO, SIGNAL(sysxReply(QString)),
                         this, SLOT(autosyncResult(QString)));

        sysxIO->requestPatch(0, 0); // GT100 patch request from temorary buffer memory.

    };
}

void floorBoardDisplay::autosyncResult(QString sysxMsg)
{
    SysxIO *sysxIO = SysxIO::Instance();
    QObject::disconnect(sysxIO, SIGNAL(sysxReply(QString)),
                        this, SLOT(autosyncResult(QString)));

    sysxIO->setDeviceReady(true); // Free the device after finishing interaction.
    this->autoButton->setBlink(false);
    sysxMsg = sysxMsg.remove(" ").toUpper();       /* TRANSLATE SYSX MESSAGE FORMAT to 128 byte data blocks */
    if (sysxMsg.size()/2 == patchReplySize){
        QString header = "F0411000005312";
        QString footer ="00F7";
        QString addressMsb = sysxMsg.mid(14,4);    //  copy patch address MSB.
        QString part1 = sysxMsg.mid(22, 256);      //  copy 128 bytes of address 00 data .
        part1.prepend("0000").prepend(addressMsb).prepend(header).append(footer);   //add LSB + MSB address, header and footer.
        QString part2 = sysxMsg.mid(278, 256);     // copy 114 bytes of address 01 data.
        part2.prepend("0100").prepend(addressMsb).prepend(header).append(footer); //add LSB + MSB address, header and footer.
        QString part3 = sysxMsg.mid(534, 156);     //  copy 78 bytes of address 02 data .
        part3.prepend("0200").prepend(addressMsb).prepend(header).append(footer);  //add LSB + MSB address, header and footer.
        QString part4 = sysxMsg.mid(716, 256);    //  copy 128 bytes of address 03 data .
        part4.prepend("0300").prepend(addressMsb).prepend(header).append(footer);  //add LSB + MSB address, header and footer.
        QString part5 = sysxMsg.mid(972, 256);    // copy 114 bytes of address 04 data.
        part5.prepend("0400").prepend(addressMsb).prepend(header).append(footer); //add LSB + MSB address, header and footer.
        QString part6 = sysxMsg.mid(1228, 36);    // copy 18 bytes of address 05 data.
        part6.prepend("0500").prepend(addressMsb).prepend(header).append(footer); //add LSB + MSB address, header and footer.
        QString part7 = sysxMsg.mid(1290, 60);    // copy 30 bytes of address 06 data.
        part7.prepend("0600").prepend(addressMsb).prepend(header).append(footer); //add LSB + MSB address, header and footer.
        QString part8 = sysxMsg.mid(1376, 250);   //  copy 125 bytes of address 07 data .
        part8.prepend("0700").prepend(addressMsb).prepend(header).append(footer); //add LSB + MSB address, header and footer.
        QString part9 = sysxMsg.mid(1652, 256);   //  copy 128 bytes of address 10 data .
        part9.prepend("1000").prepend(addressMsb).prepend(header).append(footer); //add LSB + MSB address, header and footer.
        QString part10 = sysxMsg.mid(1908,172);   //  copy 86 bytes of address 11 data .
        part10.prepend("1100").prepend(addressMsb).prepend(header).append(footer); //add LSB + MSB address, header and footer.
        QString part11 = sysxMsg.mid(2106, 70);    //  copy 35 bytes of address 20 data .
        part11.prepend("2000").prepend(addressMsb).prepend(header).append(footer); //add LSB + MSB address, header and footer.
        QString part12 = sysxMsg.mid(2202, 70);    //  copy 35 bytes of address 21 data .
        part12.prepend("2100").prepend(addressMsb).prepend(header).append(footer); //add LSB + MSB address, header and footer.
        QString part13 = sysxMsg.mid(2298, 104);   //  copy 52 bytes of address 30 data .
        part13.prepend("3000").prepend(addressMsb).prepend(header).append(footer);  //add LSB + MSB address, header and footer.
        QString part14 = sysxMsg.mid(2428, 104);   //  copy 52 bytes of address 31 data .
        part14.prepend("3100").prepend(addressMsb).prepend(header).append(footer); //add LSB + MSB address, header and footer.

        sysxMsg = "";
        sysxMsg.append(part1).append(part2).append(part3).append(part4).append(part5).append(part6).append(part7)
                .append(part8).append(part9).append(part10).append(part11).append(part12).append(part13).append(part14);

        QString reBuild = "";       /* Add correct checksum to patch strings */
        QString sysxEOF = "";
        QString hex = "";
        int msgLength = sysxMsg.length()/2;
        for(int i=0;i<msgLength*2;++i)
        {
            hex.append(sysxMsg.mid(i*2, 2));
            sysxEOF = (sysxMsg.mid((i*2)+4, 2));
            if (sysxEOF == "F7")
            {
                int dataSize = 0; bool ok;
                for(int h=checksumOffset;h<hex.size()-1;++h)
                { dataSize += hex.mid(h*2, 2).toInt(&ok, 16); };
                QString base = "80";                       // checksum calculate.
                unsigned int sum = dataSize % base.toInt(&ok, 16);
                if(sum!=0) { sum = base.toInt(&ok, 16) - sum; };
                QString checksum = QString::number(sum, 16).toUpper();
                if(checksum.length()<2) {checksum.prepend("0");};
                hex.append(checksum);
                hex.append("F7");
                reBuild.append(hex);

                hex = "";
                sysxEOF = "";
                i=i+2;
            };
        };
        sysxMsg = reBuild.simplified().toUpper().remove("0X").remove(" ");

        QList< QList<QString> > patchData = sysxIO->getFileSource().hex; // Get the loaded patch data.
        QString current_data;
        for(int i=0;i<patchData.size();++i)
        {
            QList<QString> data = patchData.at(i);
            for(int x=0;x<data.size();++x)
            {
                QString hex = data.at(x);
                if (hex.length() < 2) hex.prepend("0");
                current_data.append(hex);
            };
        };
        if(sysxMsg != current_data)
        {
            sysxIO->setFileSource("Structure", sysxMsg);		// Set the source to the data received.
            sysxIO->setDevice(true);				// Patch received from the device so this is set to true.
            sysxIO->setSyncStatus(true);			// We can't be more in sync than right now! :)
            emit updateSignal();
        };
    };
}

void floorBoardDisplay::patchChangeFailed()
{
    SysxIO *sysxIO = SysxIO::Instance();
    sysxIO->setBank(sysxIO->getLoadedBank());
    sysxIO->setPatch(sysxIO->getLoadedPatch());
    setPatchNumDisplay(sysxIO->getLoadedBank(), sysxIO->getLoadedPatch());
}

void floorBoardDisplay::resetDevice(QString sysxMsg)
{
    SysxIO *sysxIO = SysxIO::Instance();
    QObject::disconnect(sysxIO, SIGNAL(sysxReply(QString)), this, SLOT(resetDevice(QString)));

    if(sysxIO->getBank() != sysxIO->getLoadedBank() || sysxIO->getPatch() != sysxIO->getLoadedPatch())
    {
        sysxIO->setLoadedBank(sysxIO->getBank());
        sysxIO->setLoadedPatch(sysxIO->getPatch());
    };

    SLEEP(1000);
    if(set_bank < 999 && set_patch < 999) {sysxIO->requestPatchChange(set_bank, set_patch); };
    set_bank = 999;
    set_patch = 999;
    SLEEP(500);
    sysxIO->setDeviceReady(true);	// Free the device after finishing interaction.
    emit connectedSignal();		// Emit this signal to tell we are still connected and to update the patch names in case they have changed.
    sysxIO->setDeviceReady(true);	// Free the device after finishing interaction.
 }

void floorBoardDisplay::patchSelectSignal(int bank, int patch)
{
    SysxIO *sysxIO = SysxIO::Instance();
    if(blinkCount == 0)
    {
        currentSyncStatus = sysxIO->getSyncStatus();
        sysxIO->setSyncStatus(false);
        writeButton->setBlink(false);
    };

    //if( sysxIO->getLoadedBank() != bank ||  sysxIO->getLoadedPatch() != patch)
    //{
    sysxIO->setBank(bank);
    sysxIO->setPatch(patch);

    if(blinkCount == 0)
    {
        QObject::connect(timer, SIGNAL(timeout()), this, SLOT(blinkSellectedPatch()));
        timer->start(sellectionBlinkInterval);
    }
    else
    {
        blinkCount = 0;
    };
    //}
    //else
    //{
    //	blinkSellectedPatch(false);
    //};
}

void floorBoardDisplay::blinkSellectedPatch(bool active)
{
    SysxIO *sysxIO = SysxIO::Instance();
    int bank = sysxIO->getBank();
    int patch = sysxIO->getPatch();

    if(active && blinkCount <= (sellectionBlinks * 2) - 1)
    {
        if(blinkCount % 2 == 0)
        {
            this->patchNumDisplay->clearAll();
        }
        else
        {
            setPatchNumDisplay(bank, patch);
        };
        blinkCount++;
    }
    else
    {
        QObject::disconnect(timer, SIGNAL(timeout()), this, SLOT(blinkSellectedPatch()));
        timer->stop();
        blinkCount = 0;
        //sysxIO->setBank(sysxIO->getLoadedBank());
        //sysxIO->setPatch(sysxIO->getLoadedPatch());
        sysxIO->setSyncStatus(currentSyncStatus);
        if(currentSyncStatus || sysxIO->getLoadedBank() == 0)
        {
            writeButton->setBlink(false);
        };
        setPatchNumDisplay(bank,patch);//(sysxIO->getLoadedBank(),  sysxIO->getLoadedPatch());
    };
    emit setStatusSymbol(1);
    emit setStatusMessage(tr("Ready"));
}

void floorBoardDisplay::patchLoadSignal(int bank, int patch)
{
    blinkSellectedPatch(false);

    SysxIO *sysxIO = SysxIO::Instance();
    sysxIO->setBank(bank);
    sysxIO->setPatch(patch);
}

void floorBoardDisplay::notConnected()
{
    this->connectButton->setBlink(false);
    this->connectButton->setValue(false);
    this->writeButton->setBlink(false);
    this->autosyncTimer->stop();
    this->autoButton->setBlink(false);
    this->autoButton->setValue(false);
    this->writeButton->setValue(false);

    SysxIO *sysxIO = SysxIO::Instance();
    sysxIO->setConnected(false);
    sysxIO->setSyncStatus(false);
    sysxIO->setDeviceReady(true);	// Free the device after finishing interaction.

    emit setStatusSymbol(0);
    emit setStatusProgress(0);
    emit setStatusMessage(tr("Not connected"));
}

void floorBoardDisplay::valueChanged(bool value, QString hex1, QString hex2, QString hex3)
{

}


