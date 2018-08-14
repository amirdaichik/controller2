//
// Created by amirdaichik on 08/08/2018.
//

#ifndef PROJECT_PAINTER_H
#define PROJECT_PAINTER_H


#include "painterWorker.h"
#include "register.h"
class painter {
private:
    painterWorker* m_workers;// painter workers, each one in charge of one serial cluster
    referenceSerialCluster* m_refCluster; // continues buffers which contains the data of every cluster
    int m_numOfWorkers; // num of workers
    int m_curRow;
	//(TODO: Show Golan)
	posRegister* m_posReg;
	int m_numOfLats;
	int m_numOfClks;
	int m_numOfOEs;
	register* m_clks;
	register* m_OEs;
	register* m_lats;
	
    painter();
    ~painter();
public:
    static painter s_thePainter;
	//Get the instance of the painter
	static painter* getInstance();
	//Initialize of the workers (TODO: Show Golan)
	void init(posRegister pos[],int numOfClks,register* clk,int numOfOEs, register* OEs,int numOfLats, register* lats, register** redRegs,register** greenRegs,register** blueRegs);
	//This function will execute the sequence of painting para pixels by all the workers
    void paintIter();
	// Update the next buffer of all the reference serial cluster 
    void latchScreen();
	// Switch between old buffer and new buffer (TODO: Is it needed ?)
    void switchToNextBuffer();
};


#endif //PROJECT_PAINTER_H
