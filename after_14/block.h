#ifndef block_h
#define block_h
#define NUM_OF_DIRECTIONS 4

typedef struct pixelData{
	bool bit;
    pixelData(){
        bit = false;
    }
} pixelData;
typedef struct coord{
    int row;
    int col;
    coord(){
        row =0;
        col =0;
    }
    coord(int r,int c){
        row = r;
        col = c;
    }
} coord;
typedef enum direction{RIGHT=0,DOWN=1,LEFT=2,UP=3} direction;
class block{
public:
	 // Dimension of the blocks
    static int s_dim ;
	// built in paralizm, every worker will be in charge of numOfParall pixels
    static int s_numOfParall; 
	 // The blocks data, there are four blocks , all the directions
    pixelData** m_data[NUM_OF_DIRECTIONS];
    //direction m_curDirection; //????
	// this function assumes that the right data is valid, and will set rest of the data based on the right block data
    void adjust_m_data(); 
public:
	/*Static functions */

	 // initiate the block class with dimension and parallelize as requested
	static void init(int dim,int para);
	// This function will turn the source 90 degrees and will put it in dest
	static void turn90_comp(pixelData** source,pixelData** dest);
	// This function will return the dimension of the blocks
    static int getDim(); 
	// This function will return the para of the blocks
	sttaic in getPara();
	/*object methods*/
    block();
    ~block();
	//Will return the data in the requested direction
    pixelData** getData(direction d);
	//Will copy the data from d to the block , it will start coping from start coord 
    void setData_copy(pixelData** d,coord start);
	//Unused
    void setData_noCopy(pixelData** d);
#ifdef DEBUG
    void printBlock(direction d=RIGHT);// Print block in requested direction
    static void test(); // Debug function
#endif
};
#endif
