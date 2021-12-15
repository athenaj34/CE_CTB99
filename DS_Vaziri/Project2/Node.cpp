#include "Node.h"
#include <unistd.h>
#include <iostream>
using namespace std;
Node::Node(char Letter) {
	letter = Letter;
	next = nullptr;
}

Node:: Node() {
	next = nullptr;
}

int Node::Length(Node *&start) {
	Node *temp = start;
	int l = 0;
	for(temp; temp!=nullptr ; temp = temp -> next , ++l);
	return l;
}

int Node::Search(char letter, Node *start) {
	Node *temp = start;
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

void Node::Delete(int index, Node *& start) {
	if(index==0)	start = start -> next;
	Node *pre = nullptr, *temp = start;
	int i = 0;
	while(i<=index) {
		if(i == index-1 || index==0)	pre = temp;
		else if(i == index) {
			pre -> next = temp -> next;
			temp -> next = nullptr;
			temp->~Node();
		}
		temp = temp -> next;
		++i;
	}
}

void Node::Add(int index, Node *&start, Node *new_element) {
	Node *pre = nullptr, *temp = start;
	if(index==1)	start = new_element;
		else{
		for(int i=2; i<= index; ++i){
			pre = temp;
			temp = temp -> next;
		}
		pre -> next = new_element;
	}
	new_element -> next = temp;
}

void Node::UPPERCASE(Node *&start) {
	Node * temp = start;
	for(temp; temp != nullptr; temp = temp -> next)
		temp -> letter = toupper(temp -> letter);
}

void Node::lowercase(Node *&start) {
	Node * temp = start;
	for(temp; temp != nullptr; temp = temp -> next)
		temp -> letter = tolower(temp -> letter);
}

void Node::Print(Node *&start) {
	Node *temp = start;
	cout << temp -> letter;
	if(temp -> next != nullptr)		temp -> Print(temp -> next);
}

void Node::reversedPrint(Node *&start) {
	Node *temp = start;
	if(temp -> next != nullptr)		temp -> reversedPrint(temp -> next);
	cout << temp->letter ;
}

char Node::return_let() {
	return this->letter;
}

Node* Node::return_next() {
	return this->next;
}

void Node::fill_let(char letter) {
	this -> letter = letter;
}

void Node::fill_next(Node* next) {
	this -> next = next;
}