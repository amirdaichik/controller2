//
// Created by amirdaichik on 26/07/2018.
//

#ifndef PROJECT_SERIAL_CLUSTER_BLOCK_H
#define PROJECT_SERIAL_CLUSTER_BLOCK_H
#include "referenceBlock.h"
#include "picture.h"

class serial_cluster_block
{
    // The serial cluster will know its dim and it can send it to the screen(can be calculated at the constructor)
    // When the screen wants to add a picture, it will send the pointer to the picture and the offset in the picture
private:
	friend class referenceSerialCluster;
	//serial_cluster has array of referenceBlocks
    referenceBlock* m_ref_blocks;
	//num_of_blocks in cluster
    static int s_num_of_blocks;
	//The direction settings of the class
    static direction* s_directions;
	//The dimention of the cluster
	static coord s_rectangle_dim;

	//This function will update the pos based on the direction (And the current pos)
	void fixPos(coord* pos,direction d);

public:
	/*static methods */
	//Init the class
	static void init(int num_of_blocks,direction* d);
	//Get the dimention of serial cluster (It is static since all the clusters have the same dimention)
	static coord getRectangleDim();

	/* object methods */
	serial_cluster_block();
    ~serial_cluster_block();
	//Will clean the whole cluster
    void clean();
	//setPicture will place a picture in the cluster 
    // posInPic is the offset in the picture of the left upper block in the cluster (being sent by the screen) [Can be negative if the picture is not being drawn in the left upper block]
    void setPicture(picture* pic,coord posInPic,colorData c);
	//Debug
	static void test();
    void print();

};


#endif //PROJECT_SERIAL_CLUSTER_BLOCK_H
