#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "ZorkUL.h"

#include<QMessageBox>
#include <string>
#include <QString>
#include <QtDebug>
#include <QPixmap>
#include <cstring>
#include <QColor>
#include <QProgressBar>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


     ui ->groupBox ->setStyleSheet("QGroupBox {color: lightblue; font:bold}");
      ui->potionLb->setStyleSheet("QLabel {color: white; font:bold}");
     ui->moveLb ->setStyleSheet("QLabel {color:white; font:bold}");
     ui->progressBar->setStyleSheet("QProgressBar::chunk{background-color: lightgreen;} QProgressBar {color: blue; font:bold}");

    //upload map picture in the mainwindow screen
    QPixmap pix(":/resources/img/map.png");
    ui -> mapImg -> setPixmap(pix);   //mapImg = label




    zork = new ZorkUL();
    QString qstr = QString::fromStdString(zork ->printWelcome());
    ui ->output -> setText(qstr);


    ui->moveLb ->setText("MOVE: " + toQstr(to_string(zork->getCharacter()->getMove())));


    QPixmap pix1(toQstr(zork ->getPic()));
    ui -> imgLb -> setPixmap(pix1);

    listItem();
    ui ->activation ->setEnabled(false);

     ui->potionLb ->setText("MAGICAL POTION:");


}

MainWindow::~MainWindow()
{
    delete ui;
    delete zork;


}

//change any string to Qstring
QString MainWindow::toQstr(string str){
    QString toQstr = QString::fromStdString(str);
    return toQstr;
}


void MainWindow::on_messageBtn_clicked()
{
    //this =this class
    QMessageBox::about(this,"---WELCOME ヾ(*´▽‘*)ﾉ---", "You are now standing in the city of loswifire and you are a messenger guarding the five-colored spirit stones."
                                                       " Suddenly one day, you find that the light of the five-colored spiritual stone is flickering, which means that the city is about to shake until it is destroyed. "
                                                       "Check out countless books and you've finally found a way. It is recorded in the book that every 500 years, the energy of the five-color stone will weaken, "
                                                       "and it is necessary to gather all the elements of gold, wood, water, fire, and earth to reactivate the energy source. "
                                                       "You will be ready to embark on a fantastic adventure. Check out the info to before starting the game.<(￣︶￣)↗ Let's starrrt!!!!");
}


void MainWindow::on_infoBtn_clicked()
{
   //convert string to QString to met the infomation method
   QString qstr = QString::fromStdString(zork->ZorkUL::printHelp());
   QMessageBox::information(this,"Information",qstr);

}



void MainWindow::on_quitBtn_clicked()
{
    //ask the player if he want to quit the game
    QMessageBox::StandardButtons reply = QMessageBox::question(this,"Quit the program","Are you sure you want to quit?",QMessageBox::Yes | QMessageBox::No);

    if(reply == QMessageBox::Yes) {
        QApplication::quit();

    }else {
        qDebug() << "Stay in the program";
    }
}


void MainWindow::counter(){

    string stay = ui->output->toPlainText().toStdString();
    zork ->getCharacter() ->moveCounter(stay);
    string move = to_string(zork ->getCharacter() ->getMove());

    ui->moveLb ->setText("MOVE: " + toQstr(move));


}






void MainWindow::on_northBtn_clicked()
{

    QString s = toQstr( zork ->go("north"));

    ui -> output ->setText(s);

    QPixmap pix1(toQstr(zork ->getPic()));
    ui -> imgLb -> setPixmap(pix1);

    counter();
    hasTakeBtn(s);

   checkWordleQuizz();

   randChoice(ui->northBtn,s);

}


void MainWindow::on_eastBtn_clicked()
{
    QString s = toQstr( zork ->go("east"));

    ui -> output ->setText(s);

    QPixmap pix1(toQstr(zork ->getPic()));
    ui -> imgLb -> setPixmap(pix1);

    counter();
    hasTakeBtn(s);

    checkWordleQuizz();
    randChoice(ui->eastBtn,s);



}



void MainWindow::on_west_clicked()
{
    QString s = toQstr( zork ->go("west"));

    ui -> output ->setText(s);

    QPixmap pix1(toQstr(zork ->getPic()));
    ui -> imgLb -> setPixmap(pix1);

    counter();
    hasTakeBtn(s);
    checkWordleQuizz();
randChoice(ui->west,s);
}





