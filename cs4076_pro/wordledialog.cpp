#include "wordledialog.h"
#include "ui_wordledialog.h"
#include <QMessageBox>
#include <string>
#include<QString>

using namespace std;



int counter = 0;




WordleDialog::WordleDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WordleDialog)
{
    ui->setupUi(this);

    wordleGame = new wordle();

   QString welcomeMes =QString::fromStdString(wordleGame ->setGame());
   ui ->opText ->setText(welcomeMes);

}

WordleDialog::~WordleDialog()
{
    delete ui;
    delete wordleGame;
}





void WordleDialog::on_lineEdit_returnPressed()
{


    QString textInLine = ui ->lineEdit->text();    //text yo typed in the Leditor
    string word = ui -> lineEdit -> text().toStdString();

    ui -> opText ->append("You Entered -->  " + textInLine );

    if(wordleGame -> winGame(word) == true ){
       QString congrat = QString::fromStdString("Congratulations!!! You win! You guess the magic word!! You can activate your magic potion for your spirit stone! Go back to the castle in the mainLand to transfer the power to the spirit stone! Good Luck!!!");
        QMessageBox::information(this,"****CONGRATULATION****", congrat);
   }

    if(wordleGame->validWord(word) == false){
        QString mess = QString::fromStdString("Word is not recognise Please try another 5-letters words\n");
        ui -> opText -> append(mess);


    }


    if(wordleGame->validWord(word)== true){


      wordleGame ->checkWord(word);
        wordWithColor(word);

        counter++;

        if(wordleGame->validWord(word)== true && counter == max){
            counter--;
            ui ->lineEdit->setEnabled(false);
        }
    }





        //counter for number of trial

     if(counter == max){
         ui ->lineEdit->setEnabled(false);
         QString correctWord = QString::fromStdString(wordleGame->getGuessWord());
         QMessageBox::information(this," Challenge Ended ", "Challenge is ended,you cannot fill up or activate the magic potion. \n The magic word is  \n\t !!  " + correctWord + "  !! \n >>>> Try next time. <<<<");

     }
 ui->lineEdit ->clear();

}


void WordleDialog::wordWithColor(string word){

    string colorWord = wordleGame->getAttemptWord();



 for(int i = 0; i < 5; i++){

        if(colorWord[i] == 'g'){


            ui -> typedWords -> setTextColor(Qt::green);
            QString str = QString(word[i]);     //change char to qstring
            ui ->typedWords -> insertPlainText(str);
            ui->typedWords ->moveCursor(QTextCursor::End);


        }else if(colorWord[i] == 'y'){

            ui -> typedWords -> setTextColor(Qt::yellow);
            QString str = QString(word[i]);   //change char to qstring
            ui ->typedWords -> insertPlainText(str);
            ui->typedWords ->moveCursor(QTextCursor::End);

        }else if(colorWord[i] == 'x'){

            ui -> typedWords -> setTextColor(Qt::blue);
            QString str = QString(word[i]);   //change char to qstring
            ui ->typedWords -> insertPlainText(str);
            ui->typedWords ->moveCursor(QTextCursor::End);

        }


    }
 ui->typedWords ->append("");

}





void WordleDialog::on_pushButton_clicked()
{
    QString qstr = QString::fromStdString("Wordle is simple: You have six chances to guess the day's secret five-letter word. Type in a word as a guess, and the game tells you which letters are or aren't in the word.\n\nBlue Color: A letter which is not in the guess word.\nYellow Color: A letter which is in the word somewhere. \n Green Color: Letter is in the guess word and also in the right position.\n\nThe aim is to figure out the secret word with the fewest guesses."
                                          "If player won the game, the magic potion get activate or fill up. If you lost, you cannot use potion to activate the power of 5-colours sprite stone");
    QMessageBox::information(this," Wordle ", qstr);

}



