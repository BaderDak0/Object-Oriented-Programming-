// BADER DAKA :208219212 //ADHAM JABER:204218184
#pragma once
#include "MyDate.h"


class Calendar
{
public:
	Calendar();
	~Calendar();

public:	
	int setDate(const MyDate& newDate, int num);
	bool isFree(int num);
	int firstFree();
	int insert(const MyDate& newDate);
	int oldest();
	int datesNum(const MyDate& newDate);
	void deleteAll();
	int deleteDate(int num);
	char* print();
	void sortDates();
	int num();
	private:
	MyDate **Date;
	MyDate **temp;
};

