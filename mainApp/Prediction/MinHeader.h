#define pie 3.1416
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <qprogressdialog.h>
#include <qmessagebox.h>


#include "ProgressBarController/pbc.h"
#include "statusManager/statusManager.h"
#include "ParamManager/paramManager.h"
#include "sessionManager/sessionManager.h"

pbc *mainPbc;
QWidget *appl;
statusManager *sManager;
File_Manager *fm;
paramManager *paramMg;
sessionManager *sessionMg;



int Occur, Occur_org;
int MIN_CHAR,MAX_CHAR,Addaptive_Flag,choice,inputType; // choice ~ 1 ~ R-Statistic or 2 ~ P-Value, accept value in Gene_Prediction.c
bool interactiveMode=true;

double *PeekValueFW,**Matrix,*MatrixW,From1,To1,From2,To2,PeakValue,Omega_From,Omega_To,Omega_Interval; 
int fileLength; //Sequence length under process
char *forward_Genome,*reverse_Genome;
int genomeLength;
char seq_work_dir[400];

void Omega(int RowNum);
void compute_omega_parametere(int RowNum,int fileLength);
int ReadFile(char *FName,char **Buffer);
void reverse_complement_of_Sequence();//Debabrata 
void seqSearch(char *Buf,char seqArr,char **Buffer,int Length); 
void fOmega(char *Buf,int Length,int RowNo);
double fOmega_PeekValue(char *Buf,int fileLength);
int UnionW();
double Ratio(int Count);
double FindMax(int Row,int Col);
void Swap(char **tempBuf,int Length,int Swap_No,double  Swap_Pro);
void Mutation(char **tempBuf,int Mut_No,double  Mut_Pro,double  *Pat_Pro,int Pat_Pro_Length,int Length);
int Search(int Char_Swap_Pro,int Occurence_Probability); 
void Read_Pat_Probability(double  *pat_prob);
void Clear_Memory(int seqLen);
void searchChar(char ,int , char **,char *);
///////////////////////////////////

char *mainMethod[]={"","R-stat_Results","P-Value_Results"};

///////////////////////////////////
int ReadFile(char *FName,char **Buffer)
{
  FILE *fp;
  char ch;
  int i,Position;
  char str[400];

  //int predictedLength = 100;

  QString qtemps("");
  fp = fopen(FName,"r");
  if(fp == NULL)
    {
      qtemps="*** Abnormal Termination :: Cannot open file "+QString(FName);
      QMessageBox::warning(appl,"Warning",qtemps);
      exit(0);
    }
  rewind(fp);
  fscanf(fp, "%[^\n]\n", str);
  fseek(fp, SEEK_CUR,SEEK_END);
  Position = ftell( fp );
  rewind( fp );
  fscanf( fp, "%[^\n]\n", str );

  *Buffer = (char *) malloc( ( Position + 1 ) * sizeof( char ) );
  i = 0;

  while( !feof( fp ) )
    {
      ch = fgetc( fp );
      ch = toupper( ch );
      switch( ch )
	{
	case 'A':
	case 'T':
	case 'C':
	case 'G':
	case 'N':
	case 'R':
	case 'W':
	case 'Y':
	case 'M':
	case 'K':
	case 'S':
	case 'H':
	case 'B':
	case 'V':     
	case 'D':
	  *(*Buffer+i) = ch;
	  ++i;
	  break;
	default :
	  break;
	}
      /*
	if(i%10000==0){
	if(predictedLength<i) predictedLength = (int)(i*1.2);
	if(mainPbc->pbcWasCanceled()) break;
	mainPbc->setProgressA(i,predictedLength);
	mainPbc->updateProgress();
	}
      */
    }
  fclose(fp);
  *(*Buffer+i) = '\0'; 
  return i;
}


int Read_RandFile(char *FName,char **Buffer)
{
  FILE *fp;
  char ch;
  int i,Position;

  fp = fopen(FName,"r");
  if(fp == NULL)
    {
      QMessageBox::warning(appl,"Warning",QString("Cann't open file")+QString(FName));
      exit(0);
    }
  rewind(fp);
  fseek(fp,0L,SEEK_END);
  Position=ftell(fp);
  rewind(fp);
  *Buffer = (char *)malloc((Position+1)*sizeof(char));
  i=0;
  while(!feof(fp))
    {
      ch = fgetc(fp);
      ch = toupper(ch);
      switch(ch)
	{
	case 'A':
	case 'T':
	case 'C':
	case 'G':
	case 'N':
	case 'R':
	case 'W':
	case 'Y':
	case 'M':
	case 'K':
	case 'S':
	case 'H':
	case 'B':
	case 'V':	    
	case 'D':
	  *(*Buffer+i) = ch;
	  ++i;
	  break;
	default :
	  break;
	}
    }
  fclose(fp);
  *(*Buffer+i) = '\0';
  return i;
}

