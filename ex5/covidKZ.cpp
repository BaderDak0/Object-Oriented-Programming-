//name of hagshot
//  Bader Daka 208219212
//  Adham Jaber 204218184
//
#include "covidKZ.h"
#include <cstring>
covidKZ::covidKZ() : covid19(), covidGB(), covidSA(), m_DNA(nullptr)
{
}
covidKZ::covidKZ(float R, int molecules, bool vacc, const char *name, const char *countryA, const char *countryB, int lungs, int liver, const char *DNA)
    : covid19(R, molecules, vacc, name), covidGB(R, molecules, vacc, name, countryB, lungs), covidSA(R, molecules, vacc, name, countryA, liver)
{
    if (DNA == nullptr)
        throw("There not DNA IS NULL");

    for (int i = 0; i < strlen(DNA); i++)
    {
        if (DNA[i] != 'A' && DNA[i] != 'G' && DNA[i] != 'T' && DNA[i] != 'C')
        {
            throw("wrong DNA combination ");
        }
    }

    m_DNA = strdup(DNA);
}
covidKZ::covidKZ(const covidKZ &c)
    : covid19(c.m_R, c.m_molecules, c.m_vacc, c.m_name), covidGB(c.m_R, c.m_molecules, c.m_vacc, c.m_name, c.m_countryB, c.m_lungs),
      covidSA(c.m_R, c.m_molecules, c.m_vacc, c.m_name, c.m_countryA, c.m_liver)
{
    m_DNA = strdup(c.m_DNA);
    if(m_DNA==nullptr)
    throw("Bad ALLOC");
}
covidKZ::~covidKZ()
{

    delete[] m_DNA;
}
void covidKZ::print()
{
    covid19::print();
    cout << "the country of BG is::" << m_countryB << endl;
    cout << "the damage to luges:" << m_lungs << endl;
    cout << "the country of SA is:" << m_countryA << endl;
    cout << "the damage to liver:" << m_liver << endl;
    cout << "The DNA is:" << m_DNA << endl;
}
void covidKZ::setgenetic(const char *DNA)
{
    for (int i = 0; i < strlen(DNA); i++)
    {
        if (DNA[i] != 'A' && DNA[i] != 'G' && DNA[i] != 'T' && DNA[i] != 'C')
        {
            throw("wrong DNA combination ");
        }
    }
    delete[] m_DNA;
    m_DNA = strdup(DNA);
    if(m_DNA==nullptr)
    throw("Bad ALLOC");
}