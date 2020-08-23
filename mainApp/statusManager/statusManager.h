#ifndef __WRITE_XML
#define __WRITE_XML

#include <qdom.h>
#include <qfile.h>
#include <qwidget.h>
#include "File_Manager/File_Manager.h"
class statusManager
{

public:
    statusManager(){};
    statusManager( const QString fileName, QWidget *parent=0,File_Manager *f=0 );
    void setProcessState(int processId, const QString state);
    void getProcessState(int, int *, QString*);
    ~statusManager();

private:
    QWidget *appl;
    File_Manager *fm;
    QString __fileName;
    QFile   __stateFile;
    QDomDocument __stateDom;
    
   
    // Dom description
    QDomElement root;
    QDomElement sequence;
    QDomElement orf;
    QDomElement random;
    QDomElement prediction;

    QDomElement prediction_R_statistic;
    QDomElement prediction_R_statistic_threshold;
    QDomElement prediction_R_statistic_pattern_filter;
    QDomElement prediction_R_statistic_neighberhood;
    QDomElement prediction_R_statistic_smallGene;

    QDomElement prediction_P_value;
    QDomElement prediction_P_value_threshold;
    QDomElement prediction_P_value_pattern_filter;    
    QDomElement prediction_P_value_neighberhood;
    QDomElement prediction_P_value_smallGene;

    void initalizeDom();   
    void readStateFile();

    void writeDom();
    QString searchStateFromTable(QString , int );
  
};
#endif
