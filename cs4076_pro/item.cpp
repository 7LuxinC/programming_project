#include "item.h"

/**
 * @brief Item::Item     creat a constructor
 * @param inDescription
 * @param numPotion
 * @param imgPath
 */
Item::Item(string inDescription,int numPotion, string imgPath) {
    description = inDescription;
    potion = numPotion;
    imagePath = imgPath;
}


/**
 * @brief Item::Item    overloading constructor
 * @param inDescription
 * @param imgPath
 */
Item::Item (string inDescription,string imgPath) {
	description = inDescription;
    imagePath = imgPath;

}

/**
 * @brief Item::getPotion
 * @return potion
 */
int Item::getPotion(){
    return potion;
}

/**
 * @brief Item::setPotion
 * @param numP
 */
void Item::setPotion(int numP){
    potion = numP;

}

/**
 * @brief Item::getImagePath   get image of a item
 * @return imagePath
 */
string Item::getImagePath(){

    return imagePath;

}

/**
 * @brief Item::getShortDescription   get the name of the item
 * @return description
 */
string Item::getShortDescription()
{
	return description;
}


/**
 * @brief Item::getLongDescription    item information
 * @return string
 */
string Item::getLongDescription()
{
	return " item(s), " + description + ".\n";
}

