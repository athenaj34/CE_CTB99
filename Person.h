#include <iostream>
using namespace std;
#include "Date.h"
#ifndef UNTITLED_PERSON_H
#define UNTITLED_PERSON_H
class Person{
private:
    //Name,Lastname, National international number
    string Name,Lastname,Nin;
    //Age
    int Age;
    //Birthday Date
    Date Birthday;
public:
    Person(string,string,string,int,Date);

};
#endif //UNTITLED_PERSON_H
