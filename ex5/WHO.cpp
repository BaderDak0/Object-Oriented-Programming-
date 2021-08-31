//name of hagshot
//  Bader Daka 208219212
//  Adham Jaber 204218184
//
#include "WHO.h"
#include <cstring>
#include <typeinfo>
WHO::WHO() : m_people(0), m_viruscount(0), m_maxsize(maxsize), m_infected(0), m_country(nullptr)
{
    m_corona = new covid19 *[m_maxsize];
    if (m_corona == nullptr)
    {
        throw("Bad ALLOC Memory");
    }
    memset(m_corona, 0, m_maxsize * sizeof(covid19 *));
}
WHO ::~WHO()
{
    clear();
}
WHO::WHO(const char *country, int people, int infected)
    : m_people(people), m_infected(infected), m_maxsize(maxsize), m_viruscount(0)
{
    if (country == nullptr)
        throw("no name of country");

    m_country = country;
    m_corona = new covid19 *[m_maxsize];
    if (m_corona == nullptr)
    {
        throw("Bad ALLOC Memory");
    }
    memset(m_corona, 0, m_maxsize * sizeof(covid19 *));
}
WHO::WHO(const WHO &w)
{
    *this = w;
}
void WHO::Addvirus(covid19 *cov)
{
    

    if (cov == nullptr)
        throw("Bad argument");

    for (int i = 0; i < m_viruscount; i++)
    {
        if (strcmp(cov->getname(), m_corona[i]->getname()) == 0)
        {
            throw("Virus exists");
        }
    }
    
    if (m_viruscount == m_maxsize)
    {
        covid19 **tmp = new covid19 *[m_maxsize * 2];
        if (tmp == nullptr)
            throw("Bad Alloc Memory");
        memset(tmp, 0, (m_maxsize * 2) * sizeof(covid19 *));
        for (int i = 0; i < m_maxsize; i++)
        {

            if ((dynamic_cast<covidKZ *>(m_corona[i]) != nullptr))
            {
                tmp[i] = new covidKZ(*(dynamic_cast<covidKZ *>(m_corona[i])));
                if (tmp[i] == nullptr)
                    throw("Bad Alloc Memory");
            }
            if ((dynamic_cast<covidGB *>(m_corona[i]) != nullptr))
            {
                tmp[i] = new covidGB(*(dynamic_cast<covidGB *>(m_corona[i])));
                if (tmp[i] == nullptr)
                    throw("Bad Alloc Memory");
            }
            if ((dynamic_cast<covidSA *>(m_corona[i]) != nullptr))
            {
                tmp[i] = new covidSA(*(dynamic_cast<covidSA *>(m_corona[i])));
                if (tmp[i] == nullptr)
                    throw("Bad Alloc Memory");
            }
            if ((dynamic_cast<covid19 *>(m_corona[i]) != nullptr))
            {
                tmp[i] = new covid19(*m_corona[i]);
                if (tmp[i] == nullptr)
                    throw("Bad Alloc Memory");
            }
        }
        m_maxsize *= 2;
        clear();
        m_corona = tmp;
    }
    if ((dynamic_cast<covidKZ *>(cov) != nullptr))
    {
        m_corona[m_viruscount++] = new covidKZ(*(dynamic_cast<covidKZ *>(cov)));
        if (m_corona[m_viruscount - 1] == nullptr)
            throw("Bad Alloc Memory");

        return;
    }
    if ((dynamic_cast<covidGB *>(cov) != nullptr))
    {
        m_corona[m_viruscount++] = new covidGB(*(dynamic_cast<covidGB *>(cov)));
        if (m_corona[m_viruscount - 1] == nullptr)
            throw("Bad Alloc Memory");
        return;
    }
    if ((dynamic_cast<covidSA *>(cov) != nullptr))
    {
        m_corona[m_viruscount++] = new covidSA(*(dynamic_cast<covidSA *>(cov)));
        if (m_corona[m_viruscount - 1] == nullptr)
            throw("Bad Alloc Memory");
        return;
    }
    if ((dynamic_cast<covid19 *>(cov) != nullptr))
    {
        m_corona[m_viruscount++] = new covid19(*cov);
        if (m_corona[m_viruscount - 1] == nullptr)
            throw("Bad Alloc Memory");
        return;
    }
}

WHO &WHO::operator=(const WHO &w)
{
    m_viruscount = w.m_viruscount;
    m_maxsize = w.m_maxsize;
    m_country = w.m_country;
    m_people = w.m_people;
    m_infected = w.m_infected;

    for (int i = 0; i < w.m_viruscount; i++)
    {
        if ((dynamic_cast<covidKZ *>(w.m_corona[i])) != nullptr)
        {
            m_corona[i] = new covidKZ(*(dynamic_cast<covidKZ *>(w.m_corona[i])));
            if (m_corona[i] == nullptr)
            {
                throw("Error allocating memory");
            }
            continue;
        }
        if ((dynamic_cast<covidGB *>(w.m_corona[i])) != nullptr)
        {
            m_corona[i] = new covidGB(*(dynamic_cast<covidKZ *>(w.m_corona[i])));
            if (m_corona[i] == nullptr)
            {
                throw("Error allocating memory");
            }
            continue;
        }
        if ((dynamic_cast<covidSA *>(w.m_corona[i])) != nullptr)
        {
            m_corona[i] = new covidSA(*(dynamic_cast<covidKZ *>(w.m_corona[i])));
            if (m_corona[i] == nullptr)
            {
                throw("Error allocating memory");
            }
            continue;
        }
        if ((dynamic_cast<covid19 *>(w.m_corona[i])) != nullptr)
        {
            m_corona[i] = new covid19(*((covid19 *)(w.m_corona[i])));
            if (m_corona[i] == nullptr)
            {
                throw("Error allocating memory");
            }
            continue;
        }
    }
    return *this;
}
bool WHO::Change_genetic(const char *DNA, int i)
{

    m_corona[i]->setgenetic(DNA);

    return true;
}

covid19 **WHO::getcovid() const
{
    return m_corona;
}

ostream &operator<<(ostream &out, const WHO &w)
{
    covid19 **tmp = w.getcovid();
    for (int i = 0; i < w.getviruscount(); i++)
    {

        tmp[i]->print();
        out << "*----------------------------------------------*" << endl;
    }

    return out;
}
int WHO::getinfected() const
{
    return m_infected;
}
int WHO::getpeople() const
{
    return m_people;
}
int WHO::getviruscount() const
{
    return m_viruscount;
}
void WHO::clear()
{
    for (int i = 0; i < m_viruscount; i++)
    {
        delete m_corona[i];
    }
    delete[] m_corona;
}