#ifndef MYADMINEDIT_H
#define MYADMINEDIT_H

#include <QWidget>

namespace Ui {
class MyAdminEditing;
}

class MyAdminEditing : public QWidget
{
    Q_OBJECT

public:
    explicit MyAdminEditing(QWidget *parent = nullptr);
    ~MyAdminEditing();

signals:
    void showAdminInput();
    void showDisplayMovie();
    void showAddOld();
    void showAddNew();

private slots:
    void receiveAdminInput();

    void on_returnButton_clicked();

    void on_display_movie_clicked();

    void on_add_old_clicked();

    void on_add_new_clicked();

private:
    Ui::MyAdminEditing *ui;
};



#endif // MYADMINEDIT_H
