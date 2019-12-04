/*
 * stack_functions.cpp
 *
 *  Created on: Oct 26, 2019
 *      Author: gregorytaylor
 */

#include <iostream>
#include <string>
#include "stacks.h"

using namespace std;

Stack::Stack(int size)
{
	height = size;
	top_element = 0;

	current_stack = new string[height];

	stack_map.push_front(current_stack);
}

void Stack::push(string data)
{
	if (top_element == height)
	{
		current_stack = new string[height];
		stack_map.push_front(current_stack);


		current_stack[0] = data;
		top_element = 1;
	}
	else
	{
		current_stack[top_element] = data;
		top_element++;
	}
}

bool Stack::top(string& result_box)
{
	if (top_element == 0)
	{
		if (stack_map.list_length() == 1)
		{
			return false;
		}
		else
		{
			stack_map.delete_front(current_stack);
			top_element = height - 1;
			result_box = current_stack[top_element];
			return true;
		}
	}
	else
	{
		result_box = current_stack[top_element - 1];
		return true;
	}
}

bool Stack::pop(string& result_box)
{
	if (top_element == 0)
	{
		if (stack_map.list_length() == 1)
		{
			return false;
		}
		else
		{
			delete[] current_stack;
			stack_map.delete_front(current_stack);
			top_element = height - 1;
			result_box = current_stack[top_element];
			return true;
		}
	}
	else
	{
		top_element--;
		result_box = current_stack[top_element];
		return true;
	}
}

void Stack::destroy()
{
	delete [] current_stack;
	stack_map.delete_front(current_stack);
	top_element = height;
}


