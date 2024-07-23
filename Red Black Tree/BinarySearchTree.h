// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// Jonathan Wang & Omar Daas

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include "TreeNode.h"
#include <iostream>

class BinarySearchTree
{
public:
	BinarySearchTree();
	virtual ~BinarySearchTree();
	virtual TreeNode* getRoot();
	virtual void insert(int value);
	virtual void printTree(TreeNode* root);
	virtual int getHeight(TreeNode* root);
private:
	TreeNode* insertNode(TreeNode* root, TreeNode* node);
	TreeNode* root_;
};

#endif