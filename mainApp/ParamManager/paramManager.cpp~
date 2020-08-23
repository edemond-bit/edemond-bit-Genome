#include "paramManager.h"
#include <qapplication.h>
#include <qmessagebox.h>
#include <iostream>
#include "File_Manager/File_Manager.h"
#include <qpushbutton.h>
#include <qradiobutton.h>
#include <qbutton.h>
#include <qgroupbox.h>
#include <qcheckbox.h>
paramManager::paramManager(QWidget *parent, File_Manager *f)
{

    fm = f; 					// file 
    appl =(Form1 *) parent; 			// main application  
}
// set new parameter file to use
bool paramManager::useNewParameterFile(const char *s){
 
  __finalFileName = fm->get_final_param_xml();
  __finalFile.setName(__finalFileName);

  if ( QFile::exists(__finalFileName ) &&
        QMessageBox::question(
            0,
            QApplication::tr("Overwrite File? inputParam.xml"),
            QApplication::tr("You are going to override exising inputParam.xml file.\n"
                "Are you sure that you want to overwrite it?")
                .arg( __finalFileName ),
            QApplication::tr("&Yes"), QApplication::tr("&No"),
            QString::null, 0, 1 ) )
        return false;
        

   char tmp[400];
   //QMessageBox::warning(0,"check",__finalFileName);
   sprintf(tmp,"cp %s %s", s, (const char *) __finalFileName);


   if(system(tmp)==-1) {
        QMessageBox::critical(0,"Critical error", "default parameter file can not be copied to destination");
        return false;
   }

   __finalFile.setName(__finalFileName);
   createWidgetMap(); 
   readAndPrepearDom();
   populateFields();
   __finalFile.close();
   return true;
}

bool paramManager::openExistingParameterFile(){
   __finalFileName = fm->get_final_param_xml();
   __finalFile.setName(__finalFileName);
   if(!__finalFile.exists()){
   
        QMessageBox::critical(0,"Critical error", "Parameter file cannot be opened as it dose not exist");
        return false;
   }


createWidgetMap(); 
   readAndPrepearDom();
   populateFields();
   __finalFile.close();
return true;
}


// reads and populate fields from inputParamXML
void paramManager::readAndPrepearDom(){


   if(  __finalFile.open( IO_ReadWrite)){
        
   }else{

       
           QMessageBox::critical(0,  QApplication::tr("Critical Error") , QApplication::tr("Can not open file %1").arg(__defaultFileName));
        
   }
   // read the file to __finalDom

    if ( !__finalDom.setContent( &__finalFile ) ) {
        QMessageBox::critical( 0,   QApplication::tr( "Critical Error" ),
                QApplication::tr( "Parsing error for file %1" ).arg(__finalFileName) );
        __finalFile.close();
        return;
    }

    __finalFile.close();
}

// search an item from dom by id
// returns the index of the __nodeList
int paramManager::foundNodeById(QString id){
     QDomNode tmpNode;
     QDomNamedNodeMap nnm;
     int i;
     bool found=false;
     int nodeCount = __nodeList.count();
     for( i = 0;i<nodeCount;i++){
     	tmpNode = __nodeList.item(i);
        nnm = tmpNode.attributes();
        if(strcmp(id, (nnm.namedItem("id")).nodeValue())==0){
       //  QMessageBox::warning(0,"warning  match found",QApplication::tr(" search id=%1, matched id=%2").arg(id,(nnm.namedItem("id")).nodeValue()));
         found = true;
         break;
       }
     }
    return found? i:-1;
}

// get raw (string) value of id 
QString paramManager::getValueById(QString id){
     int index;
     QDomNode tmpNode;
     QDomNamedNodeMap nnm;
     index = foundNodeById(id);
     if(index>=0){
       tmpNode = __nodeList.item(index);
        nnm = tmpNode.attributes();
       return (nnm.namedItem("value")).nodeValue();
       //setWidgetValue(id,value);
     } else {
      // QMessageBox::warning(0,"Warning", QApplication::tr("<function:getValueById>Id= %1 not found").arg(id));
       return "";
     }

}

