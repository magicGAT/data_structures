
#include <iostream>
#include <string>

using namespace std;

// node structure

struct LLnode
{
	LLnode * fwdPtr; // has a pointer member
	string theData; // the data within the node
};

// node functions

// adds a node to the front of the linked list
void push_front(LLnode * & theLLHeader, string data)  // 'pass by reference' to save changes to header
{
	LLnode * new_node;
	new_node = new LLnode;							// initiates a new node pointer and new node object
	new_node -> theData = data;						// adds data to new node

	if (theLLHeader == nullptr)  					// checks for an empty list:
	{												// if list is empty, it assigns new node
		theLLHeader = new_node;                     // as first node and points header at it
		new_node -> fwdPtr = nullptr;
	}
	else											// if list has nodes:
	{
		LLnode * temp;								// copies header's target to 'temp'
		temp = theLLHeader;							// points header at new node
		theLLHeader = new_node;						// assigns new node's pointer to header's previous
		new_node -> fwdPtr = temp;					// target (node with was previously at the front)
	}

	return;
}

// adds a node to the back of the linked list
void push_back(LLnode * & theLLHeader, string data) // passes by reference to save changes to header
{
	LLnode * new_node, * temp;
	new_node = new LLnode;								// initiates a new node pointer and node object
	new_node -> theData = data;							// adds data to the new node
	new_node -> fwdPtr = nullptr;						// sets pointer member at 'nullptr' as the last node should
	temp = theLLHeader;									// copies header target into temp

	if (temp == nullptr)								// checks for empty list
	{
		theLLHeader = new_node;							// if list is empty, point header at new code
	}
	else												// if list has nodes:
	{
		while (temp -> fwdPtr != nullptr)				// traverse list using temp to copy pointers
		{
			temp = temp -> fwdPtr;
		}
		temp -> fwdPtr = new_node;						// when the end node is reached, point it at the new (end) node
	}

	return;
}

// counts the number of nodes in the linked list
int list_length(LLnode * theLLHeader)				// pass by value to avoid permanent changes to header
{
	int counter = 0;								// initiates a counter and temp variable
	LLnode * temp = theLLHeader;

	if (temp == nullptr)							// checks for an empty list:
	{
		return counter;								// if it is empty, returns '0'
	}
	else											// if list has nodes:
	{
		while (temp != nullptr)						// traverses the list using 'temp' to check for 'nullptr'
		{
			temp = temp -> fwdPtr;
			counter++;								// increment counter by 1 for each node traversed
		}
		return counter;								// when the last node is reached and counted, returns counter
	}
}

// returns the data in the first node
string retrieve_front(LLnode * theLLHeader)      // pass by value to avoid permanent changes to header
{
	string data,								// initiates variable to contain desired node data
		   warning = "This list is empty";

	if (theLLHeader == nullptr)					// checks for empty list:
	{
		throw warning;				// throws an error if empty
	}
	else										// if list has nodes:
	{
		data = theLLHeader -> theData;			// copies data inside header target node into 'data'
		return data;							// returns 'data'
	}
}

// returns the data in the last node
string retrieve_back(LLnode * theLLHeader)      // pass by value to avoid permanent changes to header
{
	string data,
		   warning = "This list is empty";		// initiates variable to contain desired node data

	LLnode * temp = theLLHeader;

	if (temp == nullptr)						// checks for empty list:
	{
		throw warning;							// throws an error if empty
	}
	else										// if list has nodes:
	{
		while (temp -> fwdPtr != nullptr)		// traverses the list using 'temp' to check for 'nullptr'
		{
			temp = temp -> fwdPtr;
		}
		data = temp -> theData;					// copies data within the last node into 'data'
		return data;							// return 'data'
	}
}

// returns all the values in all the nodes
void display_nodes(LLnode * theLLHeader)			// 'pass by value' to avoid changing permanent value of header
{
	if (theLLHeader == nullptr)						// checks for an empty list
	{												// outputs 'empty list alert' string
		cout << "This is an empty list and currently holds "
			 << "no nodes\n";
	}
	else											// protocol for non-empty list:
	{
		LLnode * temp, * address;					// creates 'temp', 'address', 'node_data',
		string node_data;							// and 'counter' utlity variables
		int node_count = 0;

		temp = theLLHeader;							// places header target inside 'temp'
													// outputs the header report component
		cout << "Header Target -> " << temp << endl;

		while (temp != nullptr)						// sets loop condition
		{
			address = temp;							// places 'temp' target inside address
			node_data = temp -> theData;			// places data of node currently pointed to by temp
													// and address inside 'node_data'
			cout << "node_" << node_count << "_address -> "
				 << address << endl;						// outputs current address and data with 'node_count' label
			cout << "node_" << node_count << "_data -> "
				 << node_data << endl;

			node_count++; 							// increments node_count and changes temp to contain the address inside
			temp = temp -> fwdPtr;  				// current node's pointer member to prepare for the next loop
		}
	}

	return;
}


// main function (testing)

int main() {

	LLnode * theLLHeader1 = nullptr;

	cout << "Main:  number of nodes in empty list " << list_length(theLLHeader1) << endl;
	display_nodes(theLLHeader1);
	push_front (theLLHeader1, "aaaaa");
	push_back (theLLHeader1, "bbbbb");
	push_front (theLLHeader1, "before aaaaa");
	push_back (theLLHeader1, "after bbbbb");
	cout << "Main:  number of nodes after 4 pushes - " << list_length(theLLHeader1) << endl;
	display_nodes (theLLHeader1);
	cout << "Main:  retrieve front: " << retrieve_front (theLLHeader1) << endl;
	cout << "Main:  retrieve back: " << retrieve_back (theLLHeader1) << endl;
	cout << endl;

	LLnode * theLLHeader2 = nullptr;

	push_front (theLLHeader2, "33333");
	push_front (theLLHeader2, "22222");
	push_front (theLLHeader2, "11111");
	push_back (theLLHeader2, "44444");
	push_back (theLLHeader2, "55555");
	push_back (theLLHeader2, "66666");
	display_nodes (theLLHeader2);

	return 0;
}
