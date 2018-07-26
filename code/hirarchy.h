typedef enum direction{RIGHT,DOWN,LEFT,UP} direction;
class block{ //
	private:
	const int m_rows,m_cols;
	pixelData** m_data;
	const int numOfPara;
	
	public:
	block(int rows,int cols,pixelData** data,int numOfPara) m_rowS(rows),m_cols(cols),m_data(data),m_numOfPara(numOfPara){
		
	}
	bool turnData(direction wantedDirection);
	pixelData** getData();
}

class picture{
	private:
	const int m_block_rows;
	const int m_block_cols;
	block** m_data;
}
class serial_cluster_block{
	private:
	const int m_num_of_blocks;
	direction* m_serial_directions;
	block* m_blocks;	
}
class screen{ // Should be singelton
	private:
	const int m_num_of_serial_clusters;
	serial_cluster_block* m_clusters;
}
class painter_worker{
	private:
	serial_cluster_block* m_cluster;
	int curBlock;
	int curRowInBlock;
	int curColInBlock;

	public:
	void setCluster(serial_cluster_block* cluster);
	bool paintIter(); // should check block's paralizm , in one interation should paint up to 2 pixels
	
}
class painter{ // Should be singleton
	private:
	const int m_num_of_workers;
	painter_worker* painters;
	
	public:
	//bool set
	bool assignClusterToPainter(int pid,serial_cluster_block* cluster);
	bool paintPicture();
}