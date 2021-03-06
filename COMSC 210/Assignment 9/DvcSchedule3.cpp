// Programmer: Richard Xie
// Programmer's ID: 1435650

#define _CRT_SECURE_NO_WARNINGS

#include <fstream>
#include <iostream>
#include <string>
#include <queue>
using namespace std;

#include <cstring> // for strtok and strcpy

#include "AssociativeArray.h"
#include "DynamicArray.h"

int main()
{
  // programmer's identification
  cout << "Programmer: Richard Xie";
  cout << "Programmer's ID: 1435650\n";
  cout << "File: " << __FILE__ << endl << endl;

  AssociativeArray<string, AssociativeArray<string, bool> > alreadySeen;
  AssociativeArray<string, AssociativeArray<string, int> > sub;
  DynamicArray<string> s;

  int n = 0;
  int dup = 0;
  int counter = 0;
  bool duplicate;

  // for parsing the inputfile
  char* token;
  char buf[1000];
  const char* const tab = "\t";

  // open the input file
  ifstream fin;
  fin.open("dvc-schedule.txt");
  if (!fin.good()) throw "I/O error";

  cout << "Sorting..."; cout.flush();

  // read the input file
  while (fin.good())
  {
    if(counter % 1000 == 0) cout << '.'; cout.flush();

    // set the check to false
    duplicate = false;

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
    if(alreadySeen[term].containsKey(section) == true)
    {
      duplicate = true;
      dup++;
    }

    if(duplicate == true)
      continue;

    else
    {
      alreadySeen[term][section] = true;
    }

    // counting
    if(sub[subjectCode].containsKey(course) == true)
    {
      sub[subjectCode][course]++;
    }

    if(sub[subjectCode].containsKey(course) == false)
    {
      sub[subjectCode][course] = 1;
    }

    if(sub.containsKey(subjectCode) == false)
    {
      sub[subjectCode][course] = 1;
    }

    counter++;
  }
  fin.close();
  cout << endl;

  // sort
  for(queue<string> a= sub.keys(); !a.empty(); a.pop())
  {
    s[n] = a.front();
    n++;
  }

  for (int i = 0; i < sub.size(); i++)
    for (int j = i + 1; j < sub.size(); j++)
      if (s[j] < s[i])
        swap(s[i], s[j]);

  // output
  for (int i = 0; i < sub.size(); i++)
  {
    cout << s[i] << ", " << sub[s[i]].size() << "course(s)" << endl;
    for (queue<string> b = sub[s[i]].keys(); !b.empty(); b.pop())
      cout << "  " << b.front() << ", " << sub[s[i]][b.front()] << "sections" << endl;
  }

  cout << "\nNumber of duplicates: " << dup << endl;
}
