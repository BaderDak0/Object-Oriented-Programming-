//name of hagshot
//  Bader Daka 208219212
//  Adham Jaber 204218184
//
#include "Avengers.h"

using namespace std;

int main()
{

	SuperHero *superArr[5];
	superArr[0] = new SuperHero("Clark Kent", 25);
	superArr[1] = new ProfessionBasedSuperHero("IronMan", 38, false, "entrepreneur", 18);
	superArr[2] = new AnimalBasedSuperHero("Scott Lang", 30, false, "Ant");
	superArr[3] = new CaptainAmerica("Steve Rogers", 22, true, "soldier", 75, 89);
	superArr[4] = new Spiderman("Peter Parker", 17, true, "spider", 2.3);

	Avengers team("Avengers");

	team.setSuperHeros(superArr, 5);
	team.addSuperHero(new AnimalBasedSuperHero("Batman", 35, false, "Bat"));
	
	cout << team << endl;
	team.initiateTeamAttack();
	// team.printAvengersTeam();

	// ofstream out("teamoutput.txt");
	// if (!out.is_open())
	// {
	// 	cerr << "Error could not open file" << endl;
	// 	return 0;
	// }
	// out << team << endl;
	// ifstream in("teaminput.txt");
	// if (!in.is_open())
	// {
	// 	cerr << "Error could not find file" << endl;
	// 	return 0;
	// }
	// in >> team;

	// // cout << team << endl;

	// for (int i = 0; i < 5; i++)
	// {
	// 	delete superArr[i];
	// }
	// out.close();
	// in.close();
	return 0;
}
