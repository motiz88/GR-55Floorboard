/****************************************************************************
**
** Copyright (C) 2007~2013 Colin Willcocks.
** Copyright (C) 2005~2007 Uco Mesdag.
** All rights reserved.
** This file is part of "GT-100 Fx FloorBoard".
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

#include "customControlEZ_Patch.h"
#include "MidiTable.h"
#include "SysxIO.h"

// Platform-dependent sleep routines.
#ifdef Q_OS_WIN
#include <windows.h>
#define SLEEP( milliseconds ) Sleep( (DWORD) milliseconds )
#else // Unix variants & Mac
#include <unistd.h>
#define SLEEP( milliseconds ) usleep( (unsigned long) (milliseconds * 1000.0) )
#endif

customControlEZ_Patch::customControlEZ_Patch(QWidget *parent,
                                             QString hex1, QString hex2, QString hex3,
                                             QString direction)
    : QWidget(parent)
{
    this->label = new customControlLabel(this);
    this->hex1 = hex1;
    this->hex2 = hex2;
    this->hex3 = hex3;
    this->area = "Tables";
    MidiTable *midiTable = MidiTable::Instance();
    Midi items = midiTable->getMidiMap(this->area, hex1, hex2, hex3);
    QString labeltxt = items.customdesc;

    this->label->setUpperCase(true);
    this->label->setText(labeltxt);

    QString imagePath(":/images/EZ_Patch.png");
    this->switchbutton = new customEZ_Patch(false, this, hex1, hex2, hex3, imagePath);
    this->tone_comboBox = new customControlListMenu(this, hex1, hex2, hex3, "Tables");
    bool ok;
    int x = hex3.toInt(&ok, 16)+1;
    QString hex = QString::number(x, 16).toUpper();
    if(hex.length() < 2) hex.prepend("0");
    this->variation_comboBox = new customControlListMenu(this, hex1, hex2, hex, "Tables");
    this->label->setAlignment(Qt::AlignCenter);

    QVBoxLayout *comboLayout = new QVBoxLayout;
    comboLayout->setMargin(0);
    comboLayout->setSpacing(5);
    comboLayout->addWidget(this->tone_comboBox, 0, Qt::AlignCenter);
    comboLayout->addWidget(this->variation_comboBox, 0, Qt::AlignCenter);
    comboLayout->addStretch(0);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->setMargin(0);
    mainLayout->setSpacing(5);
    mainLayout->addWidget(this->label, 0, Qt::AlignCenter);
    mainLayout->addWidget(this->switchbutton, 0, Qt::AlignCenter);

    mainLayout->addLayout(comboLayout);
    mainLayout->addStretch(0);

    this->setLayout(mainLayout);

    QFile file(":EZ-Tone.syx");           // Read the EZ-Tone sysx file .
    if (file.open(QIODevice::ReadOnly))
    {this->EZ_Patches = file.readAll(); };

    QObject::connect(tone_comboBox, SIGNAL( currentIndexChanged(int)),
                     switchbutton, SLOT( setValue(int)));

    QObject::connect(tone_comboBox, SIGNAL( currentIndexChanged(int)),
                     this, SLOT( tone_select(int)));

    QObject::connect(variation_comboBox, SIGNAL( currentIndexChanged(int)),
                     this, SLOT( variation_select(int)));

    tone_comboBox->set_index(0);
    variation_comboBox->set_index(0);
    variation_comboBox->controlListComboBox->setFixedWidth(180);
    variation_comboBox->controlListComboBox->setMaxVisibleItems(10);
    tone_select(0);
}

void customControlEZ_Patch::paintEvent(QPaintEvent *)
{
    /*DRAWS RED BACKGROUND FOR DEBUGGING PURPOSE */
    /*QPixmap image(":images/dragbar.png");

    QRectF target(0.0, 0.0, this->width(), this->height());
    QRectF source(0.0, 0.0, this->width(), this->height());

    QPainter painter(this);
    painter.drawPixmap(target, image, source);*/

}

void customControlEZ_Patch::mouseReleaseEvent ( QMouseEvent *pMouseEvent )
{
    select_patch();
}

void customControlEZ_Patch::valueChanged(int value)
{

}

void customControlEZ_Patch::tone_select(int value)
{
    this->patch_range = 13330*value;   //multiples of 10 patches per catagory = 1333 * 10
    variation_comboBox->set_index(0);
    this->variation_range = 0;
    QList<QString> patch_list;
    for(int x=0; x<10; ++x)
    {
        QString list;
        for(int l = 12; l<28; ++l)
        {
            int pos = this->patch_range + (x*1333);
            unsigned char r = (char)EZ_Patches[l+pos];
            list.append(r);
        };
        patch_list.append(list);        //added new patches to list and remove old list
        variation_comboBox->controlListComboBox->removeItem(0);
    };
    variation_comboBox->controlListComboBox->addItems(patch_list);
}

void customControlEZ_Patch::variation_select(int value)
{
    this->variation_range = 1333 * value;
}

void customControlEZ_Patch::select_patch()
{
    this->patch_select = this->patch_range + this->variation_range;
    QByteArray patch = EZ_Patches.mid( patch_select, 1333);
    SysxIO *sysxIO = SysxIO::Instance();
    QByteArray mode;
    int mode_check = sysxIO->getSourceValue("Structure", "00", "00", "00");     //check for guitar mode
    if(mode_check > 0)
    {
        mode.append("1");
        patch.replace(11, 1, mode);
    }
    else
    {
        mode = patch.mid(3, 1);
        patch.replace(11, 1, mode);
    };
    sysxIO->setFileName("EZ-Tone");
    sysxIO->setFileSource("Structure", patch);
    if(sysxIO->isConnected() && sysxIO->deviceReady())
    {
        int time = 0;
        sysxIO->writeToBuffer();
        while(time<20)
        {
            SLEEP(150);
            if(sysxIO->deviceReady())
            {
                time = 20;
            };
            ++time;     // wait until device is ready
        };
    };
    emit sysxIO->relayUpdateSignal();
}

