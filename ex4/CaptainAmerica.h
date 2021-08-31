//name of hagshot
//  Bader Daka 208219212
//  Adham Jaber 204218184
//
#include "ProfessionBasedSuperHero.h"
#include "SuperHero.h"
class CaptainAmerica : public ProfessionBasedSuperHero
{
public:
	CaptainAmerica();
	CaptainAmerica(const char *name, double age, bool radioactive, const char *profession, int yearsExperience, double ageIncludingFreezing);
	CaptainAmerica(const char *profession, int yearsExperience, double ageIncludingFreezing);
	CaptainAmerica(double ageIncludingFreezing);
	CaptainAmerica(const CaptainAmerica &captainAmerica);
	virtual ~CaptainAmerica() {}

	double getAgeIncludingFreezing() const;
	void setAgeIncludingFreezing(double ageIncludingFreezing);
	virtual void print();
	//virtual istream &read(istream &in);
	virtual ostream &write(ostream &out);

protected:
	double _ageIncludingFreezing;
};
