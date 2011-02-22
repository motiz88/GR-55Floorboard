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

#include <QFileInfo>
#include <QFile>
#include <QDir>
#include <QRegExp>
#include "SysxIO.h"
#include "sysxWriter.h"
#include "Preferences.h"
#include "initPatchListMenu.h"

initPatchListMenu::initPatchListMenu(QRect geometry, QWidget *parent)
    : QWidget(parent)
{
	this->available = false;
	setInitPatchComboBox(geometry);
};

QDir initPatchListMenu::getInitPatchDir()
{
	Preferences *preferences = Preferences::Instance();
	QDir preferencesDir = QDir(preferences->getPreferences("General", "Files", "dir").remove(QRegExp("$(/)")));
	QString initPatchesDirName = "Init Patches";
	QString symlinkExstention;

	#ifdef Q_OS_UNIX
		symlinkExstention = "";
	#endif

	#ifdef Q_OS_WIN
		symlinkExstention = ".lnk";
	#endif
	
	QDir initPatchesDir; /* The "Init Pathces" directory. */
	if ( QFileInfo( preferencesDir, initPatchesDirName + symlinkExstention ).exists() &&
		 QFileInfo( preferencesDir, initPatchesDirName + symlinkExstention ).canonicalPath() == 
		 QFileInfo( preferencesDir, initPatchesDirName + symlinkExstention ).symLinkTarget() )
	{	/* If the "Init Pathces" directory is a symlink and lives in the user sellected patch directory. */
		initPatchesDir.setPath(QFileInfo( preferencesDir, initPatchesDirName + symlinkExstention ).symLinkTarget());
	}
	else if ( QFileInfo( preferencesDir, initPatchesDirName ).exists() )
	{	/* If the "Init Pathces" directory lives in the user sellected patch directory. */
		initPatchesDir.setPath(QFileInfo( preferencesDir, initPatchesDirName ).absoluteFilePath() );
	}
	else if ( QFileInfo( initPatchesDirName ).exists() )
	{	/* If the "Init Pathces" directory lives in the application directory. */
		initPatchesDir.setPath(QFileInfo( initPatchesDirName ).absoluteFilePath());
		if( QFileInfo( preferencesDir, initPatchesDirName ).absolutePath() != initPatchesDir.absolutePath() && 
			preferencesDir.exists() )
		{	/* Add a symlink to the user selected patch directory (if it is set and exists). */
			QString symlinkPath = QFileInfo( preferencesDir, initPatchesDirName + symlinkExstention ).absoluteFilePath();
			QFile::link(initPatchesDir.absolutePath(), symlinkPath);
		};
	};

	return initPatchesDir;
};

void initPatchListMenu::setInitPatchComboBox(QRect geometry)
{
	QDir initPatchesDir = getInitPatchDir();
	if(initPatchesDir.exists())
	{	/* If the "Init Pathces" directory exists. */
		QStringList filters;
		filters << "*.syx" << "*.syx2";
		QStringList initPatchesList = initPatchesDir.entryList(filters);

		if (initPatchesList.size() != 0)
		{	/* If it has "Init Pathces" in it. */
			this->initPatchComboBox = new customComboBox(this);
			this->available = true;
			this->initPatchComboBox->setObjectName("smallcombo");
			initPatchComboBox->addItem(tr("[ INIT Patches ]")); 
			
			int itemcount;
			for(itemcount=0; itemcount<initPatchesList.size(); itemcount++)
			{	/* Filling the combobox with the patches. */
				QString path = initPatchesDir.absolutePath().append("/").append(initPatchesList.at(itemcount));
				this->initPatches.append(path);
				QString item = initPatchesList.at(itemcount);	// Start formatting the item name.
				item.remove(QRegExp("^[0-9_]+"));
				item.remove(QRegExp(".{1}(syx|syx2)"));
				if(!item.contains("INIT_"))
				{
					item.prepend(tr("(My INIT) "));
				};
				item.remove("INIT_");
				item.replace("_", " ");
				item.replace("-!-", "/");
				initPatchComboBox->addItem(item);				// Finished formatting the item name.
			};	

			initPatchComboBox->setGeometry(geometry);
			initPatchComboBox->setEditable(false);
			initPatchComboBox->setFrame(false);
			initPatchComboBox->setMaxVisibleItems(itemcount + 1); // +1 for "[ INIT Patches ]" entry.

			QObject::connect(initPatchComboBox, SIGNAL(currentIndexChanged(int)),
					this, SLOT(loadInitPatch(int)));
			QObject::connect(this, SIGNAL(updateSignal()),
				this->parent()->parent(), SIGNAL(updateSignal()));
		};
	};
};


void initPatchListMenu::setIndex(int index)
{
	if(this->available)
	{
		this->initPatchComboBox->setCurrentIndex(index);
	};
};

void initPatchListMenu::loadInitPatch(int index)
{
	if(index > 0)
	{
		QString fileName = this->initPatches.at(index - 1 );
		if (!fileName.isEmpty())	
		{
			sysxWriter file;
			file.setFile(fileName);  
			if(file.readFile())
			{	
				// DO SOMETHING AFTER READING THE FILE (UPDATE THE GUI)
				SysxIO *sysxIO = SysxIO::Instance();
				QString area = "Structure";
				sysxIO->setFileSource(area, file.getFileSource());
				sysxIO->setFileName(tr("init patch"));
				sysxIO->setSyncStatus(false);
				sysxIO->setDevice(false);
				emit updateSignal();
				if(sysxIO->isConnected())
				{sysxIO->writeToBuffer(); };
			};
		};
	};
};