void MainWindow::on_southBtn_clicked()
{
    QString s = toQstr(zork ->go("south"));


    ui -> output ->setText(s);

    QPixmap pix1(toQstr(zork ->getPic()));
    ui -> imgLb -> setPixmap(pix1);
    counter();
    hasTakeBtn(s);
    checkWordleQuizz();

     randChoice(ui->southBtn,s);

}





void MainWindow::on_teleportBtn_clicked()
{
    QString s = toQstr("Zfffffft transfer completed.~~~\n\nCurrent Location:\n"  + zork -> teleport());

    ui -> output ->setText(s);

    QPixmap pix1(toQstr(zork ->getPic()));
    ui -> imgLb -> setPixmap(pix1);
    counter();
    hasTakeBtn(s);
    checkWordleQuizz();

    randChoice(ui->teleportBtn,toQstr("no end output"));


}




void MainWindow::hasTakeBtn(QString qs){

ui -> listWidget ->clear();
    if(zork ->hasItems()){

        if(zork ->hasItems() && zork->getCurrentRoom()->shortDescription() == "Sky City"){

            // listItem();
              ui -> collectBtn -> setEnabled(false);
        }

        ui ->collectBtn->setEnabled(true);
        listItem();


    }else {
        ui -> collectBtn -> setEnabled(false);

    }

    if(qs == toQstr("*****Invalid direction,try different ways!*****")){
        ui->listWidget -> clear();
    }
}


void MainWindow::listItem(){


    int itemsize = zork -> getCurrentRoom()->getItemSize();
    for(int i = 0 ; i < itemsize; i++){
        QString itemlist = toQstr(zork ->showItems(i));
        ui -> listWidget ->addItem(itemlist);


    }

}

void MainWindow::collectItems(){

    int rowOfItems = ui -> listWidget ->currentRow();

    QListWidgetItem *it = ui ->listWidget->takeItem(rowOfItems);  //get the selected item in list


    string foundItem = zork ->getCurrentRoom()->searchItem(rowOfItems);       //search matching item in room
 showElement(foundItem);

    zork ->getCharacter()->addItems(foundItem,*zork ->getCurrentRoom());      //add item in player's bag





    zork ->getCurrentRoom() ->removeItemFromRoom(rowOfItems);   //remove the item in room

    //details:
    string currItemDetail = zork -> getCurrentRoom() ->longDescription();
    ui->output->append("----------------------------------------");
    ui ->output -> append(toQstr("\n" + currItemDetail));
    showItemsInBag();


    delete it;    //it won't delete the object itself


}




void MainWindow::showElement(string itemN){
    string imgP = zork->getCurrentRoom()->getItemImage(itemN);

    if(itemN == "Magical Potion"){

       // ui->element1 ->setText(toQstr(itemN));
         ui -> element1 -> setPixmap(toQstr(imgP));

         if(zork ->getCharacter()->getPotion() == 0){
             ui->element1 ->clear();
         }
    }else if(itemN == "Fertile Soil"){
        ui -> element2 -> setPixmap(toQstr(imgP));
    }else if(itemN == "Spring Water"){
        ui -> element3 -> setPixmap(toQstr(imgP));
    }else if(itemN == "Gold Ore"){
        ui -> element4 -> setPixmap(toQstr(imgP));
    }else if(itemN == "Fire Gabbro"){
         ui -> element5 -> setPixmap(toQstr(imgP));
    }else if(itemN == "Wood Stick"){
        ui -> element6 -> setPixmap(toQstr(imgP));
    }
}



void MainWindow::on_collectBtn_clicked()
{

    collectItems();

    int value = zork->getCharacter()->getPotion();
    setProgressValue(ui->collectBtn,value);

}

void MainWindow::showItemsInBag(){
     ui -> output -> append(toQstr(zork ->getCharacter() ->getLongDescription()));
}

void MainWindow::on_bag_clicked()

{
    showItemsInBag();

}


void MainWindow::checkWordleQuizz(){

    if(zork ->getCurrentRoom()->shortDescription() == "Sky City"){
        if(zork->getCharacter()->getNumItemInBag() != 0){

        ui ->activation ->setEnabled(true);
        }
    }else {
        ui ->activation ->setEnabled(false);
    }


}




