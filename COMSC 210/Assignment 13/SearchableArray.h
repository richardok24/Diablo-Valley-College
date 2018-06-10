// Programmer: Richard Xie
// Programmer's ID: 1435650

#ifndef SearchableArray_h
#define SearchableArray_h

#include <algorithm>
using namespace std;

template <typename V>
class SearchableArray
{
  V* values;
  int cap;
  V dummy;

public:
  SearchableArray(int=2); // constructor
  ~SearchableArray(){delete [ ] values;} // destructor
  SearchableArray(const SearchableArray<V>&); // copy constructor
  SearchableArray<V>& operator=(const SearchableArray<V>&); // assignment operator
  int capacity() const {return cap;} // a getter to return the data structure's now-variable capacity
  void capacity(int); // a setter to change the capacity
  void sort(int); // a setter to sort the array
  int bsearch(int, const V&) const; // a setter to search the array
  V operator[](int) const; // square bracket getter
  V& operator[](int); // square bracket setter
};

template <typename V>
SearchableArray<V>::SearchableArray(int cap)
{
  this->cap = cap;
  values = new V[cap];
}

template <typename V>
SearchableArray<V>::SearchableArray(const SearchableArray<V>& original)
{
  cap = original.cap;
  values = new V[cap];
  for (int i = 0; i < cap; i++)
    values[i] = original.values[i];
}

template <typename V>
SearchableArray<V>& SearchableArray<V>::operator=(const SearchableArray<V>& original)
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
void SearchableArray<V>::capacity(int cap)
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
void SearchableArray<V>::sort(int n)
{
  // create a dynamic array of size n as a working space, named "temp"
  V* temp = new V[n];
  // create an integer to track the size of the sub-arrays in each iteration -- set to 1
  int siz = 1;
  // start a loop
  while (true)
  {
    // if the sub-array size for this iteration is greater than n, break -- nothing more to do!
    if (siz > n) break;
    // declare and set an "index" to 0 -- the next position in the array to fill
    int index = 0;
    // copy the array into the working space -- the whole thing!
    for (int i = 0; i < n; i++) temp[i] = values[i];
    // start a loop to visit each adjacent pair of sub-arrays, with a counter i=0
    for (int i = 0; i < n; i)
    {
      // create these integers to track the lead and end values of the two sub-arrays being merged:
      int left = i;
      int leftMax = min(n, left + siz);
      int right = leftMax;
      int rightMax = min(n, right + siz);
      // start another loop to run as long as left < leftMax OR right < rightMax
      while (left < leftMax || right < rightMax)
      {
        if (left == leftMax) values[index++] = temp[right++];
        else if (right == rightMax) values[index++] = temp[left++];
        else if (temp[right] < temp[left]) values[index++] = temp[right++];
        else values[index++] = temp[left++];
      }
      // add two sub-array sizes to i for the next cycle of the inner loop
      i += 2 * siz;
    }
    // double the sub-array size for the next iteration
    siz *= 2;
  }
  // deallocate the working space array
  delete [] temp;
}

template <typename V>
int SearchableArray<V>::bsearch(int n, const V& value) const
{
  int s = 0; // start of a range of the array to search
  int e = n; // end of a range of the array to search
  int m = 0; // the matching value's index

  while (m != n) // "n" means no match was found
  {
     m = (s + e - 1) / 2; // the middle element
     if (value == values[m]) break; // got lucky -- matches middle element
     else if (s >= e - 1) m = n; // 1-element array and it did not match
     else if (value < values[m]) e = m; // look between s and m-1
     else s = m + 1; // look between m+1 and e-1
  }

  if (m == n)
    return -1;

  else
    return m;
}

template <typename V>
V SearchableArray<V>::operator[](int index) const
{
  if (index < 0 || index >= capacity()) return dummy;
  return values[index];
}

template <typename V>
V& SearchableArray<V>::operator[](int index)
{
  if (index < 0) return dummy;
  if (index >= capacity()) capacity(2 * index);
  return values[index];
}

#endif