// get value from xml dom and set the value to widget reference is id

void paramManager::getValueToWidget(QString id, QWidget *wdg, QString widgetType)
{
   QString value = getValueById(id);
   //////////////////////////////////
   if(strcmp(widgetType,"QLineEdit")==0){
     
        ((QLineEdit *)wdg)->setText(value);
    }else if(strcmp(widgetType,"QRadioButton")==0){
       if(value=="true"){
          ((QRadioButton *)wdg)->setChecked(true);
            
        }else if(value=="false") {
          ((QRadioButton *)wdg)->setChecked(false);
        }
        

    } else if(strcmp(widgetType,"QCheckBox")==0){
        if(value=="true"){
            ((QCheckBox *)wdg)->setChecked(true);
            
        }else if(value=="false") {
           ((QCheckBox *)wdg)->setChecked(false);
        }
        

   }
}

// get the value from widget and set to xml dom
void paramManager::getValueFromWdiget(QString id, QWidget *wdg, QString widgetType){
 
QString value="";

    if(strcmp(widgetType,"QLineEdit") == 0 ){
     
      value=((QLineEdit *)wdg)->text();
    }else if(strcmp(widgetType,"QRadioButton") == 0){

         if(((QRadioButton *)wdg)->isChecked () ){

            value="true";
        }else {
            value="false";
        }
        

    } else if(strcmp(widgetType,"QCheckBox") == 0 ){

         if(((QCheckBox *)wdg)->isChecked () ){

            value = "true";
        }else {
            value = "false";
        }
        

   }

  if(strcmp(value,"")==0) {
    QMessageBox::warning(0,"warning",QApplication::tr("<function:getValueFromWidget> Could not read the value of the widget (type %1)").arg(widgetType));
  } else {
     setValueById(id,  value);
  }


}

// set node value by id

void paramManager::setValueById(QString id, QString value){
   int index;
   QDomNode tmpNode;
     QDomNamedNodeMap nnm;
     index = foundNodeById(id);
     if(index>=0){
          tmpNode = __nodeList.item(index);
          nnm = tmpNode.attributes();
          nnm.namedItem("value").setNodeValue(value);
     } else {
          // QMessageBox::warning(0,"Warning", QApplication::tr("<function:setValueById> Id= %1 not found").arg(id));
     }
}

// populate fields
void paramManager::populateFields(){
     int nodeCount=0;
     QString id;
     QString value;
     QDomNode tmpNode;
     QDomNamedNodeMap nnm;
     __nodeList = __finalDom.elementsByTagName("param");
     nodeCount = __nodeList.count();
     for(int i = 0;i<nodeCount;i++){
     	tmpNode = __nodeList.item(i);
        nnm = tmpNode.attributes();
      
      // QMessageBox::warning(0,"warning",(nnm.namedItem("id")).nodeValue());
        id = (nnm.namedItem("id")).nodeValue();
        value =(nnm.namedItem("value")).nodeValue();
        setWidgetValue(id,value);
    
     }
   

}

// update finalDom with the updated field values
void paramManager::updateFinalDom(){
    QDomNode tmpNode;
     QDomNamedNodeMap nnm;
    QString id,tmp;

 int nodeCount = __nodeList.count();
     for(int i = 0;i<nodeCount;i++){
     	tmpNode = __nodeList.item(i);
        nnm = tmpNode.attributes();
      
      // QMessageBox::warning(0,"warning",(nnm.namedItem("id")).nodeValue());
        id = (nnm.namedItem("id")).nodeValue();
     tmp = getWidgetValue(id,"main");
if(tmp!="*")
     (nnm.namedItem("value")).setNodeValue(tmp);
        //setWidgetValue(id,value);
    
     }
   //QMessageBox::warning(0,"warning", __finalDom.toString());
   
// write updated parameter xml to file
    QFile file( __finalFileName );
    if ( file.open( IO_WriteOnly ) ) {
        QTextStream stream( &file );
       // for ( QStringList::Iterator it = lines.begin(); it != lines.end(); ++it )
            stream << __finalDom.toString();
        file.close();
    }




}


