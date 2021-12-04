#ifndef PROJECT2_NODES_H
#define PROJECT2_NODES_H


class Nodes {
public:
    char letter;
    Nodes *next;
    Nodes(char Letter);
    Nodes();
    void Length();
    void Search();
    void Delete();
    void Add();
    void UPPERCASE();
    void lowercase();
    void reversedPrint(Nodes *&start);
    void Print(Nodes *&start);
};


#endif //PROJECT2_NODES_H
