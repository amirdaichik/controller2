//
// Created by amirdaichik on 31/07/2018.
//

#include <iostream>
#include "pictureDatabase.h"
pictureDatabase pictureDatabase::s_theDatabase;

pictureDatabase::pictureDatabase()
{
    for(int i=0;i<MAX_NUM_OF_PICTURES;i++)
    {
        m_isValidPicture[i] = false;
        m_pics[i] = NULL;
    }
    //init();
}
pictureDatabase::~pictureDatabase()
{
    for(int i=0;i<MAX_NUM_OF_PICTURES;i++)
    {
        if(m_isValidPicture[i])
            delete m_pics[i];
    }
}

typedef struct
{
    coord dim;
    pixelData** d;
} initData;


void buildEight(pixelData ***d)
{
    int dim = block::getDim();
    *d =  new pixelData*[block::getDim()];
    (*d)[0] = new pixelData[dim*dim];
    for(int i=0;i<dim;i++){
        (*d)[i] = (*d)[0] + dim*i;
        for(int j=0;j<dim;j++)
        {
            if(i==0 || i == dim-1 || j==0 || j == dim-1 || i == dim/2)
                (*d)[i][j].r = (*d)[i][j].g = (*d)[i][j].b = 5;
            else
                (*d)[i][j].r = (*d)[i][j].g = (*d)[i][j].b = 0;
        }
    }
}

void initializeDigitData(initData digitData[NUM_OF_DIGITS]){
    for(int i=0;i<NUM_OF_DIGITS;i++)
    {
        digitData[i].dim.col = 1;
        digitData[i].dim.row = 1;
        buildEight(&digitData[i].d);
    }
}
void initializeArrowData(initData arrowData[NUM_OF_ARROWS]){
    for(int i=0;i<NUM_OF_ARROWS;i++)
    {
        arrowData[i].dim.col = 1;
        arrowData[i].dim.row = 1;
        buildEight(&arrowData[i].d);
    }
}


void pictureDatabase::init(){
    initData arrowData[NUM_OF_ARROWS];
    initData digitData[NUM_OF_DIGITS];
    initializeArrowData(arrowData);
    initializeDigitData(digitData);

    int tmp;
    for(int i=0;i<NUM_OF_ARROWS;i++)
    {
        picture* pic = new picture(arrowData[i].dim,arrowData[i].d);
        addPicture(pic,&tmp,i);
    }
    for(int i=0;i<NUM_OF_DIGITS;i++)
    {
        picture* pic = new picture(digitData[i].dim,digitData[i].d);
        addPicture(pic,&tmp,NUM_OF_ARROWS+i);
    }
    for(int i=0;i<NUM_OF_ARROWS;i++)
    {
        delete[] arrowData[i].d[0];
        delete[] arrowData[i].d;
    }
    for(int i=0;i<NUM_OF_DIGITS;i++)
    {
        delete[] digitData[i].d[0];
        delete[] digitData[i].d;
    }
}
pictureDatabase* pictureDatabase::getInstance() {
    return &s_theDatabase;
}

bool pictureDatabase::addPicture(picture *pic,int* output,int offset)
{
    for(int i=offset;i<MAX_NUM_OF_PICTURES;i++)
    {
        if(!m_isValidPicture[i])
        {
            m_isValidPicture[i] = true;
            m_pics[i] = pic;
            *output = i;
            return true;
        }
    }
    return false;
}
bool pictureDatabase::removePicture(int index)
{
    if(index<NUM_OF_DIGITS+NUM_OF_ARROWS || index>=MAX_NUM_OF_PICTURES || !m_isValidPicture[index])
        return false;
    delete m_pics[index];
    m_pics[index] = NULL;
    m_isValidPicture[index] = false;
    return true;
}
bool pictureDatabase::getArrow(arrowDirection d,picture** output)
{
    int index = (int)d-START_ARROW_INDEX;
    if(index<0||index>=NUM_OF_ARROWS)
        return false;
    *output = m_pics[index];
    return true;
}
bool pictureDatabase::getDigit(int n,picture** output)
{
    if(n>=NUM_OF_DIGITS||n<0)
        return false;
    *output = m_pics[NUM_OF_ARROWS+n];
    return true;
}
bool pictureDatabase::getPicture(int index,picture** output)
{
    if(index<0||index>=MAX_NUM_OF_PICTURES||!m_isValidPicture[index])
        return false;
    *output = m_pics[index];
    return true;
}

void pictureDatabase::test()
{
    std::cout<<"TEST"<<std::endl;
    block::setDim(32);
    pictureDatabase* database = pictureDatabase::getInstance();
    database->init();
    picture* output;
    database->getDigit(2,&output);
    output->print();
}