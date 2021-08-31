//name of hagshot
//  Bader Daka 208219212
//  Adham Jaber 204218184
//
#pragma once
#include "SuperHero.h"
class AnimalBasedSuperHero : public SuperHero
{
public:
	AnimalBasedSuperHero();
	AnimalBasedSuperHero(const char *name, double age, bool radioactive, const char *animal);
	AnimalBasedSuperHero(const char *animal);
	AnimalBasedSuperHero(const AnimalBasedSuperHero &animalBasedSuperHero);

	virtual ~AnimalBasedSuperHero();

public:
	void setAnimal(const char *animal);
	const char *getAnimal() const;
	virtual void print();
	//virtual istream &read(istream &in);
	virtual ostream &write(ostream &out);

protected:
	char *m_animal;
};
