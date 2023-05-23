#include "myhomepage.h"
#include "ui_myhomepage.h"
#include "mysharedialog.h"
#include "ui_mysharedialog.h"
#include "global.h"
#include "QLabel"
#include "QDate"
#include "QDialog"
#include "QPixmap"
#include "QPainter"
#include "QBitmap"
#include "QColor"
#include "QPalette"
#include "QSizePolicy"
#include "QFileDialog"
#include "QInputDialog"
#include "QSqlDatabase"
#include "QSqlError"
#include "QSqlQuery"
#include "QPushButton"
#include "QDebug"
#include "QList"

static QPixmap PixmapToRound(QPixmap &src, int radius)
{
    if (src.isNull()) {
        return QPixmap();
    }

    QSize size(2*radius, 2*radius);
    QBitmap mask(size);
    QPainter painter(&mask);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setRenderHint(QPainter::SmoothPixmapTransform);
    painter.fillRect(0, 0, size.width(), size.height(), Qt::white);
    painter.setBrush(QColor(0, 0, 0));
    painter.drawRoundedRect(0, 0, size.width(), size.height(), 99, 99);

    QPixmap image = src.scaled(size);
    image.setMask(mask);
    return image;
}


MyHomepage::MyHomepage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyHomepage)
{
    ui->setupUi(this);
    ui->frame_myhomepage->setStyleSheet("#frame_myhomepage{border-image: url(:/background/ypuclogo.jpg);}");

    for(int i=0;i<15;i++) history[i] = "";
    for(int i=0;i<10;i++) top5[i] = "";
    //设置所有按钮
    const QString round_SheetStyle = "min-width: 28px; min-height: 28px;max-width:28px; max-height: 30px;border-radius: 14px; border:1px solid pink;background:pink;font-size:17px ";
    ui->photo_edit->setStyleSheet(round_SheetStyle);//改成圆形
    ui->nickname_edit->setStyleSheet(round_SheetStyle);//改成圆形
    ui->real_name_edit->setStyleSheet(round_SheetStyle);//改成圆形
    ui->grade_edit->setStyleSheet(round_SheetStyle);//改成圆形
    ui->major_edit->setStyleSheet(round_SheetStyle);//改成圆形
    //ui->birthdate_edit->setStyleSheet(round_SheetStyle);//改成圆形
    //ui->title_edit->setStyleSheet(round_SheetStyle);//改成圆形
    //ui->title_edit_2->setStyleSheet(round_SheetStyle);//改成圆形

    //设置标题
    const QString label_SheetStyle_1 = "min-width: 220px; min-height: 27px; max-width:280px; max-height: 32px;border-radius: 12px;  border:1px solid pink;background:pink;font-size:17px;color:white";
    ui->title_watched_list->setStyleSheet(label_SheetStyle_1);
    ui->title_top_5->setStyleSheet(label_SheetStyle_1);
    //初始化用户画像
    QPixmap pixmap_userIcon;
    QString userPath = ":/background/covertest.jpg";//待修改
    pixmap_userIcon.load(userPath);
    QPixmap fitpixmap_userIcon = pixmap_userIcon.scaled(120, 120, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    fitpixmap_userIcon = PixmapToRound(fitpixmap_userIcon, 60);
    ui->my_image->setPixmap(fitpixmap_userIcon);

    const QString label_SheetStyle_2 = "min-width: 150px; min-height: 27px; max-width:210px; max-height: 32px;border-radius: 12px;  border:1px solid pink;background:pink;font-size:17px;color:white";
    //QString userNickname = currUser->username;
    //ui->nickname_content->setText(userNickname);
    ui->nickname_content->setStyleSheet(label_SheetStyle_2);
    //QString userRealname = currUser->realname;
    //ui->real_name_content->setText(userRealname);
    ui->real_name_content->setStyleSheet(label_SheetStyle_2);
    //QString userGrade = currUser->grade;
    //ui->grade_content->setText(userGrade);
    ui->grade_content->setStyleSheet(label_SheetStyle_2);
    //QString userMajor = currUser->major;
    //ui->major_content->setText(userMajor);
    ui->major_content->setStyleSheet(label_SheetStyle_2);
    //QDate userBirthdate = currUser->birthday;
    //ui->dateEdit->setDate(userBirthdate);
    ui->dateEdit->setStyleSheet(label_SheetStyle_2);
}

MyHomepage::~MyHomepage()
{
    delete ui;
}

void MyHomepage::receivePublicSpace()
{
    //download 从数据库获取此用户完整信息，用currUser记录
    QSqlDatabase dbnow;
    if(QSqlDatabase::contains("db_users")) dbnow = QSqlDatabase::database("db_users");
    if (!dbnow.open()) qDebug() << "Error: Failed to connect database." << db_users.lastError();
    QSqlQuery query_users(dbnow);
    if(!currUser) qDebug()<<"wrong in";
    QString now_account = currUser->account;
    QString select = "select * from user where account = :account";
    query_users.prepare(select);
    query_users.bindValue(":account",now_account);
    if(!query_users.exec()) qDebug()<<query_users.lastError();
    else
    {
        while(query_users.next())
        {
            QString account_ = query_users.value(0).toString();
            QString password_ = query_users.value(1).toString();
            QString username_ = query_users.value(2).toString();
            QString realname_ = query_users.value(3).toString();
            QString grade_ = query_users.value(4).toString();
            QString major_ = query_users.value(5).toString();
            QString birthdayStr_ = query_users.value(6).toString();
            QDate birthday_ = QDate::fromString(birthdayStr_,"yyyy/M/d");
            QString watched_list_ = query_users.value(7).toString();
            QString top_five_ = query_users.value(8).toString();

            if(currUser)
            {
                delete currUser;
                currUser = NULL;
            }
            currUser = new Quser(account_,password_,username_,realname_,grade_,major_,birthday_,watched_list_,top_five_);
        }
    }

    //show 将currUser里的信息显示在homepage上
    ui->nickname_content->setText(currUser->username);
    ui->real_name_content->setText(currUser->realname);
    ui->grade_content->setText(currUser->grade);
    ui->major_content->setText(currUser->major);
    ui->dateEdit->setDate(currUser->birthday);
    QString path10[15];
    if(currUser->watched_list != "")
    {
        int k=1;
        QString origin = currUser->watched_list; //qDebug()<<origin;
        QStringList pathlist = origin.split('|');
        QList<QString>::Iterator it;
        for(it = pathlist.begin();it!=pathlist.end();it++)
        {
            path10[k] = *it;
            history[k] = *it;
            //qDebug()<<"path10"<<k<<" "<<path10[k];
            k++;
        }
    }
    if(path10[1]!="") ui->movie1->setStyleSheet("border-image: url(:" + path10[1] + ");");
    if(path10[2]!="") ui->movie2->setStyleSheet("border-image: url(:" + path10[2] + ");");
    if(path10[3]!="") ui->movie3->setStyleSheet("border-image: url(:" + path10[3] + ");");
    if(path10[4]!="") ui->movie4->setStyleSheet("border-image: url(:" + path10[4] + ");");
    if(path10[5]!="") ui->movie5->setStyleSheet("border-image: url(:" + path10[5] + ");");
    if(path10[6]!="") ui->movie6->setStyleSheet("border-image: url(:" + path10[6] + ");");
    if(path10[7]!="") ui->movie7->setStyleSheet("border-image: url(:" + path10[7] + ");");
    if(path10[8]!="") ui->movie8->setStyleSheet("border-image: url(:" + path10[8] + ");");
    if(path10[9]!="") ui->movie9->setStyleSheet("border-image: url(:" + path10[9] + ");");
    if(path10[10]!="") ui->movie10->setStyleSheet("border-image: url(:" + path10[10] + ");");

    QString path5[10];
    if(currUser->top_five != "")
    {
        int k=1;
        QString origin = currUser->top_five; //qDebug()<<origin;
        QStringList pathlist = origin.split('|');
        QList<QString>::Iterator it;
        for(it = pathlist.begin();it!=pathlist.end();it++)
        {
            path5[k] = *it;
            top5[k] = *it;
            //qDebug()<<"path5"<<" "<<path5[k];
            k++;
        }
    }
    if(path5[1]!="") ui->top1->setStyleSheet("border-image: url(:" + path5[1] + ");");
    if(path5[2]!="") ui->top2->setStyleSheet("border-image: url(:" + path5[2] + ");");
    if(path5[3]!="") ui->top3->setStyleSheet("border-image: url(:" + path5[3] + ");");
    if(path5[4]!="") ui->top4->setStyleSheet("border-image: url(:" + path5[4] + ");");
    if(path5[5]!="") ui->top5->setStyleSheet("border-image: url(:" + path5[5] + ");");

    this->show();
}


void MyHomepage::on_return_button_clicked()
{
    this->hide();
    emit showLogin();
}
void MyHomepage::on_publicSpaceButton_clicked()
{
    this->hide();
    emit showPublicSpace();
}

void MyHomepage::on_dateEdit_userDateChanged(const QDate &date)
{
    currUser->birthday = date;
    QString yy = QString::number(date.year());
    QString mm = QString::number(date.month());
    QString dd = QString::number(date.day());
    QString datestr = yy+'/'+mm+'/'+dd;
    upload_str("birthday",datestr);
}



void MyHomepage::on_photo_edit_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                        tr("文件对话框！"),
                                                        "F:",
                                                        tr("图片文件(*png *jpg *jpeg *gif);;"
                                                           "文本文件(*txt)"));
    currUser->avatar = fileName;
    QPixmap pixmap_userIcon;
    QString userPath = currUser->avatar;//待修改
    pixmap_userIcon.load(userPath);
    QPixmap fitpixmap_userIcon = pixmap_userIcon.scaled(120, 120, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    fitpixmap_userIcon = PixmapToRound(fitpixmap_userIcon, 60);
    ui->my_image->setPixmap(fitpixmap_userIcon);

}

