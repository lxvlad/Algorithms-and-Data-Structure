#include "gtest/gtest.h"
#include "/Users/vlish21/University/Algorithms-and-Data-Structure/lab10/DijkstraAlgorithm/Graph.cpp"

TEST(GraphTest, DijkstraShortestPath)
{
    Graph g(5);

    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 1);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 5);
    g.addEdge(2, 3, 2);
    g.addEdge(2, 4, 1);
    g.addEdge(3, 4, 3);

    vector<int> shortest_distances = g.dijkstra(0);

    EXPECT_EQ(shortest_distances[0], 0);  // Distance to itself should be 0
    EXPECT_EQ(shortest_distances[1], 3);  // Shortest path to vertex 1
    EXPECT_EQ(shortest_distances[2], 1);  // Shortest path to vertex 2
    EXPECT_EQ(shortest_distances[3], 3);  // Shortest path to vertex 3
    EXPECT_EQ(shortest_distances[4], 2);  // Shortest path to vertex 4
}

TEST(GraphTest, DijkstraSingleVertex)
{
    Graph g(1);

    vector<int> shortest_distances = g.dijkstra(0);

    EXPECT_EQ(shortest_distances[0], 0);
}

TEST(GraphTest, DijkstraNegativeWeights)
{
    Graph g(4);

    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, -2);
    g.addEdge(1, 3, 1);
    g.addEdge(2, 3, -4);

    vector<int> distances = g.dijkstra(0);

    ASSERT_EQ(distances[0], 0); // Відстань від вершини 0 до себе повинна бути 0
    ASSERT_EQ(distances[1], 5); // Відстань від вершини 0 до вершини 1
    ASSERT_EQ(distances[2], -2); // Відстань від вершини 0 до вершини 2
    ASSERT_EQ(distances[3], -3); // Відстань від вершини 0 до вершини 3
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
