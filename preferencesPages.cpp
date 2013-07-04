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

#include <QtGui>
#include "midiIO.h"
#include "RtMidi.h"
#include "preferencesPages.h"
#include "Preferences.h"

GeneralPage::GeneralPage(QWidget *parent)
    : QWidget(parent)
{
    Preferences *preferences = Preferences::Instance();
    QString dir = preferences->getPreferences("General", "Files", "dir");

    QGroupBox *patchGroup = new QGroupBox(QObject::tr("Patch folder"));

    QLabel *descriptionLabel = new QLabel(QObject::tr("Select the default folder for storing patches."));
    QLabel *dirLabel = new QLabel(QObject::tr("Default patch folder:"));
    QLineEdit *dirEdit = new QLineEdit(dir);
    QPushButton *browseButton = new QPushButton(QObject::tr("Browse"));

    connect(browseButton, SIGNAL(clicked()), this, SLOT(browseDir()));

    this->dirEdit = dirEdit;

    QHBoxLayout *dirEditLayout = new QHBoxLayout;
    dirEditLayout->addWidget(dirEdit);
    dirEditLayout->addWidget(browseButton);

    QVBoxLayout *dirLayout = new QVBoxLayout;
    dirLayout->addWidget(descriptionLabel);
    dirLayout->addSpacing(12);
    dirLayout->addWidget(dirLabel);
    dirLayout->addLayout(dirEditLayout);

    QVBoxLayout *patchLayout = new QVBoxLayout;
    patchLayout->addLayout(dirLayout);
    patchGroup->setLayout(patchLayout);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(patchGroup);
    mainLayout->addStretch(1);
    setLayout(mainLayout);
}

