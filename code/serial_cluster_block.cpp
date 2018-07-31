//
// Created by amirdaichik on 26/07/2018.
//

#include <iostream>
#include "serial_cluster_block.h"


void serial_cluster_block::init(int num_of_blocks,direction* d)
{
	s_num_of_blocks = num_of_blocks;
		
	s_rectangle_dim.col = 0; // The first block is also being calculated
    s_rectangle_dim.row = 1; // And we assume that the first block is turning right
    direction dimCalcState = RIGHT;
    for(int i=0;i<s_num_of_blocks;i++)
    {
        if(d[i] == RIGHT && dimCalcState == RIGHT) {
            s_rectangle_dim.col++;
        }
        else {
            dimCalcState = DOWN;
        }
        if(d[i] == DOWN && dimCalcState == DOWN)
            s_rectangle_dim.row++;
        else if(dimCalcState == DOWN)
            dimCalcState = LEFT;
        s_directions[i] = d[i];
    }	
	
}

serial_cluster_block::serial_cluster_block()
{
    m_ref_blocks = new referenceBlock[s_num_of_blocks];

	/*
	m_rectangle_dim.col = 0; // The first block is also being calculated
    m_rectangle_dim.row = 1; // And we assume that the first block is turning right
	m_directions = new direction[s_num_of_blocks];
    direction dimCalcState = RIGHT;
    for(int i=0;i<s_num_of_blocks;i++)
    {
        if(d[i] == RIGHT && dimCalcState == RIGHT) {
            m_rectangle_dim.col++;
        }
        else {
            dimCalcState = DOWN;
        }
        if(d[i] == DOWN && dimCalcState == DOWN)
            m_rectangle_dim.row++;
        else if(dimCalcState == DOWN)
            dimCalcState = LEFT;
        m_directions[i] = d[i];
    }
    */

}
void serial_cluster_block::print(){
    for(int i=0;i<s_num_of_blocks;i++)
    {
        std::cout<<"Direction = "<<s_directions[i]<<std::endl;
        m_ref_blocks[i].print();
    }
}

serial_cluster_block::~serial_cluster_block()
{
    delete[] m_ref_blocks;
}
void serial_cluster_block::clean()
{
    for(int i=0;i<m_num_of_blocks;i++)
        m_ref_blocks[i].clean();
}
coord serial_cluster_block::getRectangleDim()
{
    return s_rectangle_dim;
}
// posInPic is the offset in the picture of the left upper block in the cluster (being sent by the screen) [Can be negative if the picture is not being drawn in the left upper block]
void serial_cluster_block::setPicture(picture* pic,coord posInPic)
{
    block** data = pic->getData();
    for(int i=0;i<s_num_of_blocks;i++)
    {
        if(pic->isValidPos(posInPic))
            m_ref_blocks[i].setData(data[posInPic.row][posInPic.col].getData(s_directions[i]));
        fixPos(&posInPic,s_directions[i]);
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




void serial_cluster_block::test()
{
    block::setDim(4);
    direction direct[] = {RIGHT,RIGHT,RIGHT,DOWN,DOWN,LEFT,LEFT,UP,RIGHT};
	serial_cluster_block::init(9,direct);
    serial_cluster_block s = serial_cluster_block();
    coord dim = s.getRectangleDim();
    std::cout<<"dim: ["<<dim.row<<"x"<<dim.col<<"]"<<std::endl;

    pixelData** d;
    d = new pixelData*[4];
    d[0] = new pixelData[4*4];
    for(int i=0;i<4;i++) {
        d[i] = d[0] + 4*i;
        for (int j = 0; j < 4; j++) {
            if (i == 0 || j == 3)
                d[i][j].r = 5;
            else
                d[i][j].r = 0;
            //std::cout<<d[i][j].r<< " ";
        }
        //std::cout<<std::endl;
    }
    coord dataSize;
    dataSize.row = 1;
    dataSize.col = 1;

    picture p = picture(dataSize,d);

    block** b = p.getData();
    dataSize = p.getPicSize();
    std::cout<<"picture:";
    for(int i=0;i<dataSize.row;i++)
    {
        for(int j=0;j<dataSize.col;j++)
        {
            std::cout << "b[" << i <<"]["<< j<<"]"<<std::endl;
            b[i][j].printBlock();
        }
    }

    coord posInPic;
    posInPic.row = 1;
    posInPic.col = 1;
    s.setPicture(&p,posInPic);
    /*posInPic.row = 0;
    posInPic.col = 2;
    s.setPicture(&p,posInPic);
     */
    std::cout<<"s.print()"<<std::endl;
    s.print();

    delete[] d[0];
    delete[] d;

}