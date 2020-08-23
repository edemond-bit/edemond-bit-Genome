#include "orf.h"

void ORF::setMaxLen(int i)
{
  maxLen = i;
}
void ORF::setMinLen(int i)
{
  minLen = i;
}
void ORF::setFilterSequence_wrt(int i)
{
  filter_Option = i;

}
void ORF::saveIntermediateData_toFile(bool b)
{
  if(b){
    storeIn_File='Y';
  }else {
    storeIn_File='N';
  }
}
void ORF::setOption(int i)
{
  option = i; 

}
void ORF::setStartCodons(char *scodon)
{
  numStartCodon =0;
  char tmp[20];
  int lc=0;
  int j=0;

  startCodon = (char **)calloc(1,sizeof(char**));
  while(true){ 

    if(scodon[lc] !=' '){
      if(scodon[lc] == ',' || scodon[lc]=='\0'){
 tmp[j] ='\0';
 if(numStartCodon>0)
   {
     register void *value = (char **)realloc(startCodon, numStartCodon+1);

     if(value ==0){
       printf("Out of memory");
     }

   }
 startCodon[numStartCodon]=(char *)calloc(j+2, sizeof(char *));
 startCodon[numStartCodon] = strcpy(startCodon[numStartCodon],tmp);
 //printf("\n startcodon %s %d", startCodon[numStartCodon], numStartCodon);
 numStartCodon++;
 j=0;

     } else {
 tmp[j++] = scodon[lc];
      }
    } 

    if(scodon[lc]=='\0') break;
    lc++;
 
}
  //printf("\n ********** startcodon = %s",startCodon[0]);
  //for(j=0;j<numStartCodon;j++)
    //printf(" \n>>>  %s %d",startCodon[j],j);

}


void ORF::setStopCodons(char *scodon)
{
  numStopCodon =0;
  char tmp[20];
  int lc=0;
  int j=0;
  stopCodon = (char **)calloc(1,sizeof(char**));
  while(true){
    if(scodon[lc] !=' '){
      if(scodon[lc] == ',' || scodon[lc]=='\0'){
 tmp[j] ='\0';
 if(numStopCodon>0)
   {
     register void *value = (char **)realloc(stopCodon, numStopCodon+1);
     
     if(value ==0){
       printf("Out of memory");
     }
     
   }
 stopCodon[numStopCodon]=(char *)calloc(j+2, sizeof(char *));
 stopCodon[numStopCodon] = strcpy(stopCodon[numStopCodon],tmp);
 numStopCodon++;

 j=0;
      } else {
 tmp[j++] = scodon[lc];
      }
    } 
    if(scodon[lc] =='\0') break;
    lc++;
  }
  //for(j=0;j<numStopCodon;j++)
   // printf("\n>>> stop condon(%s)",stopCodon[j]);
}





void ORF::openPath(char *Path){
  FILE *fp;

  fp = fopen(Path,"r");
  if(fp != NULL)
    {
      scanVal = fscanf(fp,"%s",path_Seq);
    }
  fclose(fp);
	
}
void ORF::readInBuf_GUI()
{
  readInBuf();
}
char * ORF::frequencyOfElements()
{
  char *reternstr = (char *) malloc(250*sizeof(char *));
  char tmp[] ="";
  reternstr=strcpy(reternstr,tmp);
  addString(reternstr,"Occurance of A=");
  itoa(A,tmp);
  addString(reternstr,tmp);

  addString(reternstr,",\t T=");
  itoa(T,tmp);
  addString(reternstr,tmp);


  addString(reternstr,",\t C=");
  itoa(C,tmp);
  addString(reternstr,tmp);

  addString(reternstr,",\t G=");
  itoa(G,tmp);
  addString(reternstr,tmp);

  addString(reternstr,",\t N=");
  itoa(N,tmp);
  addString(reternstr,tmp);
  addString(reternstr,",\t R=");
  itoa(R,tmp);
  addString(reternstr,tmp);

  addString(reternstr,",\t W=");
  itoa(W,tmp);
  addString(reternstr,tmp);

  addString(reternstr,",\t Y=");
  itoa(Y,tmp);
  addString(reternstr,tmp);

  addString(reternstr,",\t M=");
  itoa(M,tmp);
  addString(reternstr,tmp);

  addString(reternstr,",\t K=");
  itoa(K,tmp);
  addString(reternstr,tmp);


  addString(reternstr,",\t S=");
  itoa(S,tmp);
  addString(reternstr,tmp);

  addString(reternstr,",\t H=");
  itoa(H,tmp);
  addString(reternstr,tmp);

  addString(reternstr,",\t B=");
  itoa(B,tmp);
  addString(reternstr,tmp);


  addString(reternstr,",\t V=");
  itoa(V,tmp);
  addString(reternstr,tmp);


  addString(reternstr,",\t D=");
  itoa(D,tmp);
  addString(reternstr,tmp);
  return reternstr;

  //		cout << "\nOccurances of A = " << A << " T = " << T << " C = " << C << " G = " << G << endl;
  //		cout << "              N = " << N << " R = " << R << " W = " << W << " Y = " << Y << endl;
  //		cout << "              M = " << M << " K = " << K << " S = " << S << " H = " << H << endl;
  //		cout << "              B = " << B << " V = " << V << " D = " << D << endl;
}

void ORF::addString(char *s, const char *cs){
  char *tmp=(char *)malloc(10*sizeof(char *));
  tmp = strcpy(tmp, cs);
  s=strcat(s, tmp);
}


