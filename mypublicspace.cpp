#include "global.h"
#include "mypublicspace.h"
#include "ui_mypublicspace.h"
#include "QSqlDatabase"
#include "QSqlQuery"
#include "QSqlError"
#include "QDebug"
#include "mymoviedetail.h"
#include "QMessageBox"

MyPublicSpace::MyPublicSpace(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyPublicSpace)
{
    ui->setupUi(this);
    ui->frame_publicspace->setStyleSheet("#frame_publicspace{border-image: url(:/background/ypuclogo.jpg);}");
    ui->frame_recentmovie1->setStyleSheet("#frame_recentmovie1{background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0.2 rgba(250, 255, 255, 200), stop:1 rgba(255, 255, 255, 0));border-bottom-left-radius:25px;}");
    ui->frame_recentmovie2->setStyleSheet("#frame_recentmovie2{background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0.2 rgba(250, 255, 255, 200), stop:1 rgba(255, 255, 255, 0));border-bottom-left-radius:25px;}");
    ui->frame_recentmovie3->setStyleSheet("#frame_recentmovie3{background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0.2 rgba(250, 255, 255, 200), stop:1 rgba(255, 255, 255, 0));border-bottom-left-radius:25px;}");
    ui->frame_futuremovie1->setStyleSheet("#frame_futuremovie1{background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0.2 rgba(250, 255, 255, 200), stop:1 rgba(255, 255, 255, 0));border-bottom-left-radius:25px;}");
    ui->frame_futuremovie2->setStyleSheet("#frame_futuremovie2{background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0.2 rgba(250, 255, 255, 200), stop:1 rgba(255, 255, 255, 0));border-bottom-left-radius:25px;}");
    ui->frame_futuremovie3->setStyleSheet("#frame_futuremovie3{background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0.2 rgba(250, 255, 255, 200), stop:1 rgba(255, 255, 255, 0));border-bottom-left-radius:25px;}");



}
MyPublicSpace::~MyPublicSpace()
{
    delete ui;
}

void MyPublicSpace::on_returnButton_clicked()
{
    this->hide();
    ui->publicSpaceButton->show();
    ui->homepageButton->show();
    ui->detailButton_r1->show();ui->detailButton_r2->show();ui->detailButton_r3->show();
    ui->detailButton_f1->show();ui->detailButton_f2->show();ui->detailButton_f3->show();
    emit showLogin();
}

void MyPublicSpace::on_homepageButton_clicked()
{
    this->hide();
    emit showHomepage();
}

