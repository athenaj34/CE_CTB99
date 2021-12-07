#ifndef PROJECT2_NODES_H
#define PROJECT2_NODES_H


class Nodes {
public:
	char letter;
	Nodes *next;
	Nodes();
	Nodes(char Letter);
	int Length(Nodes *&start);
	int Search(char letter, Nodes *start);
	void Delete(int index, Nodes *& start);
	void Add(int index, Nodes *&start, Nodes *new_element);
	void UPPERCASE(Nodes *&start);
	void lowercase(Nodes *&start);
	void Print(Nodes *&start);
	void reversedPrint(Nodes *&start);
};


#endif //PROJECT2_NODES_H
