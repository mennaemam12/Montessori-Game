#ifndef CONGRATS_H
#define CONGRATS_H

#include <QDialog>

namespace Ui {
class Congrats;
}

class Congrats : public QDialog
{
    Q_OBJECT

public:
    explicit Congrats(QWidget *parent = nullptr);
    ~Congrats();

    void closeEvent(QCloseEvent *event);

private:
    Ui::Congrats *ui;
};

#endif // CONGRATS_H
