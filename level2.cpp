#include "level2.h"
#include "ui_level2.h"
#include <QMessageBox>
#include <QFile>
#include <ctime>
#include <time.h>
#include <QCloseEvent>
#include <QWidget>
#include <QTextStream>
#include <QTimer>
#include <QTime>

using namespace std;
double startTimeLev2=time(0);

Level2::Level2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Level2)
{
    ui->setupUi(this);
    srand(time(0));
    sel2=rand()%4+1;

    QTimer *timer2 = new QTimer(this);
    connect(timer2,SIGNAL(timeout()),this,SLOT(hint()));
    timer2->start(25000);

    QTimer *reset2 = new QTimer(this);
    connect(reset2,SIGNAL(timeout()),this,SLOT(reset()));
    reset2->start(8000);

    if(sel2 == 1)
    {
        QPixmap pix(":/background/images/1.jpg");
        int w = ui->label_pic2->width();
        int h= ui->label_pic2->height();
        ui->label_pic2->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    }
    else if(sel2 == 2)
    {
        QPixmap pix(":/background/images/2.jpg");
        int w = ui->label_pic2->width();
        int h= ui->label_pic2->height();
        ui->label_pic2->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    }
    else if(sel2==3)
       { QPixmap pix(":/background/images/3.jpg");
        int w = ui->label_pic2->width();
        int h= ui->label_pic2->height();
        ui->label_pic2->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    }
    else
    {
        QPixmap pix(":/background/images/4.jpg");
                int w = ui->label_pic2->width();
                int h= ui->label_pic2->height();
                ui->label_pic2->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    }
}

Level2::~Level2()
{
    delete ui;
}

void Level2::hint()
{
    if(sel2==1)
        ui->pushButton->setStyleSheet(QString("QPushButton{background-color:#86ff52}"));
    else if(sel2==2)
        ui->pushButton_2->setStyleSheet(QString("QPushButton{background-color:#86ff52}"));
    else if(sel2==3)
        ui->pushButton_3->setStyleSheet(QString("QPushButton{background-color:#86ff52}"));
    else
        ui->pushButton_4->setStyleSheet(QString("QPushButton{background-color:#86ff52}"));
}

void Level2::reset()
{
    if(sel2==1)
        ui->pushButton->setStyleSheet(QString("QPushButton{background-color:rgb(18, 97, 154)}"));
    else if(sel2==2)
        ui->pushButton_2->setStyleSheet(QString("QPushButton{background-color:rgb(18, 97, 154)}"));
    else if(sel2==3)
        ui->pushButton_3->setStyleSheet(QString("QPushButton{background-color:rgb(18, 97, 154)}"));
    else
        ui->pushButton_4->setStyleSheet(QString("QPushButton{background-color:rgb(18, 97, 154)}"));
}

void Level2::on_pushButton_clicked()
{
    if(sel2 == 1){
    QMessageBox::information(this,"Congratulations","Correct Answer!");
    ui->nextButton2->setDisabled(false);
    ui->ansBox2->setText("15");
   }
    else
    {
        QMessageBox::information(this,"No Problem!","Try Again");
        ui->nextButton2->setDisabled(true);
        countWrong2++;
    }
}


void Level2::on_pushButton_2_clicked()
{
    if(sel2==2){
        QMessageBox::information(this,"Congratulations","Correct Answer!");
        ui->nextButton2->setDisabled(false);
        ui->ansBox2->setText("11");

    }
    else {
        QMessageBox::information(this,"No Problem!","Try Again");
        ui->nextButton2->setDisabled(true);
        countWrong2++;
    }
}


void Level2::on_pushButton_3_clicked()
{
    if(sel2==3){
        QMessageBox::information(this,"Congratulations","Correct Answer!");
        ui->nextButton2->setDisabled(false);
        ui->ansBox2->setText("9");
    }
    else{
            QMessageBox::information(this,"No Problem!","Try Again");
            ui->nextButton2->setDisabled(true);
            countWrong2++;
        }
}


void Level2::on_pushButton_4_clicked()
{
    if(sel2==4){
        QMessageBox::information(this,"Congratulations","Correct Answer!");
        ui->nextButton2->setDisabled(false);
        ui->ansBox2->setText("6");

    }
    else {
        QMessageBox::information(this,"No Problem!","Try Again");
        ui->nextButton2->setDisabled(true);
        countWrong2++;
    }
}

void Level2::closeEvent(QCloseEvent *event)
{
    QFile file ("C:/Users/shahd/OneDrive/Documents/CSproject/infoFile.txt");
    if(!file.open(QFile::ReadWrite |QFile::Text|QFile::Append))
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
                if(!line.isNull()){
                    empty = false;
                }
            }
        }
    }
    if(empty == true){
        level = "level 2";
        out << level << Qt::endl;
    }
    else
    {
        line.clear();
        out << line;
        level = "level 2";
        out << level;
    }

    file.close();
    child.close();
}

