/****************************************************************************
**
** Copyright (C) 2007~2012 Colin Willcocks.
** Copyright (C) 2005~2007 Uco Mesdag.
** All rights reserved.
** This file is part of "GR-55B FloorBoard".
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

#include "customMasterEQGraph.h"
#include <QPainter>
#include <QMouseEvent>
#include <QGraphicsPathItem>

customMasterEQGraph::customMasterEQGraph (QWidget *parent)
{
	QFrame::setFrameShape(QFrame::Panel);
        QFrame::setFrameShadow(QFrame::Sunken);

}

customMasterEQGraph::~customMasterEQGraph (void)
{
}

void customMasterEQGraph::setLowGain ( unsigned short iLowGain )
{
     if (iLowGain > 24) iLowGain = 24;
        if (m_iLowGain != iLowGain) {
                m_iLowGain  = iLowGain;
                update();
                emit LowGainChanged(LowGain());
        };
}

unsigned short customMasterEQGraph::LowGain (void) const
{
        return m_iLowGain;
}


void customMasterEQGraph::setMidFreq ( unsigned short iMidFreq )
{
     if (iMidFreq > 27) iMidFreq = 27;
        if (m_iMidFreq != iMidFreq) {
                m_iMidFreq  = iMidFreq;
                update();
                emit MidFreqChanged(MidFreq());
        };
}

unsigned short customMasterEQGraph::MidFreq (void) const
{
        return m_iMidFreq;
}


void customMasterEQGraph::setMidQ ( unsigned short iMidQ )
{
    if (iMidQ > 5) iMidQ = 5;
        if (m_iMidQ != iMidQ) {
                m_iMidQ  = iMidQ;
                update();
                emit MidQChanged(MidQ());
        }
}

unsigned short customMasterEQGraph::MidQ (void) const
{
        return m_iMidQ;
}


void customMasterEQGraph::setMidGain ( unsigned short iMidGain )
{
    if (iMidGain > 24) iMidGain = 24;
        if (m_iMidGain != iMidGain) {
                m_iMidGain  = iMidGain;
                update();
                emit MidGainChanged(MidGain());
        }
}

unsigned short customMasterEQGraph::MidGain (void) const
{
        return m_iMidGain;
}

void customMasterEQGraph::setHighGain ( unsigned short iHighGain )
{
    if (iHighGain > 24) iHighGain = 24;
        if (m_iHighGain != iHighGain) {
                m_iHighGain  = iHighGain;
                update();
                emit HighGainChanged(HighGain());
        };
}

unsigned short customMasterEQGraph::HighGain (void) const
{
        return m_iHighGain;
}

void customMasterEQGraph::setLevel ( unsigned short iLevel )
{
    if (iLevel > 100) iLevel = 100;
        if (m_iLevel != iLevel) {
                m_iLevel  = iLevel;
                update();
                emit LevelChanged(Level());
        };
}

unsigned short customMasterEQGraph::Level (void) const
{
        return m_iLevel;
}


void customMasterEQGraph::paintEvent ( QPaintEvent *pPaintEvent )
{
    QPixmap image = QPixmap(":images/EQ_graph.png");
    QRectF target(0.0, 0.0, image.width()*85/100, image.height()*43/100);
    QRectF source(0.0, 0.0, image.width(), image.height());

    QPainter painter(this);
    painter.drawPixmap(target, image, source);

    int h  = height();
    int w  = width();

    int lg  = h - (m_iLowGain*4) - 25;

    int mf = (m_iMidFreq*20) + 5;
    int mq = h*100/82-(m_iMidQ*40);
    int mg = h - (m_iMidGain)-40;

    int hg  = h - (m_iHighGain*4) - 25;

    int lev = h/10 - (m_iLevel);

    QLinearGradient grad(0, 0, w << 1, h << 1);
    grad.setColorAt(0.0f, Qt::yellow);
    grad.setColorAt(1.0f, Qt::black);

   /* painter.setBrush(grad);
    //painter.drawPath(path);*/

    poly.putPoints(0, 11,
            0,       h,                         // [0]    horizonal, vertical

            0,       (h/4*3)+lev,               // [1]
            w/4,      lg+lev,                   // [2]
            w/2,     (h*50/78)+lev,             // [3]

            mf-mq,   mg+lev,                    // [4]
            mf,      ((h*100/82)-(m_iMidGain*5))+lev, // [5]
            mf+mq,   mg+lev,                    // [6]

            w/3*2,     (h*50/78)+lev,           // [7]
            w/4*3,      hg+lev,                 // [8]
            w,       (h/4*3)+lev,               // [9]

            w,        h  );                     // [10]

    QPainterPath loHi;
    loHi.moveTo(poly.at(0));
    loHi.lineTo(poly.at(1));
    loHi.cubicTo(poly.at(1), poly.at(2), poly.at(3));
    loHi.lineTo(poly.at(7));
    loHi.cubicTo(poly.at(7), poly.at(8), poly.at(9));
    loHi.lineTo(poly.at(10));

    QPainterPath Mid;
    Mid.moveTo(poly.at(4));
    Mid.cubicTo(poly.at(4), poly.at(5), poly.at(6));

    painter.setPen(Qt::yellow);

    QPainterPath graph = (loHi.subtracted(Mid));
    painter.setBrush(grad);
    painter.drawPath((graph));
    painter.setBrush(Qt::red);
    painter.drawRect(nodeRect(1));
    painter.drawRect(nodeRect(2));
    painter.drawRect(nodeRect(3));
    painter.setBrush(Qt::green);
    painter.drawRect(nodeRect(4));
    painter.drawRect(nodeRect(5));
    painter.drawRect(nodeRect(6));
    painter.setBrush(Qt::blue);
    painter.drawRect(nodeRect(7));
    painter.drawRect(nodeRect(8));
    painter.drawRect(nodeRect(9));


    painter.end();

    QFrame::paintEvent(pPaintEvent);
}


