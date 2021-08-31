//name of hagshot
//  Bader Daka 208219212
//  Adham Jaber 204218184
//
#include "covidSA.h"
covidSA::covidSA() : covid19(), m_countryA(nullptr), m_liver()
{
}
covidSA::covidSA(float R, int molecules, bool vacc, const char *name, const char *country, int liver)
    : covid19(R, molecules, vacc, name), m_liver(liver), m_countryA(country)
{
}
covidSA::covidSA(const covidSA &c) : covid19(c.m_R, c.m_molecules, c.m_vacc, c.m_name), m_liver(c.m_liver), m_countryA(c.m_countryA)
{
}
void covidSA::print()
{
    covid19::print();
    cout << "the country of SA is::" << m_countryA << endl;
    cout << "the damage to liver:" << m_liver << endl;
}
void covidSA::setgenetic(const char *DNA)
{

    throw("Unable to change genetic code CovidSA does not support!");
}