#include "myadminlogin.h"
#include "ui_myadminlogin.h"
#include "global.h"
#include "QMessageBox"

MyAdminLoginInput::MyAdminLoginInput(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyAdminLoginInput)
{
    ui->setupUi(this);
    ui->frame_admininput->setStyleSheet("#frame_admininput{border-image: url(:/background/logininputbackground.jpg);}");
}

MyAdminLoginInput::~MyAdminLoginInput()
{
    delete ui;
}

void MyAdminLoginInput::receiveLogin(){
    this->show();
}

void MyAdminLoginInput::on_returnButton_clicked()
{
    this->hide();
    emit showLogin();
}


void MyAdminLoginInput::on_pushButton_clicked()
{

    QString nameInput=ui->lineEdit_username->text();
    QString keyInput=ui->lineEdit_code->text();
    if(nameInput == "" || keyInput == "")
        QMessageBox::about(this,tr("啊哦！出现问题了！"), tr("你的输入不完整，再试一次吧！"));
    if(nameInput == "cups" && keyInput == "2100017")
    {
        this->hide();
        emit showAdminEdit();
    }
    else
    {
        QMessageBox::information(this,tr("啊哦！出现问题了！"), tr("输入不正确，请再试一次！"));
    }
    /*
    QString nameInput=ui->lineEdit_username->text();
    QString keyInput=ui->lineEdit_code->text();
    if (nameInput==all_admins.begin()->account&&keyInput==all_admins.begin()->password){

    }
    else{
        ui->error_label->setText("用户名或密码错误，请重新输入");
        QPalette pe;
        pe.setColor(QPalette::WindowText,Qt::red);
        ui->error_label->setPalette(pe);
        ui->error_label->show();

    }
    */
    //以上还没处理好
}

