//name of hagshot
//  Bader Daka 208219212
//  Adham Jaber 204218184
//
#include "covid19.h"
#include <string.h>
covid19::covid19()
    : m_R(0), m_molecules(0), m_vacc(false), m_name(nullptr)
{
}
covid19::covid19(float R, int molecules, bool vacc, const char *name)
    : m_R(R), m_molecules(molecules), m_vacc(vacc)
{
    if (name == nullptr)
    {
        throw("name is empty (Nullptr)");
    }
    m_name = strdup(name);
}
covid19::covid19(const covid19 &c)
    : m_R(c.m_R), m_molecules(c.m_molecules), m_vacc(c.m_vacc)
{
    m_name = strdup(c.m_name);
}
covid19::~covid19()
{

    delete[] m_name;
}
char *covid19::getname() const
{
    return m_name;
}
float covid19::getratio() const
{
    return m_R;
}
int covid19::getmolecules() const
{
    return m_molecules;
}
bool covid19::getvacc() const
{
    return m_vacc;
}

void covid19::print()
{
    cout << "name of the virus:" << m_name << endl;
    cout << "infection rate:  " << m_R << endl;
    cout << "molecules of the virus:" << m_molecules << endl;
    if (m_vacc == true)
        cout << "vaccine:"
             << "Yes" << endl;
    else
        cout << "vaccine:"
             << "No" << endl;
}
void covid19::setgenetic(const char *DNA)
{
    throw("Unable to change genetic code Covid19 does not support!");
}