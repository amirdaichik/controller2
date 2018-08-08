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
    picture* m_pics[MAX_NUM_OF_PICTURES];
    bool m_isValidPicture[MAX_NUM_OF_PICTURES];
    pictureDatabase();
    ~pictureDatabase();
public:
    void init();
    static pictureDatabase s_theDatabase;
    static pictureDatabase* getInstance();
    bool getArrow(arrowDirection direction,picture** output);
    bool getDigit(int d,picture** output);
    bool addPicture(picture* pic,int* output,int offset=NUM_OF_DIGITS+NUM_OF_ARROWS);
    bool removePicture(int index);
    bool getPicture(int index,picture** output);

    static void test();
};
#endif //PROJECT_PICTUREDATABASE_H
