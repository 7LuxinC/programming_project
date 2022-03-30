#include "time.h"
#include <stdlib.h>
#include <string>


/** store word in the vector*/
void wordle::listOfWords(string filename){
  string line;

  ifstream file(filename);

  if(file.is_open()){

    while(getline(file,line)){
      possibleWords.push_back(line);
    }
  }

  file.close();
}

/** set a guess-word for player to guess*/
  void Wordle::setGuessWord(){
    int size,i;
    srand(time(0));

    size = 1;
    i = rand() % size;
    guessWord = possibleWords.at(i);
  }

/** get the guess word */
  string getGuessWord(){
    return guessWord;
  }


bool validWord(string word){
  if(word.length() != 5){
    return false;
  }
word  = toLower(word);

  for(int i = 0; i < MAX; i++){
    if(possibleWords.at(i) == word){
      return true;
    }
  }
  return false;
}

string toLower(string word){
  int n = word.length();

  for(int i = 0; i < n; i++){
     word[i] = tolower(word[i]);
  }
  return word;
}


bool winGame(string word){

  word = toLower(word);

  if(word == guessWord){
     return true;
   }

  return false;

  }

string setGame(){
  listOfWords("words.txt");
  setGuessWord();

  string welcome = "Welcome to wordle world challenge! What will be the magic word of the day????" ;

  return welcome;
  }

void checkWord(string word){
  bool correctP = false, wrongP = false;

  for(int i = 0; i < 5; i++){
    if(guessWords[i] == word[i]){
      correctP = true;
      attemptWord[i] = "g";   //g = green color
    }else{

      for(int in = 0; in < 5; in++){
        if(word[i] == guessWord[in]){
          wrongP = true;
          attemptWord[in] = "y";    //y = yellow color
        }
      }

    }

    if(rightP = false && wrongP == false){
      attemptWord[i] = "x";    //x = no color
    }

  }

}

