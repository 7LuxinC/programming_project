#include "wordle.h"
#include "time.h"
#include <stdlib.h>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDebug>


using namespace std;

wordle::wordle(){

}
/** store word in the vector*/
void wordle::listOfWords(){
  string line;

  QFile file(":/resources/word_list.txt");


  try{
      file.open(QFile::ReadOnly|QFile::Text);
      QTextStream in(&file);

      while(!in.atEnd()){
          QString line = in.readLine();

          string l = line.toStdString();
          possibleWords.push_back(l);
   }

  }catch(std::exception& e){
      qDebug() << "File is not open";
  }


  file.close();


}

/** set a guess-word for player to guess*/
  void wordle::setGuessWord(){
    int size;
    srand(time(0));

    size = possibleWords.size();
    int in = rand() % size ;
    guessWord = possibleWords.at(in );
  }

/** get the guess word */
  string wordle::getGuessWord(){
    return guessWord;
  }

  string wordle::setAttemptWord(string word){
      this->attemptWord = word;
      return attemptWord;
  }


  string wordle::getAttemptWord(){


      return attemptWord;
  }


bool wordle::validWord(string word){
  if(word.length() != 5){
    return false;
  }
word  = toLower(word);

  for(int i = 0; i < MAX; i++){
    if(possibleWords.at(i) == word){  //check the word you typed if it existed in the wordfile list
      return true;
    }
  }
  return false;
}

string wordle::toLower(string word){
  int n = word.length();

  for(int i = 0; i < n; i++){
     word[i] = tolower(word[i]);
  }
  return word;
}


bool wordle::winGame(string word){

  word = toLower(word);

  if(word == guessWord){
     return true;
   }
  return false;

  }

string wordle::setGame(){
 listOfWords();
 setGuessWord();

  string welcome = "Welcome to wordle world challenge! What will be the magic word of the day????" ;

  return welcome;
  }


void wordle::checkWord(string word){

   setAttemptWord(word);

  for(int i = 0; i < 5; i++){
      bool wrongPlace = false;
      bool rightPlace = false;
    if(guessWord[i] == word[i]){    //correct letter in right place

      attemptWord[i] = 'g';   //g = green color
      rightPlace = true;

    }else{

      for(int in = 0; in < 5; in++){
        if(word[i] == guessWord[in]){   //correct letter in wrong place

            wrongPlace = true;//y = yellow color
        }
      }

      if(wrongPlace == true){
        attemptWord[i]= 'y';
      }
    }
if(wrongPlace == false && rightPlace == false){
      attemptWord[i] = 'x';    //x = no color    // irrelevant letter
    }
 }


}
