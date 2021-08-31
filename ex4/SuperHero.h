//name of hagshot
//  Bader Daka 208219212
//  Adham Jaber 204218184
//
#pragma once
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
enum Mod
{
	attack,
	stand
};
class SuperHero
{
public:
	SuperHero();
	SuperHero(const char *name, double age, bool radioactive = false);
	SuperHero(const SuperHero &superHero);
	virtual ~SuperHero();

public:
	const char *getName() const;
	double getAge() const;
	bool getRadioactive() const;
	void setName(const char *name);
	void setAge(double age);
	void setRadioactive(bool radioactive);
	void changeMod();
	Mod getMod() const;
	virtual void print() ;
    // virtual istream& read(istream& in);
    virtual ostream& write(ostream& out);
protected:
	char *m_name;
	double m_age;
	bool m_radioactive;

private:
	Mod m_mod = stand;
};
