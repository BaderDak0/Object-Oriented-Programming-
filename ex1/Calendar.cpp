// BADER DAKA :208219212 //ADHAM JABER:204218184
#include "Calendar.h"

Calendar ::Calendar()

{
    Date = new MyDate *[30];
    memset(Date, 0, 30 * sizeof(MyDate *));
    temp = new MyDate *[30];
    memset(temp, 0, 30 * sizeof(MyDate *));
}
Calendar::~Calendar()
{
    for (int i = 0; i < 30; i++)
    {
        if (Date[i] != nullptr)
            delete Date[i];
    }
    delete[] Date;
    for (int i = 0; i < 30; i++)
    {
        if (temp[i] != nullptr)
            delete temp[i];
    }
    delete[] temp;
}
int Calendar::setDate(const MyDate &newDate, int num)
{
    if (num < 0 || num > 29)
    {
        return -1;
    }

    Date[num] = new MyDate;
    if (Date[num] == nullptr)
    {
        return -1;
    }
    Date[num]->set(newDate.get_day(), newDate.get_month(), newDate.get_year());
    return 1;
}
bool Calendar::isFree(int num)
{
    if (num > 29 || num < 0)
        return false;
    if (Date[num] == nullptr)
        return false;
    return true;
}
int Calendar::firstFree()
{

    for (int i = 0; i < 30; i++)
    {
        if (Date[i] == nullptr)
        {
            return i;
        }
    }
    return -1;
}
int Calendar::insert(const MyDate &newDate)
{

    int x = firstFree();
    if (x == -1)
        return -1;
    Date[x] = new MyDate;
    if (Date[x] == nullptr)
    {
        return -1;
    }

    Date[x]->set(newDate.get_day(), newDate.get_month(), newDate.get_year());
    return 1;
}
int Calendar::oldest()
{

    if (firstFree() == -1)
        return -1;
    int x = firstFree();
    int z = 0;

    MyDate d;

    for (int i = 0; i < 30; i++)
    {
        if (Date[i] != nullptr && (Date[i]->get_day() > 0 && Date[i]->get_month() > 0 && Date[i]->get_year() > 0))
        {
            d.set(Date[i]->get_day(), Date[i]->get_month(), Date[i]->get_year());
            z = i;
            break;
        }
    }

    for (int i = 0; i < 30; i++)
    {
        if (Date[i] != nullptr && (Date[i]->get_day() > 0 && Date[i]->get_month() > 0 && Date[i]->get_year() > 0))
        {

            if (Date[i]->get_year() < d.get_year())
            {
                z = i;
                d.set(Date[i]->get_day(), Date[i]->get_month(), Date[i]->get_year());
            }
            if (Date[i]->get_year() == d.get_year())
            {
                if (Date[i]->get_month() < d.get_month())
                {
                    z = i;
                    d.set(Date[i]->get_day(), Date[i]->get_month(), Date[i]->get_year());
                }
                if (Date[i]->get_month() == d.get_month())
                {
                    if (Date[i]->get_day() < d.get_day())
                    {
                        z = i;
                        d.set(Date[i]->get_day(), Date[i]->get_month(), Date[i]->get_year());
                    }
                }
            }
        }
    }
    for (int i = 0; i < 30; i++)
    {
        if (Date[i] != nullptr && (Date[i]->get_day() == 0 && Date[i]->get_month() == 0 && Date[i]->get_year() == 0))
        {
            return i;
        }
    }
    return z;
}
int Calendar::datesNum(const MyDate &newDate)
{
    int x = firstFree();
    int count = 0;
    for (int i = 0; i < x; i++)
    {
        if (newDate.get_day() == Date[i]->get_day() && newDate.get_month() == Date[i]->get_month() && newDate.get_year() == Date[i]->get_year())
        {
            count++;
        }
    }
    for (int i = x + 1; i < 30; i++)
    {
        if (Date[i] != nullptr)
        {
            if (newDate.get_day() == Date[i]->get_day() && newDate.get_month() == Date[i]->get_month() && newDate.get_year() == Date[i]->get_year())
            {
                count++;
            }
        }
    }

    return count;
}
void Calendar::deleteAll()
{
    int x = firstFree();
    int zero = 0;
    MyDate ne;

    for (int i = 0; i < x; i++)
    {
        Date[i]->copy_date(ne);
    }
    for (int i = x + 1; i < 30; i++)
    {
        if (Date[i] != nullptr)
        {
            Date[i]->copy_date(ne);
        }
    }
}
int Calendar::deleteDate(int num)
{
    int x = firstFree();
    if (num > 29 || (num < 0))
        return -1;
    if (Date[num] == nullptr)
    {
        return -1;
    }
    MyDate ne;

    Date[num]->copy_date(ne);
    return 0;
}
char *Calendar::print()
{
    int count = 0;
    for (int i = 0; i < 30; i++)
    {
        if (Date[i] != nullptr)
        {
            count++;
        }
    }
    if (count == 0)
    {
        char *error = new char[50];
        strcpy(error, "Empty Calandar");
        cout << error << endl;
        return error;
    }

    char *str = new char[count * 11];
    str[0] = '\0';
    char *de;
    if (str == nullptr)
    {
        return nullptr;
    }
    for (int i = 0; i < 30; i++)
    {
        if (Date[i] != nullptr)
        {
            de = Date[i]->print();
            strcat(str, de);
            strcat(str, " ");
            delete[] de;
        }
    }
    strcat(str, "\0");

    cout << "the calender is:" << str << endl;
    return str;
}
int Calendar::num() // returned number of date on calendar
{
    int count = 0;
    for (int i = 0; i < 30; i++)
    {
        if (Date[i] != nullptr)
        {
            count++;
        }
    }
    return count;
}
void Calendar::sortDates()
{
    int z = 0, count = 0;
    count = num();

    for (int i = 0; i < count; i++)
    {

        z = oldest();

        temp[i] = new MyDate;
        if (temp[i] == nullptr)
            return;
        temp[i]->set(Date[z]->get_day(), Date[z]->get_month(), Date[z]->get_year());
        delete Date[z];
        Date[z] = nullptr;
    }
    for (int i = 0; i < count; i++)
    {
        if (Date[i] == nullptr&&temp[i]->get_day()!=0&& temp[i]->get_month()!=0&& temp[i]->get_year()!=0)
        {
            Date[i] = new MyDate;
            Date[i]->set(temp[i]->get_day(), temp[i]->get_month(), temp[i]->get_year());
        }
        else if(temp[i]->get_day()!=0&& temp[i]->get_month()!=0&& temp[i]->get_year()!=0)
            Date[i]->set(temp[i]->get_day(), temp[i]->get_month(), temp[i]->get_year());
    }
}