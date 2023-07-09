#include "level3.h"
#include "ui_level3.h"
#include <QFile>
#include <QMessageBox>
#include <ctime>
#include <time.h>
#include <QWidget>
#include <QTimer>
#include <QTime>
#include <QCloseEvent>
#include <QWidget>

using namespace std;
double startTimeLev3=time(0);

Level3::Level3(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Level3)
{
    ui->setupUi(this);
    srand(time(0));
    sel3=rand()%5+1;

    QTimer *timer3 = new QTimer(this);
    connect(timer3,SIGNAL(timeout()),this,SLOT(hint()));
    timer3->start(30000);

    QTimer *reset3 = new QTimer(this);
    connect(reset3,SIGNAL(timeout()),this,SLOT(reset()));
    reset3->start(8000);


    if(sel3 == 1)
    {
        QPixmap pix(":/background/images/Q1L3.jpg");
        int w = ui->label_pic3->width();
        int h= ui->label_pic3->height();
        ui->label_pic3->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    }
    else if(sel3 == 2)
    {
        QPixmap pix(":/background/images/2Q2.jpg");
        int w = ui->label_pic3->width();
        int h= ui->label_pic3->height();
        ui->label_pic3->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    }
    else if(sel3==3)
    {
        QPixmap pix(":/background/images/Q3L3.jpg");
        int w = ui->label_pic3->width();
        int h= ui->label_pic3->height();
        ui->label_pic3->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    }
    else if(sel3==4)
    {
        QPixmap pix(":/background/images/2Q4.jpg");
        int w = ui->label_pic3->width();
        int h= ui->label_pic3->height();
        ui->label_pic3->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    }
    else{
        QPixmap pix(":/background/images/2Q5.jpg");
        int w = ui->label_pic3->width();
        int h= ui->label_pic3->height();
        ui->label_pic3->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    }
}

Level3::~Level3()
{
    delete ui;
}

void Level3::hint()
{
    if(sel3==1)
        ui->pushButton->setStyleSheet(QString("QPushButton{background-color:#86ff52}"));
    else if(sel3==2)
        ui->pushButton_2->setStyleSheet(QString("QPushButton{background-color:#86ff52}"));
    else if(sel3==3)
        ui->pushButton_3->setStyleSheet(QString("QPushButton{background-color:#86ff52}"));
    else
        ui->pushButton_4->setStyleSheet(QString("QPushButton{background-color:#86ff52}"));
}

void Level3::reset()
{
    if(sel3==1)
        ui->pushButton->setStyleSheet(QString("QPushButton{background-color:rgb(18, 97, 154)}"));
    else if(sel3==2)
        ui->pushButton_2->setStyleSheet(QString("QPushButton{background-color:rgb(18, 97, 154)}"));
    else if(sel3==3)
        ui->pushButton_3->setStyleSheet(QString("QPushButton{background-color:rgb(18, 97, 154)}"));
    else
        ui->pushButton_4->setStyleSheet(QString("QPushButton{background-color:rgb(18, 97, 154)}"));
}

void Level3::on_pushButton_clicked()
{
    if(sel3 == 1){
        QMessageBox::information(this,"Congratulations","Correct Answer!");
        ui->nextButton3->setDisabled(false);
        ui->ansBox5->setText("3");
   }
    else
    {
        QMessageBox::information(this,"No Problem!","Try Again");
        ui->nextButton3->setDisabled(true);
        countWrong3++;
    }
}


void Level3::on_pushButton_2_clicked()
{
    if(sel3==2){
        QMessageBox::information(this,"Congratulations","Correct Answer!");
        ui->nextButton3->setDisabled(false);
        ui->ansBox4->setText("4");

    }
    else {
        QMessageBox::information(this,"No Problem!","Try Again");
        ui->nextButton3->setDisabled(true);
        countWrong3++;
    }
}


void Level3::on_pushButton_3_clicked()
{
    if(sel3==3){
        QMessageBox::information(this,"Congratulations","Correct Answer!");
        ui->nextButton3->setDisabled(false);
        ui->ansBox3->setText("9");
    }
    else{
            QMessageBox::information(this,"No Problem!","Try Again");
            ui->nextButton3->setDisabled(true);
            countWrong3++;
        }
}


