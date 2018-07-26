typedef struct block_l
{
	block* blk;
	direction* direct;
	block_l* next;
} block_l

class serial_cluster_block_fixed
{
	private:
	int m_num_of_blocks;
	direction* m_directions;
	block* m_blocks;
	public:
	serial_cluster_block(int num_of_blocks)
	{
		m_blocks = new block[num_of_blocks];
		m_directions = new direction[num_of_blocks];
		for(int i=0;i<num_of_blocks;i++)
			m_directions[i] = RIGHT;
	}
	~serial_cluster_block()
	{
		delete[] m_blocks;
	}
	void setBlock(int idx,block* b)
	{
		block[idx] = b;
		block[idx].turnData(m_directions[idx]);
	}
	void setup(direction* d)
	{
		int myX = -1;
		int myY = 0;
		for(int i=0; i<m_num_of_blocks;i++)
		{
			switch(d[i])
			{
				case RIGHT:
					myX+=1;
					break;
				case LEFT:
					myX -=1;
					break;
				case UP:
					myY+=1;
					break;
				case DOWN:
					myY+=1;
					break;
			}
			int curX = myX;
			int curY = myY;
			for(int j=i+1;j<m_num_of_blocks;j++)
			{
				switch(d[j])
				{
					case RIGHT:
						curX+=1;
						break;
					case LEFT:
						curX -=1;
						break;
					case UP:
						curY+=1;
						break;
					case DOWN:
						curY+=1;
						break;
				}
				if(curX==myX && curY == myY+1)
				{
					
				}
				else if(curX == myX && curY == myY -1)
				{
					
				}
				else if(curY == myY && curX == curX+1)
				{
					
				}
				else if(curY == myY && curX == curX-1)
				{
					
				}
			}
		}
	}
}