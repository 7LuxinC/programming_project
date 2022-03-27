#include <iostream>
#include <QApplication>
#include <string>
#include <QPixmap>

using namespace std;
#include "ZorkUL.h"
#include "mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc,argv);
    MainWindow w;

    //ZorkUL temp;
    //temp.play();

   w.show();    //...show the main window
   return app.exec();

}

ZorkUL::ZorkUL() {
	createRooms();
}

void ZorkUL::createRooms()  {
    Room *a, *b, *c, *d, *e, *f, *g, *h, *i, *nr;           //--add a new room called nr


    a = new Room("a", ":/resources/img/mainland.jpg");
        a->addItem(new Item("x", 1, 11));
        a->addItem(new Item("y", 2, 22));


    b = new Room("b",":/resources/img/cliff.jpg");
        b->addItem(new Item("xx", 3, 33));
        b->addItem(new Item("yy", 4, 44));

    c = new Room("c",":/resources/img/dark_cave.jpg");

    d = new Room("d",":/resources/img/mainland.jpg");
    e = new Room("e",":/resources/img/farm.jpg");
    f = new Room("f",":/resources/img/mysterious_wood.jpg");
    g = new Room("g",":/resources/img/sky_city.jpg");
    h = new Room("h",":/resources/img/riverside.jpg");
    i = new Room("i",":/resources/img/volcano.jpg");

    nr = new Room("nr",":/resources/img/mainland.jpg");                                     //--create a newRoom object

   //--add all the room to pointer arrays
    rooms[0] = a;
    rooms[1] = b;
    rooms[2] = c;
    rooms[3] = d;
    rooms[4] = e;
    rooms[5] = f;
    rooms[6] = g;
    rooms[7] = h;
    rooms[8] = i;
    rooms[9] = nr;



//             (N, E, S, W)
	a->setExits(f, b, d, c);
	b->setExits(NULL, NULL, NULL, a);
	c->setExits(NULL, a, NULL, NULL);
	d->setExits(a, e, NULL, i);
	e->setExits(NULL, NULL, NULL, d);
	f->setExits(NULL, g, a, h);
	g->setExits(NULL, NULL, NULL, f);
	h->setExits(NULL, f, NULL, NULL);
     	i->setExits(NULL, d, NULL, NULL);
    	nr->setExits(d, NULL, NULL, NULL);                    //--setExits nr

        currentRoom = a;
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
    string welcome = "Welcome to the Land of Loswilire! \n\nCheck out the message and info button for more infomation. \n\nCurrent Location: \n";
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
        cout << "[h] --- [f] --- [g]" << endl;
        cout << "         |         " << endl;
        cout << "         |         " << endl;
        cout << "[c] --- [a] --- [b]" << endl;
		cout << "         |         " << endl;
		cout << "         |         " << endl;
		cout << "[i] --- [d] --- [e]" << endl;
        cout << "         |         " << endl;            //-add nr in the map
        cout << "         |         " << endl;            //^
        cout << "        [nr]       " << endl;            //^

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

    int i = rand() % 10;
    currentRoom = rooms[i];

    return currentRoom -> longDescription();
}


