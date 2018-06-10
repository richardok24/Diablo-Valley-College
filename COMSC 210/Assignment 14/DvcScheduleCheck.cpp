// Programmer: Richard Xie
// Programmer's ID: 1435650

#define _CRT_SECURE_NO_WARNINGS

#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;

#include <cstring> // for strtok and strcpy

int main()
{
  // programmer's identification
  cout << "Programmer: Richard Xie";
  cout << "Programmer's ID: 1435650\n";
  cout << "File: " << __FILE__ << endl << endl;

  map<string, set<string> > c;
  map<string, set<string> >::iterator it1;
  set<string>::iterator it2;

  // for parsing the inputfile
  char* token;
  char buf[1000];
  const char* const tab = "\t";

  // open the input file
  ifstream fin;
  fin.open("dvc-schedule.txt");
  if (!fin.good()) throw "I/O error";

  // read the input file
  while (fin.good())
  {
    // read the line
    string line;
    getline(fin, line);
    strcpy(buf, line.c_str());
    if (buf[0] == 0) continue; // skip blank lines

    // parse the line
    const string term(token = strtok(buf, tab));
    const string section(token = strtok(0, tab));
    const string course((token = strtok(0, tab)) ? token : "");
    const string instructor((token = strtok(0, tab)) ? token : "");
    const string whenWhere((token = strtok(0, tab)) ? token : "");
    if (course.find('-') == string::npos) continue; // invalid line: no dash in course name
    const string subjectCode(course.begin(), course.begin() + course.find('-'));

    // check for duplicates
    string TS = term + " " + section;
    if (c.find(TS) == c.end())
      c[TS].insert(course);
    else if (c[TS].find(course) == c[TS].end())
      c[TS].insert(course);
  }
  fin.close();

  // output
  cout << "Entries with the same section and term, with different course names:\n" << endl;
  cout << "Term and Section:        Course:\n" << endl;
  for (it1 = c.begin(); it1 != c.end(); it1++)
  {
    if (it1->second.size() > 1)
    {
      cout << it1->first;
      cout << "           ";
      for (it2 = it1->second.begin(); it2 != it1->second.end(); it2++)
      {
        cout  << *it2 << "  ";
      }
      cout << endl;
      cout << endl;
    }
  }
}

