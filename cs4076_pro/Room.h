#ifndef ROOM_H_
#define ROOM_H_

#include <map>
#include <string>
#include <vector>


#include "item.h"

using namespace std;
using std::vector;

class Room {

private:
	string description;
    string imgPath;
	map<string, Room*> exits;
	string exitString();
    vector <Item> itemsInRoom;
    vector <string> rmImgs;         //room images


public:
    int numberOfItems();
    Room(string description,string imgPath);
	void setExits(Room *north, Room *east, Room *south, Room *west);
	string shortDescription();
	string longDescription();
	Room* nextRoom(string direction);
    void addItem(Item *inItem);
    string displayItem();
    int isItemInRoom(string inString);
    void removeItemFromRoom(int location);
   //string setPic();
   string getImg();
};

#endif
