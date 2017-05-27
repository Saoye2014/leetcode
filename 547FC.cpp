#include<iostream>
using namespace std;

class Solution{
public:
  bool isV[1200];
  int findCircleNum(vector<vector<int>>& M){
    for(int i = 0; i < 1200; ++i)
      isV[i] = false;
    return dfs(M);
  }
  
  int dfs(vector<vector<int>>& M){
    int count = 0;
    for(int i = 0; i < M.size(); i++)
      if(isV[i] == false){
	dfs_visit(i, M);
	++count;
      }

    return count;
  }

  void  dfs_visit(int v, vector<vector<int>>& M){
    isV[v] = true;
    for(int i = 0; i < M[v].size(); ++i){
      if(M[v][i] == 1 && isV[i] == false)
	dfs_visit(i, M);
    }
  }
};


















