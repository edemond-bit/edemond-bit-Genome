/****************************************************************************
** Form interface generated from reading ui file 'createDirectory/createDirectory.ui'
**
** Created: Sat Nov 27 12:05:37 2010
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.3   edited Nov 24 2003 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef FOLDER_CREATION_H
#define FOLDER_CREATION_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QPushButton;

class Folder_creation : public QDialog
{
    Q_OBJECT

public:
    Folder_creation( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~Folder_creation();

    QLabel* textLabel1;
    QLineEdit* lineEdit12;
    QPushButton* buttonOk;
    QPushButton* buttonCancel;

    QString currentDirectory;

public slots:
    virtual void buttonOk_clicked();
    virtual void reject();
    virtual void newSlot();

protected:
    QHBoxLayout* layout7;

protected slots:
    virtual void languageChange();

private:
    QLineEdit *__lineEdit;

    void init();

};

#endif // FOLDER_CREATION_H
