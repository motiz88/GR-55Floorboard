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
 
#include "MidiTable.h"     
#include "MidiTableDestroyer.h" 
#include <QFile> 
#include <QStringList>
#include "Preferences.h"
#include "globalVariables.h"
 
MidiTable::MidiTable()  
{ 
    loadMidiMap(); 
}; 
 
MidiTable* MidiTable::_instance = 0;// initialize pointer 
MidiTableDestroyer MidiTable::_destroyer; 
 
MidiTable* MidiTable::Instance()  
{ 
    /* Multi-threading safe */ 
    if (!_instance)  // is it the first call? 
    {   
        _instance = new MidiTable; // create sole instance 
        _destroyer.SetMidiTable(_instance); 
    }; 
    return _instance; // address of sole instance 
};

void MidiTable::loadMidiMap() 
{ 
    QDomDocument doc( "MIDI Transalation" ); 
	QFile file( ":midi.xml" ); 
    doc.setContent( &file );                    // file is a QFile 
    file.close(); 
    QDomElement root = doc.documentElement();   // Points to <SysX> 
    this->root = root; 
     //QList<Midi> midiMap; 
     
    QDomNode node = root.firstChild(); 
    while ( !node.isNull() )  
    { 
        Midi section; 
		section.type.append(node.nodeName()); 
		
		QDomNode level1Node = node.firstChild(); 
        while ( !level1Node.isNull() )  
        { 
            Midi level1; 
			level1.type.append(level1Node.nodeName()); 
            level1.name = level1Node.attributes().namedItem("name").nodeValue(); 
            level1.value = level1Node.attributes().namedItem("value").nodeValue();             
            level1.abbr = level1Node.attributes().namedItem("abbr").nodeValue(); 
            level1.desc = level1Node.attributes().namedItem("desc").nodeValue(); 
			level1.customdesc = level1Node.attributes().namedItem("customdesc").nodeValue(); 
         
            QDomNode level2Node = level1Node.firstChild(); 

            while ( !level2Node.isNull() )  
            { 
                Midi level2; 
				level2.type.append(level2Node.nodeName());
				level2.name = level2Node.attributes().namedItem("name").nodeValue(); 
				level2.value = level2Node.attributes().namedItem("value").nodeValue();             
				level2.abbr = level2Node.attributes().namedItem("abbr").nodeValue(); 
				level2.desc = level2Node.attributes().namedItem("desc").nodeValue(); 
				level2.customdesc = level2Node.attributes().namedItem("customdesc").nodeValue();

				QDomNode level3Node = level2Node.firstChild(); 
                
                while ( !level3Node.isNull() )  
                { 	
					Midi level3; 
					level3.type.append(level3Node.nodeName());
					level3.name = level3Node.attributes().namedItem("name").nodeValue(); 
					level3.value = level3Node.attributes().namedItem("value").nodeValue();             
					level3.abbr = level3Node.attributes().namedItem("abbr").nodeValue(); 
					level3.desc = level3Node.attributes().namedItem("desc").nodeValue(); 
					level3.customdesc = level3Node.attributes().namedItem("customdesc").nodeValue();

					QDomNode  level4Node = level3Node.firstChild();
                    
                    while ( !level4Node.isNull() )  
                    { 
						Midi level4; 
						level4.type.append(level4Node.nodeName());
						level4.name = level4Node.attributes().namedItem("name").nodeValue(); 
						level4.value = level4Node.attributes().namedItem("value").nodeValue();             
						level4.abbr = level4Node.attributes().namedItem("abbr").nodeValue(); 
						level4.desc = level4Node.attributes().namedItem("desc").nodeValue();
						level4.customdesc = level4Node.attributes().namedItem("customdesc").nodeValue();
	 
						QDomNode level5Node = level4Node.firstChild();

						while ( !level5Node.isNull() )  
						{ 
							Midi level5; 
							level5.type.append(level5Node.nodeName());
							level5.name = level5Node.attributes().namedItem("name").nodeValue(); 
							level5.value = level5Node.attributes().namedItem("value").nodeValue();             
							level5.desc = level5Node.attributes().namedItem("desc").nodeValue();
							level5.customdesc = level5Node.attributes().namedItem("customdesc").nodeValue();

							level4.id.append(level5.value); 
							level4.level.append(level5); 
							level5Node = level5Node.nextSibling(); 
						}; 

						level3.id.append(level4.value);
						level3.level.append(level4); 
						level4Node = level4Node.nextSibling();
                    }; 

					level2.id.append(level3.value);
                    level2.level.append(level3); 
                    level3Node = level3Node.nextSibling(); 
                }; 
				
				level1.id.append(level2.value);
                level1.level.append(level2);  
                level2Node = level2Node.nextSibling(); 
            }; 

			section.id.append(level1.value);
			section.level.append(level1); 
            level1Node = level1Node.nextSibling(); 
        }; 

		QString test = node.nodeName();
		this->midiMap.id.append(test); 
		this->midiMap.level.append(section); 
        node = node.nextSibling(); 
    }; 
}; 

