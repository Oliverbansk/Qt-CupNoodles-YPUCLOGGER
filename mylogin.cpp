#include "global.h"
#include "mylogin.h"
#include "ui_mylogin.h"

MyLogin::MyLogin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyLogin)
{
    ui->setupUi(this);
    ui->frame_login->setStyleSheet("#frame_login{border-image: url(:/background/loginbackground.jpg);}");

}

MyLogin::~MyLogin()
{
    delete ui;
}



void MyLogin::on_btUser_clicked()
{
    this->hide();
    emit showLoginInput();
}

void MyLogin::on_btAdmin_clicked()
{
    this->hide();
    emit showAdminLoginInput();
}

void MyLogin::on_btVisitor_clicked()
{
    this->hide();
    emit showVisitorPublicSpace();
}

void MyLogin::receiveOthers()
{
    this->show();
}

void MyLogin::receiveLoginInput()
{
    this->show();
}

void MyLogin::receiveAdminInput(){
    this->show();
}

void MyLogin::receiveAdminEdit(){
    this->show();
}





