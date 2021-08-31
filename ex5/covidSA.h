//name of hagshot
//  Bader Daka 208219212
//  Adham Jaber 204218184
//
#pragma once
#include "covid19.h"
class covidSA : virtual public covid19
{

public:
  covidSA();
  covidSA(float R, int molecules, bool vacc, const char *name, const char *country, int liver);
  covidSA(const covidSA &);
  virtual ~covidSA() {}
  virtual void print();
  virtual void setgenetic(const char *DNA);

protected:
  int m_liver;
  const char *m_countryA;
};