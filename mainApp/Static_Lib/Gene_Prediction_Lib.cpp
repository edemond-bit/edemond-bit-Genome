#include "Gene_Prediction_Lib.h"
#include "qmessagebox.h"
void Gene_Pred::search_char(char delim,int Occurance, char **token, char *string)
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

 void Gene_Pred::extract_index(char *PathName,int &pos1,int &pos2,char sign)
{
  char *token1,*token2;
        Gene_Pred::search_char('_',1,&token1,PathName);
        Gene_Pred::search_char(sign,2,&token2,token1);
        pos1 = atoi((const char*)token2);
        free(token2);
        Gene_Pred::search_char(sign,1,&token2,token1);
        pos2 = atoi((const char*)token2);
        free(token2);
        free(token1);
}
void Gene_Pred::sort_orf_list_file(char *orf_File,int field_No)
{
    char query[200];
    sprintf(query,"sort --key=%d --g %s > temp_99.csv",field_No,orf_File);
    system(query);
    sprintf(query,"rm %s",orf_File);
    system(query);
    sprintf(query,"rename temp_99.csv %s temp_99.csv",orf_File);
    system(query);
}

// This function returns the present working directory
const char * Gene_Pred::pwd(void)
{
   FILE *fp;
   char *working_directory =(char *)malloc(sizeof(char)*100);
   system("pwd > working_Dir.csv");
   fp = fopen("working_Dir.csv","r");
   if(fp != NULL)
   {
      fscanf(fp,"%s",working_directory);
      fclose(fp);
      fp = NULL;
      remove("working_Dir.csv");        
   }


   return (const char*)working_directory;

}
void Gene_Pred::min_max_GUI_validator( int minRange, int maxRange, QLineEdit *minLineEdit, QLineEdit *maxLineEdit )
{
    
 bool ok;
 QString smin, smax;
   
    int state1 =0; // 1->valid, 2->wrong, 3->invalid
    int state2=0;
    int minval, maxval;
  
   smin = minLineEdit->text();
   smax = maxLineEdit->text();
   minval = smin.toInt(&ok, 10);
   maxval = smax.toInt(&ok, 10);
   // lineEdit1 valid
   if( minRange<=minval && minval<=maxval){
       state1 = 1;
  } else if(minval>maxval && minval<=maxRange) {
      // lineEdit1 wrong
          state1 = 2;
      
      } else if(minval<minRange || minval>maxRange){
   //lineEdit1 invalid
   state1=3;
      };
      color_Field_validator(minLineEdit, state1);
      
     if(maxval>=minval && maxval<=maxRange){
//lineEdit2 valid
   state2 = 1;
}else if(maxval<minval && maxval>=minRange){
    //lineEdit2 wrong
               state2 = 2;
    }else if(maxval>maxRange || maxval < minRange){
  //lineEdit2 invalid
 state2 = 3;
    }
      color_Field_validator(maxLineEdit, state2);
    
      
}

// change field color

void Gene_Pred::color_Field_validator(QLineEdit *Field, int state){
     QColor *qcr,*qcg, *qco;
      qcr= new QColor(150,0,0);
      qco= new QColor(255,100,0);
   qcg= new QColor(0,80,0);
    switch(state){
    case 1: // valid
 Field->setPaletteForegroundColor(*qcg);
 break;
case 2://wrong
    Field->setPaletteForegroundColor(*qco);
    break;
case 3: // invalid
    Field->setPaletteForegroundColor(*qcr);
    break;
    }
}