// create widget map
void paramManager::createWidgetMap(){
// ORF
  //sequence length
  mapWidget["10"] = (QWidget *) appl->radioButton7; mapWidgetType["10"] = "QRadioButton";
  mapWidget["11"] = (QWidget *) appl->radioButton8; mapWidgetType["11"] = "QRadioButton";
  mapWidget["12"] = (QWidget *) appl->lineEdit61; mapWidgetType["12"] = "QLineEdit";
  mapWidget["13"] = (QWidget *) appl->lineEdit62; mapWidgetType["13"] = "QLineEdit";
  //--end:sequence length
  
  // codon
  mapWidget["20"] = (QWidget *) appl->lineEdit3; mapWidgetType["20"] = "QLineEdit";
  mapWidget["21"] = (QWidget *) appl->lineEdit4; mapWidgetType["21"] = "QLineEdit";
  // --end: codon
  
  // filter sequence
  mapWidget["30"] = (QWidget *) appl->radioButton9; mapWidgetType["30"] = "QRadioButton";
  mapWidget["31"] = (QWidget *) appl->radioButton10; mapWidgetType["31"] = "QRadioButton";
  // -- end:filter
  
  // save orf file
  mapWidget["40"] = (QWidget *) appl->checkBox2; mapWidgetType["40"] = "QCheckBox";
  // -- end: save orf file

  // Prediction 
  // ---------------------------------  R-Stat --------------------------------------
  //--sequence length
  mapWidget["110"] = (QWidget *) appl->radioButton10_2; mapWidgetType["110"] = "QRadioButton";
  mapWidget["111"] = (QWidget *) appl->radioButton11; mapWidgetType["111"] = "QRadioButton";
  mapWidget["112"] = (QWidget *) appl->lineEdit8; mapWidgetType["112"] = "QLineEdit";
  mapWidget["113"] = (QWidget *) appl->lineEdit9; mapWidgetType["113"] = "QLineEdit";
  //--end:sequence length
   mapWidget["120"] = (QWidget *) appl->lineEdit10; mapWidgetType["120"] = "QLineEdit";
   mapWidget["130"] = (QWidget *) appl->checkBox3; mapWidgetType["130"] = "QCheckBox";
   mapWidget["131"] = (QWidget *) appl->lineEdit11; mapWidgetType["131"] = "QLineEdit";
   mapWidget["140"] = (QWidget *) appl->lineEdit45; mapWidgetType["140"] = "QLineEdit";
  //----------------------------------- R-stat --------------------------------------
  //----------------------------------- Threshold --------------------------------------
mapWidget["200"] = (QWidget *) appl->lineEdit_File_PGS; mapWidgetType["200"] = "QLineEdit";
mapWidget["210"] = (QWidget *) appl->lineEdit_File_PNPS; mapWidgetType["210"] = "QLineEdit";
mapWidget["220"] = (QWidget *) appl->lineEdit_File_PNGS; mapWidgetType["220"] = "QLineEdit";

  //--sequence length
  mapWidget["230"] = (QWidget *) appl->radioButton10_2_2; mapWidgetType["230"] = "QRadioButton";
  mapWidget["231"] = (QWidget *) appl->radioButton11_2; mapWidgetType["231"] = "QRadioButton";
  mapWidget["232"] = (QWidget *) appl->lineEdit8_3; mapWidgetType["232"] = "QLineEdit";
  mapWidget["233"] = (QWidget *) appl->lineEdit9_3; mapWidgetType["233"] = "QLineEdit";

 mapWidget["240"] = (QWidget *) appl->checkBox4; mapWidgetType["240"] = "QCheckBox";
  mapWidget["250"] = (QWidget *) appl->lineEdit15; mapWidgetType["250"] = "QLineEdit";
  mapWidget["260"] = (QWidget *) appl->lineEdit16; mapWidgetType["260"] = "QLineEdit";
  //----------------------------------- Threshold --------------------------------------

// threshold for fratio
 mapWidget["339"] = (QWidget *) appl->checkBox9; mapWidgetType["339"] = "QCheckBox";
  mapWidget["340"] = (QWidget *) appl->lineEdit17; mapWidgetType["340"] = "QLineEdit";

//----------------------
// -------------------- nearest neighbour hood ------------------------------------
mapWidget["350"] = (QWidget *) appl->lineEdit19; mapWidgetType["350"] = "QLineEdit";
mapWidget["360"] = (QWidget *) appl->lineEdit19_2; mapWidgetType["360"] = "QLineEdit";
  mapWidget["470"] = (QWidget *) appl->radioButton17; mapWidgetType["470"] = "QRadioButton";
  mapWidget["480"] = (QWidget *) appl->radioButton16; mapWidgetType["480"] = "QRadioButton";
mapWidget["490"] = (QWidget *) appl->lineEdit19_3; mapWidgetType["490"] = "QLineEdit";
mapWidget["500"] = (QWidget *) appl->lineEdit19_4; mapWidgetType["500"] = "QLineEdit";
mapWidget["510"] = (QWidget *) appl->lineEdit19_5; mapWidgetType["510"] = "QLineEdit";
mapWidget["520"] = (QWidget *) appl->lineEdit19_6; mapWidgetType["520"] = "QLineEdit";
mapWidget["530"] = (QWidget *) appl->lineEdit19_7; mapWidgetType["530"] = "QLineEdit";
 mapWidget["540"] = (QWidget *) appl->checkBox8; mapWidgetType["540"] = "QCheckBox";
// ---------------------nearest neighbour hood ------------------------------------
// --------------------- rethresholding fro small gene ---------------------------

mapWidget["550"] = (QWidget *) appl->lineEdit51; mapWidgetType["550"] = "QLineEdit";
//--------------------------------------------------------------------------------
  //----------------------------P-Value ------------------------------------------
  
  //--sequence length
 mapWidget["600"] = (QWidget *) appl->radioButton9_2; mapWidgetType["600"] = "QRadioButton";
 mapWidget["610"] = (QWidget *) appl->radioButton8_2; mapWidgetType["610"] = "QRadioButton";
  mapWidget["620"] = (QWidget *) appl->lineEdit8_2; mapWidgetType["620"] = "QLineEdit";
  mapWidget["630"] = (QWidget *) appl->lineEdit9_2; mapWidgetType["630"] = "QLineEdit";
   //--end:sequence length
   mapWidget["640"] = (QWidget *) appl->lineEdit10_2; mapWidgetType["640"] = "QLineEdit";
   mapWidget["650"] = (QWidget *) appl->checkBox3_2; mapWidgetType["650"] = "QCheckBox";
   mapWidget["660"] = (QWidget *) appl->lineEdit11_2; mapWidgetType["660"] = "QLineEdit";
   mapWidget["670"] = (QWidget *) appl->lineEdit45_2; mapWidgetType["670"] = "QLineEdit";
   // --- montecarlo
   mapWidget["680"] = (QWidget *) appl->lineEdit29; mapWidgetType["680"] = "QLineEdit";
   // -- swap
   mapWidget["690"] = (QWidget *) appl->lineEdit30; mapWidgetType["690"] = "QLineEdit";
   // ---- mutation
   mapWidget["700"] = (QWidget *) appl->lineEdit31; mapWidgetType["700"] = "QLineEdit";
   //----------------------------  THRESHOLD ------------------------------------------
    mapWidget["710"] = (QWidget *) appl->lineEdit_File_PGS_2; mapWidgetType["710"] = "QLineEdit";
   mapWidget["720"] = (QWidget *) appl->lineEdit_File_PNPS_2; mapWidgetType["720"] = "QLineEdit";
   mapWidget["730"] = (QWidget *) appl->lineEdit_File_PNGS_2; mapWidgetType["730"] = "QLineEdit";

  //--sequence length
  mapWidget["740"] = (QWidget *) appl->radioButton10_2_2_2; mapWidgetType["740"] = "QRadioButton";
  mapWidget["750"] = (QWidget *) appl->radioButton11_2_2; mapWidgetType["750"] = "QRadioButton";
  mapWidget["760"] = (QWidget *) appl->lineEdit8_3_2; mapWidgetType["760"] = "QLineEdit";
  mapWidget["770"] = (QWidget *) appl->lineEdit9_3_2; mapWidgetType["770"] = "QLineEdit";
  // P-value for gene
  mapWidget["780"] = (QWidget *) appl->lineEdit15_2; mapWidgetType["780"] = "QLineEdit";
  // p-value for non-gene
  mapWidget["790"] = (QWidget *) appl->lineEdit16_2; mapWidgetType["790"] = "QLineEdit";
 
   //----------------------------  END: THRESHOLD -------------------------------------
   // threshold for fratio
 mapWidget["895"] = (QWidget *) appl->checkBox9_2; mapWidgetType["895"] = "QCheckBox";
  mapWidget["897"] = (QWidget *) appl->lineEdit17_2; mapWidgetType["897"] = "QLineEdit";
  
  // -------------------- nearest neighbour hood ------------------------------------
mapWidget["900"] = (QWidget *) appl->lineEdit19_8; mapWidgetType["900"] = "QLineEdit";
mapWidget["910"] = (QWidget *) appl->lineEdit19_2_2; mapWidgetType["910"] = "QLineEdit";
  mapWidget["920"] = (QWidget *) appl->radioButton17_2; mapWidgetType["920"] = "QRadioButton";
  mapWidget["930"] = (QWidget *) appl->radioButton16_2; mapWidgetType["930"] = "QRadioButton";
mapWidget["940"] = (QWidget *) appl->lineEdit19_3_2; mapWidgetType["940"] = "QLineEdit";
mapWidget["950"] = (QWidget *) appl->lineEdit19_4_2; mapWidgetType["950"] = "QLineEdit";
mapWidget["960"] = (QWidget *) appl->lineEdit19_5_2; mapWidgetType["960"] = "QLineEdit";
mapWidget["970"] = (QWidget *) appl->lineEdit19_6_2; mapWidgetType["970"] = "QLineEdit";
mapWidget["980"] = (QWidget *) appl->lineEdit19_7_2; mapWidgetType["980"] = "QLineEdit";
 mapWidget["990"] = (QWidget *) appl->checkBox8_2; mapWidgetType["990"] = "QCheckBox";
// ---------------------nearest neighbour hood ------------------------------------
// --------------------- rethresholding fro small gene ---------------------------

mapWidget["1000"] = (QWidget *) appl->lineEdit51_2; mapWidgetType["1000"] = "QLineEdit";
//--------------------------------------------------------------------------------

  
  //----------------------- END P-VALUE ------------------------------------------
  // test code --------------------------
  //  setWidgetValue("20","MAP CHECKING");
  //  setWidgetValue("11","true");
}



