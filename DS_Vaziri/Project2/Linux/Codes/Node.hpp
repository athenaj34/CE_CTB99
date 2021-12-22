#ifndef PROJECT2_Node_HPP
#define PROJECT2_Node_HPP


class Node {
private:
	char letter;
	Node *next;
public:
	Node();
	Node(char Letter);
	int Length(Node *&start);
	int Search(char letter, Node *start);
	void Delete(int index, Node *& start);
	void Add(int index, Node *&start, Node *new_element);
	void UPPERCASE(Node *&start);
	void lowercase(Node *&start);
	void Print(Node *&start);
	void reversedPrint(Node *&start);
	char return_let();
	Node* return_next();
	void fill_let(char letter);
	void fill_next(Node* next);
};


#endif //PROJECT2_Node_HPP
