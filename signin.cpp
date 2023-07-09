#include "signin.h"
#include "ui_signin.h"
#include <QFile>
#include <QMessageBox>
#include "startgame.h"

bool repeated;
QString l;
SignIn::SignIn(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SignIn)
{
    ui->setupUi(this);
}

SignIn::~SignIn()
{
    delete ui;
}

void SignIn::on_doneButton_clicked()
{
    QString username = ui->usernameTE->toPlainText();
    QString password = ui->passwordTE->toPlainText();



    bool repeated = false;
    QFile f("C:/Users/shahd/OneDrive/Documents/CSproject/Child Accounts.txt");
        if(!f.open(QFile::ReadWrite | QFile::Text)){
            QMessageBox::warning(this,"title","file not open.");
        }
        QTextStream inp(&f);
        l=inp.readLine();
        while(!l.isNull())
        {
            if(l==username)
            {
                repeated=true;
            }
            l=inp.readLine();
        }

    QFile file("C:/Users/shahd/OneDrive/Documents/CSproject/infoFile.txt");
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this,"title","file not open.");
    }
    QTextStream in(&file);
    QString line;
    line = in.readLine() ;
    while(!line.isNull()){
        if(line == username)
        {
            line = in.readLine();
            if(line == password)
            {
                QFile file2("C:/Users/shahd/OneDrive/Documents/CSproject/Child Accounts.txt");
                if(!file2.open(QFile::WriteOnly | QFile::Text | QFile::Append))
                {
                    QMessageBox::warning(this,"title","File not open");
                }
                QTextStream out(&file2);
                file2.close();
                QMessageBox::information(this,"title","Signed In Successfully");

                QFile child("C:/Users/shahd/OneDrive/Documents/CSproject/Current Child.txt");
                    if(!child.open(QFile::WriteOnly | QFile::Text)){
                        QMessageBox::warning(this,"title","file not open.");
                    }
                QTextStream w(&child);
                w << username << Qt::endl;
                w << password << Qt::endl;
                child.close();

                line = in.readLine();
                if(line == "level 1")
                  {
                       objlev1 = new Level1;
                       objlev1 ->show();
                       this->hide();
                  }
                 else if (line == "level 2")
                    {
                       objlev2 = new Level2;
                       objlev2 -> show();
                       this->hide();
                     }
                 else if(line == "level 3")
                     {
                        objlev3 = new Level3;
                        objlev3 -> show();
                        this->hide();
                     }
                 else
                     {
                        objstart = new StartGame;
                        objstart->show();
                        this->hide();
                      }

              }
            else
                QMessageBox::warning(this,"warning","Incorrect Password. Try Again.");

        }
            line = in.readLine();
   }
    if(!repeated)
        {
           QTextStream out(&f);
           out<<username<< Qt::endl;
           f.close();
        }
    file.close();

}

