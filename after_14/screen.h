//
// Created by amirdaichik on 26/07/2018.
//

#ifndef PROJECT_SCREEN_H
#define PROJECT_SCREEN_H
#include "serial_cluster_block.h"
#define MAX_NUM_OF_CLUSTERS 5
class screen{
    static screen theScreen;
private:
    int m_numOfClusters;
    coord m_dim;
    serial_cluster_block* m_clusters[MAX_NUM_OF_CLUSTERS];
    screen();
    ~screen();
public:
	//Gets a pointer to the screen
    static screen* getInstance();
	//Gets the dimantion of the screen in block size
    coord getDim();
	//Adss a picture to the screen
    void addPicture(picture* pic,coord pos,colorData c);
	//Clears the screen
    void cleanScreen();
	//Adss serialCluster to the screen
    void addCluster(serial_cluster_block* cluster);
	//Gets cluster from the screen 
    serial_cluster_block* getCluster(int index);
	//will return true if the screen is big enough to place a frame with picFrameSize in pos
    bool isScreenBigEnough(coord pos,coord picsFrameSize);
	//Will clear rectangle from the screen
    void clearRectangle(coord start,coord size);
	//Will return the number of serial clusters in the screen
	int getNumOfClusters();

    //DEBUG
    void printScreen();
	static void test();


};


#endif //PROJECT_SCREEN_H
