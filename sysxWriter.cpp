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

#include <QFile>
#include <QDataStream>
#include <QByteArray>
#include <QMessageBox>
#include "sysxWriter.h"
#include "fileDialog.h"
#include "globalVariables.h"

sysxWriter::sysxWriter()
{

};

sysxWriter::~sysxWriter()
{

};

void sysxWriter::setFile(QString fileName)
{
    this->fileName = fileName;
    this->fileSource.address.clear();
    this->fileSource.hex.clear();
};

bool sysxWriter::readFile()
{
    QFile file(fileName);
    if (file.open(QIODevice::ReadOnly))
    {
        QByteArray data = file.readAll();     // read the pre-selected file,
            QByteArray default_data;
                QByteArray G5L_default;
                QByteArray hextable;
                QFile file(":default.syx");           // Read the default GR-55 sysx file .
    if (file.open(QIODevice::ReadOnly))
          {	default_data = file.readAll(); };
          QFile G5Lfile(":default.g5l");           // Read the default GR-55 G5L file .
    if (G5Lfile.open(QIODevice::ReadOnly))
          {	G5L_default = G5Lfile.readAll(); };
          QFile hexfile(":HexLookupTable.hex");           // Read the HexLookupTable for the SMF header file .
    if (hexfile.open(QIODevice::ReadOnly))
          {	hextable = hexfile.readAll(); };

          QByteArray default_header = default_data.mid(0, 7);           // copy header from default.syx
          QByteArray file_header = data.mid(0, 7);                      // copy header from read file.syx
          QByteArray G5L_header = G5L_default.mid(3, 20);                // copy header from default.g5l
          QByteArray SMF_header = hextable.mid(288,18);
          QByteArray SMF_file = data.mid(0, 18);
          bool isHeader = false;
          if (default_header == file_header) {isHeader = true;};
          bool isG5L = false;
          if (data.contains(G5L_header)){isG5L = true; };             // see if file is a G5L type and set isG5L flag.
          bool isSMF = false;
          if (data.contains(SMF_header)) {isSMF = true; };
        if((data.size() == 2340  || data.size() == 2261)/* && isHeader == true*/){         // if GR-55 system file size is correct- load file.
                SysxIO *sysxIO = SysxIO::Instance();
                QString area = "System";
                sysxIO->setFileSource(area, data);
                this->systemSource = sysxIO->getSystemSource();
                return true;
                }
              /*  else if(data.size() == fullPatchSize && isHeader == true){         //2045 if GR-55 patch file size is correct- load file >>>  currently at 1763 bytes standard or 1904 with text.
                SysxIO *sysxIO = SysxIO::Instance();
                QString area = "Structure";
                sysxIO->setFileSource(area, data);
                sysxIO->setFileName(this->fileName);
                this->fileSource = sysxIO->getFileSource();
                return true;
                }
    else*/ if(data.size() == 1333 && isHeader == true){         //1333 if GR-55 standard patch file size is correct- load file >>>  currently at 1763 bytes.

               SysxIO *sysxIO = SysxIO::Instance();
               QString area = "Structure";
               sysxIO->setFileSource(area, data);
               sysxIO->setFileName(this->fileName);
               this->fileSource = sysxIO->getFileSource();
               return true;
           }
         /*
           else if (isSMF)                      // SMF ******************************************************************
           {                                        // file contains a .mid type SMF patch file header from ROLAND Librarian
               QByteArray smf_data = data;
               QFile file(":default.syx");              // Read the default GR-55 sysx file so we don't start empty handed.
               if (file.open(QIODevice::ReadOnly))
               {	data = file.readAll(); };
               QByteArray temp;                         // TRANSLATION of GR-55 SMF PATCHES, data read from smf patch **************

               if ( smf_data.at(37) != data.at(5) ){    // check if a valid GR-55 file
                   QMessageBox *msgBox = new QMessageBox();
                   msgBox->setWindowTitle(QObject::tr("SMF file import"));
                   msgBox->setIcon(QMessageBox::Warning);
                   msgBox->setTextFormat(Qt::RichText);
                   QString msgText;
                   msgText.append("<font size='+1'><b>");
                   msgText.append(QObject::tr("This is not a GR-55 patch!"));
                   msgText.append("<b></font><br>");
                   msgText.append(QObject::tr("this file is a GR-55B Bass version<br>"));
                   msgText.append(QObject::tr("*Loading this file may have unpredictable results*."));
                   msgBox->setText(msgText);
                   msgBox->setStandardButtons(QMessageBox::Ok);
                   msgBox->exec();
               };

               index = 1;
               int patchCount = (smf_data.size()-32)/1806;
               if (patchCount>1)
               {
                   QString msgText;
                   QString patchText;
                   QString patchNumber;
                   unsigned char r;
                   this->patchList.clear();
                   this->patchList.append(QObject::tr("Select Patch"));
                   unsigned int a = 43; // locate patch text start position from the start of the file
                   for (int h=0;h<patchCount;h++)
                   {
                       for (int b=0;b<16;b++)
                       {
                           r = (char)smf_data[a+b];
                           patchText.append(r);
                       };
                       patchNumber = QString::number(h+1, 10).toUpper();
                       msgText.append(patchNumber + " : ");
                       msgText.append(patchText + "   ");
                       this->patchList.append(msgText);
                       patchText.clear();
                       msgText.clear();
                       a=a+1806;                      // offset is set in front of marker
                   };

                   QString type = "smf";
                   fileDialog *dialog = new fileDialog(fileName, patchList, data, default_data, type);
                   dialog->exec();
                   patchIndex(this->index);
               };

               int a=0;
               if (patchCount>1)
               {
                   int q=index-1;      // find start of required patch
                   a = q*1806;
               };
               temp = smf_data.mid(a+43, 128);            // copy SMF 128 bytes
               data.replace(11, 128, temp);             // replace GR55 address "00"
               temp = smf_data.mid(a+171, 114);           // copy SMF part1
               temp.append(smf_data.mid(a+301,14));       // copy SMF part2
               data.replace(152, 128, temp);            // replace GR55 address "01"
               temp = smf_data.mid(a+315, 128);           // copy SMF part1
               data.replace(293, 128, temp);            // replace GR55 address "02"
               temp = smf_data.mid(a+443, 100);           // copy SMF part1
               temp.append(smf_data.mid(a+559,28));       // copy SMF part2
               data.replace(434, 128, temp);            // replace GR55 address "03"
               temp = smf_data.mid(a+587, 128);           // copy SMF part1
               data.replace(575, 128, temp);            // replace GR55 address "04"
               temp = smf_data.mid(a+715, 86);            // copy SMF part1
               data.replace(716, 86, temp);             // replace GR55 address "05"
               temp = smf_data.mid(a+859, 128);           // copy SMF part1
               data.replace(815,128, temp);             // replace GR55 address "06"
               temp = smf_data.mid(a+987, 72);            // copy SMF part1
               temp.append(smf_data.mid(a+1075,56));      // copy SMF part2
               data.replace(956, 128, temp);            // replace GR55 address "07"
               temp = smf_data.mid(a+1131, 128);          // copy SMF part1
               data.replace(1097,128, temp);            // replace GR55 address "08"
               temp = smf_data.mid(a+1259, 58);           // copy SMF part1
               temp.append(smf_data.mid(a+1333,42));      // copy SMF part2
               data.replace(1238, 100, temp);           // replace GR55 address "09"
               temp = smf_data.mid(a+1403, 128);          // copy SMF part1
               data.replace(1351,128, temp);            // replace GR55 address "0A"
               temp = smf_data.mid(a+1531, 44);           // copy SMF part1
               temp.append(smf_data.mid(a+1591,84));      // copy SMF part2
               data.replace(1492, 128, temp);           // replace GR55 address "0B"
               temp = smf_data.mid(a+1675, 128);          // copy SMF part1
               data.replace(1633,128, temp);            // replace GR55 address "0C"
               if (index>0)
               {
                   SysxIO *sysxIO = SysxIO::Instance();
                   QString area = "Structure";
                   sysxIO->setFileSource(area, data);
                   sysxIO->setFileName(this->fileName);
                   this->fileSource = sysxIO->getFileSource();
                   return true;
               } else {return false; }
           }  */
           else if (isG5L)      // if the read file is a ROLAND Librarian type. ***************************************
           {
               index=1;
               unsigned char msb = (char)data[34];     // find patch count msb bit in G5L file at byte 34
               unsigned char lsb = (char)data[35];     // find patch count lsb bit in G5L file at byte 35
               bool ok;
               int patchCount;
               patchCount = (256*QString::number(msb, 16).toUpper().toInt(&ok, 16)) + (QString::number(lsb, 16).toUpper().toInt(&ok, 16));
               QByteArray marker;
               if (patchCount>1)
               {
                   QString msgText;
                   marker = data.mid(170, 2);      //copy marker key to find "06A5" which marks the start of each patch block
                   QString patchText;
                   QString patchNumber;
                   this->patchList.clear();
                   this->patchList.append(QObject::tr("Select Patch"));
                   unsigned int a = data.indexOf(marker, 0); // locate patch start position from the start of the file
                   a=a+2;                             // offset is set in front of marker
                   for (int h=0;h<patchCount;h++)
                   {
                       for (int b=0;b<16;b++)
                       {
                           unsigned char r = (char)data[a+b];
                           patchText.append(r);
                       };
                       patchNumber = QString::number(h+1, 10).toUpper();
                       msgText.append(patchNumber + " : ");
                       msgText.append(patchText + "   ");
                       this->patchList.append(msgText);
                       patchText.clear();
                       msgText.clear();
                       a = data.indexOf(marker, a); // locate patch start position from the start of the file
                       a=a+2;                      // offset is set in front of marker
                   };

                   QString type = "g5l";
                   fileDialog *dialog = new fileDialog(fileName, patchList, data, default_data, type);
                   dialog->exec();
                   patchIndex(this->index);
               };

               marker = data.mid(170, 2);                 //copy marker key to find "06A5" which marks the start of each patch block
               unsigned int a = data.indexOf(marker, 0);  // locate patch start position from the start of the file
               a=a+2;                                     // offset is set in front of marker
               if (patchCount>1)
               {
                   int q=index-1;
                   for (int h=0;h<q;h++)
                   {
                       a = data.indexOf(marker, a);          // locate patch start position from the start of the file
                       a=a+2;
                   };                                     // offset is set in front of marker
               };
               QByteArray temp;
               temp = data.mid(a, 128);
               default_data.replace(11, 128, temp);       //address "00" +
               temp = data.mid(a+128, 128);
               default_data.replace(152, 128, temp);      //address "01" +
               temp = data.mid(a+256, 128);
               default_data.replace(293, 128, temp);      //address "02" +
               temp = data.mid(a+384, 128);
               default_data.replace(434, 128, temp);      //address "03" +
               temp = data.mid(a+512, 128);
               default_data.replace(575, 128, temp);      //address "04" +
               temp = data.mid(a+640, 86);
               default_data.replace(716, 86, temp);       //address "05" +
               temp = data.mid(a+768, 128);
               default_data.replace(815, 128, temp);      //address "06" +
               temp = data.mid(a+896, 128);
               default_data.replace(956, 128, temp);      //address "07" +
               temp = data.mid(a+1024, 128);
               default_data.replace(1097, 128, temp);     //address "08" +
               temp = data.mid(a+1152, 100);
               default_data.replace(1238, 100, temp);     //address "09" +
               temp = data.mid(a+1280, 128);
               default_data.replace(1351, 128, temp);     //address "0A" +
               temp = data.mid(a+1408, 128);
               default_data.replace(1492, 128, temp);     //address "0B" +
               temp = data.mid(a+1536, 128);
               default_data.replace(1633, 128, temp);     //address "0C" +

               // copy user text, first two sections only, sections seperated/terminated by "00"
               temp = data.mid(32, 1);                    //copy "00"
               int z = a+1701;                            //start position of first text dialog.
               int y = data.indexOf( temp, (a+1701));     //end position of first text dialog.
               int x = data.indexOf( temp, (a+1701)) + 1; //start position of second text dialog.
               int w = data.indexOf( temp, (x+1));        //end position of second text dialog.
               temp = data.mid(z, (y-z) );                //copy first text dialog.
               marker = data.mid(31, 1);                  //copy "20"
               if ((y-z)>2 )
               {
                   for (int u = (128-(y-z));u>0; u--)
                   { temp.append(marker); };
                   if (temp.size()>128) {temp=temp.mid(0, 128); };
                   default_data.replace(1774, 128, temp);   // paste text 1
               };
               temp = data.mid(x, (w-x) );
               if ((w-x)>2 )
               {
                   for (int u = (32-(w-x));u>0; u--)
                   { temp.append(marker); };
                   if (temp.size()>32) {temp=temp.mid(0, 32); };
                   default_data.replace(1915, 32, temp);    // paste text 2
               };

               if (index>0)
               {
                   SysxIO *sysxIO = SysxIO::Instance();
                   QString area = "Structure";
                   sysxIO->setFileSource(area, default_data);
                   sysxIO->setFileName(this->fileName);
                   this->fileSource = sysxIO->getFileSource();
                   return true;
               } else { return false; };
           }
           else
           {
               QMessageBox *msgBox = new QMessageBox();
               msgBox->setWindowTitle(QObject::tr("Patch size Error!"));
               msgBox->setIcon(QMessageBox::Warning);
               msgBox->setTextFormat(Qt::RichText);
               QString msgText;
               msgText.append("<font size='+1'><b>");
               msgText.append(QObject::tr("This is not a ") + deviceType + QObject::tr(" patch!"));
               msgText.append("<b></font><br>");
               msgText.append(QObject::tr("Patch size is not ") + (QString::number(patchSize, 10)) + QObject::tr(" bytes, please try another file."));
               msgText.append(QObject::tr("size reported to be ") + (QString::number(data.size(), 10)) + QObject::tr(" bytes."));
               msgBox->setText(msgText);
               msgBox->setStandardButtons(QMessageBox::Ok);
               msgBox->exec();
               return false;
           };
       }
    else
    {
        return false;
    };
};

