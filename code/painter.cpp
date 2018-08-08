//
// Created by amirdaichik on 08/08/2018.
//

#include <iostream>
#include "painter.h"
#include "screen.h"
painter painter::s_thePainter;
painter::painter()
{
    m_numOfWorkers = 0;
}
painter::~painter()
{
    if(m_numOfWorkers)
    {
        delete[] m_refCluster;
        delete[] m_workers;
    }
}
void painter::init(int numOfWorkers) // TODO: numOfWorkers is unnesesery, can be get from the screen
{
    m_numOfWorkers = numOfWorkers;
    m_workers = new painterWorker[numOfWorkers];
    m_refCluster = new referenceSerialCluster[numOfWorkers];
    for(int i=0;i<numOfWorkers;i++) {
        m_refCluster[i].setMyCluster(screen::getInstance()->getCluster(i));
        m_workers[i].setCluster(&m_refCluster[i]);
    }
}
void painter::paintIter()
{
    bool finished = false;
    for(int i=0;i<m_numOfWorkers;i++){
        finished = m_workers[i].paintIter();
    }
    if(finished){
        switchToNextBuffer();
    }
}
void painter::switchToNextBuffer()
{
    for(int i=0;i<m_numOfWorkers;i++)
    {
        m_refCluster[i].switchData();
    }
}
void painter::latchScreen()
{
    for(int i=0;i<m_numOfWorkers;i++)
        m_refCluster[i].updateData();
}
painter* painter::getInstance()
{
    return &s_thePainter;
}