void Level3::on_pushButton_4_clicked()
{
    if(sel3==4){
        QMessageBox::information(this,"Congratulations","Correct Answer!");
        ui->nextButton3->setDisabled(false);
        ui->ansBox5->setText("2");
    }
    else if(sel3==5)
    {
        QMessageBox::information(this,"Congratulations","Correct Answer!");
        ui->nextButton3->setDisabled(false);
        ui->ansBox5->setText("2");
    }
    else{
        QMessageBox::information(this,"No Problem!","Try Again");
        ui->nextButton3->setDisabled(true);
        countWrong3++;
    }
}

void Level3::closeEvent(QCloseEvent *event)
{
    QFile file ("C:/Users/shahd/OneDrive/Documents/CSproject/infoFile.txt");
    if(!file.open(QFile:: ReadWrite|QFile::Text|QFile::Append))
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
    line = in.readLine() ;
    while(!line.isNull()){

        line = in.readLine();
        line = in.readLine();

        if(line == childUsername)
        {

            line = in.readLine();
            if(line == childPassword)
            {
                line = in.readLine();
                if(!line.isNull()){
                    empty = false;
                }

            }
        }

    }
    if(empty == true)
    {
        level = "level 3";
        out << level << Qt::endl;
    }
    else
    {
        line.clear();
        out << line;
        level = "level 3";
        out << level;
    }

    file.close();
    child.close();
}



