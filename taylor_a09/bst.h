/*
 * bst.h
 *
 *  Created on: Dec 1, 2019
 *      Author: gregorytaylor
 */

#ifndef BST_H_
#define BST_H_

//============================================================================
// Name        : A9 BST code for students - CS20 Fall 2019
// Author      : Paul Hrycewicz
//============================================================================

#include <iostream>
using namespace std;

// fuctions to add: balance tree, find largest key value in a tree, user insert, print 2D, traversePostOrderInternal(?)
// aspects to edit: node definition, traverseInOrderInternal()
struct Treenode
{
	int nodeValue;
	int bf;
	Treenode * Lchild;
	Treenode * Rchild;
};

class BST
{
private:
	Treenode * root;

	void traverseInOrderInternal(Treenode *);		// internal functions - all by subtree
	void traversePreOrderInternal(Treenode *);
	void traversePostOrderInternal(Treenode *);
	bool traverseLevelOrderInternal(Treenode *, int);
	void print2DInternal(Treenode *, int);

	void deleteInternal (Treenode * &);				// internal delete function

	int heightInternal(Treenode *);					// internal BF functions
	void setallBFInternal(Treenode *&);
	int getLargestBFInternal(Treenode *);

public:
	BST();
	void insert (int &);				// user functions - all whole tree
	bool search (int &);
	void udelete (int &);

	void setallBF();					// sets BF for whole tree
	int height();						// height of whole tree
	int getLargestBF();					// largest BF in whole tree

	void traverseLevelOrder();			// traversal functions
	void print2D();
	void traverseInOrder();
	void traversePreOrder();
	void traversePostOrder();
};

BST::BST()
{
	root = nullptr;
}
//********************************************************
// user search - search, given a value
//********************************************************
bool BST::search(int & value)
{
	Treenode *current;
	bool found = false;
	if (root == nullptr)
	{
		cout << "search: tree is empty" << endl;
		exit (1);
	}
	else
	{
		current = root;
		while (current != nullptr && !found)
		{
			if (current->nodeValue == value)
			{
				found = true;
			}
			else if (current->nodeValue > value)
			{
				current = current->Lchild;
			}
			else
			{
				current = current->Rchild;
			}
		}
	}
	return found;
}
//********************************************************
// user insert - insert, given a value
//********************************************************
void BST::insert(int &value)
{
	Treenode * new_node;
	Treenode * temp;
	Treenode * trailing_temp;
	bool leash; // false means left, true means right. method of tracking where temp is in relation to trailing temp

	new_node = new Treenode;
	new_node -> nodeValue = value;
	new_node -> Lchild = nullptr;
	new_node -> Rchild = nullptr;

	if (root == nullptr)
	{
		root = new_node;
	}

	else
	{
		temp = root;

		while (temp != nullptr)
		{
			if (temp -> nodeValue == value)
			{
				cerr << "Attempting to add an already existing value" << endl;
			}
			else if (value > temp -> nodeValue)
			{
				leash = true;
				trailing_temp = temp;
				temp = temp -> Rchild;
			}
			else if (value < temp -> nodeValue)
			{
				leash = false;
				trailing_temp = temp;
				temp = temp -> Lchild;
			}
		}

		if (temp == nullptr)
		{
			if (leash == true)
			{
				trailing_temp -> Rchild = new_node;
			}
			else if (leash == false)
			{
			trailing_temp -> Lchild = new_node;
			}
		}
	}
}
//********************************************************
// user delete - delete, given a value
//********************************************************
void BST::udelete(int & value)
{
	Treenode * current; 		// pointer to node we're looking at
	Treenode * trailing; 		// trailing pointer to parent

	bool found = false;
	if (root == NULL)
	{
		cout << "udelete:  empty tree" << endl;
		exit (1);
	}
	else
	{
		current = root;
		trailing = root;
		while (current != nullptr && !found)
		{
			if (current->nodeValue == value)
			{
				found = true;
			}
			else
			{
				trailing = current;
				if (current->nodeValue > value)
				{
					current = current->Lchild;
				}
				else
				{
					current = current->Rchild;
				}
			}
		}
		if (current == nullptr)
		{
			cout << "udelete:  not found" << endl;
		}
		else if (found)
		{
			if (current == root)
			{
				deleteInternal(root);
			}
			else if (trailing->nodeValue > value)
			{
				deleteInternal(trailing->Lchild);
			}
			else
			{
				deleteInternal(trailing->Rchild);
			}
		}
	}
}
//********************************************************
// internal delete - delete, given the pointer to node to delete that is physically
// located in the node's parent as Lchild or Rchild
//********************************************************
void BST::deleteInternal (Treenode * &p)
{
	Treenode * current;			// pointer to node we're looking at
	Treenode * trailing;		// trailing pointer to parent
	Treenode * temp;			// temp pointer for delete

	if (p == nullptr)
	{
		cout << "delete: null node" << endl;
		exit(1);
	}
	else if(p->Lchild == nullptr && p->Rchild == nullptr)
	{
		temp = p;
		p = nullptr;
		delete temp;
	}
	else if(p->Lchild == nullptr)
	{
		temp = p;
		p = temp->Rchild;
		delete temp;
	}
	else if(p->Rchild == nullptr)
	{
		temp = p;
		p = temp->Lchild;
		delete temp;
	}
	else
	{
		current = p->Lchild;
		trailing = nullptr;
		while (current->Rchild != nullptr)
		{
			trailing = current;
			current = current->Rchild;
		}
		p->nodeValue = current->nodeValue;
		if (trailing == NULL)
		{
			p->Lchild = current->Lchild;
		}
		else
		{
			trailing->Rchild = current->Lchild;
		}
		delete current;

	}
}
//********************************************************
// user traversal functions
//********************************************************
void BST::traverseInOrder()
{
	traverseInOrderInternal(root);
}
void BST::traversePreOrder()
{
	traversePreOrderInternal(root);
}
void BST::traversePostOrder()
{
	traversePostOrderInternal(root);
}
void BST::print2D()
{
    print2DInternal(root, 0);
}
void BST::traverseLevelOrder()
{
    int level = 1;
    while (traverseLevelOrderInternal(root,level))
    {
    	cout << endl;
        level++;
    }
}
//********************************************************
// internal traversal functions
//********************************************************
void BST::traverseInOrderInternal(Treenode * p)
{
	if (p == nullptr)
	{
//		cout << "enter inorder with null" << endl;
	}
	else
	{
//		cout << "enter inorder " << p ->nodeValue << endl;
	}
	if (p != nullptr)
	{
		traverseInOrderInternal(p->Lchild);
		cout << p->nodeValue << endl;
		traverseInOrderInternal(p->Rchild);
	}
}

