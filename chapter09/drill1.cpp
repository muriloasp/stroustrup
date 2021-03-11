/************
 * 9.4.1
 ************/

#include "std_lib_facilities.h"

struct Date {
    int y;
    int m;
    int d;
};

void init_day(Date& dd, int y, int m, int d)
{
    if (m < 1 || m > 12) error("Invalid value for a month!");
    if (d < 1 || d > 31) error("Invalid value for a day!");

    dd.y = y;
    dd.m = m;
    dd.d = d;
}

void add_day(Date& dd, int n)
{
    dd.d = (dd.d + n) % 31;
    // keep it simple
}

ostream& operator<<(ostream& os, const Date& d)
{
    return os << '(' << d.y
            << ',' << d.m
            << ',' << d.d << ')';
}

void f() {
    Date today;
    init_day(today, 1978, 6, 25);

    Date tomorrow = today;
    add_day(tomorrow, 1);
    
    cout << today << ' ' << tomorrow << '\n';
}

void test() {
    Date bad_day;
    init_day(bad_day, 1978, -1, 25);
    
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
