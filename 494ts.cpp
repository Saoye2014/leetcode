#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
      return findT(nums, S, 0);
    }
  
  int findT(vector<int>& nums, const int& S,int sum){
    if(sum == S && nums.empty())
      return 1;
    
    if(!nums.empty()){
      int tmp = nums.back();
      nums.pop_back();
      int res = findT(nums, S, tmp+sum) + findT(nums, S, -tmp + sum);
      nums.push_back(tmp);
      return res;
    }
    else
      return 0;
  }
    
};


int main(){
  vector<int> tmp;
  int a;
  while(cin >> a){
    tmp.push_back(a);
  }
    cout << "flag:"<< cin.good() << endl;
  cin.clear();
   cout << "flag:"<< cin.good() << endl;
  int T;
  cout << "input T:";
  cin >> T;
    cout << "flag:"<< cin.good() << endl;
    cout << "T:"<< T<<endl;



  Solution s;
   cout << s.findTargetSumWays(tmp, T);
}

