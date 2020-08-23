/****************************************************************************
** Form implementation generated from reading ui file 'createDirectory/createDirectory.ui'
**
** Created: Sat Nov 27 12:06:31 2010
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.3   edited Nov 24 2003 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "createDirectory.h"

#include <qvariant.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "createDirectory.ui.h"

/*
 *  Constructs a Folder_creation as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
Folder_creation::Folder_creation( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "Folder_creation" );
    setSizeGripEnabled( TRUE );
    setModal( TRUE );

    textLabel1 = new QLabel( this, "textLabel1" );
    textLabel1->setGeometry( QRect( 20, 20, 325, 84 ) );

    QWidget* privateLayoutWidget = new QWidget( this, "layout7" );
    privateLayoutWidget->setGeometry( QRect( 10, 110, 461, 60 ) );
    layout7 = new QHBoxLayout( privateLayoutWidget, 11, 6, "layout7"); 

    lineEdit12 = new QLineEdit( privateLayoutWidget, "lineEdit12" );
    layout7->addWidget( lineEdit12 );

    buttonOk = new QPushButton( privateLayoutWidget, "buttonOk" );
    buttonOk->setAutoDefault( TRUE );
    buttonOk->setDefault( TRUE );
    layout7->addWidget( buttonOk );

    buttonCancel = new QPushButton( privateLayoutWidget, "buttonCancel" );
    buttonCancel->setAutoDefault( TRUE );
    layout7->addWidget( buttonCancel );
    languageChange();
    resize( QSize(474, 176).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    // signals and slots connections
    connect( buttonOk, SIGNAL( clicked() ), this, SLOT( buttonOk_clicked() ) );
    connect( buttonCancel, SIGNAL( clicked() ), this, SLOT( reject() ) );
    init();
}

/*
 *  Destroys the object and frees any allocated resources
 */
Folder_creation::~Folder_creation()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void Folder_creation::languageChange()
{
    setCaption( tr( "Warning: Create folder" ) );
    textLabel1->setText( tr( "[NOTE: This program uses current directory\n"
"(from where the program is run) for storing result files.\n"
"\n"
"To store them in seperate folder within current directory \n"
"you need to create the directory.]" ) );
    buttonOk->setText( tr( "&OK" ) );
    buttonOk->setAccel( QKeySequence( QString::null ) );
    buttonCancel->setText( tr( "&Cancel" ) );
    buttonCancel->setAccel( QKeySequence( QString::null ) );
}

