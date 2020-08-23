#include "statusManager.h"
#include <qapplication.h>
#include <qmessagebox.h>
#include <iostream>
#include "File_Manager/File_Manager.h"

statusManager::statusManager(const QString fileName, QWidget *parent, File_Manager *f)
{
    __fileName = fileName;
   __stateFile.setName(fileName);
   appl = parent;
   fm = f;
   if(__stateFile.open(IO_ReadOnly)){
     readStateFile();
   }else{

    if(!__stateFile.open( IO_WriteOnly))
    {
 QMessageBox::critical(0,  QApplication::tr("Critical Error") , QApplication::tr("Can not open file %1").arg(fileName));
    } 
    else 
    {
     initalizeDom();
    }
   }
    __stateFile.close();
    // setProcessState(1,"b");
     writeDom();
}
//
void statusManager::readStateFile()
{
  QDomNode tmp;
    if ( !__stateDom.setContent( &__stateFile ) ) {
        QMessageBox::critical( 0,QApplication::tr( "Critical Error" ),QApplication::tr( "Parsing error for file %1" ).arg( __fileName ) );
        __stateFile.close();
        return;
    }
    __stateFile.close();
    // map nodes
    root = __stateDom.documentElement();
    tmp = root.firstChild();
    sequence = tmp.toElement();
    
    orf = tmp.firstChild().toElement();
    tmp=orf.nextSibling();
    random = tmp.toElement();
    
    tmp=random.nextSibling();
    prediction =tmp.toElement();

    tmp=prediction.firstChild();
    prediction_R_statistic = tmp.toElement();
     //std::cout<<"\n>>>>>>node name R-stat:"<<prediction_R_statistic.nodeName();
    tmp=tmp.firstChild();
    prediction_R_statistic_threshold = tmp.toElement();
    // std::cout<<"\n>>>>>>node name R-stat threshold:"<<prediction_R_statistic_threshold.nodeName();
    tmp=tmp.nextSibling();

    prediction_R_statistic_pattern_filter = tmp.toElement();
    tmp=tmp.nextSibling();

    prediction_R_statistic_neighberhood = tmp.toElement();
    tmp = tmp.nextSibling();
    prediction_R_statistic_smallGene = tmp.toElement();

    //std::cout<<"\n>>>>>>node name R-neighber :"<<prediction_R_statistic_neighberhood.nodeName();
    tmp=prediction.firstChild().nextSibling();
    prediction_P_value = tmp.toElement();
    //std::cout<<"\n>>>>>>node name pvalue :"<<prediction_P_value.nodeName();
    tmp=tmp.firstChild();
    prediction_P_value_threshold = tmp.toElement();
    //std::cout<<"\n>>>>>>node name p-threshold :"<<prediction_P_value_threshold.nodeName();
    tmp=tmp.nextSibling();
    prediction_P_value_pattern_filter = tmp.toElement();
    //std::cout<<"\n>>>>>>node name P-neighber :"<<prediction_P_value_neighberhood.nodeName();
    tmp=tmp.nextSibling();
    prediction_P_value_neighberhood = tmp.toElement();
    //std::cout<<"\n>>>>>>node name P-neighber :"<<prediction_P_value_neighberhood.nodeName();
    tmp=tmp.nextSibling();
    prediction_P_value_smallGene = tmp.toElement();
    
}
//
void statusManager::writeDom()
{
    if(!__stateFile.open( IO_WriteOnly))
    {
 QMessageBox::critical(0,  QApplication::tr("Critical Error") , QApplication::tr("Can not open file %1").arg(__fileName));
    } 


     QTextStream stream( &__stateFile);
     QString line =  __stateDom.toString();
     stream<<line;
    __stateFile.close();
}
void statusManager::initalizeDom()
{

   // create elements
   root=__stateDom.createElement("application");
   sequence=__stateDom.createElement("sequence");
   sequence=__stateDom.createElement("sequence");
   orf=__stateDom.createElement("orf");
   random=__stateDom.createElement("random");
   prediction=__stateDom.createElement("prediction");
   prediction_R_statistic=__stateDom.createElement("R_statistic");
   prediction_R_statistic_threshold = __stateDom.createElement("threshold");
   prediction_R_statistic_pattern_filter = __stateDom.createElement("pattern_filter");
   prediction_R_statistic_neighberhood =__stateDom.createElement("neighberhood");
   prediction_R_statistic_smallGene =__stateDom.createElement("reThreshold");

   prediction_P_value = __stateDom.createElement("P_value");
   prediction_P_value_threshold = __stateDom.createElement("threshold");
   prediction_P_value_pattern_filter = __stateDom.createElement("pattern_filter");    
   prediction_P_value_neighberhood = __stateDom.createElement("neighberood");
   prediction_P_value_smallGene = __stateDom.createElement("reThreshold");
   sequence.setAttribute("name","");
   sequence.setAttribute("path","");
   sequence.setAttribute("state","");
   sequence.setAttribute("state","sequencStates");

   // initalize state attributes
   orf.setAttribute( "state","0" );
   orf.setAttribute("stateTable","orfState.xml");
   random.setAttribute( "state","0" );
   random.setAttribute("stateTable","randomState.xml");
   prediction.setAttribute( "state","0" );
   prediction.setAttribute("stateTable","predictionState.xml");
   
   prediction_R_statistic.setAttribute( "state","0" );
   prediction_R_statistic.setAttribute("stateTable","r-stateState.xml");
   prediction_R_statistic_threshold.setAttribute( "state","0" );
   prediction_R_statistic_threshold.setAttribute("stateTable","r-statThresholdState.xml");
   prediction_R_statistic_pattern_filter.setAttribute( "state","0" );
   prediction_R_statistic_pattern_filter.setAttribute("stateTable","r-stateFilter.xml");
   prediction_R_statistic_neighberhood.setAttribute("state","0");
   prediction_R_statistic_neighberhood.setAttribute("stateTable","r-statNeighber.xml");
   prediction_R_statistic_smallGene.setAttribute("state","0");
   prediction_R_statistic_smallGene.setAttribute("stateTable","r-reThresholdState.xml");



   prediction_P_value.setAttribute( "state","0" );
   prediction_P_value.setAttribute("stateTable","p-valueState.xml");
   prediction_P_value_threshold.setAttribute( "state","0" );
   prediction_P_value_threshold.setAttribute("stateTable","p-valueThresholdState.xml");
   prediction_P_value_pattern_filter.setAttribute( "state","0" );
   prediction_P_value_pattern_filter.setAttribute("stateTable","p-valueFilter.xml");
   prediction_P_value_neighberhood.setAttribute("state","0");
   prediction_P_value_neighberhood.setAttribute("stateTable","p-valueNeighber.xml");
   prediction_P_value_smallGene.setAttribute("state","0");
   prediction_P_value_smallGene.setAttribute("stateTable","p-reThresholdState.xml");
  

   //  relate elements
   __stateDom.appendChild(root);
   root.appendChild(sequence);
   sequence.appendChild(orf);
   sequence.appendChild(random);
   sequence.appendChild(prediction);
   prediction.appendChild(prediction_R_statistic);
   prediction.appendChild(prediction_P_value);

   prediction_R_statistic.appendChild(prediction_R_statistic_threshold);
   prediction_R_statistic.appendChild(prediction_R_statistic_pattern_filter);
   prediction_R_statistic.appendChild(prediction_R_statistic_neighberhood);
   prediction_R_statistic.appendChild(prediction_R_statistic_smallGene);

   prediction_P_value.appendChild(prediction_P_value_threshold);
   prediction_P_value.appendChild(prediction_P_value_pattern_filter);
   prediction_P_value.appendChild(prediction_P_value_neighberhood);
   prediction_P_value.appendChild(prediction_P_value_smallGene);
   
   QString xml = __stateDom.toString();
   //   std::cout<<xml;
   
   
}
QString statusManager::searchStateFromTable(QString stateTable, int stateId){


  QDomDocument stateDom("stateDoc");
  QString stateFile("");
  stateFile = QString(fm->get_application_home())+QString("/stateFiles/")+stateTable;
  // QMessageBox::information(appl ,"information",  stateFile              );
  QFile file(stateFile);
  if(!file.open(IO_ReadOnly)){
    QMessageBox::warning(appl,"Warning", QString("File missing :")+stateTable);
    return "";
  }
  if(!stateDom.setContent(&file)){
    file.close();
    return "";
  }
  file.close();
  ////////File read complete
  //now seek for desire information
  QDomElement docElem = stateDom.documentElement();
  QDomNode n=docElem.firstChild();
  QDomAttr a;
  int id=0;
  while(!n.isNull()){
    a = n.toElement().attributeNode("id");
    id = a.value().toInt();
    if(id ==stateId){
      a = n.toElement().attributeNode("value");
      //QMessageBox::information(appl,"Information",QString(a.value()));
      return a.value();
    }


    n= n.nextSibling();
  }

  return "";
}
void  statusManager::getProcessState(int processId, int *astateId, QString *state ){
  QString stateTable("");
   int stateId =0;
  
  switch(processId) {
    case 1:  // ORF
      stateId =orf.attributeNode("state").value().toInt();
      stateTable =orf.attributeNode("stateTable").value();
      *state =searchStateFromTable(stateTable,stateId);
      
      break;
    case 2:  // random
      stateId =random.attributeNode("state").value().toInt();
      stateTable =random.attributeNode("stateTable").value();
      *state =searchStateFromTable(stateTable,stateId);

      break;
    case 3: // prediction
      stateId =prediction.attributeNode("state").value().toInt();
      stateTable =prediction.attributeNode("stateTable").value();
      *state =searchStateFromTable(stateTable,stateId);
      //prediction.setAttribute("state",state);
      break;
    case 4: // prediction_R_statistic
      stateId =prediction_R_statistic.attributeNode("state").value().toInt();
      stateTable =prediction_R_statistic.attributeNode("stateTable").value();
      *state =searchStateFromTable(stateTable,stateId);
      //prediction_R_statistic.setAttribute("state",state);
      break;
    case 5: // prediction_R_statistic_threshold
      stateId =prediction_R_statistic_threshold.attributeNode("state").value().toInt();
      stateTable =prediction_R_statistic_threshold.attributeNode("stateTable").value();
      *state =searchStateFromTable(stateTable,stateId);
      // prediction_R_statistic.setAttribute("state",state);
      break;
    case 6: // prediction_R_statistic_pattern_filter
      stateId =prediction_R_statistic_pattern_filter.attributeNode("state").value().toInt();
      stateTable =prediction_R_statistic_pattern_filter.attributeNode("stateTable").value();
      *state =searchStateFromTable(stateTable,stateId);
      break;

  case 7:// prediction_R_statistic_neighberhood
      stateId =prediction_R_statistic_neighberhood.attributeNode("state").value().toInt();
      stateTable =prediction_R_statistic_neighberhood.attributeNode("stateTable").value();
      *state =searchStateFromTable(stateTable,stateId);
      break;
  case 8:// prediction_R_statistic_smallGene
    stateId = prediction_R_statistic_smallGene.attributeNode("state").value().toInt();
    stateTable = prediction_R_statistic_smallGene.attributeNode("stateTable").value();
    *state = searchStateFromTable(stateTable, stateId);

    break;
  case 9://prediction_P_value
      stateId =prediction_P_value.attributeNode("state").value().toInt();
      stateTable =prediction_P_value.attributeNode("stateTable").value();
      *state =searchStateFromTable(stateTable,stateId);
      break;
  case 10://prediction_P_value_threshold
    stateId =prediction_P_value_threshold.attributeNode("state").value().toInt();
    stateTable =prediction_P_value_threshold.attributeNode("stateTable").value();
    *state =searchStateFromTable(stateTable,stateId);
    break;
  case 11://prediction_P_value_pattern_filter
    stateId =prediction_P_value_pattern_filter.attributeNode("state").value().toInt();
    stateTable =prediction_P_value_pattern_filter.attributeNode("stateTable").value();
    *state =searchStateFromTable(stateTable,stateId);
    break;
  case 12://prediction_P_value_neighberhood
    stateId =prediction_P_value_neighberhood.attributeNode("state").value().toInt();
    stateTable =prediction_P_value_neighberhood.attributeNode("stateTable").value();
    *state =searchStateFromTable(stateTable,stateId);
    break;
      
      case 13:// prediction_P_value_smallGene
      stateId = prediction_P_value_smallGene.attributeNode("state").value().toInt();
    stateTable = prediction_P_value_smallGene.attributeNode("stateTable").value();
    *state =searchStateFromTable(stateTable, stateId);
    break;
  default:
    break;
  };
  *astateId = stateId;

}
void statusManager::setProcessState( int processId, const QString state)
{
    switch(processId) {
    case 1:  // ORF
      orf.setAttribute( "state",state );
      random.setAttribute("state",0);
      prediction.setAttribute("state",0);
      break;
    case 2:  // random
      random.setAttribute("state",state);
      prediction.setAttribute("state",0);
      break;
    case 3: // prediction
      prediction.setAttribute("state",state);
      
      break;
    case 4: // prediction_R_statistic
      prediction_R_statistic.setAttribute("state",state);
      prediction_R_statistic_threshold.setAttribute("state",0);
      prediction_R_statistic_pattern_filter.setAttribute("state",0);
      prediction_R_statistic_neighberhood.setAttribute("state",0);
      break;
    case 5: // prediction_R_statistic_threshold
      prediction_R_statistic_threshold.setAttribute("state",state);
      prediction_R_statistic_pattern_filter.setAttribute("state",0);
      prediction_R_statistic_neighberhood.setAttribute("state",0);
        prediction_R_statistic_smallGene.setAttribute("state", 0);
      break;
    case 6: // prediction_R_statistic_pattern_filter
      prediction_R_statistic_pattern_filter.setAttribute("state",state);
      break;
    case 7: // prediction_R_statistic_neighberhood
      prediction_R_statistic_neighberhood.setAttribute("state",state);
      break;
    case 8: // prediction_R_statistic_smallGene
      prediction_R_statistic_smallGene.setAttribute("state", state);
      break;

    case 9:// prediction_P_value
      prediction_P_value.setAttribute("state", state);
      prediction_P_value_threshold.setAttribute("state",0);
      prediction_P_value_pattern_filter.setAttribute("state",0);
      prediction_P_value_neighberhood.setAttribute("state",0);
      break;
    case 10://prediction_P_value_threshold
      prediction_P_value_threshold.setAttribute("state",state);
      prediction_P_value_pattern_filter.setAttribute("state",0);
      prediction_P_value_neighberhood.setAttribute("state",0);
       prediction_P_value_smallGene.setAttribute("state", 0);
      break;
    case 11: // prediction_P_value_pattern_filter
      prediction_P_value_pattern_filter.setAttribute("state",state);
      break;
    case 12: // prediction_p_value_neighberhood
      prediction_P_value_neighberhood.setAttribute("state",state);
      break;
    case 13: // prediction_P_value_smallGene
      prediction_P_value_smallGene.setAttribute("state", state);
      break;

    default:
      break;
    }
       writeDom();
}
statusManager::~statusManager(){
}
