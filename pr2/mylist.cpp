#include "mylist.h"

MyList::MyList()
{
    first = nullptr;
}

MyList::MyList(int _data)
{
    first = new SElement(_data, nullptr);
}

MyList::MyList(int _data1, int _data2, int _data3)
{
    first = new SElement(_data1, nullptr);
    SElement *tmp = new SElement(_data2, nullptr);
    first->next = tmp;
    tmp = new SElement(_data3, nullptr);
    first->next->next = tmp;
}

MyList::~MyList()
{
    while(first != nullptr)
        this->DeleteFirst();
}

void MyList::AddFirst(int _data){
    SElement* NewFirst = new SElement(_data, first);
    first = NewFirst;
}

std::vector<int> MyList::print()
{

        std::vector<int> vector_list;
        SElement* temp = first;

        while (temp != nullptr) {
            vector_list.push_back(temp->data);
            temp = temp->next;
        }
        return vector_list;

}

void MyList::DeleteFirst(){
    if(IsEmpty()){ return;}
    SElement *tmp = first;
    first = tmp->next;
    delete tmp;
}


bool MyList::IsEmpty(){
    return ( first==nullptr);
}
