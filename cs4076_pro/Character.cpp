#include "Character.h"
#include <vector>


/**
 *operator + : add two item together
 **/
Item operator + (Item& item1,Item& item2){                               //...overloading operator
    return Item(item1.getShortDescription(),item1.getPotion()+item2.getPotion(),item1.getImagePath());
}


/**
 * create a character constructor and initialise move and potion
 * @param move
 */
Character::Character(int move):move(move){   //...initialise list
      potion = 0;
}


/**
 * @brief deconstruct character
 */
Character::~Character(){
}

/**
 * @brief Character::getMove
 *
 */
int Character::getMove(){
    return move;
}

/**
 * @brief every steps count as one
 */
inline void Character::getMoving(){                //...inline function
    move = move + 1;
}

/**
 * @brief access protected function through ZorkUL base class
 * @return wel
 */
string Character::getWelcome(){
    string wel = printWelcome();
    return wel;
}

/**
 * @brief Character::moveCounter count the how many steps player have moved
 * @param noLoc
 */
void Character::moveCounter(string noLoc){

   if(noLoc != "*****Invalid direction,try different ways!*****"){
       getMoving();
   }
}

/**
 * @brief Character::getPotion  get number of potion in player's bags,if none return 0
 * @return potion
 */
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


/**
 * @brief Character::setPotion set number of potion in character's bags
 * @param value
 * @return potion
 */
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


/**
 * @brief Character::givePotion  give the potions to the sky city helps you activate element's power
 * @return item
 */
Item Character::givePotion(){
    Item item;
    int i = 0;
    vector<Item>::iterator it;
    for(it = itemInBag.begin(); it != itemInBag.end(); it++,i++){
        if(it->getShortDescription() == "Magical Potion"){
           item = itemInBag.at(i);                                         //.....copy constructor
        }
    }
    return item;
}


/**
 * @brief Character::takePotion   take number of potions away from player's bag
 * @param value
 * @return potion
 */
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



/**
 * @brief Character::removeItemsInBag    take away a specific item in player's bag
 * @param name
 */
void Character::removeItemsInBag(string name){
    vector<Item>::iterator it;
    for(it = itemInBag.begin(); it != itemInBag.end(); it++){
        if(it->getShortDescription() == name){
            itemInBag.erase(it);
         }
    }
}


/**
 * @brief Character::addPotion  give number of potion to the player
 * @param value
 * @return potion
 */
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


/**
 * @brief Character::getNumItemInBag  get how many items in player's bag
 * @return itemInBag.size();
 */
int Character::getNumItemInBag(){
    return itemInBag.size();
}


/**
 * @brief Character::addItems
 * @param description
 * @param room
 */
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


/**
 * @brief Character::getShortDescription    return description
 * @return description
 */
string Character::getShortDescription(){
    return this->description;
}



/**
 * @brief Character::getLongDescription   get what items information in player's bags
 * @return  ret
 */
string Character::getLongDescription()
{
    string ret = this->description;
    ret += "\n ****** Item in your Bag ******\n";


    for(int i = 0; i < getNumItemInBag(); i++){

      if(itemInBag.at(i).getShortDescription() == "Magical Potion"){
        ret += "\t"+ itemInBag.at(i).getShortDescription() + " x"+ to_string( itemInBag.at(i).getPotion()) + "\n";
      }else{

        ret += "\t"+ itemInBag.at(i).getShortDescription()  + "\n";
      }
  }
  return ret;
}



