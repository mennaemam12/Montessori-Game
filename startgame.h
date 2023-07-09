#ifndef STARTGAME_H
#define STARTGAME_H

#include <QDialog>
#include "level1.h"

namespace Ui {
class StartGame;
}

class StartGame : public QDialog
{
    Q_OBJECT

public:
    explicit StartGame(QWidget *parent = nullptr);
    Level1 *objlev1;
    ~StartGame();

private slots:
    void on_pushButton_clicked();

private:
    Ui::StartGame *ui;
};

#endif // STARTGAME_H
