#ifndef CHARACTER_H_
#define CHARACTER_H_


#include <string>
using namespace std;
#include <vector>
using std::vector;


class Character {
private:
	string description;
     vector <string> itemsInCharacter;
public:
    void addItems(string description);




public:
    Character();
    string getShortDescription();
    string getLongDescription();

};

#endif /*CHARACTER_H_*/
