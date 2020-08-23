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

#include <qfiledialog.h>
int option;

void ReferenceDirectory::init(){
    getDatabasePath(lineEdit109,"NCBI.xml");
    getDatabasePath(lineEdit109_2,"Glimmer.xml");
    getDatabasePath(lineEdit109_3,"Gene_Mark.xml");
    
}

void ReferenceDirectory::getDatabasePath(QLineEdit *l,QString t){

    QFile   __resultFile;
    QDomDocument __resultDom;
    __resultFile.setName(t);
    QDomNode tmp;
    QDomElement root;
    QDomNodeList nl;
    
    if ( !__resultDom.setContent( &__resultFile ) ) {
 //        QMessageBox::critical( 0,QApplication::tr( "Critical Error" ),QApplication::tr( "Parsing error for file %1" ).arg( resultFileName ) );
 l->setText("");
 __resultFile.close();
 return ;
    }
    __resultFile.close();
    
    root = __resultDom.documentElement();
    nl=root.childNodes();
    l->setText(root.attribute("basepath"));
}


void ReferenceDirectory::pushButton167_clicked()
{
    QString tmp=selectFile(new QString("NCBI"));
    lineEdit109->setText(tmp);
    
}


void ReferenceDirectory::pushButton1_clicked()
{
    selectFile(new QString("NCBI"));
}

QString ReferenceDirectory::selectFile(QString *){
    QFileDialog *fd=new QFileDialog(this);
    fd->show();
    fd->setMode(QFileDialog::DirectoryOnly);
    QString *dirName;
    if ( fd->exec() == QDialog::Accepted );
    dirName = new QString(fd->selectedFile());
    return *dirName;
    
    //prepXML_FileList(name, dirName);
}



void ReferenceDirectory::prepXML_FileList(QString *resultName, QString *dirName)
{
    if(dirName->isEmpty())
    {
 QMessageBox::warning(this,"Warning","Not Found "+*resultName+".xml");
 return;
    }
    QDir  d(dirName->ascii());
    QFile __resultFile;
    
    ncbiDom.removeChild(ncbiDom.firstChild());
    QDomElement root = ncbiDom.createElement("sequencebase");
    
    QDomElement seq=ncbiDom.createElement("sequence");
    seq.setAttribute("name","");
    seq.setAttribute("file","");
    root.setAttribute("result",resultName->ascii());
    root.setAttribute("basepath",dirName->ascii());
    
    
    for ( unsigned i = 2; i < d.count(); i++ )
    {
 QDomElement tmp;
 // QMessageBox::information(this,"File","selected file:"+d.absFilePath(d[i]));
 QDir td(d.absFilePath(d[i]));
 tmp=ncbiDom.createElement("sequence");
 tmp.setAttribute("name",d[i]);
 tmp.setAttribute("file",td.absFilePath(td[2]));
 root.appendChild(tmp);
 
 // QMessageBox::information(this,"test", td.absFilePath(td[2]));
    }
    ncbiDom.appendChild(root);
   // QMessageBox::information(this,"asdf",*resultName+".xml");
    __resultFile.setName(*resultName+".xml");
    if(!__resultFile.open( IO_WriteOnly))
    {
 QMessageBox::critical(0,  QApplication::tr("Critical Error") , QApplication::tr("Can not open file %1").arg(*dirName));
    } 
    
    
    QTextStream stream( &__resultFile);
    QString line =   ncbiDom.toString();
    stream<<line;
    __resultFile.close();
    //QMessageBox::information(this,"test",ncbiDom.toString());
    
}







void ReferenceDirectory::pushButton167_2_clicked()
{
    lineEdit109_2->setText(selectFile(new QString("Glimmer")));
}


void ReferenceDirectory::pushButton167_3_clicked()
{
    lineEdit109_3->setText(selectFile(new QString("Gene_Mark")));
}


void ReferenceDirectory::pushButton170_clicked()
{
   checkAndCreateXML(0);
}

void ReferenceDirectory::checkAndCreateXML(int test){
    // argument indicates from where the function is called
    //    0  :  from Ok button handle
    //    1  : from Skip button handle
     bool b=false;
    QString t=lineEdit109->text();
    QString tt;
    if(t.isEmpty())
    {
	QMessageBox::warning(this,"Warning","Please enter the directory path of NCBI data ");
	return;
    }else{
  if(test==0)  prepXML_FileList(new QString("NCBI"), &t);
    b=true;
}
    switch(option){
    case 4:
	
	break;
    case 5:
	t=lineEdit109_2->text();
	if(t.isEmpty())
	{
	    QMessageBox::warning(this,"Warning","Please enter the directory path of Glimmer data ");
	       b=false;
	    break;
	}
	if(test==0) prepXML_FileList(new QString("Glimmer"), &t);
	b=true;
	break;
    case 6:
	t=lineEdit109_3->text();
	if(t.isEmpty())
	{
	    QMessageBox::warning(this,"Warning","Please enter the directory path of Gene_Mark data ");
	          b=false;
	    break;
	}
	  if(test==0) prepXML_FileList(new QString("Gene_Mark"), &t);
	b=true;
	break;
    case 7:
	t=lineEdit109_2->text();
	tt=lineEdit109_3->text();
	if(t.isEmpty()){
	    QMessageBox::warning(this,"Warning","Please enter the directory path of Glimmer data ");
	          b=false;
	break;
	}else if(tt.isEmpty()){
	    QMessageBox::warning(this,"Warning","Please enter the directory path of Gene_Mark data ");
	    break;
	}else if(t.isEmpty() && tt.isEmpty())
	{
	    QMessageBox::warning(this,"Warning","Please enter the directory path of Glimmer and Gene_Mark data ");
	          b=false;
	    break;
	}
	  if(test==0) prepXML_FileList(new QString("Glimmer"), &t);
	
	  if(test==0) prepXML_FileList(new QString("Gene_Mark"), &tt);
	b=true;
	break;
    default:
	break;
    }
    
    if(b) this->accept();
    
}

void ReferenceDirectory::setOption(int n)
	
{
    option=n;
    groupBoxNCBI->setEnabled(true);
    switch(option){
    case 4:
	
	groupBoxGlimmer->setEnabled(false);
	groupBoxGene_Mark->setEnabled(false);
	break;
    case 5:
	groupBoxGlimmer->setEnabled(true);
	groupBoxGene_Mark->setEnabled(false);
	break;
    case 6:
	groupBoxGlimmer->setEnabled(false);
	groupBoxGene_Mark->setEnabled(true);
	break;
    case 7:
	groupBoxGlimmer->setEnabled(true);
	groupBoxGene_Mark->setEnabled(true);
	break;
    default:
	break;
    }
    
}


void ReferenceDirectory::pushButton171_clicked()
{
       checkAndCreateXML(1);
    //this->close();
    
}






void ReferenceDirectory::ReferenceDirectory_destroyed( QObject * )
{

}
