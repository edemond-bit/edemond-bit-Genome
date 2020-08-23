#include "pbc.h"
#include "qmessagebox.h"
#include <qmainwindow.h> 
#include <iostream>
#include <qpushbutton.h>
  QRect mr;
  
//constructor
pbc::pbc (QWidget* parent, const char* name , bool modal, WFlags fl ): QProgressDialog (parent,name,modal,fl)
{
  if(!name)
    setName("Progress controller..");
  __parent = parent;
  reset();  
  this->setCancelButton( new QPushButton( "Cancel", this ));
  //pd->setAutoClose(true);  
  abnormalTermination = false;
  mr=parent->geometry();
  /*QSize p=parent->frameSize();
  p.setWidth((int)(p.width()*.75));
  p.setHeight((int)(p.height()*.15));
  this->resize(p);*/
  //connect(this,SIGNAL(canceled()), SLOT(pbcWasCanceled()));
  this->setAutoReset( false );
  this->setAutoClose( false );
}
void pbc::setAbnormalTermination(){
    abnormalTermination = true;
    
}
void pbc::pbcResetTermination(){
abnormalTermination =false;
pbcReset();
}
void pbc::pbcReset(){

  currentTotalSteps = 100;
  currentProgress = 0;
  parentTotalSteps = 100;
  cumilativeProgress =0;
  processCount = 0;
 // abnormalTermination =false;
  this->reset();
  this->hide();
}


// total steps in percentage
bool pbc::addAChildProcess(int totalSteps, const QString label)
{
   if (this->abnormalTermination) return false;
   this->show();
  //std::cout<<"child process adding";
  processCount++;   
  parentTotalSteps = processCount>1?process[processCount-2].totalStepsAlloted:currentTotalSteps;
  process[processCount-1].totalStepsAlloted = (int)(((double)totalSteps/100)*(double)parentTotalSteps);
  process[processCount-1].label=new QString(label);
  currentProgress = 0;
  this->show();
  showProcessLabel();
  // relocate the dialog

  QRect tr=this->geometry();
   this->setGeometry(mr.x()+(mr.width()-tr.width())/2, mr.y()+(mr.height()-tr.height())/2,tr.width(), tr.height());
  
  //this->adjustSize();
  return true;

}
void pbc::updateCurrentProcessLabe(const QString label)
{
	updateProcessLabel(-1, label);

}
void pbc::updateProcessLabel(int processNo, const QString label)
{


   this->show();
   if(processNo < 0) {

     // use last process label
     process[processCount-1].label=new QString(label);
     this->show();
     showProcessLabel();
     
   }  else if(processNo<processCount)  {
   
     process[processNo].label=new QString(label);
     this->show();
     showProcessLabel();
     
   } 

   updateProgress();
 
}

void pbc::showProcessLabel(){
  int i;
  QString tmp("*");
  for(i=0;i<processCount;i++){
    tmp += "\n"+*process[i].label;
  }
  this->setLabelText (tmp);

  this->show();
}

// this method is called by child processes
void pbc::setProgressA(int steps, int totalSteps)
{
  int tmp= (int)(process[processCount-1].totalStepsAlloted  * ((double)steps/totalSteps));
  cumilativeProgress +=(tmp-currentProgress);
  currentProgress = tmp;
  this->setProgress(cumilativeProgress, currentTotalSteps);
//printf(" \n currentProgress = %d, cumilativeProgress = %d, currentTotalSteps = %d", currentProgress, cumilativeProgress, currentTotalSteps);

qApp->processEvents();
// next part to be called by timer latter
}

void pbc::deleteAllChildProcess(){
while(processCount>0){
this->deleteLastChildProcess();
}
  this->hide();
}


void pbc::deleteLastChildProcess(){
  pbc::setProgressA(100,100);
  if(processCount>0){
  processCount--;

  showProcessLabel();
    }
}
void pbc::updateProgress()
{

  qApp->processEvents();

}
bool pbc::pbcWasCanceled(){
   
  if (this->abnormalTermination) return true;
  if(this->wasCanceled()){

   this->abnormalTermination=true;
   return true;
 
  }else {
    return false;
  }
  //return false;
}

pbc::~pbc()
{
 
}
