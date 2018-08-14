//
// Created by amirdaichik on 08/08/2018.
//

#include <iostream>
#include "painterWorker.h"
//TODO: add default constructor that allocate the array of m_red,m_blue,m_green
void painterWorker::setCluster(referenceSerialCluster* myCluster){
    m_myCluster = myCluster;
	//TODO GOLAN CONFIRM ME!
	m_curPos.col = m_myCluster->m_numOfCols-1;
	m_curPos.row = 0;
}
//Paint sequence
void painterWorker::paintPixel(){   //(TODO: Show Golan)
	int offset = block::getDim()/block::getPara();
	for(int i=0;i<block::getPara();i++)
	{
    	//std::cout<< m_myCluster->m_data_cur[m_curPos.row+i*offset][m_curPos.col].r<<" ";
    	m_red[i].write(m_myCluster->m_data_cur[m_curPos.row+i*offset][m_curPos.col].r);
		m_green[i].write(m_myCluster->m_data_cur[m_curPos.row+i*offset][m_curPos.col].g);
		m_blue[i].write(m_myCluster->m_data_cur[m_curPos.row+i*offset][m_curPos.col].b);
	}
}
//Update coord to the next valid pos TODO: Maybe need to go backward? 
void painterWorker::updateCoord(){ 
    m_curPos.col = (m_curPos.col - 1) % m_myCluster->m_numOfCols; // TODO AMIR CHANGED CHECK GOLAN!!
    if(!m_curPos.col)
    {
        m_curPos.row = (m_curPos.row+1)% (m_myCluster->m_numOfRows/block::getPara());
    }
}
// This function will be in chrage of drawing one pixel, and it will update the current pos. It will return TRUE once it finishes to draw the whole cluster
paintIterStatus painterWorker::paintIter() //(TODO: Show Golan)
{
	int prevRow = m_curPos.row;
    paintPixel();
    updateCoord();
	if(m_curPos.row == 0 && m_curPos.col == (m_myCluster->m_numOfCols-1);) // TODO CHECK! GOLAN
    	return FINISHED_SCREEN;
	if(prevRow != m_curPos.row)
		return NEW_LINE;
	return NOTHING_TO_UPDATE;
}
// This function attaches a painter worker to a pin in the controller
void painterWorker::setPin(colorType t, register& reg,int paraId) //(TODO: Show Golan)
{
	register& changeReg;
	switch(t)
	{
		case RED: changeReg = m_red[paraId];
		case GREEN: changeReg = m_green[paraId];
		case BLUE: changeReg = m_blue[paraId];
	}
	changeReg.setPin(reg.getPin());
}