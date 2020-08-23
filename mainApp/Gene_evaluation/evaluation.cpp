#include "evaluation.h"
#include "qmessagebox.h"
#include <iostream>
#include <stdio.h>
#include <dirent.h>
#include <qfile.h>
#include <qdom.h>
bool Evaluation::readFile(char *sequenceNameList[], char *seq_work_dir)
{
 FILE *fp,*testFP;
 //int Choice, Option,records;
 char ncbStr[400],glmStr[400],gnmStr[400];//,gnpStrP[200],gnpStrN[200];
 char *token,Decision='\0', *gnpStrP, *gnpStrN;//,isHypo;
// char eval_FileName[100];
 QString *ms;
 fp = NULL;
 system("clear");
bool checkfile=true;

 isHypo = toupper(isHypo);
 

 if(isHypo == 'Y')
  sprintf(eval_FileName,"%s/evaluation_Result.csv",seq_work_dir);
	else
  sprintf(eval_FileName,"%s/evaluation_Results_Hypo.csv",seq_work_dir);

	
	if(isHypo == 'Y')
   	{							
		if((fp = fopen(eval_FileName,"w")) != NULL)
		{
			fprintf(fp,"NCBI Data Set = \t{Only multiple of 3 NCBI \tSequences}\n");
			fclose(fp);
			fp = NULL;
		}
	}
	else
	{
		if((fp = fopen(eval_FileName,"w")) != NULL)
		{
			fprintf(fp,"NCBI Data Set = \t{Multiple of 3 NCBI Sequences + \tMultiple of 3 Hypothetical \tSequences}\n");
			fclose(fp);
			fp = NULL;
		}
	}

	
     
	records =0;
        int tmp = 1;
	
        char *sequenceId;
	for(records=0; records<tmp; ++records){
        searchChar('|',3,&sequenceId,sequenceNameList[records]);
		searchChar('|',2,&gnpStrP,sequenceNameList[records]);
		searchChar('|',1,&gnpStrN,sequenceNameList[records]);

	       strcpy(ncbStr,search_in_xml_file("NCBI.xml",sequenceId));
	       if(strcmp(ncbStr,"")==0) {
	         checkfile=false;
	         break;
	       }
	       token = (char *)malloc(sizeof(char)*(strlen(sequenceNameList[records])+1));
               
	       strcpy(token,sequenceNameList[records]);

	       if(Choice == 2)
		{
			QMessageBox mb("Evaluation",QString("Perform evaluation")+token+QString(" ?"),
				       QMessageBox::Information,
				       QMessageBox::Yes,
				       QMessageBox::No|QMessageBox::Default,
				       QMessageBox::NoButton);
			switch(mb.exec()){
			case QMessageBox::Yes:
			  Decision='Y';
			  break;
			case QMessageBox::No:
			  Decision='N';
			  break;
			}
		}

		ms=new QString(qle->text());
                ms->append(QString("\n\n")+QString(sequenceId));
	        if(Choice == 2 && toupper(Decision) =='N') ms->append(QString("--> skipped"));
                ms->append(QString("\n-----------------------------------------"));
		qle->setText(*ms);
		qle->scrollToBottom();
		qApp->processEvents();

		if((Choice == 2 && toupper(Decision) == 'Y') || Choice == 1)
		  {		

		        ncb = new NCBI;
			ncb->qle=qle;

                      
			if(ncb->readNCBIFile(ncbStr,isHypo))
			{
			  
			  switch(Option)
				{
					case 4:
					
						//fscanf(fp4,"%s",gnpStrP);
						if((testFP = fopen(gnpStrP,"r")) != NULL)
						{
							fclose(testFP);
							testFP = NULL;
							//fscanf(fp4,"%s",gnpStrN);
                            
							if((fp = fopen(eval_FileName,"a")) != NULL)
							{
								fprintf(fp,"\n\t\t%s\n",sequenceId);
								fprintf(fp,"NCBI Total\t%d\n",ncb->recNum_Plus + ncb->recNum_Minus);
								if(isHypo == 'Y')
									fprintf(fp,"Predictor\tStart-Stop Matched\tStop Matched,Different Start\tNovel Prediction\tMissed\tSensitivity\tSpecificity\n");
								else
									fprintf(fp,"Predictor\tStart-Stop Matched\tStop Matched,Different Start\tHypothetical\tNovel Prediction\tMissed\tSensitivity_H\tSpecificity_H1(Except Hypo)\tSpecificity_H2(With Hypo)\n");
								fclose(fp);
								fp = NULL;
									
								GenePredict_Thread(gnpStrP,gnpStrN,sequenceId,isHypo,"Our Method",eval_FileName,0);

							}
						}

						break;
					case 5:
					//	fscanf(fp4,"%s",gnpStrP);
						if((testFP = fopen(gnpStrP,"r")) != NULL)
						{
							fclose(testFP);
							testFP = NULL;
						//	fscanf(fp4,"%s",gnpStrN);
							if((fp = fopen(eval_FileName,"a")) != NULL)
							{ 
								fprintf(fp,"\n\t\t%s\n",sequenceId);
								fprintf(fp,"NCBI Total\t%d\n",ncb->recNum_Plus + ncb->recNum_Minus);
								if(isHypo == 'Y')
									fprintf(fp,"Predictor\tStart-Stop Matched\tStop Matched,Different Start\tNovel Prediction\tMissed\tSensitivity\tSpecificity\n");
								else
									fprintf(fp,"Predictor\tStart-Stop Matched\tStop Matched,Different Start\tHypothetical\tNovel Prediction\tMissed\tSensitivity_H\tSpecificity_H1(Except Hypo)\tSpecificity_H2(With Hypo)\n");
								fclose(fp);
								fp = NULL;
						GenePredict_Thread(gnpStrP,gnpStrN,sequenceId,isHypo,"Our Method",eval_FileName,0);

						 strcpy(glmStr,search_in_xml_file("Glimmer.xml",sequenceId));
					//fscanf(fp2,"%s",glmStr);
	if(strcmp(glmStr,"")==0) {
  								   QMessageBox::critical(0,QApplication::tr("Not found"), QApplication::tr("Glimmer data for  %1 not found").arg(sequenceId));
								
								}else{


								Glimmer_Thread(glmStr,isHypo,eval_FileName);}

							}
						}
						break;
					case 6:

						if((testFP = fopen(gnpStrP,"r")) != NULL)
						{
							fclose(testFP);
							testFP = NULL;
							if((fp = fopen(eval_FileName,"a")) != NULL)
							{
								fprintf(fp,"\n\t\t%s\n",sequenceId);
								fprintf(fp,"NCBI Total\t%d\n",ncb->recNum_Plus + ncb->recNum_Minus);
								if(isHypo == 'Y')
									fprintf(fp,"Predictor\tStart-Stop Matched\tStop Matched,Different Start\tNovel Prediction\tMissed\tSensitivity\tSpecificity\n");
								else
									fprintf(fp,"Predictor\tStart-Stop Matched\tStop Matched,Different Start\tHypothetical\tNovel Prediction\tMissed\tSensitivity_H\tSpecificity_H1(Except Hypo)\tSpecificity_H2(With Hypo)\n");
								fclose(fp);
								fp = NULL;


							  	 strcpy(gnmStr,search_in_xml_file("Gene_Mark.xml",sequenceId));
	GenePredict_Thread(gnpStrP,gnpStrN,sequenceId,isHypo,"Our Method",eval_FileName,0);

   								if(strcmp(gnmStr,"")==0) {
  								   QMessageBox::critical(0,QApplication::tr("Not found"), QApplication::tr("Gene_Mark data for  %1 not found").arg(sequenceId));
								
								}else {

								GeneMark_Thread(gnmStr,isHypo,eval_FileName);
							}
														

							}
						}
						break;
					case 7:

						if((testFP = fopen(gnpStrP,"r")) != NULL)
						{
							fclose(testFP);
							testFP = NULL;
							if((fp = fopen(eval_FileName,"a")) != NULL)
							{
								fprintf(fp,"\n\t\t%s\n",sequenceId);
								fprintf(fp,"NCBI Total\t%d\n",ncb->recNum_Plus + ncb->recNum_Minus);
								if(isHypo == 'Y')
									fprintf(fp,"Predictor\tStart-Stop Matched\tStop Matched,Different Start\tNovel Prediction\tMissed\tSensitivity\tSpecificity\n");
								else
									fprintf(fp,"Predictor\tStart-Stop Matched\tStop Matched,Different Start\tHypothetical\tNovel Prediction\tMissed\tSensitivity_H\tSpecificity_H1(Except Hypo)\tSpecificity_H2(With Hypo)\n");
								fclose(fp);
								fp = NULL;
								 strcpy(glmStr,search_in_xml_file("Glimmer.xml",sequenceId));

	 strcpy(gnmStr,search_in_xml_file("Gene_Mark.xml",sequenceId));
	if(strcmp(glmStr,"")==0) {
  								   QMessageBox::critical(0,QApplication::tr("Not found"), QApplication::tr("Glimmer data for  %1 not found").arg(sequenceId));
								
								} else {


								Glimmer_Thread(glmStr,isHypo,eval_FileName);
}
 strcpy(gnmStr,search_in_xml_file("Gene_Mark.xml",sequenceId));

								GenePredict_Thread(gnpStrP,gnpStrN,sequenceId,isHypo,"Our Method",eval_FileName,0);
							if(strcmp(gnmStr,"")==0) {
  								   QMessageBox::critical(0,QApplication::tr("Not found"), QApplication::tr("Gene_Mark data for  %1 not found").arg(sequenceId));
									
								}else {

								GeneMark_Thread(gnmStr,isHypo,eval_FileName);
							}
														

							}
						}
						
						break;
				}
	
			}


			delete ncb;
			ncb = NULL;
		
		}
		else
		{



		
		}

	
	free(token);
	token = NULL;


	};



	/*switch(Option)
	{
		case 1:
			fclose(fp2);
			break;
		case 2:
			fclose(fp3);
			break;
		case 3:
			fclose(fp2);
			fclose(fp3);
			break;
		case 4:
	
			break;
		case 5:
			fclose(fp2);
			fclose(fp4);
			fclose(fp5);

			break;
		case 6:
			fclose(fp3);
			fclose(fp4);
			fclose(fp5);

			break;
		case 7:
			fclose(fp2);
			fclose(fp3);
			fclose(fp4);
			fclose(fp5);

			break;
		
 }*/
if(checkfile)  qbresult->setEnabled(true);
 fp =  NULL;
 return checkfile;
}

