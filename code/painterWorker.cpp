//
// Created by amirdaichik on 08/08/2018.
//

#include <iostream>
#include "painterWorker.h"

void painterWorker::setCluster(referenceSerialCluster* myCluster){
    m_myCluster = myCluster;
}
void painterWorker::paintPixel(){ // TODO: support paralizm paint
    std::cout<< m_myCluster->m_data_cur[m_curPos.row][m_curPos.col].r<<" ";
}
void painterWorker::updateCoord(){ //TODO: support paralizm paint
    m_curPos.col = (m_curPos.col + 1) % m_myCluster->m_numOfCols;
    if(!m_curPos.col)
    {
        m_curPos.row = (m_curPos.row+1)% m_myCluster->m_numOfRows;
    }
}
bool painterWorker::paintIter()
{
    paintPixel();
    updateCoord();
    return m_curPos.row == 0 && m_curPos.col == 0;
}