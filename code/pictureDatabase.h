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
typedef enum arrowDirection{RIGHT=30,RIGHTDOWN = 31,DOWN=32,LEFTDOWN=33,LEFT=34,LEFTUP=35, UP=36, RIGHTUP=37,TURNEDRIGHT=38, TURNEDLEFT=39} arrowDirection;
class pictureDatabase {
private:
    picture* m_pics[MAX_NUM_OF_PICTURES];
    bool m_isValidPicture[MAX_NUM_OF_PICTURES];

    static pictureDatabase* s_theDatabase;

    pictureDatabase();
    ~pictureDatabase();
    void init();
public:
    static pictureDatabase* getInstance();
    bool getArrow(arrowDirection direction,picture** output);
    bool getDigit(int d,picture** output);
    bool addPicture(picture* pic,int* output,int offset=NUM_OF_DIGITS+NUM_OF_ARROWS);
    bool removePicture(int index);
    bool getPicture(int index,picture** output);
};


#endif //PROJECT_PICTUREDATABASE_H
