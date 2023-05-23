#include "myaddnew.h"
#include "ui_myaddnew.h"
#include "global.h"
#include "QFileDialog"
#include "QDebug"
#include "QMessageBox"
#include "QSqlError"

MyAddNew::MyAddNew(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyAddNew)
{
    ui->setupUi(this);
    posterPathNowChosen = "";
    ui->background->setStyleSheet("#background{border-image: url(:/background/ypuclogo.jpg);}");
    ui->dateEdit->setDateTime(QDateTime::currentDateTime());
    ui->dateEdit->setCalendarPopup(true);
    ui->timeEdit_end->setCalendarPopup(true);
    ui->timeEdit_start->setCalendarPopup(true);
}


MyAddNew::~MyAddNew()
{
    delete ui;
}

void MyAddNew::receiveAdminEdit(){
    this->show();
}

void MyAddNew::on_returnButton_clicked()
{
    this->hide();
    emit returnAdminEdit();
}


void MyAddNew::on_figureChooseButton_clicked()//点击选择图片
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                        tr("管理员您好！如果要加载全新海报！请先添加其至posters资源文件中哦！"),
                                                        "F:",
                                                        tr("图片文件(*png *jpg *jpeg *gif);;"
                                                           "文本文件(*txt)"));
    int start = fileName.indexOf("/posters/");
    QString posterPath = fileName.right(fileName.size()-start); // "/posters/白丝带.jpg"
    ui->label_showposter->setStyleSheet("#label_showposter{border-image: url(:"+ posterPath + ");}");
    posterPathNowChosen = posterPath;
}




void MyAddNew::on_confirmButton_clicked()
{

    QString moviename = ui->nameInput->text();
    QString year = ui->yearInput->text();
    QString director = ui->directorInput->text();
    QString region = ui->regionInput->text();
    QString introduction = ui->introductionInput->document()->toPlainText();
    double dbscore = ui->dbscoreInput->text().toDouble();
    //QString moviedate = ui->dateEdit->date().toString();
    //QString stime = ui->timeEdit_start->time().toString();
    //QString etime = ui->timeEdit_end->time().toString();


    if(posterPathNowChosen == "" || moviename == "" || year == "" || director == "" ||
            region == "" || introduction == "" /*|| moviedate == "" || stime == "" || etime == ""*/){


        QMessageBox::about(this,tr("啊哦！出现问题了！"), tr("你的输入不合规，再试一次吧！"));
    }

    else{
        QSqlDatabase dbnow;
        if(QSqlDatabase::contains("db_movies")) dbnow = QSqlDatabase::database("db_movies");
        if (!dbnow.open()) qDebug() << "Error: Failed to connect database." << db_movies.lastError();
        QSqlQuery query_movies(dbnow);

        QString insert_description = "insert into movie values (?,?,?,?,?,?,?,?,?,?)";
        query_movies.prepare(insert_description);
        query_movies.addBindValue(posterPathNowChosen);query_movies.addBindValue(moviename);
        query_movies.addBindValue(year);query_movies.addBindValue(director);
        query_movies.addBindValue(region);query_movies.addBindValue(introduction);
        query_movies.addBindValue(dbscore);query_movies.addBindValue(0.0);
        query_movies.addBindValue(0);query_movies.addBindValue(0);
        //query_movies.addBindValue(moviedate);
        //query_movies.addBindValue(stime);query_movies.addBindValue(etime);
        if(!query_movies.exec())
            qDebug()<<query_movies.lastError();
        else
            qDebug()<<"inserted!";
    }


    this->hide();
    emit returnAdminEdit();


}
