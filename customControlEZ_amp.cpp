/****************************************************************************
**
** Copyright (C) 2007~2013 Colin Willcocks.
** Copyright (C) 2005~2007 Uco Mesdag. 
** All rights reserved.
** This file is part of "GR-55FloorBoard".
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

#include "customControlEZ_amp.h"
#include "MidiTable.h"
#include "SysxIO.h"

customControlEZ_amp::customControlEZ_amp(QWidget *parent,
                                         QString hex1, QString hex2, QString hex3,
                                         QString background, QString direction, int lenght)
    : QWidget(parent)
{
        this->hex1 = hex1;
        this->hex2 = hex2;
        this->hex3 = hex3;
        this->hex4 = hex1;
        this->hex5 = hex2;

    this->use = background;

    this->label_1 = new customControlLabel(this);
    this->label_1->setAlignment(Qt::AlignCenter);

    this->label_2 = new customControlLabel(this);
    this->label_2->setAlignment(Qt::AlignCenter);

    this->label_3 = new customControlLabel(this);
    this->label_3->setAlignment(Qt::AlignCenter);

    this->label_4 = new customControlLabel(this);
    this->label_4->setAlignment(Qt::AlignCenter);

    bool ok;
    int x = hex3.toInt(&ok, 16);
    if (this->use == ("Preamp"))
    {
        this->hex_1 = "02";
        this->hex_2 = "0A";
        this->label_1->setText(tr("SOFT"));
        this->label_2->setText(tr("HARD"));
        this->label_3->setText(tr("BACKING"));
        this->label_4->setText(tr("SOLO"));
    }
    else if (this->use == ("Speaker"))
    {
        this->hex_1 = "10";
        this->hex_2 = "0F";
        this->label_1->setText(tr("SMALL"));
        this->label_2->setText(tr("LARGE"));
        this->label_3->setText(tr("   LIVE"));
        this->label_4->setText(tr("RECORDING"));
    }
    else if (this->use == "Ambience")
    {
        this->hex_1 = "11";
        this->hex_2 = "02";
        this->hex1 = "06";
        this->hex2 = "00";
        this->label_1->setText(tr("SMALL"));
        this->label_2->setText(tr("LARGE"));
        this->label_3->setText(tr("DRY"));
        this->label_4->setText(tr("WET"));
    }
    else
    {
        this->hex_1 = QString::number(x+1, 16).toUpper();
        this->hex_2 = QString::number(x, 16).toUpper();
        this->label_1->setText(tr("SOFT"));
        this->label_2->setText(tr("HARD"));
        this->label_3->setText(tr("BACKING"));
        this->label_4->setText(tr("SOLO"));
    };

   //this->label_4->drawRotatedText(90);

    if(hex_1.length() < 2) hex_1.prepend("0");
    if(hex_2.length() < 2) hex_2.prepend("0");

    this->v_slider = new QSlider(Qt::Vertical, this);
    this->v_slider->setMinimum(0);
    this->v_slider->setMaximum(100);
    this->v_slider->setMinimumHeight(260);
    this->v_slider->setMinimumWidth(30);

    this->h_slider = new QSlider(Qt::Horizontal, this);
    this->h_slider->setMinimum(0);
    this->h_slider->setMaximum(100);
    this->h_slider->setMinimumWidth(260);
    this->h_slider->setMinimumHeight(30);

    QHBoxLayout *h_slider_Layout = new QHBoxLayout;
    h_slider_Layout->setMargin(0);
    h_slider_Layout->addSpacing(100);
    h_slider_Layout->addWidget(this->h_slider, 0, Qt::AlignCenter);
    h_slider_Layout->addStretch(0);

    this->frame = new customEZ_amp(this);
    this->frame->setMinimumSize(QSize(300, 300));

    QHBoxLayout *knobLayout = new QHBoxLayout;
    knobLayout->setMargin(0);
    knobLayout->setSpacing(10);
    knobLayout->addWidget(this->v_slider, 0, Qt::AlignCenter);
    knobLayout->addWidget(this->label_3, 0, Qt::AlignCenter);
    knobLayout->setMargin(0);
    knobLayout->addWidget(this->frame, 0, Qt::AlignCenter);
    knobLayout->addWidget(this->label_4, 0, Qt::AlignCenter);
    knobLayout->addStretch(0);

    QVBoxLayout *frameLayout = new QVBoxLayout;
    frameLayout->setMargin(0);
    frameLayout->setSpacing(0);
    frameLayout->addWidget(this->label_2, 0, Qt::AlignCenter);
    frameLayout->addLayout(knobLayout);
    frameLayout->addWidget(this->label_1, 0, Qt::AlignCenter);
    frameLayout->setSpacing(10);
    frameLayout->addLayout(h_slider_Layout);

    this->setLayout(frameLayout);

    QObject::connect(this->parent(), SIGNAL( dialogUpdateSignal() ),
                     this, SLOT( dialogUpdateSignal() ));

    //QObject::connect(this, SIGNAL( updateSignal() ),
                     //this->parent(), SIGNAL( updateSignal() ));

    QObject::connect(this->v_slider, SIGNAL(valueChanged(int)),
                     this, SLOT(y_axisChanged(int)));

    QObject::connect(this->h_slider, SIGNAL(valueChanged(int)),
                     this, SLOT(x_axisChanged(int)));

    QObject::connect(this, SIGNAL( graphUpdateSignal(QString, QString) ),
                     this->frame, SLOT( updateSlot(QString, QString) ));

    QObject::connect(this->frame, SIGNAL(y_axisChanged(int)),
                     this, SLOT(y_axisChanged(int) ));

    QObject::connect(this->frame, SIGNAL(x_axisChanged(int)),
                     this, SLOT(x_axisChanged(int) ));
}

void customControlEZ_amp::paintEvent(QPaintEvent *)
{
    /*DRAWS RED BACKGROUND FOR DEBUGGING PURPOSE */
    /*QPixmap image(":images/dragbar.png");

    QRectF target(0.0, 0.0, this->width(), this->height());
    QRectF source(0.0, 0.0, this->width(), this->height());

    QPainter painter(this);
    painter.drawPixmap(target, image, source);*/
}

