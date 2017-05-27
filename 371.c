#include<stdio.h>
int getSum(int a, int b){
  int size = sizeof(int)*8;
  int rtn = 0;
  int c = 0;
  for(int i = 0; i < size; ++i){
    int res = (1<<i&a) ^ (1<<i&b);
    rtn = rtn^res^(1<<i&(c<<i));
    c = 1<<i&a && 1<<i&b || (res!=0 && c==1) ? 1: 0;
  }

  return rtn;
}
//递归的解法更简单

int main(){
  int a, b;

  while(1){
    scanf("%d%d", &a, &b);
    int res = getSum(a, b);
    printf("%d", res);
  }
}
