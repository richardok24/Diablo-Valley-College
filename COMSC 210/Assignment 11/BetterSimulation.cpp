// Programmer: Richard Xie
// Programmer's ID: 1435650

#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
using namespace std;

#include <cstdlib>
#include <cmath>
#include <ctime>

#include "DynamicArray.h"
#include "Queue.h"
#include "PriorityQueue.h"

struct Customer
{
  char IDTag;
  int arrivalTime;
  int serviceEndTime;
};

struct ServiceEvent
{
  int server;
  int endOfServiceTime;
  bool operator < (const ServiceEvent& s) const {return endOfServiceTime > s.endOfServiceTime;}
};

int getRandomNumberOfArrivals(double);

int main()
{
  // programmer's identification
  cout << "Programmer: Richard Xie";
  cout << "Programmer's ID: 1435650\n";
  cout << "File: " << __FILE__ << endl << endl;

  srand(time(0)); rand();

  int numberOfServers, maxLength, minTime, maxTime, arrivalStop;
  double avgRate;
  char buf[100];

  // read the input values from a text file, one per line, in the order specified above.
  ifstream fin;
  fin.open("Simulation.txt");
  if (!fin.good()) throw "I/O error";

  fin >> buf; numberOfServers = atoi(buf);
  fin >> buf; avgRate = atof(buf);
  fin >> buf; maxLength = atoi(buf);
  fin >> buf; minTime = atoi(buf);
  fin >> buf; maxTime = atoi(buf);
  fin >> buf; arrivalStop = atoi(buf);

  fin.close();

  cout << "number of servers:     " << numberOfServers << endl;
  cout << "customer arrival rate: " << avgRate << " per minute, for " << arrivalStop << " minutes" << endl;
  cout << "maximum queue length:  " << maxLength << endl;
  cout << "minimum service time:  " << minTime << endl;
  cout << "maximum service time:  " << maxTime << endl;
  cout.setf(ios::fixed | ios::showpoint);
  cout << setprecision(2);
  cout << endl;

  // declare and create and assign arrays and queues to be used in the solution
  Queue <Customer> waitQueue;
  PriorityQueue <ServiceEvent> eventQueue;
  DynamicArray <Customer> nowServing(numberOfServers);
  DynamicArray <bool> inUse(numberOfServers);

  for (int i = 0; i < numberOfServers; i++)
    inUse[i] = false;

  int costumerCreated = 0;

  // the clock time loop
  for (int time = 0;; time++) // the clock time
  {
    // handle all services scheduled to complete at this clock time
    while (!eventQueue.empty() && eventQueue.top().endOfServiceTime == time)
    {
      inUse[eventQueue.top().server] = false;
      eventQueue.pop();
    }

    // handle new arrivals -- can be turned away if wait queue is at maximum length!
    if (time < arrivalStop)
    {
      int arrivals = getRandomNumberOfArrivals(avgRate);
      for (int i = 0; i < arrivals; i++)
      {
        if (waitQueue.size() < maxLength)
        {
          Customer a;
          a.arrivalTime = time;//set its arrival time equal to the current clock time
          a.IDTag = (char)('A' + (costumerCreated++ % 26));
          waitQueue.push(a);
        }
      }
    }

    // for idle servers, move customer from wait queue and begin service
    for (int i = 0; i < numberOfServers; i++)
    {
      if (inUse[i] == false && !waitQueue.empty())
      {
         nowServing[i] = waitQueue.front();
         waitQueue.pop();
         nowServing[i].serviceEndTime = time + minTime + rand() % (maxTime - minTime + 1);
         inUse[i] = true;

         ServiceEvent s;
         s.endOfServiceTime = nowServing[i].serviceEndTime;
         s.server = i;
         eventQueue.push(s);
      }
    }

    // output the summary
    cout << "Time: " << time << endl;
    cout << "---------------------------" << endl;
    cout << "line now serving wait queue" << endl;
    cout << "---- ----------- ----------" << endl;

    for (int i = 0; i < numberOfServers; i++)
    {
      cout << "  " << i << "       ";

      if (inUse[i] == true)
        cout << nowServing[i].IDTag;
      else
        cout << " ";

      if (i == 0)
      {
        cout << "      ";
        for (Queue<Customer> copy = waitQueue; !copy.empty(); copy.pop())
          cout << copy.front().IDTag;
      }
      cout << endl;
    }
    cout << "---------------------------" << endl;

    // if the end of the simulation has been reached, break
    if (waitQueue.empty() && time > arrivalStop)
    {
      int e = 0;
      for (int i = 0; i < numberOfServers; i++)
      {
        if (!inUse[i])
        e++;
      }

      if(e == numberOfServers)
        break;

      // pause for the user to press ENTER
      cout << "Press ENTER to continue " << endl;
      cin.get();
      continue;
    }

    // pause for the user to press ENTER
    cout << "Press ENTER to continue" << endl;;
    cin.get();
    continue;
  }
  cout << "Done!" << endl;
}

int getRandomNumberOfArrivals(double averageArrivalRate)
{
  int arrivals = 0;
  double probOfnArrivals = exp(-averageArrivalRate);
  for (double randomValue = (double)rand() / RAND_MAX;
    (randomValue -= probOfnArrivals) > 0.0;
    probOfnArrivals *= averageArrivalRate / (double)++arrivals);
  return arrivals;
}
