#ifndef MYLIST_H
#define MYLIST_H

#include <iostream>
#include <vector>
struct SElement
{
    int data;
    SElement* next;
    SElement(int _data, SElement* _next){
        data=_data;
        next=_next;
    }

    ~SElement() = default;
};

class MyList
{
private:
    SElement *first;
public:
    MyList();
    MyList(int _data);
    MyList(int _data1, int _data2, int _data3);
    ~MyList();
    bool IsEmpty();
    void AddFirst(int _data);
    void DeleteFirst();
    std::vector<int> print();
    int GetData(){return first->data;}
    SElement* GetFirst(){return first;}
};
#endif // MYLIST_H
