#include <iostream>
#include <string>
#define StackEmpty

typedef std::string Elem;

class LinkedStack
{
public:
    LinkedStack();
    int size() const;
    bool empty() const;
    const Elem& top() const throw(StackEmpty);
    void push(const Elem& e);
    void pop() throw(StackEmpty);
    private:
    
}