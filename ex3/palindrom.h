//name of hagshot 
//  Bader Daka 208219212
//  Adham Jaber 204218184
//
#pragma once
#include <iostream>
#include <string>
#define LEN 256
class palindrom
{
public:
    palindrom();
    palindrom(char *);
    palindrom(const palindrom &);
    ~palindrom();

public:
    palindrom &operator+=(const palindrom &);
    palindrom &operator+=(char);
    palindrom &operator-=(const palindrom &);
    palindrom &operator++(int);
    bool operator==(const palindrom &);
    palindrom &operator!();
    char operator[](int);
    operator const char *() const;
    bool operator<(const palindrom &);
    palindrom &operator=(const palindrom &);
   

    friend std::ostream &operator<<(std::ostream &out, const palindrom &);
    friend std::istream &operator>>(std::istream &in, palindrom &);
    int getsize() const;

private:
    std::string m_str;
    int m_size;
};
char *tolowerr(char *str);
char* halfpali(char *str);
char *makepalindrom(const std::string &m_str, int m_size);
palindrom operator+(const palindrom &, const palindrom &);
bool ispalindrom(const char *);
std::ostream &operator<<(std::ostream &out, const palindrom &);
std::istream &operator>>(std::istream &in, palindrom &);