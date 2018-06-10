// Programmer: Richard Xie
// Programmer's ID: 1435650

#define _CRT_SECURE_NO_WARNINGS

#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <utility>
using namespace std;

#include <cstring> // for strtok and strcpy

int main()
{
  // programmer's identification
  cout << "Programmer: Richard Xie";
  cout << "Programmer's ID: 1435650\n";
  cout << "File: " << __FILE__ << endl << endl;

  map<string, pair<string, string> >::iterator it;
  map<string, pair<string, string> > sub;

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
    const string s(term.substr(0, term.find(' ')));
    const string y(term.substr(s.size() + 1, term.find(' ')));

    // search
    it = sub.find(course);
    if (it != sub.end())
    {
      if (it->second.second < y)
      {
        pair<string, string> p(s, y);
        sub[course] = p;
        continue;
      }

      if (it->second.second == y)
      {
        if (it->second.first != "Fall" && s == "Summer" || s == "Fall")
        {
          pair<string, string> p(s, y);
          sub[course] = p;
          continue;
        }
      }
    }

    else
    {
      pair<string, string> p(s, y);
      sub[course] = p;
    }
  }
  fin.close();

  // output
  while (true)
  {
    string buf;
    cout << "\nInput a course to search (like COMSC-210 with uppercase letters) [X to exit]: " << endl;
    cin >> buf;
    cin.ignore(1000,10);
    if (buf == "X" || buf == "x") break;
    it = sub.find(buf);
    if (it != sub.end())
      cout << buf <<  " was last offered in " << it->second.first << " " << it->second.second << endl;
    else
      cout << buf <<  " could not be found as far back as the year 2000" << endl;
  }
}
