#include <stack>
#include "dfsMazeEscape.h"
#include <cassert>

void dfsFindExit(Maze &M)
{
  stack<Position> path;
  path.push(NULLPOS); // if we back out to here, no way out!  
  direction d;
  Position nbr;
  Position current = M.start;
  M.visit(current);
  path.push(current);
  Position oldCurrent = NULLPOS;
  while(true) {
    if (current == M.exitpos) {// we found an exit path!
      cout << endl; // a little separation!
      printPath(path);
      return;
    }
    if(current == NULLPOS) { // backed out from start
      cout << "No way out" << endl;
      return;
    }
    nbr = M.getOpenNeighbor(current);
    if(nbr == NULLPOS) {// no open neighbor; back out
      path.pop(); // remove current from stack
      oldCurrent = current;
      current = path.top();
      cout << "Backing out from " << oldCurrent << " to " << current << endl; 
    } else {
      oldCurrent = current;
      M.visit(nbr);
      current = nbr;
      cout << "Moving forward from " << oldCurrent << " to " << current << endl;
      path.push(current);
    }
      
  }
}

