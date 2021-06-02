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
	if (value > n->value) return Find(n->right, value);
	else if (value < n->value) return Find(n->left, value);
	return n;
}

void Insert(Node* root, Node* nodeToInsert)
{
	auto InsertValue = nodeToInsert->value;
	int rootValue = root->value;

	//checks right side
	if (InsertValue > rootValue) {
		if (root->right != nullptr) {
			Insert(root->right, nodeToInsert);
		}
		else //creates the right node
			root->right = nodeToInsert;
	}
	//checks left side
	else if (InsertValue < rootValue) {
		if (root->left != nullptr) {
			Insert(root->left, nodeToInsert);
		}
		else //creates the left node
			root->left = nodeToInsert;
	}
}

void Remove(int value, Node* root, Node* nodeToRemove)
{
	// TODO
	//if the value is the root
	if (nodeToRemove->value == value) {
		Node* ntr = root;
		root = nodeToRemove->right;
		Insert(nodeToRemove->left, root);
		delete ntr;
	}

	if (nodeToRemove->left->value == value) {
		Node* ntd = nodeToRemove->left;
		nodeToRemove->left = nullptr;
		Insert(ntd->left, root);
		Insert(ntd->right, root);
		delete ntd;
	}

	else if (nodeToRemove->right->value == value) {
		Node* ntd = nodeToRemove->right;
		nodeToRemove->right = nullptr;
		Insert(ntd->left, root);
		Insert(ntd->right, root);
		delete ntd;
	}

	else if (value < nodeToRemove->value) {
		Remove(value, nodeToRemove->left, root);
	}

	else if (value > nodeToRemove->value) {
		Remove(value, nodeToRemove->right, root);
	}
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


//void ForEachDfs(Node* root, std::function<void(Node*)> fn)
//{
//	// Create the stack
//	std::list<Node*> stack;
//
//	// add first node to the stack
//	stack.push_back(root);
//
//	// while stack is not empty
//	while (stack.empty() == false)
//	{
//		// remove the next node
//		Node* n = stack.back();
//		stack.pop_back();
//
//		// process the node
//		fn(n);
//
//		// add children to the stack
//		if (n->right) stack.push_back(n->right);
//		if (n->left) stack.push_back(n->left);
//	}
//}


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
	Node root(6);

	Insert(&root, new Node(4));
	Insert(&root, new Node(2));
	Insert(&root, new Node(5));
	Insert(&root, new Node(8));
	Insert(&root, new Node(7));
	Insert(&root, new Node(9));


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

	//displays a value if it can find it
	std::cout << std::endl;
	auto f = Find(new Node(root), 9);
	PrintNode(f);
	std::cout << std::endl;

	//displays new list after removing 4
	Remove(4, &root, new Node(4));
	std::cout << std::endl;
	PrintNode(f);
	std::cout << std::endl;

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
