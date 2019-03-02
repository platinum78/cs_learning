/*
 * Array Vector Implementaton
 */

#include <iostream>
#include <string>

typedef std::string Elem;

class ArrayVector
{
  public:
    ArrayVector();
    int size() const;
    bool empty() const;
    Elem &operator[](int i);
    Elem &at(int i);
    void erase(int i);
    void insert(int i, const Elem &e);
    void reserve(int N);

  private:
    int capacity;
    int n;
    Elem *A;
};

ArrayVector::ArrayVector() : capacity(0), n(0), A(NULL) {}

int ArrayVector::size() const
{
    return n;
}

bool ArrayVector::empty() const
{
    return n == 0;
}

Elem& ArrayVector::operator[](int i)
{
    return at(i);
}

Elem& ArrayVector::at(int i)
{
    return A[i];
}

void ArrayVector::erase(int i)
{
    for (int j = i; j < n; j++)
        A[j] = A[j + 1];
}

void ArrayVector::insert(int i, const Elem& e)
{
    for (int j = n - 1; j > i; j--)
        A[j] = A[j - 1];
    A[i] = e;
}

void ArrayVector::reserve(int N)
{
    A = new Elem[N];
}
ß