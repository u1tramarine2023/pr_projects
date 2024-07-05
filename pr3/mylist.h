#ifndef MYLIST_H
#define MYLIST_H

#include <iostream>
#include <vector>

class MyList {
private:
    struct SElement {
        int data;
        SElement* next;

        SElement(int _data, SElement* _next) : data(_data), next(_next) {}
    };

    SElement* first;

public:
    MyList();
    MyList(int _data) ;
    MyList(int _data1, int _data2, int _data3) ;
    ~MyList() ;
    bool IsEmpty() ;
    void AddFirst(int _data);
    void DeleteFirst() ;
    std::vector<int> print() const ;

    class Iterator {
    public:
        virtual void First() = 0;
        virtual void Next() = 0;
        virtual bool IsDone() const = 0;
        virtual int CurrentItem() const = 0;
    };

    class ListIterator : public Iterator {
    public:
        ListIterator(const MyList* aList) : _list(aList), _current(0) {}

        void First() override {
            _current = 0;
        }

        void Next() override {
            _current++;
        }

        bool IsDone() const override {
            return (_current >= _list->print().size());
        }

        int CurrentItem() const override {
            std::vector<int> list = _list->print();
            if (_current < list.size()) {
                return list[_current];
            }
         }

    private:
        const MyList* _list;
        size_t _current;
    };

    ListIterator* CreateIterator() const {
        return new ListIterator(this);
    }
};

#endif // MYLIST_H
