// Programmer: Richard Xie
// Programmer's ID: 1435650

#ifndef Stack_h
#define Stack_h

template <typename V>
class Stack
{
  struct Node
  {
    V value;
    Node* next;
  };

  Node* firstNode; // the head pointer
  int siz; // tracking the number of nodes

public:
  Stack();
  void push(const V&);
  bool peek(V&) const;
  bool pop(V&);
  bool empty() const {return 0 == siz;}
  int size() const {return siz;}
  void clear();
  Stack(const Stack<V>&);
  Stack<V>& operator=(const Stack<V>&);
  ~Stack();
};

template <typename V>
Stack<V>::Stack()
{
  firstNode = 0;
  siz = 0;
}

template <typename V>
void Stack<V>::push(const V& parameter)
{
  Node* node = new Node;
  node->value = parameter;
  node->next = firstNode;
  firstNode = node;
  ++siz;
}

template <typename V>
bool Stack<V>::peek(V& parameter) const
{
  if (0 == siz) return false;
  parameter = firstNode->value;
  return true;
}

template <typename V>
bool Stack<V>::pop(V& parameter)
{
  if (0 == siz) return false;
  parameter = firstNode->value;
  if (firstNode)
  {
    Node* p = firstNode;
    firstNode = firstNode->next;
    delete p;
    --siz;
  }
  return true;
}

template <typename V>
void Stack<V>::clear()
{
  while (firstNode)
  {
    Node* p = firstNode;
    firstNode = firstNode->next;
    delete p;
    --siz;
  }
}

template <typename V>
Stack<V>::Stack(const Stack<V>& original)
{
  firstNode = 0;
  Node* lastNode = 0; // temporary tail
  siz = original.siz;
  for (Node* p = original.firstNode; p; p = p->next)
  {
    Node* temp = new Node;
    temp->value = p->value;
    temp->next = 0;
    if (lastNode) lastNode->next = temp;
    else firstNode = temp;
    lastNode = temp;
  }
}

template <typename V>
Stack<V>& Stack<V>::operator=(const Stack<V>& original)
{
  if (this != &original)
  {
    // deallocate existing list
    while (firstNode)
    {
      Node* p = firstNode->next;
      delete firstNode;
      firstNode = p;
    }

    // build new queue
    Node* lastNode = 0; // temporary tail
    for (Node* p = original.firstNode; p; p = p->next)
    {
      Node* temp = new Node;
      temp->value = p->value;
      temp->next = 0;
      if (lastNode) lastNode->next = temp;
      else firstNode = temp;
      lastNode = temp;
    }
    siz = original.siz;
  }
  return *this;
}

template <typename V>
Stack<V>::~Stack()
{
  while (firstNode)
  {
    Node* p = firstNode;
    firstNode = firstNode->next;
    delete p;
  }
}

#endif
