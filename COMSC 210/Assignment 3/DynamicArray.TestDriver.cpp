// Programmer: Richard Xie
// Programmer's ID: 1435650

#include <iostream>
using namespace std;

#include <cassert>

#include "DynamicArray.h"
#include "DynamicArray.h" // ifndef test

int main()
{
  // programmer's identification
  cout << "Programmer: Richard Xie";
  cout << "Programmer's ID: 1435650\n";
  cout << "File: " << __FILE__ << endl;

  DynamicArray<double> a(100);

  // testing capacity getter
  cout << "\nTesting capacity getter\n";
  cout << "EXPECTED: 100\n";
  cout << "RESULT: " << a.capacity() << endl;
  assert(100 == a.capacity());

  // testing square bracket setter
  cout << "\nTesting square bracket setter\n";
  a[40] = 99;
  a[80] = 999;
  cout << "EXPECTED: 99 for a[40]\n";
  cout << "RESULT: " << a[40] << endl;
  assert(99 == a[40]);
  cout << "EXPECTED: 999 for a[80]\n";
  cout << "RESULT: " << a[80] << endl;
  assert(999 == a[80]);
  a[-1] = 9999;
  cout << "EXPECTED: 9999 for a[-1]\n";
  cout << "RESULT: " << a[-1] << endl;
  assert(99 == a[40]);
  assert(999 == a[80]);
  assert(9999 != a[100]); // any out-of-range
  assert(9999 != a[99]); // checks upper end of range
  assert(9999 != a[0]); // checks lower end of range

  // testing copy constructor
  const DynamicArray<double> b = a;
  cout << "\nTesting copy constructor\n";
  cout << "EXPECTED: 99 for b[40]\n";
  cout << "RESULT: " << b[40] << endl;
  assert(99 == b[40]);
  cout << "EXPECTED: 999 for b[80]\n";
  cout << "RESULT: " << b[80] << endl;
  assert(999 == b[80]);
  assert(99 == b[40]);
  assert(999 == b[80]);
  assert(9999 != b[100]); // any out-of-range
  assert(9999 != b[99]); // checks upper end of range
  assert(9999 != b[0]); // checks lower end of range

  // const object copy test
  assert(a.capacity() == b.capacity());
  for (int i = 0; i < 100; i++)
    assert(a[i] == b[i]);

  // testing assignment operator
  DynamicArray<double> c;
  c = a;
  assert(a.capacity() == c.capacity());
  for (int i = 0; i < 10; i++)
    assert(a[i] == c[i]);
}
