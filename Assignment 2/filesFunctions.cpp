/*
*	File:	filesFunctions.cpp
*	Author:	Ventura Lucena Martínez
*	Email:	i72lumav@uco.es
*/

#include "filesFunctions.hpp"
#include <fstream>

using namespace std;

void saveToFile(const vector<double> &n, const vector<double> &t, const string file_name)
{
	ofstream my_file;
	my_file.open(file_name);
	my_file << "n" << "\t" << "Real" << endl;

	for (int i = 0; i < t.size(); i++)
	{
		if(i == t.size() - 1)
			my_file << n[i] << "\t" << t[i];
		else
			my_file << n[i] << "\t" << t[i] << endl;
	}
	my_file.close();	
}

void saveToFile(const vector<double> &n, const vector<double> &t1, const vector <double> &t2, const string file_name)
{
	ofstream my_file;
	my_file.open(file_name);
	my_file << "n" << "\t" << "Real" << "\t" << "Estimated" << endl;

	for (int i = 0; i < t1.size(); i++)
	{
		if(i == t1.size() - 1)
			my_file << n[i] << "\t" << t1[i] << "\t" << t2[i];
		else
			my_file << n[i] << "\t" << t1[i] << "\t" << t2[i] << endl;
	}
	my_file.close();
}

void saveToFile(const vector<double> &n, const vector<double> &t1, const vector <double> &t2, const vector <double> &t3, const string file_name)
{
	ofstream my_file;
	my_file.open(file_name);
	my_file << "n" << "\t\t" << "Method 1" << "\t\t" << "Method 2" << "\t\t" << "Method 3" << endl;

	for (int i = 0; i < t1.size(); i++)
	{
		if(i == t1.size() - 1)
			my_file << n[i] << "\t\t" << t1[i] << "\t\t\t" << t2[i] << "\t\t\t" << t3[i];
		else
			my_file << n[i] << "\t\t" << t1[i] << "\t\t\t" << t2[i] << "\t\t\t" << t3[i] << endl;
	}
	my_file.close();
}