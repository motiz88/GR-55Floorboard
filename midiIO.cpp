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

#include <QSysInfo>
#include "midiIO.h"
#include "SysxIO.h"
#include "globalVariables.h"
#include "RtMidi.h"
#include "Preferences.h"
#include "MidiTable.h"

int midiIO::bytesTotal = 0;
int midiIO::bytesReceived = 0;
int loopCount;
bool midiIO::dataReceive = false;
QString midiIO::sysxBuffer;
QString midiIO::msgType = "name";


midiIO::midiIO()
{
    this->midi = false; // Set this to false until required;
    /* Connect signals */
    SysxIO *sysxIO = SysxIO::Instance();
    QObject::connect(this, SIGNAL(setStatusSymbol(int)), sysxIO, SIGNAL(setStatusSymbol(int)));
    QObject::connect(this, SIGNAL(setStatusProgress(int)), sysxIO, SIGNAL(setStatusProgress(int)));
    QObject::connect(this, SIGNAL(setStatusMessage(QString)), sysxIO, SIGNAL(setStatusMessage(QString)));
    QObject::connect(this, SIGNAL(setStatusdBugMessage(QString)), sysxIO, SIGNAL(setStatusdBugMessage(QString)));
    QObject::connect(this, SIGNAL(errorSignal(QString, QString)), sysxIO, SLOT(errorSignal(QString, QString)));
    QObject::connect(this, SIGNAL(replyMsg(QString)),	sysxIO, SLOT(receiveSysx(QString)));
    QObject::connect(this, SIGNAL(midiFinished()), sysxIO, SLOT(finishedSending()));
}

midiIO::~midiIO()
{
    this->terminate();
}

/*********************** queryMidiOutDevices() *****************************
 * Retrieves all MIDI Out devices installed on your system and stores them
 * as a QList of QStrings and device id's.
 *************************************************************************/
void midiIO::queryMidiOutDevices()
{
    RtMidiOut *midiout = 0;
    std::string portName;
    try { midiout = new RtMidiOut(); }   /* RtMidiOut constructor */
    catch (RtError &error)
    {
        QString d =  QString::fromStdString(error.getMessage());
        emit errorSignal(tr("Midi Output Fail"), d);
        goto cleanup;
    };

        outPortsCount = midiout->getPortCount();      /* Check outputs. */
        for ( unsigned int i=0; i<outPortsCount; i++ )
        {
            try{ portName = midiout->getPortName(i); }
            catch (RtError &error)
            {
                QString d =  QString::fromStdString(error.getMessage());
                emit errorSignal(tr("Midi Output Fail"), d);
                error.printMessage();
                goto cleanup;
            };
            this->midiOutDevices.append(QString::fromStdString(portName));
        };
        if (outPortsCount < 1) { this->midiOutDevices.push_back(tr("no midi device available")); };

cleanup:
    delete midiout;
}

QList<QString> midiIO::getMidiOutDevices()
{
    queryMidiOutDevices();
    return this->midiOutDevices;
}

/*********************** queryMidiInDevices() ******************************
 * Retrieves all MIDI In devices installed on your system and stores them
 * as a QList of QStrings and device id's.
 *************************************************************************/
void midiIO::queryMidiInDevices()
{
    RtMidiIn *midiin = 0;
    std::string portName;
    try { midiin = new RtMidiIn(); }    /* RtMidiIn constructor */
    catch (RtError &error)
    {
        QString d =  QString::fromStdString(error.getMessage());
        emit errorSignal(tr("Midi Input Fail"), d);
        goto cleanup;
    };
        inPortsCount = midiin->getPortCount();   /* Check inputs. */
        for ( unsigned int i=0; i<inPortsCount; i++ ) {
          try {  portName = midiin->getPortName(i); }
            catch (RtError &error)
            {
                QString d =  QString::fromStdString(error.getMessage());
                emit errorSignal(tr("Midi Input Fail"), d);
                goto cleanup;
            };
            this->midiInDevices.append(QString::fromStdString(portName));
        };
        if (inPortsCount < 1)
        { this->midiInDevices.push_back(tr("no midi device available")); };
cleanup:
    delete midiin;
}

QList<QString> midiIO::getMidiInDevices()
{
    queryMidiInDevices();
    return this->midiInDevices;
}

