#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


#include "ZorkUL.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT



public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_quitBtn_clicked();
    void on_messageBtn_clicked();
    void on_infoBtn_clicked();

private:
    Ui::MainWindow *ui;
    ZorkUL *zork;
    Parser parser;



};
#endif // MAINWINDOW_H