void MyPublicSpace::receiveLoginInput()
{
    movies_displayed.clear();
    movies_to_display.clear();
    all_movies.clear();
    //每次点击登录（即将要跳转到公共空间时），都将数据库中的信息存入全局电影QVector中，以便后续访问
    QSqlDatabase dbnow;
    if(QSqlDatabase::contains("db_movies")) dbnow = QSqlDatabase::database("db_movies");
    if (!dbnow.open()) qDebug() << "Error: Failed to connect database." << db_movies.lastError();
    QSqlQuery query_movies(dbnow);
    QString select = "select * from movie";
    if(!query_movies.exec(select)) qDebug()<<query_movies.lastError();
    else
    {
        while(query_movies.next())
        {
            QString poster_ = query_movies.value(0).toString();
            QString moviename_ = query_movies.value(1).toString();
            QString year_ = query_movies.value(2).toString();
            QString director_ = query_movies.value(3).toString();
            QString region_ = query_movies.value(4).toString();
            QString introduction_ = query_movies.value(5).toString();
            double db_score_ = query_movies.value(6).toDouble();
            double ypuc_score_ = query_movies.value(7).toDouble();
            int watched_cnt_ = query_movies.value(8).toInt();
            int watched_ = query_movies.value(9).toInt();
            if(watched_ == 0)
            {
                movies_to_display.append(Qmovie(poster_,moviename_,year_,director_,region_,introduction_,db_score_,ypuc_score_,watched_cnt_,watched_));
            }
            else if(watched_ == 1)
            {
                movies_displayed.append(Qmovie(poster_,moviename_,year_,director_,region_,introduction_,db_score_,ypuc_score_,watched_cnt_,watched_));
            }
        }
    }
    for(auto i = movies_displayed.begin();i!=movies_displayed.end();i++)
    {
        Qmovie now(*i);
        all_movies.append(now);
    }
    for(auto i = movies_to_display.begin();i!=movies_to_display.end();i++)
    {
        Qmovie now(*i);
        all_movies.append(now);
    }

    //在界面上显示电影信息
    //qDebug()<<movies_displayed.size();
    //qDebug()<<movies_to_display.size();
    QVector<Qmovie>::const_iterator i1 = movies_displayed.end();
    QVector<Qmovie>::const_iterator i2 = movies_to_display.begin();
    //1.最近播映，movies_displayed的倒数三部
    int times = movies_displayed.size();
    if(times >= 1)
    {
        i1--;
        setMovieBanner(ui->posterLabel_r1, i1->poster, ui->nameLabel_r1, i1->moviename, ui->yearLabel_r1,
                       i1->year, ui->directorLabel_r1, i1->director, ui->regionLabel_r1, i1->region,
                       ui->ypucLabel_r1, i1->ypuc_score, ui->dbLabel_r1, i1->db_score,
                       ui->label_r1_y1,ui->label_r1_y2,ui->label_r1_y3,ui->label_r1_y4,ui->label_r1_y5,
                       ui->label_r1_d1,ui->label_r1_d2,ui->label_r1_d3,ui->label_r1_d4,ui->label_r1_d5);
        times--;
    }
    if(times >= 1)
    {
        i1--;
        setMovieBanner(ui->posterLabel_r2, i1->poster, ui->nameLabel_r2, i1->moviename, ui->yearLabel_r2,
                       i1->year, ui->directorLabel_r2, i1->director, ui->regionLabel_r2, i1->region,
                       ui->ypucLabel_r2, i1->ypuc_score, ui->dbLabel_r2, i1->db_score,
                       ui->label_r2_y1,ui->label_r2_y2,ui->label_r2_y3,ui->label_r2_y4,ui->label_r2_y5,
                       ui->label_r2_d1,ui->label_r2_d2,ui->label_r2_d3,ui->label_r2_d4,ui->label_r2_d5);
        times--;
    }
    if(times >= 1)
    {
        i1--;
        setMovieBanner(ui->posterLabel_r3, i1->poster, ui->nameLabel_r3, i1->moviename, ui->yearLabel_r3,
                       i1->year, ui->directorLabel_r3, i1->director, ui->regionLabel_r3, i1->region,
                       ui->ypucLabel_r3, i1->ypuc_score, ui->dbLabel_r3, i1->db_score,
                       ui->label_r3_y1,ui->label_r3_y2,ui->label_r3_y3,ui->label_r3_y4,ui->label_r3_y5,
                       ui->label_r3_d1,ui->label_r3_d2,ui->label_r3_d3,ui->label_r3_d4,ui->label_r3_d5);
        times--;
    }


    //2.即将播映，movies_display的正数三部
    if(i2 != movies_to_display.end())
        setMovieBanner(ui->posterLabel_f1, i2->poster, ui->nameLabel_f1, i2->moviename, ui->yearLabel_f1,
                       i2->year, ui->directorLabel_f1, i2->director, ui->regionLabel_f1, i2->region,
                       ui->ypucLabel_f1, i2->ypuc_score, ui->dbLabel_f1, i2->db_score,
                       ui->label_f1_y1,ui->label_f1_y2,ui->label_f1_y3,ui->label_f1_y4,ui->label_f1_y5,
                       ui->label_f1_d1,ui->label_f1_d2,ui->label_f1_d3,ui->label_f1_d4,ui->label_f1_d5);
    if(i2 != movies_to_display.end()) i2++;
    if(i2 != movies_to_display.end())
        setMovieBanner(ui->posterLabel_f2, i2->poster, ui->nameLabel_f2, i2->moviename, ui->yearLabel_f2,
                       i2->year, ui->directorLabel_f2, i2->director, ui->regionLabel_f2, i2->region,
                       ui->ypucLabel_f2, i2->ypuc_score, ui->dbLabel_f2, i2->db_score,
                       ui->label_f2_y1,ui->label_f2_y2,ui->label_f2_y3,ui->label_f2_y4,ui->label_f2_y5,
                       ui->label_f2_d1,ui->label_f2_d2,ui->label_f2_d3,ui->label_f2_d4,ui->label_f2_d5);
    if(i2 != movies_to_display.end()) i2++;
    if(i2 != movies_to_display.end())
        setMovieBanner(ui->posterLabel_f3, i2->poster, ui->nameLabel_f3, i2->moviename, ui->yearLabel_f3,
                       i2->year, ui->directorLabel_f3, i2->director, ui->regionLabel_f3, i2->region,
                       ui->ypucLabel_f3, i2->ypuc_score, ui->dbLabel_f3, i2->db_score,
                       ui->label_f3_y1,ui->label_f3_y2,ui->label_f3_y3,ui->label_f3_y4,ui->label_f3_y5,
                       ui->label_f3_d1,ui->label_f3_d2,ui->label_f3_d3,ui->label_f3_d4,ui->label_f3_d5);

    this->show();
}
void MyPublicSpace::receiveHomepage()
{
    this->show();
}
void MyPublicSpace::receiveMovieDetail()
{
    QString nowmovie = currMovie->moviename;
    double nowyp_score = currMovie->ypuc_score;
    int nowwatched_cnt = currMovie->watched_cnt;
    //qDebug()<<nowyp_score<<' '<<nowwatched_cnt<<' '<<nowmovie<<" onpublicreceivedetail";
    if(nowyp_score > 0 || (nowyp_score == 0 && nowwatched_cnt > 0))
    {
        int ypval = ((int)(nowyp_score/0.5)+1)/2;
        int whichstar_yp[5]={0,0,0,0,0};
        for(int i=0;i<ypval/2;i++) whichstar_yp[i] = 2;
        if(ypval%2 != 0) whichstar_yp[ypval/2] = 1;
        QString setStar[3] = {"border-image: url(:/star/zeroStar.png);",
                              "border-image: url(:/star/halfStar.png);",
                              "border-image: url(:/star/fullStar.png);"};
        if(nowmovie == ui->nameLabel_r1->text()){
            ui->ypucLabel_r1->setText("地院评分："+QString::number(nowyp_score,'f',1));
            ui->label_r1_y1->setStyleSheet(setStar[whichstar_yp[0]]); ui->label_r1_y2->setStyleSheet(setStar[whichstar_yp[1]]); ui->label_r1_y3->setStyleSheet(setStar[whichstar_yp[2]]); ui->label_r1_y4->setStyleSheet(setStar[whichstar_yp[3]]); ui->label_r1_y5->setStyleSheet(setStar[whichstar_yp[4]]);
        }
        else if(nowmovie == ui->nameLabel_r2->text()) {
            ui->ypucLabel_r2->setText("地院评分："+QString::number(nowyp_score,'f',1));
            ui->label_r2_y1->setStyleSheet(setStar[whichstar_yp[0]]); ui->label_r2_y2->setStyleSheet(setStar[whichstar_yp[1]]); ui->label_r2_y3->setStyleSheet(setStar[whichstar_yp[2]]); ui->label_r2_y4->setStyleSheet(setStar[whichstar_yp[3]]); ui->label_r2_y5->setStyleSheet(setStar[whichstar_yp[4]]);
        }
        else if(nowmovie == ui->nameLabel_r3->text()) {
            ui->ypucLabel_r3->setText("地院评分："+QString::number(nowyp_score,'f',1));
            ui->label_r3_y1->setStyleSheet(setStar[whichstar_yp[0]]); ui->label_r3_y2->setStyleSheet(setStar[whichstar_yp[1]]); ui->label_r3_y3->setStyleSheet(setStar[whichstar_yp[2]]); ui->label_r3_y4->setStyleSheet(setStar[whichstar_yp[3]]); ui->label_r3_y5->setStyleSheet(setStar[whichstar_yp[4]]);
        }
        else if(nowmovie == ui->nameLabel_f1->text()) {
            ui->ypucLabel_f1->setText("地院评分："+QString::number(nowyp_score,'f',1));
            ui->label_f1_y1->setStyleSheet(setStar[whichstar_yp[0]]); ui->label_f1_y2->setStyleSheet(setStar[whichstar_yp[1]]); ui->label_f1_y3->setStyleSheet(setStar[whichstar_yp[2]]); ui->label_f1_y4->setStyleSheet(setStar[whichstar_yp[3]]); ui->label_f1_y5->setStyleSheet(setStar[whichstar_yp[4]]);
        }
        else if(nowmovie == ui->nameLabel_f2->text()) {
            ui->ypucLabel_f2->setText("地院评分："+QString::number(nowyp_score,'f',1));
            ui->label_f2_y1->setStyleSheet(setStar[whichstar_yp[0]]); ui->label_f2_y2->setStyleSheet(setStar[whichstar_yp[1]]); ui->label_f2_y3->setStyleSheet(setStar[whichstar_yp[2]]); ui->label_f2_y4->setStyleSheet(setStar[whichstar_yp[3]]); ui->label_f2_y5->setStyleSheet(setStar[whichstar_yp[4]]);
        }
            else if(nowmovie == ui->nameLabel_f3->text()) {
            ui->ypucLabel_f3->setText("地院评分："+QString::number(nowyp_score,'f',1));
            ui->label_f3_y1->setStyleSheet(setStar[whichstar_yp[0]]); ui->label_f3_y2->setStyleSheet(setStar[whichstar_yp[1]]); ui->label_f3_y3->setStyleSheet(setStar[whichstar_yp[2]]); ui->label_f3_y4->setStyleSheet(setStar[whichstar_yp[3]]); ui->label_f3_y5->setStyleSheet(setStar[whichstar_yp[4]]);
        }
    }
    this->show();
}
void MyPublicSpace::receiveMoviesCollection()//后续可能有不同用处，所以分开槽函数写
{
    this->show();
}

