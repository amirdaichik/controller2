//
// Created by amirdaichik on 26/07/2018.
//

#include "referenceBlock.h"
#include <stddef.h>

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