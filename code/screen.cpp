//
// Created by amirdaichik on 26/07/2018.
//

#include "screen.h"
screen screen::theScreen;
screen* screen::getInstance(){
    return &theScreen;
}

screen::screen()
{
    m_numOfClusters = 0;
}
void screen::addPicture(picture *pic,coord posInScreen)
{
    //coord picSize = pic->getPicSize();
    //int lastRowInPic = posInScreen.row + picSize.row -1;
    //coord curPosInScreen;
    //coord nextPosInScreen;
    //curPosInScreen.row = 0;
    //posInScreen = z
    // lastRowInPic = k
    // curPosInScreen x , next y
    posInScreen.row *= -1;
    posInScreen.col *= -1;
    for(int i=0;i<m_numOfClusters;i++)
    {
        coord clusterDim = m_clusters[i]->getRectangleDim();
        //picOffset.row -= curPosInScreen.row;
        //picOffset.col -= curPosInScreen.col
        m_clusters[i]->setPicture(pic,posInScreen);
        //if(curPosInScreen.row > lastRowInPic || nextPosInScreen.row<=posInScreen.row ) do not send
        //nextPosInScreen.row += clusterDim.row;
        posInScreen.row += clusterDim.row;
    }
}
screen::~screen(){
    for(int i=0;i<m_numOfClusters;i++)
        delete m_clusters[i];

}
void screen::cleanScreen()
{
    for(int i=0;i<m_numOfClusters;i++)
    {
        m_clusters[i]->clean();
    }
}
void screen::addCluster(serial_cluster_block* cluster)
{
    m_clusters[m_numOfClusters++] = cluster;
}