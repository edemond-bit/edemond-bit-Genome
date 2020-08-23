#ifndef __FILE_MANAGER
#define __FILE_MANAGER

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "../Static_Lib/Gene_Prediction_Lib.h"
class File_Manager
{
 private:
  char *application_home; // home of the application 
  const char *path_orf; // 
  const char *seq_name;
  const char *path_seq;
  const char *path_seq_folder;
  const char *seq_work_dir;
  const char *standerdParameterXML;
  const char *defaultParameterXML;
  const char *finalParamXML;
  const char *defaultWorkDir;
  const char *sessionXML;
  ~File_Manager();
 public:
  File_Manager();
  const char *get_seq_path(void); // returns the sequence original path
  const char *get_application_home(void); // returns application home directory
  const char *get_path_ORF(void);  // returns the path of path_ORF file
  const char *get_seq_work_dir(void); // returns seq_work_dir
  const char *get_default_work_dir(void);// returns default working directory
  ////// parameter file access
  const char *get_standerd_param_xml(void); // get standard xml file of parameter
  const char *get_default_param_xml(void); // get default xml file of parameter
  const char *get_final_param_xml(void); // get output xml file of parameter
  ///////////////////////////////////
  void set_sequence_path(char *); // sets_seq_path
  bool  set_seq_work_dir(char *swd);// sets_seq_work_dir
  //////// Session file //////
  const char *getSessionFile();// 

// unitility
bool isEmptyWorkingDir();
bool makeWorkingDirectoryEmpty();
  

};
#endif
