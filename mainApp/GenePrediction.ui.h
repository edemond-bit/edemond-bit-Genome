/****************************************************************************
 ** ui.h extension file, included from the uic-generated form implementation.
 **
 ** If you want to add, delete, or rename functions or slots, usen
 ** Qt Designer to update this file, preserving your code.
 **
 ** You should not define a constructor or destructor in this file.
 ** Instead, write your code in functions called init() and destroy().
 ** These will automatically be called by the form's cFonstructor and
 ** destructor.
 *****************************************************************************/
#include <qfiledialog.h>
#include <qlineedit.h>
#include <stream.h>
#include <stdio.h>
#include <qapplication.h>
#include <string.h>
#include <qmessagebox.h> 
#include <qprogressdialog.h>
#include <qfile.h>
#include <qtooltip.h>
#include <qwhatsthis.h> 
#include <qtimer.h>
#include "orf/orf.h"
#include "ProgressBarController/pbc.h"
#include "statusManager/statusManager.h"
#include "createDirectory/createDirectory.h"
#include "File_Manager/File_Manager.h"
#include "Static_Lib/Gene_Prediction_Lib.h"
#include "statusManager/statusManager.h"
#include "Prediction/Gene_Prediction_File.h"
#include "F_Ratio.h"
#include "referencedirectory.h"
#include "Prediction/get_Omega_PeakParam/Omega_Peak_Inputs.h"
#include "Gene_evaluation/evaluation.h"
#include "sessionManager/sessionManager.h"
ORF rf;
Evaluation eval;
char *sequenceName;
int _elapsedDay = 0;
//bool interactiveMode;

void Form1::apply(){
 
}
/////////////////////

void Form1::init(){
 appl = this;
 mainPbc=new pbc(this,"Progress bar",true);
 fm = new File_Manager();
 sessionMg= new sessionManager(this,fm);
 // default is interactive mode
 interactiveMode=true; 
 
 
 InitializeApplication();
 initEntryForm();
 
}
void Form1::initializeFields()
{
 
 radioButton21->setChecked(true);
 orfRadio->setChecked(true);
 predictionRadio->setChecked(false);
 resultRadio->setChecked(false);
 radioButton20->setChecked(false);
 //ORF calculation
 //---------------
 radioButton7_clicked();
 
 //spinBox1->setValue(0);
 lineEdit61->setText("0");
 //spinBox2->setValue(0);
 lineEdit62->setText("0");
 this->lineEdit3->setText("");
 lineEdit4->setText("");
 radioButton9->setChecked (true);
 checkBox2->setChecked (true);
 
 //R-Stat
 //=============================================================
 //RStat calculation
 //------------------
 radioButton10_2->setChecked (true); 
 lineEdit8->setText("");
 lineEdit9->setText("");
 lineEdit10->setText("Sequence_R_Statistics"); //default value
 checkBox3->setChecked (false);
 lineEdit11->setText("");
 lineEdit45->setText("R-stat_Results");
 
 //Thresholding
 //------------
 lineEdit_File_PGS->setText("potential_Gene");
 lineEdit_File_PNGS->setText("potential_NonGene");
 lineEdit_File_PNPS->setText("non_Potential_Sequence");
 
 radioButton10_2_2->setChecked(true);
 lineEdit8_3->setText("");
 lineEdit9_3->setText("");
 checkBox4->setChecked (true);
 lineEdit15->setText("0.75");
 lineEdit16->setText("1.25");
 
 
 //F-Ratio
 //-------
 lineEdit17->setText("");
 
 //Neighberhood
 //------------
 lineEdit19->setText("");
 lineEdit19_2->setText("");
 lineEdit19_3->setText("");
 lineEdit19_4->setText("");
 lineEdit19_5->setText("");
 lineEdit19_6->setText("");
 lineEdit19_7->setText("");
 radioButton16->setChecked(true);
 lineEdit51->setText("");
 //=====================================================================
 
 //P-Val 
 //====================================================================
 //P-value calculation
 ///===================
 radioButton9_2->setChecked(true);
 lineEdit8_2->setText("");
 lineEdit9_2->setText("");
 lineEdit10_2->setText("Sequence_P_Value");
 checkBox3_2->setChecked(false);
 lineEdit11_2->setText("");
 lineEdit45_2->setText("P-Value_Results");
 lineEdit29->setText("");
 lineEdit30->setText("");
 lineEdit31->setText("");
 
 
 //Threshold
 //-----------
 lineEdit_File_PGS_2->setText("potential_Gene");
 lineEdit_File_PNGS_2->setText("potential_NonGene");
 lineEdit_File_PNPS_2->setText("non_Potential_Sequence");
 radioButton10_2_2_2->setChecked("true");
 lineEdit8_3_2->setText("");
 lineEdit9_3_2->setText("");
 lineEdit15_2->setText("35");
 lineEdit16_2->setText("50");
 
 
 //F-Ratio
 //--------
 lineEdit17_2->setText("");
 
 //Neighbour
 //----------
 
 lineEdit19_8->setText("");
 lineEdit19_2_2->setText("");
 lineEdit19_3_2->setText("");
 lineEdit19_4_2->setText("");
 lineEdit19_5_2->setText("");
 lineEdit19_6_2->setText("");
 lineEdit19_7_2->setText("");
 lineEdit19_3_2->setText("");
 
 //re-thresholding
 //---------------
 lineEdit51_2->setText("");
 pushButton74_2->setEnabled(false);
}






///// Non-interactive process calling
void Form1::non_interactive_rstat_call()
{
 widgetStack5->raiseWidget(0);
 /// validate and save the input value to parameter.xml
 paramMg ->updateFinalDom();  //update parameter fields of Form1
 //
 
 
 pushButton35_clicked(); // computation r-statistics
 
 setGUIState(); 
 if(mainPbc->pbcWasCanceled()) return;
 pushButton35_2_clicked();//threshold
 setGUIState();
 // call  F-ratio computation part if it is not skipped pushButton35_3_clicked()
 if (!checkBox9->isChecked()){
  pushButton29_3_released();
  pushButton35_3_clicked();
  
 } else {
  sManager->setProcessState(6,"5");
 }
 
 if(mainPbc->pbcWasCanceled()) return;
 pushButton35_4_clicked(); // nearest neighbour calculation
 
 if(mainPbc->pbcWasCanceled()) return;
 pushButton69_clicked(); // Threshold for small gene
 setGUIState();
 if(mainPbc->pbcWasCanceled()) return;
 
}
///// Non-interactive process calling for P-Value
void Form1::non_interactive_pval_call()
{
 QMessageBox::warning(appl,"Pvalue Non interactive","Pvaue for non interactive mode has been started");
 widgetStack6->raiseWidget(0);
 /// validate and save the input value to parameter.xml
 paramMg ->updateFinalDom();  //update parameter fields of Form1
 //
 
 
 pushButton35_5_clicked(); // computation p_val
 
 setGUIState(); 
 if(mainPbc->pbcWasCanceled()) return;
 pushButton35_6_clicked();//threshold
 setGUIState();
 // call  F-ratio computation part if it is not skipped pushButton35_3_clicked()
 if (!checkBox9_2->isChecked()){
  //pushButton29_3_released();
  pushButton35_7_clicked();
  
 } else {
  sManager->setProcessState(6,"5");
 }
 
 if(mainPbc->pbcWasCanceled()) return;
 pushButton35_8_clicked(); // nearest neighbour calculation
 
 if(mainPbc->pbcWasCanceled()) return;
 pushButton69_2_clicked(); // Threshold for small gene
 setGUIState();
 if(mainPbc->pbcWasCanceled()) return;
 /*   */
}

//void Form1::save_parameters_to_xml(){
//if(choice == 1){ 
///save_RStat_parameters_to_xml();
//} else if(choice==2){
//save_PVal_parameters_to_xml();
//}
//IOmanager->writeDom(QString(seq_work_dir)+QString("/parameters.xml"));
// QMessageBox::warning(appl,"title",lineEdit8->text());
//}

//Save R-Stat parameters to file
//void Form1::save_RStat_parameters_to_xml(){
// if(radioButton11->isChecked()){ 
//  IOmanager->setSequenceLengthRStat (lineEdit8->text(), lineEdit9->text());
// }else {
//  IOmanager->setSequenceLengthRStatAll(); 
// }
//}
// Save P-Value parameters to file
//void Form1::save_PVal_parameters_to_xml(){
//}
void Form1::InitializeApplication(){
 //frame3->hide();
 initializeFields();
 this->frame3->setEnabled(false);
 
 //initialize ORF object
 
 rf.setFilterSequence_wrt(1);
 rf.saveIntermediateData_toFile(false);
 
 lineEdit3->setText("ATG, GTG");
 lineEdit4->setText("TAG, TGA, TAA");
 pushButton3->setEnabled(false);
 computeOrfNowPushButton->setEnabled(true);
 
 //R-Statistic Computation widget initialization
 choice  = 1;
 textLabel7_2->setDisabled(true);
 lineEdit11->setDisabled(true);
 groupBox25_2_2->setEnabled(false);
 groupBox25_2->setEnabled(false);
 // Initialize_Namespace();
 
 
 openSession->setEnabled(false);
 closeSession->setEnabled(false); 
 frame6->setGeometry(frame3->geometry());
 
 frame6->raise();
 frame6->show();
 
}
void Form1::Initialize_Namespace(){
 methodType = 1;
 
 // Initialize nameSpaces
 sprintf(nameSpace[0],"%s/nameSpace_R",seq_work_dir);
 //strcpy(misc[0],"misc_R");
 sprintf(misc[0],"%s/misc_R",seq_work_dir);
 // strcpy(nameSpace[1],"nameSpace_P");
 sprintf(nameSpace[1],"%s/nameSpace_P",seq_work_dir);
 // strcpy(misc[1],"misc_P");
 sprintf(misc[1],"%s/misc_P",seq_work_dir);
 //strcpy(f_Ratio_File[0],"f_Ratio_R");
 sprintf(f_Ratio_File[0],"%s/f_Ratio_R",seq_work_dir);
 //strcpy(filtered_Pattern[0],"filtered_Pattern_R");
 sprintf(filtered_Pattern[0],"%s/filtered_Pattern_R1",seq_work_dir);
 sprintf(filtered_Pattern[1],"%s/filtered_Pattern_R2",seq_work_dir);
 sprintf(f_Ratio_File[1],"%s/f_Ratio_P",seq_work_dir);
 sprintf(filtered_Pattern[2],"%s/filtered_Pattern_P1",seq_work_dir);
 sprintf(filtered_Pattern[3],"%s/filtered_Pattern_P2",seq_work_dir);
 
 qApp->processEvents();
}

//  browseFile_clicked() is the slot respnse on signal from browse button
void Form1::browseFile_clicked()
{
 QFileDialog* fd = new QFileDialog( this );
 
 if ( fd->exec() == QDialog::Accepted ){
  
  
  // fd -> setDir("$home");
  QString s    = fd->selectedFile();
  chooseSeq->setText(s);
  if(strcmp(s,"")!=0)   openSession->setEnabled(true);
 }       
 // sequenceFileName->setText(s);  
}

void Form1::acceptPath_Ready_for_Computation(){
 DIR *dir;
 QString query("");
 char * tmp=(char *)calloc(420,sizeof(char));
 char *token=(char *)calloc(420,sizeof(char));
 frame3->show();
 frame6->hide();
 this->frame3->setEnabled(true); 
 //set sequenceName variable 
 tmp=strcpy(tmp,   (const char *)sequenceFileName->text());
 Gene_Pred::search_char('/',2,&token,tmp);
 sequenceName=(char *)calloc(400, sizeof(char));
 sprintf(sequenceName,"%s",token);
 
 Initialize_Namespace();
 // This part is required to assign to file Manager
 if((dir = opendir(seq_work_dir)) == NULL)
 {
  query = QString("mkdir ")+QString(seq_work_dir);
  system(query);
 }
 mainPath=(char *)malloc(sizeof(char)*400);
 sprintf(mainPath,"%s/Path",seq_work_dir);
 
 QFile file( (QString)mainPath );
 if ( file.open( IO_WriteOnly ) ) {
  QTextStream stream( &file );
  stream <<    sequenceFileName->text() << "\n";
  file.close();
 }
 
 
 sManager = new statusManager(QString(seq_work_dir)+QString("/status.xml"), this,fm);
 
 // initalize orf with application parameters
 rf.setAppParameters(mainPbc, sManager);
 
 
 
 
 orfRadio_clicked();
 
 
 
 
 
}

