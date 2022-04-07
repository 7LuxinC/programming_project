#include <QPixmap>
#include "Room.h"
#include "Command.h"

/**
 * @brief Room::Room
 * @param description
 * @param imgPath
 */
Room::Room(string description,string imgPath) {
	this->description = description;
    this ->imgPath = imgPath;
}

/**
 * @brief Room::getImg
 * @return
 */
string Room::getImg(){
    return this->imgPath;
}


/**
 * @brief Room::getItemSize   number of items in room
 * @return
 */
int Room::getItemSize(){
    int sum = itemsInRoom.size();
    return sum;
}

/**
 * @brief Room::setExits  check if there is room in any direction
 * @param north
 * @param east
 * @param south
 * @param west
 */
void Room::setExits(Room *north, Room *east, Room *south, Room *west) {
	if (north != NULL)
		exits["north"] = north;
	if (east != NULL)
		exits["east"] = east;
	if (south != NULL)
		exits["south"] = south;
	if (west != NULL)
		exits["west"] = west;
}


/**
 * @brief Room::shortDescription   get room name
 * @return
 */
string Room::shortDescription() {
	return description;
}


/**
 * @brief Room::longDescription     current location and items in the room
 * @return
 */
string Room::longDescription() {
    return "Current location = " + description + ".\n" + displayItem() + exitString();
}


/**
 * @brief Room::exitString         show which direction is available for player to go to other rooms
 * @return
 */
string Room::exitString() {
	string returnString = "\nexits =";
	for (map<string, Room*>::iterator i = exits.begin(); i != exits.end(); i++)
		// Loop through map
		returnString += "  " + i->first;	// access the "first" element of the pair (direction as a string)
	return returnString;
}


/**
 * @brief Room::nextRoom        store direction and room ,if match the direction then player can go to next room
 * @param direction
 * @return
 */
Room* Room::nextRoom(string direction) {
	map<string, Room*>::iterator next = exits.find(direction); //returns an iterator for the "pair"
	if (next == exits.end())
		return NULL; // if exits.end() was returned, there's no room in that direction.
	return next->second; // If there is a room, remove the "second" (Room*)
				// part of the "pair" (<string, Room*>) and return it.
}


/**
 * @brief Room::addItem         add item in the room.
 * @param inItem
 */
void Room::addItem(Item *inItem) {
    itemsInRoom.push_back(*inItem);
}


/**
 * @brief Room::getItemImage     get specific item image
 * @param itemname
 * @return
 */
string Room::getItemImage(string itemname){
    for(int i = 0; i < getItemSize(); i++){
        if(itemsInRoom.at(i).getShortDescription() == itemname){
             return itemsInRoom.at(i).getImagePath();
        }
    }
    return "null";
}



/**
 * @brief Room::removeItemFromRoom   remove a specific item in room
 * @param index
 */
void Room::removeItemFromRoom(int index){
    int i = 0;

    vector<Item>::iterator it;

    for(it = itemsInRoom.begin(); it != itemsInRoom.end(); it++,i++){
        if(i == index){
            itemsInRoom.erase(it);
            break;
        }
    }
}


/**
 * @brief Room::displayItem   show what item in the room
 * @return
 */
string Room::displayItem() {

    string tempString = "Elements in Current Location :";
    int sizeItems = (itemsInRoom.size());
    if (itemsInRoom.size() < 1) {
        tempString = "**No elements in current Location**";
        }
    else if (itemsInRoom.size() > 0) {
       int x = (0);
        for (int n = sizeItems; n > 0; n--) {
            tempString = tempString + itemsInRoom[x].getShortDescription() + "  " ;
            x++;
            }
        }
    return tempString;

}


/**
 * @brief Room::numberOfItems   no. of items in the room
 * @return
 */
int Room::numberOfItems() {
    return itemsInRoom.size();
}

/**
 * @brief Room::hasItem    check if the room has item
 * @return
 */
bool Room::hasItem(){
    if(itemsInRoom.size() > 0){
        return true;
    }

    return false;
}


/**
 * @brief Room::getItem      //get specific item in room
 * @param index
 * @return
 */
string Room::getItem(int index){
    string str = "";
    int i = 0;

    vector<Item>::iterator it;

    for(it = itemsInRoom.begin(); it != itemsInRoom.end(); it++,i++){
        if(i == index){
            str = it->getShortDescription();
        }
    }
    return str;
}




