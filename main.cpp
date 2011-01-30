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

#include <QApplication>
#include "mainWindow.h"
#include "Preferences.h"
#include "MidiTable.h"
#include "SysxIO.h"
#include "sysxWriter.h"
#include "customSplashScreen.h"

int main(int argc, char **argv)
{
	QApplication app(argc, argv);

	 Preferences *preferences = Preferences::Instance(); // Load the preferences.
  QString lang = preferences->getPreferences("Language", "Locale", "select");
	bool ok;
	int choice = lang.toInt(&ok, 16);
 /* Loading translation */
	QTranslator translator;
	
	if (choice == 3) {translator.load(":language_ch.qm");  }
	else if (choice ==2) {translator.load(":language_ge.qm"); }
	else if (choice ==1) {translator.load(":language_fr.qm"); }
	else {translator.load(":language_en.qm"); };

	app.installTranslator(&translator);
	
	/* Splash Screen setup uses subclassed QSplashScreen for message position controle. */
	QPixmap splashImage(":images/splash.png");
	QPixmap splashMask(":images/splashmask.png");

	customSplashScreen *splash = new customSplashScreen(splashImage);
	splash->setMessageRect(QRect(7, 253, 415, 14), Qt::AlignCenter); // Setting the message position.

	QFont splashFont;
	splashFont.setFamily("Arial");
	splashFont.setBold(true);
	splashFont.setPixelSize(9);
	splashFont.setStretch(125);

	splash->setFont(splashFont);
	splash->setMask(splashMask);
	//splash->setWindowOpacity(0.90);
	splash->setWindowFlags(Qt::WindowStaysOnTopHint | Qt::SplashScreen);
	
	//Preferences *preferences = Preferences::Instance(); // Load the preferences.
	if(preferences->getPreferences("Window", "Splash", "bool")=="true")
	{
		splash->show();
	};
	/* To intercept mousclick to hide splash screen. Since the 
	splash screen is typically displayed before the event loop 
	has started running, it is necessary to periodically call. */
	app.processEvents();

	splash->showStatusMessage(QObject::tr("Initializing - please wait..."));
	mainWindow window;// = new mainWindow;

	QObject::connect( &window, SIGNAL(closed()), &app, SLOT(quit()) );

	app.processEvents();

	splash->showStatusMessage(QObject::tr("Checking license file..."));
	if(!QFile("license.txt").exists())
	{
		splash->showStatusMessage(QObject::tr("Loading license file..."));
		QFile file(":license.txt" );
		file.copy("license.txt");
		file.close();
	};
	
	app.processEvents();

	splash->showStatusMessage(QObject::tr("Loading midi mapping..."));
	MidiTable *midiTable = MidiTable::Instance();
        midiTable = 0;

	app.processEvents(); 

	splash->showStatusMessage(QObject::tr("Initializing main window..."));
	window.setWindowFlags( Qt::WindowTitleHint 
		| Qt::WindowMinimizeButtonHint 
		| Qt::MSWindowsFixedSizeDialogHint );
	window.setWindowIcon(QIcon(":/images/windowicon.png"));

	app.processEvents(); 

	//bool ok;
	QString x_str = preferences->getPreferences("Window", "Position", "x");
	QString y_str = preferences->getPreferences("Window", "Position", "y");

	app.processEvents(); 

	//window.show(); // need to show the windows to get the size of it, before that it doesn't exist
	//int windowWidth = window.width();                  
	//int windowHeight = window.height();

	app.processEvents(); 

	int windowWidth, windowHeight;
	if(preferences->getPreferences("Window", "Collapsed", "bool")=="true" && 
		preferences->getPreferences("Window", "Restore", "sidepanel")=="true")
	{
		
		if(preferences->getPreferences("Window", "Collapsed", "width").isEmpty())
		{
			windowWidth = preferences->getPreferences("Window", "Collapsed", "defaultwidth").toInt(&ok, 10);
		}
		else
		{
			windowWidth = preferences->getPreferences("Window", "Collapsed", "width").toInt(&ok, 10);
		};
	}
	else
	{
		if(preferences->getPreferences("Window", "Size", "width").isEmpty())
		{
			windowWidth = preferences->getPreferences("Window", "Size", "minwidth").toInt(&ok, 10);
		}
		else
		{
			windowWidth = preferences->getPreferences("Window", "Size", "width").toInt(&ok, 10);
		};
	}

	app.processEvents(); 


	if(preferences->getPreferences("Window", "Restore", "window")=="true" && !x_str.isEmpty())
	{
		splash->showStatusMessage(QObject::tr("Restoring window position..."));
		if(preferences->getPreferences("Window", "Size", "height").isEmpty())
		{
			windowHeight = preferences->getPreferences("Window", "Size", "minheight").toInt(&ok, 10);
		}
		else
		{
			windowHeight = preferences->getPreferences("Window", "Size", "height").toInt(&ok, 10);
		};
		//window.setGeometry(x_str.toInt(&ok, 10), y_str.toInt(&ok, 10), windowWidth, windowHeight);
		window.resize(QSize(windowWidth, windowHeight));
		window.move(x_str.toInt(&ok, 10), y_str.toInt(&ok, 10));
	}
	else
	{
		splash->showStatusMessage(QObject::tr("Centering main window..."));
		QDesktopWidget *desktop = new QDesktopWidget;
		QRect screen = desktop->availableGeometry(desktop->primaryScreen()); 
		int screenWidth = screen.width();                    // returns available screen width
		int screenHeight = screen.height();                  // returns available screen height

		windowHeight = preferences->getPreferences("Window", "Size", "minheight").toInt(&ok, 10);

		int x = (screenWidth - windowWidth) / 2;
		int y = (screenHeight - windowHeight) / 2;
		window.setGeometry(x, y, window.width(), window.height());
	};
	
	app.processEvents();

	splash->showStatusMessage(QObject::tr("Finished Initializing..."));

	window.show();
	splash->finish(&window);

        /* PREVIEW WARNING   */
	QMessageBox *msgBox = new QMessageBox();
        msgBox->setWindowTitle(QObject::tr("GR-55FloorBoard alpha preview version!"));
	msgBox->setIcon(QMessageBox::Warning);
	msgBox->setTextFormat(Qt::RichText);
	QString msgText;
	msgText.append("<font size='+1'><b>");
        msgText.append(QObject::tr("This software preview is currently under development!<br>"));
	msgText.append("<b></font><br>");
	msgText.append(QObject::tr("Ensure you make regular backups of your GR-55 with the ROLAND Librarian.<br><br>"));
	msgText.append(QObject::tr("Please email to http//:gumtownbassman@yahoo.com if any bugs are found.<br><br>"));
	msgText.append(QObject::tr("This version is a pre-release preview for comment only !!."));

	msgBox->setText(msgText);
	msgBox->setStandardButtons(QMessageBox::Ok);
	msgBox->exec();
         /*END WARNING */

	return app.exec();
};