void BST::traversePreOrderInternal(Treenode * p)
{
	if (p != nullptr)
	{
		cout << p->nodeValue << endl;
		traversePreOrderInternal(p->Lchild);
		traversePreOrderInternal(p->Rchild);
	}
}

void BST::traversePostOrderInternal(Treenode * p)
{
	if (p != nullptr)
	{
		traversePostOrderInternal(p->Lchild);
		traversePostOrderInternal(p->Rchild);
		cout << p->nodeValue << endl;
	}
}

bool BST::traverseLevelOrderInternal(Treenode * p, int level)
{
    if (p == nullptr)
        return false;
    if (level == 1)
    {
    	cout << p->nodeValue << "   ";
    	return true;
    }
    bool l = traverseLevelOrderInternal(p->Lchild, level-1);
    bool r = traverseLevelOrderInternal(p->Rchild, level-1);
    return l || r;
}
// internal recursive function, called by print2D
// does a reverse inorder traversal to display top to bottom
void BST::print2DInternal(Treenode *root, int space)
{
	int count=8;
    if (root == NULL)
        return;
    space += count;
    print2DInternal(root->Rchild, space);	// process right (top of page)
    cout<<endl;								// display node after spacing
    for (int i = count; i < space; i++)
        cout<<" ";
    cout<<root->nodeValue<<"("<<root->bf<<")"<<"\n";
    print2DInternal(root->Lchild, space);	// process left (bottom of page)
}
//********************************************************
// user BF functions
//********************************************************
// user height - sets the BF for each node

int BST::height()
{
	return heightInternal(root);
}



// user setallBF - sets the BF for all nodes in the tree
void BST::setallBF()
{
	if (root != nullptr)
	{
		setallBFInternal(root);
	}
	else
	{
		cout << "This tree is empty, no nodes to perform BF calculation upon" << endl;
	}
}


// user BF - returns the largest balance factor in the tree
int BST::getLargestBF()
{
	return getLargestBFInternal(root);
}
//********************************************************
// internal BF functions
//********************************************************

// heightInternal - recursive function,
// returns height of a subtree given its root

int BST::heightInternal(Treenode* p)
{
	if (p != nullptr)
	{
		int lh, rh;
		lh = heightInternal(p->Lchild);
		rh = heightInternal(p->Rchild);
		if (lh > rh)
		{
			lh++;
			return lh;
		}
		else
		{
			rh++;
			return rh;
		}
	}
	else
	{
		return -1;
	}
}

// setallBFinternal - recursive function,
// calculates the bf of a node and its subtrees
void BST::setallBFInternal(Treenode *& tree_top)
{
	//BF = height of right tree - height of the left tree
	if (tree_top == nullptr)
		return;

	tree_top -> bf = heightInternal(tree_top -> Rchild) - heightInternal(tree_top -> Lchild);// height_r - height_l;
	setallBFInternal(tree_top -> Lchild);
	setallBFInternal(tree_top -> Rchild);
}
// getlargestBFInternal - resursive function,
// returns largest BF in the given subtree
int BST::getLargestBFInternal(Treenode * tree_top)
{
	if (tree_top == nullptr)
		return 0;

	int l_bf = getLargestBFInternal(tree_top -> Lchild);
	int r_bf = getLargestBFInternal(tree_top -> Rchild);
	int root_bf = tree_top -> bf;

	root_bf = abs(root_bf);
	l_bf = abs(l_bf);
	r_bf = abs(r_bf);

	if (l_bf > r_bf)
	{
		if (root_bf > l_bf)
		{
			return root_bf;
		}
		else
			return l_bf;
	}
	else
	{
		if (root_bf > r_bf)
		{
			return root_bf;
		}
		else
			return r_bf;
	}
}


#endif /* BST_H_ */
