/****************************************************************************
**
** Copyright (C) 2007~2013 Colin Willcocks.
** Copyright (C) 2005~2007 Uco Mesdag.
** All rights reserved.
** This file is part of "GR-55B FloorBoard".
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

#ifndef SUMMARYDIALOGPATCHLIST_H
#define SUMMARYDIALOGPATCHLIST_H

#include <QDialog>
#include <QMainWindow>
#include <QTextEdit>
#include <QTextDocument>
#include <QLabel>
#include <QPrintDialog>
#include <QPrinter>
#include "SysxIO.h"

class QListWidget;
class QListWidgetItem;
class QStackedWidget;

class summaryDialogPatchList : public QWidget
{
        Q_OBJECT

public:
  summaryDialogPatchList(QWidget *parent = 0);
  ~summaryDialogPatchList();
  QTextEdit *textDialog;
  QTextDocument *document;
  QPrintDialog *dialog;
  QPushButton *cancelButton;
  QPushButton *printButton;
  QPushButton *saveAsButton;

public slots:
  void updatePatchNames(QString name);
  void cancel();
  void printFile();
  void saveAs();

signals:  
  void setStatusSymbol(int value);
	void setStatusProgress(int value);
  void setStatusMessage(QString message);

private:
QString patchList;
int bank;
int patch;
int count;
};

#endif //SUMMARYDIALOGPATCHLIST
