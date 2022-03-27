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


private:
	Parser parser;
	Room *currentRoom;
    Room *rooms[10];
	void createRooms();

	bool processCommand(Command command); 
	void goRoom(Command command);
    void teleport();
    void createItems();
    void displayItems();

public:
	ZorkUL();
	void play();
    string go(string direction);
    string printHelp();
    string printWelcome();

};


#endif /*ZORKUL_H_*/
