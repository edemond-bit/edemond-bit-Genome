/****************************************************************************
** Form interface generated from reading ui file 'Prediction/get_Omega_PeakParam/Omega_Peak_Inputs.ui'
**
** Created: Sat Nov 27 12:05:37 2010
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.3   edited Nov 24 2003 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef OMEGA_PEAK_INPUTS_H
#define OMEGA_PEAK_INPUTS_H

#include <qvariant.h>
#include <qpixmap.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QPushButton;
class QLineEdit;
class QLabel;
class QFrame;
class QGroupBox;
class Form1;

class Omega_Peak_Inputs : public QDialog
{
    Q_OBJECT

public:
    Omega_Peak_Inputs( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~Omega_Peak_Inputs();

    QPushButton* cmdOmegaNum;
    QLineEdit* txtOmegaNum;
    QLabel* lblOmegaNum;
    QFrame* frame4;
    QPushButton* cmdOK;
    QPushButton* cmdCancel;
    QGroupBox* frmGeneral;
    QGroupBox* grBox9;
    QLabel* lblLClipFrom;
    QLabel* lblRClipFrom;
    QLabel* lblClipTo;
    QLabel* lblClipTo_2;
    QLabel* lblPeakValue;
    QLineEdit* txtPeakValue;
    QLineEdit* txtLClipTo;
    QLineEdit* txtLClipFrom;
    QLineEdit* txtRClipFrom;
    QLineEdit* txtRClipTo;
    QGroupBox* grBox14;
    QLabel* lblOmega;
    QLabel* lblToOmega;
    QLabel* lblWithOmega;
    QLineEdit* txtWith;
    QLineEdit* txtEnd;
    QLineEdit* txtInitOmega;

    double *To1;
    int isAdaptive;
    bool isGet_OmegaPeak;
    double *From2;
    double *From1;
    double *To2;
    double *PeakValue;
    double *Omega_From;
    double *Omega_To;
    double *Omega_Interval;

public slots:
    virtual void cmdOmegaNum_clicked();
    virtual void txtOmegaNum_textChanged( const QString & Num );
    virtual void setOmega();
    virtual void resetOmega();
    virtual void setRStatistic();
    virtual void resetRStatistic();
    virtual void txtLClipFrom_textChanged( const QString & Num );
    virtual void txtLClipTo_textChanged( const QString & Num );
    virtual void txtRClipFrom_textChanged( const QString & Num );
    virtual void txtRClipTo_textChanged( const QString & Num );
    virtual void txtPeakValue_textChanged( const QString & Num );
    virtual void closeEvent( QCloseEvent * event );
    virtual void txtInitOmega_textChanged( const QString & Num );
    virtual void txtEnd_textChanged( const QString & Num );
    virtual void txtWith_textChanged( const QString & Num );
    virtual void cmdOK_clicked();
    virtual void cmdCancel_clicked();
    virtual void ErrorSlot( int Status );
    virtual void FileErrorSlot( QString Msg );
    virtual void Omega_Peak_Inputs_destroyed( QObject * );

protected:

protected slots:
    virtual void languageChange();

private:
    bool closeFlag;
    QString DirPath;

    QPixmap image0;

    void init();
    void destroy();

};

#endif // OMEGA_PEAK_INPUTS_H
