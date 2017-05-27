#include<stdio.h>

int hammingDistance(int x, int y) {
  int hd = 0;
  while(x!=0 && y!=0){
    if(x%2 != y%2)
      ++hd;
    x = x/2;
    y = y/2;
  }
  int z = x+y;
  while(z!=0){
    ++hd;
    z = z/2;
  }
  return hd;
}

int main(){
  int x,y;
  while(1){
    scanf("%d%d",&x,&y);
    int z = hammingDistance(x,y);
    printf("%d", z);
  }
}
