#include "myadminedit.h"
#include "ui_myadminedit.h"

MyAdminEditing::MyAdminEditing(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyAdminEditing)
{
    ui->setupUi(this);
    ui->background->setStyleSheet("#background{border-image: url(:/background/ccd.jpg);}");

}

MyAdminEditing::~MyAdminEditing()
{
    delete ui;
}

void MyAdminEditing::receiveAdminInput(){
    this->show();
}


void MyAdminEditing::on_returnButton_clicked()
{
    this->close();
    emit showAdminInput();
}


void MyAdminEditing::on_display_movie_clicked()
{
    this->close();
    emit showDisplayMovie();
}


void MyAdminEditing::on_add_old_clicked()
{
    this->close();
    emit showAddOld();
}


void MyAdminEditing::on_add_new_clicked()
{
    this->close();
    emit showAddNew();
}

