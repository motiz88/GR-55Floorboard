/****************************************************************************
**
** Copyright (C) 2007~2012 Colin Willcocks.
** Copyright (C) 2005~2007 Uco Mesdag.
** Copyright (C) 2005-2009, rncbc aka Rui Nuno Capela.
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

#ifndef CUSTOMGRAPHICEQGRAPH_H
#define CUSTOMGRAPHICEQGRAPH_H

#include <QFrame>


class customGraphicEQGraph : public QFrame
{
	Q_OBJECT

public:
        customGraphicEQGraph(QWidget *parent = 0);
        ~customGraphicEQGraph();
                unsigned short Band_1() const;
                unsigned short Band_2() const;
                unsigned short Band_3() const;
                unsigned short Band_4() const;
                unsigned short Band_5() const;
                unsigned short Band_6() const;
                unsigned short Band_7() const;
                unsigned short Band_8() const;
                unsigned short Band_9() const;
                unsigned short Band_10() const;
                unsigned short Level() const;

public slots:
        void setBand_1(unsigned short iBand_1);
        void setBand_2(unsigned short iBand_2);
        void setBand_3(unsigned short iBand_3);
        void setBand_4(unsigned short iBand_4);
        void setBand_5(unsigned short iBand_5);
        void setBand_6(unsigned short iBand_6);
        void setBand_7(unsigned short iBand_7);
        void setBand_8(unsigned short iBand_8);
        void setBand_9(unsigned short iBand_9);
        void setBand_10(unsigned short iBand_10);
        void setLevel(unsigned short iLevel);
        void updateSlot(  QString hex_1, QString hex_2, QString hex_3,
                          QString hex_4, QString hex_5, QString hex_6,
                          QString hex_7, QString hex_8, QString hex_9,
                          QString hex_10, QString hex_11);

signals:
        void Band_1Changed(unsigned short iBand_1);
        void Band_2Changed(unsigned short iBand_2);
        void Band_3Changed(unsigned short iBand_3);
        void Band_4Changed(unsigned short iBand_4);
        void Band_5Changed(unsigned short iBand_5);
        void Band_6Changed(unsigned short iBand_6);
        void Band_7Changed(unsigned short iBand_7);
        void Band_8Changed(unsigned short iBand_8);
        void Band_9Changed(unsigned short iBand_9);
        void Band_10Changed(unsigned short iBand_10);
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
        unsigned short m_iBand_1;
        unsigned short m_iBand_2;
        unsigned short m_iBand_3;
        unsigned short m_iBand_4;
        unsigned short m_iBand_5;
        unsigned short m_iBand_6;
        unsigned short m_iBand_7;
        unsigned short m_iBand_8;
        unsigned short m_iBand_9;
        unsigned short m_iBand_10;
        unsigned short m_iLevel;
	QPoint m_posDrag;
        QPolygon poly;
        int m_iDragNode;

};

#endif	//CUSTOMGRAPH_H


