#include <iostream>
#include <QApplication>

#include <QPixmap>
#include <stdlib.h>

using namespace std;
#include "ZorkUL.h"
#include "mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc,argv);
    MainWindow w;

    //ZorkUL temp;
    //temp.play();
   w.setStyleSheet(".QWidget{background-image: url(:/resources/img/forest.jpg);}");
   w.show();    //...show the main window
   return app.exec();

}
