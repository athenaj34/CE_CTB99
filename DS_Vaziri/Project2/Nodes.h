#ifndef PROJECT2_NODES_H
#define PROJECT2_NODES_H


class Nodes {
public:
    char letter;
    Nodes *next;
    Nodes(char Letter);
    Nodes();
    int Length(Nodes *&start);
    void Search(char letter, Nodes *&start);
    void Delete();
    void Add();
    void UPPERCASE();
    void lowercase();
    void Print(Nodes *start);
    void reversedPrint(Nodes *start);
};


#endif //PROJECT2_NODES_H
