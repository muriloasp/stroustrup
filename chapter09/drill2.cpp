/************
 * 9.4.2
 ************/

#include "std_lib_facilities.h"

struct Date {
    int y, m, d;
    Date(int y, int m, int d);
    void add_day(int n);
};

Date::Date(int yy, int mm, int dd)
    :y(yy), m(mm), d(dd)
{
    if (m < 1 || m > 12) error("Invalid value for a month!");
    if (d < 1 || d > 31) error("Invalid value for a day!");
}

void Date::add_day(int n)
{
    d = (d + n) % 31;
    // keep it simple
}

ostream& operator<<(ostream& os, const Date& d)
{
    return os << '(' << d.y
            << ',' << d.m
            << ',' << d.d << ')';
}

void f() {
    Date today(1978, 6, 25);

    Date tomorrow = today;
    tomorrow.add_day(1);
    
    cout << today << ' ' << tomorrow << '\n';
}

void test() {
    Date bad_day(1978, -1, 25);
    
    cout << bad_day << '\n';
}

int main()
{
    try {
        f();
        //test();
        return 0;
    } 
    catch (exception& e) {
       cerr << "error: " << e.what() << '\n';
       return 1;
    }
    catch(...) {
        cerr << "Oops: unknow exception!\n";
        return 2;
    }
}
