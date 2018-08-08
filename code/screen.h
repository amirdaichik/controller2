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
    coord getDim();
    void addPicture(picture* pic,coord pos);
    void cleanScreen();
    //void init(coord dim);
    //void setCluster(int idx,serial_cluster_block* cluster);
    void printScreen();
    void addCluster(serial_cluster_block* cluster);
    serial_cluster_block* getCluster(int index);
	static void test();
    static screen* getInstance();
    bool isScreenBigEnough(coord pos,coord picsFrameSize);
    void clearRectangle(coord start,coord size);


};


#endif //PROJECT_SCREEN_H
