#pragma once
#include <iostream>
#include <fstream>
using namespace std;

template <typename T>
class Node
{
public:
    Node(T *data) : m_data(data), next(nullptr) {}
    Node() : m_data(nullptr), next(nullptr) {}
    ~Node()
    {
        delete m_data;
        delete next;
    }
    void setnext(Node *node) { next = node; }

public:
    T *getdata() { return m_data; }
    void setdata(T *data) { m_data = data; }
    Node<T> *getnext() { return this->next; }

private:
    Node<T> *next;
    T *m_data;
};

template <typename T>
class list
{
public:
    list() : m_head(nullptr), m_tail(nullptr), m_size(0) {}
    ~list() { delete m_head; }
    bool insert(const T &item);
    int getsize() const { return m_size; }
    list<T> &operator=(const list<T> &listt);
    T &operator[](int index);
    Node<T> *gethead() const { return m_head; }

protected:
    //  friend ostream &operator<<(ostream &out, const list<T>& listt);
    int m_size;
    Node<T> *m_head;
    Node<T> *m_tail;
};
template <typename T>
ostream &operator<<(ostream &out, const list<T> &listt)
{
    Node<T> *tmp = listt.gethead();
    out << "|size: " << listt.getsize() << "| ";
    for (int i = 0; i < listt.getsize(); i++)
    {
        out << *tmp->getdata() << " ";
        tmp = tmp->getnext();
    }
    out << endl;
    return out;
}

template <typename T>
bool list<T>::insert(const T &item)
{
    Node<T> *newnode = new Node<T>(new T(item));
    if (m_head == nullptr)
    {
        m_head = newnode;
        m_tail = newnode;
        m_size++;
        return true;
    }
    m_tail->setnext(newnode);
    m_tail = newnode;
    m_size++;
    return true;
}
template <typename T>
list<T> &list<T>::operator=(const list<T> &listt)
{
    list<T> newlist;
    newlist.m_size = listt.m_size;
    Node<T> *tmp = listt.m_head;
    for (int i = 0; i < listt.m_size; i++)
    {
        newlist.insert(tmp->m_data);
        tmp = tmp->next;
    }

    return newlist;
}
template <typename T>
T &list<T>::operator[](int index)
{
    if (index < 0 || index > m_size)
    {
        throw("LIST_INVALID_INDEX");
    }
    Node<T> *tmp = m_head;
    for (int i = 1; i < index; i++)
    {
        tmp = tmp->getnext();
    }
    return *tmp->getdata();
}


// template <typename T>
// class math : public list<T>
// {
// public:
//     math() : list<T>() {}
//     ~math() {}

// public:
//     T mean() ;
// };
// template <typename T>
// T math<T>::mean() 
// {
    
//    int size=this->m_size; 
//    Node<T>* tmp=this->m_head;
//     T mid,avr;
//     for (int i =0; i < size; i++)
//     {
//         mid+=*tmp->getdata();
//         tmp=tmp->getnext();
//     }

//     avr=mid/size;
//     return avr;   
// }