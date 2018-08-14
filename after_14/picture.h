//
// Created by amirdaichik on 26/07/2018.
//

#ifndef PROJECT_PICTURE_H
#define PROJECT_PICTURE_H
#include "block.h"
class picture{
private:
	// Picture dimentions (In blocks), actualy dim would be picSize*blockDim
    coord m_picSize;
	// The block data of the picture , the size of this array is based on m_picSize
    block** m_blocks;
public:
	// Picture constructor
    picture(coord dim, pixelData** d); 
	// Empty picture constructor
    picture(coord dim); 
    ~picture();
	//Returns all the blocks
    block** getData();
	//Returns the size of the picture
    coord getPicSize();	
	//Returns true if a given pos is a valid pos in the picture (It is based on the picSize)
    bool isValidPos(coord pos);    
	//This function will calc the frame size of an array of pics which will be put next to each other
    static coord calcFrameSize(picture** pics,int sizeOfPics =1 );
	
#ifdef DEBUG
    static void test();
	void print();
#endif
};


#endif //PROJECT_PICTURE_H
