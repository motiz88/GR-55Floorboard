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

#ifndef SUMMARYDIALOG_H
#define SUMMARYDIALOG_H

#include <QDialog>
#include <QMainWindow>
#include <QTextEdit>
#include <QTextDocument>
#include <QLabel>
#include <QPrintDialog>
#include <QPrintPreviewDialog>
#include <QPrinter>
#include "SysxIO.h"

class QListWidget;
class QListWidgetItem;
class QStackedWidget;

class summaryDialog : public QWidget
{
        Q_OBJECT

public:
  summaryDialog(QWidget *parent = 0);
  ~summaryDialog();
  QTextEdit *textDialog;
  QTextDocument *document;
 // QPrintDialog *dialog;
                                                            
public slots:
  void view();
  void cancel();
  void printFile();
  void printPreview();
  void saveAs();

private:
void makeList();
QString text;
QString text2;
QString small_text;
QString large_text;
QString address;
int start;
int finish;
QString mode;
QString effect;
QString filter;
QString assign_desc;
QString assign_customdesc;
};

#endif // FILEDIALOG_H