void Evaluation::Glimmer_Thread(char glmStr[], char isHypo, char eval_FileName[])
{
 Glimmer glm;
 if(glm.readGlimmerFile(ncb,glmStr))
  glm.ncbi_Vs_Glimmer(ncb,isHypo,eval_FileName);
}

void Evaluation::GeneMark_Thread(char gnmStr[], char isHypo, char eval_FileName[])
{
 GeneMark gnm;
 if(gnm.readGeneMarkFile(ncb,gnmStr))
  gnm.ncbi_Vs_GeneMark(ncb,isHypo,eval_FileName);
}

void Evaluation::GenePredict_Thread(char gnpStrP[],char gnpStrN[],char seqName[], char isHypo, char GenePedLabel[], char eval_FileName[],int firstTimeFlag)
{
 GenePredict gp;
 
        gp.qle = qle;
 if(gp.readGenePredictFile(ncb,gnpStrP,gnpStrN,firstTimeFlag))
  gp.ncbi_Vs_genePrediction(ncb,seqName,isHypo,GenePedLabel,eval_FileName);
}

char *Evaluation::search_in_xml_file(char *resultFileName, char *sequenceName)
{
  char *str;

    QFile   __resultFile;
    QDomDocument __resultDom;
    __resultFile.setName(resultFileName);
    QDomNode tmp;
    QDomElement root;
    QDomNodeList nl;

    if ( !__resultDom.setContent( &__resultFile ) ) {
        QMessageBox::critical( 0,QApplication::tr( "Critical Error" ),QApplication::tr( "Parsing error for file %1" ).arg( resultFileName ) );
        __resultFile.close();
     str=(char *)malloc(sizeof(char)+1); 
strcpy(str,"");
return str;
    }
    __resultFile.close();
    
       

    root = __resultDom.documentElement();
    nl=root.childNodes();
//QMessageBox::critical( 0,QApplication::tr( "Critical Error" ),QApplication::tr( "Entering for search with %1" ).arg( sequenceName ) );
    unsigned int i;
    for(i=0;i<nl.count();i++){
   
    //QMessageBox::information(0,QApplication::tr("child nodes"), QApplication::tr("node is == %1").arg(nl.item(i).toElement().attribute("name")));
      if(strcmp(nl.item(i).toElement().attribute("name").ascii(),sequenceName)==0){
      //QMessageBox::information(0,QApplication::tr("child nodes"), QApplication::tr("node is == %1").arg(nl.item(i).toElement().attribute("name")));
 str=(char *)malloc(sizeof(char)*(strlen(nl.item(i).toElement().attribute("file"))+1));      
      strcpy(str,nl.item(i).toElement().attribute("file"));
     // QMessageBox::information(0,QApplication::tr("child nodes"), QApplication::tr("node is ()== %1").arg(str));
      return str;

      }
    }
str=(char *)malloc(sizeof(char)+1); 
strcpy(str,"");
QMessageBox::information(0,QApplication::tr("Warning"), QApplication::tr("Not found  %1 in %2 (case sensitive)").arg(sequenceName,resultFileName));
    return str;
    
  
}


void Evaluation::searchChar(char delim,int Occurance,char **token,char *string)
{
 int i,j,occur = 1,str,stp;
 
 stp = strlen(string)-1;
 for(i=stp; i>=0; --i)
 {
  if(string[i] == delim)
  {
   if(occur == Occurance)
    break;
   else
   {
    ++occur;
    stp = i-1;
   }
  }
 }
 *token = (char *)calloc(((stp-i)+1),sizeof(char));
 j = 0;
 for(str = i+1; str<=stp; str++,++j)
  *(*token + j) = string[str];
 *(*token + j) = '\0';
}
