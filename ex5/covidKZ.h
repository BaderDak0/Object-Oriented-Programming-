//name of hagshot
//  Bader Daka 208219212
//  Adham Jaber 204218184
//
#pragma once
#include "covid19.h"
#include "covidGB.h"
#include "covidSA.h"

class covidKZ : public covidGB, public covidSA
{
public:
    covidKZ();
    covidKZ(float R, int molecules, bool vacc,const char *name, const char *countryA,const char *countryB ,int lungs, int liver,const char *DNA);
    covidKZ(const covidKZ &);
    virtual ~covidKZ();
    virtual void print();
 virtual   void setgenetic(const char *DNA);

protected:
    char *m_DNA;
};
