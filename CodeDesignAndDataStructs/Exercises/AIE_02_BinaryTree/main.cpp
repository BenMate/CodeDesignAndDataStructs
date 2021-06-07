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
	else if (nodeToInsert->value > node->value )
		Insert(node->right, nodeToInsert);
	else if (nodeToInsert->value < node->value)
		Insert(node->left, nodeToInsert);
}


Node* MinValue(Node*& node) {
	
	Node* currentNode = node;
	while (currentNode && currentNode->left != nullptr)
	{
		currentNode = currentNode->left;
	}
	return currentNode;
	}



Node* Remove(Node* root, Node* node) {
	
	if (node == nullptr) return nullptr;

	if (node->value < root->value)
		root->left = Remove(root->left, node);
	else if (node->value > root->value)
		root->right = Remove(root->right, node);
	else {
		if (root->left == nullptr) {
			Node* tempNode = root->right;
			return tempNode;
		}
		else if (root->right == nullptr) {
			Node* tempNode = root->left;
			return tempNode;
		}
		Node* temp = MinValue(root->right);
		root->value = temp->value;
		root->right = Remove(root->right, temp);
	}
	return root;
}

int Height(Node* root)
{
	if (root == nullptr) return 0;
	
	int heightLeft = Height(root->left);
	int heightRight = Height(root->right);

	if (heightLeft > heightRight) {	
		return heightLeft + 1;
	}
	else {
		return heightLeft + 1;
	}
}




int Depth(Node* root, Node* n)
{
	// TODO

	//mabybe....root goes down till we reach n value then return the count.

	//maybe count each height until we reach target reset count then continue the count return the final number???


	if (root == nullptr) return 0;

	int DepthRight = Depth(root->right,n->right);
	int DepthLeft = Depth(root->left,n->left);

	if (DepthLeft > DepthRight) {
		return DepthLeft + 1;
	}
	if (DepthRight > DepthLeft) {
		return DepthRight+1;
	}
	
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
	if (n == nullptr) 
		std::cout << "Item not found: " << std::endl;	
	else 
		std::cout << n->value << ", ";
}

int main(int argc, char** argv)
{
	Node *root = nullptr;
	Insert(root, new Node(6));
		Insert(root, new Node(4));
		Insert(root, new Node(2));
		Insert(root, new Node(5));
	Insert(root, new Node(8));
		Insert(root, new Node(7));
		Insert(root, new Node(9)); 

	ForEachPreOrder(root, PrintNode);

	std::cout << std::endl;

	Remove(root, Find(root,8)); 
	ForEachPreOrder(root, PrintNode);

	std::cout << std::endl;

	auto f = Find(new Node(*root), 9);
	std::cout << "Found: "; PrintNode(f);

	std::cout << std::endl;
	std::cout << "Height: " <<  Height(root);

	std::cout << std::endl;
	std::cout << "Depth: " << Depth(root,Find(root,9));

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

	return 0;
}
