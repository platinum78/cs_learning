#include <string>

typedef std::string Elem;

class DNode
{
  private:
    Elem elem;
    DNode *prev;
    DNode *next;
    friend class DLinkedList;
};

class DLinkedList
{
  public:
    DLinkedList();
    ~DLinkedList();
    bool empty() const;
    const Elem &front() const;
    const Elem &rear() const;
    void addFront(const Elem &e);
    void addRear(const Elem &e);
    void removeFront();
    void removeRear();

  private:
    DNode *header;
    DNode *trailer;

  protected:
    void add(DNode *v, const Elem &e);
    void remove(DNode *v);
}

DLinkedList::DLinkedList()
{
    header = new DNode;
    trailer = new DNode;
    header->next = trailer;
    trailer->prev = header;
}

DLinkedList::~DLinkedList()
{
    while (!empty())
        removeFront();
    delete header;
    delete trailer;
}

bool DLinkedList::empty() const
{
    
}