#include <iostream>
#include "Tree.h"
#include <vector>;
#include <string>


int main()
{
    // Створення порожнього кореня дерева
    Node* root = nullptr;

    std::cout << "Enter values that will be stored in AVL-tree (type \"stop\" to stop):\n";
    while (true) {
        std::string val;
        std::cin >> val;
        if (val == "stop") // Перевірка на виход з циклу при введенні символу 'S'
            break;
        root = insert(root, std::stoi(val)); // Вставка введеного значення в дерево
    }

    std::cout << "AVL Tree (Graph representation) before deletion:\n";
    printTreeGraph(root, 0, 10); // Виведення графічного представлення дерева

    int condition;
    std::cout << "Enter the element you want to delete: ";
    std::cin >> condition;
    try {
        root = deleteNode(root, condition);

        std::cout << "AVL Tree (Graph representation) after deletion:\n";
        printTreeGraph(root, 0, 10);
    }
    catch (std::exception& e)
    {
        std::cerr << "Occured an error: " << e.what();
    }
    Node* root1 = search(root, 12);
    if (root1 == nullptr)
        std::cout << "No such value in tree ("<< 12 <<')' <<'\n';
    else {
        std::cout << root1->data;
    }
    return 0;
}