#ifndef MYMOVIEDETAIL_H
#define MYMOVIEDETAIL_H

#include <QWidget>
#include "global.h"

namespace Ui {
class MyMovieDetail;
}

class MyMovieDetail : public QWidget
{
    Q_OBJECT

public:
    explicit MyMovieDetail(QWidget *parent = 0);
    ~MyMovieDetail();

signals:
    void showPublicSpace();

private slots:
    void on_returnButton_clicked();
    void receivePublicSpace();

    void on_commentButton_clicked();

private:
    Ui::MyMovieDetail *ui;
};

#endif // MYMOVIEDETAIL_H
