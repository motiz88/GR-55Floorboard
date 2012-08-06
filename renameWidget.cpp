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

#include <QRegExp>
#include "renameWidget.h"
#include "renameDialog.h"
#include "SysxIO.h"
#include "globalVariables.h"

renameWidget::renameWidget(QWidget *parent)
    : QWidget(parent)
{
	QObject::connect(this, SIGNAL(nameChanged(QString)), 
		this->parentWidget(), SLOT(setPatchDisplay(QString)));
}

void renameWidget::mouseReleaseEvent(QMouseEvent *event)
{
	if ( event->button() == Qt::LeftButton )
	{	
		renameDialog *dialog = new renameDialog;
		connect(dialog, SIGNAL(nameChanged(QString)), this, SLOT(updateName(QString)));
		dialog->exec();
	};
}

void renameWidget::updateName(QString name)
{
	SysxIO *sysxIO = SysxIO::Instance();

	QList<QString> hexData;
	for(int i=0; i<16; ++i)
	{
		if(i<name.size())
		{
				char asciiChar = name.at(i).toAscii();
				int asciiValue = (int)asciiChar;
				QString nameHexValue = QString::number(asciiValue, 16).toUpper();
				if(nameHexValue.length() < 2) nameHexValue.prepend("0");
				hexData.append(nameHexValue);
		}
		else
		{
			hexData.append("20");
		};
	};
        sysxIO->setFileSource("Structure", "00", "00", "01", hexData);
	
	
	sysxIO->setCurrentPatchName(name);

	emit nameChanged(name);
}
