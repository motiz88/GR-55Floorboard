/****************************************************************************
**
** Copyright (C) 2007~2015 Colin Willcocks.
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

#ifndef BANKTREELIST_H
#define BANKTREELIST_H

#include <QWidget>
#include <QList>
#include <QTreeWidget>

class bankTreeList : public QWidget
{
	Q_OBJECT

public:
	bankTreeList(QWidget *parent = 0);

public slots:
	void updateSize(QRect newrect);
	void updatePatchNames(QString replyMsg);
	void updatePatch(QString patchName);
	void setClosedItems(QTreeWidgetItem *item);
	void setOpenItems(QTreeWidgetItem *item);
	void connectedSignal();
	void requestPatch();
	void requestPatch(int bank, int patch);
	void setItemClicked(QTreeWidgetItem *item, int column);
	void setItemDoubleClicked(QTreeWidgetItem *item, int column);
    void updateTreeMode();
    void systemRequest();

signals:
	void itemExpanded(QTreeWidgetItem *item);
	void itemCollapsed(QTreeWidgetItem *item);
	void itemClicked(QTreeWidgetItem *item, int column);
	void itemDoubleClicked(QTreeWidgetItem *item, int column);
	void patchSelectSignal(int bank, int patch);
	void patchLoadSignal(int bank, int patch);
	void updateSignal();
	void setStatusSymbol(int value);
	void setStatusProgress(int value);
    void setStatusMessage(QString message);
	void notConnectedSignal();

private:
	void updateTree(QTreeWidgetItem *item);
	void closeChildren(QTreeWidgetItem *item);
	QTreeWidget* newTreeList();
    QTreeWidget* newTreeList_Bass();
	QList<QTreeWidgetItem*> openBankTreeItems;
	QList<QTreeWidgetItem*> openPatchTreeItems;
	QList<QTreeWidgetItem*> currentPatchTreeItems;
	QTreeWidget* treeList;
    QTreeWidget* treeListBass;
	int itemIndex;
	int listIndex;
    bool systemRequested;
};

#endif // BANKTREELIST_H
