#include "startgame.h"
#include "ui_startgame.h"

StartGame::StartGame(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StartGame)
{
    ui->setupUi(this);
}

StartGame::~StartGame()
{
    delete ui;
}

void StartGame::on_pushButton_clicked()
{
    objlev1 = new Level1;
    objlev1->show();
    this->hide();
}

