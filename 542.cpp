#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

class Solution{
public:
  vector<vector<int> > updateMatrix(vector<vector<int> >& matrix){
    int  INT_MAX  (~0 ^ 1<<(sizeof(int)*8-1));
    cout << INT_MAX+1<<endl;
    int dir_x[4] = {0,0,1,-1};
    int dir_y[4] = {1,-1,0,0};
    int cols = matrix[0].size(), rows = matrix.size();
    vector<vector<int>> rtn(rows, vector<int>(cols,INT_MAX));
    vector<std::pair<int,int>> all_ones;
    for(int i = 0; i < matrix.size(); ++i)
      for(int j = 0; j < matrix[0].size(); ++j)
	if(matrix[i][j] == 1)
	  all_ones.push_back(std::make_pair(i,j));
	else
	  rtn[i][j] = 0;

    int step = 0;
    int x,y;
    vector<std::pair<int,int>>::iterator iter;
    vector<std::pair<int,int>> tmp;
    while(!all_ones.empty()){
      ++step;
      for(iter = all_ones.begin(); iter != all_ones.end(); iter++){
	for(int j = 0; j < 4; ++j){
	  x = iter->first + dir_x[j];
	  y = iter->second + dir_y[j];
	  if(!(x >= 0&& x < rows && y >= 0 && y < cols))
	    continue;
	  if(rtn[x][y] != INT_MAX){
	    cout << step << " " << iter->first << "," << iter->second << endl; 
	    tmp.push_back(*iter);
	    all_ones.erase(iter);
	    --iter;
	    break;
	  }
	}
      }
      for(vector<std::pair<int, int>>::iterator iter1 = tmp.begin(); iter1 != tmp.end(); iter1++){
	rtn[iter1->first][iter1->second] = step;
	cout << iter->first << "," << iter->second << endl; 
      }
      tmp.clear();
    }
   
    return rtn;
  }
};



int main(){
   Solution c;
  int a[][3]={{0,0,0},{0,1,0},{1,1,1}};
  int b[][10]={{1, 0, 1, 1, 0, 0, 1, 0, 0, 1}, {0, 1, 1, 0, 1, 0, 1, 0, 1, 1}, {0, 0, 1, 0, 1, 0, 0, 1, 0, 0}, {1, 0, 1, 0, 1, 1, 1, 1, 1, 1}, {0, 1, 0, 1, 1, 0, 0, 0, 0, 1}, {0, 0, 1, 0, 1, 1, 1, 0, 1, 0}, {0, 1, 0, 1, 0, 1, 0, 0, 1, 1}, {1, 0, 0, 0, 1, 1, 1, 1, 0, 1}, {1, 1, 1, 1, 1, 1, 1, 0, 1, 0}, {1, 1, 1, 1, 0, 1, 0, 0, 1, 1}};
  int k = 10, m =10;
  /*  while(k--){
    while(m--)
      cout << b[k][m] << " ";
    cout << endl;
    }*/

  for(int i = 0; i < 10; i ++){
    for(int j= 0; j < 10; j++){
      cout << b[i][j] << " " ;
    }
    cout << endl;
  }
  vector< vector<int> > t;
  for(int i = 0; i < sizeof(b)/sizeof(b[0]); i++)
    t.push_back(vector<int> (b[i], b[i] + sizeof(b[i])/sizeof(int)));


  t = c.updateMatrix(t);
  for(int i = 0; i < t.size(); ++i){
    for(int j = 0; j < t[i].size(); ++j)
      cout << t[i][j] << " ";
    cout << endl;
  }
  
  return 0;
}
  
	  


















