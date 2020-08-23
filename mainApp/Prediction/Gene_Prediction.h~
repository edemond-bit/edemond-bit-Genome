
	#include "MinHeader.h"
	#include "../Random_Seq/Random_Sequence.h"
	#include "../Random_Seq/RandomDialog.h"
	#include "../statusManager/statusManager.h"
	#include "F_Ratio.h"
	#include <string.h>
	#include <qlabel.h> 
	#include <qmessagebox.h>
	#include <stdio.h>
	#include <sys/stat.h>
	#define Start_frequency 50
	#define interval 5
	#define PLR 300

	void Pat_Search(char *,int ,int ,int &);
	void generatePatterns(char **, int ,int );
	void Create_Pattern(char PatArray[][3]);
	void DisJoinSearch(char *Buffer,int Pattern_Count[],char PatArray[][3],int Length,int seqLen);
	void DisJoinSearch(int ,int );
	void OverLapping_Search(int ,int );
	int Compare_Pat_Seq(char *seqArr);
	int Read_Dir(char *Dir,int file_id,char nameSpace[]);
	void Read_Dir_P_Value(char *Dir,int file_id,char nameSpace[]);  
	void compute_R_Statistic_ForRandomSequences(char misc[]);
	void compute_P_Value_ForRandomSequences(char misc[]);
	double Compute_MinRatio(char *,int ,char );
	double Compute_P_Value(char *,int ,char );
	int Find_Potential_NonPotential_File(char nameSpace[], char misc[], QLabel *, char *, int _inputType, int _MIN_CHAR, int _MAX_CHAR,int processId);
	void Separate_File(double MinRatio,char *PathName,int file_id,int fileLength);
	double Distance(double Test_Pattern_Count[],double Train_Pattern_Count[],int Pattern_Len);
	//////////////////////////////////////////////Debabrata Mondal
	int analysis_Nearest_Neighbourhood_Computation(char nameSpace[],char misc[],int iteration,int Train_Gene_Count, int Train_NonGene_Count);
	//int readSequenceFromGenome(char *,char **,int ,char );
	int readSequenceFromGenome(char *PathName,int file_id,char sign);
	void Extract_Index(char *,int &,int &,char );

	////////////////////////////////////////////End(Debabrata Mondal)

	void Decission_Gene_NonGene(char * Path,double MinRatio,int fileLength,int file_id,double *Gene_Distance,double *NonGene_Distance,int iteration);
	double Sum_Gene_Distance(double *Gene_Distance,int Train_File_Count,int Trim1,int Trim2);
	void SORT(double *Gene_Distance,int Train_File_Count);
	void Gene_Frequency_Compute(double detection_Percentage, int i);
	void NonGene_Frequency_Compute(double detection_Percentage, int i);
	void Extract_Folder_Name( char *PathName,char *Temp_Path);
	void Validation_Trim(void);
	void Free_All_Pattern_Count(void);
	void Free_Allocated_Memory(void); 
	double R_Statistic_for_P(char *PathName,int );
	/////////////////////////////////////////////////////////Debabrata Mondal
	void reThresholding_SmallGenes(char *, double, int );
	void Filter_FinalPred_File(char *nameSpace);
	void MultipleFileFinder();
	void RBSFinder();
	void FilterRBSOutPut();
	void Ribosome_PatternSelection();
	void Calculate_Scores(char [],int ,char RPat[][6],int ***);
	void Calculate_Avg_Scores(int ***,int ,double *);
	void Find_Max_Avg_Scores_And_Save_5bps(double *,char RPat[][6]);
	void searchToken(char ,int ,char **,char *);
	///////////////////////////// for GUI
	void checkIfFileExistDeleteIt(char *);
	void findSizeOfAllORF();
	void findTotalSizeOfORFFile(char *);
	void updateProgressBar_p_value(int);
	////////////////////////////////////////////////////
	int count_record_lenght_of_file(char *file_name);
	void write_method_type();
	char* GetSystemOutput(char* cmd);
	
	
	
	
	
	class SEQLIST
	{
	 public:
	  char seq[50], Strand;
	  int Pos1, Pos2;
	  SEQLIST *next;
	};
	void FreeList(SEQLIST **);

	//------------------------------------------------------------------------------------------------------------//
	char *mainPath;
	int Path_Count,Operation,Trim1,Trim2,Trim3,Trim4;
	int Total_File=0,Total_Gene=0,Total_NonGene=0,*Program_Detect_Gene,*Program_Detect_NonGene;

	int Start_Index_Potential_Gene, Potential_Gene_Count=0, Start_Index_Potential_NonGene, Potential_NonGene_Count=0,Start_Index_NonPotential_Sequence, NonPotential_Sequence_Count=0;
	int **Gene_detection_frequency, **NonGene_detection_frequency , *Undecided;
	double **ALL_Patern_Count,**ALL_Patern_Count2,*frequency_value,MinRatio_Gene,MinRatio_NonGene,swap_Percent,mut_Percent;
	char **PatArray_Gen,**PatArray_Small; //For storing Generated Patterns

	//------------------------------------------------------------------------------------------------------------//
	////////////////Debabrata/////////////////////////////////////////////////////////////////////////////////////
	//----------------------------Gene_Prediction----------------------------------
	float base_Threshold_Val;
	char curr_Dir[400],work_Dir_File_Path[400],isPrint_R_P;
	//char seq_work_dir[100];
	char nameSpace[2][400],misc[2][400],f_Ratio_File[2][400],filtered_Pattern[4][450];

	//-------------------------Gene_Prediction_File.h--------------------------------

	void computation_R_Statistic(const char * _FileName, int _MIN_CHAR, int _MAX_CHAR, const char *_seq_FileName,char _isPrint_R_P, int _Occur);
	void computation_Lower_Tail_Probability(const char * _FileName, int _MIN_CHAR, int _MAX_CHAR, const char * _seq_FileName, char _isPrint_R_P, int _Occur, int _Operation, double _swap_Percent, double _mut_Percen );
	void remove_Record_Files(char nameSpace[], char misc[],char f_Ratio_File[], char filtered_Pattern[]);
	void thresholding_R_Statistic(char nameSpace[], char misc[], char f_Ratio_File[], char filtered_Pattern[], QLabel *,int _inputType, int _MIN_CHAR, int _MAX_CHAR,int);
	void Compute_All_File_PatternCount( char nameSpace[], char misc[]);
	//void Compute_All_File_PatternCount_v2(char nameSpace[], char misc[]);
	void filtering_F_Ratio(char nameSpace[], char misc[], char f_Ratio_File[], char filtered_Pattern1[],char filtered_Pattern2[],QLabel *,int);
	void analysis_Nearest_Neighbourhood(char nameSpace[], char misc[], char filtered_Pattern1[],char filtered_Pattern2[], double, double, int , int);
	bool change_Directory(char *);
	void load_Path(char *);
	void fetch_Current_Dir();
	//void searchToken(char delim,int Occurance, char **token, char *string);
	int check_nameSpace_File(char nameSpace[]);
	void delete_nameSpace(char nameSpace[]);
	void delete_misc(char misc[]);
	void delete_F_Ratio(char f_Ratio_File[]);
	void delete_Filtered_Pattern(char filtered_Pattern[]);
	//-------------------------Gene_Prediction.h-------------------------------------
	double compute_Absolute_Distance(int ,int ,int ,int ,int );

	void fRatio_Computation();

	void fRatio_Calculation(char filtered_Pattern1[],char filtered_Pattern2[], QLabel *, double, int);

	void fRatio_Val_Sort(double f_Ratio[]);
	void free_MemForAll_Pattern_Count();
	//-------------------------------------------------------------------------------
	double *distanceMatrix,*distanceMatrix2; // used to store absolute distances fr diff purposes
	double *f_Ratio;
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//For F-Ratio
	int wordSize_Gen,wordSize_Small,NumPat_Gen,NumPat_Small,TotalPat_Gen,TotalPat_Small;//For used with Generated Patterns
	int *All_Pattern_Len;
	char *Seq_Buffer; // For Storing Sequences
	char **Result; 
	char poten_Gene_FileName[400],poten_NGene_FileName[400],nPoten_Seq_FileName[400];
	int DiscardRandomSet;

	int methodType=1; // 1 ~ all tri neucleotide, 2 ~ (60 - 300): tetra neucleotide and >300: tri neucletide


	double compute_Absolute_Distance(int numRows,int numCols,int baseIndx,int pattern_id,int compType) //Used for pattern wise absolute distance calculation
	{
	  double distanceBetween_Sum,distanceWithin_Sum,ret_Val=0.0;
	  distanceBetween_Sum = distanceWithin_Sum = 0.0;
		 
	  if(methodType == 1)
	    {
	      if(compType == 0)
		{
		  for(int j = 0; j < numRows; j++)
		    {
		      for(int k = 0; k < numCols; k++)
			distanceBetween_Sum += fabs(ALL_Patern_Count[j][pattern_id] - ALL_Patern_Count[baseIndx + k][pattern_id]);
		    }
		  ret_Val = distanceBetween_Sum/(double)(numRows * numCols);
		}
	      else
		{
		  for(int j = 0; j < numRows - 1; j++)
		    {
		      for(int k = j + 1, l = 0; k < numCols; k++,l++)
			distanceWithin_Sum += fabs(ALL_Patern_Count[baseIndx + j][pattern_id] - ALL_Patern_Count[baseIndx + k][pattern_id]);
		    }
		  ret_Val = distanceWithin_Sum;
		}
	    }
	  else if(methodType == 2)
	    {
	      if(compType == 0)
		{
		  for(int j = 0; j < numRows; j++)
		    {
		      for(int k = 0; k < numCols; k++)
			distanceBetween_Sum += fabs(ALL_Patern_Count2[j][pattern_id] - ALL_Patern_Count2[baseIndx + k][pattern_id]);
		    }
		  ret_Val = distanceBetween_Sum/(double)(numRows * numCols);
		}
	      else
		{
		  for(int j = 0; j < numRows - 1; j++)
		    {
		      for(int k = j + 1; k < numCols; k++)
			distanceWithin_Sum += fabs(ALL_Patern_Count2[baseIndx + j][pattern_id] - ALL_Patern_Count2[baseIndx + k][pattern_id]);
		    }
		  ret_Val = distanceWithin_Sum;
		}
	    }
	  return ret_Val;
	}


	void fRatio_Computation()
	{
	  double distanceBetween_Avg,distanceWithin_Sum,distanceWithin_Avg;
		 
	  if(methodType == 1)
	    {
	      TotalPat_Small = 192;
	      f_Ratio = (double *)calloc(192,sizeof(double));
	      for(int i = 0; i < 192; ++i)
		{
		  //Between Group
		  distanceBetween_Avg = compute_Absolute_Distance(Potential_Gene_Count,Potential_NonGene_Count,Potential_Gene_Count,i,0);
		  //Within Group
		  distanceWithin_Sum = 0.0;
		  distanceWithin_Sum += compute_Absolute_Distance(Potential_Gene_Count,Potential_Gene_Count,0,i,1);
		  distanceWithin_Sum += compute_Absolute_Distance(Potential_NonGene_Count,Potential_NonGene_Count,Potential_Gene_Count,i,1);
		  distanceWithin_Avg =  distanceWithin_Sum/(double)((Potential_Gene_Count*(Potential_Gene_Count-1)) / 2.0 + (Potential_NonGene_Count*(Potential_NonGene_Count-1)) / 2.0);  
		  f_Ratio[i] = (distanceWithin_Avg <= 0 ? 0 : distanceBetween_Avg / distanceWithin_Avg);
		}
	    }
	  else if(methodType == 2)
	    {
	      f_Ratio = (double *)calloc(TotalPat_Small,sizeof(double));
	      for(int i = 0; i < TotalPat_Small; ++i)
		{
		  //Between Group
		  distanceBetween_Avg = compute_Absolute_Distance(Potential_Gene_Count,Potential_NonGene_Count,Potential_Gene_Count,i,0);
		  //Within Group
		  distanceWithin_Sum = 0.0;
		  distanceWithin_Sum += compute_Absolute_Distance(Potential_Gene_Count,Potential_Gene_Count,0,i,1);
		  distanceWithin_Sum += compute_Absolute_Distance(Potential_NonGene_Count,Potential_NonGene_Count,Potential_Gene_Count,i,1);
		  distanceWithin_Avg =  distanceWithin_Sum/(double)((Potential_Gene_Count*(Potential_Gene_Count-1)) / 2.0 + (Potential_NonGene_Count*(Potential_NonGene_Count-1)) / 2.0);  
		  f_Ratio[i] = (distanceWithin_Avg <= 0.0 ? 0.0 : distanceBetween_Avg / distanceWithin_Avg);
		}
	    }
	}

	void fRatio_Calculation(char filtered_Pattern1[],char filtered_Pattern2[],QLabel *textLabel, double threshold_Val, int processId)
	{
	  char temp_Str1[10],temp_Str2[10],T_Path[400];
	  double f_Ratio_temp[TotalPat_Small],sum_F_Ratio = 0.0;
	  int above_FRatio_Count;
	  FILE *fp_Filter,*fp;
	  char fratioOutput[400];

		 
	  for(int i = 0; i < TotalPat_Small; ++i)
	    {
	      f_Ratio_temp[i] = f_Ratio[i];
	      sum_F_Ratio += f_Ratio[i];
	    }
		  
	  fRatio_Val_Sort(f_Ratio_temp);
		 
	  system("clear");
	  sprintf(fratioOutput,"<u>F-Ratio Statistic</u><br/>Maximum: %0.6lf<br/>Minimum: %0.6lf<br/>Mean: %0.6lf <br/>Median: %0.6lf <br/>Quartile 1:  %0.6lf<br/>Quartile 2:  %0.6lf<br/>Quartile 3:  %0.6lf<br/>",f_Ratio_temp[TotalPat_Small - 1],f_Ratio_temp[0],sum_F_Ratio/double(TotalPat_Small),(f_Ratio_temp[TotalPat_Small/2 - 1] + f_Ratio_temp[TotalPat_Small/2]) / 2.0,(f_Ratio_temp[TotalPat_Small/2 - 1] + f_Ratio_temp[TotalPat_Small/2]) / 4.0,(f_Ratio_temp[TotalPat_Small/2 - 1] + f_Ratio_temp[TotalPat_Small/2]) / 2.0,3*((f_Ratio_temp[TotalPat_Small/2 - 1] + f_Ratio_temp[TotalPat_Small/2])/4.0));
		  

		  
	  textLabel->setText((const char *)fratioOutput);
	  if (threshold_Val<0) return; // calling only to display the statistics
		     
		   
		   
		   
		   
	  above_FRatio_Count = 0;
	  sprintf(temp_Str1,"%0.6lf",threshold_Val);
	  for(int i = TotalPat_Small - 1; i >= 0; i--)
	    {
	      sprintf(temp_Str2,"%0.6lf",f_Ratio_temp[i]);
	      if(strcmp(temp_Str2,temp_Str1) >= 0)
		above_FRatio_Count++;
	      else
		break;
	    }
	  /////////////////////////////////////////////////////////Store sorted f-ratio values in file
		  
	  sprintf(fratioOutput,"%s",fratioOutput);

	  textLabel->setText((const char *)fratioOutput);
		     
	  QString str;
	  str = QString( "Number of pattern with F-Ratio above threshold : %1" )
	    .arg( above_FRatio_Count );
	  //QMessageBox::information(appl,"F-Ratio result", str); 

	   int opt = 0;
	   if(interactiveMode) opt = QMessageBox::information( appl, "Application name",
					      str,
					      "Ok",
					      "Cancel", 0, 0, 1 ) ;

	  if(threshold_Val>0)
	    switch(opt ) {
	    case 0: 
		        
		  
	      /////////////////////////////////////////////////////For Saving DATA after       confirmation/////////////////////
		  
	      // store the threshold value to a file
		  
	      sprintf(T_Path,"%s/fratio%d.txt",seq_work_dir,choice);
	      fp = fopen(T_Path,"w");
	      fprintf(fp,"%lf",threshold_Val);
	      fclose(fp);
		  
	      printf("\n filtered_Pattern count :%s",filtered_Pattern1);
		 
	      if(methodType == 1)
		{
		  if((fp_Filter = fopen(filtered_Pattern1,"w")) != NULL) //Store data for trinucleotide (sequences column wise & relative frequency values row wise)
		    {
		      fprintf(fp_Filter,"%d\n",above_FRatio_Count);
		      for(int i = 0; i < TotalPat_Gen; ++i)
			{
			  sprintf(temp_Str2,"%0.6lf",f_Ratio[i]);
			  if(strcmp(temp_Str2,temp_Str1) >= 0)
			    {
			      for(int j = 0; j < Total_File; ++j)
				{
				  if(j <  Total_File - 1)
				    fprintf(fp_Filter,"%lf\t",ALL_Patern_Count[j][i]);
				  else
				    fprintf(fp_Filter,"%lf",ALL_Patern_Count[j][i]);
				}
			      fprintf(fp_Filter,"\n");
			    }
			}
		    }
		}
	      else if(methodType == 2)
		{
		  if((fp_Filter = fopen(filtered_Pattern1,"w")) != NULL) //Store data for trinucleotide (sequences column wise & relative frequency values row wise)
		    { 
		      fprintf(fp_Filter,"%d\n",TotalPat_Gen);
		      for(int i = 0; i < TotalPat_Gen; ++i)
			{
			  for(int j = 0; j < Total_File; ++j)
			    {
		      
			      if(j <  Total_File - 1)
				fprintf(fp_Filter,"%lf\t",ALL_Patern_Count[j][i]);
			      else
				fprintf(fp_Filter,"%lf",ALL_Patern_Count[j][i]);
			    }
			  fprintf(fp_Filter,"\n");
			}
		    }
		  fclose(fp_Filter);
		  fp_Filter = NULL;
			
		  if((fp_Filter = fopen(filtered_Pattern2,"w")) != NULL) //Store data for tetranucleotide (sequences column wise & relative frequency values row wise)
		    {
		      fprintf(fp_Filter,"%d\n",above_FRatio_Count);
		      for(int i = 0; i < TotalPat_Small; ++i)
			{
			  sprintf(temp_Str2,"%0.6lf",f_Ratio[i]);
			  if(strcmp(temp_Str2,temp_Str1) >= 0)
			    {
			      for(int j = 0; j < Total_File; ++j)
				{
				  if(j <  Total_File - 1)
				    fprintf(fp_Filter,"%lf\t",ALL_Patern_Count2[j][i]);
				  else
				    fprintf(fp_Filter,"%lf",ALL_Patern_Count2[j][i]);
				}
			      fprintf(fp_Filter,"\n");
			    }
			}
		      fclose(fp_Filter);
		      fp_Filter = NULL;
		    }
		}
	      sprintf(T_Path,"%s/Pattern_Len.txt",seq_work_dir);
	      fp=fopen(T_Path,"w");
	      for(int j = 0; j < Total_File; ++j)
		fprintf(fp,"%d\n",All_Pattern_Len[j]);
	      fclose(fp);
	      fp = NULL;
	      write_method_type();
	      // process has usccessfully completed
	      sManager->setProcessState(processId,"100");
	      sManager->setProcessState(processId+1,"0");
	      sManager->setProcessState(processId+2,"0");
	      break;
	    case 1: // The user clicked the Quit or pressed Escape
	      // exit
	      sprintf(T_Path,"rm %s/fratio%d.txt",seq_work_dir,choice);
	      system(T_Path);
		 
	      sManager->setProcessState(processId,"20");
	      break;
	    }
		        
		        
		          
	  if(mainPbc->pbcWasCanceled()){
	    sManager->setProcessState(processId,"20");
	  }
		  
		    
	}



	void fRatio_Val_Sort(double f_Ratio[]) //Modified Bubble Sort
	{
	  double temp_F_Ratio;
	  bool flag_Bubble;
		 
	  for(int i = 0; i < TotalPat_Small - 1; ++i)
	    {
	      flag_Bubble = false;
	      for(int j = TotalPat_Small - 1; j > i; --j)
		{
		  if(f_Ratio[j] < f_Ratio[j - 1])
		    {
		      temp_F_Ratio = f_Ratio[j];
		      f_Ratio[j] = f_Ratio[j - 1];
		      f_Ratio[j - 1] = temp_F_Ratio;
		      flag_Bubble = true;
		    }
		}
	      if(flag_Bubble == false) //All elements are sorted
		break;
	    }
	}

	void free_MemForAll_Pattern_Count()
	{
	  for(int i = 0; i < Total_File; ++i)
	    free(ALL_Patern_Count[i]);
	  free(ALL_Patern_Count);
	  ALL_Patern_Count = NULL;
		  
	  if(methodType == 2)
	    {
	      for(int i = 0; i < Total_File; ++i)
		free(ALL_Patern_Count2[i]);
	      free(ALL_Patern_Count2);
	      ALL_Patern_Count2 = NULL;
	    }
			
	  free(All_Pattern_Len);
	  All_Pattern_Len = NULL;
	}
	//////////////////End Debabrata////////////////////////////////////////////////////////////////////////


	int  Read_Dir( char *Dir, int file_id, char nameSpace[] ) //recursivly scan directory to find files
	{
	  char PathName[400], Temp_Path[400], sign, seq_FileName[400];
	  int size, temp_size, file_Count, temp_count = 0;
	  double MinRatio;  
	  QString qtemps( "" );
	  FILE *fp, *fp_NameSpace, *fp_R; 

	  base_Threshold_Val = 1.0;  
	  sign = ( file_id < 2 ? '+' : '-' );
	  if( ( fp_NameSpace = fopen(nameSpace, "r") ) != NULL) 
	    {
	      fscanf( fp_NameSpace, "%d", &file_Count );
	      fscanf( fp_NameSpace, "%s", seq_FileName );
	      fscanf( fp_NameSpace, "%s", seq_FileName );
	      fclose( fp_NameSpace);
		    
	      fp = fopen( Dir, "r" );
	      if( !fp )
		{
		  qtemps = "Application terminating:: Can not open file :" + QString( Dir );
		  QMessageBox::warning( appl, "Warning", qtemps );
		  exit( 0 );
		}  
	      fscanf( fp, "%s\t%d" ,PathName, &size); 
	      temp_size = size;
	      while(1)
		{
		  strcpy( Temp_Path, PathName );
		  if( ( inputType == 2 && size >= MIN_CHAR && size <= MAX_CHAR ) || inputType == 1 )
		    {
		      if( size < PLR )
			{
			  MinRatio = base_Threshold_Val;
			  fileLength = size;
			  ++ Total_File;
			}
		      else
			MinRatio = Compute_MinRatio(PathName,file_id,sign);    
		      fp_R = fopen(seq_FileName,"a");
		      fprintf(fp_R,"%s\t%.12lf\t%d\t%d\n",PathName,MinRatio,file_id,fileLength); 
		      fclose(fp_R);   
		    }      
		  fscanf(fp,"%s\t%d",PathName,&size);   
		  if(strcmp(PathName,Temp_Path) == 0 || (inputType == 2 && temp_size > MAX_CHAR)){
		                              
		    break;
		  }
		  else	temp_size = size;
		  temp_count++;
		  if(temp_count%10){
		    if(mainPbc->pbcWasCanceled()) break;
		    mainPbc->setProgressA(size, MAX_CHAR);
		    mainPbc->updateProgress();
		  }
		}
	      fclose(fp);
	    } else return 0;
	  return 1;
	}
		     
	void compute_R_Statistic_ForRandomSequences(char misc[])
	{
	  char PathName[400],Temp_Path[400],sign;
	  int size,file_id,file_Count;
	  double MinRatio;  
	  FILE *fp,*fp_R,*fp_Misc; 

		  
	  base_Threshold_Val = 1.0;
	  if((fp_Misc = fopen(misc,"r")) != NULL)
	    {
	      fscanf(fp_Misc,"%d%d%d",&file_Count,&file_Count,&file_Count);
	      fclose(fp_Misc);
	    }
	  Total_File = file_Count;
	  sprintf(Temp_Path,"%s/RStat_Rand",seq_work_dir);
		  
	  fp_R = fopen(Temp_Path   ,"w");
	  fclose(fp_R);
	  fp_R = NULL;
			
	  file_id = 4;
	  sign = '+';
	  ///////////////////////////////////
	  int rand_file_length=count_record_lenght_of_file(randFileName);
	  int tmp_count=0;
	  //////////////////////////////////////////////
	  fp = fopen(randFileName,"r");
	  if(!fp)
	    {
	      QMessageBox::warning(appl,"Warning",QString("Con not open file :- ")+QString(randFileName));
	      printf("Can not open file:-  %s\n",randFileName);
	      exit(0);
	    }  
	  fscanf(fp,"%s\t%d\n",PathName,&size); 
	  mainPbc->pbcReset();   	      
	  mainPbc->addAChildProcess(100,"Compute R-statistic for random sequence");
	  while(1)
	    {
		  
		       
	      if(size < PLR)
		{
		      
		  MinRatio = base_Threshold_Val;
		  fileLength = size;    
		  ++Total_File; 
		}
	      else
		{
		                               

		  MinRatio = Compute_MinRatio(PathName,file_id,sign);
		}

	      sprintf(Temp_Path,"%s/RStat_Rand",seq_work_dir);


	      fp_R = fopen(Temp_Path   ,"a");

	      fprintf(fp_R,"%s\t%.12lf\t%d\t%d\n",PathName,MinRatio,file_id,fileLength);
		      
	      fclose(fp_R);   
	      strcpy(Temp_Path,PathName);
	      fscanf(fp,"%s\t%d\n",PathName,&size);   

	      if(strcmp(PathName,Temp_Path) == 0)
		break;
		 

	      mainPbc->setProgressA(tmp_count++,rand_file_length);
	      mainPbc->updateProgress();
	      if(mainPbc->pbcWasCanceled()) {
		mainPbc->deleteLastChildProcess();
		fclose(fp);
		//Random generation canceled logged
		sprintf(Temp_Path,"%s/RStat_Rand_process_state",seq_work_dir);
		fp=fopen(Temp_Path,"w");
		fprintf(fp,"%d",1); // 1-> Rstat for random computation has been canceled.
		fclose(fp);
		return;
	      }
	    }
	  fclose(fp);
	  sprintf(Temp_Path,"%s/RStat_Rand_process_state",seq_work_dir);
	  fp=fopen(Temp_Path,"w");
	  fprintf(fp,"%d",0); // 1-> Rstat for random computation has been completed.
	  mainPbc->deleteLastChildProcess();
	  fclose(fp);
	  if((fp_Misc = fopen(misc,"w")) != NULL)
	    {
	      fprintf(fp_Misc,"3\n5\n%d\n%d\n",file_Count,Total_File);
	      fclose(fp_Misc);
	    }
		  

	}





	double Compute_MinRatio(char *PathName,int file_id,char sign)
	{    
	  int i,seqLen=4;
	  char  *TempBuf, seqArr[4]={'A','T','C','G'};
	  double MinRatio;
		               
	  ++Total_File;
	  fileLength = readSequenceFromGenome(PathName,file_id,sign);
	  if(!Addaptive_Flag)  
	    Omega(seqLen);
	  else
	    compute_omega_parametere(seqLen,fileLength);
		  
	  for(i=0;i<seqLen;i++)
	    {
	      seqSearch(Seq_Buffer,seqArr[i],&TempBuf,fileLength);
	      fOmega(TempBuf,fileLength,i);
	      free(TempBuf);
	    }
		    
	  MinRatio = Ratio(Occur);//Occur ~ Count
	  free(Seq_Buffer);
	  Clear_Memory(seqLen);
	  if(isPrint_R_P == 'Y')  
	    printf("%s - %.12f - %d\n",PathName,MinRatio,file_id); 
	  return MinRatio;
	}

	void Read_Dir_P_Value(char *Dir,int file_id,char nameSpace[]) //recursivly scan directory to find files
	{
		  char PathName[400],Temp_Path[400],sign,seq_FileName[400];
		  int size,temp_size,file_Count, temp_count=0;
		  FILE *fp,*fp_NameSpace,*fp_P; 
		  double lBound_Percent;
		//  struct stat stFileInfo;	  
		  base_Threshold_Val = 35.0;
		  QString qtemps("");
		  
		 
		  sign = (file_id < 2 ? '+' : '-');
		  if((fp_NameSpace = fopen(nameSpace,"r")) != NULL)
		  {
		  
	
		  
		  	fscanf(fp_NameSpace,"%d",&file_Count);
		  	fscanf(fp_NameSpace,"%s",seq_FileName);
		  	fscanf(fp_NameSpace,"%s",seq_FileName);
		  	fclose(fp_NameSpace);
			fp = fopen(Dir,"r");
			if(!fp)
			{
			
			       	qtemps = "Application terminating :: Can not open file :"+QString(Dir);
			       	QMessageBox::warning(appl,"warning", qtemps);
		  		printf("Can not open file:-  %s\n",Dir);
			  	exit(0);
			
			}  
			 
			
			
			
		      	fscanf(fp,"%s\t%d",PathName,&size); 
		        printf("\nRead_dir_P_value: pathName - %s, size -  %d", PathName, size);
		      	temp_size = size;
		      	printf("\n ****************  start while *********************\n");
		      	while(1)
			{
			
				strcpy(Temp_Path,PathName);
				if((inputType == 2 && size>=MIN_CHAR && size<=MAX_CHAR) || inputType == 1)
				{
				
					if(size <PLR)
					{
					
						lBound_Percent = base_Threshold_Val;
						fileLength = size;
						++ Total_File;
			      		
			      		}
			      		else
						lBound_Percent = Compute_P_Value(PathName,file_id,sign); 
					
					if(mainPbc->pbcWasCanceled())
					{
					
						break;
			        	
			        	}
			        	
					fp_P = fopen(seq_FileName,"a");
					fprintf(fp_P,"%s\t%.12lf\t%d\t%d\n",PathName,lBound_Percent,file_id,fileLength);
					fclose(fp_P);
					if(mainPbc->pbcWasCanceled()) break;
					updateProgressBar_p_value(size);
				}	      
				fscanf(fp,"%s\t%d",PathName,&size);
				if(strcmp(PathName,Temp_Path) == 0 || (inputType == 2 && temp_size > MAX_CHAR))
					break;
				else
					temp_size = size;
				temp_count++;
				if(temp_count%5==0){
					if(mainPbc->pbcWasCanceled()) break;
				}   
				  
			}
			printf("\n ****************  exit while *********************\n");
			fclose(fp);
			mainPbc->updateProgress();
			if(mainPbc->pbcWasCanceled()){
				return;
			}
		}else {
			printf("\n Can not open nameSpace file: %s", nameSpace);
		}
	}
	
	
	
	/**
		This method used for progress computation only
	*/
	void updateProgressBar_p_value(int size){
	
		FILE *fp;

		char tmp_str[400];

		int totalSize = 0;
		
		int skippedSize = 0;
		
		// Skipp the progress if size < PLR as in this case no P-Value is being computed
		// totalSize also dose not include those values
		if( size < PLR ) return;
		
		sprintf(tmp_str, "%s/.tmp.txt", seq_work_dir);
		
		fp=fopen(tmp_str, "r");
		fscanf(fp, "%d %d", &totalSize, &skippedSize);
		fclose(fp);  	
	  
	  
	  
		skippedSize +=size;
		fp=fopen(tmp_str, "w");
  		fprintf(fp, "%d %d", totalSize, skippedSize);
 		fclose(fp);
	printf( "\ntotal = %d, skipped %d", totalSize, skippedSize);
		mainPbc->setProgressA(skippedSize ,totalSize);
		mainPbc->updateProgress();
	}


	void compute_P_Value_ForRandomSequences(char misc[])
	{
	  char PathName[400],Temp_Path[400],sign;
	  int size,file_id,file_Count;
	  double lBound_Percent;  
	  FILE *fp,*fp_P,*fp_Misc,*Fp_Bckup; 
		     
		    
	  printf("\n misc=%s",misc);         
	  base_Threshold_Val = 35.0;
	  if((fp_Misc = fopen(misc,"r")) != NULL)
	    {
	      fscanf(fp_Misc,"%d%d%d",&file_Count,&file_Count,&file_Count);
		      
	      fclose(fp_Misc);

	    } else {
	    printf("\n could not found file : %s",misc);
	  }
		    

		      
	  Total_File = file_Count;
		  
	  sprintf(Temp_Path,"%s/PVal_Rand",seq_work_dir);
	  fp_P = fopen(Temp_Path,"w");
	  fclose(fp_P);
	  fp_P = NULL;
	  file_id = 4;
	  sign = '+';
	  ////////////Read from Back up
	  sprintf(Temp_Path,"%s/Backup_P_Val.txt",seq_work_dir);
	  Fp_Bckup = fopen(Temp_Path,"r");
	  fscanf(Fp_Bckup,"%d\t%lf\t%lf",&Operation,&swap_Percent,&mut_Percent);
	  fclose(Fp_Bckup);
	  Fp_Bckup = NULL;
	  ///////////////////////////////////
	  int rand_file_length=count_record_lenght_of_file(randFileName);
	  int tmp_count=0;
	  //////////////////////////////////////////////
	  ///////////////////////////////////////////////
	  fp = fopen(randFileName,"r");
	  if(!fp)
	    {
	      printf("Can not open file:-  %s\n",randFileName);
	      exit(0);
	    }
	  fscanf(fp,"%s\t%d",PathName,&size); 
	  mainPbc->pbcReset();
	  mainPbc->addAChildProcess(100,"Compute P-value for random sequence");
		      
	  while(1)
	    {
     
	      if(size < PLR)
		{
		  lBound_Percent = base_Threshold_Val;
		  fileLength = size;
		  ++Total_File;
		}
	      else
		lBound_Percent = Compute_P_Value(PathName,file_id,sign);
	      sprintf(Temp_Path,"%s/PVal_Rand",seq_work_dir);
	      fp_P = fopen(Temp_Path,"a");
	      fprintf(fp_P,"%s\t%.12lf\t%d\t%d\n",PathName,lBound_Percent,file_id,fileLength); 
	      fclose(fp_P); 
	        strcpy(Temp_Path,PathName);  
	      fscanf(fp,"%s\t%d",PathName,&size);  
	  
	      if(strcmp(PathName,Temp_Path) == 0)   break;
	      mainPbc->setProgressA(tmp_count++,rand_file_length);
	      mainPbc->updateProgress();
	      if(mainPbc->pbcWasCanceled()) {
		mainPbc->deleteLastChildProcess();
		fclose(fp);
		//P-Value for random has been canceled logged
		sprintf(Temp_Path,"%s/PVal_Rand_process_state",seq_work_dir);
		fp=fopen(Temp_Path,"w");
		fprintf(fp,"%d",1); // 1-> PVal for random computation has been canceled.
		fclose(fp);
		return;
	      }
	    }
	  
		    
		    
		    
		 
	  mainPbc->deleteLastChildProcess();

	  //Random generation canceled logged
	  sprintf(Temp_Path,"%s/PVal_Rand_process_state",seq_work_dir);
	  fp=fopen(Temp_Path,"w");
	  fprintf(fp,"%d",0); // 0-> PVal for random computation has been completed.
	  fclose(fp);
	  if((fp_Misc = fopen(misc,"w")) != NULL)
	    {
	      fprintf(fp_Misc,"3\n5\n%d\n%d\n",file_Count,Total_File);
	      fclose(fp_Misc);
	    }
	}



	double Compute_P_Value(char *PathName,int file_id,char sign)
	{    
	  int i,seqLen=4;
	  char *Buf,*TempBuf,seqArr[4]={'A','T','C','G'};
	  double *MinRatio;
	  int Loop,swap_No,mut_No,Pat_Prob_Length;
	  double swap_Pro,mut_Pro,Pat_Prob[16],lBound_Percent;  
		//cout<< " now computing P value .... Compute_P_Value";     
	  swap_Pro=1.0;
	  mut_Pro=1.0;   
	  ++Total_File;
	  MinRatio = (double *)malloc(sizeof(double)*(Operation+1));
		     
	  fileLength = readSequenceFromGenome(PathName,file_id,sign);
		     
	  if(!Addaptive_Flag)  
	    Omega(seqLen);
	  else
	    compute_omega_parametere(seqLen,fileLength);
		     
	  for(i=0;i<seqLen;i++)
	    {
	      seqSearch(Seq_Buffer,seqArr[i],&TempBuf,fileLength);
	      fOmega(TempBuf,fileLength,i);
	      free(TempBuf);
	    }

	  MinRatio[0] = Ratio(Occur);

	  Buf = (char *)malloc((fileLength+1)*sizeof(char));
	  swap_No = (int)(fileLength*(swap_Percent/100));
	  mut_No = (int)(fileLength*(mut_Percent/100));
	  Read_Pat_Probability(Pat_Prob);
	  Pat_Prob_Length = 2;
		 
	  for(Loop=1; Loop<=Operation; Loop++)
	    {
	      strcpy(Buf,Seq_Buffer);
	      Swap(&Buf,fileLength,swap_No,swap_Pro);
	      Mutation(&Buf,mut_No,mut_Pro,Pat_Prob,Pat_Prob_Length,fileLength); 
	      for(i=0;i<seqLen;i++)
		{
		  seqSearch(Buf,seqArr[i],&TempBuf,fileLength);
		  fOmega(TempBuf,fileLength,i);
		  free(TempBuf);
		} 
		MinRatio[Loop] = Ratio(Occur);
	      // printf("\n inner loop fOmega function ended");
	   //mainPbc->updateProgress();
	    //  if(mainPbc->pbcWasCanceled()) break;
	     
		      
	    }
		    
	  free(Buf); 
	  free(Seq_Buffer); 
	  Clear_Memory(seqLen);
	  lBound_Percent = find_Region(MinRatio,Operation+1); 
	  free(MinRatio);
		     
	  if(isPrint_R_P == 'Y')
	    printf("%s - %.12f - %d\n",PathName,lBound_Percent,file_id);
	  return lBound_Percent;
	}

	int Find_Potential_NonPotential_File(
					     char nameSpace[], 
					     char misc[],
					     QLabel *textLabel,char seq_work_dir[],
					     int inputType,
					     int MIN_CHAR,
					     int MAX_CHAR,
					     int processId)
	{
	  char seq_FileName[400];
	  char PathName[400];
	  char rand_File[400];
	  char thresholdOutput[500];
	  char tempPath[400];
	  char tmp_str[400];
	  int totNonRandSeqCount;
	  int dec=0;
	  int file_id;
	  int fileLength;
	  int file_Count;
	  int _min_range;
	  int _max_range;
	  double swap_percent;
	  double mut_percent;
	  int CountBigGene;
	  int CountBigNGene;
	  
	  double MinRatio;  
	  FILE *fp_NameSpace,*fp,*fp_Misc;
	  FILE *fp1, *fp2, *fp3;
	  // information received from Random_Sequence
	  QString s1,s2,s3,s4;
	  int orf_n;
	  int RMIN_CHAR;
	  int RMAX_CHAR;
	  int Operation;
	  //////////////// 
	  int sequence_length;
	  int rand_sequence_length;
	  int tmp_count=0;
	  int processState;
	  QString stateDescription("");
	  ////////////////
	  bool ok;
	  RandomDialog *randForm = NULL;   
	  //mainPbc->pbcReset(); 
		   
		  
	  if((fp_NameSpace = fopen(nameSpace,"r")) != NULL)
	    {
	      fscanf(fp_NameSpace,"%d",&file_Count);
	      fscanf(fp_NameSpace,"%s",seq_FileName);
	      fscanf(fp_NameSpace,"%s",seq_FileName);
		 
	      ///////////////////////////////

	      if(file_Count >= 2) //R-Statistic file Name
		{
		  //  if (Random sequence not generated)
		  //   { Generate random Sesquence
		  //  }
		  //   else 
		  //      ask for regenaration or skip
		  //     if want to regenarate generate random sequence again
		  //}
		  /////////////////////////////
		  // mainPbc->hide();
		  if(choice==1)
		    sprintf(rand_File,"%s/RStat_Rand",seq_work_dir);
		  else
		    sprintf(rand_File,"%s/PVal_Rand",seq_work_dir);
		  sManager->getProcessState(processId,&processState,&stateDescription);
		  sprintf(tmp_str,"%s/nameSpace_R",seq_work_dir);
		   
		  
		  if(processState<=20){ // random not yet computed 
		    dec=3;
		  } else if(processState>20)
		    { 
		      int skipRecompute;
			// line below is to execute when program runs in interactive mode..( Random has already been generated)
			if(interactiveMode){
			  skipRecompute = QMessageBox::warning(appl, "Random Sequence compuation",
							       "Recompute random sequence or skip", "Recompute", "Skip",0,0,1);
	                }else {
	                 
	                  QString val=paramMg->getValueById("280");
	                  if(strcmp(val,"true")) { 
			    skipRecompute =1;}
			  else{
			    skipRecompute =0;
			  }
	                }

		      // random computed 
		      switch(skipRecompute)
			{
			case 0: // user clicks the recompute
			  dec = 1;
			  break;
			case 1: // user clicks to Skip 
			  dec =2;
			  break;
			}  
		    }
		 
		  if(dec == 1 || dec==3)
		    {
		      if(interactiveMode){ //start: if interactive mode
		      randForm = new RandomDialog(appl,"Random",true);
		      randForm->checkBox9->setHidden(interactiveMode);
		      randForm ->paramMg = paramMg; // reference of parameter manager opbject send to randomForm
		      strcpy(randForm->seq_work_dir,seq_work_dir);
		      if(inputType == 2) //thresholding is computing on specific min-max length
			{ 
			  if(MIN_CHAR>=PLR)
			    {
			      randForm->min_range_random =MIN_CHAR;
			      randForm->lineEdit2->setText(QString("%1").arg(MIN_CHAR,0,10));
			    }
			  else
			    {
			      randForm->min_range_random = PLR;
			      randForm->lineEdit2->setText(QString("%1").arg(PLR,0,10));
			    }
			  randForm->max_range_random=MAX_CHAR ;
			  randForm->lineEdit3->setText(QString("%1").arg(MAX_CHAR,0,10));
			} else 
			{
			  if(choice == 1) sprintf(tmp_str,"%s/orf_max_min_R",seq_work_dir);
			  if(choice == 2) sprintf(tmp_str,"%s/orf_max_min_P",seq_work_dir);
			  fp = fopen(tmp_str,"r"); 
			  if(fp)
			    {
			      fscanf(fp,"%d\t%d", &_min_range, &_max_range);
			      fclose(fp);
			    }
			  if(_min_range>=PLR)
			    {
			      randForm->min_range_random= _min_range;
			      randForm->lineEdit2->setText(QString("%1").arg(_min_range,0,10));
			    }else
			    {
			      randForm->min_range_random= PLR;
			      randForm->lineEdit2->setText(QString("%1").arg(PLR,0,10));
			    }
			  randForm->max_range_random= _max_range;
			  randForm->lineEdit3->setText(QString("%1").arg(_max_range,0,10));
			}
		        }//end: if interactive 
		    
		      while(1){
			bool randFormFlag = false;
	                if(interactiveMode) randFormFlag = randForm->exec();
		
			if(randFormFlag||!interactiveMode){
			  
	                  if(randFormFlag ) s1 = randForm->lineEdit1->text(); else s1 =  paramMg->getValueById("300");           
		          orf_n = s1.toInt(&ok,10);

		          if(randFormFlag )s2 = randForm->lineEdit2->text(); else s2 =  paramMg->getValueById("290");  
		          RMIN_CHAR = s2.toInt(&ok,10);

		          if(randFormFlag )s3 = randForm->lineEdit3->text();else s3 =  paramMg->getValueById("295");  
		          RMAX_CHAR = s3.toInt(&ok,10);

		          if(randFormFlag )s4 = randForm->lineEdit4->text(); else s4 =  paramMg->getValueById("315");  
			  Operation = s4.toInt(&ok,10);

		          if(randFormFlag )s1 = randForm->swapPercent->text();else s1 =  paramMg->getValueById("305");  
			  swap_percent = (double)s1.toDouble(&ok);
		   
			  if(randFormFlag) s1 = randForm->mutPercent->text();else s1 =  paramMg->getValueById("310");  
			  mut_percent = (double)s1.toDouble(&ok);
			  if(randFormFlag) {
			       CountBigGene = randForm->CountBigGene;
			   }else
			   {
			       s1 =  paramMg->getValueById("316"); 
			       CountBigGene = (int)s1.toDouble(&ok);
			    }
			    if(randFormFlag) {
			       CountBigNGene = randForm->CountBigNGene;
			   }else
			   {
			       s1 =  paramMg->getValueById("317"); 
			       CountBigNGene = (int)s1.toDouble(&ok);
			    }

			  if(orf_n<=0 && Operation<=0){
			    DiscardRandomSet=1;
			    QMessageBox::information(appl,"Gene Prediction","Random set is not computing!");
			  }else {
			    DiscardRandomSet=0;
			  }  
			  // printf("\n random computation parameter has been inserted %d\n",DiscardRandomSet);
		    
			  if(DiscardRandomSet==0){
			    // printf("\n ***orf_num = %d **MIN_CHAR = %d *** MAX_CHAR = %d, Operation = %d\n", orf_n, RMIN_CHAR, RMAX_CHAR, Operation);
			    sManager->setProcessState(processId,"10");
		            Create_Random_Sequence(orf_n, RMIN_CHAR, RMAX_CHAR, Operation, swap_percent, mut_percent,CountBigGene,CountBigNGene);
			    //Random generation restarted
			    // printf("\n ---------------------------------------------------\n ");
			    sprintf(tmp_str,"%s/RStat_Rand_process_state",seq_work_dir);
			    fp=fopen(tmp_str,"w");
			    fprintf(fp,"%d",2); // 2-> Random files regenerated
			    fclose(fp);  
			  }
			  break;
			}else {
			  if(dec==1){
			    //QMessageBox::information(appl,"Information","Skipping the random sequence generation process\n (Previous data will be in use)"); 
		                
			    mainPbc->setAbnormalTermination();
			    return false;
			    break;
			  } else if(dec==3){
			    QMessageBox::information(appl,"Random Sequence Generation", "You must generate random sequence for first time");
			    mainPbc->setAbnormalTermination();
			    return false;
			  }
			}
		      } // end while
		 
	              
		      if(DiscardRandomSet==0){// if random generation has been descarted
		        
		        fp = NULL;

		        sprintf(tmp_str,"%s/Addaptive_Flag.txt",seq_work_dir);
		 	// printf("\n ......... %s---", seq_work_dir);
			fp = fopen(tmp_str,"r");
			fscanf(fp, "%d\n%d", &Addaptive_Flag, &Occur);
			fclose(fp);
			    printf("\n Addaptive_Flag = %d, Occur = %d", Addaptive_Flag, Occur);
			sManager->getProcessState(processId,&processState,&stateDescription);  
			if(choice == 1){
		                        
			  // check if RStat for random has been computed 
		      
			  if(processState==20)
			    QMessageBox::warning(appl,"Random Generation", "R-Statistic for Random has not been computed, going to complete the process");
		                           
		                     
		                 
		                
			  sManager->setProcessState(processId,"20");
			  compute_R_Statistic_ForRandomSequences(misc);
		          
			} else
			  {

			    //  check if RStat for random has been computed 

			    if(processState==20)
			      QMessageBox::warning(appl,"Random Generation", "P-Val for Random has not been computed, going to complete the process");
		                    
		               
			    sManager->setProcessState(processId,"20");
			    compute_P_Value_ForRandomSequences(misc);
			  }            

		      };  
		    }   
		  if(mainPbc->pbcWasCanceled()){
		    printf("\n computation on randomsequence has been cancelled\n");
		    return true;
		  }
		  //////////////////////   //  
		  sManager->setProcessState(processId,"50");
		  mainPbc->pbcReset();
		  mainPbc->addAChildProcess(100,"Thresholding on progress");
		  Potential_Gene_Count = Potential_NonGene_Count = NonPotential_Sequence_Count = 0;//
		    
		  load_Path(seq_FileName);
		  //---------------------------------------------------------------------------------
		  sprintf(poten_Gene_FileName,"%s/%s/potential_Gene",seq_work_dir,curr_Dir);
		  sprintf(poten_NGene_FileName,"%s/%s/potential_NonGene",seq_work_dir,curr_Dir);
		  sprintf(nPoten_Seq_FileName,"%s/%s/non_Potential_Sequence",seq_work_dir,curr_Dir);
		             
		  
		  fp = fopen(poten_Gene_FileName,"w"); 
		  fclose(fp);
		  fp = NULL;
		  fp = fopen(poten_NGene_FileName,"w"); 
		  fclose(fp);
		  fp = NULL;
		  fp = fopen(nPoten_Seq_FileName,"w"); 
		  fclose(fp);
		  fp = NULL;
		  
		  if((fp_Misc = fopen(misc,"r")) != NULL)
		    {
		      fscanf(fp_Misc,"%d",&file_Count); // Number of records in file
		      fscanf(fp_Misc,"%d",&Path_Count); // Number of file's data processed for R-Stat Calculation
		      fscanf(fp_Misc,"%d",&totNonRandSeqCount); // Total sequence Count excluding random sequences
		      if(DiscardRandomSet == 0)      
			fscanf(fp_Misc,"%d",&Total_File); // Total sequence Count including random sequences
		      fclose(fp_Misc);
		    }
		  strcpy(tempPath,"");

		  //////////////////   for progress bar ////////////////////////////

		  sequence_length=count_record_lenght_of_file(seq_FileName);
		  rand_sequence_length = 0;
		  if(DiscardRandomSet== 0){ 
		    rand_sequence_length=count_record_lenght_of_file(rand_File);
		  } 
		  int tmp_r = (int) ( sequence_length / ( sequence_length+rand_sequence_length ) ) * 100;
		  ///////////////////////////////////////////////////////////////////////////
		  fp = fopen(seq_FileName,"r");
		  mainPbc->addAChildProcess(tmp_r,"Building Potential and non Potential files(not random)");
		      
		  while(!feof(fp))
		    {
		      mainPbc->setProgressA(tmp_count++,sequence_length);
		      fscanf(fp,"%s %lf %d %d",PathName,&MinRatio,&file_id,&fileLength);
		      if(strcmp(tempPath,PathName) == 0)
			break;
		      else
			strcpy(tempPath, PathName);     
		        
		      if((inputType == 2 && (fileLength >= MIN_CHAR && fileLength <= MAX_CHAR)) || inputType == 1)
			{
			  if((file_id == 0 || file_id == 2) && MinRatio < MinRatio_Gene )//changed by Subhajit
			    {    
			      fp1=fopen(poten_Gene_FileName,"a"); 
			      fprintf(fp1,"%s \t %.12lf \t %d \t %d\n",PathName,MinRatio,file_id,fileLength);
			      fclose(fp1);
			      ++Potential_Gene_Count; 
			    }
			  else if(MinRatio > MinRatio_NonGene) 
			    {  
			      fp2=fopen(poten_NGene_FileName,"a");   
			      fprintf(fp2,"%s \t %.12lf \t %d \t %d\n",PathName,MinRatio,file_id,fileLength);
			      fclose(fp2);
			      ++Potential_NonGene_Count;
			    }
			  else if(file_id == 0 || file_id == 2) //changed by Subhajit
			    {
			      fp3=fopen(nPoten_Seq_FileName,"a");  
			      fprintf(fp3,"%s \t %.12lf \t %d \t %d\n",PathName,MinRatio,file_id,fileLength);
			      fclose(fp3);
			      ++NonPotential_Sequence_Count; 
			    }
			}
		    }// while end
		  fclose(fp);
		  mainPbc->deleteLastChildProcess();
		  fp = NULL;
		  strcpy(tempPath,"");
		  if(DiscardRandomSet== 0){ // Random file has been considered
		    tmp_r = (int) (rand_sequence_length/(sequence_length+rand_sequence_length)) * 100;
		    mainPbc->addAChildProcess(tmp_r,"Building Potential and non Potential files(random)");
		    sequence_length=count_record_lenght_of_file(rand_File);
		    fp = fopen(rand_File,"r");
		    while(!feof(fp))
		      {
			tmp_count++;
			mainPbc->setProgressA(tmp_count++,sequence_length);
			fscanf(fp,"%s %lf %d %d",PathName,&MinRatio,&file_id,&fileLength);
			if(strcmp(tempPath,PathName) == 0)
			  break;
			else
			  strcpy(tempPath,PathName);
			     if((inputType == 2 && (fileLength >= MIN_CHAR && fileLength <= MAX_CHAR)) || inputType == 1)
				          {
						if(MinRatio < MinRatio_Gene )
						{    
					          fp1=fopen(poten_Gene_FileName,"a"); 
					          fprintf(fp1,"%s\t%.12lf\t%d\t%d\n",PathName,MinRatio,file_id,fileLength);
					          fclose(fp1);
					          ++Potential_Gene_Count; 
						}
						else if(MinRatio > MinRatio_NonGene) 
						{  
						  fp2=fopen(poten_NGene_FileName,"a");   
						  fprintf(fp2,"%s\t%.12lf\t%d\t%d\n",PathName,MinRatio,file_id,fileLength);
					          fclose(fp2);
					          ++Potential_NonGene_Count;
						}
						else
						{
					          fp3=fopen(nPoten_Seq_FileName,"a");  
					          fprintf(fp3,"%s\t%.12lf\t%d\t%d\n",PathName,MinRatio,file_id,fileLength);
					          fclose(fp3);
					          ++NonPotential_Sequence_Count; 
						}
					  }
		      }
		    fclose(fp);
		    mainPbc->deleteLastChildProcess();
		  }
		  //Updatation of misc file after rejecting random sequences which are likely to be considered as gene
		  if((fp_Misc = fopen(misc,"w")) != NULL)
		    {

		      file_Count = 3; // Number of records always be 3 here irrespective of random sequence consideration or not
		      fprintf(fp_Misc,"%d\n%d\n%d\n%d\n",file_Count,Path_Count,totNonRandSeqCount,(Potential_Gene_Count + Potential_NonGene_Count + NonPotential_Sequence_Count));
		      fclose(fp_Misc);
		    }
		  //END Uptdatation  

		  sprintf(thresholdOutput,"Potential Gene Count = %d<br/>Potential Non-Gene Count = %d<br>Non-Potential Sequence Count = %d <br/>", Potential_Gene_Count,    Potential_NonGene_Count, NonPotential_Sequence_Count);
		  textLabel->setText((const char *)thresholdOutput);
		  if(Potential_Gene_Count*Potential_NonGene_Count ==0 )
		    {
		      // printf("\nThere should be non zero number of Potential_Gene_Count and Potential_ NonGene_Count to run the program...exiting ---->\n");
		      sprintf(thresholdOutput,"Potential Gene Count = %d<br/>Potential Non-Gene Count = %d<br/> Non-Potential Sequence Count = %d <br/><br/><br/> <b><font color=\"#aa0000\"> All counts must be non-zero. <br/> Please change the parameters and recompute to proceed.<br/></font></b>", Potential_Gene_Count, Potential_NonGene_Count, NonPotential_Sequence_Count);
		      textLabel->setText((const char *)thresholdOutput);
		      mainPbc->pbcReset();
		      return true;
		    }
		}
	      else
		{
		  QMessageBox::warning(appl,"Warning","R-Statistic Computation must be run first \n before running Thresholding for R-Statistic.");
		  printf("\nR-Statistic Computation(Option 1) must be run first before running Thresholding For R-Statistic.\n");
		  mainPbc->pbcReset();
		   
		  return true;
		}
	      fclose(fp_NameSpace);
	    }
	  mainPbc->deleteAllChildProcess();
	  sManager->setProcessState(processId,"100");
	  return true;
	}





	//=============================================================================================================
	/**
	   Function gets the record length of a file 
	   inputs the file name
	   returns the length of the file
	*/
	int count_record_lenght_of_file(char *file_name){
	  char tmp_str[400];
	  int sequence_length;
	  FILE *fp;
	  //--------------------------
	  sprintf(tmp_str,"wc -l %s> %s/.tmp.txt",file_name,seq_work_dir);
	  system(tmp_str);
	  sprintf(tmp_str,"%s/.tmp.txt",seq_work_dir);
	  fp=fopen(tmp_str,"r");
	  fscanf(fp,"%d %s",&sequence_length,tmp_str);


	  sprintf(tmp_str,"rm %s/.tmp.txt",seq_work_dir);
	  system(tmp_str);


	  //-----------------------------------------
	  return sequence_length;
	}

	void Separate_File(double MinRatio,char *PathName,int file_id,int fileLength)
	// This function separate files into four gruop
	{
	  FILE *fp1,*fp2,*fp3;
		   
		      
	  if(MinRatio < MinRatio_Gene )
	    {   
	      if(file_id<4){
		fp1=fopen(poten_Gene_FileName,"a+"); 
		fprintf(fp1,"%s \t %.12lf \t %d \t %d\n",PathName,MinRatio,file_id,fileLength);
		 
		fclose(fp1);
		++Potential_Gene_Count; 
	      }
	    }
	  else if(MinRatio > MinRatio_NonGene) 
	    {  
	      fp2=fopen(poten_NGene_FileName,"a+");   
	      fprintf(fp2,"%s \t %.12lf \t %d \t %d\n",PathName,MinRatio,file_id,fileLength);

	      fclose(fp2);
	      ++Potential_NonGene_Count;
	    }
	  else  
	    {
	      fp3=fopen(nPoten_Seq_FileName,"a+");  
	      fprintf(fp3,"%s \t %.12lf \t %d \t %d\n",PathName,MinRatio,file_id,fileLength);

	      fclose(fp3);
	      ++NonPotential_Sequence_Count; 
	    } 
	}  

	void Compute_All_File_PatternCount(char nameSpace[], char misc[])
	{
	  FILE *fp_NameSpace,*fp,*fp_Misc_In,*fp_Misc_Out;
	  int i,file_id,file_Count,count_Val;  
	  int FileCount = 0,Length;
	  char PathName[400],FileName[400],query[400],tmp_string[400];
	  double MinRatio;
		 
	  F_Ratio *fratio_param;   

		  
	  if((fp_NameSpace = fopen(nameSpace,"r")) != NULL)
	    {
	      fscanf(fp_NameSpace,"%d",&file_Count);
	      fscanf(fp_NameSpace,"%s",poten_Gene_FileName);
		         
	      fp = fopen(poten_Gene_FileName,"r"); //Read Genome sequence path from ORF Path File
	      fscanf(fp,"%s",PathName);
	      fclose(fp);
	      fp = NULL;
	      genomeLength = ReadFile(PathName,&forward_Genome); //Read whole genome seqence in forward_Genome
	      reverse_complement_of_Sequence(); //Reverse complement of the whole genome seqence in reverse_Genome
		       
	      fscanf(fp_NameSpace,"%s",poten_Gene_FileName); 
	      /////////////////Some Essential allocation and Initialization//////////////
	      mainPbc->hide();
	      if(interactiveMode){
	      //========= this part is for interactive mode===========
	      fratio_param = new F_Ratio(appl,"F-ratio computation", true);
	      fratio_param ->paramMg = paramMg;
	      fratio_param->initialize();
	      bool fratio_closed=false;
	      // this form will set the option ot DOM
	      // program need to read value from DOM
	      while(!fratio_closed){
		if(fratio_param->exec()){
		      
		       
		  /* if(fratio_param->methodType == 1){
		     methodType = 1;
		     }else  if(fratio_param->methodType == 2){
		     methodType = 2;
		     }*/
		  fratio_closed=true;
		} else {
		            
		  if(fratio_param->close()) QMessageBox::warning(appl,"Warning","Please! Press 'OK' buuton to proceed");
		}
	      }
	      //=============================================

	      }
	      // set method type reading from dom
	      QString method;
	      method=paramMg->getValueById("320");// value for tri in dom
	      strcmp(method,"true")==0? methodType=1:methodType=2;

	     // QMessageBox::warning(0,"warning",QString("methodType = %1   ").arg(methodType,0,10)+method);
	      mainPbc->show(); 
	      wordSize_Gen = 3;
	      wordSize_Small = 0;
	      if(methodType == 2)
		{

		  wordSize_Small = 4;
		}
		  
	      printf("\n methodType = %d, wordSiz_Small= %d",methodType, wordSize_Small);
	      //........................................................................................................................
	      NumPat_Gen = (int)pow(4.0,(double)wordSize_Gen);
	      TotalPat_Gen = NumPat_Gen*wordSize_Gen;
	      PatArray_Gen = (char **)calloc(NumPat_Gen,sizeof(char*));
	      for(int j = 0; j <  NumPat_Gen; j++)
		PatArray_Gen[j] = (char *)calloc((wordSize_Gen + 1),sizeof(char));
	      generatePatterns(PatArray_Gen, wordSize_Gen, NumPat_Gen); //Generate Patterns for Sequences of Length >= PLR(300)
	      
	      //........................................................................................................................
	      TotalPat_Small = NumPat_Small = 0;
	      PatArray_Small = NULL;
	      if(methodType == 2)
		{
		  TotalPat_Small = NumPat_Small = (int)pow(4.0,(double)wordSize_Small);
		  PatArray_Small = (char **)calloc(NumPat_Small,sizeof(char*));
		  for(int j = 0; j <  NumPat_Small; j++)
		    PatArray_Small[j] = (char *)calloc((wordSize_Small + 1),sizeof(char));
		  generatePatterns(PatArray_Small,wordSize_Small,NumPat_Small); //Generate Patterns for Sequences of Length < PLR(300)
		}
		        
	      //........................................................................................................................    
	      ALL_Patern_Count = (double **)calloc(Total_File,sizeof(double *));
	      for(i = 0; i < Total_File; i++)
		ALL_Patern_Count[i] = (double *)calloc(TotalPat_Gen,sizeof(double));
		  
	      ALL_Patern_Count2 = NULL;
	      if(methodType == 2)
		{
		  ALL_Patern_Count2 = (double **)calloc(Total_File,sizeof(double *));
		  for(i = 0; i < Total_File; i++)
		    ALL_Patern_Count2[i] = (double *)calloc(TotalPat_Small,sizeof(double)); 
		}
		       
	      All_Pattern_Len = (int *)calloc(Total_File,sizeof(int)); // For storing Length of sequences
	      /////////////////////End of Some Essential allocation and Initialization///////////////////
		  
	      for(int loop = 0; loop < 3; loop++)
		{
		  switch(loop)
		    {
		    case 0:
		      fscanf(fp_NameSpace,"%s",poten_Gene_FileName);
		      Start_Index_Potential_Gene = FileCount;
		      fp = fopen(poten_Gene_FileName,"r");
		      break;
		    case 1:
		      fscanf(fp_NameSpace,"%s",poten_NGene_FileName);
		      Potential_Gene_Count = FileCount;
		      Start_Index_Potential_NonGene = FileCount;
		      fp = fopen(poten_NGene_FileName,"r"); 
		      break;
		    case 2:
		      fscanf(fp_NameSpace,"%s",nPoten_Seq_FileName);
		      Potential_NonGene_Count = FileCount - Potential_Gene_Count;    
		      Start_Index_NonPotential_Sequence = FileCount;
		      fp = fopen(nPoten_Seq_FileName,"r");
		    }
		  if(fp != NULL)
		    {
		      fscanf(fp,"%s %lf %d %d",PathName,&MinRatio,&file_id,&fileLength);
		      strcpy(FileName,PathName);       
		      while(!feof(fp))
			{
			  //check cancelled
			  if(mainPbc->pbcWasCanceled()){
			    return;
			  };
			  mainPbc->updateProgress();
			  Pat_Search(PathName,FileCount,file_id,Length);
			  if(Length <= 0)
			    {
			      cout << "\nWrong length value: " << Length << " exiting..." << endl;
			      exit(0);
			    }
			  All_Pattern_Len[FileCount] = Length; // For storing Length of sequences
			  ++FileCount;        
			  fscanf(fp,"%s %lf %d %d",PathName,&MinRatio,&file_id,&fileLength);
			  if(!strcmp(FileName,PathName))  
			    break;
			  strcpy(FileName,PathName);
			}
		      fclose(fp);
		      fp = NULL;
		    }
		}
		   
	      Total_File = FileCount;
	      NonPotential_Sequence_Count = FileCount - Potential_Gene_Count - Potential_NonGene_Count;
	      ///////////////Delete some allocated Memory////////////////////////////
	      for(int i = 0; i < NumPat_Gen; i++)
		free(PatArray_Gen[i]);
	      free(PatArray_Gen);
	      PatArray_Gen = NULL;
		         
	      if(methodType == 2)
		{
		  for(int i = 0; i < NumPat_Small; i++)
		    free(PatArray_Small[i]);
		  free(PatArray_Small);
		  PatArray_Small = NULL;
		}
		       
	      ///////////////////////////////////////////////////////////////////////
	      sprintf(tmp_string,"%s/misc_temp2",seq_work_dir);
	      if((fp_Misc_In = fopen(misc,"r")) != NULL)
		{
		        
		  if((fp_Misc_Out = fopen(tmp_string,"w")) != NULL)
		    {
		      fprintf(fp_Misc_Out,"6\n");
		      fscanf(fp_Misc_In,"%d",&file_Count);
		      fscanf(fp_Misc_In,"%d",&count_Val);
		      fprintf(fp_Misc_Out,"%d\n",count_Val);
		      fscanf(fp_Misc_In,"%d",&count_Val);
		      fprintf(fp_Misc_Out,"%d\n",count_Val);
		      fscanf(fp_Misc_In,"%d",&count_Val);
		      fprintf(fp_Misc_Out,"%d\n",Total_File);
		      fclose(fp_Misc_In);
		      fprintf(fp_Misc_Out,"%d\n%d\n%d\n",Potential_Gene_Count,Potential_NonGene_Count,NonPotential_Sequence_Count);
		      fclose(fp_Misc_Out);
		    } 
		}
	
	      sprintf(query,"rm %s",misc);
	      system(query);
	      rename(tmp_string,misc);
	      fclose(fp_NameSpace);
	      free(forward_Genome);
	      free(reverse_Genome);
	    }
	   
	}




	void Pat_Search(char *PathName,int FileCount,int file_id,int &Length)
	{
	  char sign;
	  int i,Total_Pattern_Count;
		                     
	  for(i = 0; i < TotalPat_Gen; i++)
	    ALL_Patern_Count[FileCount][i] = 0.0;
		     
	  if(methodType == 2)
	    {
	      for(i = 0; i < TotalPat_Small; i++)
		ALL_Patern_Count2[FileCount][i] = 0.0;
	    }
		   
	  sign = (file_id < 2 ? '+' : '-');
	  Length = readSequenceFromGenome(PathName,file_id,sign);
		   
	  if(methodType == 1)
	    {
	      DisJoinSearch(Length,FileCount);
	      Total_Pattern_Count = 0;
	      for(i = 0; i < TotalPat_Gen; i++)
		Total_Pattern_Count += (int)ALL_Patern_Count[FileCount][i];
	      for(i = 0; i < TotalPat_Gen; i++)
		ALL_Patern_Count[FileCount][i] = (ALL_Patern_Count[FileCount][i]*1000.0)/(double)Total_Pattern_Count;
	    }
	  else if(methodType == 2)
	    {
	      if(Length >= PLR)
		{
		  DisJoinSearch(Length,FileCount);
		  Total_Pattern_Count = 0;
		  for(i = 0; i < TotalPat_Gen; i++)
		    Total_Pattern_Count += (int)ALL_Patern_Count[FileCount][i];
		  for(i = 0; i < TotalPat_Gen; i++)
		    ALL_Patern_Count[FileCount][i] = (ALL_Patern_Count[FileCount][i]*1000.0)/(double)Total_Pattern_Count;
		}
	      OverLapping_Search(Length,FileCount);
	      Total_Pattern_Count = 0;
	      for(i = 0; i < TotalPat_Small; i++)
		Total_Pattern_Count += (int)ALL_Patern_Count2[FileCount][i];
	      for(i = 0; i < TotalPat_Small; i++)
		ALL_Patern_Count2[FileCount][i] = (ALL_Patern_Count2[FileCount][i]*1000.0)/(double)Total_Pattern_Count;
	    }
	  free(Seq_Buffer);
	  Seq_Buffer = NULL;
	}

	void OverLapping_Search(int Length,int FileCount) 
	{
	  int k,Len;
	  Len = Length - (wordSize_Small - 1);
	  for(int i = 0; i < TotalPat_Small; i++)
	    {
	      for(int j = 0; j < Len; j++)
		{
		  for(k = 0; k < wordSize_Small; k++)
		    {
		      if(PatArray_Small[i][k] != *(Seq_Buffer+j+k))
			break;
		    }
		  ALL_Patern_Count2[FileCount][i] += (k == wordSize_Small ? 1.0 : 0.0);
		}
	    }
	}

	void DisJoinSearch(int Length,int FileCount)
	{
	  int i,j,Loop,index;
	  char seqArr[4];
		    
	  for(Loop = 0;Loop < wordSize_Gen;Loop++)
	    {
	      for(i = Loop;i <= (Length - wordSize_Gen);)
		{
		  for(j = 0; j < wordSize_Gen; j++)
		    seqArr[j] = *(Seq_Buffer+i+j);
		  seqArr[3] = '\0';
		  index = Compare_Pat_Seq(seqArr);
		  if(index != -1)
		    ALL_Patern_Count[FileCount][(Loop*NumPat_Gen) + index] += 1.0;
		  i += wordSize_Gen;
		}
	    }
	}

	void generatePatterns(char **patMatrix, int wordSize, int No_Pattern)
	{
	  char Pattern[] = {'A','T','C','G'};
	  int i,j,k,l;
	  int *repitation;
	  int Size;
	  repitation = (int *)calloc(wordSize - 1,sizeof(int));
	  for(i = 0;i < wordSize - 1; i++)
	    repitation[i] = (int)pow((double)4,(double)(i + 1)); 
	  Size = wordSize;
	  --wordSize; 
	  for(i = 0; i < No_Pattern;)
	    {
	      for(j = 0; j < 4; j++)
		{
		  patMatrix[i][wordSize] = Pattern[j];   
		  ++i;
		}
	    }      
	  --wordSize;
	  l = 0;
	  while(wordSize >= 0)
	    {     
	      for(i = 0; i < No_Pattern;)
		{
		  k = 0;
		  while(k < 4)
		    {
		      j = 0; 
		      while(j < repitation[l])
			{
			  patMatrix[i][wordSize] = Pattern[k];   
			  ++i;
			  ++j;
			} 
		      ++k;
		    }
		}
	      ++l;
	      --wordSize;
	    }
	  free(repitation);
	  for(int m = 0; m < No_Pattern; m++)
	    patMatrix[m][Size] = '\0';
	}



	int Compare_Pat_Seq(char *seqArr) //This function return the position of matching patttern 
	{
	  int i,j;
		     
	  for(i = 0; i < NumPat_Gen; i++)
	    {
	      for(j = 0; j < wordSize_Gen; j++)
		{
		  if( PatArray_Gen[i][j] == seqArr[j] )      
		    continue;
		  else
		    break;
		}
	      if(j == wordSize_Gen)
		return i;
	    }   
	  return -1;
	}




	double Distance(int Test_Pattern_index,int Train_Pattern_index)
	{  
	  int i;
	  double distance = 0.0;  
		     
	  if(All_Pattern_Len[Test_Pattern_index] < PLR)
	    {
	      if(methodType == 1)
		{
		  for(i = 0; i < TotalPat_Gen; i++) //tri-nucleotide
		    {
		      if(ALL_Patern_Count[Test_Pattern_index][i] > 0.0 && ALL_Patern_Count[Train_Pattern_index][i] > 0.0)
			distance += fabs(ALL_Patern_Count[Test_Pattern_index][i] - ALL_Patern_Count[Train_Pattern_index][i]);
		    }
		}
	      else if(methodType == 2)
		{
		  for(i = 0; i < TotalPat_Small; i++) //tetra-nucleotide
		    {
		      if(ALL_Patern_Count2[Test_Pattern_index][i] > 0.0 && ALL_Patern_Count2[Train_Pattern_index][i] > 0.0)
			distance += fabs(ALL_Patern_Count2[Test_Pattern_index][i] - ALL_Patern_Count2[Train_Pattern_index][i]);
		    }
		}
	    }
	  else
	    {
	      for(i = 0; i < TotalPat_Gen; i++) //tri-nucleotide
		distance += fabs(ALL_Patern_Count[Test_Pattern_index][i] - ALL_Patern_Count[Train_Pattern_index][i]);
	    }
	  return distance;
	}  

	int analysis_Nearest_Neighbourhood_Computation(
						       char nameSpace[],
						       char misc[],
						       int iteration,
						       int Train_Gene_Count,
						       int Train_NonGene_Count)
	{
		char PathName[400];
		char seqFile[400];
		int FileCount = 0;
		int numRecords;
		
		int index;
		int file_id;
		int Omit_Gene = 0;
		int Omit_NonGene = 0;
		int Test_Pattern_index = 0;
		int Train_Pattern_index;
		double *Gene_Distance;
		double *NonGene_Distance;
		double *Individual_Gene_Distance;
		double *Individual_NonGene_Distance;
		double MinRatio;
		FILE *fp1,*fp_NameSpace_In,*fp_Misc;
		unsigned int seed;
		int total_file = 0;
		int skipped_file =0;
		
		
		////////////////////////////Memory Allocation///////////////////////////////////////////////
		Gene_Distance = ( double * ) malloc ( iteration * sizeof( double ) );
		NonGene_Distance = ( double * ) malloc ( iteration * sizeof( double ) );
		
		Individual_Gene_Distance = ( double * ) malloc( Train_Gene_Count*sizeof( double ) );
		Individual_NonGene_Distance = ( double * ) malloc( Train_NonGene_Count*sizeof( double ) );
		////////////////////////////////////////////////////////////////////////////////////////////
		if( ( fp_NameSpace_In = fopen( nameSpace,"r" ) ) != NULL )
		{
	  		fscanf( fp_NameSpace_In, "%d", &FileCount );
	  		fscanf( fp_NameSpace_In, "%s", seqFile);
	  		fscanf( fp_NameSpace_In, "%s", seqFile);
	  		if( ( fp_Misc = fopen( misc, "r" ) ) != NULL )
			{
			
				fscanf( fp_Misc, "%d", &numRecords );
				fscanf( fp_Misc, "%d", &numRecords );
				fscanf( fp_Misc, "%d", &numRecords);
				fscanf( fp_Misc, "%d", &numRecords); 
				// reading for progressbar
				fscanf( fp_Misc, "%d", &numRecords );
				total_file +=numRecords;
				fscanf( fp_Misc, "%d", &numRecords);
				total_file +=numRecords;
				fscanf( fp_Misc, "%d", &numRecords);
				total_file +=numRecords; 
				fclose( fp_Misc );
	
			}
			// Again open and set pointer 
			if( ( fp_Misc = fopen( misc, "r" ) ) != NULL )
			{
			
				fscanf( fp_Misc, "%d", &numRecords );
				fscanf( fp_Misc, "%d", &numRecords );
				fscanf( fp_Misc, "%d", &numRecords);
				fscanf( fp_Misc, "%d", &numRecords); 
			
			}
			
			//************* computation for potential Gene, potential Non-Gene, Non-Potential gene ***************
			//sprintf( tmpString, " Total File : %d", total_file );
			//QMessageBox::warning(appl,"Warning", tmpString );	
			for( int loop = 0; loop < 3; ++loop )
			{
				switch( loop )
				{
					case 0:
						mainPbc -> updateCurrentProcessLabe("Computation for Potential Gene running ...");
			      			//mainPbc->addAChildProcess( 33, "Computation for Potential Gene" );
			      			break;
			      		case 1:
			      			mainPbc -> updateCurrentProcessLabe("Computation for Potential Gene done. \n Computation for Potential Non-Gene running ... ");
			      			//mainPbc->addAChildProcess( 33, "Computation for Potential Non-Gene" );
			      			break;
			    		case 2:
			    			mainPbc -> updateCurrentProcessLabe("Computation for Potential Gene done. \n Computation for Potential Non-Gene done. \n Computation for Non Potential Gene running ...");
			    			//mainPbc->addAChildProcess( 33, "Computation for Non Potential Gene" );
			    			break;
			    	}
			    	fscanf(fp_NameSpace_In,"%s", seqFile);
			    	fscanf(fp_Misc,"%d",&numRecords);
			    	mainPbc->updateProgress();
	
				if((fp1 = fopen(seqFile, "r+")) != NULL)
			    	{
			    		FileCount = 0;
			    		while(FileCount < numRecords)
			    		{
			    			fscanf(fp1, "%s %lf %d %d", PathName, &MinRatio, &file_id, &fileLength);
			    			if( loop == 0 || loop == 2 || ( loop == 1 && ( file_id == 0 || file_id == 2 ) ) ) // changed by Subhajit & Debu da
			    			{
			    				seed = (unsigned int) time( ( time_t * ) NULL );
			    				srand(seed);
			    				mainPbc->updateProgress();
			    				switch(loop)
							{
								case 0:
			       
									Test_Pattern_index = Start_Index_Potential_Gene + FileCount;
									Omit_Gene = FileCount;
									Omit_NonGene = -1;
									break;
								case 1:
				        
							  		Test_Pattern_index = Start_Index_Potential_NonGene + FileCount;
							  		Omit_Gene = -1;
							  		Omit_NonGene = FileCount;
							  		break;
								case 2:
					        
							  		Test_Pattern_index = Start_Index_NonPotential_Sequence + FileCount;
							  		Omit_Gene = -1;
							  		Omit_NonGene = -1;
							  		break;
							}   
	
			   
						      	for(int i = 0; i < iteration; i++)
							{
								for(int k = 0; k < Train_Gene_Count; k++)
								{
					     	
									while(1)
									{
			
								  		index = rand() % (Potential_Gene_Count - 1);
				
										if( index == Omit_Gene)	continue;
								  		else
								    		break;
									}
									Train_Pattern_index = Start_Index_Potential_Gene + index;
							      		Individual_Gene_Distance[k] = Distance(Test_Pattern_index,Train_Pattern_index);
							      	}
							      	Gene_Distance[i] = Sum_Gene_Distance(Individual_Gene_Distance, Train_Gene_Count, Trim1, Trim2);
							      	for(int k = 0; k < Train_NonGene_Count; k++)
							      	{
							      		while(1)
							      		{
							      			index = rand() % ( Potential_NonGene_Count - 1 );
							      			if(index == Omit_NonGene)   continue;
							      			else  break;
							      		}
							      		Train_Pattern_index = Start_Index_Potential_NonGene + index;
							      		Individual_NonGene_Distance[ k ] = Distance( Test_Pattern_index, Train_Pattern_index );
							      	}
							      	NonGene_Distance[ i ] = Sum_Gene_Distance(Individual_NonGene_Distance,Train_NonGene_Count,Trim3,Trim4);
							}
							/*for(i = 0; i < iteration; i++)*/
						      	Decission_Gene_NonGene(PathName,MinRatio,fileLength,file_id,Gene_Distance,NonGene_Distance,iteration);
						}   
						//printf( " \nFileCount : %d, TotalFile : %d ", FileCount, total_file );
						skipped_file++;
						mainPbc->setProgressA( skipped_file, total_file );  
						mainPbc->updateProgress();      
						++FileCount;
						//printf("\n File Count : %d,  numRecords=%d",FileCount, numRecords);
						if( mainPbc->pbcWasCanceled() ) 
						{
							free(Gene_Distance);
							Gene_Distance = NULL;
							free(NonGene_Distance);
							NonGene_Distance = NULL;
							free(Individual_Gene_Distance);
							Individual_Gene_Distance = NULL;
							free(Individual_NonGene_Distance);
							Individual_NonGene_Distance = NULL;
							return 0;
						}
						mainPbc->updateProgress();
					}/*while(!feof(fp1))*/
					fclose(fp1);
					fp1 = NULL;      
				} /*if((fp1 = fopen(seqFile,"r+")) != NULL)*/
			}/*for(int loop = 0; loop < 3; ++loop)*/
			
			//}/*for(int loop = 0; loop < 3; ++loop)*/
			//******** End of : computation for potential Gene, Potential non Gene, Non potential gene
			fclose(fp_NameSpace_In);
			fclose(fp_Misc);
			fp_NameSpace_In = fp_Misc = NULL;
		}	
		//mainPbc->deleteLastChildProcess();
		free(Gene_Distance);
		Gene_Distance = NULL;
		free(NonGene_Distance);
		NonGene_Distance = NULL;
		free(Individual_Gene_Distance);
		Individual_Gene_Distance = NULL;
		free(Individual_NonGene_Distance);
		Individual_NonGene_Distance = NULL;
		return 0;
	}

	void Decission_Gene_NonGene(char * Path,double MinRatio,int fileLength,int file_id,double *Gene_Distance,double *NonGene_Distance,int iteration)
	{   
	  int i,Gene_Count = 0,NonGene_Count = 0,Program_dtect;
	  double detection_Percentage;
	  char Temp_Path[400];    
		     
	  for(i = 0; i < iteration; i++)
	    if(Gene_Distance[i] < NonGene_Distance[i])
	      ++Gene_Count;
	    else
	      ++NonGene_Count;
		    
	  if(Gene_Count > NonGene_Count)
	    {
	      Program_dtect = 1;
	      detection_Percentage = ((double)Gene_Count*100.00)/(double)iteration;
	      ++Program_Detect_Gene[file_id];
	      Gene_Frequency_Compute(detection_Percentage,file_id);
	    }
	  else if(Gene_Count < NonGene_Count)
	    { 
	      Program_dtect = 0; 
	      detection_Percentage = ((double)NonGene_Count*100.00)/(double)iteration;
	      ++Program_Detect_NonGene[file_id];
	      NonGene_Frequency_Compute(detection_Percentage,file_id); 
	    }
	  else
	    {
	      Program_dtect = 2; 
	      detection_Percentage = ((double)NonGene_Count*100.00)/(double)iteration;
	      Undecided[file_id] += 1;
	    }
	  //// check canceled
	  if(mainPbc->pbcWasCanceled()) {
	    return ;
	  };
	  mainPbc->updateProgress();
		       
		       
	  FILE *fp = fopen(Result[file_id],"a+");
	  if(fp)
	    {
	      Extract_Folder_Name(Path,Temp_Path);
	      if( choice == 2)
		fprintf(fp,"%s\t%d\t%.3f%\t%.6f\t%d\n",Temp_Path,Program_dtect,detection_Percentage,MinRatio,fileLength); //MinRatio~PValue R_Statistic_for_P(Path,file_id)
	      else
		fprintf(fp,"%s\t%d\t%.3f%\t%.6f\t%d\n",Temp_Path,Program_dtect,detection_Percentage,MinRatio,fileLength);
	      fclose(fp); 
	      fp = NULL;
	    }
	}

	void Gene_Frequency_Compute(
				    double detection_Percentage,
				    int i)
	{  
	  int j,frequency_length;
		         
	  frequency_length = (100-Start_frequency)/interval;
	  if(detection_Percentage == 100.000000)
	    Gene_detection_frequency[i][frequency_length] +=1;
	  else
	    {
	      for(j=0; j<frequency_length; j++)
		if(detection_Percentage<frequency_value[j])
		  {
		    Gene_detection_frequency[i][j] += 1;
		    if(mainPbc->pbcWasCanceled()) {
		      return ;
		    };
		    mainPbc->updateProgress();
		    break;
		  }
	    }
	} 

	void NonGene_Frequency_Compute(
				       double detection_Percentage, 
				       int i)
	{      
	  int j,frequency_length;
		         
	  frequency_length = (100-Start_frequency)/interval;
	  if(detection_Percentage == 100.000000)
	    NonGene_detection_frequency[i][frequency_length] += 1;               
	  else
	    { 
	      for(j=0; j<frequency_length; j++)
		if(detection_Percentage<frequency_value[j])
		  {
		    NonGene_detection_frequency[i][j] += 1;
		    if(mainPbc->pbcWasCanceled()) {
		      return ;
		    };
		    mainPbc->updateProgress();
		    break;
		  }
	    }
		 
	}    

	double Sum_Gene_Distance(double *Gene_Distance,int Train_File_Count,int Trim1,int Trim2)
	{
	  int i;
	  double Sum_Gene_Distance = 0.0;
		     
	  Trim1 = (int)(double(Trim1*Train_File_Count)/100.0);
	  Trim2 = (int)(double(Trim2*Train_File_Count)/100.0);
	  SORT(Gene_Distance,Train_File_Count);
	  for(i = Trim1;i< (Train_File_Count - Trim2); i++) 
	    Sum_Gene_Distance += Gene_Distance[i];  
		      
	  Sum_Gene_Distance = Sum_Gene_Distance/(double)(Train_File_Count - (Trim1 + Trim2));
	  return Sum_Gene_Distance;
	}

	void SORT(
		  double *Gene_Distance,
		  int Train_File_Count)
	{
	  int i,j,Flag;
	  double temp;
		   
	  for(i=0;i<Train_File_Count-1;i++)
	    {
	      Flag=0;
	      for(j=0;j<(Train_File_Count-1-i);j++)
		if(Gene_Distance[j] > Gene_Distance[j+1])
		  {
		    temp=Gene_Distance[j]; Gene_Distance[j]=Gene_Distance[j+1]; Gene_Distance[j+1]=temp;
		    Flag=1;
		  }   
	      if(Flag==0)
		break;
	    }

	}

	//-----------------------------------Written by Debabrata Mondal------------------------------------------------------------------------------------
	int readSequenceFromGenome(char *PathName,int file_id,char sign)
	{
	  int Pos1,Pos2,Length,i;
			
	  if(file_id < 4)
	    Extract_Index(PathName,Pos1,Pos2,sign); //Extract index values from sequence name
	  else
	    Pos1 = Pos2 = 0; // For randomy generated sequences
	  if(file_id == 2 || file_id == 3)
	    {
	      Pos1 = genomeLength - (Pos1 - 1);
	      Pos2 = genomeLength - (Pos2 - 1);
	    }
	  --Pos1;
	  --Pos2;
	  Length = (abs(Pos2 - Pos1) + 1);
	  if(file_id < 2)
	    {
	      i = 0;
	      Seq_Buffer = (char *)calloc((Length + 1),sizeof(char)); //fileLength global variable contains sequence's(PathName) length///////////////////C
	      for(int Index = Pos1; Index <= Pos2; Index++)	*(Seq_Buffer + i++) = forward_Genome[Index];
	      *(Seq_Buffer + i) = '\0';
		     
	    }
	  else if(file_id == 2 || file_id == 3)
	    {
	      i = 0;
	      Seq_Buffer = (char *)calloc((Length + 1),sizeof(char));/////////////////////////C
	      for(int Index = Pos1; Index <= Pos2; Index++)
		*(Seq_Buffer + i++) = reverse_Genome[Index];
	      *(Seq_Buffer + i) = '\0';
		     
	    }
	  else{
	    Length = Read_RandFile(PathName,&Seq_Buffer);
	    }
	  return Length;
	}

	void Extract_Index(char *PathName,int &pos1,int &pos2,char sign)
	{
	  char *token1,*token2;
			
	  searchChar('_',1,&token1,PathName);
	  searchChar(sign,2,&token2,token1);
	  pos1 = atoi((const char*)token2);
	  free(token2);
	  searchChar(sign,1,&token2,token1);
	  pos2 = atoi((const char*)token2);
	  free(token2);
	  free(token1);
	}

	void searchChar(char delim,int Occurance, char **token, char *string)
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
	//----------------------------------End(Debabrata Mondal)--------
	void  Extract_Folder_Name(char *PathName,char *Temp_Path)
	{
	  int len,i,j;
		   
	  len=strlen(PathName);
	  for(i=len-1; i>=0; --i)
	    if( *(PathName+i) == '/' )
	      break; 
	  ++i; 
	  j=0;
	  for(;i<len;i++)
	    {
	      *(Temp_Path+j) = *(PathName+i);
	      ++j;
	    }
	  *(Temp_Path+j) = '\0'; 
	}

	void Validation_Trim(void)
	{

	  while(1)
	    {
	      printf("\nEnter lower trim percentage for Gene average :- "); 
	      scanf("%d",&Trim1);
	      if(Trim1>25)
		{
		  printf("\nTrim percentage must be less then equal to 25\n");
		  continue; 
		}
	      break;  
	    }
	  while(1)
	    {
	      printf("\nEnter upper trim percentage for Gene average :- "); 
	      scanf("%d",&Trim2);  
	      if(Trim2>25)
		{
		  printf("\nTrim percentage must be less then equal to 25\n");
		  continue; 
		}
	      break;  
	    }
	  while(1)
	    {
	      printf("\nEnter lower trim percentage for Non-Gene average :- "); scanf("%d",&Trim3);
	      if(Trim3>25)
		{
		  printf("\nTrim percentage must be less then equal to 25\n");
		  continue; 
		}
	      break;
	    }
	  while(1)
	    {
	      printf("\nEnter upper trim percentage for Non-Gene average  :- "); scanf("%d",&Trim4); 
	      if(Trim4>25)
		{
		  printf("\nTrim percentage must be less then equal to 25\n");
		  continue; 
		}
	      break;
	    }
	}

	void Free_Allocated_Memory(void) 
	{
	  int i;

	  for( i=0; i<Path_Count; i++)
	    {
	      free(Gene_detection_frequency[i]);
	      free(NonGene_detection_frequency[i]); 
	      free(Result[i]);      
	    }
	  free(Gene_detection_frequency); free(NonGene_detection_frequency); free(Undecided);  free(frequency_value); 
	  free(Program_Detect_Gene); free(Program_Detect_NonGene);  free(Result);

	}

	double R_Statistic_for_P(
				 char *PathName,
				 int file_id)
	{    
	  int i,Count,Length=0,seqLen=4;
	  char  *TempBuf,seqArr[4]={'A','T','C','G'},sign;
	  double MinRatio;
		             
	  sign = (file_id < 2 ? '+' : '-');
	  Length = readSequenceFromGenome(PathName,file_id,sign);

	  if(Length < MIN_CHAR || Length > MAX_CHAR)
	    {
		      
	      return 0;
	    }
		     
	  if(!Addaptive_Flag)  
	    Omega(seqLen);
	  else
	    compute_omega_parametere(seqLen,Length);
		          
	  for(i=0;i<seqLen;i++)
	    {
	      seqSearch(Seq_Buffer,seqArr[i],&TempBuf,Length);
	      fOmega(TempBuf,Length,i);
	      free(TempBuf);
	    }
	  Count=UnionW(); MinRatio=Ratio(Count);Clear_Memory(seqLen); 
	  return MinRatio;
	}

	//------------------------Re-Thresholding SmallGenes-------------------------------
	void reThresholding_SmallGenes(char *nameSpace, double MinRatio_Gene,int processId_f_Ratio)
	{
	  FILE *fp,*fp_NameSpace,*fp1,*fp2,*Fp_Bckup;
	  int file_Count;
	  char seq_FileName[400];
	  char orfPlus_File[400],orfMinus_File[400];
	  char str[500], tmp_str[400];
	  char seq_Name[400],predict[50];
	  int isGene,Length,nonGenes = 0;
	  double rVal,MinRatio,lBound_Percent;
	  int predGenes,predNonGenes;
	  char T_Path[400];
	  int processState;
	  double threshold_val;
	  char result_folder[400], query[400];
	  int totalRecord = 0, lineCount =0;
	  QString tmps;
	  QString stateDescription;
		 

	  mainPbc->addAChildProcess(100,"Re-Thresholding SmallGene");

	 

	  if(choice == 1)
	    printf("\nEnter threshold for R-Statistic for Genes :- ");
	  else
	    {
	      ////////////Read from Back up
	      sprintf(tmp_str  ,"%s/Backup_P_Val.txt",seq_work_dir);
	      Fp_Bckup = fopen(tmp_str,"r");
	      fscanf(Fp_Bckup,"%d\t%lf\t%lf",&Operation,&swap_Percent,&mut_Percent);
	      fclose(Fp_Bckup);
	      Fp_Bckup = NULL;

	      ///////////////////////////////////////////////
	      // printf("\nEnter threshold for P-Value for Genes :- ");
	    }
	  //printf("\n namespance = %s", nameSpace);
	  if((fp_NameSpace = fopen(nameSpace,"r")) != NULL)
	    {
	      fscanf(fp_NameSpace,"%d",&file_Count);
	      for(int i = 0; i < 6; i++)
		fscanf(fp_NameSpace,"%s",orfPlus_File);
	      fscanf(fp_NameSpace,"%s",orfMinus_File);
	      fscanf(fp_NameSpace,"%s",orfMinus_File);
	      fclose(fp_NameSpace);
	      fp_NameSpace = NULL;
	    }

	  // --------- Read method type ------
	  if(choice==1)
	    {
	     tmps=paramMg->getValueById("140"); // the RStat result folder reference
	      sprintf(T_Path,"%s/%s/methodType.txt",seq_work_dir,(const char *)tmps);
	    } else
	    {
	     tmps=paramMg->getValueById("670"); // the RStat result folder reference
	      //sprintf(T_Path,"%s/%/methodType.txt",seq_work_dir);
	      sprintf(T_Path,"%s/%s/methodType.txt",seq_work_dir,(const char *)tmps);
	    }
	  fp=fopen(T_Path,"r");
	  fscanf(fp, "%d", &methodType);
	  fclose(fp);
	  // ------ Read Method Type (end) -------
		   
	  // -----  Read fration from file --------
	  sprintf(T_Path,"%s/fratio%d.txt",seq_work_dir,choice);
	  if(fp=fopen(T_Path,"r"))   {  
	    fscanf(fp,"%lf", &threshold_val); fclose(fp);
	  }
	  // ------ Read fration from file (end) ------

	  sprintf(query,"mkdir %s/%s/smallGene ", seq_work_dir,(const char *)tmps);
	  system(query);
	  if(methodType==1){
	    sprintf(query,"mkdir %s/%s/smallGene/tri ", seq_work_dir,(const char *)tmps);
	    system(query);
	  }
	  if(methodType==2){
	    sprintf(query,"mkdir %s/%s/smallGene/tetra ", seq_work_dir,(const char *)tmps);
	    system(query);
	  }

	  // get pvalue folder from paramManager and replace the folder name (as implemented from R-stat)
	  sprintf(query,"mkdir %s/%s/smallGene",seq_work_dir,(const char *)tmps);
	  system(query);   
	 
	  if(methodType==1)
	    {
	      sprintf(query,"mkdir %s/%s/smallGene/tri",seq_work_dir,(const char *)tmps);
	      system(query);   
	    }
	  if(methodType==2)
	    {
	      sprintf(query,"mkdir %s/%s/smallGene/tetra",seq_work_dir,(const char *)tmps);
	      system(query);   
	    }


	  // Create folder 
	  sManager->getProcessState(processId_f_Ratio,&processState,&stateDescription);

	  // create a folder named 'normal' in the result directory
	  // if already exist delete the same recursively.
		 

	  printf("\n>>>>method type: %d",methodType);
	  if(processState==100  && (fp=fopen(T_Path,"r"))){
		       
	    fscanf(fp,"%lf,%d", &threshold_val,&methodType);
	    if(choice ==1){
		       
	      if(methodType==1)	sprintf(result_folder,"%s/%s/smallGene/tri/f%lf",seq_work_dir,(const char *)tmps,threshold_val);
	      if(methodType==2)	sprintf(result_folder,"%s/%s/smallGene/tetra/f%lf",seq_work_dir,(const char *)tmps,threshold_val);
	    }else{
	      if(methodType==1) sprintf(result_folder,"%s/%s/smallGene/tri/f%lf",seq_work_dir,(const char *)tmps,threshold_val);
	      if(methodType==2) sprintf(result_folder,"%s/%s/smallGene/tetra/f%lf",seq_work_dir,(const char *)tmps,threshold_val);
			
	    }
	  }else{
	    // create a folder named like 'f1.24' (fration no)
	    // if already delete the folder recursively.
	    // create a directory "normal"

	    if(choice ==1){
	      if(methodType==1) sprintf(result_folder,"%s/%s/smallGene/tri/normal",seq_work_dir,(const char *)tmps);
	      if(methodType==2) sprintf(result_folder,"%s/%s/smallGene/tetra/normal",seq_work_dir,(const char *)tmps);
	    }else{
	      if(methodType==1) sprintf(result_folder,"%s/%s/smallGene/tri/normal",seq_work_dir,(const char *)tmps);
	      if(methodType==2) sprintf(result_folder,"%s/%s/smallGene/tetra/normal",seq_work_dir,(const char *)tmps);
	    }
		   
	  }
	  //  

	  // use system command to create directory
	  sprintf(query,"rm %s -r",result_folder);
	  system(query);
	  sprintf(query,"mkdir %s",result_folder);
	  system(query); 
	  printf(" \n ****  Choice = %d", choice);  	





	  // printf("\n orfPlus_File = %s", orfPlus_File);
	  //printf("\n orfMinus_File = %s", orfMinus_File);

	  sprintf(tmp_str,"%s/Addaptive_Flag.txt",seq_work_dir);
		  
	  fp = fopen(tmp_str,"r");

	  fscanf(fp,"%d%d",&Addaptive_Flag,&Occur);
	  fclose(fp);
	  fp = NULL;
	  sprintf(tmp_str,"%s/path_ORF",seq_work_dir);
	  fp = fopen(tmp_str,"r");
	  if(!fp)
	    { 

	      QMessageBox::warning(appl,"Warning", "path_ORF file cannot be opend; exit(0)");
	      exit(0);
	    }

	  fscanf(fp,"%s",seq_FileName);

	  genomeLength = ReadFile(seq_FileName,&forward_Genome); 
	  reverse_complement_of_Sequence();
	  fclose(fp);
	  fp = NULL;
	// read number of lines of orfplus file for progressbar
	
	sprintf(str, "wc %s -l>%s/.tmp.txt", orfPlus_File, seq_work_dir);
	system(str);
	sprintf(str, "%s/.tmp.txt", seq_work_dir);
	fp = fopen(str, "r");
	fscanf(fp, "%d", &lineCount);
	totalRecord = lineCount;
	fclose(fp);
	// read number of lines of orfminus for progressbar
	sprintf(str, "wc %s -l>%s/.tmp.txt", orfMinus_File, seq_work_dir);
	system(str);
	sprintf(str, "%s/.tmp.txt", seq_work_dir);
	fp = fopen(str, "r");
	fscanf(fp, "%d", &lineCount);
	totalRecord += lineCount;
	fclose(fp);
	sprintf(str, "rm %s/.tmp.txt", seq_work_dir);
	system(str);
	///////////////////////////////////
	
	
	
	///////////////////////////////////
	
	  sprintf(seq_FileName,"%sB",orfPlus_File);
	
	  sprintf(str,"rename %s %s %s",orfPlus_File,seq_FileName,orfPlus_File);
	  system(str);


 	

	  fp1 = fopen(seq_FileName,"r");
	 
	  
	  
	  fp2 = fopen(orfPlus_File,"w");
	  fscanf(fp1,"%[^\n]\n",str);
	  fprintf(fp2,"%s\n",str);
	  lineCount =0;
	  while(1)
	    {
	      mainPbc->setProgressA(lineCount++, totalRecord);
	      mainPbc->updateProgress();
	      // Processed closed forcefully
	      if(mainPbc->pbcWasCanceled()) 
		{
		  fclose(fp1);
		  fclose(fp2);
		  fp1 = NULL;
		  fp2 = NULL;
		  free(forward_Genome);
		  free(reverse_Genome);
		  sprintf(query,"rm %s -r",result_folder);
		  system(query);
		  sprintf(query,"rm %s", orfPlus_File);
		  system(query);
		  sprintf(query,"mv %s %s -f",seq_FileName, orfPlus_File);
		  system(query);
							 
							 
		  forward_Genome = reverse_Genome = NULL;
		  mainPbc->pbcReset(); return;
		}
	      /////
	      fscanf(fp1,"%[^\t]\t%d\t%[^\t]\t%lf\t%d\n",seq_Name,&isGene,predict,&rVal,&Length);
	      if(strncmp(seq_Name,"Total Predicted Genes = 0",15) == 0)
		{
		  sscanf(seq_Name,"%s %s %s %s %d %s %s %s %s %d",str,str,str,str,&predGenes,str,str,str,str,&predNonGenes);
		  fprintf(fp2,"\n\n Total Predicted Genes = %d\n",(predGenes - nonGenes));
		  fscanf(fp1,"%[^\t]\t%d\t%[^\t]\t%lf\t%d\n",seq_Name,&isGene,predict,&rVal,&Length);
		  fprintf(fp2," Total Predicted Non-Genes = %d\n\n",(predNonGenes + nonGenes));
		  fprintf(fp2," Prediction Confidence in %\tFrequency of Predicted Genes\tFrequency of Predicted Non-Genes\n");
		  fscanf(fp1,"\n\n%[^\n]\n",str);
		  for(int i = 0; i < 12; ++i)
		    {
		      fscanf(fp1,"\n\n%[^\n]\n",str);
		      fprintf(fp2," %s\n",str);
		    }
		  break;
		}
	      else
		{
		  if(Length < PLR && isGene == 1)
		    {
			    
		      if(choice == 1)
			{
			  MinRatio = Compute_MinRatio(seq_Name,0,'+');
				 	
			  if(MinRatio <= MinRatio_Gene)
			    fprintf(fp2,"%s\t%d\t%s\t%lf\t%d\n",seq_Name,1,predict,MinRatio,Length);
			  else
			    {
			      fprintf(fp2,"%s\t%d\t%s\t%lf\t%d\n",seq_Name,0,predict,MinRatio,Length);
			      ++nonGenes;
			    }
			}
		      else
			{
			  lBound_Percent = Compute_P_Value(seq_Name,0,'+');
			  if(lBound_Percent <= MinRatio_Gene)
			    fprintf(fp2,"%s\t%d\t%s\t%lf\t%d\n",seq_Name,1,predict,lBound_Percent,Length);
			  else
			    {
			      fprintf(fp2,"%s\t%d\t%s\t%lf\t%d\n",seq_Name,0,predict,lBound_Percent,Length);
			      ++nonGenes;
			    }
			}	
		    }
		  else
		    fprintf(fp2,"%s\t%d\t%s\t%lf\t%d\n",seq_Name,isGene,predict,rVal,Length);
		}
	    }


	  sprintf(query,"mv %s %s -f",orfPlus_File, result_folder);
	  system(query);
	  sprintf(query,"mv %s %s -f", seq_FileName, orfPlus_File);
	  system(query);





	  fclose(fp1);
	  fclose(fp2);
	  fp1 = NULL;
	  fp2 = NULL;
		 
	  nonGenes = 0;
	  sprintf(seq_FileName,"%sB",orfMinus_File);
	  sprintf(str,"rename %s %s %s",orfMinus_File,seq_FileName,orfMinus_File);
	  system(str);
	  fp1 = fopen(seq_FileName,"r");
	  fp2 = fopen(orfMinus_File,"w");
	  fscanf(fp1,"%[^\n]\n",str);
	  fprintf(fp2,"%s\n",str);
	  while(1)
	    {
	      mainPbc->setProgressA(lineCount++, totalRecord);
	      mainPbc->updateProgress();
	      // Processed closed forcefully
	      if(mainPbc->pbcWasCanceled()) 
		{
		  fclose(fp1);
		  fclose(fp2);
		  fp1 = NULL;
		  fp2 = NULL;
		  free(forward_Genome);
		  free(reverse_Genome);
		  sprintf(query,"rm %s", orfMinus_File);
		  system(query);
		  sprintf(query,"rm %s -r",result_folder);
		  system(query);
		  sprintf(query,"mv %s %s -f",seq_FileName, orfMinus_File);
		  system(query);
		  forward_Genome = reverse_Genome = NULL;
		  mainPbc->pbcReset(); return;
		}
	      /////
	      fscanf(fp1,"%[^\t]\t%d\t%[^\t]\t%lf\t%d\n",seq_Name,&isGene,predict,&rVal,&Length);
	      if(strncmp(seq_Name,"Total Predicted Genes = 0",15) == 0)
		{
		  sscanf(seq_Name,"%s %s %s %s %d %s %s %s %s %d",str,str,str,str,&predGenes,str,str,str,str,&predNonGenes);
		  fprintf(fp2,"\n\n Total Predicted Genes = %d\n",(predGenes - nonGenes));
		  fscanf(fp1,"%[^\t]\t%d\t%[^\t]\t%lf\t%d\n",seq_Name,&isGene,predict,&rVal,&Length);
		  fprintf(fp2," Total Predicted Non-Genes = %d\n\n",(predNonGenes + nonGenes));
		  fprintf(fp2," Prediction Confidence in %\tFrequency of Predicted Genes\tFrequency of Predicted Non-Genes\n");
		  fscanf(fp1,"\n\n%[^\n]\n",str);
		  for(int i = 0; i < 12; ++i)
		    {
		      fscanf(fp1,"\n\n%[^\n]\n",str);
		      fprintf(fp2," %s\n",str);
		    }
		  break;
		}
	      else
		{
		  if(Length < PLR && isGene == 1)
		    {
			    
		      if(choice == 1)
			{
			  MinRatio = Compute_MinRatio(seq_Name,2,'-');
				  		
			  if(MinRatio <= MinRatio_Gene)
			    fprintf(fp2,"%s\t%d\t%s\t%lf\t%d\n",seq_Name,1,predict,MinRatio,Length);
			  else
			    {
			      fprintf(fp2,"%s\t%d\t%s\t%lf\t%d\n",seq_Name,0,predict,MinRatio,Length);
			      ++nonGenes;
			    }
			}
		      else
			{
			  lBound_Percent = Compute_P_Value(seq_Name,2,'-');
			  if(lBound_Percent <= MinRatio_Gene)
			    fprintf(fp2,"%s\t%d\t%s\t%lf\t%d\n",seq_Name,1,predict,lBound_Percent,Length);
			  else
			    {
			      fprintf(fp2,"%s\t%d\t%s\t%lf\t%d\n",seq_Name,0,predict,lBound_Percent,Length);
			      ++nonGenes;
			    }
			}
		    }
		  else
		    fprintf(fp2,"%s\t%d\t%s\t%lf\t%d\n",seq_Name,isGene,predict,rVal,Length);
		}
		
	    }


	  sprintf(query,"mv %s %s -f",orfMinus_File, result_folder);
	  system(query);
	  sprintf(query,"mv %s %s -f", seq_FileName, orfMinus_File);
	  system(query);


	  fclose(fp1);
	  fclose(fp2);
	  fp1 = NULL;
	  fp2 = NULL;
	  free(forward_Genome);
	  free(reverse_Genome);
	  forward_Genome = reverse_Genome = NULL;
	  mainPbc->pbcReset();


	}
	//--------------------------------End Re-Thresholding SmallGenes-------------------------
	//--------------------------------Ribosome Pattern/s Selection---------------------------
	void Ribosome_PatternSelection()
	{
	  FILE *fp1,*fp2;
	  char RPat[26][6],Window[50], tmp_str[400];
	  char seqName_Train[400],seqName_Test[400];
	  int Pos1_Train,Pos2_Train,Pos1_Test,Pos2_Test,index,winIndx,Counter;
	  int Plusrec_Counter,Minusrec_Counter,recCounter;
	  int **RPat_Scores;
	  double avg_Scores[26];
			
	  bool Flag;
	  SEQLIST *head,*node=NULL,*tempNode;
			
	  fp1 = fopen("Num_records.txt","r");
	  fscanf(fp1,"%d\n",&Plusrec_Counter);
	  fscanf(fp1,"%d\n",&Minusrec_Counter);
	  fclose(fp1);
	  fp1 = NULL;
			
	  if((fp1 = fopen("5bp.txt","r")) != NULL)
	    {
	      for(index = 0; index < 26; index++)
		fscanf(fp1,"%s\n",RPat[index]);
	      fclose(fp1);
	      fp1 = NULL;
	    }
			
	  head = NULL;
	  Flag = TRUE;
	  Counter = 0;
	  recCounter = 1;
	  fp1 = fopen("MultipleStart.txt","r");
	  fp2 = fopen("orfPlus_Minus.txt","r");
	  while(!feof(fp2))
	    {
	      fscanf(fp2,"%s\t%d\t%d\n",seqName_Train,&Pos1_Train,&Pos2_Train);
	      if(Flag == TRUE)
		fscanf(fp1,"%s\t%d\t%d\n",seqName_Test,&Pos1_Test,&Pos2_Test);
	      if(strcmp(seqName_Train,seqName_Test) != 0)
		{
		  tempNode = new SEQLIST();
		  strcpy(tempNode->seq,seqName_Train);
		  tempNode->Pos1 = Pos1_Train;
		  tempNode->Pos2 = Pos2_Train;
		  if(recCounter <= Plusrec_Counter)
		    tempNode->Strand = '+';
		  else if(recCounter <= (Plusrec_Counter + Minusrec_Counter))
		    tempNode->Strand = '-';	
		  tempNode->next = NULL;			
		  if(head == NULL)
		    head = tempNode;
		  else
		    node->next = tempNode;	
		  node = tempNode;
		  ++Counter;
		  Flag = FALSE;
		}
	      else
		Flag = TRUE;
	      ++recCounter;
	    }
	  fclose(fp1);
	  fclose(fp2);
	  fp1 = fp2 = NULL;
			
	  RPat_Scores = new int*[Counter];
	  for(int i = 0; i < Counter; i++)
	    RPat_Scores[i] = new int[26];
	  sprintf(tmp_str,"%s/path_ORF",seq_work_dir);	
	  fp1 = fopen(tmp_str,"r");
	  if(!fp1)
	    { 
	      QMessageBox::warning(appl,"warning","path_ORF file cannot be opend; exit(0)");
	      exit(0);
	    }
	  printf("\n\nPlease Wait...........\n\n"); 
	  fscanf(fp1,"%s",seqName_Train);
	  genomeLength = ReadFile(seqName_Train,&forward_Genome); 
	  reverse_complement_of_Sequence();
	  fclose(fp1);
	  fp1 = NULL;
	  node = head;
	  for(int i = 0; i < Counter; i++)
	    {

	      if(node->Strand == '+')
		{
		  for(winIndx = 0,index = node->Pos1 - 50 - 1; index < node->Pos1 - 1; index++,winIndx++)
		    Window[winIndx] = forward_Genome[index];
		  Window[winIndx] = '\0';
		}
	      else if(node->Strand == '-')
		{
		  node->Pos1 = genomeLength - node->Pos1;
		  node->Pos2 = genomeLength - node->Pos2;
		  for(winIndx = 0,index = node->Pos1 - 50 - 1; index < node->Pos1 - 1; index++)
		    Window[winIndx++] = reverse_Genome[index];
		  Window[winIndx] = '\0';
		}

	      Calculate_Scores(Window,i,RPat,&RPat_Scores);
	      node = node->next;
	    }
	  Calculate_Avg_Scores(&RPat_Scores,Counter,&avg_Scores[0]);
	  Find_Max_Avg_Scores_And_Save_5bps(&avg_Scores[0],RPat);
			
	  cout << Counter << endl;
	  for(int i = 0; i < Counter; i++)
	    delete [] RPat_Scores[i];
	  delete [] RPat_Scores;
	  free(forward_Genome);
	  forward_Genome = NULL;
	  free(reverse_Genome);
	  reverse_Genome = NULL;
	  FreeList(&head);
	}

	void Calculate_Scores(char Window[],int Counter,char RPat[][6],int ***RPat_Scores)
	{
	  int Score,maxScore=0,k,l;
			
	  for(int i = 0; i < 26; i++)
	    {
	      for(int j = 0; j < 46; j++)
		{
		  l = j;
		  Score = 0;
		  for(k = 0; k < 5; k++)
		    {
		      if(Window[l++] == RPat[i][k])
			++Score;
		      else 
			--Score;
		    }
		  if(j == 0)
		    maxScore = Score;
		  else
		    maxScore = (maxScore >= Score ? maxScore : Score);
		}
	      *(*(*RPat_Scores + Counter) + i) = maxScore;
				
	    }
	}

	void Calculate_Avg_Scores(int ***RPat_Scores,int Counter,double *avg_Scores)
	{
	  int Scores_Sum;
			
	  for(int i = 0; i < 26; i++)
	    {
	      Scores_Sum = 0;
	      for(int j = 0; j < Counter; j++)
		Scores_Sum += *(*(*RPat_Scores + j) + i);
	      *(avg_Scores + i) = double(Scores_Sum)/double(Counter);
	      cout << *(avg_Scores + i) << "\t";
	    }
	  cout << endl;
	}

	void Find_Max_Avg_Scores_And_Save_5bps(double *avg_Scores,char RPat[][6])
	{
	  FILE *fp;
	  double max_Avg;
			
	  max_Avg = avg_Scores[0];
	  for(int i = 1; i < 26; i++)
	    max_Avg = (max_Avg >= *(avg_Scores + i) ? max_Avg : *(avg_Scores + i));
	  cout << "\nmax_Avg: " << max_Avg << endl;
	  if((fp = fopen("5bp_Selected.txt","w")) != NULL)
	    {
	      for(int i = 0; i < 26; i++)
		{
		  if(max_Avg == *(avg_Scores + i))
		    {
		      cout << RPat[i] << endl;
		      fprintf(fp,"%s\n",RPat[i]);
		    }
		}
	      fclose(fp);
	      fp = NULL;
	    }
	}

	void FreeList(SEQLIST **head)
	{
	  SEQLIST *tempNode;
			
	  while((*head)->next != NULL)
	    {
	      tempNode = *head;
	      *head = (*head)->next;
	      delete [] tempNode;
	    }
	  delete [] *head;
	}
	//-----------------------------End Ribosome Pattern/s Selection----------------------------
	//--------------------------------RBSFinder----------------------------------------------
	void Filter_FinalPred_File(char *nameSpace)
	{
	  FILE *fp,*fp_NameSpace,*fp1,*fp3;
	  char orfPlus_File[400],orfMinus_File[400];
	  char seq_Name[400],predict[50];
	  int isGene,Length,file_Count;
	  int Pos1,Pos2;
	  double rVal;
	  int recCounter;
				
	  if((fp_NameSpace = fopen(nameSpace,"r")) != NULL)
	    {
	      fscanf(fp_NameSpace,"%d",&file_Count);
	      for(int i = 0; i < 6; ++i)
		fscanf(fp_NameSpace,"%s",orfPlus_File);	
	      fscanf(fp_NameSpace,"%s",orfMinus_File);
	      fscanf(fp_NameSpace,"%s",orfMinus_File);
	      fclose(fp_NameSpace);
	      fp_NameSpace = NULL;
	    }
	  fp3 = fopen("Num_records.txt","w");
	  fp1 = fopen(orfPlus_File,"r");
	  fp = fopen("orfPlus_Minus.txt","w");
	  recCounter = 0;
	  fscanf(fp1,"%[^\n]\n",seq_Name);
	  while(1)
	    {
	      fscanf(fp1,"%[^\t]\t%d\t%[^\t]\t%lf\t%d\n",seq_Name,&isGene,predict,&rVal,&Length);
	      if(strncmp(seq_Name,"Total Predicted Genes = 0",15) == 0)
		break;
	      else
		{
		  if(isGene == 1)
		    {
		      Extract_Index(seq_Name,Pos1,Pos2,'+'); //Extract index values from sequence name
		      fprintf(fp,"%s\t%d\t%d\n",seq_Name,Pos1,Pos2);
		      ++recCounter;
		    }
		}
	    }
	  fclose(fp1);
	  fclose(fp);
	  fp = fp1 = NULL;
	  fprintf(fp3,"%d\n",recCounter);
	  recCounter = 0;
	  fp1 = fopen(orfMinus_File,"r");
	  fp = fopen("orfPlus_Minus.txt","a");
	  fscanf(fp1,"%[^\n]\n",seq_Name);
	  while(1)
	    {
	      fscanf(fp1,"%[^\t]\t%d\t%[^\t]\t%lf\t%d\n",seq_Name,&isGene,predict,&rVal,&Length);
	      if(strncmp(seq_Name,"Total Predicted Genes = 0",15) == 0)
		break;
	      else
		{
		  if(isGene == 1)
		    {
		      Extract_Index(seq_Name,Pos1,Pos2,'-'); //Extract index values from sequence name
		      fprintf(fp,"%s\t%d\t%d\n",seq_Name,Pos1,Pos2);
		      ++recCounter;
		    }
		}
	    }
	  fclose(fp1);
	  fclose(fp);
	  fp = fp1 = NULL;
	  fprintf(fp3,"%d\n",recCounter);
	  recCounter = 0;
	  fclose(fp3);
	  fp3 = NULL;
	}

	void MultipleFileFinder()
	{
	  FILE *fp,*fp1,*fp2,*fp3;
	  char seq_FileName[400], temp_String[400];
	  char MPlus_File[400],MMinus_File[400];
	  char seq_Name[400];
	  int Length;
	  int Pos1,Pos2;
	  int Plusrec_Counter,Minusrec_Counter,recCounter;
	  sprintf(temp_String,"%s/path_ORF",seq_work_dir);
	  if((fp = fopen(temp_String,"r")) != NULL)
	    {
	      for(int i = 0; i < 6; ++i)
		fscanf(fp,"%s",MPlus_File);
	      fscanf(fp,"%s",MMinus_File);
	      fclose(fp);
	      fp = NULL;
	    }
			
	  fp3 = fopen("Num_records.txt","r");
	  fscanf(fp3,"%d\n",&Plusrec_Counter);
	  fscanf(fp3,"%d\n",&Minusrec_Counter);
	  fclose(fp3);
	  fp3 = NULL;
	  recCounter = 0;
			
	  fp1 = fopen("orfPlus_Minus.txt","r");
	  fp2 = fopen(MPlus_File,"r");
	  fp = fopen("MultipleStart.txt","w");
	  while(!feof(fp1))
	    {
	      fscanf(fp1,"%s\t%d\t%d\n",seq_Name,&Pos1,&Pos2);
	      if(++recCounter <= Plusrec_Counter)
		{
		  rewind(fp2);
		  while(!feof(fp2))
		    {
		      fscanf(fp2,"%s\t%d\n",seq_FileName,&Length);
		      if(strcmp(seq_FileName,seq_Name) == 0)
			{
			  fprintf(fp,"%s\t%d\t%d\n",seq_FileName,Pos1,Pos2);
			  break;
			}	
		    }
		}
	      else
		break;
	    }

	  fclose(fp2);
	  fclose(fp);
	  fp = fp2 = NULL;
	  //----------------------------------------------------------------------------------------------------

	  recCounter = 1;

	  fp2 = fopen(MMinus_File,"r");
	  fp = fopen("MultipleStart.txt","a");
	  while(1)
	    {
	      if(recCounter++ <= Minusrec_Counter)
		{
		  rewind(fp2);
		  while(!feof(fp2))
		    {
		      fscanf(fp2,"%s\t%d\n",seq_FileName,&Length);
		      if(strcmp(seq_FileName,seq_Name) == 0)
			{
			  fprintf(fp,"%s\t%d\t%d\n",seq_FileName,Pos1,Pos2);
			  break;
			}
		    }
		}
	      if(feof(fp1))
		break;
	      fscanf(fp1,"%s\t%d\t%d\n",seq_Name,&Pos1,&Pos2);
	    }
			
	  fclose(fp1);
	  fclose(fp2);
	  fclose(fp);
	  fp = fp1 = fp2 = NULL;

	}

	void RBSFinder()
	{
	  FILE *fp,*fp1;
	  char GenomeFile[400],basePair[6],str[400];

	  fp = fopen("path","r");
	  fscanf(fp,"%s",GenomeFile);
	  fclose(fp);
	  fp = NULL;
			
	  if((fp1 = fopen("RBSLst.txt","w")) != NULL)
	    {
	      if((fp = fopen("5bp_Selected.txt","r")) != NULL)
		{
		  while(!feof(fp))
		    {
		      fscanf(fp,"%s\n",basePair);
		      sprintf(str,"./rbs_finder.pl %s orfPlus_Minus.txt RBS_%s.txt 50 %s -p MultipleStart.txt",GenomeFile,basePair,basePair);
		      system(str);
		      sprintf(str,"RBS_%s.txt",basePair);
		      fprintf(fp1,"%s\n",str);
		    }
		  fclose(fp);
		  fp = NULL;
		}
	      fclose(fp1);
	      fp1 = NULL;
	    }
	}

	void FilterRBSOutPut()
	{
	  FILE *fp1,*fp2,*fp3,*fp4;
	  char seqName_Train[400],seqName_Test[400],RBSFile1[20],RBSFile2[20],str[400];
	  char *token1,*token2;
	  int Pos1_Train,Pos2_Train,Pos1_Test,Pos2_Test;
	  int Plusrec_Counter,Minusrec_Counter,recCounter;
	  bool Flag;
			
	  fp1 = fopen("Num_records.txt","r");
	  fscanf(fp1,"%d\n",&Plusrec_Counter);
	  fscanf(fp1,"%d\n",&Minusrec_Counter);
	  fclose(fp1);
	  fp1 = NULL;
			
	  if((fp4 = fopen("RBSLst.txt","r")) != NULL)
	    {
	      while(!feof(fp4))
		{
		  fscanf(fp4,"%s\n",RBSFile1);
		  recCounter = 1;
		  Flag = TRUE;
		  searchToken('.',2,&token1,RBSFile1);
		  searchToken('_',1,&token2,token1);
		  sprintf(RBSFile2,"RBS%s.txt",token2);
		  fp2 = fopen(RBSFile2,"w");
		  fp3 = fopen("orfPlus_Minus.txt","r");
		  fp1 = fopen(RBSFile1,"r");
		  fscanf(fp1,"%[^\n]\n",seqName_Test);
		  fscanf(fp1,"%[^\n]\n",seqName_Test);
		  while(!feof(fp3))
		    {
		      fscanf(fp3,"%s\t%d\t%d\n",seqName_Train,&Pos1_Train,&Pos2_Train);
		      if(Flag == TRUE)
			fscanf(fp1,"%s\t%d\t%d\t%[^\n]\n",seqName_Test,&Pos1_Test,&Pos2_Test,str);
		      if(strcmp(seqName_Train,seqName_Test) == 0)
			{
			  if(recCounter <= Plusrec_Counter)
			    fprintf(fp2,"%s\t%d\t%d\t%c\n",seqName_Test,Pos1_Test,Pos2_Test,'+');
			  else if(recCounter <= (Plusrec_Counter + Minusrec_Counter))
			    fprintf(fp2,"%s\t%d\t%d\t%c\n",seqName_Test,Pos1_Test,Pos2_Test,'-');
			  Flag = TRUE;
			}
		      else
			{
			  if(recCounter <= Plusrec_Counter)
			    fprintf(fp2,"%s\t%d\t%d\t%c\n",seqName_Train,Pos1_Train,Pos2_Train,'+');
			  else if(recCounter <= (Plusrec_Counter + Minusrec_Counter))
			    fprintf(fp2,"%s\t%d\t%d\t%c\n",seqName_Train,Pos1_Train,Pos2_Train,'-');
			  Flag = FALSE;
			}
		      ++recCounter;
		    }
		  fclose(fp1);
		  fclose(fp2);
		  fclose(fp3);
		  fp1 = fp2 = fp3 = NULL;
		}
	      fclose(fp4);
	      fp4 = NULL;
	    }

	}
	//--------------------------------End RBSFinder------------------------------------------
