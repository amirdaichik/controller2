class serial_cluster_block_fixed
{
	// The serial cluster will know its dim and it can send it to the screen(can be calculated at the constructor)
	// When the screen wants to add a picture, it will send the pointer to the picture and the offset in the picture
	private:
	int m_rectangle_dim.row;
	int m_rectangle_dim.col;
	
	int m_num_of_blocks;
	direction* m_directions;
	referenceBlock* m_ref_blocks;
	public:
	serial_cluster_block(int num_of_blocks,direction* d)
	{
		m_rectangle_dim.col = 0; // The first block is also being calculated
		m_rectangle_dim.row = 1; // And we assume that the first block is turning right
		
		m_ref_blocks = new referenceBlock[num_of_blocks];
		m_directions = new direction[num_of_blocks];
		for(int i=0;i<num_of_blocks;i++)
		{
			if(d[i] == RIGHT)
				m_rectangle_dim.col++;
			if(d[i] == DOWN)
				m_rectangle_dim.row++;
			m_directions[i] = d[i];
		}
			
	}
	~serial_cluster_block()
	{
		delete[] m_blocks;
		delete[] direction;
	}
	int getRectangleCols()
	{
		return m_rectangle_dim.col;
	}
	int getRectangleRows()
	{
		return m_rectangle_dim.row;
	}
	void setPicture(picture* pic,)
	{
		block** data = pic->getData();
		//int curRowInPic = offsetRows;
		//int curColInPic = offsetCols;
		for(int i=0;i<m_num_of_blocks;i++)
		{
			//if(pic->getNumOfRows()>curRow && pic->getNumOfCols()>curCol)
			//	m_ref_blocks[i].setdata(data[curRow][curCol],m_directions[i]);
			//fixPos(&curRow,&curCol,m_directions[i]);
		}
	}
	/*void fixPos(int* curRow,int* corCol,direction d)
	{
			switch(d)
			{
				case RIGHT:
				{
					(*curCol)++;
					return;
				}
				case LEFT:
				{
					(*curCol)--;
					return;
				}
				case UP:
				{
					(*curRow)--;
					return;
				}
				case DOWN:
				{
					(*curRow)++;
					return;
				}
			}
	}*/
}