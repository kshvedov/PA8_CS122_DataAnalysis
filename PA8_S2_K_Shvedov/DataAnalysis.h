#ifndef DataAnalysis_H
#define DataAnalysis_H

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

#include "BST.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::noskipws;
using std::istream;
using std::ostream;
using std::ofstream;
using std::ifstream;

class DataAnalysis
{
public:
	DataAnalysis();
	~DataAnalysis();

	void runAnalysis(void);

private:
	BST mTreeSold;
	BST mTreePurchased;
	ifstream mCsvStream;

	void openFile(void);
	void readLine(string &data, int &units, string &status);
	void readFile(void);
	void insertIntoTrees(string data, int units, string status);
	void writeTrends(void);
};
#endif