#include "stack.h"

void Stack::push(int _data){
    stack.AddFirst(_data);
}
void Stack::pop() {
    stack.DeleteFirst();
}
bool Stack::IsEmpty(){
    return(stack.IsEmpty());
}
std::vector<int> Stack::print() {
    return stack.print();
}
