//
// Created by amirdaichik on 26/07/2018.
//

#include <iostream>
#include "picture.h"
picture::picture(coord picSize, pixelData** d)
{
    m_picSize = picSize;

    m_blocks = new block*[picSize.row];
    m_blocks[0] = new block[picSize.row*picSize.col];

    int dim = block::getDim();
    for(int i=0;i<picSize.row;i++)
    {
        m_blocks[i] = m_blocks[0] + i*picSize.col;
        for(int j=0;j<picSize.col;j++)
        {
            coord offset;
            offset.row = dim*i;
            offset.col = dim*j;
            //std::cout<<"block="<<"["<<i<<"]"<<"["<<j<<"]"<<" offset = "<<offset.row<<" "<<offset.col<<std::endl;
            m_blocks[i][j].setData_copy(d,offset);
        }
    }

}
picture::picture(coord picSize)
{
    m_picSize = picSize;
    m_blocks = NULL;
}

bool picture::isValidPos(coord pos)
{
    //std::cout<<"isValidPos = "<<pos.row<<" "<<pos.col;
    if(pos.row<0 || pos.row >= m_picSize.row) {
        //std::cout<<" FALSE" << std::endl;
        return false;
    }
    if(pos.col<0 || pos.col >= m_picSize.col) {
        //std::cout<<" FALSE" << std::endl;
        return false;
    }
    //std::cout<<" TRUE"<<std::endl;
    return true;
}
picture::~picture()
{
    if(m_blocks!=NULL) {
        delete[] m_blocks[0];
        delete[] m_blocks;
    }
}
block** picture::getData()
{
    return m_blocks;
}
coord picture::getPicSize()
{
    return m_picSize;
}
void picture::test(){
    block::setDim(2);

    pixelData** d;
    d = new pixelData*[10];
    d[0] = new pixelData[10*10];
    for(int i=0;i<10;i++) {
        d[i] = d[0] + 10*i;
        for (int j = 0; j < 10; j++) {
            if (j == 2 || i == 2)
                d[i][j].r = 5;
            else
                d[i][j].r = 0;
            std::cout<<d[i][j].r<< " ";
        }
        std::cout<<std::endl;
    }
    coord dataSize;
    dataSize.row = 5;
    dataSize.col = 5;
    picture p = picture(dataSize,d);
    block** b = p.getData();
    dataSize = p.getPicSize();
    for(int i=0;i<dataSize.row;i++)
    {
        for(int j=0;j<dataSize.col;j++)
        {
            std::cout << "b[" << i <<"]["<< j<<"]"<<std::endl;
            b[i][j].printBlock();
        }
    }
}
coord picture::calcFrameSize(picture** pics,int sizeOfPics) {
    coord picsFrameSize;
    for(int i=0;i<sizeOfPics;i++)
    {
        coord curPicSize = pics[i]->getPicSize();
        //std::cout<<"PicSize["<<i<<"]="<<curPicSize.row<<"x"<<curPicSize.col<<std::endl;

        picsFrameSize.col += curPicSize.col;
        if(curPicSize.row > picsFrameSize.row)
            picsFrameSize.row = curPicSize.row;

        //std::cout<<"frameNewSize["<<i<<"]="<<picsFrameSize.row<<"x"<<picsFrameSize.col<<std::endl;
    }
    return picsFrameSize;
}

void picture::print()
{
    for(int i=0;i<m_picSize.row;i++) {
        for (int j = 0; j < m_picSize.col; j++) {
            std::cout << "block [" << i << "][" << j << "]:" << std::endl;
            m_blocks[i][j].printBlock();
        }
    }
}