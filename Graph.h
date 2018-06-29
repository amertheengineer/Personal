
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
	int x = 0, y = 0;
	Node start;
	Node finish;
	Node** g1;
	Graph()
	{
		x = 0;
		y = 0;

	}
	Graph(ifstream& myfile)
	{


		cout << "File open" << endl;
		int x2, y2;
		myfile >> x;
		myfile >> y;
		cout << x << endl;
		cout << y << endl;

		string line;
		/*Graph g2;
		g2.x = x2;
		g2.y = y2;
		cout << g2.x << endl;
		cout << g2.y << endl;*/

		Node** g1;

		for (int i = 0; i < x; i++)
		{
			g1[i] = new Node[y];
		}
		int x0 = 0;
		int y0 = 0;
		cout << x2 << y2 << endl;
		start = g1[x0][y0];
		finish = g1[x2 - 1][y2 - 1];

		std::string s1;

		for (int i = 0; i < x2; i++)
		{
			for (int j = 0; j < y2; j++)
			{
				Node N1;
				myfile >> s1;

				int pos = s1.find("-");

				cout << pos << endl;
				string col1, dir1;
				if (pos != -1)
				{
					col1 = s1.substr(0, pos);
					dir1 = s1.substr(pos + 1, s1.length());

				}
				cout << col1 << endl;
				cout << dir1 << endl;
				N1.set_color(col1);
				N1.set_dir(dir1);
				N1.set_i(i);
				N1.set_j(j);

				g1[i][j] = N1;


			}
		}


		/*while (myfile)
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
		}*/
		myfile.close();




	}

};






#endif // !GRAPH_H
