#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max(); // Нескінченність для відстаней

class Graph {
    int V;
    vector<vector<pair<int, int>>> adj; // Список суміжності (пара <вершина, вага ребра>)

public:
    Graph(int V)
    {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v, int weight)
    {
        adj[u].push_back(make_pair(v, weight));
        adj[v].push_back(make_pair(u, weight)); // Якщо граф ненаправлений
    }

    vector<int> dijkstra(int src)
    {
        vector<int> dist(V, INF); // Відстані від src до всіх вершин, початково встановлюємо як нескінченність
        dist[src] = 0; // Відстань до самої себе = 0

        // Пріоритетна черга для зберігання пар <відстань, вершина> в порядку зростання відстаней
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push(make_pair(0, src)); // Додаємо початкову вершину з вагою 0

        while (!pq.empty())
        {
            int u = pq.top().second; // Поточна вершина з найменшою відстанню
            pq.pop();

            // Проходимо по всіх сусідніх вершинах поточної вершини u
            for (auto& neighbor : adj[u])
            {
                int v = neighbor.first; // Сусідня вершина
                int weight = neighbor.second; // Вага ребра u-v

                // Оновлення відстані, якщо знайдено коротший шлях
                if (dist[v] > dist[u] + weight)
                {
                    dist[v] = dist[u] + weight;
                    pq.push(make_pair(dist[v], v));
                }
            }
        }

        return dist; // Повертаємо масив з найкоротшими відстанями до всіх вершин від src
    }
};


