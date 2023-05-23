#ifndef MYHOMEPAGE_H
#define MYHOMEPAGE_H

#include <QWidget>
#include "QString"
#include "QPushButton"

namespace Ui {
class MyHomepage;
}

class MyHomepage : public QWidget
{
    Q_OBJECT

public:
    explicit MyHomepage(QWidget *parent = nullptr);
    ~MyHomepage();
    QString history[15];
    QString top5[10];
    void setTop5(int i,QPushButton * button);
    void setHis(int i,QPushButton * button);
    void upload_str(QString kind,QString content);

signals://自己发出的信号
    void showLogin();
    void showPublicSpace();


private slots://接收他人信号的槽
    void receivePublicSpace();
    void on_publicSpaceButton_clicked();
    void on_return_button_clicked();

    void on_dateEdit_userDateChanged(const QDate &date);
    void on_photo_edit_clicked();

    void on_nickname_edit_clicked();
    void on_real_name_edit_clicked();
    void on_grade_edit_clicked();
    void on_major_edit_clicked();



    void on_top1_clicked();

    void on_top2_clicked();

    void on_top3_clicked();

    void on_top4_clicked();

    void on_top5_clicked();

    void on_movie1_clicked();

    void on_movie2_clicked();

    void on_movie3_clicked();

    void on_movie4_clicked();

    void on_movie5_clicked();

    void on_movie6_clicked();

    void on_movie7_clicked();

    void on_movie8_clicked();

    void on_movie9_clicked();

    void on_movie10_clicked();

private:
    Ui::MyHomepage *ui;
};

#endif // MYHOMEPAGE_H
