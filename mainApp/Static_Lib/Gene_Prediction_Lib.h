#ifndef __GENE_PREDICTION_LIB
#define __GENE_PREDICTION_LIB

#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include "qlineedit.h"

#include "qcolor.h"
class Gene_Pred
{
 private:

 public:
  static void search_char(char, int, char **, char *);
  static void extract_index(char *, int &, int &, char);
  static void min_max_GUI_validator( int minRange, int maxRange, QLineEdit *minLineEdit, QLineEdit *maxLineEdit );
  static void color_Field_validator(QLineEdit *Field, int state);
  
  static void sort_orf_list_file(char *, int);
  static const char *pwd(void);

};
#endif
