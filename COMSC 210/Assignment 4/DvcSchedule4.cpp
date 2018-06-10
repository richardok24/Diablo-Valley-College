// Programmer: Richard Xie
// Programmer's ID: 1435650

#define _CRT_SECURE_NO_WARNINGS

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

#include <cstring> // for strtok and strcpy

#include "DynamicArray.h"

struct Class
{
  string subjectCode;
  int count;
};

int main()
{
  // programmer's identification
  cout << "Programmer: Richard Xie";
  cout << "Programmer's ID: 1435650\n";
  cout << "File: " << __FILE__ << endl << endl;

  DynamicArray <Class> sub;
  DynamicArray <string> sem;
  DynamicArray <string> sec;

  int n = 0;
  int dup = 0;
  int counter = 0;
  bool duplicate;
  bool stored;

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
    stored = false;

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
    for(int i = 0; i < counter; i++)
    {
      if(sem[i] == term && sec[i] == section)
      {
        dup++;
        duplicate = true;
        break;
      }
    }

    if(duplicate == true)
      continue;

    sem[counter] = term;
    sec[counter] = section;
    counter++;

    // check for same section
    for(int i = 0; i < n; i++)
    {
      if (sub[i].subjectCode == subjectCode)
      {
        sub[i].count++;
        stored = true;
        break;
      }
    }

    if(stored == true)
      continue;

    Class y;
    y.subjectCode = subjectCode;
    y.count = 1;
    sub[n] = y;
    n++;
  }
  fin.close();
  cout << endl;

  // sort
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      if (sub[j].subjectCode < sub[i].subjectCode)
        swap(sub[j], sub[i]);

  // output
  for(int i = 0; i < n; i++)
  {
    cout << sub[i].subjectCode << ", " << sub[i].count << " sections" << endl;
  }

  cout << "\nNumber of duplicates: " << dup << endl;
}
