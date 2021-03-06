// BADER DAKA :208219212 //ADHAM JABER:204218184
#pragma once
#include <iostream>
#include <cstring>

using namespace std;

class MyDate
{
	
public:
	MyDate();
	MyDate(int day, int month, int year);
	~MyDate() {};
	
public:	
	void init();
	bool isBefore(const MyDate& newDate);
	int delay(int num);
	int bringForward(int num);
	char* print();
	bool copy_date(MyDate& new_date);
	
public:	
	int set(int day, int month, int year);
	int setDay(int day);
	int setMonth(int month);
	int setYear(int year);
	int get_day() const;
	int get_year() const;
	int get_month() const;
	
private:
	int m_day;
    int m_month;
    int m_year;
};

