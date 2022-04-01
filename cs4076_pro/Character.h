#ifndef CHARACTER_H_
#define CHARACTER_H_


#include <string>
using namespace std;
#include <vector>
using std::vector;
#include "Room.h"


class Character {
private:
    int move;

     string description;

     vector<Item> itemInBag;
public:
    void addItems(string description,Room& room);
    Character(int move = 0);    //default parameter in constructor
    string getShortDescription();
    string getLongDescription();
     void getMoving();
   string getMove();
    int getPotion();
    void moveCounter(string noLoc);
    Item operator+(Item& item1);
    int getNumItemInBag();

};

#endif /*CHARACTER_H_*/
