//
// Created by amirdaichik on 26/07/2018.
//

#include "referenceBlock.h"
#include <stddef.h>
#include <iostream>

typedef char color;
typedef struct colorData{
	color r;
	color g;
	color b;
	colorData(){
		r = g = b = 0;
	}
	/*struct colorData& operator=(const struct colorData& other)
		r = other.r;
		g = other.g;
		b = other.b;
	}*/
}colorData;
referenceBlock::referenceBlock()
{
    m_data = NULL;
	//m_needToFree = false;
}
void referenceBlock::setData(pixelData** data,colorData c);//, bool needToFree)
{
	/*if(m_needToFree)
	{
		delete[] m_data[0];
		delete[] m_data;
	}*/
    m_data = data;
	m_color = c; // COPY CONTRUCTOR TODO
}
void referenceBlock::clean()
{
	/*if(m_needToFree)
	{
		delete[] m_data[0];
		delete[] m_data;
	}*/	
    m_data = NULL;
	m_color = colorData();
}
pixelData** referenceBlock::getData() // CAN BE NULL
{
    return m_data;
}
void referenceBlock::copyRow(int row,colorData* buffer)
{
    for(int i=0;i<block::getDim();i++)
    {
        if(m_data != NULL && m_data[row][i].bit)
            buffer[i] = m_color;
        else {
            buffer[i] = colorData();
        }
    }
}

void referenceBlock::print(){
    int s_dim= block::getDim();
    if(m_data == NULL){
        std::cout<<"NULL"<<std::endl;
        return;
    }
    for(int i=0;i<s_dim;i++)
    {
        for(int j=0;j<s_dim;j++)
        {
            if(m_data[i][j].r == 0)
                std::cout<<"  ";
            else
                std::cout<<m_data[i][j].r<<" ";
        }
        std::cout<<std::endl;
    }
}