#include<iostream>
#include<queue>
using namespace std;
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
      tmp.push(x);
      while(!nums.empty()){
	tmp.push(nums.front());
	nums.pop();
      }
      queue<int> swp = nums;
      nums = tmp;
      tmp = swp;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
      int rtn = top();
      nums.pop();
      return rtn;
    }
    
    /** Get the top element. */
    int top() {
      return nums.front();  
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
      return nums.empty();
    }

private:
  queue<int> nums;
  queue<int> tmp;
};

/**
 * Your MyStack object will be instantiated and called as such:
c * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */
int main(){
  MyStack obj;
  obj.push(1);
  obj.push(2);
  int param_2 = obj.top();
  bool param_4 = obj.empty();
  cout << param_2<< param_4;
  return 0;
}
