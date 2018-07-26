//
// Created by amirdaichik on 26/07/2018.
//

#include "serial_cluster_block.h"

serial_cluster_block::serial_cluster_block(int num_of_blocks,direction* d)
{
    m_rectangle_dim.col = 0; // The first block is also being calculated
    m_rectangle_dim.row = 1; // And we assume that the first block is turning right

    m_ref_blocks = new referenceBlock[num_of_blocks];
    m_directions = new direction[num_of_blocks];
    for(int i=0;i<num_of_blocks;i++)
    {
        if(d[i] == RIGHT)
            m_rectangle_dim.col++;
        if(d[i] == DOWN)
            m_rectangle_dim.row++;
        m_directions[i] = d[i];
    }

}

serial_cluster_block::~serial_cluster_block()
{
    delete[] m_ref_blocks;
    delete[] m_directions;
}
void serial_cluster_block::clean()
{
    for(int i=0;i<m_num_of_blocks;i++)
        m_ref_blocks[i].clean();
}
coord serial_cluster_block::getRectangleDim()
{
    return m_rectangle_dim;
}
// posInPic is the offset in the picture of the left upper block in the cluster (being sent by the screen) [Can be negative if the picture is not being drawn in the left upper block]
void serial_cluster_block::setPicture(picture* pic,coord posInPic)
{
    block** data = pic->getData();
    for(int i=0;i<m_num_of_blocks;i++)
    {
        if(pic->isValidPos(posInPic))
            m_ref_blocks[i].setData(data[posInPic.row][posInPic.col].getData(m_directions[i]));
        fixPos(&posInPic,m_directions[i]);
    }
}
void serial_cluster_block::fixPos(coord* pos,direction d)
{
    switch(d)
    {
        case RIGHT:
        {
            pos->col++;
            return;
        }
        case LEFT:
        {
            pos->col--;
            return;
        }
        case UP:
        {
            pos->row--;
            return;
        }
        case DOWN:
        {
            pos->row++;
            return;
        }
    }
}