// Mouse interaction.
void customMasterEQGraph::mousePressEvent ( QMouseEvent *pMouseEvent )
{
    if (pMouseEvent->button() == Qt::LeftButton) {
            const QPoint& pos = pMouseEvent->pos();
            int iDragNode = nodeIndex(pos);
            if (iDragNode >= 0) {
                    setCursor(iDragNode == 1 || iDragNode == 3 || iDragNode == 6 || iDragNode == 8
                            ? Qt::SizeAllCursor
                            : Qt::SizeHorCursor);
                    m_iDragNode = iDragNode;
                    m_posDrag = pos;
            }
    }

    QFrame::mousePressEvent(pMouseEvent);

}


void customMasterEQGraph::mouseMoveEvent ( QMouseEvent *pMouseEvent )
{

    dragNode(pMouseEvent->pos());
}


void customMasterEQGraph::mouseReleaseEvent ( QMouseEvent *pMouseEvent )
{
    QFrame::mouseReleaseEvent(pMouseEvent);

        dragNode(pMouseEvent->pos());

        if (m_iDragNode >= 0) {
                m_iDragNode = -1;
                unsetCursor();
        }
}



// Draw rectangular point.
QRect customMasterEQGraph::nodeRect ( int iNode ) const
{
        const QPoint& pos = poly.at(iNode);
        return QRect(pos.x() - 4, pos.y() - 4, 8, 8);
}


int customMasterEQGraph::nodeIndex ( const QPoint& pos ) const
{     
        if (nodeRect(8).contains(pos))
                return 5; // HighGain

        if (nodeRect(6).contains(pos))
                return 4; // MidQ

        if (nodeRect(5).contains(pos))
                return 3; // MidFreq/MidGain

        if (nodeRect(4).contains(pos))
                return 2; // MidQ

        if (nodeRect(2).contains(pos))
                return 1; //LowGain

        return -1;
}

void customMasterEQGraph::dragNode ( const QPoint& pos )
{
        static unsigned short m_iLevel0 = 0; // Dummy!
        unsigned short *piRate  = NULL;
        unsigned short *piLevel = NULL;
        switch (m_iDragNode) {
        case 1: // LowGain
                piRate  = &m_iLevel0;
                piLevel = &m_iLowGain;
                break;
        case 2: // MidQ
                piRate  = &m_iMidQ;
                piLevel = &m_iLevel0;
                break;
        case 3: // MidFreq/MidGain
                piRate  = &m_iMidFreq;
                piLevel = &m_iMidGain;
                break;
        case 4: // MidQ
                piRate  = &m_iMidQ;
                piLevel = &m_iLevel0;
                break;
        case 5: // HighGain
                piRate  = &m_iHighGain;
                piLevel = &m_iLevel0;
                break;
        }

        if (piRate && piLevel) {
                int iRate = int(*piRate) + ((pos.x() - m_posDrag.x()) << 6) / (width() >> 2);
                int iLevel = int(*piLevel) + ((m_posDrag.y() - pos.y()) << 7) / height();
                if (iLevel < 0) iLevel = 0;
                else
                if (iLevel > 40) iLevel = 40;
                if (iRate < 0) iRate = 0;
                else
                if (iRate > 30) iRate = 30;
                if (*piRate  != (unsigned short) iRate ||
                        *piLevel != (unsigned short) iLevel) {
                        m_posDrag = pos;
                        switch (m_iDragNode) {
                        case 1: // LowGain
                                setLowGain(iLevel);
                                break;
                        case 2: // MidQ
                                setMidQ(iRate);
                                break;
                        case 3: // MidFreq/MidGain
                                setMidFreq(iRate);
                                setMidGain(iLevel);
                                break;
                        case 4: // MidQ
                                setMidQ(iRate);
                                break;
                        case 5: // HighGain
                                setHighGain(iLevel);
                                break;

                        }
                }
        } else if (nodeIndex(pos) >= 0) {
                setCursor(Qt::PointingHandCursor);
        } else {
                unsetCursor();
        }
}

void customMasterEQGraph::updateSlot(  QString hex_1, QString hex_2, QString hex_3,
                               QString hex_4, QString hex_5, QString hex_6 )
{
    this->hex_1 = hex_1;
    this->hex_2 = hex_2;
    this->hex_3 = hex_3;
    this->hex_4 = hex_4;
    this->hex_5 = hex_5;
    this->hex_6 = hex_6;
    bool ok;
    setLowGain(this->hex_1.toShort(&ok, 16));
    setMidFreq(this->hex_2.toShort(&ok, 16));
    setMidQ(this->hex_3.toShort(&ok, 16));
    setMidGain(this->hex_4.toShort(&ok, 16));
    setHighGain(this->hex_5.toShort(&ok, 16));
    setLevel(this->hex_6.toShort(&ok, 16));

}