Midi MidiTable::getMidiMap(QString root)
{
	Midi section = midiMap.level.at( midiMap.id.indexOf(root) );
	return section;
};

Midi MidiTable::getMidiMap(QString root, QString hex1)
{ 
	Midi section = midiMap.level.at( midiMap.id.indexOf(root) );
	Midi level1 = section.level.at( section.id.indexOf(hex1) );;
	return level1; 
};

Midi MidiTable::getMidiMap(QString root, QString hex1, QString hex2)
{ 
	Midi section = midiMap.level.at( midiMap.id.indexOf(root) );
	Midi level1 = section.level.at( section.id.indexOf(hex1) );
	Midi level2 = level1.level.at( level1.id.indexOf(hex2) );
	return level2; 
};

Midi MidiTable::getMidiMap(QString root, QString hex1, QString hex2, QString hex3)
{ 
	Midi section = midiMap.level.at( midiMap.id.indexOf(root) );
	Midi level1 = section.level.at( section.id.indexOf(hex1) );
	Midi level2 = level1.level.at( level1.id.indexOf(hex2) );
	Midi level3;
	if(!level2.id.contains(hex3) && level2.id.contains("range"))
	{
		level3 = level2.level.at( level2.id.indexOf("range") );
	}
	else
	{
		level3 = level2.level.at( level2.id.indexOf(hex3) );
	};
	return level3; 
};

Midi MidiTable::getMidiMap(QString root, QString hex1, QString hex2, QString hex3, QString hex4)
{ 
	Midi section = midiMap.level.at( midiMap.id.indexOf(root) );
	Midi level1 = section.level.at( section.id.indexOf(hex1) );
	Midi level2 = level1.level.at( level1.id.indexOf(hex2) );
	Midi level3;
	if(!level2.id.contains(hex3) && level2.id.contains("range"))
	{
		level3 = level2.level.at( level2.id.indexOf("range") );
	}
	else
	{
		level3 = level2.level.at( level2.id.indexOf(hex3) );
	};

	Midi level4 = level3.level.at( level3.id.indexOf(hex4) );
	return level4; 
};

Midi MidiTable::getMidiMap(QString root, QString hex1, QString hex2, QString hex3,  QString hex4, QString hex5)
{ 
	Midi section = midiMap.level.at( midiMap.id.indexOf(root) );
	Midi level1 = section.level.at( section.id.indexOf(hex1) );
	Midi level2 = level1.level.at( level1.id.indexOf(hex2) );
	Midi level3 = level2.level.at( level2.id.indexOf(hex3) );
	Midi level4 = level3.level.at( level3.id.indexOf(hex4) );
	Midi level5 = level4.level.at( level4.id.indexOf(hex5) );
	return level5; 
};

int MidiTable::getRange(QString root, QString hex1, QString hex2, QString hex3)
{
	Midi range;
	
	/* When FX has alot off settings (more than ) it's spanned over more then one entry in the 
	midi.xml, so when out of range we jump to the next entry and start from 00. */
	bool ok;
	range = getMidiMap(root, hex1, hex2, hex3);		
  int lastIndex;
	if(range.level.last().value == "range")
	{
		lastIndex = range.level.last().name.split("/").at(1).toInt(&ok, 16);
	}
	else if(range.level.last().type.contains("DATA"))
	{
		int maxRange = QString("7F").toInt(&ok, 16) + 1; // index starts at 0 -> 0-127 = 128 entry's.
		int lastIndex1 = range.level.last().value.toInt(&ok, 16);
		int lastIndex2 = range.level.last().level.last().value.toInt(&ok, 16);
		lastIndex = (lastIndex1 * maxRange) + lastIndex2;
	}
	else
	{
		lastIndex = range.level.last().value.toInt(&ok, 16);
	};
	return lastIndex;
};

