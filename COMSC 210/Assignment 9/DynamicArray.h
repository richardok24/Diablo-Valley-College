// Programmer: Richard Xie
// Programmer's ID: 1435650

#ifndef DynamicArray_h
#define DynamicArray_h

#include <algorithm>
using namespace std;

template <typename V>
class DynamicArray
{
  V* values;
  int cap;
  V dummy;

public:
  DynamicArray(int=2); // constructor
  ~DynamicArray(){delete [ ] values;} // destructor
  DynamicArray(const DynamicArray<V>&); // copy constructor
  DynamicArray<V>& operator=(const DynamicArray<V>&); // assignment operator
  int capacity() const {return cap;} // a getter to return the data structure's now-variable capacity
  void capacity(int); // a setter to change the capacity
  V operator[](int) const; // square bracket getter
  V& operator[](int); // square bracket setter
};

template <typename V>
DynamicArray<V>::DynamicArray(int cap)
{
  this->cap = cap;
  values = new V[cap];
}

template <typename V>
DynamicArray<V>::DynamicArray(const DynamicArray<V>& original)
{
  cap = original.cap;
  values = new V[cap];
  for (int i = 0; i < cap; i++)
    values[i] = original.values[i];
}

template <typename V>
DynamicArray<V>& DynamicArray<V>::operator=(const DynamicArray<V>& original)
{
  if (this != &original)
  {
    delete [ ] values;
    cap = original.cap;
    values = new V[cap];
    for (int i = 0; i < cap; i++)
      values[i] = original.values[i];
  }
  return *this;
}

template <typename V>
void DynamicArray<V>::capacity(int cap)
{
  V* temp = new V[cap];
  int limit = min(cap, this->cap);
  for (int i = 0; i < limit; i++)
    temp[i] = values[i];
  delete [ ] values;
  values = temp;
  this->cap = cap;
}

template <typename V>
V DynamicArray<V>::operator[](int index) const
{
  if (index < 0 || index >= capacity()) return dummy;
  return values[index];
}

template <typename V>
V& DynamicArray<V>::operator[](int index)
{
  if (index < 0) return dummy;
  if (index >= capacity()) capacity(2 * index);
  return values[index];
}

#endif
