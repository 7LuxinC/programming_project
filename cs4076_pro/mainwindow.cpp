#include<iostream>
#include <string>
#include <QString>
#include <QtDebug>
#include <QPixmap>
#include <QProgressBar>
#include<QMessageBox>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ZorkUL.h"
#include "Character.h"

int num = 0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //set properties of the mainwindow.
    setWindowIcon(QIcon(":/resources/img/Loswilire.ico"));
    ui ->groupBox ->setStyleSheet("QGroupBox {color: lightblue; font:bold}");
    ui->potionLb->setStyleSheet("QLabel {color: white; font:bold}");
    ui->moveLb ->setStyleSheet("QLabel {color:white; font:bold}");
    ui->progressBar->setStyleSheet("QProgressBar::chunk{background-color: lightgreen;} QProgressBar {color: blue; font:bold}");
    ui->potionLb ->setText("MAGICAL POTION:");

    //upload map picture in the mainwindow screen
    QPixmap pix(":/resources/img/map.png");
    ui -> mapImg -> setPixmap(pix);   //mapImg = label


    //creat a player object
    zorker = new Character();
    QString qstr = QString::fromStdString(zorker ->getWelcome());
    ui ->output -> setText(qstr);                                             //print welcome message

    ui->moveLb ->setText("MOVE: " + toQstr(to_string(zorker->getMove())));


    QPixmap pix1(toQstr(zorker ->getPic()));        //get current room picture
    ui -> imgLb -> setPixmap(pix1);

    listItem();                                     //show items in the list
    ui ->activation ->setEnabled(false);            //disable activation button from the start

}



MainWindow::~MainWindow()
{
    delete ui;
    ZorkUL *zork = zorker;         //assigned character obj pointer to base class obj pointer
    delete zork;


}



//change any string to Qstring
QString MainWindow::toQstr(string str){
    QString toQstr = QString::fromStdString(str);
    return toQstr;
}


//welcom message
void MainWindow::on_messageBtn_clicked()
{
    //this =this class
    QMessageBox::about(this,"---WELCOME ヾ(*´▽‘*)ﾉ---", "You are now standing in the land of Loswilire and you are the new guardiance the five-colored spiritual stones to take if they have enough power to prevent any enemy come to this land.\n\n"
                                                       "One day, you find that the light of the five-colored spiritual stone is flashing, which means the energy almost run out!\n\n"
                                                       "You searched a lot of books for a solution and you've finally found a way. It is recorded in one of the books that every 500 years, the energy of the five-color stone will weaken, "
                                                       "and it is necessary to gather all the elements of gold, wood, water, fire, and earth to reactivate the energy source.\n\n"
                                                       "You will be ready to embark on a fantastic adventure. Check out the info to before starting the game.\n\n"
                                                       "Before transfer magical energy, you have to activate magical potion in sky city."
                                                       "To transfer the magical energy to the 5-colored spirtual stone,you have to collect 5 element and get 100% of power energy in magic potions.\n\n"
                                                       "<(￣︶￣)↗ Let's starrrt!!!!\n\n");
}


//information = help
void MainWindow::on_infoBtn_clicked()
{
   //convert string to QString to met the infomation method
   QString qstr = QString::fromStdString(zorker->printHelp());
   QMessageBox::information(this,"Information",qstr);

}


//quit the program
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


//counter the number of steps you move
void MainWindow::counter(){

    string stay = ui->output->toPlainText().toStdString();     //if the output= no room available ,move won't be counted
    zorker ->moveCounter(stay);
    string move = to_string(zorker ->getMove());               //show the number of moves

    ui->moveLb ->setText("MOVE: " + toQstr(move));

}



void MainWindow::on_northBtn_clicked()
{

    QString s = toQstr( zorker ->go("north"));

    ui -> output ->setText(s);                                  //print room infos

    QPixmap pix1(toQstr(zorker ->getPic()));                    //room pic
    ui -> imgLb -> setPixmap(pix1);

    counter();                                                  //moves counter
    hasTakeBtn(s);                                              //check the item if you have take aways or not
    checkWordleQuizz();                                         //if the location is sky city ,enable wordle
    randChoice(ui->northBtn,s);                                 //connect energy bar to set value of potions

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

    ui -> output ->setText(s);                            //room infos

    QPixmap pix1(toQstr(zorker ->getPic()));                //room pic
    ui -> imgLb -> setPixmap(pix1);
    counter();
    hasTakeBtn(s);
    checkWordleQuizz();

    randChoice(ui->teleportBtn,toQstr("no end output"));
}



