#include "Character.h"
#include <vector>

Character::Character(string description) {
	this->description = description;
}


void Character::addItems(Item *item) {

    itemsInCharacter.push_back(item->getShortDescription());
    delete item;
}

string Character::getShortDescription(){
    return this -> description;
}


string Character::getLongDescription()
{
  string ret = this->description;
  ret += "\n Item list:\n";

  int itemSize = itemsInCharacter.size();
  string i = "";

  for (int i = 0; i < itemSize; i++){

    ret += "\t"+ itemsInCharacter.at(i) + "\n";
  }
  return ret;
}



