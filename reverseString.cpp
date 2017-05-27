#include<iostream>
using namespace std;

class Solution{
  public:
  string reverseString(string s){
    String result ="";
    char[] ch = s.toCharArray();
    for(int i = ch.length -1; i >= 0; i--){
      result += ch[i];
    }
    return result;
  }
};
