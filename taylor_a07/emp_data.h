/*
 * emp_data.h
 *
 *  Created on: Nov 11, 2019
 *      Author: gregorytaylor
 */

#ifndef EMP_DATA_H_
#define EMP_DATA_H_

#include <iostream>
#include <string>

using namespace std;

struct EmployeeData
{
	private:
	public:
		class LL
		{
			private:
			public:
				struct node
				{
					public:
						node * fwdPtr;
						int SSN;
						string f_name;
						string l_name;
				};
				node * header;
				void push_back(int, string, string);
				void find_node(int);
				void display_chain();
		};
		int SSN;
		string f_name;
		string l_name;
		LL chain;
		EmployeeData();
};

#endif /* EMP_DATA_H_ */
