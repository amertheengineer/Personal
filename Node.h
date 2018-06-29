#pragma once
#ifndef NODE_H
#define NODE_H
#include <string>
#include <iostream>
using namespace std;
class Node
{
public:
	string dir;
	string color;
	bool finish;
	int i, j;

	void set_dir(string d)
	{
		dir = d;
	}
	void set_color(string c)
	{
		color = c;
	}
	void set_i(int x)
	{
		i = x;
	}
	void set_j(int y)
	{
		j = y;
	}
	void set_finish(bool f)
	{
		finish = f;
	}
	bool is_visited()
	{
		return finish;
	}
	int get_i()
	{
		return i;
	}
	int get_j()
	{
		return j;
	}
	string get_dir()
	{
		return dir;
	}
	string get_color()
	{
		return color;
	}

	Node()
	{
		dir = ' ';
		color = ' ';
		finish = false;
		i = -1, j = -1;

	}
	
	bool operator == (Node const &N1)
	{
		Node temp;
		if ((this->j == N1.j) && (this->j == N1.i))
			return true;

	}
	bool operator != (Node const &N2)
	{
		Node temp;
		if ((this->i != N2.i) || (this->j != N2.j))
		{
			return false;
		}
	}
	Node operator = (Node const &N3)
	{
		Node N4;
		N4.i = N3.i;
		N4.j = N3.j;
		N4.color = N3.color;
		N4.dir = N3.dir;
		return N4;
	}
};
#endif // NODE_H
