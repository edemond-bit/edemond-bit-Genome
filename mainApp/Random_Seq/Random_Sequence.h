
#ifndef RANDOM_SEQUENCE_H
#define RANDOM_SEQUENCE_H
 
#include<stdio.h>
#include<iostream.h>
#include <string.h> 
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <curses.h>
#include <ctype.h>
#include <sys/types.h>
#include <dirent.h>

void Create_Random_Sequence(int orf_num, int MIN_CHAR, int MAX_CHAR, int Operation, double, double,int, int );
int readInBuf(char *FName1,char **Buffer);
void searchChar(char ,int , char **,char *);
void Swap(char *tempBuf,int Swap_No,int Length);
void Mutation(char *tempBuf,int Mut_No,int Length);
char randFileName[400];
int *swapPos,*mutPos;


void Create_Random_Sequence(int orf_num, int MIN_CHAR, int MAX_CHAR, int Operation, double swap_Percent, double mut_Percent,int CountBigGene,int CountBigNGene)
{
    
   int swap_No,mut_No,counter,pos1,pos2,fileLength;
   char sign,Genome[400],Gen_Name[400], FName[400],*Buf=NULL,*Buffer=NULL,rand_name[400],temp_rand_name[400],rand_index[16],query[400];
   //double swap_Percent,mut_Percent;
   int index;
   char *token1,*token2;
   FILE *fp1, *fp2, *fp3, *fp4;
   //int CountBigGene,CountBigNGene; //Contain seq count having Length >= MIN_CHAR & Length >= MAX_CHAR
   char **Gene_Seq=0,**NGene_Seq=0; // for storing sequence names having Length >= MIN_CHAR & Length >= MAX_CHAR
   int pGene,pNGene; // number of perturbed sequences from Gene and NonGene sets
   char  rand_path_list_file[400];
  
   fp1 = NULL; 

  
   fp1 = fopen(fm->get_path_ORF(),"r");
   if(fp1==NULL)
   {
     QMessageBox::warning(appl,"Warning","You must run ORF computation first");
     //mainPbc->pbcReset();
     return;
   }

   ///////////////////////////////////////Modified 16.09.08
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
   		if((strcmp(temp_rand_name,FName) == 0) || (fileLength > MAX_CHAR))
   			break;
   		else
   			strcpy(temp_rand_name,FName);
   		CountBigGene = ((fileLength >= MIN_CHAR && fileLength <= MAX_CHAR) ? CountBigGene + 1 : CountBigGene);
   	}
   	
   	Gene_Seq = (char **)calloc(CountBigGene,sizeof(char *));
	for(int i = 0; i < CountBigGene; ++i)
   		Gene_Seq[i] = (char *)calloc(100,sizeof(char));
   		
   	////////////////////////////////////////////////////////Reading and storing sequences Length >= MIN_CHAR & Length >= MAX_CHAR in array	
   	rewind(fp2);
   	strcpy(temp_rand_name,"");
   	int i = 0;
	while(!feof(fp2))
   	{
   		fscanf(fp2,"%s\t%d",FName,&fileLength);
   		if(i == CountBigGene)
   			break;
   		else
   			strcpy(temp_rand_name,FName);
   		if((fileLength >= MIN_CHAR && fileLength <= MAX_CHAR))
	   		strcpy(Gene_Seq[i++],FName);
   	}
   	////////////////////////////////////////////////////////  	
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
   		if((strcmp(temp_rand_name,FName) == 0) || (fileLength > MAX_CHAR))
   			break;
   		else
   			strcpy(temp_rand_name,FName);
   		CountBigNGene = ((fileLength >= MIN_CHAR && fileLength <= MAX_CHAR) ? CountBigNGene + 1 : CountBigNGene);
   	}
   	
   	NGene_Seq = (char **)calloc(CountBigNGene,sizeof(char *));
	for(int i = 0; i < CountBigNGene; ++i)
   		NGene_Seq[i] = (char *)calloc(100,sizeof(char));
   		
   	////////////////////////////////////////////////////////Reading and storing sequences Length >= MIN_CHAR & Length >= MAX_CHAR in array	
   	rewind(fp2);
   	strcpy(temp_rand_name,"");
   	int i = 0;
   	while(!feof(fp2))
   	{
   		fscanf(fp2,"%s\t%d",FName,&fileLength);
   		if(i == CountBigNGene)
   			break;
   		else
   			strcpy(temp_rand_name,FName);
   		if((fileLength >= MIN_CHAR && fileLength <= MAX_CHAR))
	   		strcpy(NGene_Seq[i++],FName);
   	}
   	///////////////////////////////////////////////	
   	fclose(fp2);
   	fp2 = NULL;
   }
   fclose(fp1);
   fp1 = NULL;
   
   
   
   ///////////////////////////////////////////////////////
   
   pGene = (int)round(((double)CountBigGene/(double)(CountBigGene + CountBigNGene))*(double)orf_num);
   pNGene = (int)round(((double)CountBigNGene/(double)(CountBigGene + CountBigNGene))*(double)orf_num);
        mainPbc->reset();   
 mainPbc->addAChildProcess(100,"Random sequence generating...");
 swap_Percent=35.00; 
 mut_Percent=35.00;
