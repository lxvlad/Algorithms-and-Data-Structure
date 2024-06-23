#include <iostream>

#include "Graph.cpp"

int main()
{
    int V = 6;
    Graph g(V);

    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 1);
    g.addEdge(1, 3, 3);
    g.addEdge(1, 4, 8);
    g.addEdge(2, 3, 7);
    g.addEdge(3, 4, 2);
    g.addEdge(3, 5, 1);
    g.addEdge(4, 5, 4);

    int src = 0;

    vector<int> shortestDistances = g.dijkstra(src);

    cout << "Відстані від вершини " << src << " до інших вершин:" << endl;
    for (int i = 0; i < V; ++i)
        cout << "До вершини " << i << ": " << shortestDistances[i] << endl;


    return 0;
}