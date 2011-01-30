/****************************************************************************
** Filename: XMLWriter.h
** Last updated [dd/mm/yyyy]: 19/08/2005
**
** Class for XML file generation [Requires Qt4 - QtCore module].
**
** Copyright (C) 2005 Angius Fabrizio. All rights reserved.
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

#ifndef	XMLWRITER_H
#define	XMLWRITER_H

#include <QtCore/QIODevice>
#include <QtCore/QMap>
#include <QtCore/QTextCodec>
#include <QtCore/QTextStream>

class XMLWriter
{

public:
	XMLWriter(QIODevice* device, QTextCodec* codec = 0, bool writeEncoding = true);
	~XMLWriter();

	enum NewLineType { CR, CRLF, LF };

	void writeString(const QString& string);
	void writeOpenTag(const QString& name, const QMap<QString,QString>* attrs = 0);
	void writeCloseTag(const QString& name);
	void writeAtomTag(const QString& name, const QMap<QString,QString>* attrs = 0);
	void writeTaggedString(const QString& name, const QString& string, const QMap<QString,QString>* attrs = 0);
	void writeComment(const QString& comment);
	void startComment();
	void endComment();
	void newLine();
	void setNewLine(NewLineType type);
	void pauseIndent(bool pause);
	void writeCurrentIndent();
	void setIndentType(int spaces);
	void setAutoNewLine(bool on) { mAutoNL = on; }

private:
	QString escape(const QString& str) const;
	QString openTag(const QString& tag, const QMap<QString,QString>* attributes);
	void writeEncoding();

	QTextStream* mOut;
	QString mNewLine;
	QString mIndentString;
	bool mAutoNL;
	bool mLineStart;
	bool mPauseIndent;
	int mIndent;
};

#endif // XMLWRITER_H
