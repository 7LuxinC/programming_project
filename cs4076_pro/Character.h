#ifndef CHARACTER_H_
#define CHARACTER_H_


#include <string>
using namespace std;
#include <vector>
using std::vector;


class Character {
private:
    int move;
    int potion;
     string description;
     vector <string> itemsInCharacter;
public:
    void addItems(string description);
    Character(int move = 0, int potion = 0);    //default parameter in constructor
    string getShortDescription();
    string getLongDescription();
     void getMoving();
   string getMove();
    int getPotion();
    void moveCounter(string noLoc);

};

#endif /*CHARACTER_H_*/
