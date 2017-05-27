#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
//如果用简单的数组来实现栈的话会简单很多，不超过20行代码即可实现
typedef struct Node{
  char s;
  struct Node* next;
} Node;


void push(Node **obj, char c){
  Node* tmp = (Node*)malloc(sizeof(Node));
  tmp->s = c;
  if(*obj == NULL)
    tmp->next = NULL;
  else
    tmp->next = *obj;
  
  *obj = tmp;
}

void pop(Node **obj){
  if(*obj == NULL)
    return;
  Node *tmp = *obj;
  *obj = (*obj)->next;
  free(tmp);
}

void clearStack(Node** obj){
  Node** tmp;
  while(*obj != NULL){
    tmp = *obj;
    *obj = (*obj)->next;
    free(tmp);
  }
}


char top(Node *(*obj)){
  if((*obj) == NULL)
    return;
  return (*obj)->s;
}
bool isLeft(char c){
  return c == '(' || c == '{' || c == '[' ? true: false;
}

bool isValid(char* s){
  Node* Stack = NULL;
  
  int len = strlen(s);
  for(int i = 0; i < len; ++i){
    char c = s[i];
    if(isLeft(c)){
      push(&Stack, c);
      continue;
    }
    char tmp = top(&Stack);
    if(tmp == '(' && c == ')' || (tmp == '{' && c == '}') ||(tmp == '[' && c ==']'))
      pop(&Stack);
    else
      return false;
  }

  bool rtn = false;
  if(Stack == NULL)
    rtn = true;
  clearStack(&Stack);
  return rtn;
}

int main(){
  char* s = "{{)}";
  if(isValid(s))
    printf("%d", 1);
  else
    printf("%d", 0);
  return 0;
}
