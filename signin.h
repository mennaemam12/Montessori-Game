#ifndef SIGNIN_H
#define SIGNIN_H

#include <QDialog>
#include "startgame.h"
#include "level1.h"
#include "level2.h"
#include "level3.h"

namespace Ui {
class SignIn;
}

class SignIn : public QDialog
{
    Q_OBJECT

public:
    explicit SignIn(QWidget *parent = nullptr);
    StartGame *objstart;
    Level1 *objlev1;
    Level2 *objlev2;
    Level3 *objlev3;
    int countR =0;
    ~SignIn();

private slots:
    void on_doneButton_clicked();

private:
    Ui::SignIn *ui;
};

#endif // SIGNIN_H
