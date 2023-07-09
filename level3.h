#ifndef LEVEL3_H
#define LEVEL3_H

#include <QDialog>
#include "congrats.h"
#include <QTimer>

namespace Ui {
class Level3;
}

class Level3 : public QDialog
{
    Q_OBJECT

public:
    explicit Level3(QWidget *parent = nullptr);
    int sel3;
    int count3=0;
    int countWrong3=0;
    QTimer *timer3;
    QTimer *reset3;
    Congrats *objcongrats;
    ~Level3();

private slots:
    void on_nextButton3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void closeEvent(QCloseEvent *event);

    void hint();

    void reset();

private:
    Ui::Level3 *ui;
};

#endif // LEVEL3_H
