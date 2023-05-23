#include "global.h"
#include "mylogininput.h"
#include "ui_mylogininput.h"
#include "QDebug"
#include "QMessageBox"
#include "QVector"
#include "QtSql/QSqlDatabase"
#include "QtSql/QSqlQuery"
#include "QSqlError"

MyLoginInput::MyLoginInput(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyLoginInput)
{
    ui->setupUi(this);
    ui->frame_logininput->setStyleSheet("#frame_logininput{border-image: url(:/background/logininputbackground.jpg);}");

}



MyLoginInput::~MyLoginInput()
{
    delete ui;
}

void MyLoginInput::on_returnButton_clicked()
{
    this->hide();
    emit showLogin();
}

void MyLoginInput::on_loginButton_clicked()
{
    bool permission = false;
    QString accountstr = ui->accountLineEdit->text();
    QString passwordstr = ui->passwordLineEdit->text();
    if(accountstr == "" || passwordstr == "")
        QMessageBox::about(this,tr("啊哦！出现问题了！"), tr("你的输入不正确，再试一次吧！"));
    else
    {
        QSqlDatabase dbnow;
        if(QSqlDatabase::contains("db_users")) dbnow = QSqlDatabase::database("db_users");
        if (!dbnow.open()) qDebug() << "Error: Failed to connect database." << db_users.lastError();
        QSqlQuery query_users(dbnow);
        QString select_sql = "select account, password from user";
        if(!query_users.exec(select_sql)) qDebug()<<query_users.lastError();
        else
        {
            while(query_users.next())
            {
                QString ac = query_users.value(0).toString();
                QString pa = query_users.value(1).toString();
                if(ac == accountstr && pa == passwordstr)
                {
                    permission = true;
                    break;
                }
            }
        }
        if(permission)
        {
            if(!currUser){
                currUser = new Quser(accountstr,passwordstr);
            }
            else if(currUser->account != accountstr){
                delete currUser;
                currUser = NULL;
                currUser = new Quser(accountstr,passwordstr);
            }
            else if(currUser->account == accountstr){}
            this->hide();
            emit showPublicSpace();
        }
        else
            QMessageBox::information(this,tr("啊哦！出现问题了！"), tr("没有检索到对应的用户名密码组合，请您再试一次！"));
    }
}

void MyLoginInput::on_registerButton_clicked()
{
    QString accountstr = ui->accountLineEdit->text();
    QString passwordstr = ui->passwordLineEdit->text();
    if(accountstr == "" || passwordstr == "")
        QMessageBox::about(this,tr("啊哦！出现问题了！"), tr("你的输入不完整，再试一次吧！"));
    else
    {
        QSqlDatabase dbnow;
        if(QSqlDatabase::contains("db_users")) dbnow = QSqlDatabase::database("db_users");
        if (!dbnow.open()) qDebug() << "Error: Failed to connect database." << db_users.lastError();
        QSqlQuery query_users(dbnow);

        QString insert_description = "insert into user values (?,?,?,?,?,?,?,?,?)";
        query_users.prepare(insert_description);
        query_users.addBindValue(accountstr);
        query_users.addBindValue(passwordstr);
        query_users.addBindValue("未填写");
        query_users.addBindValue("未填写");
        query_users.addBindValue("未填写");
        query_users.addBindValue("未填写");
        query_users.addBindValue("2000/01/01");
        query_users.addBindValue("||||||||||");
        query_users.addBindValue("|||||");
        //for(int i=1;i<=7;i++) query_users.addBindValue("");
        if(!query_users.exec())
            qDebug()<<query_users.lastError();
        else
            qDebug()<<"inserted!";


        /*QString select_sql = "select account, password from user";
        if(!query_users.exec(select_sql))
        {
            qDebug()<<query_users.lastError();
        }
        else
        {
            while(query_users.next())
            {
                QString ac = query_users.value(0).toString();
                QString pa = query_users.value(1).toString();
                qDebug()<<QString("ac:%1  pa:%2").arg(ac).arg(pa);
            }
        }*/
        /*QString clear_sql = "delete from user";
        query_users.prepare(clear_sql);
        if(!query_users.exec())
        {
            qDebug() << query_users.lastError();
        }
        else
        {
            qDebug() << "table cleared";
        }*/


        this->hide();
        emit showLogin();
    }
}
void MyLoginInput::receiveLogin()
{
    ui->registerButton->show();
    this->show();
}
void MyLoginInput::receiveLogin_noregister()
{
    ui->registerButton->hide();
    this->show();
}
