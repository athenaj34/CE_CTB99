// AP_1
// Created by Athena Jafari
// 03/05/2021
#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;
class information{
private:
    string name,lastname;
    float average;
public:
    void get_name(){
        cout << "Name: ";
        getline(cin,name,'\n');
    }
    void get_lastname(){
        cout << "Lastname: ";
        getline(cin,lastname,'\n');
    }
    void get_average(){
        cout << "Average: ";
        cin >> average;
        cin.get();
    }

    double return_average()const{
        return average;
    }
    string return_name()const{
        return name;
    }
    string return_lastname()const{
        return lastname;
    }
};
int main() {
    cout << "Enter students numbers:";
    int size;
    cin >> size;
    cin.get();
    cout << "Enter students' information:\n";
    information *students= new information[size]; //creating objects
    for(int i=0;i<size;++i){
        cout << i+1 << ")";
        students[i].get_name();
        students[i].get_lastname();
        students[i].get_average();
    }
    double *marks=new double [size]{};
    //printing results
    cout << "--------------------------\nResults(sorted by Average):\n";

    for(int i=0;i<size;++i)
        marks[i]=students[i].return_average(); //filling marks

    sort(marks,marks+size,greater<double>()); //sorting marks
    cout << "No. Average  Name & Lastname" << endl;
    for (int i=0;i<size;++i)
        for(int j=0;j<size;++j)
            if(marks[i]==students[j].return_average()){
                cout <<  i+1 << ")  "<< fixed << setprecision(2) <<students[j].return_average() << "\t "  << students[j].return_name() << " "<< students[j].return_lastname() <<endl;
            }


    return 0;
}
