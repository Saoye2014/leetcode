#include<stdio.h>
int findComplement(int num){
  int com = ~num;
  int tmp = 31;
  if(sizeof(int)!=4)
    return 1;
  for(tmp = 31;tmp >= 0 && (((1 << tmp)&com) != 0); --tmp){
    int a = -1;
    com = com^(1<<tmp);
  }
  return com;
}

int main(){
  int a;
  while(1){
    scanf("%d",&a);
    int com = findComplement(a);
    printf("%d",com);
  }
}
