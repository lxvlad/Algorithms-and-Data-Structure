#include <iostream>
#include "Tree.h"
#include <iomanip>

int height(Node* node) {
    if (node == nullptr) return 0;
    return node->height;
}

int getBalance(Node* node) {
    if (node == nullptr) return 0;
    return height(node->left) - height(node->right);
}

Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* T = x->right;
    x->right = y;
    y->left = T;
    y->height = 1 + std::max(height(y->left), height(y->right));
    x->height = 1 + std::max(height(x->left), height(x->right));
    return x;
}

Node* rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T = y->left;
    y->left = x;
    x->right = T;
    x->height = 1 + std::max(height(x->left), height(x->right));
    y->height = 1 + std::max(height(y->left), height(y->right));
    return y;
}

Node* insert(Node* node, int data) {
    if (node == nullptr) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->left = nullptr;
        newNode->right = nullptr;
        newNode->height = 1;
        return newNode;
    }
    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    else
        return node;
    node->height = 1 + std::max(height(node->left), height(node->right));
    int balance = getBalance(node);
    // Left Heavy
    if (balance > 1) {
        if (data < node->left->data) {
            // Left-Left Case
            return rotateRight(node);
        }
        else {
            // Left-Right Case
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
    }
    // Right Heavy
    if (balance < -1) {
        if (data > node->right->data) {
            // Right-Right Case
            return rotateLeft(node);
        }
        else {
            // Right-Left Case
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }
    }
    return node;
}

Node* findMin(Node* node) {
    Node* current = node;
    while (current->left != nullptr) {
        current = current->left;
    }
    return current;
}
Node* search(Node* node, int key) {
    if (node == nullptr) {
        return nullptr;
    }
    if (node->data == key) {
        return node;
    }
    if (node->data < key) {
        return search(node->right, key);
    }
    return search(node->left, key);
}

Node* deleteNode(Node* node, int data) {
    if (node == nullptr) {
        throw std::invalid_argument("Element to delete is not found in the tree");
    }

    if (data < node->data)
        node->left = deleteNode(node->left, data);
    else if (data > node->data)
        node->right = deleteNode(node->right, data);
    else {
        if (node->left == nullptr || node->right == nullptr) {
            Node* temp = node->left ? node->left : node->right;
            if (temp == nullptr) {
                temp = node;
                node = nullptr;
            }
            else {
                *node = *temp;
            }
            delete temp;
        }
        else {
            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }
    }

    if (node == nullptr) return node;

    node->height = 1 + std::max(height(node->left), height(node->right));
    int balance = getBalance(node);

    // Left Heavy
    if (balance > 1) {
        if (getBalance(node->left) >= 0) {
            return rotateRight(node);
        }
        else {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
    }
    // Right Heavy
    if (balance < -1) {
        if (getBalance(node->right) <= 0) {
            return rotateLeft(node);
        }
        else {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }
    }
    return node;
}

void printTreeGraph(Node* root, int space, int count) {
    if (root == nullptr) return;
    space += count;
    printTreeGraph(root->right, space);
    std::cout << std::endl;
    for (int i = count; i < space; i++)
        std::cout << " ";
    std::cout << '*' << root->data << "\n";
    printTreeGraph(root->left, space);
}