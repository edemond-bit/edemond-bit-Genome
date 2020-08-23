#ifndef EVALUATION_H
#define EVALUATION_H
#include <string.h>
#include "qtextedit.h"
#include "qapplication.h"
#include "qpushbutton.h"

#define TRUE 1
#define FALSE 0

class Evaluation;

class RecFields
{
public:
	char name[200],Strand;
	int pos1,pos2,Length;
	char Temp_String[200];
	bool flag;
	RecFields()
	{
		strcpy(name,"");
		Strand = '0';
		pos1 = pos2 = Length = 0;
		strcpy(Temp_String,"");
		flag = FALSE;
	}
	QTextEdit *qle;
};

class RecFields2
{
public:
	float Rs,percent_Match;
        int pos1,pos2,len,match_Type;
        int flag;
        char name[200],match_Seq[200];    
        char PrC[16];
        char Strand;
        RecFields2()
        {
        	Rs = percent_Match = 0.0;
        	pos1 = pos2 = len = match_Type = 0;
        	flag = 0;
        	strcpy(name,"");
        	strcpy(match_Seq,"");
        	strcpy(PrC,"");
        }
};

class NCBI : public RecFields
{
public:
	friend class Evaluation;
       	int recNum_Plus,recNum_Minus,hypo_Plus,hypo_Minus;
	int minLen,maxLen,Choice;
	RecFields *recs_Plus,*recs_Minus,*recs_Hypo_Plus,*recs_Hypo_Minus;
	NCBI()
	{
		recNum_Plus = recNum_Minus = 0;
		minLen = maxLen = Choice = 0;
		recs_Plus = recs_Minus = NULL;
	}
        QTextEdit *qle;
	char isHypo_local;
	int readNCBIFile(char *,char );
	bool compareString(char [],int );
	void display_out(char *, QApplication *);
 
	~NCBI();
};

class Glimmer : public RecFields
{
	char isHypo;
	int recNum_Plus,recNum_Minus;
	RecFields *recs_Plus,*recs_Minus;
	RecFields2 *arr_Absolute1,*arr_Absolute2,*arr_Absolute3,*arr_Absolute4;
	RecFields2 *arr_Stop_Only1,*arr_Stop_Only2,*arr_Stop_Only3,*arr_Stop_Only4;
	RecFields2 *arr_Uniq1,*arr_Uniq2;
	RecFields2 *Position2_Array_Plus,*Position2_Array_Minus;
public:
	Glimmer()
	{
		recNum_Plus = recNum_Minus = 0;
		recs_Plus = recs_Minus = NULL;
	}
	int readGlimmerFile(NCBI *,char *);
	void ncbi_Vs_Glimmer(NCBI *, char , char *);
	void display_out(char *, QApplication *);

	~Glimmer();
};

class GeneMark : public RecFields
{
	char isHypo;
	int recNum_Plus,recNum_Minus;
	RecFields *recs_Plus,*recs_Minus;
	RecFields2 *arr_Absolute1,*arr_Absolute2,*arr_Absolute3,*arr_Absolute4;
	RecFields2 *arr_Stop_Only1,*arr_Stop_Only2,*arr_Stop_Only3,*arr_Stop_Only4;
	RecFields2 *arr_Uniq1,*arr_Uniq2;
	RecFields2 *Position2_Array_Plus,*Position2_Array_Minus;
public:
	GeneMark()
	{
		recNum_Plus = recNum_Minus = 0;
		recs_Plus = recs_Minus = NULL;
	}
	int readGeneMarkFile(NCBI *,char *);
	void ncbi_Vs_GeneMark(NCBI *, char , char *);
 	void display_out(char *, QApplication *);
	~GeneMark();
};

class GenePredict : public RecFields2
{
	char isHypo;
	int recNum_Plus,recNum_Minus,recNum_Plus_Zero,recNum_Minus_Zero;
	RecFields2 *recs_Plus,*recs_Minus,*recs_Plus_Zero,*recs_Minus_Zero;
	RecFields2 *arr_Absolute1,*arr_Absolute2,*arr_Absolute3,*arr_Absolute4;
	RecFields2 *arr_Stop_Only1,*arr_Stop_Only2,*arr_Stop_Only3,*arr_Stop_Only4;
	RecFields2 *arr_Uniq1,*arr_Uniq2;
	RecFields2 *Position2_Array_Plus,*Position2_Array_Minus;
	
	int Parse1(char *name);
	int Parse2(char *name);
public:
	QTextEdit *qle;
      
  	GenePredict()
	{
		recNum_Plus = recNum_Minus = recNum_Plus_Zero = recNum_Minus_Zero = 0;
		recs_Plus = recs_Minus = recs_Plus_Zero = recs_Minus_Zero = NULL;
		arr_Absolute1 = arr_Absolute2 = NULL;
		arr_Stop_Only1 = arr_Stop_Only2 = NULL;
		arr_Uniq1 = arr_Uniq2 = NULL;
		Position2_Array_Plus = Position2_Array_Minus = NULL;
	}
	int readGenePredictFile(NCBI *,char * ,char *,int);
	void ncbi_Vs_genePrediction(NCBI *,char *, char , char *, char *);
        void display_out(char *, QApplication *);
	~GenePredict();
};

class Evaluation
{
public:
	NCBI *ncb;
	Evaluation()
	{
		ncb = NULL;
	}
        
	bool readFile(char *[], char *);
	void Glimmer_Thread(char glmStr[], char ,char eval_FileName[]);
	void GeneMark_Thread(char gnmStr[], char , char eval_FileName[]);
	void GenePredict_Thread(char [],char [], char [], char , char [], char eval_FileName[],int );
        char *search_in_xml_file(char result[], char sequenceName[]); // returns file refference; result=[NCBI|Glimmer|Gene_Mark]; sequenceName=<name of the sequence>
	void searchChar(char ,int ,char ** ,char * );
	~Evaluation()
	{
		delete ncb;
		ncb = NULL;
	}
       char eval_FileName[200];
       int Choice, Option, records;
       char isHypo;
       QTextEdit *qle;
QPushButton *qbresult;
       QApplication *qApp;
};
#endif //EVALUATION_H
