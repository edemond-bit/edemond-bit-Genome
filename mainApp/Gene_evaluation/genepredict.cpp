#include "evaluation.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>

int GenePredict::readGenePredictFile(NCBI *ncb,char *File_Name1,char *File_Name2,int firstTimeFlag)
{
 FILE *fp;
// char query[200];
 char tmp[200];
 int i,j,Pr,minLen,maxLen;
 RecFields2 rf;
 
 fp = NULL;
 minLen = ncb->minLen;
 maxLen = ncb->maxLen;
 /////////////////////////////////////////////////////////////////////Positive Strand
 fp = fopen(File_Name1,"r");
 if(fp != NULL)
 {
  fscanf(fp,"%[^\n]\n",rf.name);
  while(!feof(fp))
  {
   fscanf(fp,"%[^\t]\t%d\t%[^\t]\t%f\t%d\n",rf.name,&Pr,rf.PrC,&rf.Rs,&rf.len);
   if(strncmp(rf.name,"Total Predicted Genes = 0",15) == 0)
    break;
   if(ncb->Choice == 1 || (ncb->Choice == 2 && (rf.len >= minLen && rf.len <= maxLen)))
   {
    if(Pr == 1)
     ++recNum_Plus;
    else if(Pr == 0)
     ++recNum_Plus_Zero;
   }
  }
 }
 else
 {
  printf("\n %s doesn't exist!\n", File_Name1);
  return 0;
 }
 
 recs_Plus = new RecFields2[recNum_Plus];
 recs_Plus_Zero = new RecFields2[recNum_Plus_Zero];
 Position2_Array_Plus = new RecFields2[recNum_Plus];
 rewind(fp);
 if(fp != NULL)
 {
  i = j = 0; 
  fscanf(fp,"%[^\n]\n",recs_Plus[i].name);
  while(!feof(fp))
  {
   fscanf(fp,"%[^\t]\t%d\t%[^\t]\t%f\t%d\n",rf.name,&Pr,rf.PrC,&rf.Rs,&rf.len);
   if(strncmp(rf.name,"Total Predicted Genes = 0",15) == 0)
    break;
   if(ncb->Choice == 1 || (ncb->Choice == 2 && (rf.len >= minLen && rf.len <= maxLen)))
   {
    if(Pr == 1)
    {
     strcpy(recs_Plus[i].name,rf.name);
     strcpy(recs_Plus[i].PrC,rf.PrC);
     recs_Plus[i].Rs = rf.Rs;
     recs_Plus[i].len = rf.len;
     recs_Plus[i].pos1 = Parse1(recs_Plus[i].name);
     recs_Plus[i].pos2 = Parse2(recs_Plus[i].name);
     i++;
    }
    else if(Pr == 0)
    {
     strcpy(recs_Plus_Zero[j].name,rf.name);
     strcpy(recs_Plus_Zero[j].PrC,rf.PrC);
     recs_Plus_Zero[j].Rs = rf.Rs;
     recs_Plus_Zero[j].len = rf.len;
     recs_Plus_Zero[j].pos1 = Parse1(recs_Plus_Zero[j].name);
     recs_Plus_Zero[j].pos2 = Parse2(recs_Plus_Zero[j].name);
     j++;
    }
   }
  }
  fclose(fp);
  fp = NULL;
 }
 /////////////////////////////////////////////////////////////////////Negative Strand
 fp = fopen(File_Name2,"r");
 if(fp != NULL)
 {
  fscanf(fp,"%[^\n]\n",rf.name);
  while(!feof(fp))
  {
   fscanf(fp,"%[^\t]\t%d\t%[^\t]\t%f\t%d\n",rf.name,&Pr,rf.PrC,&rf.Rs,&rf.len);
   if(strncmp(rf.name,"Total Predicted Genes = 0",15) == 0)
    break;
   if(ncb->Choice == 1 || (ncb->Choice == 2 && (rf.len >= minLen && rf.len <= maxLen)))
   {
    if(Pr == 1)
     ++recNum_Minus;
    else if(Pr == 0)
     ++recNum_Minus_Zero; 
   }
  }
 }
 else
 {
  printf( "\n %s doesn't exist!\n", File_Name2);
  return 0;
 }
 
 //cout << "\nTotal seq(Our Method): " << recNum_Plus + recNum_Minus << endl;
if(firstTimeFlag==0){
sprintf(tmp,"Total seq(Our Method): %d",recNum_Plus+recNum_Minus);
display_out(tmp, qApp);
}
 rewind(fp);
 recs_Minus = new RecFields2[recNum_Minus];
 recs_Minus_Zero = new RecFields2[recNum_Minus_Zero];
 Position2_Array_Minus = new RecFields2[recNum_Minus];
 rewind(fp);
 fp = fopen(File_Name2,"r");
 if(fp != NULL)
 {
  i = j = 0;
  fscanf(fp,"%[^\n]\n",rf.name);
  while(!feof(fp))
  {
   fscanf(fp,"%[^\t]\t%d\t%[^\t]\t%f\t%d\n",rf.name,&Pr,rf.PrC,&rf.Rs,&rf.len);
   if(strncmp(rf.name,"Total Predicted Genes = 0",15) == 0)
    break;
   if(ncb->Choice == 1 || (ncb->Choice == 2 && (rf.len >= minLen && rf.len <= maxLen)))
   {
    if(Pr == 1)
    {
     strcpy(recs_Minus[i].name,rf.name);
     strcpy(recs_Minus[i].PrC,rf.PrC);
     recs_Minus[i].Rs = rf.Rs;
     recs_Minus[i].len = rf.len;
     recs_Minus[i].pos1 = Parse1(recs_Minus[i].name);
     recs_Minus[i].pos2 = Parse2(recs_Minus[i].name);
     i++;
    }
    else if(Pr == 0)
    {
     strcpy(recs_Minus_Zero[j].name,rf.name);
     strcpy(recs_Minus_Zero[j].PrC,rf.PrC);
     recs_Minus_Zero[j].Rs = rf.Rs;
     recs_Minus_Zero[j].len = rf.len;
     recs_Minus_Zero[j].pos1 = Parse1(recs_Minus_Zero[j].name);
     recs_Minus_Zero[j].pos2 = Parse2(recs_Minus_Zero[j].name);
     j++;
    }
   }
  }
  fclose(fp);
  fp = NULL;
 }
 return 1;
}

int GenePredict::Parse1(char *name)
{
   int i,len,num=0;
   
   len = strlen(name);
   for(i=len-1;i>=0;i--)
    if(name[i] == '_')
  break;
   ++i;
   for(;i<len;i++)  
   {
       if( name[i] != '+' && name[i] != '-' ) 
       {
          num *= 10; 
          num += ( name[i] - 48);
       }
       else
          break;
   }
   return num;
} 

int GenePredict::Parse2(char *name)
{
   int i,len,num=0;
   
   len = strlen(name);
   for(i=len-1;i>=0;i--)
      if(name[i] == '-' || name[i] == '+')
          break;
   ++i;
   for(;i<len;i++)  
   {
       if( name[i] != '.') 
       {
          num *= 10; 
          num += ( name[i] - 48);
       }
       else
           break;
   }
   return num;
} 

