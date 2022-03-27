#ifndef ZORKUL_H_
#define ZORKUL_H_

#include "Command.h"
#include "Parser.h"
#include "Room.h"
#include "item.h"
#include <iostream>
#include <string>
using namespace std;

class ZorkUL {

static int const arrSize = 10;  // room array of pointer

private:
	Parser parser;
	Room *currentRoom;
    Room *rooms[arrSize];
	void createRooms();

	bool processCommand(Command command); 
	void goRoom(Command command);

    void createItems();
    void displayItems();

public:
	ZorkUL();
	void play();
    string go(string direction);
    string printHelp();
    string printWelcome();
    string teleport();
    string getPic();
};


#endif /*ZORKUL_H_*/
