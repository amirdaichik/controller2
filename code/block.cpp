//
// Created by amirdaichik on 26/07/2018.
//

#include <iostream>
#include "block.h"
int block::s_dim ;
int block::s_numOfParall;
void block::setDim(int dim)
{
    s_dim = dim;
}
int block::getDim(){
    return s_dim;
}
void block::setPara(int para)
{
    s_numOfParall = para;
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
//	m_curData = m_data[RIGHT];
}
/*
block::block(const block& b)
{
	m_curDirection = b.m_curDirection
	for(int i=0;i<NUM_OF_DIRECTIONS;i++)
	{
		m_data[i] = new *pixelData[s_dim];
		m_data[i][0] = new pixelData[s_dim*s_dim]
		for(int j=1;j<s_dim;j++)
		{
			m_data[i][j] = m_data[i][0] + s_dim*j;
			for(int k=0;k<s_dim;k++)
			{
				m_data[i][j][k].r = b.m_data[i][j][k].r;
				m_data[i][j][k].g = b.m_data[i][j][k].g;
				m_data[i][j][k].b = b.m_data[i][j][k].b;
			}
		}
	}
}
*/
block::~block()
{
    for(int i=0;i<NUM_OF_DIRECTIONS;i++)
    {
        delete[] m_data[i][0];
        delete[] m_data[i];
    }
}
/*
block& block::operator=(const block& b)
{
	m_curDirection = b.m_curDirection;
	for(int i=0;i<NUM_OF_DIRECTIONS;i++)
	{
		for(int j=0;j<s_dim;j++)
		{
			for(int k=0;k<s_dim;k++)
			{
				m_data[i][j][k].r = b.m_data[i][j][k].r;
				m_data[i][j][k].g = b.m_data[i][j][k].g;
				m_data[i][j][k].b = b.m_data[i][j][k].b;
			}
		}
	}
	return this;
}

bool block::turnData(direction wantedDirection)
{
	bool wasTurned = false;
	int numOfTimesToTurn = (wantedDirection - m_curDirection)%NUM_OF_DIRECTIONS;
	for(int i=0;i<numOfTimesToTurn;i++)
	{
		turn90();
		wasTurned = true;
	}
	m_curDirection = wantedDirection;
	return wasTurned;
}
*/
void block::turn90_comp(pixelData** source,pixelData** dest)
{
    pixelData** tmpBlock;
    if(source == dest)
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
            tmpBlock[newY][newX].r = source[y][x].r;
            tmpBlock[newY][newX].g = source[y][x].g;
            tmpBlock[newY][newX].b = source[y][x].b;
        }
    }
    if(source == dest)
    {
        for(int i=0;i<s_dim;i++)
        {
            for(int j=0;j<s_dim;j++)
            {
                dest[i][j].r = tmpBlock[i][j].r;
                dest[i][j].g = tmpBlock[i][j].g;
                dest[i][j].b = tmpBlock[i][j].b;
            }
            delete[] tmpBlock[i];
        }
        delete[] tmpBlock;
    }
}
/*
bool block::turn90()
{
	m_curDirection = (m_curDirection+1)%NUM_OF_DIRECTIONS;
}
*/
void block::setData_noCopy(pixelData** d)
{
    m_data[RIGHT] = d;
    adjust_m_data();
}

void block::setData_copy(pixelData** d,coord start)
{
    for(int i=0;i<s_dim;i++)
    {
        for(int j=0;j<s_dim;j++)
        {
            //std::cout <<"c "<< start.row+i<<","<<start.col+j<<"="<<d[start.row+i][start.col+j].r <<" add=0x"<<&d[start.row+i][start.col+j].r<<std::endl;
            m_data[RIGHT][i][j].r = d[start.row+i][start.col+j].r;
            m_data[RIGHT][i][j].g = d[start.row+i][start.col+j].g;
            m_data[RIGHT][i][j].b = d[start.row+i][start.col+j].b;
        }
    }
    adjust_m_data();
}
void block::adjust_m_data()
{
    for(int i=1;i<NUM_OF_DIRECTIONS;i++)
    {
        turn90_comp(m_data[i-1],m_data[i]);
    }
}
/*pixelData** block::getData()
{
	return m_data[m_curDirection];
}
*/
pixelData** block::getData(direction d)
{
    return m_data[d];
}

/*void block::printBlockRow(direction d,int row){
    for(int j=0;j<s_dim;j++)
    {
        std::cout<< m_data[d][row][j].r << " ";
    }
}*/
void block::printBlock(direction d)
{
    for(int i=0;i<s_dim;i++)
    {
        for (int j = 0; j < s_dim; j++)
        {
            if(m_data[d][i][j].r == 0)
                std::cout<<"  ";
            else
                std::cout << m_data[d][i][j].r << " ";
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