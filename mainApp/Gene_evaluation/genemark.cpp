#include "evaluation.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

int GeneMark::readGeneMarkFile(NCBI *ncb,char *File_Name)
{
	FILE *fp;
	int i,j;
	RecFields rf;
		
	fp = fopen(File_Name,"r");
	if(fp != NULL)
	{
		fscanf(fp,"%[^\n]\n",rf.Temp_String);
		fscanf(fp,"%[^\n]\n",rf.Temp_String);
		while(!feof(fp))
		{
			fscanf(fp,"%[^ ]\t%c\t%d\t%d\t%d\t%[^\n]\n",rf.name,&rf.Strand,&rf.pos1,&rf.pos2,&rf.Length,rf.Temp_String);
			if(ncb->Choice == 1 || (ncb->Choice == 2 && (rf.Length >= ncb->minLen && rf.Length <= ncb->maxLen)))
			{
				if(rf.Strand == '+')
					++recNum_Plus;
				else if(rf.Strand == '-')
					++recNum_Minus;
			}
		}
	}
	else
	{
		printf( "\n %s doesn't exist!\n", File_Name);
		return 0;
	}
	
	recs_Plus = new RecFields[recNum_Plus];
	recs_Minus = new RecFields[recNum_Minus];
	Position2_Array_Plus = new RecFields2[recNum_Plus];
	Position2_Array_Minus = new RecFields2[recNum_Minus];
	rewind(fp);
	if(fp != NULL)
	{
		i = j = 0;
		fscanf(fp,"%[^\n]\n",rf.Temp_String);
		fscanf(fp,"%[^\n]\n",rf.Temp_String);
		while(!feof(fp))
		{
			fscanf(fp,"%[^ ]\t%c\t%d\t%d\t%d\t%[^\n]\n",rf.name,&rf.Strand,&rf.pos1,&rf.pos2,&rf.Length,rf.Temp_String);
			if(ncb->Choice == 1 || (ncb->Choice == 2 && (rf.Length >= ncb->minLen && rf.Length <= ncb->maxLen)))
			{
				if(rf.Strand == '+')
				{
					strcpy(recs_Plus[i].name,rf.name);
					recs_Plus[i].pos1 = rf.pos1;
					recs_Plus[i].pos2 = rf.pos2;
					recs_Plus[i].Strand = rf.Strand;
					recs_Plus[i].Length = rf.Length;
					++i;
				}
				else if(rf.Strand == '-')
				{
					strcpy(recs_Minus[j].name,rf.name);
					recs_Minus[j].pos1 = rf.pos1;
					recs_Minus[j].pos2 = rf.pos2;
					recs_Minus[j].Strand = rf.Strand;
					recs_Minus[j].Length = rf.Length;
					++j;
				}
			}
		}
		recNum_Plus = i;
		recNum_Minus = j;
		printf( "\nTotal seq(Gene Mark): %d \n ",recNum_Plus + recNum_Minus );
		fclose(fp);
		fp = NULL;
	}
	return 1;
}

