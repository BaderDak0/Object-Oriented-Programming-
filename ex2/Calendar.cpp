// BADER DAKA :208219212 //ADHAM JABER:204218184
#include "Calendar.h"

Calendar ::Calendar()
    : m_currdate()
{
    m_event = new Event *[30];
    memset(m_event, 0, 30 * sizeof(Event *));
}
Calendar::Calendar(const Event &event, const MyDate &date)
    : m_currdate(date)
{

    m_event = new Event *[30];
    memset(m_event, 0, 30 * sizeof(Event *));
    m_event[0] = new Event(event);
    // (*m_event[0]) = event;
}
Calendar::~Calendar()
{
    for (int i = 0; i < 30; i++)
    {
        if (m_event[i] != nullptr)
            delete m_event[i];
    }
    delete[] m_event;
}
int Calendar::setevent(const Event &newevent, int num)
{
    if (newevent.geteventnum() <= 0 || newevent.getpresent() == nullptr)
    {
        return -1;
    }

    if (num < 0 || num > 29)
    {
        return -1;
    }
    for (int i = 0; i < 30; i++)
    {
        if (m_event[i] != nullptr && m_event[i]->geteventnum() == newevent.geteventnum())
        {
            return -1;
        }
    }
    for (int i = 0; i < 30; i++)
    {
        if (m_event[i] != nullptr)
            if (m_event[i]->notbetween(newevent) == false)
                return -1;
    }

    m_event[num] = new Event;
    if (m_event[num] == nullptr)
    {
        return -1;
    }
    (*m_event[num]) = newevent;
    return 1;
}
bool Calendar::isFree(int num)
{
    if (num > 29 || num < 0)
        return false;
    if (m_event[num] == nullptr)
        return false;
    return true;
}
int Calendar::firstFree()
{

    for (int i = 0; i < 30; i++)
    {
        if (m_event[i] == nullptr)
        {
            return i;
        }
    }
    return -1;
}
int Calendar::insert(const Event &newevent)
{
    if (newevent.geteventnum() <= 0 || newevent.getpresent() == nullptr)
    {
        return -1;
    }

    int x = firstFree();
    if (x == -1)
        return -1;

    for (int i = 0; i < 30; i++)
    {
        if (m_event[i] != nullptr && m_event[i]->geteventnum() == newevent.geteventnum())
        {
            return -1;
        }
    }
    for (int i = 0; i < 30; i++)
    {
        if (m_event[i] != nullptr)
            if (m_event[i]->notbetween(newevent) == false)
                return -1;
    }
    m_event[x] = new Event;
    if (m_event[x] == nullptr)
    {
        return -1;
    }
    (*m_event[x]) = newevent;
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
        if (m_event[i] != nullptr)
        {
            d.set(m_event[i]->getstart().get_day(), m_event[i]->getstart().get_month(), m_event[i]->getstart().get_year());
            z = i;
            break;
        }
    }

    for (int i = 0; i < 30; i++)
    {
        if (m_event[i] != nullptr)
        {

            if (m_event[i]->getstart().get_year() < d.get_year())
            {
                z = i;
                d.set(m_event[i]->getstart().get_day(), m_event[i]->getstart().get_month(), m_event[i]->getstart().get_year());
            }
            if (m_event[i]->getstart().get_year() == d.get_year())
            {
                if (m_event[i]->getstart().get_month() < d.get_month())
                {
                    z = i;
                    d.set(m_event[i]->getstart().get_day(), m_event[i]->getstart().get_month(), m_event[i]->getstart().get_year());
                }
                if (m_event[i]->getstart().get_month() == d.get_month())
                {
                    if (m_event[i]->getstart().get_day() < d.get_day())
                    {
                        z = i;
                        d.set(m_event[i]->getstart().get_day(), m_event[i]->getstart().get_month(), m_event[i]->getstart().get_year());
                    }
                }
            }
        }
    }

    return z;
}

