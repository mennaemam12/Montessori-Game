#ifndef CHOOSE_H
#define CHOOSE_H

#include <QDialog>
#include "signin.h"
#include "signin2.h"

namespace Ui {
class Choose;
}

class Choose : public QDialog
{
    Q_OBJECT

public:
    explicit Choose(QWidget *parent = nullptr);
    SignIn2 *objparent;
    SignIn *objchild;
    ~Choose();

private slots:
    void on_childButton_clicked();

    void on_parentButton_clicked();

private:
    Ui::Choose *ui;
};

#endif // CHOOSE_H
