#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "ZorkUL.h"
#include "Character.h"
#include<QMessageBox>
#include <string>
#include <QString>
#include <QtDebug>
#include <QPixmap>
#include <cstring>
#include <QColor>
#include <QProgressBar>

int num = 0;

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




    zorker = new Character();


    QString qstr = QString::fromStdString(zorker ->getWelcome());
    ui ->output -> setText(qstr);


    ui->moveLb ->setText("MOVE: " + toQstr(to_string(zorker->getMove())));


    QPixmap pix1(toQstr(zorker ->getPic()));
    ui -> imgLb -> setPixmap(pix1);

    listItem();
    ui ->activation ->setEnabled(false);

     ui->potionLb ->setText("MAGICAL POTION:");

}



MainWindow::~MainWindow()
{
    delete ui;

    ZorkUL *zork = zorker;
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
    QMessageBox::about(this,"---WELCOME ヾ(*´▽‘*)ﾉ---", "You are now standing in the land of Loswilire and you are the new guardiance the five-colored spiritual stones to take if they have enough power to prevent any enemy come to this land."
                                                       "One day, you find that the light of the five-colored spiritual stone is flashing, which means the energy almost run out!"
                                                       "You searched a lot of books for a solution and you've finally found a way. It is recorded in one of the books that every 500 years, the energy of the five-color stone will weaken, "
                                                       "and it is necessary to gather all the elements of gold, wood, water, fire, and earth to reactivate the energy source. "
                                                       "You will be ready to embark on a fantastic adventure. Check out the info to before starting the game.<(￣︶￣)↗ Let's starrrt!!!!");
}


void MainWindow::on_infoBtn_clicked()
{
   //convert string to QString to met the infomation method
   QString qstr = QString::fromStdString(zorker->ZorkUL::printHelp());
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
    zorker ->moveCounter(stay);
    string move = to_string(zorker ->getMove());

    ui->moveLb ->setText("MOVE: " + toQstr(move));


}






void MainWindow::on_northBtn_clicked()
{

    QString s = toQstr( zorker ->go("north"));

    ui -> output ->setText(s);

    QPixmap pix1(toQstr(zorker ->getPic()));
    ui -> imgLb -> setPixmap(pix1);

    counter();
    hasTakeBtn(s);

   checkWordleQuizz();

   randChoice(ui->northBtn,s);

}


void MainWindow::on_eastBtn_clicked()
{
    QString s = toQstr( zorker ->go("east"));

    ui -> output ->setText(s);

    QPixmap pix1(toQstr(zorker ->getPic()));
    ui -> imgLb -> setPixmap(pix1);

    counter();
    hasTakeBtn(s);

    checkWordleQuizz();
    randChoice(ui->eastBtn,s);



}



void MainWindow::on_west_clicked()
{
    QString s = toQstr( zorker ->go("west"));

    ui -> output ->setText(s);

    QPixmap pix1(toQstr(zorker ->getPic()));
    ui -> imgLb -> setPixmap(pix1);

    counter();
    hasTakeBtn(s);
    checkWordleQuizz();
randChoice(ui->west,s);
}





void MainWindow::on_southBtn_clicked()
{
    QString s = toQstr(zorker ->go("south"));


    ui -> output ->setText(s);

    QPixmap pix1(toQstr(zorker ->getPic()));
    ui -> imgLb -> setPixmap(pix1);
    counter();
    hasTakeBtn(s);
    checkWordleQuizz();

     randChoice(ui->southBtn,s);

}





void MainWindow::on_teleportBtn_clicked()
{
    QString s = toQstr("Zfffffft transfer completed.~~~\n\nCurrent Location:\n"  + zorker -> teleport());

    ui -> output ->setText(s);

    QPixmap pix1(toQstr(zorker ->getPic()));
    ui -> imgLb -> setPixmap(pix1);
    counter();
    hasTakeBtn(s);
    checkWordleQuizz();

    randChoice(ui->teleportBtn,toQstr("no end output"));


}




