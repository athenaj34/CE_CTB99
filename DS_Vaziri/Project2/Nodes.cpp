#include "Nodes.h"
#include <iostream>
using namespace std;
Nodes::Nodes(char Letter) {
        letter = Letter;
        next = nullptr;
}
Nodes::Nodes() {

}

void Nodes::Length() {

}

void Nodes::Search() {

}

void Nodes::Delete() {

}

void Nodes::Add() {

}

void Nodes::UPPERCASE() {

}

void Nodes::lowercase() {

}

void Nodes::Print(Nodes *&start) {
    while(start != nullptr){
        cout << start -> letter;
        start = start -> next;
        start -> Print(start);
    }
}

void Nodes::reversedPrint(Nodes *&start) {
    while(start != nullptr){
//        start = start -> next;
//        start -> reversedPrint(start);
//        cout << start -> letter;
    }
}


