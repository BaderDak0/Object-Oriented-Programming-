//name of hagshot
//  Bader Daka 208219212
//  Adham Jaber 204218184
//
#include "Avengers.h"
#include <typeinfo>
#include <string>
using namespace std;
Avengers::Avengers() : m_maxsupersize(supersize)
{
    m_superHeros = new SuperHero *[m_maxsupersize];
    if (m_superHeros == nullptr)
    {
        cerr << "Error Memory" << endl;
    }

    memset(m_superHeros, 0, m_maxsupersize * sizeof(SuperHero *));
    m_numSuperHeros = 0;
}
Avengers::Avengers(const char *name) : m_maxsupersize(supersize), m_teamName(name)
{
    m_superHeros = new SuperHero *[m_maxsupersize];
    if (m_superHeros == nullptr)
    {
        cerr << "Error Memory" << endl;
    }
    memset(m_superHeros, 0, m_maxsupersize * sizeof(SuperHero *));
    m_numSuperHeros = 0;
}
Avengers::~Avengers()
{
    cleansuperheroarr();
}
void Avengers::cleansuperheroarr()
{

    for (int i = 0; i < m_maxsupersize; i++)
    {
        if (m_superHeros != nullptr)
            delete m_superHeros[i];
    }
    delete[] m_superHeros;
}
void Avengers::setSuperHeros(SuperHero **superHeros, int size)
{
    if (superHeros == nullptr || size < 0)
    {
        cout << "Error" << endl;
        return;
    }

    if (size > m_maxsupersize)
    {
        cleansuperheroarr();
        m_maxsupersize = size;
        m_superHeros = new SuperHero *[m_maxsupersize];
        if (m_superHeros == nullptr)
        {
            cerr << "Error Memory" << endl;
            return;
        }
        memset(m_superHeros, 0, m_maxsupersize * sizeof(SuperHero *));
    }
    else
    {
        cleansuperheroarr();
        m_superHeros = new SuperHero *[m_maxsupersize];
        if (m_superHeros == nullptr)
        {
            cerr << "Error Memory" << endl;
            return;
        }
        memset(m_superHeros, 0, m_maxsupersize * sizeof(SuperHero *));
    }

    for (int i = 0; i < size; i++)
    {
        if ((dynamic_cast<CaptainAmerica *>(superHeros[i])) != nullptr)
        {
            m_superHeros[i] = new CaptainAmerica(*((CaptainAmerica *)(superHeros[i])));
            if (m_superHeros[i] == nullptr)
            {
                cerr << "Error Memory" << endl;
            }
            continue;
        }
        if ((dynamic_cast<Spiderman *>(superHeros[i])) != nullptr)
        {
            m_superHeros[i] = new Spiderman(*((Spiderman *)(superHeros[i])));
            if (m_superHeros[i] == nullptr)
            {
                cerr << "Error Memory" << endl;
            }
            continue;
        }
        if ((dynamic_cast<ProfessionBasedSuperHero *>(superHeros[i])) != nullptr)
        {
            m_superHeros[i] = new ProfessionBasedSuperHero(*((ProfessionBasedSuperHero *)(superHeros[i])));
            if (m_superHeros[i] == nullptr)
            {
                cerr << "Error Memory" << endl;
            }
            continue;
        }
        if ((dynamic_cast<AnimalBasedSuperHero *>(superHeros[i])) != nullptr)
        {
            m_superHeros[i] = new AnimalBasedSuperHero(*((AnimalBasedSuperHero *)(superHeros[i])));
            if (m_superHeros[i] == nullptr)
            {
                cerr << "Error Memory" << endl;
            }
            continue;
        }
        if ((dynamic_cast<SuperHero *>(superHeros[i])) != nullptr)
        {
            m_superHeros[i] = new SuperHero(*superHeros[i]);
            if (m_superHeros[i] == nullptr)
            {
                cerr << "Error Memory" << endl;
            }
            continue;
        }
    }
    m_numSuperHeros = size;
}
void Avengers::addSuperHero(SuperHero *superHero)
{
    if (m_numSuperHeros == m_maxsupersize)
    {
        SuperHero **temp = new SuperHero *[m_maxsupersize * 2];
        if (temp == nullptr)
        {
            cerr << "Error Memory" << endl;
            return;
        }
        memset(temp, 0, (m_maxsupersize * 2) * sizeof(SuperHero *));
        for (int i = 0; i < m_maxsupersize; i++)
        {
            if (m_superHeros[i] != nullptr)
            {

                if ((dynamic_cast<CaptainAmerica *>(m_superHeros[i])) != nullptr)
                {
                  
                    
                    temp[i] = new CaptainAmerica(*((CaptainAmerica *)(m_superHeros[i])));
                    if (temp[i] == nullptr)
                    {
                        cerr << "Error Memory" << endl;
                    }

                    continue;
                }
                if ((dynamic_cast<Spiderman *>(m_superHeros[i])) != nullptr)
                {

                    temp[i] = new Spiderman(*((Spiderman *)(m_superHeros[i])));
                    if (temp[i] == nullptr)
                    {
                        cerr << "Error Memory" << endl;
                    }
                    continue;
                }
                if ((dynamic_cast<ProfessionBasedSuperHero *>(m_superHeros[i])) != nullptr)
                {

                    temp[i] = new ProfessionBasedSuperHero(*((ProfessionBasedSuperHero *)(m_superHeros[i])));
                    if (temp[i] == nullptr)
                    {
                        cerr << "Error Memory" << endl;
                    }
                    continue;
                }
                if ((dynamic_cast<AnimalBasedSuperHero *>(m_superHeros[i])) != nullptr)
                {

                    temp[i] = new AnimalBasedSuperHero(*((AnimalBasedSuperHero *)(m_superHeros[i])));
                    if (temp[i] == nullptr)
                    {
                        cerr << "Error Memory" << endl;
                    }
                    continue;
                }
                if ((dynamic_cast<SuperHero *>(m_superHeros[i])) != nullptr)
                {

                    temp[i] = new SuperHero(*m_superHeros[i]);
                    if (temp[i] == nullptr)
                    {
                        cerr << "Error Memory" << endl;
                    }
                    continue;
                }
            }
        }
        cleansuperheroarr();
        m_superHeros = temp;
        m_maxsupersize *= 2;
    }

    if ((dynamic_cast<CaptainAmerica *>(superHero)) != nullptr)
    {
        m_superHeros[m_numSuperHeros++] = new CaptainAmerica(*((CaptainAmerica *)(superHero)));
        if (m_superHeros == nullptr)
        {
            cerr << "Error Memory" << endl;
        }
        return;
    }

    if ((dynamic_cast<Spiderman *>(superHero)) != nullptr)
    {
        m_superHeros[m_numSuperHeros++] = new Spiderman(*((Spiderman *)(superHero)));
        if (m_superHeros == nullptr)
        {
            cerr << "Error Memory" << endl;
        }
        return;
    }

    if ((dynamic_cast<ProfessionBasedSuperHero *>(superHero)) != nullptr)
    {
        m_superHeros[m_numSuperHeros++] = new ProfessionBasedSuperHero(*((ProfessionBasedSuperHero *)(superHero)));
        if (m_superHeros == nullptr)
        {
            cerr << "Error Memory" << endl;
        }
        return;
    }

    if ((dynamic_cast<AnimalBasedSuperHero *>(superHero)) != nullptr)
    {
        m_superHeros[m_numSuperHeros++] = new AnimalBasedSuperHero(*((AnimalBasedSuperHero *)(superHero)));
        if (m_superHeros == nullptr)
        {
            cerr << "Error Memory" << endl;
        }
        return;
    }
    if ((dynamic_cast<SuperHero *>(superHero)) != nullptr)
    {
        m_superHeros[m_numSuperHeros++] = new SuperHero(*superHero);
        if (m_superHeros == nullptr)
        {
            cerr << "Error Memory" << endl;
        }
        return;
    }
}

