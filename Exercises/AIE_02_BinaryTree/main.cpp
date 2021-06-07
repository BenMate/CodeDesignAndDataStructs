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

	PostOrderPrint(n->left);
	PostOrderPrint(n->right);

	std::cout << n->value << std::endl;
}


Node* Find(Node* n, int value)
{
	if (n == nullptr) return nullptr;
	if (value > n->value) return Find(n->right, value);
	else if (value < n->value) return Find(n->left, value);
	return n;
}

void Insert(Node*& node, Node* nodeToInsert)
{	
	if (node == nullptr) 
		node = nodeToInsert;
	if (node->value < nodeToInsert->value) 
		Insert(node->right, nodeToInsert);
	if (node->value > nodeToInsert->value) 
		Insert(node->left, nodeToInsert);
}

void Remove(Node* root, int value) {
	Node* parent = nullptr;
	Node* nodeToRemove = Find(parent,value);
	if (nodeToRemove == nullptr) return;

	if (parent == nullptr) root = nullptr;
	else if (parent->left == nodeToRemove) parent->left = nullptr;
	else if (parent->right == nodeToRemove) parent->right = nullptr;

	Insert(root, nodeToRemove->left);
	Insert(root, nodeToRemove->right);
	delete nodeToRemove;
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
	if (n == nullptr) {
		std::cout << "Item not found: " << std::endl;
	}
	else {
		std::cout << n->value << ", ";
	}
}

int main(int argc, char** argv)
{
	Node *root = nullptr;
	Insert(root, new Node(6));
	Insert(root, new Node(8));
	
	auto find = Find(root,8);
	std::cout << find->value << std::endl;

	Remove(root, 8);

	//auto f = Find(new Node(*root), 4);
	//PrintNode(f);


	// Call our ForEach Method defined above,
	// Pass in the "PrintNode" method
	ForEachPreOrder(root, PrintNode);

	// our tree Becomes
	/***********************
			      6
				 / \
				/   \
		       /     \
		      4       8
			 / \     / \
			2   5   7   9
	*************************/

	/*We can also pass in a lambda function
	 directly as a parameter

	ForEachDfsRecursive(&root, [](Node* n) {
	std::cout << n->value << ", ";

	});
	*/
	
	return 0;
}
