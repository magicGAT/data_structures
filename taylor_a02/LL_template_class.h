/*
 * LL_template_class.h
 *
 *  Created on: Sep 26, 2019
 *      Author: gregorytaylor
 */

#ifndef LL_TEMPLATE_CLASS_H_
#define LL_TEMPLATE_CLASS_H_


#include <iostream>
#include <string>

using namespace std;

template <class T>
struct LLnode
{
	LLnode * fwdPtr;
	T theData;
};

template <class Z>
class LL
{
	private:
		LLnode <Z>* header;
	public:
		LL();
		void push_front(string data);
		void push_back(string data);
		int list_length() const;
		string retrieve_front() const;
		string retrieve_back() const;
		void display_nodes() const;
		void destroy_list();
		bool search_list(string key_value) const;
		bool delete_node(string key_value);
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
				while (temp -> fwdPtr != nullptr)
				{
					temp = temp -> fwdPtr;
				}
				temp -> fwdPtr = new_node;
			}

			return;
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
				while (temp != nullptr)
				{
					temp = temp -> fwdPtr;
					counter++;
				}
				return counter;
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
				while (temp -> fwdPtr != nullptr)
				{
					temp = temp -> fwdPtr;
				}
				data = temp -> theData;
				return data;
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
				LLnode <Z>* temp, * address;
				string node_data;
				int node_count = 0;

				temp = header;

				cout << "Header Target -> " << temp << endl;

				while (temp != nullptr)
				{
					address = temp;
					node_data = temp -> theData;

					cout << "node_" << node_count << "_address -> "
						 << address << endl;
					cout << "node_" << node_count << "_data -> "
						 << node_data << endl;

					node_count++;
					temp = temp -> fwdPtr;
				}
			}
			cout << endl;
			return;
		}
		template <class Z>
		void LL<Z>::destroy_list()
		{
			LLnode <Z>* temp, * killbox;

			if (header == nullptr)
			{
				return;
			}
			else
			{
				temp = header;
				header = nullptr;

				while (temp != nullptr)
				{
					killbox = temp;
					temp = temp -> fwdPtr;
					delete killbox;
				}
			}
				return;
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
				while (temp != nullptr)
				{
					viewpoint = temp -> theData;
					if (viewpoint == key_value)
					{
						result = true;
					}
					temp = temp -> fwdPtr;
				}
				return result;
			}
		}
		template <class Z>
		bool LL<Z>::delete_node(string key_value)
		{
			bool result;
			LLnode <Z>* temp, * t_temp;
			string viewpoint;

			temp = header;

			if (header -> theData == key_value)
			{
				header = header -> fwdPtr;
				delete temp;
				result = true;
				return result;
			}
			else
			{
				while (temp != nullptr)
				{
					viewpoint = temp -> theData;

					if (viewpoint == key_value)
					{
						t_temp -> fwdPtr = temp -> fwdPtr;
						delete temp;
						result = true;
						return result;
					}
					else
					{
						t_temp = temp;
						temp = temp -> fwdPtr;
					}
				}
				result = false;
				return result;
			}
		}



#endif // LL_TEMPLATE_CLASS_H
