// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// Jonathan Wang & Omar Daas

#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H
#include "TreeNode.h"
#include "BinarySearchTree.h"
#include <iostream>

class RedBlackTree: public BinarySearchTree
{
public:
	RedBlackTree();
	~RedBlackTree();
	TreeNode* getRoot();
	void insert(int value);
	void printTree(TreeNode* root);
	int getHeight(TreeNode* root);
	void printRedNodes(TreeNode * root);
	void printBlackNodes(TreeNode * root);
private:
	TreeNode* insertNode(TreeNode* root, TreeNode* node);
	void balanceColor(TreeNode *& root, TreeNode *& newNode);
	void rotateLeft(TreeNode *& root, TreeNode *& newNode);
	void rotateRight(TreeNode *& root, TreeNode *& newNode);
	TreeNode* root_;
};

#endif