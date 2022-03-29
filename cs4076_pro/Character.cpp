#include "Character.h"
#include <vector>

Character::Character() {

}


void Character::addItems(string description) {

//    this->description = description;

    itemsInCharacter.push_back(description);

}

string Character::getShortDescription(){
    return this -> description;
}


string Character::getLongDescription()
{
  string ret = this->description;
  ret += "\n *** Item in your Bag ***\n";

  int itemSize = itemsInCharacter.size();
  string i = "";

  for (int i = 0; i < itemSize; i++){

    ret += "\t"+ itemsInCharacter.at(i) + "\n";
  }
  return ret;
}



