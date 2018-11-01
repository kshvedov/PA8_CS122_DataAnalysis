#ifndef TRANSACTIONNODE_H
#define TRANSACTIONNODE_H

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

#include "Node.h"

using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;
using std::ofstream;
using std::ifstream;
using std::string;

class TransactionNode: public Node
{
public:
	TransactionNode(string newData = "", int newUnits = 0);
	~TransactionNode();

	int getCont() const;

	void setCont(const int newCont);

	void printData();

private:
	int mUnits;
};

#endif