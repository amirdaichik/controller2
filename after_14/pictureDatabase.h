//
// Created by amirdaichik on 31/07/2018.
//

#ifndef PROJECT_PICTUREDATABASE_H
#define PROJECT_PICTUREDATABASE_H

#include <cstddef>
#include "picture.h"
#define MAX_NUM_OF_PICTURES 30
#define NUM_OF_DIGITS 11
#define NUM_OF_ARROWS 10
#define EMPTY_DIGIT 10
#define START_ARROW_INDEX 30
typedef enum arrowDirection{A_RIGHT=30,A_RIGHTDOWN = 31,A_DOWN=32,A_LEFTDOWN=33,A_LEFT=34,A_LEFTUP=35, A_UP=36, A_RIGHTUP=37,A_TURNEDRIGHT=38, A_TURNEDLEFT=39} arrowDirection;
class pictureDatabase {
private:
    picture* m_pics[MAX_NUM_OF_PICTURES];// pictures array
    bool m_isValidPicture[MAX_NUM_OF_PICTURES];//valid array
    pictureDatabase();
    ~pictureDatabase();
public:
    static pictureDatabase s_theDatabase;
	//returns the instance of the database
    static pictureDatabase* getInstance();
	//Initiate the database (It will create all the arrows and the digits)
	void init();
	//will put the requested arrow in output
    bool getArrow(arrowDirection direction,picture** output); 
	// Will put the requested digit in output
    bool getDigit(int d,picture** output);
	//Will add picture to the database
    bool addPicture(picture* pic,int* output,int offset=NUM_OF_DIGITS+NUM_OF_ARROWS);
	// Will remove picture from the database, return value will be true in case index is valid index
    bool removePicture(int index, bool allowRemovalOfArrowOrDigit = false);
	// Will put pic[index] in output, return value will be true in case index is a valid index
    bool getPicture(int index,picture** output);
	// This function will transfer a number into an array of digit pictures. 
	// It will return empty digits for any left digit which is zero (Expect of the last one)
	bool num2digits(int num,picture* array[3]);
#ifdef DEBUG
    static void test();
#endif
};
#endif //PROJECT_PICTUREDATABASE_H
