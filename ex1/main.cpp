#include "Calendar.h"

int main(int argc, char const *argv[])
{

    MyDate d1(28, 3, 1999);
    MyDate d2(20, 2, 2000);
    MyDate d3(10, 1, 2000);

    Calendar c;
    c.setDate(d1, 5);
    c.setDate(d2, 10);
    c.setDate(d3, 20);

    // int x=c.oldest();

    // cout<<x;
    // c.deleteDate(10);
    // c.deleteDate(5);
    c.sortDates();
    c.print();
    // cout<<endl<<c.num();


    // c.print();

    return 0;
}
