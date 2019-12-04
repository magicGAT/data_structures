/*
 * stacks.h
 *
 *  Created on: Oct 22, 2019
 *      Author: gregorytaylor
 */

#ifndef STACKS_H_
#define STACKS_H_

#include <iostream>
#include <string>

using namespace std;

class Stack
{
	private:
		int height;
		class LL
			{
				private:
				struct LLnode
					{
						LLnode * fwdPtr;
						string * stack_address;
					};
					LLnode * header;
				public:
					LL()
					{
						header = nullptr;
					}
					void push_front(string * current_stack)
					{
						LLnode * new_node;
						new_node = new LLnode;
						new_node -> stack_address = current_stack;

						if (header == nullptr)
						{
							header = new_node;
							new_node -> fwdPtr = nullptr;
						}
						else
						{
							LLnode * temp;
							temp = header;
							header = new_node;
							new_node -> fwdPtr = temp;
						}

						return;
					}

					int list_length() const
					{
						int counter = 0;
						LLnode * temp = header;

						if (temp == nullptr)
						{
							return counter;
						}
						else
						{
							while (temp != nullptr)
							{
								temp = temp -> fwdPtr;
								counter++;
							}
							return counter;
						}
					}

					void delete_front(string *& current_stack)
					{
						LLnode * temp, * kill_box;

						if (header == nullptr)
						{
							return;
						}
						else if (header -> fwdPtr == nullptr)
						{
							kill_box = header;
							delete kill_box;
							header = nullptr;
						}
						else
						{
							kill_box = header;
							temp = header -> fwdPtr;
							delete kill_box;
							header = temp;
							current_stack = temp -> stack_address;



						}
					}

					void new_front(string * current_stack)
					{
						header -> stack_address = current_stack;
					}
			};

	public:
		LL stack_map;
		string * current_stack;
		int top_element;
		Stack(int);
		void push(string);
		bool top(string&);
		bool pop(string&);
		void destroy();

};



#endif /* STACKS_H_ */
