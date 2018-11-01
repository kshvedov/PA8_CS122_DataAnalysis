#include "Node.h"

//Node Constructor
Node::Node(string newData)
{
	mData = newData;
	mpRight = nullptr;
	mpLeft = nullptr;
}

//Node detructor
Node::~Node()
{
	//INSIDE THE MAGNIFICENT Node DESTRUCTOR
}

//-------------------------------------------------------------------------------//
//------------------------------------GETTERS------------------------------------//
//-------------------------------------------------------------------------------//
//gets the data stored inside node
string Node::getData() const
{
	if (this == NULL)
	{
		cout << "NULL NODE ENCOUNTERED" << endl;
	}
	else return mData;
}
//getter for left pointer
Node *& Node::getPLeft()
{
	if (this == NULL)
	{
		cout << "NULL NODE ENCOUNTERED" << endl;
	}
	else return mpLeft;
}
//getter for right pointer
Node *& Node::getPRight()
{
	if (this == NULL)
	{
		cout << "NULL NODE ENCOUNTERED" << endl;
	}
	else return mpRight;
}

//-------------------------------------------------------------------------------//
//------------------------------------SETTERS------------------------------------//
//-------------------------------------------------------------------------------//
//sets the data within the node to the new one
void Node::setData(const string newCont)
{
	this->mData = newCont;
}
//sets the left pointer to the new one
void Node::setPLeft(Node *const newPLeft)
{
	this->mpLeft = newPLeft;
}
//sets the right pointer to the new one
void Node::setPRight(Node *const newPRight)
{
	this->mpRight = newPRight;
}