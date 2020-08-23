#include "sessionManager.h"
#include <qapplication.h>
#include <qmessagebox.h>
#include <iostream>
#include <qdatetime.h> 
#include "File_Manager/File_Manager.h"

// constructor
sessionManager::sessionManager( QWidget *parent, File_Manager *f){

appl = parent;
fm = f;
opened = false;
}

// open existing file
bool sessionManager::openExistingSession(){
// search for session.xml
// if session.xml not found warning generate that the session.xml file dose not exist for the folder and exit
if(cehckSessionXML()){
// populate the sequenceFileName and parameterFileName fields from sessionXML data
 readSessionFile();

 return true;
}
// if session.xml exist check for time stamp if all are previous or same as the clossing session time
//     if the last check is false   give an warning that file has been modified after closing the session so problem may arrise
// start the session 
return false;
}

// return the sequence file name from the xml file
QString sessionManager::getSequenceFile(){
    return __DomSequenceName.attribute("path");
}

// return the parameter file name from the xml file
QString sessionManager::getParameterFile(){
    return __DomParamFileName.attribute("path");
}


// open a new session
bool sessionManager::openNewSession(){
// check if the folder is empty. If not empty ask to make empty the folder
// if user choose to delete all file delete all files and folder recursively
if(!fm->isEmptyWorkingDir())
if(!fm->makeWorkingDirectoryEmpty()){
   return false ;
}

// get session file(session.xml) name where to write the session data 
__sessionFileName = fm->getSessionFile();
// initilize the dom
initalizeDom();
// set the file name to file object
__sessionFile.setName( __sessionFileName);
setStartTime();
// set the stop time to zero
__DomStopTime.setAttribute("time","0");
return true;
}

// set start time
void sessionManager::setStartTime(){
// set the start time to the current system time
__DomStartTime.setAttribute("time",QTime::currentTime().toString());
}

// set the stop time
// this function must be called at the time of clossing the session

void sessionManager::setCloseTime(){
__DomStopTime.setAttribute("time",QTime::currentTime().toString());
}



bool sessionManager::cehckSessionXML(){

__sessionFileName = fm->getSessionFile();
__sessionFile.setName( __sessionFileName);
  if(!__sessionFile.exists()) {
      QMessageBox::warning(appl,"Warning", QApplication::tr("%1 file dose not exists.\n Hence session cannot be opened.").arg(__sessionFileName));
      return false;
  } 
return true;
}

// set folderName
void sessionManager::setFolderName(QString s){
//QMessageBox::warning(0,"warning", s);
  __DomFolderName.setAttribute("path",s);
}

//set sequenceName
void sessionManager::setSequenceFile(QString s){
  __DomSequenceName.setAttribute("path",s);
}

//set parameterName
void sessionManager::setParameterFile(QString s){
   __DomParamFileName.setAttribute("path",s);
}


// read session file
void sessionManager::readSessionFile(){
 QDomNode tmp;

    if ( !__sessionDom.setContent( &__sessionFile ) ) {
        QMessageBox::critical( 0,QApplication::tr( "Critical Error" ),QApplication::tr( "Parsing error for file %1" ).arg( __sessionFileName ) );
        __sessionFile.close();
        return;
    }
    __sessionFile.close();
    // map nodes
    __DomRoot = __sessionDom.documentElement();
    // sequence name
    tmp = __DomRoot.firstChild();
    __DomSequenceName = tmp.toElement();
    // folder name
    tmp=__DomSequenceName.nextSibling();
    __DomFolderName= tmp.toElement();

    //parameter name
    tmp=__DomFolderName.nextSibling();
    __DomParamFileName= tmp.toElement();
    
    // start time
       tmp=__DomParamFileName.nextSibling();
    __DomStartTime= tmp.toElement();

    // end time
      tmp=__DomStartTime.nextSibling();
   __DomStopTime= tmp.toElement();

    // histroy 
          tmp=__DomStopTime.nextSibling();
  __DomHistory= tmp.toElement();

    
}



// write session XML to the file
void sessionManager::writeDom()
{
 std::cout<<"writing session file";
    if(!__sessionFile.open( IO_WriteOnly))
    {
 QMessageBox::critical(0,  QApplication::tr("Critical Error") , QApplication::tr("Can not open file %1").arg(__sessionFileName));
    } 


     QTextStream stream( &__sessionFile);
     QString line =  __sessionDom.toString();
     stream<<line;
    __sessionFile.close();

      std::cout<<line;

}
void sessionManager::setSessionOpen(){
opened = true;
}
void sessionManager::initalizeDom()
{
__sessionDom=QDomDocument("sesion");
   // create elements
   __DomRoot=__sessionDom.createElement("session");
   __DomSequenceName =__sessionDom.createElement("sequence");
   __DomFolderName =__sessionDom.createElement("folder");
   __DomParamFileName = __sessionDom.createElement("parameterFile");
   __DomStartTime = __sessionDom.createElement("startTime");
   __DomStopTime = __sessionDom.createElement("stopTime");
   __DomHistory = __sessionDom.createElement("history");

   __DomSequenceName.setAttribute("path","");
   __DomFolderName.setAttribute("path","");
   __DomParamFileName.setAttribute("path","");

   __sessionDom.appendChild(__DomRoot);
   __DomRoot.appendChild(__DomSequenceName);
   __DomRoot.appendChild(__DomFolderName);
   __DomRoot.appendChild(__DomParamFileName);
   __DomRoot.appendChild(__DomStartTime);
   __DomRoot.appendChild(__DomStopTime);
   __DomRoot.appendChild(__DomHistory);
  
  // QString xml = __sessionDom.toString();
     // std::cout<<xml;
   
   
}
void sessionManager::closeSession(){
 setCloseTime();
}

 sessionManager::~sessionManager(){
}