void Form1::updateStatusView(){
 FILE *fp;
 int processState=0;
 bool rstat_neib_state=false;
 bool pval_neib_state=false;   
 char tmp_str[200];
 pushButton75_2->setHidden(true);
 
 
 
 
 //
 QString stateDescription("");
 pixmapLabel1_1->setEnabled(false);
 pixmapLabel1_2->setEnabled(false);
 pixmapLabel1_3->setEnabled(false);
 pixmapLabel1_4->setEnabled(false);
 pixmapLabel2_1->setEnabled(false);
 pixmapLabel2_2->setEnabled(false);
 pixmapLabel2_3->setEnabled(false);
 pixmapLabel2_4->setEnabled(false);
 //check ORF computation status
 sManager->getProcessState(1,&processState,&stateDescription);
 textLabel3->setText(stateDescription);
 predictionRadio->setEnabled(false);
 resultRadio->setEnabled(false);
 if(processState !=100){
  widgetStack->raiseWidget(1);
  sManager->setProcessState(3,"0");
  sManager->setProcessState(4,"0");
  sManager->setProcessState(5,"0");
  sManager->setProcessState(6,"0");
  sManager->setProcessState(7,"0");
  sManager->setProcessState(8,"0");
  sManager->setProcessState(9,"0");
  sManager->setProcessState(10,"0");
  sManager->setProcessState(11,"0");
  sManager->setProcessState(12,"0");
  sManager->setProcessState(13,"0");
  // Non interactive radio option is false
  radioButton22->setEnabled(false);
  radioButton22->setChecked(false);
  radioButton21->setChecked(true);
 } else {
widgetStack->raiseWidget(0);  
  // non interactive radio option is true     
  predictionRadio->setEnabled(true);
  radioButton22->setEnabled(true);
  sprintf(tmp_str,"%s/orf_max_min",seq_work_dir);
  
  fp = fopen(tmp_str,"r"); 
  
  if(fp){
   
   fscanf(fp,"%d\t%d", &_min_range, &_max_range);
   fclose(fp);
  }
  // R-Stat field initalizationwhen computation not completed
  // QMessageBox::warning(0,"check", QString(" Rstat min field value")+lineEdit8->text());
  if(strcmp((lineEdit8->text()),"")==0){
   // text field is not initalized means data has not received from inputParam.xml
   lineEdit8->setText(QString("%1").arg(_min_range,0,10));
   lineEdit9->setText(QString("%1").arg(_max_range,0,10));
   
   // R-Stat Thresholding field initialization
   sprintf(tmp_str,"%s/orf_max_min_R",seq_work_dir);     
   fp = fopen(tmp_str,"r");
   if(fp){
    fscanf(fp,"%d\t%d", &_min_range_r, &_max_range_r);
    fclose(fp);
    
    lineEdit8_3->setText(QString("%1").arg(_min_range_r,0,10));
    lineEdit9_3->setText(QString("%1").arg(_max_range_r,0,10));
   }
  }  
  // P-value field initalization
  if(strcmp((lineEdit8_2->text()),"")==0){
   // text field is not initalized means data has not received from inputParam.xml
   lineEdit8_2->setText(QString("%1").arg(_min_range,0,10));
   lineEdit9_2->setText(QString("%1").arg(_max_range,0,10));  
   // p-value Thresholding field initialization
   sprintf(tmp_str,"%s/orf_max_min_P",seq_work_dir);
   fp = fopen(tmp_str,"r");
   if(fp){
    fscanf(fp,"%d\t%d", &_min_range_p, &_max_range_p);
    fclose(fp);
    lineEdit8_3_2->setText(QString("%1").arg(_min_range_p,0,10));
    lineEdit9_3_2->setText(QString("%1").arg(_max_range_p,0,10));
    
    
   }   
  }
 }
 
 
 
 sManager->getProcessState(4,&processState,&stateDescription);
 textLabel1_18_3->setText(stateDescription);
 if(processState!=100){
  sManager->setProcessState(5,"0");
  textLabel1_18_3->setPaletteForegroundColor(qRgb(170,0,0));
  pushButton59->setEnabled(false);
  pushButton29->setEnabled(true);
  groupBox10->setEnabled(false);
 }else{
  groupBox10->setEnabled(true);
  pixmapLabel1_1->setEnabled(true);
  textLabel1_18_3->setPaletteForegroundColor(qRgb(0,170,0));
  pushButton59->setEnabled(true);
  pushButton29->setEnabled(false);
 }
 
 
 //set for R-thresholdingtabWidget2
 sManager->getProcessState(5,&processState,&stateDescription);
 textLabel1_18->setText(stateDescription);
 if(processState==100){
  groupBox11 ->setEnabled(true);
  groupBox12->setEnabled(true);
  
  pixmapLabel1_2->setEnabled(true);
  textLabel1_18->setPaletteForegroundColor(qRgb(0,170,0));
  pushButton29_2->setEnabled(false);
  pushButton59_2->setEnabled(true);
  
 }else{
  groupBox11->setEnabled(false);
  groupBox12->setEnabled(false);
  textLabel1_18->setPaletteForegroundColor(qRgb(170,0,0));
  pushButton29_2->setEnabled(true);
  pushButton59_2->setEnabled(false);
 }
 // set for R-stat pattern Filtering
 sManager->getProcessState(6,&processState,&stateDescription);
 //QMessageBox::warning(0,"warning", stateDescription);
 textLabel1_18_2->setText(stateDescription);
 if(processState==100){     
  groupBox9 ->setEnabled(true);
  groupBox11->setEnabled(true);
  pixmapLabel1_3->setEnabled(true);
  textLabel1_18_2->setPaletteForegroundColor(qRgb(0,170,0));
  pushButton29_3->setEnabled(false);
  pushButton59_2_2->setEnabled(true);
  
  
 } else {
  textLabel1_18_2->setPaletteForegroundColor(qRgb(170,0,0));
  pushButton29_3->setEnabled(true);
  pushButton59_2_2->setEnabled(false);
 }
 // set for R-stat neighberhood calcuation
 sManager->getProcessState(7,&processState,&stateDescription);
 textLabel1_18_2_2->setText(stateDescription);
 if(processState==100){
  rstat_neib_state=true;
  pixmapLabel1_4->setEnabled(true);
  groupBox12_2->setEnabled(true);
  textLabel1_18_2_2->setPaletteForegroundColor(qRgb(0,170,0));
  pushButton29_4->setEnabled(false);
  pushButton59_2_3->setEnabled(true);
  groupBox7->setEnabled(true);
  
 }else{
  rstat_neib_state=false;
  textLabel1_18_2_2->setPaletteForegroundColor(qRgb(170,0,0));
  groupBox12_2->setEnabled(false);
  
  groupBox7->setEnabled(false);
  pushButton29_4->setEnabled(true);
  pushButton59_2_3->setEnabled(false);
  
  
 }
 
 
 // set for R-stat thresholding for small Gene calculation
 sManager->getProcessState(8,&processState,&stateDescription);
 
 textLabel1_18_2_2_2->setText(stateDescription);
 if(processState==100){
  pixmapLabel1_5->setEnabled(true);
  textLabel1_18_2_2_2->setPaletteForegroundColor(qRgb(0,170,0));
  pushButton29_4_3->setEnabled(false);
  pushButton59_2_3_2->setEnabled(true);
  pushButton71->setEnabled(true);
  
  
 }else{
  textLabel1_18_2_2_2->setPaletteForegroundColor(qRgb(170,0,0));
  pixmapLabel1_5->setEnabled(false);
  pushButton29_4_3->setEnabled(true);
  pushButton59_2_3_2->setEnabled(false);
  pushButton71->setEnabled(false);
  
 }
 
 
 
 /////////////////////////// P-value controls state /////////////////////////////
 //set for P-value computation
 sManager->getProcessState(9,&processState,&stateDescription);
 textLabel2_13->setText(stateDescription);
 if(processState!=100){
  groupBox15->setEnabled(false);
  groupBox16->setEnabled(false);
  groupBox17->setEnabled(false);
  pixmapLabel2_1->setEnabled(false);
  sManager->setProcessState(10,"0");
  pushButton29_5->setEnabled(true);
  pushButton59_3->setEnabled(false);
  textLabel2_13->setPaletteForegroundColor(qRgb(170,0,0));
 }else{
  groupBox15->setEnabled(true);
  pixmapLabel2_1->setEnabled(true);
  pushButton29_5->setEnabled(false);
  pushButton59_3->setEnabled(true);
  textLabel2_13->setPaletteForegroundColor(qRgb(0,170,0));
 }
 //set for P-thresholding
 sManager->getProcessState(10,&processState,&stateDescription);
 textLabel2_13_2->setText(stateDescription);
 if(processState==100){
  groupBox16->setEnabled(true);
  groupBox17->setEnabled(true);
  pixmapLabel2_2->setEnabled(true);
  pushButton29_2_2->setEnabled(false);
  pushButton59_4->setEnabled(true);
  textLabel2_13_2->setPaletteForegroundColor(qRgb(0,170,0));
 }else{
  
  groupBox16->setEnabled(false);
  groupBox17->setEnabled(false);
  pixmapLabel2_2->setEnabled(false);
  sManager->setProcessState(11,"0");
  sManager->setProcessState(12,"0"); 
  pushButton29_2_2->setEnabled(true);
  pushButton59_4->setEnabled(false);
  textLabel2_13_2->setPaletteForegroundColor(qRgb(170,0,0));
 }
 // set for P-value pattern Filtering
 sManager->getProcessState(11,&processState,&stateDescription);
 textLabel2_13_2_2->setText(stateDescription);
 if(processState==100){
  pixmapLabel2_3->setEnabled(true);
  textLabel2_13_2_2->setPaletteForegroundColor(qRgb(0,170,0));
  pushButton29_3_2->setEnabled(false);
  pushButton59_5->setEnabled(true);
 }else{
  pushButton29_3_2->setEnabled(true);
  pushButton59_5->setEnabled(false);
  textLabel2_13_2_2->setPaletteForegroundColor(qRgb(170,0,0));
 }
 // set for P-stat neighberhood calcuation
 sManager->getProcessState(12,&processState,&stateDescription);
 textLabel2_13_2_2_2->setText(stateDescription);
 if(processState==100){
  pval_neib_state=true;
  groupBox17_2->setEnabled(true);
  pixmapLabel2_4->setEnabled(true);
  textLabel2_13_2_2_2->setPaletteForegroundColor(qRgb(0,170,0));
  pushButton29_4_2->setEnabled(false);
  pushButton59_6->setEnabled(true);
  groupBox8->setEnabled(true);
  
  if(!radioButton20->isEnabled()) radioButton20->setEnabled(true);
 }else{
  pval_neib_state=false;
  textLabel2_13_2_2_2->setPaletteForegroundColor(qRgb(170,0,0));
  groupBox17_2->setEnabled(false);
  pushButton29_4_2->setEnabled(true);
  pushButton59_6->setEnabled(false);
  groupBox8->setEnabled(false);
  
  
 }
 // result and evaluation radio_button state change
 if( rstat_neib_state || pval_neib_state){
  resultRadio->setEnabled(true);
  radioButton20->setEnabled(true);
 }else{
  resultRadio->setEnabled(false);
  radioButton20->setEnabled(false);
 }
 
 // set for P-value re-trhesholding for small gene
 sManager->getProcessState(13,&processState,&stateDescription);
 textLabel2_13_2_2_2_2->setText(stateDescription);
 if(processState==100){
  //groupBox17_2->setEnabled(true);
  pixmapLabel2_5->setEnabled(true);
  textLabel2_13_2_2_2_2->setPaletteForegroundColor(qRgb(0,170,0));
  pushButton29_5_2->setEnabled(false);
  pushButton59_7->setEnabled(true);
  pushButton71_2->setEnabled(true);
  //radioButton20->setEnabled(true);
 }else{
  pixmapLabel2_5->setEnabled(false);
  textLabel2_13_2_2_2_2->setPaletteForegroundColor(qRgb(170,0,0));
  pushButton29_5_2->setEnabled(true);
  pushButton59_7->setEnabled(false);
  pushButton71_2->setEnabled(false);
  //radioButton20->setEnabled(false);
  //groupBox8->setEnabled(false);
 }
 
}

