#include "Calendar.h"

int main(int argc, char const *argv[])
{
    MyDate d1(28, 3, 1999);
    MyDate d2(20, 2, 2000);
    MyDate d3(10, 1, 2000);
    char str[256];
    strcpy(str, "bader");

    char str2[256];
    strcpy(str2, "noorx");
    Event e(10, str, str, d1, d3);
    Event e1(12, str2, str2, d3, d2);
    Calendar c(e, d2);
    c.setevent(e1, 1);
    c.print();
    // c.setDate(d1, 5);
    // c.setDate(d2, 10);
    // c.setDate(d3, 20);

    // int x=c.oldest();

    // cout<<x;
    // c.deleteDate(10);
    // c.deleteDate(5);
    // c.sortDates();
    // c.print();
    // cout<<endl<<c.num();

    // c.print();

    return 0;
}