void MyPublicSpace::receiveVisitorLogin()
{
    ui->publicSpaceButton->hide();
    ui->homepageButton->hide();
    ui->detailButton_r1->hide();ui->detailButton_r2->hide();ui->detailButton_r3->hide();
    ui->detailButton_f1->hide();ui->detailButton_f2->hide();ui->detailButton_f3->hide();

    movies_displayed.clear();
    movies_to_display.clear();
    all_movies.clear();
    //每次点击登录（即将要跳转到公共空间时），都将数据库中的信息存入全局电影QVector中，以便后续访问
    QSqlDatabase dbnow;
    if(QSqlDatabase::contains("db_movies")) dbnow = QSqlDatabase::database("db_movies");
    if (!dbnow.open()) qDebug() << "Error: Failed to connect database." << db_movies.lastError();
    QSqlQuery query_movies(dbnow);
    QString select = "select * from movie";
    if(!query_movies.exec(select)) qDebug()<<query_movies.lastError();
    else
    {
        while(query_movies.next())
        {
            QString poster_ = query_movies.value(0).toString();
            QString moviename_ = query_movies.value(1).toString();
            QString year_ = query_movies.value(2).toString();
            QString director_ = query_movies.value(3).toString();
            QString region_ = query_movies.value(4).toString();
            QString introduction_ = query_movies.value(5).toString();
            double db_score_ = query_movies.value(6).toDouble();
            double ypuc_score_ = query_movies.value(7).toDouble();
            int watched_cnt_ = query_movies.value(8).toInt();
            int watched_ = query_movies.value(9).toInt();
            if(watched_ == 0)
            {
                movies_to_display.append(Qmovie(poster_,moviename_,year_,director_,region_,introduction_,db_score_,ypuc_score_,watched_cnt_,watched_));
            }
            else if(watched_ == 1)
            {
                movies_displayed.append(Qmovie(poster_,moviename_,year_,director_,region_,introduction_,db_score_,ypuc_score_,watched_cnt_,watched_));
            }
        }
    }
    for(auto i = movies_displayed.begin();i!=movies_displayed.end();i++)
    {
        Qmovie now(*i);
        all_movies.append(now);
    }
    for(auto i = movies_to_display.begin();i!=movies_to_display.end();i++)
    {
        Qmovie now(*i);
        all_movies.append(now);
    }

    //在界面上显示电影信息,
    QVector<Qmovie>::const_iterator i1 = movies_displayed.end();
    QVector<Qmovie>::const_iterator i2 = movies_to_display.begin();
    //1.最近播映，movies_displayed的倒数三部
    int times = movies_displayed.size();
    if(times >= 1)
    {
        i1--;
        setMovieBanner(ui->posterLabel_r1, i1->poster, ui->nameLabel_r1, i1->moviename, ui->yearLabel_r1,
                       i1->year, ui->directorLabel_r1, i1->director, ui->regionLabel_r1, i1->region,
                       ui->ypucLabel_r1, i1->ypuc_score, ui->dbLabel_r1, i1->db_score,
                       ui->label_r1_y1,ui->label_r1_y2,ui->label_r1_y3,ui->label_r1_y4,ui->label_r1_y5,
                       ui->label_r1_d1,ui->label_r1_d2,ui->label_r1_d3,ui->label_r1_d4,ui->label_r1_d5);
        times--;
    }
    if(times >= 1)
    {
        i1--;
        setMovieBanner(ui->posterLabel_r2, i1->poster, ui->nameLabel_r2, i1->moviename, ui->yearLabel_r2,
                       i1->year, ui->directorLabel_r2, i1->director, ui->regionLabel_r2, i1->region,
                       ui->ypucLabel_r2, i1->ypuc_score, ui->dbLabel_r2, i1->db_score,
                       ui->label_r2_y1,ui->label_r2_y2,ui->label_r2_y3,ui->label_r2_y4,ui->label_r2_y5,
                       ui->label_r2_d1,ui->label_r2_d2,ui->label_r2_d3,ui->label_r2_d4,ui->label_r2_d5);
        times--;
    }
    if(times >= 1)
    {
        i1--;
        setMovieBanner(ui->posterLabel_r3, i1->poster, ui->nameLabel_r3, i1->moviename, ui->yearLabel_r3,
                       i1->year, ui->directorLabel_r3, i1->director, ui->regionLabel_r3, i1->region,
                       ui->ypucLabel_r3, i1->ypuc_score, ui->dbLabel_r3, i1->db_score,
                       ui->label_r3_y1,ui->label_r3_y2,ui->label_r3_y3,ui->label_r3_y4,ui->label_r3_y5,
                       ui->label_r3_d1,ui->label_r3_d2,ui->label_r3_d3,ui->label_r3_d4,ui->label_r3_d5);
        times--;
    }
    //2.即将播映，movies_display的正数三部
    if(i2 != movies_to_display.end())
        setMovieBanner(ui->posterLabel_f1, i2->poster, ui->nameLabel_f1, i2->moviename, ui->yearLabel_f1,
                       i2->year, ui->directorLabel_f1, i2->director, ui->regionLabel_f1, i2->region,
                       ui->ypucLabel_f1, i2->ypuc_score, ui->dbLabel_f1, i2->db_score,
                       ui->label_f1_y1,ui->label_f1_y2,ui->label_f1_y3,ui->label_f1_y4,ui->label_f1_y5,
                       ui->label_f1_d1,ui->label_f1_d2,ui->label_f1_d3,ui->label_f1_d4,ui->label_f1_d5);
    if(i2 != movies_to_display.end()) i2++;
    if(i2 != movies_to_display.end())
        setMovieBanner(ui->posterLabel_f2, i2->poster, ui->nameLabel_f2, i2->moviename, ui->yearLabel_f2,
                       i2->year, ui->directorLabel_f2, i2->director, ui->regionLabel_f2, i2->region,
                       ui->ypucLabel_f2, i2->ypuc_score, ui->dbLabel_f2, i2->db_score,
                       ui->label_f2_y1,ui->label_f2_y2,ui->label_f2_y3,ui->label_f2_y4,ui->label_f2_y5,
                       ui->label_f2_d1,ui->label_f2_d2,ui->label_f2_d3,ui->label_f2_d4,ui->label_f2_d5);
    if(i2 != movies_to_display.end()) i2++;
    if(i2 != movies_to_display.end())
        setMovieBanner(ui->posterLabel_f3, i2->poster, ui->nameLabel_f3, i2->moviename, ui->yearLabel_f3,
                       i2->year, ui->directorLabel_f3, i2->director, ui->regionLabel_f3, i2->region,
                       ui->ypucLabel_f3, i2->ypuc_score, ui->dbLabel_f3, i2->db_score,
                       ui->label_f3_y1,ui->label_f3_y2,ui->label_f3_y3,ui->label_f3_y4,ui->label_f3_y5,
                       ui->label_f3_d1,ui->label_f3_d2,ui->label_f3_d3,ui->label_f3_d4,ui->label_f3_d5);


    this->show();
}

