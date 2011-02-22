#############################################################################
##
## Copyright (C) 2007~2011 Colin Willcocks.
## Copyright (C) 2005~2007 Uco Mesdag. 
## All rights reserved.
##
## This file is part of "GR-55 FloorBoard".
##
## This program is free software; you can redistribute it and/or modify
## it under the terms of the GNU General Public License as published by
## the Free Software Foundation; either version 2 of the License, or
## (at your option) any later version.
##
## This program is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU General Public License for more details.
##
## You should have received a copy of the GNU General Public License along
## with this program; if not, write to the Free Software Foundation, Inc.,
## 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
##
#############################################################################
 
#Header files
HEADERS += ./editPage.h \
    ./editWindow.h \
    ./globalVariables.h \
    ./mainWindow.h \
    ./bankTreeList.h \
    ./bulkEditDialog.h \
    ./bulkLoadDialog.h \
    ./bulkSaveDialog.h \
    ./customButton.h \
    ./customComboBox.h \
    ./customControlParaEQ.h \
    ./customControlGraphicEQ.h \
    ./customControlKnob.h \
    ./customControlDataKnob.h \
    ./customControlRange.h \
    ./customControlLabel.h \
    ./customControlMasterEQ.h \
    ./customControlListMenu.h \
    ./customControlSwitch.h \
    ./customControlTarget.h \
    ./customDial.h \
    ./customDisplay.h \
    ./customParaEQGraph.h \
    ./customGraphicEQGraph.h \
    ./customKnob.h \
    ./customDataKnob.h \
    ./customKnobTarget.h \
    ./customKnobRange.h \
    ./customLabelDisplay.h \
    ./customLed.h \
    ./customMasterEQGraph.h \
    ./customPanelButton.h \
    ./customRangeDial.h \
    ./customRenameDialog.h \
    ./customRenameWidget.h \
    ./customSlider.h \
    ./customSplashScreen.h \
    ./customSwitch.h \ 
    ./customSwitch3way.h \ 
    ./customTargetDial.h \
    ./customTargetListMenu.h \
    ./dragBar.h \
    ./fileDialog.h \
    ./floorBoard.h \
    ./floorBoardDisplay.h \
    ./floorPanelBar.h \
    ./floorPanelBarButton.h \
    ./initPatchListMenu.h \
    ./menuPage.h \
    ./menuPage_assign1.h \
    ./menuPage_assign2.h \
    ./menuPage_assign3.h \
    ./menuPage_assign4.h \
    ./menuPage_assign5.h \
    ./menuPage_assign6.h \
    ./menuPage_assign7.h \
    ./menuPage_assign8.h \
    ./menuPage_master.h \
    ./menuPage_pdl.h \
    ./menuPage_system.h \
    ./renameDialog.h \
    ./renameWidget.h \
    ./statusBarSymbol.h \
    ./statusBarWidget.h \
    ./soundSource.h \
    ./soundSource_analogPU.h \
    ./soundSource_modeling.h \
    ./soundSource_synth_a.h \
    ./soundSource_synth_b.h \
    ./stompBox.h \
    ./stompbox_amp.h \
    ./stompbox_ce.h \
    ./stompbox_dd.h \
    ./stompbox_eq.h \
    ./stompbox_mod.h \
    ./stompbox_mfx.h \
    ./stompbox_ns.h \   
    ./stompbox_rv.h \
    ./midiIO.h \
    ./MidiTable.h \
    ./MidiTableDestroyer.h \
    ./RtError.h \
    ./RtMidi.h \
    ./summaryDialog.h \
    ./summaryDialogPatchList.h \
    ./summaryDialogSystem.h \
    ./SysxIO.h \
    ./SysxIODestroyer.h \
    ./sysxWriter.h \
    ./Preferences.h \
    ./PreferencesDestroyer.h \
    ./preferencesDialog.h \
    ./preferencesPages.h \
    ./xmlwriter/xmlwriter.h \
    ./xmlwriter/xmlwriter_p.h 

