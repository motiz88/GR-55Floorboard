/****************************************************************************
**
** Copyright (C) 2007~2012 Colin Willcocks.
** Copyright (C) 2005~2007 Uco Mesdag.
** All rights reserved.
** This file is part of "GT-100B Fx FloorBoard".
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

#include "customEZ_amp.h"
#include "SysxIO.h"
#include "globalVariables.h"
#include <QPainter>
#include <QMouseEvent>
#include <QGraphicsPathItem>

customEZ_amp::customEZ_amp (QWidget *parent)
{
    QFrame::setFrameShape(QFrame::Panel);
    QFrame::setFrameShadow(QFrame::Sunken);
}

customEZ_amp::~customEZ_amp (void)
{
}

void customEZ_amp::setY_axis ( int iy_axis )
{
    if (iy_axis > 100) iy_axis = 100;
    if (m_iy_axis != iy_axis) {
        m_iy_axis  = iy_axis;
        update();
        emit y_axisChanged(Y_axis());
    };
}

int customEZ_amp::Y_axis (void) const
{
    return m_iy_axis;
}

void customEZ_amp::setX_axis ( int ix_axis )
{
    if (ix_axis > 100) ix_axis = 100;
    if (m_ix_axis != ix_axis) {
        m_ix_axis  = ix_axis;
        update();
        emit x_axisChanged(X_axis());
    };
}

int customEZ_amp::X_axis (void) const
{
    return m_ix_axis;
}

void customEZ_amp::paintEvent ( QPaintEvent *pPaintEvent )
{
    QPixmap image = QPixmap(":images/EZ_Tone.png");
    QRectF target(0.0, 0.0, image.width(), image.height());
    QRectF source(0.0, 0.0, image.width(), image.height());

    QPainter painter(this);
    painter.drawPixmap(target, image, source);

    int h   =     height();
    int w   =     width();
    int ver =     20+(100-m_iy_axis)*110/100;
    int hor  =    20+(m_ix_axis*260/100);

    QLinearGradient grad(0, 0, w << 1, h << 1);
    grad.setColorAt(0.0f, Qt::yellow);
    grad.setColorAt(1.0f, Qt::black);

    painter.setBrush(grad);
                // horizonal,      vertical
    poly.putPoints(0,              9,
                   20,              ver,                // [0]
                   w-20,            ver,                // [1]
                   w-20,            ver+2,              // [2]
                   20,              ver+2,              // [3]
                   hor,            20,                  // [4]
                   hor,            h-20,                // [5]
                   hor+2,          h-20,                // [6]
                   hor+2,          20,                  // [7]
                   hor+1,          ver+1);              // [8]


    QPainterPath vert;
    vert.moveTo(poly.at(0));
    vert.lineTo(poly.at(1));
    vert.lineTo(poly.at(2));
    vert.lineTo(poly.at(3));
    vert.lineTo(poly.at(0));

    QPainterPath hori;
    hori.moveTo(poly.at(4));
    hori.lineTo(poly.at(5));
    hori.lineTo(poly.at(6));
    hori.lineTo(poly.at(7));
    hori.lineTo(poly.at(4));

    painter.setPen(Qt::black);
    painter.setBrush(grad);
    painter.drawPath(vert);
    painter.drawPath(hori);

    painter.setBrush(Qt::blue);
    painter.drawRect(nodeRect(1));
    painter.end();

    QFrame::paintEvent(pPaintEvent);
}

// Mouse interaction.
void customEZ_amp::mousePressEvent ( QMouseEvent *pMouseEvent )
{
    if (pMouseEvent->button() == Qt::LeftButton) {
        const QPoint& pos = pMouseEvent->pos();
        int iDragNode = nodeIndex(pos);
        if (iDragNode >= 0) {setCursor(Qt::SizeAllCursor);
            m_iDragNode = iDragNode;
            m_posDrag = pos;
        };
    };
    QFrame::mousePressEvent(pMouseEvent);
}


void customEZ_amp::mouseMoveEvent ( QMouseEvent *pMouseEvent )
{

    dragNode(pMouseEvent->pos());
}


void customEZ_amp::mouseReleaseEvent ( QMouseEvent *pMouseEvent )
{
    QFrame::mouseReleaseEvent(pMouseEvent);

    dragNode(pMouseEvent->pos());

    if (m_iDragNode >= 0) {
        m_iDragNode = -1;
        unsetCursor();
        sync();
        //emit updateSignal();
    }
}

// Draw rectangular point.
QRect customEZ_amp::nodeRect ( int iNode ) const
{
    const QPoint& pos = poly.at(8);
    return QRect(pos.x() - 4, pos.y() - 4, 8, 8);
}

int customEZ_amp::nodeIndex ( const QPoint& pos ) const
{     
    if (nodeRect(8).contains(pos))
        return 1;
    return -1;
}

void customEZ_amp::dragNode ( const QPoint& pos )
{
    int *piRate  = NULL;
    int *piLevel = NULL;
    switch (m_iDragNode) {
    case 1: // Y_axis
        piRate  = &m_ix_axis;
        piLevel = &m_iy_axis;
        break;
    }

    if (piRate && piLevel) {
        int iRate = int(*piRate) + ((pos.x() - m_posDrag.x()) << 6) / (width() >> 2);
        int iLevel = int(*piLevel) + ((m_posDrag.y() - pos.y()) << 7) / height();
        if (iLevel < 0) iLevel = 0;
        else
            if (iLevel > 100) iLevel = 100;
        if (iRate < 0) iRate = 0;
        else
            if (iRate > 100) iRate = 100;
        if (*piRate  != (int) iRate ||
                *piLevel != (int) iLevel) {
            m_posDrag = pos;
            switch (m_iDragNode) {
            case 1: // Y_axis
                setY_axis(iLevel);
                setX_axis(iRate);
                break;
            }
        }
    } else if (nodeIndex(pos) >= 0) { setCursor(Qt::PointingHandCursor); }
      else { unsetCursor(); };
}

void customEZ_amp::updateSlot(  QString hex_1, QString hex_2)
{
    this->hex_1 = hex_1;
    this->hex_2 = hex_2;
    bool ok;
    setY_axis(this->hex_1.toInt(&ok, 16));
    setX_axis(this->hex_2.toInt(&ok, 16));
}

void customEZ_amp::sync()
{

    SysxIO *sysxIO = SysxIO::Instance();
    emit sysxIO->relayUpdateSignal();
   /* if( sysxIO->isConnected())
    {
        //sysxIO->setsetStatusSymbol(2);
        //sysxIO->setStatusMessage(tr("Patch Sync"));
        sysxIO->setDeviceReady(false); // Reserve the device for interaction.

        QObject::disconnect(sysxIO, SIGNAL(sysxReply(QString)));
        QObject::connect(sysxIO, SIGNAL(sysxReply(QString)),
                         this, SLOT(syncResult(QString)));

        sysxIO->requestPatch(0, 0); // GT100 patch request from temorary buffer memory.
    };*/
}

