//
// Created by amirdaichik on 31/07/2018.
//

#ifndef PROJECT_COMMANDHANDLER_H
#define PROJECT_COMMANDHANDLER_H
#include "pictureDatabase.h"
class commandHandler {
private:
    commandHandler* theCommandHandler;

    commandHandler();
    ~commandHandler();
public:
    bool recieveOldTypeCommand(int num1,arrowDirection arrow1,int isArrow1First, int num2, arrowDirection arrow2, int isArrow2First,int startRow = 0, int startCol = 0);
    bool isScreenBigEnough(coord pos,picture** pics,int sizeOfPics = 1);
};


#endif //PROJECT_COMMANDHANDLER_H
