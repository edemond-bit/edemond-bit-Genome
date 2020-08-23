/****************************************************************************
** Form interface generated from reading ui file 'F_Ratio.ui'
**
** Created: Sat Nov 27 12:05:37 2010
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.3   edited Nov 24 2003 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef F_RATIO_H
#define F_RATIO_H

#include <qvariant.h>
#include <qdialog.h>
#include "paramManager.h"

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QPushButton;
class QButtonGroup;
class QRadioButton;

class F_Ratio : public QDialog
{
    Q_OBJECT

public:
    F_Ratio( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~F_Ratio();

    QPushButton* buttonOk;
    QButtonGroup* buttonGroup11;
    QRadioButton* radioButton21;
    QRadioButton* radioButton22;

    paramManager *paramMg;
    int methodType;

    virtual void setDefaultValue();

public slots:
    virtual void initialize();
    virtual void radioButton21_clicked();
    virtual void radioButton22_clicked();
    virtual void buttonOk_pressed();

protected:
    QHBoxLayout* Layout1;
    QSpacerItem* Horizontal_Spacing2;

protected slots:
    virtual void languageChange();

};

#endif // F_RATIO_H
