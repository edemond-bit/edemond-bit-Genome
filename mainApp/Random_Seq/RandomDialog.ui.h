/****************************************************************************
** ui.h extension file, included from the uic-generated form implementation.
**
** If you want to add, delete, or rename functions or slots, use
** Qt Designer to update this file, preserving your code.
**
** You should not define a constructor or destructor in this file.
** Instead, write your code in functions called init() and destroy().
** These will automatically be called by the form's constructor and
** destructor.
*****************************************************************************/


#include "GenePrediction.h"
#include "../Static_Lib/Gene_Prediction_Lib.h"
#include "qmessagebox.h"
void RandomDialog::lineEdit2_textChanged( const QString & )
{

    Gene_Pred::min_max_GUI_validator(min_range_random, max_range_random, lineEdit2, lineEdit3 );
    
purtrub_value_default();
}
void RandomDialog::lineEdit3_textChanged( const QString & )
{   
    Gene_Pred::min_max_GUI_validator(min_range_random, max_range_random, lineEdit2, lineEdit3 );
    purtrub_value_default();

}

void RandomDialog::init(){

}


void RandomDialog::lineEdit1_textChanged( const QString & )
{
              QString s1 = lineEdit1->text();
              bool ok;
              int orf_n = s1.toInt(&ok,10);
           
      if(orf_n<=0 ) {
          swapPercent->setEnabled(false);
          mutPercent->setEnabled(false);
        // lineEdit2->setEnabled(false);
       //   lineEdit3->setEnabled(false);
          lineEdit4->setEnabled(false);
   buttonCreateRand->setEnabled(false);
                    } else
                   {
                      swapPercent->setEnabled(true);
                      mutPercent->setEnabled(true);
                   //   lineEdit2->setEnabled(true);
                  //    lineEdit3->setEnabled(true);
                      lineEdit4->setEnabled(true);
                      buttonCreateRand->setEnabled(true);
        
                   }
}


void RandomDialog::purtrub_value_default()
{
        QString s1 = lineEdit2->text();
              bool ok;
              int minVal = s1.toInt(&ok,10);
      QString s2 = lineEdit3->text();
       char tmp_str[400],temp_rand_name[400], Genome[400];
   FILE  *fp1, *fp2;
              int maxVal = s2.toInt(&ok,10);     

    //////////////////////Perturb max value boundary setting////////////////////////////////
       char Gen_Name[400],FName[400];
       //int CountBigGen; //Contain seq count >= 300
       int fileLength;
       sprintf(tmp_str,"%s/path_ORF",seq_work_dir);

       fp1 = fopen(tmp_str,"r");
      if(fp1==NULL)
      {
         printf("\nCan't open file %s   ",tmp_str);
         exit(0);
      }
   
      ///////////////////////////////////////
   fscanf(fp1,"%s",Genome);//Read Genome Sequence File Path
   fscanf(fp1,"%s",Gen_Name);//Read ORF+
   
   if((fp2 = fopen(Gen_Name,"r")) != NULL)
   {
    ////////////////////////Counting Sequences having Length >= MIN_CHAR & Length >= MAX_CHAR
    strcpy(temp_rand_name,"");
    CountBigGene = 0;
    while(!feof(fp2))
    {
     fscanf(fp2,"%s\t%d",FName,&fileLength);
     if(strcmp(temp_rand_name,FName) == 0)
      break;
     else
      strcpy(temp_rand_name,FName);
     CountBigGene = ((fileLength >= minVal && fileLength <= maxVal) ? CountBigGene + 1 : CountBigGene);
    }
    fclose(fp2);
    fp2 = NULL;
   }
   
   fscanf(fp1,"%s",Gen_Name);//Read NORF+
   fscanf(fp1,"%s",Gen_Name);//Read ORF-
   if((fp2 = fopen(Gen_Name,"r")) != NULL)
   {
    ////////////////////////Counting Sequences having Length >= MIN_CHAR & Length >= MAX_CHAR
    strcpy(temp_rand_name,"");
    CountBigNGene = 0;
    while(!feof(fp2))
    {
     fscanf(fp2,"%s\t%d",FName,&fileLength);
     if(strcmp(temp_rand_name,FName) == 0)
      break;
     else
      strcpy(temp_rand_name,FName);
     CountBigNGene = ((fileLength >= minVal && fileLength <= maxVal) ? CountBigNGene + 1 : CountBigNGene);
    }
    fclose(fp2);
    fp2 = NULL;
   }
   fclose(fp1);
   fp1 = NULL;
    ////////////////////Perturb max value boundary setting [END]/////////////////////////////////
      int tmp,tempVar;
      tempVar = (CountBigGene + CountBigNGene)/2;
      if(tempVar>500) {
    tmp=500;
    lineEdit4->setText("10");
}else{
    //tmp=tempVar;
    tmp=250;
    lineEdit4->setText("20");
}
               
  lineEdit1->setText(QString::number(tmp,10));
      textLabel1_2->setText(QString("(Maximum :")+QString::number((CountBigGene + CountBigNGene)/2,10)+QString(")"));

}


void RandomDialog::buttonCreateRand_pressed()
{
//   

}


void RandomDialog::buttonCreateRand_released()
{ 
    //QMessageBox::warning(0,"Save parameter to dom", "Save the random paramater to dom");
   paramMg->getValueFromWdiget("290",  lineEdit2, "QLineEdit");
     paramMg->getValueFromWdiget("295",  lineEdit3, "QLineEdit");
      paramMg->getValueFromWdiget("300",  lineEdit1, "QLineEdit"); 
         paramMg->getValueFromWdiget("305", swapPercent, "QLineEdit");
 paramMg->getValueFromWdiget("310", mutPercent, "QLineEdit"); 
 paramMg->getValueFromWdiget("315", lineEdit4, "QLineEdit");
  paramMg->setValueById("316",QString("%1").arg(CountBigGene,0,10));
   paramMg->setValueById("317",  QString("%1").arg(CountBigNGene,0,10));
 
}
