#pragma once
#ifndef GRAPH_H
#define GRAPH_H
#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <array>
#include "Node.h"
using namespace std;


class Graph
{
public:
	int x, y;
	Node start;
	Node finish;
	Node** graph = new Node*[x];
	Graph()
	{
		x = 0;
		y = 0;	

	}
	Graph(ifstream &myfile)
	{
		
		
		myfile.open("Test.txt");


		int x1, y1;

		myfile >> x1;
		myfile >> y1;

		string line;
		Graph g2;
		g2.x = x1;
		g2.y = y1;
		Node** g1 = new Node*[x1];
		for (int i = 0; i < x1; i++)
		{
			g1[x1] = new Node[y1];
		}
		int x0 = 0;
		int y0 = 0;

		while (myfile)
		{
			if (getline(myfile, line, '-'))
			{
				string c;
				g1[x0][y0].set_color(c);
				getline(myfile, line, ' ');
				g1[x0][y0].set_dir( line);
				g1[x0][y0].set_i(x0);
				g1[x0][y0].set_j(y0);
				y0++;

			}
			else
			{
				getline(myfile, line);
				g1[x0][y0].set_dir(line) ;
				g1[x0][y0].set_i( x0);
				g1[x0][y0].set_j (y0);
				x0++;
				y0 = 0;
			}
		}
		myfile.close();




		}
};

	




#endif // !GRAPH_H
