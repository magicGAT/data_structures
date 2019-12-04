/*
 * emp_data_functions.cpp
 *
 *  Created on: Nov 11, 2019
 *      Author: gregorytaylor
 */
#include <iostream>
#include <string>

#include "emp_data.h"

using namespace std;

// employee data hash table constructor
EmployeeData::EmployeeData()
{
	SSN = 0;
	f_name = "";
	l_name = "";
	chain.header = nullptr;
}

void EmployeeData::LL::push_back(int key, string first, string last)
{
	node * temp, * new_node;

	new_node = new node;
	new_node -> fwdPtr = nullptr;

	new_node -> SSN = key;
	new_node -> f_name = first;
	new_node -> l_name = last;

	temp = header;
	if (temp == nullptr)
	{
		header = new_node;
	}

	else
	{
		while (temp -> fwdPtr != nullptr)
		{
			temp = temp -> fwdPtr;
		}

		temp -> fwdPtr = new_node;
	}

}

void EmployeeData::LL::find_node(int key)
{
	node * temp;

	temp = header;

	while (temp -> SSN != key)
	{
		temp = temp -> fwdPtr;
	}

	cout << temp -> f_name << " " << temp -> l_name << endl;
	return;
}

void EmployeeData::LL::display_chain()
{

	node * temp;

	temp = header;

	cout << "chain - " << temp -> SSN << " " << temp -> f_name << " " << temp -> l_name << endl;

	while (temp -> fwdPtr != nullptr)
	{
		temp = temp -> fwdPtr;
		cout << "chain - " << temp -> SSN << " " << temp -> f_name << temp -> l_name << endl;
	}

	return;
}





