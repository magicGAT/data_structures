/*
 * vert.h
 *
 *  Created on: Dec 14, 2019
 *      Author: gregorytaylor
 */

#ifndef VERT_H_
#define VERT_H_

#include <queue>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct Vertex
{
	int vertexValue;
	bool visited;
	vector <int> neighbors;
};

void buildGraph (vector <Vertex>& graph);
int find_gindex(vector <Vertex>, int);
bool all_visited(vector <Vertex>);
void depthfirstTraversal(vector <Vertex>&);
void dftInternal(vector <Vertex>&, Vertex&);
void breadthfirstTraversal(vector <Vertex>&);

void buildGraph (vector <Vertex>& graph)
{
	ifstream input_file("v_data.txt");

	if (input_file.fail())
	{
		cerr << "File Error";
		exit(0);
	}
	else
	{
		int temp;
		Vertex v_temp;

		while (!input_file.eof())
		{
			input_file >> temp; // takes first value
			v_temp.vertexValue = temp;

			input_file >> temp; // takes subsequent value, checks if it is the end of neighbor list

			while (temp != -1)
			{
				v_temp.neighbors.push_back(temp); //fills the neighbors vector
				input_file >> temp;
			}

			graph.push_back(v_temp); //pushes into the Vertex vector
			v_temp.neighbors.clear();
		}

		// outputs the entire graph structure
		cout << "!!!--.GRAPH-READOUT.--!!!" << endl;
		int counter0  = 0;
		while (counter0 < graph.size())
		{
			cout << "Vertex " << counter0 << "- value: ";
			cout << graph[counter0].vertexValue << "| neighbors : ";
			int counter1 = 0;
			while (counter1 < graph[counter0].neighbors.size())
			{
				cout << graph[counter0].neighbors[counter1] << " ";
				counter1++;
			}
			cout << endl;
			counter0++;
		}
	}
	cout << endl << endl;
}

// need a hash/lookup function for the vertex index
int find_gindex(vector <Vertex> graph, int value)
{
	Vertex * navigator;
	int index = 0;

	navigator = &graph[index];

	while (navigator -> vertexValue != value)
	{
		index++;

		if (index >= graph.size())
		{
			cerr << "Value not contained in graph structure" << endl;
			return 4;
		}

		navigator = &graph[index];
	}

	return index;
}

bool all_visited(vector <Vertex> graph)
{
	for (int i = 0; i < graph.size(); i++) //iterates through all Vertexes, when one which has not been visited
	{									   // is reached, returns `false`
		if (graph[i].visited == false)
		{
			return false;
		}
	}

	return true; // if all vertexes are checked and none are unvisited, returns `true`
}

void depthfirstTraversal(vector <Vertex> &graph)
{
	cout << "Depth First Traversal Order:" << endl << endl;

	for (int i = 0; i < graph.size(); i++)
	{
		graph[i].visited = false;
	}

	int index = 0;
	while (!all_visited(graph))
	{
		if (graph[index].visited == false)
		{
			dftInternal(graph, graph[index]);
		}
		index++;
	}
	cout << endl << endl;
}

void dftInternal(vector <Vertex> &graph, Vertex &current)
{
	cout << current.vertexValue << " ";
	Vertex * v_temp = &current;
	v_temp -> visited = true;
	if (!v_temp -> neighbors.empty())
	{
		int counter = 0;
		int i_temp = v_temp -> neighbors[counter];
		while (counter < v_temp -> neighbors.size())
		{
			i_temp = v_temp -> neighbors[counter];
			if (graph[i_temp].visited == false)
			{
				dftInternal(graph, graph[i_temp]);
			}
			counter++;
		}
	}
}

void breadthfirstTraversal(vector <Vertex> &graph)
{
	cout << "Breadth First Traversal Order:" << endl << endl;
	for (int i = 0; i < graph.size(); i++)
	{
		graph[i].visited = false;
	}

	queue <int> que;

	for (int i = 0; i < graph.size(); i++)
	{
		if (graph[i].visited == false)
		{
			que.push(i);
			graph[i].visited = true;
			cout << i << " ";

			while (!que.empty())
			{
				int temp = que.front();
				que.pop();

				for (int i = 0; i < graph[temp].neighbors.size(); i++)
				{
					int temp2 = graph[temp].neighbors[i];

					if (graph[temp2].visited == false)
					{
						que.push(temp2);
						graph[temp2].visited = true;
						cout << temp2 << " ";
					}
				}
			}
		}
	}
	cout << endl << endl;
}

#endif /* VERT_H_ */
