#ifndef BST_H
#define BST_H

/*
* Programmer: Konstantin Shvedov
* Class: CptS 122
* Programming Assignment: PA6
* Date: 25/10/2017
* Description: This is the header file with all BST functions
*/

#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

#include "TransactionNode.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::noskipws;
using std::istream;
using std::ostream;
using std::ofstream;
using std::ifstream;

class BST
{
public:
	//constructor
	BST();
	//destructor
	~BST();

	//getter
	Node *& getRootPtr(void);

	//setter
	void setRootPtr(Node *const pNewRoot);

	//checks if the Tree is empty
	bool isEmpty(void);

	//prints the BST in order
	void inOrderTraversal();

	//inserting 
	void insert(string const data, int const units);

	//finds a transaction node with the smallest mUnits
	TransactionNode & findSmallest(void);

	//finds a transaction node with the largest mUnits
	TransactionNode & findLargest(void);

private:
	Node *mpRoot;

	//inserting 
	void insert(Node *&node, string const data, int const units);

	//traverses the tree
	void inOrderTraversal(Node *node);

	//helper destructor for BST
	void destroyTreeHelper(Node * const pMem);

	//detsructor for node
	void destroyTree(void);
};
#endif