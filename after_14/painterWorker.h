//
// Created by amirdaichik on 08/08/2018.
//

#ifndef PROJECT_PAINTERWORKER_H
#define PROJECT_PAINTERWORKER_H

#include "referenceSerialCluster.h"

typedef enum{FINISHED_SCREEN,NEW_LINE,NOTHING_TO_UPDATE} paintIterStatus; // TODO: Show golan
class painterWorker {
private:
    referenceSerialCluster* m_myCluster;
    coord m_curPos;
	//(TODO: Show Golan)
	register* m_red;
	register* m_green;
	register* m_blue;
	//Paint sequence
	void paintPixel();
	//Update coord to the next valid pos
    void updateCoord();
public:
	painterWorker(); // TODO: allocate m_red, m_green and m_blue based on para of block
	~painterWorker();
	//This function is in charge of attaching worker with a cluster
    void setCluster(referenceSerialCluster* myCluster);
	// This function will be in chrage of drawing one pixel, and it will update the current pos. It will return TRUE once it finishes to draw the whole cluster
    paintIterStatus paintIter(); 
	void setPin(colorType t, register* r, int paraId); // (TODO: Show Golan)
};


#endif //PROJECT_PAINTERWORKER_H