void reverse_complement_of_Sequence()
{
  int End;
  reverse_Genome = (char *)calloc((genomeLength + 1),sizeof(char));
  End = genomeLength - 1;
  for(int Start = 0; Start < genomeLength; Start++)
    {
      if(*(forward_Genome + (End - Start)) == 'A')	reverse_Genome[Start] = 'T';
      else if(*(forward_Genome + (End - Start)) == 'T') reverse_Genome[Start] = 'A';
      else if(*(forward_Genome + (End - Start)) == 'C')reverse_Genome[Start] = 'G';                                                                               
      else if(*(forward_Genome + (End - Start)) == 'G') reverse_Genome[Start] = 'C';
    }
  reverse_Genome[genomeLength] = '\0';
}

void seqSearch(char *Buf,char seqArr,char **Buffer,int Length) 
{
  int i;

  *Buffer = (char *)malloc((Length+1) * sizeof(char));
  for(i=0;i<Length;i++)
    {
      if(toupper(seqArr) == *(Buf+i)) *(*Buffer+i)='1';
      else
	*(*Buffer+i)='0';
    }
}


void Omega(int RowNum)
{
  int i,from1_index,to1_index,from2_index,to2_index;
  double value;
  Occur = Occur_org;
  ///////////////////////Initialization for Omega & Peak Values
    From1 =  .02;
    To1 = 0.31;
    From2 = 0.35;
    To2 = 0.5;
    PeakValue = 0.333333;
    Omega_Interval = 1.00/Occur;         
    Omega_From = Omega_Interval;
    Omega_To = 1.00;
    ///////////////////////End of Initialization
      ///////////////////////Counting of Generated Omega Values
      from1_index = (int) floor((double)(Occur - 1) * From1);
      to1_index = (int) floor((double)(Occur - 1) * To1);
      from2_index = (int) floor((double)(Occur - 1) * From2);
      to2_index = (int) floor((double)(Occur - 1) * To2);

      Occur = (to1_index - from1_index) + (to2_index - from2_index) + 4;
      ///////////////////////End of Counting
	MatrixW = (double *) calloc(Occur, sizeof(double));
	i = 0;
	for(value = From1; value <= To1; value = value + Omega_Interval)
	  MatrixW[i++] = value;
	for(value = From2; value <= To2; value = value + Omega_Interval)
	  MatrixW[i++] = value;
	if(i > Occur)
	  {
	    QMessageBox::warning(appl,"warning","Abnormal Termination:: from function (Omega())");
	    exit(0);
	  }
	Occur = i;
	//////////////////////End of Omega Value Generation
	//////////////////////Allocation for storing FW values
	Matrix = (double  **)calloc(RowNum,sizeof(double *));
	for(i = 0; i < RowNum; i++)
	  Matrix[i] = (double  *)calloc(Occur,sizeof(double ));
	//   printf("\n Occur = %d i = %d , Occur_tmp=%d RowNum=%d\n",Occur,i, Occur_tmp, RowNum); 
}

