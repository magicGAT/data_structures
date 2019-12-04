/*
 * que_functions.cpp
 *
 *  Created on: Nov 1, 2019
 *      Author: gregorytaylor
*/

#include <iostream>
#include <string>
#include "que.h"

using namespace std;

string error_empty = "The Queue is empty";
string error_full = "The Queue is already full!";

Que::Que(int size)
{
	the_queue = new int[size];
	queue_size = size;
	queue_front = 0;
	queue_back = queue_size - 1;
	count = 0;
}

Que::~Que()
{
	delete the_queue;
}

void Que::intialize_queue()
{
	queue_front = 0;
	queue_back = queue_size - 1;
	count = 0;
}

void Que::into_queue(int input)
{
	if (is_full())
	{
		cerr << error_full << endl;
		exit(4);
	}
	else
	{
		queue_back = (queue_back + 1) % queue_size;
		the_queue[count] = input;
		count++;
	}
}

void Que::leave_queue()
{
	if (is_empty())
	{
		cerr << error_empty << endl;
	}
	else
	{
		queue_front = (queue_front + 1) % queue_size;
		count--;
	}
}

int Que::in_front()
{
	if (is_empty())
	{
		cerr << error_empty << endl;
		return 4;
	}
	else
		return the_queue[queue_front];
}

int Que::in_back()
{
	if (is_empty())
	{
		cerr << error_empty << endl;
		return 4;
	}
	else
		return the_queue[queue_back];
}

bool Que::is_empty()
{
	if (count == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Que::is_full()
{
	if (count == queue_size)
		return true;
	else
		return false;
}



