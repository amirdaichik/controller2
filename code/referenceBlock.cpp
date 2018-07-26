#include "referenceBlock.h"
//This class will keep the relevant data from the block in the relevant direction only.
referenceBlock::referenceBlock()
{
	m_data = NULL;
}
void referenceBlock::setData(block *b,direction d)
{
	m_data = b.getData(d);
}
void referenceBlock::clean()
{
	m_data = NULL;
}
pixelData** referenceBlock::getData() // CAN BE NULL
{
	return m_data;
}