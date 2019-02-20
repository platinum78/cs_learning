#include <iostream>
#include <string>

typedef std::string Elem;

class CNode
{
    private:
    Elem elem;
    CNode* next;
    friend class CircleList;
};

class CircleList
{
    public:
    CircleList();
    ~CircleList();
    bool empty() const;
    const Elem& front() const;
    const Elem& rear() const;
    void advance();
    void add(const Elem& e);
    void remove();

    private:
    CNode* cursor;
};

CircleList::CircleList() : cursor(NULL) {}
CircleList::~CircleList()
{
    while (!empty())
        remove();
}

bool CircleList::empty() const
{
    return (cursor == NULL);
}

const Elem& CircleList::front() const
{
    return cursor->next->elem;
}

const Elem& CircleList::rear() const
{
    return cursor->elem;
}

void CircleList::advance()
{
    cursor = cursor->next;
}

void CircleList::add(const Elem& e)
{
    CNode* pNode = new CNode;
    pNode->elem = e;
    pNode->next = cursor->next;
    cursor->next = pNode;
}

void CircleList::remove()
{
    if (cursor)
    {
        if (cursor->next)
        {
            cursor->next = cursor->next->next;
            delete cursor->next;
        }
    }
}