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

#include <QtGui>
#include <QFile>
#include <QDataStream>
#include <QByteArray>
#include <QMessageBox>
#include "bulkSaveDialog.h"
#include "Preferences.h"
#include "globalVariables.h"


// Platform-dependent sleep routines.
#ifdef Q_OS_WIN
  #include <windows.h>
  #define SLEEP( milliseconds ) Sleep( (DWORD) milliseconds ) 
#else // Unix variants & Mac
  #include <unistd.h>
  #define SLEEP( milliseconds ) usleep( (unsigned long) (milliseconds * 1000.0) )
#endif

bulkSaveDialog::bulkSaveDialog()
{ 
  QLabel *startRangeLabel = new QLabel(tr("Start Bank."));
	QLabel *finishRangeLabel = new QLabel(tr("Finish Bank."));
	
  this->g5lButton = new QRadioButton(tr("*.g5l Librarian file"), this );
  this->syxButton = new QRadioButton(tr("*.syx System Exclusive file"), this );
  this->midButton = new QRadioButton(tr("*.mid Standard Midi (SMF) file"), this );
  this->g5lButton->setChecked(true);
    
	QCheckBox *systemCheckBox = new QCheckBox(tr("Save System Data"));
	QSpinBox *startRangeSpinBox = new QSpinBox;
	QSpinBox *finishRangeSpinBox = new QSpinBox;

	this->systemCheckBox = systemCheckBox;
		
	this->startRangeSpinBox = startRangeSpinBox;
	startRangeSpinBox->setValue(1);
	startRangeSpinBox->setRange(1, 50);
	startRangeSpinBox->setPrefix(tr("Start at U"));
	startRangeSpinBox->setSuffix("-1");

	this->finishRangeSpinBox = finishRangeSpinBox;
	finishRangeSpinBox->setValue(50);    
	finishRangeSpinBox->setRange(1, 50);
	finishRangeSpinBox->setPrefix(tr("Finish at U"));
	finishRangeSpinBox->setSuffix("-4");

	QVBoxLayout *rangeLabelLayout = new QVBoxLayout;
	rangeLabelLayout->addSpacing(12);
	rangeLabelLayout->addWidget(startRangeLabel);
	rangeLabelLayout->addWidget(finishRangeLabel);

	QVBoxLayout *rangeBoxLayout = new QVBoxLayout;
	//rangeBoxLayout->addWidget(systemCheckBox);
	rangeBoxLayout->addSpacing(12);
	rangeBoxLayout->addWidget(startRangeSpinBox);
	rangeBoxLayout->addSpacing(12);
	rangeBoxLayout->addWidget(finishRangeSpinBox);

	QHBoxLayout *dataRangeLayout = new QHBoxLayout;
	dataRangeLayout->addSpacing(20);
	dataRangeLayout->addLayout(rangeLabelLayout);
	//dataRangeLayout->addSpacing(12);
	dataRangeLayout->addLayout(rangeBoxLayout);
	dataRangeLayout->addSpacing(20);

	QGroupBox *patchRangeGroup = new QGroupBox(tr("Set range of Patch data to save"));
  patchRangeGroup->setLayout(dataRangeLayout);

  this->startButton = new QPushButton(this);
  this->startButton->setText(tr("Start"));
  connect(startButton, SIGNAL(clicked()), this, SLOT(backup()));
  
  this->completedButton = new QPushButton(this);
  this->completedButton->setText(tr("DATA TRANSFER COMPLETED"));
  this->completedButton->hide();
  connect(completedButton, SIGNAL(clicked()), this, SLOT(close()));
  
	this->cancelButton = new QPushButton(this);
	this->cancelButton->setText(tr("Cancel"));
  connect(cancelButton, SIGNAL(clicked()), this, SLOT(close()));
  
  this->progressLabel = new QLabel(this);
  this->progressLabel->setText(tr("Full Backup may take up to 2 minutes"));
  this->bytesLabel = new QLabel(this);
  this->bytesLabel->setText("");
  
  this->progressBar = new QProgressBar(this);
	this->progressBar->setTextVisible(false);
	this->progressBar->setRange(0, 100);
	this->progressBar->setValue(0);  
	
	QVBoxLayout *fileFormatLayout = new QVBoxLayout;
	fileFormatLayout->addStretch(1);
	fileFormatLayout->addSpacing(6);
	fileFormatLayout->addWidget(g5lButton);
	fileFormatLayout->addStretch(1);
	fileFormatLayout->addSpacing(6);
	fileFormatLayout->addWidget(syxButton);
	fileFormatLayout->addStretch(1);
	fileFormatLayout->addSpacing(6);
	fileFormatLayout->addWidget(midButton);
	fileFormatLayout->addSpacing(6);
	 QGroupBox *fileFormatGroup = new QGroupBox(tr("Select File format to save"));
  fileFormatGroup->setLayout(fileFormatLayout);
 
	QHBoxLayout *buttonsLayout = new QHBoxLayout;
	buttonsLayout->addSpacing(40);
	buttonsLayout->addWidget(startButton);
	buttonsLayout->addStretch(1);
	buttonsLayout->addSpacing(20);
	buttonsLayout->addWidget(cancelButton);
	buttonsLayout->addSpacing(40);
	
	QHBoxLayout *progressBarLayout = new QHBoxLayout;	
	progressBarLayout->addWidget(progressBar);
	
	QVBoxLayout *mainLayout = new QVBoxLayout;
	mainLayout->addWidget(fileFormatGroup);
	mainLayout->addStretch(1);
	mainLayout->addSpacing(12);
	mainLayout->addLayout(buttonsLayout, Qt::AlignCenter);
	mainLayout->addStretch(1);
	mainLayout->addSpacing(12);
	mainLayout->addWidget(patchRangeGroup, Qt::AlignCenter);
	mainLayout->addStretch(1);
	mainLayout->addSpacing(12);
	mainLayout->addWidget(progressLabel, Qt::AlignCenter);
	
	mainLayout->addWidget(bytesLabel, Qt::AlignCenter);
	mainLayout->addStretch(1);
	mainLayout->addSpacing(12);
	mainLayout->addWidget(completedButton);
	mainLayout->addStretch(1);
	mainLayout->addSpacing(12);
	mainLayout->addLayout(progressBarLayout, Qt::AlignCenter);
	setLayout(mainLayout);

	setWindowTitle(tr("Bulk File Backup"));
	
        //QObject::connect(this, SIGNAL( startRangeSpinBox->valueChanged(int) ), this, SLOT( bankStart(int) ));
        //QObject::connect(this, SIGNAL( finishRangeSpinBox->valueChanged(int) ), this, SLOT( bankFinish(int) ));
	SysxIO *sysxIO = SysxIO::Instance();
	QObject::connect(this, SIGNAL(setStatusSymbol(int)), sysxIO, SIGNAL(setStatusSymbol(int)));
	QObject::connect(this, SIGNAL(setStatusProgress(int)), sysxIO, SIGNAL(setStatusProgress(int)));
	QObject::connect(this, SIGNAL(setStatusMessage(QString)), sysxIO, SIGNAL(setStatusMessage(QString)));	
  
};