void MyPublicSpace::on_moviesCollectionButton_clicked()
{
    this->hide();
    emit showMoviesCollection();
}

void MyPublicSpace::setMovieBanner(QLabel * poster_, QString posterStr, QLabel * moviename_, QString movienameStr,
                    QLabel * year_, QString yearStr, QLabel * director_, QString directorStr,
                    QLabel * region_ , QString regionStr, QLabel * ypuclabel_,double ypuc_val,
                    QLabel * dblabel_,double db_val, QLabel * y1,QLabel * y2,QLabel * y3,QLabel * y4,QLabel * y5,
                    QLabel * d1,QLabel * d2,QLabel * d3,QLabel * d4,QLabel * d5)
{
    //qDebug()<<posterStr;
    poster_->setStyleSheet("border-image: url(:" + posterStr + ");");
    moviename_->setText(movienameStr); //moviename_->setFont("font: 10pt '楷体';");
    year_->setText(yearStr); //year_->setFont("font: 10pt '楷体';");
    director_->setText(directorStr); //director_->setFont("font: 10pt '楷体';");
    region_->setText(regionStr); //region_->setFont("font: 10pt '楷体';");
    if(ypuc_val != 0) ypuclabel_->setText("地院评分：" + QString::number(ypuc_val,'f',1));
    else ypuclabel_->setText("地院评分：未评分");
    //ypuclabel_->setFont("font: 10pt '楷体';");
    dblabel_->setText("豆瓣评分：" + QString::number(db_val,'f',1));
    //dblabel_->setFont("font: 10pt '楷体';");

    int ypval = ((int)(ypuc_val/0.5)+1)/2;
    int whichstar_yp[5]={0,0,0,0,0};
    for(int i=0;i<ypval/2;i++) whichstar_yp[i] = 2;
    if(ypval%2 != 0) whichstar_yp[ypval/2] = 1;
    int dbval = ((int)(db_val/0.5)+1)/2;
    int whichstar_db[5]={0,0,0,0,0};
    for(int i=0;i<dbval/2;i++) whichstar_db[i] = 2;
    if(dbval%2 != 0) whichstar_db[dbval/2] = 1;
    QString setStar[3] = {"border-image: url(:/star/zeroStar.png);",
                          "border-image: url(:/star/halfStar.png);",
                          "border-image: url(:/star/fullStar.png);"};
    y1->setStyleSheet(setStar[whichstar_yp[0]]); y2->setStyleSheet(setStar[whichstar_yp[1]]);
    y3->setStyleSheet(setStar[whichstar_yp[2]]); y4->setStyleSheet(setStar[whichstar_yp[3]]);
    y5->setStyleSheet(setStar[whichstar_yp[4]]);
    d1->setStyleSheet(setStar[whichstar_db[0]]); d2->setStyleSheet(setStar[whichstar_db[1]]);
    d3->setStyleSheet(setStar[whichstar_db[2]]); d4->setStyleSheet(setStar[whichstar_db[3]]);
    d5->setStyleSheet(setStar[whichstar_db[4]]);

}


