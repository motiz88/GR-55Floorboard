/****************************************************************************
** Filename: xmlwriter.h
** Last updated [dd/mm/yyyy]: 15/02/2007
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

#ifndef OSDAB_XMLWRITER_H
#define OSDAB_XMLWRITER_H

#include <QHash>

class QIODevice;
class QTextCodec;

class XmlWriterPrivate;

class XmlWriter
{
public:
	typedef QHash<QString,QString> AttributeMap;

	XmlWriter(QIODevice* device, QTextCodec* codec = 0, bool writeEncoding = true);
	virtual ~XmlWriter();

	enum LineBreakType { Unix, Windows, Macintosh };

	void writeString(const QString& string);
	void writeLine();

	void writeOpenTag(const QString& name, const AttributeMap& attrs = AttributeMap());
	void writeCloseTag(const QString& name);
	void writeAtomTag(const QString& name, const AttributeMap& attrs = AttributeMap());
	void writeTaggedString(const QString& name, const QString& string, const AttributeMap& attrs = AttributeMap());

	void writeComment(const QString& comment);
	void startComment();
	void endComment();	

	LineBreakType lineBreakType() const;
	void setLineBreakType(LineBreakType type);

	bool pauseIndent() const;
	void setPauseIndent(bool pause);

	void writeCurrentIndent();

	int indentType() const;
	void setIndentType(int spaces);

	bool autoNewLine() const;
	void setAutoNewLine(bool on);

	bool skipEmptyTags() const;
	void setSkipEmptyTags(bool skip);

	bool skipEmptyAttributes() const;
	void setSkipEmptyAttributes(bool skip);

private:
	XmlWriterPrivate* d;
};

#endif // OSDAB_XMLWRITER_H
