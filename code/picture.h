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
    picture(coord dim);
    ~picture();
    static void test();
    block** getData();
//	block* getBlock(int i,int j);
    coord getPicSize();
    bool isValidPos(coord pos);
    void print();

    static picture* createDummyPic(coord size);
    static coord calcFrameSize(picture** pics,int sizeOfPics =1 );
};


#endif //PROJECT_PICTURE_H
