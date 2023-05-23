#include "global.h"
#include "mymoviedetail.h"
#include "ui_mymoviedetail.h"
#include "QInputDialog"
#include "QSqlError"
#include "QDebug"

MyMovieDetail::MyMovieDetail(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyMovieDetail)
{
    ui->setupUi(this);
    ui->frame_moviedetail->setStyleSheet("#frame_moviedetail{border-image: url(:/background/ypuclogo.jpg);}");
    const QString round_SheetStyle = "min-width: 28px; min-height: 28px;max-width:28px; max-height: 30px;border-radius: 14px; border:1px solid pink;background:pink;font-size:17px ";
    ui->commentButton->setStyleSheet(round_SheetStyle);

    /*QSqlDatabase dbnow;
    if(QSqlDatabase::contains("db_movies")) dbnow = QSqlDatabase::database("db_movies");
    if (!dbnow.open()) qDebug() << "Error: Failed to connect database." << db_movies.lastError();
    QSqlQuery query_movies(dbnow);
    query_movies.prepare("update movie set ypuc_score = :ypuc_score ,watched_cnt = :watched_cnt where moviename = :moviename");
    query_movies.bindValue(":ypuc_score",0);
    query_movies.bindValue(":watched_cnt",0);
    query_movies.bindValue(":moviename","妈的多重宇宙");
    if(!query_movies.exec()) qDebug()<<query_movies.lastError();
    else{
        qDebug()<<"yesssss!!";
    }*/

}



MyMovieDetail::~MyMovieDetail()
{
    delete ui;
}

void MyMovieDetail::on_returnButton_clicked()
{
    this->hide();
    emit showPublicSpace();
}

void MyMovieDetail::receivePublicSpace()
{
    QString posterStr = currMovie->poster;
    QString movienameStr = currMovie->moviename;
    QString yearStr = currMovie->year;
    QString directorStr = currMovie->director;
    QString regionStr = currMovie->region;
    QString introductionStr = currMovie->introduction;
    double db_score_ = currMovie->db_score;
    QString db_scoreStr = QString::number(db_score_,'f',1);
    double ypuc_score_ = currMovie->ypuc_score;
    QString ypuc_scoreStr;
    if(ypuc_score_ > 0 || currMovie->watched_cnt > 0){
        //qDebug()<<ypuc_score_<<' '<<currMovie->watched_cnt<<' '<<currMovie->moviename;
        ypuc_scoreStr = QString::number(ypuc_score_,'f',1);
    }
    else ypuc_scoreStr = "未评";
    ui->posterLabel->setStyleSheet("border-image: url(:" + posterStr + ");");
    ui->nameLabel->setText(movienameStr);
    ui->yearLabel->setText(yearStr);
    ui->directorLabel->setText(directorStr);
    ui->regionLabel->setText(regionStr);
    ui->introTextBrowser->setText(introductionStr);
    ui->dbScoreLabel->setText(db_scoreStr);
    ui->ypucScoreLabel->setText(ypuc_scoreStr);
    this->show();
}

void MyMovieDetail::on_commentButton_clicked()
{
    bool bOk;
    int comment_val = QInputDialog::getInt(this,tr("评分!"),tr("请输入您的评分（十分制整数）"),-1,0,10,1,&bOk,Qt::Dialog | Qt::WindowCloseButtonHint );
    if(comment_val >= 0 && comment_val<=10) {
        QSqlDatabase dbnow;
        if(QSqlDatabase::contains("db_movies")) dbnow = QSqlDatabase::database("db_movies");
        if (!dbnow.open()) qDebug() << "Error: Failed to connect database." << db_movies.lastError();
        QSqlQuery query_movies(dbnow);


        query_movies.prepare("update movie set ypuc_score = :ypuc_score ,watched_cnt = :watched_cnt where moviename = :moviename");
        query_movies.bindValue(":ypuc_score",(currMovie->ypuc_score * currMovie->watched_cnt + comment_val)/(currMovie->watched_cnt+1));
        query_movies.bindValue(":watched_cnt",currMovie->watched_cnt+1);
        query_movies.bindValue(":moviename",currMovie->moviename);
        if(!query_movies.exec()) qDebug()<<query_movies.lastError();
        else
        {
            qDebug()<<"score updated!";
            currMovie->ypuc_score = (currMovie->ypuc_score * currMovie->watched_cnt  + comment_val)/(double)(currMovie->watched_cnt+1);
            currMovie->watched_cnt = currMovie->watched_cnt + 1;
            ui->ypucScoreLabel->setText(QString::number(currMovie->ypuc_score,'f',1));
            //qDebug()<<currMovie->ypuc_score<<' '<<currMovie->watched_cnt<<' '<<currMovie->moviename<<" 123";
        }
    }

}