void ORF::itoa(int n, char s[]){
  int i, sign;
  if((sign = n) <0) n=-n;
  i=0;
  do{
    s[i++] = n%10 + '0';

  } while((n/=10)>0);
  if(sign <0) s[i++] = '-';
  s[i]='\0';
  reverse(s);
}
void ORF::reverse(char *s)
{
  int c,i,j;
  for(i=0,j=strlen(s)-1;i<j;i++,j--){
    c=s[i];
    s[i]=s[j];
    s[j] =c;
  }
}
void ORF::setAppParameters(pbc *tmainPbc, statusManager *sManager){
  
  // progressBar = pb;
  // progressText = pt;
  this->mainPbc = tmainPbc;
  this->sManager = sManager;
  
}
void ORF::executeProcess(char *seq_work_dir){

  _seq_work_dir = (char *)calloc(200,sizeof(char*));
  _seq_work_dir = strcpy(_seq_work_dir, seq_work_dir);
  //printf("\n ================ seq_work_dir = %s", _seq_work_dir);
  this->sManager->setProcessState(1,"10");
  mainPbc->pbcReset();
  mainPbc->addAChildProcess(100,"ORF computation... ");
  /*for( i=0;i<numStartCodon;i++) 
    printf("\n start codons: %s", startCodon[i]);  
  for(i=0;i<numStopCodon;i++) 
    printf("\n stop codons: %s", stopCodon[i]);  

 */
 
  if(!mainPbc->addAChildProcess(10,"Reverse complement computation")) return;

  reverse_complement_of_Sequence();

  mainPbc->deleteLastChildProcess();
  
  if(!mainPbc->addAChildProcess(90,"Orf Computation started...")) return;
  initiateProcess();
  
  mainPbc->deleteLastChildProcess(); 
  
  free(forward_Genome);
  free(reverse_Genome);
  
  mainPbc->deleteLastChildProcess();
  if(mainPbc->pbcWasCanceled()){
    this->sManager->setProcessState(1,"20");
  }else{
    this->sManager->setProcessState(1,"100");
  }
  mainPbc->pbcReset();

}


////////////////////////////////////////////////Main data processing Functions/////////////////////////////////////////////////////////////
void ORF::initiateProcess()
{
  char query[400],prime_File[400],tempDir[400];
  DIR *dir;
  FILE *gp;
   int startCodonIterator;
  //------------Creation of necessary files and directory/s-------------------------------
  char *token1,*token2;
  char path_orf[400];

  searchChar('/',1,&token1,path_Seq);
  searchChar('.',2,&token2,token1);
  strcpy(seq_Name,token2);
  searchChar('/',2,&token1,path_Seq);
  free(token2);


  


  sprintf(prime_File,"%s/orf_data/%s",_seq_work_dir,seq_Name); 
 // printf("\n -----------------------%s  ---\n",prime_File);
  free(token1);



  sprintf(tempDir,"%s/orf_data",_seq_work_dir);
  if((dir = opendir(tempDir)) != NULL)
    {
      printf( "\n %s this path exist! \nDepending on the size of the destination folder program may take few seconds to romove the destination folder and it's contents\n", tempDir);
      sprintf(query,"rm -r %s",tempDir);
      system(query);
    }
  sprintf(query,"mkdir %s",tempDir);
  system(query);
 
       
 
  //Prime = NEGATIVE;
  sprintf(path_orf,"%s/path_ORF",_seq_work_dir);
  // gp = fopen("path_ORF","w");
  gp = fopen(path_orf,"w");

  fprintf(gp,"%s\n",path_Seq);
  if(storeIn_File == 'Y')
    {
      curr_Dir = (char **)calloc(4,sizeof(char *));
      for(int i = 0; i < 4; ++i)
         curr_Dir[i] = (char *)calloc(200,sizeof(char));
     
      sprintf(curr_Dir[0],"%s_ORF%c/",prime_File,'+'); //For Positive ORF
      sprintf(query,"mkdir %s",curr_Dir[0]);
      system(query);
     
      sprintf(curr_Dir[1],"%s_NORF%c/",prime_File,'+'); //For Positve NON-ORF
      sprintf(query,"mkdir %s",curr_Dir[1]);
      system(query);
     
      sprintf(curr_Dir[2],"%s_ORF%c/",prime_File,'-'); //For Negative ORF
      sprintf(query,"mkdir %s",curr_Dir[2]);
      system(query);
     
      sprintf(curr_Dir[3],"%s_NORF%c/",prime_File,'-'); //For Negative NON-ORF
      sprintf(query,"mkdir %s",curr_Dir[3]);
      system(query);
       
    }
 
  //update (calloc and for range from 4 to 6)
  record_FileName = (char **)calloc(6,sizeof(char *));
  for(int i = 0; i < 6; ++i)
    record_FileName[i] = (char *)calloc(200,sizeof(char));
 
  sprintf(record_FileName[0],"%s_ORF%c.csv",prime_File,'+');
  sprintf(record_FileName[1],"%s_NORF%c.csv",prime_File,'+');
  sprintf(record_FileName[2],"%s_ORF%c.csv",prime_File,'-');
  sprintf(record_FileName[3],"%s_NORF%c.csv",prime_File,'-');
  sprintf(record_FileName[4],"%s_tempNORF+.csv",prime_File);
  sprintf(record_FileName[5],"%s_tempNORF-.csv",prime_File);


  for(int i = 0; i <4; ++i)
    fprintf(gp,"%s\n",record_FileName[i]);
  fclose(gp);
  gp = NULL;
   
  if(!mainPbc->addAChildProcess(40,"Reading frame from both strand 1")) return;
  
 readFrameFromBothStrand(0);
 mainPbc->deleteLastChildProcess();
 startCodonIterator = 1;
  if(!mainPbc->addAChildProcess(40,"Reading frame from both strand 2")) return;
 while(startCodonIterator < numStartCodon)
 {
  readFrameFromBothStrand2(startCodonIterator);
  ++startCodonIterator;
  if(mainPbc->pbcWasCanceled()) break;
	mainPbc->setProgressA(startCodonIterator,genomeLength);
	mainPbc->updateProgress();
   
 }

  mainPbc->deleteLastChildProcess();
  // printf(" \n Reading frame from both strand 1 complete:");
  //update
  //if(!mainPbc->addAChildProcess(40,"Reading frame from both strand 1-2")) return;
  // readFrameFromBothStrand2();
 //  mainPbc->deleteLastChildProcess();
   //printf(" \n Reading frame from both strand 1-2 complete:");
  for(int i = 0; i < 2; ++i)
    sort_ORF_List_File(record_FileName[i],1,2,3);
  
  for(int i = 2; i < 4; ++i)
    sort_ORF_List_File(record_FileName[i],2,2,3);


  if(filter_Option == 1)
    {

  if(!mainPbc->addAChildProcess(10,"filtering with respect to longest ORF")) return;
      filtering_W_R_T_Longest_ORF();
  mainPbc->deleteLastChildProcess();
    }
  else if(filter_Option == 2){
  
  printf("\nfiltering_W_R_T_best_R_Value\n");
if(!mainPbc->addAChildProcess(10,"filtering with respect to best R-value")) return;
mainPbc->updateProgress();
    filtering_W_R_T_best_R_Value();
  mainPbc->deleteLastChildProcess();
  }
  for(int i = 0; i < 4; ++i)
    sort_ORF_List_File(record_FileName[i],0,2,-1);

  
}

