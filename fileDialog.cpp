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

#include <QtGui>
#include "fileDialog.h"


fileDialog::fileDialog(QString fileName, QList<QString> patchList, QByteArray fileData, QByteArray default_data, QString type)
{
    this->file_format = type;
    this->fileData = fileData;
    this->default_data = default_data;
    QLabel *patchLabel = new QLabel(tr("Select patch to load"));
    QLabel *nameLabel = new QLabel(fileName);
    QComboBox *patchCombo = new QComboBox;
    patchCombo->setMaxVisibleItems(297);
    patchCombo->addItems(patchList);
    patchCombo->setWhatsThis(tr("To auditon a multi-patch *.g5l file, hover the mouse cursor over a patch and the patch data will be loaded into the GR-55 temporary buffer"
                                "<br>a click on the patch will load it into the editor."));

    QObject::connect(patchCombo, SIGNAL(currentIndexChanged(int)),
                     this, SLOT(valueChanged(int)));

    //QObject::connect(patchCombo, SIGNAL(highlighted(int)),
                     //this, SLOT(highlighted(int)));

    QPushButton *cancelButton = new QPushButton(tr("Cancel"));
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(cancel()));
    cancelButton->setWhatsThis(tr("Selecting this will close the patch load window and reset the GR-55 back to the current editor patch."));

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
}

void fileDialog::valueChanged(int value)
{  
    SysxIO *sysxIO = SysxIO::Instance();
    sysxIO->patchListValue = value;
    this->close();
}

void fileDialog::cancel()
{
    SysxIO *sysxIO = SysxIO::Instance();
    sysxIO->patchListValue = 0;
    sysxIO->writeToBuffer();
    this->close();
}

void fileDialog::highlighted(int value)
{
    this->value = value;
    if (file_format == "g5l")
    {
        QByteArray marker = fileData.mid(162, 10);      //copy marker key to find "04D3" which marks the start of each patch block
        unsigned int a = fileData.indexOf(marker, 0); // locate patch start position from the start of the file
        a=a+10;                             // offset is set in front of marker
        if (value>1)
        {
            int q=value-1;
            for (int h=0;h<q;h++)
            {
                a = fileData.indexOf(marker, a); // locate patch start position from the start of the file
                a=a+10;
            };                             // offset is set in front of marker
        };
        QByteArray temp;
        temp = fileData.mid(a, 128);
        default_data.replace(11, 128, temp);      //address "00"
        temp = fileData.mid(a+128, 128);
        default_data.replace(152, 128, temp);     //address "01"
        temp = fileData.mid(a+261, 73);
        default_data.replace(298, 73, temp);     //address "02" +
        temp = fileData.mid(a+350, 128);
        default_data.replace(384, 128, temp);     //address "03" +
        temp = fileData.mid(a+478, 128);
        default_data.replace(525, 128, temp);     //address "04" +
        temp = fileData.mid(a+606, 18);
        default_data.replace(666, 18, temp);     //address "05" +
        temp = fileData.mid(a+640, 30);
        default_data.replace(697, 30, temp);     //address "06" +
        temp = fileData.mid(a+678, 125);
        default_data.replace(740, 125, temp);     //address "07" +
        temp = fileData.mid(a+811, 128);
        default_data.replace(878, 128, temp);     //address "10" +
        temp = fileData.mid(a+939, 86);
        default_data.replace(1019, 86, temp);     //address "11" +
        temp = fileData.mid(a+1033, 35);
        default_data.replace(1118, 35, temp);    //address "20" +
        temp = fileData.mid(a+1072, 35);
        default_data.replace(1166, 35, temp);    //address "21" +
        temp = fileData.mid(a+1115, 52);
        default_data.replace(1214, 52, temp);    //address "30" +
        temp = fileData.mid(a+1171, 52);
        default_data.replace(1279, 52, temp);    //address "31" +

        if (value>0)
        {
            SysxIO *sysxIO = SysxIO::Instance();
            QString area = "Structure";
            sysxIO->setFileSource(area, default_data);
            sysxIO->setFileName("file audition");
            sysxIO->writeToBuffer();
        };
    };
}


void fileDialog::mouseRightClickEvent(QMouseEvent *event)
{
    highlighted(value);
}


