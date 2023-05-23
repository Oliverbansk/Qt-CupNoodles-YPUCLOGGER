#ifndef MYADDNEW_H
#define MYADDNEW_H

#include <QWidget>
#include "QString"

namespace Ui {
class MyAddNew;
}

class MyAddNew : public QWidget
{
    Q_OBJECT

public:
    explicit MyAddNew(QWidget *parent = nullptr);
    ~MyAddNew();
    QString posterPathNowChosen;

signals:
    void returnAdminEdit();

private slots:
    void receiveAdminEdit();

    void on_returnButton_clicked();

    void on_figureChooseButton_clicked();

    void on_confirmButton_clicked();

private:
    Ui::MyAddNew*ui;
};

#endif // MYADDNEW_H
