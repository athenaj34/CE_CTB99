#include "Nodes.h"
#include <iostream>
using namespace std;
Nodes::Nodes(char Letter) {
	letter = Letter;
	next = nullptr;
}

Nodes:: Nodes() {

}

int Nodes::Length(Nodes *&start) {
	int l = 0;
	for(start; start!=nullptr ; start = start -> next , ++l);
	return l;
}

void Nodes::Search(char letter, Nodes *&start) {

}

void Nodes::Delete(char letter, Nodes *& start) {

}

void Nodes::Add(char pre, char letter, Nodes *&start) {

}

void Nodes::UPPERCASE(Nodes *&start) {
    Nodes * temp = start;
    for(temp; temp!=nullptr ; temp = temp -> next)
        temp -> letter = toupper(temp -> letter);

}

void Nodes::lowercase(Nodes *&start) {
    Nodes * temp = start;
    for(temp; temp!=nullptr ; temp = temp -> next)
        temp -> letter = tolower(temp -> letter);

}

void Nodes::Print(Nodes *start) {
	if(start -> next == nullptr) {
		cout << start -> letter;
		return;
	}
	else {
		cout << start -> letter;
		start->Print(start->next);
	}
	
}

void Nodes::reversedPrint(Nodes *start) {
	if(start -> next == nullptr) {
		cout << start -> letter;
		return;
	}
	else {
		start->Print(start->next);
		cout << start -> letter;
	}
}


