// BADER DAKA :208219212 //ADHAM JABER:204218184
#pragma once
#include "Event.h"

class Calendar
{
public:
	Calendar();
	Calendar(const Event &event,const MyDate &date);
	~Calendar();

public:
	bool isFree(int num);
	int firstFree();
	int insert(const Event &newevent);
	int oldest();
	int eventNum(const Event &newevent); //
	void deleteAll();
	int deleteevent(int num); //
	char *print();
	void sortevent();
	int num(); //num of events
	void changeDate(int index,MyDate &stardate,MyDate&enddate);
	Event **UpcomingEvents() const;
	//geter
	MyDate getcurentdate() const;
	const Event *getevent(int index) const;
	int GetMonthEvents() const;
	//setter
	void setcurentdate(MyDate &date);
	int setevent(const Event &newevent, int num); //

	

private:
	Event **m_event;
	MyDate m_currdate;
};
