// Programmer: Richard Xie
// Programmer's ID: 1435650

#include <iostream>
using namespace std;

#include <cassert>

#include "Queue.h"
#include "Queue.h" // ifndef test

int main()
{
  // programmer's identification
  cout << "Programmer: Richard Xie";
  cout << "Programmer's ID: 1435650\n";
  cout << "File: " << __FILE__ << endl << endl;

  Queue<int> a;

  cout << "Checking size, the expected size is 0" << endl;
  cout << "The actual size is " << a.size() << endl;
  assert(a.size() == 0);

  cout << "\nChecking empty, expecting the queue to be empty" << endl;
  if (a.empty())
    cout << "It is empty" << endl;
  else
    cout << "It is not empty" << endl;
  assert(a.empty());

  cout << "\nNow push 5 values to the queue" << endl;
  a.push(1);
  a.push(2);
  a.push(3);
  a.push(4);
  a.push(5);

  cout << "\nChecking front(), expecting 1" << endl;
  cout << "Actual: " << a.front() << endl;;
  assert(a.front()== 1);

  cout << "\nChecking back(), expecting 5" << endl;
  cout << "Actual: " << a.back() << endl;;
  assert(a.back()== 5);

  cout << "\nChecking pop(), expecting front() to be 2 and back() to be 5 after pop()" << endl;
  a.pop();
  cout << "Actual(front()): " << a.front() << endl;
  cout << "Actual(back()): " << a.back() << endl;
  assert(a.front()== 2);
  assert(a.back()== 5);

  cout << "\nCheck size again, the expected size is 4, the actual size is " << a.size() << endl;
  assert(a.size() == 4);
  cout << "\nChecking empty again, expecting the queue to be not empty" << endl;
  if (a.empty())
    cout << "It is empty" << endl;
  else
    cout << "It is not empty" << endl;
  assert(!(a.empty()));

  cout << "\nObject Copy Testing" << endl;
  const Queue<int> copy1 = a;

  cout << "\nCheck if their sizes match, expect them to be matched" << endl;
  if (a.size() == copy1.size())
    cout << "Their sizes match" << endl;
  else
    cout << "Their sizes do not match" << endl;
  assert(a.size() == copy1.size());

  cout << "\nObject Assignment Testing" << endl;
  Queue<int> copy2; copy2 = a;

  cout << "\nCheck if their sizes match, expect them to be matched" << endl;
  if (a.size() == copy2.size())
    cout << "Their sizes match" << endl;
  else
    cout << "Their sizes do not match" << endl;
  assert(a.size() == copy2.size());

   cout << "\nCheck if front() match, expect them to be matched" << endl;
  if (a.front() == copy2.front())
    cout << "front() match" << endl;
  else
    cout << "front() do not match" << endl;
  assert(a.front() == copy2.front());

  cout << "\nCheck if back() match, expect them to be matched" << endl;
  if (a.back() == copy2.back())
    cout << "back() match" << endl;
  else
    cout << "back() do not match" << endl;
  assert(a.back() == copy2.back());

  cout << "\nTesting clear" << endl;
  a.clear();

  cout << "\nCheck size again, the expected size is 0" << endl;
  cout << "The actual size is " << a.size() << endl;
  assert(a.size() == 0);
}