/*********************** sendMsg() **********************************
 * Prepares the sysx message before sending on the MIDI Out device. It
 * converts the message from a QString to a std::vector and opens, sends
 * and closes the MIDI device.
 *************************************************************************/
void midiIO::sendSyxMsg(QString sysxOutMsg)
{
    int close = 0;
    int retryCount = 0;
    int wait_time = 0;
    int s = 0;
    std::vector<unsigned char> message;
    message.reserve(1333);
    int msgLength = sysxOutMsg.length()/2;
    char *ptr  = new char[msgLength];		// Convert QString to char* (hex value).
    QString hex;
    wait_time = 0;
    s = sysxOutMsg.size()/4;
    close = 20 + s;
    retryCount = 0;
    int midiOutPortInt = 0;
    RtMidiOut *midiMsgOut = 0;
    QList<QString> midiOutDevices = getMidiOutDevices();
    int id=outPortsCount;
    for(int x=0; x<id; ++x)
    {
        QString item = midiOutDevices.at(x).toAscii();
        if ( item==this->midiOutPort )
        {
            midiOutPortInt=x;
        };
    };
RETRY:
   try {

        midiMsgOut = new RtMidiOut();
        if ( outPortsCount < 1 ) { goto cleanup; };

        midiMsgOut->openPort(midiOutPortInt);	// Open selected port.
        for(int i=0;i<msgLength*2;++i)
        {
            unsigned int n;
            hex = sysxOutMsg.mid(i, 2);
            bool ok;
            n = hex.toInt(&ok, 16);
            *ptr = (char)n;
            message.push_back(*ptr);		// insert the char* string into a std::vector
            wait_time = wait_time + 1;
            emit setStatusProgress(wait_time);
            ptr++; i++;
        };
        midiMsgOut->sendMessage(&message);
        midiMsgOut->closePort();
        goto cleanup;
    }
    catch (RtError &error)
    {
        msleep(100);
        retryCount++;
        if (retryCount < 10) { goto RETRY; };
        //error.printMessage();
        QString d =  QString::fromStdString(error.getMessage());
        emit errorSignal("Syx Output Error - midi-out:"+midiOutPort+": port number:"+QString::number(midiOutPortInt,10)+": ", d);
        goto cleanup;
    };
    /* Clean up */
cleanup:
    msleep(close);						// wait as long as the message is sending.
    delete midiMsgOut;
    //emit errorSignal("test - midi-out:"+midiOutPort+":", "port number:"+QString::number(midiOutPortInt,10)+": ");

}
/*********** send midi messages *******************************/
void midiIO::sendMidiMsg(QString sysxOutMsg)
{
    RtMidiOut *midiMsgOut = 0;
    const std::string clientName = "FloorBoard";

    int midiOutPortInt = 0;
    QList<QString> midiOutDevices = getMidiOutDevices();
    int id=outPortsCount;
    for(int x=0; x<id; ++x)
    {
        QString item = midiOutDevices.at(x).toAscii();
        if ( item == this->midiOutPort )
        {
            midiOutPortInt = x;
        };
    };

    try{
        midiMsgOut = new RtMidiOut();
        if ( outPortsCount < 1 ){ goto cleanup; };
        midiMsgOut->openPort(midiOutPortInt, clientName);	// Open selected port.
        std::vector<unsigned char> message;
        int msgLength = sysxOutMsg.length()/2;
        char *ptr  = new char[msgLength];		// Convert QString to char* (hex value)
        for(int i=0;i<msgLength*2;++i)
        {unsigned int n;
            QString hex;
            hex.append(sysxOutMsg.mid(i, 2));
            bool ok;
            n = hex.toInt(&ok, 16);
            *ptr = (char)n;
            message.push_back(*ptr);		// insert the char* string into a std::vector
            ptr++; i++;
        };
        midiMsgOut->sendMessage(&message);  // send the midi data as a std::vector
        midiMsgOut->closePort();
        goto cleanup;
    }
    catch (RtError &error)
    {
        QString d =  QString::fromStdString(error.getMessage());
        emit errorSignal(tr("Midi Output Fail  -"), d);
        goto cleanup;
    };
cleanup:
    delete midiMsgOut;
}

/*********************** receiveMsg() **********************************
 * Prepares the sysx message after receiving on the MIDI In device. It
 *  and opens, receives and closes the MIDI device then converts the
 *  message from a std::vector to a QString.
 *************************************************************************/
