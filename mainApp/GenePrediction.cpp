/****************************************************************************
** Form implementation generated from reading ui file 'GenePrediction.ui'
**
** Created: Sat Nov 27 12:06:06 2010
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.3   edited Nov 24 2003 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "GenePrediction.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qgroupbox.h>
#include <qwidgetstack.h>
#include <qwidget.h>
#include <qbuttongroup.h>
#include <qradiobutton.h>
#include <qlineedit.h>
#include <qtextedit.h>
#include <qcheckbox.h>
#include <qtabwidget.h>
#include <qframe.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>

#include "GenePrediction.ui.h"
static const char* const image0_data[] = { 
"32 30 4 1",
"a c #000000",
"b c #000083",
"# c #e6e6e6",
". c #fafafa",
"................................",
"################################",
"################################",
"################################",
"################################",
"################################",
"################################",
"################################",
"################################",
"#########a########bbbbb#########",
"#########aa######bbb#bbb########",
"#########aaa####bbb###bbb#######",
"#########aaaa###bb#####bb#######",
"#########aaaaa##bb#####bb#######",
"#########aaaaaa##b####bbb#######",
"#########aaaaaaa#####bbb########",
"#########aaaaaaaa###bbb#########",
"#########aaaaaaaaa#bbb##########",
"#########aaaaa#####bbb##########",
"#########aa#aaa#################",
"#########a##aaa####bbb##########",
"#############aaa###bbb##########",
"#############aaa################",
"##############aaa###############",
"##############aaa###############",
"################################",
"################################",
"################################",
"################################",
"################################"};

static const unsigned char image1_data[] = { 
    0x89, 0x50, 0x4e, 0x47, 0x0d, 0x0a, 0x1a, 0x0a, 0x00, 0x00, 0x00, 0x0d,
    0x49, 0x48, 0x44, 0x52, 0x00, 0x00, 0x00, 0x1e, 0x00, 0x00, 0x00, 0x14,
    0x08, 0x06, 0x00, 0x00, 0x00, 0x9a, 0xab, 0x8d, 0xc4, 0x00, 0x00, 0x00,
    0x88, 0x49, 0x44, 0x41, 0x54, 0x48, 0x89, 0xc5, 0xd3, 0x5b, 0x0e, 0x80,
    0x20, 0x0c, 0x44, 0xd1, 0x8b, 0x6b, 0x71, 0xff, 0x2b, 0x72, 0x2f, 0xf8,
    0x61, 0x30, 0x84, 0x14, 0xe4, 0x31, 0xc5, 0xfe, 0x77, 0x4e, 0x26, 0x50,
    0xf8, 0x69, 0xc2, 0x0e, 0xe4, 0x8c, 0xc4, 0xad, 0xb0, 0x05, 0x5e, 0xe1,
    0x31, 0xdd, 0xe0, 0x12, 0x4d, 0x60, 0x1a, 0x39, 0xdc, 0x6a, 0xe9, 0x06,
    0x7f, 0xb5, 0x74, 0x81, 0x47, 0x50, 0x19, 0x3c, 0x8a, 0x4a, 0xe0, 0x19,
    0x14, 0xe0, 0xb0, 0x96, 0xbd, 0xd1, 0x17, 0x9e, 0xc1, 0x57, 0x50, 0x80,
    0x30, 0x13, 0xb0, 0x8a, 0x42, 0xd6, 0xb8, 0x77, 0x14, 0x28, 0x14, 0x9f,
    0x2b, 0x85, 0xd6, 0xc2, 0x54, 0x28, 0x54, 0x1a, 0x5b, 0xef, 0xad, 0x44,
    0xc1, 0x38, 0xa7, 0x1c, 0x48, 0xe1, 0x6a, 0xd4, 0x84, 0x2d, 0x48, 0x8d,
    0x56, 0xe1, 0x1a, 0xae, 0x42, 0x9b, 0x70, 0x89, 0x2b, 0x51, 0xe8, 0x3c,
    0x27, 0x35, 0x0a, 0x70, 0x03, 0xb8, 0xa7, 0x45, 0x7f, 0xb0, 0x21, 0x19,
    0xfb, 0x00, 0x00, 0x00, 0x00, 0x49, 0x45, 0x4e, 0x44, 0xae, 0x42, 0x60,
    0x82
};


/*
 *  Constructs a Form1 which is a child of 'parent', with the
 *  name 'name'.' 
 */
