#include "File_Manager.h"
#include "qmessagebox.h"
#include "qapplication.h"
#include "qdir.h"

// File_Manager constructor
File_Manager::File_Manager(){
    path_orf = (const char *)calloc(sizeof(char ),400);
    seq_name = (const char *)calloc(sizeof(char ),400);
    path_seq = (const char *)calloc(sizeof(char ),400);
    path_seq_folder = (const char *)calloc(sizeof(char ),400);
    application_home = (char *)Gene_Pred::pwd();
    // parameter xml file
    standerdParameterXML = (char *)calloc(sizeof(char ),400);
    defaultParameterXML = (char *)calloc(sizeof(char ),400); 
    finalParamXML = (char *) calloc(sizeof(char ), 400);
    defaultWorkDir = (char *) calloc(sizeof(char ), 400);
     sessionXML = (char *) calloc(sizeof(char ), 400);
    // set standerd Parameter XML file with path
   char *tmps=(char *)standerdParameterXML;
   sprintf(tmps,"%s/standardParam.xml", application_home);
   printf("\n standardParameter xml:%s\n", standerdParameterXML);

   tmps=(char *)defaultParameterXML;
   sprintf(tmps,"%s/defaultParam.xml", application_home);
   //QMessageBox::warning(0,"warning", standerdParameterXML);
   
   // default working directory
   tmps=(char *)defaultWorkDir;
   sprintf(tmps,"%s/defaultWorkDir/", application_home);

};


// returns application home directory
const char *File_Manager::get_application_home()
{
 char *tmp = (char *) application_home;
 return (const char *)tmp;
}

// returns default working directory path
const char *File_Manager::get_default_work_dir()
{
 char *tmp = (char *) defaultWorkDir;
 return (const char *)tmp;
}



// openPath function returns the sequence file name
const char *File_Manager::get_seq_path()
{
  FILE *fp;
  char *tmp_path_seq=(char *)path_seq;
  char *tmps=(char *)malloc(sizeof(char)*300);
  sprintf(tmps,"%s/Path",path_seq_folder);
 
  fp = fopen(tmps,"r");
  if(fp != NULL)
    {
      fscanf(fp,"%s",tmp_path_seq);
    } else 
    { 
       printf("Path - file dose not exist");
    }   
 fclose(fp);
  return path_seq;
}
// returns sequence_working directory
const char *File_Manager::get_seq_work_dir(){
 char *tmp = (char *)path_seq_folder;
 return (const char *)tmp;
}
// returns registry file of all orfs of a sequcne if exist
const char *File_Manager::get_path_ORF()
{
 
 char *tmp=(char *)path_orf;
  sprintf(tmp,"%s/path_ORF",(char *)get_seq_work_dir());
  return (const char *)path_orf;
}
//
bool File_Manager::set_seq_work_dir( char *swd)
{
 bool val;
 if( QFile::exists(swd) ) {
  static bool flag=false;
  char *tmp;

     tmp=(char *)path_seq_folder;
     sprintf(tmp,"%s",swd);
     flag=true;


   tmp=(char *)finalParamXML;
   sprintf(tmp,"%s/inputParam.xml", path_seq_folder);
    tmp=(char *)sessionXML;
    sprintf(tmp,"%s/session.xml",path_seq_folder);
    val = true;
    } else  val= false;
    return val;

}

// returns the defaultParamXML filename
const char *File_Manager::get_default_param_xml(){
 char *tmp=(char *)defaultParameterXML;
 return (const char *)tmp;
}

// return standaredParamXml filename
const char *File_Manager::get_standerd_param_xml(){
 char *tmp=(char *)standerdParameterXML;
 return (const char *)tmp;
}
// return finalParamXML filename
const char *File_Manager::get_final_param_xml(){
 char *tmp=(char *)finalParamXML;
 return (const char *)tmp;
}
// return session xml file name
const char *File_Manager::getSessionFile(){
  char *tmp=(char*) sessionXML;
  return (const char *)tmp;
}

bool File_Manager::isEmptyWorkingDir(){
QDir d(path_seq_folder);

if(d.count()>2) {
return false;

}



return true;
}

bool File_Manager::makeWorkingDirectoryEmpty(){
QDir d(path_seq_folder);
char *tmp=(char *) malloc(sizeof(char)*400);
if (  QMessageBox::critical(
           0, QApplication::tr("Critial warning"),
             QApplication::tr(QString("Folder containts %1 no of file and working direcotories\n\nDo you want to delete all file and folders?").arg(d.count()-2,0,10)),
             QApplication::tr("&Yes"),  QApplication::tr("&No"),
            QString::null, 0, 1 ) )
     return false;
if (  QMessageBox::critical(
           0, QApplication::tr("Critial warning"),
             QApplication::tr(QString("************* \nARE YOU SURE YOU ARE GOING TO DELETE THE FOLDER %1?\n*************").arg(path_seq_folder)),
             QApplication::tr("&Yes"),  QApplication::tr("&No"),
            QString::null, 0, 1 ) )
         return false;

// delete all files and folder
sprintf(tmp,"rm -rf %s", path_seq_folder);
system(tmp);
// create empty working directory
sprintf(tmp,"mkdir  %s", path_seq_folder);
system(tmp);
return true;

}

// destructor
File_Manager::~File_Manager()
{

}

//


