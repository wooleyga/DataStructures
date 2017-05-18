#ifndef _BINARYTREE_HPP_
#define _BINARYTREE_HPP_

#pragma once
#include "TreeNode.hpp"

class BinaryTree {
public:
	BinaryTree();
	~BinaryTree();
	virtual void add(int x) = 0;
	int getHeight();
	int getNumberOfNodes();
	bool contains(int x);
	std::string preorderTraversal();
	std::string inorderTraversal();
	std::string postorderTraversal();
	bool isFull();
private:
	TreeNode* root;
};

#endif