//另一种做法：高位和低位两两交换
#include<stdio.h>
#define uint32_t int
uff

lint32_t reverseBits(uint32_t n) {
  uint32_t rtn = 0;
  for(int i = 0; i < 32; ++i){
    rtn ^=(1 & n) << 31 - i;
    n = n>> 1;
  }

  return rtn;
}

int main(){
  uint32_t a = 1;
  printf("%d",(int)reverseBits(a));
  return 0;
}
