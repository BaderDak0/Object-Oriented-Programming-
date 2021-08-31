#include "Event.h"
Event::Event() : m_eventnum(0),
                 m_start(),
                 m_end()
{
    m_eventnum = 0;
    m_nameevent = nullptr;
    m_present = nullptr;
}

Event::~Event()
{
    delete[] m_nameevent;
    delete[] m_present;
}

Event::Event(int eventnum, char *nameevent, char *present, MyDate &start, MyDate &end)
    : m_eventnum(eventnum)
{
    if (((start.isBefore(end) == true) && (present != nullptr))||(start==end&&(present != nullptr)))
    {
        m_start = start;
        m_end = end;
        m_nameevent = new char[strlen(nameevent) + 1];
        strncpy(m_nameevent, nameevent, strlen(nameevent) + 1);
        m_present = new char[strlen(present) + 1];
        strncpy(m_present, present, strlen(present) + 1);
    }
    else
    {
        cout << "Error there is not present or end date before start date " << endl;
    }
}
Event::Event(const Event &event)
{
    m_eventnum = event.m_eventnum;
    m_nameevent = new char[strlen(event.m_nameevent) + 1];
    strncpy(m_nameevent, event.m_nameevent, strlen(event.m_nameevent) + 1);
    m_present = new char[strlen(event.m_present) + 1];
    strncpy(m_present, event.m_present, strlen(event.m_present) + 1);
    m_start = event.m_start;
    m_end = event.m_end;
}

Event &Event::operator=(const Event &event)
{
    m_eventnum = event.m_eventnum;
    delete[] m_nameevent;
    m_nameevent = new char[strlen(event.m_nameevent) + 1];
    strncpy(m_nameevent, event.m_nameevent, strlen(event.m_nameevent) + 1);
    delete[] m_present;
    m_present = new char[strlen(event.m_present) + 1];
    strncpy(m_present, event.m_present, strlen(event.m_present) + 1);
    m_start = event.m_start;
    m_end = event.m_end;

    return *this;
}
bool Event::notbetween(const Event& myevent)
{
  
    if(myevent.getstart().isBefore(m_start)==true&&myevent.getend().isBefore(m_end)==true) 
    {
        return true;

    }
    else if ((myevent.getstart().isAfter(m_start)==true&&myevent.getend().isAfter(m_end)==true))
    {
        return true;
    }
    return false;
    
}
int Event::geteventnum() const
{
    return m_eventnum;
}
char *Event::getnameevent() const
{
    return m_nameevent;
}
char *Event::getpresent() const
{
    return m_present;
}
MyDate Event::getstart() const
{
    return m_start;
}
MyDate Event::getend() const
{
    return m_end;
}
void Event::seteventnum(int eventnum)
{
    m_eventnum = eventnum;
}
void Event::setnameevent(char *nameevent)
{
    delete[] m_nameevent;
    m_nameevent = new char[strlen(nameevent) + 1];
    strncpy(m_nameevent, nameevent, strlen(nameevent) + 1);
}
void Event::setpresent(char *present)
{
    delete[] m_present;
    m_present = new char[strlen(present) + 1];
    strncpy(m_present, present, strlen(present) + 1);
}

void Event::setstartdate(MyDate &start)
{
    m_start = start;
}
void Event::setenddate(MyDate &end)
{
    m_end = end;
}
char *Event::printevent() const
{
    char *event = new char[256];
    strncpy(event, "number event:", strlen("number event:"));
    // strcpy(event,"number event:");
    sprintf(event+strlen(event), "%d ", m_eventnum);
    strcat(event, "name event:");
    strcat(event, m_nameevent);
    strcat(event, " present:");
    strcat(event, m_present);
    strcat(event, " start event:");
    char *tmp = m_start.print();
    strcat(event, tmp);
    delete[] tmp;
    strcat(event, " end event:");
    tmp = m_end.print();
    strcat(event, tmp);
    delete[] tmp;
    cout << event << endl;
    return event;                   
}