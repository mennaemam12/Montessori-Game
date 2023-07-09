#include "signup.h"
#include "ui_signup.h"
#include <QMessageBox>
#include <QFile>

SignUp::SignUp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SignUp)
{
    ui->setupUi(this);
}

SignUp::~SignUp()
{
    delete ui;
}

void SignUp::on_pushButton_clicked()
{
    QFile file("C:/Users/shahd/OneDrive/Documents/CSproject/infoFile.txt");
    if(!file.open(QFile::WriteOnly | QFile::Text | QFile::Append)){
        QMessageBox::warning(this,"title","file not open.");
    }
    QTextStream out(&file);
    QString usernameParent = ui->usernameParentTE->toPlainText();
    QString passwordParent = ui->passwordParentTE->toPlainText();
    QString usernameChild = ui->usernameChildTE->toPlainText();
    QString passwordChild = ui->passwordChildTE->toPlainText();

    out << usernameParent << Qt::endl;
    out << passwordParent << Qt::endl;
    out << usernameChild << Qt::endl;
    out << passwordChild << Qt::endl;
    file.close();
    QMessageBox::information(this,"title","Your Account Has Been Created!");
    this->hide();
}

