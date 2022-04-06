#include "wordle.h"
#include "time.h"
#include <stdlib.h>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDebug>



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
    guessWord = possibleWords.at(in);
}

/** get the guess word */
string wordle::getGuessWord(){
    return guessWord;
}

/**get the attempted word */
string wordle::getAttemptWord(){
      return attemptWord;
}


/** check if the word valid from specific file(words you store in vector) the system provided */
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

/** make all letter lowercase*/
string wordle::toLower(string word){
  int n = word.length();

  for(int i = 0; i < n; i++){
     word[i] = tolower(word[i]);
  }
  return word;
}

/**check if the word match the guess word*/
bool wordle::winGame(string word){

  word = toLower(word);

  if(word == guessWord){
     return true;
   }
  return false;

  }

/** set the Game*/
string wordle::setGame(){
 listOfWords();
 setGuessWord();

  string welcome = "Welcome to wordle world challenge! What will be the magic word of the day????" ;

  return welcome;
  }


/**check a word you guessed if matching the guess word*/
void wordle::checkWord(string word){

   attemptWord = "xxxxx";                   //x = blue color

    if(word == guessWord){
        attemptWord ="ggggg";

    }else{

        for(int i = 0; i < 5; i++){

            if(guessWord[i] == word[i]){    //correct letter in right place

                attemptWord[i] = 'g';   //g = green color

            }else{

                for(int j = 0; j < 5; j++){
                    if(guessWord[i] == word[j]){    //if letters exist in the guess word.

                        attemptWord[j] = 'y';   //y = yellow color

                    }
                }
            }

        }
    }
}
