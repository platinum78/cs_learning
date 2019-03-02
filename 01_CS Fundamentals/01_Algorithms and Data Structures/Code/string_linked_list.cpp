#include <iostream>
#include <string>

// Implementation from the book
class StringNode
{
  private:
    std::string str;
    StringNode *next;

    friend class StringLinkedList;
};

// Implementation from the book
class StringLinkedList
{
  public:
    StringLinkedList();
    ~StringLinkedList();
    bool empty() const;
    const std::string &front() const;
    void addFront(const std::string &e);
    void removeFront();

  private:
    StringNode *head;
};

StringLinkedList::StringLinkedList() : head(NULL) {}

StringLinkedList::~StringLinkedList()
{
    while (!empty) removeFront();
}

bool StringLinkedList::empty() const
{
    return (head == NULL);
}

const std::string& StringLinkedList::front() const
{
    return head->str;
}

void StringLinkedList::addFront(const std::string& e)
{
    StringNode* pNode = new StringNode;
    pNode->str = e;
    pNode->next = head;
    head = pNode;
}

void StringLinkedList::removeFront()
{
    if (!head)
        return;
    StringNode* pDelNode = head;
    head = head->next;
    delete pDelNode;
}