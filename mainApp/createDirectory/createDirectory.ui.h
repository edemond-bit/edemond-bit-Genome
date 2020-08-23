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

void Folder_creation::init()
{
   // __lineEdit =parent->lineEdit45;
currentDirectory=QString("");
}
void Folder_creation::buttonOk_clicked()
{
    printf(" Folder_creation : ok button pressed:");
   __lineEdit->setText(lineEdit12->text());
     this->hide();
}





void Folder_creation::reject()
{

    this->hide();
}




void Folder_creation::newSlot()
{

}
