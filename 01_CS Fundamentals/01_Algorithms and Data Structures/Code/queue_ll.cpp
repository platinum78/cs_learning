#include <iostream>
#include <string>
#include "./circularly_linked_list.cpp"

typedef std::string Elem;

class LinkedQueue
{
    public:
    LinkedQueue();
    int size() const;
    bool empty() const;
    const Elem& front();
    void enqueue(const Elem& e);
    void dequeue();

    private:
    CircleList c;
    int n;
};

LinkedQueue::LinkedQueue() : c(), n(0) {}

int LinkedQueue::size() const
{
    return n;
}

bool LinkedQueue::empty() const
{
    return n == 0;
}

const Elem& LinkedQueue::front()
{
    return c.front();
}

void LinkedQueue::enqueue(const Elem& e)
{
    c.add(e);
    c.advance();
    n++;
}

void LinkedQueue::dequeue()
{
    c.remove();
    n--;
}