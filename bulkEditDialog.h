/****************************************************************************
**
** Copyright (C) 2007~2016 Colin Willcocks. 
** All rights reserved.
**
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

#ifndef BULKEDITDIALOG_H
#define BULKEDITDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QProgressBar>
#include <QSpinBox>
#include <QCheckBox>
#include <QRadioButton>
#include <QPushButton>
#include <QComboBox>
#include "SysxIO.h" 


class bulkEditDialog : public QDialog
{
    Q_OBJECT

public:
    bulkEditDialog(int partStart, int partLength, QString partHex1, QString partHex3);
    ~bulkEditDialog();
    QString msg;

signals:
    void setStatusMessage(QString message);
    void setStatusProgress(int value);
    void setStatusSymbol(int value);
    void setdeBugStatusMessage(QString message);

public slots:
    void sendData();
    void prepareData();
    void bulkStatusProgress(int value);
    void sendSequence(QString value);
    void sendPatch(QString data);

private slots:
    void comboValueChanged(int value);
    void close();

private: 
    QComboBox *startPatchCombo;
    QComboBox *finishPatchCombo;
    QLineEdit *finishRange;
    QProgressBar *progressBar;
    QLabel *progressLabel;
    QLabel *bytesLabel;
    QPushButton *startButton;
    QPushButton *cancelButton;
    QPushButton *completedButton;
    int start;
    int finish;
    int patchRange;
    int progress;
    int partialStart;
    int partialLength;
    int range;
    int patch;
    int bank;
    int steps;
    int dataSent;
    QString patchName;
    QString partialData;
    QString bulk;
    QList<QString> patchList;
    bool failed;
    QString hex1;
    QString hex3;
    QString addrMSB;
};

#endif // bulkEditDialog_H
