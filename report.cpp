#include "report.h"
#include "ui_report.h"
#include <level1.h>
#include <level2.h>
#include <level3.h>
#include <signin.h>
#include <signin2.h>
#include <iostream>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QLabel>
using namespace std;

QString user;
QString pass;
QString line1;
QString line;
QString child;
QString progress;
QString lev1,lev2,lev3,wr1,wr2,wr3;


Report::Report(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Report)
{
    ui->setupUi(this);
}

Report::~Report()
{
    delete ui;
}




void Report::on_viewReportButton_clicked()
{
    QFile file2("C:/Users/shahd/OneDrive/Documents/CSproject/Current Parent Account.txt");
        if(!file2.open(QFile::ReadOnly | QFile::Text))
        {
            QMessageBox::warning(this,"title","file not open");

        }
        QTextStream in(&file2);
        user=in.readLine();
        pass=in.readLine();
        file2.close();


        QFile file("C:/Users/shahd/OneDrive/Documents/CSproject/infoFile.txt");
        if(!file.open(QFile::ReadOnly | QFile::Text))
        {
            QMessageBox::warning(this,"title","file not open");
        }
        QTextStream input(&file);

        line1=input.readLine();
        while(!line1.isNull())
        {
            if(line1==user)
            {
                line1=input.readLine();
                if(line1==pass)
                {
                   child=input.readLine();
                }
                input.readLine();
                progress = input.readLine();
            }
            line1=input.readLine();
        }
        ui->childName->setText(" "+child);
        file.close();


        QFile f("C:/Users/shahd/OneDrive/Documents/CSproject/Child Accounts.txt");
        if(!f.open(QFile::ReadOnly | QFile::Text))
        {
            QMessageBox::warning(this,"title","file not open");
        }
        QTextStream inp(&f);
        line=inp.readLine();
        while(!line.isNull())
        {
            if(line==child)
            {
                if(progress == "level 1"){
                    ui->label_4->setText("Level 1 status:");
                    lev1 = "Not Completed";
                    wr1 = " ";
                    ui->label_5->setText("Level 2 status:");
                    lev2 = "Not Completed";
                    wr1 = " ";
                    ui->label_6->setText("Level 3 status:");
                    lev3 = "Not Completed";
                    wr3 = " ";
                }
                if(progress == "level 2"){
                    ui->label_4->setText("Level 1 Completed in: ");
                    lev1=inp.readLine();
                    wr1=inp.readLine();
                    ui->label_5->setText("Level 2 status:");
                    lev2 = "Not Completed";
                    wr2 = " ";
                    ui->label_6->setText("Level 3 status:");
                    lev3 = "Not Completed";
                    wr3 = " ";
                }
                else if(progress == "level 3"){
                    ui->label_4->setText("Level 1 Completed in: ");
                    lev1=inp.readLine();
                    wr1=inp.readLine();
                    ui->label_5->setText("Level 2 Completed in: ");
                    lev2=inp.readLine();
                    wr2=inp.readLine();
                    ui->label_6->setText("Level 3 status:");
                    lev3 = "Not Completed";
                    wr3 = " ";
                }
                else if(progress == "finished"){
                    ui->label_4->setText("Level 1 Completed in: ");
                    lev1=inp.readLine();
                    wr1=inp.readLine();
                    ui->label_5->setText("Level 2 Completed in: ");
                    lev2=inp.readLine();
                    wr2=inp.readLine();
                    ui->label_6->setText("Level 3 Completed in: ");
                    lev3=inp.readLine();
                    wr3=inp.readLine();
                }
                else{
                    ui->label_4->setText("Level 1 status:");
                    lev1 = "Not Started";
                    wr1 = " ";
                    ui->label_5->setText("Level 2 status:");
                    lev2 = "Not Started";
                    wr1 = " ";
                    ui->label_5->setText("Level 3 status:");
                    lev3 = "Not Started";
                    wr3 = " ";
                    ui->notStarted->setText("has not played the game yet.");
                }

            }
            line=inp.readLine();
        }
        f.close();

        ui->l1->setText(" "+lev1);
        ui->l2->setText(" "+lev2);
        ui->l3->setText(" "+lev3);

        ui->w1->setText(" "+wr1);
        ui->w2->setText(" "+wr2);
        ui->w3->setText(" "+wr3);
}