Form1::Form1( QWidget* parent,  const char* name )
    : QFrame( parent, name ),
      image0( (const char **) image0_data )
{
    QImage img;
    img.loadFromData( image1_data, sizeof( image1_data ), "PNG" );
    image1 = img;
    if ( !name )
	setName( "Form1" );
    setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)5, 255, 255, sizePolicy().hasHeightForWidth() ) );
    setFrameShape( QFrame::NoFrame );
    setFrameShadow( QFrame::Plain );

    textLabel1 = new QLabel( this, "textLabel1" );
    textLabel1->setGeometry( QRect( 10, 10, 140, 20 ) );
    textLabel1->setFrameShape( QLabel::NoFrame );
    textLabel1->setFrameShadow( QLabel::Plain );

    pushButton74 = new QPushButton( this, "pushButton74" );
    pushButton74->setGeometry( QRect( 499, 4, 110, 28 ) );
    pushButton74->setIconSet( QIconSet( image0 ) );

    sequenceFileName = new QLabel( this, "sequenceFileName" );
    sequenceFileName->setGeometry( QRect( 150, 10, 340, 20 ) );

    closeSession = new QPushButton( this, "closeSession" );
    closeSession->setGeometry( QRect( 611, 3, 100, 30 ) );

    frame6 = new QFrame( this, "frame6" );
    frame6->setEnabled( TRUE );
    frame6->setGeometry( QRect( 30, 50, 690, 590 ) );
    frame6->setPaletteForegroundColor( QColor( 18, 0, 65 ) );
    frame6->setFrameShape( QFrame::StyledPanel );
    frame6->setFrameShadow( QFrame::Raised );

    textLabel3_4 = new QLabel( frame6, "textLabel3_4" );
    textLabel3_4->setGeometry( QRect( 11, 21, 668, 40 ) );
    QFont textLabel3_4_font(  textLabel3_4->font() );
    textLabel3_4_font.setPointSize( 16 );
    textLabel3_4->setFont( textLabel3_4_font ); 
    textLabel3_4->setAlignment( int( QLabel::WordBreak | QLabel::AlignCenter ) );

    textLabel4 = new QLabel( frame6, "textLabel4" );
    textLabel4->setGeometry( QRect( 11, 50, 668, 62 ) );

    groupBox18 = new QGroupBox( frame6, "groupBox18" );
    groupBox18->setGeometry( QRect( 11, 121, 670, 420 ) );

    sessionSelectionWg = new QWidgetStack( groupBox18, "sessionSelectionWg" );
    sessionSelectionWg->setGeometry( QRect( 5, 69, 661, 340 ) );

    WStackPage = new QWidget( sessionSelectionWg, "WStackPage" );

    pushButton78 = new QPushButton( WStackPage, "pushButton78" );
    pushButton78->setGeometry( QRect( 474, 189, 166, 26 ) );

    groupBox37 = new QGroupBox( WStackPage, "groupBox37" );
    groupBox37->setGeometry( QRect( 12, 81, 630, 93 ) );
    groupBox37->setColumnLayout(0, Qt::Vertical );
    groupBox37->layout()->setSpacing( 6 );
    groupBox37->layout()->setMargin( 11 );
    groupBox37Layout = new QGridLayout( groupBox37->layout() );
    groupBox37Layout->setAlignment( Qt::AlignTop );

    buttonGroup15 = new QButtonGroup( groupBox37, "buttonGroup15" );

    radioButton33 = new QRadioButton( buttonGroup15, "radioButton33" );
    radioButton33->setGeometry( QRect( 21, 7, 112, 21 ) );
    radioButton33->setChecked( TRUE );

    radioButton34 = new QRadioButton( buttonGroup15, "radioButton34" );
    radioButton34->setGeometry( QRect( 20, 32, 120, 21 ) );

    groupBox37Layout->addWidget( buttonGroup15, 0, 0 );

    lineEdit63 = new QLineEdit( groupBox37, "lineEdit63" );

    groupBox37Layout->addWidget( lineEdit63, 0, 1 );

    pushButton75_3 = new QPushButton( groupBox37, "pushButton75_3" );

    groupBox37Layout->addWidget( pushButton75_3, 0, 2 );

    pushButton77 = new QPushButton( WStackPage, "pushButton77" );
    pushButton77->setGeometry( QRect( 302, 189, 166, 26 ) );
    sessionSelectionWg->addWidget( WStackPage, 0 );

    WStackPage_2 = new QWidget( sessionSelectionWg, "WStackPage_2" );

    groupBox37_2 = new QGroupBox( WStackPage_2, "groupBox37_2" );
    groupBox37_2->setGeometry( QRect( 17, 40, 630, 280 ) );
    groupBox37_2->setColumnLayout(0, Qt::Vertical );
    groupBox37_2->layout()->setSpacing( 6 );
    groupBox37_2->layout()->setMargin( 11 );
    groupBox37_2Layout = new QGridLayout( groupBox37_2->layout() );
    groupBox37_2Layout->setAlignment( Qt::AlignTop );

    pushButton96 = new QPushButton( groupBox37_2, "pushButton96" );

    groupBox37_2Layout->addWidget( pushButton96, 2, 0 );

    groupBox41 = new QGroupBox( groupBox37_2, "groupBox41" );
    groupBox41->setColumnLayout(0, Qt::Vertical );
    groupBox41->layout()->setSpacing( 6 );
    groupBox41->layout()->setMargin( 11 );
    groupBox41Layout = new QGridLayout( groupBox41->layout() );
    groupBox41Layout->setAlignment( Qt::AlignTop );

    textLabel3_10 = new QLabel( groupBox41, "textLabel3_10" );

    groupBox41Layout->addWidget( textLabel3_10, 0, 0 );

    browseFile = new QPushButton( groupBox41, "browseFile" );

    groupBox41Layout->addWidget( browseFile, 0, 2 );

    chooseSeq = new QLineEdit( groupBox41, "chooseSeq" );

    groupBox41Layout->addWidget( chooseSeq, 0, 1 );

    groupBox37_2Layout->addMultiCellWidget( groupBox41, 0, 0, 0, 1 );

    groupBox38 = new QGroupBox( groupBox37_2, "groupBox38" );

    buttonGroup13 = new QButtonGroup( groupBox38, "buttonGroup13" );
    buttonGroup13->setGeometry( QRect( 11, 22, 207, 97 ) );
    buttonGroup13->setRadioButtonExclusive( TRUE );
    buttonGroup13->setColumnLayout(0, Qt::Vertical );
    buttonGroup13->layout()->setSpacing( 6 );
    buttonGroup13->layout()->setMargin( 11 );
    buttonGroup13Layout = new QVBoxLayout( buttonGroup13->layout() );
    buttonGroup13Layout->setAlignment( Qt::AlignTop );

    radioButton28 = new QRadioButton( buttonGroup13, "radioButton28" );
    radioButton28->setEnabled( FALSE );
    radioButton28->setChecked( FALSE );
    buttonGroup13Layout->addWidget( radioButton28 );

    radioButton27 = new QRadioButton( buttonGroup13, "radioButton27" );
    radioButton27->setChecked( TRUE );
    buttonGroup13Layout->addWidget( radioButton27 );

    radioButton29 = new QRadioButton( buttonGroup13, "radioButton29" );
    buttonGroup13Layout->addWidget( radioButton29 );

    textLabel1_28 = new QLabel( groupBox38, "textLabel1_28" );
    textLabel1_28->setGeometry( QRect( 236, 53, 598, 67 ) );

    pushButton76_3 = new QPushButton( groupBox38, "pushButton76_3" );
    pushButton76_3->setGeometry( QRect( 545, 26, 52, 26 ) );

    lineEdit64 = new QLineEdit( groupBox38, "lineEdit64" );
    lineEdit64->setGeometry( QRect( 229, 27, 310, 23 ) );

    groupBox37_2Layout->addMultiCellWidget( groupBox38, 1, 1, 0, 1 );

    openSession = new QPushButton( groupBox37_2, "openSession" );

    groupBox37_2Layout->addWidget( openSession, 2, 1 );
    sessionSelectionWg->addWidget( WStackPage_2, 1 );

    frame3 = new QFrame( this, "frame3" );
    frame3->setEnabled( TRUE );
    frame3->setGeometry( QRect( 10, 40, 700, 560 ) );
    frame3->setFrameShape( QFrame::StyledPanel );
    frame3->setFrameShadow( QFrame::Raised );

    groupBox6 = new QGroupBox( frame3, "groupBox6" );
    groupBox6->setGeometry( QRect( 200, 10, 490, 540 ) );

    widgetStack2 = new QWidgetStack( groupBox6, "widgetStack2" );
    widgetStack2->setGeometry( QRect( 10, 20, 470, 510 ) );

    WStackPage_3 = new QWidget( widgetStack2, "WStackPage_3" );

    widgetStack = new QWidgetStack( WStackPage_3, "widgetStack" );
    widgetStack->setGeometry( QRect( 10, 10, 450, 490 ) );

    WStackPage_4 = new QWidget( widgetStack, "WStackPage_4" );

    textLabel3 = new QLabel( WStackPage_4, "textLabel3" );
    textLabel3->setGeometry( QRect( 20, 160, 330, 21 ) );
    textLabel3->setAlignment( int( QLabel::AlignCenter ) );

    pushButton3 = new QPushButton( WStackPage_4, "pushButton3" );
    pushButton3->setGeometry( QRect( 130, 450, 140, 30 ) );

    computeOrfNowPushButton = new QPushButton( WStackPage_4, "computeOrfNowPushButton" );
    computeOrfNowPushButton->setGeometry( QRect( 280, 450, 150, 30 ) );
    widgetStack->addWidget( WStackPage_4, 0 );

    WStackPage_5 = new QWidget( widgetStack, "WStackPage_5" );

    groupBox31 = new QGroupBox( WStackPage_5, "groupBox31" );
    groupBox31->setGeometry( QRect( 20, 10, 401, 160 ) );

    buttonGroup4 = new QButtonGroup( groupBox31, "buttonGroup4" );
    buttonGroup4->setGeometry( QRect( 10, 10, 380, 40 ) );

    radioButton7 = new QRadioButton( buttonGroup4, "radioButton7" );
    radioButton7->setGeometry( QRect( 40, 10, 120, 21 ) );
    radioButton7->setChecked( TRUE );

    radioButton8 = new QRadioButton( buttonGroup4, "radioButton8" );
    radioButton8->setGeometry( QRect( 200, 10, 140, 21 ) );
    radioButton8->setChecked( FALSE );

    groupBox5 = new QGroupBox( groupBox31, "groupBox5" );
    groupBox5->setEnabled( FALSE );
    groupBox5->setGeometry( QRect( 10, 50, 380, 100 ) );

    textLabel8 = new QLabel( groupBox5, "textLabel8" );
    textLabel8->setGeometry( QRect( 20, 20, 210, 20 ) );

    textLabel9 = new QLabel( groupBox5, "textLabel9" );
    textLabel9->setGeometry( QRect( 20, 50, 210, 20 ) );

    lineEdit61 = new QLineEdit( groupBox5, "lineEdit61" );
    lineEdit61->setGeometry( QRect( 300, 23, 60, 23 ) );

    lineEdit62 = new QLineEdit( groupBox5, "lineEdit62" );
    lineEdit62->setGeometry( QRect( 300, 50, 60, 23 ) );

    groupBox17_2_2 = new QGroupBox( WStackPage_5, "groupBox17_2_2" );
    groupBox17_2_2->setGeometry( QRect( 20, 180, 400, 261 ) );

    textLabel1_2 = new QLabel( groupBox17_2_2, "textLabel1_2" );
    textLabel1_2->setGeometry( QRect( 40, 20, 130, 20 ) );

    textLabel3_2 = new QLabel( groupBox17_2_2, "textLabel3_2" );
    textLabel3_2->setGeometry( QRect( 40, 80, 290, 20 ) );

    textLabel2_2 = new QLabel( groupBox17_2_2, "textLabel2_2" );
    textLabel2_2->setGeometry( QRect( 40, 130, 130, 20 ) );

    pushButton27 = new QPushButton( groupBox17_2_2, "pushButton27" );
    pushButton27->setGeometry( QRect( 260, 50, 60, 30 ) );

    pushButton28 = new QPushButton( groupBox17_2_2, "pushButton28" );
    pushButton28->setGeometry( QRect( 260, 160, 60, 30 ) );

    textLabel3_2_2 = new QLabel( groupBox17_2_2, "textLabel3_2_2" );
    textLabel3_2_2->setGeometry( QRect( 40, 190, 290, 20 ) );

    lineEdit4 = new QLineEdit( groupBox17_2_2, "lineEdit4" );
    lineEdit4->setGeometry( QRect( 40, 160, 200, 21 ) );

    lineEdit3 = new QLineEdit( groupBox17_2_2, "lineEdit3" );
    lineEdit3->setGeometry( QRect( 40, 50, 200, 21 ) );

    pushButton14 = new QPushButton( WStackPage_5, "pushButton14" );
    pushButton14->setGeometry( QRect( 350, 450, 95, 30 ) );
    widgetStack->addWidget( WStackPage_5, 1 );

    WStackPage_6 = new QWidget( widgetStack, "WStackPage_6" );

    buttonGroup5 = new QButtonGroup( WStackPage_6, "buttonGroup5" );
    buttonGroup5->setGeometry( QRect( 20, 300, 380, 70 ) );

    radioButton10 = new QRadioButton( buttonGroup5, "radioButton10" );
    radioButton10->setGeometry( QRect( 10, 40, 310, 21 ) );

    radioButton9 = new QRadioButton( buttonGroup5, "radioButton9" );
    radioButton9->setGeometry( QRect( 10, 10, 320, 21 ) );
    radioButton9->setChecked( TRUE );

    pushButton16_3 = new QPushButton( WStackPage_6, "pushButton16_3" );
    pushButton16_3->setGeometry( QRect( 10, 450, 95, 30 ) );

    textEdit1 = new QTextEdit( WStackPage_6, "textEdit1" );
    textEdit1->setEnabled( TRUE );
    textEdit1->setGeometry( QRect( 20, 20, 380, 260 ) );
    textEdit1->setReadOnly( TRUE );

    checkBox2 = new QCheckBox( WStackPage_6, "checkBox2" );
    checkBox2->setGeometry( QRect( 20, 390, 380, 21 ) );

    pushButton25 = new QPushButton( WStackPage_6, "pushButton25" );
    pushButton25->setGeometry( QRect( 250, 443, 180, 30 ) );
    widgetStack->addWidget( WStackPage_6, 2 );

    WStackPage_7 = new QWidget( widgetStack, "WStackPage_7" );

    textLabel2_4 = new QLabel( WStackPage_7, "textLabel2_4" );
    textLabel2_4->setGeometry( QRect( 90, 290, 260, 20 ) );

    textLabel1_4 = new QLabel( WStackPage_7, "textLabel1_4" );
    textLabel1_4->setGeometry( QRect( 80, 260, 280, 20 ) );

    pushButton26 = new QPushButton( WStackPage_7, "pushButton26" );
    pushButton26->setGeometry( QRect( 10, 450, 95, 30 ) );
    widgetStack->addWidget( WStackPage_7, 3 );
    widgetStack2->addWidget( WStackPage_3, 0 );

    WStackPage_8 = new QWidget( widgetStack2, "WStackPage_8" );

    widgetStack3 = new QWidgetStack( WStackPage_8, "widgetStack3" );
    widgetStack3->setGeometry( QRect( 10, 20, 450, 490 ) );

    WStackPage_9 = new QWidget( widgetStack3, "WStackPage_9" );

    pushButton16_4 = new QPushButton( WStackPage_9, "pushButton16_4" );
    pushButton16_4->setGeometry( QRect( 80, 410, 280, 31 ) );

    textLabel2_3 = new QLabel( WStackPage_9, "textLabel2_3" );
    textLabel2_3->setGeometry( QRect( 50, 240, 310, 20 ) );

    textLabel1_3 = new QLabel( WStackPage_9, "textLabel1_3" );
    textLabel1_3->setGeometry( QRect( 10, 90, 130, 20 ) );
    widgetStack3->addWidget( WStackPage_9, 0 );

    WStackPage_10 = new QWidget( widgetStack3, "WStackPage_10" );

    textLabel1_5 = new QLabel( WStackPage_10, "textLabel1_5" );
    textLabel1_5->setGeometry( QRect( 30, 110, 210, 40 ) );

    textLabel2_5 = new QLabel( WStackPage_10, "textLabel2_5" );
    textLabel2_5->setGeometry( QRect( 60, 200, 150, 20 ) );

    lineEdit6 = new QLineEdit( WStackPage_10, "lineEdit6" );
    lineEdit6->setGeometry( QRect( 220, 230, 121, 21 ) );

    textLabel3_5 = new QLabel( WStackPage_10, "textLabel3_5" );
    textLabel3_5->setGeometry( QRect( 59, 230, 140, 20 ) );

    textLabel4_3 = new QLabel( WStackPage_10, "textLabel4_3" );
    textLabel4_3->setGeometry( QRect( 40, 310, 300, 20 ) );

    lineEdit7 = new QLineEdit( WStackPage_10, "lineEdit7" );
    lineEdit7->setGeometry( QRect( 340, 310, 40, 21 ) );

    pushButton18 = new QPushButton( WStackPage_10, "pushButton18" );
    pushButton18->setGeometry( QRect( 100, 430, 190, 30 ) );

    lineEdit5 = new QLineEdit( WStackPage_10, "lineEdit5" );
    lineEdit5->setGeometry( QRect( 220, 200, 121, 21 ) );

    lineEdit4_2 = new QLineEdit( WStackPage_10, "lineEdit4_2" );
    lineEdit4_2->setGeometry( QRect( 270, 120, 80, 21 ) );
    widgetStack3->addWidget( WStackPage_10, 1 );
    widgetStack2->addWidget( WStackPage_8, 1 );

    WStackPage_11 = new QWidget( widgetStack2, "WStackPage_11" );

    widgetStack4 = new QWidgetStack( WStackPage_11, "widgetStack4" );
    widgetStack4->setGeometry( QRect( 0, 10, 460, 500 ) );

    WStackPage_12 = new QWidget( widgetStack4, "WStackPage_12" );

    tabWidget2 = new QTabWidget( WStackPage_12, "tabWidget2" );
    tabWidget2->setGeometry( QRect( 10, 10, 440, 490 ) );

    R_Statistic = new QWidget( tabWidget2, "R_Statistic" );

    textLabel2_6 = new QLabel( R_Statistic, "textLabel2_6" );
    textLabel2_6->setGeometry( QRect( 11, -5, 340, 20 ) );

    pushButton74_2 = new QPushButton( R_Statistic, "pushButton74_2" );
    pushButton74_2->setGeometry( QRect( 360, 0, 80, 20 ) );

    widgetStack5 = new QWidgetStack( R_Statistic, "widgetStack5" );
    widgetStack5->setGeometry( QRect( 0, 20, 440, 440 ) );

    WStackPage_13 = new QWidget( widgetStack5, "WStackPage_13" );

    QWidget* privateLayoutWidget = new QWidget( WStackPage_13, "layout1" );
    privateLayoutWidget->setGeometry( QRect( 4, 10, 430, 430 ) );
    layout1 = new QVBoxLayout( privateLayoutWidget, 11, 6, "layout1"); 

    groupBox9 = new QGroupBox( privateLayoutWidget, "groupBox9" );

    textLabel3_3 = new QLabel( groupBox9, "textLabel3_3" );
    textLabel3_3->setGeometry( QRect( 34, 10, 164, 30 ) );
    textLabel3_3->setBackgroundMode( QLabel::PaletteBackground );

    pixmapLabel1_1 = new QLabel( groupBox9, "pixmapLabel1_1" );
    pixmapLabel1_1->setEnabled( FALSE );
    pixmapLabel1_1->setGeometry( QRect( 4, 10, 30, 20 ) );
    pixmapLabel1_1->setPixmap( image1 );
    pixmapLabel1_1->setScaledContents( TRUE );

    textLabel1_18_3 = new QLabel( groupBox9, "textLabel1_18_3" );
    textLabel1_18_3->setGeometry( QRect( 11, 44, 260, 20 ) );
    textLabel1_18_3->setPaletteForegroundColor( QColor( 170, 0, 0 ) );

    pushButton59 = new QPushButton( groupBox9, "pushButton59" );
    pushButton59->setGeometry( QRect( 300, 40, 80, 30 ) );

    pushButton29 = new QPushButton( groupBox9, "pushButton29" );
    pushButton29->setGeometry( QRect( 301, 9, 80, 30 ) );
    layout1->addWidget( groupBox9 );

    groupBox10 = new QGroupBox( privateLayoutWidget, "groupBox10" );

    textLabel4_2 = new QLabel( groupBox10, "textLabel4_2" );
    textLabel4_2->setGeometry( QRect( 35, 10, 192, 30 ) );

    textLabel1_18 = new QLabel( groupBox10, "textLabel1_18" );
    textLabel1_18->setGeometry( QRect( 10, 50, 280, 20 ) );
    textLabel1_18->setPaletteForegroundColor( QColor( 170, 0, 0 ) );

    pushButton29_2 = new QPushButton( groupBox10, "pushButton29_2" );
    pushButton29_2->setGeometry( QRect( 301, 7, 80, 30 ) );

    pushButton59_2 = new QPushButton( groupBox10, "pushButton59_2" );
    pushButton59_2->setGeometry( QRect( 301, 43, 80, 30 ) );

    pixmapLabel1_2 = new QLabel( groupBox10, "pixmapLabel1_2" );
    pixmapLabel1_2->setEnabled( FALSE );
    pixmapLabel1_2->setGeometry( QRect( 4, 9, 30, 20 ) );
    pixmapLabel1_2->setPixmap( image1 );
    pixmapLabel1_2->setScaledContents( TRUE );
    layout1->addWidget( groupBox10 );

    groupBox11 = new QGroupBox( privateLayoutWidget, "groupBox11" );

    textLabel5_2 = new QLabel( groupBox11, "textLabel5_2" );
    textLabel5_2->setGeometry( QRect( 35, 16, 188, 20 ) );

    pixmapLabel1_3 = new QLabel( groupBox11, "pixmapLabel1_3" );
    pixmapLabel1_3->setEnabled( FALSE );
    pixmapLabel1_3->setGeometry( QRect( 3, 5, 30, 20 ) );
    pixmapLabel1_3->setPixmap( image1 );
    pixmapLabel1_3->setScaledContents( TRUE );

    textLabel1_18_2 = new QLabel( groupBox11, "textLabel1_18_2" );
    textLabel1_18_2->setGeometry( QRect( 10, 43, 290, 20 ) );
    textLabel1_18_2->setPaletteForegroundColor( QColor( 170, 0, 0 ) );

    pushButton29_3 = new QPushButton( groupBox11, "pushButton29_3" );
    pushButton29_3->setGeometry( QRect( 300, 0, 80, 30 ) );

    pushButton59_2_2 = new QPushButton( groupBox11, "pushButton59_2_2" );
    pushButton59_2_2->setGeometry( QRect( 301, 37, 80, 30 ) );
    layout1->addWidget( groupBox11 );

    groupBox12 = new QGroupBox( privateLayoutWidget, "groupBox12" );

    textLabel6_2 = new QLabel( groupBox12, "textLabel6_2" );
    textLabel6_2->setGeometry( QRect( 38, 17, 188, 20 ) );

    pixmapLabel1_4 = new QLabel( groupBox12, "pixmapLabel1_4" );
    pixmapLabel1_4->setEnabled( FALSE );
    pixmapLabel1_4->setGeometry( QRect( 5, 10, 30, 20 ) );
    pixmapLabel1_4->setPixmap( image1 );
    pixmapLabel1_4->setScaledContents( TRUE );

    textLabel1_18_2_2 = new QLabel( groupBox12, "textLabel1_18_2_2" );
    textLabel1_18_2_2->setGeometry( QRect( 10, 50, 280, 20 ) );
    textLabel1_18_2_2->setPaletteForegroundColor( QColor( 170, 0, 0 ) );

    pushButton29_4 = new QPushButton( groupBox12, "pushButton29_4" );
    pushButton29_4->setGeometry( QRect( 301, 7, 80, 30 ) );

    pushButton59_2_3 = new QPushButton( groupBox12, "pushButton59_2_3" );
    pushButton59_2_3->setGeometry( QRect( 301, 43, 80, 30 ) );
    layout1->addWidget( groupBox12 );

    groupBox12_2 = new QGroupBox( privateLayoutWidget, "groupBox12_2" );

    pixmapLabel1_5 = new QLabel( groupBox12_2, "pixmapLabel1_5" );
    pixmapLabel1_5->setEnabled( FALSE );
    pixmapLabel1_5->setGeometry( QRect( 5, 10, 30, 20 ) );
    pixmapLabel1_5->setPixmap( image1 );
    pixmapLabel1_5->setScaledContents( TRUE );

    textLabel1_18_2_2_2 = new QLabel( groupBox12_2, "textLabel1_18_2_2_2" );
    textLabel1_18_2_2_2->setGeometry( QRect( 10, 50, 280, 20 ) );
    textLabel1_18_2_2_2->setPaletteForegroundColor( QColor( 170, 0, 0 ) );

    textLabel6_2_2 = new QLabel( groupBox12_2, "textLabel6_2_2" );
    textLabel6_2_2->setGeometry( QRect( 38, 17, 188, 20 ) );

    pushButton29_4_3 = new QPushButton( groupBox12_2, "pushButton29_4_3" );
    pushButton29_4_3->setGeometry( QRect( 301, 7, 80, 30 ) );

    pushButton59_2_3_2 = new QPushButton( groupBox12_2, "pushButton59_2_3_2" );
    pushButton59_2_3_2->setGeometry( QRect( 301, 43, 80, 30 ) );
    layout1->addWidget( groupBox12_2 );
    widgetStack5->addWidget( WStackPage_13, 0 );

    WStackPage_14 = new QWidget( widgetStack5, "WStackPage_14" );

    textLabel1_8 = new QLabel( WStackPage_14, "textLabel1_8" );
    textLabel1_8->setGeometry( QRect( 20, 10, 170, 21 ) );

    textLabel5_3 = new QLabel( WStackPage_14, "textLabel5_3" );
    textLabel5_3->setGeometry( QRect( 40, 203, 180, 20 ) );

    groupBox21 = new QGroupBox( WStackPage_14, "groupBox21" );
    groupBox21->setGeometry( QRect( 20, 30, 400, 160 ) );

    buttonGroup6 = new QButtonGroup( groupBox21, "buttonGroup6" );
    buttonGroup6->setGeometry( QRect( 9, 7, 380, 41 ) );

    radioButton11 = new QRadioButton( buttonGroup6, "radioButton11" );
    radioButton11->setGeometry( QRect( 151, 13, 190, 21 ) );
    radioButton11->setChecked( TRUE );

    radioButton10_2 = new QRadioButton( buttonGroup6, "radioButton10_2" );
    radioButton10_2->setEnabled( TRUE );
    radioButton10_2->setGeometry( QRect( 11, 13, 112, 21 ) );
    radioButton10_2->setChecked( FALSE );

    groupBox25 = new QGroupBox( groupBox21, "groupBox25" );
    groupBox25->setGeometry( QRect( 9, 53, 380, 100 ) );

    textLabel1_21 = new QLabel( groupBox25, "textLabel1_21" );
    textLabel1_21->setGeometry( QRect( 246, 30, 100, 16 ) );
    textLabel1_21->setPaletteForegroundColor( QColor( 170, 0, 0 ) );
    QFont textLabel1_21_font(  textLabel1_21->font() );
    textLabel1_21_font.setPointSize( 7 );
    textLabel1_21->setFont( textLabel1_21_font ); 

    textLabel1_22 = new QLabel( groupBox25, "textLabel1_22" );
    textLabel1_22->setGeometry( QRect( 247, 74, 100, 16 ) );
    textLabel1_22->setPaletteForegroundColor( QColor( 170, 0, 0 ) );
    QFont textLabel1_22_font(  textLabel1_22->font() );
    textLabel1_22_font.setPointSize( 7 );
    textLabel1_22->setFont( textLabel1_22_font ); 

    textLabel4_5 = new QLabel( groupBox25, "textLabel4_5" );
    textLabel4_5->setGeometry( QRect( 16, 62, 192, 20 ) );

    textLabel3_7 = new QLabel( groupBox25, "textLabel3_7" );
    textLabel3_7->setGeometry( QRect( 17, 16, 188, 20 ) );

    lineEdit9 = new QLineEdit( groupBox25, "lineEdit9" );
    lineEdit9->setGeometry( QRect( 246, 62, 100, 21 ) );

    lineEdit8 = new QLineEdit( groupBox25, "lineEdit8" );
    lineEdit8->setGeometry( QRect( 247, 16, 100, 21 ) );
    lineEdit8->setPaletteForegroundColor( QColor( 0, 0, 0 ) );

    frame5 = new QFrame( WStackPage_14, "frame5" );
    frame5->setGeometry( QRect( 50, 230, 330, 60 ) );
    frame5->setFrameShape( QFrame::StyledPanel );
    frame5->setFrameShadow( QFrame::Raised );

    textLabel7_2 = new QLabel( frame5, "textLabel7_2" );
    textLabel7_2->setEnabled( FALSE );
    textLabel7_2->setGeometry( QRect( 21, 31, 240, 20 ) );

    lineEdit11 = new QLineEdit( frame5, "lineEdit11" );
    lineEdit11->setEnabled( FALSE );
    lineEdit11->setGeometry( QRect( 271, 31, 50, 21 ) );

    checkBox3 = new QCheckBox( frame5, "checkBox3" );
    checkBox3->setGeometry( QRect( 20, 10, 210, 16 ) );

    pushButton27_2_5 = new QPushButton( WStackPage_14, "pushButton27_2_5" );
    pushButton27_2_5->setGeometry( QRect( 20, 392, 70, 30 ) );

    lineEdit10 = new QLineEdit( WStackPage_14, "lineEdit10" );
    lineEdit10->setGeometry( QRect( 230, 203, 140, 21 ) );

    frame10 = new QFrame( WStackPage_14, "frame10" );
    frame10->setGeometry( QRect( 20, 297, 400, 90 ) );
    frame10->setFrameShape( QFrame::StyledPanel );
    frame10->setFrameShadow( QFrame::Raised );

    lineEdit45 = new QLineEdit( frame10, "lineEdit45" );
    lineEdit45->setGeometry( QRect( 170, 58, 190, 21 ) );

    textLabel1_16 = new QLabel( frame10, "textLabel1_16" );
    textLabel1_16->setGeometry( QRect( 20, 2, 340, 50 ) );

    pushButton35 = new QPushButton( WStackPage_14, "pushButton35" );
    pushButton35->setGeometry( QRect( 320, 390, 95, 30 ) );
    widgetStack5->addWidget( WStackPage_14, 1 );

    threshold_R_Statistics = new QWidget( widgetStack5, "threshold_R_Statistics" );

    textLabel4_6 = new QLabel( threshold_R_Statistics, "textLabel4_6" );
    textLabel4_6->setGeometry( QRect( 10, 30, 80, 20 ) );

    textLabel1_10 = new QLabel( threshold_R_Statistics, "textLabel1_10" );
    textLabel1_10->setGeometry( QRect( 40, 334, 231, 20 ) );

    textLabel1_9 = new QLabel( threshold_R_Statistics, "textLabel1_9" );
    textLabel1_9->setGeometry( QRect( 40, 54, 160, 20 ) );

    textLabel2_9 = new QLabel( threshold_R_Statistics, "textLabel2_9" );
    textLabel2_9->setGeometry( QRect( 40, 363, 256, 20 ) );

    groupBox27 = new QGroupBox( threshold_R_Statistics, "groupBox27" );
    groupBox27->setGeometry( QRect( 30, 277, 390, 51 ) );

    checkBox4 = new QCheckBox( groupBox27, "checkBox4" );
    checkBox4->setGeometry( QRect( 20, 20, 101, 21 ) );
    checkBox4->setChecked( TRUE );

    pushButton72 = new QPushButton( groupBox27, "pushButton72" );
    pushButton72->setEnabled( FALSE );
    pushButton72->setGeometry( QRect( 131, 11, 251, 30 ) );

    groupBox21_2 = new QGroupBox( threshold_R_Statistics, "groupBox21_2" );
    groupBox21_2->setGeometry( QRect( 29, 143, 390, 130 ) );

    buttonGroup6_2 = new QButtonGroup( groupBox21_2, "buttonGroup6_2" );
    buttonGroup6_2->setGeometry( QRect( 9, 7, 371, 41 ) );

    radioButton11_2 = new QRadioButton( buttonGroup6_2, "radioButton11_2" );
    radioButton11_2->setGeometry( QRect( 151, 13, 190, 21 ) );

    radioButton10_2_2 = new QRadioButton( buttonGroup6_2, "radioButton10_2_2" );
    radioButton10_2_2->setEnabled( TRUE );
    radioButton10_2_2->setGeometry( QRect( 11, 13, 112, 21 ) );
    radioButton10_2_2->setChecked( TRUE );

    groupBox25_2 = new QGroupBox( groupBox21_2, "groupBox25_2" );
    groupBox25_2->setGeometry( QRect( 9, 53, 371, 71 ) );

    textLabel3_7_3 = new QLabel( groupBox25_2, "textLabel3_7_3" );
    textLabel3_7_3->setGeometry( QRect( 17, 6, 188, 20 ) );

    textLabel4_5_3 = new QLabel( groupBox25_2, "textLabel4_5_3" );
    textLabel4_5_3->setGeometry( QRect( 17, 36, 192, 20 ) );

    lineEdit8_3 = new QLineEdit( groupBox25_2, "lineEdit8_3" );
    lineEdit8_3->setGeometry( QRect( 257, 6, 90, 21 ) );

    lineEdit9_3 = new QLineEdit( groupBox25_2, "lineEdit9_3" );
    lineEdit9_3->setGeometry( QRect( 257, 30, 90, 21 ) );

    textLabel2_8 = new QLabel( threshold_R_Statistics, "textLabel2_8" );
    textLabel2_8->setGeometry( QRect( 40, 114, 190, 20 ) );

    textLabel3_8 = new QLabel( threshold_R_Statistics, "textLabel3_8" );
    textLabel3_8->setGeometry( QRect( 40, 84, 204, 20 ) );

    pushButton27_2_6 = new QPushButton( threshold_R_Statistics, "pushButton27_2_6" );
    pushButton27_2_6->setGeometry( QRect( 22, 391, 70, 30 ) );

    textLabel4_2_2 = new QLabel( threshold_R_Statistics, "textLabel4_2_2" );
    textLabel4_2_2->setGeometry( QRect( 10, 10, 310, 19 ) );

    lineEdit_File_PGS = new QLineEdit( threshold_R_Statistics, "lineEdit_File_PGS" );
    lineEdit_File_PGS->setGeometry( QRect( 260, 54, 120, 21 ) );

    lineEdit_File_PNPS = new QLineEdit( threshold_R_Statistics, "lineEdit_File_PNPS" );
    lineEdit_File_PNPS->setGeometry( QRect( 260, 84, 121, 21 ) );

    lineEdit_File_PNGS = new QLineEdit( threshold_R_Statistics, "lineEdit_File_PNGS" );
    lineEdit_File_PNGS->setGeometry( QRect( 260, 114, 120, 21 ) );

    lineEdit15 = new QLineEdit( threshold_R_Statistics, "lineEdit15" );
    lineEdit15->setGeometry( QRect( 310, 330, 70, 21 ) );

    lineEdit16 = new QLineEdit( threshold_R_Statistics, "lineEdit16" );
    lineEdit16->setGeometry( QRect( 310, 360, 70, 21 ) );

    pushButton35_2 = new QPushButton( threshold_R_Statistics, "pushButton35_2" );
    pushButton35_2->setGeometry( QRect( 320, 390, 95, 30 ) );

    pushButton75 = new QPushButton( threshold_R_Statistics, "pushButton75" );
    pushButton75->setGeometry( QRect( 260, 390, 110, 28 ) );
    widgetStack5->addWidget( threshold_R_Statistics, 2 );

    WStackPage_15 = new QWidget( widgetStack5, "WStackPage_15" );

    textLabel5_2_2 = new QLabel( WStackPage_15, "textLabel5_2_2" );
    textLabel5_2_2->setGeometry( QRect( 20, 10, 188, 16 ) );

    textLabel1_11 = new QLabel( WStackPage_15, "textLabel1_11" );
    textLabel1_11->setGeometry( QRect( 20, 40, 410, 260 ) );

    textLabel2_10 = new QLabel( WStackPage_15, "textLabel2_10" );
    textLabel2_10->setGeometry( QRect( 90, 310, 120, 20 ) );

    lineEdit17 = new QLineEdit( WStackPage_15, "lineEdit17" );
    lineEdit17->setGeometry( QRect( 210, 310, 121, 21 ) );

    pushButton35_3 = new QPushButton( WStackPage_15, "pushButton35_3" );
    pushButton35_3->setGeometry( QRect( 340, 390, 80, 30 ) );

    pushButton27_2_7 = new QPushButton( WStackPage_15, "pushButton27_2_7" );
    pushButton27_2_7->setGeometry( QRect( 19, 389, 70, 30 ) );

    checkBox9 = new QCheckBox( WStackPage_15, "checkBox9" );
    checkBox9->setGeometry( QRect( 340, 310, 60, 20 ) );
    widgetStack5->addWidget( WStackPage_15, 3 );

    WStackPage_16 = new QWidget( widgetStack5, "WStackPage_16" );

    pushButton27_2_8 = new QPushButton( WStackPage_16, "pushButton27_2_8" );
    pushButton27_2_8->setGeometry( QRect( 9, 401, 70, 30 ) );

    groupBox3 = new QGroupBox( WStackPage_16, "groupBox3" );
    groupBox3->setGeometry( QRect( 10, 10, 420, 380 ) );

    frame6_2_input = new QFrame( groupBox3, "frame6_2_input" );
    frame6_2_input->setGeometry( QRect( 10, 20, 400, 330 ) );
    frame6_2_input->setFrameShape( QFrame::NoFrame );
    frame6_2_input->setFrameShadow( QFrame::Plain );

    textLabel7_3 = new QLabel( frame6_2_input, "textLabel7_3" );
    textLabel7_3->setGeometry( QRect( 1, 295, 305, 32 ) );

    textLabel5_4 = new QLabel( frame6_2_input, "textLabel5_4" );
    textLabel5_4->setGeometry( QRect( 1, 220, 277, 32 ) );

    textLabel4_7 = new QLabel( frame6_2_input, "textLabel4_7" );
    textLabel4_7->setGeometry( QRect( 1, 182, 277, 32 ) );

    textLabel3_9 = new QLabel( frame6_2_input, "textLabel3_9" );
    textLabel3_9->setGeometry( QRect( 0, 144, 277, 32 ) );

    textLabel6_3 = new QLabel( frame6_2_input, "textLabel6_3" );
    textLabel6_3->setGeometry( QRect( 1, 258, 299, 31 ) );

    lineEdit19_6 = new QLineEdit( frame6_2_input, "lineEdit19_6" );
    lineEdit19_6->setGeometry( QRect( 309, 264, 68, 21 ) );

    lineEdit19_7 = new QLineEdit( frame6_2_input, "lineEdit19_7" );
    lineEdit19_7->setGeometry( QRect( 309, 301, 68, 21 ) );

    lineEdit19_4 = new QLineEdit( frame6_2_input, "lineEdit19_4" );
    lineEdit19_4->setGeometry( QRect( 309, 190, 68, 21 ) );

    lineEdit19_5 = new QLineEdit( frame6_2_input, "lineEdit19_5" );
    lineEdit19_5->setGeometry( QRect( 309, 227, 68, 21 ) );

    lineEdit19_3 = new QLineEdit( frame6_2_input, "lineEdit19_3" );
    lineEdit19_3->setGeometry( QRect( 308, 154, 68, 21 ) );

    buttonGroup8 = new QButtonGroup( frame6_2_input, "buttonGroup8" );
    buttonGroup8->setGeometry( QRect( -1, 10, 400, 120 ) );

    textLabel1_12 = new QLabel( buttonGroup8, "textLabel1_12" );
    textLabel1_12->setGeometry( QRect( 11, 31, 207, 21 ) );

    textLabel2_11 = new QLabel( buttonGroup8, "textLabel2_11" );
    textLabel2_11->setGeometry( QRect( 11, 58, 207, 21 ) );

    lineEdit19 = new QLineEdit( buttonGroup8, "lineEdit19" );
    lineEdit19->setGeometry( QRect( 221, 31, 108, 21 ) );

    lineEdit19_2 = new QLineEdit( buttonGroup8, "lineEdit19_2" );
    lineEdit19_2->setGeometry( QRect( 220, 50, 108, 21 ) );

    textLabel2_16 = new QLabel( buttonGroup8, "textLabel2_16" );
    textLabel2_16->setGeometry( QRect( 60, 90, 211, 20 ) );

    radioButton16 = new QRadioButton( buttonGroup8, "radioButton16" );
    radioButton16->setGeometry( QRect( 330, 90, 60, 21 ) );
    radioButton16->setChecked( TRUE );

    radioButton17 = new QRadioButton( buttonGroup8, "radioButton17" );
    radioButton17->setGeometry( QRect( 270, 90, 60, 21 ) );
    radioButton17->setChecked( FALSE );

    textLabel1_13 = new QLabel( groupBox3, "textLabel1_13" );
    textLabel1_13->setGeometry( QRect( 30, 345, 351, 21 ) );
    textLabel1_13->setPaletteForegroundColor( QColor( 170, 0, 0 ) );

    pushButton35_4 = new QPushButton( WStackPage_16, "pushButton35_4" );
    pushButton35_4->setGeometry( QRect( 330, 400, 95, 30 ) );

    checkBox8 = new QCheckBox( WStackPage_16, "checkBox8" );
    checkBox8->setGeometry( QRect( 101, 404, 190, 21 ) );
    widgetStack5->addWidget( WStackPage_16, 4 );

    thresh = new QWidget( widgetStack5, "thresh" );

    textLabel2_12 = new QLabel( thresh, "textLabel2_12" );
    textLabel2_12->setGeometry( QRect( 20, 30, 220, 20 ) );

    textLabel1_20 = new QLabel( thresh, "textLabel1_20" );
    textLabel1_20->setGeometry( QRect( 10, 160, 260, 20 ) );

    pushButton27_2_5_2 = new QPushButton( thresh, "pushButton27_2_5_2" );
    pushButton27_2_5_2->setGeometry( QRect( 10, 390, 70, 30 ) );

    lineEdit51 = new QLineEdit( thresh, "lineEdit51" );
    lineEdit51->setGeometry( QRect( 280, 160, 90, 20 ) );

    pushButton69 = new QPushButton( thresh, "pushButton69" );
    pushButton69->setGeometry( QRect( 340, 390, 91, 31 ) );

    pushButton75_2 = new QPushButton( thresh, "pushButton75_2" );
    pushButton75_2->setGeometry( QRect( 230, 390, 100, 28 ) );
    widgetStack5->addWidget( thresh, 5 );

    WStackPage_17 = new QWidget( widgetStack5, "WStackPage_17" );

    buttonGroup11 = new QButtonGroup( WStackPage_17, "buttonGroup11" );
    buttonGroup11->setGeometry( QRect( 10, 130, 420, 90 ) );

    radioButton21_2 = new QRadioButton( buttonGroup11, "radioButton21_2" );
    radioButton21_2->setGeometry( QRect( 20, 10, 380, 21 ) );
    radioButton21_2->setChecked( TRUE );

    radioButton22_2 = new QRadioButton( buttonGroup11, "radioButton22_2" );
    radioButton22_2->setGeometry( QRect( 20, 40, 380, 40 ) );

    textLabel1_14 = new QLabel( WStackPage_17, "textLabel1_14" );
    textLabel1_14->setGeometry( QRect( 19, 27, 250, 20 ) );
    widgetStack5->addWidget( WStackPage_17, 6 );

    WStackPage_18 = new QWidget( widgetStack5, "WStackPage_18" );

    textLabel2_18 = new QLabel( WStackPage_18, "textLabel2_18" );
    textLabel2_18->setGeometry( QRect( 20, 20, 320, 21 ) );

    groupBox32 = new QGroupBox( WStackPage_18, "groupBox32" );
    groupBox32->setGeometry( QRect( 10, 80, 420, 250 ) );

    lineEdit2 = new QLineEdit( groupBox32, "lineEdit2" );
    lineEdit2->setGeometry( QRect( 180, 11, 121, 21 ) );

    textLabel3_5_2 = new QLabel( groupBox32, "textLabel3_5_2" );
    textLabel3_5_2->setGeometry( QRect( 19, 41, 140, 20 ) );

    textLabel2_5_2 = new QLabel( groupBox32, "textLabel2_5_2" );
    textLabel2_5_2->setGeometry( QRect( 20, 11, 150, 20 ) );

    textLabel1_5_2 = new QLabel( groupBox32, "textLabel1_5_2" );
    textLabel1_5_2->setGeometry( QRect( 10, 83, 210, 40 ) );

    textLabel2_17 = new QLabel( groupBox32, "textLabel2_17" );
    textLabel2_17->setGeometry( QRect( 20, 170, 345, 20 ) );

    lineEdit3_2 = new QLineEdit( groupBox32, "lineEdit3_2" );
    lineEdit3_2->setGeometry( QRect( 180, 41, 121, 21 ) );

    textLabel1_26 = new QLabel( groupBox32, "textLabel1_26" );
    textLabel1_26->setGeometry( QRect( 20, 140, 280, 30 ) );

    lineEdit4_3 = new QLineEdit( groupBox32, "lineEdit4_3" );
    lineEdit4_3->setGeometry( QRect( 360, 200, 40, 21 ) );

    lineEdit1 = new QLineEdit( groupBox32, "lineEdit1" );
    lineEdit1->setGeometry( QRect( 240, 83, 80, 21 ) );

    textLabel4_3_2 = new QLabel( groupBox32, "textLabel4_3_2" );
    textLabel4_3_2->setGeometry( QRect( 20, 200, 340, 20 ) );

    swapPercent = new QLineEdit( groupBox32, "swapPercent" );
    swapPercent->setGeometry( QRect( 371, 140, 30, 21 ) );

    mutPercent = new QLineEdit( groupBox32, "mutPercent" );
    mutPercent->setGeometry( QRect( 371, 170, 30, 21 ) );
    widgetStack5->addWidget( WStackPage_18, 7 );

    WStackPage_19 = new QWidget( widgetStack5, "WStackPage_19" );

    textLabel4_2_2_3 = new QLabel( WStackPage_19, "textLabel4_2_2_3" );
    textLabel4_2_2_3->setGeometry( QRect( 30, 30, 320, 30 ) );

    pushButton76 = new QPushButton( WStackPage_19, "pushButton76" );
    pushButton76->setGeometry( QRect( 340, 400, 95, 30 ) );

    pushButton27_2_5_2_2 = new QPushButton( WStackPage_19, "pushButton27_2_5_2_2" );
    pushButton27_2_5_2_2->setGeometry( QRect( 20, 400, 70, 30 ) );

    textLabel1_14_3 = new QLabel( WStackPage_19, "textLabel1_14_3" );
    textLabel1_14_3->setGeometry( QRect( 29, 74, 370, 191 ) );
    textLabel1_14_3->setTextFormat( QLabel::RichText );
    textLabel1_14_3->setScaledContents( TRUE );
    textLabel1_14_3->setAlignment( int( QLabel::WordBreak | QLabel::AlignTop ) );
    widgetStack5->addWidget( WStackPage_19, 8 );

    WStackPage_20 = new QWidget( widgetStack5, "WStackPage_20" );

    textLabel1_19 = new QLabel( WStackPage_20, "textLabel1_19" );
    textLabel1_19->setGeometry( QRect( 30, 10, 220, 20 ) );
    widgetStack5->addWidget( WStackPage_20, 9 );
    tabWidget2->insertTab( R_Statistic, QString("") );

    P_Value = new QWidget( tabWidget2, "P_Value" );

    pushButton74_2_2 = new QPushButton( P_Value, "pushButton74_2_2" );
    pushButton74_2_2->setGeometry( QRect( 360, 0, 80, 20 ) );

    textLabel1_6 = new QLabel( P_Value, "textLabel1_6" );
    textLabel1_6->setGeometry( QRect( 9, -3, 310, 20 ) );

    widgetStack6 = new QWidgetStack( P_Value, "widgetStack6" );
    widgetStack6->setGeometry( QRect( 2, 20, 440, 440 ) );

    WStackPage_21 = new QWidget( widgetStack6, "WStackPage_21" );

    QWidget* privateLayoutWidget_2 = new QWidget( WStackPage_21, "layout2" );
    privateLayoutWidget_2->setGeometry( QRect( 6, 6, 430, 430 ) );
    layout2 = new QVBoxLayout( privateLayoutWidget_2, 11, 6, "layout2"); 

    groupBox14 = new QGroupBox( privateLayoutWidget_2, "groupBox14" );

    textLabel1_7 = new QLabel( groupBox14, "textLabel1_7" );
    textLabel1_7->setGeometry( QRect( 36, 20, 188, 20 ) );

    textLabel2_13 = new QLabel( groupBox14, "textLabel2_13" );
    textLabel2_13->setGeometry( QRect( 30, 50, 280, 20 ) );
    textLabel2_13->setPaletteForegroundColor( QColor( 170, 0, 0 ) );

    pixmapLabel2_1 = new QLabel( groupBox14, "pixmapLabel2_1" );
    pixmapLabel2_1->setEnabled( FALSE );
    pixmapLabel2_1->setGeometry( QRect( 3, 10, 30, 20 ) );
    pixmapLabel2_1->setPixmap( image1 );
    pixmapLabel2_1->setScaledContents( TRUE );

    pushButton59_3 = new QPushButton( groupBox14, "pushButton59_3" );
    pushButton59_3->setGeometry( QRect( 301, 43, 80, 30 ) );

    pushButton29_5 = new QPushButton( groupBox14, "pushButton29_5" );
    pushButton29_5->setGeometry( QRect( 301, 7, 80, 30 ) );
    layout2->addWidget( groupBox14 );

    groupBox15 = new QGroupBox( privateLayoutWidget_2, "groupBox15" );

    textLabel2_7 = new QLabel( groupBox15, "textLabel2_7" );
    textLabel2_7->setGeometry( QRect( 36, 13, 188, 20 ) );

    textLabel2_13_2 = new QLabel( groupBox15, "textLabel2_13_2" );
    textLabel2_13_2->setGeometry( QRect( 30, 50, 280, 20 ) );
    textLabel2_13_2->setPaletteForegroundColor( QColor( 170, 0, 0 ) );

    pixmapLabel2_2 = new QLabel( groupBox15, "pixmapLabel2_2" );
    pixmapLabel2_2->setEnabled( FALSE );
    pixmapLabel2_2->setGeometry( QRect( 3, 12, 30, 20 ) );
    pixmapLabel2_2->setPixmap( image1 );
    pixmapLabel2_2->setScaledContents( TRUE );

    pushButton59_4 = new QPushButton( groupBox15, "pushButton59_4" );
    pushButton59_4->setGeometry( QRect( 301, 43, 80, 30 ) );

    pushButton29_2_2 = new QPushButton( groupBox15, "pushButton29_2_2" );
    pushButton29_2_2->setGeometry( QRect( 301, 7, 80, 30 ) );
    layout2->addWidget( groupBox15 );

    groupBox16 = new QGroupBox( privateLayoutWidget_2, "groupBox16" );

    textLabel3_6 = new QLabel( groupBox16, "textLabel3_6" );
    textLabel3_6->setGeometry( QRect( 42, 19, 188, 20 ) );

    textLabel2_13_2_2 = new QLabel( groupBox16, "textLabel2_13_2_2" );
    textLabel2_13_2_2->setGeometry( QRect( 27, 53, 280, 20 ) );
    textLabel2_13_2_2->setPaletteForegroundColor( QColor( 170, 0, 0 ) );

    pixmapLabel2_3 = new QLabel( groupBox16, "pixmapLabel2_3" );
    pixmapLabel2_3->setEnabled( FALSE );
    pixmapLabel2_3->setGeometry( QRect( 6, 19, 30, 20 ) );
    pixmapLabel2_3->setPixmap( image1 );
    pixmapLabel2_3->setScaledContents( TRUE );

    pushButton59_5 = new QPushButton( groupBox16, "pushButton59_5" );
    pushButton59_5->setGeometry( QRect( 301, 43, 80, 30 ) );

    pushButton29_3_2 = new QPushButton( groupBox16, "pushButton29_3_2" );
    pushButton29_3_2->setGeometry( QRect( 301, 7, 80, 30 ) );
    layout2->addWidget( groupBox16 );

    groupBox17 = new QGroupBox( privateLayoutWidget_2, "groupBox17" );

    textLabel4_4 = new QLabel( groupBox17, "textLabel4_4" );
    textLabel4_4->setGeometry( QRect( 39, 14, 188, 20 ) );

    textLabel2_13_2_2_2 = new QLabel( groupBox17, "textLabel2_13_2_2_2" );
    textLabel2_13_2_2_2->setGeometry( QRect( 30, 50, 280, 20 ) );
    textLabel2_13_2_2_2->setPaletteForegroundColor( QColor( 170, 0, 0 ) );

    pixmapLabel2_4 = new QLabel( groupBox17, "pixmapLabel2_4" );
    pixmapLabel2_4->setEnabled( FALSE );
    pixmapLabel2_4->setGeometry( QRect( 6, 15, 30, 20 ) );
    pixmapLabel2_4->setPixmap( image1 );
    pixmapLabel2_4->setScaledContents( TRUE );

    pushButton59_6 = new QPushButton( groupBox17, "pushButton59_6" );
    pushButton59_6->setGeometry( QRect( 301, 44, 80, 30 ) );

    pushButton29_4_2 = new QPushButton( groupBox17, "pushButton29_4_2" );
    pushButton29_4_2->setGeometry( QRect( 301, 8, 80, 30 ) );
    layout2->addWidget( groupBox17 );

    groupBox17_2 = new QGroupBox( privateLayoutWidget_2, "groupBox17_2" );

    textLabel2_13_2_2_2_2 = new QLabel( groupBox17_2, "textLabel2_13_2_2_2_2" );
    textLabel2_13_2_2_2_2->setGeometry( QRect( 30, 50, 280, 20 ) );
    textLabel2_13_2_2_2_2->setPaletteForegroundColor( QColor( 170, 0, 0 ) );

    textLabel4_4_3 = new QLabel( groupBox17_2, "textLabel4_4_3" );
    textLabel4_4_3->setGeometry( QRect( 39, 14, 188, 20 ) );

    pixmapLabel2_5 = new QLabel( groupBox17_2, "pixmapLabel2_5" );
    pixmapLabel2_5->setEnabled( FALSE );
    pixmapLabel2_5->setGeometry( QRect( 6, 15, 30, 20 ) );
    pixmapLabel2_5->setPixmap( image1 );
    pixmapLabel2_5->setScaledContents( TRUE );

    pushButton59_7 = new QPushButton( groupBox17_2, "pushButton59_7" );
    pushButton59_7->setGeometry( QRect( 301, 44, 80, 30 ) );

    pushButton29_5_2 = new QPushButton( groupBox17_2, "pushButton29_5_2" );
    pushButton29_5_2->setGeometry( QRect( 301, 8, 80, 30 ) );
    layout2->addWidget( groupBox17_2 );
    widgetStack6->addWidget( WStackPage_21, 0 );

    WStackPage_22 = new QWidget( widgetStack6, "WStackPage_22" );

    frame10_2 = new QFrame( WStackPage_22, "frame10_2" );
    frame10_2->setGeometry( QRect( 10, 243, 410, 50 ) );
    frame10_2->setFrameShape( QFrame::StyledPanel );
    frame10_2->setFrameShadow( QFrame::Raised );

    textLabel1_16_2 = new QLabel( frame10_2, "textLabel1_16_2" );
    textLabel1_16_2->setGeometry( QRect( 10, 7, 222, 33 ) );

    lineEdit45_2 = new QLineEdit( frame10_2, "lineEdit45_2" );
    lineEdit45_2->setGeometry( QRect( 260, 14, 130, 21 ) );

    frame5_2 = new QFrame( WStackPage_22, "frame5_2" );
    frame5_2->setGeometry( QRect( 10, 174, 410, 60 ) );
    frame5_2->setFrameShape( QFrame::StyledPanel );
    frame5_2->setFrameShadow( QFrame::Raised );

    textLabel7_2_2 = new QLabel( frame5_2, "textLabel7_2_2" );
    textLabel7_2_2->setEnabled( FALSE );
    textLabel7_2_2->setGeometry( QRect( 41, 31, 240, 20 ) );

    checkBox3_2 = new QCheckBox( frame5_2, "checkBox3_2" );
    checkBox3_2->setGeometry( QRect( 20, 10, 210, 16 ) );

    lineEdit11_2 = new QLineEdit( frame5_2, "lineEdit11_2" );
    lineEdit11_2->setEnabled( FALSE );
    lineEdit11_2->setGeometry( QRect( 291, 31, 50, 21 ) );

    textLabel5_3_2 = new QLabel( WStackPage_22, "textLabel5_3_2" );
    textLabel5_3_2->setGeometry( QRect( 15, 146, 180, 20 ) );

    textLabel1_7_2 = new QLabel( WStackPage_22, "textLabel1_7_2" );
    textLabel1_7_2->setGeometry( QRect( 10, 1, 188, 21 ) );

    textLabel6_4 = new QLabel( WStackPage_22, "textLabel6_4" );
    textLabel6_4->setGeometry( QRect( 20, 305, 210, 20 ) );

    groupBox4 = new QGroupBox( WStackPage_22, "groupBox4" );
    groupBox4->setGeometry( QRect( 10, 22, 410, 120 ) );

    buttonGroup5_2 = new QButtonGroup( groupBox4, "buttonGroup5_2" );
    buttonGroup5_2->setGeometry( QRect( 30, 10, 350, 30 ) );

    radioButton9_2 = new QRadioButton( buttonGroup5_2, "radioButton9_2" );
    radioButton9_2->setGeometry( QRect( 10, 3, 105, 20 ) );
    radioButton9_2->setChecked( FALSE );
    buttonGroup5_2->insert( radioButton9_2, 0 );

    radioButton8_2 = new QRadioButton( buttonGroup5_2, "radioButton8_2" );
    radioButton8_2->setGeometry( QRect( 140, 6, 190, 16 ) );
    radioButton8_2->setMouseTracking( FALSE );
    radioButton8_2->setChecked( FALSE );
    buttonGroup5_2->insert( radioButton8_2, 1 );

    groupBox6_2 = new QGroupBox( groupBox4, "groupBox6_2" );
    groupBox6_2->setEnabled( TRUE );
    groupBox6_2->setGeometry( QRect( 31, 48, 350, 61 ) );

    textLabel3_7_2 = new QLabel( groupBox6_2, "textLabel3_7_2" );
    textLabel3_7_2->setEnabled( TRUE );
    textLabel3_7_2->setGeometry( QRect( 31, 6, 188, 20 ) );

    textLabel4_5_2 = new QLabel( groupBox6_2, "textLabel4_5_2" );
    textLabel4_5_2->setEnabled( TRUE );
    textLabel4_5_2->setGeometry( QRect( 31, 36, 192, 20 ) );

    lineEdit9_2 = new QLineEdit( groupBox6_2, "lineEdit9_2" );
    lineEdit9_2->setEnabled( TRUE );
    lineEdit9_2->setGeometry( QRect( 231, 36, 90, 21 ) );

    lineEdit8_2 = new QLineEdit( groupBox6_2, "lineEdit8_2" );
    lineEdit8_2->setEnabled( TRUE );
    lineEdit8_2->setGeometry( QRect( 231, 6, 90, 21 ) );

    textLabel7_4 = new QLabel( WStackPage_22, "textLabel7_4" );
    textLabel7_4->setGeometry( QRect( 20, 335, 272, 20 ) );

    textLabel8_2 = new QLabel( WStackPage_22, "textLabel8_2" );
    textLabel8_2->setGeometry( QRect( 20, 365, 345, 20 ) );

    pushButton27_2 = new QPushButton( WStackPage_22, "pushButton27_2" );
    pushButton27_2->setGeometry( QRect( 10, 401, 70, 30 ) );

    lineEdit10_2 = new QLineEdit( WStackPage_22, "lineEdit10_2" );
    lineEdit10_2->setGeometry( QRect( 205, 146, 140, 21 ) );

    lineEdit29 = new QLineEdit( WStackPage_22, "lineEdit29" );
    lineEdit29->setGeometry( QRect( 390, 305, 30, 21 ) );

    lineEdit30 = new QLineEdit( WStackPage_22, "lineEdit30" );
    lineEdit30->setGeometry( QRect( 390, 335, 30, 21 ) );

    lineEdit31 = new QLineEdit( WStackPage_22, "lineEdit31" );
    lineEdit31->setGeometry( QRect( 390, 365, 30, 21 ) );

    pushButton35_5 = new QPushButton( WStackPage_22, "pushButton35_5" );
    pushButton35_5->setGeometry( QRect( 320, 400, 95, 30 ) );
    widgetStack6->addWidget( WStackPage_22, 1 );

    WStackPage_23 = new QWidget( widgetStack6, "WStackPage_23" );

    textLabel2_7_2 = new QLabel( WStackPage_23, "textLabel2_7_2" );
    textLabel2_7_2->setGeometry( QRect( 20, 10, 188, 20 ) );

    textLabel1_9_2 = new QLabel( WStackPage_23, "textLabel1_9_2" );
    textLabel1_9_2->setGeometry( QRect( 50, 80, 160, 20 ) );

    textLabel4_6_2 = new QLabel( WStackPage_23, "textLabel4_6_2" );
    textLabel4_6_2->setGeometry( QRect( 50, 50, 80, 20 ) );

    groupBox21_2_2 = new QGroupBox( WStackPage_23, "groupBox21_2_2" );
    groupBox21_2_2->setGeometry( QRect( 29, 177, 390, 130 ) );

    buttonGroup6_2_2 = new QButtonGroup( groupBox21_2_2, "buttonGroup6_2_2" );
    buttonGroup6_2_2->setGeometry( QRect( 9, 7, 371, 41 ) );

    radioButton11_2_2 = new QRadioButton( buttonGroup6_2_2, "radioButton11_2_2" );
    radioButton11_2_2->setGeometry( QRect( 151, 13, 190, 21 ) );

    radioButton10_2_2_2 = new QRadioButton( buttonGroup6_2_2, "radioButton10_2_2_2" );
    radioButton10_2_2_2->setEnabled( TRUE );
    radioButton10_2_2_2->setGeometry( QRect( 11, 13, 112, 21 ) );
    radioButton10_2_2_2->setChecked( TRUE );

    groupBox25_2_2 = new QGroupBox( groupBox21_2_2, "groupBox25_2_2" );
    groupBox25_2_2->setGeometry( QRect( 9, 53, 371, 71 ) );

    textLabel3_7_3_2 = new QLabel( groupBox25_2_2, "textLabel3_7_3_2" );
    textLabel3_7_3_2->setGeometry( QRect( 17, 6, 188, 20 ) );

    textLabel4_5_3_2 = new QLabel( groupBox25_2_2, "textLabel4_5_3_2" );
    textLabel4_5_3_2->setGeometry( QRect( 17, 36, 192, 20 ) );

    lineEdit8_3_2 = new QLineEdit( groupBox25_2_2, "lineEdit8_3_2" );
    lineEdit8_3_2->setGeometry( QRect( 257, 6, 90, 21 ) );

    lineEdit9_3_2 = new QLineEdit( groupBox25_2_2, "lineEdit9_3_2" );
    lineEdit9_3_2->setGeometry( QRect( 257, 36, 90, 21 ) );

    textLabel2_9_2 = new QLabel( WStackPage_23, "textLabel2_9_2" );
    textLabel2_9_2->setGeometry( QRect( 40, 358, 283, 20 ) );

    textLabel1_10_2 = new QLabel( WStackPage_23, "textLabel1_10_2" );
    textLabel1_10_2->setGeometry( QRect( 40, 330, 262, 20 ) );

    textLabel2_8_2 = new QLabel( WStackPage_23, "textLabel2_8_2" );
    textLabel2_8_2->setGeometry( QRect( 50, 140, 190, 20 ) );

    textLabel3_8_2 = new QLabel( WStackPage_23, "textLabel3_8_2" );
    textLabel3_8_2->setGeometry( QRect( 50, 110, 204, 20 ) );

    pushButton27_2_2 = new QPushButton( WStackPage_23, "pushButton27_2_2" );
    pushButton27_2_2->setGeometry( QRect( 10, 401, 70, 30 ) );

    lineEdit_File_PGS_2 = new QLineEdit( WStackPage_23, "lineEdit_File_PGS_2" );
    lineEdit_File_PGS_2->setGeometry( QRect( 270, 80, 120, 21 ) );

    lineEdit_File_PNPS_2 = new QLineEdit( WStackPage_23, "lineEdit_File_PNPS_2" );
    lineEdit_File_PNPS_2->setGeometry( QRect( 270, 110, 121, 21 ) );

    lineEdit_File_PNGS_2 = new QLineEdit( WStackPage_23, "lineEdit_File_PNGS_2" );
    lineEdit_File_PNGS_2->setGeometry( QRect( 270, 140, 120, 21 ) );

    lineEdit16_2 = new QLineEdit( WStackPage_23, "lineEdit16_2" );
    lineEdit16_2->setGeometry( QRect( 330, 358, 70, 21 ) );

    lineEdit15_2 = new QLineEdit( WStackPage_23, "lineEdit15_2" );
    lineEdit15_2->setGeometry( QRect( 330, 330, 70, 21 ) );

    pushButton35_6 = new QPushButton( WStackPage_23, "pushButton35_6" );
    pushButton35_6->setGeometry( QRect( 328, 401, 95, 30 ) );

    pushButton75_4 = new QPushButton( WStackPage_23, "pushButton75_4" );
    pushButton75_4->setGeometry( QRect( 200, 400, 110, 28 ) );
    widgetStack6->addWidget( WStackPage_23, 2 );

    WStackPage_24 = new QWidget( widgetStack6, "WStackPage_24" );

    textLabel3_6_2 = new QLabel( WStackPage_24, "textLabel3_6_2" );
    textLabel3_6_2->setGeometry( QRect( 20, 10, 188, 21 ) );

    textLabel2_10_2 = new QLabel( WStackPage_24, "textLabel2_10_2" );
    textLabel2_10_2->setGeometry( QRect( 30, 310, 120, 20 ) );

    pushButton27_2_3 = new QPushButton( WStackPage_24, "pushButton27_2_3" );
    pushButton27_2_3->setGeometry( QRect( 10, 401, 70, 30 ) );

    textLabel1_11_2 = new QLabel( WStackPage_24, "textLabel1_11_2" );
    textLabel1_11_2->setGeometry( QRect( 20, 40, 410, 240 ) );

    checkBox9_2 = new QCheckBox( WStackPage_24, "checkBox9_2" );
    checkBox9_2->setGeometry( QRect( 300, 310, 60, 20 ) );

    lineEdit17_2 = new QLineEdit( WStackPage_24, "lineEdit17_2" );
    lineEdit17_2->setGeometry( QRect( 160, 310, 121, 21 ) );

    pushButton35_7 = new QPushButton( WStackPage_24, "pushButton35_7" );
    pushButton35_7->setGeometry( QRect( 330, 400, 95, 30 ) );
    widgetStack6->addWidget( WStackPage_24, 3 );

    WStackPage_25 = new QWidget( widgetStack6, "WStackPage_25" );

    textLabel4_4_2 = new QLabel( WStackPage_25, "textLabel4_4_2" );
    textLabel4_4_2->setGeometry( QRect( 20, 10, 188, 30 ) );

    pushButton27_2_4 = new QPushButton( WStackPage_25, "pushButton27_2_4" );
    pushButton27_2_4->setGeometry( QRect( 9, 401, 70, 30 ) );

    pushButton35_8 = new QPushButton( WStackPage_25, "pushButton35_8" );
    pushButton35_8->setGeometry( QRect( 328, 401, 95, 30 ) );

    groupBox3_2 = new QGroupBox( WStackPage_25, "groupBox3_2" );
    groupBox3_2->setGeometry( QRect( 10, 40, 420, 360 ) );

    frame6_2_input_2 = new QFrame( groupBox3_2, "frame6_2_input_2" );
    frame6_2_input_2->setGeometry( QRect( 10, 20, 400, 300 ) );
    frame6_2_input_2->setFrameShape( QFrame::NoFrame );
    frame6_2_input_2->setFrameShadow( QFrame::Plain );

    textLabel1_13_2 = new QLabel( frame6_2_input_2, "textLabel1_13_2" );
    textLabel1_13_2->setGeometry( QRect( 9, 314, 351, 21 ) );
    textLabel1_13_2->setPaletteForegroundColor( QColor( 170, 0, 0 ) );

    textLabel3_9_2 = new QLabel( frame6_2_input_2, "textLabel3_9_2" );
    textLabel3_9_2->setGeometry( QRect( 24, 132, 277, 26 ) );

    textLabel4_7_2 = new QLabel( frame6_2_input_2, "textLabel4_7_2" );
    textLabel4_7_2->setGeometry( QRect( 25, 167, 277, 26 ) );

    textLabel5_4_2 = new QLabel( frame6_2_input_2, "textLabel5_4_2" );
    textLabel5_4_2->setGeometry( QRect( 25, 199, 277, 26 ) );

    textLabel6_3_2 = new QLabel( frame6_2_input_2, "textLabel6_3_2" );
    textLabel6_3_2->setGeometry( QRect( 25, 231, 291, 26 ) );

    textLabel7_3_2 = new QLabel( frame6_2_input_2, "textLabel7_3_2" );
    textLabel7_3_2->setGeometry( QRect( 25, 263, 293, 26 ) );

    buttonGroup8_2 = new QButtonGroup( frame6_2_input_2, "buttonGroup8_2" );
    buttonGroup8_2->setGeometry( QRect( 10, 0, 361, 120 ) );

    textLabel1_12_2 = new QLabel( buttonGroup8_2, "textLabel1_12_2" );
    textLabel1_12_2->setGeometry( QRect( 10, 20, 240, 26 ) );

    textLabel2_11_2 = new QLabel( buttonGroup8_2, "textLabel2_11_2" );
    textLabel2_11_2->setGeometry( QRect( 10, 50, 250, 26 ) );

    textLabel2_16_2 = new QLabel( buttonGroup8_2, "textLabel2_16_2" );
    textLabel2_16_2->setGeometry( QRect( 10, 90, 211, 20 ) );

    radioButton17_2 = new QRadioButton( buttonGroup8_2, "radioButton17_2" );
    radioButton17_2->setGeometry( QRect( 220, 90, 50, 21 ) );
    radioButton17_2->setChecked( FALSE );

    radioButton16_2 = new QRadioButton( buttonGroup8_2, "radioButton16_2" );
    radioButton16_2->setEnabled( TRUE );
    radioButton16_2->setGeometry( QRect( 280, 90, 70, 21 ) );
    radioButton16_2->setChecked( TRUE );

    lineEdit19_8 = new QLineEdit( buttonGroup8_2, "lineEdit19_8" );
    lineEdit19_8->setGeometry( QRect( 260, 20, 48, 21 ) );

    lineEdit19_2_2 = new QLineEdit( buttonGroup8_2, "lineEdit19_2_2" );
    lineEdit19_2_2->setGeometry( QRect( 260, 52, 48, 21 ) );

    lineEdit19_5_2 = new QLineEdit( frame6_2_input_2, "lineEdit19_5_2" );
    lineEdit19_5_2->setGeometry( QRect( 325, 199, 48, 21 ) );

    lineEdit19_6_2 = new QLineEdit( frame6_2_input_2, "lineEdit19_6_2" );
    lineEdit19_6_2->setGeometry( QRect( 325, 230, 48, 21 ) );

    lineEdit19_7_2 = new QLineEdit( frame6_2_input_2, "lineEdit19_7_2" );
    lineEdit19_7_2->setGeometry( QRect( 325, 261, 48, 21 ) );

    lineEdit19_3_2 = new QLineEdit( frame6_2_input_2, "lineEdit19_3_2" );
    lineEdit19_3_2->setGeometry( QRect( 324, 136, 48, 21 ) );

    lineEdit19_4_2 = new QLineEdit( frame6_2_input_2, "lineEdit19_4_2" );
    lineEdit19_4_2->setGeometry( QRect( 325, 168, 48, 21 ) );

    checkBox8_2 = new QCheckBox( WStackPage_25, "checkBox8_2" );
    checkBox8_2->setGeometry( QRect( 110, 410, 190, 21 ) );
    widgetStack6->addWidget( WStackPage_25, 4 );

    WStackPage_26 = new QWidget( widgetStack6, "WStackPage_26" );

    textLabel4_2_2_3_2 = new QLabel( WStackPage_26, "textLabel4_2_2_3_2" );
    textLabel4_2_2_3_2->setGeometry( QRect( 30, 20, 320, 30 ) );

    pushButton27_2_2_2 = new QPushButton( WStackPage_26, "pushButton27_2_2_2" );
    pushButton27_2_2_2->setGeometry( QRect( 10, 402, 70, 30 ) );

    pushButton76_2 = new QPushButton( WStackPage_26, "pushButton76_2" );
    pushButton76_2->setGeometry( QRect( 330, 400, 95, 30 ) );

    textLabel1_14_2 = new QLabel( WStackPage_26, "textLabel1_14_2" );
    textLabel1_14_2->setGeometry( QRect( 30, 60, 371, 330 ) );
    textLabel1_14_2->setTextFormat( QLabel::RichText );
    textLabel1_14_2->setAlignment( int( QLabel::AlignTop | QLabel::AlignLeft ) );
    widgetStack6->addWidget( WStackPage_26, 5 );

    WStackPage_27 = new QWidget( widgetStack6, "WStackPage_27" );

    textLabel3_11 = new QLabel( WStackPage_27, "textLabel3_11" );
    textLabel3_11->setGeometry( QRect( 20, 20, 230, 30 ) );

    textLabel1_20_2 = new QLabel( WStackPage_27, "textLabel1_20_2" );
    textLabel1_20_2->setGeometry( QRect( 30, 170, 260, 20 ) );

    pushButton27_2_4_2 = new QPushButton( WStackPage_27, "pushButton27_2_4_2" );
    pushButton27_2_4_2->setGeometry( QRect( 9, 404, 70, 30 ) );

    lineEdit51_2 = new QLineEdit( WStackPage_27, "lineEdit51_2" );
    lineEdit51_2->setGeometry( QRect( 289, 167, 90, 20 ) );

    pushButton69_2 = new QPushButton( WStackPage_27, "pushButton69_2" );
    pushButton69_2->setGeometry( QRect( 340, 400, 91, 31 ) );

    pushButton75_2_2 = new QPushButton( WStackPage_27, "pushButton75_2_2" );
    pushButton75_2_2->setGeometry( QRect( 230, 400, 100, 28 ) );
    widgetStack6->addWidget( WStackPage_27, 6 );

    WStackPage_28 = new QWidget( widgetStack6, "WStackPage_28" );

    textLabel1_15 = new QLabel( WStackPage_28, "textLabel1_15" );
    textLabel1_15->setGeometry( QRect( 39, 44, 380, 21 ) );

    pushButton27_2_4_2_2 = new QPushButton( WStackPage_28, "pushButton27_2_4_2_2" );
    pushButton27_2_4_2_2->setGeometry( QRect( 9, 404, 70, 30 ) );
    widgetStack6->addWidget( WStackPage_28, 7 );

    WStackPage_29 = new QWidget( widgetStack6, "WStackPage_29" );

    buttonGroup11_2 = new QButtonGroup( WStackPage_29, "buttonGroup11_2" );
    buttonGroup11_2->setGeometry( QRect( 10, 140, 420, 90 ) );

    radioButton21_2_2 = new QRadioButton( buttonGroup11_2, "radioButton21_2_2" );
    radioButton21_2_2->setGeometry( QRect( 20, 10, 380, 21 ) );
    radioButton21_2_2->setChecked( TRUE );

    radioButton22_2_2 = new QRadioButton( buttonGroup11_2, "radioButton22_2_2" );
    radioButton22_2_2->setGeometry( QRect( 20, 40, 380, 40 ) );

    textLabel1_14_4 = new QLabel( WStackPage_29, "textLabel1_14_4" );
    textLabel1_14_4->setGeometry( QRect( 19, 37, 250, 20 ) );
    widgetStack6->addWidget( WStackPage_29, 8 );
    tabWidget2->insertTab( P_Value, QString("") );
    widgetStack4->addWidget( WStackPage_12, 0 );
    widgetStack2->addWidget( WStackPage_11, 2 );

    WStackPage_30 = new QWidget( widgetStack2, "WStackPage_30" );

    textLabel1_17 = new QLabel( WStackPage_30, "textLabel1_17" );
    textLabel1_17->setGeometry( QRect( 20, 10, 140, 20 ) );

    groupBox8 = new QGroupBox( WStackPage_30, "groupBox8" );
    groupBox8->setGeometry( QRect( 20, 310, 440, 140 ) );

    pushButton50_3 = new QPushButton( groupBox8, "pushButton50_3" );
    pushButton50_3->setGeometry( QRect( 20, 41, 130, 31 ) );

    pushButton50_2_4 = new QPushButton( groupBox8, "pushButton50_2_4" );
    pushButton50_2_4->setGeometry( QRect( 160, 41, 130, 31 ) );

    pushButton71_2 = new QPushButton( groupBox8, "pushButton71_2" );
    pushButton71_2->setGeometry( QRect( 20, 90, 410, 31 ) );

    groupBox7 = new QGroupBox( WStackPage_30, "groupBox7" );
    groupBox7->setGeometry( QRect( 15, 100, 441, 140 ) );

    pushButton71 = new QPushButton( groupBox7, "pushButton71" );
    pushButton71->setGeometry( QRect( 20, 90, 410, 31 ) );

    pushButton50 = new QPushButton( groupBox7, "pushButton50" );
    pushButton50->setGeometry( QRect( 20, 40, 130, 31 ) );

    pushButton50_2 = new QPushButton( groupBox7, "pushButton50_2" );
    pushButton50_2->setGeometry( QRect( 160, 40, 130, 31 ) );
    widgetStack2->addWidget( WStackPage_30, 3 );

    WStackPage_31 = new QWidget( widgetStack2, "WStackPage_31" );

    textLabel1_24 = new QLabel( WStackPage_31, "textLabel1_24" );
    textLabel1_24->setGeometry( QRect( 12, 11, 270, 30 ) );

    widgetStack7 = new QWidgetStack( WStackPage_31, "widgetStack7" );
    widgetStack7->setGeometry( QRect( 10, 40, 450, 460 ) );

    WStackPage_32 = new QWidget( widgetStack7, "WStackPage_32" );

    groupBox29 = new QGroupBox( WStackPage_32, "groupBox29" );
    groupBox29->setGeometry( QRect( -1, 21, 450, 430 ) );

    buttonGroup2_2 = new QButtonGroup( groupBox29, "buttonGroup2_2" );
    buttonGroup2_2->setGeometry( QRect( 21, 160, 410, 220 ) );
    buttonGroup2_2->setProperty( "selectedId", -1 );

    checkBox4_2 = new QCheckBox( buttonGroup2_2, "checkBox4_2" );
    checkBox4_2->setGeometry( QRect( 190, 190, 190, 21 ) );

    groupBox29_2 = new QGroupBox( buttonGroup2_2, "groupBox29_2" );
    groupBox29_2->setGeometry( QRect( 10, 10, 390, 170 ) );

    checkBox7 = new QCheckBox( groupBox29_2, "checkBox7" );
    checkBox7->setEnabled( TRUE );
    checkBox7->setGeometry( QRect( 160, 140, 138, 21 ) );

    textLabel2_15 = new QLabel( groupBox29_2, "textLabel2_15" );
    textLabel2_15->setGeometry( QRect( 5, 10, 383, 101 ) );

    checkBox6 = new QCheckBox( groupBox29_2, "checkBox6" );
    checkBox6->setGeometry( QRect( 160, 110, 138, 21 ) );

    groupBox30 = new QGroupBox( groupBox29, "groupBox30" );
    groupBox30->setGeometry( QRect( 15, 20, 420, 130 ) );

    textLabel1_25 = new QLabel( groupBox30, "textLabel1_25" );
    textLabel1_25->setGeometry( QRect( 10, 11, 70, 20 ) );

    textLabel3_12 = new QLabel( groupBox30, "textLabel3_12" );
    textLabel3_12->setGeometry( QRect( 10, 71, 110, 20 ) );

    textLabel4_8 = new QLabel( groupBox30, "textLabel4_8" );
    textLabel4_8->setGeometry( QRect( 10, 101, 113, 20 ) );

    lineEdit53 = new QLineEdit( groupBox30, "lineEdit53" );
    lineEdit53->setGeometry( QRect( 131, 71, 280, 21 ) );

    lineEdit54 = new QLineEdit( groupBox30, "lineEdit54" );
    lineEdit54->setGeometry( QRect( 131, 101, 280, 21 ) );

    pushButton81 = new QPushButton( groupBox30, "pushButton81" );
    pushButton81->setGeometry( QRect( 90, 40, 230, 24 ) );

    textLabel2 = new QLabel( groupBox30, "textLabel2" );
    textLabel2->setGeometry( QRect( 90, 11, 310, 20 ) );

    pushButton2 = new QPushButton( groupBox29, "pushButton2" );
    pushButton2->setGeometry( QRect( 320, 390, 88, 30 ) );
    widgetStack7->addWidget( WStackPage_32, 0 );

    WStackPage_33 = new QWidget( widgetStack7, "WStackPage_33" );

    textEdit1_2 = new QTextEdit( WStackPage_33, "textEdit1_2" );
    textEdit1_2->setGeometry( QRect( 20, 50, 420, 300 ) );
    textEdit1_2->setWordWrap( QTextEdit::WidgetWidth );

    pushButton82 = new QPushButton( WStackPage_33, "pushButton82" );
    pushButton82->setGeometry( QRect( 19, 400, 95, 30 ) );

    textLabel1_23 = new QLabel( WStackPage_33, "textLabel1_23" );
    textLabel1_23->setGeometry( QRect( 20, 20, 61, 20 ) );

    pushButton4 = new QPushButton( WStackPage_33, "pushButton4" );
    pushButton4->setGeometry( QRect( 210, 394, 230, 30 ) );
    widgetStack7->addWidget( WStackPage_33, 1 );

    WStackPage_34 = new QWidget( widgetStack7, "WStackPage_34" );
    widgetStack7->addWidget( WStackPage_34, 2 );
    widgetStack2->addWidget( WStackPage_31, 4 );

    buttonGroup2 = new QButtonGroup( frame3, "buttonGroup2" );
    buttonGroup2->setGeometry( QRect( 10, 10, 180, 540 ) );

    resultRadio = new QRadioButton( buttonGroup2, "resultRadio" );
    resultRadio->setGeometry( QRect( 8, 144, 165, 21 ) );
    buttonGroup2->insert( resultRadio, 1 );

    line1 = new QFrame( buttonGroup2, "line1" );
    line1->setGeometry( QRect( 11, 223, 160, 20 ) );
    line1->setFrameShape( QFrame::HLine );
    line1->setFrameShadow( QFrame::Sunken );
    line1->setFrameShape( QFrame::HLine );

    radioButton20 = new QRadioButton( buttonGroup2, "radioButton20" );
    radioButton20->setGeometry( QRect( 8, 194, 165, 21 ) );

    orfRadio = new QRadioButton( buttonGroup2, "orfRadio" );
    orfRadio->setGeometry( QRect( 8, 44, 165, 21 ) );
    orfRadio->setChecked( TRUE );
    buttonGroup2->insert( orfRadio, 1 );

    predictionRadio = new QRadioButton( buttonGroup2, "predictionRadio" );
    predictionRadio->setEnabled( TRUE );
    predictionRadio->setGeometry( QRect( 8, 94, 165, 21 ) );

    buttonGroup12 = new QButtonGroup( buttonGroup2, "buttonGroup12" );
    buttonGroup12->setGeometry( QRect( 10, 250, 160, 170 ) );
    buttonGroup12->setFrameShape( QButtonGroup::WinPanel );

    line2 = new QFrame( buttonGroup12, "line2" );
    line2->setGeometry( QRect( 8, 83, 141, 20 ) );
    line2->setFrameShape( QFrame::HLine );
    line2->setFrameShadow( QFrame::Sunken );
    line2->setFrameShape( QFrame::HLine );

    radioButton21 = new QRadioButton( buttonGroup12, "radioButton21" );
    radioButton21->setGeometry( QRect( 20, 30, 112, 21 ) );
    radioButton21->setChecked( TRUE );

    computationPart = new QLabel( buttonGroup12, "computationPart" );
    computationPart->setGeometry( QRect( 10, 100, 140, 20 ) );
    QFont computationPart_font(  computationPart->font() );
    computationPart_font.setPointSize( 8 );
    computationPart->setFont( computationPart_font ); 

    radioButton22 = new QRadioButton( buttonGroup12, "radioButton22" );
    radioButton22->setGeometry( QRect( 20, 60, 112, 21 ) );

    textLabel1_27 = new QLabel( buttonGroup2, "textLabel1_27" );
    textLabel1_27->setGeometry( QRect( 10, 450, 160, 40 ) );
    languageChange();
    resize( QSize(725, 608).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    // signals and slots connections
    connect( orfRadio, SIGNAL( clicked() ), this, SLOT( orfRadio_clicked() ) );
    connect( predictionRadio, SIGNAL( clicked() ), this, SLOT( predictionRadio_clicked() ) );
    connect( pushButton29, SIGNAL( clicked() ), this, SLOT( pushButton29_clicked() ) );
    connect( pushButton29_2, SIGNAL( clicked() ), this, SLOT( pushButton29_2_clicked() ) );
    connect( pushButton29_4, SIGNAL( clicked() ), this, SLOT( pushButton29_4_clicked() ) );
    connect( pushButton27_2_5, SIGNAL( clicked() ), this, SLOT( pushButton27_2_5_clicked() ) );
    connect( pushButton27_2_6, SIGNAL( clicked() ), this, SLOT( pushButton27_2_6_clicked() ) );
    connect( pushButton27_2_7, SIGNAL( clicked() ), this, SLOT( pushButton27_2_7_clicked() ) );
    connect( pushButton27_2_8, SIGNAL( clicked() ), this, SLOT( pushButton27_2_8_clicked() ) );
    connect( tabWidget2, SIGNAL( currentChanged(QWidget*) ), this, SLOT( tabWidget2_currentChanged(QWidget*) ) );
    connect( pushButton35, SIGNAL( clicked() ), this, SLOT( pushButton35_clicked() ) );
    connect( checkBox3, SIGNAL( clicked() ), this, SLOT( checkBox3_clicked() ) );
    connect( pushButton35_2, SIGNAL( clicked() ), this, SLOT( pushButton35_2_clicked() ) );
    connect( pushButton35_3, SIGNAL( clicked() ), this, SLOT( pushButton35_3_clicked() ) );
    connect( widgetStack5, SIGNAL( aboutToShow(int) ), this, SLOT( widgetStack5_aboutToShow(int) ) );
    connect( pushButton29_3, SIGNAL( pressed() ), this, SLOT( pushButton29_3_pressed() ) );
    connect( pushButton29_3, SIGNAL( released() ), this, SLOT( pushButton29_3_released() ) );
    connect( pushButton35_4, SIGNAL( clicked() ), this, SLOT( pushButton35_4_clicked() ) );
    connect( pushButton27_2_5_2, SIGNAL( clicked() ), this, SLOT( pushButton27_2_5_2_clicked() ) );
    connect( pushButton27_2_4, SIGNAL( clicked() ), this, SLOT( pushButton27_2_4_clicked() ) );
    connect( pushButton27_2_3, SIGNAL( clicked() ), this, SLOT( pushButton27_2_3_clicked() ) );
    connect( pushButton27_2_2, SIGNAL( clicked() ), this, SLOT( pushButton27_2_2_clicked() ) );
    connect( pushButton35_5, SIGNAL( clicked() ), this, SLOT( pushButton35_5_clicked() ) );
    connect( pushButton27_2, SIGNAL( clicked() ), this, SLOT( pushButton27_2_clicked() ) );
    connect( pushButton29_4_2, SIGNAL( clicked() ), this, SLOT( pushButton29_4_2_clicked() ) );
    connect( pushButton29_2_2, SIGNAL( clicked() ), this, SLOT( pushButton29_2_2_clicked() ) );
    connect( pushButton29_5, SIGNAL( clicked() ), this, SLOT( pushButton29_5_clicked() ) );
    connect( pushButton35_6, SIGNAL( clicked() ), this, SLOT( pushButton35_6_clicked() ) );
    connect( pushButton27_2_2_2, SIGNAL( clicked() ), this, SLOT( pushButton27_2_2_2_clicked() ) );
    connect( radioButton9_2, SIGNAL( clicked() ), this, SLOT( radioButton9_2_clicked() ) );
    connect( radioButton8_2, SIGNAL( clicked() ), this, SLOT( radioButton8_2_clicked() ) );
    connect( pushButton35_7, SIGNAL( clicked() ), this, SLOT( pushButton35_7_clicked() ) );
    connect( pushButton35_8, SIGNAL( clicked() ), this, SLOT( pushButton35_8_clicked() ) );
    connect( pushButton27_2_4_2, SIGNAL( released() ), this, SLOT( pushButton27_2_4_2_released() ) );
    connect( pushButton27_2_4_2_2, SIGNAL( released() ), this, SLOT( pushButton27_2_4_2_2_released() ) );
    connect( pushButton29_3_2, SIGNAL( pressed() ), this, SLOT( pushButton29_3_2_pressed() ) );
    connect( pushButton29_3_2, SIGNAL( released() ), this, SLOT( pushButton29_3_2_released() ) );
    connect( checkBox3_2, SIGNAL( clicked() ), this, SLOT( checkBox3_2_clicked() ) );
    connect( resultRadio, SIGNAL( clicked() ), this, SLOT( resultRadio_clicked() ) );
    connect( pushButton50, SIGNAL( clicked() ), this, SLOT( pushButton50_clicked() ) );
    connect( pushButton50_2, SIGNAL( clicked() ), this, SLOT( pushButton50_2_clicked() ) );
    connect( pushButton50_3, SIGNAL( clicked() ), this, SLOT( pushButton50_3_clicked() ) );
    connect( pushButton50_2_4, SIGNAL( clicked() ), this, SLOT( pushButton50_2_4_clicked() ) );
    connect( closeSession, SIGNAL( clicked() ), this, SLOT( closeSession_clicked() ) );
    connect( pushButton59, SIGNAL( clicked() ), this, SLOT( pushButton59_clicked() ) );
    connect( pushButton59_2, SIGNAL( clicked() ), this, SLOT( pushButton59_2_clicked() ) );
    connect( pushButton59_2_2, SIGNAL( released() ), this, SLOT( pushButton59_2_2_released() ) );
    connect( pushButton59_2_2, SIGNAL( pressed() ), this, SLOT( pushButton59_2_2_pressed() ) );
    connect( pushButton59_2_3, SIGNAL( clicked() ), this, SLOT( pushButton59_2_3_clicked() ) );
    connect( pushButton59_6, SIGNAL( clicked() ), this, SLOT( pushButton59_6_clicked() ) );
    connect( pushButton59_5, SIGNAL( released() ), this, SLOT( pushButton59_5_released() ) );
    connect( pushButton59_5, SIGNAL( pressed() ), this, SLOT( pushButton59_5_pressed() ) );
    connect( pushButton59_4, SIGNAL( clicked() ), this, SLOT( pushButton59_4_clicked() ) );
    connect( pushButton59_3, SIGNAL( clicked() ), this, SLOT( pushButton59_3_clicked() ) );
    connect( widgetStack, SIGNAL( aboutToShow(QWidget*) ), this, SLOT( widgetStack_aboutToShow(QWidget*) ) );
    connect( pushButton26, SIGNAL( clicked() ), this, SLOT( pushButton26_clicked() ) );
    connect( pushButton16_3, SIGNAL( clicked() ), this, SLOT( pushButton16_3_clicked() ) );
    connect( checkBox2, SIGNAL( toggled(bool) ), this, SLOT( checkBox2_toggled(bool) ) );
    connect( radioButton10, SIGNAL( clicked() ), this, SLOT( radioButton10_clicked() ) );
    connect( radioButton9, SIGNAL( clicked() ), this, SLOT( radioButton9_clicked() ) );
    connect( radioButton7, SIGNAL( clicked() ), this, SLOT( radioButton7_clicked() ) );
    connect( radioButton8, SIGNAL( clicked() ), this, SLOT( radioButton8_clicked() ) );
    connect( pushButton3, SIGNAL( clicked() ), this, SLOT( pushButton3_clicked() ) );
    connect( computeOrfNowPushButton, SIGNAL( clicked() ), this, SLOT( computeOrfNowPushButton_clicked() ) );
    connect( radioButton10_2, SIGNAL( clicked() ), this, SLOT( radioButton10_2_clicked() ) );
    connect( radioButton11, SIGNAL( clicked() ), this, SLOT( radioButton11_clicked() ) );
    connect( radioButton10_2_2, SIGNAL( clicked() ), this, SLOT( radioButton10_2_2_clicked() ) );
    connect( radioButton11_2, SIGNAL( clicked() ), this, SLOT( radioButton11_2_clicked() ) );
    connect( radioButton10_2_2_2, SIGNAL( clicked() ), this, SLOT( radioButton10_2_2_2_clicked() ) );
    connect( radioButton11_2_2, SIGNAL( clicked() ), this, SLOT( radioButton11_2_2_clicked() ) );
    connect( pushButton29_4_3, SIGNAL( clicked() ), this, SLOT( pushButton29_4_3_clicked() ) );
    connect( pushButton59_2_3_2, SIGNAL( clicked() ), this, SLOT( pushButton59_2_3_2_clicked() ) );
    connect( pushButton69, SIGNAL( clicked() ), this, SLOT( pushButton69_clicked() ) );
    connect( pushButton29_5_2, SIGNAL( clicked() ), this, SLOT( pushButton29_5_2_clicked() ) );
    connect( pushButton69_2, SIGNAL( clicked() ), this, SLOT( pushButton69_2_clicked() ) );
    connect( pushButton27, SIGNAL( clicked() ), this, SLOT( pushButton27_clicked() ) );
    connect( pushButton28, SIGNAL( clicked() ), this, SLOT( pushButton28_clicked() ) );
    connect( pushButton71, SIGNAL( clicked() ), this, SLOT( pushButton71_clicked() ) );
    connect( pushButton71_2, SIGNAL( clicked() ), this, SLOT( pushButton71_2_clicked() ) );
    connect( pushButton14, SIGNAL( clicked() ), this, SLOT( pushButton14_clicked() ) );
    connect( pushButton25, SIGNAL( clicked() ), this, SLOT( pushButton25_clicked() ) );
    connect( checkBox4, SIGNAL( stateChanged(int) ), this, SLOT( checkBox4_stateChanged(int) ) );
    connect( pushButton72, SIGNAL( clicked() ), this, SLOT( pushButton72_clicked() ) );
    connect( pushButton76_2, SIGNAL( clicked() ), this, SLOT( pushButton76_2_clicked() ) );
    connect( pushButton59_7, SIGNAL( clicked() ), this, SLOT( pushButton59_7_clicked() ) );
    connect( pushButton2, SIGNAL( clicked() ), this, SLOT( pushButton2_clicked() ) );
    connect( pushButton82, SIGNAL( clicked() ), this, SLOT( pushButton82_clicked() ) );
    connect( widgetStack7, SIGNAL( aboutToShow(int) ), this, SLOT( widgetStack7_aboutToShow(int) ) );
    connect( radioButton20, SIGNAL( clicked() ), this, SLOT( radioButton20_clicked() ) );
    connect( pushButton4, SIGNAL( clicked() ), this, SLOT( pushButton4_clicked() ) );
    connect( pushButton81, SIGNAL( clicked() ), this, SLOT( pushButton81_clicked() ) );
    connect( lineEdit17, SIGNAL( textChanged(const QString&) ), this, SLOT( lineEdit17_textChanged(const QString&) ) );
    connect( lineEdit17_2, SIGNAL( returnPressed() ), this, SLOT( lineEdit17_2_returnPressed() ) );
    connect( lineEdit17, SIGNAL( returnPressed() ), this, SLOT( lineEdit17_returnPressed() ) );
    connect( lineEdit17_2, SIGNAL( textChanged(const QString&) ), this, SLOT( lineEdit17_2_textChanged(const QString&) ) );
    connect( pushButton75, SIGNAL( clicked() ), this, SLOT( pushButton75_clicked() ) );
    connect( radioButton21, SIGNAL( clicked() ), this, SLOT( radioButton21_clicked() ) );
    connect( radioButton22, SIGNAL( clicked() ), this, SLOT( radioButton22_clicked() ) );
    connect( pushButton74, SIGNAL( clicked() ), this, SLOT( pushButton74_clicked() ) );
    connect( tabWidget2, SIGNAL( selected(const QString&) ), this, SLOT( tabWidget2_selected(const QString&) ) );
    connect( pushButton18, SIGNAL( released() ), this, SLOT( pushButton18_released() ) );
    connect( pushButton16_4, SIGNAL( released() ), this, SLOT( pushButton16_4_released() ) );
    connect( lineEdit3, SIGNAL( textChanged(const QString&) ), this, SLOT( lineEdit3_textChanged(const QString&) ) );
    connect( lineEdit4, SIGNAL( textChanged(const QString&) ), this, SLOT( lineEdit4_textChanged(const QString&) ) );
    connect( pushButton75_2, SIGNAL( clicked() ), this, SLOT( pushButton75_2_clicked() ) );
    connect( checkBox8, SIGNAL( stateChanged(int) ), this, SLOT( checkBox8_stateChanged(int) ) );
    connect( lineEdit61, SIGNAL( textChanged(const QString&) ), this, SLOT( lineEdit61_textChanged(const QString&) ) );
    connect( lineEdit62, SIGNAL( textChanged(const QString&) ), this, SLOT( lineEdit62_textChanged(const QString&) ) );
    connect( radioButton21_2, SIGNAL( toggled(bool) ), this, SLOT( radioButton21_2_toggled(bool) ) );
    connect( radioButton22_2, SIGNAL( toggled(bool) ), this, SLOT( radioButton22_2_toggled(bool) ) );
    connect( pushButton76, SIGNAL( clicked() ), this, SLOT( pushButton76_clicked() ) );
    connect( pushButton27_2_5_2_2, SIGNAL( clicked() ), this, SLOT( pushButton27_2_5_2_2_clicked() ) );
    connect( checkBox9, SIGNAL( clicked() ), this, SLOT( checkBox9_clicked() ) );
    connect( pushButton74_2, SIGNAL( clicked() ), this, SLOT( pushButton74_2_clicked() ) );
    connect( predictionRadio, SIGNAL( stateChanged(int) ), this, SLOT( predictionRadio_stateChanged(int) ) );
    connect( pushButton96, SIGNAL( clicked() ), this, SLOT( pushButton96_clicked() ) );
    connect( pushButton77, SIGNAL( clicked() ), this, SLOT( pushButton77_clicked() ) );
    connect( pushButton78, SIGNAL( clicked() ), this, SLOT( pushButton78_clicked() ) );
    connect( radioButton33, SIGNAL( clicked() ), this, SLOT( radioButton33_clicked() ) );
    connect( radioButton34, SIGNAL( clicked() ), this, SLOT( radioButton34_clicked() ) );
    connect( pushButton75_3, SIGNAL( clicked() ), this, SLOT( pushButton75_3_clicked() ) );
    connect( browseFile, SIGNAL( clicked() ), this, SLOT( browseFile_clicked() ) );
    connect( radioButton27, SIGNAL( clicked() ), this, SLOT( radioButton27_clicked() ) );
    connect( radioButton29, SIGNAL( clicked() ), this, SLOT( radioButton29_clicked() ) );
    connect( openSession, SIGNAL( clicked() ), this, SLOT( openSession_clicked() ) );
    connect( radioButton29, SIGNAL( stateChanged(int) ), this, SLOT( radioButton29_stateChanged(int) ) );
    connect( radioButton28, SIGNAL( stateChanged(int) ), this, SLOT( radioButton28_stateChanged(int) ) );
    connect( radioButton33, SIGNAL( stateChanged(int) ), this, SLOT( radioButton33_stateChanged(int) ) );
    connect( radioButton34, SIGNAL( stateChanged(int) ), this, SLOT( radioButton34_stateChanged(int) ) );
    connect( radioButton27, SIGNAL( stateChanged(int) ), this, SLOT( radioButton27_stateChanged(int) ) );
    connect( pushButton76_3, SIGNAL( clicked() ), this, SLOT( pushButton76_3_clicked() ) );
    connect( pushButton74_2_2, SIGNAL( released() ), this, SLOT( pushButton74_2_2_released() ) );
    connect( pushButton75_2_2, SIGNAL( clicked() ), this, SLOT( pushButton75_2_2_clicked() ) );
    connect( pushButton75_4, SIGNAL( clicked() ), this, SLOT( pushButton75_4_clicked() ) );
    connect( checkBox8_2, SIGNAL( stateChanged(int) ), this, SLOT( checkBox8_2_stateChanged(int) ) );
    connect( widgetStack6, SIGNAL( aboutToShow(int) ), this, SLOT( widgetStack6_aboutToShow(int) ) );
    connect( radioButton21_2_2, SIGNAL( toggled(bool) ), this, SLOT( radioButton21_2_2_toggled(bool) ) );
    connect( radioButton22_2_2, SIGNAL( toggled(bool) ), this, SLOT( radioButton22_2_2_toggled(bool) ) );

    // tab order
    setTabOrder( pushButton29, pushButton59 );
    setTabOrder( pushButton59, pushButton29_2 );
    setTabOrder( pushButton29_2, pushButton59_2 );
    setTabOrder( pushButton59_2, pushButton29_3 );
    setTabOrder( pushButton29_3, pushButton59_2_2 );
    setTabOrder( pushButton59_2_2, pushButton29_4 );
    setTabOrder( pushButton29_4, pushButton59_2_3 );
    setTabOrder( pushButton59_2_3, pushButton29_4_3 );
    setTabOrder( pushButton29_4_3, pushButton59_2_3_2 );
    setTabOrder( pushButton59_2_3_2, radioButton10_2 );
    setTabOrder( radioButton10_2, lineEdit8 );
    setTabOrder( lineEdit8, lineEdit9 );
    setTabOrder( lineEdit9, lineEdit10 );
    setTabOrder( lineEdit10, checkBox3 );
    setTabOrder( checkBox3, lineEdit45 );
    setTabOrder( lineEdit45, pushButton27_2_5 );
    setTabOrder( pushButton27_2_5, pushButton35 );
    setTabOrder( pushButton35, lineEdit_File_PGS );
    setTabOrder( lineEdit_File_PGS, lineEdit_File_PNGS );
    setTabOrder( lineEdit_File_PNGS, lineEdit_File_PNPS );
    setTabOrder( lineEdit_File_PNPS, radioButton10_2_2 );
    setTabOrder( radioButton10_2_2, lineEdit8_3 );
    setTabOrder( lineEdit8_3, lineEdit9_3 );
    setTabOrder( lineEdit9_3, checkBox4 );
    setTabOrder( checkBox4, lineEdit15 );
    setTabOrder( lineEdit15, lineEdit16 );
    setTabOrder( lineEdit16, pushButton27_2_6 );
    setTabOrder( pushButton27_2_6, pushButton35_2 );
    setTabOrder( pushButton35_2, lineEdit17 );
    setTabOrder( lineEdit17, pushButton35_3 );
    setTabOrder( pushButton35_3, pushButton27_2_7 );
    setTabOrder( pushButton27_2_7, radioButton16 );
    setTabOrder( radioButton16, lineEdit19 );
    setTabOrder( lineEdit19, lineEdit19_2 );
    setTabOrder( lineEdit19_2, lineEdit19_3 );
    setTabOrder( lineEdit19_3, lineEdit19_4 );
    setTabOrder( lineEdit19_4, lineEdit19_5 );
    setTabOrder( lineEdit19_5, lineEdit19_6 );
    setTabOrder( lineEdit19_6, lineEdit19_7 );
    setTabOrder( lineEdit19_7, pushButton27_2_8 );
    setTabOrder( pushButton27_2_8, pushButton35_4 );
    setTabOrder( pushButton35_4, lineEdit51 );
    setTabOrder( lineEdit51, pushButton27_2_5_2 );
    setTabOrder( pushButton27_2_5_2, pushButton69 );
    setTabOrder( pushButton69, pushButton29_5 );
    setTabOrder( pushButton29_5, pushButton59_3 );
    setTabOrder( pushButton59_3, pushButton29_2_2 );
    setTabOrder( pushButton29_2_2, pushButton59_4 );
    setTabOrder( pushButton59_4, pushButton29_3_2 );
    setTabOrder( pushButton29_3_2, pushButton59_5 );
    setTabOrder( pushButton59_5, pushButton29_4_2 );
    setTabOrder( pushButton29_4_2, pushButton59_6 );
    setTabOrder( pushButton59_6, pushButton29_5_2 );
    setTabOrder( pushButton29_5_2, pushButton59_7 );
    setTabOrder( pushButton59_7, radioButton9_2 );
    setTabOrder( radioButton9_2, lineEdit8_2 );
    setTabOrder( lineEdit8_2, lineEdit9_2 );
    setTabOrder( lineEdit9_2, lineEdit10_2 );
    setTabOrder( lineEdit10_2, checkBox3_2 );
    setTabOrder( checkBox3_2, lineEdit45_2 );
    setTabOrder( lineEdit45_2, lineEdit29 );
    setTabOrder( lineEdit29, lineEdit30 );
    setTabOrder( lineEdit30, lineEdit31 );
    setTabOrder( lineEdit31, pushButton27_2 );
    setTabOrder( pushButton27_2, pushButton35_5 );
    setTabOrder( pushButton35_5, lineEdit_File_PGS_2 );
    setTabOrder( lineEdit_File_PGS_2, lineEdit_File_PNGS_2 );
    setTabOrder( lineEdit_File_PNGS_2, lineEdit_File_PNPS_2 );
    setTabOrder( lineEdit_File_PNPS_2, radioButton10_2_2_2 );
    setTabOrder( radioButton10_2_2_2, lineEdit8_3_2 );
    setTabOrder( lineEdit8_3_2, lineEdit9_3_2 );
    setTabOrder( lineEdit9_3_2, lineEdit15_2 );
    setTabOrder( lineEdit15_2, lineEdit16_2 );
    setTabOrder( lineEdit16_2, pushButton27_2_2 );
    setTabOrder( pushButton27_2_2, pushButton35_6 );
    setTabOrder( pushButton35_6, lineEdit17_2 );
    setTabOrder( lineEdit17_2, pushButton35_7 );
    setTabOrder( pushButton35_7, pushButton27_2_3 );
    setTabOrder( pushButton27_2_3, radioButton16_2 );
    setTabOrder( radioButton16_2, lineEdit19_8 );
    setTabOrder( lineEdit19_8, lineEdit19_2_2 );
    setTabOrder( lineEdit19_2_2, lineEdit19_3_2 );
    setTabOrder( lineEdit19_3_2, lineEdit19_4_2 );
    setTabOrder( lineEdit19_4_2, lineEdit19_5_2 );
    setTabOrder( lineEdit19_5_2, lineEdit19_6_2 );
    setTabOrder( lineEdit19_6_2, lineEdit19_7_2 );
    setTabOrder( lineEdit19_7_2, pushButton27_2_4 );
    setTabOrder( pushButton27_2_4, pushButton35_8 );
    setTabOrder( pushButton35_8, pushButton27_2_2_2 );
    setTabOrder( pushButton27_2_2_2, pushButton76_2 );
    setTabOrder( pushButton76_2, lineEdit51_2 );
    setTabOrder( lineEdit51_2, pushButton27_2_4_2 );
    setTabOrder( pushButton27_2_4_2, pushButton69_2 );
    setTabOrder( pushButton69_2, pushButton27_2_4_2_2 );
    setTabOrder( pushButton27_2_4_2_2, pushButton50 );
    setTabOrder( pushButton50, pushButton50_2 );
    setTabOrder( pushButton50_2, pushButton71 );
    setTabOrder( pushButton71, pushButton50_3 );
    setTabOrder( pushButton50_3, pushButton50_2_4 );
    setTabOrder( pushButton50_2_4, pushButton71_2 );
    setTabOrder( pushButton71_2, pushButton4 );
    setTabOrder( pushButton4, pushButton82 );
    setTabOrder( pushButton82, pushButton81 );
    setTabOrder( pushButton81, lineEdit53 );
    setTabOrder( lineEdit53, lineEdit54 );
    setTabOrder( lineEdit54, checkBox6 );
    setTabOrder( checkBox6, checkBox7 );
    setTabOrder( checkBox7, checkBox4_2 );
    setTabOrder( checkBox4_2, pushButton2 );
    setTabOrder( pushButton2, lineEdit4_2 );
    setTabOrder( lineEdit4_2, lineEdit5 );
    setTabOrder( lineEdit5, lineEdit6 );
    setTabOrder( lineEdit6, lineEdit7 );
    setTabOrder( lineEdit7, pushButton18 );
    setTabOrder( pushButton18, pushButton14 );
    setTabOrder( pushButton14, radioButton8_2 );
    setTabOrder( radioButton8_2, lineEdit11_2 );
    setTabOrder( lineEdit11_2, closeSession );
    setTabOrder( closeSession, orfRadio );
    setTabOrder( orfRadio, textEdit1 );
    setTabOrder( textEdit1, radioButton9 );
    setTabOrder( radioButton9, checkBox2 );
    setTabOrder( checkBox2, pushButton16_3 );
    setTabOrder( pushButton16_3, pushButton26 );
    setTabOrder( pushButton26, radioButton7 );
    setTabOrder( radioButton7, pushButton14 );
    setTabOrder( pushButton14, lineEdit11 );
    setTabOrder( lineEdit11, tabWidget2 );
    setTabOrder( tabWidget2, pushButton3 );
    setTabOrder( pushButton3, computeOrfNowPushButton );
    setTabOrder( computeOrfNowPushButton, pushButton16_4 );
    setTabOrder( pushButton16_4, lineEdit3 );
    setTabOrder( lineEdit3, pushButton27 );
    setTabOrder( pushButton27, pushButton28 );
    setTabOrder( pushButton28, lineEdit4 );
    setTabOrder( lineEdit4, pushButton25 );
    setTabOrder( pushButton25, pushButton72 );
    setTabOrder( pushButton72, textEdit1_2 );
    init();
}

