// Programmer: Richard Xie
// Programmer's ID: 1435650

#ifndef StaticArray_h
#define StaticArray_h

template <typename V, int CAP>
class StaticArray
{
  V values[CAP];
  V dummy;

public:
  int capacity() const {return CAP;} // a getter to return the data structure's capacity
  V operator[](int) const; // Array::operator[ ] getter
  V& operator[](int); // Array::operator[ ] setter
};

template <typename V, int CAP>
V StaticArray<V, CAP>::operator[](int index) const
{
  if (index < 0 || index >= capacity()) return dummy;
  return values[index];
}

template <typename V, int CAP>
V& StaticArray<V, CAP>::operator[](int index)
{
  if (index < 0 || index >= capacity()) return dummy;
  return values[index];
}

#endif
