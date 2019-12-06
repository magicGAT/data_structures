/*
 * main.cpp
 *
 *  Created on: Dec 1, 2019
 *      Author: gregorytaylor
 */

#include <iostream>

#include "bst.h"

using namespace std;


int main() {
	BST mytree;
	int i;
	bool b;

	int array[14] = {60,50,70,30,53,80,35,57,75,32,40,77,48,45};
	for (int i=0;i<14;i++)
	{
		mytree.insert(array[i]);
	}

	cout << "traverse inorder" << endl;
	mytree.traverseInOrder();
	cout << "traverse preorder" << endl;
	mytree.traversePreOrder();
	cout << "traverse postorder" << endl;
	mytree.traversePostOrder();

	mytree.print2D();
	cout << "-------------------------------------------" << endl;
	mytree.setallBF();
	mytree.print2D();
	cout <<" largest BF " << mytree.getLargestBF() << endl;
	cout << "-------------------------------------------" << endl;
	i = 46;
	mytree.insert(i);
	i = 47;
	mytree.insert(i);
	mytree.setallBF();
	mytree.print2D();
	cout <<" largest BF " << mytree.getLargestBF() << endl;
	cout << "-------------------------------------------" << endl;
	i=45;
	mytree.udelete(i);
	mytree.setallBF();
	mytree.print2D();
	i = 53;
	b = mytree.search(i);
	if (b)
		cout << "search for 53 successful" << endl;
	else
		cout << "search for 53 not successful" << endl;

	return 0;
}



