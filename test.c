#include<stdio.h>

struct s{
  char c;
  char d;
  char b;
} a;

int main(){
  a;
  a.c = '2';
  printf("%c", a.c);
  
  return 0;
}
