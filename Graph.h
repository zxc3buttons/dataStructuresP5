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

    // Поиск в глубину - Depth-First-Search
    void DFS(int st, bool* visited);

    // Связный ли граф?
    bool isConnectedGraph(int st);

    // Возвращает массив минимальных расстояний от стартовой вершины до конечной
    int* Dijkstra(int st, int end);

    // Вывод самого короткого пути от стартовой от до конечной вершины
    void outputShortestPath(int st, int end, int* distance);
    
 
    ~Graph();
};

#endif 

