/****************************************************************************
**
** Copyright (C) 2007~2016 Colin Willcocks.
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

#include <QtWidgets>
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
    text = "<br><b>Patch name = " + patchName + "</b>";

    text.append("<br><br><b>Patch Mode = </b>");
    int value = sysxIO->getSourceValue("Structure", "00", "00", "00");
    QString valueHex = QString::number(value, 16).toUpper();
    if(valueHex.length() < 2) {valueHex.prepend("0"); };
    text.append(midiTable->getValue("Structure", "00", "00", "00", valueHex) );

    int mode_value = sysxIO->getSourceValue("Structure", "02", "00", "2C");
    if(mode_value == 0) {text.append("<br><br><b>Structure Type = </b>[1]"); }
    else {text.append("<br><br><b><u>Structure Type = [2]</b></u>"); };

    small_text.append(text);
    large_text.append(text);

    text = "<br><br><b><u>Pre Amp***********</b></u>";
    address= "07";
    start = 0;
    finish = 17;
    makeList();
    large_text.append(text);
    if(effect == "on") { small_text.append(text); };

    this->effect = "off";
    text = "<br><br><b><u>Noise Suppressor***********</b></u>";
    address= "07";
    start = 90;
    finish = 93;
    makeList();
    large_text.append(text);
    if(effect == "on") { small_text.append(text); };

    this->effect = "off";
    text = "<br><br><b><u>Chorus***********</b></u>";
    address= "06";
    start = 0;
    finish = 5;
    makeList();
    large_text.append(text);
    if(effect == "on") { small_text.append(text); };

    this->effect = "off";
    text = "<br><br><b><u>Delay***********</b></u>";
    address= "06";
    start = 5;
    finish = 12;
    makeList();
    large_text.append(text);
    if(effect == "on") { small_text.append(text); };

    this->effect = "off";
    text = "<br><br><b><u>Reverb***********</b></u>";
    address= "06";
    start = 12;
    finish = 17;
    makeList();
    large_text.append(text);
    if(effect == "on") { small_text.append(text); };

    this->effect = "off";
    text = "<br><br><b><u>Equalizer***********</b></u>";
    address= "06";
    start = 17;
    finish = 30;
    makeList();
    large_text.append(text);
    if(effect == "on") { small_text.append(text); };

    this->effect = "off";
    text = "<br><br><b><u>PCM Synth A***********</b></u>";
    address= "20";
    start = 1;
    finish =23;
    makeList();
    address= "30";
    start = 0;
    finish =40;
    makeList();
    large_text.append(text);
    if(effect == "off") { small_text.append(text); };

    this->effect = "off";
    text = "<br><br><b><u>PCM Synth B***********</b></u>";
    address= "21";
    start = 1;
    finish =23;
    makeList();
    address= "31";
    start = 0;
    finish =40;
    makeList();
    large_text.append(text);
    if(effect == "off") { small_text.append(text); };

    this->effect = "off";
    mode_value = sysxIO->getSourceValue("Structure", "00", "00", "00");
    if(mode_value != 0) {
        text = "<br><br><b><u>Bass Mode Modeling***********</b></u>";
        address= "10";
        start = 9;
        finish = 46;
        makeList();
        address = "10";
        start = 5;
        finish = 9;
        makeList();
        address = "11";
        start = 16;
        finish = 74;
        makeList();
    } else {
        text = "<br><br><b><u>Guitar Mode Modeling***********</b></u>";
        address= "10";
        start = 9;
        finish = 46;
        makeList();
        address = "10";
        start = 0;
        finish = 5;
        makeList();
        address = "10";
        start = 46;
        finish = 115;
        makeList();  };

    large_text.append(text);
    if(effect == "on") { small_text.append(text); };

    this->effect = "off";
    text = "<br><br><b><u>MOD***********</b></u>";
    text2 = text;
    address= "07";
    start = 21;
    finish = 90;
    makeList();
    address= "07";
    start = 17;
    finish = 20;
    makeList();
    large_text.append(text2);
    if(effect == "on") { small_text.append(text); };
    this->filter = "off";

    this->effect = "off";
    text = "<br><br><b><u>MFX***********</b></u>";
    text2 = text;
    address= "03";
    start = 4;
    finish = 128;
    makeList();
    address= "04";
    start = 0;
    finish = 114;
    makeList();
    address= "03";
    start = 0;
    finish = 3;
    makeList();
    large_text.append(text2);
    if(effect == "on") { small_text.append(text); };
    this->filter = "off";

    this->effect = "on";
    text = "<br><br><b><u>Master***********</b></u>";
    address= "02";
    start = 36;
    finish = 72;
    makeList();
    large_text.append(text);
    small_text.append(text);

    this->effect = "off";
    text = "<br><br><b><u>Pedal/GK***********</b></u>";
    address= "00";
    start = 17;
    finish = 128;
    makeList();
    address= "01";
    start = 0;
    finish = 12;
    makeList();
    large_text.append(text);
    //small_text.append(text);

    this->effect = "off";
    text = "<br><br><b><u>Assign 1***********</b></u>";
    address= "01";
    start = 12;
    finish = 31;
    makeList();
    large_text.append(text);
    if(effect == "on") { small_text.append(text); };

    this->effect = "off";
    text = "<br><br><b><u>Assign 2***********</b></u>";
    address= "01";
    start = 31;
    finish = 50;
    makeList();
    large_text.append(text);
    if(effect == "on") { small_text.append(text); };

    this->effect = "off";
    text = "<br><br><b><u>Assign 3***********</b></u>";
    address= "01";
    start = 50;
    finish = 69;
    makeList();
    large_text.append(text);
    if(effect == "on") { small_text.append(text); };

    this->effect = "off";
    text = "<br><br><b><u>Assign 4***********</b></u>";
    address= "01";
    start = 69;
    finish = 88;
    makeList();
    large_text.append(text);
    if(effect == "on") { small_text.append(text); };

    this->effect = "off";
    text = "<br><br><b><u>Assign 5***********</b></u>";
    address= "01";
    start = 88;
    finish = 107;
    makeList();
    large_text.append(text);
    if(effect == "on") { small_text.append(text); };

    this->effect = "off";
    text = "<br><br><b><u>Assign 6***********</b></u>";
    address= "01";
    start = 107;
    finish = 126;
    makeList();
    large_text.append(text);
    if(effect == "on") { small_text.append(text); };

    this->effect = "off";
    text = "<br><br><b><u>Assign 7***********</b></u>";
    address= "01";
    start = 126;
    finish = 128;
    makeList();
    address= "02";
    start = 2;
    finish = 17;
    makeList();
    large_text.append(text);
    if(effect == "on") { small_text.append(text); };

    this->effect = "off";
    text = "<br><br><b><u>Assign 8***********</b></u>";
    address= "02";
    start = 17;
    finish = 36;
    makeList();
    large_text.append(text);
    if(effect == "on") { small_text.append(text); };



    text = "<br><br><b><u>Patch Data***********</b></u><br>";
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

    viewButton = new QPushButton(tr("More Details"));
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
}

void summaryDialog::makeList()
{
    // construct a text string using address and locator parameters to read from midi.xml
    SysxIO *sysxIO = SysxIO::Instance();
    MidiTable *midiTable = MidiTable::Instance();
    bool ok;
    for(int i=start;i<finish;i++ )  //start and finish range defined above.
    {
        QString temp;
        QString pos2;
        QString pos3;
        QString address2 = address;
        int pos_int = i;

        QString pos = QString::number(pos_int, 16).toUpper();
        if(pos.size()<2){ pos.prepend("0"); };
        QString txt = midiTable->getMidiMap("Structure", address, "00", pos).customdesc;  //trawl through midi.xml

        pos_int = i+1; if(pos_int > 127){pos_int=pos_int-128; address2 = QString::number(address.toInt(&ok, 16)+1).toUpper(); };
        if (address2.size()<2){address2.prepend("0"); };
        pos2 = QString::number(pos_int, 16).toUpper();
        if(pos2.size()<2){ pos2.prepend("0"); };

        pos_int = i+2; if(pos_int > 127){pos_int=pos_int-128; address2 = QString::number(address.toInt(&ok, 16)+1).toUpper(); };
        if (address2.size()<2){address2.prepend("0"); };
        pos3 = QString::number(pos_int, 16).toUpper();
        if(pos3.size()<2){ pos3.prepend("0"); };

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
            QString x;
            if(pretxt.contains("Assign") && (txt.contains("Target")) )
            {
                value = sysxIO->getSourceValue("Structure", address, "00", pos);
                valueHex = QString::number(value, 16).toUpper();
                value = sysxIO->getSourceValue("Structure", address2, "00", pos2);
                QString valueHex2 = QString::number(value, 16).toUpper();
                value = sysxIO->getSourceValue("Structure", address2, "00", pos3);
                QString valueHex3 = QString::number(value, 16).toUpper();
                valueHex.append(valueHex2).append(valueHex3);
                int maxRange = 256;
                value = valueHex.toInt(&ok, 16);
                int dif = value/maxRange;
                QString valueHex1 = QString::number(dif, 16).toUpper();
                if(valueHex1.length() < 2) valueHex1.prepend("0");
                valueHex2 = QString::number(value - (dif * maxRange), 16).toUpper();
                if(valueHex2.length() < 2) valueHex2.prepend("0");
                QString hex4 = valueHex1;
                QString hex5 = valueHex2;
                QString mode_hex = "00";
                int mode_value = sysxIO->getSourceValue("Structure", "00", "00", "00");     //check for guitar mode
                if(mode_value != 0) {mode_hex = "0D"; };
                Midi items = midiTable->getMidiMap("Tables", "00", "00", mode_hex, hex4, hex5);
                assign_desc = items.desc;
                assign_customdesc = items.customdesc;
                temp.append( items.name);
            }
            else if(pretxt.contains("Assign") && ((txt.contains("Min") || txt.contains("Max"))))
            {
                value = sysxIO->getSourceValue("Structure", address, "00", pos);
                valueHex = QString::number(value, 16).toUpper();
                value = sysxIO->getSourceValue("Structure", address, "00", pos2);
                QString valueHex2 = QString::number(value, 16).toUpper();
                value = sysxIO->getSourceValue("Structure", address, "00", pos3);
                QString valueHex3 = QString::number(value, 16).toUpper();
                valueHex.append(valueHex2).append(valueHex3);
                value = (valueHex.toInt(&ok, 16));
                valueHex = QString::number(value, 16).toUpper();
                if(valueHex.length() < 2) valueHex.prepend("0");
                temp.append(midiTable->getValue("Tables", assign_desc, "00", assign_customdesc, valueHex));
                //temp.append("<br>"+assign_desc+" "+assign_customdesc+" - "+valueHex);

            }
            else
            {
                temp.append(midiTable->getValue("Structure", address, "00", pos, valueHex));
            };
            text2.append(temp);

            if (this->filter != "off")
            {
                if (pretxt == this->filter) { text.append(temp); };
            } else if(!pretxt.contains("Custom:")){text.append(temp); };
            if((i == start || i == start+1 || i == start+2) && x == "On") { this->effect = "on"; }; // first byte is usually the effect on/off switch
            if((pretxt == "MOD:" || pretxt == "MFX:") && (txt == "Type"))
            {this->filter = midiTable->getMidiMap("Structure", address, "00", pos, valueHex).desc;};
        };
    };
}

summaryDialog::~summaryDialog()
{}

void summaryDialog::view()
{
    if (mode == "Compact")
    {
        viewButton->setText(tr("Less Details"));
        textDialog->setText(large_text);
        this->mode = "Expanded";
    }
    else
    {
        viewButton->setText(tr("More Details"));
        textDialog->setText(small_text);
        this->mode = "Compact";
    };
}

void summaryDialog::cancel()
{
    this->close();
}

void summaryDialog::printFile()
{
 //#ifdef  Q_PROCESSOR_ARM
 //#elif QT_NO_PRINTER
    QPrinter printer;
    QPrintDialog *dialog = new QPrintDialog(&printer, this);
    //QPrintPreviewDialog *dialog = new QPrintPreviewDialog(&printer, this);
    dialog->setWindowTitle(tr("Print Document"));
    if (dialog->exec() != QDialog::Accepted) { return; }
    else { textDialog->print(&printer); };
    dialog->deleteLater();
//#endif
}

void summaryDialog::printPreview()
{
#ifdef  Q_PROCESSOR_ARM
#elif QT_NO_PRINTER

    QPrinter printer;
    //QPrintDialog *dialog = new QPrintDialog(&printer, this);
    QPrintPreviewDialog *dialog = new QPrintPreviewDialog(&printer, this);
    dialog->setWindowTitle(tr("Print Preview"));
    if (dialog->exec() != QDialog::Accepted) { return; }
    else { textDialog->print(&printer); };
    dialog->deleteLater();
#endif
}

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
    }
}
