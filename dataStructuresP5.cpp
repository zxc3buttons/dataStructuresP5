#include <iostream>
#include "Graph.h"

using namespace std;

int main()
{
    int numVertices = 0;

    cout << "Enter amount of Vertices: "; cin >> numVertices;
    cout << endl;

    Graph graph(numVertices);

    cout << "Enter edges a >= 0 and b >= 0 and weight > 0. Enter -1 -1 -1 if you want to end input: " << endl;

    int a, b, weight;

    while (true) {
        cin >> a >> b >> weight;
        if (a == -1 && b == -1 && weight == -1) break;
        graph.addEdge(a, b, weight);
    }

    cout << endl;

    cout << "Adjacency matrix: " << endl;
    cout << endl;
    graph.toString();
    cout << endl;

    if (graph.isConnectedGraph(0)) cout << "Graph is connected";
    else cout << "Graph is disconnected" << endl;
    cout << endl;

    int st, end;
    cout << "Enter start and end vertices to calculate path cost: "; cin >> st >> end;
    graph.Dijkstra(st, end);
    cout << endl;
}