void sysxWriter::patchIndex(int listIndex)
{
    SysxIO *sysxIO = SysxIO::Instance();
    this->index=sysxIO->patchListValue;
};

void sysxWriter::writeFile(QString fileName)
{
    QFile file(fileName);
    if (file.open(QIODevice::WriteOnly))
    {
        SysxIO *sysxIO = SysxIO::Instance();
        this->fileSource = sysxIO->getFileSource();

        QByteArray out;
        unsigned int count=0;
        for (QList< QList<QString> >::iterator dev = fileSource.hex.begin(); dev != fileSource.hex.end(); ++dev)
        {
            QList<QString> data(*dev);
            for (QList<QString>::iterator code = data.begin(); code != data.end(); ++code)
            {
                QString str(*code);
                bool ok;
                unsigned int n = str.toInt(&ok, 16);
                out[count] = (char)n;
                count++;
            };
        };
        file.write(out);
    };

};

void sysxWriter::writeSystemFile(QString fileName)
{
    QFile file(fileName);
    if (file.open(QIODevice::WriteOnly))
    {
        SysxIO *sysxIO = SysxIO::Instance();
        this->systemSource = sysxIO->getSystemSource();

        QByteArray out;
        unsigned int count=0;
        for (QList< QList<QString> >::iterator dev = systemSource.hex.begin(); dev != systemSource.hex.end(); ++dev)
        {
            QList<QString> data(*dev);
            for (QList<QString>::iterator code = data.begin(); code != data.end(); ++code)
            {
                QString str(*code);
                bool ok;
                unsigned int n = str.toInt(&ok, 16);
                out[count] = (char)n;
                count++;
            };
        };
        file.write(out);
    };

};

