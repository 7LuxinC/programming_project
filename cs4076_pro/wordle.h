#ifndef WORDLE_H
#define WORDLE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <time.h>
#include <string>
//#include <cctype>

using namespace std;

#define MAX 2000

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
      string setAttemptWord(string word);
       string getAttemptWord();



#endif // WORDLE_H

};
