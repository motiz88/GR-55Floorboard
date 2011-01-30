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

#include <QtGui>
#include <QFile>
#include "summaryDialog.h"
#include "Preferences.h"
#include "SysxIO.h"
#include "MidiTable.h"
#include "globalVariables.h"

summaryDialog::summaryDialog(QWidget *parent)
                  : QWidget(parent)
{
  this->mode = "Compact";
  this->filter = "off";
  this->textDialog = new QTextEdit(parent);
  textDialog->setReadOnly(true);
  //textDialog->setWordWrapMode(QTextOption::NoWrap);
  textDialog->setDocumentTitle("GR-55 Patch settings");
  textDialog->setMinimumHeight(600);

  SysxIO *sysxIO = SysxIO::Instance();
  QString sysxMsg;
        QList< QList<QString> > patchData = sysxIO->getFileSource().hex; // Get the loaded patch data.
        for(int i=0;i<patchData.size();++i)
        {
                QList<QString> data = patchData.at(i);
                for(int x=0;x<data.size();++x)
                {
                        QString hex;
                        hex = data.at(x);
                        if (hex.length() < 2) hex.prepend("0");
                        sysxMsg.append(hex);
                        if(hex == "F7"){ sysxMsg.append("<br>"); };
                };
        };
  /******************************************************
  ******QString "sysxMsg" contains current patch data *****
  ******************************************************/
  MidiTable *midiTable = MidiTable::Instance();
  QDateTime dateTime = QDateTime::currentDateTime();
  text = dateTime.toString();
  text.append("<br>");   
   small_text = text;
   small_text.append("<b><u>ROLAND GR-55 Compact Patch Summary</u></b><br>");
   small_text.append("a listing of active only effects.<br>");
   large_text = text;
   large_text.append("<b><u>ROLAND GR-55 Complete Patch Summary</u></b><br>");
   large_text.append("a list of all parameters with-in this patch.<br>");
  

  QString patchName = sysxIO->getCurrentPatchName();
  text = "<br><b><u>Patch name = </u>" + patchName + "</b>";

  text.append("<br><br><b>Patch Mode Output Select = </b>");
  int value = sysxIO->getSourceValue("Structure", "00", "00", "11");
  QString valueHex = QString::number(value, 16).toUpper();
  if(valueHex.length() < 2) {valueHex.prepend("0"); };
  text.append(midiTable->getValue("Structure", "00", "00", "11", valueHex) );



  QList<QString> fxChain = sysxIO->getFileSource("Structure", "0B", "00");

  QString chainText = "<br><br><b><u>**********Signal Chain**********</u></b><br>Input = -> ";
  QString chainData;
  QString chain;
  for(int i= sysxDataOffset;i< (sysxDataOffset + 18);i++ )
  {
     chainData.append(fxChain.at(i));
     chain.append(" [");
     chain.append( midiTable->getMidiMap("Structure", "0B", "00", "00", fxChain.at(i)).name );
     chain.append("]");
  };
  QString part;
  for(int x=0;x<chainData.size();x++)
  {
    part.append(chainData.at(x));
    ++x;
  };
  int i = part.indexOf("4")+sysxDataOffset;
  QString g = ( midiTable->getMidiMap("Structure", "0B", "00", "00", fxChain.at(i)).name );
  chain.replace("["+g, "<br>Channel B = ["+g);
  chain.replace("CH_B", "PreAmp B");
  chain.replace("[analogPU]", "[A/B Split]<br>Channel A = ");
  chain.replace("[modeling]", "<br>Output = [A/B Merge]");
  chain.replace("CH_A", "PreAmp A");
  chain.replace("LP", "Send/Return");
  chain.replace("CS", "Comp");
  chain.replace("PDL", "PDL/WAH");
  chain.replace("OD", "Dist/ODrive");
  chain.replace("ns", "N.Supp 1");
  chain.replace("NS_2", "N.Supp 2");
  chain.replace("FV", "Foot Vol");
  chain.replace("DD", "Delay");
  chain.replace("RV", "Reverb");
  chain.replace("CE", "Chorus");
  chain.replace("DGT", "DGT/USB");
  
  text.append(chainText);
  text.append(chain + " ->");
  small_text.append(text);
  large_text.append(text);
  
  this->effect = "off";
  text = "<br><br><b><u>**********PreAmp/Channel Control***********</b></u>";
  text2 = text;
  address= "01";
  start = 0;
  finish = 5;
  makeList();

  text.append("<br><br><b><u>**********Pre Amp A***********</b></u>");
  text2.append("<br><br><b><u>**********Pre Amp A***********</b></u>");
  address= "01";
  start = 16;
  finish = 45;
  makeList();

  text.append("<br><br><b><u>**********Pre Amp B***********</b></u>");
  text2.append("<br><br><b><u>**********Pre Amp B***********</b></u>");
  address= "01";
  start = 48;
  finish = 77;
  makeList();
  
  large_text.append(text2);
  if(effect == "on") { small_text.append(text); };

  this->effect = "off";
  text = "<br><br><b><u>**********Compressor***********</b></u>";
  address= "00";
  start = 64;
  finish = 72;
  makeList();
  large_text.append(text);
  if(effect == "on") { small_text.append(text); };
 
  this->effect = "off";
  text = "<br><br><b><u>**********Distortion***********</b></u>";
  address= "00";
  start = 112;
  finish = 126;
  makeList();
  large_text.append(text);
  if(effect == "on") { small_text.append(text); };
 
  this->effect = "off";
  text = "<br><br><b><u>**********Equalizer***********</b></u>";
  address= "01";
  start = 112;
  finish = 124;
  makeList();
  large_text.append(text);
  if(effect == "on") { small_text.append(text); };
 
  this->effect = "off";
  text = "<br><br><b><u>**********Delay***********</b></u>";
  address= "0A";
  start = 0;
  finish = 25;
  makeList();
  large_text.append(text);
  if(effect == "on") { small_text.append(text); };
 
  this->effect = "off";
  text = "<br><br><b><u>**********Chorus***********</b></u>";
  address= "0A";
  start = 32;
  finish = 40;
  makeList();
  large_text.append(text);
  if(effect == "on") { small_text.append(text); };
 
  this->effect = "off";
  text = "<br><br><b><u>**********Reverb***********</b></u>";
  address= "0A";
  start = 48;
  finish = 60;
  makeList();
  large_text.append(text);
  if(effect == "on") { small_text.append(text); };
 
  this->effect = "off";
  text = "<br><br><b><u>**********Pedal FX***********</b></u>";
  address= "0A";
  start = 64;
  finish = 94;
  makeList();
  large_text.append(text);
  if(effect == "on") { small_text.append(text); };
 
  this->effect = "off";
  text = "<br><br><b><u>**********Misc Settings***********</b></u>";
  address= "0C";
  start = 32;
  finish = 35;
  makeList();
  large_text.append(text);
  if(effect == "on") { small_text.append(text); };
 
  this->effect = "on";
  text = "<br><br><b><u>**********Master***********</b></u>";
  address= "0A";
  start = 96;
  finish = 106;
  makeList();
  large_text.append(text);
  if(effect == "on") { small_text.append(text); };
 
  this->effect = "off";
  text = "<br><br><b><u>**********Noise Suppressor 1***********</b></u>";
  address= "0A";
  start = 113;
  finish = 117;
  makeList();
  large_text.append(text);
  if(effect == "on") { small_text.append(text); };
 
  this->effect = "off";
  text = "<br><br><b><u>**********Noise Suppressor 2***********</b></u>";
  address= "0A";
  start = 117;
  finish = 121;
  makeList();
  large_text.append(text);
  if(effect == "on") { small_text.append(text); };
 
  this->effect = "off";
  text = "<br><br><b><u>**********Send/Return***********</b></u>";
  address= "0A";
  start = 121;
  finish = 125;
  makeList();
  large_text.append(text);
  if(effect == "on") { small_text.append(text); };
 
  this->effect = "off";
  text = "<br><br><b><u>**********FX-1***********</b></u>";
  text2 = text;
  address= "02";
  start = 0;
  finish = 110;
  makeList();
  address= "03";
  start = 6;
  finish = 92;
  makeList();
  address= "05";
  start = 29;
  finish = 65;
  makeList();
  large_text.append(text2);
  if(effect == "on") { small_text.append(text); };
  this->filter = "off";
 
  this->effect = "off";
  text = "<br><br><b><u>**********FX-2***********</b></u>";
  text2 = text;
  address= "06";
  start = 0;
  finish = 110;
  makeList();
  address= "07";
  start = 6;
  finish = 92;
  makeList();
  address= "09";
  start = 29;
  finish = 65;
  makeList();
  large_text.append(text2);
  if(effect == "on") { small_text.append(text); };
  this->filter = "off";
 
  this->effect = "off";
  text = "<br><br><b><u>**********Assign 1***********</b></u>";
  address= "0B";
  start = 32;
  finish = 48;
  makeList();
  large_text.append(text);
  if(effect == "on") { small_text.append(text); };
 
  this->effect = "off";
  text = "<br><br><b><u>**********Assign 2***********</b></u>";
  address= "0B";
  start = 48;
  finish = 64;
  makeList();
  large_text.append(text);
  if(effect == "on") { small_text.append(text); };
 
  this->effect = "off";
  text = "<br><br><b><u>**********Assign 3***********</b></u>";
  address= "0B";
  start = 64;
  finish = 80;
  makeList();
  large_text.append(text);
  if(effect == "on") { small_text.append(text); };
 
  this->effect = "off";
  text = "<br><br><b><u>**********Assign 4***********</b></u>";
  address= "0B";
  start = 80;
  finish = 96;
  makeList();
  large_text.append(text);
  if(effect == "on") { small_text.append(text); };
 
  this->effect = "off";
  text = "<br><br><b><u>**********Assign 5***********</b></u>";
  address= "0B";
  start = 96;
  finish = 112;
  makeList();
  large_text.append(text);
  if(effect == "on") { small_text.append(text); };
 
  this->effect = "off";
  text = "<br><br><b><u>**********Assign 6***********</b></u>";
  address= "0B";
  start = 112;
  finish = 128;
  makeList();
  large_text.append(text);
  if(effect == "on") { small_text.append(text); };
 
  this->effect = "off";
  text = "<br><br><b><u>**********Assign 7***********</b></u>";
  address= "0C";
  start = 0;
  finish = 16;
  makeList();
  large_text.append(text);
  if(effect == "on") { small_text.append(text); };

  this->effect = "off";
  text = "<br><br><b><u>**********Assign 8***********</b></u>";
  address= "0C";
  start = 16;
  finish = 32;
  makeList();
  large_text.append(text);
  if(effect == "on") { small_text.append(text); };
 
  this->effect = "off";
  text = "<br><br><b><u>**********FX-1 Harmonist User***********</b></u>";
  address= "02";
  start = 110;
  finish = 128;
  makeList();
  address= "03";
  start = 0;
  finish = 6;
  makeList();
  large_text.append(text);
  if(effect == "on") { small_text.append(text); };
 
  this->effect = "off";
  text = "<br><br><b><u>**********FX-2 Harmonist User***********</b></u>";
  address= "06";
  start = 110;
  finish = 128;
  makeList();
  address= "07";
  start = 0;
  finish = 6;
  makeList();
  large_text.append(text);
  if(effect == "on") { small_text.append(text); };
 
  this->effect = "off";
  text = "<br><br><b><u>**********FX-1 AutoRiff User Scales***********</b></u>";
  address= "03";
  start = 92;
  finish = 128;
  makeList();
  address= "04";
  start = 0;
  finish = 128;
  makeList();
  address= "05";
  start = 0;
  finish = 28;
  makeList();
  large_text.append(text);
  if(effect == "on") { small_text.append(text); };

  this->effect = "off";
  text = "<br><br><b><u>**********FX-2 AutoRiff User Scales***********</b></u>";
  address= "07";
  start = 92;
  finish = 128;
  makeList();
  address= "08";
  start = 0;
  finish = 128;
  makeList();
  address= "09";
  start = 0;
  finish = 28;
  makeList();
  large_text.append(text);
  if(effect == "on") { small_text.append(text); };
   
  text = "<br><br><b><u>**********Patch Data***********</b></u><br>";
  text.append(sysxMsg);
  large_text.append(text);

  textDialog->setText(small_text);
  textDialog->show();


  QPushButton *cancelButton = new QPushButton(tr("Close"));
  connect(cancelButton, SIGNAL(clicked()), this, SLOT(cancel()));
  cancelButton->setWhatsThis(tr("Will close the currently open Dialog page."));

  QPushButton *printButton = new QPushButton(tr("Print"));
  connect(printButton, SIGNAL(clicked()), this, SLOT(printFile()));
  printButton->setWhatsThis(tr("Will Print the current Dialog to the prefered printer<br>printed text will be simular to the screen layout."));

  QPushButton *printPreviewButton = new QPushButton(tr("Print Preview"));
  connect(printPreviewButton, SIGNAL(clicked()), this, SLOT(printPreview()));
  printPreviewButton->setWhatsThis(tr("Will Print the current Dialog to the prefered printer<br>printed text will be simular to the screen layout."));

  QPushButton *saveAsButton = new QPushButton(tr("Save As"));
  connect(saveAsButton, SIGNAL(clicked()), this, SLOT(saveAs()));
  saveAsButton->setWhatsThis(tr("Will save the current dialog page to file in a *.txt format."));
  
  QPushButton *viewButton = new QPushButton(tr("Change View"));
  connect(viewButton, SIGNAL(clicked()), this, SLOT(view()));
  viewButton->setWhatsThis(tr("Will Expand the summary dialog to include all patch parameters."));
  
        QHBoxLayout *horizontalLayout = new QHBoxLayout;
        horizontalLayout->addWidget(textDialog);

        QHBoxLayout *buttonsLayout = new QHBoxLayout;
        buttonsLayout->addStretch(1);
        //buttonsLayout->addWidget(printPreviewButton);
        //buttonsLayout->addSpacing(12);
        buttonsLayout->addWidget(printButton);
        buttonsLayout->addSpacing(12);
        buttonsLayout->addWidget(saveAsButton);
        buttonsLayout->addSpacing(12);
        buttonsLayout->addWidget(viewButton);
        buttonsLayout->addSpacing(12);
        buttonsLayout->addWidget(cancelButton);

        QVBoxLayout *mainLayout = new QVBoxLayout;
        mainLayout->addLayout(horizontalLayout);
        mainLayout->addStretch(1);
        mainLayout->addSpacing(12);
        mainLayout->addLayout(buttonsLayout);
        setLayout(mainLayout);

        setWindowTitle(tr("GR-55 Patch Summary of ")+ patchName);
};

