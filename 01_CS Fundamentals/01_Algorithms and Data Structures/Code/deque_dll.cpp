#include <iostream>
#include <string>
#include "./doubly_linked_list.cpp"

typedef std::string Elem;

class LinkedDeque
{
    public:
    LinkedDeque();
    int size() const;
    bool empty() const;
    const Elem& front() const;
    const Elem& back() const;
    void insertFront(const Elem& e);
    void insertBack(const Elem& e);
    void removeFront();
    void removeBack();

    private:
    DLinkedList D;
    int n;
};

LinkedDeque::LinkedDeque() : D(), n(0) {}

int LinkedDeque::size() const
{
    return n;
}

bool LinkedDeque::empty() const
{
    return n == 0;
}

const Elem& LinkedDeque::front() const
{
    return D.front();
}

const Elem& LinkedDeque::back() const
{
    return D.rear();
}

void LinkedDeque::insertFront(const Elem& e)
{
    D.addFront(e);
    n++;
}

void LinkedDeque::insertBack(const Elem& e)
{
    D.addRear(e);
    n++;
}

void LinkedDeque::removeFront()
{
    D.removeFront();
    n--;
}

void LinkedDeque::removeBack()
{
    D.removeRear();
    n--;
}