void MyHomepage::on_nickname_edit_clicked()
{
    bool bOk = false;
        QString sName = QInputDialog::getText(this,
                                             "昵称",
                                             "请输入昵称",
                                             QLineEdit::Normal,
                                             "ypuc_logger",
                                             &bOk
                                             );

        if (bOk && !sName.isEmpty()) {
            currUser->username = sName;
            ui->nickname_content->setText(sName);
        }
    upload_str("username",ui->nickname_content->text());
}

void MyHomepage::on_real_name_edit_clicked()
{
    bool bOk = false;
        QString sName = QInputDialog::getText(this,
                                             "姓名",
                                             "请输入姓名",
                                             QLineEdit::Normal,
                                             "",
                                             &bOk
                                             );

        if (bOk && !sName.isEmpty()) {
            currUser->realname = sName;
            ui->real_name_content->setText(sName);
        }
    upload_str("realname",ui->real_name_content->text());
}

void MyHomepage::on_grade_edit_clicked()
{
    bool bOk = false;
        QString sName = QInputDialog::getText(this,
                                             "年级",
                                             "请输入年级",
                                             QLineEdit::Normal,
                                             "2022",
                                             &bOk
                                             );

        if (bOk && !sName.isEmpty()) {
            currUser->grade = sName;
            ui->grade_content->setText(sName);
        }
    upload_str("grade",ui->grade_content->text());
}