void GenePredict::ncbi_Vs_genePrediction(NCBI *ncb, char *seqName, char isHypo,char *GenePedLabel, char *eval_FileName)
{
   FILE *fp1,*fp2;
   bool matched_flag;
   int abs_Count1,stopOnly_Count1,uniq_Count1,uniq_Count1_Check;
   int abs_Count2,stopOnly_Count2,uniq_Count2,uniq_Count2_Check;
   int abs_Count3,stopOnly_Count3,abs_Count4,stopOnly_Count4;
   int missed_Count1,Gene_NonGenePred_Count1,nonGene_Count1,missed_Count2,Gene_NonGenePred_Count2,nonGene_Count2;
   char query[200],query2[200];
   
   isHypo = isHypo;
   //////////////////////////////////////Directory Creation
   DIR *dir;
   if((dir = opendir("Our_Predict_Results")) == NULL)
    system("mkdir Our_Predict_Results");

   sprintf(query,"Our_Predict_Results/%s",seqName);
   if((dir = opendir(query)) != NULL)
   {
    sprintf(query,"rm -r Our_Predict_Results/%s",seqName);
    system(query);
   }
   sprintf(query,"mkdir Our_Predict_Results/%s",seqName);
   system(query);
   sprintf(query,"Our_Predict_Results/%s",seqName);
   ///////////////////////////////////////////
   arr_Absolute1 = new RecFields2[recNum_Plus];
   arr_Stop_Only1 = new RecFields2[recNum_Plus];
   arr_Uniq1 = new RecFields2[recNum_Plus];
      
   /////////////////////////////////////////////////////////////////////Positive Strand
   abs_Count1 = stopOnly_Count1 = uniq_Count1 = uniq_Count1_Check = missed_Count1 = Gene_NonGenePred_Count1 = nonGene_Count1 = 0;
   fp1 = NULL;
   sprintf(query2,"%s/Result+1.txt",query);
   fp1 = fopen(query2,"w");
   for(int i = 0; i < recNum_Plus; i++)
   {
        matched_flag = false;
        for(int j = 0; j < ncb->recNum_Plus; j++)
        {
            if(recs_Plus[i].pos2 == ncb->recs_Plus[j].pos2)
            {
                if(recs_Plus[i].pos1 == ncb->recs_Plus[j].pos1)
                {
                 fprintf(fp1,"%s\t%d\t%s\t%f\t%d\t%s\n",recs_Plus[i].name,1,recs_Plus[i].PrC,recs_Plus[i].Rs,recs_Plus[i].len,ncb->recs_Plus[j].name);
                 strcpy(arr_Absolute1[abs_Count1].name,recs_Plus[i].name);
                 strcpy(arr_Absolute1[abs_Count1].PrC,recs_Plus[i].PrC);
                 arr_Absolute1[abs_Count1].Rs = recs_Plus[i].Rs;
                 arr_Absolute1[abs_Count1].len = recs_Plus[i].len;
                 arr_Absolute1[abs_Count1].pos1 = recs_Plus[i].pos1;
                 arr_Absolute1[abs_Count1].pos2 = recs_Plus[i].pos2;
                 arr_Absolute1[abs_Count1].flag = 0;
                 ++abs_Count1;
                }
                else
                {
                       fprintf(fp1,"%s\t%d\t%s\t%f\t%d\t%s\n",recs_Plus[i].name,2,recs_Plus[i].PrC,recs_Plus[i].Rs,recs_Plus[i].len,ncb->recs_Plus[j].name);
                       strcpy(arr_Stop_Only1[stopOnly_Count1].name,recs_Plus[i].name);
                 strcpy(arr_Stop_Only1[stopOnly_Count1].PrC,recs_Plus[i].PrC);
                 arr_Stop_Only1[stopOnly_Count1].Rs = recs_Plus[i].Rs;
                 arr_Stop_Only1[stopOnly_Count1].len = recs_Plus[i].len;
                 arr_Stop_Only1[stopOnly_Count1].pos1 = recs_Plus[i].pos1;
                 arr_Stop_Only1[stopOnly_Count1].pos2 = recs_Plus[i].pos2;
                 arr_Stop_Only1[stopOnly_Count1].flag = 0;
                 ++stopOnly_Count1;
                }
                ncb->recs_Plus[j].flag = TRUE;
                matched_flag = true; 
                break;
            }
        }
        if(matched_flag == false)
        {
             fprintf(fp1,"%s\t%d\t%s\t%f\t%d\n",recs_Plus[i].name,3,recs_Plus[i].PrC,recs_Plus[i].Rs,recs_Plus[i].len);
             Position2_Array_Plus[uniq_Count1].pos2 = recs_Plus[i].pos2;
             Position2_Array_Plus[uniq_Count1].flag = 0;
             strcpy(arr_Uniq1[uniq_Count1].name,recs_Plus[i].name);
             strcpy(arr_Uniq1[uniq_Count1].PrC,recs_Plus[i].PrC);
             arr_Uniq1[uniq_Count1].Rs = recs_Plus[i].Rs;
             arr_Uniq1[uniq_Count1].len = recs_Plus[i].len;
             arr_Uniq1[uniq_Count1].pos1 = recs_Plus[i].pos1;
             arr_Uniq1[uniq_Count1].pos2 = recs_Plus[i].pos2;
             arr_Uniq1[uniq_Count1].flag = 0;
             ++uniq_Count1;
        }
   }
   fclose(fp1); 
   fp1 = NULL;
   sprintf(query2,"%s/Result+3.txt",query);
   fp1 = fopen(query2,"w");
   for(int i = 0; i < recNum_Plus_Zero; i++)
   {
        for(int j = 0; j < ncb->recNum_Plus; j++)
        {
            if(recs_Plus_Zero[i].pos2 == ncb->recs_Plus[j].pos2)
            {
               if(recs_Plus_Zero[i].pos1 == ncb->recs_Plus[j].pos1)
               { 
                      ncb->recs_Plus[j].flag = TRUE;
                      fprintf(fp1,"%s\t%d\t%s\t%f\t%d\t%s\n",recs_Plus_Zero[i].name,1,recs_Plus_Zero[i].PrC,recs_Plus_Zero[i].Rs,recs_Plus_Zero[i].len,ncb->recs_Plus[j].name);
                      ++Gene_NonGenePred_Count1;
               }
               else
               {
                      fprintf(fp1,"%s\t%d\t%s\t%f\t%d\t%s\n",recs_Plus_Zero[i].name,2,recs_Plus_Zero[i].PrC,recs_Plus_Zero[i].Rs,recs_Plus_Zero[i].len,ncb->recs_Plus[j].name);
                      ++nonGene_Count1;
               }
            }
        }
   }
   fclose(fp1);
   fp1 = NULL;
   sprintf(query2,"%s/Result+2.txt",query);
   fp1 = fopen(query2,"w");
   for(int j = 0; j < ncb->recNum_Plus; j++)
   {
      if(ncb->recs_Plus[j].flag == FALSE)
      {
           fprintf(fp1,"%s\t%d\t%d\n",ncb->recs_Plus[j].name,ncb->recs_Plus[j].pos1,ncb->recs_Plus[j].pos2);
           ++missed_Count1;
      }
   }
   fclose(fp1); 
   fp1 = NULL;
   int temp;
   for(int i = 0; i < uniq_Count1 - 1; i++)
   {
       temp = Position2_Array_Plus[i].pos2;
       for(int j = i+1; j < uniq_Count1; j++)
       {
          if(temp == Position2_Array_Plus[j].pos2)  //Unique 2
          {
               Position2_Array_Plus[j].flag = 1;
               printf("\nPos2: %d\n",Position2_Array_Plus[j].pos2);
          }
       }
   }
   
   for(int i = 0; i < uniq_Count1; i++)
   {
      if(Position2_Array_Plus[i].flag == 0)
             ++uniq_Count1_Check;
   }
  
   fflush(stdin);
   fflush(stdout);
   //----------------------------------------------------------------------------------------------------------------------
   arr_Absolute2 = new RecFields2[recNum_Minus];
   arr_Stop_Only2 = new RecFields2[recNum_Minus];
   arr_Uniq2 = new RecFields2[recNum_Minus];
   
   /////////////////////////////////////////////////////////////////////Negative Strand
   abs_Count2 = stopOnly_Count2 = uniq_Count2 = uniq_Count2_Check = missed_Count2 = Gene_NonGenePred_Count2 = nonGene_Count2 = 0;
   fp1 = NULL;
   sprintf(query2,"%s/Result-1.txt",query);
   fp1 = fopen(query2,"w");
   for(int i = 0; i < recNum_Minus; i++)
   {
        matched_flag = false;
        for(int j = 0; j < ncb->recNum_Minus; j++)
        {
            if(recs_Minus[i].pos2 == ncb->recs_Minus[j].pos1) 
            {
                if(recs_Minus[i].pos1 == ncb->recs_Minus[j].pos2)
                {
                      fprintf(fp1,"%s\t%d\t%s\t%f\t%d\t%s\n",recs_Minus[i].name,1,recs_Minus[i].PrC,recs_Minus[i].Rs,recs_Minus[i].len,ncb->recs_Minus[j].name); 
                      strcpy(arr_Absolute2[abs_Count2].name,recs_Minus[i].name);
                      strcpy(arr_Absolute2[abs_Count2].PrC,recs_Minus[i].PrC);
                      arr_Absolute2[abs_Count2].Rs = recs_Minus[i].Rs;
                      arr_Absolute2[abs_Count2].len = recs_Minus[i].len;
                      arr_Absolute2[abs_Count2].pos1 = recs_Minus[i].pos2;
                      arr_Absolute2[abs_Count2].pos2 = recs_Minus[i].pos1;
                      arr_Absolute2[abs_Count2].flag = 0;
                      ++abs_Count2;
                }
                else
                {
                      fprintf(fp1,"%s\t%d\t%s\t%f\t%d\t%s\n",recs_Minus[i].name,2,recs_Minus[i].PrC,recs_Minus[i].Rs,recs_Minus[i].len,ncb->recs_Minus[j].name);
                      strcpy(arr_Stop_Only2[stopOnly_Count2].name,recs_Minus[i].name);
                      strcpy(arr_Stop_Only2[stopOnly_Count2].PrC,recs_Minus[i].PrC);
                      arr_Stop_Only2[stopOnly_Count2].Rs = recs_Minus[i].Rs;
                      arr_Stop_Only2[stopOnly_Count2].len = recs_Minus[i].len;
                      arr_Stop_Only2[stopOnly_Count2].pos1 = recs_Minus[i].pos2;
                      arr_Stop_Only2[stopOnly_Count2].pos2 = recs_Minus[i].pos1;
                      arr_Stop_Only2[stopOnly_Count2].flag = 0;
                      ++stopOnly_Count2;
                }
                ncb->recs_Minus[j].flag = TRUE;
                matched_flag = true;
                break; 
            }
        }
        if(matched_flag == false)
        { 
             fprintf(fp1,"%s\t%d\t%s\t%f\t%d\n",recs_Minus[i].name,3,recs_Minus[i].PrC,recs_Minus[i].Rs,recs_Minus[i].len);
             Position2_Array_Minus[uniq_Count2].pos2 = recs_Minus[i].pos2; 
             Position2_Array_Minus[uniq_Count2].flag = 0; 
             strcpy(arr_Uniq2[uniq_Count2].name,recs_Minus[i].name);
             strcpy(arr_Uniq2[uniq_Count2].PrC,recs_Minus[i].PrC);
             arr_Uniq2[uniq_Count2].Rs = recs_Minus[i].Rs;
             arr_Uniq2[uniq_Count2].len = recs_Minus[i].len;
             arr_Uniq2[uniq_Count2].pos1 = recs_Minus[i].pos2;
             arr_Uniq2[uniq_Count2].pos2 = recs_Minus[i].pos1;
             arr_Uniq2[uniq_Count2].flag = 0;
             ++uniq_Count2;
        }
   }
   fclose(fp1); 
   fp1 = NULL;
   sprintf(query2,"%s/Result-3.txt",query);
   fp1 = fopen(query2,"w");
   for(int i = 0; i < recNum_Minus_Zero; i++)
   {
        for(int j = 0; j < ncb->recNum_Minus; j++)
        {
            if(recs_Minus_Zero[i].pos2 == ncb->recs_Minus[j].pos1 ) 
            {
                if(recs_Minus_Zero[i].pos1 == ncb->recs_Minus[j].pos2)
                {
                      ncb->recs_Minus[j].flag = TRUE;  
                      fprintf(fp1,"%s\t%d\t%s\t%f\t%d\t%s\n",recs_Minus_Zero[i].name,1,recs_Minus_Zero[i].PrC,recs_Minus_Zero[i].Rs,recs_Minus_Zero[i].len,ncb->recs_Minus[j].name);
                      ++Gene_NonGenePred_Count2;
                } 
                else
                {
                     fprintf(fp1,"%s\t%d\t%s\t%f\t%d\t%s\n",recs_Minus_Zero[i].name,2,recs_Minus_Zero[i].PrC,recs_Minus_Zero[i].Rs,recs_Minus_Zero[i].len,ncb->recs_Minus[j].name);
                     ++nonGene_Count2;
                }
            }
        }
   }
   fclose(fp1); 
   fp1 = NULL;
   sprintf(query2,"%s/Result-2.txt",query);
   fp1 = fopen(query2,"w");
   for(int j = 0; j < ncb->recNum_Minus; j++)
   {
      if(ncb->recs_Minus[j].flag == FALSE)
      {
           fprintf(fp1,"%s\t%d\t%d\n",ncb->recs_Minus[j].name,ncb->recs_Minus[j].pos1,ncb->recs_Minus[j].pos2);
           ++missed_Count2;
      }
   }
   fclose(fp1);
   fp1 = NULL;

   for(int i = 0; i < uniq_Count2 - 1; i++)
   {
       temp = Position2_Array_Minus[i].pos2;
       for(int j= i+1; j < uniq_Count2; j++)
       {
          if(temp == Position2_Array_Minus[j].pos2)
          {
               Position2_Array_Minus[j].flag = 1;
               printf("\nPos2: %d\n",Position2_Array_Minus[j].pos2);
          }
       }
   }
   
   for(int i = 0; i < uniq_Count2; i++)
   {
      if(Position2_Array_Minus[i].flag == 0)
             ++uniq_Count2_Check;
   }
//----------------------------------------------------------------------------------------------------------------------
   sprintf(query2,"%s/Output_Help",query);
   fp1 = fopen(query2,"w");
   fprintf(fp1,"Cmmand line Output description : \n");     
   fprintf(fp1,"1 ORFs detected by both our program and NCBI annotation as genes\n");
   fprintf(fp1,"2 Stop codon matched with NCBI, but different start (Multiple start codons)\n");    
   fprintf(fp1,"3 ORFs detected by our program as genes but missed in NCBI annotation\n");     
   fprintf(fp1,"4 ORFs detected in NCBI annotation as genes but missed by our program (missed for some other reasons like gene length (<300), start codon other than ATG, GTG etc\n");
   fprintf(fp1,"5 ORFs detected in NCBI annotation as genes but predicted as non gene by our program\n");   
   fprintf(fp1,"6 ORFs  predicted as non gene by both our program and NCBI annotation\n\n\n");
   fprintf(fp1,"Output file description\n");
   fprintf(fp1,"Result+1.txt file contains ----->\n");
   fprintf(fp1,"     1 ORFs detected by both our program and NCBI annotation as genes\n");
   fprintf(fp1,"     2 Stop codon matched with NCBI, but different start (Multiple start codons\n"); 
   fprintf(fp1,"     3 ORFs detected by our program as genes but missed in NCBI annotation\n\n"); 
   fprintf(fp1,"Result+2.txt file contains------>\n");
   fprintf(fp1,"                                   ORFs detected in NCBI annotation as genes but missed by our program (missed for some other reasons like gene length (<300), start codon other than ATG, GTG etc)\n\n");
   fprintf(fp1,"Result+3.txt file contains------->\n");
   fprintf(fp1,"                                   ORFs detected in NCBI annotation as genes but predicted as non gene by our program\n");
   fprintf(fp1,"                                   1 Stop and Start Codon matched.\n"); 
   fprintf(fp1,"                                   2 Stop codon matched with NCBI, but different start (Multiple start codons)\n\n");  
   fprintf(fp1,"(Same description for - files, for negative strand)\n");  
   fclose(fp1);
   fp1 = NULL;
   //////////////////////////////////////////////////////////////////////////////////////
   ////////////////////////////////////////////////////////////For Positive Strand(5'->3')
   int arr_Size1,arr_Size2;
   arr_Size1 = uniq_Count1;
   //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
   //////////This Part is appended for Calculation excluding(but in) Hypothetical Proteins in Plus Strand//////////////////////
   int Our_Hypothetical_Plus = 0;
   abs_Count3 = stopOnly_Count3 = 0;
   if(isHypo == 'N')
   {
    arr_Absolute3 = new RecFields2[uniq_Count1];
 arr_Stop_Only3 = new RecFields2[uniq_Count1];
   
  for(int i = 0; i < arr_Size1; ++i)
  {
     for(int j = 0; j < ncb->hypo_Plus; j++)
     {
         if(arr_Uniq1[i].pos2 == ncb->recs_Hypo_Plus[j].pos2) 
         {
             if(arr_Uniq1[i].pos1 == ncb->recs_Hypo_Plus[j].pos1)
             { 
               strcpy(arr_Absolute3[abs_Count3].name,arr_Uniq1[i].name);
                 arr_Absolute3[abs_Count3].len = arr_Uniq1[i].len;
                 arr_Absolute3[abs_Count3].pos1 = arr_Uniq1[i].pos1;
                 arr_Absolute3[abs_Count3].pos2 = arr_Uniq1[i].pos2;
                 arr_Absolute3[abs_Count3].flag = 0;
                 ++abs_Count3;
                 arr_Uniq1[i].flag = 1;
             }
             else
             {
               strcpy(arr_Stop_Only3[stopOnly_Count3].name,arr_Uniq1[i].name);
                 arr_Stop_Only3[stopOnly_Count3].len = arr_Uniq1[i].len;
                 arr_Stop_Only3[stopOnly_Count3].pos1 = arr_Uniq1[i].pos1;
                 arr_Stop_Only3[stopOnly_Count3].pos2 = arr_Uniq1[i].pos2;
                 arr_Stop_Only3[stopOnly_Count3].flag = 0;
                 ++stopOnly_Count3;
                 arr_Uniq1[i].flag = 1;
             }
             ncb->recs_Hypo_Plus[j].flag = TRUE;
             break;
         }
     }
  }
  Our_Hypothetical_Plus = abs_Count3 + stopOnly_Count3;
  fp1 = NULL;
  sprintf(query2,"%s/Result+2.txt",query);
  fp1 = fopen(query2,"a");
  for(int j = 0; j < ncb->hypo_Plus; j++)
  {
      if(ncb->recs_Hypo_Plus[j].flag == FALSE)
      {
           fprintf(fp1,"%s\t%d\t%d\n",ncb->recs_Hypo_Plus[j].name,ncb->recs_Hypo_Plus[j].pos1,ncb->recs_Hypo_Plus[j].pos2);
           ++missed_Count1;
      }
  }
  fclose(fp1);
  fp1 = NULL;
   }
   /////////This Part is appended for Calculation excluding(but in) Hypothetical Proteins in Plus Strand(END)//////////////////
   //////////This Part is appended for Calculation excluding(but in) Hypothetical Proteins in Minus Strand//////////////////////
   int Our_Hypothetical_Minus = 0;
   abs_Count4= stopOnly_Count4= 0;
   if(isHypo == 'N')
   {
 arr_Absolute4 = new RecFields2[uniq_Count2];
 arr_Stop_Only4 = new RecFields2[uniq_Count2];
 
 for(int i = 0; i < uniq_Count2; ++i)
 {
     for(int j = 0; j < ncb->hypo_Minus; j++)
     {
         if(arr_Uniq2[i].pos2 == ncb->recs_Hypo_Minus[j].pos1) 
         {
            if(arr_Uniq2[i].pos1 == ncb->recs_Hypo_Minus[j].pos2)
            { 
             strcpy(arr_Absolute4[abs_Count4].name,arr_Uniq2[i].name);
                 arr_Absolute4[abs_Count4].len = arr_Uniq2[i].len;
                 arr_Absolute4[abs_Count4].pos1 = arr_Uniq2[i].pos1;
                 arr_Absolute4[abs_Count4].pos2 = arr_Uniq2[i].pos2;
                 arr_Absolute4[abs_Count4].flag = 0;
                 ++abs_Count4;
                arr_Uniq2[i].flag = 1;
             }
             else
             {
              strcpy(arr_Stop_Only4[stopOnly_Count4].name,arr_Uniq2[i].name);
                 arr_Stop_Only4[stopOnly_Count4].len = arr_Uniq2[i].len;
                 arr_Stop_Only4[stopOnly_Count4].pos1 = arr_Uniq2[i].pos1;
                 arr_Stop_Only4[stopOnly_Count4].pos2 = arr_Uniq2[i].pos2;
                 arr_Stop_Only4[stopOnly_Count4].flag = 0;
                 ++stopOnly_Count4;
                 arr_Uniq2[i].flag = 1;
             }
             ncb->recs_Hypo_Minus[j].flag = TRUE;
             break;
         }
	    }
	}
	Our_Hypothetical_Minus = abs_Count4 + stopOnly_Count4;
	fp1 = NULL;
	sprintf(query2,"%s/Result-2.txt",query);
	fp1 = fopen(query2,"a");
	for(int j = 0; j < ncb->hypo_Minus; j++)
	{
	   if(ncb->recs_Hypo_Minus[j].flag == FALSE)
	   {
	        fprintf(fp1,"%s\t%d\t%d\n",ncb->recs_Hypo_Minus[j].name,ncb->recs_Hypo_Minus[j].pos1,ncb->recs_Hypo_Minus[j].pos2);
	        ++missed_Count2;
	   }
	}
	fclose(fp1);
	fp1 = NULL;
   }
   /////////This Part is appended for Calculation excluding(but in) Hypothetical Proteins in Minus Strand(END)/////////////////
   //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
   ///////////////////////////////Positive Uniq is checked against Positive Sequence(+1 & +2)//////////////////////////////////
   arr_Size2 = abs_Count1;
   for(int i = 0; i < arr_Size1; ++i)
   {
    if(arr_Uniq1[i].flag == 0)
 {
  for(int j = 0; j < arr_Size2; ++j)
  {
   if((arr_Uniq1[i].pos1 >= arr_Absolute1[j].pos1) && (arr_Uniq1[i].pos2 <= arr_Absolute1[j].pos2)) //within absolute sequence
   {
    --uniq_Count1;
    arr_Uniq1[i].flag = 1;
    strcpy(arr_Uniq1[i].match_Seq,arr_Absolute1[j].name);
    arr_Uniq1[i].percent_Match = 100;
    arr_Uniq1[i].match_Type = 0;
    break;
   }
   else if((arr_Uniq1[i].pos2 >= arr_Absolute1[j].pos1) && (arr_Uniq1[i].pos2 <= arr_Absolute1[j].pos2)) //pos2 within absolute sequence
   {
    arr_Uniq1[i].percent_Match = (double(abs(arr_Uniq1[i].pos2 - arr_Absolute1[j].pos1) + 1)/double(abs(arr_Uniq1[i].pos2 - arr_Uniq1[i].pos1) + 1)) * 100.0;
    if(arr_Uniq1[i].percent_Match >= 0.1)
    {
     --uniq_Count1;
     arr_Uniq1[i].flag = 1;
     strcpy(arr_Uniq1[i].match_Seq,arr_Absolute1[j].name);
     arr_Uniq1[i].match_Type = 1;
     break;
    }
   }
   else if((arr_Uniq1[i].pos1 >= arr_Absolute1[j].pos1) && (arr_Uniq1[i].pos1 <= arr_Absolute1[j].pos2)) //pos1 within absolute sequence
   {
    arr_Uniq1[i].percent_Match = (double(abs(arr_Absolute1[j].pos2 - arr_Uniq1[i].pos1) + 1)/double(abs(arr_Uniq1[i].pos2 - arr_Uniq1[i].pos1) + 1)) * 100.0;
    if(arr_Uniq1[i].percent_Match >= 0.1)
    {
					--uniq_Count1;
					arr_Uniq1[i].flag = 1;
					strcpy(arr_Uniq1[i].match_Seq,arr_Absolute1[j].name);
					arr_Uniq1[i].match_Type = 2;
					break;
				}
			}
			else if((arr_Uniq1[i].pos1 < arr_Absolute1[j].pos1) && (arr_Uniq1[i].pos2 > arr_Absolute1[j].pos2)) //uniq sequence cover absolute sequence
			{
				--uniq_Count1;
				arr_Uniq1[i].flag = 1;
				strcpy(arr_Uniq1[i].match_Seq,arr_Absolute1[j].name);
				arr_Uniq1[i].percent_Match = 100;
				arr_Uniq1[i].match_Type = 3;
				break;
			}
  }
 }
   }
   //.............................................................................................................................
   arr_Size2 = stopOnly_Count1;
   for(int i = 0; i < arr_Size1; ++i)
   {
 if(arr_Uniq1[i].flag == 0)
 {
  for(int j = 0; j < arr_Size2; ++j)
  {
   if((arr_Uniq1[i].pos1 >= arr_Stop_Only1[j].pos1) && (arr_Uniq1[i].pos2 <= arr_Stop_Only1[j].pos2)) //within Stop Only sequence
   {
    --uniq_Count1;
    arr_Uniq1[i].flag = 1;
    strcpy(arr_Uniq1[i].match_Seq,arr_Stop_Only1[j].name);
    arr_Uniq1[i].percent_Match = 100;
    arr_Uniq1[i].match_Type = 0;
    break;
   }
   else if((arr_Uniq1[i].pos2 >= arr_Stop_Only1[j].pos1) && (arr_Uniq1[i].pos2 <= arr_Stop_Only1[j].pos2)) //pos2 within Stop Only sequence
   {
    arr_Uniq1[i].percent_Match = (double(abs(arr_Uniq1[i].pos2 - arr_Stop_Only1[j].pos1) + 1)/double(abs(arr_Uniq1[i].pos2 - arr_Uniq1[i].pos1) + 1)) * 100.0;
    if(arr_Uniq1[i].percent_Match >= 0.1)
    {
     --uniq_Count1;
     arr_Uniq1[i].flag = 1;
     strcpy(arr_Uniq1[i].match_Seq,arr_Stop_Only1[j].name);
     arr_Uniq1[i].match_Type = 1;
     break;
    }
   }
   else if((arr_Uniq1[i].pos1 >= arr_Stop_Only1[j].pos1) && (arr_Uniq1[i].pos1 <= arr_Stop_Only1[j].pos2)) //pos1 within Stop Only sequence
   {
    arr_Uniq1[i].percent_Match = (double(abs(arr_Stop_Only1[j].pos2 - arr_Uniq1[i].pos1) + 1)/double(abs(arr_Uniq1[i].pos2 - arr_Uniq1[i].pos1) + 1)) * 100.0;
    if(arr_Uniq1[i].percent_Match >= 0.1)
    {
     --uniq_Count1;
					arr_Uniq1[i].flag = 1;
					strcpy(arr_Uniq1[i].match_Seq,arr_Stop_Only1[j].name);
					arr_Uniq1[i].match_Type = 2;
					break;
				}
			}
   else if((arr_Uniq1[i].pos1 < arr_Stop_Only1[j].pos1) && (arr_Uniq1[i].pos2 > arr_Stop_Only1[j].pos2)) //uniq sequence cover Stop Only sequence
   {
    --uniq_Count1;
    arr_Uniq1[i].flag = 1;
    strcpy(arr_Uniq1[i].match_Seq,arr_Stop_Only1[j].name);
    arr_Uniq1[i].percent_Match = 100;
    arr_Uniq1[i].match_Type = 3;
    break;
   }
  }
 }
   }
   ///////////////////////////////Positive Uniq is checked against Positive Sequence(+1 & +2) END///////////////////////////////////////
   if(isHypo == 'N')
   {
    ///////////////////////////////Positive Uniq is checked against Positive Hypothetical Sequence(+1 & +2)//////////////////////////////
    arr_Size2 = abs_Count3;
    for(int i = 0; i < arr_Size1; ++i)
    {
     if(arr_Uniq1[i].flag == 0)
  {
   for(int j = 0; j < arr_Size2; ++j)
   {
    if((arr_Uniq1[i].pos1 >= arr_Absolute3[j].pos1) && (arr_Uniq1[i].pos2 <= arr_Absolute3[j].pos2)) //within absolute sequence
    {
     --uniq_Count1;
     arr_Uniq1[i].flag = 1;
     strcpy(arr_Uniq1[i].match_Seq,arr_Absolute3[j].name);
     arr_Uniq1[i].percent_Match = 100;
     arr_Uniq1[i].match_Type = 0;
     break;
    }
    else if((arr_Uniq1[i].pos2 >= arr_Absolute3[j].pos1) && (arr_Uniq1[i].pos2 <= arr_Absolute3[j].pos2)) //pos2 within absolute sequence
    {
     arr_Uniq1[i].percent_Match = (double(abs(arr_Uniq1[i].pos2 - arr_Absolute3[j].pos1) + 1)/double(abs(arr_Uniq1[i].pos2 - arr_Uniq1[i].pos1) + 1)) * 100.0;
     if(arr_Uniq1[i].percent_Match >= 0.1)
					{
      --uniq_Count1;
      arr_Uniq1[i].flag = 1;
      strcpy(arr_Uniq1[i].match_Seq,arr_Absolute3[j].name);
      arr_Uniq1[i].match_Type = 1;
      break;
     }
    }
    else if((arr_Uniq1[i].pos1 >= arr_Absolute3[j].pos1) && (arr_Uniq1[i].pos1 <= arr_Absolute3[j].pos2)) //pos1 within absolute sequence
    {
     arr_Uniq1[i].percent_Match = (double(abs(arr_Absolute3[j].pos2 - arr_Uniq1[i].pos1) + 1)/double(abs(arr_Uniq1[i].pos2 - arr_Uniq1[i].pos1) + 1)) * 100.0;
     if(arr_Uniq1[i].percent_Match >= 0.1)
     {
      --uniq_Count1;
      arr_Uniq1[i].flag = 1;
      strcpy(arr_Uniq1[i].match_Seq,arr_Absolute3[j].name);
      arr_Uniq1[i].match_Type = 2;
      break;
     }
    }
    else if((arr_Uniq1[i].pos1 < arr_Absolute3[j].pos1) && (arr_Uniq1[i].pos2 > arr_Absolute3[j].pos2)) //uniq sequence cover absolute sequence
    {
     --uniq_Count1;
     arr_Uniq1[i].flag = 1;
     strcpy(arr_Uniq1[i].match_Seq,arr_Absolute3[j].name);
     arr_Uniq1[i].percent_Match = 100;
     arr_Uniq1[i].match_Type = 3;
     break;
    }
   }
  }
    }
    //...................................................................................................................................................................
    arr_Size2 = stopOnly_Count3;
    for(int i = 0; i < arr_Size1; ++i)
    {
  if(arr_Uniq1[i].flag == 0)
  {
   for(int j = 0; j < arr_Size2; ++j)
   {
    if((arr_Uniq1[i].pos1 >= arr_Stop_Only3[j].pos1) && (arr_Uniq1[i].pos2 <= arr_Stop_Only3[j].pos2)) //within Stop Only sequence
    {
     --uniq_Count1;
     arr_Uniq1[i].flag = 1;
     strcpy(arr_Uniq1[i].match_Seq,arr_Stop_Only3[j].name);
     arr_Uniq1[i].percent_Match = 100;
     arr_Uniq1[i].match_Type = 0;
     break;
    }
    else if((arr_Uniq1[i].pos2 >= arr_Stop_Only3[j].pos1) && (arr_Uniq1[i].pos2 <= arr_Stop_Only3[j].pos2)) //pos2 within Stop Only sequence
    {
     arr_Uniq1[i].percent_Match = (double(abs(arr_Uniq1[i].pos2 - arr_Stop_Only3[j].pos1) + 1)/double(abs(arr_Uniq1[i].pos2 - arr_Uniq1[i].pos1) + 1)) * 100.0;
     if(arr_Uniq1[i].percent_Match >= 0.1)
     {
      --uniq_Count1;
						arr_Uniq1[i].flag = 1;
						strcpy(arr_Uniq1[i].match_Seq,arr_Stop_Only3[j].name);
						arr_Uniq1[i].match_Type = 1;
						break;
     }
    }
    else if((arr_Uniq1[i].pos1 >= arr_Stop_Only3[j].pos1) && (arr_Uniq1[i].pos1 <= arr_Stop_Only3[j].pos2)) //pos1 within Stop Only sequence
    {
     arr_Uniq1[i].percent_Match = (double(abs(arr_Stop_Only3[j].pos2 - arr_Uniq1[i].pos1) + 1)/double(abs(arr_Uniq1[i].pos2 - arr_Uniq1[i].pos1) + 1)) * 100.0;
     if(arr_Uniq1[i].percent_Match >= 0.1)
     {
      --uniq_Count1;
      arr_Uniq1[i].flag = 1;
      strcpy(arr_Uniq1[i].match_Seq,arr_Stop_Only3[j].name);
      arr_Uniq1[i].match_Type = 2;
      break;
     }
    }
    else if((arr_Uniq1[i].pos1 < arr_Stop_Only3[j].pos1) && (arr_Uniq1[i].pos2 > arr_Stop_Only3[j].pos2)) //uniq sequence cover Stop Only sequence
    {
     --uniq_Count1;
     arr_Uniq1[i].flag = 1;
     strcpy(arr_Uniq1[i].match_Seq,arr_Stop_Only3[j].name);
     arr_Uniq1[i].percent_Match = 100;
     arr_Uniq1[i].match_Type = 3;
     break;
    }
			}
		}
	  }
   ///////////////////////////////Positive Uniq is checked against Positive Hypothetical Sequence(+1 & +2) END//////////////////////////
   }
   //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
   ///////////////////////////////Positive Uniq is checked against Negative Sequence(-1 & -2)///////////////////////////////////////////
   arr_Size2 = abs_Count2;
   for(int i = 0; i < arr_Size1; ++i)
   {
 if(arr_Uniq1[i].flag == 0)
 {
  for(int j = 0; j < arr_Size2; ++j)
  {
   if((arr_Uniq1[i].pos1 >= arr_Absolute2[j].pos1) && (arr_Uniq1[i].pos2 <= arr_Absolute2[j].pos2)) //within absolute sequence
   {
    --uniq_Count1;
    arr_Uniq1[i].flag = 1;
    strcpy(arr_Uniq1[i].match_Seq,arr_Absolute2[j].name);
    arr_Uniq1[i].percent_Match = 100;
    arr_Uniq1[i].match_Type = 0;
    break;
   }
   else if((arr_Uniq1[i].pos2 >= arr_Absolute2[j].pos1) && (arr_Uniq1[i].pos2 <= arr_Absolute2[j].pos2)) //pos2 within absolute sequence
   {
    arr_Uniq1[i].percent_Match = (double(abs(arr_Uniq1[i].pos2 - arr_Absolute2[j].pos1) + 1)/double(abs(arr_Uniq1[i].pos2 - arr_Uniq1[i].pos1) + 1)) * 100.0;
				if(arr_Uniq1[i].percent_Match >= 0.1)
				{
					--uniq_Count1;
     arr_Uniq1[i].flag = 1;
     strcpy(arr_Uniq1[i].match_Seq,arr_Absolute2[j].name);
     arr_Uniq1[i].match_Type = 1;
     break;
    }
   }
   else if((arr_Uniq1[i].pos1 >= arr_Absolute2[j].pos1) && (arr_Uniq1[i].pos1 <= arr_Absolute2[j].pos2)) //pos1 within absolute sequence
   {
    arr_Uniq1[i].percent_Match = (double(abs(arr_Absolute2[j].pos2 - arr_Uniq1[i].pos1) + 1)/double(abs(arr_Uniq1[i].pos2 - arr_Uniq1[i].pos1) + 1)) * 100.0;
    if(arr_Uniq1[i].percent_Match >= 0.1)
    {
     --uniq_Count1;
     arr_Uniq1[i].flag = 1;
     strcpy(arr_Uniq1[i].match_Seq,arr_Absolute2[j].name);
     arr_Uniq1[i].match_Type = 2;
     break;
    }
   }
   else if((arr_Uniq1[i].pos1 < arr_Absolute2[j].pos1) && (arr_Uniq1[i].pos2 > arr_Absolute2[j].pos2)) //uniq sequence cover absolute sequence
   {
    --uniq_Count1;
    arr_Uniq1[i].flag = 1;
    strcpy(arr_Uniq1[i].match_Seq,arr_Absolute2[j].name);
    arr_Uniq1[i].percent_Match = 100;
    arr_Uniq1[i].match_Type = 3;
				break;
			}
		}
 }
   }
   //...................................................................................................................
   arr_Size2 = stopOnly_Count2;
   for(int i = 0; i < arr_Size1; ++i)
   {
 if(arr_Uniq1[i].flag == 0)
 {
  for(int j = 0; j < arr_Size2; ++j)
  {
   if((arr_Uniq1[i].pos1 >= arr_Stop_Only2[j].pos1) && (arr_Uniq1[i].pos2 <= arr_Stop_Only2[j].pos2))
   {
    --uniq_Count1;
    arr_Uniq1[i].flag = 1;
    strcpy(arr_Uniq1[i].match_Seq,arr_Stop_Only2[j].name);
    arr_Uniq1[i].percent_Match = 100;
    arr_Uniq1[i].match_Type = 0;
    break;
   }
   else if((arr_Uniq1[i].pos2 >= arr_Stop_Only2[j].pos1) && (arr_Uniq1[i].pos2 <= arr_Stop_Only2[j].pos2))
   {
    arr_Uniq1[i].percent_Match = (double(abs(arr_Uniq1[i].pos2 - arr_Stop_Only2[j].pos1) + 1)/double(abs(arr_Uniq1[i].pos2 - arr_Uniq1[i].pos1) + 1)) * 100.0;
    if(arr_Uniq1[i].percent_Match >= 0.1)
    {
     --uniq_Count1;
     arr_Uniq1[i].flag = 1;
     strcpy(arr_Uniq1[i].match_Seq,arr_Stop_Only2[j].name);
     arr_Uniq1[i].match_Type = 1;
     break;
    }
   }
   else if((arr_Uniq1[i].pos1 >= arr_Stop_Only2[j].pos1) && (arr_Uniq1[i].pos1 <= arr_Stop_Only2[j].pos2))
   {
    arr_Uniq1[i].percent_Match = (double(abs(arr_Stop_Only2[j].pos2 - arr_Uniq1[i].pos1) + 1)/double(abs(arr_Uniq1[i].pos2 - arr_Uniq1[i].pos1) + 1)) * 100.0;
    if(arr_Uniq1[i].percent_Match >= 0.1)
    {
					--uniq_Count1;
					arr_Uniq1[i].flag = 1;
					strcpy(arr_Uniq1[i].match_Seq,arr_Stop_Only2[j].name);
					arr_Uniq1[i].match_Type = 2;
					break;
				}
			}
   else if((arr_Uniq1[i].pos1 < arr_Stop_Only2[j].pos1) && (arr_Uniq1[i].pos2 > arr_Stop_Only2[j].pos2))
   {
    --uniq_Count1;
    arr_Uniq1[i].flag = 1;
    strcpy(arr_Uniq1[i].match_Seq,arr_Stop_Only2[j].name);
    arr_Uniq1[i].percent_Match = 100;
    arr_Uniq1[i].match_Type = 3;
    break;
   }
  }
 }
   }
   ///////////////////////////////Positive Uniq is checked against Negative Sequence(-1 & -2) END///////////////////////////////////////
   //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
   if(isHypo == 'N')
   {
    ///////////////////////////////Positive Uniq is checked against Negative Hypothetical Sequence(-1 & -2)//////////////////////////////
    arr_Size2 = abs_Count4;
    for(int i = 0; i < arr_Size1; ++i)
    {
  if(arr_Uniq1[i].flag == 0)
		{
			for(int j = 0; j < arr_Size2; ++j)
			{
    if((arr_Uniq1[i].pos1 >= arr_Absolute4[j].pos1) && (arr_Uniq1[i].pos2 <= arr_Absolute4[j].pos2)) //within absolute sequence
    {
     --uniq_Count1;
     arr_Uniq1[i].flag = 1;
     strcpy(arr_Uniq1[i].match_Seq,arr_Absolute4[j].name);
     arr_Uniq1[i].percent_Match = 100;
     arr_Uniq1[i].match_Type = 0;
     break;
    }
    else if((arr_Uniq1[i].pos2 >= arr_Absolute4[j].pos1) && (arr_Uniq1[i].pos2 <= arr_Absolute4[j].pos2)) //pos2 within absolute sequence
    {
     arr_Uniq1[i].percent_Match = (double(abs(arr_Uniq1[i].pos2 - arr_Absolute4[j].pos1) + 1)/double(abs(arr_Uniq1[i].pos2 - arr_Uniq1[i].pos1) + 1)) * 100.0;
     if(arr_Uniq1[i].percent_Match >= 0.1)
     {
      --uniq_Count1;
      arr_Uniq1[i].flag = 1;
      strcpy(arr_Uniq1[i].match_Seq,arr_Absolute4[j].name);
      arr_Uniq1[i].match_Type = 1;
      break;
     }
    }
    else if((arr_Uniq1[i].pos1 >= arr_Absolute4[j].pos1) && (arr_Uniq1[i].pos1 <= arr_Absolute4[j].pos2)) //pos1 within absolute sequence
				{
					arr_Uniq1[i].percent_Match = (double(abs(arr_Absolute4[j].pos2 - arr_Uniq1[i].pos1) + 1)/double(abs(arr_Uniq1[i].pos2 - arr_Uniq1[i].pos1) + 1)) * 100.0;
					if(arr_Uniq1[i].percent_Match >= 0.1)
					{
						--uniq_Count1;
						arr_Uniq1[i].flag = 1;
      strcpy(arr_Uniq1[i].match_Seq,arr_Absolute4[j].name);
      arr_Uniq1[i].match_Type = 2;
      break;
     }
    }
    else if((arr_Uniq1[i].pos1 < arr_Absolute4[j].pos1) && (arr_Uniq1[i].pos2 > arr_Absolute4[j].pos2)) //uniq sequence cover absolute sequence
    {
     --uniq_Count1;
     arr_Uniq1[i].flag = 1;
     strcpy(arr_Uniq1[i].match_Seq,arr_Absolute4[j].name);
     arr_Uniq1[i].percent_Match = 100;
     arr_Uniq1[i].match_Type = 3;
     break;
    }
   }
  }
    }
    //....................................................................................................................................
    arr_Size2 = stopOnly_Count4;
    for(int i = 0; i < arr_Size1; ++i)
    {
  if(arr_Uniq1[i].flag == 0)
  {
   for(int j = 0; j < arr_Size2; ++j)
   {
    if((arr_Uniq1[i].pos1 >= arr_Stop_Only4[j].pos1) && (arr_Uniq1[i].pos2 <= arr_Stop_Only4[j].pos2))
    {
     --uniq_Count1;
     arr_Uniq1[i].flag = 1;
     strcpy(arr_Uniq1[i].match_Seq,arr_Stop_Only4[j].name);
     arr_Uniq1[i].percent_Match = 100;
     arr_Uniq1[i].match_Type = 0;
     break;
    }
    else if((arr_Uniq1[i].pos2 >= arr_Stop_Only4[j].pos1) && (arr_Uniq1[i].pos2 <= arr_Stop_Only4[j].pos2))
    {
     arr_Uniq1[i].percent_Match = (double(abs(arr_Uniq1[i].pos2 - arr_Stop_Only4[j].pos1) + 1)/double(abs(arr_Uniq1[i].pos2 - arr_Uniq1[i].pos1) + 1)) * 100.0;
     if(arr_Uniq1[i].percent_Match >= 0.1)
     {
      --uniq_Count1;
      arr_Uniq1[i].flag = 1;
      strcpy(arr_Uniq1[i].match_Seq,arr_Stop_Only4[j].name);
      arr_Uniq1[i].match_Type = 1;
      break;
     }
    }
    else if((arr_Uniq1[i].pos1 >= arr_Stop_Only4[j].pos1) && (arr_Uniq1[i].pos1 <= arr_Stop_Only4[j].pos2))
    {
     arr_Uniq1[i].percent_Match = (double(abs(arr_Stop_Only4[j].pos2 - arr_Uniq1[i].pos1) + 1)/double(abs(arr_Uniq1[i].pos2 - arr_Uniq1[i].pos1) + 1)) * 100.0;
     if(arr_Uniq1[i].percent_Match >= 0.1)
     {
      --uniq_Count1;
      arr_Uniq1[i].flag = 1;
      strcpy(arr_Uniq1[i].match_Seq,arr_Stop_Only4[j].name);
      arr_Uniq1[i].match_Type = 2;
      break;
     }
    }
    else if((arr_Uniq1[i].pos1 < arr_Stop_Only4[j].pos1) && (arr_Uniq1[i].pos2 > arr_Stop_Only4[j].pos2))
    {
     --uniq_Count1;
     arr_Uniq1[i].flag = 1;
     strcpy(arr_Uniq1[i].match_Seq,arr_Stop_Only4[j].name);
     arr_Uniq1[i].percent_Match = 100;
     arr_Uniq1[i].match_Type = 3;
     break;
    }
   }
  }
    }
    ///////////////////////////////Positive Uniq is checked against Negative Hypothetical Sequence(-1 & -2) END//////////////////////////
   }
   //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
   //////////////////////////////////Recording Really Unique and Duplicate sequences in Files for Positive Strand///////////////////////
   fp1 = fp2 = NULL;
   sprintf(query2,"%s/Unique+1.txt",query);
   fp1 = fopen(query2,"w");
   sprintf(query2,"%s/Duplicate+1.txt",query);
   fp2 = fopen(query2,"w");
   fprintf(fp1,"Sequence Name\tPrediction Confidence\tR-Statistic\tLength\n");
   fprintf(fp2,"Sequence Name\tMatch Sequence in Negative Strand\tPercentage Matching\tMatch Type(0~Absolute,1~Partial(stop),2~Partial(start),"
   "3~Over absolute)\tPrediction Confidence\tR-Statistic\tLength\n");
   
   /////////////////////////////////Probable pshudo gene checking in Positive Strand for Hypothetical Proteins (END)
   for(int i = 0; i < arr_Size1; ++i)
   {
 if(arr_Uniq1[i].flag == 1)
    fprintf(fp2,"%s\t%s\t%0.2f\%\t%d\t%s\t%f\t%d\n",arr_Uniq1[i].name,arr_Uniq1[i].match_Seq,arr_Uniq1[i].percent_Match,arr_Uniq1[i].match_Type,arr_Uniq1[i].PrC,arr_Uniq1[i].Rs,arr_Uniq1[i].len);
 else if(arr_Uniq1[i].flag == 0)
    fprintf(fp1,"%s\t%s\t%f\t%d\n",arr_Uniq1[i].name,arr_Uniq1[i].PrC,arr_Uniq1[i].Rs,arr_Uniq1[i].len);
   }
   fclose(fp1);
   fclose(fp2);
   fp1 = fp2 = NULL;
   
  
   ////////////////////////////////////////////////////////////////////////For Negative strand(3'->5')////////////////////////////////////
   arr_Size1 = uniq_Count2;
   ////////////////////////////////Negative Uniq is checked against Positive Sequence(+1 & +2)////////////////////////////////////////////
   arr_Size2 = abs_Count1;
   for(int i = 0; i < arr_Size1; ++i)
   {
    if(arr_Uniq2[i].flag == 0)
 {
  for(int j = 0; j < arr_Size2; ++j)
  {
   if((arr_Uniq2[i].pos1 >= arr_Absolute1[j].pos1) && (arr_Uniq2[i].pos2 <= arr_Absolute1[j].pos2))
   {
    --uniq_Count2;
    arr_Uniq2[i].flag = 1;
    strcpy(arr_Uniq2[i].match_Seq,arr_Absolute1[j].name);
    arr_Uniq2[i].percent_Match = 100;
    arr_Uniq2[i].match_Type = 0;
    break;
   }
   else if((arr_Uniq2[i].pos2 >= arr_Absolute1[j].pos1) && (arr_Uniq2[i].pos2 <= arr_Absolute1[j].pos2))
   {
    arr_Uniq2[i].percent_Match = (double(abs(arr_Uniq2[i].pos2 - arr_Absolute1[j].pos1) + 1)/double(abs(arr_Uniq2[i].pos2 - arr_Uniq2[i].pos1) + 1)) * 100.0;
    if(arr_Uniq2[i].percent_Match >= 0.1)
    {
     --uniq_Count2;
     arr_Uniq2[i].flag = 1;
     strcpy(arr_Uniq2[i].match_Seq,arr_Absolute1[j].name);
     arr_Uniq2[i].match_Type = 1;
     break;
    }
   }
   else if((arr_Uniq2[i].pos1 >= arr_Absolute1[j].pos1) && (arr_Uniq2[i].pos1 <= arr_Absolute1[j].pos2))
   {
    arr_Uniq2[i].percent_Match = (double(abs(arr_Absolute1[j].pos2 - arr_Uniq2[i].pos1) + 1)/double(abs(arr_Uniq2[i].pos2 - arr_Uniq2[i].pos1) + 1)) * 100.0;
    if(arr_Uniq2[i].percent_Match >= 0.1)
    {
     --uniq_Count2;
     arr_Uniq2[i].flag = 1;
     strcpy(arr_Uniq2[i].match_Seq,arr_Absolute1[j].name);
     arr_Uniq2[i].match_Type = 2;
     break;
    }
			}
   else if((arr_Uniq2[i].pos1 < arr_Absolute1[j].pos1) && (arr_Uniq2[i].pos2 > arr_Absolute1[j].pos2))
   {
    --uniq_Count2;
    arr_Uniq2[i].flag = 1;
    strcpy(arr_Uniq2[i].match_Seq,arr_Absolute1[j].name);
    arr_Uniq2[i].percent_Match = 100;
    arr_Uniq2[i].match_Type = 3;
    break;
   }
  }
 }
   }
   //.......................................................................................................................................
   arr_Size2 = stopOnly_Count1;
   for(int i = 0; i < arr_Size1; ++i)
   {
 if(arr_Uniq2[i].flag == 0)
 {
  for(int j = 0; j < arr_Size2; ++j)
  {
   
   if((arr_Uniq2[i].pos1 >= arr_Stop_Only1[j].pos1) && (arr_Uniq2[i].pos2 <= arr_Stop_Only1[j].pos2))
   {
    --uniq_Count2;
    arr_Uniq2[i].flag = 1;
    strcpy(arr_Uniq2[i].match_Seq,arr_Stop_Only1[j].name);
    arr_Uniq2[i].percent_Match = 100;
    arr_Uniq2[i].match_Type = 0;
    break;
   }
   else if((arr_Uniq2[i].pos2 >= arr_Stop_Only1[j].pos1) && (arr_Uniq2[i].pos2 <= arr_Stop_Only1[j].pos2))
   {
    arr_Uniq2[i].percent_Match = (double(abs(arr_Uniq2[i].pos2 - arr_Stop_Only1[j].pos1) + 1)/double(abs(arr_Uniq2[i].pos2 - arr_Uniq2[i].pos1) + 1)) * 100.0;
    if(arr_Uniq2[i].percent_Match >= 0.1)
    {
     --uniq_Count2;
     arr_Uniq2[i].flag = 1;
     strcpy(arr_Uniq2[i].match_Seq,arr_Stop_Only1[j].name);
     arr_Uniq2[i].match_Type = 1;
     break;
    }
   }
   else if((arr_Uniq2[i].pos1 >= arr_Stop_Only1[j].pos1) && (arr_Uniq2[i].pos1 <= arr_Stop_Only1[j].pos2))
   {
    arr_Uniq2[i].percent_Match = (double(abs(arr_Stop_Only1[j].pos2 - arr_Uniq2[i].pos1) + 1)/double(abs(arr_Uniq2[i].pos2 - arr_Uniq2[i].pos1) + 1)) * 100.0;
    if(arr_Uniq2[i].percent_Match >= 0.1)
    {
     --uniq_Count2;
     arr_Uniq2[i].flag = 1;
     strcpy(arr_Uniq2[i].match_Seq,arr_Stop_Only1[j].name);
     arr_Uniq2[i].match_Type = 2;
     break;
    }
   }
   else if((arr_Uniq2[i].pos1 < arr_Stop_Only1[j].pos1) && (arr_Uniq2[i].pos2 > arr_Stop_Only1[j].pos2))
   {
    --uniq_Count2;
    arr_Uniq2[i].flag = 1;
    strcpy(arr_Uniq2[i].match_Seq,arr_Stop_Only1[j].name);
    arr_Uniq2[i].percent_Match = 100;
    arr_Uniq2[i].match_Type = 3;
    break;
   }
  }
 }
   }
   ////////////////////////////////Negative Uniq is checked against Positive Sequence(+1 & +2) END//////////////////////////////////////////
   if(isHypo == 'N')
   {
    ///////////////////////////////Negative Uniq is checked against Positive Hypothetical Sequence(+1 & +2)/////////////////////////////
 arr_Size2 = abs_Count3;
 for(int i = 0; i < arr_Size1; ++i)
 {
     if(arr_Uniq2[i].flag == 0)
  {
   for(int j = 0; j < arr_Size2; ++j)
   {
    if((arr_Uniq2[i].pos1 >= arr_Absolute3[j].pos1) && (arr_Uniq2[i].pos2 <= arr_Absolute3[j].pos2))
    {
    --uniq_Count2;
    arr_Uniq2[i].flag = 1;
    strcpy(arr_Uniq2[i].match_Seq,arr_Absolute3[j].name);
    arr_Uniq2[i].percent_Match = 100;
    arr_Uniq2[i].match_Type = 0;
    break;
    }
    else if((arr_Uniq2[i].pos2 >= arr_Absolute3[j].pos1) && (arr_Uniq2[i].pos2 <= arr_Absolute3[j].pos2))
    {
     arr_Uniq2[i].percent_Match = (double(abs(arr_Uniq2[i].pos2 - arr_Absolute3[j].pos1) + 1)/double(abs(arr_Uniq2[i].pos2 - arr_Uniq2[i].pos1) + 1)) * 100.0;
     if(arr_Uniq2[i].percent_Match >= 0.1)
     {
      --uniq_Count2;
      arr_Uniq2[i].flag = 1;
      strcpy(arr_Uniq2[i].match_Seq,arr_Absolute3[j].name);
      arr_Uniq2[i].match_Type = 1;
      break;
     }
    }
    else if((arr_Uniq2[i].pos1 >= arr_Absolute3[j].pos1) && (arr_Uniq2[i].pos1 <= arr_Absolute3[j].pos2))
    {
     arr_Uniq2[i].percent_Match = (double(abs(arr_Absolute3[j].pos2 - arr_Uniq2[i].pos1) + 1)/double(abs(arr_Uniq2[i].pos2 - arr_Uniq2[i].pos1) + 1)) * 100.0;
     if(arr_Uniq2[i].percent_Match >= 0.1)
     {
      --uniq_Count2;
      arr_Uniq2[i].flag = 1;
      strcpy(arr_Uniq2[i].match_Seq,arr_Absolute3[j].name);
      arr_Uniq2[i].match_Type = 2;
      break;
     }
    }
    else if((arr_Uniq2[i].pos1 < arr_Absolute3[j].pos1) && (arr_Uniq2[i].pos2 > arr_Absolute3[j].pos2))
    {
     --uniq_Count2;
     arr_Uniq2[i].flag = 1;
     strcpy(arr_Uniq2[i].match_Seq,arr_Absolute3[j].name);
     arr_Uniq2[i].percent_Match = 100;
     arr_Uniq2[i].match_Type = 3;
     break;
    }
   }
  }
    }
    //.......................................................................................................................................
 arr_Size2 = stopOnly_Count3;
 for(int i = 0; i < arr_Size1; ++i)
 {
  if(arr_Uniq2[i].flag == 0)
  {
   for(int j = 0; j < arr_Size2; ++j)
   {
    if((arr_Uniq2[i].pos1 >= arr_Stop_Only3[j].pos1) && (arr_Uniq2[i].pos2 <= arr_Stop_Only3[j].pos2))
    {
     --uniq_Count2;
     arr_Uniq2[i].flag = 1;
     strcpy(arr_Uniq2[i].match_Seq,arr_Stop_Only3[j].name);
     arr_Uniq2[i].percent_Match = 100;
     arr_Uniq2[i].match_Type = 0;
     break;
    }
    else if((arr_Uniq2[i].pos2 >= arr_Stop_Only3[j].pos1) && (arr_Uniq2[i].pos2 <= arr_Stop_Only3[j].pos2))
    {
     arr_Uniq2[i].percent_Match = (double(abs(arr_Uniq2[i].pos2 - arr_Stop_Only3[j].pos1) + 1)/double(abs(arr_Uniq2[i].pos2 - arr_Uniq2[i].pos1) + 1)) * 100.0;
     if(arr_Uniq2[i].percent_Match >= 0.1)
     {
      --uniq_Count2;
      arr_Uniq2[i].flag = 1;
      strcpy(arr_Uniq2[i].match_Seq,arr_Stop_Only3[j].name);
      arr_Uniq2[i].match_Type = 1;
      break;
     }
    }
    else if((arr_Uniq2[i].pos1 >= arr_Stop_Only3[j].pos1) && (arr_Uniq2[i].pos1 <= arr_Stop_Only3[j].pos2))
    {
     arr_Uniq2[i].percent_Match = (double(abs(arr_Stop_Only3[j].pos2 - arr_Uniq2[i].pos1) + 1)/double(abs(arr_Uniq2[i].pos2 - arr_Uniq2[i].pos1) + 1)) * 100.0;
     if(arr_Uniq2[i].percent_Match >= 0.1)
     {
      --uniq_Count2;
      arr_Uniq2[i].flag = 1;
      strcpy(arr_Uniq2[i].match_Seq,arr_Stop_Only3[j].name);
      arr_Uniq2[i].match_Type = 2;
      break;
     }
    }
    else if((arr_Uniq2[i].pos1 < arr_Stop_Only3[j].pos1) && (arr_Uniq2[i].pos2 > arr_Stop_Only3[j].pos2))
    {
     --uniq_Count2;
     arr_Uniq2[i].flag = 1;
     strcpy(arr_Uniq2[i].match_Seq,arr_Stop_Only3[j].name);
     arr_Uniq2[i].percent_Match = 100;
     arr_Uniq2[i].match_Type = 3;
     break;
    }
   }
  }
 }
 ///////////////////////////////Negative Uniq is checked against Positive Hypothetical Sequence(+1 & +2) END//////////////////////////
   }
   ////////////////////////////////Negative Uniq is checked against Negative Sequence(-1 & -2)///////////////////////////////////////////////
   arr_Size2 = abs_Count2;
   for(int i = 0; i < arr_Size1; ++i)
   {
 if(arr_Uniq2[i].flag == 0)
 {
  for(int j = 0; j < arr_Size2; ++j)
  {
   if((arr_Uniq2[i].pos1 >= arr_Absolute2[j].pos1) && (arr_Uniq2[i].pos2 <= arr_Absolute2[j].pos2))
   {
    --uniq_Count2;
    arr_Uniq2[i].flag = 1;
    strcpy(arr_Uniq2[i].match_Seq,arr_Absolute2[j].name);
    arr_Uniq2[i].percent_Match = 100;
    arr_Uniq2[i].match_Type = 0;
    break;
   }
   else if((arr_Uniq2[i].pos2 >= arr_Absolute2[j].pos1) && (arr_Uniq2[i].pos2 <= arr_Absolute2[j].pos2))
   {
    arr_Uniq2[i].percent_Match = (double(abs(arr_Uniq2[i].pos2 - arr_Absolute2[j].pos1) + 1)/double(abs(arr_Uniq2[i].pos2 - arr_Uniq2[i].pos1) + 1)) * 100.0;
    if(arr_Uniq2[i].percent_Match >= 0.1)
    {
     --uniq_Count2;
     arr_Uniq2[i].flag = 1;
     strcpy(arr_Uniq2[i].match_Seq,arr_Absolute2[j].name);
     arr_Uniq2[i].match_Type = 1;
     break;
    }
   }
   else if((arr_Uniq2[i].pos1 >= arr_Absolute2[j].pos1) && (arr_Uniq2[i].pos1 <= arr_Absolute2[j].pos2))
   {
    arr_Uniq2[i].percent_Match = (double(abs(arr_Absolute2[j].pos2 - arr_Uniq2[i].pos1) + 1)/double(abs(arr_Uniq2[i].pos2 - arr_Uniq2[i].pos1) + 1)) * 100.0;
    if(arr_Uniq2[i].percent_Match >= 0.1)
    {
     --uniq_Count2;
     arr_Uniq2[i].flag = 1;
     strcpy(arr_Uniq2[i].match_Seq,arr_Absolute2[j].name);
     arr_Uniq2[i].match_Type = 2;
     break;
    }
   }
   else if((arr_Uniq2[i].pos1 < arr_Absolute2[j].pos1) && (arr_Uniq2[i].pos2 > arr_Absolute2[j].pos2))
   {
    --uniq_Count2;
    arr_Uniq2[i].flag = 1;
    strcpy(arr_Uniq2[i].match_Seq,arr_Absolute2[j].name);
    arr_Uniq2[i].percent_Match = 100;
    arr_Uniq2[i].match_Type = 3;
    break; 
   }
  }
 }
   }
   //..........................................................................................................................
   arr_Size2 = stopOnly_Count2;
   for(int i = 0; i < arr_Size1; ++i) 
   {
 if(arr_Uniq2[i].flag == 0)
 {
  for(int j = 0; j < arr_Size2; ++j)
  {
   
   if((arr_Uniq2[i].pos1 >= arr_Stop_Only2[j].pos1) && (arr_Uniq2[i].pos2 <= arr_Stop_Only2[j].pos2))
   {
    --uniq_Count2;
    arr_Uniq2[i].flag = 1;
    strcpy(arr_Uniq2[i].match_Seq,arr_Stop_Only2[j].name);
    arr_Uniq2[i].percent_Match = 100;
    arr_Uniq2[i].match_Type = 0;
    break;
   }
   else if((arr_Uniq2[i].pos2 >= arr_Stop_Only2[j].pos1) && (arr_Uniq2[i].pos2 <= arr_Stop_Only2[j].pos2))
   {
    arr_Uniq2[i].percent_Match = (double(abs(arr_Uniq2[i].pos2 - arr_Stop_Only2[j].pos1) + 1)/double(abs(arr_Uniq2[i].pos2 - arr_Uniq2[i].pos1) + 1)) * 100.0;
    if(arr_Uniq2[i].percent_Match >= 0.1)
    {
     --uniq_Count2;
     arr_Uniq2[i].flag = 1;
     strcpy(arr_Uniq2[i].match_Seq,arr_Stop_Only2[j].name);
     arr_Uniq2[i].match_Type = 1;
     break;
    }
   }
   else if((arr_Uniq2[i].pos1 >= arr_Stop_Only2[j].pos1) && (arr_Uniq2[i].pos1 <= arr_Stop_Only2[j].pos2))
   {
    arr_Uniq2[i].percent_Match = (double(abs(arr_Stop_Only2[j].pos2 - arr_Uniq2[i].pos1) + 1)/double(abs(arr_Uniq2[i].pos2 - arr_Uniq2[i].pos1) + 1)) * 100.0;
    if(arr_Uniq2[i].percent_Match >= 0.1)
    {
     --uniq_Count2;
     arr_Uniq2[i].flag = 1;
     strcpy(arr_Uniq2[i].match_Seq,arr_Stop_Only2[j].name);
     arr_Uniq2[i].match_Type = 2;
     break;
    }
   }
   else if((arr_Uniq2[i].pos1 < arr_Stop_Only2[j].pos1) && (arr_Uniq2[i].pos2 > arr_Stop_Only2[j].pos2))
   {
    --uniq_Count2;
    arr_Uniq2[i].flag = 1;
    strcpy(arr_Uniq2[i].match_Seq,arr_Stop_Only2[j].name);
    arr_Uniq2[i].percent_Match = 100;
    arr_Uniq2[i].match_Type = 3;
    break;
   }
  }
 }
   }
   ////////////////////////////////Negative Uniq is checked against Negative Sequence(-1 & -2) END///////////////////////////////////////////
   if(isHypo == 'N')
   {
    ///////////////////////////////Negative Uniq is checked against Negative Hypothetical Sequence(-1 & -2) /////////////////////////////
    arr_Size2 = abs_Count4;
 for(int i = 0; i < arr_Size1; ++i)
 {
  if(arr_Uniq2[i].flag == 0)
  {
   for(int j = 0; j < arr_Size2; ++j)
   {
    if((arr_Uniq2[i].pos1 >= arr_Absolute4[j].pos1) && (arr_Uniq2[i].pos2 <= arr_Absolute4[j].pos2))
    {
     --uniq_Count2;
     arr_Uniq2[i].flag = 1;
     strcpy(arr_Uniq2[i].match_Seq,arr_Absolute4[j].name);
     arr_Uniq2[i].percent_Match = 100;
     arr_Uniq2[i].match_Type = 0;
     break;
    }
    else if((arr_Uniq2[i].pos2 >= arr_Absolute4[j].pos1) && (arr_Uniq2[i].pos2 <= arr_Absolute4[j].pos2))
    {
     arr_Uniq2[i].percent_Match = (double(abs(arr_Uniq2[i].pos2 - arr_Absolute4[j].pos1) + 1)/double(abs(arr_Uniq2[i].pos2 - arr_Uniq2[i].pos1) + 1)) * 100.0;
     if(arr_Uniq2[i].percent_Match >= 0.1)
     {
      --uniq_Count2;
      arr_Uniq2[i].flag = 1;
      strcpy(arr_Uniq2[i].match_Seq,arr_Absolute4[j].name);
      arr_Uniq2[i].match_Type = 1;
      break;
     }
    }
    else if((arr_Uniq2[i].pos1 >= arr_Absolute4[j].pos1) && (arr_Uniq2[i].pos1 <= arr_Absolute4[j].pos2))
    {
     arr_Uniq2[i].percent_Match = (double(abs(arr_Absolute4[j].pos2 - arr_Uniq2[i].pos1) + 1)/double(abs(arr_Uniq2[i].pos2 - arr_Uniq2[i].pos1) + 1)) * 100.0;
     if(arr_Uniq2[i].percent_Match >= 0.1)
     {
      --uniq_Count2;
      arr_Uniq2[i].flag = 1;
      strcpy(arr_Uniq2[i].match_Seq,arr_Absolute4[j].name);
      arr_Uniq2[i].match_Type = 2;
      break;
     }
    }
    else if((arr_Uniq2[i].pos1 < arr_Absolute4[j].pos1) && (arr_Uniq2[i].pos2 > arr_Absolute4[j].pos2))
    {
     --uniq_Count2;
     arr_Uniq2[i].flag = 1;
     strcpy(arr_Uniq2[i].match_Seq,arr_Absolute4[j].name);
     arr_Uniq2[i].percent_Match = 100;
     arr_Uniq2[i].match_Type = 3;
     break; 
    }
   }
  }
    }
    //..........................................................................................................................
    arr_Size2 = stopOnly_Count4;
    for(int i = 0; i < arr_Size1; ++i) 
    {
  if(arr_Uniq2[i].flag == 0)
  {
   for(int j = 0; j < arr_Size2; ++j)
   {
    if((arr_Uniq2[i].pos1 >= arr_Stop_Only4[j].pos1) && (arr_Uniq2[i].pos2 <= arr_Stop_Only4[j].pos2))
    {
     --uniq_Count2;
     arr_Uniq2[i].flag = 1;
     strcpy(arr_Uniq2[i].match_Seq,arr_Stop_Only4[j].name);
     arr_Uniq2[i].percent_Match = 100;
     arr_Uniq2[i].match_Type = 0;
     break;
    }
    else if((arr_Uniq2[i].pos2 >= arr_Stop_Only4[j].pos1) && (arr_Uniq2[i].pos2 <= arr_Stop_Only4[j].pos2))
    {
     arr_Uniq2[i].percent_Match = (double(abs(arr_Uniq2[i].pos2 - arr_Stop_Only4[j].pos1) + 1)/double(abs(arr_Uniq2[i].pos2 - arr_Uniq2[i].pos1) + 1)) * 100.0;
     if(arr_Uniq2[i].percent_Match >= 0.1)
     {
      --uniq_Count2;
      arr_Uniq2[i].flag = 1;
      strcpy(arr_Uniq2[i].match_Seq,arr_Stop_Only4[j].name);
      arr_Uniq2[i].match_Type = 1;
      break;
     }
    }
    else if((arr_Uniq2[i].pos1 >= arr_Stop_Only4[j].pos1) && (arr_Uniq2[i].pos1 <= arr_Stop_Only4[j].pos2))
    {
     arr_Uniq2[i].percent_Match = (double(abs(arr_Stop_Only4[j].pos2 - arr_Uniq2[i].pos1) + 1)/double(abs(arr_Uniq2[i].pos2 - arr_Uniq2[i].pos1) + 1)) * 100.0;
     if(arr_Uniq2[i].percent_Match >= 0.1)
     {
      --uniq_Count2;
      arr_Uniq2[i].flag = 1;
      strcpy(arr_Uniq2[i].match_Seq,arr_Stop_Only4[j].name);
      arr_Uniq2[i].match_Type = 2;
      break;
     }
    }
    else if((arr_Uniq2[i].pos1 < arr_Stop_Only4[j].pos1) && (arr_Uniq2[i].pos2 > arr_Stop_Only4[j].pos2))
    {
     --uniq_Count2;
     arr_Uniq2[i].flag = 1;
     strcpy(arr_Uniq2[i].match_Seq,arr_Stop_Only4[j].name);
     arr_Uniq2[i].percent_Match = 100;
     arr_Uniq2[i].match_Type = 3;
     break;
    }
   }
  }
    }
    ///////////////////////////////Negative Uniq is checked against Negative Hypothetical Sequence(-1 & -2) END/////////////////////////
   }
   //////////////////////////////////Recording Really Unique and Duplicate sequences in Files for Negative Strand
   fp1 = fp2 = NULL;
   sprintf(query2,"%s/Unique-1.txt",query);
   fp1 = fopen(query2,"w");
   sprintf(query2,"%s/Duplicate-1.txt",query);
   fp2 = fopen(query2,"w");
   fprintf(fp1,"Sequence Name\tPrediction Confidence\tR-Statistic\tLength\n");
   fprintf(fp2,"Sequence Name\tMatch Sequence in Positive Strand\tPercentage Matching\tMatch Type(0~Absolute,1~Partial(stop),2~Partial(start),"
   "3~Over absolute)\tPrediction Confidence\tR-Statistic\tLength\n");
  
   for(int i = 0; i < arr_Size1; ++i)
   {
 if(arr_Uniq2[i].flag == 1)
     fprintf(fp2,"%s\t%s\t%0.2f\%\t%d\t%s\t%f\t%d\n",arr_Uniq2[i].name,arr_Uniq2[i].match_Seq,arr_Uniq2[i].percent_Match,arr_Uniq2[i].match_Type,arr_Uniq2[i].PrC,arr_Uniq2[i].Rs,arr_Uniq2[i].len);
 else if(arr_Uniq2[i].flag == 0)
     fprintf(fp1,"%s\t%s\t%f\t%d\n",arr_Uniq2[i].name,arr_Uniq2[i].PrC,arr_Uniq2[i].Rs,arr_Uniq2[i].len);
   }
   fclose(fp1);
   fclose(fp2);
   fp1 = fp2 = NULL;
  
   
   sprintf(query2,"%s/Gene_Ped_Out.txt",query);
   if((fp1 = fopen(query2,"w")) != NULL)
   {
 fprintf(fp1," +1 = %d\n\n +2 = %d\n\n +3 = %d (Unique = %d)\n\n +4 = %d\n\n +5 = %d\n\n +6 = %d\n\n",
 abs_Count1,stopOnly_Count1,uniq_Count1,uniq_Count1_Check,missed_Count1,Gene_NonGenePred_Count1,recNum_Plus_Zero - (Gene_NonGenePred_Count1 + nonGene_Count1));
 fprintf(fp1," -1 = %d\n\n -2 = %d\n\n -3 = %d (Unique = %d)\n\n -4 = %d\n\n -5 = %d\n\n -6 = %d\n\n",
 abs_Count2,stopOnly_Count2,uniq_Count2,uniq_Count2_Check,missed_Count2,Gene_NonGenePred_Count2,recNum_Minus_Zero - (Gene_NonGenePred_Count2 + nonGene_Count2));
   fclose(fp1);
  fp1 = NULL;
   }
   if((fp1 = fopen(eval_FileName,"a")) != NULL)
   {
    if(isHypo == 'Y')
 {
     //With Hypothetical
     sprintf(query,"%s",GenePedLabel);
  fprintf(fp1,"%s\t%d\t%d\t%d\t%d\t%0.4lf\t%0.4lf\n",query,(abs_Count1 + abs_Count2),(stopOnly_Count1 + stopOnly_Count2),(uniq_Count1 + uniq_Count2),(missed_Count1 + missed_Count2),
  (double)((abs_Count1 + abs_Count2) + (stopOnly_Count1 + stopOnly_Count2))/(double)(ncb->recNum_Plus + ncb->recNum_Minus),
  (double)((abs_Count1 + abs_Count2) + (stopOnly_Count1 + stopOnly_Count2))/(double)((abs_Count1 + abs_Count2) + (stopOnly_Count1 + stopOnly_Count2) + (uniq_Count1 + uniq_Count2)));
     
    }
 else if(isHypo == 'N')
 {
  //Hypothetical Seperately
  sprintf(query,"%s",GenePedLabel);
  fprintf(fp1,"%s\t%d\t%d\t%d\t%d\t%d\t%0.4lf\t%0.4lf\t%0.4lf\n",query,(abs_Count1 + abs_Count2),(stopOnly_Count1 + stopOnly_Count2),(Our_Hypothetical_Plus + Our_Hypothetical_Minus),
  ((uniq_Count1 + uniq_Count2) - (Our_Hypothetical_Plus + Our_Hypothetical_Minus)),(missed_Count1 + missed_Count2),
  (double)((abs_Count1 + abs_Count2) + (stopOnly_Count1 + stopOnly_Count2))/(double)(ncb->recNum_Plus + ncb->recNum_Minus),
  (double)((abs_Count1 + abs_Count2) + (stopOnly_Count1 + stopOnly_Count2))/(double)((abs_Count1 + abs_Count2) + (stopOnly_Count1 + stopOnly_Count2) + (uniq_Count1 + uniq_Count2)),
  (double)((abs_Count1 + abs_Count2) + (stopOnly_Count1 + stopOnly_Count2))/(double)((abs_Count1 + abs_Count2) + (stopOnly_Count1 + stopOnly_Count2) + ((uniq_Count1 + uniq_Count2)
  - (Our_Hypothetical_Plus + Our_Hypothetical_Minus))));
 }
  fclose(fp1);
  fp1 = NULL;
   }
   
   ///////////////Roll Back Changes in NCBI Array/////////////
   for(int j = 0; j < ncb->recNum_Plus; j++)
      ncb->recs_Plus[j].flag = FALSE;
   for(int j = 0; j < ncb->recNum_Minus; j++)
      ncb->recs_Minus[j].flag = FALSE;
   for(int j = 0; j < ncb->hypo_Plus; j++)
      ncb->recs_Hypo_Plus[j].flag = FALSE;
   for(int j = 0; j < ncb->hypo_Minus; j++)
      ncb->recs_Hypo_Minus[j].flag = FALSE;
   //////////////////////////////////////////////////////////
}

