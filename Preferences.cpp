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

#include "Preferences.h"
#include "PreferencesDestroyer.h"
#include <QList>
#include <QFile>
#include <QTextCodec> 
#include <QHash>
#include "xmlwriter/xmlwriter.h"
#include <QMessageBox>

Preferences::Preferences() 
{
	loadPreferences(":preferences.xml.dist");

	QString buildVersion = this->getPreferences("General", "Application", "version");

	if(!QFile("preferences.xml").exists())
	{
		loadPreferences(":preferences.xml.dist");
	}
	else
	{
		loadPreferences("preferences.xml");
		if(this->getPreferences("General", "Application", "version")!=buildVersion)
		{
			loadPreferences(":preferences.xml.dist");
		};
	};
};

Preferences* Preferences::_instance = 0;// initialize pointer
PreferencesDestroyer Preferences::_destroyer;

Preferences* Preferences::Instance() 
{
	/* Multi-threading safe */
	if (!_instance /*_instance == 0*/)  // is it the first call?
	{  
		_instance = new Preferences; // create sole instance
		_destroyer.SetPreferences(_instance);
	};
	return _instance; // address of sole instance

	/* Single-threading */
	/*
	static Preferences inst;
	return &inst;
	*/
};

QString Preferences::getPreferences(QString prefGroupName, QString prefTypeName, QString prefItemName)
{
	/* Look op and return of the value coresponding to the group->type->item */
	QString setting;
	int indexOfValue = this->metaSearch.indexOf(QString(prefGroupName + ":" + prefTypeName + ":" + prefItemName));
	if(indexOfValue!=-1)
	{
		setting = this->prefValues.at(indexOfValue);
	}
	else
	{
		setting = "";
	};
	return setting;
};

void Preferences::setPreferences(QString prefGroupName, QString prefTypeName, QString prefItemName, QString prefValueData)
{
	/* Look op and set the value coresponding to the group->type->item */
	int indexOfValue = this->metaSearch.indexOf(QString(prefGroupName + ":" + prefTypeName + ":" + prefItemName));
	if(indexOfValue!=-1)
	{
		this->prefValues.replace(indexOfValue, prefValueData); 
	}
	else
	{
		/* If the group->type->item does not exist/found it will be created/added */
		this->metaSearch.append(QString(prefGroupName + ":" + prefTypeName + ":" + prefItemName));
		this->groupNames.append(prefGroupName);
		this->typeNames.append(prefTypeName);
		this->itemNames.append(prefItemName);		
		this->prefValues.append(prefValueData);
	};
};

void Preferences::loadPreferences(QString fileName)
{	
	this->metaSearch.clear();
	this->groupNames.clear();
	this->typeNames.clear();
	this->itemNames.clear();
	this->prefValues.clear();
	
	QFile file;
	file.setFileName(fileName);
	/* Loads the xml document and creates the QDomElement root */
	QDomDocument doc( "Application Preferences" );
	doc.setContent( &file );                    // file is a QFile
	file.close();
	QDomElement root = doc.documentElement();   // Points to <Preferences>
	this->root = root;

	/* Iterate trough xml tree and load in to the assigned vector */
	QDomNode node = root.firstChild(); // Points to prefBuffer group
	while ( !node.isNull() ) 
	{
		QString _groupName = node.nodeName();
		
		QDomNode childNode = node.firstChild(); // Points to prefBuffer type
		while ( !childNode.isNull() ) 
		{
			QString _typeName = childNode.nodeName();

			for (int itemNum=0;itemNum<childNode.attributes().count();itemNum++ ) 
			{   // Iterates trough all the atributes
				QString _itemName = childNode.attributes().item(itemNum).nodeName();
				QString _value = childNode.attributes().namedItem(_itemName).nodeValue();
				
				this->metaSearch.append(_groupName + ":" + _typeName + ":" + _itemName);
				this->prefValues.append(_value);
				this->groupNames.append(_groupName);
				this->typeNames.append(_typeName);
				this->itemNames.append(_itemName);
			};

			childNode = childNode.nextSibling();
		};
		
		node = node.nextSibling();
	};	
};

struct IndexList // Create a structure of metaSearchData and indexnumbers to sort and match them afterwords
{
	QString metaSearchData, indexNumber;

	bool operator<(const IndexList& rhs) const;
	//indexList(QString metaSearchData_, QString indexNumber_) : metaSearchData(metaSearchData_), indexNumber(indexNumber_) {}
};

bool IndexList::operator<(const IndexList& rhs) const
{
	return (metaSearchData < rhs.metaSearchData) ? true : (metaSearchData == rhs.metaSearchData) ? rhs.indexNumber > indexNumber : false;
};

void Preferences::savePreferences()
{
	//Write back to file/create
    QFile file("preferences.xml");
    if (!file.open(QIODevice::WriteOnly)) {
    // ERROR
    }
    XmlWriter xout(&file);

    QHash<QString, QString> attrs;

	xout.writeComment("Preferences of the GR-55 FloorBoard application.");
	xout.writeOpenTag("Preferences");

	unsigned int aSize = this->metaSearch.size();
	QList<IndexList> sortIndexList;
	IndexList tmp;
	for(unsigned int n=0;n<aSize;n++)
	{
		//sortIndexList.append( indexList(this->metaSearch.at(n), QString::number(n, 10)) );
		tmp.metaSearchData = this->metaSearch.at(n);
		tmp.indexNumber = QString::number(n, 10);
		sortIndexList.append( tmp );
	};

	qSort(sortIndexList.begin(), sortIndexList.end());

	bool ok;
	int i =0, a = 0;
	QString currentGroupName;
	for(unsigned int n=0; n<aSize;n++)
	{
		i = sortIndexList.at(n).indexNumber.toInt(&ok, 10);
		if( this->groupNames.at(i) != currentGroupName )
		{
			xout.writeOpenTag(this->groupNames.at(i));
		};
		currentGroupName = this->groupNames.at(i);

		attrs.insert(this->itemNames.at(i), this->prefValues.at(i));
		if(n<aSize-1)
		{
			a = sortIndexList.at(n + 1).indexNumber.toInt(&ok, 10);
			if(this->typeNames.at(i) != this->typeNames.at(a))
			{
				xout.writeAtomTag(this->typeNames.at(i), attrs);
				attrs.clear();
			};
		}
		else
		{
			xout.writeAtomTag(this->typeNames.at(i), attrs);
			attrs.clear();
		};

		if(n==aSize-1)
		{
			xout.writeCloseTag(currentGroupName);
		}
		else if( currentGroupName != this->groupNames.at(a) )
		{
			xout.writeCloseTag(currentGroupName);
		};
	};

	xout.writeCloseTag("Preferences");
	//file.close();
};
