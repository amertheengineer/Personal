#pragma once
#ifndef DFS_H
#define DFS_H
#include <stdio.h>
#include "Graph.h"
#include <stack>
#include "Node.h"
#include <iostream>
void DFS(Graph g)
{
	stack <Node> stack;
	std::stack <int> num;


	int i = 0;
	int j = 0;
	int count;
	Node current = g.start;

	Node temp;
	stack.push(current);
	num.push(0);
	cout << current.get_i() << endl;
	cout << current.get_j() << endl;
	while (current != g.finish)
	{
		if (stack.empty())
		{
			cout << "The maze can't be solved" << endl;
		}
		int count = 0;
		current = stack.top();

		current.set_i(i);
		current.set_j(j);

		string curr = current.get_dir();
		string color = current.get_color();
		current.set_dir(curr);
		cout << curr << endl;
		if (curr == "N")
		{
			if (i == 0)
			{
				stack.pop();
				num.pop();
				continue;
			}
			i--;
			count++;
			temp = current;
			while (temp.get_color() == current.get_color() || (temp.is_visited() == true && i != 1))
			{
				i--;
				count++;
				if (i != 1)
				{
					temp = current;
				}
			}
			if (i == -1)
			{
				num.pop();
				stack.pop();
				continue;
			}
			g.g1[i][j].set_finish(true);
			num.push(count);
			stack.push(temp);

		}

		if (curr == "E")
		{
			if (j == g.y - 1)
			{
				num.pop();
				stack.pop();
				continue;
			}
			j++;
			count++;
			temp = g.g1[i][j];

			while ((temp.get_color() == current.get_color() || temp.is_visited() == true) && j != g.y)
			{
				j++;
				count++;
				if (j != g.y)
				{
					temp = g.g1[i][j];

				}

				if (j == g.y) {
					num.pop();
					stack.pop();
					continue;
				}
				g.g1[i][j].set_finish(true);
				num.push(count);
				stack.push(temp);
			}

		}

		if (curr == "S")
		{
			if (i == g.x - 1)
			{
				num.pop();
				stack.pop();
				continue;
			}
			i++;
			count++;
			temp = g.g1[i][j];
			while (((temp.get_color() == current.get_color()) || temp.is_visited() == true && i != g.x))
			{
				i++;
				count++;
				if (i != g.x)
				{
					temp = g.g1[i][j];
				}
			}
			if (i == g.x)
			{
				num.pop();
				stack.pop();
				continue;
			}
			g.g1[i][j].set_finish(true);
			num.push(count);
			stack.push(temp);

		}

		if (curr == "W")
		{
			if (j == 0)
			{
				num.pop();
				stack.pop();
				continue;
			}
			j--;
			count++;
			temp = g.g1[i][j];
			while (temp.get_color() == current.get_color() || (temp.is_visited() == true && j != -1))
			{
				j--;
				count++;
				if (j != 1)
				{
					temp = g.g1[i][j];
				}
			}
			if (j == -1)
			{
				num.pop();
				stack.pop();
				continue;
			}
			g.g1[i][j].set_finish(true);
			num.push(count);
			stack.push(temp);

		}
		if (curr == "NE")
		{
			if (i == 0 || j == g.y - 1)
			{
				num.pop();
				stack.pop();
				continue;
			}
			i--;
			j++;
			count++;
			temp = g.g1[i][j];
			while ((temp.get_color() == current.get_color() || temp.is_visited() == true) && j != g.y)
			{
				i--;
				j++;
				count++;
				if (i != -1 && j != g.y)
				{
					num.pop();
					stack.pop();
					continue;
				}
				g.g1[i][j].set_finish(true);
				num.push(count);
				stack.push(temp);
			}

		}
		if (curr == "NW")
		{
			if (i == 0 || j == 0)
			{
				num.pop();
				stack.pop();
				continue;
			}
			i--;
			j--;
			count++;
			temp = g.g1[i][j];
			while ((temp.get_color() == current.get_color() || temp.is_visited() == true) && (i != -1 && j != -1))
			{
				i--;
				j--;
				count++;
				if (i != -1 && j != -1)
					temp = g.g1[i][j];
			}
			if (i == -1 || j == -1)
			{
				num.pop();
				stack.pop();
				continue;
			}
			g.g1[i][j].set_finish(true);
			num.push(count);
			stack.push(temp);



		}

		if (curr == "SE")
		{
			if (i == g.x - 1 || j == g.y - 1)
			{
				num.pop();
				stack.pop();
				continue;
			}
			i++;
			j++;
			count++;
			temp = g.g1[i][j];

			while ((temp.get_color() == current.get_color() || temp.is_visited() == true) && (i != g.x && j != g.y))
			{

				i++;
				j++;
				count++;

				if (i != g.x && j != g.y)
					temp = g.g1[i][j];

			}
			if (i == g.x || j == g.y)
			{
				num.pop();
				stack.pop();
				continue;
			}
			g.g1[i][j].set_finish(true);
			num.push(count);
			stack.push(temp);

		}

		if (curr == "SW")
		{
			if (i == g.x - 1 || j == 0)
			{
				num.pop();
				stack.pop();
				continue;
			}
			i++;
			j--;
			count++;
			temp = g.g1[i][j];

			while ((temp.get_color() == current.get_color() || temp.is_visited() == true) && (i != g.x && j != -1))
			{
				i++;
				j--;
				count++;
				if (i != g.x && j != -1)
					temp = g.g1[i][j];
			}

			if (i == g.x || j == -1)
			{
				num.pop();
				stack.pop();
				continue;
			}
			g.g1[i][j].set_finish(true);
			num.push(count);
			stack.push(temp);


		}


	}




	std::stack <Node> rev;
	while (!stack.empty())
	{
		Node cur = stack.top();
		stack.pop();
		rev.push(cur);
	}
	std::stack <int> revnum;
	while (!num.empty())
	{
		int x = num.top();
		num.pop();
		revnum.push(x);

	}
	int c = 0;
	ofstream outfile;
	while (!rev.empty())
	{
		if (c == 0)
		{
			revnum.pop();
			c++;
			continue;
		}
		if (rev.size() == 1)
		{
			rev.pop();
			break;
		}

		outfile.open("Output.txt");
		cout << "Writing to Output file" << endl;
		outfile << revnum.top() << rev.top().dir << " " << endl;
		rev.pop();
		revnum.pop();
		c++;

	}
	cout << "Done" << endl;
	outfile.close();


}


#endif // !DFS_H
