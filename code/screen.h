#ifndef screen_h
#define screen_h
#inlcude "serial_cluster"
class screen{
	private:
	static int s_dim;
	static int s_numOfParall;
		
	pixelData** m_data[NUM_OF_DIRECTIONS];
	direction m_curDirection;
	
	static bool turn90_comp(pixelData** source,pixelData** dest);
	static void setDim(int dim);
	static void setPara(int para);
	
	bool turn90();
	
	public:
	block();
	//block(const block& b);
	~block();
	//Assumption : b.rows = this.rows , b.cols = this.cols
	//block& operator=(const block& b);
	//bool turnData(direction wantedDirection);
	pixelData** getData(direction d);
	bool setData_copy(pixelData** d);
	bool setData_noCopy(pixelData** d);
}
#endif