/****************************************************************************
**
** Copyright (C) 2007~2012 Colin Willcocks.
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

#ifndef INITPATCHLISTMENU_H 
#define INITPATCHLISTMENU_H

#include <QtGui>
#include <QWidget>
#include <QTimer>
#include "customButton.h"
#include "customComboBox.h"

class initPatchListMenu : public QWidget
{
	Q_OBJECT

public:
	initPatchListMenu(QRect geometry, QWidget *parent = 0);

public slots:
	void loadInitPatch(int index);
    void highLightInitPatch(int index);
	void setIndex(int index);

signals:
	void currentIndexChanged(int index);
	void updateSignal();


private:
	customComboBox *initPatchComboBox;
	bool available;

	void setInitPatchComboBox(QRect geometry);
	QDir getInitPatchDir();
	QList<QString> initPatches;

};

#endif // INITPATCHLISTMENU_H
