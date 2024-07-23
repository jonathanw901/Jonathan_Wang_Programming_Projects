// Driver Program
//
// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// Jonathan Wang & Omar Daas

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "TreeNode.h"
#include "BinarySearchTree.h"
#include "RedBlackTree.h"

int main() {
	// declare red black tree
	RedBlackTree* tree1 = new RedBlackTree();
	// read in data
	std::ifstream input("data.txt");
	std::string reader("");
	if (input.is_open()) {
		while (std::getline(input, reader, ' ')) {
			std::cout << reader << " ";
			tree1->insert(stoi(reader));
		}
	}
	input.close();
	
	std::cout << "\n";

	std::cout << "Root: " + std::to_string(tree1->getRoot()->getData()) + " and it's Color is " + tree1->getRoot()->getColor() << "\n";

	std::cout << "Inorder Red Nodes: ";
	tree1->printRedNodes(tree1->getRoot());
	std::cout << "\n";
	
	std::cout << "Preorder Black Nodes: ";
	tree1->printBlackNodes(tree1->getRoot());
	std::cout << "\n";

	std::cout << "Height: " + std::to_string(tree1->getHeight(tree1->getRoot())) << "\n";

	delete tree1;

	return 0;
}