void MainWindow::on_activation_clicked()
{

    if(wonGame() == false){

    wordleDialog = new WordleDialog();

    wordleDialog->exec();

    if(wordleDialog ->winGame()){
         setProgressValue(ui->activation,10);
        zork->getCharacter()->setPotion(10);
    }

    delete wordleDialog;

    }



}


void MainWindow::setProgressValue(QPushButton *button,int value){

    if(ui->progressBar->value() != 100){
    connect(button,SIGNAL(click(bool)),ui->progressBar,SLOT(reset(bool)));
    if(value > 10){
        ui->progressBar->setValue(100);
    }
   ui->progressBar ->setValue(value * 10);
}
}

void MainWindow::randChoice(QPushButton *button,QString directionOut){
    int step = zork->getCharacter()->getMove();
    string roomName = zork -> getCurrentRoom()->shortDescription();

    if(zork->getCharacter()->getPotion() != 0 && ui->progressBar ->value() != 100){
        if(step % 3 == 0 && roomName == "Mysterious Wood" ){
            if(ui->progressBar ->value() > 10){
            zork->getCharacter() ->takePotion(1);
            int potionValue = zork ->getCharacter()->getPotion();
            setProgressValue(button,potionValue);

            ui->imgLb ->setPixmap(toQstr(":/resources/img/troll_attack.png"));

            if(directionOut != toQstr("*****Invalid direction,try different ways!*****")){

              QMessageBox::information(this, "ALERT!!", "Troll is trying to take all your potion in Mysterious Wood. \n(Magical Potion -1)");
            }
           }

        }else if(step % 4 == 0 && roomName == "Mysterious Wood"){
            zork->getCharacter() ->addPotion(2);

            int potionValue = zork ->getCharacter()->getPotion();
            setProgressValue(button,potionValue);

            ui->imgLb ->setPixmap(toQstr(":/resources/img/Mystery_Witch.png"));

             if(directionOut != toQstr("*****Invalid direction,try different ways!*****")){
            QMessageBox::information(this, "The witch has flown by.", "You saw a witch has flown by and droped two magical potion. \n(Magical Potion +2)");
        }




        }else if(step % 3 == 0 && roomName == "Cliff"){
            if(ui->progressBar ->value() > 20){
            ui->imgLb ->setPixmap(toQstr(":/resources/img/dropping_potion.png"));

             if(directionOut != toQstr("*****Invalid direction,try different ways!*****")){
            QMessageBox::information(this, "Cliff", "Opps,You almost fell off a cliff and lost two magical potion. \n(Magic Potion -2)");
             }
}
            zork->getCharacter() ->takePotion(2);

            int potionValue = zork ->getCharacter()->getPotion();
            setProgressValue(button,potionValue);
        }else if(step % 4 == 0 && roomName == "Cliff"){

            ui->imgLb ->setPixmap(toQstr(":/resources/img/soldier.png"));

             if(directionOut != toQstr("*****Invalid direction,try different ways!*****")){
            QMessageBox::information(this, "A solider.", "A soldier is resting around cliff, wondering if you are the enemy...\n(Magical Potion +1)");
}
            zork->getCharacter() ->addPotion(1);
            int potionValue = zork ->getCharacter()->getPotion();
            setProgressValue(button,potionValue);

        }

}
}

bool MainWindow::wonGame(){
   int progressValue = ui->progressBar ->value();
   int bagItems = zork->getCharacter()->getNumItemInBag();

   if(progressValue == 100 && bagItems == 6){
       ui->progressBar->setStyleSheet("QProgressBar::chunk{background-color: cyan;} QProgressBar {color: blue; font:bold}");

        zork->getCurrentRoom()->addItem(new Item(zork->getCharacter()->givePotion()));

       listItem();

        zork->getCharacter()->removeItemsInBag("Magical Potion");
       QMessageBox::information(this,"!!!!  GREAT JOB  !!!!", "Hoooray!!, you save the land of the Loswilire and you are the master of power guardiance of this land.\n\n ******  MISSION FINISHED  ******");
        return true;
   }
   return false;
}





