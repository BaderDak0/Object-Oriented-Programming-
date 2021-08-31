//name of hagshot
//  Bader Daka 208219212
//  Adham Jaber 204218184
//
#include "covidGB.h"
covidGB::covidGB() : covid19(), m_lungs(0), m_countryB(nullptr)
{
}
covidGB ::covidGB(float R, int molecules, bool vacc,const char *name, const char *countryB, int lungs) : covid19(R, molecules, vacc, name),
                                                                                                   m_countryB(countryB), m_lungs(lungs)
{
}
covidGB ::covidGB(const covidGB &c)
    : covid19(c.m_R, c.m_molecules, c.m_vacc, c.m_name), m_lungs(c.m_lungs), m_countryB(c.m_countryB)
{}
int covidGB ::getlungs() const
{
    return m_lungs;
}
const char *covidGB ::getcountr() const
{
    return m_countryB;
}
void covidGB::print()
{
    covid19::print();
    cout<<"the country of BG is::"<<m_countryB<<endl;
    cout<<"the damage to luges:"<<m_lungs<<endl; 
}
void covidGB::setgenetic(const char *DNA)
{
    throw("Unable to change genetic code Covid19 does not support!");
}