#Source files
SOURCES += ./editPage.cpp \
    ./editWindow.cpp \
    ./main.cpp \
    ./mainWindow.cpp \
    ./bankTreeList.cpp \
    ./bulkEditDialog.cpp \
    ./bulkLoadDialog.cpp \
    ./bulkSaveDialog.cpp \
    ./customButton.cpp \
    ./customComboBox.cpp \
    ./customControlParaEQ.cpp \
    ./customControlGraphicEQ.cpp \
    ./customControlKnob.cpp \
    ./customControlDataKnob.cpp \
    ./customControlLabel.cpp \
    ./customControlListMenu.cpp \
    ./customControlMasterEQ.cpp \
    ./customControlRange.cpp \
    ./customControlSwitch.cpp \
    ./customControlTarget.cpp \
    ./customDial.cpp \
    ./customDisplay.cpp \
    ./customParaEQGraph.cpp \
    ./customGraphicEQGraph.cpp \
    ./customKnob.cpp \
    ./customDataKnob.cpp \
    ./customKnobTarget.cpp \
    ./customKnobRange.cpp \
    ./customLabelDisplay.cpp \
    ./customLed.cpp \
    ./customMasterEQGraph.cpp \
    ./customPanelButton.cpp \
    ./customRangeDial.cpp \
    ./customRenameDialog.cpp \
    ./customRenameWidget.cpp \
    ./customSlider.cpp \
    ./customSplashScreen.cpp \
    ./customSwitch.cpp \
     ./customSwitch3way.cpp \
    ./customTargetDial.cpp \
    ./customTargetListMenu.cpp \
    ./dragBar.cpp \
    ./fileDialog.cpp \
    ./floorBoard.cpp \
    ./floorBoardDisplay.cpp \
    ./floorPanelBar.cpp \
    ./floorPanelBarButton.cpp \
    ./initPatchListMenu.cpp \
    ./menuPage.cpp \
    ./menuPage_assign1.cpp \
    ./menuPage_assign2.cpp \
    ./menuPage_assign3.cpp \
    ./menuPage_assign4.cpp \
    ./menuPage_assign5.cpp \
    ./menuPage_assign6.cpp \
    ./menuPage_assign7.cpp \
    ./menuPage_assign8.cpp \
    ./menuPage_master.cpp \
    ./menuPage_pdl.cpp \
    ./menuPage_system.cpp \
    ./renameDialog.cpp \
    ./renameWidget.cpp \
    ./statusBarSymbol.cpp \
    ./statusBarWidget.cpp \
    ./soundSource.cpp \
    ./soundSource_analogPU.cpp \
    ./soundSource_modeling.cpp \
    ./soundSource_synth_a.cpp \
    ./soundSource_synth_b.cpp \
    ./stompBox.cpp \
    ./stompbox_amp.cpp \
    ./stompbox_ce.cpp \
    ./stompbox_dd.cpp \
    ./stompbox_eq.cpp \
    ./stompbox_mod.cpp \
    ./stompbox_mfx.cpp \
    ./stompbox_ns.cpp \
    ./stompbox_rv.cpp \ 
    ./summaryDialog.cpp \
    ./summaryDialogPatchList.cpp \
    ./summaryDialogSystem.cpp \
    ./midiIO.cpp \
    ./MidiTable.cpp \
    ./MidiTableDestroyer.cpp \
    ./Preferences.cpp \
    ./PreferencesDestroyer.cpp \
    ./preferencesDialog.cpp \
    ./preferencesPages.cpp \
    ./SysxIO.cpp \
    ./SysxIODestroyer.cpp \
    ./sysxWriter.cpp \
    ./xmlwriter/xmlwriter.cpp    
    
#Resource file(s)
RESOURCES += GR-55FloorBoard.qrc
