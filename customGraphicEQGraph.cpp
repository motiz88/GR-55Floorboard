/****************************************************************************
**
** Copyright (C) 2007~2010 Colin Willcocks.
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

#include "customGraphicEQGraph.h"
//#include <QMessageBox>
#include <QPainter>
#include <QMouseEvent>

customGraphicEQGraph::customGraphicEQGraph (QWidget *parent) : poly(13), m_iDragNode(-1)
{
    QFrame::setFrameShape(QFrame::Panel);
    QFrame::setFrameShadow(QFrame::Sunken);

}

customGraphicEQGraph::~customGraphicEQGraph (void)
{
}

void customGraphicEQGraph::setBand_1 ( unsigned short iBand_1 )
{
    if (iBand_1 > 24) iBand_1 = 24;
    if (m_iBand_1 != iBand_1) {
        m_iBand_1  = iBand_1;
        update();
        emit Band_1Changed(Band_1());
    };
}

unsigned short customGraphicEQGraph::Band_1 (void) const
{
    return m_iBand_1;
}


void customGraphicEQGraph::setBand_2 ( unsigned short iBand_2 )
{
    if (iBand_2 > 24) iBand_2 = 24;
    if (m_iBand_2 != iBand_2) {
        m_iBand_2  = iBand_2;
        update();
        emit Band_2Changed(Band_2());
    };
}

unsigned short customGraphicEQGraph::Band_2 (void) const
{
    return m_iBand_2;
}


void customGraphicEQGraph::setBand_3 ( unsigned short iBand_3 )
{
    if (iBand_3 > 24) iBand_3 = 24;
    if (m_iBand_3 != iBand_3) {
        m_iBand_3  = iBand_3;
        update();
        emit Band_3Changed(Band_3());
    };
}

unsigned short customGraphicEQGraph::Band_3 (void) const
{
    return m_iBand_3;
}


void customGraphicEQGraph::setBand_4 ( unsigned short iBand_4 )
{
    if (iBand_4 > 24) iBand_4 = 24;
    if (m_iBand_4 != iBand_4) {
        m_iBand_4  = iBand_4;
        update();
        emit Band_4Changed(Band_4());
    }
}

unsigned short customGraphicEQGraph::Band_4 (void) const
{
    return m_iBand_4;
}


void customGraphicEQGraph::setBand_5 ( unsigned short iBand_5 )
{
    if (iBand_5 > 24) iBand_5 = 24;
    if (m_iBand_5 != iBand_5) {
        m_iBand_5  = iBand_5;
        update();
        emit Band_5Changed(Band_5());
    }
}

unsigned short customGraphicEQGraph::Band_5 (void) const
{
    return m_iBand_5;
}


void customGraphicEQGraph::setBand_6 ( unsigned short iBand_6 )
{
    if (iBand_6 > 24) iBand_6 = 24;
    if (m_iBand_6 != iBand_6) {
        m_iBand_6  = iBand_6;
        update();
        emit Band_6Changed(Band_6());
    }
}

unsigned short customGraphicEQGraph::Band_6 (void) const
{
    return m_iBand_6;
}

void customGraphicEQGraph::setBand_7 ( unsigned short iBand_7 )
{
    if (iBand_7 > 24) iBand_7 = 24;
    if (m_iBand_7 != iBand_7) {
        m_iBand_7  = iBand_7;
        update();
        emit Band_7Changed(Band_7());
    }
}

unsigned short customGraphicEQGraph::Band_7 (void) const
{
    return m_iBand_7;
}


void customGraphicEQGraph::setBand_8 ( unsigned short iBand_8 )
{
    if (iBand_8 > 24) iBand_8 = 24;
    if (m_iBand_8 != iBand_8) {
        m_iBand_8  = iBand_8;
        update();
        emit Band_8Changed(Band_8());
    }
}

unsigned short customGraphicEQGraph::Band_8 (void) const
{
    return m_iBand_8;
}

void customGraphicEQGraph::setBand_9 ( unsigned short iBand_9 )
{
    if (iBand_9 > 24) iBand_9 = 24;
    if (m_iBand_9 != iBand_9) {
        m_iBand_9  = iBand_9;
        update();
        emit Band_9Changed(Band_9());
    };
}

unsigned short customGraphicEQGraph::Band_9 (void) const
{
    return m_iBand_9;
}

void customGraphicEQGraph::setBand_10 ( unsigned short iBand_10 )
{
    if (iBand_10 > 24) iBand_10 = 24;
    if (m_iBand_10 != iBand_10) {
        m_iBand_10  = iBand_10;
        update();
        emit Band_10Changed(Band_10());
    };
}

unsigned short customGraphicEQGraph::Band_10 (void) const
{
    return m_iBand_10;
}

void customGraphicEQGraph::setLevel ( unsigned short iLevel )
{
    if (iLevel > 24) iLevel = 24;
    if (m_iLevel != iLevel) {
        m_iLevel  = iLevel;
        update();
        emit LevelChanged(Level());
    };
}

unsigned short customGraphicEQGraph::Level (void) const
{
    return m_iLevel;
}

void customGraphicEQGraph::paintEvent ( QPaintEvent *pPaintEvent )
{
    QPixmap image = QPixmap(":images/EQ_graph.png");
    QRectF target(0.0, 0.0, image.width()*85/100, image.height()*43/100);
    QRectF source(0.0, 0.0, image.width(), image.height());

    QPainter painter(this);
    painter.drawPixmap(target, image, source);

    int h  = height();
    int w  = width();

    int b1 = h - (m_iBand_1*4) - 25;
    int b2 = h - (m_iBand_2*4) - 25;
    int b3 = h - (m_iBand_3*4) - 25;
    int b4 = h - (m_iBand_4*4) - 25;
    int b5 = h - (m_iBand_5*4) - 25;
    int b6 = h - (m_iBand_6*4) - 25;
    int b7 = h - (m_iBand_7*4) - 25;
    int b8 = h - (m_iBand_8*4) - 25;
    int b9 = h - (m_iBand_9*4) - 25;
    int b10 = h - (m_iBand_10*4) - 25;

    int lev = h/6 - (m_iLevel*4);

    QLinearGradient grad(0, 0, w << 1, h << 1);
    grad.setColorAt(0.0f, Qt::yellow);
    grad.setColorAt(1.0f, Qt::black);

    int spacer = w/9;
    poly.putPoints(0, 13,
                   0,    h,
                   0,    b1+lev,
                   spacer*1, b2+lev,
                   spacer*2, b3+lev,
                   spacer*3, b4+lev,
                   spacer*4, b5+lev,
                   spacer*5, b6+lev,
                   spacer*6, b7+lev,
                   spacer*7, b8+lev,
                   spacer*8, b9+lev,
                   spacer*9, b10+lev,
                   w,    b10+lev,
                   w,    h     );

    QPainterPath path;
    path.moveTo(poly.at(0));
    path.addPolygon(poly);

    painter.setPen(Qt::yellow);
    painter.setBrush(grad);
    painter.drawPath((path));

    painter.setBrush(Qt::red);
    painter.drawRect(nodeRect(1));
    painter.drawRect(nodeRect(2));
    painter.drawRect(nodeRect(3));
    painter.drawRect(nodeRect(4));
    painter.drawRect(nodeRect(5));
    painter.drawRect(nodeRect(6));
    painter.drawRect(nodeRect(7));
    painter.drawRect(nodeRect(8));
    painter.drawRect(nodeRect(9));
    painter.drawRect(nodeRect(10));

    painter.end();
    QFrame::paintEvent(pPaintEvent);
}

void customGraphicEQGraph::mousePressEvent ( QMouseEvent *pMouseEvent )
{
    if (pMouseEvent->button() == Qt::LeftButton) {
        const QPoint& pos = pMouseEvent->pos();
        int iDragNode = nodeIndex(pos);
        if (iDragNode >= 0) {setCursor(Qt::SizeVerCursor);
            m_iDragNode = iDragNode;
            m_posDrag = pos;
        }
    }
    QFrame::mousePressEvent(pMouseEvent);
}


void customGraphicEQGraph::mouseMoveEvent ( QMouseEvent *pMouseEvent )
{

    dragNode(pMouseEvent->pos());
}


void customGraphicEQGraph::mouseReleaseEvent ( QMouseEvent *pMouseEvent )
{
    QFrame::mouseReleaseEvent(pMouseEvent);

    dragNode(pMouseEvent->pos());

    if (m_iDragNode >= 0) {
        m_iDragNode = -1;
        unsetCursor();
    }
}


QRect customGraphicEQGraph::nodeRect ( int iNode ) const
{
    const QPoint& pos = poly.at(iNode);
    return QRect(pos.x() - 10, pos.y() - 4, 20, 8);
}


int customGraphicEQGraph::nodeIndex ( const QPoint& pos ) const
{
    if (nodeRect(10).contains(pos))
        return 10; // Band_10

    if (nodeRect(9).contains(pos))
        return 9; // Band_9

    if (nodeRect(8).contains(pos))
        return 8; // Band_8

    if (nodeRect(7).contains(pos))
        return 7; // Band_7

    if (nodeRect(6).contains(pos))
        return 6; // Band_6

    if (nodeRect(5).contains(pos))
        return 5; // Band_5

    if (nodeRect(4).contains(pos))
        return 4; // Band_4

    if (nodeRect(3).contains(pos))
        return 3; // Band_3

    if (nodeRect(2).contains(pos))
        return 2; // Band_2

    if (nodeRect(1).contains(pos))
        return 1; //Band_1

    return -1;
}

void customGraphicEQGraph::dragNode ( const QPoint& pos )
{
    unsigned short *piLevel = NULL;
    switch (m_iDragNode) {
    case 1: // Band_1
        piLevel = &m_iBand_1;
        break;
    case 2: // Band_2
        piLevel = &m_iBand_2;
        break;
    case 3: // Band_3/
        piLevel = &m_iBand_3;
        break;
    case 4: // Band_4
        piLevel = &m_iBand_4;
        break;
    case 5: // Band_5
        piLevel = &m_iBand_5;
        break;
    case 6: // Band_6
        piLevel = &m_iBand_6;
        break;
    case 7: // Band_7
        piLevel = &m_iBand_7;
        break;
    case 8: // Band_8
        piLevel = &m_iBand_8;
    case 9: // Band_9
        piLevel = &m_iBand_9;
        break;
    case 10: // Band_10
        piLevel = &m_iBand_10;
        break;
    }

    if (piLevel) {
        int iLevel = int(*piLevel) + ((m_posDrag.y() - pos.y()) << 5) / height();
        if (iLevel < 0) iLevel = 0;
        else if (iLevel > 24) iLevel = 24;
        if (*piLevel != (unsigned short) iLevel) {
            m_posDrag = pos;
            switch (m_iDragNode) {
            case 1: // Band_1
                setBand_1(iLevel);
                break;
            case 2: // Band_2
                setBand_2(iLevel);
                break;
            case 3: // Band_3
                setBand_3(iLevel);
                break;
            case 4: // Band_4
                setBand_4(iLevel);
                break;
            case 5: // Band_5
                setBand_5(iLevel);
                break;
            case 6: // Band_6
                setBand_6(iLevel);
                break;
            case 7: // Band_7
                setBand_7(iLevel);
                break;
            case 8: // Band_8
                setBand_8(iLevel);
                break;
            case 9: // Band_9
                setBand_9(iLevel);
                break;
            case 10: // Band_10
                setBand_10(iLevel);
                break;
            }
        }
    } else if (nodeIndex(pos) >= 0) {
        setCursor(Qt::PointingHandCursor);
    } else {
        unsetCursor();
    }
}

void customGraphicEQGraph::updateSlot(  QString hex_1, QString hex_2, QString hex_3,
                                        QString hex_4, QString hex_5, QString hex_6,
                                        QString hex_7, QString hex_8, QString hex_9,
                                        QString hex_10, QString hex_11)
{
    this->hex_1 = hex_1;
    this->hex_2 = hex_2;
    this->hex_3 = hex_3;
    this->hex_4 = hex_4;
    this->hex_5 = hex_5;
    this->hex_6 = hex_6;
    this->hex_7 = hex_7;
    this->hex_8 = hex_8;
    this->hex_9 = hex_9;
    this->hex_10 = hex_10;
    this->hex_11 = hex_11;
    bool ok;
    setBand_1(this->hex_1.toShort(&ok, 16));
    setBand_2(this->hex_2.toShort(&ok, 16));
    setBand_3(this->hex_3.toShort(&ok, 16));
    setBand_4(this->hex_4.toShort(&ok, 16));
    setBand_5(this->hex_5.toShort(&ok, 16));
    setBand_6(this->hex_6.toShort(&ok, 16));
    setBand_7(this->hex_7.toShort(&ok, 16));
    setBand_8(this->hex_8.toShort(&ok, 16));
    setBand_9(this->hex_9.toShort(&ok, 16));
    setBand_10(this->hex_10.toShort(&ok, 16));
    setLevel(this->hex_11.toShort(&ok, 16));

}