sprintf(rand_name,"%s/Random_Data",seq_work_dir);

 if(opendir(rand_name)!=NULL){

		  sprintf(temp_rand_name,"rm -r %s/Random_Data",seq_work_dir);
		  system(temp_rand_name);
	
 }

 //   strcpy( rand_name,"Random_Data");
 strcpy(temp_rand_name,"mkdir ");
 strcat(temp_rand_name,rand_name);
 system(temp_rand_name);
 sprintf(rand_path_list_file,"%s/RandomPathList.csv",seq_work_dir);
 
 fp3 = fopen(rand_path_list_file,"w+");
 if(fp3==NULL)
   {
     fp1 = NULL;
     QMessageBox::warning(appl,"Warning",QString("Cann't open file :-")+QString(temp_rand_name));
   
     exit(0);
   }   
 strcpy(temp_rand_name,rand_name);
 //////////////////Start of random selection (with replacement)
   sign = '+';
   counter = 0;
   genomeLength = readInBuf(Genome,&forward_Genome);
  //////////////Allocate 'Buf' with MAX_CHAR(maximum possible sequence size) to store original sequence and another one 'Buffer' to load copy of'Buf' for random perturbation of its content
   ////////////// Also some necessary dynamic allocation is done here with MAX_CHAR size/////
   //////////////It is done to avoid repeated allocation and deallocation///////
   Buf = (char *)calloc((MAX_CHAR + 1),sizeof(char));
   Buffer = (char *)calloc((MAX_CHAR + 1),sizeof(char));
   swapPos = (int *)calloc(MAX_CHAR,sizeof(int));
   mutPos = (int *)calloc(MAX_CHAR,sizeof(int));
   ///////////////////////////////////////////////////////////////////////
   mainPbc->addAChildProcess(50,"Random computation for gene");
   srand((unsigned int)time((time_t *)NULL));
   for(int i = 0; i < pGene; ++i)
   {
   	index = rand()%(CountBigGene - i); //Without Replacement Procedure
   	/////////Extract sequence position from it's name/////////////////
   	searchChar('_',1,&token1,Gene_Seq[index]);
        searchChar(sign,2,&token2,token1);
        //pos1 = atoi((const char*)token2);
        sscanf(token2,"%d",&pos1);
        free(token2);
        token2 = NULL;
        searchChar(sign,1,&token2,token1);
        //pos2 = atoi((const char*)token2);
        sscanf(token2,"%d",&pos2);
        free(token2);
        token2 = NULL;
        free(token1);
        token1 = NULL;
        //////////////////////////////////////////////////////////////////
        //strcpy(FName,Gene_Seq[index]);
        strcpy(Gene_Seq[index],Gene_Seq[CountBigGene - i - 1]); //Just overwrite the sequence name of index psition(bcz sequence in index position will not be required further) with that of 'CountBigGene - i - 1' position
        //strcpy(Gene_Seq[CountBigGene - i - 1],FName);
        //////////////////////////////////////////////////////////////////
        int bufIndex;
       	bufIndex = 0;
       	--pos1;
       	--pos2;
       	fileLength = abs(pos1 - pos2) + 1;
       	for(int Index = pos1; Index <= pos2; ++Index,++bufIndex)
		Buf[bufIndex] = forward_Genome[Index];
	Buf[bufIndex] = '\0';
	
 	swap_No = (int)round(double(fileLength)*(swap_Percent/100.0));
	mut_No = (int)round(double(fileLength)*(mut_Percent/100.0));
 	 
        for(int Loop = 1; Loop <= Operation; Loop++)
	{
	   strcpy(Buffer,Buf);
	   Swap(Buffer, swap_No, fileLength);
	   Mutation(Buffer, mut_No, fileLength);
	   strcat(rand_name,"/rand");
	   ++counter; 
	   sprintf(rand_index,"%d",counter);
	   strcat(rand_name,"-");
	   strcat(rand_name,rand_index);
	   fp4 = fopen(rand_name, "w");     //rand file opened
	   fputs(Buffer,fp4); // rand sequence is saved in the file
	   fclose(fp4); 
	   fp4 = NULL;
	   fprintf(fp3,"%s\t%d\n",rand_name,fileLength);
	   strcpy(rand_name,temp_rand_name);
	}
   }
   mainPbc->deleteLastChildProcess();
   for(int i = 0; i < CountBigGene; ++i)
   	free(Gene_Seq[i]);
   free(Gene_Seq); 
    sign = '-';
   reverse_complement_of_Sequence();
   free(forward_Genome);
   srand((unsigned int)time((time_t *)NULL));
   for(int i = 0; i < pNGene; ++i)
   {
 	index = rand()%(CountBigNGene - i); //Without Replacement Procedure
	/////////Extract sequence position from it's name/////////////////
	searchChar('_',1,&token1,NGene_Seq[index]);
	searchChar(sign,2,&token2,token1);
	sscanf(token2,"%d",&pos1);
	free(token2);
	token2 = NULL;
	searchChar(sign,1,&token2,token1);
        sscanf(token2,"%d",&pos2);
	free(token2);
	token2 = NULL;
	free(token1);
	token1 = NULL;
	//////////////////////////////////////////////////////////////////
	//strcpy(FName,NGene_Seq[index]);
	strcpy(NGene_Seq[index],NGene_Seq[CountBigNGene - i - 1]);//Just overwrite the sequence name of index psition(bcz sequence in index position will not be required further) with that of 'CountBigGene - i - 1' position
	//strcpy(NGene_Seq[CountBigNGene - i - 1],FName);
	//////////////////////////////////////////////////////////////////
	int bufIndex;
        bufIndex = 0;
        pos1 = genomeLength - pos1;
        pos2 = genomeLength - pos2;
        fileLength = abs(pos1 - pos2) + 1;
        for(int Index = pos1; Index <= pos2; ++Index,++bufIndex)
		Buf[bufIndex] = reverse_Genome[Index];
       	Buf[bufIndex] = '\0';
       	
        swap_No = (int)round(double(fileLength)*(swap_Percent/100.0));
	mut_No = (int)round(double(fileLength)*(mut_Percent/100.0));
        
        for(int Loop = 1; Loop <= Operation; Loop++)
        {
        	strcpy(Buffer,Buf);
	        Swap(Buffer, swap_No, fileLength);
       		Mutation(Buffer, mut_No, fileLength);
                strcat(rand_name,"/rand");
                ++counter; 
       	        sprintf(rand_index,"%d",counter);
                strcat(rand_name,"-");
                strcat(rand_name,rand_index);
                fp4 = fopen(rand_name, "w");     //rand file opened
                fputs(Buffer,fp4); // rand sequence is saved in the file
                fclose(fp4); 
                fp4 = NULL;
                fprintf(fp3,"%s\t%d\n",rand_name,fileLength);
                strcpy(rand_name,temp_rand_name);
        }
   }
   mainPbc->deleteLastChildProcess();
   fclose(fp3); 
   fp3=NULL;
   free(reverse_Genome);
   forward_Genome = reverse_Genome = NULL;
   /////////////////////////////////////////////////////////////////////////////
   for(int i = 0; i < CountBigNGene; ++i)
   	free(NGene_Seq[i]);
   free(NGene_Seq);
   /////////////////////////////////////////////////////////////////////////////
   //////////////Deallocate 'Buf',Buffer' here//////////////////////////////////
   ////////////// Also some necessary dynamic allocation is done here with MAX_CHAR size/////
   free(Buf);
   free(Buffer);
   Buf = Buffer = NULL;
   free(swapPos);
   free(mutPos);
   swapPos = mutPos = NULL;
   /////////////////////////////////////////////////////////////////////////////
   fp1 = fopen(fm->get_path_ORF(),"r");
   sprintf(temp_rand_name,"%s/path_ORF99.csv",seq_work_dir);
   fp3 = fopen(temp_rand_name,"w");
   for(int i = 0; i < 5; ++i)
   {
   	fscanf(fp1,"%s",FName);
   	fprintf(fp3,"%s\n",FName);
   }
