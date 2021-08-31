//name of hagshot
//  Bader Daka 208219212
//  Adham Jaber 204218184
//
#include "WHO.h"
#include <cstring>

int main(int argc, char const *argv[])
{
    covid19 **c19 = new covid19 *[5];
    memset(c19, 0, 5 * sizeof(covid19 *));

    try
    {

        c19[0] = new covid19(1.1, 50000, true, "SJBDYSLNHSJDMJDUESKD");
        c19[1] = new covidGB(5.5, 1000, false, "SJBDYSLNHSJDMJDADAMM", "Britan", 5);
        c19[2] = new covidKZ(1.33, 100, false, "ASSSAWCTACGTTGCCATTG", "icland", "turkey", 4, 3, "AAGTGCCTACGTTGCCATTG");
        c19[3] = new covidSA(4.4, 2000, false, "SJBDYSLNHSJDMJDBADER", "AFRICA", 6);
        c19[4] = new covidKZ(7.7, 7000, true, "SJBDYSLNHSJBADERADAM", "AFRICA", "BRITAN", 7, 8, "AAGTGCCTACGTTGCCTTTT");
    }
    catch (const char *error_creating)
    {
        cout << "*------------------------------*" << endl;
        std::cerr << error_creating << endl;
        cout << "*------------------------------*" << endl;
        return 0;
    }

    WHO who("AMERCA", 5000000, 1000000);
    try
    {

        who.Addvirus(c19[0]);
        who.Addvirus(c19[1]);
        who.Addvirus(c19[2]);
        who.Addvirus(c19[3]);
        who.Addvirus(c19[4]);
    }
    catch (const char *ADD_VIRUSERROR)
    {
        cout << "*------------------------------*" << endl;
        std::cerr << ADD_VIRUSERROR << endl;
        cout << "*------------------------------*" << endl;
        return 0;
    }
    cout << who << endl;
    try
    {
        who.Change_genetic("TTTTTTTTTTTTTTTTTTTT", 2);
        who.Change_genetic("TTTTTTTTTTTTTTTYTTTT", 3);
    }
    catch (const char *error)
    {
        cout << "*------------------------------*" << endl;
        std::cerr << error << endl;
        cout << "*------------------------------*" << endl;
    }

    cout << who << endl;

    for (int i = 0; i < 5; i++)
    {
        delete c19[i];
    }

    delete[] c19;

    return 0;
}
