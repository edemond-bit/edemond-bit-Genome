/****************************************************************************
** Form implementation generated from reading ui file 'referencedirectory.ui'
**
** Created: Sat Nov 27 12:06:28 2010
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.3   edited Nov 24 2003 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "referencedirectory.h"

#include <qvariant.h>
#include <qlabel.h>
#include <qgroupbox.h>
#include <qsplitter.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "referencedirectory.ui.h"

/*
 *  Constructs a ReferenceDirectory as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
ReferenceDirectory::ReferenceDirectory( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "ReferenceDirectory" );

    textLabel1 = new QLabel( this, "textLabel1" );
    textLabel1->setGeometry( QRect( 80, 310, 260, 20 ) );

    groupBoxGene_Mark = new QGroupBox( this, "groupBoxGene_Mark" );
    groupBoxGene_Mark->setGeometry( QRect( 29, 219, 500, 80 ) );

    splitter5 = new QSplitter( groupBoxGene_Mark, "splitter5" );
    splitter5->setGeometry( QRect( 20, 30, 460, 30 ) );
    splitter5->setOrientation( QSplitter::Horizontal );

    lineEdit109_3 = new QLineEdit( splitter5, "lineEdit109_3" );

    pushButton167_3 = new QPushButton( splitter5, "pushButton167_3" );

    groupBoxNCBI = new QGroupBox( this, "groupBoxNCBI" );
    groupBoxNCBI->setGeometry( QRect( 30, 30, 500, 80 ) );

    splitter6 = new QSplitter( groupBoxNCBI, "splitter6" );
    splitter6->setGeometry( QRect( 20, 30, 460, 30 ) );
    splitter6->setOrientation( QSplitter::Horizontal );

    lineEdit109 = new QLineEdit( splitter6, "lineEdit109" );

    pushButton167 = new QPushButton( splitter6, "pushButton167" );

    groupBoxGlimmer = new QGroupBox( this, "groupBoxGlimmer" );
    groupBoxGlimmer->setGeometry( QRect( 30, 120, 500, 80 ) );

    splitter3 = new QSplitter( groupBoxGlimmer, "splitter3" );
    splitter3->setGeometry( QRect( 20, 30, 460, 30 ) );
    splitter3->setOrientation( QSplitter::Horizontal );

    lineEdit109_2 = new QLineEdit( splitter3, "lineEdit109_2" );

    pushButton167_2 = new QPushButton( splitter3, "pushButton167_2" );

    pushButton170 = new QPushButton( this, "pushButton170" );
    pushButton170->setGeometry( QRect( 440, 310, 90, 24 ) );

    pushButton171 = new QPushButton( this, "pushButton171" );
    pushButton171->setGeometry( QRect( 340, 310, 90, 24 ) );
    languageChange();
    resize( QSize(566, 344).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    // signals and slots connections
    connect( pushButton167, SIGNAL( clicked() ), this, SLOT( pushButton167_clicked() ) );
    connect( pushButton167_2, SIGNAL( clicked() ), this, SLOT( pushButton167_2_clicked() ) );
    connect( pushButton167_3, SIGNAL( clicked() ), this, SLOT( pushButton167_3_clicked() ) );
    connect( pushButton170, SIGNAL( clicked() ), this, SLOT( pushButton170_clicked() ) );
    connect( pushButton171, SIGNAL( clicked() ), this, SLOT( pushButton171_clicked() ) );
    connect( this, SIGNAL( destroyed(QObject*) ), this, SLOT( ReferenceDirectory_destroyed(QObject*) ) );

    // tab order
    setTabOrder( lineEdit109, pushButton167 );
    setTabOrder( pushButton167, lineEdit109_2 );
    setTabOrder( lineEdit109_2, pushButton167_2 );
    setTabOrder( pushButton167_2, lineEdit109_3 );
    setTabOrder( lineEdit109_3, pushButton167_3 );
    setTabOrder( pushButton167_3, pushButton171 );
    setTabOrder( pushButton171, pushButton170 );
    init();
}

/*
 *  Destroys the object and frees any allocated resources
 */
ReferenceDirectory::~ReferenceDirectory()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void ReferenceDirectory::languageChange()
{
    setCaption( tr( "Choose Directory" ) );
    textLabel1->setText( tr( "NOTE: Skip if directory paths are correct" ) );
    groupBoxGene_Mark->setTitle( tr( "Enter directory path of Gene_Mark data" ) );
    pushButton167_3->setText( tr( "Browse" ) );
    groupBoxNCBI->setTitle( tr( "Enter directory path of NCBI data" ) );
    pushButton167->setText( tr( "Browse" ) );
    groupBoxGlimmer->setTitle( tr( "Enter directory path of Glimmer data" ) );
    pushButton167_2->setText( tr( "Browse" ) );
    pushButton170->setText( tr( "Ok" ) );
    pushButton171->setText( tr( "Skip" ) );
}

