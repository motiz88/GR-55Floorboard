/****************************************************************************
**
** Copyright (C) 2007~2016 Colin Willcocks.
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

#include <QtWidgets>
#include <QFile>
#include "notesDialog.h"
#include "Preferences.h"
#include "SysxIO.h"
#include "MidiTable.h"
#include "globalVariables.h"

notesDialog::notesDialog(QWidget *parent)
    : QWidget(parent)
{
    this->label1 = new QLabel(parent);
    label1->setText("MEMO 1");

    this->label2 = new QLabel(parent);
    label2->setText("MEMO 2");

    this->label3 = new QLabel(parent);
    label3->setText("MEMO 3");

    this->label4 = new QLabel(parent);
    label4->setText("MEMO 4");

    this->label5 = new QLabel(parent);
    label5->setText("MEMO NOTES ONLY SAVED IN *.G5L LIBRARIAN FORMAT FILE ");

    this->memo1Dialog = new QPlainTextEdit(parent);
    memo1Dialog->setReadOnly(false);
    memo1Dialog->setDocumentTitle("Patch Memo 1 Notes");
    memo1Dialog->setMinimumHeight(150);

    this->memo2Dialog = new QPlainTextEdit(parent);
    memo2Dialog->setReadOnly(false);
    memo2Dialog->setDocumentTitle("Patch Memo 2 Notes");
    memo2Dialog->setMinimumHeight(150);

    this->memo3Dialog = new QPlainTextEdit(parent);
    memo3Dialog->setReadOnly(false);
    memo3Dialog->setDocumentTitle("Patch Memo 3 Notes");
    memo3Dialog->setMinimumHeight(150);

    this->memo4Dialog = new QPlainTextEdit(parent);
    memo4Dialog->setReadOnly(false);
    memo4Dialog->setDocumentTitle("Patch Memo 4 Notes");
    memo4Dialog->setMinimumHeight(150);

    SysxIO *sysxIO = SysxIO::Instance();

    memo1Dialog->setPlainText(sysxIO->memo1Array);
    memo1Dialog->show();

    memo2Dialog->setPlainText(sysxIO->memo2Array);
    memo2Dialog->show();

    memo3Dialog->setPlainText(sysxIO->memo3Array);
    memo3Dialog->show();

    memo4Dialog->setPlainText(sysxIO->memo4Array);
    memo4Dialog->show();


    QPushButton *cancelButton = new QPushButton(tr("Close"));
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(cancel()));
    cancelButton->setWhatsThis(tr("Will close the currently open Dialog page."));

    QPushButton *saveAsButton = new QPushButton(tr("Patch file Save As"));
    connect(saveAsButton, SIGNAL(clicked()), this, SLOT(saveAs()));
    saveAsButton->setWhatsThis(tr("Will save the current Patch to file in a *.G5L format."));

    QHBoxLayout *memo1Layout = new QHBoxLayout;
    memo1Layout->addWidget(label1);
    memo1Layout->addWidget(memo1Dialog);

    QHBoxLayout *memo2Layout = new QHBoxLayout;
    memo2Layout->addWidget(label2);
    memo2Layout->addWidget(memo2Dialog);

    QHBoxLayout *memo3Layout = new QHBoxLayout;
    memo3Layout->addWidget(label3);
    memo3Layout->addWidget(memo3Dialog);

    QHBoxLayout *memo4Layout = new QHBoxLayout;
    memo4Layout->addWidget(label4);
    memo4Layout->addWidget(memo4Dialog);

    QVBoxLayout *memoLayout = new QVBoxLayout;
    memoLayout->addItem(memo1Layout);
    memoLayout->addSpacing(12);
    memoLayout->addItem(memo2Layout);;
    memoLayout->addSpacing(12);
    memoLayout->addItem(memo3Layout);
    memoLayout->addSpacing(12);
    memoLayout->addItem(memo4Layout);

    QHBoxLayout *buttonsLayout = new QHBoxLayout;
    buttonsLayout->addStretch(1);
    buttonsLayout->addWidget(label5);
    buttonsLayout->addSpacing(12);
    buttonsLayout->addWidget(saveAsButton);
    buttonsLayout->addSpacing(12);
    buttonsLayout->addWidget(cancelButton);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(memoLayout);
    mainLayout->addStretch(1);
    mainLayout->addSpacing(12);
    mainLayout->addLayout(buttonsLayout);
    setLayout(mainLayout);

    setWindowTitle(tr("GR-55 Patch notes"));//+ patchName);
}

notesDialog::~notesDialog()
{
    SysxIO *sysxIO = SysxIO::Instance();
    sysxIO->memo1Array.clear();
    sysxIO->memo2Array.clear();
    sysxIO->memo3Array.clear();
    sysxIO->memo4Array.clear();
    sysxIO->memo1Array.append(memo1Dialog->toPlainText().simplified());
    sysxIO->memo2Array.append(memo2Dialog->toPlainText().simplified());
    sysxIO->memo3Array.append(memo3Dialog->toPlainText().simplified());
    sysxIO->memo4Array.append(memo4Dialog->toPlainText().simplified());
    this->deleteLater();
}

void notesDialog::cancel()
{
    this->close();
}

void notesDialog::saveAs()
{
    SysxIO *sysxIO = SysxIO::Instance();
    sysxIO->memo1Array.clear();
    sysxIO->memo2Array.clear();
    sysxIO->memo3Array.clear();
    sysxIO->memo4Array.clear();
    sysxIO->memo1Array.append(memo1Dialog->toPlainText().simplified());
    sysxIO->memo2Array.append(memo2Dialog->toPlainText().simplified());
    sysxIO->memo3Array.append(memo3Dialog->toPlainText().simplified());
    sysxIO->memo4Array.append(memo4Dialog->toPlainText().simplified());
    Preferences *preferences = Preferences::Instance();
    QString dir = preferences->getPreferences("General", "Files", "dir");

    QString fileName = QFileDialog::getSaveFileName(
                this,
                tr("Save Patch *.g5l"),
                dir,
                tr("ROLAND Librarian File (*.g5l)"));
    if (!fileName.isEmpty())
    {
        if(!fileName.contains(".g5l"))
        {
            fileName.append(".g5l");
        };
        file.writeG5L(fileName);

        file.setFile(fileName);
        if(file.readFile())
        {
            // DO SOMETHING AFTER READING THE FILE (UPDATE THE GUI)
            QString area = "Structure";
            sysxIO->setFileSource(area, file.getFileSource());
            sysxIO->relayUpdateSignal();
        };

    };
}
