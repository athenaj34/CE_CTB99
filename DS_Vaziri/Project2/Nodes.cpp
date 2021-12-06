#include "Nodes.h"
#include <unistd.h>
#include <iostream>
using namespace std;
Nodes::Nodes(char Letter) {
	letter = Letter;
	next = nullptr;
}

Nodes:: Nodes() {
	next = nullptr;
}

int Nodes::Length(Nodes *&start) {
	Nodes *temp = start;
	int l = 0;
	for(temp; temp!=nullptr ; temp = temp -> next , ++l);
	return l;
}

int Nodes::Search(char letter, Nodes *start) {
	Nodes *temp = start;
	int i = 0;
	while(temp != nullptr) {
		if(temp -> letter == letter){
			return i+1;
		}
		else	temp = temp -> next;
		++i;
	}
	return -1;
}

void Nodes::Delete(int index, Nodes *& start) {
	if(index==0)	start = start -> next;
	Nodes *pre = nullptr, *temp = start;
	int i = 0;
	while(i<=index) {
		if(i == index-1 || index==0)	pre = temp;
		else if(i == index) {
			pre -> next = temp -> next;
			temp -> next = nullptr;
		}
		temp = temp -> next;
		++i;
	}
}

void Nodes::Add(int index, char letter, Nodes *&start) { ///?????????
	Nodes *pre = nullptr, *temp = start, new_element(letter);
	int i = 0;
	while(i<=index) {
		if(i == index-1) {
			pre = temp;
			pre -> next = &new_element;
			new_element.next=temp->next;
		}
		else if(index==0) {
			pre = temp;
			start = &new_element;
			new_element.next = pre;
		}
		temp = temp -> next;
		++i;
	}
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

void Nodes::Print(Nodes *&start) {
	Nodes *temp = start;
	if(temp -> next == nullptr) {
		cout << temp -> letter;
		return;
	}
	else {
		cout << temp -> letter;
		temp->Print(temp->next);
	}
}

void Nodes::reversedPrint(Nodes *&start) {
	Nodes *temp = start;
	if(temp -> next == nullptr) {
		cout << temp -> letter ;
	}
	else {
		temp ->reversedPrint(temp -> next);
		cout << temp -> letter;
	}
}