MidiPage::MidiPage(QWidget *parent)
    : QWidget(parent)
{
    bool ok; int id;
    midiIO *midi = new midiIO();
    Preferences *preferences = Preferences::Instance();
    QString midiInDevice = preferences->getPreferences("Midi", "MidiIn", "device");
    QString midiOutDevice = preferences->getPreferences("Midi", "MidiOut", "device");
    QString dBugScreen = preferences->getPreferences("Midi", "DBug", "bool");
    QString midiTxChSet = preferences->getPreferences("Midi", "TxCh", "set");
    //QString midiDelaySet = preferences->getPreferences("Midi", "Delay", "set");

    QList<QString> midiInDevices = midi->getMidiInDevices();
    QList<QString> midiOutDevices = midi->getMidiOutDevices();

    QGroupBox *midiGroup = new QGroupBox(QObject::tr("Midi settings"));

    QLabel *mididescriptionLabel = new QLabel(QObject::tr("Select your midi in and out device."));
    QLabel *midiInLabel = new QLabel(QObject::tr("Midi in:"));
    QLabel *midiOutLabel = new QLabel(QObject::tr("Midi out:"));

    QComboBox *midiInCombo = new QComboBox;
    this->midiInCombo = midiInCombo;
    midiInCombo->addItem(QObject::tr("Select midi-in device"));
    id = midiInDevices.count();
    midiInCombo->setCurrentIndex(0);

    for(int x=0; x<id; ++x)
    {
        midiInCombo->addItem(midiInDevices.at(x).toAscii());
        QString item = midiInDevices.at(x).toAscii();
        if ( item == midiInDevice )
        {
            midiInCombo->setCurrentIndex(x+1);
        };
    };

    QComboBox *midiOutCombo = new QComboBox;
    this->midiOutCombo = midiOutCombo;
    midiOutCombo->addItem(QObject::tr("Select midi-out device"));
    id = midiOutDevices.count();
    midiOutCombo->setCurrentIndex(0);

    for(int x=0; x<id; ++x)
    {
        midiOutCombo->addItem(midiOutDevices.at(x).toAscii());
        QString item = midiOutDevices.at(x).toAscii();
        if ( item == midiOutDevice )
        {
            midiOutCombo->setCurrentIndex(x+1);
        };
    };

    QVBoxLayout *midiLabelLayout = new QVBoxLayout;
    midiLabelLayout->addWidget(midiInLabel);
    midiLabelLayout->addWidget(midiOutLabel);

    QVBoxLayout *midiComboLayout = new QVBoxLayout;
    midiComboLayout->addWidget(midiInCombo);
    midiComboLayout->addWidget(midiOutCombo);

    QHBoxLayout *midiSelectLayout = new QHBoxLayout;
    midiSelectLayout->addLayout(midiLabelLayout);
    midiSelectLayout->addLayout(midiComboLayout);

    QVBoxLayout *midiDevLayout = new QVBoxLayout;
    midiDevLayout->addWidget(mididescriptionLabel);
    midiDevLayout->addSpacing(12);
    midiDevLayout->addLayout(midiSelectLayout);

    QVBoxLayout *midiLayout = new QVBoxLayout;
    midiLayout->addLayout(midiDevLayout);
    midiGroup->setLayout(midiLayout);



    QGroupBox *dBugScreenGroup = new QGroupBox(QObject::tr("Advanced settings"));

    QLabel *dBugDescriptionLabel = new QLabel(QObject::tr("Debug mode."));
    QLabel *midiTxChDescriptionLabel = new QLabel(tr("Midi Tx Channel:"));
    //QLabel *midiDelayDescriptionLabel = new QLabel(tr("Realtime edit send rate."));

    QCheckBox *dBugCheckBox = new QCheckBox(QObject::tr("deBug Mode"));
    QSpinBox *midiTxChSpinBox = new QSpinBox;
    QSpinBox *midiDelaySpinBox = new QSpinBox;

    this->dBugCheckBox = dBugCheckBox;
    if(dBugScreen=="true")
    {
        dBugCheckBox->setChecked(true);
    };

    this->midiTxChSpinBox = midiTxChSpinBox;
    const int tempDataWrite = preferences->getPreferences("Midi", "TxCh", "set").toInt(&ok, 10);
    midiTxChSpinBox->setValue(tempDataWrite);
    midiTxChSpinBox->setRange(1, 16);
    midiTxChSpinBox->setPrefix("Channel ");
    //midiTxChSpinBox->setSuffix(QObject::tr("Channel"));

    this->midiDelaySpinBox = midiDelaySpinBox;
    const int minWait = preferences->getPreferences("Midi", "Delay", "set").toInt(&ok, 10);
    midiDelaySpinBox->setValue(minWait);
    midiDelaySpinBox->setRange(1, 20);
    midiDelaySpinBox->setPrefix("= ");
    midiDelaySpinBox->setSuffix(QObject::tr(" times/second"));


    QVBoxLayout *dBugLabelLayout = new QVBoxLayout;
    dBugLabelLayout->addWidget(dBugDescriptionLabel);
    dBugLabelLayout->addWidget(midiTxChDescriptionLabel);
    //dBugLabelLayout->addWidget(midiDelayDescriptionLabel);

    QVBoxLayout *dBugTimeBoxLayout = new QVBoxLayout;
    dBugTimeBoxLayout->addWidget(dBugCheckBox);
    dBugTimeBoxLayout->addWidget(midiTxChSpinBox);
    //dBugTimeBoxLayout->addWidget(midiDelaySpinBox);

    QHBoxLayout *dBugSelectLayout = new QHBoxLayout;
    dBugSelectLayout->addLayout(dBugLabelLayout);
    dBugSelectLayout->addLayout(dBugTimeBoxLayout);

    QVBoxLayout *dBugScreenLayout = new QVBoxLayout;
    dBugScreenLayout->addWidget(dBugDescriptionLabel);
    dBugScreenLayout->addLayout(dBugSelectLayout);

    dBugScreenGroup->setLayout(dBugScreenLayout);


    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(midiGroup);
    mainLayout->addWidget(dBugScreenGroup);
    mainLayout->addStretch(1);
    setLayout(mainLayout);
}

