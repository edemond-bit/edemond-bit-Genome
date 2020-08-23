/****************************************************************************
** ui.h extension file, included from the uic-generated form implementation.
**
** If you want to add, delete, or rename functions or slots, use
** Qt Designer to update this file, preserving your code.
**
** You should not define a constructor or destructor in this file.
** Instead, write your code in functions called init() and destroy().
** These will automatically be called by the form's constructor and
** destructor.
*****************************************************************************/

#include "qmessagebox.h"

void F_Ratio::initialize(){
    	paramMg->getValueToWidget("320", radioButton21, "QRadioButton");
	paramMg->getValueToWidget("330", radioButton22, "QRadioButton");
}
void F_Ratio::radioButton21_clicked()
{
setDefaultValue();
}


void F_Ratio::radioButton22_clicked()
{
setDefaultValue();
}



void F_Ratio::setDefaultValue()
{
    if(radioButton21->isChecked()) {
	
 methodType = 1;

}
    if(radioButton22->isChecked()) {
 methodType = 2;

}
  paramMg->getValueFromWdiget("320", radioButton21, "QRadioButton");
  paramMg->getValueFromWdiget("330", radioButton22, "QRadioButton");
}


void F_Ratio::buttonOk_pressed()
{
setDefaultValue();

}





