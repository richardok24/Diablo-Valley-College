// Programmer: Richard Xie
// Programmer's ID: 1435650

#include <iostream> // for cout, ios, and endl
#include <string> // for string
using namespace std;

#include <cassert> // for assert
#include <cmath> // for log and pow
#include <cstdlib> // for srand and rand
#include <ctime> // for clock(), clock_t, time, and CLOCKS_PER_SEC

#include "PriorityQueue.h" // your H file #include(s) go here, plus any more library includes

int main()
{
  // programmer's identification
  cout << "Programmer: Richard Xie";
  cout << "Programmer's ID: 1435650\n";
  cout << "File: " << __FILE__ << endl << endl;

  srand(time(0)); rand(); // seed the random number generator (in case you need it)

  // programmer customization go here
  int n = 3000000; // THE STARTING PROBLEM SIZE (MAX 250 MILLION)
  const int reps = n / 100; // one percent of starting n

  cout.setf(ios::fixed);
  cout.precision(4);
  double expectedSeconds = 0;
  double elapsedSecondsNorm = 0;
  for (int cycle = 0; cycle < 4; cycle++, n*= 2)
  {
    // problem setup goes here -- create a data structure of size n
    PriorityQueue<int> pq (n + reps);
    for (int i = 0; i < n; i++) pq.push(rand());

    // assert that n is the size of the data structure if applicable
    assert(pq.size() == n);

    // start the timer, do something, and stop the timer
    clock_t startTime = clock();
    for (int rep = 0; rep < reps; rep++)
    {
      // do something where n is the "size" of the problem
      pq.pop();
    }
    clock_t endTime = clock();

    // validation block -- assure that process worked if applicable
    assert(pq.size() == n - reps);
    int last = pq.top(); pq.pop();
    while (!pq.empty())
    {
      assert(last >= pq.top());
      last = pq.top();
      pq.pop();
    }

    // compute timing results
    double elapsedSeconds = (double)(endTime - startTime) / CLOCKS_PER_SEC;
    double factor = pow(2.0, double(cycle));
    if (cycle == 0) elapsedSecondsNorm = elapsedSeconds;
    double expectedSecondsLog = log(double(n)) / log(n / factor) * elapsedSecondsNorm;

    // reporting block
    cout << elapsedSeconds;
    if (cycle == 0) cout << " (expected)";
    else cout << " (expected " << elapsedSecondsNorm << " to " << expectedSecondsLog << ')';
    cout << " for n=" << n << endl;
  }
}