void compute_omega_parametere(int RowNum,int Length)
{
  int i;
  double value;
  int from1_index,to1_index,from2_index,to2_index;

  ///////////////////////Initialization for Omega & Peak Values
    value = 2.00/(double)Length; 	
    if( 0.02 > value )
      value = 0.02;       
    From1 =  value;
    To1 = 0.31;
    From2 = 0.35;
    value = (double) ( 1.00 - (2.00/(double)Length) ); 	  
    if( 0.5<value )
      value = 0.5;
    To2 = value;
    PeakValue = 0.333333;
    value = 2.00/(double)Length; 	
    if( 0.001 > value )
      value = 0.001;      	   
    Omega_From = value;
    value = 1.00 - value;
    Omega_To = value;
    value = 1.0/(double)Length;	
    if( 0.001 > value) 
      value = 0.001;
    Omega_Interval = value; 
    ///////////////////////End of Initialization
      ///////////////////////Counting of Generated Omega Values
      Occur = (int)ceil((Omega_To - Omega_From)/Omega_Interval + 2);
      from1_index = (int)ceil((double)(Occur - 1)*From1);
      to1_index = (int)ceil((double)(Occur - 1)*To1);
      from2_index = (int)ceil((double)(Occur - 1)*From2);
      to2_index = (int)ceil((double)(Occur - 1)*To2);

      Occur = (to1_index - from1_index) + (to2_index - from2_index) + 4;
      ///////////////////////End of Counting
	///////////////////////Omega Value generation part
	MatrixW = (double *)calloc(Occur,sizeof(double));
	i = 0;
	for(value = From1; value <= To1; value = value + Omega_Interval)
	  MatrixW[i++] = value;
	for(value = From2; value <= To2; value = value + Omega_Interval)
	  MatrixW[i++] = value;
	if(i > Occur)
	  {
	    QMessageBox::warning(appl,"warning","Abnormal Termination:: from function (compute_omega_parameter)");
	    exit(0);
	  }
	Occur = i;
	//////////////////////End of Omega Value Generation
	//////////////////////Allocation for storing FW values
	Matrix = (double **)calloc(RowNum,sizeof(double *));
	PeekValueFW = (double *)calloc(RowNum,sizeof(double));
	for(i = 0; i < RowNum; i++)
	  Matrix[i] = (double  *)calloc(Occur,sizeof(double ));
}


void fOmega(char *Buf, int Length, int RowNo)
{
  double Val,cosVal = 0.0,sinVal = 0.0;
  int i,j=0,k=0,Byte; 

  for(i = 0; i < Occur; i++)
    {
      cosVal= sinVal = 0.0;
      for(j = 0;j < Length; j++)
	{	
	  Byte = Buf[j];
	  Byte -=48;
	  Val = 2.00*(double)pie*MatrixW[i]*j;
	  cosVal += Byte*cos(Val);
	  sinVal += Byte*sin(Val);
	}
      cosVal = cosVal/(double)Length; 
      sinVal = sinVal/(double)Length;
      Matrix[RowNo][k++] = (double )sqrt((cosVal*cosVal)+(sinVal*sinVal));
    }

  if(Addaptive_Flag) 
    PeekValueFW[RowNo] = fOmega_PeekValue(Buf,Length);
}


double fOmega_PeekValue(char *Buf,int Length)
{
  double FW,Val,cosVal=0.0,sinVal=0.0,Power=2.0;
  int j=0,Byte; 

  cosVal= sinVal = 0.0;
  for(j=0;j<Length;j++)
    {	
      Byte = Buf[j];
      Byte -=48;  
      Val = (double)(2.00*pie*PeakValue*j);
      cosVal += Byte*cos(Val);
      sinVal += Byte*sin(Val);
    }
  cosVal = cosVal/(double)Length; 
  sinVal = sinVal/(double)Length;
  FW = (double )sqrt(pow(cosVal,Power)+pow(sinVal,Power));
  return FW;
}


int UnionW()
{
  int Count=0,from1_index,to1_index,from2_index,to2_index;

  from1_index=(int)floor((double)(Occur-1)*From1);  
  to1_index=(int)floor((double)(Occur-1)*To1);   
  from2_index=(int)floor((double)(Occur-1)*From2);  
  to2_index=(int)floor((double)(Occur-1)*To2);   
  return Count;
}


double Ratio(int Count)
{
  int i,index;
  double  Max[4],ratio[4],Min; 
  Min = 9999.99;

  if(!Addaptive_Flag)
    {     
      index = Occur/3 -1;  
      for(i=0;i<4;i++)
	{
	  Max[i]=FindMax(i,Count);
	  ratio[i]=Max[i]/Matrix[i][index];
	  Min = (Min > ratio[i] ? ratio[i] : Min);
	}
      //  if(Min>9000) QMessageBox::warning(0,"warning", QApplication::tr(" MIN= %1").arg(Min));
    }
  else
    {
      for(i=0;i<4;i++)
	{
	  Max[i]=FindMax(i,Count);
	  ratio[i]=Max[i]/PeekValueFW[i];
	  Min = (Min > ratio[i] ? ratio[i] : Min);
	}
    }
  return Min;
}


double FindMax(int Row,int Col)
{
  int i;
  double Max = Matrix[Row][0];
  for(i=1;i<Col;i++)
    {
      if(Max<Matrix[Row][i])
	Max=Matrix[Row][i];
    }
  return Max; 
}