void MyHomepage::on_major_edit_clicked()
{
    bool bOk = false;
        QString sName = QInputDialog::getText(this,
                                             "专业",
                                             "请输入专业",
                                             QLineEdit::Normal,
                                             "PPE",
                                             &bOk
                                             );

        if (bOk && !sName.isEmpty()) {
            currUser->major = sName;
            ui->major_content->setText(sName);
        }
    upload_str("major",ui->major_content->text());
}



void MyHomepage::setTop5(int i,QPushButton * button)
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                        tr("管理员您好！如果要加载全新海报！请先添加其至posters资源文件中哦！"),
                                                        "F:",
                                                        tr("图片文件(*png *jpg *jpeg *gif);;"
                                                           "文本文件(*txt)"));
    int start = fileName.indexOf("/posters/");
    QString posterPath = fileName.right(fileName.size()-start); // "/posters/白丝带.jpg"
    button->setStyleSheet("border-image: url(:"+ posterPath + ");");
    top5[i] = posterPath;

    //upload
    QString upload5 = "";
    for(int k=1;k<=5;k++)
    {
        upload5 += top5[k];
        upload5 += "|";
    }
    //qDebug()<<upload5;
    QSqlDatabase dbnow;
    if(QSqlDatabase::contains("db_users")) dbnow = QSqlDatabase::database("db_users");
    if (!dbnow.open()) qDebug() << "Error: Failed to connect database." << db_users.lastError();
    QSqlQuery query_users(dbnow);
    if(!currUser) qDebug()<<"wrong in";
    QString now_account = currUser->account;
    QString update_sql = "update user set top_five = :top_five where account = :account";
    query_users.prepare(update_sql);
    query_users.bindValue(":top_five", upload5);
    query_users.bindValue(":account", now_account);
    if(!query_users.exec()) qDebug() << query_users.lastError();
    else qDebug() << "just set "<<i<<" and updated it!";

}