// createWidgetMap for randomForm
// The map is created when randomForm is being initialized. 
// this function is called from randomForm constructor
// void paramManager::createWidgetMapRandom(){
//}


// createWidgetMap for omegaValue
// The map is created when OmegaValue dialog is being initialized. 
// this function is called from  OmegaValue dialog constructor
// void paramManager::createWidgetMapOmegaValue(){
//}



// get widget values
QString paramManager::getWidgetValue(QString id, QString container){
// values reading from main container
if(strcmp(container,"main")==0) {
    if(mapWidget.find(id)!=mapWidget.end()){
    // QMessageBox::warning(appl,"warning",mapWidgetType[id]);
    if(strcmp(mapWidgetType[id],"QLineEdit")==0){
     
      return ((QLineEdit *)mapWidget[id])->text();
    }else if(strcmp(mapWidgetType[id],"QRadioButton")==0){

         if(((QRadioButton *)mapWidget[id])->isChecked () ){

            return "true";
        }else {
            return "false";
        }
        

    } else if(strcmp(mapWidgetType[id],"QCheckBox")==0){

         if(((QCheckBox *)mapWidget[id])->isChecked () ){

            return "true";
        }else {
            return "false";
        }
        

   }


  } else {
   // QMessageBox::warning(0,"warning",  QApplication::tr("function :<getWidgetValue> Can not find id= %1").arg(id));
  return "*";
  }

// values read from randomForm

// values read from omegavalue dialog

}
return "";


}


