#include "global.h"
#include "mysharedialog.h"
#include "ui_mysharedialog.h"

MyShareDialog::MyShareDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyShareDialog)
{
    ui->setupUi(this);
}

MyShareDialog::~MyShareDialog()
{
    delete ui;
}

void MyShareDialog::receiveHomepage()
{
    this->show();
}
