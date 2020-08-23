#ifndef __INPUTVALUEMG
#define __INPUTVALUEMG

#include <qdom.h>
#include <qfile.h>
#include <qwidget.h>
#include "File_Manager/File_Manager.h"
#include "GenePrediction.h"
#include <qmap.h> 
class paramManager
{

public:
    paramManager(){};
    paramManager( QWidget *parent=0,File_Manager *f=0 );
    QMap<QString,QWidget *> mapWidget;
    QMap<QString,QString> mapWidgetType;
    // void setProcessState(int processId, const QString state);
    //void getProcessState(int, int *, QString*);
    ~paramManager();
        // initialize dom
    void initializeDom();
    void createWidgetMap();
void changeDependentControls();
    void setWidgetValue(QString, QString);
    QString getWidgetValue( QString, QString);
    void updateFinalDom();
    int foundNodeById(QString);
    void setValueById(QString id, QString value);
    void getValueToWidget(QString , QWidget* , QString );
    void getValueFromWdiget(QString , QWidget *, QString );
    QString getValueById(QString);
    bool useNewParameterFile(const char *s);
    bool openExistingParameterFile();
    void writeDom(const QString);
private:
    
    Form1 *appl;
    File_Manager *fm;
    QString __standardFileName;
    QString __defaultFileName;
    QString __finalFileName;
    QFile __standardFile;
    QFile __defaultFile;
    QFile __finalFile;
    QDomDocument __standardDom;
    QDomDocument __defaultDom;
    QDomDocument __finalDom;
    QDomNodeList __nodeList;
    // Dom description
  QDomElement root;
  QDomElement currentNode;
    /*QDomElement sequence;
    QDomElement orf;
    QDomElement random;
    QDomElement prediction;
    
    QDomElement prediction_R;
    QDomElement prediction_R_statistic;
    QDomElement prediction_R_statistic_threshold;
    QDomElement prediction_R_statistic_pattern_filter;
    QDomElement prediction_R_statistic_neighberhood;
    QDomElement prediction_R_statistic_smallGene;

    QDomElement prediction_P;
    QDomElement prediction_P_value;
    QDomElement prediction_P_value_threshold;
    QDomElement prediction_P_value_pattern_filter;    
    QDomElement prediction_P_value_neighberhood;
    QDomElement prediction_P_value_smallGene;

    */

void readAndPrepearDom();
void populateFields();

    
    
  
};
#endif
