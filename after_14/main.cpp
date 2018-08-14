#include <iostream>
#include "block.h";
#include "picture.h"
#include "serial_cluster_block.h"
#include "screen.h"
#include "pictureDatabase.h"
#include "referenceSerialCluster.h"
#include "commandHandler.h"
#include "painter.h"

void testCommandNumber1()
{
    block::setDim(6);
    direction d[] = {RIGHT,RIGHT,RIGHT,DOWN,LEFT,LEFT};
	
    commandHandler* command = commandHandler::getInstance();
	//setupHandler(int blockDim, int blockPara, int numOfBlocksInSerialCluter, direction * serial_cluster_direction, int numOfSerialClusters)
	command->setupHandler(6, 1, 6, d, 2);
    //recieveOldTypeCommand(int num1,arrowDirection arrow1,int isArrow1First, int num2, arrowDirection arrow2, int isArrow2First,int startRow = 0, int startCol = 0);
    bool success = command->recieveOldTypeCommand(1,A_RIGHT,true, 1, A_RIGHT, false, 1 , 0);
    //std::cout<<success<<" "<<std::endl;
    p_screen->printScreen();
    p_painter->latchScreen();
    p_painter->switchToNextBuffer();
    /*for(int i=0;i<15*6*2;i++) {
        std::cout << "Iter" << i << ":";
        p_painter->paintIter();
        std::cout<<std::endl;
    }*/
    command->clearScreen();
    coord pos;
    for(int i=0;i<4;i++)
        for(int j=0;j<3;j++) {
            pos.row = i;
            pos.col = j;
            command->paintPicture(1, pos);
        }
    std::cout<<"----------"<<std::endl;
    //p_screen->clearRectangle(coord(1,1),coord(3,2));
    command->clearRectangleCommandHandler(coord(1,1),coord(3,2));
    p_screen->printScreen();

}
int main() {
    testCommandNumber1();
    //block::test();
    //picture::test();
    //serial_cluster_block::test();
    //screen::test();
    //pictureDatabase::test();
    //referenceSerialCluster::test();
    return 0;
}

