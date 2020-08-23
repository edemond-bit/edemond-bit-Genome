#include "evaluation.h"
#include<iostream>
#include<stdio.h>
#include <stdlib.h>

int NCBI::readNCBIFile(char *File_Name, char isHypo)
{
	FILE *fp;
	int i,j,k,l;
	RecFields rf;
        char tmp[200];
	
	isHypo_local=isHypo;
	/*printf("1) All Sequences\n"
	       "2) Sequences of Specified Lengths\n"
	       "Enter your choice: ");
	cin >> Choice;*/
	Choice = 2;
       // printf("\n reading NCBI file now \n");
	switch(Choice)
	{
		case 1:
			minLen = maxLen = -1;
			break;
		case 2:
			/*cout << "\nEnter minimum sequence length: ";
			cin >> minLen;
			cout << "\nEnter maximum sequence length: ";
			cin >> maxLen;*/
			minLen = 60;
			maxLen = 20000;
			break;
	}
	
	recNum_Plus = recNum_Minus = hypo_Plus = hypo_Minus = 0;
	fp = fopen(File_Name,"r");
	if(fp != NULL)
	{
		fscanf(fp,"%[^\n]\n",rf.Temp_String);
		if(isHypo == 'Y')
		{
			while(!feof(fp))
			{
				fscanf(fp,"%[^\t]\t%d\t%d\t%c\t%d\t%[^\n]\n",rf.name,&rf.pos1,&rf.pos2,&rf.Strand,&rf.Length,rf.Temp_String);
				rf.Length = abs(rf.pos1 - rf.pos2) + 1;
				if((rf.Length%3 == 0) && (Choice == 1 || (Choice == 2 && (rf.Length >= minLen && rf.Length <= maxLen))))
				{
					if(rf.Strand == '+')
						++recNum_Plus;
					else if(rf.Strand == '-')
						++recNum_Minus;
				}
			}
			hypo_Plus = hypo_Minus = 1;
		}
		else
		{
			while(!feof(fp))
			{
				fscanf(fp,"%[^\t]\t%d\t%d\t%c\t%d\t%[^\n]\n",rf.name,&rf.pos1,&rf.pos2,&rf.Strand,&rf.Length,rf.Temp_String);
				rf.Length = abs(rf.pos1 - rf.pos2) + 1;
				if((rf.Length%3 == 0) && (Choice == 1 || (Choice == 2 && (rf.Length >= minLen && rf.Length <= maxLen))))
				{
				
					//if(compareString(rf.name,12) == FALSE)
					if(strncmp(rf.name,"hypothetical",12) != 0)
					{
						if(rf.Strand == '+')
							++recNum_Plus;
						else if(rf.Strand == '-')
							++recNum_Minus;
					}
					else				
					{
						if(rf.Strand == '+')
							++hypo_Plus;
						else if(rf.Strand == '-')
							++hypo_Minus;
					}
				}
			}
		}
	}
	else
	{
		printf("\n %s  doesn't exist!\n", File_Name);
		return 0;
	}
	recs_Plus = new RecFields[recNum_Plus];
	recs_Minus = new RecFields[recNum_Minus];
	if(isHypo == 'N')
	{
		recs_Hypo_Plus = new RecFields[hypo_Plus];
		recs_Hypo_Minus = new RecFields[hypo_Minus];
	}
	rewind(fp);
	if(fp != NULL)
	{
		i = j = k = l = 0;
		fscanf(fp,"%[^\n]\n",rf.Temp_String);
		if(isHypo == 'Y')
		{
			while(!feof(fp))
			{
				fscanf(fp,"%[^\t]\t%d\t%d\t%c\t%d\t%[^\n]\n",rf.name,&rf.pos1,&rf.pos2,&rf.Strand,&rf.Length,rf.Temp_String);
				rf.Length = abs(rf.pos1 - rf.pos2) + 1;
				if((rf.Length%3 == 0) && (Choice == 1 || (Choice == 2 && (rf.Length >= minLen && rf.Length <= maxLen))))
				{
					if(rf.Strand == '+')
					{
						strcpy(recs_Plus[i].name,rf.name);
						recs_Plus[i].pos1 = rf.pos1;
						recs_Plus[i].pos2 = rf.pos2;
						recs_Plus[i].Strand = rf.Strand;
						recs_Plus[i].Length = rf.Length;
						recs_Plus[i].flag = FALSE;
						i++;
					}
					else
					{
						strcpy(recs_Minus[j].name,rf.name);
						recs_Minus[j].pos1 = rf.pos1;
						recs_Minus[j].pos2 = rf.pos2;
						recs_Minus[j].Strand = rf.Strand;
						recs_Minus[j].Length = rf.Length;
						recs_Minus[j].flag = FALSE;
						j++;
					}
				}
			}
		}
		else
		{
			while(!feof(fp))
			{
				fscanf(fp,"%[^\t]\t%d\t%d\t%c\t%d\t%[^\n]\n",rf.name,&rf.pos1,&rf.pos2,&rf.Strand,&rf.Length,rf.Temp_String);
				rf.Length = abs(rf.pos1 - rf.pos2) + 1;
				if((rf.Length%3 == 0) && (Choice == 1 || (Choice == 2 && (rf.Length >= minLen && rf.Length <= maxLen))))
				{
					//if(compareString(rf.name,12) == FALSE)
					if(strncmp(rf.name,"hypothetical",12) != 0)
					{
						if(rf.Strand == '+')
						{
							strcpy(recs_Plus[i].name,rf.name);
							recs_Plus[i].pos1 = rf.pos1;
							recs_Plus[i].pos2 = rf.pos2;
							recs_Plus[i].Strand = rf.Strand;
							recs_Plus[i].Length = rf.Length;
							recs_Plus[i].flag = FALSE;
							i++;
						}
						else
						{
							strcpy(recs_Minus[j].name,rf.name);
							recs_Minus[j].pos1 = rf.pos1;
							recs_Minus[j].pos2 = rf.pos2;
							recs_Minus[j].Strand = rf.Strand;
							recs_Minus[j].Length = rf.Length;
							recs_Minus[j].flag = FALSE;
							j++;
						}			
					}
					else
					{
						if(rf.Strand == '+')
						{
							strcpy(recs_Hypo_Plus[k].name,rf.name);
							recs_Hypo_Plus[k].pos1 = rf.pos1;
							recs_Hypo_Plus[k].pos2 = rf.pos2;
							recs_Hypo_Plus[k].Strand = rf.Strand;
							recs_Hypo_Plus[k].Length = rf.Length;
							recs_Hypo_Plus[k].flag = FALSE;
							k++;
						}
						else
						{
							strcpy(recs_Hypo_Minus[l].name,rf.name);
							recs_Hypo_Minus[l].pos1 = rf.pos1;
							recs_Hypo_Minus[l].pos2 = rf.pos2;
							recs_Hypo_Minus[l].Strand = rf.Strand;
							recs_Hypo_Minus[l].Length = rf.Length;
							recs_Hypo_Minus[l].flag = FALSE;
							l++;
						}
					}
				}
			}
		}
		recNum_Plus = i;
		recNum_Minus = j;
		hypo_Plus = k;
		hypo_Minus = l;
		//	cout << "\nTotal seq(NCBI): " << recNum_Plus + recNum_Minus << endl;
                      sprintf(tmp,"Total seq(NCBI): %d",recNum_Plus + recNum_Minus);
		display_out(tmp,qApp);
if(isHypo=='N'){
		//      cout << "\nTotal seq(HYPO): " << hypo_Plus + hypo_Minus << endl;
                      sprintf(tmp,"Total seq(HYPO): %d", hypo_Plus+hypo_Minus);
                display_out(tmp,qApp);		
}
		fclose(fp);
		fp = NULL;
	}
	return 1;
}

