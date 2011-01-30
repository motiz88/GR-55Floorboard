/****************************************************************************
**
** Copyright (C) 2007~2010 Colin Willcocks.
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

#ifndef STATUSBARWIDGET_H
#define STATUSBARWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QProgressBar>
#include <QStatusBar>
#include "statusBarSymbol.h"

class statusBarWidget : public QWidget
{
    Q_OBJECT

public:
    statusBarWidget(QWidget *parent = 0);

public slots:
	void setStatusMessage(QString message);
	void setStatusdBugMessage(QString dBug);
	void setStatusProgress(int value);
	void setStatusSymbol(int value);

private:
	QProgressBar *progressBar;
	statusBarSymbol *symbol;
	QLabel *label;
	QStatusBar *dBuglabel;
};

#endif // STATUSBARWIDGET_H
