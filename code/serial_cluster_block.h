#ifndef serial_cluster_block_h
#define serial_cluster_block_h

class serial_cluster_block
{
	// The serial cluster will know its dim and it can send it to the screen(can be calculated at the constructor)
	// When the screen wants to add a picture, it will send the pointer to the picture and the offset in the picture
	private:
	int m_rectangle_dim.row;
	int m_rectangle_dim.col;
	
	int m_num_of_blocks;
	direction* m_directions;
	referenceBlock* m_ref_blocks;
	void fixPos(coord* pos,direction d);
	
	public:
	serial_cluster_block(int num_of_blocks,direction* d);
	~serial_cluster_block();
	int getRectangleDim();
	// posInPic is the offset in the picture of the left upper block in the cluster (being sent by the screen) [Can be negative if the picture is not being drawn in the left upper block]
	void setPicture(picture* pic,coord posInPic);
	
}