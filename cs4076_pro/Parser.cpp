#include "Parser.h"

#include <string>

Parser::Parser() {
	commands = new CommandWords();
}


/**
 * Print out a list of valid command words.
 */
string Parser::showCommands() {
    return commands->showAll();
}
