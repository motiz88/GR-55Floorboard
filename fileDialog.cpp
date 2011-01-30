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
#include "fileDialog.h"


fileDialog::fileDialog(QString fileName, QList<QString> patchList, QByteArray fileData, QByteArray default_data, QString type)
{
    //QObject::connect(this, SIGNAL(patchIndex(int)),
                //this->parent(), SLOT(patchIndex(int)));
  this->file_format = type;
  this->fileData = fileData;
  this->default_data = default_data;
  QLabel *patchLabel = new QLabel(tr("Select patch to load"));
  QLabel *nameLabel = new QLabel(fileName);
  QComboBox *patchCombo = new QComboBox;
  patchCombo->setMaxVisibleItems(200);
  patchCombo->addItems(patchList);
  patchCombo->setWhatsThis(tr("To auditon a multi-patch *.g5l file, hover the mouse cursor over a patch and the patch data will be loaded into the GT temporary buffer"
                              "<br>a click on the patch will load it into the editor."));


  QObject::connect(patchCombo, SIGNAL(currentIndexChanged(int)),
                this, SLOT(valueChanged(int)));

  QObject::connect(patchCombo, SIGNAL(highlighted(int)),
                this, SLOT(highlighted(int)));

  QPushButton *cancelButton = new QPushButton(tr("Cancel"));
  connect(cancelButton, SIGNAL(clicked()), this, SLOT(cancel()));
  cancelButton->setWhatsThis(tr("Selecting this will close the patch load window and reset the GT back to the current editor patch."));



        QHBoxLayout *horizontalLayout = new QHBoxLayout;
        horizontalLayout->addWidget(patchLabel);
        horizontalLayout->addWidget(patchCombo);

        QHBoxLayout *buttonsLayout = new QHBoxLayout;
        buttonsLayout->addStretch(1);
        buttonsLayout->addWidget(cancelButton);

        QVBoxLayout *mainLayout = new QVBoxLayout;
        mainLayout->addWidget(nameLabel);
        mainLayout->addLayout(horizontalLayout);
        mainLayout->addStretch(1);
        mainLayout->addSpacing(12);
        mainLayout->addLayout(buttonsLayout);
        setLayout(mainLayout);

        setWindowTitle(tr("Bulk File Patch Extraction"));
};

void fileDialog::valueChanged(int value)
{
  SysxIO *sysxIO = SysxIO::Instance();
  sysxIO->patchListValue = value;
  this->close();
};

void fileDialog::cancel()
{
  SysxIO *sysxIO = SysxIO::Instance();
  sysxIO->patchListValue = 0;
  sysxIO->writeToBuffer();
  this->close();
};

void fileDialog::highlighted(int value)
{


 if (file_format == "g5l")
    {
    QByteArray marker = fileData.mid(170, 2);      //copy marker key to find "06A5" which marks the start of each patch block
    unsigned int a = fileData.indexOf(marker, 0); // locate patch start position from the start of the file
    a=a+2;                             // offset is set in front of marker
    if (value>1)
    {
     int q=value-1;
      for (int h=0;h<q;h++)
        {
         a = fileData.indexOf(marker, a); // locate patch start position from the start of the file
         a=a+2;
        };                             // offset is set in front of marker
    };
    QByteArray temp;
    temp = fileData.mid(a, 128);
    default_data.replace(11, 128, temp);      //address "00" +
    temp = fileData.mid(a+128, 128);
    default_data.replace(152, 128, temp);     //address "01" +
    temp = fileData.mid(a+256, 128);
    default_data.replace(293, 128, temp);     //address "02" +
    temp = fileData.mid(a+384, 128);
    default_data.replace(434, 128, temp);     //address "03" +
    temp = fileData.mid(a+512, 128);
    default_data.replace(575, 128, temp);     //address "04" +
    temp = fileData.mid(a+640, 86);
    default_data.replace(716, 86, temp);     //address "05" +
    temp = fileData.mid(a+768, 128);
    default_data.replace(815, 128, temp);     //address "06" +
    temp = fileData.mid(a+896, 128);
    default_data.replace(956, 128, temp);     //address "07" +
    temp = fileData.mid(a+1024, 128);
    default_data.replace(1097, 128, temp);     //address "08" +
    temp = fileData.mid(a+1152, 100);
    default_data.replace(1238, 100, temp);     //address "09" +
    temp = fileData.mid(a+1280, 128);
    default_data.replace(1351, 128, temp);    //address "0A" +
    temp = fileData.mid(a+1408, 128);
    default_data.replace(1492, 128, temp);    //address "0B" +
    temp = fileData.mid(a+1536, 128);
    default_data.replace(1633, 128, temp);    //address "0C" +

    temp = fileData.mid(32, 1);
    int z = a+1701;
    int y = fileData.indexOf( temp, (a+1701));          // copy user text, first two sections only, section terminated by "00"
    int x = fileData.indexOf( temp, (a+1701)) + 1;
    int w = fileData.indexOf( temp, (x+1));
    temp = fileData.mid(z, (y-z) );
    marker = fileData.mid(31, 1);    //"20"
    if (temp.size()>0 )
     {
       for (int u = (32-(y-z));u>0; u--)
       { temp.append(marker); };
       if (temp.size()>32) {temp=temp.mid(0, 32); }
       default_data.replace(1915, (y-z), temp);       // paste text 1
     };
     temp = fileData.mid(x, (w-x) );
     if (temp.size()>0 )
     {
       for (int u = (128-(w-x));u>0; u--)
       { temp.append(marker); };
       if (temp.size()>128) {temp=temp.mid(0, 128); }
       default_data.replace(1774, (w-x), temp);            // paste text 2
     };

     if (value>0)
     {
     SysxIO *sysxIO = SysxIO::Instance();
     QString area = "Structure";
     sysxIO->setFileSource(area, default_data);
     sysxIO->setFileName("file audition");
     //this->fileSource = sysxIO->getFileSource();
     sysxIO->writeToBuffer();
     // QApplication::beep();
     };
 };
};





