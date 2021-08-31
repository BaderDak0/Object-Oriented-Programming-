//name of hagshot
//  Bader Daka 208219212
//  Adham Jaber 204218184
//
#include "AnimalBasedSuperHero.h"
using namespace std;
AnimalBasedSuperHero::AnimalBasedSuperHero() : SuperHero(), m_animal(nullptr)
{
}
AnimalBasedSuperHero::AnimalBasedSuperHero(const char *name, double age, bool radioactive, const char *animal)
    : SuperHero(name, age, radioactive)
{
    m_animal = strdup(animal);
}
AnimalBasedSuperHero::AnimalBasedSuperHero(const char *animal) : SuperHero()
{
    m_animal = strdup(animal);
}
AnimalBasedSuperHero::AnimalBasedSuperHero(const AnimalBasedSuperHero &animalBasedSuperHero)
    : SuperHero(animalBasedSuperHero.m_name, animalBasedSuperHero.m_age, animalBasedSuperHero.m_radioactive)
{
    m_animal = strdup(animalBasedSuperHero.m_animal);
}
AnimalBasedSuperHero::~AnimalBasedSuperHero()
{
    delete[] m_animal;
}
void AnimalBasedSuperHero::setAnimal(const char *animal)
{
    m_animal = strdup(animal);
}
const char *AnimalBasedSuperHero::getAnimal() const
{
    return m_animal;
}
void AnimalBasedSuperHero::print()
{
    SuperHero::print();
    cout << "Animal:" << m_animal<< endl;
   
}
ostream &AnimalBasedSuperHero ::write(ostream &out)
{
    SuperHero::write(out);
    out << "Animal:" << m_animal<< endl;

    return out;
}
