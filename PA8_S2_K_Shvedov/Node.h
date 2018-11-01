#ifndef NODE_H
#define NODE_H

/*
* Programmer: Konstantin Shvedov
* Class: CptS 122
* Programming Assignment: PA6
* Date: 25/10/2017
* Description: This is the header file for Node
*/

#include <iostream>
#include <fstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;
using std::ofstream;
using std::ifstream;
using std::string;

class Node
{
public:
	Node(string newSymb = "");
	virtual ~Node();

	string getData() const;
	Node *&getPLeft();
	Node *&getPRight();

	void setData(const string newCont);
	void setPLeft(Node *const newPLeft);
	void setPRight(Node *const newPRight);

	virtual void printData() = 0;

protected:
	string mData;
	Node *mpLeft;
	Node *mpRight;
};

#endif