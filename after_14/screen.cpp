//
// Created by amirdaichik on 26/07/2018.
//

#include <cstddef>
#include <iostream>
#include "screen.h"
screen screen::theScreen;
screen* screen::getInstance(){
    return &theScreen;
}

screen::screen()
{
    m_numOfClusters = 0;
}
coord screen::getDim()
{
    return m_dim;
}
int screen::getNumOfClusters()
{
	return m_numOfClusters;
}
void screen::addPicture(picture *pic,coord posInScreen,colorData c)
{
    //coord picSize = pic->getPicSize();
    //int lastRowInPic = posInScreen.row + picSize.row -1;
    //coord curPosInScreen;
    //coord nextPosInScreen;
    //curPosInScreen.row = 0;
    //posInScreen = z
    // lastRowInPic = k
    // curPosInScreen x , next y
    posInScreen.row *= -1;
    posInScreen.col *= -1;
	coord clusterDim = serial_cluster_block::getRectangleDim();
    for(int i=0;i<m_numOfClusters;i++)
    {
        //picOffset.row -= curPosInScreen.row;
        //picOffset.col -= curPosInScreen.col
        m_clusters[i]->setPicture(pic,posInScreen,c);
        //if(curPosInScreen.row > lastRowInPic || nextPosInScreen.row<=posInScreen.row ) do not send
        //nextPosInScreen.row += clusterDim.row;
        posInScreen.row += clusterDim.row;
    }
}
screen::~screen(){
    for(int i=0;i<m_numOfClusters;i++)
        delete m_clusters[i];

}
void screen::cleanScreen()
{
    for(int i=0;i<m_numOfClusters;i++)
    {
        m_clusters[i]->clean();
    }
}
serial_cluster_block* screen::getCluster(int index)
{
	if(index>=m_numOfClusters || index<0)
		return NULL;
    return m_clusters[index];
}

void screen::addCluster(serial_cluster_block* cluster)
{
    coord clusterDim = cluster->getRectangleDim();
    m_dim.col = clusterDim.col;
    m_dim.row += clusterDim.row;
    m_clusters[m_numOfClusters++] = cluster;
}
bool screen::isScreenBigEnough(coord pos,coord picsFrameSize)
{
    coord screenSize = getDim();
    if(screenSize.row < picsFrameSize.row + pos.row)
        return false;
    if(screenSize.col < picsFrameSize.col + pos.col)
        return false;
    return true;
}
void screen::clearRectangle(coord start,coord size)
{
    /*start.row *= -1;
    start.col *= -1;
    coord clusterDim = serial_cluster_block::getRectangleDim();
    for(int i=0;i<m_numOfClusters;i++)
    {
        m_clusters[i]->clean(start,size);
        start.row += clusterDim.row;
    }*/
    picture emptyPicture = picture(size);
    addPicture(&emptyPicture,start);
}


void screen::printScreen(){
    for(int i=0;i<m_numOfClusters;i++){
        std::cout<<"Cluster #"<<i<<":"<<std::endl;
        m_clusters[i]->print();
    }
}


#define CLEAN_OPER 0
#define PRINT_OPER 1
#define ADD_PIC_OPPER 2
typedef struct operations{
	int op;
	picture* pic;
	coord pos;
} operations;

operations* setupTest(int* nOpers)
{
    block::setDim(4);
	int numOfClusters = 2;
	int numOfBlocksPerCluster = 9;
	direction direct[] = {RIGHT,RIGHT,RIGHT,DOWN,DOWN,LEFT,LEFT,UP,RIGHT};
	serial_cluster_block::init(numOfBlocksPerCluster,direct);
	for(int i=0;i<numOfClusters;i++)
	{
		screen* s = screen::getInstance();
		s->addCluster(new serial_cluster_block());
	}

    pixelData** d;
    d = new pixelData*[8];
    d[0] = new pixelData[4*8];
    for(int i=0;i<8;i++) {
        d[i] = d[0] + 4*i;
        for (int j = 0; j < 4; j++) {
            if (i == 0 || j == 3)
                d[i][j].bit = true;
            else
                d[i][j].bit = false;
        }
    }
    coord dataSize;
    dataSize.row = 2;
    dataSize.col = 1;


	//
	int num_of_opers = 2;
	*nOpers = num_of_opers;
    operations* oper = new operations[num_of_opers];
	oper[0].op = ADD_PIC_OPPER;
	oper[0].pic = new picture(dataSize,d);
    oper[0].pos.row = 2;
    oper[0].pos.col = 1;

	oper[1].op = PRINT_OPER;
    oper[1].pic = NULL;
	return oper;
}

void screen::test()
{
	operations* oper;
	int num_of_clusters,num_of_opers;
	oper = setupTest(&num_of_opers);
	/*if(coper == NULL)
	{
		std::cout<<"oper is null";
		return;
	}*/
	screen* s = screen::getInstance();
	for(int i=0;i<num_of_opers;i++)
	{
		if(oper[i].op == CLEAN_OPER)
			s->cleanScreen();
		if(oper[i].op == ADD_PIC_OPPER )
		{
			s->addPicture(oper[i].pic,oper[i].pos);
		}
		if(oper[i].op == PRINT_OPER)
		{
			s->printScreen();
		}
		//delete(oper[i].pic);
	}
    //delete(oper);
}