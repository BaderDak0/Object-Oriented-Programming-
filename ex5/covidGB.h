//name of hagshot
//  Bader Daka 208219212
//  Adham Jaber 204218184
//
#pragma once
#include "covid19.h"
class covidGB : virtual public covid19
{

public:
    covidGB();
    covidGB(float R, int molecules, bool vacc, const char *name, const char *country, int lungs);
    covidGB(const covidGB &);
    virtual ~covidGB() {}

public:
    int getlungs() const;
    const char *getcountr() const;
    virtual void print();
    virtual void setgenetic(const char *DNA);

protected:
    int m_lungs;
    const char *m_countryB;
};