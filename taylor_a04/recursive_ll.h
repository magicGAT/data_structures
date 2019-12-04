/*
 * recursive_ll.h
 *
 *  Created on: Oct 10, 2019
 *      Author: gregorytaylor
 */

#ifndef LL_TEMPLATE_CLASS_H_
#define LL_TEMPLATE_CLASS_H_


#include <iostream>
#include <string>

using namespace std;

//templated node data structure
template <class T>
struct LLnode
{
	LLnode * fwdPtr;  //non-template pointer member
	T theData;		  //templated data member
};

//templated linked list class
template <class Z>
class LL
{
	private:
		LLnode <Z>* header;  // header member
	public:
		LL();
		void push_front(string data); //pushes a new node to the front of a linked list
		void end_servicer(LLnode <Z>*, LLnode <Z>*);// HELPER FUNCTION
		void push_back(string data); //pushes a new node to the back of a linked list
		int count_next(LLnode <Z>*, int) const;//HELPER FUNCTION
		int list_length() const; //returns the length of a linked list based on the number of nodes within
		string retrieve_front() const; //returns the string data contained within the first node in the list
		string tail_data(LLnode <Z>*, string);//HELPER FUNCTION
		string retrieve_back() const; //returns the string data contained within the last node in the list
		void node_printer(LLnode<Z>*, int) const;//HELPER FUNCTION
		void display_nodes() const; //outputs a detailed, labeled report on the location in memomry of each node and its data
		void recur_killbox(LLnode <Z>*);//HELPER FUNCTION
		void destroy_list(); //clears out every node in a list and points the header at NULL
		bool search_next(LLnode <Z>*, bool, string) const;//HELPER FUNCTION
		bool search_list(string key_value) const; //searches a list according to the data within each node, returns true or false
		bool killbox_next(LLnode <Z>*, LLnode <Z>*, bool, string);//HELPER FUNCTION
		bool delete_node(string key_value); //deletes any one node who's data matches the search term and leaves the rest of the list functional
};
		template <class Z>
		LL<Z>::LL()
			{
				header = nullptr;
			}

		template <class Z>
		void LL<Z>::push_front(string data)
		{
			LLnode <Z>* new_node;
			new_node = new LLnode<Z>;
			new_node -> theData = data;

			if (header == nullptr)
			{
				header = new_node;
				new_node -> fwdPtr = nullptr;
			}
			else
			{
				LLnode <Z>* temp;
				temp = header;
				header = new_node;
				new_node -> fwdPtr = temp;
			}

			return;
		}
		template <class Z>
		void LL<Z>::end_servicer(LLnode <Z>* sub_node, LLnode <Z>* temp_box)
		{
			if (temp_box -> fwdPtr == nullptr)
			{
				temp_box -> fwdPtr = sub_node;
				return;
			}
			else
			{
				temp_box = temp_box -> fwdPtr;
				end_servicer(sub_node, temp_box);
			}
		}
		template <class Z>
		void LL<Z>::push_back(string data)
		{
			LLnode <Z>* new_node, * temp;
			new_node = new LLnode<Z>;
			new_node -> theData = data;
			new_node -> fwdPtr = nullptr;
			temp = header;

			if (temp == nullptr)
			{
				header = new_node;
			}
			else
			{
				end_servicer(new_node, temp);
			}

			return;
		}
		template <class Z>
		int LL<Z>::count_next(LLnode <Z>* location, int count) const
		{
			LLnode <Z>* temp = location;
			int counter = count;

			if (temp == nullptr)
			{
				return counter;
			}
			else
			{
				temp = temp -> fwdPtr;
				return count_next(temp, counter + 1);
			}
		}
		template <class Z>
		int LL<Z>::list_length() const
		{
			int counter = 0;
			LLnode <Z>* temp = header;

			if (temp == nullptr)
			{
				return counter;
			}
			else
			{
				return count_next(temp, counter);
			}
		}

		template <class Z>
		string LL<Z>::retrieve_front() const
		{
			string data,
				   warning = "This list is empty";

			if (header == nullptr)
			{
				throw warning;
			}
			else
			{
				data = header -> theData;
				return data;
			}
		}
		template <class Z>
		string LL<Z>::tail_data(LLnode <Z>* temp_box, string data_box)
		{
			if (temp_box -> fwdPtr == nullptr)
			{
				data_box = temp_box -> theData;
				return data_box;
			}
			else
			{
				temp_box = temp_box -> fwdPtr;
				return tail_data(temp_box, data_box);
			}
		}
		template <class Z>
		string LL<Z>::retrieve_back() const
		{
			string data,
				   warning = "This list is empty";

			LLnode <Z>* temp = header;

			if (temp == nullptr)
			{
				throw warning;
			}
			else
			{
				return tail_data(temp, data);
			}
		}
		template <class Z>
		void LL<Z>::node_printer(LLnode <Z>* location, int count) const
		{
			LLnode <Z>* address;
			string node_data;
			int node_count;

			address = location;
			node_data = location -> theData;
			node_count = count;

			cout << "node_" << node_count << "_address -> "
				 << address << endl;
			cout << "node_" << node_count << "_data -> "
				 << node_data << endl;

			if (location -> fwdPtr == nullptr)
			{
				return;
			}
			else
			{
				location = location -> fwdPtr;
				node_printer(location, node_count + 1);
			}
		}
		template <class Z>
		void LL<Z>::display_nodes() const
		{
			if (header == nullptr)
			{
				cout << "This is an empty list and currently holds "
					 << "no nodes\n";
			}
			else
			{
				LLnode <Z>* temp; // * address
				// string node_data;
				int node_count = 0;

				temp = header;

				cout << "Header Target -> " << temp << endl;
				node_printer(temp, node_count);
			}
			cout << endl;
			return;
		}
		template <class Z>
		void LL<Z>::recur_killbox(LLnode <Z>* target)
		{
			if (target == nullptr)
			{
				return;
			}
			else
			{
				LLnode <Z> * killbox, * temp;

				temp = target -> fwdPtr;
				killbox = target;

				delete killbox;
				recur_killbox(temp);

			}
		}
		template <class Z>
		void LL<Z>::destroy_list()
		{
			LLnode <Z>* temp;

			if (header == nullptr)
			{
				return;
			}
			else
			{
				temp = header;
				header = nullptr;

				recur_killbox(temp);
			}
				return;
		}
		template <class Z>
		bool LL<Z>::search_next(LLnode <Z>* location, bool status, string key_value) const
		{
			if (location == nullptr)
			{
				return status;
			}
			else
			{
				if (location -> theData == key_value)
				{
					status = true;
					return status;
				}
				else
				{
					location = location -> fwdPtr;
					return search_next(location, status, key_value);
				}
			}
		}
		template <class Z>
		bool LL<Z>::search_list(string key_value) const
		{
			bool result = false;
			LLnode <Z>* temp;
			string viewpoint;

			temp = header;

			if (temp == nullptr)
			{
				result = false;
				return result;
			}
			else
			{
				return search_next(temp, result, key_value);
			}
		}
		template <class Z>
		bool LL<Z>::killbox_next(LLnode <Z>* location, LLnode <Z>* connector, bool status, string key_value)
		{
			if (location == nullptr)
			{
				return status;
			}
			else if (location -> theData == key_value)
			{
				status = true;
				connector -> fwdPtr = location -> fwdPtr;
				delete location;
				return status;
			}
			else
			{
				connector = location;
				location = location -> fwdPtr;
				return killbox_next(location, connector, status, key_value);
			}
		}
		template <class Z>
		bool LL<Z>::delete_node(string key_value)
		{
			bool result = false;
			LLnode <Z>* temp, * connect_box;

			temp = header;
			connect_box = nullptr;

			if (header -> theData == key_value)
			{
				header = header -> fwdPtr;
				delete temp;
				result = true;
				return result;
			}
			else
			{
				return killbox_next(temp, connect_box, result, key_value);
			}
		}



#endif // LL_TEMPLATE_CLASS_H