void bulkSaveDialog::backup()
{
  this->startButton->hide();
  this->cancelButton->hide();
  this->bankStart = this->startRangeSpinBox->value();
  this->bankFinish = this->finishRangeSpinBox->value();
  if (bankFinish<bankStart) {bankFinish = bankStart; this->finishRangeSpinBox->setValue(bankStart); };
  this->bank=bankStart*4;
	bulk.clear();
	this->progress = 0;
	this->patch = 1;
	range = 200/(bankFinish-bankStart+1);
	requestPatch(bank/4, patch);  
};

void bulkSaveDialog::requestPatch(int bank, int patch) 
{	
SysxIO *sysxIO = SysxIO::Instance();
	if(sysxIO->isConnected() && sysxIO->deviceReady() )
	{
	  SysxIO *sysxIO = SysxIO::Instance();
		QObject::connect(sysxIO, SIGNAL(sysxReply(QString)), this, SLOT(updatePatch(QString)));					
		sysxIO->requestPatch(bank, patch);    		
	};
};

void bulkSaveDialog::updatePatch(QString replyMsg)
{
	SysxIO *sysxIO = SysxIO::Instance(); 
	QObject::disconnect(sysxIO, SIGNAL(sysxReply(QString)), this, SLOT(updatePatch(QString)));		
	sysxIO->setDeviceReady(true); // Free the device after finishing interaction.
	
	replyMsg = replyMsg.remove(" ").toUpper();       // TRANSLATE SYSX MESSAGE FORMAT to 128 byte data blocks 
		if (replyMsg.size()/2 == patchReplySize){
        QString header = "F0411000005312";
	QString footer ="00F7";
	QString addressMsb = replyMsg.mid(14,4);
	QString part1 = replyMsg.mid(22, 256); 
  part1.prepend("0000").prepend(addressMsb).prepend(header).append(footer);    
	QString part2 = replyMsg.mid(278, 228);
	QString part2B = replyMsg.mid(532, 28);
	part2.prepend("0100").prepend(addressMsb).prepend(header).append(part2B).append(footer); 
	QString part3 = replyMsg.mid(560, 256);
	part3.prepend("0200").prepend(addressMsb).prepend(header).append(footer);
	QString part4 = replyMsg.mid(816, 200);
	QString part4B = replyMsg.mid(1042, 56);
	part4.prepend("0300").prepend(addressMsb).prepend(header).append(part4B).append(footer); 
	QString part5 = replyMsg.mid(1098, 256);
	part5.prepend("0400").prepend(addressMsb).prepend(header).append(footer);   
	QString part6 = replyMsg.mid(1354, 172);   //
	part6.prepend("0500").prepend(addressMsb).prepend(header).append(footer);   
	QString part7 = replyMsg.mid(1552, 256);   // 0x308+128
	part7.prepend("0600").prepend(addressMsb).prepend(header).append(footer);   
	QString part8 = replyMsg.mid(1808, 228);  // 0x388+114
	QString part8B = replyMsg.mid(2062, 28);   // 
	part8.prepend("0700").prepend(addressMsb).prepend(header).append(part8B).append(footer); 
	QString part9 = replyMsg.mid(2090, 256);
	part9.prepend("0800").prepend(addressMsb).prepend(header).append(footer);
	QString part10 = replyMsg.mid(2346,200);    //
	part10.prepend("0900").prepend(addressMsb).prepend(header).append(footer);
	QString part11 = replyMsg.mid(2572, 256);
	part11.prepend("0A00").prepend(addressMsb).prepend(header).append(footer);
	QString part12 = replyMsg.mid(2828, 226);   //
	QString part12B = replyMsg.mid(3080, 30); 
	part12.prepend("0B00").prepend(addressMsb).prepend(header).append(part12B).append(footer);
	QString part13 = replyMsg.mid(3110, 256);
	part13.prepend("0C00").prepend(addressMsb).prepend(header).append(footer);
	
	replyMsg = "";
	replyMsg.append(part1).append(part2).append(part3).append(part4).append(part5).append(part6)
  .append(part7).append(part8).append(part9).append(part10).append(part11).append(part12).append(part13);
  /*QByteArray data;
  QFile file(":default.syx");   // Read the default GR-55 sysx file so we don't start empty handed.
    if (file.open(QIODevice::ReadOnly))
	  {	data = file.readAll(); };
	  QByteArray temp;                      
    temp = data.mid(1763, 282);           // copy patch description from default.syx  address 00 0D 00 00   
	
	QString sysxBuffer; 
	for(int i=0;i<temp.size();i++)
	{
		unsigned char byte = (char)temp[i];
		unsigned int n = (int)byte;
		QString hex = QString::number(n, 16).toUpper();     // convert QByteArray to QString
		if (hex.length() < 2) hex.prepend("0");
		sysxBuffer.append(hex);
  };
	replyMsg.append(sysxBuffer);   */
	
	QString reBuild = "";       // Add correct checksum to patch strings 
  QString sysxEOF = "";	
  QString hex = "";
  int msgLength = replyMsg.length()/2;
  for(int i=0;i<msgLength*2;++i) 
  {
	hex.append(replyMsg.mid(i*2, 2));
	sysxEOF = (replyMsg.mid((i*2)+4, 2));
  if (sysxEOF == "F7")
    {   
  	int dataSize = 0; bool ok;
	  for(int h=checksumOffset;h<hex.size()-1;++h)
	  { dataSize += hex.mid(h*2, 2).toInt(&ok, 16); };
	 	QString base = "80";                       // checksum calculate.
	  unsigned int sum = dataSize % base.toInt(&ok, 16);
  	if(sum!=0) { sum = base.toInt(&ok, 16) - sum; };
	  QString checksum = QString::number(sum, 16).toUpper();
	   if(checksum.length()<2) {checksum.prepend("0");};
      	hex.append(checksum);
        hex.append("F7");   
        reBuild.append(hex);   
    
		hex = "";
		sysxEOF = "";
		i=i+2;
    }; 
  };    
	replyMsg = reBuild.simplified().toUpper();	
	bulk.append(replyMsg); 	                                           // add patch to the bulk string.
	}; 	       
	      ++patch; 
        if(patch>4) {patch=1; bank=bank+4;};	                      // increment patch.
        progress=progress+range;
        bulkStatusProgress(this->progress);                         // advance the progressbar.
        int bf = (bankFinish+1)*4 -2;
  if (bank >= bf) 
      {                                                            // check if nearly finished.
        this->completedButton->show();        
        this->progressLabel->setText(tr("Bulk data transfer completed!!"));              
      };              
  if (bank<(bankFinish+1)*4 )
  {      
        bool ok;
        QString patchText;
        QString name = replyMsg.mid(22, 32);                       // get name from loaded patch. 
        QList<QString> x;        
        for (int b=0;b<16;b++)
        {
          x.append(name.mid(b*2, 2));       
        };
        for (int b=0;b<16;b++)
        {
        	QString hexStr = x.at(b);			
		      patchText.append( (char)(hexStr.toInt(&ok, 16)) );      // convert name to readable text characters.
        };
        
  QString patchNumber = QString::number(bank/4, 10).toUpper();
  if (patchNumber.size()<2) { patchNumber.prepend("0"); };
  patchNumber.prepend(tr("User Patch U"));
  patchNumber.append("-");
  patchNumber.append( QString::number(patch, 10).toUpper() );
  patchNumber.append("     ");
  patchNumber.append(patchText);
  patchText=patchNumber;   
  this->progressLabel->setText(patchText);                        //display the patch number and name.
  
  patchNumber = tr("File build size = ");
  int size = (bulk.size()/2)+fullPatchSize;
  patchNumber.append(QString::number(size, 10).toUpper() );
  patchNumber.append(tr(" bytes"));
  this->bytesLabel->setText(patchNumber);                         //display the bulk data size.
  
  setStatusMessage(tr("Bulk Download"));  
  requestPatch(bank/4, patch);                                   //request the next patch.
  } else {
  setStatusMessage(tr("Ready"));
  sysxIO->bulk = this->bulk;
  if (this->g5lButton->isChecked() ) { writeG5L(); };                      // format and write bulk patches.
  if (this->syxButton->isChecked() ) { writeSYX(); };
  if (this->midButton->isChecked() ) { writeSMF(); };
  };  
};

