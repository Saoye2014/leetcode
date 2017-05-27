#include<stdio.h>
#include<string.h>
#include<stdlib.h>
xint largestRectangleArea(int* heights, int heightsSize) {
  int max = 0;
  int Stack[1000000];
  memset(Stack, 0, sizeof(Stack));
  int top = -1;
  
  for(int i = 0; i < heightsSize; ++i){
    if(top == -1 || heights[i] >=  Stack[top]){
      Stack[++top] = i;
    }
    else{
      int tmp = heights[--top];
      int res = tmp * (top == -1 ? i : i - heights[top] - 1);
      if(max < res)
	max = res;
    }
  }
  return max;
}


int main(){
  int a[100] = {2,1,2};
  int size = 6;
  printf("%d", largestRectangleArea(a,size));
  return 0;
}
