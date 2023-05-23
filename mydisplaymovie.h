#ifndef MYDISPLAYMOVIE_H
#define MYDISPLAYMOVIE_H

#include <QWidget>

namespace Ui {
class MyDisplayMovie;
}

class  MyDisplayMovie : public QWidget
{
    Q_OBJECT

public:
    explicit  MyDisplayMovie(QWidget *parent = nullptr);
    ~ MyDisplayMovie();
    int moviecnt;

signals:
    void returnAdminEdit();

private slots:
    void receiveAdminEdit();

    void on_returnButton_clicked();

    void on_comfirmButton_clicked();

private:
    Ui:: MyDisplayMovie *ui;
};

#endif // MYDISPLAYMOVIE_H
