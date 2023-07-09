#include "level1.h"
#include "ui_level1.h"
#include <QMessageBox>
#include <QFile>
#include <ctime>
#include <time.h>
#include <QCloseEvent>
#include <QWidget>
#include <QTimer>
#include <QTime>

using namespace std;
double startTimeLev1 = time(0);

Level1::Level1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Level1)
{
    ui->setupUi(this);
    srand(time(0));
    sel=rand()%4+1;

    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(hint()));
    timer->start(20000);

    QTimer *reset = new QTimer(this);
    connect(reset,SIGNAL(timeout()),this,SLOT(reset1()));
    reset->start(8000);

    if(sel == 1)
    {
        QPixmap pix(":/background/images/Q1.jpg");
        int w = ui->label_pic->width();
        int h= ui->label_pic->height();
        ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    }
    else if(sel == 2)
    {
        QPixmap pix(":/background/images/Q2.jpg");
        int w = ui->label_pic->width();
        int h= ui->label_pic->height();
        ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    }
    else if(sel==3)
       { QPixmap pix(":/background/images/Q3.jpg");
        int w = ui->label_pic->width();
        int h= ui->label_pic->height();
        ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    }
    else
    {
        QPixmap pix(":/background/images/Q4.jpg");
                int w = ui->label_pic->width();
                int h= ui->label_pic->height();
                ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    }
}

Level1::~Level1()
{
    delete ui;
}

void Level1::hint()
{
    if(sel==1)
        ui->pushButton->setStyleSheet(QString("QPushButton{background-color:#86ff52},font: 16pt"));
    else if(sel==2)
        ui->pushButton_2->setStyleSheet(QString("QPushButton{background-color:#86ff52},font: 16pt"));
    else
        ui->pushButton_3->setStyleSheet(QString("QPushButton{background-color:#86ff52},font: 16pt"));
}

void Level1::reset1()
{
    if(sel==1)
        ui->pushButton->setStyleSheet(QString("QPushButton{background-color:rgb(18, 97, 154)},font: 16pt"));
    else if(sel==2)
        ui->pushButton_2->setStyleSheet(QString("QPushButton{background-color:rgb(18, 97, 154)},font: 16pt"));
    else
        ui->pushButton_3->setStyleSheet(QString("QPushButton{background-color:rgb(18, 97, 154)},font: 16pt"));
}

void Level1::on_pushButton_clicked()
{
    if(sel == 1){
    QMessageBox::information(this,"Congratulations","Correct Answer!");
    ui->nextButton->setDisabled(false);
    ui->ansBox->setText("5");
   }
    else
    {
        QMessageBox::information(this,"No Problem!","Try Again");
        ui->nextButton->setDisabled(true);
        countWrong++;
    }

}


void Level1::on_pushButton_2_clicked()
{
    if(sel==2){
        QMessageBox::information(this,"Congratulations","Correct Answer!");
        ui->nextButton->setDisabled(false);
        ui->ansBox->setText("10");

    }
    else {
        QMessageBox::information(this,"No Problem!","Try Again");
        ui->nextButton->setDisabled(true);
        countWrong++;
    }
}



void Level1::on_pushButton_3_clicked()
{
    if(sel==3){
        QMessageBox::information(this,"Congratulations","Correct Answer!");
        ui->nextButton->setDisabled(false);
        ui->ansBox->setText("8");
    }
    else if(sel==4)
    {
        QMessageBox::information(this,"Congratulations","Correct Answer!");
        ui->nextButton->setDisabled(false);
        ui->ansBox->setText("8");
    }
    else{
        QMessageBox::information(this,"No Problem!","Try Again");
        ui->nextButton->setDisabled(true);
        countWrong++;
    }
}



void Level1::on_pushButton_4_clicked()
{
    QMessageBox::information(this,"No Problem!","Try Again");
    ui->nextButton->setDisabled(true);
    countWrong++;
}

void Level1::closeEvent(QCloseEvent *event)
{
    QFile file ("C:/Users/shahd/OneDrive/Documents/CSproject/infoFile.txt");
    if(!file.open(QFile::ReadWrite|QFile::Text|QFile::Append))
    {
        QMessageBox::warning(this,"title","file not open.");
    }
    QTextStream out(&file);
    QFile child("C:/Users/shahd/OneDrive/Documents/CSproject/Current Child.txt");
        if(!child.open(QFile::ReadOnly | QFile::Text)){
            QMessageBox::warning(this,"title","file not open.");
        }
    QTextStream w(&child);
    QString childUsername  = w.readLine();
    QString childPassword = w.readLine();

    QTextStream in(&file);
    QString line;
    QString level;
    bool empty = true;
    line = in.readLine();
    while(!line.isNull()){

        line = in.readLine();
        line = in.readLine();

        if(line == childUsername)
        {
            line = in.readLine();
            if(line == childPassword)
            {
                line = in.readLine();
                if(!line.isNull())
                        empty = false;
            }
        }

    }
    if(empty == true)
    {
        level = "level 1";
        out << level << Qt::endl;
    }
    else
    {
        line.clear();
        out << line;
        level = "level 1";
        out << level;
    }

    file.close();
    child.close();
}

