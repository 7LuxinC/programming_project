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


}

WordleDialog::~WordleDialog()
{
    delete ui;
}





void WordleDialog::on_lineEdit_returnPressed()
{



    QString textInLine = ui ->lineEdit->text();


        ui -> opText ->append("You Entered:  " + textInLine);
        ui->lineEdit ->clear();

        ui ->typedWords ->append(textInLine);

        counter++;

        if(counter == max){
            ui ->lineEdit->setEnabled(false);
            QMessageBox::information(this," Challenge Ended ", "Challenge is ended,you cannot fill up or activate the magic potion. Try next time.");

        }


}





void WordleDialog::on_pushButton_clicked()
{
    QString qstr = QString::fromStdString("Wordle is simple: You have six chances to guess the day's secret five-letter word. Type in a word as a guess, and the game tells you which letters are or aren't in the word. The aim is to figure out the secret word with the fewest guesses."
                                          "If player won the game, the magic potion get activate or fill up. If you lost, you cannot use potion to activate the power of 5-colours sprite stone");
    QMessageBox::information(this," Wordle ", qstr);

}