void Calendar::deleteAll()
{

    Event ne;

    for (int i = 0; i < 30; i++)
    {
        if (m_event[i] != nullptr)
        {
            delete m_event[i];
            m_event[i] = nullptr;
        }
    }
}
int Calendar::deleteevent(int num)
{

    if (num > 29 || (num < 0))
        return -1;
    if (m_event[num] == nullptr)
    {
        return -1;
    }
    delete m_event[num];
    m_event[num] = nullptr;
    return 0;
}
char *Calendar::print()
{
    int count = 0, x = 0;
    for (int i = 0; i < 30; i++)
    {
        if (m_event[i] != nullptr)
        {
            count++;
        }
    }
    for (int i = 0; i < 30; i++)
    {
        if (m_event[i] != nullptr)
        {
            x = i;
            break;
        }
    }
    
    if (count == 0)
    {
        char *error = new char[50];
        strcpy(error, "Empty Calandar");
        cout << error << endl;
        return error;
    }
    cout << "the calender is:" << endl;
    int size = strlen(m_event[x]->printevent());
    char *str = new char[count * size];
    str[0] = '\0';
    char *de;
    if (str == nullptr)
    {
        return nullptr;
    }
    for (int i = 0; i < 30; i++)
    {
        if (m_event[i] != nullptr)
        {
            de = m_event[i]->printevent();
            // cout << endl;
            strcat(str, de);
            strcat(str, " ");
            delete[] de;
        }
    }
    strcat(str, "\0");

    
    return str;
}
int Calendar::num() // returned number of date on calendar
{
    int count = 0;
    for (int i = 0; i < 30; i++)
    {
        if (m_event[i] != nullptr)
        {
            count++;
        }
    }
    return count;
}
void Calendar::sortevent()
{
    int z = 0, count = 0;
    count = num();
    MyDate *tempstart[30];
    MyDate *tempend[30];
    Event *event[30];
    for (int i = 0; i < count; i++)
    {

        z = oldest();

        event[i] = new Event((*m_event[z]));

        delete m_event[z];
        m_event[z] = nullptr;
    }
    for (int i = 0; i < count; i++)
    {

        m_event[i] = new Event((*event[i]));
    }
    for (int i = 0; i < count; i++)
    {
        delete event[i];
    }
}
MyDate Calendar::getcurentdate() const
{

    return m_currdate;
}
const Event *Calendar::getevent(int index) const
{
    if (index > 0 && index < 30 && m_event[index] != nullptr)
    {

        return m_event[index];
    }
    else
        return nullptr;
}
void Calendar::setcurentdate(MyDate &date)
{
    m_currdate = date;
}
void Calendar::changeDate(int index, MyDate &stardate, MyDate &enddate)
{
    if (index < 0 || index > 30)
    {
        return;
    }

    Event event;
    event.setstartdate(stardate);
    event.setenddate(enddate);

    for (int i = 0; i < 30; i++)
    {
        if (m_event[i] != nullptr)
            if (m_event[i]->notbetween(event) == false)
                return;
    }

    m_event[index]->setstartdate(stardate);
    m_event[index]->setstartdate(enddate);
}
int Calendar::GetMonthEvents() const
{
    int count = 0;

    for (int i = 0; i < 30; i++)
    {
        if (m_event[i] != nullptr && m_event[i]->getstart().isAfter(m_currdate) == true && m_event[i]->getstart().get_month() == m_currdate.get_month()&&m_event[i]->getstart().get_year() == m_currdate.get_year())
        {
            count++;
        }
    }
    return count;
}
Event **Calendar::UpcomingEvents() const
{
    int count = GetMonthEvents();
    Event **event = new Event *[count];
    if (event == nullptr)
        return nullptr;
    int j = 0;
    for (int i = 0; i < 30; i++)
    {
        if (m_event[i] != nullptr && m_event[i]->getstart().isAfter(m_currdate) == true && m_event[i]->getstart().get_month() == m_currdate.get_month()&&m_event[i]->getstart().get_year() == m_currdate.get_year())

        {
            event[j] = new Event((*m_event[i]));
            if (event[j] == nullptr)
                return nullptr;
           
            j++;
        }
    }

    return event;
}