void midicallback(double deltatime, std::vector<unsigned char> *message, void *userData)
{
    QString rxData;
    midiIO *midi = new midiIO();
    unsigned int nBytes = message->size();
    for ( unsigned int i=0; i<nBytes; i++ )
    {
        int n = ((int)message->at(i));					// convert std::vector to QString
        QString hex = QString::number(n, 16).toUpper();
        if (hex.length() < 2) hex.prepend("0");
        rxData.append(hex);
    };
    if (rxData.contains("F0") || rxData.contains("F7"))   // filter out non-syx events
    { midi->callbackMsg(rxData); };
    midi->terminate();
}
void midiIO::callbackMsg(QString rxData)
{
    this->sysxBuffer.append(rxData);
}

void midiIO::receiveMsg()
{
    count = 0;
    emit setStatusSymbol(3);
#ifdef Q_OS_WIN
    int q = 1;
#else
    int q = 3;
#endif

    if (msgType == "patch"){ loopCount = q*300; count = patchReplySize; }
    else if(msgType == "system"){ loopCount = q*600; count = 1173; }
    else if (msgType == "name") { loopCount = q*100; count = 29; }
    else if (msgType == "identity") { loopCount = q*100; count = 15; }
    else if (msgType == "write") { loopCount = q*200; count = 40; }
    else  { loopCount = q*10; count = 0; };

    int midiInPortInt = 0;
    QList<QString> midiInDevices = getMidiInDevices();
    int id=inPortsCount;
    for(int deviceCount=0; deviceCount<id; ++deviceCount)
    {
        QString item = midiInDevices.at(deviceCount).toAscii();
        if ( item==this->midiInPort )
        {
            midiInPortInt = deviceCount;
        };
    };
    int x = 0;
    unsigned int s = 1;
    unsigned int t = 1;
    RtMidiIn *midiin = 0;
    if(midiInPortInt<1) {goto cleanup; };
try {  midiin = new RtMidiIn();	}	         //RtMidi constructor
    catch (RtError &error)
    {
        QString d =  QString::fromStdString(error.getMessage());
        emit errorSignal(tr("no Midi In Port avaliable-"), d);
        goto cleanup;
    };
    if ( inPortsCount < 1 ) { goto cleanup; };
  try{  midiin->ignoreTypes(false, true, true);      //don,t ignore sysex messages, but ignore other crap like active-sensing
        midiin->openPort(midiInPortInt); // open the midi in port
        midiin->setCallback(&midicallback);       }   // set the callback
    catch (RtError &error)
    {
        QString d =  QString::fromStdString(error.getMessage());
        emit errorSignal("Midi Input Fail - ","midi-out:"+midiOutPort+":  midi-in:"+midiInPort+":");
        goto cleanup;
    };
        sendSyxMsg(sysxOutMsg);         // send the data request message out
        while ((x<loopCount && sysxBuffer.size()/2 < count) && !sysxBuffer.contains("F04110000053120F000002434F4D504C45545BF7"))  // wait until exact bytes received or timeout or write returns "COMPLET"
        {
            msleep(5);
            s = (this->sysxBuffer.size()*50)/count;
            t = (x*200)/loopCount;
            if (s>t) {t=s;};
            emit setStatusProgress(t);
            x++;
        };                   // time it takes to get all sysx messages in.
        midiin->cancelCallback();
        midiin->closePort();             // close the midi in port
        goto cleanup;


    /*Clean up */
cleanup:
    emit setStatusProgress(100);
    this->sysxInMsg = this->sysxBuffer;		   //get the returning data string
    dataReceive = true;
    delete midiin;
}

/**************************** run() **************************************
 * New QThread that processes the sysex or midi message and handles if yes
 * or no it has to start receiving a reply on the MIDI In device midiIn. If
 * so midiCallback() will handle the receive of the incomming sysx message.
 *************************************************************************/
