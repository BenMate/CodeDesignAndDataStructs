

#include "BinaryTree.h"
#include "TreeNode.h"
#include "raylib.h"
#include <iostream>
#include <cstdlib>


BinaryTree::BinaryTree()
{
	m_pRoot = nullptr;
}

BinaryTree::~BinaryTree()
{
	while (m_pRoot)
	{
		Remove(m_pRoot->GetData());
	}
}

// Return whether the tree is empty
bool BinaryTree::IsEmpty() const
{
	return (m_pRoot == nullptr);
}

// Insert a new element into the tree.
// Smaller elements are placed to the left, larger onces are placed to the right.
void BinaryTree::Insert(int a_nValue)
{
	TreeNode* nodeToInsert = new TreeNode(a_nValue);
	Insert(m_pRoot, nodeToInsert);
}

void BinaryTree::Insert(TreeNode*& node, TreeNode* nodeToInsert)
{
	if (node == nullptr)
		node = nodeToInsert;
	else if (nodeToInsert->GetData() > node->GetData())
		Insert(node->GetRight(), nodeToInsert);
	else if (nodeToInsert->GetData() < node->GetData())
		Insert(node->GetLeft(), nodeToInsert);
}

TreeNode* BinaryTree::Find(int a_nValue)
{
	return FindNode(m_pRoot, a_nValue);
}

TreeNode* BinaryTree::FindNode(TreeNode* n, int a_nValue)
{
	if (n == nullptr) return nullptr;
	if (a_nValue > n->GetData()) return FindNode(n->GetRight(), a_nValue);
	else if (a_nValue < n->GetData()) return FindNode(n->GetLeft(), a_nValue);
	return n;
}

TreeNode* BinaryTree::GetMin(TreeNode*& node) {

	TreeNode* currentNode = node;
	while (currentNode->GetLeft() != nullptr)
	{
		currentNode = currentNode->GetLeft();
	}
	return currentNode;
}

void BinaryTree::Remove(int a_nValue)
{
	Remove(m_pRoot, Find(a_nValue));
}

TreeNode* BinaryTree::Remove(TreeNode* root, TreeNode* nodeToRemove) {
	//checks if empty
	if (nodeToRemove == nullptr) return nullptr;

	//checks root 
	if (m_pRoot->GetData() == nodeToRemove->GetData())
	{
		if (m_pRoot->GetLeft() == nullptr)
			m_pRoot = m_pRoot->GetRight();
		else if (m_pRoot->GetRight() == nullptr)
			m_pRoot = m_pRoot->GetLeft();
		else if (m_pRoot->GetLeft() == nullptr && m_pRoot->GetRight() == nullptr)
			m_pRoot = nullptr;
	}

	//checks left
	if (nodeToRemove->GetData() < root->GetData())
		root->SetLeft(Remove(root->GetLeft(), nodeToRemove));
	//checks right
	else if (nodeToRemove->GetData() > root->GetData())
		root->SetRight(Remove(root->GetRight(), nodeToRemove));

	//once the nodeToRemove = the root we get here
	else {
		//if the child on the left is empty
		if (root->GetLeft() == nullptr) {
			TreeNode* tempNode = root->GetRight();
			return tempNode;
		}
		//if the child on the right is empty
		else if (root->GetRight() == nullptr) {
			TreeNode* tempNode = root->GetLeft();
			return tempNode;
		}
		
		TreeNode* temp = GetMin(root->GetRight());
		root->GetData() = temp->GetData();
		root->GetRight() = Remove(root->GetRight(), temp);
	}
	return root;
}

void BinaryTree::PrintOrdered()
{
	PrintOrderedRecurse(m_pRoot);
	std::cout << std::endl;
}

void BinaryTree::PrintOrderedRecurse(TreeNode* pNode)
{

}

void BinaryTree::PrintUnordered()
{
	PrintUnorderedRecurse(m_pRoot);
	std::cout << std::endl;
}

void BinaryTree::PrintUnorderedRecurse(TreeNode* pNode)
{

}

void BinaryTree::Draw(TreeNode* selected)
{
	Draw(m_pRoot, 400, 40, 400, selected);
}

void BinaryTree::Draw(TreeNode* pNode, int x, int y, int horizontalSpacing, TreeNode* selected)
{

	horizontalSpacing /= 2;

	if (pNode)
	{
		if (pNode->HasLeft())
		{
			DrawLine(x, y, x - horizontalSpacing, y + 80, RED);

			Draw(pNode->GetLeft(), x - horizontalSpacing, y + 80, horizontalSpacing, selected);
		}

		if (pNode->HasRight())
		{
			DrawLine(x, y, x + horizontalSpacing, y + 80, RED);

			Draw(pNode->GetRight(), x + horizontalSpacing, y + 80, horizontalSpacing, selected);
		}

		pNode->Draw(x, y, (selected == pNode));
	}
}