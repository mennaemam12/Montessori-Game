#ifndef LEVEL2_H
#define LEVEL2_H

#include <QDialog>
#include "level3.h"
#include <QTimer>
#include <QCloseEvent>

namespace Ui {
class Level2;
}

class Level2 : public QDialog
{
    Q_OBJECT

public:
    explicit Level2(QWidget *parent = nullptr);
    int sel2;
    int count2=0;
    int countWrong2=0;
    QTimer *timer2;
    QTimer *reset2;
    Level3 *objlev3;
    ~Level2();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_nextButton2_clicked();

    void closeEvent(QCloseEvent *event);

    void hint();

    void reset();

private:
    Ui::Level2 *ui;
};

#endif // LEVEL2_H
