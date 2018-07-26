#include "screen.h"
/*class screen{
	static screen theScreen;
	private:
	coord m_dim;
	serial_cluster_block** m_clusters;
	screen();
	public:
	void addPicture(coord pos);
	void cleanScreen();
	void init(coord dim);
	void setCluster(int idx,serial_cluster_block* cluster);
	static screen* getInstance();
}*/
screen* screen::getInstance(){
	return &theScreen;
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
	powInScreen.col *= -1;
	for(int i=0;i<m_numOfClusters;i++)
	{
		clusterDim = m_clusters[i].getRectangleDim();
		//picOffset.row -= curPosInScreen.row;
		//picOffset.col -= curPosInScreen.col
		m_clusters[i].addPicture(pic,posInScreen);
		//if(curPosInScreen.row > lastRowInPic || nextPosInScreen.row<=posInScreen.row ) do not send
		//nextPosInScreen.row += clusterDim.row;
		PosInScreen.row += clusterDim.row;
	}
}
void screen::cleanScreen()
{
	for(int i=0;i<m_numOfClusters;i++)
	{
		m_clusters[i].clean();
	}
}
void screen::addCluster(serial_cluster_block* cluster)
{
	m_clusters[m_numOfClusters++] = cluster;
}