void MainWindow::hasTakeBtn(QString qs){

ui -> listWidget ->clear();
    if(zorker ->hasItems()){

        if(zorker->hasItems() && zorker->getCurrentRoom()->shortDescription() == "Sky City"){
              ui -> collectBtn -> setEnabled(false);
        }else{

        ui ->collectBtn->setEnabled(true);
        listItem();

    }
    }else {
        ui -> collectBtn -> setEnabled(false);

    }

    if(qs == toQstr("*****Invalid direction,try different ways!*****")){
        ui->listWidget -> clear();
    }
}


void MainWindow::listItem(){


    int itemsize = zorker -> getCurrentRoom()->getItemSize();
    for(int i = 0 ; i < itemsize; i++){
        QString itemlist = toQstr(zorker ->showItems(i));
        ui -> listWidget ->addItem(itemlist);


    }

}

void MainWindow::collectItems(){

    int rowOfItems = ui -> listWidget ->currentRow();

    QListWidgetItem *it = ui ->listWidget->takeItem(rowOfItems);  //get the selected item in list


    string foundItem = zorker->getCurrentRoom()->searchItem(rowOfItems);       //search matching item in room
 showElement(foundItem);

    zorker->addItems(foundItem,*zorker ->getCurrentRoom());      //add item in player's bag





    zorker ->getCurrentRoom() ->removeItemFromRoom(rowOfItems);   //remove the item in room

    //details:
    string currItemDetail = zorker -> getCurrentRoom() ->longDescription();
    ui->output->append("----------------------------------------");
    ui ->output -> append(toQstr("\n" + currItemDetail));
    showItemsInBag();


    delete it;    //it won't delete the object itself


}




