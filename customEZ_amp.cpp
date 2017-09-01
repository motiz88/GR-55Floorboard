/****************************************************************************
**
** Copyright (C) 2007~2016 Colin Willcocks.
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
#include "Preferences.h"
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
    if (m_iy_axis != iy_axis)
    {
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
    if (m_ix_axis != ix_axis)
    {
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
    Preferences *preferences = Preferences::Instance();
    bool ok;
    const double ratio = preferences->getPreferences("Window", "Scale", "ratio").toDouble(&ok);

    QPixmap image = QPixmap(":images/EZ_Tone.png");
    QRectF target(0.0, 0.0, image.width()*ratio, image.height()*ratio);
    QRectF source(0.0, 0.0, image.width(), image.height());

    QPainter painter(this);
    painter.drawPixmap(target, image, source);

    int h   =     height();
    int w   =     width();
    int ver =     (20*ratio)+(100-m_iy_axis)*260/100*ratio;
    int hor  =    (20*ratio)+(m_ix_axis*260/100)*ratio;

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

    if (m_iDragNode >= 0 && this->underMouse() )
    {
        m_iDragNode = -1;
        unsetCursor();
        sync();
        //emit updateSignal();
    }
}

// Draw rectangular point.
QRect customEZ_amp::nodeRect ( int iNode ) const
{
    Preferences *preferences = Preferences::Instance();
    bool ok;
    const double ratio = preferences->getPreferences("Window", "Scale", "ratio").toDouble(&ok);

    const QPoint& pos = poly.at(8);
    return QRect(pos.x() - 8*ratio, pos.y() - 8*ratio, 16*ratio, 16*ratio);
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
}