// set widget values
void paramManager::setWidgetValue(QString id, QString value)
{
if(mapWidget.find(id)!=mapWidget.end()){
/*
if(strcmp(id,"600")==0)  {
((QRadioButton *)mapWidget[id])->setChecked(true);
QMessageBox::warning(appl,"warning",mapWidgetType[id]);
QMessageBox::warning(appl,"warning id",id); 
}*/
    
     
     
 if(strcmp(mapWidgetType[id],"QLineEdit")==0){
     ((QLineEdit *)mapWidget[id])->setText(value);
  }else if(strcmp(mapWidgetType[id],"QRadioButton")==0){
      if(strcmp(value,"true") == 0) {
          ((QRadioButton *)mapWidget[id])->setChecked(true);
        } else {
       ((QRadioButton *)mapWidget[id])->setChecked(false);
      }

  } else if(strcmp(mapWidgetType[id],"QCheckBox")==0){
     
      if(strcmp(value,"true") == 0) {
          ((QCheckBox *)mapWidget[id])->setChecked(true);

        } else {
       ((QCheckBox *)mapWidget[id])->setChecked(false);
      }
  }

changeDependentControls(); 
} else {
    //QMessageBox::warning(0,"warning",  QApplication::tr("Can not find id= %1").arg(id));
}
}
/**
Check and execute state dependent functions 
*/// createWidgetMap for randomForm
// The map is created when randomForm is being initialized. 
// this function is called from randomForm constructor
// void paramManager::createWidgetMapRandom(){
//{

