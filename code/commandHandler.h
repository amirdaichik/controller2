//
// Created by amirdaichik on 31/07/2018.
//

#ifndef PROJECT_COMMANDHANDLER_H
#define PROJECT_COMMANDHANDLER_H
#include "pictureDatabase.h"
#define NUM_OF_PICS_IN_OLD_TYPE_COMMAND 8

typedef enum {NO_SUCH_PICTURE,NO_FIT_TO_SCREEN,SUCCESS} paint_picture_status;
class commandHandler {
private:

public:
    static commandHandler theCommandHandler;
    static commandHandler* getInstance();
    bool recieveOldTypeCommand(int num1,arrowDirection arrow1,int isArrow1First, int num2, arrowDirection arrow2, int isArrow2First,int startRow = 0, int startCol = 0);
    //bool isScreenBigEnough(coord pos,picture** pics,int sizeOfPics = 1);
    bool isScreenBigEnough(coord pos,coord picFrameSize);
    bool addNewPictureToDatabase(coord dim,pixelData** data,int* index_output);
    bool removePictureFromDatabase(int index);
    paint_picture_status paintPicture(int index,coord pos);
    void clearScreen();
    bool clearRectangleCommandHandler(coord leftup,coord size);


};


#endif //PROJECT_COMMANDHANDLER_H
