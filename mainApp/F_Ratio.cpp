/****************************************************************************
** Form implementation generated from reading ui file 'F_Ratio.ui'
**
** Created: Sat Nov 27 12:06:05 2010
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.3   edited Nov 24 2003 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "F_Ratio.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qbuttongroup.h>
#include <qradiobutton.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "F_Ratio.ui.h"

/*
 *  Constructs a F_Ratio as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
F_Ratio::F_Ratio( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "F_Ratio" );
    setAcceptDrops( FALSE );
    setSizeGripEnabled( TRUE );
    setModal( TRUE );

    QWidget* privateLayoutWidget = new QWidget( this, "Layout1" );
    privateLayoutWidget->setGeometry( QRect( 20, 120, 476, 33 ) );
    Layout1 = new QHBoxLayout( privateLayoutWidget, 0, 6, "Layout1"); 
    Horizontal_Spacing2 = new QSpacerItem( 20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    Layout1->addItem( Horizontal_Spacing2 );

    buttonOk = new QPushButton( privateLayoutWidget, "buttonOk" );
    buttonOk->setAutoDefault( TRUE );
    buttonOk->setDefault( TRUE );
    Layout1->addWidget( buttonOk );

    buttonGroup11 = new QButtonGroup( this, "buttonGroup11" );
    buttonGroup11->setGeometry( QRect( 20, 10, 480, 90 ) );

    radioButton21 = new QRadioButton( buttonGroup11, "radioButton21" );
    radioButton21->setGeometry( QRect( 40, 10, 410, 21 ) );
    radioButton21->setChecked( TRUE );

    radioButton22 = new QRadioButton( buttonGroup11, "radioButton22" );
    radioButton22->setGeometry( QRect( 40, 40, 390, 40 ) );
    languageChange();
    resize( QSize(511, 175).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    // signals and slots connections
    connect( radioButton21, SIGNAL( clicked() ), this, SLOT( radioButton21_clicked() ) );
    connect( radioButton22, SIGNAL( clicked() ), this, SLOT( radioButton22_clicked() ) );
    connect( buttonOk, SIGNAL( pressed() ), this, SLOT( buttonOk_pressed() ) );
    connect( buttonOk, SIGNAL( clicked() ), this, SLOT( accept() ) );
}

/*
 *  Destroys the object and frees any allocated resources
 */
F_Ratio::~F_Ratio()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void F_Ratio::languageChange()
{
    setCaption( tr( "F-Ratio Computation" ) );
    buttonOk->setText( tr( "&OK" ) );
    buttonOk->setAccel( QKeySequence( QString::null ) );
    buttonGroup11->setTitle( QString::null );
    radioButton21->setText( tr( "Compute with tri-neucleotide for all sequences" ) );
    radioButton22->setText( tr( "Compute with tetra-neucleotide for sequences with \n"
"length 60 to 300 and tri-neucleotide for all other sequences" ) );
}

