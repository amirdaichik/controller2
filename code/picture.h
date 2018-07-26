//
// Created by amirdaichik on 26/07/2018.
//

#ifndef PROJECT_PICTURE_H
#define PROJECT_PICTURE_H
#include "block.h"
class picture{
private:
    coord m_picSize;
    block** m_blocks;
public:
    picture(coord dim, pixelData** d);
    ~picture();
    static void test();
    block** getData();
//	block* getBlock(int i,int j);
    coord getPicSize();
    bool isValidPos(coord pos);
};


#endif //PROJECT_PICTURE_H
