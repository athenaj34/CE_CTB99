#ifndef UNTITLED_DATE_H
#define UNTITLED_DATE_H
class Date{
private:
    int Year,Month,Day;
public:
    Date(int,int,int);
    bool is_valid_year();
    bool is_valid_day();
    bool is_valid_month();
    bool is_leap_year();
    bool is_valid_date();
    friend class Person;
};
#endif //UNTITLED_DATE_H
