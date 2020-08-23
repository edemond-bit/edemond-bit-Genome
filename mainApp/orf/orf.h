#ifndef ORF_H
#define ORF_H

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

#include <qprogressbar.h>
#include <qapplication.h>
#include <qlabel.h>
#include "ProgressBarController/pbc.h"
#include "statusManager/statusManager.h"

#define pie 3.1416
#define POSITIVE '+'
#define NEGATIVE '-'

#define AFTER 0
#define BEFORE 1

class ORF
{
 private:
  pbc *mainPbc;
  statusManager *sManager;
  FILE *statusFp;
  char *forward_Genome,*reverse_Genome,**startCodon,**stopCodon;
  int genomeLength,numStartCodon,numStopCodon;
  char **curr_Dir,**record_FileName,seq_Name[50];
  char *_seq_work_dir;
  char path_Seq[200];
  int scanVal;
  int option,maxLen,minLen,filter_Option;
  char storeIn_File;
  int A,T,C,G,N,R,W,Y,M,K,S,H,B,V,D;
  QApplication *qApp;
  QProgressBar *progressBar;
  QLabel *progressText;

  ////////////////////////////////////////
  char seq_Path[100]; //Name of the sequence(ORF or Non-ORF)
  int seq_Length; //Length of the Sequence
  ////////////////////////////////////////
  int Occur,Addaptive_Flag;
  double *PeekValueFW,**Matrix,*MatrixW,From1,To1,From2,To2,PeakValue,Omega_From,Omega_To,Omega_Interval; 
  ////////////Main data processing Functions//////////
  void initiateProcess();
  void readFrameFromBothStrand(int);
  void readFrameFromBothStrand2(int);
  ////////////////////////////////////////////////////
  /////////////Filtering Functions////////////////////
  void filtering_W_R_T_Longest_ORF();
  void filtering_W_R_T_best_R_Value();
  double Compute_MinRatio(char **,int ,int );
  void compute_omega_parametere(int ,int );
  int readSeq_frm_Genome(char **,int ,int ,char );
  void sequentialSearch(char **,int ,char ,char **,int ); 
  void fOmega(char *,int ,int );
  double fOmega_PeekValue(char *,int );
  double Ratio(int );
  double FindMax(int ,int );
  void Clear_Memory(int );
  ////////////////////////////////////////////////////
  //////////////ORF Matching Functions////////////////
  bool match_ORF_StartCodon(char *,int);
  bool match_ORF_StopCodon(char *);
  ////////////////////////////////////////////////////
  //////////////ORF Recording Functions///////////////
  void record_ORF_PositiveStrand(int ,int ,char *);
  void record_ORF_NegativeStrand(int ,int ,char *);
  ////////////////////////////////////////////////////
  ///////////////Utility Functions////////////////////
  void toUpper(char **);
  void readInBuf();
  void reverse_complement_of_Sequence();
  void searchChar(char ,int , char **,char *);
  void Extract_Index(char *,int &,int &,char );
  void sort_ORF_List_File(char *,int,int,int );
  void addString(char *, const char *);
  void itoa(int, char []);
  void reverse(char *);
  ////////////////////////////////////////////////////
 public:
  ORF()
    {
      forward_Genome = reverse_Genome = NULL;
      genomeLength = 0;
      scanVal = 0;
    };
  void executePathList(char *);
  void setFilterSequence_wrt(int );

  void saveIntermediateData_toFile(bool);
  void setOption(int);
  void setMinLen(int);
  void setMaxLen(int);
  void setStartCodons(char *);
  void setStopCodons(char *);
  void openPath(char *);
  void readInBuf_GUI();
  char * frequencyOfElements();
  void executeProcess(char *);
  void setAppParameters(pbc *,statusManager *);
  ~ORF() {
  };
};
#endif
