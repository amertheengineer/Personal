
/*
	Amer Abdelaziz	
	U25449742

	This function is the bfs version of finding the maze
	exit, very similar to the dfs version of the search
	but uses a queue instead of the stack
*/

#include <stack>
#include <queue>
#include "bfsMazeEscape.h"
#include <cassert>

void bfsFindExit(Maze &M)
{
	queue <Position> Q;
	
	vector<vector<Position> > pred;
	init_table(pred, M.size, NULLPOS);
	Position current, nbr;
	stack<Position> path;
	current = M.start;
	M.visit(current);
	Q.push(current);
	
	while (true)
	{
		/* First condition if the current position is the exit*/
		if (current == M.exitpos)
		{
			cout << endl;
			printPath(pred, current);
			return;

		}
		/* Checking if current is a wall*/
		if (current == NULLPOS)
		{
			cout << "Now way out" << endl;
			return;

		}
		/* Getting the first open neighbor */
		nbr = M.getOpenNeighbor(current);
		/* If neighbor is a wall*/
		if (nbr == NULLPOS)
		{
			Q.pop();
			current = Q.front();
			
			continue;
		}
		/* Otherwise set entry and visit neighbor*/
		else
		{
			setEntry(pred, nbr, current);
			M.visit(nbr);
			current = nbr;
			Q.push(nbr);
		}

		
		

	}
	
	
	system("PAUSE");

}
