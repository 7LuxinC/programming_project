#include "Character.h"
#include <vector>


Character::Character(int move):move(move){  //initialise list
        potion = 0;
}

Character::~Character(){

}

 int Character::getMove(){

    return move;
}

inline void Character::getMoving(){
    move = move + 1;
}




string Character::getWelcome(){
    string wel = printWelcome();
    return wel;
}

 void Character::moveCounter(string noLoc){

   if(noLoc != "*****Invalid direction,try different ways!*****"){
       getMoving();
    }
}


int Character::getPotion(){


    vector<Item>::iterator it;
    for(it = itemInBag.begin(); it != itemInBag.end(); it++){
        if(it->getShortDescription() == "Magical Potion"){
            potion = it->getPotion();

            return potion;

        }
    }
        return potion;
}


int Character::setPotion(int value){
    vector<Item>::iterator it;
    for(it = itemInBag.begin(); it != itemInBag.end(); it++){
        if(it->getShortDescription() == "Magical Potion"){
            potion  = value;

            return potion;

        }
    }
        return potion;

}


Item Character::givePotion(){
    Item item;
    int i = 0;
    vector<Item>::iterator it;
    for(it = itemInBag.begin(); it != itemInBag.end(); it++,i++){
        if(it->getShortDescription() == "Magical Potion"){
           item = itemInBag.at(i);    //copy constructor

        }
    }
     return item;
}



int Character::takePotion(int value){
    vector<Item>::iterator it;
    for(it = itemInBag.begin(); it != itemInBag.end(); it++){
        if(it->getShortDescription() == "Magical Potion"){
            it->setPotion(potion - value);

            return potion;

        }
    }
        return potion;

}

void Character::removeItemsInBag(string name){
    vector<Item>::iterator it;
    for(it = itemInBag.begin(); it != itemInBag.end(); it++){
        if(it->getShortDescription() == name){
            itemInBag.erase(it);
         }
    }

}

int Character::addPotion(int value){
    vector<Item>::iterator it;
    for(it = itemInBag.begin(); it != itemInBag.end(); it++){
        if(it->getShortDescription() == "Magical Potion"){
           it->setPotion(potion + value);
           return potion;



        }
    }
        return potion;
}




int Character::getNumItemInBag(){
    return itemInBag.size();
}

void Character::addItems(string description,Room& room) {




    for(int i = 0; i < room.getItemSize(); i++){

        string roomItemN = room.itemsInRoom.at(i).getShortDescription();


        if(roomItemN == description){
             itemInBag.push_back(room.itemsInRoom.at(i));


            for(int j = 0; j < getNumItemInBag() - 1; j++){
               if(itemInBag.at(j).getShortDescription() == roomItemN){
                   itemInBag.at(j) = itemInBag.at(j) + room.itemsInRoom.at(i);
                   itemInBag.pop_back();
               }
           }
        }

   }
}

Item operator + (Item& item1,Item& item2){
    return Item(item1.getShortDescription(),item1.getPotion()+item2.getPotion(),item1.getImagePath());

}


string Character::getShortDescription(){
    return this->description;
}


string Character::getLongDescription()
{
  string ret = this->description;
  ret += "\n ****** Item in your Bag ******\n";




  for (int i = 0; i < getNumItemInBag(); i++){

      if(itemInBag.at(i).getShortDescription() == "Magical Potion"){
          ret += "\t"+ itemInBag.at(i).getShortDescription() + " x"+ to_string( itemInBag.at(i).getPotion()) + "\n";
      }else{

    ret += "\t"+ itemInBag.at(i).getShortDescription()  + "\n";
      }
  }
  return ret;
}



