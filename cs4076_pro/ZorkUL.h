#ifndef ZORKUL_H_
#define ZORKUL_H_

#include "Command.h"
#include "Parser.h"
#include "Room.h"
#include "item.h"
#include"Character.h"
#include <iostream>
#include <string>
using namespace std;

class ZorkUL {

static int const arrSize = 9;  // room array of pointer

private:
Character *character;
	Parser parser;
    Room *currentRoom;
    Room *rooms[arrSize];
	void createRooms();

    bool processCommand(Command command);


    void createItems();
    void displayItems();

public:
	ZorkUL();
    ~ZorkUL();
	void play();
    string go(string direction);
    string printHelp();
    string printWelcome();
    string teleport();
    string getPic();
    string showItems(int index);
    void goRoom(Command command);
     bool hasItems();
    Room* getCurrentRoom();
    Character* getCharacter();
};


#endif /*ZORKUL_H_*/
