/****************************************************************************
**
** Copyright (C) 2007~2015 Colin Willcocks.
** Copyright (C) 2005~2007 Uco Mesdag. 
** All rights reserved.
** This file is part of "GR-55 FloorBoard".
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

#ifndef CUSTOMCONTROLLABEL_H
#define CUSTOMCONTROLLABEL_H

#include <QWidget>
#include <QtWidgets>

class customControlLabel : public QWidget
{
    Q_OBJECT

public:
    customControlLabel(QWidget *parent = 0);
	void setUpperCase(bool active);
	void setAlignment(Qt::Alignment flag);
	void setButton(bool button);
	void setImage(QString imagePath);
	void setOffset(int imageNr);
	int getLabelWidth();

protected:
	void paintEvent(QPaintEvent *event);
	void mousePressEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
	void enterEvent(QEvent *event);
	void leaveEvent( QEvent *event);

public slots:
	void setText(QString text);

signals:
	void mouseReleased();
	void mousePressed();

private:
	void setSize();
	QLabel* label;
	QPixmap image;
	bool isImage;
	bool uppercase;
	bool button;
	int lenght;
	int offset;
	int imageHeight;
	int labelWidth;
};

#endif // CUSTOMCONTROLLABEL_H