void Form1::setGUIState()
{
 
 static QPushButton *tmp_previous=0;
 static QPushButton *tmp_next=0;
 
 static bool connection1=false, connection2=false;
 
 if(tmp_previous!=0) {
  
  tmp_previous->hide();
 }
 if(tmp_next!=0) 
 {
  tmp_next->hide();
 }
 
 
 updateStatusView();
 
 // nearest Neigbhour Use Auto Generated Check Box
 checkBox8->setHidden(interactiveMode);
 checkBox8_2->setHidden(interactiveMode);
 
 if(interactiveMode) {
  // non-interactive previous and next buttons
  
  
  
  //QString tmp=QString("processState = %1  ").arg(processState,0,10);
  //QMessageBox::information(appl,"information",tmp+stateDescription);
  pushButton25->setHidden(false); 
  pushButton29->setHidden(false); 
  
  pushButton29_2->setHidden(false);
  
  pushButton29_3->setHidden(false);
  
  pushButton29_4->setHidden(false);
  
  pushButton29_4_3->setHidden(false);
  
  
  
  pushButton59->setHidden(false);
  pushButton59_2->setHidden(false);
  pushButton59_2_2->setHidden(false);
  pushButton59_2_3->setHidden(false);
  pushButton59_2_3_2->setHidden(false);
  pushButton59_3->setHidden(false);
  pushButton59_4->setHidden(false);
  pushButton59_5->setHidden(false);
  pushButton59_6->setHidden(false);
  pushButton59_7->setHidden(false);
  pushButton75->setHidden(true);
  pushButton75_4->setHidden(true); // Random value button for P-Value
  // show compute buttons
  pushButton75_2->setHidden(true); // Run button for P-Value
  pushButton75_2_2->setHidden(true);
  
  
  pushButton35->setHidden(false);
  pushButton35_2->setHidden(false);
  pushButton35_3->setHidden(false);
  pushButton35_4->setHidden(false);
  pushButton69->setHidden(false);
  pushButton35_5->setHidden(false);
  pushButton35_6->setHidden(false);
  pushButton35_7->setHidden(false);
  pushButton35_8->setHidden(false);
  pushButton76_2->setHidden(false);
  pushButton69_2->setHidden(false);
  // show previous button for P-Value form 
  pushButton27_2_5->setHidden(false); // previous button of rstat form (R-Statistics)
  pushButton27_2_6->setHidden(false); // previous button of threshold (R-Statistics)
  pushButton27_2_7->setHidden(false);// f-ratio (R-Statistics)
  pushButton27_2_8->setHidden(false);// nearest neighbour (R-Statistics)
  pushButton27_2_5_2->setHidden(false); // small gene (R-Statistics)
  
  // show prevous for P-Value form
  pushButton27_2->setHidden(false); // P-Value Computation (P-Value)
  pushButton27_2_2->setHidden(false); //threshold
  pushButton27_2_3->setHidden(false); // f-ratio
  pushButton27_2_4->setHidden(false); // nearest neighbour
  pushButton27_2_4_2->setHidden(false); // small gene 
  
  
 } else {
  //// R-stat process Menu Button hide
  pushButton29->setHidden(true); 
  pushButton59->setHidden(true);
  pushButton29_2->setHidden(true);
  pushButton59_2->setHidden(true);
  pushButton29_3->setHidden(true);
  pushButton59_2_2->setHidden(true);
  pushButton29_4->setHidden(true);
  pushButton59_2_3->setHidden(true);
  pushButton29_4_3->setHidden(true);
  pushButton59_2_3_2->setHidden(true);
  
  
  
  pushButton75_2->setHidden(false);
  // non-interactive mode just to enterdata in required field
  widgetStack5->raiseWidget(0);
  widgetStack6->raiseWidget(0);
  pushButton25->setHidden(true);
  predictionRadio->setEnabled(true);
  
  
  
  pushButton75->setHidden(false); // random generation button(R-Stat);
  pushButton75_4->setHidden(false); // random generation button (P-Value)
  pushButton75_2_2->setHidden(false); // final run buttion 
  groupBox11->setEnabled(false);// f-ration entry part is not required for non-interactive mode
  groupBox16->setEnabled(false);// f-ration entry part is not required for non-interactive part
  groupBox9->setEnabled(true); // rstat computation
  groupBox10->setEnabled(true);// threshold group
  groupBox12->setEnabled(true);// nearest neighbour
  groupBox12_2->setEnabled(true); //small gene
  //////////////for p value
  groupBox14->setEnabled(true); // rstat computation
  groupBox15->setEnabled(true);// threshold group
  groupBox17->setEnabled(true);// nearest neighbour
  groupBox17_2->setEnabled(true); //small gene
  
  
  // hide compute buttons
  pushButton35->setHidden(true);
  pushButton35_2->setHidden(true);
  pushButton35_3->setHidden(true);
  pushButton35_4->setHidden(true);
  pushButton69->setHidden(true);
  pushButton35_5->setHidden(true);
  pushButton35_6->setHidden(true);
  pushButton35_7->setHidden(true);
  pushButton35_8->setHidden(true);
  pushButton76_2->setHidden(true);
  pushButton69_2->setHidden(true);
  // hide previous button for P-Value form 
  pushButton27_2_5->setHidden(true); // previous button of rstat form (R-Statistics)
  pushButton27_2_6->setHidden(true); // previous button of threshold (R-Statistics)
  pushButton27_2_7->setHidden(true);// f-ratio (R-Statistics)
  pushButton27_2_8->setHidden(true);// our (R-Statistics)
  pushButton27_2_5_2->setHidden(true); // small gene (R-Statistics)
  
  // hide prevous for P-Value form
  pushButton27_2->setHidden(true); // P-Value Computation (P-Value)
  pushButton27_2_2->setHidden(true); //threshold
  pushButton27_2_3->setHidden(true); // f-ratio
  pushButton27_2_4->setHidden(true); // nearest neighbour
  pushButton27_2_4_2->setHidden(true); // small gene
  // add a previous and next button 
  if( predictionRadio->isChecked()){ 
   // if prediction radioButton is checked then only previous and next button be enabled
   if(tmp_previous==0){
    tmp_previous = new QPushButton( "PREVIOUS",frame3);
    tmp_previous->setGeometry(  20, 510, 75, 28  );
    tmp_previous->updateGeometry();
    
    tmp_next = new QPushButton( "NEXT",frame3);
    tmp_next->setGeometry(  105, 510, 75, 28  );
    tmp_next->updateGeometry();
    
   }
   tmp_previous->setHidden(false);
   tmp_next->setHidden(false);
   if(!connection1)
    connection1=connect( tmp_previous, SIGNAL(clicked()), this, SLOT(previousForm_NI()) );
   if(!connection2)  connection2=connect( tmp_next, SIGNAL(clicked()), this, SLOT(nextForm_NI()) );
  } 
  
 }
}



void Form1::selectForm_NI(int pv_ne){
 int RstatWidgetId[]={1,2,6,3,4,5};
 int PvalueWidgetId[]={1,2,8,3,4,6};
 static int rstat=1;
 static int pval=1;
 static   QPushButton *previousSender=0; 
 
 
 QPushButton *currentSender = (QPushButton *)sender();
 /*tmp= rstat+pv_ne;
   if(tmp>4) { 
   
    return true;
} 
  if(tmp<0) { return true;}
 */
 
 
 
 if(previousSender!=0)          previousSender->setEnabled(true);
 if(tabWidget2->currentPageIndex()==0){
  // R-Statistics
  rstat+=pv_ne;
  
  
  if(rstat==6) {
   currentSender->setEnabled(false);
   previousSender=currentSender;
   
   // rstat=4;
   
  } else if(rstat==0){
   currentSender->setEnabled(false);
   previousSender=currentSender;  
   // rstat = 1;
  }
  
  printf("\n rstat widget count : %d", rstat);
  //widgetStack5->raiseWidget(
  // R-Stat computation 
  
  //  QMessageBox::warning(this,"Warning", "R-Statistic Next form ");
  
  widgetStack5->raiseWidget(RstatWidgetId[rstat]);
  // rstat computation form
  // widgetStack5->raiseWidget(2); // threshold computation form
  //  widgetStack5->raiseWidget(3); // pattern filtering computation form
  //  widgetStack5->raiseWidget(4); // nearset neighbour analysis form
  //  widgetStack5->raiseWidget(5); // value for small gene 
 }else {
  // P-Value
  pval+=pv_ne;
  if(pval==6){
   currentSender->setEnabled(false);
   previousSender=currentSender;
   // pval=4;
  }else if(pval==0){
   //pval = 0;
   currentSender->setEnabled(false);
   previousSender=currentSender;
   // 
  } 
  
  widgetStack6->raiseWidget(PvalueWidgetId[pval]);
  // QMessageBox::warning(this,"Warning", "P-Value Next form ");
 }
 
 
}
void Form1::nextForm_NI(){
 
 //QMessageBox::warning(this,"this is a test","next button pressed");
 //selectForm_NI(1);
 // QPushButton *tmp=(QPushButton *)sender();
 selectForm_NI(1);
 
}
void Form1::previousForm_NI(){
 
 //QPushButton *tmp=(QPushButton *)sender();
 // QMessageBox::warning(this,"this is a test",tmp->text());
 selectForm_NI(-1);
 
}


void Form1::linkResults(int nameSpaceid, int resultId){
 //  nameSpaceid  0 -> for R-Stat (nameSpace_R)
 // nameSpaceid 1-> for P-value (nameSpace_P)
 //////////////////////// RESULT PAGE /////////////////////////////////////////////////
 FILE *fp;
 int lineCount =0;
 char rfileName[400];
 
 int i; // for R-STAT
 if(nameSpaceid ==0 && resultId <0){
  //for small gene
  if(resultId == -1){ // for R-stat
   sprintf(rfileName,"%s/R-stat_Results/smallGene",seq_work_dir);
   
  }
  if(resultId == -2){ // P-value
   sprintf(rfileName,"%s/P-Value_Results/smallGene",seq_work_dir);
  } 
  
  QFileDialog* fd = new QFileDialog( this );
  
  //QMessageBox::warning(this,"rfileName = %s ", rfileName);
  QString s = fd -> getOpenFileName(
    rfileName,
    "*.*",
    this,
    "open file dialog",
    "Choose a file" );
  if (!s.isEmpty()) openFile(s);
 } 
 else {
  //QMessageBox::information(appl,"information",nameSpace[nameSpaceid]);
  fp=fopen(nameSpace[nameSpaceid],"r");
  if (fp!=NULL){
   fscanf(fp,"%d",&lineCount);
   std::cout<<"Line count :"<<lineCount<<"\n";
   
   for(i=1;i<=lineCount;i++){   
    fscanf(fp,"%s",rfileName);
    std::cout<<"FILE NAMES "<<rfileName<<"\n";
    if(i>5 and i == resultId){
     //  QMessageBox::information(appl,"information",QString( "Open Office  Calc, spreadsheet will be opened :")+QString(rfileName));
     openFile(rfileName);
     break;
    }
   }
   
   fclose(fp);
   
  } else {
   QMessageBox::information (appl,"Information","P-value comutation is not completed");
  }
 }    
 //////////////////////////////////////////////////////////////////////////////////////////////
}



/**
   sequenceFileName_textChanged is called when the text of the sequence file name has been changed
   This function cheks the priliminayr computation status checking task.
*/

void Form1::openFile(const char *fn){
 system(QString("oocalc ")+fn);
}
void Form1::sequenceFileName_textChanged( const QString & )
{
 
 // Check for the computational status of the sequence file 
 // and report in the right panel
 acceptPath_Ready_for_Computation();
}




void Form1::computeOrfNowPushButton_clicked()
{
 goToNextPageORF();
}

void Form1::goToNextPageORF()
{
 int wid = widgetStack->id(widgetStack->visibleWidget ());
 widgetStack->raiseWidget(wid+1);
}
void Form1::goToPreviousPageORF()
{
 int wid = widgetStack->id(widgetStack->visibleWidget ());
 widgetStack->raiseWidget(wid-1);
}
void Form1::goToPreviousPageRANDOM()
{
 int wid = widgetStack3->id(widgetStack->visibleWidget ());
 widgetStack3->raiseWidget(wid-1);
}
void Form1::goToNextPageRANDOM()
{
 int wid = widgetStack3->id(widgetStack3->visibleWidget ());
 widgetStack3->raiseWidget(wid+1);
}

void Form1::goToNextPageRStatistics()
{
 int wid = widgetStack5->id(widgetStack5->visibleWidget ());
 widgetStack5->raiseWidget(wid+1);
}
void Form1::goToPreviousPageRStatistics()
{
 int wid = widgetStack5->id(widgetStack5->visibleWidget ());
 widgetStack5->raiseWidget(wid-1);
}
void Form1::goToNextPagePValue()
{
 int wid = widgetStack6->id(widgetStack6->visibleWidget ());
 widgetStack6->raiseWidget(wid+1);
}
void Form1::goToPreviousPagePValue()
{
 int wid = widgetStack6->id(widgetStack6->visibleWidget ());
 widgetStack6->raiseWidget(wid+1);
}
//void Form1::pushButton13_clicked()
//{

// goToNextPageORF();

//}


void Form1::pushButton14_clicked()
{
 const char *tmps = lineEdit3->text();
 bool ok;
 QString tmps1;//=new QString();
 char *s=(char *) calloc (100,sizeof(char *));
 tmps1=lineEdit62->text();
 int maxv =tmps1.toInt(&ok,10)   ;//spinBox2->value();//
 tmps1=lineEdit61->text();
 int minv = tmps1.toInt(&ok,10);// spinBox1->value(); //
 
 
 int opt =2;
 if( radioButton7->isChecked()){
  opt = 1;
 }
 if( radioButton8->isChecked()){
  if(minv>maxv) 
  {
   QMessageBox::critical(this,"Critical", "Minimum sequence length must be less than maximum sequence length");
   return;
  }
  opt = 2;
 }
 
 
 rf.setMaxLen(maxv);
 
 rf.setMinLen (minv);
 
 
 rf.setOption(opt);
 
 s=strcpy(s,tmps);
 
 rf.setStartCodons(s);
 
 tmps = lineEdit4->text();
 s=strcpy(s,tmps);
 rf.setStopCodons(s);
 
 
 rf.openPath(mainPath);
 rf.readInBuf_GUI();
 char *ss=(char *)malloc(255*sizeof(char *));
 ss=rf.frequencyOfElements();
 printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
 const char *css=ss;
 QString qcss = css;
 
 textEdit1->setText(qcss);
 
 goToNextPageORF();
 paramMg ->updateFinalDom();
 
}
void Form1::initialize_max_min_fields()
{
 FILE *fp, *fp1;
 char tmp_str[200], query[200],ftmp_str[200];
 sprintf(tmp_str,"%s/path_ORF",seq_work_dir);
 fp=fopen( tmp_str,"r");
 
 fscanf(fp,"%s",ftmp_str); // sequence file
 fscanf(fp,"%s",ftmp_str); // orf pluse file 
 
 sprintf(query,"head -n 1 %s>%s/tmp.txt",ftmp_str,seq_work_dir);
 system(query);
 sprintf(query,"%s/tmp.txt",seq_work_dir);
 fp1=fopen(query,"r");
 fscanf(fp1,"%s\t%d",tmp_str, &_orf_p_min);
 fclose(fp1);
 sprintf(query,"%s/tmp.txt",seq_work_dir);
 fp1=fopen(query,"r");
 sprintf(query,"tail -n 1 %s>%s/tmp.txt",ftmp_str,seq_work_dir);
 system(query);
 sprintf(query,"%s/tmp.txt",seq_work_dir);
 fp1=fopen(query,"r");
 fscanf(fp1,"%s\t%d",tmp_str, &_orf_p_max);
 fclose(fp1);
 
 
 fscanf(fp,"%s",ftmp_str); // non ORF pluse
 fscanf(fp,"%s",ftmp_str); // orf minus file
 
 sprintf(query,"head -n 1 %s>%s/tmp.txt",ftmp_str,seq_work_dir);
 system(query);
 sprintf(query,"%s/tmp.txt",seq_work_dir);
 fp1=fopen(query,"r");
 fscanf(fp1,"%s\t%d",tmp_str, &_orf_n_min);
 fclose(fp1);
 sprintf(query,"%s/tmp.txt",seq_work_dir);
 fp1=fopen(query,"r");
 sprintf(query,"tail -n 1 %s>%s/tmp.txt",ftmp_str,seq_work_dir);
 system(query);
 sprintf(query,"%s/tmp.txt",seq_work_dir);
 fp1=fopen(query,"r");
 fscanf(fp1,"%s\t%d",tmp_str, &_orf_n_max);
 fclose(fp1);
 
 if(_orf_p_max>_orf_n_max)
 {
  _max_range = _orf_p_max;
 } else{
  _max_range = _orf_n_max;
 };
 if(_orf_p_min<_orf_n_max){
  _min_range = _orf_p_min;
 }else{
  _min_range = _orf_n_min;
 };
 // write to file
 sprintf(tmp_str,"%s/orf_max_min",seq_work_dir);
 fp = fopen(tmp_str,"w");
 fprintf(fp,"%d\t%d", _min_range, _max_range);
 fclose(fp);
 
 
}



