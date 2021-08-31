
//name of hagshot
//  Bader Daka 208219212
//  Adham Jaber 204218184
//#pragma once
#include <iostream>
#include <cstring>
#include <fstream>
#include "SuperHero.h"
#include "Spiderman.h"
#include "AnimalBasedSuperHero.h"
#include "ProfessionBasedSuperHero.h"
#include "CaptainAmerica.h"
#define supersize 3
class Avengers
{
public:
	Avengers();
	Avengers(const char *);
	~Avengers();

public:
	void setSuperHeros(SuperHero **superHeros, int size);
	void addSuperHero(SuperHero *superHero);
	SuperHero **getSuperHeros() const;
	virtual void printAvengersTeam() const;
	void initiateTeamAttack();
	std::string getteamname() const { return m_teamName; }
	virtual istream &read(istream &in);
	virtual ostream &write(ostream &out);

protected:
	void cleansuperheroarr();
	SuperHero **m_superHeros;
	int m_numSuperHeros;
	int m_maxsupersize;
	std::string m_teamName;
};
std::ostream &operator<<(std::ostream &out, Avengers &AV);
std::istream &operator>>(std::istream &in, Avengers &AV);