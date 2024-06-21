#pragma once

struct Node
{
    int data;
    Node* left;
    Node* right;
    int height;
};

int height(Node* node);
int getBalance(Node* node);
Node* rotateRight(Node* y);
Node* rotateLeft(Node* x);
Node* insert(Node* node, int data);
Node* findMin(Node* node);
Node* deleteNode(Node* node, int data);
Node* search(Node* node, int key);
void printTreeGraph(Node* root, int space = 0, int count = 10);