sprintf(temp_rand_name,"%s/RandomPathList.csv\n",seq_work_dir);
 
   fprintf(fp3,"%s",temp_rand_name);
   fclose(fp3);
   fp3 = NULL;
   fclose(fp1); 
   fp1=NULL;
   //mainPbc->deleteLastChildProcess();
   // from here onword in this function the variable temp_rand_name has been 
   // used as a temporary variable
   sprintf(temp_rand_name,"rm %s/path_ORF",seq_work_dir);
   system(temp_rand_name);
   sprintf(temp_rand_name,"rename %s/path_ORF99.csv %s/path_ORF %s/path_ORF99.csv",seq_work_dir,seq_work_dir,seq_work_dir);
   sprintf(query,temp_rand_name);
   system(query);
   sprintf(temp_rand_name,"sort --key=2 -n %s/RandomPathList.csv > %s/temp_99.csv",seq_work_dir,seq_work_dir);
   system(temp_rand_name);
   sprintf(temp_rand_name,"rm %s/RandomPathList.csv",seq_work_dir);
   system(temp_rand_name);
   //
   sprintf(temp_rand_name,"mv %s/temp_99.csv %s/RandomPathList.csv ",seq_work_dir,seq_work_dir);
   system(temp_rand_name);
   sprintf(randFileName,"%s/RandomPathList.csv",seq_work_dir);
 mainPbc->pbcReset();
 

}

