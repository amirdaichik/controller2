//
// Created by amirdaichik on 31/07/2018.
//

#include <iostream>
#include "commandHandler.h"
#include "screen.h"
commandHandler commandHandler::theCommandHandler;

//This function will handle old style command ( draw 2 numbers (3 digits each) and 2 arrows on the screen )
bool commandHandler::recieveOldTypeCommand(int num1,arrowDirection arrow1,int isArrow1First,colorData c1, int num2, arrowDirection arrow2, int isArrow2First,colorData c2,int startRow, int startCol)
{
    pictureDatabase* picDatabase = pictureDatabase::getInstance();
    picture* pictures[NUM_OF_PICS_IN_OLD_TYPE_COMMAND];

    bool success = true;
    success &= picDatabase->num2digits(num1,&pictures[isArrow1First]);
    success &= picDatabase->getArrow(arrow1,&pictures[(1-isArrow1First)*3]);
    success &= picDatabase->num2digits(num2,&pictures[4+isArrow2First]);
    success &= picDatabase->getArrow(arrow2,&pictures[4+(1-isArrow2First)*3]);
    if(!success)
        return false;// TODO: Return more error values
	
    coord pos(startRow,startCol);

    screen* s = screen::getInstance();
    coord frameSize = picture::calcFrameSize(pictures,NUM_OF_PICS_IN_OLD_TYPE_COMMAND);
    if(!s->isScreenBigEnough(pos,frameSize))
        return false;

    for(int i=0;i<NUM_OF_PICS_IN_OLD_TYPE_COMMAND;i++)
    {
    	colorData* c;
		if(i<NUM_OF_PICS_IN_OLD_TYPE_COMMAND/2)
			c = &c1;
		else
			c = &c2;
        s->addPicture(pictures[i],pos,*c);
        coord picSize = pictures[i]->getPicSize();
        pos.col+= picSize.col;
    }
    return true;

}
// return sthe instance of the command handler
commandHandler* commandHandler::getInstance()
{
    return &theCommandHandler;
}
//This function will handle adding new picture to the database command
bool commandHandler::addNewPictureToDatabase(coord dim,pixelData** data,int* index_output)
{
    picture* newPic = new picture(dim,data);
    pictureDatabase* database = pictureDatabase::getInstance();
    bool success = database->addPicture(newPic,index_output);
    delete[] data[0];
    delete[] data;
    return success;
}
//This function will handle removing picture from the database command
bool commandHandler::removePictureFromDatabase(int index) {
    return pictureDatabase::getInstance()->removePicture(index);
}
//This function will handle paint picture on the screen at pos command
paint_picture_status commandHandler::paintPicture(int index,coord pos,colorData c)
{
    pictureDatabase* database = pictureDatabase::getInstance();
    picture* pic;
    if(!database->getPicture(index,&pic))
        return NO_SUCH_PICTURE;
    screen* p_screen = screen::getInstance();
    if(!p_screen->isScreenBigEnough(pos,pic->getPicSize()))
        return NO_FIT_TO_SCREEN;
    p_screen->addPicture(pic,pos,c);
    return SUCCESS;
}
//This function will handle clean rectangle command
bool commandHandler::clearRectangleCommandHandler(coord leftup,coord size)
{
    screen* p_screen = screen::getInstance();
    if(!p_screen->isScreenBigEnough(leftup,size))
        return false;
    p_screen->clearRectangle(leftup,size);
    return true;
}
//This function will handle clean screen command
void commandHandler::clearScreen()
{
    screen* p_screen = screen::getInstance();
    coord dim = p_screen->getDim();
    coord leftup;
    clearRectangleCommandHandler(leftup,dim);
}
//This function will handle setup command (TODO: Show Golan)
bool setupHandler(int id, int blockDim, int blockPara,
					int numOfBlocksInSerialCluter, direction* serial_cluster_direction , int numOfSerialClusters,
					posRegister pos[],int numOfClks,register* clk,int numOfOEs, register* OEs,int numOfLats, register* lats, 
					register** redRegs,register** greenRegs,register** blueRegs)
{
	m_id = id;
	block::init(blockDim,blockPara);
	serial_cluster_block::init(numOfBlocksInSerialCluter,serial_cluster_direction); //TODO make sure that I do not free the serial_cluster_direction!
	pictureDatabase::getInstance()->init();
	for(int i=0;i<numOfSerialClusters;i++)
	{
		screen::getInstance()->addCluster(new serial_cluster_block());
	}
	painter::getInstance()->init(pos,numOfClks,clk,numOfOEs,OEs,numOfLats,lats,redRegs,greenRegs,blueRegs);//TODO Free stuff
	hasBeenSetup = true;
	return true;
}