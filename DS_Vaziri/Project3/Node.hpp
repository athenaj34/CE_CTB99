#ifndef PROJECT3_Node_HPP
#define PROJECT3_Node_HPP


class Node {
private:
	int x, y;
	int direction;
public:
	Node(int i, int j);
	int return_x();
	int return_y();
	int return_dir();
	void dir_incre();
};

#endif //PROJECT2_Node_HPP
