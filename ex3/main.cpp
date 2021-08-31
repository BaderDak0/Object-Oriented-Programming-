//name of hagshot
//  Bader Daka 208219212
//  Adham Jaber 204218184
//
#include "palindrom.h"
#include <cstring>
using namespace std;

int main(int argc, char const *argv[])
{
    palindrom **pali = new palindrom *[3];
    memset(pali, 0, 3 * sizeof(palindrom *));
    int x = 0, i = 0;
    char tmp[LEN];
    int j = 0, k = 0;
    char tav;
   const palindrom p=*pali[0];
    while (x != 10)
    {
        cout << "1:creat palindrome" << endl;
        cout << "2:edit palindrom " << endl;
        cout << "3:chaining palindrom" << endl;
        cout << "4: substract palindrome" << endl;
        cout << "5: add to palindrom" << endl;
        cout << "6: equal palendrom" << endl;
        cout << "7:increase palindrome" << endl;
        cout << "8:access tp palindrome" << endl;
        cout << "9: print palindrom " << endl;
        cout << "10:exit" << endl;
        cin >> x;
        switch (x)
        {
        case 1:
            cout << "please enter a number between 0-2:";
            cin >> i;
            cout << "please enter a palindrome string:";
            if (i < 0 || i > 2)
            {
                cout << "error" << endl;
                continue;
            }
            cin >> tmp;
            if (pali[i] == nullptr)
                pali[i] = new palindrom(tmp);

            if (pali[i]->getsize() == 0)
            {
                delete pali[i];
                pali[i] = nullptr;
            }
            cout << endl;
            break;
        case 2:
            cout << "please enter a number between 0-2:";
            cin >> i;
            cout << "please enter a palindrome string:";
            if ((i < 0 || i > 2) || pali[i] == nullptr)
            {
                cout << "error" << endl;
                continue;
            }

            cin >> (*pali[i]);
            cout << endl;
            break;
        case 3:
            cout << "please enter a number between 0-2 to left operand:";
            cin >> i;
            cout << "please enter a number between 0-2 to right operand:";
            cin >> j;
            cout << "please enter a number between 0-2 to Result operand:";
            cin >> k;
            if (((i < 0 || i > 2) && (j < 0 || j > 2) && (k < 0 || k > 2)) || ((pali[i] == nullptr) || (pali[j] == nullptr)))
            {
                cout << "error" << endl;
                continue;
            }
            if (i == k)
            {
                (*pali[i]) += (*pali[j]);
            }
            else
                (*pali[k]) = (*pali[i]) + (*pali[j]);

            cout << endl;
            break;
        case 4:
            cout << "please enter a number between 0-2 to left operand:";
            cin >> i;
            cout << "please enter a number between 0-2 to right operand:";
            cin >> j;
            if ((i < 0 || i > 2) && (j < 0 || j > 2) || ((pali[i] == nullptr) || (pali[j] == nullptr)))
            {
                cout << "error" << endl;
                continue;
            }
            (*pali[i]) -= (*pali[j]);
            cout << endl;
            break;
        case 5:
            cout << "please enter a number between 0-2 to left operand:";
            cin >> i;
            cout << "please enter a char Tav:";
            cin >> tav;
            if ((i < 0 || i > 2) || (pali[i] == nullptr))
            {
                cout << "error" << endl;
                continue;
            }
            (*pali[i]) += tav;
            cout << endl;
            break;
        case 6:
            cout << "please enter a number between 0-2 to left operand:";
            cin >> i;
            cout << "please enter a number between 0-2 to right operand:";
            cin >> j;
            if ((i < 0 || i > 2) && (j < 0 || j > 2) || ((pali[i] == nullptr) || (pali[j] == nullptr)))
            {
                cout << "error" << endl;
                continue;
            }
            if ((*pali[i]) < (*pali[j]) == true)
            {
                cout << "-1" << endl;
            }
            else if (((*pali[i]) == (*pali[j])) == true)
            {
                cout << "0" << endl;
            }
            else
            {
                cout << "1" << endl;
            }
            cout << endl;
            break;
        case 7:
            cout << "please enter a number between 0-2:";
            cin >> i;
            if ((i < 0 || i > 2) || (pali[i] == nullptr))
            {
                cout << "error" << endl;
                continue;
            }
            (*pali[i])++;
            cout << endl;
            break;
        case 8:
            cout << "please enter a number between 0-2:";
            cin >> i;
            cout << "please enter a index:";
            cin >> j;
            cout << endl;
            if ((i < 0 || i > 2) || (pali[i] == nullptr))
            {
                cout << "error" << endl;
                continue;
            }

            cout << (*pali[i][j]) << endl;
            break;

        case 9:
            cout << "please enter a number between 0-2 to print a palindrome:";
            cin >> i;
            cout << endl;
            if ((i < 0 || i > 2) || pali[i] == nullptr)
            {
                cout << "error" << endl;
                continue;
            }
            cout << (*pali[i]);
            break;
        case 10:

            x = 10;
            break;
        }
    }
    const char *name=*(pali[0]);
    cout<<name<<endl;
    for (int i = 0; i < 3; i++)
    {
        if (pali[i] != nullptr)
            delete pali[i];
    }
    delete[] pali;

    return 0;
}
