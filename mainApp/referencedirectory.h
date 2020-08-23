/****************************************************************************
** Form interface generated from reading ui file 'referencedirectory.ui'
**
** Created: Sat Nov 27 12:05:37 2010
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.3   edited Nov 24 2003 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef REFERENCEDIRECTORY_H
#define REFERENCEDIRECTORY_H

#include <qvariant.h>
#include <qdialog.h>
#include "qfiledialog.h"
#include "qmessagebox.h"
#include "qdir.h"
#include "qdom.h"
#include "qapplication.h"
#include "qlineedit.h"

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QGroupBox;
class QSplitter;
class QLineEdit;
class QPushButton;

class ReferenceDirectory : public QDialog
{
    Q_OBJECT

public:
    ReferenceDirectory( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~ReferenceDirectory();

    QLabel* textLabel1;
    QGroupBox* groupBoxGene_Mark;
    QSplitter* splitter5;
    QLineEdit* lineEdit109_3;
    QPushButton* pushButton167_3;
    QGroupBox* groupBoxNCBI;
    QSplitter* splitter6;
    QLineEdit* lineEdit109;
    QPushButton* pushButton167;
    QGroupBox* groupBoxGlimmer;
    QSplitter* splitter3;
    QLineEdit* lineEdit109_2;
    QPushButton* pushButton167_2;
    QPushButton* pushButton170;
    QPushButton* pushButton171;

    QDomDocument ncbiDom;

    virtual QString selectFile( QString * );

public slots:
    virtual void getDatabasePath( QLineEdit * l, QString t );
    virtual void pushButton167_clicked();
    virtual void pushButton1_clicked();
    virtual void prepXML_FileList( QString * resultName, QString * dirName );
    virtual void pushButton167_2_clicked();
    virtual void pushButton167_3_clicked();
    virtual void pushButton170_clicked();
    virtual void checkAndCreateXML( int test );
    virtual void setOption( int n );
    virtual void pushButton171_clicked();
    virtual void ReferenceDirectory_destroyed( QObject * );

protected:

protected slots:
    virtual void languageChange();

private:
    void init();

};

#endif // REFERENCEDIRECTORY_H
