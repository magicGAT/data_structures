/*
 * main.cpp
 *
 *  Created on: Nov 11, 2019
 *      Author: gregorytaylor
 */
#include <iostream>
#include <string>
#include <fstream>

#include "emp_data.h"

using namespace std;

void readData(string, EmployeeData[]);
int my_hash(int);
void tableOp(int, string, string, EmployeeData[]);
void tableList(EmployeeData[], int);
void tableQuery(EmployeeData[]);

int main()
{
	const int SIZE = 25;
	// PART 1

	EmployeeData our_hash[SIZE];
	readData("employee_data.txt", our_hash);

	// PART 2

	tableList(our_hash, SIZE);
	cout << endl;

	// PART 3

	tableQuery(our_hash);


	return 0;
}

// reads formatted data from a file, queries the hash table for each entry. If the
// data is original, places it in the table. If the data already exists, does not duplicate.
// Outputs a complete report. New entries are outputted in full, duplicates are noted and the
// name/key combinations is presented
void readData(string file_name, EmployeeData table[])
{
	string ss, first, last, garbage;
	int ss_key;

	ifstream inputFile(file_name);

	while (!inputFile.fail())
	{
		getline(inputFile, ss, '|');
		getline(inputFile, first, '0');
		getline(inputFile, garbage, '|');
		getline(inputFile, last, '0');
		getline(inputFile, garbage);

		ss_key = stoi(ss);

		tableOp(ss_key, first, last, table);

		if (garbage == "XXX")
			break;
	}
}

// basic hash function for key classification, ensures at least 2-3 collisions.
int my_hash(int key)
{
	int hashed;

	hashed = key % 100;

	return hashed;
}

// New records are added to the hash value (or chained if necessary)
void tableOp(int key, string name_1, string name_2, EmployeeData table[])
{
	// this may NEED to be a pointer
	EmployeeData * target;
	EmployeeData::LL view;

	int hashed_key;

	hashed_key = my_hash(key);

	target = &table[hashed_key];

	if (target -> SSN == 0)
	{
		target -> SSN = key;
		target -> f_name = name_1;
		target -> l_name = name_2;
	}

	else
	{
		target -> chain.push_back(key, name_1, name_2);
	}
}

// displays a readout of all hash table entries, the data within, and their chained record (if any exist)
void tableList(EmployeeData table[], int size)
{
	EmployeeData view;
	int i = 0;
	EmployeeData::LL * chain_view;
	EmployeeData::LL::node * node_view;

	cout << "--.HASH TABLE CONTENT REPORT.--" << endl;
	while (i < size)
	{
		view = table[i];

		cout << "Hash Table Entry " << i + 1 << ":" << endl;
		cout << "\tEmployee Name: " << view.f_name << " " << view.l_name << endl;
		cout << "\tEmployee SSN: " << view.SSN << endl;

		chain_view = &view.chain;

		if (chain_view -> header != nullptr)
		{
			view.chain.display_chain();
		}

		else
		{
			cout << "\tThis table position has no chained records" << endl;
		}

		i++;
	}
}

// allows the user to query individual keys (SSN) values and have the data associated
// with it displayed to the console
void tableQuery(EmployeeData table[])
{
	int query_SSN = 1, hashed_key;
	string first, last;
	EmployeeData sight;
	EmployeeData::LL chain_view;

	cout << "Welcome to the XCOM Employee Database" << endl;

	while (query_SSN != 0)
	{
		cout << "Please enter a Social Security Number and the database will be queried" << endl;

		cin >> query_SSN;

		if (query_SSN == 0)
		{
			break;
		}

		hashed_key = my_hash(query_SSN);

		sight = table[hashed_key];

		if (sight.SSN == 0)
		{
			cout << "Record not found, please try again" << endl;
			continue;
		}

		else
		{
			cout << "Record Found:" << endl;
		}
			chain_view = sight.chain;

			if (chain_view.header == nullptr)
			{
				cout << sight.f_name << " " << sight.l_name << endl;
			}

			else
			{
				chain_view.find_node(query_SSN);
			}
		}
}



