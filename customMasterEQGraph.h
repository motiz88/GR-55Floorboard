/****************************************************************************
**
** Copyright (C) 2007~2013 Colin Willcocks.
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

#ifndef CUSTOMMASTEREQGRAPH_H
#define CUSTOMMASTEREQGRAPH_H

#include <QFrame>


class customMasterEQGraph : public QFrame
{
    Q_OBJECT

public:
    customMasterEQGraph(QWidget *parent = 0);
    ~customMasterEQGraph();
    unsigned short LowGain() const;
    unsigned short MidFreq() const;
    unsigned short MidQ() const;
    unsigned short MidGain() const;
    unsigned short HighGain() const;
    unsigned short Level() const;

public slots:
    void setLowGain(unsigned short iLowGain);
    void setMidFreq(unsigned short iMidFreq);
    void setMidQ(unsigned short iMidQ);
    void setMidGain(unsigned short iMidGain);
    void setHighGain(unsigned short iHighGain);
    void setLevel(unsigned short iLevel);
    void updateSlot(  QString hex_1, QString hex_2, QString hex_3,
                      QString hex_4, QString hex_5, QString hex_6 );

signals:
    void LowGainChanged(unsigned short iLowGain);
    void MidFreqChanged(unsigned short iMidFreq);
    void MidQChanged(unsigned short iMidQ);
    void MidGainChanged(unsigned short iMidGain);
    void HighGainChanged(unsigned short iHighGain);
    void LevelChanged(unsigned short iLevel);

protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *pMouseEvent);
    void mouseMoveEvent(QMouseEvent *pMouseEvent);
    void mouseReleaseEvent(QMouseEvent *pMouseEvent);
    QRect nodeRect(int iNode) const;
    int nodeIndex(const QPoint& pos) const;
    void dragNode(const QPoint& pos);

private:
    QString hex1;
    QString hex2;
    QString hex_1;
    QString hex_2;
    QString hex_3;
    QString hex_4;
    QString hex_5;
    QString hex_6;
    unsigned short m_iLowGain;
    unsigned short m_iMidFreq;
    unsigned short m_iMidQ;
    unsigned short m_iMidGain;
    unsigned short m_iHighGain;
    unsigned short m_iLevel;

    QPoint m_posDrag;

    QPolygon poly;
    int    m_iDragNode;

};

#endif	//customMasterEQGraph_H


