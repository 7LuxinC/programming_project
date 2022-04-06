#ifndef WORDLE_H
#define WORDLE_H

#include <iostream>
#include <vector>
#include <time.h>
#include <string>

using namespace std;

#define MAX 1000

class wordle{

 private:
      vector <string> possibleWords;
      string filename;


  public:
      wordle();
      string guessWord;
      string attemptWord;

      void listOfWords();
      void setGuessWord();
       string getGuessWord();
       bool validWord(string word);
       string toLower(string word);
       bool winGame(string word);
       string setGame();
       void checkWord(string word);
       string getAttemptWord();



#endif // WORDLE_H

};
