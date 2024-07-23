// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// Jonathan Wang & Omar Daas

#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree():root_(nullptr){
	
}
BinarySearchTree::~BinarySearchTree(){
	if(root_!=nullptr){
		delete root_;
	}
}
TreeNode * BinarySearchTree::getRoot(){
	return root_;
}
void BinarySearchTree::insert(int value){
	TreeNode * node = new TreeNode(value);
	
	root_ = insertNode(root_, node);
}

TreeNode* BinarySearchTree::insertNode(TreeNode * root, TreeNode * newNode){
	if (root == nullptr) {
		return newNode;
	}
	else {
		if (newNode->getData() < root->getData()) {
			//Left subtree
			root->setLeftChild(insertNode(root->getLeftChild(), newNode));
			root->getLeftChild()->setParent(root);
		}
		else {
			//Right subtree
			root->setRightChild(insertNode(root->getRightChild(), newNode));
			root->getRightChild()->setParent(root);
		}

		return root;
	}
}

void BinarySearchTree::printTree(TreeNode* root){
	//In-order Traversal
	if (root == nullptr) {
		return;
	}
	else {
		printTree(root->getLeftChild());
		std::cout << root->getData()<<" ";
		printTree(root->getRightChild());
	}
}

int BinarySearchTree::getHeight(TreeNode* root){
    if (root == NULL)
        return 0;
    else {
        /* compute the height of each subtree */
        int lHeight = getHeight(root->getLeftChild());
        int rHeight = getHeight(root->getRightChild());
 
        /* use the taller one */
        if (lHeight > rHeight)
            return (lHeight + 1);
        else
            return (rHeight + 1);
    }
}