#include <iostream>
#include <string>
#include <exception>

struct Node
{
    int value;
    Node* left = nullptr;
    Node* right = nullptr;

    // Constructor
    Node() {};

    // Overloaded Constructor
    Node(int value) : value(value) {}

    // Overloaded Constructor
    Node(int value, Node* left, Node* right) : value(value), left(left), right(right) {}
};

void PreOrderPrint(Node* n)
{ 
    std::cout << n->value << std::endl;
    PreOrderPrint(n->left);
    PreOrderPrint(n->right);
}

void PostOrderPrint(Node* n)
{ 
    PreOrderPrint(n->left);
    PreOrderPrint(n->right);
    std::cout << n->value << std::endl;
}

//Node* Find(Node* n, int value)
//{
//    // TODO
//}
//
//void Insert(Node* root, Node* nodeToInsert)
//{
//    // TODO 
//}
//
//void Remove(Node* root, Node* nodeToRemove)
//{
//    // TODO
//}
//
//int Height(Node* n)
//{
//    // TODO
//}
//
//int Depth(Node* root, Node* n)
//{
//    // TODO
//}

int main(int argc, char** argv)
{

    new Node(6,
        new Node(4,
            new Node(2, nullptr, nullptr),
            new Node(5, nullptr, nullptr)),
        new Node(8,
            new Node(7, nullptr, nullptr),
            new Node(9, nullptr, nullptr)));

    // TODO: Test the methods


    return 0;
}
