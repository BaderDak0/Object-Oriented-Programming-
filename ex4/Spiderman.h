//name of hagshot
//  Bader Daka 208219212
//  Adham Jaber 204218184
//
#pragma once
#include "AnimalBasedSuperHero.h"
#include "SuperHero.h"
class Spiderman : public AnimalBasedSuperHero
{

public:
	Spiderman();
	Spiderman(const char *name, double age, bool radioactive, const char *animal, double webSize);
	Spiderman(const char *animal, double webSize);
	Spiderman(double webSize);
	Spiderman(const Spiderman &spiderman);
	virtual ~Spiderman(){};

	double getWebSize() const;
	void setWebSize(double webSize);
	virtual void print();
	// virtual istream &read(istream &in);
	virtual ostream &write(ostream &out);

protected:
	double _webSize;
};