int MidiTable::getRangeMinimum(QString root, QString hex1, QString hex2, QString hex3)
{
	Midi range;
	
	/* When FX has alot off settings (more than ) it's spanned over more then one entry in the 
	midi.xml, so when out of range we jump to the next entry and start from 00. */
	bool ok;
  
	range = getMidiMap(root, hex1, hex2, hex3);	
	int firstIndex;
	if(range.level.first().value == "range")
	{
		firstIndex = range.level.last().name.split("/").at(0).toInt(&ok, 16);
	}
	else if(range.level.last().type.contains("DATA"))
	{
	  firstIndex = range.level.last().customdesc.toInt(&ok, 16);  //get manually entered value from level 4 bottom customdesc.
	}
	else
	{
		firstIndex = range.level.first().value.toInt(&ok, 16);
	};
	return firstIndex;
};

bool MidiTable::isData(QString root, QString hex1, QString hex2, QString hex3)
{
	Midi range;
	
	/* When FX has alot off settings (more than ) it's spanned over more then one entry in the 
	midi.xml, so when out of range we jump to the next entry and start from 00. */

	range = getMidiMap(root, hex1, hex2, hex3);	
	if(range.level.last().type.contains("DATA"))
	{
		return true;
	}
	else
	{
		return false;
	};
};

QString MidiTable::getValue(QString root, QString hex1, QString hex2, QString hex3, QString hex4)
{
	Midi range = getMidiMap(root, hex1, hex2, hex3);
	QString valueStr; bool ok;
	if(range.level.last().type.contains("DATA"))
	{
		int maxRange = QString("7F").toInt(&ok, 16) + 1;
		int value = hex4.toInt(&ok, 16);
		int dif = value/maxRange;
		QString index1 = QString::number(dif, 16).toUpper();
		if(index1.length() < 2) index1.prepend("0");
		QString index2 = QString::number(value - (dif * maxRange), 16).toUpper();
		if(index2.length() < 2) index2.prepend("0");

		Midi dataRange = range.level.at(range.id.indexOf(index1));
		valueStr = rangeToValue(dataRange, index2);
	}
	else
	{
		valueStr = rangeToValue(range, hex4);
	};
	return valueStr;
};

QString MidiTable::rangeToValue(Midi range, QString hex)
{
	QString valueStr;
	if(!range.id.contains(hex) /*&& range.id.contains("range")*/)
	{
		int i = 0; bool ok;
		while(range.id.indexOf("range", i) != -1)
		{
			QStringList rangeList = range.level.at(range.id.indexOf("range", i)).name.split("/");
			QString desc = range.level.at(range.id.indexOf("range", i)).desc;
			
			int valueInt = hex.toInt(&ok, 16);
			int start = rangeList.at(0).toInt(&ok, 16);
			int end = rangeList.at(1).toInt(&ok, 16);
			
			if(valueInt == start || (valueInt > start && valueInt < end) || valueInt == end)
			{
				
				double min = rangeList.at(2).toDouble(&ok);
				double max = rangeList.at(3).toDouble(&ok);
				double dataRange = max - min;
				double range = end - start;
				double result = ((double)valueInt * (dataRange / range)) + (min - start);
				int precision;
				if(rangeList.at(3).contains("."))
				{
					precision = rangeList.at(3).split(".").last().length();
				}
				else
				{
					precision = 0;
				};
				valueStr = QString::number(result, 10, precision) + desc;
				break;
			};
			i++;
		};
	}
	else
	{
		valueStr = range.level.at(range.id.indexOf(hex)).name;
	};
	return valueStr;
};

QString MidiTable::getHeader(bool receive)
{
	Midi section = midiMap.level.at( midiMap.id.indexOf("Header") );

	QString header;
	for(int i=0;i<section.level.size();++i)
	{
		int offset = 0;
		if(!receive && i == sysxAddressOffset - 1) 
		{
			offset = 1;
		};
		Midi level1 = section.level.at(i);
		Midi level2 = level1.level.at(offset);
		header.append(level2.value);
	};

	return header;
};

QString MidiTable::getFooter()
{
	Midi section = midiMap.level.at( midiMap.id.indexOf("Footer") );

	QString footer;
	Midi level1 = section.level.at(0);
	Midi level2 = level1.level.at(0);
	footer.append(level2.value);

	return footer;
};

