//name of hagshot
//  Bader Daka 208219212
//  Adham Jaber 204218184
//
#pragma once
#include <iostream>
using namespace std;
class covid19
{

public:
    covid19();
    covid19(float R, int molecules, bool vacc, const char *name);
    covid19(const covid19 &);
    virtual ~covid19();

public:
    char *getname() const;
    float getratio() const;
    int getmolecules() const;
    bool getvacc() const;
    virtual void setgenetic(const char *DNA);
    virtual void print();

protected:
    float m_R;
    int m_molecules;
    bool m_vacc;
    char *m_name;
};