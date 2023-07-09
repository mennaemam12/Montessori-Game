#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "choose.h"
#include "signup.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    Choose *objchoose;
    SignUp *objSignUp;
    ~MainWindow();

private slots:
    void on_signInButton_clicked();

    void on_signUpButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