void sysxWriter::writeSMF(QString fileName)
{
    QFile file(fileName);
    if (file.open(QIODevice::WriteOnly))
    {
        SysxIO *sysxIO = SysxIO::Instance();
        this->fileSource = sysxIO->getFileSource();

        QByteArray out;
        unsigned int count=0;
        for (QList< QList<QString> >::iterator dev = fileSource.hex.begin(); dev != fileSource.hex.end(); ++dev)
        {
            QList<QString> data(*dev);
            for (QList<QString>::iterator code = data.begin(); code != data.end(); ++code)
            {
                QString str(*code);
                bool ok;
                unsigned int n = str.toInt(&ok, 16);
                out[count] = (char)n;
                count++;
            };
        };

        QByteArray temp;                        // TRANSLATION of GR-55 PATCHES, data read from syx patch **************
        QByteArray Qhex;                        // and replace syx headers with mid data and new addresses**************
        QFile hexfile(":HexLookupTable.hex");   // use a QByteArray of hex numbers from a lookup table.
        if (hexfile.open(QIODevice::ReadOnly))
        {	Qhex = hexfile.readAll(); };

        temp = Qhex.mid((288), 30);
        out.remove(1763, 282);       //remove user text from end
        out.prepend(temp);          // insert midi timing header
        out.remove(30, 11);         // remove address "00 00" header
        temp = Qhex.mid((320), 13);
        out.insert(30, temp);       // insert new address "00 00" header
        out.remove(171, 13);        // remove address "01 00" header
        temp = Qhex.mid((336), 16);
        out.insert(285, temp);      // insert new address "01 72" header
        out.remove(315, 13);        // remove address "02 00" header
        out.remove(443, 13);        // remove address "03 00" header
        temp = Qhex.mid((352), 16);
        out.insert(543, temp);      // insert new address "03 64" header
        out.remove(587, 13);        // remove address "04 00" header
        out.remove(715, 13);        // remove address "05 00" header
        temp = Qhex.mid((368), 16);
        out.insert(801, temp);      // insert new address "05 56" header
        out.remove(817, 13);        // remove address "06 00" header
        out.remove(945, 13);        // remove address "07 00" header
        temp = Qhex.mid((438), 42);  // copy 42 x extra "00"
        out.insert(817, temp);      // insert 42 x extra "00"
        temp = Qhex.mid((384), 16);
        out.insert(1059, temp);      // insert new address "07 48" header
        out.remove(1131, 13);        // remove address "08 00" header
        out.remove(1259, 13);        // remove address "09 00" header
        temp = Qhex.mid((400), 16);
        out.insert(1317, temp);      // insert new address "09 3A" header
        out.remove(1375, 13);        // remove address "0A 00" header
        out.remove(1503, 13);        // remove address "0B 00" header
        out.remove(1631, 13);        // remove address "0C 00" header
        temp = Qhex.mid((438), 28);  // copy 28 x extra "00"
        out.insert(1375, temp);      // insert 28 x extra "00"
        temp = Qhex.mid((416), 16);
        out.insert(1575, temp);      // insert new address "0B 2C" header
        out.remove(1803, 2);        // remove file footer
        temp = Qhex.mid((438), 29);  // copy 29 x extra "00"
        out.insert(1803, temp);      // insert 28 x extra "00"
        temp = Qhex.mid((432), 3);
        out.insert(1832, temp);      // insert new file footer (part of)
        out.remove(0, 29);           // remove header again for checksum calcs
        out.remove(1835, 70);

        this->fileSource.address.clear();
        this->fileSource.hex.clear();

        QList<QString> sysxBuffer;
        int dataSize = 0; int offset = 0;
        for(int i=0;i<out.size();i++)
        {
            unsigned char byte = (char)out[i];
            unsigned int n = (int)byte;
            QString hex = QString::number(n, 16).toUpper();
            if (hex.length() < 2) hex.prepend("0");
            sysxBuffer.append(hex);

            unsigned char nextbyte = (char)out[i+1];
            unsigned int nextn = (int)nextbyte;
            QString nexthex = QString::number(nextn, 16).toUpper();
            if (nexthex.length() < 2) nexthex.prepend("0");
            if(offset >= checksumOffset+3 && nexthex != "F7")   // smf offset is 8 bytes + previous byte
            {
                dataSize += n;
            };
            if(nexthex == "F7")
            {
                QString checksum;
                bool ok;
                int dataSize = 0;
                for(int i=checksumOffset+3;i<sysxBuffer.size()-1;++i)
                { dataSize += sysxBuffer.at(i).toInt(&ok, 16); };
                QString base = "80";
                int sum = dataSize % base.toInt(&ok, 16);
                if(sum!=0) sum = base.toInt(&ok, 16) - sum;
                checksum = QString::number(sum, 16).toUpper();
                if(checksum.length()<2) checksum.prepend("0");
                sysxBuffer.replace(sysxBuffer.size() - 1, checksum);

            };
            offset++;

            if(hex == "F7")
            {
                this->fileSource.address.append( sysxBuffer.at(sysxAddressOffset + 5) + sysxBuffer.at(sysxAddressOffset + 6) );
                this->fileSource.hex.append(sysxBuffer);
                sysxBuffer.clear();
                dataSize = 0;
                offset = 0;
            };
        };


        out.clear();
        count=0;
        for (QList< QList<QString> >::iterator dev = fileSource.hex.begin(); dev != fileSource.hex.end(); ++dev)
        {
            QList<QString> data(*dev);
            for (QList<QString>::iterator code = data.begin(); code != data.end(); ++code)
            {
                QString str(*code);
                bool ok;
                unsigned int n = str.toInt(&ok, 16);
                out[count] = (char)n;
                count++;
            };
        };
        temp = Qhex.mid((288), 29);           // place smf header after checksum is added
        out.prepend(temp);
        temp = Qhex.mid((435), 4);             // place smf footer after "F7" EOF
        out.append(temp);
        file.write(out);
    };
};

