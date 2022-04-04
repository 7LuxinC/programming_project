#ifndef ITEM_H_
#define ITEM_H_

#include <map>
#include <string>
#include <iostream>
using namespace std;

class Item {

    friend Item operator + (Item& item1,Item& item2);
private:
	string description;
	string longDescription;
    string imagePath;
    int potion;
    //int weightGrams;
    //float value;
    //bool weaponCheck;

public:
    Item (string description, string imgPath);
    Item (string description="",int potion=0, string imgPath="");
	string getShortDescription();
    string getLongDescription();
    int getPotion();
    void setPotion(int numPotion);
    //int getWeight();
    //void setWeight(int weightGrams);
    //float getValue();
    //void setValue(float value);
	int getWeaponCheck();
	void setWeaponCheck(int weaponCheck);
    string getImagePath();

};

#endif /*ITEM_H_*/
