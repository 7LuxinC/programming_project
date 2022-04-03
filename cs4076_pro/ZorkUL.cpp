#include <iostream>
#include <QApplication>
#include <string>
#include <QPixmap>
#include <stdlib.h>

using namespace std;
#include "ZorkUL.h"
#include "mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc,argv);
    MainWindow w;

    //ZorkUL temp;
    //temp.play();
  w.setStyleSheet(".QWidget{background-image: url(:/resources/img/forest.jpg);}");
   w.show();    //...show the main window
   return app.exec();

}

ZorkUL::~ZorkUL(){


}

ZorkUL::ZorkUL() {
     character = new Character();
	createRooms();
}

void ZorkUL::createRooms()  {
    Room *mainland, *farm, *mysWood, *river, *cave, *forest, *volcano, *sky, *cliff;


    mainland = new Room("Mainland", ":/resources/img/mainland.jpg");
            mainland->addItem(new Item("Magical Potion", 1,":/resources/img/magic_potion.png"));

   farm = new Room("Farm",":/resources/img/farm.jpg");
       farm->addItem(new Item("Fertile Soil",":/resources/img/earth.png"));

    mysWood = new Room("Mysterious Wood",":/resources/img/mysterious_wood.jpg");

    river = new Room("Riverside",":/resources/img/riverside.jpg");
        river ->addItem(new Item("Spring Water",":/resources/img/water.png"));

    cave = new Room("Cave",":/resources/img/dark_cave.jpg");
        cave ->addItem(new Item("Gold Ore",":/resources/img/gold.png"));
        cave ->addItem(new Item("Magical Potion",1,":/resources/img/magic_potion.png"));
        cave ->addItem(new Item("Magical Potion",1,":/resources/img/magic_potion.png"));

    forest = new Room("Forest",":/resources/img/forest.jpg");
        forest -> addItem(new Item("Wood Stick",":/resources/img/wood.png"));

    volcano = new Room("Volcano",":/resources/img/volcano.jpg");
        volcano ->addItem(new Item("Fire Gabbro",":/resources/img/fire.png"));
        volcano ->addItem(new Item("Magical Potion",1,":/resources/img/magic_potion.png"));

    sky = new Room("Sky City",":/resources/img/sky_city.jpg");

    cliff = new Room("Cliff",":/resources/img/cliff.jpg");


   //nr = new Room("nr",":/resources/img/mainland.jpg");                                     //--create a newRoom object

   //--add all the room to pointer arrays
    rooms[0] = mainland;
    rooms[1] = farm;
    rooms[2] = mysWood;
    rooms[3] = river;
    rooms[4] = cave;
    rooms[5] = forest ;
    rooms[6] = volcano;
    rooms[7] = sky;
    rooms[8] = cliff;




//             (N, E, S, W)
    mainland->setExits(sky, farm, cave, NULL);
    farm->setExits(cliff, mysWood, NULL, mainland);
    mysWood->setExits(NULL, NULL, river, farm);
    river->setExits(mysWood, NULL, NULL, NULL);
    cave->setExits(mainland, NULL, NULL, forest);
    forest->setExits(NULL,cave, NULL, NULL);
    volcano->setExits(NULL, sky, NULL, NULL);
    sky->setExits(NULL, cliff, mainland, volcano);
    cliff->setExits(NULL, NULL, farm, sky);


        currentRoom = mainland;
}

Room* ZorkUL::getCurrentRoom(){
    return currentRoom;
}

Character* ZorkUL::getCharacter(){

    return character;
}


/**
 *  Main play routine.  Loops until end of play.
 */
void ZorkUL::play() {
	printWelcome();

	// Enter the main command loop.  Here we repeatedly read commands and
	// execute them until the ZorkUL game is over.

	bool finished = false;
	while (!finished) {
		// Create pointer to command and give it a command.
		Command* command = parser.getCommand();
		// Pass dereferenced command and check for end of game.
		finished = processCommand(*command);
		// Free the memory allocated by "parser.getCommand()"
		//   with ("return new Command(...)")
		delete command;
	}
	cout << endl;
	cout << "end" << endl;
}
string ZorkUL::printWelcome() {
    //cout << "start"<< endl;
    //cout << "info for help"<< endl;
    //cout << endl;
    //cout << currentRoom->longDescription() << endl;
    string welcome = "Welcome to the Land of Loswilire! \n\nCheck out the message and info button for more infomation.\n\n";
    string curLoc = currentRoom -> longDescription();
    welcome = welcome + curLoc + "\n";

    return welcome;
}