QString MidiTable::getSize(QString hex1, QString hex2, QString hex3)
{
	Midi section = midiMap.level.at( midiMap.id.indexOf("Structure") );
	Midi level1 = section.level.at( section.id.indexOf(hex1) );
	Midi level2 = level1.level.at( level1.id.indexOf(hex2) );
	QString currenFxName = level2.level.at( level2.id.indexOf(hex3) ).name;
	QString nextFxName = level2.level.at( level2.id.indexOf(hex3) + 1 ).name;
	
	int sizeCount = 1; bool ok;
	if(currenFxName == nextFxName) sizeCount += 1;
	sizeCount += hex3.toInt(&ok, 16);
	
	QString itemSize = QString::number(sizeCount, 16).toUpper();
	if (itemSize.length() < 2) itemSize.prepend("0");
	
	QString size;
	size.append(hex3);
	size.append("00");
	size.append(itemSize);
	size.append("00");
	return size;
};

QString MidiTable::getSize(QString hex1, QString hex2)
{
	Midi section = midiMap.level.at( midiMap.id.indexOf("Structure") );
	Midi level1 = section.level.at( section.id.indexOf(hex1) );
	Midi level2 = level1.level.at( level1.id.indexOf(hex2) );

	QString size;

	int sizeCount = 1; bool ok;
	
	for(int i=0;i<level2.level.size();++i)
	{
		QString hex3 = QString::number(i, 16).toUpper();
		if (hex3.length() < 2) hex3.prepend("0");
		
		if(!level2.id.contains(hex3) && level2.id.contains("range"))
		{
			Midi level3 = level2.level.at( level2.id.indexOf("range") );
			QStringList rangeList = level3.name.split("/");
			sizeCount += rangeList.at(1).toInt(&ok, 16);
		}
		else
		{
			Midi level3 = level2.level.at( level2.id.indexOf(hex3) );
			if(!level3.level.isEmpty())
			{
				if(level3.level.last().type.contains("DATA"))
				{
					sizeCount += 1;
				}
				else
				{
					sizeCount += 1;
				};
			}
			else
			{
				sizeCount += 1;
			};
		};		
	};

	QString itemSize = QString::number(sizeCount, 16).toUpper();
	if (itemSize.length() < 2) itemSize.prepend("0");

	size.append("00");
	size.append("00");
	size.append("00");
	size.append(itemSize);
	return size;
};

QString MidiTable::getSize()
{
	Midi section = midiMap.level.at( midiMap.id.indexOf("Structure") );

	QString size;
	bool ok;
	int sizeCount = 1;
	sizeCount += section.level.last().value.toInt(&ok, 16);

	QString itemSize = QString::number(sizeCount, 16).toUpper();
	if (itemSize.length() < 2) itemSize.prepend("0");
	
	size.append("00");
	size.append("00");
	size.append(itemSize);
	size.append("00");
	return size;
};

QString MidiTable::getCheckSum(int dataSize)
{
	bool ok;
	QString base = "80";
	int sum = dataSize % base.toInt(&ok, 16);
	if(sum!=0){ sum = base.toInt(&ok, 16) - sum; };
	QString checksum = QString::number(sum, 16).toUpper();
	if(checksum.length()<2) { checksum.prepend("0"); };
	return checksum;
};

QString MidiTable::dataRequest(QString hex1, QString hex2, QString hex3)
{
	QString sysxMsg;
	sysxMsg.append(getHeader(true));
	
	sysxMsg.append(hex1);
	sysxMsg.append(hex2);


	sysxMsg.append(getFooter());
	return sysxMsg;
};

QString MidiTable::dataChange(QString area, QString hex1, QString hex2, QString hex3, QString hex4)
{
	QString sysxMsg;
	sysxMsg.append(getHeader(false));
		if (area != "System")
    {
      area = "Structure"; 
      sysxMsg.append(tempDataWrite);
      sysxMsg.append("00");

	    sysxMsg.append(hex1);
	    sysxMsg.append(hex3);
    } 
    else
    {
       area = "System";
      sysxMsg.append("00");
	    sysxMsg.append(hex1);
	    sysxMsg.append(hex2);
	    sysxMsg.append(hex3);
    };

	sysxMsg.append(hex4);

	int dataSize = 0;
	bool ok;
	for(int i=checksumOffset;i<sysxMsg.size()-1;++i)
	{ dataSize += sysxMsg.mid(i*2, 2).toInt(&ok, 16); };	
	sysxMsg.append(getCheckSum(dataSize));

	sysxMsg.append(getFooter());
	return sysxMsg;
};

