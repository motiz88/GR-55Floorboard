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

#ifndef MIDITABLE_H
#define MIDITABLE_H

#include <QString>
#include <QList>
#include <qdom.h>

/* Declaring struc types */
struct Midi
{
	QString value, name, abbr, desc, customdesc;
	QList<QString> type, id;
	QList<Midi> level;
};

class MidiTableDestroyer;

class MidiTable
{

public:
	static MidiTable* Instance(); //Singleton pattern design

	void loadMidiMap();
	Midi getMidiMap(QString root);
	Midi getMidiMap(QString root, QString hex1);
	Midi getMidiMap(QString root, QString hex1, QString hex2);
	Midi getMidiMap(QString root, QString hex1, QString hex2, QString hex3);
	Midi getMidiMap(QString root, QString hex1, QString hex2, QString hex3, QString hex4);
	Midi getMidiMap(QString root, QString hex1, QString hex2, QString hex3, QString hex4, QString hex5);

	//int getRange(QString root, QString hex1);
	//int getRange(QString root, QString hex1, QString hex2);
	int getRange(QString root, QString hex1, QString hex2, QString hex3);
	int getRangeMinimum(QString root, QString hex1, QString hex2, QString hex3);
	//int getRange(QString root, QString hex1, QString hex2, QString hex3, QString hex4);
	//int getRange(QString root, QString hex1, QString hex2, QString hex3, QString hex4, QString hex5);

	QString getValue(QString root, QString hex1, QString hex2, QString hex3, QString hex4);
	bool isData(QString root, QString hex1, QString hex2, QString hex3);
	QString rangeToValue(Midi range, QString value);
	QString getHeader(bool receive);
	QString getFooter();
	QString getSize(QString hex1, QString hex2, QString hex3);
	QString getSize(QString hex1, QString hex2);
	QString getSize();
	QString dataRequest(QString hex1, QString hex2, QString hex3);
	QString dataChange(QString area, QString hex1, QString hex2, QString hex3, QString hex4);
	QString dataChange(QString area, QString hex1, QString hex2, QString hex3, QString hex4, QString hex5);
	QString nameRequest(int bank, int patch);
	QString getCheckSum(int dataSize);
	QString patchRequest(int bank, int patch);

	
protected:
	MidiTable();
	friend class MidiTableDestroyer;
	virtual ~MidiTable() { };

private:
	static MidiTable* _instance;
	static MidiTableDestroyer _destroyer;

	QDomElement root;
	Midi midiMap;
};

#endif // MIDITABLE_H
