//
// Created by amirdaichik on 26/07/2018.
//

#ifndef PROJECT_REFERENCEBLOCK_H
#define PROJECT_REFERENCEBLOCK_H
#include "block.h"

//ReferenceBlock is an object which points to a data in specific direction of an actual block 
class referenceBlock{
private:
	//Pointer to the data from the block which the referenceBlock points upppon
	// if m_data is null , it means the block is empty block
    pixelData** m_data;
	//bool needToFree;
	colorData c;
public:
    referenceBlock();
	//Sets the data of the referenceBlock
    void setData(pixelData** d,colorData c); //,bool needToFree = false);
	//Returns the data of the referenceBlock
    pixelData** getData();
	//cleans the referenceBlock
    void clean();
	//Coppies a specific row from the datablock to a buffer
	// In case the data is null, it will copy zeros to the buffer
	void copyRow(int row,colorData* buffer);
    void print();
    
};

#endif //PROJECT_REFERENCEBLOCK_H