QString MidiTable::dataChange(QString area, QString hex1, QString hex2, QString hex3, QString hex4, QString hex5)
{
	QString sysxMsg;
	sysxMsg.append(getHeader(false));
	if (area != "System")
    {
      area = "Structure"; 
      sysxMsg.append(tempDataWrite);
      sysxMsg.append("00");

	    sysxMsg.append(hex1);
	    sysxMsg.append(hex3);
    } 
    else
    {
      area = "System";
      sysxMsg.append("00");
	    sysxMsg.append(hex1);
	    sysxMsg.append(hex2);
	    sysxMsg.append(hex3);
    };
	
	sysxMsg.append(hex4);
	sysxMsg.append(hex5);

	int dataSize = 0; bool ok;
	for(int i=checksumOffset;i<sysxMsg.size()-1;++i)
	{ dataSize += sysxMsg.mid(i*2, 2).toInt(&ok, 16); };	
	sysxMsg.append(getCheckSum(dataSize));

	sysxMsg.append(getFooter());
	return sysxMsg;
};

QString MidiTable::nameRequest(int bank, int patch)
{
	bool ok;
	QString addr1, addr2;
	if(bank != 0 && patch != 0 && bank <= bankTotalAll && patch <= patchPerBank) 
	{
		int patchOffset = (((bank - 1 ) * patchPerBank) + patch) - 1;
                int memmorySize = 298;
		int emptyAddresses = (memmorySize) - ((bankTotalUser * patchPerBank) - (memmorySize));
		if(bank > bankTotalUser) patchOffset += emptyAddresses; //System patches start at a new memmory range.
		int addrMaxSize = QString("80").toInt(&ok, 16);       //patch/bank = 100
		int n = (int)(patchOffset / addrMaxSize);
		if (bank > bankTotalUser){
                addr1 = QString::number(48 + n, 16).toUpper();
		addr2 = QString::number(patchOffset - (addrMaxSize * n), 16).toUpper();
		}else{
                addr1 = QString::number(32 + n, 16).toUpper();
		addr2 = QString::number(patchOffset - (addrMaxSize * n), 16).toUpper();
    };
    if (addr1.length() < 2) addr1.prepend("0");
		if (addr2.length() < 2) addr2.prepend("0");
	}
    else
	{
        addr1 = tempDataWrite;
	addr2 = "00";
	};
	QString hex1 = "00";
	QString hex2 = "01";

	QString sysxMsg;
	sysxMsg.append(getHeader(true));
	sysxMsg.append(addr1);
	sysxMsg.append(addr2);
	sysxMsg.append(hex1);
	sysxMsg.append(hex2);
	sysxMsg.append("00000010");

	int dataSize = 0;
	for(int i=checksumOffset;i<sysxMsg.size()-1;++i)
	{ dataSize += sysxMsg.mid(i*2, 2).toInt(&ok, 16);	};	
	sysxMsg.append(getCheckSum(dataSize));
	sysxMsg.append(getFooter());

	return sysxMsg;
};

QString MidiTable::patchRequest(int bank, int patch)
{
	bool ok;
	QString addr1, addr2;
	if(bank != 0 && patch != 0 && bank <= bankTotalAll)   
	{
		int patchOffset = (((bank - 1 ) * patchPerBank) + patch) - 1;
                int memmorySize = 297;    //user patch range
		int emptyAddresses = (memmorySize) - ((bankTotalUser * patchPerBank) - (memmorySize));
		if(bank > bankTotalUser) patchOffset += emptyAddresses; //System patches start at a new memmory range.
		int addrMaxSize = QString("80").toInt(&ok, 16);          //patch/bank
		int n = (int)(patchOffset / addrMaxSize);
		
		if (bank > bankTotalUser){
                addr1 = QString::number(48 + n, 16).toUpper();
		addr2 = QString::number(patchOffset - (addrMaxSize * n), 16).toUpper();
		}else{
                addr1 = QString::number(32 + n, 16).toUpper();
		addr2 = QString::number(patchOffset - (addrMaxSize * n), 16).toUpper();
    };
	}
         else
	{
                addr1 = tempDataWrite;
		addr2 = "00";
	};
  if (addr1.length() < 2) addr1.prepend("0");
	if (addr2.length() < 2) addr2.prepend("0");
	QString hex1 = "00";
	QString hex2 = "00";

	QString sysxMsg;
	sysxMsg.append(getHeader(true));
	sysxMsg.append(addr1);
	sysxMsg.append(addr2);
	sysxMsg.append(hex1);
	sysxMsg.append(hex2);
	sysxMsg.append(patchRequestDataSize);    //(getSize());

	int dataSize = 0;
	for(int i=checksumOffset;i<sysxMsg.size()-1;++i)
	{ dataSize += sysxMsg.mid(i*2, 2).toInt(&ok, 16); };	
	sysxMsg.append(getCheckSum(dataSize));
	sysxMsg.append(getFooter());

	return sysxMsg;
};
