#ifndef __PBC
#define __PBC

#include <qprogressdialog.h>
#include <qapplication.h>
class pbc:public QProgressDialog
{
     Q_OBJECT

 private:
//  QProgressDialog *pd;
  int currentTotalSteps;
  int currentProgress;
  int processCount;
  int cumilativeProgress;
  int parentTotalSteps;
  int abnormalTermination;
  QWidget *__parent;
  struct processStack{    // this entry will be performed by parent process
    int totalStepsAlloted; //(in %) total step alloted to parent for this process
    const QString *label;
  };
  

  struct processStack process[10];
  //methods
 
 
 public:
  pbc( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = WStyle_DialogBorder );
  ~pbc();
  bool addAChildProcess(int totalSteps, const QString);
  void deleteLastChildProcess();
  void setProgressA(int steps,int totalSteps);
  void updateProgress();
  void showProcessLabel();
  void deleteAllChildProcess();
  bool pbcWasCanceled();
  void pbcReset();
  void pbcResetTermination();
  void setAbnormalTermination();
  void updateProcessLabel(int processNo, const QString label);
  void updateCurrentProcessLabe(const QString label);
};


#endif

