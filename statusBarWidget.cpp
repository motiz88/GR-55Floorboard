/****************************************************************************
**
** Copyright (C) 2007~2011 Colin Willcocks.
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

#include <QtGui>
#include "statusBarWidget.h"

statusBarWidget::statusBarWidget(QWidget *parent)
    : QWidget(parent)
{
	this->progressBar = new QProgressBar(this);
	this->progressBar->setTextVisible(false);
	this->progressBar->setFixedSize(80, 13);
	this->progressBar->setRange(0, 100);
	this->progressBar->setValue(0);

	this->symbol = new statusBarSymbol(this);
	this->symbol->setValue(0);

	this->label = new QLabel(this);
  this->label->setFixedWidth(150);
	this->label->setText("");

	this->dBuglabel = new QStatusBar(this);
  this->dBuglabel->setFixedWidth(750);
	this->dBuglabel->showMessage(tr(""));

	QHBoxLayout *widgetLayout = new QHBoxLayout;
	widgetLayout->setMargin(0);
	widgetLayout->addWidget(this->progressBar, Qt::AlignCenter);
	widgetLayout->addWidget(this->symbol, Qt::AlignCenter);
	widgetLayout->addWidget(this->label, Qt::AlignCenter);
	widgetLayout->addWidget(this->dBuglabel, Qt::AlignCenter);
	
	
	widgetLayout->addStretch(0);

	this->setLayout(widgetLayout);
};

void statusBarWidget::setStatusMessage(QString message)
{
	this->label->setText(message);
};

void statusBarWidget::setStatusdBugMessage(QString dBug)
{
	this->dBuglabel->showMessage(dBug, 3000);
};

void statusBarWidget::setStatusProgress(int value)
{
	this->progressBar->setValue(value);
};

void statusBarWidget::setStatusSymbol(int value)
{
	this->symbol->setValue(value);
};


