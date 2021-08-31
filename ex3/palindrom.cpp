//name of hagshot
//  Bader Daka 208219212
//  Adham Jaber 204218184
//
#include "palindrom.h"
#include <cstring>
using namespace std;

palindrom::palindrom()
{
    m_size = 0;
}
palindrom::palindrom(char *str)
{
    if (ispalindrom(str) == false)
    {
        cout << "this string is not palindrome" << endl;
        m_size = 0;
    }
    else
    {

        m_size = strlen(str);
        m_str = halfpali(str);
    }
}
palindrom::palindrom(const palindrom &pali)
{
    *this = pali;
}
palindrom::~palindrom()
{
    m_str.clear();
}

palindrom &palindrom::operator+=(const palindrom &pal)
{
    if (pal.m_str.empty() == true)
    {
        m_str = pal.m_str;
        m_size = pal.m_size;
        return *this;
    }
    m_str += pal.m_str;
    if (m_size % 2 == 1)
    {
        m_size = m_size + pal.m_size + 1;
    }
    else

        m_size += pal.m_size;

    return *this;
}
palindrom &palindrom::operator+=(char Tav)
{

    char *str = new char[m_str.length() + 2];
    str[0] = Tav;

    strcpy(str + 1, m_str.c_str());

    m_str = str;
    m_size += 2;
    delete[] str;

    return *this;
}
char *makepalindrom(const std::string &m_str, int m_size)
{
    int len = m_str.length();
    char *s1 = new char[len + 1];
    strcpy(s1, m_str.c_str());
    char *s2 = new char[len + 1];
    strcpy(s2, m_str.c_str());
    char *s3 = new char[m_size + 1];
    int x = (m_size - (2 * len));
    int i = 0;
    for (i = 0; i < len; i++)
    {
        s3[i] = s1[i];
    }
    char tmp = s3[i - 1];
    for (int j = 0; j < x; j++)
    {
        s3[i] = tmp;
        i++;
    }
    if (x < 0)
    {
        for (int k = len - 2; k >= 0; k--)
        {
            s3[i] = s2[k];
            i++;
        }
    }
    else
    {
        for (int k = len - 1; k >= 0; k--)
        {
            s3[i] = s2[k];
            i++;
        }
    }
    delete[] s1;
    delete[] s2;
    s3[i] = '\0';
    return s3;
}
bool ispalindrom(const char *str)
{
    int i = 0, length = 0;
    int flag = 0;

    length = strlen(str);

    for (i = 0; i < length; i++)
    {
        if (str[i] != str[length - i - 1])
        {
            flag = 1;
            break;
        }
    }

    if (flag)
    {
        return false;
    }
    else
    {
        return true;
    }
}
char *halfpali(char *str)
{
    int len = strlen(str);
    int x = len / 2;

    while (x > 0 && str[x] == str[x - 1])
    {
        x -= 1;
    }
    str[x + 1] = '\0';

    return str;
}
palindrom &palindrom::operator-=(const palindrom &pali)
{
    int flag = 0;
    char *tmp = makepalindrom(m_str, m_size);
    char *tmp2 = makepalindrom(pali.m_str, pali.m_size);
    int length1 = strlen(tmp);
    int length2 = strlen(tmp2);
    char *s3 = new char[length1 - length2];
    int m = 0;
    for (int i = 0; i < length2; i++) //y=ba
    {
        for (int j = 0; j < length1; j++) //x==abcba       x-=y =aa s3=aa
        {
            if (tmp[j] == tmp2[i])
            {
                tmp[j] = '$';
                break;
            }
        }
    }
    for (int i = 0; i < length1; i++)
    {
        if (tmp[i] != '$')
        {
            s3[m] = tmp[i];
            m++;
        }
    }
    s3[m] = '\0';
    if (ispalindrom(s3) == true)
    {
        m_str = halfpali(s3);
        m_size = length1 - length2;
    }
    delete[] tmp;
    delete[] tmp2;
    delete[] s3;
    return *this;
}
palindrom operator+(const palindrom &pali1, const palindrom &pali2)
{
    palindrom tmp(pali1);
    tmp += pali2;
    return tmp;
}

palindrom &palindrom::operator++(int)
{
    char tav = m_str[0];
    switch (tav)
    {
    case 'z':
        m_str[0] = 'a';
        break;
    case 'Z':
        m_str[0] = 'A';
        break;
    case '9':
        m_str[0] = '0';
        break;

    default:
        m_str[0] += 1;
        break;
    }
    return *this;
}
char *tolowerr(char *str)
{

    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] <= 'Z' && str[i] >= 'A')
            str[i] -= ('Z' - 'z');
    }
    return str;
}
bool palindrom::operator==(const palindrom &pali)
{
    if (this->m_size != pali.m_size)
        return false;

    char *tmp = new char[strlen(m_str.c_str()) + 1];
    char *tmp2 = new char[strlen(pali.m_str.c_str()) + 1];
    tmp = tolowerr(tmp);
    tmp2 = tolowerr(tmp2);
    if (strcmp(tmp, tmp2) == 0)
    {
        return true;
    }
    delete[] tmp;
    delete[] tmp2;
    return false;
}
palindrom &palindrom::operator!()
{
    char *tmp = new char[strlen(m_str.c_str()) + 1];
    strcpy(tmp, m_str.c_str());
    tmp[strlen(m_str.c_str())] = '\0';
    m_str = tolowerr(tmp);
    delete[] tmp;
    return *this;
}
palindrom::operator const char *() const
{
    const char *tmp=m_str.c_str();
    return tmp;
}
char palindrom::operator[](int i)
{
    if (i < 0 || i >= m_str.length())
        return '?';

    return m_str[i];
}

bool palindrom::operator<(const palindrom &pali)
{
    char *tmp = new char[strlen(m_str.c_str()) + 1];
    strcpy(tmp, m_str.c_str());
    tmp[strlen(m_str.c_str())] = '\0';
    tmp = tolowerr(tmp);

    char *tmp2 = new char[strlen(pali.m_str.c_str()) + 1];
    strcpy(tmp2, pali.m_str.c_str());
    tmp2[strlen(pali.m_str.c_str())] = '\0';
    tmp2 = tolowerr(tmp2);

    if (strcmp(tmp, tmp2) == -1)
    {
        return true;
    }
    delete[] tmp;
    delete[] tmp2;
    return false;
}
palindrom &palindrom::operator=(const palindrom &pali)
{
    m_str = pali.m_str;
    m_size = pali.m_size;

    return *this;
}
std::ostream &operator<<(std::ostream &out, const palindrom &pali)
{

    char *tmp = makepalindrom(pali.m_str, pali.m_size);
    out << tmp << endl;

    return out;
}
std::istream &operator>>(std::istream &in, palindrom &pali)
{
    char tmp[LEN];

    in >> tmp;
    if (ispalindrom(tmp) == false)
    {

        return in;
    }

    pali.m_size = strlen(tmp);
    pali.m_str = halfpali(tmp);
    return in;
}
int palindrom::getsize() const
{

    return m_size;
}