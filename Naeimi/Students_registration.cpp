//
// Created by athena on 8/5/21.
// +taking courses +course removation
#include <iostream>
#include <vector>
using namespace std;
class subject{
    string name_,teacher_name_,day_;
    int time_h_,time_min_,coefficient_;
public:
    subject(string name,string teacher_name,string day,int time_h,int time_min,int coefficient):name_(name),teacher_name_(teacher_name),day_(day),time_h_(time_h),time_min_(time_min),coefficient_(coefficient){

    }
    string return_Sname()const{
        return name_;
    }
    string return_STname()const{
        return teacher_name_;
    }
    string return_day()const{
        return day_;
    }
    int return_time_h()const{
        return time_h_;
    }
    int return_time_m()const{
        return time_min_;
    }
    int return_coefficient()const{
        return coefficient_;
    }
};
class student{
    string name_,lastname_,student_number_,password_;
    vector<subject>subjects;
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
    vector<subject> return_subjects(){
        return subjects;
    }
};

vector<subject>subjects_list(vector<subject>subjects){
    subjects.push_back(subject("Advanced Programming","Abolfazl Naeimi","Saturday",9,55,3));
    subjects.push_back(subject("Calculus2","Behrouz Daneshian","Monday",10,55,3));
    subjects.push_back(subject("Advanced Programming","Abolfazl Naeimi","Saturday",13,30,3));
    subjects.push_back(subject("Basic Programming","Abolfazl Naeimi","Monday",9,55,3));
    subjects.push_back(subject("Basic Programming","Maryam Afshari","Sunday",9,55,3));
    subjects.push_back(subject("Claculus-1","Morteza Ghorbani","Saturday",9,55,3));
    subjects.push_back(subject("Calculus-1","Mansour Ebrahimi","Wednesday",9,55,3));
    subjects.push_back(subject("RE","Nafise Khansari","Saturday",9,10,2));
    subjects.push_back(subject("RE","Siavash Bahrami","Monday",15,10,2));
    subjects.push_back(subject("Physics-1","Farshid Nouralishahi","Saturday",9,55,3));
    subjects.push_back(subject("Physics-1","Samira Zolghadr","Monday",9,30,3));
    return subjects;
}
int main(){
    char command;
    vector <student> students;
    vector <subject> subjects;
    subjects=subjects_list(subjects);
    cout << "------------------------------------\n";
    cout << "1)Sign up \t\t2)Sign in\t\t 3)Exit \n";
    string name, lastname, student_number, password;
    while(cin >> command) { ;
        if (command == '1') {

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
                    cout << "**************************\n**************************\n**************************\n";
                    vector<subject> sub =students[i].return_subjects();
                    if(sub.empty()) {
                        for (int i = 0; i < subjects.size(); ++i)
                            cout << i + 1 << ") " << subjects[i].return_Sname() << " // " << subjects[i].return_STname() <<" // " << subjects[i].return_day() << " // " << subjects[i].return_time_h() << ":" << subjects[i].return_time_m() << "\t|" << subjects[i].return_coefficient() << endl ;
                        cout << "Choose courses from the courses list:(after each number press enter)\n";
                        cout << endl;
                        int k = 0;
                        int num;
                        int coef=0;
                        char esc;
                        while (true) {
                            if (coef <=20) {
                                cout << "Enter the course number:\n";
                                k++;
                                cin >> num;
                                sub.push_back(subjects[num - 1]);
                                coef += subjects[num - 1].return_coefficient();
                                starting_menu:
                                cout << "  coefficient till now: " << coef << endl;
                                cout << "Type \'e' to exit \nType \'u' to edit your choices\npress any key to continue then enter course number\n";
                                cin >> esc;
                                if (esc == 'e' || k >= subjects.size())
                                    break;
                                else if (esc == 'u') {
                                    editing_menu:
                                    while (true) {
                                        cout << "------------------------------------\n";
                                        cout << "Your subjects are:\n";
                                        for (int f = 0; f < sub.size(); f++)
                                            cout << f + 1 << ") " << sub[f].return_Sname() << " // "
                                                 << sub[f].return_STname() << " // " << sub[f].return_day() << " // "
                                                 << sub[f].return_time_h() << ":" << sub[f].return_time_m() << "\t|"
                                                 << sub[f].return_coefficient() << endl;
                                        cout << endl;
                                        cout << "To delete a course enter its number\n";

                                        cin >> num;
                                        cout << sub[num - 1].return_Sname() << " // " << sub[num - 1].return_STname()
                                             << " // " << sub[num - 1].return_day() << " // "
                                             << sub[num - 1].return_time_h() << ":" << sub[num - 1].return_time_m()
                                             << "\t|" << sub[num - 1].return_coefficient();
                                        sub.erase(sub.begin() + (num - 1));
                                        cout << "    Successfully deleted\n";
                                        cout << "------------------------------------\n";
                                        again:
                                        cout << "Type \'e' to exit editing menu \nType \'u' to continue editing \n";
                                        cin >> esc;
                                        if (esc == 'e')
                                            goto starting_menu;
                                        else if (esc == 'u')
                                            continue;
                                        else {
                                            cout << "unsupported input try again\n";
                                            goto again;
                                        }
                                    }
                                }
                                else
                                    continue;

                            }
                            if(coef>20){
                                cout << "you've reached the limit\n";
                                cout << "Type \'e' to exit\nType \'u' to enter to editing menu\n";
                                cin >> esc;
                                if(esc=='u')
                                    goto editing_menu;
                                else if(esc=='e')
                                    break;
                            }
                        }
                    }
                    cout << "------------------------------------\n";
                    cout << "Your subjects are:\n";
                    for(int f=0; f<sub.size();f++)
                        cout << "  " << sub[f].return_Sname() << " // " << sub[f].return_STname() <<" // "<< sub[f].return_day() << " // " << sub[f].return_time_h() << ":" << sub[f].return_time_m() << "\t|" << sub[f].return_coefficient() << endl ;
                    cout << endl;
                    cout << "------------------------------------\n";
                }
                else if ((password != students[i].return_password() ||
                         student_number != students[i].return_student_number() ||
                         lastname != students[i].return_lastname() || name != students[i].return_name()) && (i!=students.size()-1) ){
                    cout << i << endl << students.size()-1 << endl;
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