void MyPublicSpace::on_detailButton_r1_clicked()
{
     QVector<Qmovie>::const_iterator i1 = movies_displayed.end();i1--;
     if(i1 != movies_displayed.cend())
     {
         currMovie = new Qmovie(*i1);
         currMovie->ypuc_score = extract_ypscore(currMovie->moviename);
         currMovie->watched_cnt = extrace_watchedcnt(currMovie->moviename);
         this->hide();
         emit showMovieDetail();
     }
}


void MyPublicSpace::on_detailButton_r2_clicked()
{
     QVector<Qmovie>::const_iterator i1 = movies_displayed.end();i1--;
     if(i1 != movies_displayed.cend()) i1--;
     if(i1 != movies_displayed.cend())
     {
         currMovie = new Qmovie(*i1);
         currMovie->ypuc_score = extract_ypscore(currMovie->moviename);
         currMovie->watched_cnt = extrace_watchedcnt(currMovie->moviename);
         this->hide();
         emit showMovieDetail();
     }
}

void MyPublicSpace::on_detailButton_r3_clicked()
{
    QVector<Qmovie>::const_iterator i1 = movies_displayed.end();i1--;
    if(i1 != movies_displayed.cend()) i1--;
    if(i1 != movies_displayed.cend()) i1--;
    if(i1 != movies_displayed.cend())
    {
        currMovie = new Qmovie(*i1);
        currMovie->ypuc_score = extract_ypscore(currMovie->moviename);
        currMovie->watched_cnt = extrace_watchedcnt(currMovie->moviename);
        this->hide();
        emit showMovieDetail();
    }
}

