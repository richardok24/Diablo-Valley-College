// Programmer: Richard Xie
// Programmer's ID: 1435650

#ifndef PriorityQueue_h
#define PriorityQueue_h

template <typename V>
class PriorityQueue
{
  V* values;
  int siz;
  int cap;
  void capacity(int);

public:
  PriorityQueue(int=2);
  V& top() const {return values[0];}
  void push(const V&);
  void pop();
  bool empty() const;
  int size() const {return siz;}
  void clear() {siz = 0;}
  PriorityQueue(const PriorityQueue<V>&); // copy constructor
  PriorityQueue<V>& operator=(const PriorityQueue<V>&); // assignment operator
  ~PriorityQueue(){delete [ ] values;} // destructor
};

template <typename V>
void PriorityQueue<V>::capacity(int cap)
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
PriorityQueue<V>::PriorityQueue(int cap)
{
  siz = 0;
  this->cap = cap;
  values = new V[cap];
}

template <typename V>
void PriorityQueue<V>::push(const V& parameter)
{
  if (cap == siz) capacity(2 * cap);
  values[siz] = parameter;
  int index = siz;
  int pIndex = (index + 1)/2 - 1;
  while (0 <= pIndex)
  {
    if (values[index] < values[pIndex]) break;
    swap (values[pIndex], values[index]); // promote and demote
    index = pIndex; // traverse up the hierarchy
    pIndex = (index + 1)/2 - 1;
  }
  ++siz;
}

template <typename V>
void PriorityQueue<V>::pop()
{
  int index = 0;
  int lIndex = 2 * index + 1;
  int rIndex = 2 * index + 2;

  while (lIndex < siz) // top down loop
  {
    if (lIndex == siz - 1 || values[rIndex] < values[lIndex])
    {
      values[index] = values[lIndex];
      index = lIndex;
    }

    else
    {
      values[index] = values[rIndex];
      index = rIndex;
    }

    lIndex = 2 * index + 1;
    rIndex = 2 * index + 2;
  }

  --siz;
  values[index] = values[siz];
  int pIndex = (index + 1)/2 - 1;

  while (0 <= pIndex) // bottom up loop
  {
    if (values[index] < values[pIndex]) break;
    swap (values[pIndex], values[index]);
    index = pIndex;
    pIndex = (index + 1)/2 - 1;
  }
}

template <typename V>
bool PriorityQueue<V>::empty() const
{
  if (0 == siz)
    return true;
  else
    return false;
}

template <typename V>
PriorityQueue<V>::PriorityQueue(const PriorityQueue<V>& original)
{
  siz = original.siz;
  cap = original.cap;
  values = new V[cap];
  for (int i = 0; i < cap; i++)
    values[i] = original.values[i];
}

template <typename V>
PriorityQueue<V>& PriorityQueue<V>::operator=(const PriorityQueue<V>& original)
{
  siz = original.siz;
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

#endif
