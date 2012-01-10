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

#include "renameDialog.h"
#include "SysxIO.h"

renameDialog::renameDialog(QWidget *parent)
     : QDialog(parent)
{
	SysxIO *sysxIO = SysxIO::Instance();

	QRegExp rx( QString::fromUtf8( "[\x20-\x7F\xe2\x86\x92\xe2\x86\x90]{1,16}" ) );
	QValidator *validator = new QRegExpValidator(rx, this);
	
	nameLabel = new QLabel(tr("Name:"));
	nameEdit = new QLineEdit(sysxIO->getCurrentPatchName());
	nameEdit->setValidator(validator);

	QPushButton *leftArrowButton =	new QPushButton((QChar)(0x2192));
	leftArrowButton->setMaximumWidth(20);
	leftArrowButton->setMaximumHeight(15);
	leftArrowButton->setFlat(true);
	QPushButton *rightArrowButton = new QPushButton((QChar)(0x2190));
	rightArrowButton->setMaximumWidth(20);
	rightArrowButton->setMaximumHeight(15);
	rightArrowButton->setFlat(true);

	charLabel = new QLabel(tr("Insert :"));
	charLabel->setAlignment(Qt::AlignRight|Qt::AlignBottom);

	connect(rightArrowButton, SIGNAL(clicked()), this, SLOT(addRightArrow()));
	connect(leftArrowButton, SIGNAL(clicked()), this, SLOT(addLeftArrow()));

	QPushButton *cancelButton =	new QPushButton(tr("Cancel"));
	QPushButton *okButton = new QPushButton(tr("Apply"));

	connect(okButton, SIGNAL(clicked()), this, SLOT(emitValue()));
	connect(cancelButton, SIGNAL(clicked()), this, SLOT(close()));

	QGroupBox *renameGroup = new QGroupBox(tr("Rename patch"));
	
	QHBoxLayout *nameEditLayout = new QHBoxLayout;
	nameEditLayout->addWidget(nameEdit);

	QHBoxLayout *arrowButtonLayout = new QHBoxLayout;
	arrowButtonLayout->addStretch(1);
	//arrowButtonLayout->addWidget(charLabel);
	//arrowButtonLayout->addWidget(rightArrowButton);
	//arrowButtonLayout->addWidget(leftArrowButton);

	QHBoxLayout *buttonsLayout = new QHBoxLayout;
	buttonsLayout->addStretch(1);
	buttonsLayout->addWidget(okButton);
	buttonsLayout->addWidget(cancelButton);

	QHBoxLayout *nameLayout = new QHBoxLayout;
	nameLayout->addWidget(nameLabel);
	nameLayout->addLayout(nameEditLayout);

	QVBoxLayout *renameLayout = new QVBoxLayout;
	renameLayout->addLayout(nameLayout);
	renameLayout->addLayout(arrowButtonLayout);
	renameGroup->setLayout(renameLayout);

	QVBoxLayout *mainLayout = new QVBoxLayout;
	mainLayout->addWidget(renameGroup);
	mainLayout->addLayout(buttonsLayout);
	setLayout(mainLayout);

	this->setMinimumWidth(250);
};


void renameDialog::addRightArrow()
{
	nameEdit->insert((QChar)(0x2190));
	nameEdit->setFocus();

};

void renameDialog::addLeftArrow()
{
	nameEdit->insert((QChar)(0x2192));
	nameEdit->setFocus();
};

void renameDialog::emitValue()
{
	emit nameChanged(nameEdit->text());
	this->accept();
};
