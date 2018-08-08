//
// Created by amirdaichik on 08/08/2018.
//

#ifndef PROJECT_REFERENCESERIALCLUSTER_H
#define PROJECT_REFERENCESERIALCLUSTER_H
#include "serial_cluster_block.h"

class referenceSerialCluster {
private:
    friend class painterWorker;
    pixelData** m_data_cur;
    pixelData** m_data_next;
    bool m_isNextValid;
    int m_numOfRows;
    int m_numOfCols;
    serial_cluster_block* m_myCluster;
    void allocData();
public:
    referenceSerialCluster();
    referenceSerialCluster(serial_cluster_block* myCluster);
    ~referenceSerialCluster();
    void setMyCluster(serial_cluster_block* myCluster);
    void updateData();
    bool switchData();
    void print();
    static void test();
};


#endif //PROJECT_REFERENCESERIALCLUSTER_H
