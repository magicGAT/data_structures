/*
 * main.cpp
 *
 *  Created on: Dec 14, 2019
 *      Author: gregorytaylor
 */
#include "vert.h"

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector <Vertex> this_graph;

	buildGraph(this_graph);

	depthfirstTraversal(this_graph);

	breadthfirstTraversal(this_graph);

	return 0;
}



