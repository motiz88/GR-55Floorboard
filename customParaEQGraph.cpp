/****************************************************************************
**
** Copyright (C) 2007~2011 Colin Willcocks.
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

#include "customParaEQGraph.h"
//#include <QMessageBox>
#include <QPainter>
#include <QMouseEvent>
#include <QGraphicsPathItem>

customParaEQGraph::customParaEQGraph (QWidget *parent) //: /*m_poly(5), */loMid(11), m_iDragNode(-1)
{
	QFrame::setFrameShape(QFrame::Panel);
        QFrame::setFrameShadow(QFrame::Sunken);

}

customParaEQGraph::~customParaEQGraph (void)
{
}

void customParaEQGraph::setLowCut ( unsigned short iLowCut )
{
     if (iLowCut > 9) iLowCut = 9;
        if (m_iLowCut != iLowCut) {
                m_iLowCut  = iLowCut;
                update();
                emit LowCutChanged(LowCut());
        };
}

unsigned short customParaEQGraph::LowCut (void) const
{
        return m_iLowCut;
}


void customParaEQGraph::setLowGain ( unsigned short iLowGain )
{
     if (iLowGain > 40) iLowGain = 40;
        if (m_iLowGain != iLowGain) {
                m_iLowGain  = iLowGain;
                update();
                emit LowGainChanged(LowGain());
        };
}

unsigned short customParaEQGraph::LowGain (void) const
{
        return m_iLowGain;
}


void customParaEQGraph::setLowMidFreq ( unsigned short iLowMidFreq )
{
     if (iLowMidFreq > 27) iLowMidFreq = 27;
        if (m_iLowMidFreq != iLowMidFreq) {
                m_iLowMidFreq  = iLowMidFreq;
                update();
                emit LowMidFreqChanged(LowMidFreq());
        };
}

unsigned short customParaEQGraph::LowMidFreq (void) const
{
        return m_iLowMidFreq;
}


void customParaEQGraph::setLowMidQ ( unsigned short iLowMidQ )
{
    if (iLowMidQ > 5) iLowMidQ = 5;
        if (m_iLowMidQ != iLowMidQ) {
                m_iLowMidQ  = iLowMidQ;
                update();
                emit LowMidQChanged(LowMidQ());
        }
}

unsigned short customParaEQGraph::LowMidQ (void) const
{
        return m_iLowMidQ;
}


void customParaEQGraph::setLowMidGain ( unsigned short iLowMidGain )
{
    if (iLowMidGain > 40) iLowMidGain = 40;
        if (m_iLowMidGain != iLowMidGain) {
                m_iLowMidGain  = iLowMidGain;
                update();
                emit LowMidGainChanged(LowMidGain());
        }
}

unsigned short customParaEQGraph::LowMidGain (void) const
{
        return m_iLowMidGain;
}


void customParaEQGraph::setHighMidFreq ( unsigned short iHighMidFreq )
{
    if (iHighMidFreq > 27) iHighMidFreq = 27;
        if (m_iHighMidFreq != iHighMidFreq) {
                m_iHighMidFreq  = iHighMidFreq;
                update();
                emit HighMidFreqChanged(HighMidFreq());
        }
}

unsigned short customParaEQGraph::HighMidFreq (void) const
{
        return m_iHighMidFreq;
}

void customParaEQGraph::setHighMidQ ( unsigned short iHighMidQ )
{
    if (iHighMidQ > 5) iHighMidQ = 5;
        if (m_iHighMidQ != iHighMidQ) {
                m_iHighMidQ  = iHighMidQ;
                update();
                emit HighMidQChanged(HighMidQ());
        }
}

unsigned short customParaEQGraph::HighMidQ (void) const
{
        return m_iHighMidQ;
}


void customParaEQGraph::setHighMidGain ( unsigned short iHighMidGain )
{
    if (iHighMidGain > 40) iHighMidGain = 40;
        if (m_iHighMidGain != iHighMidGain) {
                m_iHighMidGain  = iHighMidGain;
                update();
                emit HighMidGainChanged(HighMidGain());
        }
}

unsigned short customParaEQGraph::HighMidGain (void) const
{
        return m_iHighMidGain;
}