void Swap(char **tempBuf, int Length,int Swap_No,double  Swap_Pro)
{
  int i,First,Second,Pro_Range,Char_Swap_Pro,Occurence_Probability,Found;
  char ch;
  unsigned int seed;

  if(Swap_Pro!=1.0)
    {
      Pro_Range=10; 
      Char_Swap_Pro = (int)(Swap_Pro * Pro_Range); 
    }
  else
    Pro_Range=Char_Swap_Pro=100;

  seed = (unsigned  int)time((time_t *)NULL);
  seed = seed*(unsigned int)(rand()%100);
  srand(seed);
  for(i=0;i<Swap_No;i++)
    {
      Occurence_Probability=(rand()%Pro_Range);   
      First=(rand()%(Length-2));
      Second=(rand()%(Length-2));
      Found=Search(Char_Swap_Pro,Occurence_Probability);
      if(Found)
	{
	  ch = *(*tempBuf+First);
	  *(*tempBuf+First) = *(*tempBuf+Second);
	  *(*tempBuf+Second) = ch;
	}
    }

}



void Mutation(char **tempBuf,int Mut_No,double  Mut_Pro,double  *Pat_Pro,int Pat_Pro_Length,int Length)
{

  int i,j,index=0,First,Occurence_Probability,Pro_Range,Char_Mut_Pro,Found,Pat_Pro_Range,Sum_Pat_Pro,Pat_Occurence_Pro; 
  char Mut_Char[]={'A','T','C','G'},ch; 
  unsigned int seed;

  Pat_Pro_Range =(int)pow(10.00,(double )Pat_Pro_Length);

  if(Mut_Pro!=1.0)
    {
      Pro_Range=10; 
      Char_Mut_Pro = (int)(Mut_Pro*Pro_Range);    
    }
  else
    Pro_Range=Char_Mut_Pro=100;

  seed = (unsigned int)time((time_t *)NULL);
  seed = seed*(unsigned int)(rand()%100);
  srand(seed);
  for(i=0;i<Mut_No;i++)
    {   
      Occurence_Probability=(rand()%Pro_Range);
      Found=Search(Char_Mut_Pro,Occurence_Probability);
      if(Found)
	{ 
	label:
	  First=(rand()% (Length-2));
	  ch=(*(*tempBuf+First));
	  if(ch!='A' && ch!='T' && ch!='C' && ch!='G')
	    {
	      printf("%c\n",ch);
	      goto label; 
	    }   
	  switch(ch)
	    {
	    case 'A' : index=0;break;
	    case 'T' : index=4;break;
	    case 'C' : index=8;break;
	    case 'G' : index=12;break;
	    }
	  Sum_Pat_Pro=0;Pat_Occurence_Pro=(rand()%Pat_Pro_Range); 
	  for(j=0;j<4;j++)
	    {
	      Sum_Pat_Pro += (int)(Pat_Pro[index+j] * Pat_Pro_Range);
	      if(Pat_Occurence_Pro<=Sum_Pat_Pro)
		break;
	    }
	  if(j<4)
	    *(*tempBuf+First) = Mut_Char[j];
	}

    }

}


int Search(int Char_Swap_Pro,int Occurence_Probability)
{ 
  if(Occurence_Probability<= Char_Swap_Pro)
    return 1;
  return 0;
}



void Read_Pat_Probability(double  *pat_prob)
{
  // 0.0,0.33,0.33,0.33,0.33,0.0,0.33,0.33,0.33,0.33,0.0,0.33,0.33,0.33,0.33,0.0
  int i;
  for(i=0;i<16;i++)
    pat_prob[i] = 0.33;

  for(i=0;i<16;i=i+5)
    pat_prob[i] = 0.0;

}


void Clear_Memory(int seqLen)
{   
  int i;  
  for(i=0;i<seqLen;i++)
    free(Matrix[i]);
  free(Matrix);
  free(MatrixW);
  if(Addaptive_Flag)
    free(PeekValueFW);      
}


double find_Region(double * min_Arr,int Operation)
{
  int i;
  double  lBound_Percent,lower_Bound=0;

  for(i=1; i<Operation; i++)
    if(min_Arr[i]< min_Arr[0])
      lower_Bound++; 

  lBound_Percent = (double )(lower_Bound/(Operation-1));
  lBound_Percent *=100.00;
  return lBound_Percent;	
}













