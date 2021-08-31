// BADER DAKA :208219212 //ADHAM JABER:204218184
#include "MyDate.h"

MyDate::MyDate()
{
    m_day = 0;
    m_month = 0;
    m_year = 0;
}
MyDate ::MyDate(int day, int month, int year)
{
    if (month == 2 && (day <= 28 && day > 0) && (year > 1900 && year < 2100))
    {
        m_day = day;
        m_month = month;
        m_year = year;
    }
    else if ((day <= 30 && day > 0) && (month <= 12 && month > 0) && (year > 1900 && year < 2100))
    {
        m_day = day;
        m_month = month;
        m_year = year;
    }
    else
    {
        m_day = 0;
        m_month = 0;
        m_year = 0;
    }
}
bool MyDate::operator==(const MyDate &b) const
{   
        if (m_day==b.m_day&&m_month==b.m_month&&m_year==b.m_year)
        {
            return true;
        }
        
        return false;
}
void MyDate ::init()
{
    m_day = 0;
    m_month = 0;
    m_year = 0;
}
int MyDate::set(int day, int month, int year)
{
    if (month == 2 && (day <= 28 && day > 0) && (year > 1900 && year < 2100))
    {
        m_day = day;
        m_month = month;
        m_year = year;
        return 1;
    }
    else if ((day <= 30 && day > 0) && (month <= 12 && month > 0) && (year > 1900 && year < 2100))
    {
        m_day = day;
        m_month = month;
        m_year = year;
        return 1;
    }
    else
    {
        return -1;
    }
}
int MyDate::setDay(int day)
{
    if (m_month == 2 && day <= 28 && day > 0)
    {
        m_day = day;
        return day;
    }
    else if (day <= 30 && day > 0)
    {
        m_day = day;
        return day;
    }
    return -1;
}
int MyDate::setMonth(int month)
{
    if (month <= 12 && month > 0)
    {
        m_month = month;
        return month;
    }
    return -1;
}
int MyDate::setYear(int year)
{
    if (year > 1900 && year < 2100)
    {
        m_year = year;
        return year;
    }
    return -1;
}
int MyDate::get_day() const
{
    return m_day;
}
int MyDate::get_year() const
{

    return m_year;
}
int MyDate::get_month() const
{
    return m_month;
}
bool MyDate::isBefore(const MyDate &newDate)
{

    if (newDate.m_year > m_year)
        return true;
    if (newDate.m_year < m_year)
        return false;
    if (newDate.m_month > m_month)
        return true;
    if (newDate.m_month < m_month)
        return false;
    if (newDate.m_day > m_day)
        return true;
    if (newDate.m_day <= m_day)
        return false;

    return true;
}
bool MyDate::isAfter(const MyDate &newDate)
{
    if (newDate.m_year < m_year)
        return true;
    if (newDate.m_year > m_year)
        return false;
    if (newDate.m_month < m_month)
        return true;
    if (newDate.m_month > m_month)
        return false;
    if (newDate.m_day < m_day)
        return true;
    if (newDate.m_day >= m_day)
        return false;

    return true;
}
int MyDate::delay(int num)
{
    if (num > 365)
    {
        return -1;
    }
    while (num > 30)
    {

        if (m_month == 2 && num > 28)
        {
            num -= 28;
            m_month++;
        }
        else
        {
            num = num - 30;
            m_month++;
        }
        if (m_month > 12)
        {
            m_year++;
            m_month = 1;
        }
    }
    m_day += num;
    if (m_day > 30)
    {
        if (m_month == 2)
        {
            m_day -= 28;
            m_month++;
            return 0;
        }
        else
        {
            m_day -= 30;
            m_month++;
            return 0;
        }
    }
    return 0;
}
int MyDate::bringForward(int num)
{
    if (num > 365)
    {
        return -1;
    }
    while (num >= 30)
    {
        num -= 30;
        m_month--;

        if (m_month == 0)
        {
            m_year--;
            m_month = 12;
        }
        if (m_month == 2)
        {
            num += 2;
        }
    }
    m_day -= num;
    if (m_day <= 0)
    {
        m_month--;
        if (m_month != 2)
        {
            m_day += 30;
        }
        if (m_month == 2)
        {
            m_day += 28;
        }
    }
    return 0;
}
char *MyDate::print() const
{
    char *snum = new char[11];
    if (snum == nullptr)
    {
        return nullptr;
    }

    itoa(m_day, snum, 10);
    strcat(snum, "/");
    char *monthh = new char[3];
    if (monthh == nullptr)
    {
        return nullptr;
    }
    itoa(m_month, monthh, 10);
    strcat(snum, monthh);
    strcat(snum, "/");
    char *yearr = new char[5];
    if (yearr == nullptr)
    {
        return nullptr;
    }
    itoa(m_year, yearr, 10);
    strcat(snum, yearr);
    delete[] yearr;
    delete[] monthh;

    // cout<<"the date is:"<<snum<<" ";
    return snum;
}
bool MyDate::copy_date(MyDate &new_date)
{
    m_day = new_date.m_day;
    m_month = new_date.m_month;
    m_year = new_date.m_year;

    return true;
}