#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

class Graph {

private:
      int** adjMatrix;
      int numVertices;

public:

    Graph(int numVertices);
 
    void addEdge(int i, int j, int weight);
    void removeEdge(int i, int j);
    void toString();

    void DFS(int st, bool* visited);
    bool isConnectedGraph(int st);
    void Dijkstra(int st, int end);
    
 
    ~Graph();
};

#endif 

