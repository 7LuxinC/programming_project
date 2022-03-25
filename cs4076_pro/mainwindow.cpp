#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ZorkUL.h"

#include<QMessageBox>
#include <string>
#include <QString>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    ui ->textEdit ->setText("hello");
}


void MainWindow::on_pushButton_3_clicked()
{
    //this =this class
    QMessageBox::about(this,"---WELCOME ヾ(*´▽‘*)ﾉ---", "You are now standing in the city of loswifire and you are a messenger guarding the five-colored spirit stones."
                                                       " Suddenly one day, you find that the light of the five-colored spiritual stone is flickering, which means that the city is about to shake until it is destroyed. "
                                                       "Check out countless books and you've finally found a way. It is recorded in the book that every 500 years, the energy of the five-color stone will weaken, "
                                                       "and it is necessary to gather all the elements of gold, wood, water, fire, and earth to reactivate the energy source. "
                                                       "You will be ready to embark on a fantastic adventure. Check out the info to before starting the game.<(￣︶￣)↗ Let's starrrt!!!!");

}



void MainWindow::on_pushButton_4_clicked()
{
   //convert string to QString to met the infomation method


   QString qstr = QString::fromStdString(zork->ZorkUL::printHelp());
   QMessageBox::information(this,"Information",qstr);

}