void summaryDialog::makeList()
{
    // construct a text string using address and locator parameters to read from midi.xml
    SysxIO *sysxIO = SysxIO::Instance();
    MidiTable *midiTable = MidiTable::Instance();
    for(int i=start;i<finish;i++ )  //start and finish range defined above.
      {
        QString temp;
        QString pos = QString::number(i, 16).toUpper();
        if(pos.size()<2){ pos.prepend("0"); };
        QString txt = midiTable->getMidiMap("Structure", address, "00", pos).customdesc;  //trawl through midi.xml 
        if(!txt.isEmpty() && txt != "") // skip the empty midi.xml .desc section and move to the next.
        {
        QString pretxt =  midiTable->getMidiMap("Structure", address, "00", pos).desc;
        int value = sysxIO->getSourceValue("Structure", address, "00", pos);
        QString valueHex = QString::number(value, 16).toUpper();
        if(valueHex.length() < 2) {valueHex.prepend("0"); };
         temp.append("<br>");
         temp.append("[");
         if(!pretxt.isEmpty() && txt != "") { temp.append(pretxt + " "); };
         temp.append(txt);
         temp.append("] = ");
         QString x = midiTable->getValue("Structure", address, "00", pos, valueHex);
         {temp.append(x); };
         text2.append(temp);        
         
          if (this->filter != "off") 
          {
            if (pretxt == this->filter) { text.append(temp); };
          } else if(!pretxt.contains("Custom:")){text.append(temp); };
          if(i == start && x == "On") { this->effect = "on"; }; // first byte is usually the effect on/off switch
         if((pretxt == "MOD:" || pretxt == "MFX:") && (txt == "Type"))
          {this->filter = midiTable->getMidiMap("Structure", address, "00", pos, valueHex).desc;};
        };
      };
};