/*
 *  Destroys the object and frees any allocated resources
 */
Form1::~Form1()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void Form1::languageChange()
{
    setCaption( tr( "Gene Prediction and Merging" ) );
    textLabel1->setText( tr( "Sequence File Name :" ) );
    pushButton74->setText( tr( "What is this?" ) );
    QToolTip::add( pushButton74, QString::null );
    QWhatsThis::add( pushButton74, tr( "This is What is button. <br> You can click on this button and then click on required object to know what is this?" ) );
    sequenceFileName->setText( tr( "<b></b>" ) );
    closeSession->setText( tr( "Close Session" ) );
    textLabel3_4->setText( tr( "<b><p align=\"center\">GENE PREDICTION AND ANALYSIS SOFTWARE<font size=\"+3\"></font></p></b>" ) );
    textLabel4->setText( tr( "<p align=\"center\"><b><font size=\"+1\">Stat-Math Unit</font></b></p>\n"
"<font><font size=\"+2\"><p align=\"center\">Indian Statistical Institute, Kolkata, India</p></font></font><font size=\"+2\"></font>" ) );
    groupBox18->setTitle( QString::null );
    pushButton78->setText( tr( "Open existing session" ) );
    groupBox37->setTitle( tr( "Folder, where the intermediate and processed output will be stored for a sequence " ) );
    buttonGroup15->setTitle( QString::null );
    radioButton33->setText( tr( "Default Folder" ) );
    radioButton34->setText( tr( "Choose a folder" ) );
    lineEdit63->setText( tr( "/applicationHome/defaultFolder" ) );
    pushButton75_3->setText( tr( "Browse" ) );
    pushButton77->setText( tr( "Open new session" ) );
    groupBox37_2->setTitle( tr( "Session parameters" ) );
    pushButton96->setText( tr( "Previous" ) );
    groupBox41->setTitle( tr( "Sequence File Name" ) );
    textLabel3_10->setText( tr( "Sequence File :" ) );
    browseFile->setText( tr( "Browse" ) );
    groupBox38->setTitle( tr( "Parameter Stored in file " ) );
    buttonGroup13->setTitle( QString::null );
    radioButton28->setText( tr( "Last used parameter" ) );
    radioButton27->setText( tr( "Default parameter" ) );
    radioButton29->setText( tr( "Choose parameter from file" ) );
    textLabel1_28->setText( tr( "( The application copies the parameter file to its default \n"
"working directory when use selects the parameter file \n"
"and uses the file during the processing of the sequnce file.\n"
"No updation is made on the selected parameter file. )" ) );
    pushButton76_3->setText( tr( "Browse" ) );
    lineEdit64->setText( tr( "/applicationHome/defaultParameter.xml" ) );
    openSession->setText( tr( "Start Session" ) );
    groupBox6->setTitle( tr( "ORF COMPUTATION" ) );
    textLabel3->setText( tr( "NOT COMPUTED" ) );
    pushButton3->setText( tr( "Previous" ) );
    computeOrfNowPushButton->setText( tr( "Compute ORF now" ) );
    computeOrfNowPushButton->setAccel( QKeySequence( QString::null ) );
    groupBox31->setTitle( QString::null );
    buttonGroup4->setTitle( QString::null );
    radioButton7->setText( tr( "All Sequence" ) );
    radioButton8->setText( tr( "Specified Length" ) );
    groupBox5->setTitle( tr( "Specific Length for computation" ) );
    textLabel8->setText( tr( "Enter Minimum Sequence Length :" ) );
    textLabel9->setText( tr( "Enter Maximum Sequence Length :" ) );
    groupBox17_2_2->setTitle( QString::null );
    textLabel1_2->setText( tr( "Enter Start CODONs" ) );
    textLabel3_2->setText( tr( "(e.g ATG, GTG, ... )" ) );
    textLabel2_2->setText( tr( "Enter Stop CODONs" ) );
    pushButton27->setText( tr( "Clear" ) );
    pushButton28->setText( tr( "Clear" ) );
    textLabel3_2_2->setText( tr( "(e.g ATG, GTG, ... )" ) );
    pushButton14->setText( tr( "Next" ) );
    buttonGroup5->setTitle( QString::null );
    radioButton10->setText( tr( "Filter Sequences w.r.t best R-Statistic Value" ) );
    radioButton9->setText( tr( "Filter Sequences w.r.t Max ORF" ) );
    pushButton16_3->setText( tr( "Previous" ) );
    textEdit1->setText( tr( "Output of the general characteristics of the sequence to be displayed here" ) );
    checkBox2->setText( tr( "Save ORF and NON ORF in file" ) );
    pushButton25->setText( tr( "Start ORF Computation" ) );
    textLabel2_4->setText( QString::null );
    textLabel1_4->setText( QString::null );
    pushButton26->setText( tr( "Previous" ) );
    pushButton16_4->setText( tr( "Proceed for Random Sequence Generation" ) );
    textLabel2_3->setText( tr( "NOT COMPLETED" ) );
    textLabel1_3->setText( tr( "Random Sequence :" ) );
    textLabel1_5->setText( tr( "How many ORF's to be perturbed?\n"
"( number must be even )" ) );
    textLabel2_5->setText( tr( "Minimum ORF length" ) );
    textLabel3_5->setText( tr( "Maximum ORF length" ) );
    textLabel4_3->setText( tr( "How many random file do you want for each ORF?" ) );
    pushButton18->setText( tr( "Generate Random Sequence" ) );
    QWhatsThis::add( tabWidget2, tr( "<b>R-Statistic Computation</b><br><br>\n"
"Computation procedure based on R-Stat values" ) );
    textLabel2_6->setText( tr( "<u>Prediction based on R-Statistics computation</u>" ) );
    pushButton74_2->setText( tr( "Status" ) );
    groupBox9->setTitle( QString::null );
    textLabel3_3->setText( tr( "R-Statistic Computation" ) );
    textLabel1_18_3->setText( tr( "<font color=\"#5500ff\"><font size=\"-1\"></font></font>" ) );
    pushButton59->setText( tr( "Alter" ) );
    pushButton29->setText( tr( "Proceed..." ) );
    groupBox10->setTitle( QString::null );
    textLabel4_2->setText( tr( "Thresholding For R-Statistic" ) );
    textLabel1_18->setText( tr( "<font color=\"#5500ff\"><font size=\"-1\"></font></font>" ) );
    pushButton29_2->setText( tr( "Proceed..." ) );
    pushButton59_2->setText( tr( "Alter" ) );
    groupBox11->setTitle( QString::null );
    textLabel5_2->setText( tr( "Pattern Filtering by F-Ratio" ) );
    textLabel1_18_2->setText( tr( "<font color=\"#5500ff\"><font size=\"-1\"></font></font>" ) );
    pushButton29_3->setText( tr( "Proceed..." ) );
    pushButton59_2_2->setText( tr( "Alter" ) );
    groupBox12->setTitle( QString::null );
    textLabel6_2->setText( tr( "Nearest Neighbour Analysis" ) );
    textLabel1_18_2_2->setText( tr( "<font color=\"#5500ff\"><font size=\"-1\"></font></font>" ) );
    pushButton29_4->setText( tr( "Proceed..." ) );
    pushButton59_2_3->setText( tr( "Alter" ) );
    groupBox12_2->setTitle( QString::null );
    textLabel1_18_2_2_2->setText( tr( "<font color=\"#5500ff\"><font size=\"-1\"></font></font>" ) );
    textLabel6_2_2->setText( tr( "Thresholding Small Genes" ) );
    pushButton29_4_3->setText( tr( "Proceed..." ) );
    pushButton59_2_3_2->setText( tr( "Alter" ) );
    textLabel1_8->setText( tr( "<b>R-Statistic Computation</b>" ) );
    textLabel5_3->setText( tr( "Store R-Statistic value in file" ) );
    groupBox21->setTitle( QString::null );
    buttonGroup6->setTitle( QString::null );
    radioButton11->setText( tr( "Sequences of specific length" ) );
    radioButton10_2->setText( tr( "All Sequences" ) );
    groupBox25->setTitle( QString::null );
    textLabel1_21->setText( QString::null );
    textLabel1_22->setText( QString::null );
    textLabel4_5->setText( tr( "Enter maximum sequence length" ) );
    textLabel3_7->setText( tr( "Enter minimum sequence length" ) );
    lineEdit8->setText( QString::null );
    textLabel7_2->setText( tr( "Frequency value (should be multiple of 3)" ) );
    checkBox3->setText( tr( "Fixed set of frequency values" ) );
    pushButton27_2_5->setText( tr( "Previous" ) );
    lineEdit10->setText( tr( "Sequence_R_Statistics" ) );
    lineEdit45->setText( tr( "R-stat_Results" ) );
    textLabel1_16->setText( tr( "Folder name to store R-Statistic result\n"
"(If folder exist you will be warned)" ) );
    pushButton35->setText( tr( "Compute" ) );
    textLabel4_6->setText( tr( "<u>File Names :</u>" ) );
    textLabel1_10->setText( tr( "Enter threshold for R-Statistic for genes" ) );
    textLabel1_9->setText( tr( "Potential Gene Sequence :" ) );
    textLabel2_9->setText( tr( "Enter threshold for R-Statistic for non-genes" ) );
    groupBox27->setTitle( QString::null );
    checkBox4->setText( tr( "Default" ) );
    pushButton72->setText( tr( "Omega and Peak Location Inputs" ) );
    groupBox21_2->setTitle( QString::null );
    buttonGroup6_2->setTitle( QString::null );
    radioButton11_2->setText( tr( "Sequences of specific length" ) );
    radioButton10_2_2->setText( tr( "All Sequences" ) );
    groupBox25_2->setTitle( QString::null );
    textLabel3_7_3->setText( tr( "Enter minimum sequence length" ) );
    textLabel4_5_3->setText( tr( "Enter maximum sequence length" ) );
    textLabel2_8->setText( tr( "Potential Non-Gene Sequence :" ) );
    textLabel3_8->setText( tr( "Non-Potential Sequence :" ) );
    pushButton27_2_6->setText( tr( "Previous" ) );
    textLabel4_2_2->setText( tr( "<b>Thresholding For R-Statistic</b>" ) );
    lineEdit_File_PGS->setText( tr( "potential_Gene" ) );
    lineEdit_File_PNPS->setText( tr( "non_Potential_Sequence" ) );
    lineEdit_File_PNGS->setText( tr( "potential_NonGene" ) );
    lineEdit15->setText( tr( "0.75" ) );
    lineEdit16->setText( tr( "1.25" ) );
    pushButton35_2->setText( tr( "Compute" ) );
    pushButton75->setText( tr( "Random values" ) );
    textLabel5_2_2->setText( tr( "Pattern Filtering by F-Ratio" ) );
    textLabel1_11->setText( QString::null );
    textLabel2_10->setText( tr( "Threshold value :" ) );
    pushButton35_3->setText( tr( "Compute" ) );
    pushButton35_3->setAccel( QKeySequence( tr( "Ctrl+Down, Ctrl+Down, Ctrl+Down, Down" ) ) );
    pushButton27_2_7->setText( tr( "Previous" ) );
    checkBox9->setText( tr( "Skip" ) );
    pushButton27_2_8->setText( tr( "Previous" ) );
    groupBox3->setTitle( tr( "Nearest Neighbour Analysis" ) );
    textLabel7_3->setText( tr( "Enter upper trim percentage for Non-Gene average" ) );
    textLabel5_4->setText( tr( "Enter upper trim percentage for Gene average" ) );
    textLabel4_7->setText( tr( "Enter lower trim percentage for Gene average" ) );
    textLabel3_9->setText( tr( "Enter number of random samples" ) );
    textLabel6_3->setText( tr( "Enter lower trim percentage for Non-Gene average" ) );
    lineEdit19_6->setText( tr( "3" ) );
    lineEdit19_7->setText( tr( "3" ) );
    lineEdit19_4->setText( tr( "3" ) );
    lineEdit19_5->setText( tr( "3" ) );
    lineEdit19_3->setText( QString::null );
    buttonGroup8->setTitle( QString::null );
    textLabel1_12->setText( tr( "Potential Genes to be sampled" ) );
    textLabel2_11->setText( tr( "Potential Non-Genes to be sampled" ) );
    textLabel2_16->setText( tr( "Data entered in above fields are in  :" ) );
    radioButton16->setText( tr( "Count" ) );
    radioButton17->setText( tr( "%  Or" ) );
    textLabel1_13->setText( QString::null );
    pushButton35_4->setText( tr( "Compute" ) );
    checkBox8->setText( tr( "Use Auto Generated value" ) );
    textLabel2_12->setText( tr( "<b>Thresholding for Small Genes</b>" ) );
    textLabel1_20->setText( tr( "Enter R-Statistics for Threshold for Gene :" ) );
    pushButton27_2_5_2->setText( tr( "Previous" ) );
    lineEdit51->setText( tr( "0.75" ) );
    pushButton69->setText( tr( "Compute" ) );
    pushButton75_2->setText( tr( "Run" ) );
    buttonGroup11->setTitle( QString::null );
    radioButton21_2->setText( tr( "Compute with tri-neucleotide for all sequences" ) );
    radioButton22_2->setText( tr( "Compute with tetra-neucleotide for sequences with \n"
"length 60 to 300 and tri-neucleotide for all other sequences" ) );
    textLabel1_14->setText( tr( "<b><u>F-Ratio Computation based on</u></b>" ) );
    textLabel2_18->setText( tr( "<b><u>Random Sequence Generation Parameters</u></b>" ) );
    groupBox32->setTitle( QString::null );
    textLabel3_5_2->setText( tr( "Maximum ORF length" ) );
    textLabel2_5_2->setText( tr( "Minimum ORF length" ) );
    textLabel1_5_2->setText( tr( "How many ORF's to be perturbed?\n"
"( number must be even )" ) );
    textLabel2_17->setText( tr( "Enter number of mutation (in % of the length of sequence) :" ) );
    textLabel1_26->setText( tr( "Number of Swap ( in % of length of sequence):" ) );
    lineEdit4_3->setText( tr( "10" ) );
    textLabel4_3_2->setText( tr( "How many random sequence do you want for each ORF?" ) );
    swapPercent->setText( tr( "35" ) );
    mutPercent->setText( tr( "35" ) );
    textLabel4_2_2_3->setText( tr( "Completed Thresholding For R-Statistic computation" ) );
    pushButton76->setText( tr( "Next" ) );
    pushButton27_2_5_2_2->setText( tr( "Previous" ) );
    textLabel1_14_3->setText( QString::null );
    textLabel1_19->setText( tr( "<b>Thresholding Small Genes</b>" ) );
    tabWidget2->changeTab( R_Statistic, tr( "R-Statistics" ) );
    pushButton74_2_2->setText( tr( "Status" ) );
    textLabel1_6->setText( tr( "<u>Prediction Based on P-Value computation</u>" ) );
    groupBox14->setTitle( QString::null );
    textLabel1_7->setText( tr( "P-Value Computation" ) );
    textLabel2_13->setText( QString::null );
    pushButton59_3->setText( tr( "Alter" ) );
    pushButton29_5->setText( tr( "Proceed..." ) );
    groupBox15->setTitle( QString::null );
    textLabel2_7->setText( tr( "Thresholding For P-Value" ) );
    textLabel2_13_2->setText( QString::null );
    pushButton59_4->setText( tr( "Alter" ) );
    pushButton29_2_2->setText( tr( "Proceed..." ) );
    groupBox16->setTitle( QString::null );
    textLabel3_6->setText( tr( "Pattern Filtering by F-Ratio" ) );
    textLabel2_13_2_2->setText( QString::null );
    pushButton59_5->setText( tr( "Alter" ) );
    pushButton29_3_2->setText( tr( "Proceed..." ) );
    groupBox17->setTitle( QString::null );
    textLabel4_4->setText( tr( "Nearest Neighbour Analysis" ) );
    textLabel2_13_2_2_2->setText( QString::null );
    pushButton59_6->setText( tr( "Alter" ) );
    pushButton29_4_2->setText( tr( "Proceed..." ) );
    groupBox17_2->setTitle( QString::null );
    textLabel2_13_2_2_2_2->setText( QString::null );
    textLabel4_4_3->setText( tr( "Thresholding Small Genes" ) );
    pushButton59_7->setText( tr( "Alter" ) );
    pushButton29_5_2->setText( tr( "Proceed..." ) );
    textLabel1_16_2->setText( tr( "Folder name to store P-Value result\n"
"(If folder exist you will be warned)" ) );
    lineEdit45_2->setText( tr( "P-Value_Results" ) );
    textLabel7_2_2->setText( tr( "Frequency value (should be multiple of 3)" ) );
    checkBox3_2->setText( tr( "Fixed set of frequency values" ) );
    textLabel5_3_2->setText( tr( "Store P-value in file" ) );
    textLabel1_7_2->setText( tr( "<b>P-Value Computation</b>" ) );
    textLabel6_4->setText( tr( "Number of Monte-Carlo Replication :" ) );
    groupBox4->setTitle( QString::null );
    buttonGroup5_2->setTitle( QString::null );
    radioButton9_2->setText( tr( "All Sequences" ) );
    radioButton8_2->setText( tr( "Sequences of Specific length" ) );
    groupBox6_2->setTitle( QString::null );
    textLabel3_7_2->setText( tr( "Enter minimum sequence length" ) );
    textLabel4_5_2->setText( tr( "Enter maximum sequence length" ) );
    textLabel7_4->setText( tr( "Number of Swap ( in % of length of sequence):" ) );
    textLabel8_2->setText( tr( "Enter number of mutation (in % of the length of sequence) :" ) );
    pushButton27_2->setText( tr( "Previous" ) );
    lineEdit10_2->setText( tr( "Sequence_P_Value" ) );
    lineEdit29->setText( tr( "100" ) );
    lineEdit30->setText( tr( "35" ) );
    lineEdit31->setText( tr( "35" ) );
    pushButton35_5->setText( tr( "Compute" ) );
    textLabel2_7_2->setText( tr( "<b>Thresholding For P-Value</b>" ) );
    textLabel1_9_2->setText( tr( "Potential Gene Sequence :" ) );
    textLabel4_6_2->setText( tr( "<u>File Names :</u>" ) );
    groupBox21_2_2->setTitle( QString::null );
    buttonGroup6_2_2->setTitle( QString::null );
    radioButton11_2_2->setText( tr( "Sequences of specific length" ) );
    radioButton10_2_2_2->setText( tr( "All Sequences" ) );
    groupBox25_2_2->setTitle( QString::null );
    textLabel3_7_3_2->setText( tr( "Enter minimum sequence length" ) );
    textLabel4_5_3_2->setText( tr( "Enter maximum sequence length" ) );
    textLabel2_9_2->setText( tr( "Enter threshold for P-Value for non-genes ( in %)" ) );
    textLabel1_10_2->setText( tr( "Enter threshold for P-Value for genes ( in % )" ) );
    textLabel2_8_2->setText( tr( "Potential Non-Gene Sequence :" ) );
    textLabel3_8_2->setText( tr( "Non-Potential Sequence :" ) );
    pushButton27_2_2->setText( tr( "Previous" ) );
    lineEdit_File_PGS_2->setText( tr( "potential_Gene" ) );
    lineEdit_File_PNPS_2->setText( tr( "non_Potential_Gene" ) );
    lineEdit_File_PNGS_2->setText( tr( "potential_NonGene" ) );
    lineEdit16_2->setText( tr( "50" ) );
    lineEdit15_2->setText( tr( "35" ) );
    pushButton35_6->setText( tr( "Compute" ) );
    pushButton75_4->setText( tr( "Random values" ) );
    textLabel3_6_2->setText( tr( "<b>Pattern Filtering by F-Ratio</b>" ) );
    textLabel2_10_2->setText( tr( "Threshold value :" ) );
    pushButton27_2_3->setText( tr( "Previous" ) );
    textLabel1_11_2->setText( QString::null );
    checkBox9_2->setText( tr( "Skip" ) );
    pushButton35_7->setText( tr( "Compute" ) );
    textLabel4_4_2->setText( tr( "<b>Nearest Neighbour Analysis</b>" ) );
    pushButton27_2_4->setText( tr( "Previous" ) );
    pushButton35_8->setText( tr( "Compute" ) );
    groupBox3_2->setTitle( tr( "Nearest Neighbour Analysis" ) );
    textLabel1_13_2->setText( QString::null );
    textLabel3_9_2->setText( tr( "Enter number of random samples" ) );
    textLabel4_7_2->setText( tr( "Enter lower trim percentage for Gene average" ) );
    textLabel5_4_2->setText( tr( "Enter upper trim percentage for Gene average" ) );
    textLabel6_3_2->setText( tr( "Enter lower trim percentage for Non-Gene average" ) );
    textLabel7_3_2->setText( tr( "Enter upper trim percentage for Non-Gene average" ) );
    buttonGroup8_2->setTitle( tr( "Are the units in count or percentage?" ) );
    textLabel1_12_2->setText( tr( "Potential Genes to be sampled" ) );
    textLabel2_11_2->setText( tr( "Potential Non-Genes to be sampled" ) );
    textLabel2_16_2->setText( tr( "Data entered in above fields are in  :" ) );
    radioButton17_2->setText( tr( "% or" ) );
    radioButton16_2->setText( tr( "count" ) );
    lineEdit19_5_2->setText( tr( "3" ) );
    lineEdit19_6_2->setText( tr( "3" ) );
    lineEdit19_7_2->setText( tr( "3" ) );
    lineEdit19_4_2->setText( tr( "3" ) );
    checkBox8_2->setText( tr( "Use Auto Generated value" ) );
    textLabel4_2_2_3_2->setText( tr( "Completed Thresholding For P-Value computation" ) );
    pushButton27_2_2_2->setText( tr( "Previous" ) );
    pushButton76_2->setText( tr( "Next" ) );
    textLabel1_14_2->setText( QString::null );
    textLabel3_11->setText( tr( "<b>Re-thresholding for small gene</b>" ) );
    textLabel1_20_2->setText( tr( "Enter R-Statistics for Threshold for Gene :" ) );
    pushButton27_2_4_2->setText( tr( "Previous" ) );
    lineEdit51_2->setText( tr( "0.75" ) );
    pushButton69_2->setText( tr( "Compute" ) );
    pushButton75_2_2->setText( tr( "Run" ) );
    textLabel1_15->setText( tr( "<b>Nearest Neighbour Analysis for P-value is completed</b>" ) );
    pushButton27_2_4_2_2->setText( tr( "Previous" ) );
    buttonGroup11_2->setTitle( QString::null );
    radioButton21_2_2->setText( tr( "Compute with tri-neucleotide for all sequences" ) );
    radioButton22_2_2->setText( tr( "Compute with tetra-neucleotide for sequences with \n"
"length 60 to 300 and tri-neucleotide for all other sequences" ) );
    textLabel1_14_4->setText( tr( "<b><u>F-Ratio Computation based on</u></b>" ) );
    tabWidget2->changeTab( P_Value, tr( "P-Value" ) );
    textLabel1_17->setText( tr( "<u>Computation Results</u>" ) );
    groupBox8->setTitle( tr( "Results of P-Value" ) );
    pushButton50_3->setText( tr( "ORF+" ) );
    pushButton50_3->setAccel( QKeySequence( tr( "Ctrl+Up, Ctrl+Up, Ctrl+Up, Ctrl+Up" ) ) );
    pushButton50_2_4->setText( tr( "ORF-" ) );
    pushButton50_2_4->setAccel( QKeySequence( tr( "Ctrl+Up, Ctrl+Up, Ctrl+Up, Ctrl+Up" ) ) );
    pushButton71_2->setText( tr( "Result: Re-thresholding for small genes" ) );
    pushButton71_2->setAccel( QKeySequence( tr( "Ctrl+Up, Ctrl+Up, Ctrl+Up, Ctrl+Up" ) ) );
    groupBox7->setTitle( tr( "Results of R-Statistics" ) );
    pushButton71->setText( tr( "Result: Re-thresholding for small genes" ) );
    pushButton50->setText( tr( "ORF+" ) );
    pushButton50_2->setText( tr( "ORF-" ) );
    textLabel1_24->setText( tr( "<h3>Gene Evaluation</h3>" ) );
    groupBox29->setTitle( QString::null );
    buttonGroup2_2->setTitle( QString::null );
    checkBox4_2->setText( tr( "Include Hypothetical proteins" ) );
    groupBox29_2->setTitle( QString::null );
    checkBox7->setText( tr( "GeneMark" ) );
    textLabel2_15->setText( tr( "This program will generate and use data on predicted gene from \n"
"NCBI (http://www.ncbi.nlm.nih.gov) database and also from Gene \n"
"Prediction program.\n"
"\n"
"In addition would you like to obtain and compare results from \n"
"Glimmer and Gene Mark?" ) );
    checkBox6->setText( tr( "Glimmer" ) );
    groupBox30->setTitle( QString::null );
    textLabel1_25->setText( tr( "Sequence :" ) );
    textLabel3_12->setText( tr( "Result file +ORF" ) );
    textLabel4_8->setText( tr( "Result file for -ORF" ) );
    pushButton81->setText( tr( "Choose Result to evaluate" ) );
    textLabel2->setText( QString::null );
    pushButton2->setText( tr( "Proceed" ) );
    textEdit1_2->setText( QString::null );
    pushButton82->setText( tr( "Previous" ) );
    textLabel1_23->setText( tr( "Console" ) );
    pushButton4->setText( tr( "View output file" ) );
    buttonGroup2->setTitle( tr( "Computation And Analysis" ) );
    resultRadio->setText( tr( "Results" ) );
    radioButton20->setText( tr( "Evaluation" ) );
    orfRadio->setText( tr( "ORF Computation" ) );
    QToolTip::add( orfRadio, QString::null );
    QWhatsThis::add( orfRadio, tr( "<b>Open Reading Frame (ORF)</b><br>\n"
"An open reading frame (ORF) is a portion of an organism's genome which contains a sequence of bases that could potentially encode a protein. The start-points and end-points of a given ORF are not equivalent to the ends of the mRNA, but they are usually contained within the mRNA sequence. In a gene, ORFs are located between the start-code sequence (initiation codon) and the stop-code sequence (termination codon). ORFs are usually encountered when sifting through pieces of DNA while trying to locate a gene. Since there exist variations in the start-code sequence of organisms with altered genetic code, the ORF will be identified differently. A typical ORF finder will employ algorithms based on existing genetic codes (including the altered ones) and all possible reading frames.", "Test what is this" ) );
    predictionRadio->setText( tr( "Prediction and Analysis" ) );
    buttonGroup12->setTitle( tr( "Mode of Computation" ) );
    radioButton21->setText( tr( "Interactive" ) );
    QWhatsThis::add( radioButton21, tr( "<b>Interactive Mode </b><br/><br/>\n"
"Run program in interactive mode. In this mode program waits for input after completion of each part of computation." ) );
    computationPart->setText( QString::null );
    radioButton22->setText( tr( "Non Interactive" ) );
    QWhatsThis::add( radioButton22, tr( "<b>Non Interactive Mode of Computation</b><br/><br/>\n"
"Run program in non interactive mode. In this mode, program accepts all required values from the form fields and complete the computation procedure at one run." ) );
    textLabel1_27->setText( QString::null );
}

