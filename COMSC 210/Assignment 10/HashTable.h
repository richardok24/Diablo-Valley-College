// Programmer: Richard Xie
// Programmer's ID: 1435650

#ifndef HashTable_h
#define HashTable_h

#include <queue>
#include <list>
using namespace std;

template <typename K, typename V, int CAP>
class HashTable
{
  struct Node
  {
    K key;
    V value;
  };

  list<Node> data[CAP];
  int(*hashCode)(const K&);
  int siz; // tracking the number of nodes
  V dummy;

public:
  HashTable(int(*h)(const K&)=0){hashCode = h;}
  V operator[ ](const K&) const; // The Square Bracket Operator Getter
  V& operator[ ](const K&); // The Square Bracket Operator Setter
  bool containsKey(const K&) const; // containsKey Getter
  void deleteKey(const K&); // deleteKey Setter
  double loadFactor() const {return 1.0 * siz / CAP;}
  bool empty() const;
  int size() const {return siz;}
  void clear();
  queue<K> keys() const; // The keys Getter
};

template <typename K, typename V, int CAP>
V HashTable<K,V,CAP>::operator[ ](const K& key) const
{
  int index = hashCode(key) % CAP;
  if (index < 0) index += CAP;
  typename list<Node>::const_iterator it;
  for (it = data[index].begin(); it != data[index].end(); it++)
   if (it->key == key)
     break;
  if (it == data[index].end()) // not found
    return dummy;
  if (it != data[index].end()) // found
    return it->value;
}

template <typename K, typename V, int CAP>
V& HashTable<K,V,CAP>::operator[ ](const K& key)
{
  int index = hashCode(key) % CAP;
  if (index < 0) index += CAP;
  typename list<Node>::iterator it;
  for (it = data[index].begin(); it != data[index].end(); it++)
   if (it->key == key)
     break;
  if (it == data[index].end()) // not found
  {
    ++siz;
    Node n; n.key = key; // a temporary Node...
    data[index].push_back(n); // ...copied to a more permanent location
    return data[index].back().value; // the V value attribute of the added Node
  }
  if (it != data[index].end()) // found
    return it->value;
}

template <typename K, typename V, int CAP>
bool HashTable<K,V,CAP>::containsKey(const K& key) const
{
  int index = hashCode(key) % CAP;
  if (index < 0) index += CAP;
  typename list<Node>::const_iterator it;
  for (it = data[index].begin(); it != data[index].end(); it++)
   if (it->key == key)
     break;
  if (it == data[index].end()) // not found
    return false;
  if (it != data[index].end()) // found
    return true;
}

template <typename K, typename V, int CAP>
void HashTable<K,V,CAP>::deleteKey(const K& key)
{
  int index = hashCode(key) % CAP;
  if (index < 0) index += CAP;
  typename list<Node>::iterator it;
  for (it = data[index].begin(); it != data[index].end(); it++)
   if (it->key == key)
     break;
  if (it != data[index].end()) // found
  {
    --siz;
    data[index].erase(it); // removes the key-value pair
  }
}

template <typename K, typename V, int CAP>
bool HashTable<K,V,CAP>::empty() const
{
  if (0 == siz)
    return true;
  else
    return false;
}

template <typename K, typename V, int CAP>
void HashTable<K,V,CAP>::clear()
{
  siz = 0;
  for (int i = 0; i < CAP; i++)
    data[i].clear();
}

template <typename K, typename V, int CAP>
queue<K> HashTable<K,V,CAP>::keys() const
{
  queue<K> k;

  typename list<Node>::const_iterator it;
  for (int i = 0; i < CAP; i++)
    for (it = data[i].begin(); it != data[i].end(); it++)
      k.push(it->key);

  return k;
}

#endif