void MainWindow::hasTakeBtn(QString qs){

    ui -> listWidget ->clear();                       //delete the all items in the list

    if(zorker ->hasItems()){                           //show the current room items

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

    int itemsize = zorker -> getCurrentRoom()->getItemSize();           //get no. of items in room
    for(int i = 0 ; i < itemsize; i++){
        QString itemlist = toQstr(zorker ->showItems(i));
        ui -> listWidget ->addItem(itemlist);                           //add them to the list box
    }

}



void MainWindow::collectItems(){

    int rowOfItems = ui -> listWidget ->currentRow();               //get currentrow index in the list

    QListWidgetItem *it = ui ->listWidget->takeItem(rowOfItems);  //--assign the specific item  from the list to the list item in order to delte it in list


    string foundItem = zorker->getCurrentRoom()->getItem(rowOfItems);       //search matching item in room
 showElement(foundItem);

    zorker->addItems(foundItem,*zorker ->getCurrentRoom());      //add item in player's bag

    zorker ->getCurrentRoom() ->removeItemFromRoom(rowOfItems);   //remove the item in room

    //details:
    string currItemDetail = zorker -> getCurrentRoom() ->longDescription();                     //updates room and item details
    ui->output->append("----------------------------------------");
    ui ->output -> append(toQstr("\n" + currItemDetail));
    showItemsInBag();                                                                           //updat ebags items


    delete it;    //it won't delete the object itself     //delete the item in the list not the room object


}




void MainWindow::showElement(string itemN){
    string imgP = zorker->getCurrentRoom()->getItemImage(itemN);                        //get room pic

    if(itemN == "Magical Potion"){                                                      //get element picture in the groupbox gui

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
    setProgressValue(ui->collectBtn,value);                             //update progress bar
}


void MainWindow::showItemsInBag(){                                      //items in bags info
     ui -> output -> append(toQstr(zorker ->getLongDescription()));
}


void MainWindow::on_bag_clicked()                                           //items in bags info

{
    showItemsInBag();

}


void MainWindow::checkWordleQuizz(){                                        //enable /diable wordle challenge

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


    wordleDialog = new WordleDialog();                          //enable wordle quizz
    wordleDialog->exec();


    if(wordleDialog ->winGame()){                     //update 100%  to your progress bar if player guessed the correct word in wordle challenge
         setProgressValue(ui->activation,10);
        zorker->setPotion(10);
    }

     delete wordleDialog;                           //deallocate

    }



}


void MainWindow::setProgressValue(QPushButton *button,int value){                       //update progress bar

    if(ui->progressBar->value() != 100){
        connect(button,SIGNAL(click(bool)),ui->progressBar,SLOT(reset(bool)));                //connect button to progressbar

        if(value > 10){
        ui->progressBar->setValue(100);
        }

        ui->progressBar ->setValue(value * 10);
    }
}


void MainWindow::randChoice(QPushButton *button,QString directionOut){
    int step = zorker->getMove();
    string roomName = zorker -> getCurrentRoom()->shortDescription();

     //specific moves steps will provide player potion or take away
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
                        if(num == 0){                           //this question will show only once in the game (will add 3 potion)
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

       zorker->getCurrentRoom()->addItem(new Item(zorker->givePotion()));           //give potion to the sky city

       listItem();

        zorker->removeItemsInBag("Magical Potion");                     //remove potion in ur bag(give all of them to the sky for activate)
       QMessageBox::information(this,"!!!!  GREAT JOB  !!!!", "╭(○｀∀´○)╯╰(○'◡'○)╮ (○'◡'○)ﾉヾ(*´▽'*)\n\nHoooray!!!\n\nYou save the land of the Loswilire and you are the master of power guardiance of this land.\n\n ******  MISSION FINISHED  ******");
        return true;
   }
   return false;
}



template<class T>
T MainWindow::division(T a, T b){          //template function
    T sum;
    sum = a / b;
    return sum;
}





