#ifndef GLOBAL_H
#define GLOBAL_H

#include "QVector"
#include "QQueue"
#include "QString"
#include "QDate"
#include "QSqlDatabase"
#include "QSqlQuery"


class Qmovie{
public:
    QString poster;//路径后缀
    QString moviename;
    QString year;
    QString director;
    QString region;
    QString introduction;
    double db_score;
    double ypuc_score;
    int watched_cnt;
    int watched;//0-unwatched,1-watched
    void deal_new_score(double new_score)//观看人数加1，计算平均分数
    {
        watched_cnt++;
        ypuc_score = (ypuc_score+new_score)/watched_cnt;
    }

    Qmovie(){}
    //Qmovie(const Qmovie & x){}
    Qmovie(QString poster_,QString moviename_ ,QString year_,QString director_ ,QString region_ ,
           QString introduction_ ,double db_score_ ,double ypuc_score_ ,int watched_cnt_ ,int watched_):
        poster(poster_),moviename(moviename_),year(year_),director(director_),region(region_),
        introduction(introduction_),db_score(db_score_),ypuc_score(ypuc_score_),watched_cnt(watched_cnt_),watched(watched_)
    {}
};

class Quser{
public:
    QString avatar;//不存入数据库！

    QString account;
    QString password;
    QString username;
    QString realname;
    QString grade;
    QString major;
    QDate birthday;
    QString watched_list;
    QString top_five;
    Quser(){}
    Quser(QString account_,QString password_,QString username_ = "未填写",QString realname_ = "未填写",QString grade_ = "未填写",
          QString major_ = "未填写",QDate birthday_= QDate(2000,01,01),QString watched_list_ = "",QString top_five_ = "|||||")
        :account(account_),password(password_),username(username_),realname(realname_),grade(grade_),
          major(major_),birthday(birthday_),watched_list(watched_list_),top_five(top_five_)
    {
    }
};

class Qadmin{
public:
    QString account;
    QString password;
    Qadmin(QString account_,QString password_):account(account_),password(password_){}
};


extern QVector<Qadmin> all_admins;
extern QVector<Quser> all_users;
extern QVector<Qmovie> all_movies;

extern QVector<Qmovie> movies_displayed;
extern QVector<Qmovie> movies_to_display;

extern void display();

extern Quser* currUser;//指向此时登录的user
extern Qadmin* currAdmin;//指向此时正在操作的admin（admin不设置页面注册功能，只能由我们设置，如果非空则代表此时是管理员界面）
extern Qmovie* currMovie;


extern QSqlDatabase db_users;
extern QSqlDatabase db_movies;

#endif // GLOBAL_H
