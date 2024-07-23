// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// Jonathan Wang & Omar Daas

#ifndef TREENODE_H
#define TREENODE_H

#include <string>

class TreeNode{
	public:
		TreeNode();
		TreeNode(int data);
		~TreeNode();
		void setParent(TreeNode * parent);
		void setLeftChild(TreeNode * leftChild);
		void setRightChild(TreeNode * rightChild);
		void setColor(std::string color);
		TreeNode * getLeftChild();
		TreeNode * getRightChild();
		TreeNode * getParent();
		int getData();
		std::string getColor();
	private:
		TreeNode * leftChild_;
		TreeNode * rightChild_;
		TreeNode * parent_;
		int data_;
		std::string color_;
};

#endif