WindowPage::WindowPage(QWidget *parent)
    : QWidget(parent)
{
    Preferences *preferences = Preferences::Instance();
    QString windowRestore = preferences->getPreferences("Window", "Restore", "window");
    QString sidepanelRestore = preferences->getPreferences("Window", "Restore", "sidepanel");
    QString splashScreen = preferences->getPreferences("Window", "Splash", "bool");
    QString SingleWindow = preferences->getPreferences("Window", "Single", "bool");
    QString WidgetsUse = preferences->getPreferences("Window", "Widgets", "bool");

    QGroupBox *windowGroup = new QGroupBox(QObject::tr("Window settings"));

    QLabel *restoreDescriptionLabel = new QLabel(QObject::tr("Select if you want the window position to be saved on exit."));
    QCheckBox *windowCheckBox = new QCheckBox(QObject::tr("Restore window"));
    QCheckBox *sidepanelCheckBox = new QCheckBox(QObject::tr("Restore sidepanel"));
    QCheckBox *singleWindowCheckBox = new QCheckBox(QObject::tr("Single Window Layout"));
    QCheckBox *widgetsCheckBox = new QCheckBox(QObject::tr("Graphical Assistance"));
    this->windowCheckBox = windowCheckBox;
    this->sidepanelCheckBox = sidepanelCheckBox;
    this->singleWindowCheckBox = singleWindowCheckBox;
    this->widgetsCheckBox = widgetsCheckBox;

    if(windowRestore=="true") { windowCheckBox->setChecked(true); };
    if(sidepanelRestore=="true") { sidepanelCheckBox->setChecked(true); };
    if(SingleWindow=="true") { singleWindowCheckBox->setChecked(true); };
    if(WidgetsUse=="true") { widgetsCheckBox->setChecked(true); };

    QVBoxLayout *restoreLayout = new QVBoxLayout;
    restoreLayout->addWidget(restoreDescriptionLabel);
    restoreLayout->addSpacing(12);
    restoreLayout->addWidget(windowCheckBox);
    restoreLayout->addWidget(sidepanelCheckBox);
    restoreLayout->addWidget(singleWindowCheckBox);
    restoreLayout->addWidget(widgetsCheckBox);

    QVBoxLayout *windowLayout = new QVBoxLayout;
    windowLayout->addLayout(restoreLayout);
    windowGroup->setLayout(windowLayout);

    QGroupBox *splashScreenGroup = new QGroupBox(QObject::tr("Show splash screen"));

    QLabel *splashDescriptionLabel = new QLabel(QObject::tr("Disable or enable the splash screen."));
    QCheckBox *splashCheckBox = new QCheckBox(QObject::tr("Splash screen"));
    this->splashCheckBox = splashCheckBox;

    if(splashScreen=="true") { splashCheckBox->setChecked(true); };

    QVBoxLayout *splashLayout = new QVBoxLayout;
    splashLayout->addWidget(splashDescriptionLabel);
    splashLayout->addSpacing(12);
    splashLayout->addWidget(splashCheckBox);

    QVBoxLayout *splashScreenLayout = new QVBoxLayout;
    splashScreenLayout->addLayout(splashLayout);
    splashScreenGroup->setLayout(splashScreenLayout);

    QLabel *note = new QLabel(QObject::tr("<b>***Changes take effect on next startup***</b>" ));

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(windowGroup);
    mainLayout->addWidget(splashScreenGroup);
    mainLayout->addWidget(note);

    mainLayout->addStretch(1);
    setLayout(mainLayout);
}

LanguagePage::LanguagePage(QWidget *parent)
    : QWidget(parent)
{
    Preferences *preferences = Preferences::Instance();
    QString lang = preferences->getPreferences("Language", "Locale", "select");
    bool ok;
    int choice = lang.toInt(&ok, 16);

    QGroupBox *languageGroup = new QGroupBox(QObject::tr("Language Selection"));

    QRadioButton *englishButton = new QRadioButton(QObject::tr("English"));
    //this->englishButton = englishButton;
    this->frenchButton = new QRadioButton(QObject::tr("French"));
    this->germanButton = new QRadioButton(QObject::tr("German"));
    this->portugueseButton = new QRadioButton(QObject::tr("Portuguese"));
    this->spanishButton = new QRadioButton(QObject::tr("Spanish"));
    this->japaneseButton = new QRadioButton(QObject::tr("Japanese"));
    this->chineseButton = new QRadioButton(QObject::tr("Chinese (simplified)"));
    if (choice == 6)      {chineseButton->setChecked(true); }
    else if (choice == 5) {japaneseButton->setChecked(true); }
    else if (choice == 4) {spanishButton->setChecked(true); }
    else if (choice == 3) {portugueseButton->setChecked(true); }
    else if (choice == 2) {germanButton->setChecked(true); }
    else if (choice == 1) {frenchButton->setChecked(true); }
    else {englishButton->setChecked(true); };

    QVBoxLayout *languageLayout = new QVBoxLayout;
    languageLayout->addWidget(englishButton);
    languageLayout->addWidget(frenchButton);
    languageLayout->addWidget(germanButton);
    languageLayout->addWidget(portugueseButton);
    languageLayout->addWidget(spanishButton);
    languageLayout->addWidget(japaneseButton);
    languageLayout->addWidget(chineseButton);

    languageGroup->setLayout(languageLayout);

    QLabel *note = new QLabel(QObject::tr("<b>***Changes take effect on next startup***</b>" ));

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(languageGroup);
    languageLayout->addSpacing(12);
    mainLayout->addStretch(1);
    mainLayout->addWidget(note);
    setLayout(mainLayout);
}

