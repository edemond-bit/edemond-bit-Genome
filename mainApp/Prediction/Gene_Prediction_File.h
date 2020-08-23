
	#include "Gene_Prediction.h"
	#include "qmessagebox.h"
	#include "qprogressdialog.h"


	// Parameters to pass from the GUI programm
	// FileName : (%s) Enter name of the directory list
	// MIN_CHAR : (%d) Enter Minimum sequence length
	// MAX_CHAR : (%d) Enter Maximum sequence length
	// seq_FileName: (%s) Sequence_R-Statistic
	// isPrint_R_P : (%c) Do you want use a fixed set of frequency values 
	//               for R-Statistic computation ? (Y/N) :- ");
	// Occur : (%d)  Enter number of frequency vaanalysis_Nearest_Neighbourhoodlue (should be multiple of 3) :- "
	// if value of Occur is negative that means not to use fixed set of 
	//               frequency value


	void computation_R_Statistic(
		const char * _FileName, 
	        int _MIN_CHAR, 
	        int _MAX_CHAR, 
	        const char *_seq_FileName,
	        char _isPrint_R_P,
		int _Occur)
	{
		FILE *fp,*fp_Misc;
		char temp_String[400],seq_FileName[400],PathName[400],temp_Path[400];
		char FileName[400];
		mainPbc->pbcReset();
		mainPbc->addAChildProcess(100,"R-Statistic Computation");
		// changing the current directory 
		strcpy(curr_Dir,"");
		strcpy(FileName, _FileName);
		MIN_CHAR = _MIN_CHAR;
		MAX_CHAR = _MAX_CHAR;
		strcpy(seq_FileName, _seq_FileName);
		fp = fopen(seq_FileName,"w"); 
		fclose(fp); 
		fp=NULL;
		//Below part to record the R-Statistic file name in a master file
		if((fp = fopen(nameSpace[0],"w")) != NULL); 
		{
			fprintf(fp,"2\n%s/path_ORF\n%s\n",seq_work_dir,seq_FileName);
			fclose(fp); 
		}
		fp=NULL;
		///////////////////////////////////
		while(1)
		{
			if(_Occur>=0)
			{
				Occur = _Occur;
				Addaptive_Flag = 0;
				break;
			}
			else
			{
				Occur = 0;
				Addaptive_Flag = 1;
				break;
			}
		}
		Occur_org = Occur;
		fp = NULL;
		sprintf(temp_String,"%s/Addaptive_Flag.txt",seq_work_dir);
		fp= fopen(temp_String,"w");
		fprintf(fp,"%d\n%d\n",Addaptive_Flag, Occur);
		fclose(fp);
		isPrint_R_P = toupper(_isPrint_R_P);
		// Open path_ORF file
		sprintf(temp_String,"%s/path_ORF",seq_work_dir);
		Total_File = Path_Count = 0;
		fp = fopen(temp_String,"r");
		if(!fp)
		{
			QString tmp("Process terminating:: Cannot open file : ");
			QMessageBox::warning(appl,"Warning", tmp+temp_String);
			return;
		}
		fscanf(fp,"%s",PathName);
		// forward computation
		mainPbc->addAChildProcess(2,"Forword Computation ");
		genomeLength = ReadFile(PathName,&forward_Genome); 
		mainPbc->deleteLastChildProcess();
		// reverse computation
		reverse_complement_of_Sequence();
		fscanf(fp,"%s",PathName);
		while(1)
		{
			strcpy(temp_Path,PathName);
			if(mainPbc->pbcWasCanceled()) break;
			mainPbc->addAChildProcess(22,PathName);
			Read_Dir(PathName, Path_Count, nameSpace[0]);
			mainPbc->deleteLastChildProcess();
			++Path_Count;
			fscanf(fp,"%s",PathName);
			if(Path_Count == 4 || strcmp(PathName,temp_Path) == 0)	break;
		}
		fclose(fp);
		free(forward_Genome);
		free(reverse_Genome);
		if((fp_Misc = fopen(misc[0],"w")) != NULL)
		{
			fprintf(fp_Misc,"2\n%d\n%d\n",Path_Count,Total_File);
			fclose(fp_Misc);
		}
		mainPbc->deleteLastChildProcess();
		mainPbc->pbcReset();
	}

	
	void computation_Lower_Tail_Probability(
		const char * _FileName, 
		int _MIN_CHAR, 
		int _MAX_CHAR, 
		const char * _seq_FileName, 
		char _isPrint_R_P, 
		int _Occur, 
		int _Operation, 
		double _swap_Percent, 
		double _mut_Percent)

	{
		FILE *fp,*fp_Misc,*Fp_Bckup;
		char temp_String[400];
		char seq_FileName[400];
		char PathName[400];
		char temp_Path[400];
		char FileName[400];
		QString qtmpstr("");
		mainPbc->pbcReset();
		strcpy(FileName, _FileName);
		MIN_CHAR = _MIN_CHAR;
		MAX_CHAR = _MAX_CHAR;
		strcpy(seq_FileName, _seq_FileName);
		fp = fopen(seq_FileName,"w");
		fclose(fp);
		fp=NULL;
		if((fp = fopen(nameSpace[1],"w")) != NULL)
		{
			fprintf(fp,"2\n%s/path_ORF\n%s\n",seq_work_dir,seq_FileName);
			fclose(fp);
		}
		fp=NULL;
		if(_Occur>=0)
		{
			Occur = _Occur;
			Addaptive_Flag = 0;
		}
		else
		{
			Occur = 0;
			Addaptive_Flag = 1;
		}
		Occur_org = Occur;
		fp = NULL;
		sprintf(temp_String,"%s/Addaptive_Flag.txt",seq_work_dir);
		fp= fopen(temp_String,"w");
		fprintf(fp,"%d\n%d\n",Addaptive_Flag, Occur);
		fclose(fp);
		isPrint_R_P = toupper(_isPrint_R_P);
		/**
		This par this for progress computation of p-value calculation
		*/
		// remove  .tmp.txt  which is used by progress bar
		sprintf(temp_String,"%s/.tmp.txt",seq_work_dir);
		checkIfFileExistDeleteIt(temp_String);
		findSizeOfAllORF();
		////////////////////////////////////////////////
		sprintf(temp_String, "%s/path_ORF",seq_work_dir);
		Total_File = Path_Count = 0;
		fp = fopen(temp_String,"r");
		if(!fp)
		{
			//FILE I/O Error
			qtmpstr = "Cannot open file :- " + QString(temp_String);
			qtmpstr = qtmpstr + "\n Current process has been terminated";
			QMessageBox::warning(appl,"warning",qtmpstr);
			return;
		}
		Operation = _Operation;
		swap_Percent = _swap_Percent;
		mut_Percent = _mut_Percent;
		////////////Back up
		sprintf(temp_String,"%s/Backup_P_Val.txt",seq_work_dir);
		Fp_Bckup = fopen(temp_String,"w");
		fprintf(Fp_Bckup,"%d\t%lf\t%lf",Operation,swap_Percent,mut_Percent);
		fclose(Fp_Bckup);
		Fp_Bckup = NULL;
		fscanf(fp,"%s",PathName);
		mainPbc->addAChildProcess(50,"Reading File");
		genomeLength = ReadFile(PathName,&forward_Genome);
		mainPbc->deleteLastChildProcess();
		mainPbc->addAChildProcess(50,"Reverse computation");
		reverse_complement_of_Sequence();
		mainPbc->deleteLastChildProcess();
		fscanf(fp,"%s",PathName);
		mainPbc->deleteLastChildProcess();
		mainPbc->pbcReset();
		sprintf(temp_String, "P-Value computation using :");
		mainPbc->addAChildProcess(100, temp_String);
		while(1)
		{
			strcpy(temp_Path,PathName);
			sprintf(temp_String, "P-Value computation using : %s", PathName);
			mainPbc -> setLabelText(temp_String);
			Read_Dir_P_Value(PathName, Path_Count, nameSpace[1]);
			if(mainPbc->pbcWasCanceled())
			{
				fclose(fp);
				free(forward_Genome);
				free(reverse_Genome);
				return;
			}
			++Path_Count;
			fscanf(fp,"%s",PathName);
			if(Path_Count == 4 || strcmp(PathName,temp_Path) == 0) break;
		}
		mainPbc->deleteLastChildProcess();
		fclose(fp);
		free(forward_Genome);
		free(reverse_Genome);
		if((fp_Misc = fopen(misc[1],"w")) != NULL)
		{
			fprintf(fp_Misc,"2\n%d\n%d\n",Path_Count,Total_File);
			fclose(fp_Misc);
		}
		// remove  .tmp.txt  which is used by progress bar
		sprintf(temp_String,"%s/.tmp.txt",seq_work_dir);
		checkIfFileExistDeleteIt(temp_String);
	}
	
	
	
 	/**
 	This function could be used generally to check if a file exist and delete
 	*/
 	void checkIfFileExistDeleteIt(char *file)
  	{
  		char temp_String[400];
  		struct stat stFileInfo;
  		sprintf(temp_String,"%s", file);
  		if( stat(temp_String, &stFileInfo) == 0)
  		{
  			// file exist so delete it 
  			sprintf(temp_String, "rm %s", file);
  			system(temp_String);
  		}
  	}
 
 
 	/**
 	This function is used for progress computation only.
 	*/
 	void findSizeOfAllORF()
 	{
 		FILE *fp;
 		char temp_String[400];
 		char PathName[400];
 		char temp_Path[400];
 		
 		QString qtmpstr("");
 		sprintf(temp_String, "%s/path_ORF",seq_work_dir);
 		Total_File = Path_Count = 0;
 		
 		fp = fopen(temp_String,"r");
 		if(!fp)
 		{
 			//FILE I/O Error
 			qtmpstr = "Cannot open file :- " + QString(temp_String);
 			qtmpstr = qtmpstr + "\n Current process has been terminated";
			QMessageBox::warning(appl,"warning",qtmpstr);
			return;
		}
		// reads the first entry which is the sequence file name
		fscanf(fp,"%s",PathName); 
		fscanf(fp,"%s",PathName);

		while(1)
		{
			strcpy(temp_Path,PathName);
			findTotalSizeOfORFFile(PathName);
			++Path_Count;
			fscanf(fp,"%s",PathName);
			if(Path_Count == 4 || strcmp(PathName,temp_Path) == 0)
					break;
		}
	
 	}

	/**
	This method used for progress computation only
	This function is to calculate total size of the orf lengs
	*/
	void findTotalSizeOfORFFile(char *orfFile)
	{
		int cumSize = 0;
		int size = 0;
		int temp_size = 0;
		int temp_size1 = 0;
		char PathName[400],Temp_Path[400], tmp_str[400];
		FILE *fp;
		struct stat stFileInfo;
		fp = fopen(orfFile,"r");
		fscanf(fp,"%s\t%d",PathName,&size);
		printf(" \n %s  <<< ", orfFile);
		temp_size = size;
		while(1)
		{
			strcpy(Temp_Path,PathName);
			if((inputType == 2 && size>=MIN_CHAR && size<=MAX_CHAR) || inputType == 1)
			{
				if(size >= PLR)
				{
					cumSize += size;
				}
			}
			fscanf(fp,"%s\t%d",PathName,&size);
			if(strcmp(PathName,Temp_Path) == 0 || (inputType == 2 && temp_size > MAX_CHAR))
				break;
			else
				temp_size = size;
					
				  
				  
		}
		printf("\n Cumulitive size (within rage) = %d , size = %d", cumSize, size);
		sprintf(tmp_str, "%s/.tmp.txt", seq_work_dir);
		if( stat(tmp_str, &stFileInfo) == 0)
		{ 
			//file dose  exist
			fp=fopen(tmp_str, "r");
	 		int p;
			fscanf(fp, "%d %d", &temp_size1, &p );
			cumSize +=temp_size1;
			fclose(fp);
		}
		fp=fopen(tmp_str, "w");
	 	fprintf(fp, "%d %d", cumSize, 0 );
		fclose(fp);
		printf("\n sum of Cumulitive size = %d , size = %d", cumSize, size);
	  	
	}
	


	void thresholding_R_Statistic(
		char nameSpace[],
		char misc[], 
		char f_Ratio_File[], 
		char filtered_Pattern1[],
		char filtered_Pattern2[], 
		QLabel *textLabel,
		int _inputType, 
		int _MIN_CHAR, 
		int _MAX_CHAR,
		int processId)
 	{
 		FILE *fp_NameSpace_In,*fp_NameSpace_Out,*fp_check;
 		int file_Count;
 		char FileName[400];
 		char query[400];
 		char temp_String[400];
 		bool ok=false;
 		mainPbc->pbcReset();
 		ok =Find_Potential_NonPotential_File(nameSpace,misc, textLabel, seq_work_dir, _inputType, _MIN_CHAR, _MAX_CHAR,processId); 
 		if(mainPbc->pbcWasCanceled()) {mainPbc->pbcReset(); return;}  // Process canceled 
 		if(ok)
 		{
 			if((fp_NameSpace_In = fopen(nameSpace,"r")) != NULL)
 			{
 				sprintf(temp_String,"%s/temp_nameSpace.csv",seq_work_dir);
 				if((fp_NameSpace_Out = fopen(temp_String,"w")) != NULL)
 				{
 					fprintf(fp_NameSpace_Out,"5\n");
 					fscanf(fp_NameSpace_In,"%d",&file_Count);
 					fscanf(fp_NameSpace_In,"%s",FileName);
 					fprintf(fp_NameSpace_Out,"%s\n",FileName);
 					fscanf(fp_NameSpace_In,"%s",FileName);
 					fprintf(fp_NameSpace_Out,"%s\n",FileName);
 					if(file_Count > 2) // Only R_Statistic computation has been done
 					{
 						for(int file_id_Count = 2; file_id_Count < file_Count; ++file_id_Count)
 						{
 							fscanf(fp_NameSpace_In,"%s",FileName);
 							if(!(strcmp(FileName,poten_Gene_FileName) == 0 || strcmp(FileName,poten_NGene_FileName) == 0 || strcmp(FileName, nPoten_Seq_FileName) == 0))
 							{
 								if((fp_check = fopen(FileName,"r")) != NULL)
 								{
 									fclose(fp_check);
 									fp_check = NULL;
 									sprintf(query,"rm %s",FileName);
 									system(query);
 								}
 							}
 						}
 					}
 					fclose(fp_NameSpace_In);
 					fprintf(fp_NameSpace_Out,"%s\n",poten_Gene_FileName);
 					fprintf(fp_NameSpace_Out,"%s\n",poten_NGene_FileName);
 					fprintf(fp_NameSpace_Out,"%s\n",nPoten_Seq_FileName);
 					fclose(fp_NameSpace_Out);
 				}
 			}
 			sprintf(query,"rm %s",nameSpace);
 			system(query);
 			sprintf(query,"mv %s/temp_nameSpace.csv %s",seq_work_dir,nameSpace);
 			system(query);
 			delete_F_Ratio(f_Ratio_File);
 			delete_F_Ratio("f_Ratio_Sorted");
 			delete_Filtered_Pattern(filtered_Pattern1);
 			delete_Filtered_Pattern(filtered_Pattern2);
 			sprintf(temp_String,"%s/fratio%d.txt",seq_work_dir,choice);
 			delete_F_Ratio(temp_String);
 			sManager->setProcessState(processId,"100");
 			mainPbc->pbcReset();
 			if(interactiveMode) QMessageBox::information (appl,"information", "Thresholding  is completed");
 		}
 		else
 		{
 			sManager->setProcessState(processId,"50");
 			return;
 		}
 	}


	void filtering_F_Ratio(
		char nameSpace[], 
		char misc[],
		char f_Ratio_File_[],
		char filtered_Pattern1[],
		char filtered_Pattern2[],
		QLabel *textLabel,
		int processId)
	{
		FILE *fp_NameSpace,*fp_Misc,*f_RFP;
		char seq_FileName[400];
		int file_Count;
		bool completeFlag=true;
		if((fp_NameSpace = fopen(nameSpace,"r")) != NULL)
		{
			fscanf(fp_NameSpace,"%d",&file_Count);
			fscanf(fp_NameSpace,"%s",seq_FileName);
			if(file_Count >= 2) // R-Statistic Computation has been run
			{
				fscanf(fp_NameSpace,"%s",seq_FileName);
				if(file_Count > 2) //Thresholding For R-Statistic has also been run
				{
					mainPbc->addAChildProcess(100,"Filtering F-Ratio");
					if((fp_Misc = fopen(misc,"r")) != NULL)
					{
						fscanf(fp_Misc,"%d",&file_Count);
						fscanf(fp_Misc,"%d",&Path_Count);
						fscanf(fp_Misc,"%d",&Total_File);
						fscanf(fp_Misc,"%d",&Total_File);
						fclose(fp_Misc);
						textLabel->setText("Please wait, frequency counting of patterns for all sequences is under processing...");
						mainPbc->addAChildProcess(70,"Computing all file pattern count");
						Compute_All_File_PatternCount(nameSpace,misc);
						mainPbc->deleteLastChildProcess();
						if((f_RFP = fopen(f_Ratio_File_,"r")) != NULL)	
							fclose(f_RFP);
						else
						{
							textLabel->setText("Please wait, F-Ratio calculation is under processing...");
							fRatio_Computation();
							textLabel->setText("F-Ratio Computation Complete");
						}
						mainPbc->addAChildProcess(30,"Calculating F-ratio");
						fRatio_Calculation(filtered_Pattern1,filtered_Pattern2,textLabel,-1,processId);
						mainPbc->deleteLastChildProcess();
					}
				}
				else
				{
					completeFlag = false;
					textLabel->setText("Thresholding for R-statistic has not been completed.\n Go back and run thresholding.");
				}
			}
			else
			{
				completeFlag = false;
				QMessageBox::warning(appl,"warning","R-Statistic computation has not been completed");
			}
			fclose(fp_NameSpace);
		}
		else
		{
			completeFlag = false;
			QMessageBox::warning(appl,"warning","R-Statistic computation has not been completed");
		}
		mainPbc->deleteLastChildProcess();
		mainPbc->pbcReset();
	}
	
	
	
	void analysis_Nearest_Neighbourhood(
		char nameSpace[],
		char misc[],
		char filtered_Pattern1[],
		char filtered_Pattern2[],
		double Gene,
		double NonGene,
		int iteration,
		int inputType) 
	{
		int i;
		int j;
		int sample_GeneCount=0;
		int sample_NonGeneCount=0;
		int frequency_length;
		double Gene_Percentage,NonGene_Percentage;
		FILE *fp,*fp1,*fp_Misc,*fp_Filter,*fp_NameSpace_In,*fp_NameSpace_Out; 
		char seq_FileName[400];
		char FileName[400];
		char PathName[400];
		char Temp_Path[400];
		char query[400];
		char temp_String[400];
		int file_Count1;
		int file_Count2;
		int rec_In_nameSpace;
		QString qtemps("");
		if((fp_NameSpace_In = fopen(nameSpace,"r")) != NULL)
		{
			sprintf(temp_String,"%s/temp_nameSpace.csv",seq_work_dir);
			if((fp_NameSpace_Out = fopen(temp_String,"w")) != NULL) 
			{
				fscanf(fp_NameSpace_In,"%d",&file_Count1);
				if(file_Count1 >= 2) // R-Statistic Computation has been run
				{
					if(file_Count1 > 2) //Thresholding For R-Statistic has also been run
					{
						if((fp_Misc = fopen(misc,"r")) != NULL)
						{
							mainPbc->pbcReset();
							mainPbc->addAChildProcess(100,"Analysing nearest neighbourhood");
							//************* Prepearing ***********************
							//mainPbc->addAChildProcess(10,"Prepearing ...");
							if(mainPbc->wasCanceled()) return;
							//mainPbc->setProgressA(10,100);
							fscanf(fp_Misc,"%d",&file_Count2);
							fscanf(fp_Misc,"%d",&Path_Count);
							fscanf(fp_Misc,"%d",&Total_File);
							fscanf(fp_Misc,"%d",&Total_File);
							rec_In_nameSpace = (Path_Count > 4 ? 10 : 9);
							fprintf(fp_NameSpace_Out,"%d\n",rec_In_nameSpace);
							fscanf(fp_NameSpace_In,"%s",FileName);
							fprintf(fp_NameSpace_Out,"%s\n",FileName);
							fscanf(fp_NameSpace_In,"%s",seq_FileName);
							fprintf(fp_NameSpace_Out,"%s\n",seq_FileName);
							//   ---------------------
							if((fp_Filter=fopen(filtered_Pattern1,"r")) != NULL) //F-Ratio Computation part has been executed
							{
								fscanf(fp_Filter,"%d",&TotalPat_Gen);
								ALL_Patern_Count = (double **)calloc(Total_File,sizeof(double *));
								for(int i = 0; i < Total_File; ++i)
									ALL_Patern_Count[i] = (double *)calloc(TotalPat_Gen,sizeof(double));
								if(mainPbc->wasCanceled()) return;
								//mainPbc->setProgressA(80,100);
								for(int i = 0; i < TotalPat_Gen; ++i)
								{
									for(int j = 0; j < Total_File; ++j) 
										fscanf(fp_Filter,"%lf\t",&ALL_Patern_Count[j][i]);
								}
								fclose(fp_Filter);
								fp_Filter = NULL;
								if(methodType == 2) 
								{
									if((fp_Filter = fopen(filtered_Pattern2,"r")) != NULL)
									{
										fscanf(fp_Filter,"%d",&TotalPat_Small);
										ALL_Patern_Count2 = (double **)calloc(Total_File,sizeof(double *));
										for(int i = 0; i < Total_File; ++i)
											ALL_Patern_Count2[i] = (double *)calloc(TotalPat_Small,sizeof(double));
										for(int i = 0; i < TotalPat_Small; ++i)
										{
											for(int j = 0; j < Total_File; ++j)
												fscanf(fp_Filter,"%lf\t",&ALL_Patern_Count2[j][i]);
										}
										fclose(fp_Filter);
										fp_Filter = NULL;
									}
								}
							All_Pattern_Len = (int *)calloc(Total_File,sizeof(int)); // For storing Length of sequences
							sprintf(temp_String,"%s/Pattern_Len.txt", seq_work_dir);
							fp = fopen(temp_String,"r");
							for(int j = 0; j < Total_File; ++j)
								fscanf(fp,"%d\n",&All_Pattern_Len[j]);
							fclose(fp);
							fp = NULL;
						}
						else //F-Ratio Computation part has been skipped
						{
							Compute_All_File_PatternCount(nameSpace,misc);
							write_method_type();
						}
						//---------------------------------
						fscanf(fp_NameSpace_In,"%s",seq_FileName);
						fprintf(fp_NameSpace_Out,"%s\n",seq_FileName);
						strcpy(poten_Gene_FileName,seq_FileName);
						fscanf(fp_NameSpace_In,"%s",poten_NGene_FileName);
						fprintf(fp_NameSpace_Out,"%s\n",poten_NGene_FileName);
						fscanf(fp_NameSpace_In,"%s",nPoten_Seq_FileName);
						fprintf(fp_NameSpace_Out,"%s\n",nPoten_Seq_FileName);
						if(file_Count1 > 5)
						{
							for(int file_id_Count = 5; file_id_Count < file_Count1; ++file_id_Count)
							{
								fscanf(fp_NameSpace_In,"%s",seq_FileName);
								sprintf(query,"rm %s",seq_FileName);
								system(query);
							}
						}
						fclose(fp_NameSpace_In);///////////////////////////////////
						fscanf(fp_Misc,"%d",&Potential_Gene_Count);
						fscanf(fp_Misc,"%d",&Potential_NonGene_Count);
						fscanf(fp_Misc,"%d",&NonPotential_Sequence_Count);
						fclose(fp_Misc);
						/////////---------------------
						switch(inputType)
						{
							case 1:
								sample_GeneCount = (int) Gene;
								Gene_Percentage = fabs((double)(Gene*100)/(double)Potential_Gene_Count);
								sample_NonGeneCount = (int) NonGene;
								Gene_Percentage = fabs((double)(NonGene*100)/(double)Potential_Gene_Count);
								break;
							case 2:
								Gene_Percentage = Gene;
								sample_GeneCount = (int)fabs(((double)Potential_Gene_Count*Gene)/100.0);
								NonGene_Percentage = NonGene;
								sample_NonGeneCount = (int)fabs(((double)Potential_NonGene_Count*NonGene)/100.0);
								break;
						}
						Result = (char **)malloc(Path_Count * sizeof(char *));
						//////////////////////////////////////////////////////////////
						load_Path(seq_FileName);
						///////////////////////////////////////////////////////////////
						fp1 = fopen(FileName,"r");
						fscanf(fp1,"%s",PathName); // orf
						for(i=0; i < Path_Count; i++)
						{
							if(i == 4)
							{
								fscanf(fp1,"%s", PathName);
								fscanf(fp1,"%s", PathName);
							}
							fscanf(fp1,"%s",PathName);
							Extract_Folder_Name(PathName,Temp_Path);
							Result[i] = (char *)malloc(200*sizeof(char));
							strcpy(Result[i],Temp_Path);
							sprintf(temp_String,"%s/%s/%s",seq_work_dir,curr_Dir,Result[i]);
							strcpy(Result[i],temp_String);
							fprintf(fp_NameSpace_Out,"%s\n",Result[i]);
							fp = fopen(Result[i],"w");
							if(fp)
							{
								if(choice == 1)
									fprintf(fp,"%s\t%s\t%s\t%s\t%s\n","FileName","Prediction(Gene=1, Non-Gene=0, Undecide	d=2)","Prediction Confidence","R-Statistics","Sequence Length"); 
								else
									fprintf(fp,"%s\t%s\t%s\t%s\t%s\n","FileName","Prediction(Gene=1, Non-Gene=0, Undecide	d=2)","Prediction Confidence","P-Value","Sequence Length");
								fclose(fp); fp=NULL;
							}
							else
								{
									qtemps = "Cannot open file :"+QString(Result[i]);
									QMessageBox::warning(appl,"warning", qtemps);
								}
							}
							fclose(fp1);
							fp1=NULL;
							fclose(fp_NameSpace_Out);//////////////////
							sprintf(query,"rm %s",nameSpace);
							system(query);
							sprintf(query,"mv %s/temp_nameSpace.csv %s",seq_work_dir, nameSpace);
							system(query);
							frequency_length = (100-Start_frequency)/interval ;
							Gene_detection_frequency = (int **)malloc(Path_Count*sizeof(int *));
							NonGene_detection_frequency = (int **)malloc(Path_Count*sizeof(int *));
							Undecided = (int *)malloc(Path_Count * sizeof(int));
							Program_Detect_Gene = (int *)malloc(Path_Count*sizeof(int));
							Program_Detect_NonGene = (int *)malloc(Path_Count*sizeof(int));
							for(i=0; i< Path_Count; i++)
							{
								Gene_detection_frequency[i] = (int *)malloc((frequency_length+1) * sizeof(int));
								NonGene_detection_frequency[i] = (int *)malloc((frequency_length+1) * sizeof(int ));
								Undecided[i] = 0;
								for(j=0;j<=frequency_length;j++)
									Gene_detection_frequency[i][j] = NonGene_detection_frequency[i][j] = 0;
								Program_Detect_Gene[i] = Program_Detect_NonGene[i] = 0;
							}
							frequency_value = (double*)malloc((frequency_length+1) * sizeof(double));
							for(i=0;i<frequency_length;i++)
								frequency_value[i] = Start_frequency+(interval*(i+1));
							frequency_value[frequency_length] = Start_frequency+(interval*frequency_length);
							//mainPbc->deleteLastChildProcess();
							//************* Preperation end **********************
							//************************* computation starts ********
							mainPbc->addAChildProcess(100,"Computation started ...");
							analysis_Nearest_Neighbourhood_Computation(nameSpace,misc,iteration,sample_GeneCount,sample_NonGeneCount);
							free_MemForAll_Pattern_Count();
							mainPbc->deleteLastChildProcess();
							//************************computation ends *************
							for( i=0; i< Path_Count; i++)
							{
								fp1 = fopen(Result[i],"a+");
								fprintf(fp1,"\n\n Total Predicted Genes = %d",Program_Detect_Gene[i]);
								fprintf(fp1,"\n Total Predicted Non-Genes = %d",Program_Detect_NonGene[i]);
								fprintf(fp1,"\n\n Prediction Confidence in %\tFrequency of Predicted Genes\tFrequency of Predicted Non-Genes\n");
								fprintf(fp1," (%-3.0f , %3.0f)\t%d\t%d\n",frequency_value[0]-interval,frequency_value[0],Gene_detection_frequency[i][0],NonGene_detection_frequency[i][0]);
								for(j=1; j<frequency_length; j++)
									fprintf(fp1," [%-3.0f , %3.0f)\t%d\t%d\n",frequency_value[j]-interval,frequency_value[j],Gene_detection_frequency[i][j],NonGene_detection_frequency[i][j]);
								fprintf(fp1,"%.0f\t%d\t%d\n",frequency_value[frequency_length],Gene_detection_frequency[i][frequency_length],NonGene_detection_frequency[i][frequency_length]);
								fprintf(fp1,"\n\n%s %d\n","Undecided Cases( 50% Prediction Confidence ) = ",Undecided[i]);
								fclose(fp1); 
								fp1=NULL;
							}
							Free_Allocated_Memory();
							if(!mainPbc->pbcWasCanceled())
							{
								mainPbc->pbcReset();
								if(interactiveMode) QMessageBox::information(appl,"Information","Nearest Neigbour Analysis completed successfully");	
							}
						}
					}
					else
					{
						fclose(fp_NameSpace_In);
						fclose(fp_NameSpace_Out);
						sprintf(temp_String,"rm %s/temp_nameSpace.csv",seq_work_dir);
						system(temp_String);
						QMessageBox::warning(appl,"warning","Thresolding for R-Statistic has not been completed");
					}
				}
				else
				{
					fclose(fp_NameSpace_In);
					fclose(fp_NameSpace_Out);
					sprintf(temp_String, "rm %s/temp_nameSpace.csv",seq_work_dir);
					system(temp_String);
					QMessageBox::warning(appl,"warning","R-Statistic computation has not been completed");
				}
			}		
     		}
   		else
    		 {
  			QMessageBox::warning(appl,"warning","R-Statistic computation has not been completed");

    		 }
  		mainPbc->deleteLastChildProcess();
 	}



	void houskipping_abnormal_termination_nearest_neighbour()
	{
	
		free_MemForAll_Pattern_Count();
		Free_Allocated_Memory();
		
	}
	

		
	void remove_Record_Files(char nameSpace[],char misc[],char f_Ratio_File[], char filtered_Pattern[])
	{
	
		char query[400];
		sprintf(query,"rm -r %s",curr_Dir);
		system(query);
		delete_nameSpace(nameSpace);
		delete_misc(misc);
		delete_F_Ratio(f_Ratio_File);
		delete_Filtered_Pattern(filtered_Pattern);
	}
	
	
	
	bool change_Directory( char * currentDirectory)
	{
	
		char query[400];
		DIR *dir;
		strcpy(curr_Dir, currentDirectory);
		if((dir = opendir(curr_Dir)) != NULL)
		{
		
			if(check_nameSpace_File(nameSpace[0])==1)
			{
			
				QMessageBox mb("Prediction ", "Directory "+ QString(curr_Dir)+ " already  exist.\n If you use this folder it's previous records will be deleted.\n Do you want to continue ?",
				QMessageBox::Question,
				QMessageBox::Yes|QMessageBox::Default,
				QMessageBox::No |QMessageBox:: Escape,
				QMessageBox::NoButton);
				
				if(mb.exec() == QMessageBox::Yes)
				{
				
					remove_Record_Files(nameSpace[0],misc[0],f_Ratio_File[0],filtered_Pattern[0]);
					
				}
				
				else
				return false;
				
			}
			else if(check_nameSpace_File(nameSpace[1])==1)
			{
			
				QMessageBox mb("Prediction ", "Directory" + QString(curr_Dir) +" already exist.\n If you use this folder it's previous records will be deleted.\n Do you want to continue ?",
				QMessageBox::Question, 
				QMessageBox::Yes|QMessageBox::Default,
				QMessageBox::No |QMessageBox:: Escape,
				QMessageBox::NoButton);
				if(mb.exec() == QMessageBox::Yes)
				{
				
					remove_Record_Files(nameSpace[1],misc[1],f_Ratio_File[1],filtered_Pattern[1]);
					
				} else return false;
				
			}
			
		}
		
		sprintf(query,"mkdir %s",curr_Dir);
		system(query);
		return true;
	}



	void load_Path(char *FileName)
	{
		char *token;
		searchToken('/',2,&token,FileName);
		strcpy(curr_Dir,token);
		free(token);
		fetch_Current_Dir();
	}
	
	
	
	void fetch_Current_Dir()
	{
		FILE *fp;
		system("pwd > working_Dir.csv");
		fp = fopen("working_Dir.csv","r");
		if(fp != NULL)
		{
			fscanf(fp,"%s",work_Dir_File_Path);
			fclose(fp);
			fp = NULL;
			remove("working_Dir.csv");
		}
	}



	int check_nameSpace_File(char nameSpace[])
	{
		FILE *fp_nameSpace;
		int file_Count,return_Val;
		char seq_FileName[400];
		
		if((fp_nameSpace = fopen(nameSpace,"r")) != NULL)
		{
			fscanf(fp_nameSpace,"%d",&file_Count);
			fscanf(fp_nameSpace,"%s",seq_FileName);
			fscanf(fp_nameSpace,"%s",seq_FileName);
			char *token1, *token2;
			token1=(char *)malloc(sizeof(char)*50);
			token2=(char *)malloc(sizeof(char)*50);
			searchToken('/',2,&token1,seq_FileName);
			searchToken('/',2,&token2,curr_Dir);
			if(strcmp(token1,token2) == 0) return_Val = 1;
			else
			return_Val = 0;
			free(token1);
			free(token2);
			fclose(fp_nameSpace);
		}
		else
		return_Val = 0;
		return return_Val;
	}
	
	
	
	void searchToken(char delim,int Occurance, char **token, char *string)
	{
		int i,j,occur = 1,str,stp;
		stp = strlen(string)-1;
		for(i=stp; i>=0; --i)
		{
			if(string[i] == delim)
			{
				if(occur == Occurance)	break;
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
	
	
	
	
	void delete_nameSpace(char nameSpace[])
	{
		FILE *fp_check;
		char query[400];
		if((fp_check = fopen(nameSpace,"r")) != NULL)
		{
			fclose(fp_check);
			fp_check = NULL;
			sprintf(query,"rm %s",nameSpace);
			system(query);
		}
	}

	
	
	void delete_misc(char misc[])
	{
		FILE *fp_check;
		char query[400];
		if((fp_check = fopen(misc,"r")) != NULL)
		{
			fclose(fp_check);
			fp_check = NULL;
			sprintf(query,"rm %s",misc);
			system(query);
		}
	}
	
	
	
	
	void delete_F_Ratio(char f_Ratio_File[])
	{
		FILE *fp_check;
		char query[400];
		if((fp_check = fopen(f_Ratio_File,"r")) != NULL)
		{
			fclose(fp_check);
			fp_check = NULL;
			sprintf(query,"rm %s",f_Ratio_File);
			system(query);
		}
	}
	
	
	
	
	void delete_Filtered_Pattern(char filtered_Pattern[])
	{
		FILE *fp_check;
		char query[400];
		if((fp_check = fopen(filtered_Pattern,"r")) != NULL)
		{
			fclose(fp_check);
			fp_check = NULL;
			sprintf(query,"rm %s",filtered_Pattern);
			system(query);
		}
	}
	
	
	
	
	void write_method_type()
	{
		char T_Path[400];
		QString tmps;
		FILE *fp;
		// set default methodType to 1  i.e. tri 
		if(choice==1)
		{
			tmps=paramMg->getValueById("140"); // the RStat result folder reference
			sprintf(T_Path,"%s/%s/methodType.txt",seq_work_dir,(const char *)tmps);
		} else
		{
			// similarly to R-stat to be implemented by id
			tmps=paramMg->getValueById("670");
			sprintf(T_Path,"%s/%s/methodType.txt",seq_work_dir, (const char *)tmps);
		}
		fp=fopen(T_Path,"w");
		fprintf(fp, "%d", methodType);
		fclose(fp);
	}
