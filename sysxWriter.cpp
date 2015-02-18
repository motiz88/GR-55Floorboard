/****************************************************************************
**
** Copyright (C) 2007~2013 Colin Willcocks.
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
#include <QTimer>

sysxWriter::sysxWriter()
{

}

sysxWriter::~sysxWriter()
{

}

void sysxWriter::setFile(QString fileName)
{
    this->fileName = fileName;
    this->fileSource.address.clear();
    this->fileSource.hex.clear();
}

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
        QByteArray SMF_header = hextable.mid(144,18);
        QByteArray SMF_file = data.mid(0, 18);
        bool isHeader = false;
        if (default_header == file_header) {isHeader = true;};
        bool isG5L = false;
        if (data.contains(G5L_header)){isG5L = true; };             // see if file is a G5L type and set isG5L flag.
        bool isSMF = false;
        if (data.contains(SMF_header)) {isSMF = true; };
        if((data.size() == 1186 || data.size() == 52002) && isHeader == true){ // if GR-55 system file size is correct- load file.
            SysxIO *sysxIO = SysxIO::Instance();
            QString area = "System";
            sysxIO->setFileSource(area, data);
            this->systemSource = sysxIO->getSystemSource();
            return true;
        }
        else if(data.size() == 1333 && isHeader == true){         //1333 if GR-55 standard patch file size is correct- load file >>>  currently at 1763 bytes.

            SysxIO *sysxIO = SysxIO::Instance();
            QString area = "Structure";
            sysxIO->setFileSource(area, data);
            sysxIO->setFileName(this->fileName);
            this->fileSource = sysxIO->getFileSource();
            return true;
        }
        else if (isSMF)                      // SMF ******************************************************************
        {                                        // file contains a .mid type SMF patch file header from ROLAND Librarian
            QByteArray smf_data = data;
            QFile file(":default.syx");              // Read the default GR-55 sysx file so we don't start empty handed.
            if (file.open(QIODevice::ReadOnly))
            {	data = file.readAll(); };
            QByteArray temp;                         // TRANSLATION of GR-55 SMF PATCHES, data read from smf patch **************

            if ( smf_data.at(30) != data.at(5) ){    // check if a valid GR-55 file
                QMessageBox *msgBox = new QMessageBox();
                msgBox->setWindowTitle(QObject::tr("SMF file import"));
                msgBox->setIcon(QMessageBox::Warning);
                msgBox->setTextFormat(Qt::RichText);
                QString msgText;
                msgText.append("<font size='+1'><b>");
                msgText.append(QObject::tr("This is not a GR-55 patch!"));
                msgText.append("<b></font><br>");
                msgText.append(QObject::tr("*Loading this file may have unpredictable results*."));
                msgBox->setText(msgText);
                msgBox->show();
                QTimer::singleShot(3000, msgBox, SLOT(deleteLater()));
            };

            index = 1;
            int patchCount = (smf_data.size()-26)/1320;
            if (patchCount>1)
            {
                QString msgText;
                QString patchText;
                QString patchNumber;
                unsigned char r;
                this->patchList.clear();
                this->patchList.append(QObject::tr("Select Patch"));
                unsigned int a = 36; // locate patch text start position from the start of the file
                for (int h=0;h<patchCount;h++)
                {
                    for (int b=1;b<17;b++)
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
                    a=a+1320;                      // offset is set in front of marker
                };

                QString type = "smf";
                fileDialog *dialog = new fileDialog(fileName, patchList, data, default_data, type);
                dialog->exec();
                dialog->deleteLater();
                patchIndex(this->index);
            };

            int a=0;
            if (patchCount>1)
            {
                int q=index-1;      // find start of required patch
                a = q*1320;
            };
            data.replace(11, 128, smf_data.mid(a+36, 128));   //Address 00 00
            data.replace(152, 114, smf_data.mid(a+164, 114)); //Address 00 00
            data.replace(266, 14, smf_data.mid(a+293, 14));   //Address 01 72
            data.replace(293, 78, smf_data.mid(a+307, 78));   //Address 01 72
            data.replace(384, 128, smf_data.mid(a+401, 128)); //Address 03 00
            data.replace(525, 114, smf_data.mid(a+529, 114)); //Address 03 00
            data.replace(639, 14, smf_data.mid(a+658, 14));   //Address 04 72
            data.replace(666, 18, smf_data.mid(a+672, 18));   //Address 04 72
            data.replace(697, 30, smf_data.mid(a+705, 30));   //Address 06 00
            data.replace(740, 125, smf_data.mid(a+751, 125)); //Address 07 00
            data.replace(878, 128, smf_data.mid(a+892, 128)); //Address 10 00
            data.replace(1019, 86, smf_data.mid(a+1020, 86)); //Address 11 00
            data.replace(1118, 35, smf_data.mid(a+1121, 35)); //Address 20 00
            data.replace(1166, 35, smf_data.mid(a+1171, 35)); //Address 21 00
            data.replace(1214, 52, smf_data.mid(a+1221, 52)); //Address 30 00
            data.replace(1279, 52, smf_data.mid(a+1288, 52)); //Address 31 00

            if (index>0)
            {
                SysxIO *sysxIO = SysxIO::Instance();
                QString area = "Structure";
                sysxIO->setFileSource(area, data);
                sysxIO->setFileName(this->fileName);
                this->fileSource = sysxIO->getFileSource();
                return true;
            } else {return false; }
        }
        else if (isG5L)      // if the read file is a ROLAND Librarian type. ***************************************
        {
            index=1;
            unsigned char msb = (char)data[34];     // find patch count msb bit in G5L file at byte 34
            unsigned char lsb = (char)data[35];     // find patch count lsb bit in G5L file at byte 35
            bool ok;
            int patchCount;
            patchCount = (256*QString::number(msb, 16).toUpper().toInt(&ok, 16)) + (QString::number(lsb, 16).toUpper().toInt(&ok, 16));
           if (patchCount>1)
            {
                int m_step = 162;
                unsigned int a = m_step + 10;
                QString msgText;
                QString patchText;
                QString patchNumber;
                this->patchList.clear();
                this->patchList.append(QObject::tr("Select Patch"));
                for (int h=0;h<patchCount;h++)
                {
                    for (int b=1;b<17;b++)
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
                    msb = (char)data[m_step];     // find patch size msb bit
                    lsb = (char)data[m_step+1];   // find patch size lsb bit and calculate jump to next patch.
                    m_step = m_step+4+(256*QString::number(msb, 16).toUpper().toInt(&ok, 16)) + (QString::number(lsb, 16).toUpper().toInt(&ok, 16));
                    a = m_step + 10;   // move to start of patch
                };

                QString type = "g5l";
                fileDialog *dialog = new fileDialog(fileName, patchList, data, default_data, type);
                dialog->exec();
                dialog->deleteLater();
                patchIndex(this->index);
            };

             int m_step = 162;
             unsigned int a = m_step + 10;                                   // offset is set in front of marker
            if (patchCount>1)
            {
                int q=index-1;
                for (int h=0;h<q;h++)
                {
                    msb = (char)data[m_step];     // find patch size msb bit
                    lsb = (char)data[m_step+1];   // find patch size lsb bit and calculate jump to next patch.
                    m_step = m_step+4+(256*QString::number(msb, 16).toUpper().toInt(&ok, 16)) + (QString::number(lsb, 16).toUpper().toInt(&ok, 16));
                    a = m_step + 10;   // move to start of patch
                };                                     // offset is set in front of marker
            };
            QByteArray temp;            //*.G5L FORMAT READ CONVERSION
            temp = data.mid(a, 128);
            default_data.replace(11, 128, temp);      //address "00"
            temp = data.mid(a+128, 114);
            default_data.replace(152, 114, temp);     //address "01"
            temp = data.mid(a+252, 12);
            default_data.replace(268, 12, temp);     //address "01"
            temp = data.mid(a+264, 78);
            default_data.replace(293, 78, temp);     //address "02" +
            temp = data.mid(a+350, 128);
            default_data.replace(384, 128, temp);     //address "03" +
            temp = data.mid(a+478, 72);
            default_data.replace(525, 72, temp);     //address "04" +
            temp = data.mid(a+606, 18);
            default_data.replace(666, 18, temp);     //address "05" +
            temp = data.mid(a+640, 30);
            default_data.replace(697, 30, temp);     //address "06" +
            temp = data.mid(a+678, 125);
            default_data.replace(740, 125, temp);     //address "07" +
            temp = data.mid(a+811, 128);
            default_data.replace(878, 128, temp);     //address "10" +
            temp = data.mid(a+939, 86);
            default_data.replace(1019, 86, temp);     //address "11" +
            temp = data.mid(a+1033, 35);
            default_data.replace(1118, 35, temp);    //address "20" +
            temp = data.mid(a+1072, 35);
            default_data.replace(1166, 35, temp);    //address "21" +
            temp = data.mid(a+1115, 52);
            default_data.replace(1214, 52, temp);    //address "30" +
            temp = data.mid(a+1171, 52);
            default_data.replace(1279, 52, temp);    //address "31" +

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
            msgBox->show();
            QTimer::singleShot(3000, msgBox, SLOT(deleteLater()));
            return false;
        };
    }
    else
    {
        return false;
    };
}

void sysxWriter::patchIndex(int listIndex)
{
    SysxIO *sysxIO = SysxIO::Instance();
    this->index=sysxIO->patchListValue;
}

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

}

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
}

void sysxWriter::writeSMF(QString fileName)
{
    QFile file(fileName);
    if (file.open(QIODevice::WriteOnly))
    {
        SysxIO *sysxIO = SysxIO::Instance();
        this->fileSource = sysxIO->getFileSource();

        QByteArray syx;
        unsigned int count=0;
        for (QList< QList<QString> >::iterator dev = fileSource.hex.begin(); dev != fileSource.hex.end(); ++dev)
        {
            QList<QString> data(*dev);
            for (QList<QString>::iterator code = data.begin(); code != data.end(); ++code)
            {
                QString str(*code);
                bool ok;
                unsigned int n = str.toInt(&ok, 16);
                syx[count] = (char)n;                   // copy current filesource patch and convert to QByteArray
                count++;
            };
        };

        QByteArray header;                        // TRANSLATION of GR-55 PATCHES
        QByteArray footer;
        QByteArray smf;                        // and replace syx headers with mid data and new addresses**************
        QFile smffile(":default.mid");         // use default smf file and replace patch data
        if (smffile.open(QIODevice::ReadOnly))
        {	smf = smffile.readAll(); };
        header = smf.mid(0,22);
        footer = smf.mid(1342,4);
        smf.replace(36, 128, syx.mid(11, 128));   //Address 00 00
        smf.replace(164, 114, syx.mid(152, 114)); //Address 00 00
        smf.replace(293, 14, syx.mid(266, 14));   //Address 01 72
        smf.replace(307, 78, syx.mid(293, 78));   //Address 01 72
        smf.replace(401, 128, syx.mid(384, 128)); //Address 03 00
        smf.replace(529, 114, syx.mid(525, 114)); //Address 03 00
        smf.replace(658, 14, syx.mid(639, 14));   //Address 04 72
        smf.replace(672, 18, syx.mid(666, 18));   //Address 04 72
        smf.replace(705, 30, syx.mid(697, 30));   //Address 06 00
        smf.replace(751, 125, syx.mid(740, 125)); //Address 07 00
        smf.replace(892, 128, syx.mid(878, 128)); //Address 10 00
        smf.replace(1020, 86, syx.mid(1019, 86)); //Address 11 00
        smf.replace(1121, 35, syx.mid(1118, 35)); //Address 20 00
        smf.replace(1171, 35, syx.mid(1166, 35)); //Address 21 00
        smf.replace(1221, 52, syx.mid(1214, 52)); //Address 30 00
        smf.replace(1288, 52, syx.mid(1279, 52)); //Address 31 00

        smf.remove(1342, 4);      // remove file footer
        smf.remove(0, 22);        // remove File header

        QString rebuild;
        QString sysxBuffer;
        QString checksum;
        int dataSize = 110; int offset = 0;
        for(int i=0;i<smf.size();i++)
        {
            unsigned char byte = (char)smf[i];
            unsigned int n = (int)byte;
            QString hex = QString::number(n, 16).toUpper();
            if (hex.length() < 2) hex.prepend("0");
            sysxBuffer.append(hex);

            unsigned char nextbyte = (char)smf[i+1];
            unsigned int nextn = (int)nextbyte;
            QString nexthex = QString::number(nextn, 16).toUpper();
            if (nexthex.length() < 2) nexthex.prepend("0");

            if(offset >= 9 && nexthex != "F7")   // smf offset is 8 bytes + previous byte
            {
                dataSize += n;
            }

            else if(nexthex == "F7")
            {      
                int sum = dataSize % 128;
                if(sum!=0) { sum = 128 - sum; };
                checksum = QString::number(sum, 16).toUpper();
                if(checksum.length()<2) { checksum.prepend("0"); };
            };

            if(hex == "F7")
            {
                sysxBuffer.replace(sysxBuffer.size()-4, 2, checksum);  // replace checksum with calculated value
                rebuild.append(sysxBuffer);
                sysxBuffer.clear();
                dataSize = 110;
                offset = 0;
            };
             ++offset;
        };
        smf.clear();
        for (int k=0; k<rebuild.size(); k++)
        {
            bool ok;
            unsigned int n = rebuild.mid(k, 2).toInt(&ok, 16);
            smf[k/2] = (char)n;
            ++k;
        };
        smf.prepend(header);
        smf.append(footer);             // place smf footer after "F7" EOF
        file.write(smf);
    };
}

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
        int a = 172;
        QFile G5Lfile(":default.g5l");           // Read the default GR-55 G5L file .
        if (G5Lfile.open(QIODevice::ReadOnly))
        { G5L_default = G5Lfile.readAll(); };

        G5L_default.replace(a, 128, out.mid(11, 128));          //address "00"
        G5L_default.replace(a+128, 114, out.mid(152, 114));     //address "01"
        G5L_default.replace(a+252, 12, out.mid(268, 12));       //address "01 B"
        G5L_default.replace(a+264, 78, out.mid(293, 78));       //address "02"
        G5L_default.replace(a+350, 128, out.mid(384, 128));     //address "03"
        G5L_default.replace(a+478, 72, out.mid(525, 72));       //address "04"
        G5L_default.replace(a+606, 18, out.mid(666, 18));       //address "05"
        G5L_default.replace(a+640, 30, out.mid(697, 30));       //address "06"
        G5L_default.replace(a+678, 125, out.mid(740, 125));     //address "07"
        G5L_default.replace(a+811, 128, out.mid(878, 128));     //address "10"
        G5L_default.replace(a+939, 86, out.mid(1019, 86));      //address "11"
        G5L_default.replace(a+1033, 35, out.mid(1118, 35));     //address "20"
        G5L_default.replace(a+1072, 35, out.mid(1166, 35));     //address "21"
        G5L_default.replace(a+1115, 52, out.mid(1214, 52));     //address "30"
        G5L_default.replace(a+1171, 52, out.mid(1279, 52));     //address "31"
        file.write(G5L_default);
    };
}

SysxData sysxWriter::getFileSource()
{
    return fileSource;
}

SysxData sysxWriter::getSystemSource()
{
    return systemSource;
}

QString sysxWriter::getFileName()
{
    return fileName;
}


/* QString snork;
 snork.append("<font size='-1'>");
 snork.append("{ size=");
 snork.append(QString::number(sysxBuffer.size()/2, 10));
 snork.append("}");
 snork.append("<br>{ checksum="+checksum+" }");

 snork.append("<br> midi data received");
 for(int i=0;i<sysxBuffer.size();++i)
 {
     bool ok;
     unsigned char byte = (char)sysxBuffer.mid(i, 2).toInt(&ok, 16);
     unsigned int n = (int)byte;
     QString hex = QString::number(n, 16).toUpper();
     if (hex.length() < 2) hex.prepend("0");
     snork.append(hex);
     snork.append(" ");
     ++i;
 };
 snork.replace("F7", "F7 } <br>");
 snork.replace("F0", "{ F0");
 QMessageBox *msgBox = new QMessageBox();
 msgBox->setWindowTitle("dBug Result for re-formatted GR-55 patch data");
 msgBox->setIcon(QMessageBox::Information);
 msgBox->setText(snork);
 msgBox->setStandardButtons(QMessageBox::Ok);
 msgBox->exec();
msgBox->deleteLater();*/