summaryDialog::~summaryDialog()
{};

void summaryDialog::view()
{
  if (mode == "Compact")
  {
    textDialog->setText(large_text);
    this->mode = "Expanded";
  } 
  else 
  {
    textDialog->setText(small_text);
    this->mode = "Compact";
  };
};

 void summaryDialog::cancel()
{
  this->close();
};

 void summaryDialog::printFile()
 {
   #ifndef QT_NO_PRINTER

     QPrinter printer;
     QPrintDialog *dialog = new QPrintDialog(&printer, this);
     //QPrintPreviewDialog *dialog = new QPrintPreviewDialog(&printer, this);
     dialog->setWindowTitle(tr("Print Document"));
     if (dialog->exec() != QDialog::Accepted) { return; }
     else { textDialog->print(&printer); };
 #endif
 };
 
  void summaryDialog::printPreview()
 {
   #ifndef QT_NO_PRINTER

     QPrinter printer;
     //QPrintDialog *dialog = new QPrintDialog(&printer, this);
     QPrintPreviewDialog *dialog = new QPrintPreviewDialog(&printer, this);
     dialog->setWindowTitle(tr("Print Preview"));
     if (dialog->exec() != QDialog::Accepted) { return; }
     else { textDialog->print(&printer); };
 #endif
 };

 void summaryDialog::saveAs()
 {

         Preferences *preferences = Preferences::Instance();
         QString dir = preferences->getPreferences("General", "Files", "dir");

         QString fileName = QFileDialog::getSaveFileName(
                     this,
                     tr("Save As"),
                     dir,
                     tr("Text Document (*.txt)"));
         if (!fileName.isEmpty())
         {
                 if(!fileName.contains(".txt"))
                 {
                   fileName.append(".txt");
                 };
                 QFile file(fileName);

                 QByteArray out;
                 text.remove("<b>");
                 text.remove("</b>");
                 text.remove("<u>");
                 text.remove("</u>");
                 QString newLine;
                 newLine.append((char)13);
                 newLine.append((char)10);
                 text.replace("<br>", newLine);

                 unsigned int size = text.size();

                         for (unsigned int x=0; x<size; x++)
                         {
                           QString str(text.at(x));
                           out.append(str);
                         };

             if (file.open(QIODevice::WriteOnly))
                 {
                   file.write(out);
                 };

         };
 };
