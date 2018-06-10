// Programmer: Richard Xie
// Programmer's ID: 1435650

#include <iostream>
using namespace std;

#include <cstdlib>

#include "DynamicArray.h"

int main()
{
  // programmer's identification
  cout << "Programmer: Richard Xie";
  cout << "Programmer's ID: 1435650\n";
  cout << "File: " << __FILE__ << endl << endl;

  DynamicArray<double> a(100);
  DynamicArray<bool> b(100);
  int index;

  for(int index = 0; index < b.capacity(); index++)
    b[index] = false;

  if(index >= b.capacity())
      b.capacity(index);

  while(true)
  {
    string buf;
    cout << "Input an index and a value [Q to quit]: ";
    cin >> buf;
    if (buf == "Q" || buf == "q")break;
    index = atoi(buf.c_str());
    cin >> buf;
    if (buf == "Q" || buf == "q")break;
    a[index] = atof(buf.c_str());
    b[index] = true;
  }

  int storedValues = 0;
  for(int index = 0; index < b.capacity(); index++)
  {
    if(b[index])
      storedValues ++;
  }

  cout << "\nYou stored this many values : " << storedValues << endl;
  cout << "\nThe index-value pairs are:\n\n";

  for(int index = 0; index < b.capacity(); index++)
  {
    if(b[index])
      cout << index << " " << a[index] << endl;
  }

  while (true)
  {
    string buf;
    cout << "\nInput an index for me to look up [Q to quit]: ";
    cin >> buf;
    cin.ignore(1000,10);
    if (buf == "Q" || buf == "q") break;
    index = atoi(buf.c_str());
    if(b[index] && index >= 0)
      cout << "Found it -- the value stored at " << index << " is " << a[index] << endl;
    else
      cout << "I didn't find it" << endl;
  }
}
