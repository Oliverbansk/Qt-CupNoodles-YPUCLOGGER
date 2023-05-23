#include "global.h"
#include "mylogin.h"
#include "mylogininput.h"
#include "mypublicspace.h"
#include "myhomepage.h"
#include "mymoviescollection.h"
#include "mymoviedetail.h"
#include "myadminedit.h"
#include "myadminlogin.h"
#include "mydisplaymovie.h"
#include "myaddold.h"
#include "myaddnew.h"
#include "QApplication"
#include "QVector"
#include "QQueue"
#include "QString"
#include "QDebug"
#include "QDate"
#include "QSqlQuery"
#include "QSqlError"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //currUser = new Quser("new_user","00000000","oli","班世锟","2021","DataScience");//替换为复制构造函数
    //QDate currdate(2002,12,30);
    //currUser->birthday = currdate;
    //currUser->avatar = ":/background/covertest.jpg";

    //建立用户数据库
    QSqlDatabase db_users = QSqlDatabase::database("db_users");
    db_users.setHostName("cupnoodles");
    db_users.setDatabaseName("db_users");
    db_users.setUserName("cups");
    db_users.setPassword("123456");
    bool ok_users = db_users.open();
    if(ok_users) qDebug()<<"db_users opened successfully!";
    QSqlQuery query_users(db_users);
    QString table_description = "create table user (account varchar(100) NOT NULL, password varchar(100) NOT NULL, username varchar(100) NULL, realname varchar(100) NULL, grade varchar(100) NULL, major varchar(100) NULL, birthday varchar(100) NULL, watched_list varchar(200) NULL, top_five varchar(100) NULL )";
    if(!query_users.exec(table_description))
        qDebug()<<"Error:fail to create table"<<query_users.lastError();
    else
        qDebug() << "Table created!";
    /*if(!query_users.exec("delete from user")) qDebug() << query_users.lastError();
    else qDebug() << "table cleared";*/
    /*if(!query_users.exec("drop table user")) qDebug() << query_users.lastError();
    else qDebug() << "table dropped";*/


    //建立电影数据库
    QSqlDatabase db_movies = QSqlDatabase::database("db_movies");
    db_movies.setHostName("cupnoodles_2");
    db_movies.setDatabaseName("db_movies");
    db_movies.setUserName("cups_2");
    db_movies.setPassword("123456");
    bool ok_movies = db_movies.open();
    if(ok_movies) qDebug()<<"db_movies opened successfully!";
    QSqlQuery query_movies(db_movies);
    QString table_description_mov = "create table movie (poster varchar(100) NULL, moviename varchar(100) NOT NULL, year varchar(50) NULL, director varchar(100) NULL, region varchar(100) NULL, introduction varchar(100) NULL, db_score double NULL, ypuc_score double NULL, watched_cnt int NULL, watched int NULL )";//, moviedate varchar(100) NULL, stime varchar(100) NULL , etime varchar(100) NULL)";
    if(!query_movies.exec(table_description_mov)) qDebug()<<"fail to create table"<<query_movies.lastError();
    else qDebug() << "Table created!";
    /*if(!query_movies.exec("delete from movie")) qDebug() << query_movies.lastError();
    else qDebug() << "table cleared";*/
    /*if(!query_movies.exec("drop table movie")) qDebug() << query_movies.lastError();
    else qDebug() << "table dropped";*/

    /*query_movies.prepare("update movie set introduction = :introduction where moviename = :moviename");
    query_movies.bindValue(":introduction","富有魅力的牧场主菲尔伯班克让他周国的人又敬又怕。当他的兄弟将新婚妻子以及她的儿子带回家时，菲尔百般折磨他们，直到有一天，他发现自己对爱也存有一丝渴望。");
    query_movies.bindValue(":moviename","犬之力");
    if(!query_movies.exec()) qDebug()<<query_movies.lastError();
    else qDebug()<<"updated!";*/

    int cnt = 0;
    QString select_sql = "select moviename,year,director,region,db_score,introduction,watched from movie";
    if(!query_movies.exec(select_sql)) qDebug()<<query_movies.lastError();
    else{
        while (query_movies.next())
        {
            cnt++;
            QString name = query_movies.value(0).toString();
            QString year = query_movies.value(1).toString();
            QString director = query_movies.value(2).toString();
            QString region = query_movies.value(3).toString();
            double db_score = query_movies.value(4).toDouble();
            QString introduction = query_movies.value(5).toString();
            int watched = query_movies.value(6).toInt();
            //qDebug()<<QString("name:%1 year:%2 director:%3 region:%4 db_score:%5 intro:%6 watched:%7").arg(name).arg(year).arg(director).arg(region).arg(db_score).arg(introduction).arg(watched);
        }
    }
    //qDebug()<<cnt;



    MyLogin LoginWid;//最初始的界面
    MyLoginInput loginInputWid;//用户登陆界面（输入用户名和密码）
    MyPublicSpace publicSpaceWid;//公共空间界面
    MyHomepage homepageWid;//个人主页页面
    MyMovieDetail movieDetailWid;//电影详情页面
    MyMoviesCollection moviesCollectionWid;//更多电影页面
    MyAdminLoginInput adminLoginInputWid;//管理员登陆页面
    MyAdminEditing adminEditing;//管理员编辑界面
    MyDisplayMovie displayMovie;//放映影片界面
    MyAddOld addOld;//旧片重放界面
    MyAddNew addNew;//添加新片界面
    //MyShareDialog shareDialogWid;
    LoginWid.show();
    //publicSpaceWid.show();
    //homepageWid.show();
    //movieDetailWid.show();
    //moviesCollectionWid.show();

    QObject::connect(&LoginWid,SIGNAL(showLoginInput()),&loginInputWid,SLOT(receiveLogin()));
    QObject::connect(&loginInputWid,SIGNAL(showLogin()),&LoginWid,SLOT(receiveOthers()));
    QObject::connect(&publicSpaceWid,SIGNAL(showLogin()),&LoginWid,SLOT(receiveOthers()));
    QObject::connect(&loginInputWid,SIGNAL(showPublicSpace()),&publicSpaceWid,SLOT(receiveLoginInput()));
    QObject::connect(&publicSpaceWid,SIGNAL(showHomepage()),&homepageWid,SLOT(receivePublicSpace()));
    QObject::connect(&homepageWid,SIGNAL(showPublicSpace()),&publicSpaceWid,SLOT(receiveHomepage()));
    QObject::connect(&homepageWid,SIGNAL(showLogin()),&LoginWid,SLOT(receiveOthers()));
    QObject::connect(&publicSpaceWid,SIGNAL(showMoviesCollection()),&moviesCollectionWid,SLOT(receivePublicSpace()));
    QObject::connect(&moviesCollectionWid,SIGNAL(showPublicSpace()),&publicSpaceWid,SLOT(receiveMoviesCollection()));
    QObject::connect(&movieDetailWid,SIGNAL(showPublicSpace()),&publicSpaceWid,SLOT(receiveMovieDetail()));
    //初始界面->游客登陆界面
    QObject::connect(&LoginWid,SIGNAL(showVisitorPublicSpace()),&publicSpaceWid,SLOT(receiveVisitorLogin()));
    //初始界面->管理员登陆界面
    QObject::connect(&LoginWid,SIGNAL(showAdminLoginInput()),&adminLoginInputWid,SLOT(receiveLogin()));
    //管理员登陆界面->初始界面
    QObject::connect(&adminLoginInputWid,SIGNAL(showLogin()),&LoginWid,SLOT(receiveAdminInput()));
    //管理员登陆界面->管理员编辑界面
    QObject::connect(&adminLoginInputWid,SIGNAL(showAdminEdit()),&adminEditing,SLOT(receiveAdminInput()));
    //管理员编辑界面->初始界面
    QObject::connect(&adminEditing,SIGNAL(showAdminInput()),&LoginWid,SLOT(receiveAdminEdit()));
    //管理员编辑界面->放映影片界面
    QObject::connect(&adminEditing,SIGNAL(showDisplayMovie()),&displayMovie,SLOT(receiveAdminEdit()));
    //管理员编辑界面->旧片重放界面
    QObject::connect(&adminEditing,SIGNAL(showAddOld()),&addOld,SLOT(receiveAdminEdit()));
    //管理员编辑界面->添加新片界面
    QObject::connect(&adminEditing,SIGNAL(showAddNew()),&addNew,SLOT(receiveAdminEdit()));
    //放映影片界面->管理员编辑界面
    QObject::connect(&displayMovie,SIGNAL(returnAdminEdit()),&adminEditing,SLOT(receiveAdminInput()));
    //旧片重放界面->管理员编辑界面
    QObject::connect(&addOld,SIGNAL(returnAdminEdit()),&adminEditing,SLOT(receiveAdminInput()));
    //添加新片界面->管理员编辑界面
    QObject::connect(&addNew,SIGNAL(returnAdminEdit()),&adminEditing,SLOT(receiveAdminInput()));
    //公共空间->电影详情（六个按钮）
    QObject::connect(&publicSpaceWid,SIGNAL(showMovieDetail()),&movieDetailWid,SLOT(receivePublicSpace()));

    db_users.close();
    db_movies.close();

    if(currMovie)
    {
        delete currMovie;
        currMovie = NULL;
    }
    if(currUser)
    {
        delete currUser;
        currUser = NULL;
    }
    return a.exec();
}
