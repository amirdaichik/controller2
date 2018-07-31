//
// Created by amirdaichik on 31/07/2018.
//

#include "commandHandler.h"
#include "screen.h"

bool commandHandler::isScreenBigEnough(coord pos,picture** pics,int sizeOfPics)
{
    coord picsFrameSize;
    for(int i=0;i<sizeOfPics;i++)
    {
        coord curPicSize = pics[i]->getPicSize();
        picsFrameSize.col += curPicSize.col;
        if(curPicSize.row > picsFrameSize.row)
            picsFrameSize.row = curPicSize.row;
    }
    screen* s = screen::getInstance();
    coord screenSize = s->getDim();
    if(screenSize.row < picsFrameSize.row + pos.row)
        return false;
    if(screenSize.col < picsFrameSize.col + pos.col)
        return false;
    return true;
}
bool num2digits(int num,picture* array[3])
{
    pictureDatabase* picDatabase = pictureDatabase::getInstance();
    if(num<0 || num>999)
        return false;
    int ahadot = num%10;
    int asarot = (num/10)%10;
    int meot = num/100;
    meot > 0 ? picDatabase->getDigit(meot,&array[0]) : picDatabase->getDigit(EMPTY_DIGIT,&array[0]);
    meot >0 || asarot >0 ? picDatabase->getDigit(asarot,&array[1]) : picDatabase->getDigit(EMPTY_DIGIT,&array[0]);
    picDatabase->getDigit(ahadot,&array[2]);
    return true;

}
bool commandHandler::recieveOldTypeCommand(int num1,arrowDirection arrow1,int isArrow1First, int num2, arrowDirection arrow2, int isArrow2First,int startRow, int startCol)
{
    pictureDatabase* picDatabase = pictureDatabase::getInstance();
    picture* pictures[8];
    bool success = true;
    success &= num2digits(num1,&pictures[isArrow1First]);
    success &= picDatabase->getArrow(arrow1,&pictures[(1-isArrow1First)*3]);
    success &= num2digits(num2,&pictures[4+isArrow2First]);
    success &= picDatabase->getArrow(arrow2,&pictures[4+(1-isArrow2First)*3]);
    if(!success)
        return false;
    coord pos(startRow,startCol);
    if(!isScreenBigEnough(pos,pictures,4));
        return false;
    screen* s = screen::getInstance();
    for(int i=0;i<4;i++)
    {
        s->addPicture(pictures[i],pos);
        coord picSize = pictures[i]->getPicSize();
        pos.col+= picSize.col;
    }
    return true;
}
