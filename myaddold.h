#ifndef MYADDOLD_H
#define MYADDOLD_H

#include <QWidget>

namespace Ui {
class MyAddOld;
}

class MyAddOld : public QWidget
{
    Q_OBJECT

public:
    explicit MyAddOld(QWidget *parent = nullptr);
    ~MyAddOld();
signals:
    void returnAdminEdit();

private slots:
    void receiveAdminEdit();


    void on_returnButton_clicked();

    void on_confirmButton_clicked();

private:
    Ui::MyAddOld *ui;
};

#endif // MYADDOLD_H
