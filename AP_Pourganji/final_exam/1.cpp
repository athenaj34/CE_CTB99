//Athena Jafari
#include <iostream>
using namespace std;

//ALEF
class base{
public:
    virtual void print(){
        cout << "base\n";
    }
};
class derived1 : public base{
public:
    void print(){
        cout << "derived1\n";
    }
};
class derived2 : public base{
public:
    void print(){
        cout << "derived2\n";
    }
};

int main(){

    //BE
    base obj1;
    derived1 obj2;
    derived2 obj3;
    obj1.print();

    obj2.print();
    obj3.print();
    cout << "****\n";

    //JIM
    base* b;
    derived1 d1;
    derived2 d2;
    b=&d1;
    b->print();

    cout << endl << endl;


    b=&d2;
    b->print();
    cout << "****\n";

    return 0;

}


