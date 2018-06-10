// Programmer: Richard Xie
// Programmer's ID: 1435650

#include <fstream>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;

struct Vertex
{
  string name;
  bool isVisited;
  list<int> adjacentVertices;
};

queue<int> doBreadthFirstSearch(int iOriginVertex, vector<Vertex>& database)
{
  queue<int> searchOrder; // return this queue of indices
  // TO DO -- write this function
  // create another queue of ints to store the "to-do" list
  stack<int> toDo;
  // initialize each node in database: set to "not visited"
  for (int i = 0; i < database.size(); i++)
    database[i].isVisited = false;
  // push start node's index onto the "to-do" list
  toDo.push(iOriginVertex);
  // while the "to-do" list is not empty
  while (!toDo.empty())
  {
    // peek/pop a node's index from the "to-do" list
    int n = toDo.top();
    toDo.pop();
    // if that node has not yet been visited
    if (!database[n].isVisited)
    {
      // mark neighbor as visited
      database[n].isVisited = true;
      // push node's index onto the result queue
      searchOrder.push(n);
      // for each of that node's neighbors (in reverse order)
      list<int>::reverse_iterator it;
      for (it = database[n].adjacentVertices.rbegin(); it != database[n].adjacentVertices.rend(); it++)
      {
        // if neighbor has not yet been visited
        if (!(database[*it].isVisited))
          // push neighbor's index onto the "to-do" list
          toDo.push(*it);
      }
    }
  }
  // return the result queue
  return searchOrder;
}

int main()
{
  // programmer's identification
  cout << "Programmer: Richard Xie";
  cout << "Programmer's ID: 1435650\n";
  cout << "File: " << __FILE__ << endl << endl;

  ifstream fin;
  fin.open("cities.txt");
  if (!fin.good()) throw "I/O error";

  // process the input file
  vector<Vertex> database;
  while (fin.good()) // EOF loop
  {
    string fromCity, toCity;

    // read one edge
    getline(fin, fromCity);
    getline(fin, toCity);
    fin.ignore(1000, 10); // skip the line with distance
    fin.ignore(1000, 10); // skip the separator

    // add vertices for new cities included in the edge
    int iToVertex = -1, iFromVertex = -1, i;
    for (i = 0; i < database.size(); i++) // seek "to" city
      if (database[i].name == fromCity)
        break;
    if (i == database.size()) // not in database yet
    {
      // store the vertex if it is new
      Vertex fromVertex;
      fromVertex.name = fromCity;
      database.push_back(fromVertex);
    }
    iFromVertex = i;

    for (i = 0; i < database.size(); i++) // seek "from" city
      if (database[i].name == toCity)
        break;
    if (i == database.size()) // not in vector yet
    {
      // store the vertex if it is new
      Vertex toVertex;
      toVertex.name = toCity;
      database.push_back(toVertex);
    }
    iToVertex = i;

    // store bi-directional edges
    database[iFromVertex].adjacentVertices.push_back(iToVertex);
    database[iToVertex].adjacentVertices.push_back(iFromVertex);
  }
  fin.close();
  cout << "Input file processed\n\n";

  while (true)
  {
    // get the start city for the search
    string startCity;
    cout << "\nEnter the start city [blank to exit]: ";
    getline(cin, startCity);
    if (startCity.length() == 0) break;

    // find the start city
    int i;
    for (i = 0; i < database.size(); i++)
      if (database[i].name == startCity)
        break;

    // BFS result
    cout << "DFS";
    queue<int> q = doBreadthFirstSearch(i, database);
    while(!q.empty())
    {
      cout  << '-'<< database[q.front()].name;
      q.pop();
    }
    cout << endl;
  }
}