string ZorkUL::getPic(){
    string picpath = currentRoom ->getImg();
    return picpath;
}

/**
 * Given a command, process (that is: execute) the command.
 * If this command ends the ZorkUL game, true is returned, otherwise false is
 * returned.
 */
bool ZorkUL::processCommand(Command command) {
    if (command.isUnknown()) {
		cout << "invalid input"<< endl;
		return false;
	}

	string commandWord = command.getCommandWord();
	if (commandWord.compare("info") == 0)
		printHelp();

	else if (commandWord.compare("map") == 0)
		{
        cout << "[Volcano] ---[Sky World] ----- [Cliff]                       " << endl;
        cout << "                 |                |                          " << endl;
        cout << "                 |                |                          " << endl;
        cout << "             [Main Land] ----- [farm] --- [Mysterious wood]  " << endl;
        cout << "                 |                             |             " << endl;
        cout << "                 |                             |             " << endl;
        cout << "[Forest] --- [Dark Cave] ----------------- [River Side]      " << endl;



        }

	else if (commandWord.compare("go") == 0)
		goRoom(command);

    else if (commandWord.compare("teleport") == 0)  {               //--create teleport condition

      teleport();
      cout << currentRoom ->longDescription() << endl;

    }else if (commandWord.compare("take") == 0){

        if (!command.hasSecondWord()) {
            cout << "incomplete input"<< endl;

    }else if (command.hasSecondWord()) {
        cout << "you're trying to take " + command.getSecondWord() << endl;
        int location = currentRoom->isItemInRoom(command.getSecondWord());
        if (location  < 0 )
            cout << "item is not in room" << endl;
        else{                                                                   //--add {} to avoid missleading indentation
            cout << "item is in room" << endl;
            cout << "index number " << + location << endl;
            cout << endl;
            cout << currentRoom->longDescription() << endl;
        }
        }
    }else if (commandWord.compare("put") == 0)
    {

    }
    /*
    {
    if (!command.hasSecondWord()) {
		cout << "incomplete input"<< endl;
        }
        else
            if (command.hasSecondWord()) {
            cout << "you're adding " + command.getSecondWord() << endl;
            itemsInRoom.push_Back;
        }
    }
*/
    else if (commandWord.compare("quit") == 0) {
        if (command.hasSecondWord())
            cout << "overdefined input"<< endl;
        else
            return true; /**signal to quit*/
    }
    return false;
}
/** COMMANDS **/

string ZorkUL::printHelp() {
    //cout << "valid inputs are; " << endl;
    string infos = "Valid inputs are: \n" + parser.showCommands();
    return infos;

}

void ZorkUL::goRoom(Command command) {
	if (!command.hasSecondWord()) {
		cout << "incomplete input"<< endl;
		return;
	}

	string direction = command.getSecondWord();

	// Try to leave current room.
	Room* nextRoom = currentRoom->nextRoom(direction);

	if (nextRoom == NULL)
		cout << "underdefined input"<< endl;
	else {
		currentRoom = nextRoom;
		cout << currentRoom->longDescription() << endl;
	}
}

string ZorkUL::go(string direction) {
	//Make the direction lowercase
	//transform(direction.begin(), direction.end(), direction.begin(),:: tolower);
	//Move to the next room
	Room* nextRoom = currentRoom->nextRoom(direction);
	if (nextRoom == NULL)
        return("*****Invalid direction,try different ways!*****");
	else
	{
		currentRoom = nextRoom;
		return currentRoom->longDescription();
	}
}

string ZorkUL::teleport(){
    srand(time(0));          //--initalize random number generator

    int i = rand() % 9;
    currentRoom = rooms[i];

    return currentRoom -> longDescription();
}

bool ZorkUL::hasItems(){
    return currentRoom -> hasItem();
}

string ZorkUL::showItems(int index){

    return currentRoom ->getItem(index);
}


