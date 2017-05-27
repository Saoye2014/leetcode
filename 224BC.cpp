#include<iostream>
/*反思：
栈的特点：先进先出，似乎有记忆力，但是记忆特性是在做减法，遇到特定的条件就开始从栈顶往前处理抛弃那些没用的选择。比如这一题，操作符的处理顺序和操作数的计算顺序就符合栈先进先出的特性，而每次遇到反括号就开始对栈作处理，只记住有用的元素放栈顶！之前计算maximum rectangler的时候也类似，不断的做减法，回退。
*/
#include<stack>

using namespace std;
class Solution {
public:
  bool isOps(char ch){
    return ch == '+' || ch == '-';
  }
  int calculate(string s) {
    s="("+s;
    stack<string> nums;
    stack<char> ops;
    nums.push(")");
    for(int i = s.length()-1; i >=0; --i){
      char ch = s.at(i);
      if(ch == ')')
	nums.push(")");
      else if(ch == ' ')
	continue;
      else if(isOps(ch))
	ops.push(ch);
      else if(ch == '('){
	int tmp = stoi(nums.top());
	nums.pop();
	while(nums.top() != ")"){
	  if(ops.top() == '+')
	    tmp += stoi(nums.top());
	  else
	    tmp -= stoi(nums.top());
	  
	  ops.pop();
	  nums.pop();
	}
	nums.pop();
	nums.push(to_string(tmp));
      }
      else{
	string tmp = "";
	tmp += ch;
        while(--i >= 0  && s.at(i) - '0' <= 9 && s.at(i) - '0' >= 0)
	  tmp=s.at(i)+tmp;
	++i;
	if(tmp!= "")
	  nums.push(tmp);
      }
    }
    return stoi(nums.top());
  }
};

int main(){
  string s="";
  while(getline(cin, s)){
    Solution sol;
    cout << sol.calculate(s);
  }
  return 0;
}
   















