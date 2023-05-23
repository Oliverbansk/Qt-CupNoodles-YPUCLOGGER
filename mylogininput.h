#ifndef MYLOGININPUT_H
#define MYLOGININPUT_H


#include <QWidget>
#include "QtSql/QSqlDatabase"
#include "QtSql/QSqlQuery"


namespace Ui {
class MyLoginInput;
}

class MyLoginInput : public QWidget
{
    Q_OBJECT

public:
    explicit MyLoginInput(QWidget *parent = 0);
    ~MyLoginInput();

signals:
    void showLogin();
    void showPublicSpace();

private slots:
    void on_returnButton_clicked();
    void receiveLogin();
    void receiveLogin_noregister();

    void on_loginButton_clicked();
    void on_registerButton_clicked();

private:
    Ui::MyLoginInput *ui;
    QSqlDatabase db_users;
    QSqlDatabase db_admins;
};

#endif // MYLOGININPUT_H