void customParaEQGraph::setHighGain ( unsigned short iHighGain )
{
    if (iHighGain > 40) iHighGain = 40;
        if (m_iHighGain != iHighGain) {
                m_iHighGain  = iHighGain;
                update();
                emit HighGainChanged(HighGain());
        };
}

unsigned short customParaEQGraph::HighGain (void) const
{
        return m_iHighGain;
}

void customParaEQGraph::setHighCut ( unsigned short iHighCut )
{
    if (iHighCut > 9) iHighCut = 9;
        if (m_iHighCut != iHighCut) {
                m_iHighCut  = iHighCut;
                update();
                emit HighCutChanged(HighCut());
        };
}

unsigned short customParaEQGraph::HighCut (void) const
{
        return m_iHighCut;
}

void customParaEQGraph::setLevel ( unsigned short iLevel )
{
    if (iLevel > 40) iLevel = 40;
        if (m_iLevel != iLevel) {
                m_iLevel  = iLevel;
                update();
                emit LevelChanged(Level());
        };
}

unsigned short customParaEQGraph::Level (void) const
{
        return m_iLevel;
}


void customParaEQGraph::paintEvent ( QPaintEvent *pPaintEvent )
{
    QPixmap image = QPixmap(":images/EQ_graph.png");
    QRectF target(0.0, 0.0, image.width()*85/100, image.height()*43/100);
    QRectF source(0.0, 0.0, image.width(), image.height());

    QPainter painter(this);
    painter.drawPixmap(target, image, source);

    int h  = height();
    int w  = width();

    int lc  = (m_iLowCut*32);
    int lg  = h - (m_iLowGain*2) - 25;

    int lmf = (m_iLowMidFreq*20) + 5;
    int lmq = h*100/82-(m_iLowMidQ*40);
    int lmg = h - (m_iLowMidGain)-40;

    int hmf = (m_iHighMidFreq*20) + 5;
    int hmq = h*100/82-(m_iHighMidQ*40);
    int hmg = h - (m_iHighMidGain)-40;

    int hg  = h - (m_iHighGain*2) - 25;
    int hc  = w/2 + (m_iHighCut*32)+10;

    int lev = h/10 - (m_iLevel*2);

    //if (hmf+hmq > hc) hmf = hc - hmq;
    //if (lmf+lmq > hmf-hmq) lmf = hmf - hmq - lmq ;
    //if (lc > lmf-lmq) lmf = lc + lmq;


  /*  m_poly.putPoints(0, 5,
            lc-50,   h+lev+63,
            lc,      lg+lev,

            //lmf-lmq, lmg+lev,
            //lmf,     ((h*100/82)-(m_iLowMidGain*5))+lev,
            //lmf+lmq, lmg+lev,
            w/2,       (h*50/78)+lev,
            //hmf-hmq, hmg+lev,
            //hmf,     ((h*100/82)-(m_iHighMidGain*5))+lev,
            //hmf+hmq, hmg+lev,

            hc,      hg+lev,
            hc+50,   h+lev+63);

    QPainterPath path;
    path.setFillRule(Qt::WindingFill);
    path.addPolygon(m_poly);
    //path.moveTo(m_poly.at(0));
    //path.cubicTo(m_poly.at(0), m_poly.at(1), m_poly.at(2));
    //path.cubicTo(m_poly.at(2), m_poly.at(3), m_poly.at(4));
    //path.lineTo(m_poly.at(1));
    //path.quadTo(m_poly.at(1), m_poly.at(2));
    //path.cubicTo(m_poly.at(3), m_poly.at(4), m_poly.at(5));
    //path.cubicTo(m_poly.at(4), m_poly.at(7), m_poly.at(8));
    //path.lineTo(m_poly.at(9));
    //path.moveTo(m_poly.at(0));
    //path.lineTo(m_poly.at(1));
    //path.quadTo(m_poly.at(1), m_poly.at(2));
    //path.cubicTo(m_poly.at(5), m_poly.at(6), m_poly.at(7));
    //path.quadTo(m_poly.at(7), m_poly.at(8));
    //path.lineTo(m_poly.at(9));

    //path.addText(m_poly.at(1), QFont("Arial"), QString("LowCut") );

    const QPalette& pal = palette();
    painter.fillRect(0, 0, w, h, pal.dark().color());

    painter.setPen(Qt::yellow);
*/
    QLinearGradient grad(0, 0, w << 1, h << 1);
    grad.setColorAt(0.0f, Qt::yellow);
    grad.setColorAt(1.0f, Qt::black);

   /* painter.setBrush(grad);
    //painter.drawPath(path);*/

    loMid.putPoints(0, 11,
            lc-50,   h+lev+63,
            lc,      lg+lev,

            lmf-lmq, lmg+lev,
            lmf,     ((h*100/82)-(m_iLowMidGain*5))+lev,
            lmf+lmq, lmg+lev,
                w/2,       (h*50/78)+lev,
            hmf-hmq, hmg+lev,
            hmf,     ((h*100/82)-(m_iHighMidGain*5))+lev,
            hmf+hmq, hmg+lev,

            hc,      hg+lev,
            hc+50,   h+lev+63);

    QPainterPath loHiCut;
    loHiCut.moveTo(loMid.at(0));
    loHiCut.lineTo(loMid.at(1));
    //loHiCut.cubicTo(loMid.at(0), loMid.at(1), loMid.at(5));
    loHiCut.quadTo(loMid.at(1), loMid.at(5));
    loHiCut.quadTo(loMid.at(5), loMid.at(9));
    //loHiCut.cubicTo(loMid.at(5), loMid.at(9), loMid.at(10));
    loHiCut.lineTo(loMid.at(10));

    QPainterPath para_1;
    para_1.moveTo(loMid.at(2));
    //para_1.lineTo(loMid.at(2));
    para_1.cubicTo(loMid.at(2), loMid.at(3), loMid.at(4));
    //para_1.lineTo(w, h+lev);
    //para_1.lineTo(loMid.at(9));

    QPainterPath para_2;
    para_2.moveTo(loMid.at(6));
    //para_2.lineTo(loMid.at(6));
    para_2.cubicTo(loMid.at(6), loMid.at(7), loMid.at(8));
    //para_2.lineTo(loMid.at(10));

    //loHiCut.setFillRule(Qt::WindingFill);
    //loHiCut.addText(loMid.at(1), QFont("Arial"), QString("LowCut") );
    //const QPalette& pal = palette();
    //painter.fillRect(0, 0, w, h, pal.dark().color());
 //painter.setCompositionMode(QPainter::CompositionMode_DestinationOut);
    painter.setPen(Qt::yellow);

    QPainterPath graph = (loHiCut.subtracted(para_1));
    painter.setBrush(grad);
    //painter.drawPath(loHiCut);
    painter.drawPath((graph));
    /*painter.setBrush(Qt::red);
    painter.drawRect(nodeRect(1));
    painter.setBrush(Qt::green);
    painter.drawRect(nodeRect(2));
    painter.setBrush(Qt::red);
    painter.drawRect(nodeRect(3));
    painter.setBrush(Qt::green);
    painter.drawRect(nodeRect(4));
    painter.drawRect(nodeRect(5));
    painter.setBrush(Qt::red);
    painter.drawRect(nodeRect(6));
    painter.setBrush(Qt::green);
    painter.drawRect(nodeRect(7));
    painter.setBrush(Qt::red);
    painter.drawRect(nodeRect(8));*/



    painter.end();

    QFrame::paintEvent(pPaintEvent);
}