void bulkSaveDialog::bulkStatusProgress(int value)
{
   value=value/8;
  if (value >100) {value = 100;};
  if (value<0) {value = 0; };
	this->progressBar->setValue(value);
};

void bulkSaveDialog::writeG5L()         // ************************************ G5L File Format***************************
{	
  	Preferences *preferences = Preferences::Instance();
	          QString dir = preferences->getPreferences("General", "Files", "dir");

          	QString fileName = QFileDialog::getSaveFileName(
                    this,
                    tr("Save Bulk Data"),
                    dir,
                    tr("Librarian Backup File (*.g5l)"));
	             if (!fileName.isEmpty())	
                	{
	                  if(!fileName.contains(".g5l"))
	                     	{
		                    	fileName.append(".g5l");
	                     	};		
		
	QFile file(fileName);
    if (file.open(QIODevice::WriteOnly))
	{	
     bool ok;	
		QByteArray out;
		int size = this->bulk.size()/2;
	  int patchCount = size/patchSize;
		for (int x=0;x<size*2;x++)
		{
		   QString hexStr = bulk.mid(x, 2);
		   out.append( (char)(hexStr.toInt(&ok, 16)) );          // convert the bulk QString to a QByteArray.
		    ++x;
		};
		QByteArray bulkFile;
		QByteArray G5L_default;
		QByteArray temp;
		QFile G5Lfile(":default.g5l");           // Read the default GR-55B G5L file .
    if (G5Lfile.open(QIODevice::ReadOnly))
	  {	G5L_default = G5Lfile.readAll(); };
	  bulkFile.append(G5L_default.mid(0, 160));
	  int b = 0;
		for (int x=0;x<patchCount;x++)
		{  
   int a = 172;    
   temp = out.mid(b+11, 128);
   G5L_default.replace(a, 128, temp);         //address "00" +   
   temp = out.mid(b+152, 128);
   G5L_default.replace(a+128, 128, temp);     //address "01" +      
   temp = out.mid(b+293, 128);
   G5L_default.replace(a+256, 128, temp);     //address "02" +    
   temp = out.mid(b+434, 128);
   G5L_default.replace(a+384, 128, temp);     //address "03" +        
   temp = out.mid(b+575, 128);
   G5L_default.replace(a+512, 100, temp);     //address "04" +      no "04"     
   temp = out.mid(b+716, 86);
   G5L_default.replace(a+640, 86, temp);     //address "05" +           
   temp = out.mid(b+815, 128);
   G5L_default.replace(a+768, 128, temp);     //address "06" +       
   temp = out.mid(b+956, 128);
   G5L_default.replace(a+896, 128, temp);     //address "07" +      
   temp = out.mid(b+1097, 128);
   G5L_default.replace(a+1024, 128, temp);     //address "08" +      no "08"   
   temp = out.mid(b+1238, 100);
   G5L_default.replace(a+1152, 100, temp);    //address "09" +   
   temp = out.mid(b+1351, 128);
   G5L_default.replace(a+1280, 128, temp);    //address "0A" +        
   temp = out.mid(b+1492, 128);
   G5L_default.replace(a+1408, 128, temp);    //address "0B" +       
   temp = out.mid(b+1633, 128);
   G5L_default.replace(a+1536, 128, temp);    //address "0C" +
   temp.clear();
   QString hexStr = "06";
   temp.append((char)(hexStr.toInt(&ok, 16))); 
   hexStr = "B1";
   temp.append((char)(hexStr.toInt(&ok, 16)));   
   G5L_default.replace(162, 2, temp);     // replace patch size index
    
   b=b+patchSize;                                  // increment point to next *.syx patch in bulk.
   bulkFile.append(G5L_default.mid(160, 1713)); // copy most of the patch + index except for 4 text chars on end.
   bulkFile.append(G5L_default.mid(80, 4));     // copy 4 bytes of "00" from no-where special.
    };
    QString hex = QString::number(patchCount, 16).toUpper();     // convert integer to QString.
		if (hex.length() < 2) hex.prepend("0");
    QByteArray count;
   count.append( (char)(hex.toInt(&ok, 16)) ); 
   bulkFile.replace(35, 1, count);     //   insert the correct patch count into the G5L file.
   file.write(bulkFile); 
	};
 };
  close();      // close the dialog page after the file has been saved or cancelled.
};

