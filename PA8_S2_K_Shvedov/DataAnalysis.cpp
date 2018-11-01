#include "DataAnalysis.h"
//empty constructor
DataAnalysis::DataAnalysis()
{

}
//empty destructor
DataAnalysis::~DataAnalysis()
{
	mCsvStream.close();
}

//runs the analisys application
void DataAnalysis::runAnalysis(void)
{
	openFile();
	readFile();
	writeTrends();
}

//opens the file stream
void DataAnalysis::openFile(void)
{
	mCsvStream.open("data.csv");
}

//reads one line from the file
void DataAnalysis::readLine(string &data, int &units, string &status)
{
	string temp;
	getline(mCsvStream, temp, ',');
	if (!temp.empty())
	{
		units = stoi(temp);
		getline(mCsvStream, data, ',');
		getline(mCsvStream, status, '\n');
	}
}

//loops through the file until end of file and then prints both trees out in order
void DataAnalysis::readFile(void)
{
	string tdata, tstatus;
	int tunits = 0;
	getline(mCsvStream, tdata);
	while (!mCsvStream.eof())
	{
		readLine(tdata, tunits, tstatus);
		insertIntoTrees(tdata, tunits, tstatus);
	}
	cout << "Sold Tree" << endl;
	mTreeSold.inOrderTraversal();
	cout << endl << "Purchased Tree" << endl;
	mTreePurchased.inOrderTraversal();
}

//checks data and inserts in the right tree
void DataAnalysis::insertIntoTrees(string data, int units, string status)
{
	if (status == "Sold")
	{
		mTreeSold.insert(data, units);
	}
	else if (status == "Purchased")
	{
		mTreePurchased.insert(data, units);
	}
}

//writes the trends from the trees
void DataAnalysis::writeTrends(void)
{
	cout << endl << "Least Sold" << endl;
	mTreeSold.findSmallest().printData();
	cout << "Most Sold" << endl;
	mTreeSold.findLargest().printData();
	cout << endl << endl << "Least Purchased" << endl;
	mTreePurchased.findSmallest().printData();
	cout << "Most Purchased" << endl;
	mTreePurchased.findLargest().printData();
}