void Level3::on_nextButton3_clicked()
{

    reset();
    ui->ansBox3->setText(" ");
    ui->ansBox4->setText(" ");
    ui->ansBox5->setText(" ");



    QTimer *timer3 = new QTimer(this);
    connect(timer3,SIGNAL(timeout()),this,SLOT(hint()));
    timer3->start(30000);

    QTimer *reset3 = new QTimer(this);
    connect(reset3,SIGNAL(timeout()),this,SLOT(reset()));
    reset3->start(8000);

    if(sel3 == 1)
    {
        ui->nextButton3->setDisabled(true);
        sel3 = rand()% 4 +2;
        if(sel3 == 2){
            QPixmap pix(":/background/images/2Q2.jpg");
            int w = ui->label_pic3->width();
            int h= ui->label_pic3->height();
            ui->label_pic3->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
            count3++;
        }
        else if(sel3==3)
           {
            ui->nextButton3->setDisabled(true);
            QPixmap pix(":/background/images/Q3L3.jpg");
            int w = ui->label_pic3->width();
            int h= ui->label_pic3->height();
            ui->label_pic3->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
            count3++;
        }
        else if(sel3==4){
            ui->nextButton3->setDisabled(true);
            QPixmap pix(":/background/images/2Q4.jpg");
            int w = ui->label_pic3->width();
            int h= ui->label_pic3->height();
            ui->label_pic3->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
            count3++;
        }
        else{
            ui->nextButton3->setDisabled(true);
            QPixmap pix(":/background/images/2Q5.jpg");
            int w = ui->label_pic3->width();
            int h= ui->label_pic3->height();
            ui->label_pic3->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
            count3++;
        }
    }
    else if(sel3 == 3)
    {
        sel3 = rand()% 4 +1;
        if(sel3 == 3){
            sel3=1;
            ui->nextButton3->setDisabled(true);
            QPixmap pix(":/background/Q1L3.jpg");
            int w = ui->label_pic3->width();
            int h= ui->label_pic3->height();
            ui->label_pic3->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
            count3++;
        }
        else if(sel3==2)
           {
            ui->nextButton3->setDisabled(true);
            QPixmap pix(":/background/images/2Q2.jpg");
            int w = ui->label_pic3->width();
            int h= ui->label_pic3->height();
            ui->label_pic3->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
            count3++;
        }
        else if(sel3==4)
        {
            ui->nextButton3->setDisabled(true);
            QPixmap pix(":/background/images/2Q4.jpg");
            int w = ui->label_pic3->width();
            int h= ui->label_pic3->height();
            ui->label_pic3->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
            count3++;
        }
        else{
            ui->nextButton3->setDisabled(true);
            QPixmap pix(":/background/images/2Q5.jpg");
            int w = ui->label_pic3->width();
            int h= ui->label_pic3->height();
            ui->label_pic3->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
            count3++;
        }

    }
    else if(sel3==2){
        sel3 = rand()%4+1;
        if(sel3 == 2){
            sel3=1;
            ui->nextButton3->setDisabled(true);
            QPixmap pix(":/background/images/Q1L3.jpg");
            int w = ui->label_pic3->width();
            int h= ui->label_pic3->height();
            ui->label_pic3->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
            count3++;
        }
        else if(sel3==3)
        {
            ui->nextButton3->setDisabled(true);
            QPixmap pix(":/background/images/Q3L3.jpg");
            int w = ui->label_pic3->width();
            int h= ui->label_pic3->height();
            ui->label_pic3->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
            count3++;
        }
        else if(sel3==4)
        {
            ui->nextButton3->setDisabled(true);
            QPixmap pix(":/background/images/2Q4.jpg");
            int w = ui->label_pic3->width();
            int h= ui->label_pic3->height();
            ui->label_pic3->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
            count3++;
        }
        else{
            ui->nextButton3->setDisabled(true);
            QPixmap pix(":/background/images/2Q5.jpg");
            int w = ui->label_pic3->width();
            int h= ui->label_pic3->height();
            ui->label_pic3->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
            count3++;
        }

    }
    else if(sel3==4)
    {
        sel3 = rand()%4+1;
        if(sel3==4){
            sel3=1;
            ui->nextButton3->setDisabled(true);
            QPixmap pix(":/background/images/Q1L3.jpg");
            int w = ui->label_pic3->width();
            int h= ui->label_pic3->height();
            ui->label_pic3->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
            count3++;
        }
        else if(sel3 == 2){
            ui->nextButton3->setDisabled(true);
            QPixmap pix(":/background/images/2Q2.jpg");
            int w = ui->label_pic3->width();
            int h= ui->label_pic3->height();
            ui->label_pic3->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
            count3++;
        }
        else if(sel3==3){
            ui->nextButton3->setDisabled(true);
            QPixmap pix(":/background/images/Q3L3.jpg");
            int w = ui->label_pic3->width();
            int h= ui->label_pic3->height();
            ui->label_pic3->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
            count3++;
        }
        else{
            ui->nextButton3->setDisabled(true);
            QPixmap pix(":/background/images/2Q5.jpg");
            int w = ui->label_pic3->width();
            int h= ui->label_pic3->height();
            ui->label_pic3->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
            count3++;
        }
    }
    else
    {
        sel3 = rand()%4+1;
        if(sel3==1){
            ui->nextButton3->setDisabled(true);
            QPixmap pix(":/background/images/Q1L3.jpg");
            int w = ui->label_pic3->width();
            int h= ui->label_pic3->height();
            ui->label_pic3->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
            count3++;
        }
        else if(sel3 == 2){
            ui->nextButton3->setDisabled(true);
            QPixmap pix(":/background/images/2Q2.jpg");
            int w = ui->label_pic3->width();
            int h= ui->label_pic3->height();
            ui->label_pic3->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
            count3++;
        }
        else if(sel3==3){
            ui->nextButton3->setDisabled(true);
            QPixmap pix(":/background/images/Q3L3.jpg");
            int w = ui->label_pic3->width();
            int h= ui->label_pic3->height();
            ui->label_pic3->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
            count3++;
        }
        else{
            ui->nextButton3->setDisabled(true);
            QPixmap pix(":/background/images/2Q4.jpg");
            int w = ui->label_pic3->width();
            int h= ui->label_pic3->height();
            ui->label_pic3->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
            count3++;
        }

    }
    if(count3 == 3)
    {
         double endTimeLev3=time(0);
         double lev3Time=endTimeLev3-startTimeLev3;
         QFile file2("C:/Users/shahd/OneDrive/Documents/CSproject/Child Accounts.txt");
         if(!file2.open(QFile::WriteOnly | QFile::Text | QFile:: Append))
         {
             QMessageBox::warning(this,"title","File not open");
         }
         QTextStream out(&file2);
         out << lev3Time << Qt::endl;
         out << countWrong3 << Qt::endl;
         file2.close();
         objcongrats = new Congrats;
         objcongrats->show();
         this->hide();
    }


}


