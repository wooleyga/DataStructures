#ifndef _TREENODE_HPP_
#define _TREENODE_HPP_

#pragma once
#include <iostream>

class TreeNode {
public:
	TreeNode(int x);
	~TreeNode();
	int getHeight();
	int getNumberOfNodes();
	bool contains(int x);
	std::string preorderTraversal();
	std::string inorderTraversal();
	std::string postorderTraversal();
	bool isLeaf();
	bool isFull();
private:
	int max(int x, int y);
	int val;
	TreeNode *left, *right;
};

#endif