void sysxWriter::writeG5L(QString fileName)
{
    QFile file(fileName);
    if (file.open(QIODevice::WriteOnly))
    {
        SysxIO *sysxIO = SysxIO::Instance();
        this->fileSource = sysxIO->getFileSource();

        QByteArray out;
        unsigned int count=0;
        for (QList< QList<QString> >::iterator dev = fileSource.hex.begin(); dev != fileSource.hex.end(); ++dev)
        {
            QList<QString> data(*dev);
            for (QList<QString>::iterator code = data.begin(); code != data.end(); ++code)
            {
                QString str(*code);
                bool ok;
                unsigned int n = str.toInt(&ok, 16);
                out[count] = (char)n;
                count++;
            };
        };
        QByteArray G5L_default;
        QByteArray temp;
        int a = 172;
        QFile G5Lfile(":default.g5l");           // Read the default GR-55 G5L file .
        if (G5Lfile.open(QIODevice::ReadOnly))
        { G5L_default = G5Lfile.readAll(); };
        temp = out.mid(11, 128);
        G5L_default.replace(a, 128, temp);         //address "00"
        temp = out.mid(152, 128);
        G5L_default.replace(a+128, 128, temp);     //address "01"
        temp = out.mid(293, 128);
        G5L_default.replace(a+256, 128, temp);     //address "02"
        temp = out.mid(434, 128);
        G5L_default.replace(a+384, 128, temp);     //address "03"
        temp = out.mid(575, 128);
        G5L_default.replace(a+512, 128, temp);     //address "04"
        temp = out.mid(716, 86);
        G5L_default.replace(a+640, 86, temp);      //address "05"
        temp = out.mid(815, 128);
        G5L_default.replace(a+768, 128, temp);     //address "06"
        temp = out.mid(956, 128);
        G5L_default.replace(a+896, 128, temp);     //address "07"
        temp = out.mid(1097, 128);
        G5L_default.replace(a+1024, 128, temp);    //address "08"
        temp = out.mid(1238, 100);
        G5L_default.replace(a+1152, 100, temp);    //address "09"
        temp = out.mid(1351, 128);
        G5L_default.replace(a+1280, 128, temp);    //address "0A"
        temp = out.mid(1492, 128);
        G5L_default.replace(a+1408, 128, temp);    //address "0B"
        temp = out.mid(1633, 128);
        G5L_default.replace(a+1536, 128, temp);    //address "0C"
        // copy user text, first two sections only, section terminated by "00"
        QByteArray marker = G5L_default.mid(32, 1);     //copy "00" for position marker.
        //int z = a+1701;
        //int y = G5L_default.indexOf( marker, (a+1701));

        temp = out.mid(1774, 128 );   // copy first text section from patch
        //G5L_default.replace(a+1701, (y-z), temp);       // paste text 1
        G5L_default.replace(a+1701, 128, temp);       // paste text 1

        //int x = G5L_default.indexOf( marker, (y+1));
        //int w = G5L_default.indexOf( marker, (x+1));

        temp = out.mid(1915, 32 );     // copy second text section from patch
        //G5L_default.replace(x+1, (w-x), temp);          // paste text 2
        G5L_default.replace(a+1830, 32, temp);          // paste text 2

        file.write(G5L_default);
    };
};

SysxData sysxWriter::getFileSource()
{
    return fileSource;
};

SysxData sysxWriter::getSystemSource()
{
    return systemSource;
};

QString sysxWriter::getFileName()
{
    return fileName;
};

