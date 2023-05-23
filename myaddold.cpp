#include "myaddold.h"
#include "ui_myaddold.h"
#include "global.h"
#include "QDialog"
#include "QSqlDatabase"
#include "QSqlError"
#include "QSqlQuery"
#include "QDebug"
#include "QMessageBox"

MyAddOld::MyAddOld(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyAddOld)
{
    ui->setupUi(this);
    ui->background->setStyleSheet("#background{border-image: url(:/background/covertest.jpg);}");
}

MyAddOld::~MyAddOld()
{
    delete ui;
}

void MyAddOld::receiveAdminEdit(){
    this->show();
}

void MyAddOld::on_returnButton_clicked()
{
    this->hide();
    //ui->movieNameInput->hide();
    emit returnAdminEdit();
}


void MyAddOld::on_confirmButton_clicked()
{
    QString input=ui->movieNameInput->text();//获取用户输入的旧电影名字
    QSqlDatabase dbnow;
    if(QSqlDatabase::contains("db_movies")) dbnow = QSqlDatabase::database("db_movies");
    if (!dbnow.open()) qDebug() << "Error: Failed to connect database." << db_movies.lastError();
    QSqlQuery query_movies(dbnow);
    QString select = "select moviename from movie";
    bool exist = false;
    if(!query_movies.exec(select)) qDebug()<<query_movies.lastError();
    else
    {
        while(query_movies.next())
        {
            QString name = query_movies.value(0).toString();
            if(input == name)
            {
                exist = true; break;
            }
        }
    }
    if(exist)
    {
        query_movies.prepare("update movie set watched = :watched where moviename = :moviename");
        query_movies.bindValue(":watched",0);
        query_movies.bindValue(":moviename",input);
        if(!query_movies.exec()) qDebug()<<query_movies.lastError();
        else qDebug()<<"updated! movie:"<<input<<" to future movie!";
        QMessageBox::information(this,tr("管理员提示"), tr("操作成功！"));
    }
    else
        QMessageBox::information(this,tr("管理员提示"), tr("没有检索到对应电影，请再试一次！"));


    this->hide();
    //ui->movieNameInput->hide();
    emit returnAdminEdit();
}

