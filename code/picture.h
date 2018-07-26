#ifndef picture_h
#define picture_h
#include "block.h"
class picture{
	private:
	int m_num_block_rows;
	int m_num_block_cols;
	block** m_blocks;
	public:
	picture(coord dim, pixelData** d);
	~picture();
	block** getData();
//	block* getBlock(int i,int j);
	int getNumOfRows();
	int getNumOfCols();
}
#endif