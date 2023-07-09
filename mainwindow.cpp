#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_signInButton_clicked()
{
    objchoose = new Choose;
    objchoose->show();
    this->hide();
}


void MainWindow::on_signUpButton_clicked()
{
    objSignUp = new SignUp;
    objSignUp->show();
}

