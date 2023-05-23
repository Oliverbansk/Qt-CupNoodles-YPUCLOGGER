#ifndef MYMOVIESCOLLECTION_H
#define MYMOVIESCOLLECTION_H

#include <QWidget>
#include "QPushButton"

namespace Ui {
class MyMoviesCollection;
}

class MyMoviesCollection : public QWidget
{
    Q_OBJECT

public:
    explicit MyMoviesCollection(QWidget *parent = nullptr);
    ~MyMoviesCollection();
    QPushButton * pButtons[25];

signals:
    void showPublicSpace();

private slots:
    void receivePublicSpace();
    //void receiveHomepage();
    void on_toolButton_clicked();

private:
    Ui::MyMoviesCollection *ui;
};

#endif // MYMOVIESCOLLECTION_H
