#include "signin2.h"
#include "ui_signin2.h"
#include <QFile>
#include <QMessageBox>


SignIn2::SignIn2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SignIn2)
{
    ui->setupUi(this);
}

SignIn2::~SignIn2()
{
    delete ui;
}

void SignIn2::on_doneButton_2_clicked()
{
    QString username=ui->usernameTE_2->toPlainText();
    QString password=ui->passwordTE_2->toPlainText();


    QFile file5("C:/Users/shahd/OneDrive/Documents/CSproject/infoFile.txt");
    if(!file5.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this,"title","file not open");
    }
    QTextStream in(&file5);
    QString line1;
    line1=in.readLine();
    while(!line1.isNull())
    {
        if(line1==username)
        {
            line1=in.readLine();
            if(line1==password)
            {
                QMessageBox::information(this,"title","Signed In Successfully");
                QFile file2("C:/Users/shahd/OneDrive/Documents/CSproject/Current Parent Account.txt");
                if(!file2.open(QFile::WriteOnly | QFile::Text))
                {
                    QMessageBox::warning(this,"title","file not open");

                }
                QTextStream out(&file2);
                out<<username<<Qt::endl;
                out<<password<<Qt::endl;
                file2.close();
            }
            else
            {
                QMessageBox::warning(this,"title","Incorrect Password");
            }
        }
        line1=in.readLine();
    }
    file5.close();
    objreport = new Report;
    objreport->show();
    this->hide();
}