void ORF::readFrameFromBothStrand(int startCodonIndex)
{
	FILE *fp1,*fp2,*fp3,*fp4;
	int count; 
	char codon[4];
	int Iterator;
	int startIndx,stopIndx; //For + ORF
	int startIndex,stopIndex; //For - ORF
	int maxStopIndx[2]; //max stop index value

	
	fp1 = fopen(record_FileName[0],"a");
	fp2 = fopen(record_FileName[1],"a");
	fp3 = fopen(record_FileName[2],"a");
	fp4 = fopen(record_FileName[3],"a");
	
	startIndex = 0;
	stopIndex = 0;
	startIndx = 0;
	stopIndx = 0;
	maxStopIndx[0] = 1;
	maxStopIndx[1] = 0;
	
	for(int Pivot = 0; Pivot < genomeLength - 5; ++Pivot)
	{
	 if(Pivot%100==0){
	if(mainPbc->pbcWasCanceled()) break;
	mainPbc->setProgressA(Pivot,genomeLength);
	mainPbc->updateProgress();
      }
		///////////////////////////////////For Forward Strand
		Iterator = Pivot;
		//////////////////////////Search for Start CODON(5' ---> 3')
		count = 0;
		while(count < 3 && Iterator < genomeLength)
			codon[count++] = forward_Genome[Iterator++];
		codon[3] = '\0';
		
		if(match_ORF_StartCodon(codon,startCodonIndex))
		{
			startIndx = Iterator - 2; //////////////Actual Start Co-ordinate
			/////////////////////Search for Stop CODON
			while(Iterator < genomeLength - 2)
			{
				count = 0;
				while(count < 3 && Iterator < genomeLength)
					codon[count++] = forward_Genome[Iterator++];
				codon[3] = '\0';
				
				if(match_ORF_StopCodon(codon))
				{
					stopIndx = Iterator; //////////////Actual Stop Co-ordinate
					seq_Length = (stopIndx - startIndx) + 1;
					//===================== 
					while((Iterator < genomeLength - 2) && (seq_Length%3 != 0))
					{
      				/////////////////////Search for Stop CODON
     				   count = 0;
      				while(count < 3 && Iterator < genomeLength)
       							codon[count++] = forward_Genome[Iterator++];
      				codon[3] = '\0';
      
      				if(match_ORF_StopCodon(codon))
      				{
       					stopIndx = Iterator; //////////////Actual Stop Co-ordinate
       					seq_Length = (stopIndx - startIndx) + 1;
      				}
     				}
     				
     				if(seq_Length%3 == 0)
     				{
      				if(option == 1 || (option == 2 && (seq_Length >= minLen && seq_Length <= maxLen)))
      				{
       					sprintf(seq_Path,"%s_%d%c%d",seq_Name,startIndx,'+',stopIndx);
       					fprintf(fp1,"%s\t%d\t%d\n",seq_Path,stopIndx,seq_Length);
       					if(storeIn_File == 'Y')
        						record_ORF_PositiveStrand(startIndx - 1,stopIndx - 1,curr_Dir[0]); //record orf from Positive strand
      				}
      				//////////////////////Record Non-ORF
      				seq_Length = startIndx - maxStopIndx[0];
      				if(seq_Length > 0)
      				{
      					if(option == 1 || ((option == 2) && (seq_Length >= minLen && seq_Length <= maxLen)))
       					{
        						sprintf(seq_Path,"%s_%d%c%d",seq_Name,maxStopIndx[0],'+',startIndx - 1); 
        						fprintf(fp2,"%s\t%d\t%d\n",seq_Path,startIndx - 1,seq_Length);
								if(storeIn_File == 'Y')
									record_ORF_PositiveStrand(maxStopIndx[0] - 1,startIndx - 2,curr_Dir[1]); //record Non-orf from Positive strand
							}
						}
						maxStopIndx[0] = (stopIndx >= maxStopIndx[0] ? stopIndx + 1 : maxStopIndx[0]); // Actual Index
					}
					break;
				}
			}
		}
		////////////////////////////////////For Reverse Strand(3' ---> 5')
		Iterator = Pivot;
		//////////////////////////Search for Start CODON
		count = 0;
		while(count < 3 && Iterator < genomeLength)
			codon[count++] = reverse_Genome[Iterator++];
		codon[3] = '\0';
		
		if(match_ORF_StartCodon(codon,startCodonIndex))
		{
			startIndex = Iterator - 3; //////////////Actual Start Co-ordinate - 1
			/////////////////////Search for Stop CODON
			while(Iterator < genomeLength - 2)
			{
				count = 0;
				while(count < 3 && Iterator < genomeLength)
					codon[count++] = reverse_Genome[Iterator++];
				codon[3] = '\0';
				
				if(match_ORF_StopCodon(codon))
				{
					stopIndex = Iterator - 1; //////////////Actual Stop Co-ordinate - 1
					seq_Length = (stopIndex - startIndex) + 1;
					while((Iterator < genomeLength - 2) && (seq_Length%3 != 0))
     {
      /////////////////////Search for Stop CODON
      count = 0;
      while(count < 3 && Iterator < genomeLength)
       codon[count++] = reverse_Genome[Iterator++];
      codon[3] = '\0';
      if(match_ORF_StopCodon(codon))
      {
       stopIndex = Iterator - 1; //////////////Actual Stop Co-ordinate - 1
       seq_Length = (stopIndex - startIndex) + 1;
      }
     }
     if(seq_Length%3 == 0)
     {
      if(option == 1 || (option == 2 && (seq_Length >= minLen && seq_Length <= maxLen)))
      {
       sprintf(seq_Path,"%s_%d%c%d",seq_Name,genomeLength - startIndex,'-',genomeLength - stopIndex);
       fprintf(fp3,"%s\t%d\t%d\n",seq_Path,genomeLength - stopIndex,seq_Length);
       if(storeIn_File == 'Y')
        record_ORF_NegativeStrand(startIndex,stopIndex,curr_Dir[2]); //record orf from Negative strand
      }
      //////////////////////Record Non-ORF
      seq_Length = startIndex - maxStopIndx[1];
      if(seq_Length > 0)
      {
       if(option == 1 || ((option == 2) && (seq_Length >= minLen)))
       {
        sprintf(seq_Path,"%s_%d%c%d",seq_Name,genomeLength - maxStopIndx[1],'-',genomeLength - (startIndex - 1));
        fprintf(fp4,"%s\t%d\t%d\n",seq_Path,genomeLength - (startIndex - 1),seq_Length);
        if(storeIn_File == 'Y')
         record_ORF_NegativeStrand(maxStopIndx[1],startIndex - 1,curr_Dir[3]); //record Non-orf from Negative strand
       }
      }
      maxStopIndx[1] = (stopIndex >= maxStopIndx[1] ? stopIndex + 1 : maxStopIndx[1]); //Actual Index - 1
     }
     break;
    }
   }
  }
 }
 
 if(maxStopIndx[0] < genomeLength)
 {
  seq_Length = (genomeLength - maxStopIndx[0]) + 1;
  if(seq_Length > 0)
  {
   if(option == 1 || ((option == 2) && (seq_Length >= minLen)))
   {
    sprintf(seq_Path,"%s_%d%c%d",seq_Name,maxStopIndx[0],'+',genomeLength);
    fprintf(fp2,"%s\t%d\t%d\n",seq_Path,genomeLength,seq_Length);
    if(storeIn_File == 'Y')
     record_ORF_PositiveStrand(maxStopIndx[0] - 1,genomeLength - 1,curr_Dir[1]); //record Non-orf from Positive strand
   }
  }
 }
 
 if(maxStopIndx[1] + 1 < genomeLength)
 {
  seq_Length = genomeLength - maxStopIndx[1];
  if(seq_Length > 0)
  {
   if(option == 1 || ((option == 2) && (seq_Length >= minLen)))
   {
    sprintf(seq_Path,"%s_%d%c%d",seq_Name,genomeLength - maxStopIndx[1],'-',1);
    fprintf(fp4,"%s\t%d\t%d\n",seq_Path,1,seq_Length);
    if(storeIn_File == 'Y')
					record_ORF_NegativeStrand(maxStopIndx[1],genomeLength - 1,curr_Dir[3]); //record Non-orf from Negative strand
			}
		}
	}	
		
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
	fclose(fp4);
	fp1 = fp2 = fp3 = fp4 = NULL;
}


