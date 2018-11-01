#include "BST.h"

//constructor
BST::BST()
{
	mpRoot = nullptr;
}

//destructor
BST::~BST()
{
	//cout << endl << "Inside BST's destructor! Freeing each Node in the BST!" << endl;
	destroyTree();
	//cout << "Target OBLITERATED" << endl;
}

//returns the root
Node *& BST::getRootPtr()
{
	return mpRoot;
}

//sets the root
void BST::setRootPtr(Node *const pNewRoot)
{
	mpRoot = pNewRoot;
}

//checks if tree is empty
bool BST::isEmpty()
{
	if (this->mpRoot == nullptr)
	{
		return true;
	}
	else return false;
}

//in order traversal by calling protected function
void BST::inOrderTraversal()
{
	inOrderTraversal(mpRoot);
}

//in order traversal of tree (protected version)
void BST::inOrderTraversal(Node *node)
{
	if (node == nullptr)
	{
		//Base case nothing to print
	}
	else
	{
		inOrderTraversal(node->getPLeft());
		(dynamic_cast <TransactionNode*>(node)->printData());
		inOrderTraversal(node->getPRight());
	}
}


//inserts node by calling protected function
void BST::insert(string const data, int const units)
{
	insert(mpRoot, data, units);
}

//inserts node (protected version)
void BST::insert(Node *&node, string const data, int const units)
{
	if (node == nullptr)
	{
		Node *newNode = new TransactionNode(data, units);
		node = newNode;
	}
	else if ((dynamic_cast <TransactionNode*>(node))->getCont() < units)
	{
		insert(node->getPRight(), data, units);
	}
	else if ((dynamic_cast <TransactionNode*>(node))->getCont() > units)
	{
		insert(node->getPLeft(), data, units);
	}
	else
	{
		//identical node, no point in inserting
	}
}

//finds a transaction node with the smallest mUnits
TransactionNode & BST::findSmallest(void)
{
	Node *tsmall = mpRoot;
	TransactionNode *temp;
	while (tsmall->getPLeft() != nullptr)
	{
		tsmall = tsmall->getPLeft();
	}
	temp = (dynamic_cast <TransactionNode*>(tsmall));
	return *temp;
}

//finds a transaction node with the largest mUnits
TransactionNode & BST::findLargest(void)
{
	Node *tlarge = mpRoot;
	TransactionNode *temp;
	while (tlarge->getPRight() != nullptr)
	{
		tlarge = tlarge->getPRight();
	}
	temp = (dynamic_cast <TransactionNode*>(tlarge));
	return *temp;
}

//destroys the tree
void BST::destroyTree()
{
	destroyTreeHelper(mpRoot);
}

//helper destructor for BST
void BST::destroyTreeHelper(Node * node)
{
	if (node != nullptr)
	{
		destroyTreeHelper(node->getPLeft());
		destroyTreeHelper(node->getPRight());
		delete node;
		//out << "Deleted A Node" << endl;
	}
}