void Form1::pushButton15_clicked()
{
 
 textLabel2_4->setText("");
 goToNextPageORF();
 pushButton25->setEnabled(true);
 
}


void Form1::pushButton20_clicked()
{
 //    textLabel3->setText(" ORF computation has been completed");
 widgetStack->raiseWidget(0);
 computeOrfNowPushButton->setEnabled(false);
 pushButton3->setEnabled(true);
}


void Form1::pushButton12_clicked()
{
 goToNextPageORF();
}


void Form1::orfRadio_clicked()
{
 groupBox6->setTitle("ORF COMPUTATION");
 computationPart->setText("ORF Computation");
 radioButton21->setEnabled(false);
 radioButton22->setEnabled(false);
 widgetStack->raiseWidget(1);
 widgetStack2->raiseWidget(0);    
 setGUIState();
}


/*void Form1::Radio_clicked()
{
    groupBox6->setTitle("RANDOM SEQUENCE COMPUTATIONS");
    widgetStack3->raiseWidget(0);
    widgetStack2->raiseWidget(1); 
}*/


void Form1::predictionRadio_clicked()
{
 groupBox6->setTitle("PREDICTION AND ANALYSIS");
 radioButton21->setEnabled(true);
 radioButton22->setEnabled(true);
 widgetStack2->raiseWidget(2);
 setGUIState();
}


void Form1::pushButton16_3_clicked()
{
 goToPreviousPageORF();
}


void Form1::pushButton16_2_clicked()
{
 goToPreviousPageORF();
}


void Form1::pushButton16_clicked()
{
 goToPreviousPageORF();
}


void Form1::pushButton19_clicked()
{
 QFileDialog* fd = new QFileDialog( this ); 
 fd -> setDir("$home");
 QString s = fd -> getOpenFileName(
   "Text files (*.txt)",
   "",
   this,
   "open file dialog",
   "Choose a file" );
 // sequenceFileName->setText(s);
}


void Form1::radioButton7_clicked()
{
 // rf.setOption(1);
 groupBox5->setEnabled(false);
}



void Form1::radioButton8_clicked()
{  
 //  rf.setOption(2);
 groupBox5->setEnabled(true);
 // read the default values of minimum and maximum length of sequence
 
 
}


void Form1::radioButton9_clicked()
{
 rf.setFilterSequence_wrt(1);
}


void Form1::radioButton10_clicked()
{
 rf.setFilterSequence_wrt(2);
}





void Form1::checkBox2_toggled( bool b)
{
 rf.saveIntermediateData_toFile(b);   
}


void Form1::pushButton15_released()
{
 goToNextPageORF();
}




void Form1::pushButton26_clicked()
{
 goToPreviousPageORF();
}


void Form1::widgetStack_aboutToShow( QWidget * )
{
 
 if (lineEdit3->text() =="" || lineEdit4->text()=="")
  pushButton14->setEnabled(false);
 
}


void Form1::lineEdit3_textChanged( const QString &)
{
 enablePusButton14();
 pushButton27->setEnabled(true);
 
}

void Form1::enablePusButton14(){
 QString  s1= lineEdit3->text();
 QString s2= lineEdit4->text();
 if (s1.isEmpty() || s2.isEmpty())
 {    
  pushButton14->setEnabled(false);
 }else {
  pushButton14->setEnabled(true);
 }
}
void Form1::lineEdit4_textChanged( const QString & )
{
 enablePusButton14();
 pushButton28->setEnabled(true);
 
}


void Form1::pushButton27_clicked()
{
 lineEdit3->setText("");
 pushButton27->setEnabled(false);
}


void Form1::pushButton28_clicked()
{
 lineEdit4->setText("");
 pushButton28->setEnabled(false);
}

void Form1::pushButton25_pressed()
{
 textLabel2_4->setText("Please wait...");
}


void Form1::pushButton3_clicked()
{
 goToNextPageORF();
}


/*void Form1::spinBox1_valueChanged( int  v)
{
    int maxv = spinBox2->value();
    if(maxv<v) {
 spinBox2->setValue(v);
 rf.setMaxLen(v);
    }
    rf.setMinLen (v);
    
}


void Form1::spinBox2_valueChanged( int v)
{
 int minv = spinBox1->value();
 if(minv>v) {
  spinBox1->setValue(v);
  rf.setMinLen(v);
 }
 rf.setMaxLen(v);
 
}*/


void Form1::pushButton16_4_released()
{
 goToNextPageRANDOM();
 
}


void Form1::pushButton18_released()
{
 /*    QString s1 = lineEdit4_2->text();
    QString s2 = lineEdit5->text();
    QString s3 = lineEdit6->text();
    QString s4 = lineEdit7->text();
    s1 = s1.stripWhiteSpace();
    s2 = s2.stripWhiteSpace();
    s3 = s3.stripWhiteSpace();
    s4 = s4.stripWhiteSpace();
    if(s1 =="" || s2=="" || s3=="" ||s4==""){
 QMessageBox::warning(appl,"Warning","Fields must not be blank");
 return;
    }
    bool ok;
    mainPbc->pbcReset();
    sManager->setProcessState(2,"10");
    Create_Random_Sequence(s1.toInt(&ok,10), s2.toInt(&ok,10), s3.toInt(&ok,10),s4.toInt(&ok,10));
    if(mainPbc->pbcWasCanceled()){
 sManager->setProcessState(2,"20");
    }else{
 sManager->setProcessState(2,"100");
    }
    mainPbc->pbcReset();
    setGUIState();
    widgetStack3->raiseWidget(0);
    */
}



void Form1::pushButton19_2_released()
{  
 widgetStack3->raiseWidget(0);
 
}




void Form1::pushButton20_2_clicked()
{
 goToNextPageRStatistics();
}


void Form1::pushButton21_clicked()
{
	goToNextPagePValue();
}


void Form1::pushButton29_clicked()
{
 mainPbc->pbcResetTermination();
 widgetStack5->raiseWidget(1);
}


void Form1::pushButton29_2_clicked()
{
 mainPbc->pbcResetTermination();
 widgetStack5->raiseWidget(2);
 
}




void Form1::pushButton29_4_clicked()
{
 widgetStack5->raiseWidget(4);
 // put default values for nearestNeighbourhood (r-stat) analysis form
 nearest_neighbour_default(0);
 
}

void Form1::nearest_neighbour_default(int flag)
{
 FILE *fp_NameSpace, *fp;
 int file_Count;
 char potentialGeneFName[200], nonPotentialGeneFName[200], query[200],tmps[100];
 int potentialCount, nonpotentialCount;
 mainPbc->pbcResetTermination();
 if((fp_NameSpace = fopen(nameSpace[flag],"r")) != NULL) 
 {
  fscanf(fp_NameSpace,"%d",&file_Count);
  if(file_Count<3) return ; // thresholdng have not yet been computed
  fscanf(fp_NameSpace,"%s",potentialGeneFName);
  fscanf(fp_NameSpace,"%s",potentialGeneFName);
  
  fscanf(fp_NameSpace,"%s",potentialGeneFName); // potentialGene file name
  
  fscanf(fp_NameSpace,"%s",nonPotentialGeneFName); // non-potentialGene file name    
  
  fclose(fp_NameSpace);
  //potential record count
  sprintf(query,"wc -l %s>%s/tmp.txt",potentialGeneFName,seq_work_dir);
  system(query);
  sprintf(query,"%s/tmp.txt",seq_work_dir);
  fp=fopen(query,"r");
  
  fscanf(fp,"%d\t%s",&potentialCount,tmps);
  nearest_neighbour_default_1(flag,0,potentialCount);
		fclose(fp);
		// non-potential record count
		sprintf(query,"wc -l %s>%s/tmp.txt",nonPotentialGeneFName,seq_work_dir);
		system(query);
		sprintf(query,"%s/tmp.txt",seq_work_dir);
		fp=fopen(query,"r");
		
		fscanf(fp,"%d\t%s",&nonpotentialCount,tmps);
		nearest_neighbour_default_1(flag,1,nonpotentialCount);
		fclose(fp); 
		
	}
}
void Form1::nearest_neighbour_default_1(int rstat_or_p_flag,int flag,int count){
	int value=0;
	int value_rs=0;
	int value_rest=0;
	static int indicate;
	if(flag==0) indicate =0;
	
	if(count>=600) {
		value = 500;
		value_rs=200;
		value_rest=3;
	} else if(count<600 && count>=500){
		value = 400;
		value_rs=200;
		value_rest=3;
 } else if(count <500 && count>=400){
  value = 300;
  value_rs=200;
  value_rest=3;
 } else if(count <400 && count>=300){
  value = 200;
  value_rs=100;
  value_rest=2;
 } else if(count <300 && count>=150){
  value = 100;
  value_rs=100;
  value_rest=1;
 } else {
  value =50;
  value_rs=100;
  value_rest=1;
  
  if(flag==0){
   indicate = 1;   
  }else if(flag==1){
   if(indicate == 1)  {
    indicate = 3;
   }else {
    indicate =2;
   }
  } 
 }
 
 if(flag==1){
  
  if(indicate >0) {
   // warning message is to be sent
   //if(interactiveMode){
			if(indicate ==1) {
				QMessageBox::warning(this,"Warning","Potential gene count must be atleast 150.\n Please recompute thresholding to increase the count");
   } else if(indicate ==2) {
    QMessageBox::warning(this,"Warning","Potential non-gene count must be atleast 150. \nPlease recompute thresholding to increase the count");
   } else if(indicate ==3){
    QMessageBox::warning(this,"Warning","Potential gene and Potential non-Gene count must be atleast 150. \nPlease recompute thresholding to increase the count");
   }
   //}
  }
 }
 
 if(rstat_or_p_flag==0){
  //R-stat
  if(flag ==0){
   // potential setting
   lineEdit19->setText(QString::number(value,10));
   lineEdit19_3->setText(QString::number(value_rs, 10));
   lineEdit19_4->setText(QString::number(value_rest, 10));
   lineEdit19_5->setText(QString::number(value_rest, 10));
   lineEdit19_6->setText(QString::number(value_rest, 10));
   lineEdit19_7->setText(QString::number(value_rest, 10));
  } else  if(flag ==1){
			// nonPotential settings
   lineEdit19_2->setText(QString::number(value, 10));
   
  }} else if(rstat_or_p_flag==1){
  //p-value
  if(flag ==0){
   // potential setting
   lineEdit19_8->setText(QString::number(value,10));
   lineEdit19_3_2->setText(QString::number(value_rs, 10));
   lineEdit19_4_2->setText(QString::number(value_rest, 10));
   lineEdit19_5_2->setText(QString::number(value_rest, 10));
   lineEdit19_6_2->setText(QString::number(value_rest, 10));
   lineEdit19_7_2->setText(QString::number(value_rest, 10));
  } else  if(flag ==1){
   // nonPotential settings
   lineEdit19_2_2->setText(QString::number(value, 10));
   
  }
 }
}
void Form1::pushButton27_2_5_clicked()
{
 widgetStack5->raiseWidget(0);
}


void Form1::pushButton27_2_6_clicked()
{
 widgetStack5->raiseWidget(0);    
}


void Form1::pushButton27_2_7_clicked()
{
	free_MemForAll_Pattern_Count(); 
	widgetStack5->raiseWidget(0);
}


void Form1::pushButton27_2_8_clicked()
{
	widgetStack5->raiseWidget(0);    
}


void Form1::pushButton29_5_clicked()
{
	widgetStack6->raiseWidget(1);  
}


void Form1::pushButton29_2_2_clicked()
{
	widgetStack6->raiseWidget(2);      
}





void Form1::pushButton29_4_2_clicked()
{
 widgetStack6->raiseWidget(4);      
 // put default values for nearestNeighbourhood (p-value)analysis form
 nearest_neighbour_default(1);
}


void Form1::pushButton27_2_clicked()
{
 widgetStack6->raiseWidget(0);   
}


void Form1::pushButton27_2_2_clicked()
{
 widgetStack6->raiseWidget(0);   
}


void Form1::pushButton27_2_3_clicked()
{
 free_MemForAll_Pattern_Count(); 
 widgetStack6->raiseWidget(0);       
}


void Form1::pushButton27_2_4_clicked()
{
 widgetStack6->raiseWidget(0);       
}


void Form1::tabWidget2_currentChanged( QWidget *w )
{   
 pushButton74_2_2->setEnabled(false);
 if(interactiveMode){
  widgetStack6->raiseWidget(0);
  widgetStack5->raiseWidget(0);
 }
 choice  = 0;
 if(strcmp(w->name(),"R_Statistic") == 0){
  choice = 1;
  //radioButton10_2->setChecked(true);
  groupBox25->setEnabled(false);
 }
 if(strcmp(w->name(),"P_Value") == 0){
  choice = 2;
  // This is for P-value computation 
  //radioButton9_2->setChecked(true);
  // groupBox6_2->setEnabled(false);
 }
 
 
}




