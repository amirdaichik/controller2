//
// Created by amirdaichik on 08/08/2018.
//

#ifndef PROJECT_PAINTER_H
#define PROJECT_PAINTER_H


#include "painterWorker.h"

class painter {
private:
    painterWorker* m_workers;
    referenceSerialCluster* m_refCluster;
    int m_numOfWorkers;
    painter();
    ~painter();
public:
    static painter s_thePainter;
    void paintIter();
    void init(int numOfWorkers); // it should happen AFTER the screen has been inited
    static painter* getInstance();
    void latchScreen();
    void switchToNextBuffer();
};


#endif //PROJECT_PAINTER_H
