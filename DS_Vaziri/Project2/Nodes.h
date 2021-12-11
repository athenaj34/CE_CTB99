#ifndef PROJECT2_NODES_H
#define PROJECT2_NODES_H


class Nodes {
private:
	char letter;
	Nodes *next;
public:
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
	char return_let();
	Nodes* return_next();
	void fill_let(char letter);
	void fill_next(Nodes* next);
};


#endif //PROJECT2_NODES_H
