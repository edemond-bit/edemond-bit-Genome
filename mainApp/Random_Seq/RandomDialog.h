/****************************************************************************
** Form interface generated from reading ui file 'Random_Seq/RandomDialog.ui'
**
** Created: Sat Nov 27 12:05:37 2010
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.3   edited Nov 24 2003 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef RANDOMDIALOG_H
#define RANDOMDIALOG_H

#include <qvariant.h>
#include <qdialog.h>
#include "paramManager.h"

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QCheckBox;
class QGroupBox;
class QLabel;
class QPushButton;
class QLineEdit;

class RandomDialog : public QDialog
{
    Q_OBJECT

public:
    RandomDialog( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~RandomDialog();

    QCheckBox* checkBox9_2;
    QGroupBox* groupBox32;
    QLabel* textLabel1_5;
    QLabel* textLabel4_3;
    QLabel* textLabel2;
    QLabel* textLabel1;
    QPushButton* buttonCreateRand;
    QPushButton* buttonCancel;
    QLabel* textLabel1_2;
    QLineEdit* swapPercent;
    QLineEdit* mutPercent;
    QLineEdit* lineEdit1;
    QLineEdit* lineEdit4;
    QLineEdit* lineEdit3;
    QLabel* textLabel2_5;
    QLineEdit* lineEdit2;
    QLabel* textLabel3_5;
    QCheckBox* checkBox9;

    paramManager *paramMg;
    char seq_work_dir[200];
    int max_range_random;
    int min_range_random;
    int CountBigGene;
    int CountBigNGene;

public slots:
    virtual void lineEdit2_textChanged( const QString & );
    virtual void lineEdit3_textChanged( const QString & );
    virtual void lineEdit1_textChanged( const QString & );
    virtual void purtrub_value_default();
    virtual void buttonCreateRand_pressed();
    virtual void buttonCreateRand_released();

protected:
    QHBoxLayout* Layout1;
    QSpacerItem* Horizontal_Spacing2;

protected slots:
    virtual void languageChange();

private:
    void init();

};

#endif // RANDOMDIALOG_H
