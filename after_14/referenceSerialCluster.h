//
// Created by amirdaichik on 08/08/2018.
//

#ifndef PROJECT_REFERENCESERIALCLUSTER_H
#define PROJECT_REFERENCESERIALCLUSTER_H
#include "serial_cluster_block.h"
//ReferenceSerialCluster is a class which acts like a continues buffer of data which describs a cluster
// For every cluster, there is a referenceSerialCluster
class referenceSerialCluster {
private:
    friend class painterWorker;
	// The data which should be displayed in the current iteration (In the first iteration will be empty cluster)
    colorData** m_data_cur;
	// The data which should be displayed in the next iteration
    colorData** m_data_next;
	// the data in the next iteration is valid
    bool m_isNextValid;
	//Num of rows in the data
    int m_numOfRows;
	// Num of cols in the data
    int m_numOfCols;
	// This is the cluster which the object is a reference of
    serial_cluster_block* m_myCluster;
	//Allocate the arrays
    void allocData();
public:
    referenceSerialCluster();
    referenceSerialCluster(serial_cluster_block* myCluster);
    ~referenceSerialCluster();
	//Update the myCluster variable
    void setMyCluster(serial_cluster_block* myCluster);
	// Update the m_data_next based on the m_myCluster
    void updateData();
	// Makes the m_data_next to be m_data_cur
    bool switchData();
	//Debug print
    void print();
	//Debug test
    static void test();
};


#endif //PROJECT_REFERENCESERIALCLUSTER_H
