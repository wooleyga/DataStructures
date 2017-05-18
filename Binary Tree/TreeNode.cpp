#include "TreeNode.hpp"

TreeNode::TreeNode(int x) : val(x), left(NULL), right(NULL){}

TreeNode::~TreeNode()
{
	TreeNode *currentLeft, *currentRight;
	currentLeft = left;
	currentRight = right;
	delete left;
	delete right;
	if (currentLeft != NULL)
		currentLeft->~TreeNode();
	if (currentRight != NULL)
		currentRight->~TreeNode();
}

int TreeNode::getHeight()
{
	int leftHeight = 0, rightHeight = 0;
	if (left != NULL)
		leftHeight += (1 + left->getHeight());
	if (right != NULL)
		rightHeight += (1 + right->getHeight());

	return max(leftHeight, rightHeight);
}

int TreeNode::getNumberOfNodes()
{
	int count = 0;
	if (left != NULL)
		count += left->getNumberOfNodes();
	if (right != NULL)
		count += right->getNumberOfNodes();

	return count;
}

bool TreeNode::contains(int x)
{
	if (this->val == x)
		return true;
	if (left != NULL && left->contains(x))
		return true;
	if (right != NULL && right->contains(x))
		return true;

	return false;
}

std::string TreeNode::preorderTraversal()
{
	std::string traversal = this->val + " ";
	if (left != NULL)
		traversal += left->preorderTraversal();
	if (right != NULL)
		traversal += right->preorderTraversal();

	return traversal;
}

std::string TreeNode::inorderTraversal()
{
	std::string traversal = "";
	if (left != NULL)
		traversal += left->inorderTraversal();
	traversal += this->val + " ";
	if (right != NULL)
		traversal += right->inorderTraversal();

	return traversal;
}

std::string TreeNode::postorderTraversal()
{
	std::string traversal = "";
	if (left != NULL)
		traversal += left->postorderTraversal();
	if (right != NULL)
		traversal += right->postorderTraversal();
	traversal += this->val + " ";

	return traversal;
}

bool TreeNode::isLeaf()
{
	return left == NULL && right == NULL;
}

bool TreeNode::isFull()
{
	if (left == NULL && right == NULL)
		return true;
	if (left != NULL && right != NULL)
		return left->isFull() && right->isFull();
	return false;
}

int TreeNode::max(int x, int y)
{
	return (x >= y) ? x : y;
}