// Mouse interaction.
void customParaEQGraph::mousePressEvent ( QMouseEvent *pMouseEvent )
{
   /* if (pMouseEvent->button() == Qt::LeftButton) {
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

    QFrame::mousePressEvent(pMouseEvent);*/

}


void customParaEQGraph::mouseMoveEvent ( QMouseEvent *pMouseEvent )
{

    //dragNode(pMouseEvent->pos());
}


void customParaEQGraph::mouseReleaseEvent ( QMouseEvent *pMouseEvent )
{
  /*  QFrame::mouseReleaseEvent(pMouseEvent);

        dragNode(pMouseEvent->pos());

        if (m_iDragNode >= 0) {
                m_iDragNode = -1;
                unsetCursor();
        }*/
}



// Draw rectangular point.
QRect customParaEQGraph::nodeRect ( int iNode ) const
{
       // const QPoint& pos = m_poly.at(iNode);
       // return QRect(pos.x() - 4, pos.y() - 4, 8, 8);
}


int customParaEQGraph::nodeIndex ( const QPoint& pos ) const
{
     /*   if (nodeRect(8).contains(pos))
            return 8; // HighCut+HighGain

        if (nodeRect(7).contains(pos))
            return 7; // HighMidQ

        if (nodeRect(6).contains(pos))
                return 6; // HighMidFreq+HighMidGain

        if (nodeRect(5).contains(pos))
                return 5; // HighMidQ

        if (nodeRect(4).contains(pos))
                return 4; // LowMidQ

        if (nodeRect(3).contains(pos))
                return 3; // LowMidFreq/LowMidGain

        if (nodeRect(2).contains(pos))
                return 2; // LowMidQ

        if (nodeRect(1).contains(pos))
                return 1; //LowCut+LowGain

        return -1;*/
}

