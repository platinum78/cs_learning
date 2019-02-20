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
};

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
    return (header->next == trailer);
}

const Elem& DLinkedList::front() const
{
	return header->next->elem;
}

const Elem& DLinkedList::rear() const
{
	return trailer->prev->elem;
}

void DLinkedList::add(DNode* v, const Elem& e)
{
	DNode *pNode = new DNode;
	pNode->elem = e;
	pNode->next = v;
	pNode->prev = v->prev;
	pNode->prev->next = pNode;
	pNode->next->prev = pNode;
}

void DLinkedList::addFront(const Elem& e)
{
	add(header->next, e);
}

void DLinkedList::addRear(const Elem& e)
{
	add(trailer, e);
}

void DLinkedList::remove(DNode* pNode)
{
	pNode->prev->next = pNode->next;
	pNode->next->prev = pNode->prev;
	delete pNode;
}

void DLinkedList::removeFront()
{
	remove(header->next);
}

void DLinkedList::removeRear()
{
	remove(trailer->prev);
}