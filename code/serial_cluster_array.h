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
	// posInPic is the offset in the picture of the left upper block in the cluster (being sent by the screen) [Can be negative if the picture is not being drawn in the left upper block]
	void setPicture(picture* pic,coord posInPic)
	{
		block** data = pic->getData();
		
		for(int i=0;i<m_num_of_blocks;i++)
		{
			if(pic->isValidPos(posInPic))
				m_ref_blocks[i].setdata(data[curRow][curCol],m_directions[i]);
			fixPos(&posInPic,m_directions[i]);
		}
	}
	void fixPos(coord* pos,direction d)
	{
			switch(d)
			{
				case RIGHT:
				{
					pos->col++;
					return;
				}
				case LEFT:
				{
					pos->col--;
					return;
				}
				case UP:
				{
					pos->row--;
					return;
				}
				case DOWN:
				{
					pos->row++;
					return;
				}
			}
	}*/
}