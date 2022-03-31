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
   void removeItemFromRoom(int index);
   //string setPic();
   string getImg();
   bool hasItem();
   string getItem(int index);

   int getItemSize();

   string searchItem(int index);
   string getItemImage(string itemname);
};

#endif