void customControlEZ_amp::dialogUpdateSignal()
{
    SysxIO *sysxIO = SysxIO::Instance();
     unsigned int value;

    value = sysxIO->getSourceValue("Structure", this->hex1, this->hex2, this->hex_2);
    if(use=="Preamp"){ value=value*2; };
    if(use=="Speaker"){ value=value*100/11; };
    if(use=="Distortion"){ value=value*55/10; };
    this->v_slider->setValue(value);
    QString data_1 = QString::number(value, 16).toUpper();
    if(data_1.length() < 2) data_1.prepend("0");

    value = sysxIO->getSourceValue("Structure", this->hex4, this->hex5, this->hex_1);
    if(use=="Preamp"){ value=value-20; };
    if(use=="Distortion"){ value=value-10; };
    this->h_slider->setValue(value);
    QString data_2 = QString::number(value, 16).toUpper();
    if(data_2.length() < 2) data_2.prepend("0");

    emit graphUpdateSignal( data_1, data_2);
}

void customControlEZ_amp::y_axisChanged(int iy_axis)
{
    if(iy_axis != y_data)
    {
        y_data = iy_axis;
        this->v_slider->setValue(y_data);
        QString data_1 = QString::number(y_data, 16).toUpper();
        if(data_1.length() < 2) data_1.prepend("0");
        QString data_2 = QString::number(x_data, 16).toUpper();
        if(data_2.length() < 2) data_2.prepend("0");
        emit graphUpdateSignal( data_1, data_2);
        dataChanged();
    };
}

void customControlEZ_amp::x_axisChanged(int ix_axis)
{
    if(ix_axis != x_data)
    {
        x_data = ix_axis;
        this->h_slider->setValue(x_data);
        QString data_1 = QString::number(y_data, 16).toUpper();
        if(data_1.length() < 2) data_1.prepend("0");
        QString data_2 = QString::number(x_data, 16).toUpper();
        if(data_2.length() < 2) data_2.prepend("0");
        emit graphUpdateSignal( data_1, data_2);
        dataChanged();
    };
}

