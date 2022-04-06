#include <iostream>
#include <QApplication>
#include <QPixmap>
#include "ZorkUL.h"
#include "mainwindow.h"

using namespace std;

int main(int argc, char *argv[]) {
    QApplication app(argc,argv);
    MainWindow w;

    //ZorkUL temp;
    //temp.play();

   w.setStyleSheet(".QWidget{background-image: url(:/resources/img/background.png);}");
   w.show();    //...show the main window
   return app.exec();

}