void bulkSaveDialog::writeSYX()        //********************************* SYX File Format *****************************
{	
  	Preferences *preferences = Preferences::Instance();
	          QString dir = preferences->getPreferences("General", "Files", "dir");

          	QString fileName = QFileDialog::getSaveFileName(
                    this,
                    tr("Save Bulk Data"),
                    dir,
                    tr("System Exclusive Backup File (*.syx)"));
	             if (!fileName.isEmpty())	
                	{
	                  if(!fileName.contains(".syx"))
	                     	{
		                    	fileName.append(".syx");
	                     	};		
		
	QFile file(fileName);
    if (file.open(QIODevice::WriteOnly))
	{	
     bool ok;	
		QByteArray out;
		int size = this->bulk.size()/2;
	  //int patchCount = size/fullPatchSize;
		for (int x=0;x<size*2;x++)
		{
		   QString hexStr = bulk.mid(x, 2);
		   out.append( (char)(hexStr.toInt(&ok, 16)) );
		    ++x;
		};
   file.write(out); 
	};	 
 };
 close();
};

void bulkSaveDialog::writeSMF()    // **************************** SMF FILE FORMAT ***************************
{	
  	Preferences *preferences = Preferences::Instance();
	          QString dir = preferences->getPreferences("General", "Files", "dir");

          	QString fileName = QFileDialog::getSaveFileName(
                    this,
                    tr("Save Bulk Data"),
                    dir,
                    tr("Standard Midi Backup File (*.mid)"));
	             if (!fileName.isEmpty())	
                	{
	                  if(!fileName.contains(".mid"))
	                     	{
		                    	fileName.append(".mid");
	                     	};		
	
  
  	QFile file(fileName);
    if (file.open(QIODevice::WriteOnly))
	{
	   bool ok;	
		QByteArray out;
		QByteArray patches;
		int size = this->bulk.size()/2;
	  int patchCount = size/patchSize;
		for (int x=0;x<size*2;x++)
		{
		   QString hexStr = bulk.mid(x, 2);
		   patches.append( (char)(hexStr.toInt(&ok, 16)) );          // convert the bulk QString to a QByteArray.
		    ++x;
		};
		QByteArray bulkFile;
		QByteArray temp;                        // TRANSLATION of GR-55B PATCHES, data read from GR55B syx patch **************
	  QByteArray Qhex;                        // and used to replace GR55B patch SMF data*********************************
    QFile hexfile(":HexLookupTable.hex");   // use a QByteArray of hex numbers from a lookup table.
    if (hexfile.open(QIODevice::ReadOnly))
	{	Qhex = hexfile.readAll(); };             // read the hexlookupTable and call the QByteArray QHex.
	  bulkFile.append(Qhex.mid((288), 30));   // insert midi timing file header...
	  int b = 0;
		for (int x=0;x<patchCount;x++)
	  {
	  out.clear();
	  out.append( patches.mid(b, patchSize) );
    //out.remove(1763, 282);	   // remove the user text portion at the end..		
		out.remove(0, 11);         // remove address "00 00" header
		temp = Qhex.mid((320), 13);
		out.insert(0, temp);       // insert new address "00 00" header
		out.remove(141, 13);        // remove address "01 00" header
		temp = Qhex.mid((336), 16);
		out.insert(255, temp);      // insert new address "01 72" header
		out.remove(285, 13);        // remove address "02 00" header
		out.remove(413, 13);        // remove address "03 00" header
		temp = Qhex.mid((352), 16);
		out.insert(513, temp);      // insert new address "03 64" header
		out.remove(557, 13);        // remove address "04 00" header
		out.remove(685, 13);        // remove address "05 00" header
		temp = Qhex.mid((368), 16);
		out.insert(771, temp);      // insert new address "05 56" header
		out.remove(787, 13);        // remove address "06 00" header
		out.remove(915, 13);        // remove address "07 00" header
		temp = Qhex.mid((438), 42);  // copy 42 x extra "00"
		out.insert(787, temp);      // insert 42 x extra "00"
		temp = Qhex.mid((384), 16);
		out.insert(1029, temp);      // insert new address "07 48" header
		out.remove(1101, 13);        // remove address "08 00" header
		out.remove(1229, 13);        // remove address "09 00" header
		temp = Qhex.mid((400), 16);
		out.insert(1287, temp);      // insert new address "09 3A" header
		out.remove(1345, 13);        // remove address "0A 00" header
		out.remove(1473, 13);        // remove address "0B 00" header
		out.remove(1601, 13);        // remove address "0C 00" header
		temp = Qhex.mid((438), 28);  // copy 28 x extra "00"
		out.insert(1345, temp);      // insert 28 x extra "00"
		temp = Qhex.mid((416), 16);
		out.insert(1545, temp);      // insert new address "0B 2C" header
		out.remove(1773, 2);        // remove file footer
		temp = Qhex.mid((438), 29);  // copy 29 x extra "00"
		out.insert(1773, temp);      // insert 28 x extra "00"
		temp = Qhex.mid((432), 3);
		out.insert(1802, temp);      // insert new file footer (part of)
		out.append(Qhex.mid((20), 1));           // add last "14" on end.
    				
	
	QByteArray sysxBuffer;
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
	         { 
	         QString hexStr = sysxBuffer.mid(i, 2);
		       dataSize += ( (char)(hexStr.toInt(&ok, 16)) );  
           };
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
		  
		  sysxBuffer.clear();
			dataSize = 0;
			offset = 0;
		};
   };
   b=b+patchSize;
   bulkFile.append(out);      // append the bulk file. 
  };
   bulkFile.append(Qhex.mid((436), 3));    // add file footer.
   file.write(bulkFile); 
 };
 close();
 };
};
