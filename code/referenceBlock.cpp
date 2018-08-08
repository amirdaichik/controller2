//
// Created by amirdaichik on 26/07/2018.
//

#include "referenceBlock.h"
#include <stddef.h>
#include <iostream>

referenceBlock::referenceBlock()
{
    m_data = NULL;
}
void referenceBlock::setData(pixelData** data)
{
    m_data = data;
}
void referenceBlock::clean()
{
    m_data = NULL;
}
pixelData** referenceBlock::getData() // CAN BE NULL
{
    return m_data;
}
void referenceBlock::copyRow(int row,pixelData* buffer)
{
    for(int i=0;i<block::getDim();i++)
    {
        if(m_data != NULL)
            buffer[i] = m_data[row][i];
        else {
            buffer[i].r = 0;
            buffer[i].g = 0;
            buffer[i].b = 0;
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