void MyPublicSpace::on_detailButton_f1_clicked()
{
    QVector<Qmovie>::const_iterator i2 = movies_to_display.begin();
    if(i2 != movies_to_display.end())
    {
        currMovie = new Qmovie(*i2);
        currMovie->ypuc_score = extract_ypscore(currMovie->moviename);
        currMovie->watched_cnt = extrace_watchedcnt(currMovie->moviename);
        this->hide();
        emit showMovieDetail();
    }
}

void MyPublicSpace::on_detailButton_f2_clicked()
{
    QVector<Qmovie>::const_iterator i2 = movies_to_display.begin();
    if(i2 != movies_to_display.end()) i2++;
    if(i2 != movies_to_display.end())
    {
        currMovie = new Qmovie(*i2);
        currMovie->ypuc_score = extract_ypscore(currMovie->moviename);
        currMovie->watched_cnt = extrace_watchedcnt(currMovie->moviename);
        this->hide();
        emit showMovieDetail();
    }
}

void MyPublicSpace::on_detailButton_f3_clicked()
{
    QVector<Qmovie>::const_iterator i2 = movies_to_display.begin();
    if(i2 != movies_to_display.end()) i2++;
    if(i2 != movies_to_display.end()) i2++;
    if(i2 != movies_to_display.end())
    {
        currMovie = new Qmovie(*i2);
        currMovie->ypuc_score = extract_ypscore(currMovie->moviename);
        currMovie->watched_cnt = extrace_watchedcnt(currMovie->moviename);
        this->hide();
        emit showMovieDetail();
    }
}

