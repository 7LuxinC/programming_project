#include "Character.h"
#include <vector>


Character::Character(int move,int potion):move(move),potion(potion){  //initialise list

}

 string Character::getMove(){

    return to_string(move);
}

inline void Character::getMoving(){
    move = move + 1;
}

 void Character::moveCounter(string noLoc){

   if(noLoc != "*****Invalid direction,try different ways!*****"){
       getMoving();
    }
}


int Character::getPotion(){
    return potion;
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



