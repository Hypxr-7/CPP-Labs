#include <iostream>
#include <string>

using std::cout, std::endl;

class Date{
private:
    int day;
    int month;
    int year;
public:
    Date(int d, int m, int y){
        day = d;
        year = y;
        if (m <= 12 && m >= 1)
            month = m;
        else
            month = 1;
    }
    void setDay(int d){
        day = d;
    }
    void setMonth(int m){
        month = m;
    }
    void setYear(int y){
        year = y;
    }
    int getDay(){
        return day;
    }
    int getMonth(){
        return month;
    }
    int getYear(){
        return year;
    }
    std::string formatDate(){
        std::string s = std::to_string(day) + '/' + std::to_string(month) + '/' + std::to_string(year);
        return s;
    }

};

int main() {
    Date d1(19, 1, 2024);
    cout << d1.formatDate() << endl; // should print 19/1/2024
    d1.setDay(17);
    cout << d1.formatDate() << endl; // should print 17/1/2024
    d1.setMonth(5);
    cout << d1.formatDate() << endl; // should print 17/5/2024
    Date d2(29, 13, 2024); // should set month to 1
    cout << d2.formatDate() << endl; // should print 29/1/2024
    return 0;
}
