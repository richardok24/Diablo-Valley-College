// Programmer: Richard Xie
// Programmer's ID: 1435650

#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

#include <cstdlib>

#include "Stack.h"

int main()
{
  // programmer's identification
  cout << "Programmer: Richard Xie";
  cout << "Programmer's ID: 1435650\n";
  cout << "File: " << __FILE__ << endl << endl;

  Stack <double> s;
  string buf;
  double x;

  while (true)
  {
    cout << "Enter: ";

    for (Stack<double> copy = s; !copy.empty(); copy.pop(x))
    {
      copy.peek(x);
      cout << x << " ";
    }

    cin >> buf;
    cin.ignore(1000, 10);

    // check for signs and size
    if (buf == "+")
    {
      if (s.size() >= 2)
      {
        s.peek(x);
        double a = x;
        s.pop(x);
        s.peek(x);
        double b = x;
        s.pop(x);
        float c = a + b;
        cout << setprecision(6) << fixed;
        s.push(c);
      }
    }
    else if (buf == "-")
    {
      if (s.size() >= 2)
      {
        s.peek(x);
        double a = x;
        s.pop(x);
        s.peek(x);
        double b = x;
        s.pop(x);
        float c = b - a;
        cout << setprecision(6) << fixed;
        s.push(c);
      }
    }
    else if (buf == "/")
    {
      if (s.size() >= 2)
      {
        s.peek(x);
        double a = x;
        s.pop(x);
        s.peek(x);
        double b = x;
        s.pop(x);
        float c = b / a;
        cout << setprecision(6) << fixed;
        s.push(c);
      }
    }
    else if (buf == "*")
    {
      if (s.size() >= 2)
      {
        s.peek(x);
        double a = x;
        s.pop(x);
        s.peek(x);
        double b = x;
        s.pop(x);
        float c = a * b;
        cout << setprecision(6) << fixed;
        s.push(c);
      }
    }
    else if (buf == "Q" || buf == "q")
      break;
    else
    {
      double d = atof(buf.c_str());
      s.push(d);
    }
  }
}
