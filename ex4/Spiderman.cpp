//name of hagshot
//  Bader Daka 208219212
//  Adham Jaber 204218184
//
#include "Spiderman.h"
using namespace std;
Spiderman::Spiderman()
    : AnimalBasedSuperHero(), _webSize(0)
{
}
Spiderman::Spiderman(const char *name, double age, bool radioactive, const char *animal, double webSize)
    : AnimalBasedSuperHero(name, age, radioactive, animal)
{
    if (webSize >= 0)
        _webSize = webSize;
}
Spiderman::Spiderman(const char *animal, double webSize)
    : AnimalBasedSuperHero(animal)
{
    if (webSize >= 0)
        _webSize = webSize;
}
Spiderman::Spiderman(double webSize)
{
    if (webSize >= 0)
        _webSize = webSize;
}
Spiderman::Spiderman(const Spiderman &spiderman)
    : AnimalBasedSuperHero(spiderman.m_name, spiderman.m_age, spiderman.m_radioactive, spiderman.m_animal), _webSize(spiderman._webSize)
{
}

double Spiderman::getWebSize() const
{
    return _webSize;
}
void Spiderman::setWebSize(double webSize)
{
    if (webSize >= 0)
        _webSize = webSize;
}
void Spiderman::print()
{
    AnimalBasedSuperHero::print();
    cout << "websize:" << _webSize << endl;
}
ostream &Spiderman::write(ostream &out)
{

    AnimalBasedSuperHero::write(out);
    out << "websize:" << _webSize << endl;
    return out;
}