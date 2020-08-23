#include <qapplication.h>
#include "GenePrediction.h"
#include <qmainwindow.h>
#include <qstatusbar.h>
#include <qrect.h>
#include "F_Ratio.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Form1  *genePredictionDialog = new Form1;
    app.setMainWidget(genePredictionDialog);
    QFont f("san", 10 );
   // f.setBold( TRUE );
   // f.setItalic( TRUE );
    app.setFont( f, TRUE, "Form1");
   // app.setFont( f, TRUE, "QPopupMenu"); 

    QRect sh = genePredictionDialog->frameRect();
    genePredictionDialog->setMaximumWidth(sh.width());    
    genePredictionDialog->setMaximumHeight(sh.height()); 
    //genePredictionDialog->statusBar()->setSizeGripEnabled(false);
    genePredictionDialog->show();
    genePredictionDialog -> show();
    return app.exec();
  /*   
   QApplication app(argc, argv);
    QMainWindow *mw = new QMainWindow(0,0,Qt::WStyle_MinMax);
    Form1  *genePredictionDialog = new Form1(mw,"Gene Prediction") ;
  
    app.setMainWidget(mw);
    mw->setCentralWidget(genePredictionDialog);
        QRect sh = genePredictionDialog->frameRect();
        // fixed size window
      genePredictionDialog->setMinimumWidth(sh.width());    
      genePredictionDialog->setMinimumHeight(sh.height());    
       genePredictionDialog->setMaximumWidth(sh.width());    
      genePredictionDialog->setMaximumHeight(sh.height()); 
      
    mw->resize(sh.width(),
           sh.height()+mw->statusBar()->height());
       mw->setMaximumWidth(sh.width());    
       mw->setMaximumHeight(sh.height()); 
    mw->statusBar()->setSizeGripEnabled(false);
    mw->show();
    genePredictionDialog -> show();
    return app.exec();*/
} 
