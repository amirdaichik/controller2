//
// Created by amirdaichik on 26/07/2018.
//

#include <iostream>
#include "block.h"

int block::s_dim ;
int block::s_numOfParall;

// initiate the block class with dimension and parallelize as requested
void block::init(int dim,int para)
{
	s_dim = dim;
	s_numOfParall = para;
}

// This function will return the dimension of the blocks
int block::getDim(){
    return s_dim;
}

block::block()
{
    for(int i=0;i<NUM_OF_DIRECTIONS;i++)
    {
        m_data[i] = new pixelData*[s_dim];
        m_data[i][0] = new pixelData[s_dim*s_dim];
        for(int j=0;j<s_dim;j++)
        {
            m_data[i][j] = m_data[i][0] + s_dim*j;
        }
    }
}

block::~block()
{
    for(int i=0;i<NUM_OF_DIRECTIONS;i++)
    {
        delete[] m_data[i][0];
        delete[] m_data[i];
    }
}

// This function will turn the source 90 degrees and will put it in dest
void block::turn90_comp(pixelData** source,pixelData** dest)
{
    pixelData** tmpBlock;
    if(source == dest) // if source equals to desk we cant use dest as tmp buffer , we need to allocate new buffer to work on
    {
        tmpBlock = new pixelData*[s_dim];
        tmpBlock[0] = new pixelData[s_dim*s_dim];
        for(int i=0;i<s_dim;i++)
            tmpBlock[i] = tmpBlock[0] + s_dim*i;
    }
    else
        tmpBlock = dest;
    for(int y=0;y<s_dim;y++)
    {
        for(int x=0;x<s_dim;x++)
        {
            int newX = s_dim - y - 1;
            int newY = x;
            tmpBlock[newY][newX] = source[y][x];// TODO : COPY constructor, maybe need to implement
        }
    }
    if(source == dest)
    {
        for(int i=0;i<s_dim;i++)
        {
            for(int j=0;j<s_dim;j++)
            {
                dest[i][j] = tmpBlock[i][j]; // TODO: Confirm that there is such thing as operator =
            }
            delete[] tmpBlock[i];
        }
        delete[] tmpBlock;
    }
}

//Unsued
void block::setData_noCopy(pixelData** d)
{
    m_data[RIGHT] = d;
    adjust_m_data();
}

//Will copy the data from d to the block , it will start coping from start coord 
void block::setData_copy(pixelData** d,coord start)
{
    for(int i=0;i<s_dim;i++)
    {
        for(int j=0;j<s_dim;j++)
        {
            m_data[RIGHT][i][j] = d[start.row+i][start.col+j]; // TODO: Copy constructor
        }
    }
    adjust_m_data();
}

// this function assumes that the right data is valid, and will set rest of the data based on the right block data , private function
void block::adjust_m_data()
{
    for(int i=1;i<NUM_OF_DIRECTIONS;i++)
    {
        turn90_comp(m_data[i-1],m_data[i]);
    }
}

//Will return the data in the requested direction
pixelData** block::getData(direction d)
{
    return m_data[d];
}

#ifdef DEBUG
void block::printBlock(direction d)
{
    for(int i=0;i<s_dim;i++)
    {
        for (int j = 0; j < s_dim; j++)
        {
            if(m_data[d][i][j].r == 0)
                std::cout<<"  ";
            else
                std::cout << m_data[d][i][j].bit << " ";
        }
        std::cout<<std::endl;
    }
}

void block::test(){
    block::setDim(6);
    block b;

    pixelData** d;
    d = new pixelData*[6];
    d[0] = new pixelData[6*6];
    for(int i=0;i<6;i++) {
        d[i] = d[0] + 6*i;
        for (int j = 0; j < 6; j++) {
            if (j == 1)
                d[i][j].r = 5;
            else
                d[i][j].r = 0;
            //std::cout<<d[i][j].r<< " ";
        }
        //std::cout<<std::endl;
    }

    coord start;
    start.col = 0;
    start.row = 0;
    b.setData_copy(d,start);

    std::cout << "right\n";

    for(int i=0;i<6;i++) {
        for (int j = 0; j < 6; j++) {
            std::cout << b.m_data[0][i][j].r << " ";
        }
        std::cout <<"\n";
    }
    std::cout << "down\n";
    for(int i=0;i<6;i++) {
        for (int j = 0; j < 6; j++) {
            std::cout << b.m_data[1][i][j].r << " ";
        }
        std::cout <<"\n";
    }
    std::cout << "left\n";
    for(int i=0;i<6;i++) {
        for (int j = 0; j < 6; j++) {
            std::cout << b.m_data[2][i][j].r << " ";
        }
        std::cout <<"\n";
    }
    std::cout << "up\n";
    for(int i=0;i<6;i++) {
        for (int j = 0; j < 6; j++) {
            std::cout << b.m_data[3][i][j].r << " ";
        }
        std::cout <<"\n";
    }

    delete[] d[0];
    delete[] d;

}
#endif