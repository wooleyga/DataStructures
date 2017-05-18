#include "BinaryTree.hpp"

BinaryTree::BinaryTree() : root(NULL){}

BinaryTree::~BinaryTree()
{
	root->~TreeNode();
}

int BinaryTree::getHeight()
{
	return root->getHeight();
}

int BinaryTree::getNumberOfNodes()
{
	return root->getNumberOfNodes();
}

bool BinaryTree::contains(int x)
{
	return root->contains(x);
}

std::string BinaryTree::preorderTraversal()
{
	return root->preorderTraversal();
}

std::string BinaryTree::inorderTraversal()
{
	return root->inorderTraversal();
}

std::string BinaryTree::postorderTraversal()
{
	return root->postorderTraversal();
}

bool BinaryTree::isFull()
{
	return root->isFull();
}
