#include "CommandWords.h"

vector<string> CommandWords::validCommands;
#include <string>

using namespace std;

/**
 * Constructor - initialise the command words.
 */
CommandWords::CommandWords() {
	// Populate the vector if we haven't already.
	if (validCommands.empty()) {
		validCommands.push_back("go");
		validCommands.push_back("info");
        validCommands.push_back("teleport");                    //--add a new command called teleport
	}
}

/**
 *
 * Print all valid commands to information screen
**/
string CommandWords::showAll() {
    string validCom = "";

	//Loops through validCommands and prints each to the screen.
	for (unsigned int i = 0; i < validCommands.size(); i++){
     validCom = validCom + validCommands[i]  + " ";
	}

    return validCom;

}
