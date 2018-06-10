// Programmer: Richard Xie
// Programmer's ID: 1435650

#include <iostream>
using namespace std;

#include <cstdlib>

class Array
{
  int values[100];
  int dummy;

public:
  int capacity() const {return 100;} // a getter to return the data structure's capacity
  int operator[](int) const; // Array::operator[ ] getter
  int& operator[](int); // Array::operator[ ] setter
};

int main()
{
  // programmer's identification
  cout << "Programmer: Richard Xie";
  cout << "Programmer's ID: 1435650\n";
  cout << "File: " << __FILE__ << endl << endl;

  Array a;
  Array b;
  int index;

  for(int index = 0; index < b.capacity(); index++)
    b[index] = 0;

  while(true)
  {
    string buf;
    cout << "Input an index and a value [Q to quit]: ";
    cin >> buf;
    if (buf == "Q" || buf == "q")break;
    index = atoi(buf.c_str());
    cin >> buf;
    if (buf == "Q" || buf == "q")break;
    a[index] = atoi(buf.c_str());
    b[index] = 9999;
  }

  int storedValues = 0;
  for(int index = 0; index < b.capacity(); index++)
  {
    if(b[index] == 9999)
      storedValues ++;
  }

  cout << "\nYou stored this many values : " << storedValues << endl;
  cout << "\nThe index-value pairs are:\n\n";

  for(int index = 0; index < b.capacity(); index++)
  {
    if(b[index] == 9999)
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
    if(b[index] == 9999 && index > 0 && index <= 100)
      cout << "Found it -- the value stored at " << index << " is " << a[index] << endl;
    else
      cout << "I didn't find it" << endl;
  }
}

int Array::operator[](int index) const
{
  if (index < 0 || index >= capacity()) return dummy;
  return values[index];
}

int& Array::operator[](int index)
{
  if (index < 0 || index >= capacity()) return dummy;
  return values[index];
}
