// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// Jonathan Wang & Omar Daas

#include "RedBlackTree.h"

RedBlackTree::RedBlackTree():root_(nullptr){
	
}
RedBlackTree::~RedBlackTree(){
	if(root_!=nullptr){
		delete root_;
	}
}
TreeNode * RedBlackTree::getRoot(){
	return root_;
}
void RedBlackTree::insert(int value){
	TreeNode * node = new TreeNode(value);
	
	root_ = insertNode(root_, node);

	if(node == root_)
	{
		node->setColor("BLACK");
	}
	else
	{
		node->setColor("RED");
		balanceColor(root_, node);
	}
}

TreeNode* RedBlackTree::insertNode(TreeNode * root, TreeNode * newNode){
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

void RedBlackTree::printTree(TreeNode* root){
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

int RedBlackTree::getHeight(TreeNode* root){
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

void RedBlackTree::printRedNodes(TreeNode * root)
{
	// Base Case
	if (root == nullptr)
	{
		return;
	}
	
	// Print Left Subtree
	printRedNodes(root->getLeftChild());
	
	// Print Root
	if (root->getColor().compare("RED")==0)
	{
		std::cout << root->getData() << " ";
	}
	
	// Print Right Subtree	
	printRedNodes(root->getRightChild());
}

void RedBlackTree::printBlackNodes(TreeNode * root)
{
	// Base Case
	if (root == nullptr)
	{
		return;
	}
	
	// Print Root
	if (root->getColor().compare("BLACK")==0)
	{
		std::cout << root->getData() << " ";
	}

	// Print Left Subtree
	printBlackNodes(root->getLeftChild());
	
	// Print Right Subtree	
	printBlackNodes(root->getRightChild());
}



void RedBlackTree::rotateLeft(TreeNode*& root, TreeNode*& newNode) {
	//  1\           
	//    2\   ->   /2\
	//     3       1   3

	TreeNode* temp = newNode->getRightChild();
	newNode->setRightChild(temp->getLeftChild());
	if (temp->getLeftChild() != nullptr) {
		temp->getLeftChild()->setParent(newNode);
	}
	temp->setParent(newNode->getParent());
	if (newNode->getParent() == nullptr) {
		root_ = temp;
	}else if (newNode == newNode->getParent()->getLeftChild()) {
		newNode->getParent()->setLeftChild(temp);
	}else {
		newNode->getParent()->setRightChild(temp);
	}
	temp->setLeftChild(newNode);
	newNode->setParent(temp);
}

void RedBlackTree::rotateRight(TreeNode*& root, TreeNode*& newNode) {
	//   /3				  5\
	//  /2  -> /2\   or	   /7
	// 1      1   3		  6
	TreeNode* temp = newNode->getLeftChild();
	newNode->setLeftChild(temp->getRightChild());
	if (temp->getRightChild() != nullptr){
		temp->getRightChild()->setParent(newNode);
	}
	temp->setParent(newNode->getParent());
	if (newNode->getParent() == nullptr){
		root_ = temp;
	}else if (newNode == newNode->getParent()->getRightChild()){
		newNode->getParent()->setRightChild(temp);
	}else{
		newNode->getParent()->setLeftChild(temp);
	}
	temp->setRightChild(newNode);
	newNode->setParent(temp);
}


void RedBlackTree::balanceColor(TreeNode*& root, TreeNode*& newNode) {
	// root_ must be black
	// no red can have red kids or parents

	//runs until returns to root_
	while (newNode != root && newNode->getParent()->getColor().compare("RED") == 0) {
		//checks if gParent is right or left child
		if (newNode->getParent() == newNode->getParent()->getParent()->getLeftChild()) {//gParent in left child
			TreeNode* uncle = newNode->getParent()->getParent()->getRightChild();

			//check if uncles exists and is red
			if (uncle != nullptr && uncle->getColor().compare("RED") == 0) {
				//newNode, uncle, and gParent flip
				newNode->getParent()->setColor("BLACK");
				uncle->setColor("BLACK");
				newNode->getParent()->getParent()->setColor("RED");
				newNode = newNode->getParent()->getParent();
			}else {//no uncle, or uncle black, thus ignore
				//check if newNode needs to be rotated
				if (newNode == newNode->getParent()->getRightChild()) {
					newNode = newNode->getParent();
					rotateLeft(root,newNode);
				}
				//set colors and rotate
				newNode->getParent()->setColor("BLACK");
				newNode->getParent()->getParent()->setColor("RED");
				TreeNode* temp = newNode->getParent()->getParent();
				rotateRight(root, temp);
			}
		}else {//gParent is right child
			TreeNode* uncle = newNode->getParent()->getParent()->getLeftChild();
			if (uncle != nullptr && uncle->getColor().compare("RED") == 0) {//uncle check
				//flip subtree colors
				newNode->getParent()->setColor("BLACK");
				uncle->setColor("BLACK");
				newNode->getParent()->getParent()->setColor("RED");
				newNode = newNode->getParent()->getParent();
			}else {//uncle DNE or is black, thus ignore
				if (newNode == newNode->getParent()->getLeftChild()) {//rotate check
					newNode = newNode->getParent();
					rotateRight(root,newNode);
				}
				//set colors and final rotation
				newNode->getParent()->setColor("BLACK");
				newNode->getParent()->getParent()->setColor("RED");
				TreeNode* temp = newNode->getParent()->getParent();
				rotateLeft(root, temp);
			}
		}
	}
	//1. Root must always be black
	root->setColor("BLACK");
}