#ifndef block_h
#define block_h
#define NUM_OF_DIRECTIONS 4
typedef struct pixelData{
    int r;
    int g;
    int b;
} pixelData;
typedef struct coord{
    int row;
    int col;
} coord;
typedef enum direction{RIGHT=0,DOWN=1,LEFT=2,UP=3} direction;
class block{
public:
    static int s_dim ;
    static int s_numOfParall;

    pixelData** m_data[NUM_OF_DIRECTIONS];
    direction m_curDirection;

    static void turn90_comp(pixelData** source,pixelData** dest);
    static void setPara(int para);
    void adjust_m_data();
    bool turn90();
    static void test();


public:
    static void setDim(int dim);
    static int getDim();
    block();
    //block(const block& b);
    ~block();
    //Assumption : b.rows = this.rows , b.cols = this.cols
    //block& operator=(const block& b);
    //bool turnData(direction wantedDirection);
    pixelData** getData(direction d);
    void setData_copy(pixelData** d,coord start);
    void setData_noCopy(pixelData** d);
    void printBlock(direction d=RIGHT);

};
#endif