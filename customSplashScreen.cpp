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

#include "customSplashScreen.h"
#include "Preferences.h"

customSplashScreen::customSplashScreen(const QPixmap& pixmap)
{
        QSplashScreen::setPixmap(pixmap);
}

customSplashScreen::~customSplashScreen()
{
}

void customSplashScreen::drawContents(QPainter *painter)
{
        QPixmap textPix = QSplashScreen::pixmap();
        painter->setPen(this->color);
        //painter->drawText(r, this->alignement, this->message);
        painter->drawText(this->rect, this->alignement, this->message);
}

void customSplashScreen::showStatusMessage(const QString &message, const QColor &color)
{
    Preferences *preferences = Preferences::Instance();
    QString version = preferences->getPreferences("General", "Application", "version");
    this->message = "version " + version + " " + message;
        this->color = color;
        this->showMessage(this->message, this->alignement, this->color);
}

void customSplashScreen::setMessageRect(QRect rect, int alignement)
{
        this->rect = rect;
        this->alignement = alignement;
}