void midiIO::run()
{
    int repeat = 0;
     if(midi && midiMsg.size() > 1)	// Check if we are going to send sysx or midi data & have an actual midi message to send.
    {
        if (midiMsg.size() <= 6)		// if the midi message is <= 3 words
        {
            sysxOutMsg = midiMsg;   // use the same sending routine as sysx messages.
            sendMidiMsg(sysxOutMsg);
        }
        else
        {
            int z=0;
            sysxOutMsg = midiMsg.mid(z,2);
            sysxOutMsg.append(midiMsg.mid(z+2,2));  // skip every second byte
            sysxOutMsg.append(midiMsg.mid(z+4,2));  // skip every second byte
            sendMidiMsg(sysxOutMsg);
            z=(z+6);								// advance to the next midi message in the string
            sysxOutMsg = midiMsg.mid(z,2);
            sysxOutMsg.append(midiMsg.mid(z+2,2));  // skip every second byte
            sysxOutMsg.append(midiMsg.mid(z+4,2));  // skip every second byte
            sendMidiMsg(sysxOutMsg);
            z=(z+6);								// advance to the next midi message in the string
            sysxOutMsg = midiMsg.mid(z,2);
            sysxOutMsg.append(midiMsg.mid(z+2,2));  // skip every second byte
            sysxOutMsg.append(midiMsg.mid(z+4,2));  // skip every second byte
            sendMidiMsg(sysxOutMsg);
        };
        emit setStatusSymbol(2);
        emit setStatusProgress(33); // time wasting sinusidal statusbar progress animation
        msleep(50);
        emit setStatusProgress(66);
        msleep(50);
        emit setStatusProgress(100);
        msleep(50);
        emit setStatusProgress(75);
        msleep(50);
        emit setStatusProgress(42);
        msleep(50);
        emit setStatusProgress(0);
        emit midiFinished(); // We are finished so we send a signal to free the device.
    }
    else   // if not a midi message, then it must be a sysx message
    {
RECEIVE:
        dataReceive = false;
        sysxBuffer.clear();
        sysxInMsg.clear();
        /* Check if we are going to receive something on sending */
        bool receive;
        (this->sysxOutMsg.mid(sysxAddressOffset*2-2, 2) != "12")? receive = true: receive = false;
        if(receive == true || msgType == "write")
        {
            emit setStatusSymbol(3);
            /* Get the size of data bytes returned to calculate the progress percentage */
            bool ok;
            QString sizeChunk = sysxOutMsg.mid(sysxDataOffset * 2, 4 * 2);
            int dataLenght = sizeChunk.toInt(&ok, 16);
            bytesTotal = (sysxDataOffset + 2) + dataLenght;
            if(dataLenght == 0) // Id request>
            {
                bytesTotal += 2;
            }
            else if(sizeChunk == patchRequestDataSize) // Patch Request data size
            {
                bytesTotal = patchReplySize;     // progressbar scaled to patch size
            }
            else if (sizeChunk == "01010000")
            {
                bytesTotal = systemSize;
            };
            dataReceive = true;
            receiveMsg();
            Preferences *preferences = Preferences::Instance(); // Load the preferences.
            if((sysxBuffer.size()/2 != count) && (repeat<10) && preferences->getPreferences("Midi", "DBug", "bool")!="true")
            {
                emit setStatusdBugMessage(tr("retrying data request"));
                repeat = repeat+1;
                msleep(100);
                goto RECEIVE;
            };
            emit midiFinished();
        }
        else
        {
            emit setStatusSymbol(2);
            emit setStatusMessage(tr("Sending"));
            sendSyxMsg(this->sysxOutMsg);
            emit setStatusProgress(33);  // do the statusbar progress thing
            msleep(20);		// and wait predetermined time before being able to send more again.
            emit setStatusProgress(75);
            msleep(20);
            emit setStatusProgress(100);
            msleep(20);
            emit setStatusProgress(66);
            msleep(20);
            emit midiFinished(); // We are finished so we send a signal to free the device.
        };
        this->sysxInMsg = sysxInMsg;
        emit replyMsg(sysxInMsg);
        emit setStatusSymbol(1);
        emit setStatusProgress(0);
    };
}

/*********************** sendSysxMsg() ***********************************
 * Starts a new thread that handles the send and receive of sysex messages.
 *************************************************************************/