StylePage::StylePage(QWidget *parent)
    : QWidget(parent)
{
    Preferences *preferences = Preferences::Instance();
    QString setting = preferences->getPreferences("Scheme", "Style", "select");
    bool ok;
    int choice = setting.toInt(&ok, 16);

    QGroupBox *styleGroup = new QGroupBox(QObject::tr("Window Style Selection"));

    QRadioButton *standardButton = new QRadioButton(QObject::tr("System"));
    this->standardButton = standardButton;
    this->plastiqueButton = new QRadioButton(QObject::tr("Plastique"));
    this->cdeButton = new QRadioButton(QObject::tr("Cleanlooks"));
    this->motifButton = new QRadioButton(QObject::tr("Motif"));
    if (choice == 3) {motifButton->setChecked(true); }
    else if (choice == 2) {cdeButton->setChecked(true); }
    else if (choice == 1) {plastiqueButton->setChecked(true); }
    else {standardButton->setChecked(true); };

    QVBoxLayout *styleLayout = new QVBoxLayout;
    styleLayout->addWidget(standardButton);
    styleLayout->addWidget(plastiqueButton);
    styleLayout->addWidget(cdeButton);
    styleLayout->addWidget(motifButton);

    styleGroup->setLayout(styleLayout);


    setting = preferences->getPreferences("Scheme", "Colour", "select");
    choice = setting.toInt(&ok, 16);
    QGroupBox *colourGroup = new QGroupBox(QObject::tr("Colour Scheme Selection"));

    QRadioButton *blueButton = new QRadioButton(QObject::tr("GR Blue"));
    this->blueButton = blueButton;
    this->blackButton = new QRadioButton(QObject::tr("GR Black"));
    this->aquaButton = new QRadioButton(QObject::tr("Aqua"));
    this->greenButton = new QRadioButton(QObject::tr("Gumtown Green"));
    this->whiteButton = new QRadioButton(QObject::tr("White"));
    if (choice == 4) {whiteButton->setChecked(true); }
    else if (choice == 3) {greenButton->setChecked(true); }
    else if (choice == 2) {aquaButton->setChecked(true); }
    else if (choice == 1) {blackButton->setChecked(true); }
    else {blueButton->setChecked(true); };

    QVBoxLayout *colourLayout = new QVBoxLayout;
    colourLayout->addWidget(blueButton);
    colourLayout->addWidget(blackButton);
    colourLayout->addWidget(aquaButton);
    colourLayout->addWidget(greenButton);
    colourLayout->addWidget(whiteButton);

    colourGroup->setLayout(colourLayout);

    QLabel *note = new QLabel(QObject::tr("<b>***Changes take effect on next startup***</b>" ));

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(styleGroup);
    mainLayout->addWidget(colourGroup);
    styleLayout->addSpacing(12);
    mainLayout->addStretch(1);
    mainLayout->addWidget(note);
    setLayout(mainLayout);
}

void GeneralPage::browseDir()
{
    QString dirName = QFileDialog::getExistingDirectory(this, QObject::tr("Select the default folder for storing patches."),
                                                        this->dirEdit->text(),
                                                        QFileDialog::ShowDirsOnly);
    if(!dirName.isEmpty())
    {
        this->dirEdit->setText(dirName);
    };
}
