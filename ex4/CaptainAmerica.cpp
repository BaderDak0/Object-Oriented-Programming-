//name of hagshot
//  Bader Daka 208219212
//  Adham Jaber 204218184
//
#include "CaptainAmerica.h"
using namespace std;
CaptainAmerica::CaptainAmerica() : ProfessionBasedSuperHero(), _ageIncludingFreezing(0)
{
}
CaptainAmerica::CaptainAmerica(const char *name, double age, bool radioactive, const char *profession, int yearsExperience, double ageIncludingFreezing)
    : ProfessionBasedSuperHero(name, age, radioactive, profession, yearsExperience)
{
    if (ageIncludingFreezing > m_age)
    {
        _ageIncludingFreezing = ageIncludingFreezing;
    }
}
CaptainAmerica::CaptainAmerica(const char *profession, int yearsExperience, double ageIncludingFreezing)
    : ProfessionBasedSuperHero(profession, yearsExperience)
{
    if (ageIncludingFreezing > m_age)
    {
        _ageIncludingFreezing = ageIncludingFreezing;
    }
}
CaptainAmerica::CaptainAmerica(double ageIncludingFreezing)
{
    if (ageIncludingFreezing > m_age)
    {
        _ageIncludingFreezing = ageIncludingFreezing;
    }
}
CaptainAmerica::CaptainAmerica(const CaptainAmerica &captainAmerica) 
    : ProfessionBasedSuperHero(captainAmerica.m_name, captainAmerica.m_age, captainAmerica.m_radioactive, captainAmerica.m_profession, captainAmerica.m_yearsExperience)
{

    _ageIncludingFreezing = captainAmerica._ageIncludingFreezing;
}

double CaptainAmerica::getAgeIncludingFreezing() const
{
    return _ageIncludingFreezing;
}
void CaptainAmerica::setAgeIncludingFreezing(double ageIncludingFreezing)
{
    if (_ageIncludingFreezing > m_age)
    {
        _ageIncludingFreezing = ageIncludingFreezing;
    }
}
void CaptainAmerica::print()
{
    ProfessionBasedSuperHero::print();
    cout << "age includion freezing: " << getAgeIncludingFreezing() << endl;
}
 ostream & CaptainAmerica::write(ostream &out)
{
 ProfessionBasedSuperHero::write(out);
    out << "age includion freezing: " << getAgeIncludingFreezing() << endl;
    return out;
}