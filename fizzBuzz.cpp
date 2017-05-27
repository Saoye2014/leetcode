#include<iostream>
#include<vector>
#include<string>

using namespace std;
class Solution{
  public:
  vector<string> fizzBuzz(int n){
    vector<string> rtc;
    for(int i = 1; i <= n; ++i){
      if(i%15)
    	rtc.push_back(string("FizzBuzz"));
      else if(i%3 == 0)
    	rtc.push_back(string("Fizz"));
      else if(i%5 ==0)
	    rtc.push_back(string("Buzz"));
      else
    	rtc.push_back(std::to_string(i));
    }
    return rtc;
  }
};

class Solution;
int main(){
  Solution s;
  vector<string> t = s.fizzBuzz(15);
  vector<string>::iterator i;
  for(i = t.begin(); i!= t.end();++i){
    cout << *i;
  }
  return 0;
}