void MyHomepage::setHis(int i,QPushButton * button)
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                        tr("管理员您好！如果要加载全新海报！请先添加其至posters资源文件中哦！"),
                                                        "F:",
                                                        tr("图片文件(*png *jpg *jpeg *gif);;"
                                                           "文本文件(*txt)"));
    int start = fileName.indexOf("/posters/");
    QString posterPath = fileName.right(fileName.size()-start); // "/posters/白丝带.jpg"
    button->setStyleSheet("border-image: url(:"+ posterPath + ");");
    history[i] = posterPath;

    //upload
    QString upload10 = "";
    for(int k=1;k<=10;k++)
    {
        upload10 += history[k];
        upload10 += '|';
    }
    //qDebug()<<upload10;
    QSqlDatabase dbnow;
    if(QSqlDatabase::contains("db_users")) dbnow = QSqlDatabase::database("db_users");
    if (!dbnow.open()) qDebug() << "Error: Failed to connect database." << db_users.lastError();
    QSqlQuery query_users(dbnow);
    if(!currUser) qDebug()<<"wrong in";
    QString now_account = currUser->account;
    QString update_sql = "update user set watched_list = :watched_list where account = :account";
    query_users.prepare(update_sql);
    query_users.bindValue(":watched_list", upload10);
    query_users.bindValue(":account", now_account);
    if(!query_users.exec()) qDebug() << query_users.lastError();
    else qDebug() << "just set one of ten and updated it";
}

void MyHomepage::on_top1_clicked()
{
    setTop5(1,ui->top1);
}


void MyHomepage::on_top2_clicked()
{
    setTop5(2,ui->top2);
}

void MyHomepage::on_top3_clicked()
{
    setTop5(3,ui->top3);
}

void MyHomepage::on_top4_clicked()
{
    setTop5(4,ui->top4);
}

void MyHomepage::on_top5_clicked()
{
    setTop5(5,ui->top5);
}


void MyHomepage::on_movie1_clicked()
{
    setHis(1,ui->movie1);
}

void MyHomepage::on_movie2_clicked()
{
    setHis(2,ui->movie2);
}

void MyHomepage::on_movie3_clicked()
{
    setHis(3,ui->movie3);
}

void MyHomepage::on_movie4_clicked()
{
    setHis(4,ui->movie4);
}

void MyHomepage::on_movie5_clicked()
{
    setHis(5,ui->movie5);
}

void MyHomepage::on_movie6_clicked()
{
    setHis(6,ui->movie6);
}

void MyHomepage::on_movie7_clicked()
{
    setHis(7,ui->movie7);
}

void MyHomepage::on_movie8_clicked()
{
    setHis(8,ui->movie8);
}

void MyHomepage::on_movie9_clicked()
{
    setHis(9,ui->movie9);
}

void MyHomepage::on_movie10_clicked()
{
    setHis(10,ui->movie10);
}

void MyHomepage::upload_str(QString kind,QString content)
{
    QSqlDatabase dbnow;
    if(QSqlDatabase::contains("db_users")) dbnow = QSqlDatabase::database("db_users");
    if (!dbnow.open()) qDebug() << "Error: Failed to connect database." << db_users.lastError();
    QSqlQuery query_users(dbnow);
    if(!currUser) qDebug()<<"wrong in";
    QString now_account = currUser->account;
    QString update_sql = "update user set " + kind + " = :content where account = :account";
    query_users.prepare(update_sql);
    query_users.bindValue(":content", content);
    query_users.bindValue(":account", now_account);
    if(!query_users.exec()) qDebug() << query_users.lastError();
    else qDebug() << "just updated "<<kind;

}


