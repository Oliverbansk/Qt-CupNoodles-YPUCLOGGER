#ifndef MYADMINLOGIN_H
#define MYADMINLOGIN_H

#include <QWidget>

namespace Ui {
class MyAdminLoginInput;
}

class MyAdminLoginInput : public QWidget
{
    Q_OBJECT

public:
    explicit MyAdminLoginInput(QWidget *parent = nullptr);
    ~MyAdminLoginInput();

signals:
    void showLogin();
    void showAdminEdit();
    void showAgain();

private slots:
    void receiveLogin();

    void on_returnButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::MyAdminLoginInput *ui;
};

#endif // MYADMINLOGIN_H
