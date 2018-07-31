//
// Created by amirdaichik on 26/07/2018.
//

#include "screen.h"
screen screen::theScreen;
screen* screen::getInstance(){
    return &theScreen;
}

screen::screen()
{
    m_numOfClusters = 0;
}
void screen::addPicture(picture *pic,coord posInScreen)
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
        m_clusters[i]->setPicture(pic,posInScreen);
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
void screen::addCluster(serial_cluster_block* cluster)
{
    m_clusters[m_numOfClusters++] = cluster;
}
#define CLEAN_OPER 0
#define PRINT_OPER 1
#define ADD_PIC_OPPER 2
typedef struct operations{
	int op;
	picture* pic;
	coord pos;
} operations;

setupTest(operations* oper,int* nOpers)
{
	int numOfClusters = 5;
	int numOfBlocksPerCluster = 9;
	direction direct[numOfBlocksPerCluster] = {RIGHT,RIGHT,RIGHT,DOWN,DOWN,LEFT,LEFT,UP,RIGHT};
	serial_cluster_block::init(numOfBlocksPerCluster,direct);
	for(int i=0;i<numOfClusters;i++)
	{
		screen s = screen::getInstance();
		s->addCluster(new serial_cluster_block());
	}
	//
	int num_of_opers = 5;
	*nOpers = num_of_opers;
	oper = new operations[num_of_opers];
	oper[0].op = CLEAN_OPER;
	oper[1].op = PRINT_OPER;
	
}
void screen::test()
{
	operations* oper;
	int num_of_clusters,num_of_opers;
	setupTest(oper,&num_of_opers);
	if(coper == NULL)
	{
		std::cout<<"oper is null";
		return;
	}
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
		free(oper[i].pic);
	}
	free(oper);
}