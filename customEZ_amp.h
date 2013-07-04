/****************************************************************************
**
** Copyright (C) 2007~2013 Colin Willcocks.
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

#ifndef CUSTOMEZ_AMP_H
#define CUSTOMEZ_AMP_H

#include <QFrame>


class customEZ_amp : public QFrame
{
    Q_OBJECT

public:
    customEZ_amp(QWidget *parent = 0);
    ~customEZ_amp();
    int Y_axis() const;
    int X_axis() const;

public slots:
    void setY_axis(int iy_axis);
    void setX_axis(int ix_axis);
    void updateSlot(  QString hex_1, QString hex_2);

signals:
    void y_axisChanged(int iy_axis);
    void x_axisChanged(int ix_axis);
    void updateSignal();

protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *pMouseEvent);
    void mouseMoveEvent(QMouseEvent *pMouseEvent);
    void mouseReleaseEvent(QMouseEvent *pMouseEvent);
    QRect nodeRect(int iNode) const;
    int nodeIndex(const QPoint& pos) const;
    void dragNode(const QPoint& pos);

private:
    void sync();
    QString hex1;
    QString hex2;
    QString hex_1;
    QString hex_2;
    QString hex_3;
    QString hex_4;
    int m_iy_axis;
    int m_ix_axis;
    int m_iLevel;
    int m_iMidQ;
    int m_iHighGain;

    QPoint m_posDrag;
    QPolygon poly;
    int    m_iDragNode;
};

#endif	//customEZ_amp_H


