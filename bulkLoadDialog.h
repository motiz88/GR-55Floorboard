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

#ifndef BULKLOADDIALOG_H
#define BULKLOADDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QProgressBar>
#include <QSpinBox>
#include <QCheckBox>
#include <QRadioButton>
#include <QPushButton>
#include <QComboBox>
#include "SysxIO.h" 


class bulkLoadDialog : public QDialog
{
	Q_OBJECT
  
public:
	bulkLoadDialog();
  QString msg;
  
signals:
  void setStatusMessage(QString message);
  void setStatusProgress(int value);
  void setStatusSymbol(int value);
  void setdeBugStatusMessage(QString message);
                    
public slots:
  void sendData();
  void updatePatch();
  void bulkStatusProgress(int value);
  void sendSequence(QString value); 
  void sendPatch(QString data);
  
private slots:
  void comboValueChanged(int value);
       
private: 
  QComboBox *startPatchCombo;
	QComboBox *finishPatchCombo;
  QComboBox *startRangeComboBox;
	QComboBox *patchRangeSpinBox;
	QLineEdit *finishRange;
  QProgressBar *progressBar;
  QLabel *progressLabel;
  QLabel *bytesLabel; 
  QPushButton *startButton;
  QPushButton *cancelButton; 
  QPushButton *completedButton;
  int startList;
  int finishList;
  int bankStart;
	int patchRange;
	int progress;
	QString bulkData;	
	QString bulk;
	int range;
	int patch;
	int bank;
	int patchCount;
	int steps;
	int dataSent;
	QString fileName;
	void loadG5L();
	void loadSYX();
	void loadSMF();
	QByteArray data;
	QByteArray default_data;
	QByteArray hextable;
	QByteArray sysxPatches;
	QList<QString> patchList;	 
	QList<QString> userList;
	bool failed;
};

#endif // BULKLOADDIALOG_H
