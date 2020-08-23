######################################################################
# Automatically generated by qmake (1.07a) Tue Sep 21 15:48:02 2010
######################################################################

TEMPLATE = app
DEPENDPATH += createDirectory \
              File_Manager \
              Gene_evaluation \
              orf \
              ParamManager \
              Prediction \
              ProgressBarController \
              Random_Seq \
              sessionManager \
              Static_Lib \
              statusManager \
              Prediction/get_Omega_PeakParam
INCLUDEPATH += . \
               File_Manager \
               Static_Lib \
               Gene_evaluation \
               orf \
               ProgressBarController \
               statusManager \
               ParamManager \
               sessionManager

# Input
HEADERS += F_Ratio.ui.h \
           GenePrediction.ui.h \
           referencedirectory.ui.h \
           createDirectory/createDirectory.ui.h \
           File_Manager/File_Manager.h \
           Gene_evaluation/evaluation.h \
           orf/orf.h \
           ParamManager/paramManager.h \
           Prediction/Gene_Prediction.h \
           Prediction/Gene_Prediction_File.h \
           Prediction/MinHeader.h \
           ProgressBarController/pbc.h \
           Random_Seq/Random_Sequence.h \
           Random_Seq/RandomDialog.ui.h \
           sessionManager/sessionManager.h \
           Static_Lib/Gene_Prediction_Lib.h \
           statusManager/statusManager.h \
           Prediction/get_Omega_PeakParam/Omega_Peak_Inputs.ui.h
INTERFACES += F_Ratio.ui \
              GenePrediction.ui \
              referencedirectory.ui \
              createDirectory/createDirectory.ui \
              Random_Seq/RandomDialog.ui \
              Prediction/get_Omega_PeakParam/Omega_Peak_Inputs.ui
SOURCES += main.cpp \
           File_Manager/File_Manager.cpp \
           Gene_evaluation/evaluation.cpp \
           Gene_evaluation/genemark.cpp \
           Gene_evaluation/genepredict.cpp \
           Gene_evaluation/glimmer.cpp \
           Gene_evaluation/ncbi.cpp \
           orf/orf.cpp \
           ParamManager/paramManager.cpp \
           ProgressBarController/pbc.cpp \
           sessionManager/sessionManager.cpp \
           Static_Lib/Gene_Prediction_Lib.cpp \
           statusManager/statusManager.cpp
