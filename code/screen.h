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
    serial_cluster_block* m_clusters[MAX_NUM_OF_CLUSTERS];
    screen();
    ~screen();
public:
    void addPicture(picture* pic,coord pos);
    void cleanScreen();
    //void init(coord dim);
    //void setCluster(int idx,serial_cluster_block* cluster);
    void addCluster(serial_cluster_block* cluster);
    static screen* getInstance();


};


#endif //PROJECT_SCREEN_H
