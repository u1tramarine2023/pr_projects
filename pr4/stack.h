#ifndef STACK_H
#define STACK_H

#include "MyList.h"
#include <vector>

class Stack {
public:
    Stack(){};

    Stack(int _data);
    void push(int _data);
    void pop();
    bool IsEmpty();
    std::vector<int> print();
private:
    MyList stack;
};
#endif // STACK_H
