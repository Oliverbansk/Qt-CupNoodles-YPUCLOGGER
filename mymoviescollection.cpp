#include "global.h"
#include "mymoviescollection.h"
#include "ui_mymoviescollection.h"

MyMoviesCollection::MyMoviesCollection(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyMoviesCollection)
{
    ui->setupUi(this);
    ui->gridFrame->setStyleSheet("#gridFrame{border-image: url(:/background/ypuclogo.jpg);}");
    for(int i=0;i<25;i++) pButtons[i] = NULL;
    pButtons[0] = ui->movie;
    pButtons[1] = ui->movie_2;
    pButtons[2] = ui->movie_3;
    pButtons[3] = ui->movie_4;
    pButtons[4] = ui->movie_5;
    pButtons[5] = ui->movie_6;
    pButtons[6] = ui->movie_7;
    pButtons[7] = ui->movie_8;
    pButtons[8] = ui->movie_9;
    pButtons[9] = ui->movie_10;
    pButtons[10] = ui->movie_11;
    pButtons[11] = ui->movie_12;
    pButtons[12] = ui->movie_13;
    pButtons[13] = ui->movie_14;
    pButtons[14] = ui->movie_15;
    pButtons[15] = ui->movie_16;
    pButtons[16] = ui->movie_17;
    pButtons[17] = ui->movie_18;

    /*ui->movie->setStyleSheet("QPushButton{border-image:url(:/posters/妈的多重宇宙.jpg)}");
    ui->movie_2->setStyleSheet("QPushButton{border-image:url(:/posters/从海底出击.jpg)}");
    ui->movie_3->setStyleSheet("QPushButton{border-image:url(:/posters/时光之尘.jpg)}");
    ui->movie_4->setStyleSheet("QPushButton{border-image:url(:/posters/地下.jpg)}");
    ui->movie_5->setStyleSheet("QPushButton{border-image:url(:/posters/控方证人.jpg)}");
    ui->movie_6->setStyleSheet("QPushButton{border-image:url(:/posters/白丝带.jpg)}");
    ui->movie_7->setStyleSheet("QPushButton{border-image:url(:/posters/鸟人.jpg)}");
    ui->movie_8->setStyleSheet("QPushButton{border-image:url(:/posters/花束般的恋爱.jpg)}");
    ui->movie_9->setStyleSheet("QPushButton{border-image:url(:/posters/山河故人.jpg)}");
    ui->movie_10->setStyleSheet("QPushButton{border-image:url(:/posters/教父.jpg)}");
    ui->movie_11->setStyleSheet("QPushButton{border-image:url(:/posters/洛可兄弟.jpg)}");
    ui->movie_12->setStyleSheet("QPushButton{border-image:url(:/posters/流浪者之歌.jpg)}");
    ui->movie_13->setStyleSheet("QPushButton{border-image:url(:/posters/风之谷.jpg)}");
    ui->movie_14->setStyleSheet("QPushButton{border-image:url(:/posters/犬之力.jpg)}");
    ui->movie_15->setStyleSheet("QPushButton{border-image:url(:/posters/迷失东京.jpg)}");*/
}

MyMoviesCollection::~MyMoviesCollection()
{
    delete ui;
}
void MyMoviesCollection::receivePublicSpace()
{
    int j = 0;
    for(auto i = all_movies.begin(); i!=all_movies.end()&&j<18;i++,j++)
    {
        QString movposter = i->poster;
        pButtons[j]->setStyleSheet("border-image: url(:" + movposter + ");");
    }
    this->show();
}

/*void MyMoviesCollection::receiveHomepage()
{

    //ui->toolButton->hide();
    //this->show();
}*/

void MyMoviesCollection::on_toolButton_clicked()
{
    this->hide();
    emit showPublicSpace();
}
