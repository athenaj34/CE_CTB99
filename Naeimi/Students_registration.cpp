//
// Created by athena on 8/5/21.
//
#include <iostream>
#include <vector>
using namespace std;
class student{
    string name_,lastname_,student_number_,password_;
    vector<string>subjects;
public:
    student(string name,string lastname,string student_number,string password):name_(name),lastname_(lastname),student_number_(student_number),password_(password){

    }
    string return_student_number()const{
        return student_number_;
    }
    string return_password()const{
        return password_;
    }
    string return_name()const{
        return name_;
    }
    string return_lastname()const{
        return lastname_;
    }
    //string return_subjects()const{
    //    return subjects;
   // }
};
vector<string>subjects_list(){
    vector<string> subject_;
    subject_.push_back("Advanced Programming");
    subject_.push_back("Calculus2");
    subject_.push_back("Basic Programming");
    subject_.push_back("Physics2");
    subject_.push_back("Physics1");
    subject_.push_back("Calculus1");
    return subject_;
}
int main(){
    char command;
    vector <student> students;
    cout << "------------------------------------\n";
    cout << "1)Sign up \t\t2)Sign in\t\t 3)Exit \n";
    string name, lastname, student_number, password;
    while(cin >> command) { ;
        if (command == '1') { //making obj

            cout << "Enter your name: ";
            cin.get();
            getline(cin, name, '\n');
            cout << "Enter your lastname: ";
            cin.get();
            getline(cin, lastname, '\n');
            cout << "Enter your student number: ";
            cin.get();
            getline(cin, student_number, '\n');
            cout << "Enter a password: ";
            cin.get();
            getline(cin, password, '\n');
            students.push_back(student(name, lastname, student_number, password));
            cout << "Your account has been created successfully\n";
            cout << "1)Sign up \t\t2)Sign in\t\t 3)Exit \n";
        } else if (command == '2') { //checking obj
            cout << "Enter your name: ";
            cin.get();
            getline(cin, name, '\n');
            cout << "Enter your lastname: ";
            cin.get();
            getline(cin, lastname, '\n');
            cout << "Enter your student number: ";
            cin.get();
            getline(cin, student_number, '\n');
            cout << "Enter a password: ";
            cin.get();
            getline(cin, password, '\n');
            for (int i = 0; i < students.size(); i++) {
                if (name == students[i].return_name() && lastname == students[i].return_lastname() &&
                    student_number == students[i].return_student_number() &&
                    password == students[i].return_password()) {
                    cout << "Login successfully\n";
                    //subjects
                    //
                    //
                    
                    cout << "1)Sign up \t\t2)Sign in\t\t 3)Exit \n";
                }
                else if (password != students[i].return_password() ||
                         student_number != students[i].return_student_number() ||
                         lastname != students[i].return_lastname() || name != students[i].return_name() && (i!=students.size()-1) ){
                    continue;
                }
                else    {
                    cout << "INVALID DATA\n";
                    cout << "1)Sign up \t\t2)Sign in\t\t 3)Exit \n";
                    break;
                }
            }
        } else if (command == '3') {
            cout << "Program is closing\n";
            break;
        }
    }
    return 0;
}