void GenePredict::display_out(char *s, QApplication *qApp){

     QString *qs=new QString(s);
      QString *ms=new QString(qle->text());
       ms->append("\n");
     ms->append(*qs);
     qle->setText(*ms);
     qle->scrollToBottom();
      qApp->processEvents();

}

GenePredict::~GenePredict()
{
 delete [] recs_Plus; 
 delete [] recs_Plus_Zero; 
 delete [] Position2_Array_Plus;
 recs_Plus = recs_Plus_Zero = Position2_Array_Plus = NULL;
   
 delete [] recs_Minus; 
 delete [] recs_Minus_Zero; 
 delete [] Position2_Array_Minus;
 recs_Minus = recs_Minus_Zero = Position2_Array_Minus = NULL;
   
 delete [] arr_Absolute1;
 delete [] arr_Absolute2;
 delete [] arr_Stop_Only1;
 delete [] arr_Stop_Only2;
 delete [] arr_Uniq1;
 delete [] arr_Uniq2;
   
    if(isHypo == 'N')
    {
  delete [] arr_Absolute3;
  delete [] arr_Absolute4;
  delete [] arr_Stop_Only3;
  delete [] arr_Stop_Only4;
  arr_Absolute3 = arr_Absolute4 = NULL;
  arr_Stop_Only3 = arr_Stop_Only4 = NULL;
 }
  
 recNum_Plus = recNum_Minus = recNum_Plus_Zero = recNum_Minus_Zero = 0;
 recs_Plus = recs_Minus = recs_Plus_Zero = recs_Minus_Zero = NULL;
 arr_Absolute1 = arr_Absolute2 = NULL;
 arr_Stop_Only1 = arr_Stop_Only2 = NULL;
 arr_Uniq1 = arr_Uniq2 = NULL;
 Position2_Array_Plus = Position2_Array_Minus = NULL;
}
