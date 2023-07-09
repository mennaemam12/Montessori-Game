#ifndef SIGNIN2_H
#define SIGNIN2_H

#include <QDialog>
#include "report.h"

namespace Ui {
class SignIn2;
}

class SignIn2 : public QDialog
{
    Q_OBJECT

public:
    explicit SignIn2(QWidget *parent = nullptr);
    Report *objreport;
    ~SignIn2();

private slots:
    void on_doneButton_2_clicked();

private:
    Ui::SignIn2 *ui;
};

#endif // SIGNIN2_H
