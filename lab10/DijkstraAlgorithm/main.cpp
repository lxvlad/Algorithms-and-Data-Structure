#include "Graph.cpp"
using namespace std;


int main()
{
    Graph graph(5);
    graph.addEdge(0, 1, 4);
    graph.addEdge(0, 2, 8);
    graph.addEdge(1, 2, 1);
    graph.addEdge(1, 3, 5);
    graph.addEdge(2, 3, 2);
    graph.addEdge(3, 4, 3);


    cout << "Найкоротший шлях від вашої вершини до останньої: " << graph.dijkstra(0) << endl;

    return 0;
}