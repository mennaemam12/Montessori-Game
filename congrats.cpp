#include "congrats.h"
#include "ui_congrats.h"
#include <QMessageBox>
#include <QFile>
#include <QCloseEvent>
#include <QWidget>

Congrats::Congrats(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Congrats)
{
    ui->setupUi(this);
}

void Congrats::closeEvent(QCloseEvent *event)
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
                line = in.readLine();
                if(!line.isNull())
                    empty = false;
            }
        }
    }
    if(empty == true){
        level = "finished";
        out << level << Qt::endl;
    }
    else
    {
        line.clear();
        out << line;
        level = "finished";
        out << level;
    }
    file.close();
    child.close();
}
Congrats::~Congrats()
{
    delete ui;
}