void midiIO::sendSysxMsg(QString sysxOutMsg, QString midiOutPort, QString midiInPort)
{
    this->midiOutPort = midiOutPort;
    this->midiInPort = midiInPort;
    if(sysxOutMsg.size()/2 == 1333 || sysxOutMsg.size()/2 == 1347) {
        sysxOutMsg = sysxOutMsg.remove(139*2, 13*2);
        sysxOutMsg = sysxOutMsg.remove(267*2, 13*2);
        sysxOutMsg = sysxOutMsg.remove(486*2, 13*2);
        sysxOutMsg = sysxOutMsg.remove(614*2, 13*2);
        sysxOutMsg = sysxOutMsg.remove(954*2, 13*2);
    };
    QString reBuild;
    QString sysxEOF;
    QString hex;
    int msgLength = sysxOutMsg.length()/2;
    for(int i=0;i<msgLength*2;++i)
    {
        hex.append(sysxOutMsg.mid(i*2, 2));
        sysxEOF = sysxOutMsg.mid((i*2)+4, 2);
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
            if (!hex.contains("F0410000001B12")) // remove txt portions of the message from address 00 0D 00 00 onwards
            {reBuild.append(hex); };
            hex.clear();
            sysxEOF.clear();
            i=i+2;
        };
    };
    msgType.clear();
    if (sysxOutMsg.contains(idRequestString))
    {reBuild = sysxOutMsg;  msgType = "identity";  emit setStatusdBugMessage(tr("identity request")); };  // identity request not require checksum
    this->sysxOutMsg = reBuild.simplified().toUpper();

    if((sysxOutMsg.size() == (sysxDataOffset*2 + 12)) && (sysxOutMsg.mid(sysxOutMsg.size()-12, 8) == patchRequestDataSize) && (sysxOutMsg.mid((sysxAddressOffset*2-2), 2) == "11") )
    { msgType = "patch"; emit setStatusdBugMessage(tr("patch request")); };

    if((sysxOutMsg.size() == 34) && (sysxOutMsg.contains("00000010")) && (sysxOutMsg.mid((sysxAddressOffset*2-2), 2) == "11"))
    { msgType = "name";  emit setStatusdBugMessage(tr("name request")); };

    if (sysxOutMsg.contains(systemRequest))
    { msgType = "system"; emit setStatusdBugMessage(tr("system request")); };

    if (sysxOutMsg.contains("F04110000053120F000001016FF7") )
    { msgType = "write"; emit setStatusdBugMessage(tr("patch write")); };

    this->midi = false;

    int gr55Port = 0;
    int midiOutPortInt = 0;
    QString portCopy;
    QList<QString> midiOutDevices = getMidiOutDevices();
    int id = midiOutDevices.count();
    for(int x=0; x<id; ++x)
    {
        QString item = midiOutDevices.at(x).toAscii();
        if ( item == midiOutPort )
        {
            midiOutPortInt = x;
        };
        if ( item.contains("GR-55") )
        {
            gr55Port = x;
            portCopy = item;
        };
    };
    if(midiOutPortInt<1 && !portCopy.isEmpty())
    {
        midiOutPortInt = gr55Port;
        this->midiOutPort = portCopy;
        this->midiInPort = portCopy;
    };
    if(midiOutPort=="Select midi-out device" || midiOutPort=="" || midiOutPortInt<1)
    {
        emit setStatusSymbol(0);
        emit setStatusMessage("no midi device set - midi-out: "+midiOutPort+" - midi-in: "+midiInPort);
        emit replyMsg("");
    }
    else
    {
        start();
    };
}

/*********************** sendMidi() **********************************
 * Starts a new thread that handles the sending of the midi messages.
 **********************************************************************/
void midiIO::sendMidi(QString midiMsg, QString midiOutPort)
{
    this->midiOutPort = midiOutPort;
    this->midiMsg = midiMsg;
    this->midi = true;
    int gr55Port = 0;
    int midiOutPortInt = 0;
    QString portCopy;
    QList<QString> midiOutDevices = getMidiOutDevices();
    int id = midiOutDevices.count();
    for(int x=0; x<id; ++x)
    {
        QString item = midiOutDevices.at(x).toAscii();
        if ( item == midiOutPort )
        {
            midiOutPortInt = x;
            portCopy = item;
        };
        if ( item.contains("GR-55") )
        {
            gr55Port = x;
        };
    };
    if(midiOutPortInt < 1 && !portCopy.isEmpty())
    {
        midiOutPortInt = gr55Port;
        this->midiOutPort = portCopy;
        this->midiInPort = portCopy;
    };
    if(midiOutPort=="Select midi-out device" || midiOutPort=="" || midiOutPortInt<1)
    {
        emit setStatusSymbol(0);
        emit setStatusMessage(tr("no midi device set"));
        emit replyMsg("");
    }
    else
    {
        start();
    };
}

