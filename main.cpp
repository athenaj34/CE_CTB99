#include <iostream>
#include "Person.h"
char Entry_menu() {
    char Command;
    cout << "Welcome! \n";
    cout << "1)Register\n2)Login\n0)Exit\n";
    cin >> Command;
    return Command;
}
char Login_menu(){


}
void Registration_menu(){
    cout << "Please enter your role: \n";


}
enum role{
    Student,
    Teacher,
    Staff
};
using namespace std;
int main() {
    int role;
    Entry_menu();
    while (Entry_menu()!='0') {
        if(Entry_menu()=='1')
            Registration_menu();
        else if(Entry_menu()=='2')
            Login_menu();
        Person athena("Athena", "Jafari", "0024720641", 18, Date(12, 3, 5));

    }
    if(Entry_menu()=='0') {
        cout << "Program is closing...";
        return 0;
    }
    return 0;
}