// Compute R-Statistics with parameters
void Form1::pushButton35_clicked()
{
 bool ok;
 FILE *fp;
 char tmp_str[200];
 QString _FileName=QString("path_ORF");
 QString s = lineEdit8->text();
 int  _MIN_CHAR = s.toInt(&ok,10);
 s = lineEdit9->text();
 int _MAX_CHAR = s.toInt(&ok,10);
 QString _seq_FileName = lineEdit10->text();
 s = lineEdit8->text();
 _MIN_CHAR = s.toInt(&ok,10);
 s = lineEdit9->text();
 _MAX_CHAR = s.toInt(&ok,10); 
 if(radioButton11->isChecked()) {
  //QMessageBox::warning(this,"input type", "input type 2");
  inputType = 2;
 } else if(radioButton10_2->isChecked()){
  //_MIN_CHAR  = -1;
  //_MAX_CHAR = -1;
  //QMessageBox::warning(this,"input type", "input type 1");
  inputType = 1;
 }
 char _isPrint_R_P ='N';
 // char _isPrint_R_P = (checkBox2_2->isChecked())?'Y':'N';    
 int _Occur =-1;
 bool flag = true;
 if(   checkBox3->isChecked()){
  s =  lineEdit11->text();
  _Occur =s.toInt(&ok,10);
  if(_Occur%3 !=0 ){
   QMessageBox::information( this, "Parameter Error",
           "Frequency value (should be multiple of 3) \n"
           "Please enter the correct value") ;
   flag = false;
  } 
 }       
 QString t=lineEdit45->text()+"/";
 
 char *ss = (char *) calloc (400,sizeof(char *));
 char *tmpstr=(char *)calloc(400,sizeof(char*));;  
 char *s2 = (char *) calloc (400,sizeof(char *));
 char *dest = (char *) calloc (400,sizeof(char *));
 ss=strcpy(ss,t);
 
 
 s2=strcpy(s2,_seq_FileName);
 sprintf(dest,"%s/%s",seq_work_dir,ss );
 if(   change_Directory(dest)){
  sprintf(tmpstr,"%s%s",dest,s2 );
 }
 else {
  //   QMessageBox::warning(this,"Warning", "Directory can not accessed!!!");
  //    sprtintf(tmpstr,"%s/%s",seq_work_dir,s2 );
  return;
 }
 
 mainPbc->pbcResetTermination();
 sManager->setProcessState(4,"10");
 computation_R_Statistic(_FileName, _MIN_CHAR, _MAX_CHAR, tmpstr, _isPrint_R_P,  _Occur);    
 
 if(mainPbc->pbcWasCanceled()){
  QMessageBox::warning(this,"Alert","Process is terminating abnormally");
  sManager->setProcessState(4,"20");
 }else{
  
  sManager->setProcessState(4,"100");
  
  
  if(inputType == 1) { // for all sequence 
   sprintf(tmp_str,"cp %s/orf_max_min %s/orf_max_min_R",seq_work_dir, seq_work_dir);
   system( tmp_str);
  } else  if(inputType == 2) {  
   //selected min_max for R-stat computation (save)
   sprintf(tmp_str,"%s/orf_max_min_R",seq_work_dir);
   fp = fopen(tmp_str,"w");
   fprintf(fp,"%d\t%d",  _MIN_CHAR,  _MAX_CHAR);
   fclose(fp);
  }
 }
 mainPbc->pbcReset();    
 // store parameters to Dom
 paramMg->updateFinalDom();
 // raise the main menu of R-stat computation
 widgetStack5->raiseWidget(0); 
 
 //check R-stat computation status
 setGUIState();
 
 
 
 
}


void Form1::checkBox3_clicked()
{
 if(checkBox3->isChecked()){
  textLabel7_2->setDisabled(false);
  lineEdit11->setDisabled(false);
 }else{
  textLabel7_2->setDisabled(true);
  lineEdit11->setDisabled(true);
 }
}


void Form1::checkBox3_2_clicked()
{
 if(checkBox3_2->isChecked()){
  textLabel7_2_2->setDisabled(false);
  lineEdit11_2->setDisabled(false);
 }else{
  textLabel7_2_2->setDisabled(true);
  lineEdit11_2->setDisabled(true);
 }
}

void Form1::pushButton45_clicked()
{
 //    Folder_creation *cdirectory;
 // cdirectory = new Folder_creation(this,"Create New Folder",true);
 // create folder to store data 
 QFileDialog* fd = new QFileDialog( this );
 connect(fd,SIGNAL(dirEntered( const QString &)), this,SLOT(directoryChangedWarning()));
 fd -> setDir(seq_work_dir);
 
 fd->setMode(QFileDialog::DirectoryOnly);
 QString s = fd -> getOpenFileName(
   "",
   "",
   this,
   "open folder dialog",
   "Choose a folder" );
 
 
}
void Form1::directoryChangedWarning(){
 std::cout<<"directory has been changed";
 QMessageBox::information(this,"warning","Don't change the directory, just create or select ");
}
//Compute Thresholding for R-Statistic
void Form1::pushButton35_2_clicked()
{
 bool ok;
 
 QString s1 = lineEdit15 ->text();
 QString s2 = lineEdit16 ->text();
 QString s;
 int _MIN_CHAR=0;
 int _MAX_CHAR=0;
 MinRatio_Gene = s1.toDouble();
 MinRatio_NonGene = s2.toDouble();
 
 mainPbc->pbcResetTermination();
 
 if(radioButton11_2->isChecked()) {
  s = lineEdit8_3->text();
  _MIN_CHAR = s.toInt(&ok,10);
  s = lineEdit9_3->text();
  _MAX_CHAR = s.toInt(&ok,10);
  inputType = 2;
 } else if(radioButton10_2_2->isChecked()){
  _MIN_CHAR  = -1;
  _MAX_CHAR = -1;
  inputType = 1;
 }
 
 thresholding_R_Statistic(nameSpace[0],misc[0], f_Ratio_File[0], filtered_Pattern[0], filtered_Pattern[1], textLabel1_14_3, inputType, _MIN_CHAR, _MAX_CHAR,5);    
 
 if(mainPbc->pbcWasCanceled()) {
  widgetStack5->raiseWidget(2);
  setGUIState();
  return ;
 }
 widgetStack5->raiseWidget(8);
 setGUIState();
 paramMg->updateFinalDom();
 // if nearest neighbourhodd is to use computed parameter  then required to run the following function else
 
 
 // skop it
 if(interactiveMode==false){
  if(strcmp(paramMg->getValueById("540"),"true")==0 ) nearest_neighbour_default(0);
 }else{ /// interactive mode
  nearest_neighbour_default(0);
 }
}


void Form1::pushButton35_3_clicked()
{
 
 
 
 QString s1 = lineEdit17 ->text();
 int processState;
 QString processDes("");
 fRatio_Calculation(filtered_Pattern[0], filtered_Pattern[1],textLabel1_11,s1.toDouble(),6);
 //pushButton77->setEnabled(true);
 //pushButton27_2_7->setEnabled(false);
 sManager->getProcessState(6,&processState,&processDes);
 if(processState==100) widgetStack5->raiseWidget(0);
 setGUIState();    
 
 
 paramMg->updateFinalDom();
 
}




void Form1::widgetStack5_aboutToShow( int widgetNo)
{
 if(widgetNo==6){
  paramMg->getValueToWidget("320", radioButton21_2, "QRadioButton"); // fratio param tri
  paramMg->getValueToWidget("330", radioButton22_2, "QRadioButton"); // fratio param tetra
 }
 
 if(widgetNo==0){
  pushButton74_2->setEnabled(false);
 } else 
  pushButton74_2->setEnabled(true);
 
}


void Form1::pushButton29_3_pressed()
{
 widgetStack5->raiseWidget(3); 
}


void Form1::pushButton29_3_released()
{
 
 int processState;
 QString processDes("");
 pushButton35_3->setEnabled(false);
 //  pushButton77->setEnabled(false); // by default Next button disabled
 //pushButton27_2_7->setEnabled(true);// by default previous button enabled
 mainPbc->pbcResetTermination();
 if(interactiveMode) lineEdit17->setText(""); // filtering fratio nfield is to be initialized (not in non-interactive mode)
 filtering_F_Ratio(nameSpace[0], misc[0], f_Ratio_File[0], filtered_Pattern[0],filtered_Pattern[1],textLabel1_11,6);    pushButton35_3->setEnabled(true);
 sManager->getProcessState(6,&processState,&processDes);
 if(processState==100) widgetStack5->raiseWidget(0);
 setGUIState();    
 
 
}


void Form1::pushButton35_4_clicked()
{
 int gene;
 int nonGene;
 int inputType=2; // in percentage 
 int iteration;
 bool ok;
 QString s1 = lineEdit19->text();
 gene = s1.toInt(&ok, 10);
 s1 = lineEdit19_2->text();
 nonGene = s1.toInt(&ok, 10);
 s1 = lineEdit19_3->text();
 iteration = s1.toInt(&ok, 10);
 
 s1 = lineEdit19_4->text();
 Trim1 = s1.toInt(&ok, 10);
 s1 = lineEdit19_5->text();
 Trim2 = s1.toInt(&ok, 10);
 s1 = lineEdit19_6->text();
 Trim3 = s1.toInt(&ok, 10);
 s1 = lineEdit19_7->text();
 Trim4 = s1.toInt(&ok, 10);
 if(radioButton16->isChecked()) inputType =1;
 if(radioButton17->isChecked()) inputType =2;
 
 
 ok = Validation_of_Trimvalues();
 
 if (ok)   {
  mainPbc->pbcResetTermination();
  sManager->setProcessState(7,"10");
  analysis_Nearest_Neighbourhood(nameSpace[0], misc[0], filtered_Pattern[0],filtered_Pattern[1], gene, nonGene, iteration, inputType);
  if(mainPbc->pbcWasCanceled()){
   sManager->setProcessState(7,"20");
   
  }else{
   sManager->setProcessState(7,"100");
  }
  sManager->setProcessState(8,"0");
  widgetStack5->raiseWidget(0);
  mainPbc->pbcReset();
 }
 
 setGUIState();   
 paramMg->updateFinalDom();
}

bool Form1::Validation_of_Trimvalues(){
 if(Trim1  > 25 || Trim2 > 25 || Trim3 > 25 || Trim4 > 25){
  textLabel1_13->setText("The trim values must be less than equal to 25");
  
  return false;
  
 } else {
  textLabel1_13->setText("");
  
  return true;
 }
}





void Form1::pushButton27_2_5_2_clicked()
{
 widgetStack5->raiseWidget(0);
}


void Form1::pushButton27_2_5_2_2_clicked()
{
 widgetStack5->raiseWidget(2);
}


void Form1::pushButton27_2_5_2_3_clicked()
{
 widgetStack5->raiseWidget(0);
}


void Form1::pushButton27_2_5_2_4_clicked()
{
 widgetStack5->raiseWidget(0);
}


void Form1::pushButton35_5_clicked()
{
 bool ok;
 int _Operation;
 int _MIN_CHAR=0;
 int _MAX_CHAR=0;
 FILE *fp;
 char tmp_str[200];
 QString s;
 QString _FileName=QString("path_ORF");
 mainPbc->pbcResetTermination();
 
 if(radioButton8_2->isChecked()) {
  s = lineEdit8_2->text();
  _MIN_CHAR = s.toInt(&ok,10);
  s = lineEdit9_2->text();
  _MAX_CHAR = s.toInt(&ok,10);
  inputType = 2;
 } else if(radioButton9_2->isChecked()){
  _MIN_CHAR  = -1;
  _MAX_CHAR = -1;
  inputType = 1;
 }
 
 QString _seq_FileName = lineEdit10_2->text();
 char _isPrint_R_P = 'N';
 int _Occur =-1;
 bool flag = true;
 if(   checkBox3_2->isChecked())
 {
  s =  lineEdit11_2->text();
  _Occur  = s.toInt(&ok,10);
  if(_Occur%3 !=0 ){
   QMessageBox::information( this, "Parameter Error","Frequency value (should be multiple of 3) \n", "Please enter the correct value") ;
   flag = false;
  }
 }
 QString t=lineEdit45_2->text()+"/";
 
 char *ss = (char *) calloc (400,sizeof(char *));
 char *tmpstr=(char *)calloc(400,sizeof(char*));;  
 char *s2 = (char *) calloc (400,sizeof(char *));
 char *dest = (char *) calloc (400,sizeof(char *));
 ss=strcpy(ss,t);
 s2=strcpy(s2,_seq_FileName);
 sprintf(dest,"%s/%s",seq_work_dir,ss );
 if(   change_Directory(dest)){
  sprintf(tmpstr,"%s%s",dest,s2 );
 }else {
  QMessageBox::information( this, "Error:",QString("Cannot get into the directory : ")+QString(dest)+QString("\n"), "Please enter the correct value") ;
  return;
 }
 //-----------------------
 
 s = lineEdit29->text();
 _Operation = s.toInt(&ok,10);
 s = lineEdit30->text();
 double _swap_Percent = s.toDouble();
 s = lineEdit31->text();
 double _mut_Percent = s.toDouble();
 computation_Lower_Tail_Probability(_FileName, _MIN_CHAR, _MAX_CHAR, tmpstr, _isPrint_R_P,  _Occur, _Operation, _swap_Percent, _mut_Percent);
 if(mainPbc->pbcWasCanceled()){
  sManager->setProcessState(9,"20");
 }else{
  sManager->setProcessState(9,"100");
  if(inputType == 1) { // for all sequence 
   sprintf( tmp_str,"cp %s/orf_max_min %s/orf_max_min_P",seq_work_dir, seq_work_dir);
   system( tmp_str);
  } else  if(inputType == 2) {  
   sprintf(tmp_str,"%s/orf_max_min_P",seq_work_dir);
   fp = fopen(tmp_str,"w");
			fprintf(fp,"%d\t%d",  _MIN_CHAR,  _MAX_CHAR);
			fclose(fp);
		}
		
	}
	
	mainPbc->pbcReset();
	
	
	setGUIState();
	paramMg->updateFinalDom();
	widgetStack6->raiseWidget(0);  // output of P-value computation}}
}

