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
    coord m_rectangle_dim;

    int m_num_of_blocks;
    direction* m_directions;
    referenceBlock* m_ref_blocks;
    void fixPos(coord* pos,direction d);

public:
    serial_cluster_block(int num_of_blocks,direction* d);
    ~serial_cluster_block();
    coord getRectangleDim();
    void clean();
    // posInPic is the offset in the picture of the left upper block in the cluster (being sent by the screen) [Can be negative if the picture is not being drawn in the left upper block]
    void setPicture(picture* pic,coord posInPic);
    static void test();
    void print();

};


#endif //PROJECT_SERIAL_CLUSTER_BLOCK_H
