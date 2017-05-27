#include<iostream>
using namespace std;

class Solution{
public:
  int islandPerimeter(vector<vector<int>>& grid){
    int rtn = 0;
    int r,l;
    int dir[2][4]={1,-1,0,0;0,0,-1,1};
    r = grid.size();
    for(int i = 0; i < r; ++i){
      l = grid[i].size();
      for(int j = 0; j < l; ++j){
	if(grid[i][j] == 0)
	  continue;
	for(int k = 0; k < 4; ++k){
	  int test_i = i + dir[0][k];
	  int test_j = j + dir[1][k];
	  if(test_i < 0 || test_i >= r || test_j < 0 || test_j >= l)
	    ++rtn;
	  else
	    if(!grid[test_i][test_j])
	      ++rtn;
	}
      }
    }
    return rtn;
  }
};
  
