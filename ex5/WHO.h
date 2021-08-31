//name of hagshot
//  Bader Daka 208219212
//  Adham Jaber 204218184
//
#pragma once
#include "covid19.h"
#include "covidGB.h"
#include "covidKZ.h"
#include "covidSA.h"
using namespace std;
#define maxsize 3 
class WHO
{
public:
    WHO();
    WHO(const char *country, int people, int infected);
    WHO(const WHO &);
    ~WHO();

public:
    void Addvirus(covid19* cov);
    WHO &operator=(const WHO &);
    bool Change_genetic(const char *, int );
    covid19 **getcovid() const;
    int getinfected() const;
    int getpeople() const;
    int getviruscount() const;
    void clear();
private:
    covid19 **m_corona;
    int m_maxsize;
    const char* m_country;
    int m_people;
    int m_infected;
    int m_viruscount;
};

ostream &operator<<(ostream &out, const WHO &);
