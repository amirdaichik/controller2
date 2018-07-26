#ifndef picture_h
#define picture_h
#include "block.h"
class picture{
	private:
	coord picSize;
	block** m_blocks;
	public:
	picture(coord dim, pixelData** d);
	~picture();
	block** getData();
//	block* getBlock(int i,int j);
	coord getPicSize();
}
#endif