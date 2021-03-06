#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ZorkUL.h"
#include "wordledialog.h"
#include "Character.h"



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
    void on_northBtn_clicked();
    void on_eastBtn_clicked();
    void on_west_clicked();
    void on_southBtn_clicked();
    void on_teleportBtn_clicked();
    void on_collectBtn_clicked();
    void on_bag_clicked();
    void on_activation_clicked();




private:
    Ui::MainWindow *ui;
    Character *zorker;
    WordleDialog *wordleDialog;
    void listItem();
    QString toQstr(string str);
    void hasTakeBtn(QString qs);
    void collectItems();
    void showItemsInBag();
    void checkWordleQuizz();
    void counter();
    void showElement(string itemN);
    void potionChange(int value);
    bool wonGame();
    void setProgressValue(QPushButton *button,int value);
    void randChoice(QPushButton *button,QString directionOut);
    void setQuestion();

    template<class T>
    T division(T a, T b);

};
#endif // MAINWINDOW_H
