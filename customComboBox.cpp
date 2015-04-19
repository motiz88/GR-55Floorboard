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

#include "customComboBox.h"
#include <QScrollBar>
#include "Preferences.h"
 
customComboBox::customComboBox(QWidget *parent)	: QComboBox(parent)
 {

 }

void customComboBox::showPopup()
{
    Preferences *preferences = Preferences::Instance();
    bool ok;
    const double ratio = preferences->getPreferences("Window", "Scale", "ratio").toDouble(&ok)*40;

	QString longestItem = "";
 	for(int i=0;i<this->count();i++)
 	{
 		QString item = this->itemText(i);
 		if(longestItem.size() < item.size()) longestItem = item;
 	};
 	int popupWidth = QFontMetrics( this->font() ).width( longestItem );
	

 	if( this->view()->verticalScrollBar()->isVisible() )
 	{
 		this->setMaxVisibleItems(this->maxVisibleItems() - 1);
                popupWidth = popupWidth + ratio;
 	};

 	if( this->view()->verticalScrollBar()->isVisibleTo(this) )
 	{
 		this->setMaxVisibleItems(this->maxVisibleItems() - 1);
                popupWidth = popupWidth + ratio;
 	};
                                                                        
   if(popupWidth < ratio) { popupWidth = ratio; };
 	this->view()->setMinimumWidth(popupWidth);
  QComboBox::showPopup();
}