double MyPublicSpace::extract_ypscore(QString name)
{
    QSqlDatabase dbnow;
    if(QSqlDatabase::contains("db_movies")) dbnow = QSqlDatabase::database("db_movies");
    if (!dbnow.open()) qDebug() << "Error: Failed to connect database." << db_movies.lastError();
    QSqlQuery query_movies(dbnow);
    QString select = QString("select ypuc_score from movie where moviename = '%1'").arg(name);
    double nowscore = 0;
    if(!query_movies.exec(select)) qDebug()<<query_movies.lastError();
    else
    {
        while(query_movies.next())
        {
            nowscore = query_movies.value(0).toDouble();
        }
    }
    return nowscore;
}

int  MyPublicSpace::extrace_watchedcnt(QString name)
{
    QSqlDatabase dbnow;
    if(QSqlDatabase::contains("db_movies")) dbnow = QSqlDatabase::database("db_movies");
    if (!dbnow.open()) qDebug() << "Error: Failed to connect database." << db_movies.lastError();
    QSqlQuery query_movies(dbnow);
    QString select = QString("select watched_cnt from movie where moviename = '%1'").arg(name);
    int nowcnt = 0;
    if(!query_movies.exec(select)) qDebug()<<query_movies.lastError();
    else
    {
        while(query_movies.next())
        {
            nowcnt = query_movies.value(0).toInt();
        }
    }
    return nowcnt;
}