void Level1::on_nextButton_clicked()
{
     reset1();
    ui->ansBox->setText(" ");


    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(hint()));
    timer->start(20000);

    QTimer *reset = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(reset()));
    reset->start(8000);

    srand(time(0));
    if(sel == 1)
    {
        ui->nextButton->setDisabled(true);
        sel = rand()% 4 +2;
        if(sel == 2){
            QPixmap pix(":/background/images/Q2.jpg");
            int w = ui->label_pic->width();
            int h= ui->label_pic->height();
            ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
            count++;
        }
        else if(sel==3)
           {
            ui->nextButton->setDisabled(true);
            QPixmap pix("::/background/images/Q3.jpg");
            int w = ui->label_pic->width();
            int h= ui->label_pic->height();
            ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
            count++;
        }
        else {
            ui->nextButton->setDisabled(true);
            QPixmap pix(":/background/images/Q4.jpg");
            int w = ui->label_pic->width();
            int h= ui->label_pic->height();
            ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
            count++;

        }
    }
    else if(sel == 3)
    {
        sel = rand()% 3 +1;
        if(sel == 1){
            ui->nextButton->setDisabled(true);
            QPixmap pix(":/background/images/Q1.jpg");
            int w = ui->label_pic->width();
            int h= ui->label_pic->height();
            ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
            count++;
        }
        else if(sel==2)
           {
            ui->nextButton->setDisabled(true);
            QPixmap pix(":/background/images/Q2.jpg");
            int w = ui->label_pic->width();
            int h= ui->label_pic->height();
            ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
            count++;
        }
        else
        {
            sel=4;
            ui->nextButton->setDisabled(true);
            QPixmap pix(":/background/images/Q4.jpg");
            int w = ui->label_pic->width();
            int h= ui->label_pic->height();
            ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
            count++;
        }
    }
    else if(sel==2){
        sel = rand()%3+2;
        if(sel == 2){
            sel=1;
            ui->nextButton->setDisabled(true);
            QPixmap pix(":/background/images/Q1.jpg");
            int w = ui->label_pic->width();
            int h= ui->label_pic->height();
            ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
            count++;
        }
        else if(sel==3)
        {
            ui->nextButton->setDisabled(true);
            QPixmap pix(":/background/images/Q3.jpg");
            int w = ui->label_pic->width();
            int h= ui->label_pic->height();
            ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
            count++;
        }
        else
        {
            ui->nextButton->setDisabled(true);
            QPixmap pix(":/background/images/Q4.jpg");
            int w = ui->label_pic->width();
            int h= ui->label_pic->height();
            ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
            count++;
        }

    }
    else if(sel==4)
    {
        sel = rand()%3+1;
        if(sel==1){
            ui->nextButton->setDisabled(true);
            QPixmap pix(":/background/images/Q1.jpg");
            int w = ui->label_pic->width();
            int h= ui->label_pic->height();
            ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
            count++;
        }
        else if(sel == 2){
            ui->nextButton->setDisabled(true);
            QPixmap pix(":/background/images/Q2.jpg");
            int w = ui->label_pic->width();
            int h= ui->label_pic->height();
            ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
            count++;
        }
        else{
            ui->nextButton->setDisabled(true);
            QPixmap pix(":/background/images/Q3.jpg");
            int w = ui->label_pic->width();
            int h= ui->label_pic->height();
            ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
            count++;
        }
    }
    if(count == 2)
    {
        double endTimeLev1 = time(0);
        double lev1Time= endTimeLev1 -startTimeLev1;
        QFile file2("C:/Users/shahd/OneDrive/Documents/CSproject/Child Accounts.txt");
        if(!file2.open(QFile::WriteOnly | QFile::Text | QFile:: Append))
        {
            QMessageBox::warning(this,"title","File not open");
        }
        QTextStream out(&file2);
        out << lev1Time << Qt::endl;
        out << countWrong << Qt::endl;
        file2.close();
        objlev2=new Level2;
        objlev2->show();
        this->hide();
    }




}

