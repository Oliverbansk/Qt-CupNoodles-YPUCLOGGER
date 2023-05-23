#ifndef MYPUBLICSPACE_H
#define MYPUBLICSPACE_H

#include <QWidget>
#include "QLabel"

namespace Ui {
class MyPublicSpace;
}

class MyPublicSpace : public QWidget
{
    Q_OBJECT

public:
    explicit MyPublicSpace(QWidget *parent = 0);
    ~MyPublicSpace();
    void setMovieBanner(QLabel * poster_, QString posterStr, QLabel * moviename_, QString movienameStr,
                        QLabel * year_, QString yearStr, QLabel * director_, QString directorStr,
                        QLabel * region_ , QString regionStr, QLabel * ypuclabel_,double ypuc_val,
                        QLabel * dblabel_,double db_val, QLabel * y1,QLabel * y2,QLabel * y3,QLabel * y4,QLabel * y5,
                        QLabel * d1,QLabel * d2,QLabel * d3,QLabel * d4,QLabel * d5);

    double extract_ypscore(QString name);
    int extrace_watchedcnt(QString name);


signals:
    void showLogin();
    void showHomepage();
    void showMoviesCollection();
    void showMovieDetail();

private slots:
    void on_returnButton_clicked();
    void on_homepageButton_clicked();
    void receiveLoginInput();
    void receiveHomepage();
    void receiveMoviesCollection();
    void receiveVisitorLogin();
    void receiveMovieDetail();
    void on_moviesCollectionButton_clicked();

    void on_detailButton_r1_clicked();
    void on_detailButton_r2_clicked();
    void on_detailButton_r3_clicked();
    void on_detailButton_f1_clicked();
    void on_detailButton_f2_clicked();
    void on_detailButton_f3_clicked();

private:
    Ui::MyPublicSpace *ui;
};

#endif // MYPUBLICSPACE_H
