/*
 * main.cpp
 *
 *  Created on: Nov 19, 2019
 *      Author: gregorytaylor
 */
#include <iostream>
#include <string>
#include "g_heaps.h"

using namespace std;

int main()
{
	int low, high;
	low = 0;			// low array index
	high = 99;			// high array index
	bool b;
	int list[100];
	string p ="CS20/a81data.txt";
	cout << "main: building first array (from a81data.txt)" << endl;
	buildArray (list, 100, p);
	cout << "main: displaying first array" << endl;
	displayArray (list, low, high);
	cout << endl;
	b=checkIfHeap (list, low, high);
	if (b)
		cout << "main: the first array is already a heap" << endl << endl;
	else
		cout << "main: the first array is not a heap" << endl << endl;
	cout << "main: now building heap" << endl;
	buildHeap (list, low, high);
	cout << "main: now displaying first array after heaping" << endl << endl;
	displayArray (list, low, high);
	b=checkIfHeap (list, low, high);
	if (b)
		cout << endl << "main: after heaping, the first array is a heap" << endl << endl;
	else
	{
		cout << endl << "main: after heaping, the first array is not a heap" << endl;
		return 4;
	}
	p ="CS20/a82data.txt";
	cout << "main: building second array (from a82data.txt)" << endl;
	buildArray (list, 100, p);
	cout << "main: displaying second array" << endl << endl;
	displayArray (list, low, high);
	heapSort (list, low, high);
	cout << endl << "main: displaying second array, which should now be sorted" << endl << endl;
	displayArray (list, low, high);

	return 0;
}


