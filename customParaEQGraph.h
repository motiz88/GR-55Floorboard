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

#ifndef CUSTOMPARAEQGRAPH_H
#define CUSTOMPARAEQGRAPH_H

#include <QFrame>


class customParaEQGraph : public QFrame
{
    Q_OBJECT

public:
    customParaEQGraph(QWidget *parent = 0);
    ~customParaEQGraph();
    unsigned short LowCut() const;
    unsigned short LowGain() const;
    unsigned short LowMidFreq() const;
    unsigned short LowMidQ() const;
    unsigned short LowMidGain() const;
    unsigned short HighMidFreq() const;
    unsigned short HighMidQ() const;
    unsigned short HighMidGain() const;
    unsigned short HighGain() const;
    unsigned short HighCut() const;
    unsigned short Level() const;

public slots:
    void setLowCut(unsigned short iLowCut);
    void setLowGain(unsigned short iLowGain);
    void setLowMidFreq(unsigned short iLowMidFreq);
    void setLowMidQ(unsigned short iLowMidQ);
    void setLowMidGain(unsigned short iLowMidGain);
    void setHighMidFreq(unsigned short iHighMidFreq);
    void setHighMidQ(unsigned short iHighMidQ);
    void setHighMidGain(unsigned short iHighMidGain);
    void setHighGain(unsigned short iHighGain);
    void setHighCut(unsigned short iHighCut);
    void setLevel(unsigned short iLevel);
    void updateSlot(  QString hex_1, QString hex_2, QString hex_3,
                      QString hex_4, QString hex_5, QString hex_6,
                      QString hex_7, QString hex_8, QString hex_9,
                      QString hex_10, QString hex_11);

signals:
    void LowCutChanged(unsigned short iLowCut);
    void LowGainChanged(unsigned short iLowGain);
    void LowMidFreqChanged(unsigned short iLowMidFreq);
    void LowMidQChanged(unsigned short iLowMidQ);
    void LowMidGainChanged(unsigned short iLowMidGain);
    void HighMidFreqChanged(unsigned short iHighMidFreq);
    void HighMidQChanged(unsigned short iHighMidQ);
    void HighMidGainChanged(unsigned short iHighMidGain);
    void HighGainChanged(unsigned short iHighGain);
    void HighCutChanged(unsigned short iHighCut);
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
    QString hex_7;
    QString hex_8;
    QString hex_9;
    QString hex_10;
    QString hex_11;
    unsigned short m_iLowCut;
    unsigned short m_iLowGain;
    unsigned short m_iLowMidFreq;
    unsigned short m_iLowMidQ;
    unsigned short m_iLowMidGain;
    unsigned short m_iHighMidFreq;
    unsigned short m_iHighMidQ;
    unsigned short m_iHighMidGain;
    unsigned short m_iHighGain;
    unsigned short m_iHighCut;
    unsigned short m_iLevel;

    QPoint m_posDrag;
    //QPolygon m_poly;
    QPolygon loMid;
    int    m_iDragNode;
};

#endif	//customParaEQGraph_H


