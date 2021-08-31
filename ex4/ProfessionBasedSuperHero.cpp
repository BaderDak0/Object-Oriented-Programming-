//name of hagshot
//  Bader Daka 208219212
//  Adham Jaber 204218184
//
#include "ProfessionBasedSuperHero.h"

using namespace std;
ProfessionBasedSuperHero::ProfessionBasedSuperHero()
    : SuperHero(), m_profession(nullptr), m_yearsExperience(0)
{
}
ProfessionBasedSuperHero::ProfessionBasedSuperHero(const char *name, double age, bool radioactive, const char *profession, int yearsExperience)
    : SuperHero(name, age, radioactive)
{
    if (yearsExperience >= 0)
        m_yearsExperience = yearsExperience;
    m_profession = strdup(profession);
}
ProfessionBasedSuperHero::ProfessionBasedSuperHero(const char *profession, int yearsExperience)
    : SuperHero()
{
    if (yearsExperience >= 0)
        m_yearsExperience = yearsExperience;
    m_profession = strdup(profession);
}
ProfessionBasedSuperHero::ProfessionBasedSuperHero(const ProfessionBasedSuperHero &professionBasedSuperHero)
    : SuperHero(professionBasedSuperHero.m_name, professionBasedSuperHero.m_age, professionBasedSuperHero.m_radioactive)
{
    if (professionBasedSuperHero.m_yearsExperience >= 0)
        m_yearsExperience = professionBasedSuperHero.m_yearsExperience;
    m_profession = strdup(professionBasedSuperHero.m_profession);
}
ProfessionBasedSuperHero::~ProfessionBasedSuperHero()
{
    delete[] m_profession;
}
void ProfessionBasedSuperHero::setProfession(const char *profession)
{
    m_profession = strdup(profession);
}

void ProfessionBasedSuperHero::setYearsExperience(int yearsExperience)
{
    if (yearsExperience >= 0)
        m_yearsExperience = yearsExperience;
}
int ProfessionBasedSuperHero::getYearsExperience() const
{
    return m_yearsExperience;
}
void ProfessionBasedSuperHero::print()
{
    SuperHero::print();
    cout << "profession:" << m_profession << endl;
    cout << "years Expirence:" << m_yearsExperience << endl;
}
ostream &ProfessionBasedSuperHero::write(ostream &out)
{

    SuperHero::write(out);
    out << "profession:" << m_profession << endl;
    out << "years Expirence:" << m_yearsExperience << endl;
    return out;
}