void GeneMark::ncbi_Vs_GeneMark(NCBI *ncb, char isHypo, char *eval_FileName)
{
   FILE *fp;
   bool matched_flag;
   int abs_Count1,stopOnly_Count1,uniq_Count1,uniq_Count1_Check;
   int abs_Count2,stopOnly_Count2,uniq_Count2,uniq_Count2_Check;
   int abs_Count3,stopOnly_Count3,abs_Count4,stopOnly_Count4;
   int missed_Count1,missed_Count2;
  // char query[200],query2[200];
   
   isHypo = isHypo;
   
   arr_Absolute1 = new RecFields2[recNum_Plus];
   arr_Stop_Only1 = new RecFields2[recNum_Plus];
   arr_Uniq1 = new RecFields2[recNum_Plus];
      
   /////////////////////////////////////////////////////////////////////Positive Strand
   abs_Count1 = stopOnly_Count1 = uniq_Count1 = uniq_Count1_Check = missed_Count1 = 0;
   for(int i = 0; i < recNum_Plus; i++)
   {
        matched_flag = false;
        for(int j = 0; j < ncb->recNum_Plus; j++)
        {
            if(recs_Plus[i].pos2 == ncb->recs_Plus[j].pos2)
            {
                if(recs_Plus[i].pos1 == ncb->recs_Plus[j].pos1)
                {
                	strcpy(arr_Absolute1[abs_Count1].name,recs_Plus[i].name);
                	arr_Absolute1[abs_Count1].len = recs_Plus[i].Length;
                	arr_Absolute1[abs_Count1].pos1 = recs_Plus[i].pos1;
                	arr_Absolute1[abs_Count1].pos2 = recs_Plus[i].pos2;
                	arr_Absolute1[abs_Count1].flag = 0;
                	++abs_Count1;
                }
                else
                {
                      	strcpy(arr_Stop_Only1[stopOnly_Count1].name,recs_Plus[i].name);
                	arr_Stop_Only1[stopOnly_Count1].len = recs_Plus[i].Length;
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
             Position2_Array_Plus[uniq_Count1].pos2 = recs_Plus[i].pos2;
             Position2_Array_Plus[uniq_Count1].flag = 0;
             strcpy(arr_Uniq1[uniq_Count1].name,recs_Plus[i].name);
             arr_Uniq1[uniq_Count1].len = recs_Plus[i].Length;
             arr_Uniq1[uniq_Count1].pos1 = recs_Plus[i].pos1;
             arr_Uniq1[uniq_Count1].pos2 = recs_Plus[i].pos2;
             arr_Uniq1[uniq_Count1].flag = 0;
             ++uniq_Count1;
        }
   }
   for(int j = 0; j < ncb->recNum_Plus; j++)
   {
      if(ncb->recs_Plus[j].flag == FALSE)
          ++missed_Count1;
   }
   
   int temp;
   for(int i = 0; i < uniq_Count1 - 1; i++)
   {
       temp = Position2_Array_Plus[i].pos2;
       for(int j = i+1; j < uniq_Count1; j++)
       {
          if(temp == Position2_Array_Plus[j].pos2)  //Unique 2
          {
               Position2_Array_Plus[j].flag = 1;
               printf("\nPos_Plus: %d\n",Position2_Array_Plus[j].pos2);
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
   abs_Count2 = stopOnly_Count2 = uniq_Count2 = uniq_Count2_Check = missed_Count2 = 0;
   for(int i = 0; i < recNum_Minus; i++)
   {
        matched_flag = false;
        for(int j = 0; j < ncb->recNum_Minus; j++)
        {
            if(recs_Minus[i].pos2 == ncb->recs_Minus[j].pos2) 
            {
                if(recs_Minus[i].pos1 == ncb->recs_Minus[j].pos1)
                {
                      strcpy(arr_Absolute2[abs_Count2].name,recs_Minus[i].name);
                      arr_Absolute2[abs_Count2].len = recs_Minus[i].Length;
                      arr_Absolute2[abs_Count2].pos1 = recs_Minus[i].pos2;
                      arr_Absolute2[abs_Count2].pos2 = recs_Minus[i].pos1;
                      arr_Absolute2[abs_Count2].flag = 0;
                      ++abs_Count2;
                }
                else
                {
                      strcpy(arr_Stop_Only2[stopOnly_Count2].name,recs_Minus[i].name);
                      arr_Stop_Only2[stopOnly_Count2].len = recs_Minus[i].Length;
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
             Position2_Array_Minus[uniq_Count2].pos2 = recs_Minus[i].pos2; 
             Position2_Array_Minus[uniq_Count2].flag = 0; 
             strcpy(arr_Uniq2[uniq_Count2].name,recs_Minus[i].name);
             arr_Uniq2[uniq_Count2].len = recs_Minus[i].Length;
             arr_Uniq2[uniq_Count2].pos1 = recs_Minus[i].pos2;
             arr_Uniq2[uniq_Count2].pos2 = recs_Minus[i].pos1;
             arr_Uniq2[uniq_Count2].flag = 0;
             ++uniq_Count2;
        }
   }
   for(int j = 0; j < ncb->recNum_Minus; j++)
   {
      if(ncb->recs_Minus[j].flag == FALSE)
         ++missed_Count2;
   }

   for(int i = 0; i < uniq_Count2 - 1; i++)
   {
       temp = Position2_Array_Minus[i].pos2;
       for(int j= i+1; j < uniq_Count2; j++)
       {
          if(temp == Position2_Array_Minus[j].pos2)
          {
               Position2_Array_Minus[j].flag = 1;
               printf("\nPos_Minus: %d\n",Position2_Array_Minus[j].pos2);
          }
       }
   }
   
   for(int i = 0; i < uniq_Count2; i++)
   {
      if(Position2_Array_Minus[i].flag == 0)
             ++uniq_Count2_Check;
   }
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
	for(int j = 0; j < ncb->hypo_Plus; j++)
	{
	    if(ncb->recs_Hypo_Plus[j].flag == FALSE)
	         ++missed_Count1;
	}
   }
   /////////This Part is appended for Calculation excluding(but in) Hypothetical Proteins in Plus Strand(END)//////////////////
   //////////This Part is appended for Calculation excluding(but in) Hypothetical Proteins in Minus Strand//////////////////////
   int Our_Hypothetical_Minus = 0;
   abs_Count4 = stopOnly_Count4 = 0;
   if(isHypo == 'N')
   {
   	arr_Absolute4 = new RecFields2[uniq_Count2];
	arr_Stop_Only4 = new RecFields2[uniq_Count2];
   	
	for(int i = 0; i < uniq_Count2; ++i)
	{
	    for(int j = 0; j < ncb->hypo_Minus; j++)
	    {
	        if(arr_Uniq2[i].pos2 == ncb->recs_Hypo_Minus[j].pos2) 
	        {
	           if(arr_Uniq2[i].pos1 == ncb->recs_Hypo_Minus[j].pos1)
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
	for(int j = 0; j < ncb->hypo_Minus; j++)
	{
	   if(ncb->recs_Hypo_Minus[j].flag == FALSE)
	        ++missed_Count2;
	}
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
   if((fp = fopen(eval_FileName,"a")) != NULL)
   {
   	if(isHypo == 'Y')
	{
	   	//With Hypothetical
		fprintf(fp,"%s\t%d\t%d\t%d\t%d\t%0.4lf\t%0.4lf\n","GeneMark",(abs_Count1 + abs_Count2),(stopOnly_Count1 + stopOnly_Count2),(uniq_Count1 + uniq_Count2),(missed_Count1 + missed_Count2),
		(double)((abs_Count1 + abs_Count2) + (stopOnly_Count1 + stopOnly_Count2))/(double)(ncb->recNum_Plus + ncb->recNum_Minus),
		(double)((abs_Count1 + abs_Count2) + (stopOnly_Count1 + stopOnly_Count2))/(double)((abs_Count1 + abs_Count2) + (stopOnly_Count1 + stopOnly_Count2) + (uniq_Count1 + uniq_Count2)));
   		
   	}
	else if(isHypo == 'N')
	{
		//Hypothetical Seperately
		fprintf(fp,"%s\t%d\t%d\t%d\t%d\t%d\t%0.4lf\t%0.4lf\t%0.4lf\n","GeneMark",(abs_Count1 + abs_Count2),(stopOnly_Count1 + stopOnly_Count2),(Our_Hypothetical_Plus + Our_Hypothetical_Minus),
		((uniq_Count1 + uniq_Count2) - (Our_Hypothetical_Plus + Our_Hypothetical_Minus)),(missed_Count1 + missed_Count2),
		(double)((abs_Count1 + abs_Count2) + (stopOnly_Count1 + stopOnly_Count2))/(double)(ncb->recNum_Plus + ncb->recNum_Minus),
		(double)((abs_Count1 + abs_Count2) + (stopOnly_Count1 + stopOnly_Count2))/(double)((abs_Count1 + abs_Count2) + (stopOnly_Count1 + stopOnly_Count2) + (uniq_Count1 + uniq_Count2)),
		(double)((abs_Count1 + abs_Count2) + (stopOnly_Count1 + stopOnly_Count2))/(double)((abs_Count1 + abs_Count2) + (stopOnly_Count1 + stopOnly_Count2) + ((uniq_Count1 + uniq_Count2)
		- (Our_Hypothetical_Plus + Our_Hypothetical_Minus))));
	}
 	fclose(fp);
 	fp = NULL;
   }
   
   ///////////////Roll Back Changes in NCBI Array////////////////
   for(int j = 0; j < ncb->recNum_Plus; j++)
      ncb->recs_Plus[j].flag = FALSE;
   for(int j = 0; j < ncb->recNum_Minus; j++)
      ncb->recs_Minus[j].flag = FALSE;
   for(int j = 0; j < ncb->hypo_Plus; j++)
      ncb->recs_Hypo_Plus[j].flag = FALSE;
   for(int j = 0; j < ncb->hypo_Minus; j++)
      ncb->recs_Hypo_Minus[j].flag = FALSE;
   /////////////////////////////////////////////////////////////
}

GeneMark::~GeneMark()
{
	delete [] recs_Plus; 
	delete [] Position2_Array_Plus;
	recs_Plus = NULL;
	Position2_Array_Plus = NULL;
   
	delete [] recs_Minus; 
	delete [] Position2_Array_Minus;
	recs_Minus = NULL;
	Position2_Array_Minus = NULL;
   
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
   	
	recNum_Plus = recNum_Minus = 0;
	recs_Plus = recs_Minus = NULL;
	arr_Absolute1 = arr_Absolute2 = NULL;
	arr_Stop_Only1 = arr_Stop_Only2 = NULL;
	arr_Uniq1 = arr_Uniq2 = NULL;
	Position2_Array_Plus = Position2_Array_Minus = NULL;
}
