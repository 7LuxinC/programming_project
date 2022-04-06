#ifndef CHARACTER_H_
#define CHARACTER_H_


#include <string>
#include <vector>
#include "Room.h"
#include "ZorkUL.h"

using namespace std;
using std::vector;


class Character :public ZorkUL {                                    //inheritance

private:
    int move;
     string description;
     vector<Item> itemInBag;
     int potion;

public:
    virtual ~Character();
    void addItems(string description,Room& room);              // room parameter is passed by refernce
    Character(int move = 0);                                 //default parameter in constructor
    string getShortDescription();
    string getLongDescription();
    void getMoving();
    int getMove();
    int getPotion();
    void moveCounter(string noLoc);
    Item operator+(Item& item1);
    int getNumItemInBag();
    int setPotion(int value);
    int takePotion(int value);
    int addPotion(int value);
    void removeItemsInBag(string name);
    string getWelcome();
    Item givePotion();

};

#endif /*CHARACTER_H_*/