SuperHero **Avengers::getSuperHeros() const
{
    return m_superHeros;
}
void Avengers::printAvengersTeam() const
{
    cout << m_teamName << endl;
    const char *str = "----------------------------------------";
    for (int i = 0; i < m_numSuperHeros; i++)
    {
        m_superHeros[i]->print();
        cout << str << endl;
    }

    cout << "The Avengers Team Is Ready!" << endl;
}
void Avengers::initiateTeamAttack()
{
    for (int i = 0; i < m_numSuperHeros; i++)
    {
        if (m_superHeros[i]->getMod() == stand)
            m_superHeros[i]->changeMod();
        else
            cout << m_superHeros[i]->getName() << " is in attack mode" << endl;
    }
}
std::ostream &operator<<(std::ostream &outt, Avengers &AV)
{

    if (typeid(outt) == typeid(std::cout))

        AV.printAvengersTeam();
    if (typeid(outt) == typeid(std::ofstream))
    {
        AV.write(outt);
    }
    return outt;
}
ostream &Avengers::write(ostream &out)
{

    out << m_teamName << endl;
    for (int i = 0; i < m_maxsupersize; i++)
    {
        if (m_superHeros[i] != nullptr)
        {

            m_superHeros[i]->write(out);
            out << endl;
        }
    }
    return out;
}
istream &Avengers::read(istream &in)
{
    cleansuperheroarr();
    m_superHeros = new SuperHero *[m_maxsupersize];
    if (m_superHeros == nullptr)
    {
        cerr << "Error Memory" << endl;
        return in;
    }
    memset(m_superHeros, 0, m_maxsupersize * sizeof(SuperHero *));
    m_numSuperHeros = 0;

    string name, prof, animal;
    double age, agefreeze, websize;
    int years, count = 0;
    bool radio;
    string typee;
    for (int i = 0; strcmp(typee.c_str(), "#") != 0; i++) // i used # to knowe am i in end of file
    {
        in >> typee;
        // cout << typee.c_str() << endl;
        if (strcmp(typee.c_str(), "CaptainAmerica") == 0)
        {

            count++;
            continue;
        }

        if (strcmp(typee.c_str(), "Spiderman") == 0)
        {

            count++;
            continue;
        }

        if (strcmp(typee.c_str(), "ProfessionBasedSuperHero") == 0)
        {

            count++;
            continue;
        }

        if (strcmp(typee.c_str(), "AnimalBasedSuperHero") == 0)
        {
            count++;
            continue;
        }
        if (strcmp(typee.c_str(), "SuperHero") == 0)
        {

            count++;
            continue;
        }
    }
    if (count > m_maxsupersize)
    {
        cleansuperheroarr();
        m_superHeros = new SuperHero *[count];
        if (m_superHeros == nullptr)
        {
            cerr << "Error Memory" << endl;
            return in;
        }
        memset(m_superHeros, 0, count * sizeof(SuperHero *));
        m_numSuperHeros = 0;
        m_maxsupersize = count;
    }
    in.seekg(0);
    for (int i = 0; i < count; i++)
    {
        in >> typee;

        if (strcmp(typee.c_str(), "CaptainAmerica") == 0)
        {

            in >> name;
            in >> age;
            in >> radio;
            in >> prof;
            in >> years;
            in >> agefreeze;
            m_superHeros[i] = new CaptainAmerica(name.c_str(), age, radio, prof.c_str(), years, agefreeze);
            if (m_superHeros[i] == nullptr)
            {
                cerr << "Error Memory" << endl;
            }
            m_numSuperHeros++;
            continue;
        }

        if (strcmp(typee.c_str(), "Spiderman") == 0)
        {

            in >> name;
            in >> age;
            in >> radio;
            in >> animal;
            in >> websize;

            m_superHeros[i] = new Spiderman(name.c_str(), age, radio, animal.c_str(), websize);
            if (m_superHeros[i] == nullptr)
            {
                cerr << "Error Memory" << endl;
            }
            m_numSuperHeros++;
            continue;
        }

        if (strcmp(typee.c_str(), "ProfessionBasedSuperHero") == 0)
        {

            in >> name;
            in >> age;
            in >> radio;
            in >> prof;
            in >> years;

            m_superHeros[i] = new ProfessionBasedSuperHero(name.c_str(), age, radio, prof.c_str(), years);
            if (m_superHeros[i] == nullptr)
            {
                cerr << "Error Memory" << endl;
            }
            m_numSuperHeros++;
            continue;
        }

        if (strcmp(typee.c_str(), "AnimalBasedSuperHero") == 0)
        {

            in >> name;
            in >> age;
            in >> radio;
            in >> animal;
            m_superHeros[i] = new AnimalBasedSuperHero(name.c_str(), age, radio, animal.c_str());
            if (m_superHeros[i] == nullptr)
            {
                cerr << "Error Memory" << endl;
            }
            m_numSuperHeros++;
            continue;
        }
        if (strcmp(typee.c_str(), "SuperHero") == 0)
        {

            in >> name;
            in >> age;
            in >> radio;
            m_superHeros[i] = new SuperHero(name.c_str(), age, radio);
            if (m_superHeros[i] == nullptr)
            {
                cerr << "Error Memory" << endl;
            }
            m_numSuperHeros++;
            continue;
        }
    }
    return in;
}
istream &operator>>(istream &in, Avengers &AV)
{

    AV.read(in);

    return in;
}