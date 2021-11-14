#include "Graph.h"

Graph::Graph(int numVertices) {

    this->numVertices = numVertices;
    adjMatrix = new int* [numVertices];

    for (int i = 0; i < numVertices; i++) {
        adjMatrix[i] = new int[numVertices];

        for (int j = 0; j < numVertices; j++)
            adjMatrix[i][j] = false;
    }
}

void Graph::addEdge(int i, int j, int weight) {
    adjMatrix[i][j] = weight;
    adjMatrix[j][i] = weight;
}

void Graph::removeEdge(int i, int j) {
    adjMatrix[i][j] = 0;
    adjMatrix[j][i] = 0;
}

void Graph::toString() {

    for (int i = 0; i < numVertices; i++) {
        cout << i << " : ";

        for (int j = 0; j < numVertices; j++)
            cout << adjMatrix[i][j] << " ";

        cout << "\n";
    }
}

void Graph::DFS(int st, bool* visited)
{
    int r;
    visited[st] = true;

    for (r = 0; r <= numVertices; r++)
        if ((adjMatrix[st][r] != 0) && (!visited[r]))
            DFS(r, visited);
}

bool Graph::isConnectedGraph(int st) {

    bool* visited = new bool[numVertices];

    for (int i = 0; i < numVertices; i++)
        visited[i] = false;

    int amountOfReachedVertices = 0;

    DFS(st, visited);

    for (int i = 0; i < numVertices; i++)
        if (visited[i]) amountOfReachedVertices++;

    if (amountOfReachedVertices == numVertices) {
        cout << "Graph is connected" << endl;
        return true;
    }
    
    cout << "Graph is disconnected";
    return false;

}

int* Graph::Dijkstra(int st, int end) {

    int* distance = new int[numVertices];
    int* arrayPath = new int[numVertices];

    int count, index, i, u, m = st + 1;

    bool* visited = new bool[numVertices];

    for (i = 0; i < numVertices; i++)
    {
        distance[i] = INT_MAX;
        visited[i] = false;
        arrayPath[i] = 0;
    }

    distance[st] = 0;

    for (count = 0; count < numVertices - 1; count++)
    {
        int min = INT_MAX;
        for (i = 0; i < numVertices; i++)
            if (!visited[i] && distance[i] <= min)
            {
                min = distance[i]; index = i;
            }

        u = index;

        visited[u] = true;

        for (i = 0; i < numVertices; i++)
            if (!visited[i] && adjMatrix[u][i] && distance[u] != INT_MAX && distance[u] + adjMatrix[u][i] < distance[i])
                distance[i] = distance[u] + adjMatrix[u][i];
    }

    cout << "Path cost from start vertex to end:\n";
    cout << distance[end] << endl;
    cout << endl;

    return distance;
}

void Graph::outputShortestPath(int st, int end, int* distance) {

    int* arrayPath = new int[numVertices];

    for (int i = 0; i < numVertices; i++)
        arrayPath[i] = 0;

    arrayPath[end] = 1;

    while (end != st) {

        for (int i = 0; i < numVertices; i++) {

            if (adjMatrix[end][i] != 0 && distance[end] - adjMatrix[end][i] == distance[i]) {
                arrayPath[i] = 1;
                end = i;
            }
        }
    }

    cout << "Path from start to end vertex:" << endl;
    cout << endl;
    for (int i = 0; i < numVertices; i++)
        if (arrayPath[i] != 0) cout << i << " ";
}

Graph::~Graph() {

    for (int i = 0; i < numVertices; i++)
        delete[] adjMatrix[i];
    delete[] adjMatrix;

}
