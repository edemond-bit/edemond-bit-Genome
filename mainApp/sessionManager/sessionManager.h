#ifndef __SESSION_MANAGER
#define __SESSION_MANAGER

#include <iostream>
#include <qdatetime.h> 
#include <qdom.h>
#include <stdlib.h>
#include <stdio.h>
#include <qfile.h>
#include <qwidget.h>
#include "../Static_Lib/Gene_Prediction_Lib.h"
#include "File_Manager/File_Manager.h"
class sessionManager
{
 private:
     const char *__folderPath;
     const char *__sequencePath;
     const char *__parameterPath;
     const char *__sessionFileName;
     
      bool opened;

     QWidget *appl;
     File_Manager *fm;
     QFile __sessionFile;
     QDomDocument __sessionDom;

     QDomElement __DomRoot;
     QDomElement __DomSequenceName;
     QDomElement __DomFolderName;
     QDomElement __DomParamFileName;
     QDomElement __DomStartTime;
     QDomElement __DomStopTime;
     QDomElement __DomHistory;

     QTime __startTime;
     QTime __endTime;
 

     void initalizeDom();
     void setStartTime();
     void setCloseTime();
 public:
   
    sessionManager(QWidget *parent=0, File_Manager *f=0);

   void setSessionOpen();
   bool openNewSession();
    bool openExistingSession( );
    bool cehckSessionXML();
     void writeDom();
    void readSessionFile();
    void setFolderName(QString);
    void setSequenceFile(QString);
    void setParameterFile(QString);
    void closeSession();
    QString getSequenceFile();
    QString getParameterFile();

    ~sessionManager();
    
 };
#endif
