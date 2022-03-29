
#include "Room.h"
#include "Command.h"

#include <QPixmap>


Room::Room(string description,string imgPath) {
	this->description = description;
    this ->imgPath = imgPath;
    //rmImgs.push_back(this -> imgPath);
}

string Room::getImg(){
    return this->imgPath;
}

int Room::getItemSize(){
    int sum = itemsInRoom.size();
    return sum;
}



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

string Room::shortDescription() {
	return description;
}

string Room::longDescription() {
    return "Current location = " + description + ".\n" + displayItem() + exitString();
}

string Room::exitString() {
	string returnString = "\nexits =";
	for (map<string, Room*>::iterator i = exits.begin(); i != exits.end(); i++)
		// Loop through map
		returnString += "  " + i->first;	// access the "first" element of the pair (direction as a string)
	return returnString;
}

Room* Room::nextRoom(string direction) {
	map<string, Room*>::iterator next = exits.find(direction); //returns an iterator for the "pair"
	if (next == exits.end())
		return NULL; // if exits.end() was returned, there's no room in that direction.
	return next->second; // If there is a room, remove the "second" (Room*)
				// part of the "pair" (<string, Room*>) and return it.
}

void Room::addItem(Item *inItem) {
    //cout <<endl;
    //cout << "Just added" + inItem->getLongDescription();
    itemsInRoom.push_back(*inItem);
}

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


string Room::displayItem() {

    string tempString = "items in room = ";
    int sizeItems = (itemsInRoom.size());
    if (itemsInRoom.size() < 1) {
        tempString = "no items in room";
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

int Room::numberOfItems() {
    return itemsInRoom.size();
}

int Room::isItemInRoom(string inString)
{
    int sizeItems = (itemsInRoom.size());
    if (itemsInRoom.size() < 1) {
        return false;
        }
    else if (hasItem()) {
       int x = (0);
        for (int n = sizeItems; n > 0; n--) {
            // compare inString with short description
            int tempFlag = inString.compare( itemsInRoom[x].getShortDescription());
            if (tempFlag == 0) {
                itemsInRoom.erase(itemsInRoom.begin()+x);
                return x;
            }
            x++;
            }
        }
    return -1;
}


bool Room::hasItem(){
    if(itemsInRoom.size() > 0){
        return true;
    }

    return false;
}

string Room::getItem(int index){
    int itemSize = itemsInRoom.size();
    string itemname = "";

    for(int i = 0; i < itemSize; i++){
        if(i == index){
            itemname = itemsInRoom[i].getShortDescription();
        }
    }

    return itemname;
}

string Room::searchItem(int index){
    string str = "";
    int i = 0;

    vector<Item>::iterator it;

    for(it = itemsInRoom.begin(); it != itemsInRoom.end(); it++,i++){
        if(i == index){
            str = itemsInRoom.at(i).getShortDescription();

        }
    }
    return str;
}




