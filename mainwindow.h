#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Btree.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btnAddKid_clicked();

    void on_pushButton_clicked();

    void on_btnAddListTo_clicked();

    void on_btnSearch_clicked();

private:
    Ui::MainWindow *ui;
    Btree<Kid* ,3> tree;
};

#endif // MAINWINDOW_H
