#ifndef MYSHAREDIALOG_H
#define MYSHAREDIALOG_H

#include <QDialog>

namespace Ui {
class MyShareDialog;
}

class MyShareDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MyShareDialog(QWidget *parent = 0);
    QString getText();
    ~MyShareDialog();

private slots:
    void receiveHomepage();

private:
    Ui::MyShareDialog *ui;
};

#endif // MYSHAREDIALOG_H
