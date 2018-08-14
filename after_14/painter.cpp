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
	m_curRow = 0;
}
painter::~painter()
{
    if(m_numOfWorkers)
    {
        delete[] m_refCluster;
        delete[] m_workers;
    }
}
//Get the instance of the painter
painter* painter::getInstance()
{
    return &s_thePainter;
}
//Initialize of the workers TODO: Show golan
void painter::init(posRegister pos[],int numOfClks,register* clk,int numOfOEs, register* OEs,int numOfLats, register* lats, register** redRegs,register** greenRegs,register** blueRegs)
{
	m_lats = lats;
	m_OEs = OEs;
	m_clks = clk;
	
	m_numOfClks = numOfClks;
	m_numOfOEs = numOfOEs;
	m_numOfLats = numOfLats;
	
    m_numOfWorkers = screen::getInstance()->getNumOfClusters();
    m_workers = new painterWorker[numOfWorkers];
    m_refCluster = new referenceSerialCluster[numOfWorkers];
    for(int i=0;i<numOfWorkers;i++) {
        m_refCluster[i].setMyCluster(screen::getInstance()->getCluster(i));
        m_workers[i].setCluster(&m_refCluster[i]);
		for(int j=0;j<block::getPara();j++)
		{
			m_workers[i].setPin(RED,redColors[i][j],j);
			m_workers[i].setPin(GREEN,greenColors[i][j],j);
			m_workers[i].setPin(BLUE,blueColors[i][j],j);
		}
    }
}
//This function will execute the sequence of painting para pixels by all the workers (TODO: Show Golan)
void painter::paintIter()
{
    paintIterStatus status;
    for(int i=0;i<m_numOfWorkers;i++){ // Write the color for all the clusters
        status = m_workers[i].paintIter();
    }
	for(int i=0;i<m_numOfClks;i++) // Move to the next register TODO: What will happen in the last clk??
	{
		m_clks[i].toggle();
	}  
	int tmpRow = m_curRow; // I need it because in case I finished the screen, I set the curRow to zero
	switch(status)
	{
		case FINISHED_SCREEN:
		{
			m_curRow = 0;
			switchToNextBuffer(); 
			// No need to add break because finished screen is also next line
		}
		case NEW_LINE:
		{
			for(int i=0;i<m_numOfPos;i++) // setup the row register
			{
				m_posReg.writeBitFromVal(tmpRow);
			}
			if(m_curRow != 0)
				m_curRow ++;
			for(int i=0;i<m_numOfLat;i++)//latch the line
			{
				m_lats[i].toggle();
			}
			for(int i=0;i<m_numOfOE;i++) // Output enable? (Should it done every row or once in a screen?)
			{
				m_OEs[i].toggle();
			}
			break;
		}	
	}
}
// Switch between old buffer and new buffer (TODO: Is it needed ?)
void painter::switchToNextBuffer()
{
    for(int i=0;i<m_numOfWorkers;i++)
    {
        m_refCluster[i].switchData();
    }
}
// Update the next buffer of all the reference serial cluster 
void painter::latchScreen()
{
    for(int i=0;i<m_numOfWorkers;i++)
        m_refCluster[i].updateData();
}