void paramManager::changeDependentControls(){
// ORF
if(appl->radioButton7->isChecked()) appl->radioButton7_clicked();
if(appl->radioButton8->isChecked()) appl->radioButton8_clicked();
if(appl->radioButton9->isChecked()) appl->radioButton9_clicked();
if(appl->radioButton10->isChecked()) appl->radioButton10_clicked();
appl->checkBox2_toggled(appl->checkBox2->isChecked());
// R-stat
 //-----R-statistics
if(appl->radioButton10_2->isChecked()) appl->radioButton10_2_clicked();
if(appl->radioButton11->isChecked()) appl->radioButton11_clicked();
if(appl->checkBox3->isChecked()) appl->checkBox3_clicked();
// ---- threshold
if(appl->radioButton10_2_2->isChecked()) appl->radioButton10_2_2_clicked();
if(appl->radioButton11_2->isChecked()) appl->radioButton11_2_clicked();

if(appl->checkBox4->isChecked()) appl->checkBox4_stateChanged(0);

// P-Val
if(appl->radioButton9_2->isChecked()) appl->radioButton9_2_clicked();
if(appl->radioButton8_2->isChecked()) appl->radioButton8_2_clicked();

if(appl->checkBox3_2->isChecked()) appl->checkBox3_2_clicked();
// threshold p-val
if(appl->radioButton11_2_2->isChecked()) appl->radioButton11_2_2_clicked();
if(appl->radioButton10_2_2_2->isChecked()) appl->radioButton10_2_2_2_clicked();
}



paramManager::~paramManager(){

}
