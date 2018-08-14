//
// Created by amirdaichik on 08/08/2018.
//

#include <cstddef>
#include <iostream>
#include "referenceSerialCluster.h"

void referenceSerialCluster::allocData()
{
    int blockDim = block::getDim();
    m_numOfRows = blockDim;
    m_numOfCols = blockDim*serial_cluster_block::s_num_of_blocks;
    m_data_cur = new pixelData*[m_numOfRows]; //serial_cluster_block::s_num_of_blocks*
    m_data_next = new pixelData*[m_numOfRows];

    m_data_cur[0] = new pixelData[m_numOfCols*m_numOfRows];
    m_data_next[0] = new pixelData[m_numOfCols*m_numOfRows];

    for(int i=0;i<m_numOfRows;i++)
    {
        m_data_cur[i] = m_data_cur[0] + i*m_numOfCols;
        m_data_next[i] = m_data_next[0] + i*m_numOfCols;
    }
}
referenceSerialCluster::referenceSerialCluster()
{
    m_myCluster = NULL;
    allocData();
}
referenceSerialCluster::referenceSerialCluster(serial_cluster_block* myCluster)
{
    m_myCluster = myCluster;
    //allocData();
}
referenceSerialCluster::~referenceSerialCluster() {
    delete[] m_data_cur[0];
    delete[] m_data_next[0];
    delete[] m_data_cur;
    delete[] m_data_next;
}
void referenceSerialCluster::setMyCluster(serial_cluster_block* myCluster)
{
    m_myCluster = myCluster;
}
void referenceSerialCluster::updateData()
{
    for(int i=0;i<m_numOfRows;i++)
    {
        for(int j=0;j<serial_cluster_block::s_num_of_blocks;j++)
        {
            m_myCluster->m_ref_blocks[j].copyRow(i,&m_data_next[i][j*block::getDim()]);
        }
    }
    m_isNextValid = true;
}
bool referenceSerialCluster::switchData()
{
    if(!m_isNextValid)
        return false;
    pixelData** tmp = m_data_cur;
    m_data_cur = m_data_next;
    m_data_next = tmp;
    m_isNextValid = false;
    return true;
}
void referenceSerialCluster::print()
{
    std::cout<<"referenceSerialClusterPrint ["<<m_numOfRows<<"x"<<m_numOfCols<<"]"<<std::endl;
    for(int i=0;i<m_numOfRows;i++)
    {
        for(int j=0;j<m_numOfCols;j++)
            std::cout<<m_data_cur[i][j].r<<" ";
        std::cout<<std::endl;
    }
}
void referenceSerialCluster::test()
{
    block::setDim(4);
    direction direct[] = {RIGHT,RIGHT,RIGHT,DOWN,DOWN,LEFT,LEFT,UP,RIGHT};
    serial_cluster_block::init(9,direct);
    serial_cluster_block s = serial_cluster_block();
    coord dim = s.getRectangleDim();
    //std::cout<<"dim: ["<<dim.row<<"x"<<dim.col<<"]"<<std::endl;
    pixelData** d;
    d = new pixelData*[4];
    d[0] = new pixelData[4*8];
    for(int i=0;i<4;i++) {
        d[i] = d[0] + 8*i;
        for (int j = 0; j < 8; j++) {
            if (i == 0 || j == 7)
                d[i][j].r = 5;
            else
                d[i][j].r = 0;
               // std::cout << i<<","<<j<<"="<<d[i][j].r <<" add=0x"<<&d[i][j].r<<std::endl;
        }
    }
    coord dataSize;
    dataSize.row = 1;
    dataSize.col = 2;
    //std::cout<<"Before pic:"<<d[0][4].r<<std::endl;
    picture p = picture(dataSize,d);
    //std::cout<<"After pic:"<<d[0][4].r<<std::endl;
    block** b = p.getData();
    dataSize = p.getPicSize();
    //std::cout<<"picture:";
    for(int i=0;i<dataSize.row;i++)
    {
        for(int j=0;j<dataSize.col;j++)
        {
            //std::cout << "b[" << i <<"]["<< j<<"]"<<std::endl;
            //b[i][j].printBlock();
        }
    }
    coord posInPic;
    posInPic.row = -1;
    posInPic.col = 0;
    s.setPicture(&p,posInPic);
    //posInPic.row = 0;
    //posInPic.col = 2;
    //s.setPicture(&p,posInPic);
    std::cout<<"s.print()"<<std::endl;
    s.print();
    referenceSerialCluster rs;
    rs.setMyCluster(&s);
    rs.updateData();
    rs.switchData();
    rs.print();

    delete[] d[0];
    delete[] d;
}