#include <iostream>
#include <string>
#include "ZorkUL.h"


using namespace std;

ZorkUL::~ZorkUL(){
    delete currentRoom;

    for(int i = 0; i<arrSize;i++){
        delete rooms[i];
    }



}


ZorkUL::ZorkUL() {
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
        volcano ->addItem(new Item("Magical Potion",2,":/resources/img/magic_potion.png"));

    sky = new Room("Sky City",":/resources/img/sky_city.jpg");

    cliff = new Room("Cliff",":/resources/img/cliff.jpg");



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


//get the current room
Room* ZorkUL::getCurrentRoom(){
    return currentRoom;
}


//welcom message of the game
string ZorkUL::printWelcome() {

    string welcome = "Welcome to the Land of Loswilire! \n\nCheck out the message and info button for more infomation.\n\n";
    string curLoc = currentRoom -> longDescription();
    welcome = welcome + curLoc + "\n";

    return welcome;
}


//get room picture
string ZorkUL::getPic(){
    string picpath = currentRoom ->getImg();
    return picpath;
}


/**
 * Given a command, process (that is: execute) the command.
 * If this command ends the ZorkUL game, true is returned, otherwise false is
 * returned.
 */
void ZorkUL::processCommand(Command command) {
    if (command.isUnknown()) {
		cout << "invalid input"<< endl;
	}

	string commandWord = command.getCommandWord();
	if (commandWord.compare("info") == 0)
		printHelp();

	else if (commandWord.compare("go") == 0)
		goRoom(command);

    else if (commandWord.compare("teleport") == 0)             //--create teleport condition
        teleport();

   /*
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
    */

}

//help information
string ZorkUL::printHelp() {
    string infos = "Valid inputs are: \n" + parser.showCommands() + "\n\nValid buttons are:\nnorth south east west teleport collect activate bag message help quit\n\n";
    string info2 = "Collect button:\nTo collect a item, click the item and press the collect a item button\n\nActivate button:\n only appear in the sky city and you "
                   "can access to the wordle game challenge to fill up your magic potion more quicker(only you win the game) and you can activate your potion when reach 100% power\n\n"
                   "Bag button:\nShow what items you collected. Message button: Brief information about the game.\n\nQuit button:\nQuit the program.";
    infos = infos + info2;
    return infos;
}


//go specific Room from the direction provided
void ZorkUL::goRoom(Command command) {
	if (!command.hasSecondWord()) {
		cout << "incomplete input"<< endl;
		return;
	}

	string direction = command.getSecondWord();

	// Try to leave current room.
	Room* nextRoom = currentRoom->nextRoom(direction);
    currentRoom = nextRoom;

}


//go to the next room
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


//transfer to any room
string ZorkUL::teleport(){
    srand(time(0));          //--initalize random number generator

    int i = rand() % 9;
    currentRoom = rooms[i];

    return currentRoom -> longDescription();
}


//check if the current room has room or not
bool ZorkUL::hasItems(){
    return currentRoom -> hasItem();
}


//show specific item in the room
string ZorkUL::showItems(int index){

    return currentRoom ->getItem(index);
}

//get the description of the zork;
string ZorkUL::getShortDescription(){
    return "The Land of Loswilire";
}

