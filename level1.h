#ifndef LEVEL1_H
#define LEVEL1_H

#include <QDialog>
#include "level2.h"
#include <QTimer>

namespace Ui {
class Level1;
}

class Level1 : public QDialog
{
    Q_OBJECT

public:
    explicit Level1(QWidget *parent = nullptr);
    int sel;
    int count=0;
    int countWrong=0;
    QTimer *timer;
    QTimer *reset;
    Level2 *objlev2;

    ~Level1();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_nextButton_clicked();

    void closeEvent(QCloseEvent *event);

    void hint();

    void reset1();

private:
    Ui::Level1 *ui;
};

#endif // LEVEL1_H
