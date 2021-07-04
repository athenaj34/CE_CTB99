#include "Date.h"
#include <iostream>
using namespace std;
int DigitCounter(int num){
    int Digits=0;
    while(num!=0){
        num%10;
        Digits++;
        num/=10;
    }
    return Digits;
};
bool PositiveNum(int num){
    if(num>0)
        return true;
    else
        return false;
}
Date::Date(int y,int m,int d){
    if(is_valid_date()) {
        Year = y;
        Month = m;
        Day = d;
    }
    else
        cout << Year << "/" << Month << "/" << Day << " is not a valid date\n";

};
bool Date::is_leap_year() {
    if(Year%33 == 1 || Year%33 == 5 || Year%33 == 9 || Year%33 == 13 ||
        Year%33 == 17 || Year%33 == 22 || Year%33 == 26  || Year%33 == 30)
        return true;
    else
        return false;
};
bool Date::is_valid_year() {
    if (DigitCounter(Year)==4)
        return true;
    else
        return false;
};

bool Date::is_valid_day() {
    if((Month>6 && Month!=12 && (!PositiveNum(Day) || Day>30)) ||
       (Month<7 && (!PositiveNum(Day) ||Day >31)) ||
       (Month==12 && (is_leap_year()) && Day>20 && PositiveNum(Day)) ||
       (Month==12 && (!is_leap_year()) && Day>29 && PositiveNum(Day)))
        return false;
    else
        return true;

};
bool Date::is_valid_month() {
    if(Month>12 || PositiveNum(Month))
        return false;
    else
        return true;
}
bool Date::is_valid_date() {
    if(is_valid_month() && is_valid_year() && is_valid_day())
        return true;
    else
        return false;
}
