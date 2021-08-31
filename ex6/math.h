#pragma once
#include "list.h"

template <typename T>
class math : public list<T>
{
public:
    math() : list<T>() {}
    ~math() {}

public:
    T mean();
    void sort(int x);
};
template <typename T>
T math<T>::mean()
{

    int size = this->m_size;
    Node<T> *tmp = this->m_head;
    T mid, avr;
    for (int i = 0; i < size; i++)
    {
        mid += *tmp->getdata();
        tmp = tmp->getnext();
    }

    avr = mid / size;
    return avr;
}
template <typename T>
void math<T>::sort(int x)
{
    Node<T> *tmp = this->m_head;
    Node<T> *tmp2 = this->m_head;
    Node<T> *tmp3 = this->m_head;
    T tmp4;
    if (x == 1)
    {
        for (int i = 0; i < this->m_size; i++)
        {
            for (int k = 0; k < i + 1; k++)
            {
                tmp2 = tmp2->getnext();
            }

            for (int j = i + 1; j < this->m_size; j++)
            {
                if (*tmp->getdata() > *tmp2->getdata())
                {
                    tmp4 = *tmp->getdata();
                    *tmp->getdata() = *tmp2->getdata();
                    *tmp2->getdata() = tmp4;
                    
                }
                tmp2 = tmp2->getnext();
            }
            tmp2 = tmp3;
            tmp = tmp->getnext();
        }
    }
    else
    {
        for (int i = 0; i < this->m_size; i++)
        {
            for (int k = 0; k < i + 1; k++)
            {
                tmp2 = tmp2->getnext();
            }

            for (int j = i + 1; j < this->m_size; j++)
            {
                if (*tmp->getdata() < *tmp2->getdata())
                {
                    tmp4 = *tmp->getdata();
                    *tmp->getdata() = *tmp2->getdata();
                    *tmp2->getdata() = tmp4;
                    
                }
                tmp2 = tmp2->getnext();
            }
            tmp2 = tmp3;
            tmp = tmp->getnext();
        }
    }
    
}
