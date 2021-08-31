#pragma once
#include "MyDate.h"
#include <cstring>
using namespace std;
class Event
{
public:
    Event();
    ~Event();
    Event(int eventnum, char *nameevent, char *present, MyDate &start, MyDate &end);
    Event(const Event &event);
    Event &operator=(const Event &event);

public:
    int geteventnum() const;
    char *getnameevent() const;
    char *getpresent() const;
    MyDate getstart() const;
    MyDate getend() const;
    bool notbetween(const Event& myevent);
    void seteventnum(int eventnum);
    void setnameevent(char *nameevent);
    void setpresent(char *present);
    void setstartdate(MyDate &start);
    void setenddate(MyDate &end);
    char *printevent() const;

private:
    int m_eventnum;
    char *m_nameevent;
    char *m_present;
    MyDate m_start;
    MyDate m_end;
    
};
