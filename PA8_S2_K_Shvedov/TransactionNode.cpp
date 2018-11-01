#include "TransactionNode.h"

//transaction node constructor
TransactionNode::TransactionNode(string newData, int newUnits) : Node(newData)
{
	mUnits = newUnits;
}

//constructor node destructor
TransactionNode::~TransactionNode()
{
	//INSIDE THE MAGNIFICENT Node DESTRUCTOR
}

//getts units from the transaction node
int TransactionNode::getCont() const
{
	return mUnits;
}

//sets units within the transaction node
void TransactionNode::setCont(const int newCont)
{
	mUnits = newCont;
}

//prints data and units to screen
void TransactionNode::printData()
{
	cout << mData << ": " << mUnits << endl;
}