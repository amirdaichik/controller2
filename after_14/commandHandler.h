//
// Created by amirdaichik on 31/07/2018.
//

#ifndef PROJECT_COMMANDHANDLER_H
#define PROJECT_COMMANDHANDLER_H
#include "pictureDatabase.h"
#include "register.h"
#define NUM_OF_PICS_IN_OLD_TYPE_COMMAND 8

typedef enum {NO_SUCH_PICTURE,NO_FIT_TO_SCREEN,SUCCESS} paint_picture_status;

class commandHandler {
private:
	static commandHandler theCommandHandler;//signleton design pattern
	bool hasBeenSetup; // TODO: Make sure that you are not able to do anything before receiving setup command
	int m_id;
	commandHandler(){ hasBeenSetup = false;}
	
public:
	// Will return pointer to the command handler
    static commandHandler* getInstance();
	//This function will handle old style command ( draw 2 numbers (3 digits each) and 2 arrows on the screen )
    bool recieveOldTypeCommand(int num1,arrowDirection arrow1,int isArrow1First,colorData c1, int num2, arrowDirection arrow2, int isArrow2First,colorData c2,int startRow = 0, int startCol = 0);
    //This function will handle adding new picture to the database command
	bool addNewPictureToDatabase(coord dim,pixelData** data,int* index_output);
	//This function will handle removing picture from the database command
    bool removePictureFromDatabase(int index);
	//This function will handle paint picture on the screen at pos command
    paint_picture_status paintPicture(int index,coord pos,colorData c);
	//This function will handle clean the screen command
    void clearScreen();
	//This function will handle clean rectangle command
    bool clearRectangleCommandHandler(coord leftup,coord size);
	//This function will handle setup command
	bool setupHandler(int id, int blockDim, int blockPara, 
						int numOfBlocksInSerialCluter, direction* serial_cluster_direction , int numOfSerialClusters,
						posRegister pos[],int numOfClks,register* clk,int numOfOEs, register* OEs,int numOfLats, register* lats, 
						register** redRegs,register** greenRegs,register** blueRegs);
	//TODO: commandHandler main method, in this function we should limit the usage of setup only at the beginig, and disable the usage of all the ohter commands before

};


#endif //PROJECT_COMMANDHANDLER_H
