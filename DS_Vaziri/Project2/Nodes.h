#ifndef PROJECT2_NODES_H
#define PROJECT2_NODES_H


class Nodes {
public:
    char letter;
    Nodes *next;
    Nodes(char Letter);
    int Length(Nodes *&start);
    void Search(char letter, Nodes *&start);
    void Delete(char letter, Nodes *& start);
    void Add(char pre, char letter, Nodes *&start);
    void UPPERCASE(Nodes *&start);
    void lowercase(Nodes *&start);
    void Print(Nodes *start);
    void reversedPrint(Nodes *start);
};


#endif //PROJECT2_NODES_H
