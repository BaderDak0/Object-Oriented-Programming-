//name of hagshot
//  Bader Daka 208219212
//  Adham Jaber 204218184
//
#pragma once

#include "SuperHero.h"

class ProfessionBasedSuperHero : public SuperHero
{
public:
	ProfessionBasedSuperHero();
	ProfessionBasedSuperHero(const char *name, double age, bool radioactive, const char *profession, int yearsExperience);
	ProfessionBasedSuperHero(const char *profession, int yearsExperience);
	ProfessionBasedSuperHero(const ProfessionBasedSuperHero &professionBasedSuperHero);
	virtual ~ProfessionBasedSuperHero();

public:
	void setProfession(const char *profession);
	const char *getProfession() const { return m_profession; }
	void setYearsExperience(int yearsExperience);
	int getYearsExperience() const;
	virtual void print();
	// virtual istream &read(istream &in);
	virtual ostream &write(ostream &out);

protected:
	int m_yearsExperience;
	char *m_profession;
};
