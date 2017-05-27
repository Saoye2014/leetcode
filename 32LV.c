#include<stdio.h>
#include<stdint.h>
#include<string.h>
int longestValidParentheses(char* s) {
  int Stack[1000000];
  int cur = 0;
  int top = -1;
  int len = strlen(s);
  int max = 0;
  int last = -1;
  for(int i = 0; i < len; ++i){
    if(s[i] == '(')
      Stack[++top] = i;
    else{
      if(top == -1){
	max = cur > max? cur: max;
	cur = 0;
	last = i;
      }
      else{
	--top;
	if(top == -1)
	  cur = i - last;
	else
	  cur = i - Stack[top];
      }
      max = cur > max? cur: max;
    }
  }
  return max > cur? max: cur;
}

int main(){
  char* s="(())()(()((";
  int c = longestValidParentheses(s);
  printf("%d", c);
  return 0;
}
