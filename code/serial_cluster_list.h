typedef struct block_l
{
	block* blk;
	block_l* next;
} block_l
class serial_cluster_block_list
{
	private:
	int m_num_of_blocks;
	//direction* m_serial_directions;
	block_l* m_head;
	block_l* tail;
	public:
	serial_cluster_block()
	{
		m_num_of_blocks = 0;
		m_head = NULL;
		m_tail = NULL;
	}
	~serial_cluster_block()
	{
		block_l* cur = m_head;
		while(cur!=NULL)
		{
			block_l* next = cur_next;
			delete cur.block;
			delete cur;
			cur = next;
		}
	}
	// need to remove the block and direction after usage
	void buildCluster(block* b,direction* d,int num_of_blocks)
	{
		for(int i=0;i<num_of_blocks;i++)
		{
			addBlock(&b[i],d[i]);
		}
	}
	void addBlock(block* b,direction d)
	{
		block_l* node = new block_l();
		node->blk = new block(b);	
		node->next = NULL;
		if(tail!=NULL)
		{
			tail->next = node;
			tail = node;
		}
		else
		{
			head = tail = node;
		}
	}
}