void customControlEZ_amp::dataChanged()
{
    SysxIO *sysxIO = SysxIO::Instance();
    bool ok;
    if(this->use=="Distortion" && this->frame->underMouse() ) // if from Preamp_A or _B or Speaker_A or _B
        {  // Check if the od/ds effect enabled and selected, if not then do so.
            QList<QString> hex_p; hex_p.append("01"); hex_p.append("00");
            int enabled = sysxIO->getSourceValue("Structure", "07", "00", "15");
            int type = sysxIO->getSourceValue("Structure", "07", "00", "16");
            if((enabled == 0) || (type > 0)) { sysxIO->setFileSource("Structure", "07", "00", "15", hex_p); };
        };
    int x = hex3.toInt(&ok, 16);
    QString hex_addr = QString::number(x, 16).toUpper();
    QString hex;
    QList<QString> hexString1;
    QList<QString> hexString2;
    QList<QString> hexString3;
    QList<QString> hexString4;
    QList<QString> hexString5;

    if(this->use=="Preamp")
    {
        hex = QString::number(x_data+20, 16).toUpper();
        if (hex.size() < 2) hex.prepend("0");  // preamp drive 20~120 int
        hexString1.append(hex);

        int data = x_data-60; if(data<0) {data=0; };
        QString hexx;
        if(data>0){ hexx="01"; } else { hexx="00"; };   // solo sw
        hexString2.append(hexx);
        data = (data*2)-20; if(data<0) { data = 0; };
        hex = QString::number(data, 16).toUpper();
        if (hex.size() < 2) hex.prepend("0");  // solo level
        hexString2.append(hex);

        data = (y_data/2);
        hex = QString::number(data, 16).toUpper();
        if (hex.size() < 2) hex.prepend("0");  // presence
        hexString3.append(hex);

        data = (y_data*2/5)+8;
        if(data>20) data=20;
        hex = QString::number(data, 16).toUpper();
        if (hex.size() < 2) hex.prepend("0");  // EQ low mid gain
        hexString4.append(hex);

        data = y_data;
        data = data/4;
        if(data<15) data=15;
        hex = QString::number(data, 16).toUpper();
        if (hex.size() < 2) hex.prepend("0");  // MFX EQ mid 2 gain
        hexString5.append(hex);


        if(this->toggle == 1)
        {
            sysxIO->setFileSource("Structure", "07", "00", "02", hexString1); //preamp drive
            this->toggle = 2;
        }
        else if(this->toggle == 2)
        {
            sysxIO->setFileSource("Structure", "07", "00", "05", hexString2); //solo sw & level
            this->toggle = 3;
        }
        else if(this->toggle == 3)
        {
            sysxIO->setFileSource("Structure", "06", "00", "16", hexString4); //EQ low mid gain
            this->toggle = 4;
        }
        else if(this->toggle == 4)
        {
            sysxIO->setFileSource("Structure", "03", "00", "0D", hexString5); //MFX EQ mid 2 gain
            this->toggle = 5;
        }
        else
        {
            sysxIO->setFileSource("Structure", "07", "00", "0A", hexString3); //presence
            this->toggle = 1;
        };
    }
    else if(this->use=="Speaker")
    {

        int data = ((y_data*9)/100);
        if(data>8){ data=8; };
        if(data<1){ data=1; };
        hex = QString::number(data, 16).toUpper();
        if (hex.size() < 2) hex.prepend("0");
        hexString1.append(hex);                   //sp cab type

        data = (y_data/25);
        hex = QString::number(data, 16).toUpper(); //mic type
        if (hex.size() < 2) hex.prepend("0");
        hexString1.append(hex);

        data = (y_data/50);
        if(data>1) { data=1; };
        hex = QString::number(data, 16).toUpper(); //mic dis
        if (hex.size() < 2) hex.prepend("0");
        hexString1.append(hex);

        data = (y_data*11/100);
        if(data>10) { data=10; };
        hex = QString::number(data, 16).toUpper(); //mic pos
        if (hex.size() < 2) hex.prepend("0");
        hexString1.append(hex);

        hex = QString::number(x_data, 16).toUpper(); //mic level
        if (hex.size() < 2) hex.prepend("0");
        hexString1.append(hex);

        data = ((100-y_data)/14);
        if(data>6) { data = 6; };
        hex = QString::number(data, 16).toUpper();
        if (hex.size() < 2) hex.prepend("0");
        hexString2.append(hex);                    //EQ character

        if(this->toggle == 1)
        {
            sysxIO->setFileSource("Structure", "07", "00", "0C", hexString1);
            this->toggle = 2;
        }
        else
        {
           sysxIO->setFileSource("Structure", "06", "00", "1D", hexString2);
           this->toggle = 1;
        };
    }
    else if(use == "Ambience")
    {
        hex = QString::number(x_data, 16).toUpper();
        if (hex.size() < 2) hex.prepend("0");               // reverb/chorus/delay mix level
        hexString1.append(hex);
        hexString1.append(hex);
        hexString1.append(hex);

        int data = (x_data*70)/100;
        hex = QString::number(data, 16).toUpper();
        if (hex.size() < 2) hex.prepend("0");               // reverb/chorusdelay level
        hexString2.append(hex);

        data = ((y_data*99/100));
        hex = QString::number(data, 16).toUpper();
        if (hex.size() < 2) hex.prepend("0");               // chorus/reverb time 00~63
        hexString3.append(hex);

        hex = QString::number(y_data*15, 16).toUpper();
        if (hex.size() < 3) hex.prepend("0");               // delay time
        if (hex.size() < 2) hex.prepend("00");

        QString byte_1 = hex.mid(0,1).prepend("0");
        hexString4.append(byte_1);
        QString byte_2 = hex.mid(1,1).prepend("0");
        hexString4.append(byte_2);
        QString byte_3 = hex.mid(2,1).prepend("0");
        hexString4.append(byte_3);

        if(this->toggle == 1)
        {
            sysxIO->setFileSource("Structure", "07", "00", "11", hexString1); //CH/DD/RV mix level
            this->toggle = 2;
        }
        else if(this->toggle == 2)
        {
            sysxIO->setFileSource("Structure", "06", "00", "04", hexString2); //chorus level
            this->toggle = 3;
        }
        else if(this->toggle == 3)
        {
            sysxIO->setFileSource("Structure", "06", "00", "0B", hexString2); //delay level
            this->toggle = 4;
        }
        else if(this->toggle == 4)
        {
            sysxIO->setFileSource("Structure", "06", "00", "10", hexString2); //reverb level
            this->toggle = 5;
        }
        else if(this->toggle == 5)
        {
            sysxIO->setFileSource("Structure", "06", "00", "02", hexString3); //chorus rate
            this->toggle = 6;
        }
        else if(this->toggle == 6)
        {
            sysxIO->setFileSource("Structure", "06", "00", "0E", hexString3); //reverb time
            this->toggle = 7;
        }
        else
        {
            sysxIO->setFileSource("Structure", "06", "00", "07", hexString4); //delay time
            this->toggle = 1;
        };
    }
    else
    {
        int data = ((y_data*10/55));
        hex = QString::number(data, 16).toUpper(); //od/ds type
        if (hex.size() < 2) hex.prepend("0");
        hexString1.append(hex);

        hex = QString::number(x_data+10, 16).toUpper(); //od/ds drive
        if (hex.size() < 2) hex.prepend("0");
        hexString1.append(hex);

        data = ((y_data*3)/10)+35;
        hex = QString::number(data, 16).toUpper();  //od/ds tone
        if (hex.size() < 2) hex.prepend("0");
        hexString1.append(hex);


        sysxIO->setFileSource("Structure", this->hex1, this->hex2, hex_addr, hexString1);
    };
    //emit updateSignal();
}