int readInBuf(char *FName1,char **Buffer)
{
	FILE *gp;
	char ch;
	int Loop1,Position;
	char str[400];
	gp = fopen(FName1,"r");
	if(gp == NULL)
	{
	   QMessageBox::warning(appl,"Warning","Cann't open file for reading neucleotides");
		exit(0);
	}
	rewind(gp);
	fscanf(gp, "%[^\n]\n", str);
	fseek(gp,SEEK_CUR,SEEK_END);
	Position=ftell(gp);
        rewind(gp);
	fscanf(gp,"%[^\n]\n", str);
       	*Buffer = (char *)calloc((Position+1),sizeof(char));
	Loop1=0;
        while(1)
	{
		ch = fgetc(gp);
                if( feof(gp) )
		    break;
                else
		{
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
                                         *(*Buffer+Loop1) = ch;
                                         ++Loop1;
					 break;
				default :
					 break;  
			}
		}
	}
        fclose(gp);
        gp = NULL;
	*(*Buffer+Loop1) = '\0';
	return Loop1;       
}


void Swap(char *tempBuf,int Swap_No,int Length)
{
	char ch;
        int pos1,pos2,val1,val2,totSwap; // pos1/2 ~ index of 'swapPos' and val1/2 ~ content of 'swapPos' that is index of 'tempBuf'
             
        totSwap = 2*Swap_No;
        
        for(int i = 0; i < Length; ++i)
        	swapPos[i] = i;
        	
        srand((unsigned int)time((time_t *)NULL));
        //Without Replacement Procedure
        for(int i = 0; i < totSwap; ++i)
        {
        	 //First Position selection is straight forward
        	 pos1 = rand()%(Length - i);
        	 val1 = swapPos[pos1];
        	 swapPos[pos1] = swapPos[Length - 1 - i];
        	 ++i;
        	 //In case of Second Position selection is has to be ensured that nucleotide in pos2 is different from that in pos1
        	 do
        	 {
        	 	pos2 = rand()%(Length - i);
        	 }
        	 while(tempBuf[swapPos[pos2]] == tempBuf[val1]);
        	 val2 = swapPos[pos2];
        	 swapPos[pos2] = swapPos[Length - 1 - i];
        	 
        	 //Perform swap here of i and i+1 position's elements of swapPos array to tempBuf sequence array
        	 ch = tempBuf[val1];
		 tempBuf[val1] = tempBuf[val2];
		 tempBuf[val2] = ch;
        }
}

void Mutation(char *tempBuf,int Mut_No,int Length)
{
	char Mut_Char[] = {'A','T','C','G'},ch; 
 	int pos,val;
 	
	for(int i = 0; i < Length; ++i)
        	mutPos[i] = i;   

	srand((unsigned int)time((time_t *)NULL));
	//Without Replacement Procedure
	for(int i = 0; i < Mut_No; ++i)
        {
        	//Mutation Position selection is straight forward
        	pos = rand()%(Length - i);
        	val = mutPos[pos];
        	mutPos[pos] = mutPos[Length - 1 - i];
		        
  	        ch = tempBuf[val];
	        switch(ch)
	        {
	             case 'A' : 
	             		Mut_Char[0] = Mut_Char[3];
	             		Mut_Char[3] = ch;
	             		break;
	             case 'T' : 
	             		Mut_Char[1] = Mut_Char[3];
	             		Mut_Char[3] = ch;
	             		break;
	             case 'C' : 
	             		Mut_Char[2] = Mut_Char[3];
	             		Mut_Char[3] = ch;
	             		break;
	             case 'G' : 
	            		break;
	        }
                tempBuf[val] = Mut_Char[rand()%3];
	        switch(ch)
	        {
	             case 'A' : 
	             		Mut_Char[3] = Mut_Char[0];
	             		Mut_Char[0] = ch;
	             		break;
	             case 'T' : 
	             		Mut_Char[3] = Mut_Char[1];
	             		Mut_Char[1] = ch;
	             		break;
	             case 'C' : 
	             		Mut_Char[3] = Mut_Char[2];
	             		Mut_Char[2] = ch;
	             		break;
	             case 'G' : 
	            		break;
	        }
	}
}
#endif