void Form1::pushButton45_2_clicked()
{
	
	
}


void Form1::pushButton35_6_clicked()
{   
	bool ok;
	QString s1 = lineEdit15_2->text();
	QString s2 = lineEdit16_2 ->text();
	QString s;
	int _MIN_CHAR=0;
 int _MAX_CHAR=0;
 MinRatio_Gene = s1.toDouble();
 MinRatio_NonGene = s2.toDouble();
 mainPbc->pbcResetTermination();
 
 
 if(radioButton11_2_2->isChecked()) {
  s = lineEdit8_3_2->text();
  _MIN_CHAR = s.toInt(&ok,10);
  s = lineEdit9_3_2->text();
  _MAX_CHAR = s.toInt(&ok,10);
  //QMessageBox::warning(this,"input type", "input type 2");
  inputType = 2;
 } else if(radioButton10_2_2_2->isChecked()){
  _MIN_CHAR  = -1;
  _MAX_CHAR = -1;
  //QMessageBox::warning(this,"input type", "input type 1");
  inputType = 1;
 }
 
 
 
 MinRatio_Gene = s1.toDouble();
 MinRatio_NonGene = s2.toDouble();    
 thresholding_R_Statistic(nameSpace[1],misc[1], f_Ratio_File[1], filtered_Pattern[2],filtered_Pattern[3], textLabel1_14_2, inputType, _MIN_CHAR, _MAX_CHAR, 10);
 
 
 if(mainPbc->pbcWasCanceled()) {
  widgetStack6->raiseWidget(2);
  setGUIState();
  mainPbc->pbcReset();
  return ;
	}
	setGUIState();
	widgetStack6->raiseWidget(5);
	nearest_neighbour_default(1);
	paramMg->updateFinalDom();
}


void Form1::pushButton64_clicked()
{
 widgetStack5->raiseWidget(2);
}


void Form1::pushButton27_2_2_2_clicked()
{
 widgetStack6->raiseWidget(0);  
}


void Form1::radioButton9_2_clicked()
{
 groupBox6_2->setEnabled(false);
}


void Form1::radioButton8_2_clicked()
{
 groupBox6_2->setEnabled(true);
}


void Form1::pushButton35_7_clicked()
{
	QString s1 = lineEdit17_2 ->text();
	int processState;
	QString processDes("");
	
	fRatio_Calculation(filtered_Pattern[2],filtered_Pattern[3],textLabel1_11_2,s1.toDouble(),11);
	//pushButton77->setEnabled(true);
	//pushButton27_2_7->setEnabled(false);
	sManager->getProcessState(11,&processState,&processDes);
	if(processState==100) widgetStack6->raiseWidget(0);
 setGUIState();    
 
 paramMg->updateFinalDom();
 
}

// Analysis of nearest neighbour for P-Value computation
void Form1::pushButton35_8_clicked()
{
 double  gene;
 double nonGene;
 int iteration;
 int inputType=2;
 bool ok;
 mainPbc->pbcResetTermination();
 QString s1 = lineEdit19_8->text();
 gene = s1.toDouble(&ok);
 s1 = lineEdit19_2_2->text();
 nonGene = s1.toDouble(&ok);
 s1 = lineEdit19_3_2->text();
 iteration = s1.toInt(&ok, 10);
 
 s1 = lineEdit19_4_2->text();
 Trim1 = s1.toInt(&ok, 10);
 s1 = lineEdit19_5_2->text();
 Trim2 = s1.toInt(&ok, 10);
 s1 = lineEdit19_6_2->text();
 Trim3 = s1.toInt(&ok, 10);
 s1 = lineEdit19_7_2->text();
 Trim4 = s1.toInt(&ok, 10);
 if(radioButton16_2->isChecked()) inputType =1;
 if(radioButton17_2->isChecked()) inputType =2;
 
	ok = Validation_of_Trimvalues();
	
	if (ok)   {
		analysis_Nearest_Neighbourhood(nameSpace[1], misc[1], filtered_Pattern[2],filtered_Pattern[3], gene, nonGene, iteration, inputType);
		if(mainPbc->pbcWasCanceled()){
			sManager->setProcessState(12,"20");
			
		}else{
			sManager->setProcessState(12,"100");
			
		}
		sManager->setProcessState(13,"0");
		widgetStack6->raiseWidget(0);
		mainPbc->pbcReset();
	}
	
	setGUIState();  
	paramMg->updateFinalDom();
	
}


void Form1::pushButton27_2_4_2_released()
{
	widgetStack6->raiseWidget(0);  
}


void Form1::pushButton27_2_4_2_2_released()
{      widgetStack6->raiseWidget(0);  
 
}


void Form1::pushButton29_3_2_pressed()
{
 widgetStack6->raiseWidget(3);
}


void Form1::pushButton29_3_2_released()
{
 int processState;
 QString processDes("");
 
 pushButton35_7->setEnabled(false);
 //  pushButton78->setEnabled(false); // by default Next button disabled
 //pushButton27_2_3->setEnabled(true);// by default previous button enabled
 
 filtering_F_Ratio(nameSpace[1], misc[1], f_Ratio_File[1], filtered_Pattern[2], filtered_Pattern[3],textLabel1_11_2,11);    
 sManager->getProcessState(11,&processState,&processDes);
 if(processState==100) widgetStack6->raiseWidget(0);
 setGUIState();
}





void Form1::resultRadio_clicked()
{
 widgetStack2->raiseWidget(3);    
 setGUIState();
}





void Form1::newSlot()
{
 
}


void Form1::pushButton50_clicked()
{
	linkResults(0,6); // ORF+
	
}


void Form1::pushButton50_2_clicked()
{
	this->linkResults(0,8); //ORF-
}


void Form1::pushButton50_3_clicked()
{
	linkResults(1,6); // ORF+   : P-value
	
}



void Form1::pushButton50_2_4_clicked()
{
	linkResults(1,8); // ORF-   : P-value
}


void Form1::closeSession_clicked()
{
 
 QMessageBox mb( "Warning",
        "The session is going to close.\n"
        "Do you really want to close the current session?",
        QMessageBox::Information,
        QMessageBox::Yes ,
        QMessageBox::No| QMessageBox::Default,
        QMessageBox::Cancel | QMessageBox::Escape );
 mb.setButtonText( QMessageBox::Yes, "Close Session" );
 mb.setButtonText( QMessageBox::No, "Don't Close" );
 switch( mb.exec() ) {
 case QMessageBox::Yes:
  // close session
  sequenceFileName->setText("");
  chooseSeq->setText("");
  InitializeApplication();
  break;
 case QMessageBox::No:
  // don't close session
  break;
 case QMessageBox::Cancel:
  // don't close
  break;
 }
 
 
 
}


void Form1::pushButton59_clicked()
{
 mainPbc->pbcResetTermination();
 widgetStack5->raiseWidget(1);
}


void Form1::pushButton59_2_clicked()
{
	mainPbc->pbcResetTermination();
	widgetStack5->raiseWidget(2);
	
}


void Form1::pushButton59_2_2_released()
{
	//    int processState;
	QString processDes("");
	pushButton35_3->setEnabled(false);
	//  pushButton77->setEnabled(false); // by default Next button disabled
	//pushButton27_2_7->setEnabled(true);// by default previous button enabled
	mainPbc->pbcResetTermination();
	lineEdit17->setText("");
	filtering_F_Ratio(nameSpace[0], misc[0], f_Ratio_File[0], filtered_Pattern[0],filtered_Pattern[1],textLabel1_11,6);    pushButton35_3->setEnabled(true);
	//sManager->getProcessState(6,&processState,&processDes);
	// if(processState==100) widgetStack5->raiseWidget(0);
	setGUIState();    
}


void Form1::pushButton59_2_2_pressed()
{
	widgetStack5->raiseWidget(3); 
}


void Form1::pushButton59_2_3_clicked()
{
	mainPbc->pbcResetTermination();
	widgetStack5->raiseWidget(4);
	// put default values for nearestNeighbourhood (r-stat)analysis form
	nearest_neighbour_default(0);
}


void Form1::pushButton59_6_clicked()
{
 widgetStack6->raiseWidget(4);     
 // put default values for nearestNeighbourhood (p-value)analysis form
 nearest_neighbour_default(1);
}


void Form1::pushButton59_5_released()
{
 
 
 pushButton35_7->setEnabled(false);
 // pushButton78->setEnabled(false); // by default Next button disabled
 //pushButton27_2_3->setEnabled(true);// by default previous button enabled
 
 filtering_F_Ratio(nameSpace[1], misc[1], f_Ratio_File[1], filtered_Pattern[2], filtered_Pattern[3],textLabel1_11_2,11);    
 setGUIState();
}


void Form1::pushButton59_5_pressed()
{
 widgetStack6->raiseWidget(3);
}





void Form1::pushButton59_4_clicked()
{
	widgetStack6->raiseWidget(2); 
}


void Form1::pushButton59_3_clicked()
{
	widgetStack6->raiseWidget(1);  
}


void Form1::radioButton11_clicked()
{
	groupBox25->setEnabled(true);
}


void Form1::radioButton10_2_clicked()
{
	groupBox25->setEnabled(false);
}


void Form1::radioButton10_2_2_clicked()
{
 groupBox25_2->setEnabled(false);
}
void Form1::radioButton11_2_clicked()
{
 groupBox25_2->setEnabled(true);
}



void Form1::radioButton10_2_2_2_clicked()
{
 groupBox25_2_2->setEnabled(false);
}


void Form1::radioButton11_2_2_clicked()
{
 groupBox25_2_2->setEnabled(true);
 
}


void Form1::pushButton29_4_3_clicked()
{
 mainPbc->pbcResetTermination();
 widgetStack5->raiseWidget(5);
}


void Form1::pushButton59_2_3_2_clicked()
{
 mainPbc->pbcResetTermination();
 widgetStack5->raiseWidget(5);
}

// small_gene_computation 
void Form1::pushButton69_clicked()
{
	QString s;
	bool ok;
	s= lineEdit51->text();
	mainPbc->pbcResetTermination();
	sManager->setProcessState(8,"0");
	reThresholding_SmallGenes(nameSpace[0],s.toDouble(&ok),6);// 6 is the processId of f-ratio calculation
	if(mainPbc->pbcWasCanceled()) { 
		sManager->setProcessState(8,"0");
	}else {
		sManager->setProcessState(8,"100");
	}
	// Do entry in sequence database for GenePredictionResult.xml
	widgetStack5->raiseWidget(0);
	setGUIState();
	paramMg->updateFinalDom();
}


void Form1::pushButton29_5_2_clicked()
{
	widgetStack6->raiseWidget(6);
	
}


void Form1::pushButton69_2_clicked()
{
	QString s;
	bool ok;
	mainPbc->pbcResetTermination();
	s= lineEdit51_2->text();
	sManager->setProcessState(13,"0");
	reThresholding_SmallGenes(nameSpace[1],s.toDouble(&ok), 11);
	
	if(mainPbc->pbcWasCanceled()) { 
		sManager->setProcessState(13,"0");
	}else {
		sManager->setProcessState(13,"100");
	}
 
 widgetStack6->raiseWidget(0);
 setGUIState();
 paramMg->updateFinalDom();
}


void Form1::pushButton71_clicked()
{
 linkResults(0,-1); // smallGene R-stat
}


void Form1::pushButton71_2_clicked()
{
 linkResults(0,-2); // smallGene P-value
}
// saves all orf parameters
//void Form1:: saveORFParameters(){

//}

void Form1::pushButton25_clicked()
{
 mainPbc->pbcResetTermination();
 //saveORFParameters();
 
 rf.executeProcess(seq_work_dir);
 // pushButton15->setEnabled(false);
 
 //pushButton25->setEnabled(false);
 
 //    textLabel3->setText(" ORF computation has been completed");
 widgetStack->raiseWidget(0);
 computeOrfNowPushButton->setEnabled(false);
	pushButton3->setEnabled(true);
	sManager->setProcessState(3,"0");
	sManager->setProcessState(4,"0");
	sManager->setProcessState(5,"0");
	sManager->setProcessState(6,"0");
	sManager->setProcessState(7,"0");
	sManager->setProcessState(8,"0");
	sManager->setProcessState(9,"0");
	sManager->setProcessState(10,"0");
	sManager->setProcessState(11,"0");
	sManager->setProcessState(12,"0");
	sManager->setProcessState(13,"0");
	// initialize maximum minimum fields .
	initialize_max_min_fields();
	
	setGUIState();
	// after completion of ORF , Non Interactive part can be enabled
	radioButton22->setEnabled(true);   
	
}


void Form1::checkBox4_stateChanged( int )
{
 if (!checkBox4->isChecked()) {
  pushButton72->setEnabled(true);
 }else{
  pushButton72->setEnabled(false);
 }
}


void Form1::pushButton72_clicked()
{
 Omega_Peak_Inputs *omgPeak = new Omega_Peak_Inputs(this,"Omega and Peak Location",true,WDestructiveClose);
 omgPeak->From1 = &From1  ;
 omgPeak->From2 = &From2  ;
 omgPeak->Omega_Interval = &Omega_Interval;
 omgPeak->Omega_To = &Omega_To;
 omgPeak->Omega_From=&Omega_From;
 omgPeak->PeakValue = &PeakValue;
 omgPeak->To2=&To2;
 omgPeak->show();
}


