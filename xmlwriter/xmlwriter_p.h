/****************************************************************************
** Filename: xmlwriter_p.h
** Last updated [dd/mm/yyyy]: 28/01/2007
**
** Class for XML file generation.
**
** Copyright (C) 2007 Angius Fabrizio. All rights reserved.
**
** This file is part of the OSDaB project (http://osdab.sourceforge.net/).
**
** This file may be distributed and/or modified under the terms of the
** GNU General Public License version 2 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.
**
** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
**
** See the file LICENSE.GPL that came with this software distribution or
** visit http://www.gnu.org/copyleft/gpl.html for GPL licensing information.
**
**********************************************************************/

#ifndef OSDAB_XMLWRITER_P__H
#define OSDAB_XMLWRITER_P__H

#include <QString>

class QTextStream;

class XmlWriterPrivate
{
public:
	XmlWriterPrivate(QIODevice* device, QTextCodec* codec, bool writeEncoding);
	~XmlWriterPrivate();

	QString escape(const QString& str) const;
	QString openTag(const QString& tag, const QHash<QString,QString>& attributes);

	QTextStream* stream;
	QString lineBreak;
	QString indentString;
	bool autoLineBreak;
	bool lineStart;
	bool pauseIndent;
	int indentLevel;
	bool skipEmptyTags;
	bool skipEmptyAttributes;
};

#endif // OSDAB_XMLWRITER_P__H
