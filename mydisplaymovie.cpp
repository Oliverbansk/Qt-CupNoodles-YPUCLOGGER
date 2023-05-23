#include "mydisplaymovie.h"
#include "ui_mydisplaymovie.h"
#include "global.h"
#include "QDialog"
#include "QDebug"
#include "QSqlDatabase"
#include "QSqlError"
#include "QSqlQuery"
#include "QMessageBox"

MyDisplayMovie::MyDisplayMovie(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyDisplayMovie)
{
    ui->setupUi(this);
    ui->background->setStyleSheet("#background{border-image: url(:/background/covertest.jpg);}");


    QSqlDatabase dbnow;
    if(QSqlDatabase::contains("db_movies")) dbnow = QSqlDatabase::database("db_movies");
    if (!dbnow.open()) qDebug() << "Error: Failed to connect database." << db_movies.lastError();
    QSqlQuery query_movies(dbnow);
    QString select = "select moviename from movie where watched = 0";
    moviecnt = 0;
    if(!query_movies.exec(select)) qDebug()<<query_movies.lastError();
    else
    {
        while(query_movies.next()) moviecnt++;
    }
    if(moviecnt == 0)
    {
        ui->dynamicLabel->setText("暂无可放电影");
        ui->chooseLabel->setText("点击确定/取消以返回管理员编辑界面");
    }


}

MyDisplayMovie::~MyDisplayMovie()
{
    delete ui;
}

void MyDisplayMovie::receiveAdminEdit(){
    this->show();
}

void MyDisplayMovie::on_returnButton_clicked()
{
    this->hide();
    emit returnAdminEdit();
}


void MyDisplayMovie::on_comfirmButton_clicked()
{
    QString movie_chosen = ui->textEdit_nameInput->document()->toPlainText();
    QSqlDatabase dbnow;
    if(QSqlDatabase::contains("db_movies")) dbnow = QSqlDatabase::database("db_movies");
    if (!dbnow.open()) qDebug() << "Error: Failed to connect database." << db_movies.lastError();
    QSqlQuery query_movies(dbnow);
    QString select = "select moviename from movie where watched = 0";
    bool exist = false;
    if(!query_movies.exec(select)) qDebug()<<query_movies.lastError();
    else
    {
        while(query_movies.next())
        {
            QString name = query_movies.value(0).toString();
            if(movie_chosen == name)
            {
                exist = true; break;
            }
        }
    }
    if(exist)
    {
        query_movies.prepare("update movie set watched = :watched where moviename = :moviename");
        query_movies.bindValue(":watched",1);
        query_movies.bindValue(":moviename",movie_chosen);
        if(!query_movies.exec()) qDebug()<<query_movies.lastError();
        else qDebug()<<"updated! movie:"<<movie_chosen<<" to watched!";
        QMessageBox::information(this,tr("管理员提示"), tr("放映成功！"));
    }
    else
        QMessageBox::information(this,tr("管理员提示"), tr("没有检索到对应的未播映电影，请再试一次！"));


    this->hide();
    emit returnAdminEdit();
}