void Form1::pushButton76_clicked()
{
 widgetStack5->raiseWidget(0);
}





void Form1::lineEdit8_textChanged( )
{
	
	Gene_Pred::min_max_GUI_validator(_min_range, _max_range, lineEdit8, lineEdit9 );
}




void Form1::lineEdit9_textChanged(  )
{
	
	Gene_Pred::min_max_GUI_validator(_min_range, _max_range, lineEdit8, lineEdit9 );
}


void Form1::lineEdit8_3_textChanged(  )
{
 //R-stat threshold minimum range field checking
 Gene_Pred::min_max_GUI_validator(_min_range_r, _max_range_r, lineEdit8_3, lineEdit9_3 );
}


void Form1::lineEdit9_3_textChanged( )
{
 //R-stat threshold minimum range field checking
 Gene_Pred::min_max_GUI_validator(_min_range_r, _max_range_r, lineEdit8_3, lineEdit9_3 );
}


void Form1::lineEdit8_2_textChanged( )
{
 Gene_Pred::min_max_GUI_validator(_min_range, _max_range, lineEdit8_2, lineEdit9_2 );
}


void Form1::lineEdit9_2_textChanged( )
{
 Gene_Pred:: min_max_GUI_validator(_min_range, _max_range, lineEdit8_2, lineEdit9_2 );
}


void Form1::lineEdit8_3_2_textChanged(  )
{
 Gene_Pred::min_max_GUI_validator(_min_range_p, _max_range_p, lineEdit8_3_2, lineEdit9_3_2 );
}


void Form1::lineEdit9_3_2_textChanged(  )
{
 Gene_Pred::min_max_GUI_validator(_min_range_p, _max_range_p, lineEdit8_3_2, lineEdit9_3_2 );
}







void Form1::pushButton76_2_clicked()
{
	widgetStack6->raiseWidget(0);  
}


void Form1::pushButton59_7_clicked()
{
	widgetStack6->raiseWidget(6);
}


void Form1::pushButton2_clicked()
{
	pushButton4->setEnabled(false);
	eval.Choice = 1; // non interactive mode
	eval.qle = textEdit1_2;
	textEdit1_2->setText("");
	
	
	widgetStack7->raiseWidget(1);
	ReferenceDirectory *referencedirectory;   
	referencedirectory= new ReferenceDirectory(appl,"Reference Directory", true);
	referencedirectory->setOption(eval.Option);
	
	if(referencedirectory->exec()==QDialog::Accepted){
		
	}else{
  widgetStack7->raiseWidget(1);  
 }
 //---------------------------------------------   
 evaluateNow();    
}


void Form1::evaluateNow()
{
 char *s[100];
 QString tmp=QString("");
 // the sequence name, orf+ path, orf- path
 // string *s[100] is to hold the sequnce to be evaluated 
 tmp= QString(sequenceName)+QString("|")+lineEdit53->text()+QString("|")+lineEdit54->text();
 s[0]=(char *)malloc(sizeof(char)*(strlen(tmp.ascii())+1));
 
 strcpy(s[0],tmp);
 
 pushButton4->setEnabled(false);
 //  pushButton79->setEnabled(false);
 eval.qbresult=pushButton4;
 
 if(!eval.readFile(s,seq_work_dir)) widgetStack7->raiseWidget(0); ;
}


void Form1::pushButton82_clicked()
{
 widgetStack7->raiseWidget(0);
}


void Form1::widgetStack7_aboutToShow( int w)
{
 if(w==0 && (lineEdit53->text()=="" || lineEdit54->text()=="")) {
  pushButton2->setEnabled(false);
 }
 
 if(w==1){
  eval.Option = 4;
  if(checkBox6->isChecked()) {
   if(checkBox7->isChecked()) {
				eval.Option =7;
			}else {
				eval.Option =5;
			}
		}else  if(checkBox7->isChecked()) {
			eval.Option =6;
		}
		
		
		
		
	}
	eval.isHypo='\0';
	if(checkBox4_2->isChecked()){
		eval.isHypo = 'Y';
	}else {
		eval.isHypo = 'N';
	}
 
 
 
}


void Form1::radioButton20_clicked()
{
 widgetStack2->raiseWidget(4);  
 setGUIState();
}


void Form1::pushButton4_clicked()
{
 system(QString("oocalc ")+eval.eval_FileName);
}



void Form1::pushButton81_clicked()
{
 char * tmp=(char *)calloc(220,sizeof(char));
 char * tmpfname=(char *)calloc(220,sizeof(char));
 char * tmpfname1=(char *)calloc(220,sizeof(char));
 char * tmpfname2=(char *)calloc(220,sizeof(char));
 char *token=(char *)calloc(220,sizeof(char));
 QString *dirName;
 bool a=false,b=false;
 QFileDialog* fd = new QFileDialog( this );
 fd->setMode(QFileDialog::DirectoryOnly);
 
 if ( fd->exec() == QDialog::Accepted )
 {
  dirName = new QString(fd->selectedFile());
  if(dirName->ascii() =="")
  {
   QMessageBox::warning(this,"File","Please specify the result folder to evaluate");
   
   return;
  }
  QDir  d(dirName->ascii());
  
  //     if(d.count()!=4){
  //      QMessageBox::warning(this,"Warning","Orf + and - files are required ");
  //        pushButton2->setEnabled(false);
  //   } else {
  
  tmp=strcpy(tmp,   (const char *)sequenceFileName->text());
  Gene_Pred::search_char('/',1,&tmpfname, tmp);
  Gene_Pred::search_char('.',2,&tmpfname, tmpfname);
  sprintf(tmpfname1,"%s_ORF+.csv",tmpfname);
  sprintf(tmpfname2,"%s_ORF-.csv",tmpfname);
  for ( unsigned i = 2; i < d.count(); i++ )
  {
   
   strcpy(tmp, d.absFilePath(d[i]));
   Gene_Pred::search_char('/',1,&token,tmp);
   //QMessageBox::information(this,"File","sequence"+QString(tmpfname1)+"   "+token);
   if(strcmp(tmpfname1,token)==0) {
    lineEdit53->setText(tmp);
    a=true;
   }
   if(strcmp(tmpfname2,token)==0){
    lineEdit54->setText(tmp);
    b=true;
   }
   
   if(a&&b)    pushButton2->setEnabled(true);
   
  }
  
 }
}


void Form1::pushButton82_2_clicked()
{
	
	QFileDialog* fd = new QFileDialog( this );
	
	//QMessageBox::information(this,">>>>>>>>>>>",fd->dirPath());
 QString s = fd -> getOpenFileName(
   seq_work_dir,
   "",
   this,
   "open file dialog",
   "Choose a file" );
 lineEdit53->setText(s);
}


void Form1::pushButton83_clicked()
{
 QFileDialog* fd = new QFileDialog( this );
 
 QString s = fd -> getOpenFileName(
   seq_work_dir,
   "",
   this,
   "open file dialog",
   "Choose a file" );
 lineEdit54->setText(s);
}




void Form1::lineEdit17_textChanged( const QString & )
{
 QString s1 = lineEdit17 ->text();
 pushButton35_3->setEnabled(true);
 if(s1.toDouble()<=0) pushButton35_3->setEnabled(false);
 
}


void Form1::lineEdit17_2_returnPressed()
{
 pushButton35_7_clicked();
}


void Form1::lineEdit17_returnPressed()
{
 pushButton35_3_clicked();
}


void Form1::lineEdit17_2_textChanged( const QString & )
{
 
 QString s1 = lineEdit17_2 ->text();
 pushButton35_7->setEnabled(true);
 if(s1.toDouble()<=0) pushButton35_7->setEnabled(false);
 
 
}


void Form1::pushButton163_clicked()
{
 this->showMaximized ();
}


void Form1::pushButton75_clicked()
{ 
 char tmp_str[400];
 
 int _MIN_CHAR,_MAX_CHAR,dec=1;
 QString s;
 bool ok;
 RandomDialog *randForm; 
 int processId =5; // process id for thresholding is 5
 int processState;
 QString stateDescription;
 sManager->getProcessState(processId,&processState,&stateDescription);
 sprintf(tmp_str,"%s/nameSpace_R",seq_work_dir);
 
 // check wheter the random set has already being computed
 if(processState<=20){ // random not yet computed 
  dec=3;
  paramMg->setValueById("270", "false");
  paramMg->setValueById("280", "false"); 
 } else if(processState>20)
 { // random computed 
  paramMg->setValueById("270", "true"); 
  switch(QMessageBox::warning(appl, "Random Sequence compuation",
            "Recompute random sequence or skip", "Recompute", "Skip",0,0,1))
  {
  case 0: // user clicks the recompute
   dec = 1;
   paramMg->setValueById("280", "false"); // dont skip
   break;
  case 1: // user clicks to Skip 
   dec =2;
   paramMg->setValueById("280", "true"); // skip random computation
   break;
  }  
 }
 
 //////////////////////////////////////////////////////// 
 if(dec==1 || dec == 3){
  randForm = new RandomDialog(appl,"Random",true);
  randForm->paramMg = paramMg;
  
  //QMessageBox::warning(0, "warning",seq_work_dir);
  strcpy(randForm->seq_work_dir,seq_work_dir);
  
  s =   lineEdit8_3->text();
  //  s = paramMg->getValueById("290"); // minimum length
  // s = paramMg->getValueById("295");// maximum length
  // s= paramMg->getValueById("300");// purtrubed number
  // s= paramMg->getValueById("305");// number of swap
  // s= paramMg->getValueById("310");// number of mutation
  // s= paramMg->getValueById("300");// purtrubed number
  // s= paramMg->getValueById("315");// number of orf for each sequence
  
  _MIN_CHAR = s.toInt(&ok,10);
  if(_MIN_CHAR<300){
   _MIN_CHAR = 300; 
  }
  randForm->min_range_random = _MIN_CHAR;
  randForm->lineEdit2->setText(QString("%1").arg( _MIN_CHAR,0,10));
  s = lineEdit9_3->text(); 
  _MAX_CHAR = s.toInt(&ok,10);
  randForm->max_range_random=_MAX_CHAR ;
  randForm->lineEdit3->setText(QString("%1").arg( _MAX_CHAR,0,10));
  
  /*
 strcpy(randForm->seq_work_dir,seq_work_dir);
 
 if(inputType == 2) //thresholding is computing on specific min-max length
 { 
  if(MIN_CHAR>=PLR)
  {
   randForm->min_range_random =MIN_CHAR;
   randForm->lineEdit2->setText(QString("%1").arg(MIN_CHAR,0,10));
  }
  else
  {
   randForm->min_range_random = PLR;
   randForm->lineEdit2->setText(QString("%1").arg(PLR,0,10));
  }
  randForm->max_range_random=MAX_CHAR ;
  randForm->lineEdit3->setText(QString("%1").arg(MAX_CHAR,0,10));
 } else 
 {
  if(choice == 1) sprintf(tmp_str,"%s/orf_max_min_R",seq_work_dir);
  if(choice == 2) sprintf(tmp_str,"%s/orf_max_min_P",seq_work_dir);
  fp = fopen(tmp_str,"r"); 
  if(fp)
  {
   fscanf(fp,"%d\t%d", &_min_range, &_max_range);
   fclose(fp);
  }
  if(_min_range>=PLR)
  {
   randForm->min_range_random= _min_range;
   randForm->lineEdit2->setText(QString("%1").arg(_min_range,0,10));
  }else
  {
   randForm->min_range_random= PLR;
   randForm->lineEdit2->setText(QString("%1").arg(PLR,0,10));
  }
  randForm->max_range_random= _max_range;
  randForm->lineEdit3->setText(QString("%1").arg(_max_range,0,10));
 }
 randForm->buttonCancel->setHidden(true);*/
  randForm->checkBox9->setHidden(interactiveMode);
  //MessageBox::warning(appl, "checking  randform state", " just going to open random form");
  randForm->exec();
 }
}





// chenging interactive modes
void Form1::radioButton21_clicked()
{
 
 QMessageBox::warning(appl,"interactive move","You are now in interactive mode\n \n In this mode you have to insert values step by step.");     
 
 interactiveMode =true;
 pushButton74_2->setHidden(true);
 setGUIState();
 //buttonGroup12->setGeometry(22,300,160,130);
 // navigate to main menu otherwise complexity may arise
 widgetStack5->raiseWidget(0);
 widgetStack6->raiseWidget(0);
}

// selecting non-interactive mode
void Form1::radioButton22_clicked()
{
 
 QMessageBox::warning(appl,"Non Interactive Mode","You are now in non interactive mode. \n You have to enter all requird data before running the program");     
 //  buttonGroup12->setGeometry(22,300,160,240);
 interactiveMode=false;
 pushButton74_2->setHidden(false);
 // set the prediction radio button checked and call the clicked event handle;
 predictionRadio->setChecked(true);
 predictionRadio_clicked();
 
 // fill the 
 setGUIState(); 
 widgetStack5->raiseWidget(1);
}


void Form1::pushButton74_clicked()
{
 QWhatsThis::enterWhatsThisMode ();
}


void Form1::tabWidget2_selected( const QString &name )
{
 
 computationPart->setText(QString("Prediction :")+name);
}

void Form1::timerStateShow(){
 //QMessageBox::warning(0,"warning","Timer has been called");
 int h,m,s;
 
 s= t->elapsed()/(1000);
 m = t->elapsed()/(1000*60);
 h = t->elapsed()/(1000*60*60);
 s=s%60;
 m=m%60;
 if(t->isNull()) _elapsedDay ++;
 setGUIState(); 
 textLabel1_27->setText(QString("Elapsed time:\n%1:%2:%3-day(%4)").arg(h,0,10).arg(m,0,10).arg(s,0,10).arg(_elapsedDay,0,10)); 
 
}

