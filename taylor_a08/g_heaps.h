/*
 * heaps.h
 *
 *  Created on: Nov 19, 2019
 *      Author: gregorytaylor
 */

#ifndef G_HEAPS_H_
#define G_HEAPS_H_

#include <iostream>
#include <string>
#include <fstream>
#include <ios>
#include <istream>


using namespace std;

// function prototypes
void buildArray(int[], int, string);
void displayArray(int[], int, int);
bool checkIfHeap(int[], int, int);
void heapify(int[], int, int);
void buildHeap(int[], int, int);
void heapSort(int[], int, int);

void buildArray(int data[], int size, string str)
{
	ifstream inputFile(str);

	int counter = 0;

	while (counter < size)
	{
		string x;
		char temp;
		int number;

		for (int i = 0; i < 3; i++)
		{
			inputFile.get(temp);
			x += temp;
		}
		number = stoi(x);
		data[counter] = number;
		counter++;
	}

}

void displayArray(int data[], int low, int high)
{
	for (int i = 0; i< 45; i++)
	{
		cout << "-";
	}
	cout << endl;
	while (low <= high)
	{
		for (int i = 0; i < 10; i++)
		{
			cout << data[low] << " ";
			low++;
		}
		cout << endl;
	}
	for (int i = 0; i< 45; i++)
	{
		cout << "-";
	}
	cout << endl;
}

bool checkIfHeap(int data[], int low, int high)
{
	if (data[low] < data[low + 1])
	{
		return false;
	}

	low += 1;

	for (int i = low; i <= high; i++)
	{
		int left = 2 * i + 1;
		int right = 2 * i + 1;

		if (left <= 100 && right <= 100)
		{
			if (data[i] < data[2 * i + 1] || data[i] < data[2 * i + 2])
			{
				return false;
			}
		}
		i++;
	}

	return true;
}

void heapify(int data[], int low, int high)
{
	int largest = low;
	int left = 2 * low + 1;
	int right = 2 * low + 2;

	/*
	cout << "root position: " << largest << endl;
	cout << "vale at root: " << data[largest] << endl;
	cout << "left child position: " << left << endl;
	cout << "vale at left child: " << data[left] << endl;
	cout << "right child position: " << right << endl;
	cout << "value at right child: " << data[right] << endl;
	*/

	if (left <= high && data[left] > data[largest])
		largest = left;

	if (right <= high && data[right] > data[largest])
		largest = right;

	// cout << "largest position: " << largest << endl;
	// cout << "largest value: " << data[largest] << endl;
	if (largest != low)
	{
		swap(data[low], data[largest]);
		heapify(data, largest, high);
	}
}

void buildHeap(int data[], int low, int high)
{

	const int SIZE = 100;

	int index = SIZE / 2 - 1;

	while (index >= low)
	{
		heapify(data, index, high);

		index--;
	}

}

void heapSort(int data[], int low, int high)
{
	int temp;

	buildHeap(data, low, high);

	for (int out_box = high; out_box >= 0; out_box--)
	{
		temp = data[out_box];
		data[out_box] = data[0];
		data[0] =temp;

		heapify(data, 0, out_box - 1);
	}
}

#endif /* G_HEAPS_H_ */
