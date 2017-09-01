/****************************************************************************
**
** Copyright (C) 2007~2016 Colin Willcocks.
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

#include <QRegExp>
#include "customRenameWidget.h"
#include "customRenameDialog.h"
#include "SysxIO.h"
#include "MidiTable.h"
#include "globalVariables.h"
#include "Preferences.h"

customRenameWidget::customRenameWidget(QWidget *parent, QString hex1, QString hex2, QString hex3, QString area, QString length)
    : QWidget(parent)

{
    Preferences *preferences = Preferences::Instance();
    bool ok;
    const double ratio = preferences->getPreferences("Window", "Scale", "ratio").toDouble(&ok);

    this->hex1 = hex1;
    this->hex2 = hex2;
    this->hex3 = hex3;
    this->area = area;
    this->length = length;
    this->label = new customControlLabel(this);
    this->catagoryDisplay = new QLineEdit(this);
    
    this->catagoryDisplay->setObjectName("catalogdisplay");
    if (this->length == "80")
    {this->catagoryDisplay->setFixedWidth(980*ratio);}
    else if (this->length == "20")
    {this->catagoryDisplay->setFixedWidth(262*ratio);}
    else
    {this->catagoryDisplay->setFixedWidth(80*ratio);
    };
    this->catagoryDisplay->setFixedHeight(25*ratio);
    this->catagoryDisplay->setAlignment(Qt::AlignCenter);
    this->catagoryDisplay->setDisabled(true);
    if (this->area == "System"){
        MidiTable *midiTable = MidiTable::Instance();
        Midi items = midiTable->getMidiMap(this->area, hex1, hex2, hex3);
        this->label->setText(items.customdesc);
        this->label->setUpperCase(true);
        QObject::connect(this->parent(), SIGNAL( dialogUpdateSignal() ), this, SLOT( dialogUpdateSignal() ));
    };

    QVBoxLayout *Layout = new QVBoxLayout;
    Layout->setMargin(0);
    Layout->setSpacing(0);
    Layout->addWidget(this->label, 0, Qt::AlignCenter);
    Layout->addWidget(this->catagoryDisplay, 0, Qt::AlignCenter);
    Layout->addStretch(0);

    this->setLayout(Layout);
    this->setFixedHeight(40*ratio);
    

    if (this->area != "System")
    { QObject::connect(this->parent()->parent(), SIGNAL(updateSignal()), this, SLOT(dialogUpdateSignal())); };
}

void customRenameWidget::mouseReleaseEvent(QMouseEvent *event)
{
    if ( event->button() == Qt::LeftButton )
    {
        customRenameDialog *dialog = new customRenameDialog(this, hex1, hex2, hex3, area, length);
        connect(dialog, SIGNAL(nameChanged(QString)), this, SLOT(updateName(QString)));
        dialog->exec();
        dialog->deleteLater();
    };
}

void customRenameWidget::updateName(QString name)
{
    SysxIO *sysxIO = SysxIO::Instance();
    bool ok;
    int l = this->length.toInt(&ok, 16);
    QList<QString> hexData;
    for(int i=0; i<l; ++i)
    {
        if(i<name.size())
        {
            char asciiChar = name.at(i).toLatin1();
            int asciiValue = (int)asciiChar;
            QString nameHexValue = QString::number(asciiValue, 16).toUpper();
            if(nameHexValue.length() < 2) nameHexValue.prepend("0");
            hexData.append(nameHexValue);
        }
        else
        {
            hexData.append("20");
        };
    };
    this->catagoryDisplay->setText(name);
    sysxIO->setFileSource(area, hex1, hex2, hex3, hexData);
}

void customRenameWidget::dialogUpdateSignal()
{
    SysxIO *sysxIO = SysxIO::Instance();
    bool ok;
    int x = this->hex3.toInt(&ok, 16) + sysxDataOffset;
    int l = this->length.toInt(&ok, 16);
    QList<QString> nameArray = sysxIO->getFileSource(this->area, this->hex1, this->hex2);
    QString name;
    l=l+x;
    for(int i = x;i<l;i++ )
    {
        QString hexStr = nameArray.at(i);
        name.append( (char)(hexStr.toInt(&ok, 16)) );
    };
    QString Name = name.trimmed();
    this->catagoryDisplay->setText(Name);
}
