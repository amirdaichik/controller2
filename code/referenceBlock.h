#ifndef referenceBlock_h
#define referenceBlock_h
#include "block.h"
class referenceBlock{
	private:
	pixelData** m_data;
	public:
	void setData(block *b,direction d);
	pixelData** getData();
}
#endif