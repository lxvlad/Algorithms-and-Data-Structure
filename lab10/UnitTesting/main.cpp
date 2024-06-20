#include "gtest/gtest.h"
#include "/Users/vlish21/University/Algorithms-and-Data-Structure/lab10/DijkstraAlgorithm/Graph.cpp"

// Тест для перевірки додавання ребер з вірними даними
TEST(GraphTest, AddValidEdge)
{
        Graph graph(3);
        graph.addEdge(0, 1, 5);
        graph.addEdge(1, 2, 3);

        EXPECT_EQ(graph.getEdgeWeight(0, 1), 5);
        EXPECT_EQ(graph.getEdgeWeight(1, 2), 3);
        EXPECT_EQ(graph.getEdgeWeight(2, 1), 3); // Можна перевірити симетричне додавання
}

// Тест для перевірки додавання ребра з однаковими вершинами
TEST(GraphTest, AddEdgeSameVertices) {
        Graph graph(3);

        // Повинен вивести повідомлення про помилку
        testing::internal::CaptureStdout();
        graph.addEdge(1, 1, 5);
        std::string output = testing::internal::GetCapturedStdout();
        EXPECT_EQ(output, "Ребро не може мати двох однакових вершин!\n");
}

// Тест для перевірки додавання ребра з неправильною вагою
TEST(GraphTest, AddEdgeInvalidWeight) {
        Graph graph(3);

        // Повинен вивести повідомлення про помилку
        testing::internal::CaptureStdout();
        graph.addEdge(0, 1, -5);
        std::string output = testing::internal::GetCapturedStdout();
        EXPECT_EQ(output, "Неправильна вага\n");
}

// Тест для перевірки алгоритму Дейкстри
TEST(GraphTest, DijkstraAlgorithm) {
        Graph graph(4);
        graph.addEdge(0, 1, 5);
        graph.addEdge(0, 2, 10);
        graph.addEdge(1, 2, 3);
        graph.addEdge(1, 3, 9);
        graph.addEdge(2, 3, 2);

        EXPECT_EQ(graph.dijkstra(0), 10);
}

int main(int argc, char **argv)
{
        testing::InitGoogleTest(&argc, argv);
        return RUN_ALL_TESTS();
}