void ORF::readFrameFromBothStrand2(int startCodonIndex)
{
	FILE *gp1,*gp2,*fp1,*fp2,*fp3,*fp4;
	int count,size; 
	char codon[4],FName[400],tempFName[400],str[500];
	int Iterator;
	int startNORF,stopNORF;
	int startIndx,stopIndx; //For + ORF
	int startIndex,stopIndex; //For - ORF
	int maxStopIndx[2]; //max stop index value
	
	gp1 = fopen(record_FileName[1],"r");
	gp2 = fopen(record_FileName[3],"r");
	fp1 = fopen(record_FileName[0],"a");
	fp2 = fopen(record_FileName[4],"w");
	fp3 = fopen(record_FileName[2],"a");
	fp4 = fopen(record_FileName[5],"w");
		
	strcpy(tempFName,"NULL");
	while(!feof(gp1))
	{
		fscanf(gp1,"%s\t%d\t%d",FName,&stopNORF,&size);
		if(strcmp(tempFName,FName) == 0)
			break;
		strcpy(tempFName,FName);
		Extract_Index(FName,startNORF,stopNORF,'+');
		startIndex = 0;
		stopIndex = 0;
		startIndx = 0;
		stopIndx = 0;
		maxStopIndx[0] = startNORF;
				
		for(int Pivot = startNORF - 1; Pivot < stopNORF - 5; ++Pivot)
		{
			///////////////////////////////////For Forward Strand
			Iterator = Pivot;
			//////////////////////////Search for Start CODON(5' ---> 3')
			count = 0;
			while(count < 3 && Iterator < stopNORF)
				codon[count++] = forward_Genome[Iterator++];
			codon[3] = '\0';
	
			if(match_ORF_StartCodon(codon, startCodonIndex))
			{
				startIndx = Iterator - 2; //////////////Actual Start Co-ordinate
				/////////////////////Search for Stop CODON
				while(Iterator < stopNORF - 2)
				{
					count = 0;
					while(count < 3 && Iterator < stopNORF)
						codon[count++] = forward_Genome[Iterator++];
					codon[3] = '\0';
				
					if(match_ORF_StopCodon(codon))
					{
						stopIndx = Iterator; //////////////Actual Stop Co-ordinate
						seq_Length = (stopIndx - startIndx) + 1;
      while((Iterator < stopNORF - 2) && (seq_Length%3 != 0))
      {   
       count = 0;
       while(count < 3 && Iterator < stopNORF)
        codon[count++] = forward_Genome[Iterator++];
       codon[3] = '\0';
       if(match_ORF_StopCodon(codon))
       {
        stopIndx = Iterator; //////////////Actual Stop Co-ordinate
        seq_Length = (stopIndx - startIndx) + 1;
       }
      }
      if(seq_Length%3 == 0)
      {
       if(option == 1 || (option == 2 && (seq_Length >= minLen && seq_Length <= maxLen)))
       {
        sprintf(seq_Path,"%s_%d%c%d",seq_Name,startIndx,'+',stopIndx);
        fprintf(fp1,"%s\t%d\t%d\n",seq_Path,stopIndx,seq_Length);
        if(storeIn_File == 'Y')
         record_ORF_PositiveStrand(startIndx - 1,stopIndx - 1,curr_Dir[0]); //record orf from Positive strand
       }
       //////////////////////Record Non-ORF
       seq_Length = startIndx - maxStopIndx[0];
       if(seq_Length > 0)
       {
        if(option == 1 || ((option == 2) && (seq_Length >= minLen)))
        {
         sprintf(seq_Path,"%s_%d%c%d",seq_Name,maxStopIndx[0],'+',startIndx - 1); 
         fprintf(fp2,"%s\t%d\t%d\n",seq_Path,startIndx - 1,seq_Length);
         if(storeIn_File == 'Y')
          record_ORF_PositiveStrand(maxStopIndx[0] - 1,startIndx - 2,curr_Dir[1]); //record Non-orf from Positive strand
        }
       }
       maxStopIndx[0] = (stopIndx >= maxStopIndx[0] ? stopIndx + 1 : maxStopIndx[0]); //Actual Co-ordinate
      }
      break;
     }
    }
   }
  }
  if(maxStopIndx[0] < stopNORF)
  {
   seq_Length = (stopNORF - maxStopIndx[0]) + 1;
   if(seq_Length > 0)
   {
    if(option == 1 || ((option == 2) && (seq_Length >= minLen)))
    {
     sprintf(seq_Path,"%s_%d%c%d",seq_Name,maxStopIndx[0],'+',stopNORF);
     fprintf(fp2,"%s\t%d\t%d\n",seq_Path,stopNORF,seq_Length);
					if(storeIn_File == 'Y')
						record_ORF_PositiveStrand(maxStopIndx[0] - 1,stopNORF - 1,curr_Dir[1]); //record Non-orf from Positive strand
				}
			}
		}
	}
	fclose(gp1);
	gp1 = NULL;
	
	strcpy(tempFName,"NULL");
	while(!feof(gp2))
	{
		fscanf(gp2,"%s\t%d\t%d",FName,&stopNORF,&size);
		if(strcmp(tempFName,FName) == 0)
			break;
		strcpy(tempFName,FName);
		Extract_Index(FName,startNORF,stopNORF,'-');
		startNORF = (genomeLength - startNORF) + 1;
		stopNORF = (genomeLength - stopNORF) + 1;
		startIndex = 0;
		stopIndex = 0;
		startIndx = 0;
		stopIndx = 0;
		maxStopIndx[1] = startNORF - 1;
		
		for(int Pivot = startNORF - 1; Pivot < stopNORF - 5; ++Pivot)
		{
			////////////////////////////////////For Reverse Strand(3' ---> 5')
			Iterator = Pivot;
			//////////////////////////Search for Start CODON
			count = 0;
			while(count < 3 && Iterator < stopNORF)
				codon[count++] = reverse_Genome[Iterator++];
			codon[3] = '\0';
			
			if(match_ORF_StartCodon(codon,startCodonIndex))
			{
				startIndex = Iterator - 3; //////////////Actual Start Co-ordinate - 1
				/////////////////////Search for Stop CODON
				while(Iterator < stopNORF - 2)
				{
					count = 0;
					while(count < 3 && Iterator < stopNORF)
						codon[count++] = reverse_Genome[Iterator++];
					codon[3] = '\0';
				
					if(match_ORF_StopCodon(codon))
					{
						stopIndex = Iterator - 1; //////////////Actual Stop Co-ordinate - 1
						seq_Length = (stopIndex - startIndex) + 1;
      while((Iterator < stopNORF - 2) && (seq_Length%3 != 0))
      {
       count = 0;
       while(count < 3 && Iterator < stopNORF)
        codon[count++] = reverse_Genome[Iterator++];
       codon[3] = '\0';
       if(match_ORF_StopCodon(codon))
       {
        stopIndex = Iterator - 1; //////////////Actual Stop Co-ordinate - 1
        seq_Length = (stopIndex - startIndex) + 1;
       }
      }
      if(seq_Length%3 == 0)
      {
       if(option == 1 || (option == 2 && (seq_Length >= minLen && seq_Length <= maxLen)))
       {
        sprintf(seq_Path,"%s_%d%c%d",seq_Name,genomeLength - startIndex,'-',genomeLength - stopIndex);
        fprintf(fp3,"%s\t%d\t%d\n",seq_Path,genomeLength - stopIndex,seq_Length);
        if(storeIn_File == 'Y')
         record_ORF_NegativeStrand(startIndex,stopIndex,curr_Dir[2]); //record orf from Negative strand
       }
       //////////////////////Record Non-ORF
       seq_Length = startIndex - maxStopIndx[1];
       if(seq_Length > 0)
       {
        if(option == 1 || ((option == 2) && (seq_Length >= minLen)))
        {
         sprintf(seq_Path,"%s_%d%c%d",seq_Name,genomeLength - maxStopIndx[1],'-',genomeLength - (startIndex - 1));
         fprintf(fp4,"%s\t%d\t%d\n",seq_Path,genomeLength - (startIndex - 1),seq_Length);
         if(storeIn_File == 'Y')
          record_ORF_NegativeStrand(maxStopIndx[1],startIndex - 1,curr_Dir[3]); //record Non-orf from Negative strand
        }
       }
       maxStopIndx[1] = (stopIndex >= maxStopIndx[1] ? stopIndex + 1 : maxStopIndx[1]); //Actual Co-ordinate - 1
      }
      break;
     }
    }
   }
  }
  if(maxStopIndx[1] + 1 < stopNORF)
  {
   seq_Length = stopNORF - maxStopIndx[1];
   if(seq_Length > 0)
   {
    if(option == 1 || ((option == 2) && (seq_Length >= minLen)))
    {
     sprintf(seq_Path,"%s_%d%c%d",seq_Name,genomeLength - maxStopIndx[1],'-',genomeLength - (stopNORF - 1));
     fprintf(fp4,"%s\t%d\t%d\n",seq_Path,genomeLength - (stopNORF - 1),seq_Length);
     if(storeIn_File == 'Y')
      record_ORF_NegativeStrand(maxStopIndx[1],stopNORF - 1,curr_Dir[3]); //record Non-orf from Negative strand
    }
   }
  }
 }
 fclose(gp2);
 gp2 = NULL;
 
 fclose(fp1);
 fclose(fp2);
 fclose(fp3);
 fclose(fp4);
 fp1 = fp2 = fp3 = fp4 = NULL;
 
 remove(record_FileName[1]);
 remove(record_FileName[3]);
 sprintf(str,"rename %s %s %s",record_FileName[4],record_FileName[1],record_FileName[4]);
 system(str);
 sprintf(str,"rename %s %s %s",record_FileName[5],record_FileName[3],record_FileName[5]);
 system(str);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////Filtering Functions/////////////////////////////////////////////////////////////////////
void ORF::filtering_W_R_T_Longest_ORF()
{
 FILE *fp1,*fp2;
 int ref_StopIndx,test_StopIndx;
 char sign,tempStr[400];
 sign = '+';
 
 for(int loop = 0; loop < 4; loop++)
 {
    sprintf(tempStr,"%s/temp_ORF_List99.txt",_seq_work_dir);
  rename(record_FileName[loop],tempStr);
  

  fp1 = fopen(tempStr,"r");
  fp2 = fopen(record_FileName[loop],"a+");
    

  fscanf(fp1,"%s\t%d\t%d",seq_Path,&ref_StopIndx,&seq_Length); //scan first record from file
  fprintf(fp2,"%s\t%d\n",seq_Path,seq_Length); //print first record in file
  strcpy(tempStr,seq_Path);
  if(sign == '-')
   ref_StopIndx = genomeLength - ref_StopIndx;

  while(!feof(fp1))
  {
   fscanf(fp1,"%s\t%d\t%d",seq_Path,&test_StopIndx,&seq_Length);
   if(strcmp(tempStr,seq_Path) == 0)
    break;
   else
    strcpy(tempStr,seq_Path);
   if(sign == '-')
    test_StopIndx = genomeLength - test_StopIndx;
   if(test_StopIndx != ref_StopIndx)
   {
    fprintf(fp2,"%s\t%d\n",seq_Path,seq_Length);
    ref_StopIndx = test_StopIndx;
   }
  }
  fclose(fp1);
  fclose(fp2);
  fp1 = fp2 = NULL;
  sprintf(tempStr,"rm %s/temp_ORF_List99.txt",_seq_work_dir);
  system(tempStr);
  if(loop == 1)
   sign = '-';
 }
}

void ORF::filtering_W_R_T_best_R_Value()
{
 FILE *fp1,*fp2, *fp;
 int test_StartIndx,test_StopIndx,ref_StartIndx,ref_StopIndx,ref_Length,match_No,Length;
 char sign,ref_Seq[400],*Buffer,tempStr[400];
 double ref_MinRatio=0.0,test_MinRatio;
  int tmpFileLength, tmpRecorCount=0;
 char tmps[400];
 sign = '+';
 
 for(int loop = 0; loop < 4; loop++)
 {
      sprintf(tempStr, "%s/temp_ORF_List99.txt", _seq_work_dir);
      rename(record_FileName[loop], tempStr);
		fp1 = fopen(tempStr, "r");
		fp2 = fopen(record_FileName[loop], "a+");
		      ///// for progress bar /////////////////////////////////////
		  sprintf(tmps,"wc -l %s>tmp",tempStr);
        system(tmps);
        fp=fopen("tmp","r");
        fscanf(fp,"%d",&tmpFileLength);
        fclose(fp);
        sprintf(tmps,"rm tmp",tempStr);
        system(tmps);
      ///////////////////////////////////////////////////////////

		fscanf(fp1, "%s\t%d\t%d", seq_Path, &ref_StopIndx, &seq_Length); //scan first record from file
      strcpy(ref_Seq, seq_Path);
      ref_Length = seq_Length;
      Extract_Index(seq_Path, ref_StartIndx, ref_StopIndx, sign);
  
      if(sign == '-')
      {
         ref_StartIndx = (genomeLength - ref_StartIndx) + 1;
         ref_StopIndx = (genomeLength - ref_StopIndx) + 1;
      }
      match_No = 0;
      tmpRecorCount=0;
      while(!feof(fp1))
      {
  
   	
         tmpRecorCount++;
        if(mainPbc->pbcWasCanceled()) break;
	      mainPbc->setProgress(tmpRecorCount,tmpFileLength);
	      mainPbc->updateProgress();
     // printf(" \nprogress : %d, total:%d",tmpRecorCount,tmpFileLength);
        // sprintf(tmps,"filtering with respect to best R-value \n %d / %d of loop = %d", tmpRecorCount,tmpFileLength,loop);
           mainPbc->updateProcessLabel(-1,tmps);
           
           
           
          fscanf(fp1, "%s\t%d\t%d", seq_Path, &test_StopIndx, &seq_Length);
          Extract_Index(seq_Path, test_StartIndx, test_StopIndx, sign);
          if(sign == '-')
          {
              test_StartIndx = genomeLength - test_StartIndx;
              test_StopIndx = genomeLength - test_StopIndx;
          }
   
          if(test_StopIndx > ref_StopIndx)
          {
              fprintf(fp2, "%s\t%d\n", ref_Seq, ref_Length);
              strcpy(ref_Seq, seq_Path);
              ref_Length = seq_Length;
              ref_StopIndx = test_StopIndx;
              //   printf("Match Number: %d\n",match_No);
              if(match_No > 0)  free(Buffer);
			     match_No = 0;
          }
          else
          {
             ++match_No;
             sprintf(tmps,"filtering with respect to best R-value (match no: %d)\nProgress : %d / %d of loop = %d / 4", match_No, tmpRecorCount,tmpFileLength,loop);
           mainPbc->updateProcessLabel(-1,tmps);
             
             if(match_No == 1)
             {
                Length = readSeq_frm_Genome(&Buffer, ref_StartIndx - 1, ref_StopIndx - 1,sign);
                ref_MinRatio = Compute_MinRatio(&Buffer, 0, Length);
             }
             test_MinRatio = Compute_MinRatio(&Buffer, (test_StartIndx - 1) - (ref_StartIndx - 1), seq_Length);
             if(test_MinRatio < ref_MinRatio)
             {
                ref_MinRatio = test_MinRatio;
                strcpy(ref_Seq, seq_Path);
                ref_Length = seq_Length;
             }
          }
     	}	// end while
  		fprintf(fp2,"%s\t%d\n",ref_Seq,ref_Length);
  		if(match_No > 0)   free(Buffer);
  		match_No = 0;
  		fclose(fp1);
  		fclose(fp2);
  		fp1 = fp2 = NULL;
  		sprintf(tempStr,"rm %s/temp_ORF_List99.txt",_seq_work_dir);
 		system(tempStr);
 		if(loop == 1)	sign = '-';
  		//printf("\n%s : Completed...",record_FileName[loop]);
 	}
 	fp1 = fp2 = NULL;
}

double ORF::Compute_MinRatio(char **Buffer,int startFrom,int Length)
{    
     int i,seqLen=4;
     char *TempBuf,seqArr[4]={'A','T','C','G'};
     double MinRatio;
 
     compute_omega_parametere(seqLen,Length);
     for(i=0;i<seqLen;i++)
     {
 		  sequentialSearch(Buffer,startFrom,seqArr[i],&TempBuf,Length);
        fOmega(TempBuf,Length,i);
 		  free(TempBuf);
 		  	mainPbc->updateProgress();
     }
     //Count = UnionW(seqLen); 
     Addaptive_Flag = 1;
     MinRatio = Ratio(Occur);//Occur ~ Count
     //printf("\nMinRatio: %0.6lf",MinRatio);
     Clear_Memory(seqLen);
     return MinRatio;
}

void ORF::compute_omega_parametere(int RowNum,int Length)
{
     int i;
     double value;
     int from1_index,to1_index,from2_index,to2_index;
     
     ///////////////////////Initialization for Omega & Peak Values
     value = 2.00/(double)Length; 	
     if( 0.02 > value ) value = 0.02;       
     From1 =  value;
     To1 = 0.31;
     From2 = 0.35;
     value = (double) ( 1.00 - (2.00/(double)Length) ); 	  
     if( 0.5<value ) value = 0.5;
     To2 = value;
     PeakValue = 0.333333;
     value = 2.00/(double)Length;  
     if( 0.001 > value )  value = 0.001;          
     Omega_From = value;
     value = 1.00 - value;
     Omega_To = value;
     value = 1.0/(double)Length; 
     if( 0.001 > value) value = 0.001;
     Omega_Interval = value; 
     ///////////////////////End of Initialization
     ///////////////////////Counting of Generated Omega Values
     Occur = (int)ceil((Omega_To - Omega_From)/Omega_Interval + 2);
     from1_index = (int)ceil((double)(Occur - 1)*From1);
     to1_index = (int)ceil((double)(Occur - 1)*To1);
     from2_index = (int)ceil((double)(Occur - 1)*From2);
     to2_index = (int)ceil((double)(Occur - 1)*To2);
     
     Occur = (to1_index - from1_index) + (to2_index - from2_index) + 4;
     //printf("Occur2= %d\n",Occur);
     ///////////////////////End of Counting
     ///////////////////////Omega Value generation part
     MatrixW = (double *)calloc(Occur,sizeof(double));
     i = 0;
     for(value = From1; value <= To1; value = value + Omega_Interval)
      MatrixW[i++] = value;
     for(value = From2; value <= To2; value = value + Omega_Interval)
      MatrixW[i++] = value;
     //printf("Occur3= %d\n",i);
     if(i > Occur)
     {
      //printf("\nI = %d Occur = %d\n",i,Occur);
      exit(0);
     }
     Occur = i;
     //////////////////////End of Omega Value Generation
     //////////////////////Allocation for storing FW values
     Matrix = (double **)calloc(RowNum,sizeof(double *));
     PeekValueFW = (double *)calloc(RowNum,sizeof(double));
     for(i = 0; i < RowNum; i++)
          Matrix[i] = (double  *)calloc(Occur,sizeof(double ));
     //printf("%lf - %lf - %lf \n",Omega_From,Omega_To,Omega_Interval); 
}

int ORF::readSeq_frm_Genome(char **Buffer,int startIndx,int endIndx,char sign)
{
	int Length,i;
	
	if(sign == '+')
     	{
     		i = 0;
		*Buffer = (char *)calloc(((endIndx - startIndx) + 2),sizeof(char)); 
		for(int Index = startIndx; Index <= endIndx; Index++)
			*(*Buffer + i++) = forward_Genome[Index];
		*(*Buffer + i) = '\0';
		i = 0;
		Length = (endIndx - startIndx) + 1;
     	}
    	else if(sign = '-')
     	{
     		i = 0;
		*Buffer = (char *)calloc(((endIndx - startIndx) + 2),sizeof(char));
		for(int Index = startIndx; Index <= endIndx; Index++)
			*(*Buffer + i++) = reverse_Genome[Index];
		*(*Buffer + i) = '\0';
		i = 0;
		Length = (endIndx - startIndx) + 1;
     	}
	return Length;
}

void ORF::sequentialSearch(char **Buf,int startFrom,char seqArr,char **Buffer,int Length) 
{
	int i;
        
        *Buffer = (char *)malloc((Length+1) * sizeof(char));
        for(i = startFrom; i < Length; i++)
	{
	   if(toupper(seqArr) == *(*Buf+i))
	       *(*Buffer+i)='1';
           else
               *(*Buffer+i)='0';
	}
}

void ORF::fOmega(char *Buf, int Length, int RowNo)
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
         
    if(Addaptive_Flag) PeekValueFW[RowNo] = fOmega_PeekValue(Buf,Length);
         //printf("i = %d k = %d\n",i,k);
}

