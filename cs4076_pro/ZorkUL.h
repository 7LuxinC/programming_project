#ifndef ZORKUL_H_
#define ZORKUL_H_

#include "Command.h"
#include "Parser.h"
#include "Room.h"
#include "item.h"
//#include"Character.h"
#include <iostream>
#include <string>

using namespace std;

class ZorkUL {

static int const arrSize = 9;  // room array of pointer

private:

	Parser parser;
    Room *currentRoom;
    Room *rooms[arrSize];
	void createRooms();
    bool processCommand(Command command);


public:
	ZorkUL();
    virtual ~ZorkUL();
	void play();
    string go(string direction);
    string printHelp();
    string getPic();
    string showItems(int index);
    void goRoom(Command command);
    bool hasItems();
    string teleport();
    virtual string getShortDescription();
    Room* getCurrentRoom();

protected:
    string printWelcome();

};


#endif /*ZORKUL_H_*/
