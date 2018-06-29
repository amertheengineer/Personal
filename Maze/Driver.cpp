#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <array>
#include "Graph.h"
#include "Node.h"
#include "DFS.h"
using namespace std;

int main()
{

		ifstream myfile;	
		myfile.open("BS.txt");
		Graph g(myfile);
		DFS(g);
		
		
	system("PAUSE");
	

}
