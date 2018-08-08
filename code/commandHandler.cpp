//
// Created by amirdaichik on 31/07/2018.
//

#include <iostream>
#include "commandHandler.h"
#include "screen.h"
commandHandler commandHandler::theCommandHandler;


bool num2digits(int num,picture* array[3])
{
    pictureDatabase* picDatabase = pictureDatabase::getInstance();
    if(num<0 || num>999)
        return false;
    int ahadot = num%10;
    int asarot = (num/10)%10;
    int meot = num/100;
    meot > 0 ? picDatabase->getDigit(meot,&array[0]) : picDatabase->getDigit(EMPTY_DIGIT,&array[0]);
    meot >0 || asarot >0 ? picDatabase->getDigit(asarot,&array[1]) : picDatabase->getDigit(EMPTY_DIGIT,&array[1]);
    picDatabase->getDigit(ahadot,&array[2]);
    return true;

}
bool commandHandler::recieveOldTypeCommand(int num1,arrowDirection arrow1,int isArrow1First, int num2, arrowDirection arrow2, int isArrow2First,int startRow, int startCol)
{
    pictureDatabase* picDatabase = pictureDatabase::getInstance();
    picture* pictures[NUM_OF_PICS_IN_OLD_TYPE_COMMAND];

    bool success = true;
    success &= num2digits(num1,&pictures[isArrow1First]);
    success &= picDatabase->getArrow(arrow1,&pictures[(1-isArrow1First)*3]);
    success &= num2digits(num2,&pictures[4+isArrow2First]);
    success &= picDatabase->getArrow(arrow2,&pictures[4+(1-isArrow2First)*3]);

    if(!success)
        return false;
    coord pos(startRow,startCol);

    screen* s = screen::getInstance();
    coord frameSize = picture::calcFrameSize(pictures,NUM_OF_PICS_IN_OLD_TYPE_COMMAND);
    if(!s->isScreenBigEnough(pos,frameSize))
        return false;

    for(int i=0;i<NUM_OF_PICS_IN_OLD_TYPE_COMMAND;i++)
    {
        s->addPicture(pictures[i],pos);
        coord picSize = pictures[i]->getPicSize();
        pos.col+= picSize.col;
    }
    return true;

}
commandHandler* commandHandler::getInstance()
{
    return &theCommandHandler;
}
bool commandHandler::addNewPictureToDatabase(coord dim,pixelData** data,int* index_output)
{
    picture* newPic = new picture(dim,data);
    pictureDatabase* database = pictureDatabase::getInstance();
    bool success = database->addPicture(newPic,index_output);
    delete[] data[0];
    delete[] data;
    return success;
}
bool commandHandler::removePictureFromDatabase(int index) {
    return pictureDatabase::getInstance()->removePicture(index);
}

paint_picture_status commandHandler::paintPicture(int index,coord pos)
{
    pictureDatabase* database = pictureDatabase::getInstance();
    picture* pic;
    if(!database->getPicture(index,&pic))
        return NO_SUCH_PICTURE;
    screen* p_screen = screen::getInstance();
    if(!p_screen->isScreenBigEnough(pos,pic->getPicSize()))
        return NO_FIT_TO_SCREEN;
    p_screen->addPicture(pic,pos);
    return SUCCESS;
}
bool commandHandler::clearRectangleCommandHandler(coord leftup,coord size)
{
    screen* p_screen = screen::getInstance();
    if(!p_screen->isScreenBigEnough(leftup,size))
        return false;
    p_screen->clearRectangle(leftup,size);
    return true;
}
void commandHandler::clearScreen()
{
    screen* p_screen = screen::getInstance();
    coord dim = p_screen->getDim();
    coord leftup;
    clearRectangleCommandHandler(leftup,dim);
}