#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void swap(char* s, int a, int b){
  int tmp = s[a];
  s[a] = s[b];
  s[b] = tmp;
}

char* quickSort(char*s, int start, int end){
  if(start >= end)
    return s;
  char pivot = s[start];
  int j = end;
  for(int i = start +1;  i <= j; ++i){
    if(s[i] <= pivot)
      continue;
    swap(s, i, j);
    --j;
    --i;
  }
  swap(s, start, j);
  
  quickSort(s, start, j - 1);
  quickSort(s, j + 1, end);
  return s;
}

char findTheDifference(char* s, char* t) {
  quickSort(s,0,strlen(s)-1);
  quickSort(t,0,strlen(t)-1);
  for(int i = 0; i < strlen(s); ++i)
    if(s[i] != t[i])
      return t[i];
  return t[strlen(t)-1];
}

int main(){
  char *s = malloc(sizeof(char)*255);
  char *t = malloc(sizeof(char)*255);
  while(1){
  scanf("%s", s);
  scanf("%s", t);
  printf("%s %d\n", s, (int)strlen(s));
  char a = findTheDifference(s,t);
  printf("%c\n", a);
  }
  return 0;
}
  
