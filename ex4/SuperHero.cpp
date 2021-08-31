//name of hagshot
//  Bader Daka 208219212
//  Adham Jaber 204218184
//
#include "SuperHero.h"
#include <cstring>
#include <iostream>
SuperHero::SuperHero()
    : m_name(nullptr), m_age(0), m_radioactive(false)
{
}
SuperHero::SuperHero(const char *name, double age, bool radioactive)
{
    if (name != nullptr)
    {
        m_name = new char[strlen(name) + 1];
        strcpy(m_name, name);

        if (age >= 15 && age < 40)
        {
            m_age = age;
        }
        m_radioactive = radioactive;
    }
    else
        std::cout << "Error the name is null " << std::endl;
}
SuperHero::SuperHero(const SuperHero &superHero)
{
    m_name = strdup(superHero.m_name);
    m_age = superHero.m_age;
    m_radioactive = superHero.m_radioactive;
}
SuperHero::~SuperHero()
{
    delete[] m_name;
}

const char *SuperHero::getName() const
{
    return m_name;
}
double SuperHero::getAge() const
{
    return m_age;
}
bool SuperHero::getRadioactive() const
{
    return m_radioactive;
}
void SuperHero::setName(const char *name)
{
    m_name = strdup(name);
}
void SuperHero::setAge(double age)
{
    if (age >= 15 && age < 40)
        m_age = age;
}
void SuperHero::setRadioactive(bool radioactive)
{
    m_radioactive = radioactive;
}
void SuperHero::print()
{
    cout << "name of Super Hero:" << m_name << endl;
    cout << "Age of Super Hero:" << m_age << endl;
    cout << "radioactive of Super Hero:" << m_radioactive << endl;
}
void SuperHero::changeMod()
{
    if (m_mod == stand)
    {
        m_mod = attack;
        cout << m_name << " is in attack mode" << endl;
    }
    else if (m_mod == attack)
    {
        m_mod == stand;
        cout << m_name << " is stand mode" << endl;
    }
}
Mod SuperHero::getMod() const
{
    return m_mod;
}
ostream& SuperHero:: write(ostream& out)
 {
    out << "name of Super Hero:" << m_name << endl;
    out << "Age of Super Hero:" << m_age << endl;
    out << "radioactive of Super Hero:" << m_radioactive << endl;
    return out;
 }