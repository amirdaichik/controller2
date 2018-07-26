#ifndef screen_h
#define screen_h
#inlcude "serial_cluster_block.h"
#define MAX_NUM_OF_CLUSTERS 5
class screen{
	static screen theScreen;
	private:
	int m_numOfClusters;
	serial_cluster_block* m_clusters[MAX_NUM_OF_CLUSTERS];
	screen();
	public:
	void addPicture(coord pos);
	void cleanScreen();
	//void init(coord dim);
	//void setCluster(int idx,serial_cluster_block* cluster);
	void addCluster(serial_cluster_block* cluster);
	static screen* getInstance();
	
	
}
#endif