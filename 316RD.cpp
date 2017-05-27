/*
always keep the minium oder in the stack, when new element comes check if it bigger than the last character in the stack, if it does, push into the stack else check wheather the last character int the stack has another dulplicate after current character
 */
#include<iostream>
#include<string>
#include<cstring>
#define INDEX(x)  ((x) - 'a')
using namespace std;


class Solution {
public:
    string removeDuplicateLetters(string s) {
      bool map[26];
      int counter[26];
      memset(counter, 0, sizeof(counter));
      string rtn;
      memset(map, 0, sizeof(map));
      int size = s.length();
      for(int i = 0; i < size; ++i)
	++counter[INDEX(s.at(i))];
      for(int i = 0; i < size; ++i){
	char ch = s.at(i);
	--counter[INDEX(ch)];
	if(map[INDEX(ch)])
	  continue;
	while(!rtn.empty() &&  ch < rtn.back() && counter[INDEX(rtn.back())]){
	  map[INDEX(rtn.back())] = false;
	  rtn.pop_back();
	}
	map[INDEX(ch)] = true;
	rtn.push_back(ch);
      }

      return rtn;
    }
};


int main(){
  string s = "bab";
  Solution a;
  string rtn = a.removeDuplicateLetters(s);
  cout << rtn<< endl;

  return 0;
}
  
