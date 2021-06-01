#include <iostream>
#include <string>
#include <exception>
#include <functional>
#include <stack>

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
    if (n == nullptr)
        return;

    std::cout << n->value << std::endl;

    PreOrderPrint(n->left);
    PreOrderPrint(n->right);
}

void PostOrderPrint(Node* n)
{ 
    if (n == nullptr)
        return;

    PreOrderPrint(n->left);
    PreOrderPrint(n->right);

    std::cout << n->value << std::endl;
}

void FindNode(int value, Node*& node, Node*& parent) {
    //TODO:
    //node = the found node
    //parent = the found nodes parent
    
    //Node *n = nullptr;
    //Node *p = nullptr;
    //FindNow(9,n,p)


}

Node* Find(Node* n, int value)
{
    if (n == nullptr) return nullptr;

    if (value > n->value) 
        return Find(n->right,value);
    
    else if (value < n->value) 
        return Find(n->left, value);
    
    return n;   
}

void Insert(Node* root, Node* nodeToInsert)
{
    // TODO 
    auto InsertValue = nodeToInsert->value;
    int rootValue = root->value;

    //checks right side
    if (InsertValue > rootValue) {
        if (root->right != nullptr) {
            Insert(root->right, nodeToInsert);
        }     
    } 
    //creates the right node
    else 
        root->right = nodeToInsert;
    
    //checks left side
    if (InsertValue < rootValue) {
        if (root->left != nullptr) {
            Insert(root->right, nodeToInsert);
        }
    }
    //creates the left node
    else 
        root->left = nodeToInsert;
    
}

void Remove(Node* root, Node* nodeToRemove)
{
    // TODO
}

int Height(Node* n)
{
    // TODO
    return 0;
}

int Depth(Node* root, Node* n)
{
    // TODO
    return 0;
}

/*
void ForEachDfs(Node* root, std::function<void(Node*)> fn)
{
    // Create the stack
    std::list<Node*> stack;

    // add first node to the stack
    stack.push_back(root);

    // while stack is not empty
    while (stack.empty() == false)
    {
        // remove the next node
        Node* n = stack.back();
        stack.pop_back();

        // process the node
        fn(n);

        // add children to the stack
        if (n->right) stack.push_back(n->right);
        if (n->left) stack.push_back(n->left);
    }
}
*/

void ForEachPreOrder(Node* n, std::function<void(Node*)> fn)
{
    if (n == nullptr)
        return;

    // Invoke the fn for each node
    fn(n);

    ForEachPreOrder(n->left, fn);
    ForEachPreOrder(n->right, fn);
}

void PrintNode(Node* n) {
    std::cout << n->value << ", ";
}

int main(int argc, char** argv)
{

    // our tree
    /***********************
                    6
                   / \
                  /   \
                 /     \
                4       8
               / \     / \
              2   5   7   9
    ***********************/

    Node root(6,
        new Node(4,
            new Node(2),
            new Node(5)),
        new Node(8,
            new Node(7),
            new Node(9)));


    // Call our ForEach Method defined above,
    // Pass it the "PrintNode" method
    ForEachPreOrder(&root, PrintNode);

    // We can also pass in a lambda function
    // directly as a parameter

    /*
    ForEachDfsRecursive(&root, [](Node* n) {
    std::cout << n->value << ", ";
    });
    */

    return 0;

}
