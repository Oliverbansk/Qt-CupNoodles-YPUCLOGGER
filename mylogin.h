#ifndef MYLOGIN_H
#define MYLOGIN_H


#include <QWidget>
#include "mylogininput.h"

namespace Ui {
class MyLogin;
}

class MyLogin : public QWidget
{
    Q_OBJECT

public:
    explicit MyLogin(QWidget *parent = 0);
    ~MyLogin();


signals:
    void showLoginInput();
    void showAdminLoginInput();
    void showVisitorPublicSpace();

private slots:
    void receiveLoginInput();
    void on_btUser_clicked();
    void on_btAdmin_clicked();
    void receiveAdminInput();
    void receiveAdminEdit();
    void receiveOthers();

    void on_btVisitor_clicked();

private:
    Ui::MyLogin *ui;

};

#endif // MYLOGIN_H
