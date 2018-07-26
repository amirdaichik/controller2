#include "picture.h"
picture::picture(coord picSize, pixelData** d)
{
	m_picSize.row = picSize.row;
	m_picSize.col = picSize.col;
	
	m_blocks = new *block[picSize.row];
	m_blocks[0] = new block[picSize.row*picSize.col];
	int dim = block::getDim();
	for(int i=0;i<picSize.row;i++)
	{
		m_blocks[i] = m_blocks[0] + i*picSize.row;
		for(int j=0;j<picSize.col)
		{
			m_blocks[i][j].setData_Copy(d,dim*i,dim*j);
		}
	}
	//delete[] d[0];
	//delete[] d; 
}
picture::~picture();
{
	delete[] m_blocks[0];
	delete[] m_blocks;
}
block** picture::getData()
{
	return m_blocks;
}
int picture::getNumOfRows()
{
	return m_picSize.row;
}
int picture::getNumOfCols()
{
	return m_picSize.col;
}