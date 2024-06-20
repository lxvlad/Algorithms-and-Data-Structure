#include <iostream>
#include <vector>
#include <limits>

class Graph {
private:
    int V;
    std::vector<std::vector<int>> edges;

public:
    Graph(int vertices) : V(vertices), edges(vertices, std::vector<int>(vertices, 0)) {}

    ~Graph() {}

    void addEdge(int u, int v, int weight) {
        if (u == v) {
            std::cout << "Ребро не може мати двох однакових вершин!" << std::endl;
            return;
        }

        if (weight <= 0) {
            std::cout << "Неправильна вага" << std::endl;
            return;
        }

        edges[u][v] = weight;
        edges[v][u] = weight;
    }

    int getEdgeWeight(int u, int v) const {
        return edges[u][v];
    }

    int minDistance(const std::vector<int>& dist, const std::vector<bool>& shortestPathSet) const {
        int min = std::numeric_limits<int>::max(), min_index = -1;

        for (int v = 0; v < V; ++v) {
            if (!shortestPathSet[v] && dist[v] <= min) {
                min = dist[v];
                min_index = v;
            }
        }

        return min_index;
    }

    int dijkstra(int src) const {
        std::vector<int> dist(V, std::numeric_limits<int>::max());
        std::vector<bool> shortestPathSet(V, false);

        dist[src] = 0;

        for (int count = 0; count < V - 1; ++count) {
            int u = minDistance(dist, shortestPathSet);
            shortestPathSet[u] = true;

            for (int v = 0; v < V; ++v) {
                if (!shortestPathSet[v] && edges[u][v] && dist[u] != std::numeric_limits<int>::max() &&
                    dist[u] + edges[u][v] < dist[v]) {
                    dist[v] = dist[u] + edges[u][v];
                }
            }
        }

        std::cout << "\nВершина   Відстань\n";
        for (int i = 0; i < V; ++i) {
            std::cout << i << "\t\t" << dist[i] << '\n';
        }

        int max = 0;
        for (int i = 1; i < V; ++i) {
            if (dist[max] < dist[i])
                max = i;
        }

        return dist[max];
    }
};


//
// Created by Vladyslav Lishchynskyi on 20.06.2024.
//