double ORF::fOmega_PeekValue(char *Buf,int Length)
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

double ORF::Ratio(int Count)
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

double ORF::FindMax(int Row,int Col)
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

void ORF::Clear_Memory(int seqLen)
{   
       int i;  
       for(i=0;i<seqLen;i++)
            free(Matrix[i]);
       free(Matrix);
       free(MatrixW);
       if(Addaptive_Flag)
           free(PeekValueFW);      
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////ORF Matching Functions/////////////////////////////////////////////////////////////////////
bool ORF::match_ORF_StartCodon(char *Codon,int index)
{
 if(strcmp(Codon,startCodon[index]) == 0)
  return true;
 else
  return false;
}

bool ORF::match_ORF_StopCodon(char *Codon)
{
 for(int i = 0; i < numStopCodon; ++i)
 {
  if(strcmp(Codon,stopCodon[i]) == 0)
   return true;
 }
 return false;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////ORF Recording Functions/////////////////////////////////////////////////
void ORF::record_ORF_PositiveStrand(int startIndex,int stopIndex,char *curr_Dir)
{
 sprintf(seq_Path,"%s%s_%d%c%d.txt",curr_Dir,seq_Name,startIndex + 1,'+',stopIndex + 1);
 FILE *fp;
 fp = fopen(seq_Path,"w");
 if(fp != NULL)
 {
  int i = 1; //Column Number
  for(int Index = startIndex; Index <= stopIndex; Index++)
  {
   fprintf(fp,"%c",forward_Genome[Index]);
   if(i == 100)
   {
    fprintf(fp,"\n");
    i = 1;
   }
   else
    i++;
  }
  fclose(fp);
  fp = NULL; 
 }
}

void ORF::record_ORF_NegativeStrand(int startIndex,int stopIndex,char *curr_Dir)
{
 char *tempBuf;
 
 sprintf(seq_Path,"%s%s_%d%c%d.txt",curr_Dir,seq_Name,genomeLength - startIndex,'+',genomeLength - stopIndex);
	FILE *fp;
 fp = fopen(seq_Path,"w");
 if(fp != NULL)
 {
  int j = 0;
  tempBuf = (char *)calloc((stopIndex - startIndex) + 2,sizeof(char));
    
  for(int Index = startIndex; Index <= stopIndex; ++Index,++j)
  {
   if(reverse_Genome[Index] == 'A')
    tempBuf[j] = 'T';
   else if(reverse_Genome[Index] == 'T')
    tempBuf[j] = 'A';
   else if(reverse_Genome[Index] == 'C')
    tempBuf[j] = 'G';               
   else if(reverse_Genome[Index] == 'G')
    tempBuf[j] = 'C';
  }
  tempBuf[j] = '\0';
  
  int i = 1; //Column Number
  for(int Index = j-1; Index >= 0; --Index)
  {
   fprintf(fp,"%c",tempBuf[Index]);
   if(i == 100)
   {
    fprintf(fp,"\n");
    i = 1;
   }
   else
    i++;
  }
  fclose(fp);
  fp = NULL;
  free(tempBuf);
  tempBuf = NULL;
 }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////Utility Functions/////////////////////////////////////////////////////////////////
void ORF::toUpper(char **Codon)
{
 for(int i = 0; i < 3; ++i)
  *(*Codon + i) = toupper(*(*Codon + i));
}

void ORF::readInBuf()
{
 FILE *gp;
 char ch;
 int Loop1=0;
        char str[400];
        
        A = T = C = G = N = R = W = Y = M = K = S = H = B = V = D = 0;
        gp = fopen(path_Seq,"r");
 if(gp == NULL)
 {
    printf("\nCan not open specified file for reading! %s\nMay be Corrupted\n ",path_Seq);
   exit(0);
 }
 rewind(gp);
 fscanf(gp,"%[^\n]\n",str);
 fseek(gp,SEEK_CUR,SEEK_END);
 //fseek(gp,0L,SEEK_END);
 Loop1 = ftell(gp);
 
 forward_Genome = (char *)malloc((Loop1+1)*sizeof(char));
 Loop1=0;
 
 rewind(gp);
 fscanf(gp,"%[^\n]\n",str);
        while(!feof(gp))
 {
  ch = fgetc(gp);
  ch = toupper(ch);
                switch(ch)
  {
   case 'A':
     *(forward_Genome + Loop1) = ch;
                                               ++Loop1;
                                               ++A;
					break;
			case 'T':
					*(forward_Genome + Loop1) = ch;
                                               ++Loop1;
                                               ++T;
					break;
			case 'C':
					*(forward_Genome + Loop1) = ch;
                                               ++Loop1;
                                               ++C;
					break;
			case 'G':
					*(forward_Genome + Loop1) = ch;
                                               ++Loop1;
                                               ++G;
					break;
			case 'N':
					*(forward_Genome + Loop1) = ch;
                                               ++Loop1;
                                               ++N;
					break;
			case 'R':
					*(forward_Genome + Loop1) = ch;
                                               ++Loop1;
                                               ++R;
					break;
			case 'W':
					*(forward_Genome + Loop1) = ch;
                                               ++Loop1;
                                               ++W;
					break;
			case 'Y':
					*(forward_Genome + Loop1) = ch;
                                               ++Loop1;
                                               ++Y;
					break;
			case 'M':
					*(forward_Genome + Loop1) = ch;
                                               ++Loop1;
                                               ++M;
					break;
			case 'K':
					*(forward_Genome + Loop1) = ch;
                                               ++Loop1;
                                               ++K;
					break;
			case 'S':
					*(forward_Genome + Loop1) = ch;
                                               ++Loop1;
                                               ++S;
					break;
			case 'H':
					*(forward_Genome + Loop1) = ch;
                                               ++Loop1;
                                               ++H;
					break;
			case 'B':
     *(forward_Genome + Loop1) = ch;
                                               ++Loop1;
                                               ++B;
     break;
   case 'V':
     *(forward_Genome + Loop1) = ch;
                                               ++Loop1;
                                               ++V;
     break;
   case 'D':
     *(forward_Genome + Loop1) = ch;
                                               ++Loop1;
                                               ++D;
     break;
   default :
     break;
  }
 }
 fclose(gp);
 gp = NULL;
 *(forward_Genome + Loop1) = '\0';
 genomeLength = Loop1;
 //printf("\nGenome Length: %d",genomeLength);
}

void ORF::reverse_complement_of_Sequence()
{
	int End;
	reverse_Genome = (char *)calloc((genomeLength+1),sizeof(char));
	End = genomeLength - 1;
	for(int Start = 0; Start < genomeLength; Start++)
	{
		if(*(forward_Genome + (End - Start)) == 'A')
			reverse_Genome[Start] = 'T';
		else if(*(forward_Genome + (End - Start)) == 'T')
			reverse_Genome[Start] = 'A';
		else if(*(forward_Genome + (End - Start)) == 'C')
			reverse_Genome[Start] = 'G';                                                                                    
		else if(*(forward_Genome + (End - Start)) == 'G')
			reverse_Genome[Start] = 'C';
	}
	reverse_Genome[genomeLength] = '\0';
}

void ORF::searchChar(char delim,int Occurance, char **token, char *string)
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

void ORF::Extract_Index(char *PathName,int &pos1,int &pos2,char sign)
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

void ORF::sort_ORF_List_File(char *orf_File,int type,int field1,int field2)
{
    char query[400];
    
    if(type == 1)
 sprintf(query,"sort -k %d,%dn -k %d,%dnr %s > %s/temp_99.txt",field1,field1,field2,field2,orf_File,_seq_work_dir);
    else if(type == 2)
     sprintf(query,"sort -k %d,%dnr -k %d,%dnr %s > %s/temp_99.txt",field1,field1,field2,field2,orf_File,_seq_work_dir);
    else
 sprintf(query,"sort --key=%d -n %s > %s/temp_99.txt",field1,orf_File,_seq_work_dir);
    system(query);
    sprintf(query,"rm %s",orf_File);
    system(query);
    sprintf(query,"rename %s/temp_99.txt %s %s/temp_99.txt",_seq_work_dir, orf_File, _seq_work_dir);
    system(query);
}
