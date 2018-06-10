// Programmer: Richard Xie
// Programmer's ID: 1435650

#include <fstream>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <utility>
using namespace std;

#include <cstdlib>

struct Vertex
{
  string name;
  bool isVisited;
  list<pair<int, double> > adjacentVertices;
  int prev;
  double cost;
};

struct Terminus // the path to a node and the cost of that path
{
  int index; // the node's index in the database array
  int prev; // the index of the preceding node in the path
  double cost; // the cost of getting to index's node from prev's node
};

bool operator<(const Terminus& a, const Terminus& b)
{
  return b.cost < a.cost; // reverse logic for lo-to-hi
}

pair<stack<int>, double> getShortestRoute(int iStart, int iEnd, vector<Vertex>& database)
{
  pair<stack<int>, double> result;
  list<pair<int, double> >::iterator it; // to iterate over adjacentVertices
  // TO DO -- write this function
  // reset prev=-1 for all vertices, isVisited to false
  for (int i = 0; i < database.size(); i++)
  {
    database[i].prev = -1;
    database[i].isVisited = false;
  }
  // create an STL priority queue of Terminus objects as the to-do list
  priority_queue<Terminus> toDo;
  // create a Terminus object for the start node with prev=-1, cost=0
  Terminus s;
  s.index = iStart;
  s.prev = -1;
  s.cost = 0;
  // push the start node's Terminus object onto the priority queue to-do list
  toDo.push(s);
  // while the priority queue to-do list is not empty
  while (!toDo.empty())
  {
    // peek/pop a Terminus object from the priority queue to-do list
    Terminus t = toDo.top();
    toDo.pop();
    // if contained object's been visited, "continue;"
    if (database[t.index].isVisited) continue;
    // mark contained object as visited
    database[t.index].isVisited = true;
    // set its cost to that of its Terminus
    database[t.index].cost = t.cost;
    // set its prev to that of its Terminus
    database[t.index].prev = t.prev;
    // if Terminus' node is the end node, exit while-loop
    if (t.index == iEnd) break;
    // for each of that node's unvisited neighbors
    for (it = database[t.index].adjacentVertices.begin(); it != database[t.index].adjacentVertices.end(); it++)
    {
      // create a Terminus object for neighbor
      Terminus n;
      n.index = it->first;
      // set its cost to that of the node, plus edge cost
      n.cost = database[t.index].cost + it->second;
      // set its prev to the node's index
      n.prev = t.index;
      // push the Terminus object onto priority queue to-do list
      toDo.push(n);
    }
  }
  result.second = database[iEnd].cost;
  // build a stack of entries, starting from the end node, back towards the start
  for (int v = iEnd; v >= 0; v = database[v].prev)
    result.first.push(v);
  return result;
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
    string fromCity, toCity, cost;

    // read one edge
    getline(fin, fromCity);
    getline(fin, toCity);
    getline(fin, cost);
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
    double edgeCost = atof(cost.c_str());
    database[iFromVertex].adjacentVertices.push_back(pair<int, double>(iToVertex, edgeCost));
    database[iToVertex].adjacentVertices.push_back(pair<int, double>(iFromVertex, edgeCost));
  }
  fin.close();
  cout << "Input file processed\n\n";

  while (true)
  {
    string fromCity, toCity;
    cout << "\nEnter the source city [blank to exit]: ";
    getline(cin, fromCity);
    if (fromCity.length() == 0) break;

    // find the from city
    int iFrom;
    for (iFrom = 0; iFrom < database.size(); iFrom++)
      if (database[iFrom].name == fromCity)
        break;

    cout << "Enter the destination city [blank to exit]: ";
    getline(cin, toCity);
    if (toCity.length() == 0) break;

    // find the destination city
    int iTo;
    for (iTo = 0; iTo < database.size(); iTo++)
      if (database[iTo].name == toCity)
        break;

    cout << "Route";
    pair<stack<int>, double> result = getShortestRoute(iFrom, iTo, database);
    while (!result.first.empty()){cout << '-' << database[result.first.top()].name; result.first.pop();}
    cout << " Total miles: " << result.second;
    cout << endl;
  }
}

