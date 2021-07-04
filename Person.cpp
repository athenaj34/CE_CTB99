#include "Person.h"
Person::Person(string n, string l, string nin, int a, Date B) :Name(n),Lastname(l),Nin(nin),Age(a), Birthday(B){
    cout << "hi " << Name << " " << Lastname << endl;
    cout << "You are " << Age << " years old and " << Birthday.Day << endl;
}
