#include "global.h"

QVector<Qadmin> all_admins;
QVector<Quser> all_users;
QVector<Qmovie> all_movies;
QVector<Qmovie> movies_displayed;
QVector<Qmovie> movies_to_display;

void display()
{
    Qmovie tmp = movies_to_display.front();
    movies_to_display.removeFirst();
    movies_displayed.append(tmp);
}

Quser* currUser = NULL;//指向此时登录的user
Qadmin* currAdmin = NULL;//指向此时正在操作的admin（admin不设置页面注册功能，只能由我们设置，如果非空则代表此时是管理员界面）
Qmovie* currMovie = NULL;



QSqlDatabase db_users = QSqlDatabase::addDatabase("QSQLITE","db_users");
QSqlDatabase db_movies = QSqlDatabase::addDatabase("QSQLITE","db_movies");