void customEZ_amp::syncResult(QString sysxMsg)
{
    SysxIO *sysxIO = SysxIO::Instance();
    QObject::disconnect(sysxIO, SIGNAL(sysxReply(QString)),
                        this, SLOT(syncResult(QString)));

    sysxIO->setDeviceReady(true); // Free the device after finishing interaction.
    sysxMsg = sysxMsg.remove(" ").toUpper();       /* TRANSLATE SYSX MESSAGE FORMAT to 128 byte data blocks */
    if (sysxMsg.size()/2 == patchReplySize){
        QString header = "F0410000006012";
        QString footer ="00F7";
        QString addressMsb = sysxMsg.mid(14,4);
        QString part1 = sysxMsg.mid(22, 256); //y
        part1.prepend("0000").prepend(addressMsb).prepend(header).append(footer);
        QString part2 = sysxMsg.mid(278, 228); //y
        QString part2B = sysxMsg.mid(532, 28); //y
        part2.prepend("0100").prepend(addressMsb).prepend(header).append(part2B).append(footer);
        QString part3 = sysxMsg.mid(560, 256); //y
        part3.prepend("0200").prepend(addressMsb).prepend(header).append(footer);
        QString part4 = sysxMsg.mid(816, 200); //y
        QString part4B = sysxMsg.mid(1042, 56); //y
        part4.prepend("0300").prepend(addressMsb).prepend(header).append(part4B).append(footer);
        QString part5 = sysxMsg.mid(1098, 256); //y
        part5.prepend("0400").prepend(addressMsb).prepend(header).append(footer);
        QString part6 = sysxMsg.mid(1354, 172); //y
        QString part6B = sysxMsg.mid(1552, 84); //y
        part6.prepend("0500").prepend(addressMsb).prepend(header).append(part6B).append(footer);
        QString part7 = sysxMsg.mid(1636, 256); //y
        part7.prepend("0600").prepend(addressMsb).prepend(header).append(footer);
        QString part8 = sysxMsg.mid(1892, 144);  //y
        QString part8B = sysxMsg.mid(2072, 16); //spacer
        QString part8C = sysxMsg.mid(2062, 96); //y
        part8.prepend("0700").prepend(addressMsb).prepend(header).append(part8B).append(part8C).append(footer);
        QString part9 = sysxMsg.mid(2158, 256); //y
        part9.prepend("0800").prepend(addressMsb).prepend(header).append(footer);
        QString part10 = sysxMsg.mid(2414,132); //y
        QString part10B = sysxMsg.mid(2072, 14); //spacer added twice
        QString part10C = sysxMsg.mid(2572,96); //y
        part10.prepend("0900").prepend(addressMsb).prepend(header).append(part10B).append(part10B).append(part10C).append(footer);
        QString part11 = sysxMsg.mid(2668, 256); //y
        part11.prepend("0A00").prepend(addressMsb).prepend(header).append(footer);
        QString part12 = sysxMsg.mid(2924, 132); //y
        QString part12B = sysxMsg.mid(3082, 124);//y
        part12.prepend("0B00").prepend(addressMsb).prepend(header).append(part12B).append(footer);
        QString part13 = sysxMsg.mid(3206, 256); //y
        part13.prepend("0C00").prepend(addressMsb).prepend(header).append(footer);
        QString part14 = sysxMsg.mid(3462, 104); //y
        QString part14B = sysxMsg.mid(3592, 152);//y
        part14.prepend("0D00").prepend(addressMsb).prepend(header).append(part14B).append(footer);
        QString part15 = sysxMsg.mid(3744, 256); //y
        part15.prepend("0E00").prepend(addressMsb).prepend(header).append(footer);
        QString part16 = sysxMsg.mid(4000, 48); //y
        part16.prepend("0F00").prepend(addressMsb).prepend(header).append(footer);

        sysxMsg.clear();
        sysxMsg.append(part1).append(part2).append(part3).append(part4).append(part5).append(part6)
                .append(part7).append(part8).append(part9).append(part10).append(part11).append(part12)
                .append(part13).append(part14).append(part15).append(part16);

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
        };
    };
}
