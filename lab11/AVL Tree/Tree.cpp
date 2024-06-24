#include <algorithm>
#include <iostream>

#pragma once

class Node
{
public:
    int key;
    Node* left;
    Node* right;
    int height;

    Node(int k) : key(k), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree
{
    Node* root;

    int height(Node* node)
    {
        if (node == nullptr) // якщо вузол порожній
            return 0;
        return node->height;
    }

    int getBalance(Node* node)
    {
        if (node == nullptr)
            return 0;

        // обчислюєм баланс фактор дерева (різниця висоти лівого сина і висоти правого сина)
        return height(node->left) - height(node->right);
    }

    // виконуєм правий та лівий повороти відповідно для виправлення небалансу.
    Node* rightRotate(Node* y)
    {
        Node* x = y->left;
        Node* T = x->right;

        // Виконання повороту
        x->right = y;
        y->left = T;

        // Оновлення висот
        y->height = 1 + std::max(height(y->left), height(y->right));
        x->height = 1 + std::max(height(x->left), height(x->right));

        return x;
    }

    Node* leftRotate(Node* x)
    {
        Node* y = x->right;
        Node* T = y->left;

        // Виконання повороту
        y->left = x;
        x->right = T;

        // Оновлення висот
        x->height = 1 + std::max(height(x->left), height(x->right));
        y->height = 1 + std::max(height(y->left), height(y->right));

        return y;
    }

    Node* insert(Node* node, int key)
    {
        if (!node)
            return new Node(key);

        if (key < node->key)
            node->left = insert(node->left, key); // рекурсивно вставляєм у ліве піддерево
        else if (key > node->key)
            node->right = insert(node->right, key); // рекурсивно вставляєм у праве піддерево
        else
            return node; // якщо такий ключ вже існує то ДУПЛІКАТ не вставляємо

        // оновлюємо висоти
        node->height = 1 + std::max(height(node->left), height(node->right));

        int balance = getBalance(node);

        if (balance > 1 && key < node->left->key)
            return rightRotate(node);

        if (balance < -1 && key > node->right->key)
            return leftRotate(node);

        if (balance > 1 && key > node->left->key) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && key < node->right->key) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    Node* deleteNode(Node* root, int key)
    {
        if (!root)
            return root;

        if (key < root->key)
            root->left = deleteNode(root->left, key); // рекурсивне видалення вузла з лівого піддерева
        else if (key > root->key)
            root->right = deleteNode(root->right, key);
        else
        {
            if ((root->left == nullptr) || (root->right == nullptr)) // перевірка на наявність синів
            {
                Node* temp = root->left ? root->left : root->right;

                if (!temp)
                {
                    temp = root;
                    root = nullptr;
                }
                else
                    *root = *temp;
                delete temp;
            }
            else
            {
                Node* temp = findMin(root->right);
                root->key = temp->key;
                root->right = deleteNode(root->right, temp->key); // рекурсивне видалення мінімального вузла з правого піддерева
            }
        }

        if (!root)
            return root;

        // Оновлення висоти та балансу
        root->height = 1 + std::max(height(root->left), height(root->right));

        int balance = getBalance(root);

        if (balance > 1 && getBalance(root->left) >= 0)
            return rightRotate(root);

        if (balance > 1 && getBalance(root->left) < 0)
        {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        if (balance < -1 && getBalance(root->right) <= 0)
            return leftRotate(root);

        if (balance < -1 && getBalance(root->right) > 0)
        {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    Node* findMin(Node* node)
    {
        Node* current = node;
        while (current->left != nullptr)
            current = current->left;
        return current;
    }

    bool search(Node* root, int key)
    {
        if (!root)
            return false;

        if (key == root->key)
            return true;

        if (key < root->key)
            return search(root->left, key);

        return search(root->right, key);
    }

    void preOrder(Node* root)
    {
        if (root != nullptr)
        {
            std::cout << root->key << " ";
            preOrder(root->left);
            preOrder(root->right);
        }
    }

    void printTreeGraph(Node* root, int space = 0, int height = 10)
    {
        if (!root)
            return;

        space += height;

        printTreeGraph(root->right, space);

        std::cout << std::endl;
        for (int i = height; i < space; i++)
            std::cout << ' ';
        std::cout << root->key << "\n";

        printTreeGraph(root->left, space);
    }

public:
    AVLTree() : root(nullptr) {}
    void insert(int key) { root = insert(root, key); }
    void deleteNode(int key) { root = deleteNode(root, key); }
    bool search(int key) { return search(root, key); }
    void preOrder() { preOrder(root); }
    void printTreeGraph() { printTreeGraph(root); }
};