void Form1::pushButton75_2_clicked()
{
 // run status updateer
 t=new QTime();
 t->start();
 QTimer *timer = new QTimer( this );
 connect( timer, SIGNAL(timeout()), this, SLOT(timerStateShow() ));
 timer->start( 2000, false ); // 2 seconds single-shot timer
 
 non_interactive_rstat_call();
 
 timer->stop();
 delete timer;  
}


void Form1::checkBox8_stateChanged( int state)
{
 if(state==QButton::On) {
  groupBox3->setEnabled(false);
 } else {
  groupBox3->setEnabled(true);
 }
}


void Form1::lineEdit61_textChanged( const QString &vs )
{
 bool ok;
 int v;
 QString tmps = lineEdit61->text();
 v=vs.toInt(&ok,10);
 int minv = tmps.toInt(&ok,10);
 tmps = lineEdit62->text();
 int maxv = tmps.toInt(&ok,10);
 if(minv>v && ok) {
  lineEdit61->setText(QString( "%1" ).arg(v, 0, 10 ));
  rf.setMinLen(v);
 }
 if(minv>maxv) {
  lineEdit62->setText(QString( "%1" ).arg(v, 0, 10 ));
 }
 rf.setMaxLen(v);
 
}


void Form1::lineEdit62_textChanged( const QString &vs)
{    
 
 bool ok;
 int v;
 QString tmps = lineEdit61->text();
 int minv =tmps.toInt(&ok,10);
 v = vs.toInt(&ok,10);
 // int minv = spinBox1->value();
 if(minv>v &&ok) {
  lineEdit61->setText( QString( "%1" ).arg(v, 0, 10 ));
  rf.setMinLen(v);
 }
 rf.setMaxLen(v);
 /*/*/
}







void Form1::radioButton21_2_toggled( bool )
{
 
 paramMg->getValueFromWdiget("320", radioButton21_2, "QRadioButton");
 
 
 
}


void Form1::radioButton22_2_toggled( bool )
{
 paramMg->getValueFromWdiget("330", radioButton22_2, "QRadioButton");
}


void Form1::checkBox9_clicked()
{
 if(checkBox9->isChecked())
 {
  lineEdit17->setText("");
  lineEdit17->setEnabled(false);
 } else {
  lineEdit17->setEnabled(true);
  paramMg->getValueToWidget("340",  lineEdit17, "QLineEdit");
 }
 
}


void Form1::pushButton74_2_clicked()
{
 widgetStack5->raiseWidget(0);
 pushButton74_2->setEnabled(false);
}


void Form1::predictionRadio_stateChanged( int state)
{
 if ( state == QButton::Off) {
  
 }
}
////////////////////////////  Entry form actions /////////////////////////////////////////
void Form1::initEntryForm(){
 
 lineEdit63->setText(fm->get_default_work_dir());
 
 radioButton33_stateChanged(2); 
 radioButton27_stateChanged(2); 
 
 
 
}

//void Form1::radioButton25_stateChanged( int state)
//{ 
//  if(state==2){

//    radioButton28->setEnabled(false);
//        radioButton27->setChecked(true);
//  }
//}


//void Form1::radioButton26_stateChanged( int state )
//{
// if(state==2){
//     radioButton28->setEnabled(true);
//   radioButton28->setChecked(true);
//chooseSeq->setEnabled(false);
// }
//}


void Form1::radioButton28_stateChanged( int state)
{
 // last used radio button
 //QMessageBox::information(0,"Warning",QString("last State %1").arg(state,0,10));
 if(state ==2){
  pushButton76_3->setEnabled(false);
  //    lineEdit64->setText("/xyz/lastUsedParameter.xml");
  // put the last used parameter
  lineEdit64->setText(sessionMg->getParameterFile());
  lineEdit64->setEnabled(false);
 }
}


void Form1::radioButton27_stateChanged( int state)
{
 if(state ==2){
  pushButton76_3->setEnabled(false);
  lineEdit64->setText(fm->get_default_param_xml());
  lineEdit64->setEnabled(false);
 }
}




void Form1::openSession_clicked()
{
 
 
 // if user selects 'default parameter' or 'choose parameter from the file' option 
 // the selected file copies to the sequence working folder for new session otherwise it will generate a warning
 // ' WARNING: you are going to override the previous parameter file; based on which the application may have 
 // made computation last time. So the result may not map with the new set of parameter with previous result.
 // Do you want to override the previous parameter file.
 bool test=true;
 paramMg = new paramManager( this,fm);
 
 
 if(radioButton27->isChecked() || radioButton29->isChecked())
 {
  QString s= lineEdit64->text();
  if(! paramMg->useNewParameterFile(s))
  {
   delete(paramMg);
   test =false;
  } else 
  {
   setSessionVariableAndStart();
  }
 }else{
  if(!  paramMg-> openExistingParameterFile()){
   delete(paramMg);
   test = false;
   
  }else {
   setSessionVariableAndStart();
  }
 }
 
              //  paramMg->readAndPrepearDom();
 
 
}
void Form1::setSessionVariableAndStart(){
 sequenceFileName->setText(chooseSeq->text());
 
 acceptPath_Ready_for_Computation();
 closeSession->setEnabled(true);
 openSession->setEnabled(false);
 
 
 //  store session variable values to a session.xml  in the same folder
 sessionMg->setFolderName(lineEdit63->text());
 sessionMg->setSequenceFile(chooseSeq->text());
 sessionMg->setParameterFile(lineEdit64->text());
 sessionMg->writeDom(); 
 sessionMg->setSessionOpen();
 sessionSelectionWg->raiseWidget(0);
}

void Form1::radioButton33_stateChanged( int state)
{
 if(state==2) {
  pushButton75_3->setEnabled(false);
  lineEdit63->setEnabled(false);
  lineEdit63->setText(fm->get_default_work_dir());
 }
}
void Form1::radioButton34_stateChanged( int state)
{
 if(state == 2){
  lineEdit63->setEnabled(true);
  pushButton75_3->setEnabled(true);
  lineEdit63->setText("");
 }
}


void Form1::radioButton29_stateChanged( int state )
{
 if(state==2){
  // choose parameter from 
  pushButton76_3->setEnabled(true);
  lineEdit64->setEnabled(true);
  lineEdit64->setText("");
 }
}

//o    fd->setMode(QFileDialog::DirectoryOnly);
void Form1::pushButton75_3_clicked()
{    
 
 QFileDialog* fd = new QFileDialog( this );
 QString dirName;
 
 fd->setMode(QFileDialog::DirectoryOnly);
 if ( fd->exec() == QDialog::Accepted )
 {
  dirName = fd->selectedFile();
  // Check for session file.
  lineEdit63->setText(dirName );
  // get folder name
  /* tmp=strcpy(tmp,   (const char *)lineEdit63->text());
    //Gene_Pred::search_char('/',2,&token,tmp);
    sprintf(seq_work_dir,"%s",tmp);
    fm->set_seq_work_dir(seq_work_dir);*/
  
  
  //   if( radioButton25->isChecked()){
  // new session is going to open
  // check if the folder contain any file and give required warning  and get permission to delete file
  //  }else {
  // existing session is going to open
  //   sessionMg->cehckSessionXML();
  //  }
  
 }
 //if(strcmp(s,"")!=0)   openSession->setEnabled(true);
 
}


bool Form1::updateFolderPathToFileMg(){
 char * tmp=(char *)calloc(420,sizeof(char));
 // get folder name
 tmp=strcpy(tmp,   (const char *)lineEdit63->text());
 //Gene_Pred::search_char('/',2,&token,tmp);
 sprintf(seq_work_dir,"%s",tmp);
 //QMessageBox::warning(0,"from updatefoderpathfileg:",seq_work_dir);
 return fm->set_seq_work_dir(seq_work_dir);
 
}


void Form1::pushButton77_clicked()
{
 if( updateFolderPathToFileMg() ){
 if(sessionMg->openNewSession()){
  // if the new session has been opend successfully
  sessionSelectionWg->raiseWidget(1);
  radioButton28->setEnabled(false);
  chooseSeq->setEnabled(true);
  browseFile->setEnabled(true);
  
 }
} else {
 QMessageBox::information(0,"Warning",QString("The folder dose not exist :")+QString(seq_work_dir));
  
}
}


void Form1::pushButton78_clicked()
{       
 // close any open session
 
 updateFolderPathToFileMg();
 if(sessionMg->openExistingSession()){
  
  //QMessageBox::warning(0,"check file",sessionMg->getSequenceFile());
  // read sequence file name and put to specific field
  chooseSeq->setText(sessionMg->getSequenceFile());
  // read parameter file and put to the field
  
  //lineEdit64->setText(sessionMg->getParameterFile());
  
  
  
  openSession->setEnabled(true);
  sessionSelectionWg->raiseWidget(1);
  // when an existing session has been opend no need to change the sequence name
  browseFile->setEnabled(false);
  chooseSeq->setEnabled(false);
  radioButton28->setEnabled(true);
  radioButton28->setChecked(true);
  radioButton28_stateChanged(2);
 }
 
 
}

//////////////////////////////////  end : Entry form actions ///////////////////////



void Form1::pushButton96_clicked()
{
 // previous button action
 chooseSeq->setText(""); // sequence file name has been reset
 radioButton27_stateChanged(2); // parameter field set to default
 // enable sequence entry fields
 browseFile->setEnabled(true);
 chooseSeq->setEnabled(true);
 sessionSelectionWg->raiseWidget(0);
}


void Form1::radioButton33_clicked()
{
 
}


void Form1::radioButton34_clicked()
{
 
}




void Form1::radioButton27_clicked()
{
 
}


void Form1::radioButton29_clicked()
{
 
}





void Form1::radioButton27_toggled( bool )
{
 
}


void Form1::pushButton76_3_clicked()
{
 QFileDialog* fd = new QFileDialog( this );
 
 if ( fd->exec() == QDialog::Accepted ){
  
  
  // fd -> setDir("$home");
  QString s    = fd->selectedFile();
  lineEdit64->setText(s);
  
 }   
}





void Form1::pushButton74_2_2_released()
{
 widgetStack6->raiseWidget(0);
}


void Form1::pushButton75_2_2_clicked()
{
 // run status updateer
 t=new QTime();
 t->start();
 QTimer *timer = new QTimer( this );
 connect( timer, SIGNAL(timeout()), this, SLOT(timerStateShow()) );
 timer->start( 2000, false ); // 2 seconds single-shot timer
 
 non_interactive_pval_call();
 
 timer->stop();
 delete timer;  
}


void Form1::pushButton75_4_clicked()
{
 char tmp_str[400];
 
 int _MIN_CHAR,_MAX_CHAR,dec=1;
 QString s;
 bool ok;
 RandomDialog *randForm; 
 int processId =5; // process id for thresholding is 5
 int processState;
 QString stateDescription;
 sManager->getProcessState(processId,&processState,&stateDescription);
 sprintf(tmp_str,"%s/nameSpace_P",seq_work_dir);
 
 // check wheter the random set has already being computed
 if(processState<=20){ // random not yet computed 
  dec=3;
  paramMg->setValueById("800", "false");
  paramMg->setValueById("810", "false"); 
 } else if(processState>20)
 { // random computed 
  paramMg->setValueById("800", "true"); 
  switch(QMessageBox::warning(appl, "Random Sequence compuation",
            "Recompute random sequence or skip", "Recompute", "Skip",0,0,1))
  {
  case 0: // user clicks the recompute
   dec = 1;
   paramMg->setValueById("810", "false"); // dont skip
   break;
  case 1: // user clicks to Skip 
   dec =2;
   paramMg->setValueById("810", "true"); // skip random computation
   break;
  }  
 }
 
 //////////////////////////////////////////////////////// 
 if(dec==1 || dec == 3){
  randForm = new RandomDialog(appl,"Random",true);
  randForm->paramMg = paramMg;
  //QMessageBox::warning(0, "warning",seq_work_dir);
  strcpy(randForm->seq_work_dir,seq_work_dir);
  
  s =   lineEdit8_3_2->text();
  //  s = paramMg->getValueById("290"); // minimum length
  // s = paramMg->getValueById("295");// maximum length
  // s= paramMg->getValueById("300");// purtrubed number
  // s= paramMg->getValueById("305");// number of swap
  // s= paramMg->getValueById("310");// number of mutation
  // s= paramMg->getValueById("300");// purtrubed number
  // s= paramMg->getValueById("315");// number of orf for each sequence
  
  _MIN_CHAR = s.toInt(&ok,10);
  if(_MIN_CHAR<300){
   _MIN_CHAR = 300; 
  }
  randForm->min_range_random = _MIN_CHAR;
  randForm->lineEdit2->setText(QString("%1").arg( _MIN_CHAR,0,10));
  s = lineEdit9_3_2->text(); 
  _MAX_CHAR = s.toInt(&ok,10);
  randForm->max_range_random=_MAX_CHAR ;
  randForm->lineEdit3->setText(QString("%1").arg( _MAX_CHAR,0,10));
  
  
  randForm->exec();
 }
}


void Form1::checkBox8_2_stateChanged( int state )
{
 if(state==QButton::On) {
  groupBox3_2->setEnabled(false);
 } else {
  groupBox3_2->setEnabled(true);
 }
}


void Form1::widgetStack6_aboutToShow( int n)
{
 if(n == 0)
 {
  pushButton74_2_2->setEnabled(false);
 } else pushButton74_2_2->setEnabled(true);
 
 
}




void Form1::radioButton21_2_2_toggled( bool )
{
 paramMg->getValueFromWdiget("892", radioButton21_2_2, "QRadioButton");
}


void Form1::radioButton22_2_2_toggled( bool )
{
 paramMg->getValueFromWdiget("894", radioButton22_2_2, "QRadioButton");
}