void customParaEQGraph::dragNode ( const QPoint& pos )
{
 /*       static unsigned short m_iLevel0 = 0; // Dummy!
        unsigned short *piRate  = NULL;
        unsigned short *piLevel = NULL;
        switch (m_iDragNode) {
        case 1: // LowCut+LowGain
                piRate  = &m_iLowCut;
                piLevel = &m_iLowGain;
                break;
        case 2: // LowMidQ
                piRate  = &m_iLowMidQ;
                piLevel = &m_iLevel0;
                break;
        case 3: // LowMidFreq/LowMidGain
                piRate  = &m_iLowMidFreq;
                piLevel = &m_iLowMidGain;
                break;
        case 4: // LowMidQ
                piRate  = &m_iLowMidQ;
                piLevel = &m_iLevel0;
                break;
        case 5: // HighMidQ
                piRate  = &m_iHighMidQ;
                piLevel = &m_iLevel0;
                break;
        case 6: // HighMidFreq+HighMidGain
                piRate  = &m_iHighMidFreq;
                piLevel = &m_iHighMidGain;
                break;
        case 7: // HighMidQ
                piRate  = &m_iHighMidQ;
                piLevel = &m_iLevel0;
                break;
        case 8: // HighCut+HighGain
                piRate  = &m_iHighCut;
                piLevel = &m_iHighGain;
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
                        case 1: // LowCut/LowGain
                                setLowCut(iRate);
                                setLowGain(iLevel);
                                break;
                        case 2: // LowCut
                                setLowMidQ(iRate);
                                break;
                        case 3: // LowMidFreq/LowMidGain
                                setLowMidFreq(iRate);
                                setLowMidGain(iLevel);
                                break;
                        case 4: // LowMidQ
                                setLowMidQ(iRate);
                                break;
                        case 5: // HighMidQ
                                setHighMidQ(iRate);
                                break;
                        case 6: // HighMidFreq/HighMidGain
                                setHighMidFreq(iRate);
                                setHighMidGain(iLevel);
                                break;
                        case 7: // HighMidQ
                                setHighMidQ(iRate);
                                break;
                        case 8: // HighCut/HighGain
                                setHighCut(iRate);
                                setHighGain(iLevel);
                                break;
                        }
                }
        } else if (nodeIndex(pos) >= 0) {
                setCursor(Qt::PointingHandCursor);
        } else {
                unsetCursor();
        }*/
}

void customParaEQGraph::updateSlot(  QString hex_1, QString hex_2, QString hex_3,
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
    setLowCut(this->hex_1.toShort(&ok, 16));
    setLowGain(this->hex_2.toShort(&ok, 16));
    setLowMidFreq(this->hex_3.toShort(&ok, 16));
    setLowMidQ(this->hex_4.toShort(&ok, 16));
    setLowMidGain(this->hex_5.toShort(&ok, 16));
    setHighMidFreq(this->hex_6.toShort(&ok, 16));
    setHighMidQ(this->hex_7.toShort(&ok, 16));
    setHighMidGain(this->hex_8.toShort(&ok, 16));
    setHighGain(this->hex_9.toShort(&ok, 16));
    setHighCut(this->hex_10.toShort(&ok, 16));
    setLevel(this->hex_11.toShort(&ok, 16));

}






