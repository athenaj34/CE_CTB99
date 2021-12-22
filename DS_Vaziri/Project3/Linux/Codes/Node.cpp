#include "Node.hpp"

Node::Node(int i, int j) {
		x = i;
		y = j;
		direction = 0;
}

int Node::return_dir() {
	return this->direction;
}

int Node::return_x() {
	return this->x;
}

int Node::return_y() {
	return this->y;
}

void Node::dir_incre() {
	this->direction++;
}