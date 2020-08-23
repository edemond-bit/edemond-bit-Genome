/****************************************************************************
** Form implementation generated from reading ui file 'Random_Seq/RandomDialog.ui'
**
** Created: Sat Nov 27 12:06:32 2010
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.3   edited Nov 24 2003 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "RandomDialog.h"

#include <qvariant.h>
#include <qcheckbox.h>
#include <qgroupbox.h>
#include <qlabel.h>
#include <qpushbutton.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "Random_Seq/RandomDialog.h"
#include "RandomDialog.ui.h"

/*
 *  Constructs a RandomDialog as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
RandomDialog::RandomDialog( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "RandomDialog" );
    setSizeGripEnabled( TRUE );

    checkBox9_2 = new QCheckBox( this, "checkBox9_2" );
    checkBox9_2->setGeometry( QRect( 331, 50, 170, 20 ) );

    groupBox32 = new QGroupBox( this, "groupBox32" );
    groupBox32->setGeometry( QRect( 7, 8, 501, 291 ) );

    textLabel1_5 = new QLabel( groupBox32, "textLabel1_5" );
    textLabel1_5->setGeometry( QRect( 30, 83, 210, 40 ) );

    textLabel4_3 = new QLabel( groupBox32, "textLabel4_3" );
    textLabel4_3->setGeometry( QRect( 40, 200, 340, 20 ) );

    textLabel2 = new QLabel( groupBox32, "textLabel2" );
    textLabel2->setGeometry( QRect( 40, 170, 345, 20 ) );

    textLabel1 = new QLabel( groupBox32, "textLabel1" );
    textLabel1->setGeometry( QRect( 40, 140, 280, 30 ) );

    QWidget* privateLayoutWidget = new QWidget( groupBox32, "Layout1" );
    privateLayoutWidget->setGeometry( QRect( 10, 240, 476, 33 ) );
    Layout1 = new QHBoxLayout( privateLayoutWidget, 0, 6, "Layout1"); 
    Horizontal_Spacing2 = new QSpacerItem( 20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    Layout1->addItem( Horizontal_Spacing2 );

    buttonCreateRand = new QPushButton( privateLayoutWidget, "buttonCreateRand" );
    buttonCreateRand->setAutoDefault( TRUE );
    buttonCreateRand->setDefault( TRUE );
    Layout1->addWidget( buttonCreateRand );

    buttonCancel = new QPushButton( privateLayoutWidget, "buttonCancel" );
    buttonCancel->setAutoDefault( TRUE );
    Layout1->addWidget( buttonCancel );

    textLabel1_2 = new QLabel( groupBox32, "textLabel1_2" );
    textLabel1_2->setGeometry( QRect( 364, 85, 110, 20 ) );

    swapPercent = new QLineEdit( groupBox32, "swapPercent" );
    swapPercent->setGeometry( QRect( 391, 140, 80, 21 ) );

    mutPercent = new QLineEdit( groupBox32, "mutPercent" );
    mutPercent->setGeometry( QRect( 391, 170, 80, 21 ) );

    lineEdit1 = new QLineEdit( groupBox32, "lineEdit1" );
    lineEdit1->setGeometry( QRect( 260, 83, 80, 21 ) );

    lineEdit4 = new QLineEdit( groupBox32, "lineEdit4" );
    lineEdit4->setGeometry( QRect( 380, 200, 40, 21 ) );

    lineEdit3 = new QLineEdit( groupBox32, "lineEdit3" );
    lineEdit3->setGeometry( QRect( 190, 41, 121, 21 ) );

    textLabel2_5 = new QLabel( groupBox32, "textLabel2_5" );
    textLabel2_5->setGeometry( QRect( 30, 11, 150, 20 ) );

    lineEdit2 = new QLineEdit( groupBox32, "lineEdit2" );
    lineEdit2->setGeometry( QRect( 190, 11, 121, 21 ) );

    textLabel3_5 = new QLabel( groupBox32, "textLabel3_5" );
    textLabel3_5->setGeometry( QRect( 29, 41, 140, 20 ) );

    checkBox9 = new QCheckBox( groupBox32, "checkBox9" );
    checkBox9->setGeometry( QRect( 320, 10, 170, 40 ) );
    languageChange();
    resize( QSize(514, 305).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    // signals and slots connections
    connect( buttonCreateRand, SIGNAL( clicked() ), this, SLOT( accept() ) );
    connect( buttonCancel, SIGNAL( clicked() ), this, SLOT( reject() ) );
    connect( lineEdit2, SIGNAL( textChanged(const QString&) ), this, SLOT( lineEdit2_textChanged(const QString&) ) );
    connect( lineEdit3, SIGNAL( textChanged(const QString&) ), this, SLOT( lineEdit3_textChanged(const QString&) ) );
    connect( lineEdit1, SIGNAL( textChanged(const QString&) ), this, SLOT( lineEdit1_textChanged(const QString&) ) );
    connect( buttonCreateRand, SIGNAL( pressed() ), this, SLOT( buttonCreateRand_pressed() ) );
    connect( buttonCreateRand, SIGNAL( released() ), this, SLOT( buttonCreateRand_released() ) );

    // tab order
    setTabOrder( lineEdit1, lineEdit2 );
    setTabOrder( lineEdit2, lineEdit3 );
    setTabOrder( lineEdit3, swapPercent );
    setTabOrder( swapPercent, mutPercent );
    setTabOrder( mutPercent, lineEdit4 );
    setTabOrder( lineEdit4, buttonCreateRand );
    setTabOrder( buttonCreateRand, buttonCancel );
    init();
}

/*
 *  Destroys the object and frees any allocated resources
 */
RandomDialog::~RandomDialog()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void RandomDialog::languageChange()
{
    setCaption( tr( "Random Sequence Generation" ) );
    checkBox9_2->setText( tr( "Use Auto generated value" ) );
    groupBox32->setTitle( QString::null );
    textLabel1_5->setText( tr( "How many ORF's to be perturbed?\n"
"( number must be even )" ) );
    textLabel4_3->setText( tr( "How many random sequence do you want for each ORF?" ) );
    textLabel2->setText( tr( "Enter number of mutation (in % of the length of sequence) :" ) );
    textLabel1->setText( tr( "Number of Swap ( in % of length of sequence):" ) );
    buttonCreateRand->setText( tr( "Ok" ) );
    buttonCreateRand->setAccel( QKeySequence( QString::null ) );
    buttonCancel->setText( tr( "&Cancel" ) );
    buttonCancel->setAccel( QKeySequence( QString::null ) );
    textLabel1_2->setText( tr( "textLabel1" ) );
    swapPercent->setText( tr( "35" ) );
    mutPercent->setText( tr( "35" ) );
    lineEdit4->setText( tr( "10" ) );
    textLabel2_5->setText( tr( "Minimum ORF length" ) );
    textLabel3_5->setText( tr( "Maximum ORF length" ) );
    checkBox9->setText( tr( "Use Auto generated value" ) );
}