void Level2::on_nextButton2_clicked()
{
    reset();

    ui->ansBox2->setText(" ");

    QTimer *timer2 = new QTimer(this);
    connect(timer2,SIGNAL(timeout()),this,SLOT(hint()));
    timer2->start(25000);

    QTimer *reset2 = new QTimer(this);
    connect(reset2,SIGNAL(timeout()),this,SLOT(reset()));
    reset2->start(8000);

    if(sel2 == 1)
    {
        sel2 = rand()% 3 +1;
        if(sel2 == 2){
            ui->nextButton2->setDisabled(true);
            QPixmap pix(":/background/images/2.jpg");
            int w = ui->label_pic2->width();
            int h= ui->label_pic2->height();
            ui->label_pic2->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
            count2++;
        }
        else if(sel2==3)
           {
            ui->nextButton2->setDisabled(true);
            QPixmap pix(":/background/images/3.jpg");
            int w = ui->label_pic2->width();
            int h= ui->label_pic2->height();
            ui->label_pic2->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
            count2++;
        }
        else {
            ui->nextButton2->setDisabled(true);
            QPixmap pix(":/background/images/4.jpg");
            int w = ui->label_pic2->width();
            int h= ui->label_pic2->height();
            ui->label_pic2->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
            count2++;

        }
    }
    else if(sel2 == 3)
    {

        sel2 = rand()% 3 +1;
        if(sel2 == 1){
            ui->nextButton2->setDisabled(true);
            QPixmap pix(":/background/images/1.jpg");
            int w = ui->label_pic2->width();
            int h= ui->label_pic2->height();
            ui->label_pic2->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
            count2++;
        }
        else if(sel2==2)
           {
            ui->nextButton2->setDisabled(true);
            QPixmap pix(":/background/images/2.jpg");
            int w = ui->label_pic2->width();
            int h= ui->label_pic2->height();
            ui->label_pic2->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
            count2++;
        }
        else
        {
            sel2=4;
            ui->nextButton2->setDisabled(true);
            QPixmap pix(":/background/images/4.jpg");
            int w = ui->label_pic2->width();
            int h= ui->label_pic2->height();
            ui->label_pic2->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
            count2++;
        }
    }
    else if(sel2==2){

        sel2 = rand()%3+1;
        if(sel2 == 1){
            ui->nextButton2->setDisabled(true);
            QPixmap pix(":/background/images/1.jpg");
            int w = ui->label_pic2->width();
            int h= ui->label_pic2->height();
            ui->label_pic2->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
            count2++;
        }
        else if(sel2==3)
        {
            ui->nextButton2->setDisabled(true);
            QPixmap pix(":/background/images/3.jpg");
            int w = ui->label_pic2->width();
            int h= ui->label_pic2->height();
            ui->label_pic2->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
            count2++;
        }
        else
        {
            sel2 = 4;
            ui->nextButton2->setDisabled(true);
            QPixmap pix(":/background/images/4.jpg");
            int w = ui->label_pic2->width();
            int h= ui->label_pic2->height();
            ui->label_pic2->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
            count2++;
        }

    }
    else if(sel2==4)
    {

        sel2 = rand()%3+1;
        if(sel2==1){
            ui->nextButton2->setDisabled(true);
            QPixmap pix(":/background/images/1.jpg");
            int w = ui->label_pic2->width();
            int h= ui->label_pic2->height();
            ui->label_pic2->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
            count2++;
        }
        else if(sel2 == 2){
            ui->nextButton2->setDisabled(true);
            QPixmap pix(":/background/images/2.jpg");
            int w = ui->label_pic2->width();
            int h= ui->label_pic2->height();
            ui->label_pic2->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
            count2++;
        }
        else{
            ui->nextButton2->setDisabled(true);
            QPixmap pix(":/background/images/3.jpg");
            int w = ui->label_pic2->width();
            int h= ui->label_pic2->height();
            ui->label_pic2->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
            count2++;
        }
    }
    if(count2 == 2)
    {
        double endTimeLev2 = time(0);
        double lev2Time = endTimeLev2 -startTimeLev2;
        QFile file2("C:/Users/shahd/OneDrive/Documents/CSproject/Child Accounts.txt");
        if(!file2.open(QFile::WriteOnly | QFile::Text | QFile:: Append))
        {
            QMessageBox::warning(this,"title","File not open");
        }
        QTextStream out(&file2);
        out << lev2Time << Qt::endl;
        out << countWrong2 << Qt::endl;
        file2.close();
        objlev3=new Level3;
        objlev3->show();
        this->hide();
    }


}

