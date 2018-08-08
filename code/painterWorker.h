//
// Created by amirdaichik on 08/08/2018.
//

#ifndef PROJECT_PAINTERWORKER_H
#define PROJECT_PAINTERWORKER_H


#include "referenceSerialCluster.h"

class painterWorker {
private:
    referenceSerialCluster* m_myCluster;
    coord m_curPos;
public:
    void setCluster(referenceSerialCluster* myCluster);
    bool paintIter();
    void paintPixel();
    void updateCoord();
};


#endif //PROJECT_PAINTERWORKER_H
