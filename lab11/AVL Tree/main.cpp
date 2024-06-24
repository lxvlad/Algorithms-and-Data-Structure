#include "Tree.cpp"


int main()
{
    AVLTree tree;

    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    tree.insert(25);

    std::cout << "Preorder notation of the constructed AVL tree is \n";
    tree.preOrder();
    std::cout << "\n";

    tree.printTreeGraph();

    std::cout << "\nDeleting 40\n";
    tree.deleteNode(40);
    tree.printTreeGraph();

    std::cout << "\nSearching for 30: " << (tree.search(30) ? "Found" : "Not Found") << "\n";
    std::cout << "Searching for 40: " << (tree.search(40) ? "Found" : "Not Found") << "\n";

    return 0;
}
