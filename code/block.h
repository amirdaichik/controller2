#ifndef block_h
#define block_h
#define NUM_OF_DIRECTIONS 4
struct pixelData{
	char r;
	char g;
	char b;
}
struct coord{
	int row;
	int col;
}
typedef enum direction{RIGHT=0,DOWN=1,LEFT=2,UP=3} direction;
class block{
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