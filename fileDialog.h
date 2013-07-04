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

#ifndef FILEDIALOG_H
#define FILEDIALOG_H

#include <QDialog>
#include <QComboBox>
#include <QLabel>
#include "SysxIO.h"

class QListWidget;
class QListWidgetItem;
class QStackedWidget;

class fileDialog : public QDialog
{
        Q_OBJECT

public:
  fileDialog(QString fileName, QList<QString> patchList, QByteArray fileData, QByteArray default_data, QString type);
  QLabel *patchLabel;
  QLabel *nameLabel;
  QComboBox *patchCombo;
  //int index;
signals:
  //void currentIndex(int value);
  void patchIndex(int value);

public slots:
  void valueChanged(int value);
  void highlighted(int value);
  void cancel();

protected:
  void mouseRightClickEvent(QMouseEvent *event);

private:
  QList<QString> patchList;
  QListWidget *contentsWidget;
  QStackedWidget *pagesWidget;
  QByteArray fileData;
  QByteArray default_data;
  QString file_format;
  int value;
};

#endif // FILEDIALOG_H
