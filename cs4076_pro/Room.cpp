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
	return "room = " + description + ".\n" + displayItem() + exitString();
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

/*
string Room::setPic(){
    /*string img = "";

    for(std::size_t i = 0; i < rmImgs.size(); i++){
        if(i ==  (size_t)numRm){
            img = rmImgs.at(i);
        }
    }

string str ;

    if(this -> description == "a"){
      str = rmImgs.at(0);
    }else if(this -> description == "b"){
        str = rmImgs.at(1);
    }else if(this -> description == "c"){
        str = rmImgs.at(2);
    }else if(this -> description == "d"){
        str = rmImgs.at(3);
    }else if(this -> description == "e"){
        str = rmImgs.at(4);
    }else if(this -> description == "f"){
        str = ":/resources/img/mysterious_wood.jpg";
    }else if(this -> description == "g"){
        str = rmImgs.at(6);
    }else if(this -> description == "h"){
        str = rmImgs.at(7);
    }else if (this -> description == "i"){
        str = rmImgs.at(8);
    }

return str;
}
*/


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
    else if (itemsInRoom.size() > 0) {
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




