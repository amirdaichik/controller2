//
// Created by amirdaichik on 26/07/2018.
//

#ifndef PROJECT_REFERENCEBLOCK_H
#define PROJECT_REFERENCEBLOCK_H
#include "block.h"

class referenceBlock{
private:
    pixelData** m_data;
public:
    referenceBlock();
    void setData(pixelData** d);
    pixelData** getData();
    void clean();
};

#endif //PROJECT_REFERENCEBLOCK_H
