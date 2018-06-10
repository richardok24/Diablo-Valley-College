// Programmer: Richard Xie
// Programmer's ID: 1435650

#define _CRT_SECURE_NO_WARNINGS

#include <fstream>
#include <iostream> // for cout, ios, and endl
#include <string> // for string
using namespace std;

#include <cstring> // for strtok and strcpy
//#include <cassert> // for assert
#include <cmath> // for log and pow
#include <cstdlib> // for srand and rand
#include <ctime> // for clock(), clock_t, time, and CLOCKS_PER_SEC

// your H file #include(s) go here, plus any more library includes

int main()
{
  // programmer's identification
  cout << "Programmer: Richard Xie";
  cout << "Programmer's ID: 1435650\n";
  cout << "File: " << __FILE__ << endl << endl;

  // srand(time(0)); rand(); // seed the random number generator (in case you need it)

  // programmer customizations go here
  int n = 8000; // THE STARTING PROBLEM SIZE (MAX 250 MILLION)
  string bigOh = "O(n)"; // YOUR PREDICTION: O(n), O(n log n), or O(n squared)

  cout.setf(ios::fixed);
  cout.precision(4);
  double elapsedSecondsNorm = 0;
  double expectedSeconds = 0;
  for (int cycle = 0; cycle < 4; cycle++, n*= 2)
  {
    // problem setup goes here -- create a data structure of size n
    int count = 0;
    // for parsing the inputfile
    char* token;
    char buf[1000];
    const char* const tab = "\t";

    // assert that n is the size of the data structure if applicable
    //assert(a.size() == n); // or something like that...

    // start the timer, do something, and stop the timer
    clock_t startTime = clock();
    // do something where n is the "size" of the problem
    for (int reps = 0; reps < 10; reps++)
    {
      // open the input file
      ifstream fin;
      fin.open("dvc-schedule.txt");
      if (!fin.good()) throw "I/O error";

      // read the input file
      while (fin.good())
      {
        count++;
        if (count >= n) break;

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
      }
      fin.close();
      count = 0;
    }
    clock_t endTime = clock();

    // validation block -- assure that process worked if applicable

    // cleanup if applicable

    // compute timing results
    double elapsedSeconds = (double)(endTime - startTime) / CLOCKS_PER_SEC;
    double factor = pow(2.0, double(cycle));
    if (cycle == 0)
      elapsedSecondsNorm = elapsedSeconds;
    else if (bigOh == "O(n)")
      expectedSeconds = factor * elapsedSecondsNorm;
    else if (bigOh == "O(n log n)")
      expectedSeconds = factor * log(double(n)) / log(n / factor) * elapsedSecondsNorm;
    else if (bigOh == "O(n squared)")
      expectedSeconds = factor * factor * elapsedSecondsNorm;

    // reporting block
    cout << elapsedSeconds;
    if (cycle == 0) cout << " (expected " << bigOh << ')';
    else cout << " (expected " << expectedSeconds << ')';
    cout << " for n=" << n << endl;
  }
}
