#ifndef CHARACTER_H_
#define CHARACTER_H_
#include "ZorkUL.h"

#include <string>
using namespace std;
#include <vector>
using std::vector;


class Character {
private:
	string description;
     vector <string> itemsInCharacter;
public:
    void addItems(Item *Item);




public:
	Character(string description);
    string getShortDescription();
    string getLongDescription();

};

#endif /*CHARACTER_H_*/
