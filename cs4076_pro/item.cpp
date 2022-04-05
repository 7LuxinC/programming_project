#include "item.h"

Item::Item(string inDescription,int numPotion, string imgPath) {
    description = inDescription;
    potion = numPotion;
    imagePath = imgPath;

}

Item::Item (string inDescription,string imgPath) {
	description = inDescription;
    imagePath = imgPath;


}

int Item::getPotion(){
    return potion;
}

void Item::setPotion(int numP){
    potion = numP;

}

string Item::getImagePath(){

    return imagePath;

}

string Item::getShortDescription()
{
	return description;
}

string Item::getLongDescription()
{
	return " item(s), " + description + ".\n";
}