bool NCBI::compareString(char Str[], int Length)
{
	int strLen,i = 0,j;
	char matchStr[] = {"hypothetical"};
	strLen = strlen(Str);
	for(j = 0; j < strLen; j++)
		Str[j] = tolower(Str[j]);
		
	while(i < strLen && Str[i++] == ' ');
	if(i < strLen)
	{
		--i;
		for(j = 0; j < Length && i < strLen; j++, i++)
		{
			if(Str[i] != matchStr[j])
				break;
		}
		if(j == Length)
			return true;
		else 
			return false;
	}
	else
		return false;
}
void NCBI::display_out(char *s, QApplication *qApp){

     QString *qs=new QString(s);
      QString *ms=new QString(qle->text());
       ms->append("\n");
     ms->append(*qs);
     qle->setText(*ms);
     qle->scrollToBottom();
      qApp->processEvents();

}

NCBI::~NCBI()
{
	delete [] recs_Plus; 
	delete [] recs_Minus;
	if(isHypo_local=='N'){
	  delete [] recs_Hypo_Plus;
	  delete [] recs_Hypo_Minus;
	  recs_Plus = recs_Minus = recs_Hypo_Plus = recs_Hypo_Minus = NULL;
	}
	recNum_Plus = recNum_Minus = hypo_Plus = hypo_Minus = 0;
	minLen = maxLen = Choice = 0;
	
}
