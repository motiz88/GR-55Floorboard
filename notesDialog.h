/****************************************************************************
**
** Copyright (C) 2007~2016 Colin Willcocks.
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

#ifndef NOTESDIALOG_H
#define NOTESDIALOG_H

#include <QDialog>
#include <QMainWindow>
#include <QPlainTextEdit>
#include <QTextDocument>
#include <QLabel>
#include "SysxIO.h"
#include "sysxWriter.h"

class QListWidget;
class QListWidgetItem;
class QStackedWidget;

class notesDialog : public QWidget
{
    Q_OBJECT

public:
    notesDialog(QWidget *parent = 0);
    ~notesDialog();
    QTextDocument *document;


public slots:
    void cancel();
    void saveAs();

private:
    QPlainTextEdit *memo1Dialog;
    QPlainTextEdit *memo2Dialog;
    QPlainTextEdit *memo3Dialog;
    QPlainTextEdit *memo4Dialog;
    QLabel *label1;
    QLabel *label2;
    QLabel *label3;
    QLabel *label4;
    QLabel *label5;
    sysxWriter file;
};

#endif 
