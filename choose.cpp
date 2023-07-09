#include "choose.h"
#include "ui_choose.h"

Choose::Choose(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Choose)
{
    ui->setupUi(this);
}

Choose::~Choose()
{
    delete ui;
}

void Choose::on_childButton_clicked()
{
    objchild = new SignIn;
    objchild->show();
    this->hide();
}


void Choose::on_parentButton_clicked()
{
    objparent = new SignIn2;
    objparent->show();
    this->hide();
}

