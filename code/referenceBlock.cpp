#include "referenceBlock.h"
//This class will keep the relevant data from the block in the relevant direction only.
void referenceBlock::setData(block *b,direction d)
{
	m_data = b.getData(d);
}
void referenceBlock::getData()
{
	return m_data;
}