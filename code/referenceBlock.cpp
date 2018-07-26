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
            std::cout<<m_data[i][j].r<<" ";
        }
        std::cout<<std::endl;
    }
}