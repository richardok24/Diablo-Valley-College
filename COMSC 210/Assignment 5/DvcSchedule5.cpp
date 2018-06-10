// Programmer: Richard Xie
// Programmer's ID: 1435650

#define _CRT_SECURE_NO_WARNINGS

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

#include <cstring> // for strtok and strcpy

#include "DynamicArray.h"

struct SectionsForTerm
{
  string term;
  int numberOfSectionsSeen; // to track where we are in the following "array"
  DynamicArray<string> seenSectionNumbers; // or int instead of string
};

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

  int numberOfTermsSeen = 0; // to track where we are in the following "array"
  DynamicArray<SectionsForTerm> alreadySeen;
  DynamicArray <Class> sub;

  int n = 0;
  int dup = 0;
  int counter = 0;
  bool match;
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
    match = false;
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
    int i;
    for(i = 0; i < numberOfTermsSeen; i++)
    {
      if(alreadySeen[i].term == term)
      {
        match = true;
        break;
      }
    }

    if(match == true)
    {
      for(int j = 0; j < alreadySeen[i].numberOfSectionsSeen; j++)
        if (alreadySeen[i].seenSectionNumbers[j]== section)
        {
          duplicate = true;
          dup++;
          break;
        }

        if (duplicate == true)
          continue;

        else
        {
          alreadySeen[i].seenSectionNumbers[alreadySeen[i].numberOfSectionsSeen]= section;
          alreadySeen[i].numberOfSectionsSeen++;
        }
    }

    else
    {
      alreadySeen[numberOfTermsSeen].term = term;
      alreadySeen[i].numberOfSectionsSeen = 1;
      numberOfTermsSeen++;
    }

    // check for same section
    for(i = 0; i < n; i++)
    {
      if(sub[i].subjectCode == subjectCode)
      {
        stored = true;
        break;
      }
    }

    if(stored == true)
    {
      sub[i].count++;
    }

    else
    {
      sub[n].subjectCode = subjectCode;
      sub[n].count = 1;
      n++;
    }

    counter++;
  }
  fin.close();
  cout << endl;

  // sort
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      if (sub[j].subjectCode < sub[i].subjectCode)
        swap(sub[i], sub[j]);

  // output
  for(int i = 0; i < n; i++)
  {
    cout << sub[i].subjectCode << ", " << sub[i].count << " sections" << endl;
  }

  cout << "\nNumber of duplicates: " << dup << endl;
}