void MainWindow::showElement(string itemN){
    string imgP = zorker->getCurrentRoom()->getItemImage(itemN);

    if(itemN == "Magical Potion"){

       // ui->element1 ->setText(toQstr(itemN));
         ui -> element1 -> setPixmap(toQstr(imgP));

         if(zorker->getPotion() == 0){
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

    int value = zorker->getPotion();
    setProgressValue(ui->collectBtn,value);

}

void MainWindow::showItemsInBag(){
     ui -> output -> append(toQstr(zorker ->getLongDescription()));
}

void MainWindow::on_bag_clicked()

{
    showItemsInBag();

}


void MainWindow::checkWordleQuizz(){

    if(zorker ->getCurrentRoom()->shortDescription() == "Sky City"){
        if(zorker->getNumItemInBag() != 0){

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
        zorker->setPotion(10);
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
    int step = zorker->getMove();
    string roomName = zorker -> getCurrentRoom()->shortDescription();

    if(zorker->getPotion() != 0 && ui->progressBar ->value() != 100){
        if(step % 3 == 0 && roomName == "Mysterious Wood" ){
            if(ui->progressBar ->value() > 10){
            zorker ->takePotion(1);
            int potionValue = zorker->getPotion();
            setProgressValue(button,potionValue);

            ui->imgLb ->setPixmap(toQstr(":/resources/img/troll_attack.png"));

            if(directionOut != toQstr("*****Invalid direction,try different ways!*****")){

              QMessageBox::information(this, "ALERT!!", "Troll is trying to take all your potion in Mysterious Wood. \n(Magical Potion -1)");
            }
           }

        }else if(step % 4 == 0 && roomName == "Mysterious Wood"){

             if(directionOut != toQstr("*****Invalid direction,try different ways!*****")){

                 ui->imgLb ->setPixmap(toQstr(":/resources/img/Mystery_Witch.png"));
            QMessageBox::information(this, "The witch has flown by.", "You saw a witch has flown by and droped two magical potion. \n(Magical Potion +2)");

            zorker ->addPotion(2);

            int potionValue = zorker->getPotion();
            setProgressValue(button,potionValue);




   }

        }else if(step % 4 == 0 && roomName == "Cliff"){
            if(ui->progressBar ->value() > 20){
            ui->imgLb ->setPixmap(toQstr(":/resources/img/dropping_potion.png"));

             if(directionOut != toQstr("*****Invalid direction,try different ways!*****")){
            QMessageBox::information(this, "Cliff", "Opps,You almost fell off a cliff and lost two magical potion. \n(Magic Potion -2)");


            zorker ->takePotion(2);

            int potionValue = zorker->getPotion();
            setProgressValue(button,potionValue);
            }
            }
        }else if(step % 3 == 0 && roomName == "Cliff"){


                if(ui->progressBar ->value() > 20){
                    ui->imgLb ->setPixmap(toQstr(":/resources/img/soldier.png"));

                    if(directionOut != toQstr("*****Invalid direction,try different ways!*****")){
                        if(num == 0){
                            //set question
                             setQuestion();
                             num ++;
                         }else if(num == 1){
                        QMessageBox::information(this, "A Soldier", "You have a great chat with the soldier. \n(Magic Potion +1)");


                        zorker ->addPotion(1);

                        int potionValue = zorker->getPotion();
                        setProgressValue(button,potionValue);
                        }
                    }
               }

           }


        }
     }





void MainWindow::setQuestion(){

    int sum1 = division<int>(1578,2);
    float sum2 = division<float>(20.274,3.1);
    float sum3 = division<float>(22.149,6.9);



    QString quest = toQstr("There are some secret information in this paper,it would be great if you could help him to figure it out!\n\n");
    QString quest1 = toQstr("  1. 1578 / 2 = ***  \n  2. 20.274 / 3.1 = ***\n  3. 22.149 / 6.9 = ***");
    quest += quest1;
    string yesAns = to_string(sum1) + "-" + to_string(sum2 ) + "-" + to_string(sum3);

    QMessageBox msgBox;
    msgBox.setWindowTitle("A soldier");
    msgBox.setInformativeText(quest);


    QAbstractButton *yesBtn = msgBox.addButton(toQstr(yesAns),QMessageBox::YesRole);
    QAbstractButton *noBtn = msgBox.addButton("987-6.4500000-3.1100000",QMessageBox::NoRole);


    msgBox.exec();

    if(msgBox.clickedButton() == yesBtn) {

        QPushButton *btn = new QPushButton(yesBtn);

        zorker->addPotion(3);

        int potionValue = zorker->getPotion();


        setProgressValue(btn,potionValue);
        delete btn;
        QMessageBox::information(this,"Well done!","Great! You find a secret number for soldier and he gave you 3 potions. (Magical potion +3");


    }else if(msgBox.clickedButton() == noBtn){

        zorker->takePotion(1);
        int potionValue = zorker->getPotion();
        QPushButton *btn = new QPushButton(noBtn);

        setProgressValue(btn,potionValue);
        delete btn;
        QMessageBox::information(this,"Run Away spell","You can't help the soldier and he is a bit angry, you used a spirit stone to activate the fly away spell.");

   }

}




bool MainWindow::wonGame(){
   int progressValue = ui->progressBar ->value();
   int bagItems = zorker->getNumItemInBag();

   if(progressValue == 100 && bagItems == 6){
       ui->progressBar->setStyleSheet("QProgressBar::chunk{background-color: cyan;} QProgressBar {color: blue; font:bold}");

        zorker->getCurrentRoom()->addItem(new Item(zorker->givePotion()));

       listItem();

        zorker->removeItemsInBag("Magical Potion");
       QMessageBox::information(this,"!!!!  GREAT JOB  !!!!", "Hoooray!!, you save the land of the Loswilire and you are the master of power guardiance of this land.\n\n ******  MISSION FINISHED  ******");
        return true;
   }
   return false;
}

template<class T>
T MainWindow::division(T a, T b){    //template function
    T sum;
    sum = a / b;
    return sum;
}





