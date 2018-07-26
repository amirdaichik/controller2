#ifndef referenceBlock_h
#define referenceBlock_h
#include "block.h"
class referenceBlock{
	private:
	pixelData** m_data;
	public:
	referenceBlock();
	void setData(block *b,direction d);
	pixelData** getData();
	void clean();
}
#endif