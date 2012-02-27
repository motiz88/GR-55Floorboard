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

#ifndef BULKSAVEDIALOG_H
#define BULKSAVEDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QProgressBar>
#include <QSpinBox>
#include <QCheckBox>
#include <QRadioButton>
#include "SysxIO.h" 


class bulkSaveDialog : public QDialog
{
    Q_OBJECT

public:
    bulkSaveDialog();
    ~bulkSaveDialog();
    QCheckBox* systemCheckBox;
    QSpinBox* startRangeSpinBox;
    QSpinBox* finishRangeSpinBox;
    QProgressBar *progressBar;
    QString msg;

signals:
    void setStatusMessage(QString message);
    void setStatusProgress(int value);
    void setStatusSymbol(int value);

public slots:
    void backup();
    void requestPatch(int bank, int patch);
    void updatePatch(QString replyMsg);
    void bulkStatusProgress(int value);
    void DialogClose();

private: 
    QLabel *progressLabel;
    QLabel *bytesLabel;
    QPushButton *startButton;
    QPushButton *cancelButton;
    QPushButton *completedButton;
    QRadioButton *g5lButton;
    QRadioButton *syxButton;
    QRadioButton *midButton;
    int bankStart;
    int bankFinish;
    int progress;
    bool systemSelect;
    QString bulkData;
    QString bulk;
    int range;
    int patch;
    int bank;
    QString fileName;
    void writeG5L();
    void writeSYX();
    void writeSMF();
};

#endif // BULKSAVEDIALOG_H
