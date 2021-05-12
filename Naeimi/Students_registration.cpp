//
// Created by athena on 8/5/21.
// + taking courses
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
    vector<string> return_subjects(){
        return subjects;
    }
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
                    cout << "****Login successfully****\n";
                    vector<string> sub =students[i].return_subjects();
                    vector<string> sub_list=subjects_list();
                    if(sub.size()==0) {
                        cout << "Choose at least 3 subjects from below:(after each number press enter)\n";
                        for (int i = 0; i < sub_list.size(); ++i)
                            cout << i + 1 << ") " << sub_list[i] << "   ";
                        cout << endl;
                        int k = 0;
                        int num;
                        char esc;
                        while (true) {
                            k++;
                            cin >> num;
                            sub.push_back(sub_list[num - 1]);
                            if (k >= 3) {
                                cout << "Type \'e' to exit \n or press any key to continue then enter subject number\n";
                                cin >> esc;
                                if (esc=='e' || k>=6)
                                    break;
                                else if(esc=='\n')
                                    continue;
                            }
                        }
                    }
                    cout << "------------------------------------\n";
                    cout << "Your subjects are:\n";
                    for(int f=0; f<sub.size();f++)
                        cout << "  " << sub[f] ;
                    cout << endl;
                    cout << "------------------------------------\n";
                }
                else if (password != students[i].return_password() ||
                         student_number != students[i].return_student_number() ||
                         lastname != students[i].return_lastname() || name != students[i].return_name() && (i!=students.size()-1) ){
                    continue;
                }
                else    {
                    cout << "INVALID DATA\n";
                    break;
                }
            }
        } else if (command == '3') {
            cout << "Program is closing\n";
            break;
        }
        cout << "1)Sign up \t\t2)Sign in\t\t 3)Exit \n";
    }
    return 0;
}
