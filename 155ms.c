#include<stdio.h>
#include<stdlib.h>


typedef struct {
  int *elements;
  int *minElements;
  int eTop; //index of the stack bottom is 0;
  int mTop;
  int maxSize;
} MinStack;

/** initialize your data structure here. */
MinStack* minStackCreate(int maxSize) {
  MinStack *minStack = (MinStack*) malloc(sizeof(MinStack));
  minStack->maxSize = maxSize;
  minStack->eTop = -1;
  minStack->mTop = -1;
  minStack->elements = (int*)malloc(sizeof(int) * maxSize);
  minStack->minElements = (int*)malloc(sizeof(int) * maxSize);
  memset(minStack->elements, 0, maxSize);
  memset(minStack->minElements, 0, maxSize);
  return minStack;
}

void minStackPush(MinStack* obj, int x) {
  if(obj->eTop >= obj->maxSize -1)
    return;

  if(obj->mTop == -1 || x <= obj->minElements[obj->mTop])
    obj->minElements[++obj->mTop] = x;
  
  obj->elements[++obj->eTop] = x;
}

void minStackPop(MinStack* obj) {
  if(obj->eTop == -1)
    return;
  if(obj->elements[obj->eTop] == obj->minElements[obj->mTop])
    --obj->mTop;

  --obj->eTop;
}

int minStackTop(MinStack* obj) {
  if(obj->eTop!=-1)
    return obj->elements[obj->eTop];
  else
    return -1;
}

int minStackGetMin(MinStack* obj) {
  if(obj->mTop == -1)
    return;
  return obj->minElements[obj->mTop];
    
}

void minStackFree(MinStack* obj) {
  free(obj->elements);
  free(obj->minElements);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * struct MinStack* obj = minStackCreate(maxSize);
 * minStackPush(obj, x);
 * minStackPop(obj);
 * int param_3 = minStackTop(obj);
 * int param_4 = minStackGetMin(obj);
 * minStackFree(obj);
 */
int main(){
  MinStack* obj = minStackCreate(8);
  minStackPush(obj, -3);
  minStackPush(obj, -1);
  minStackPush(obj, 3);

  int a = minStackGetMin(obj);

  int b = minStackTop(obj);
  minStackPop(obj);
  int c = minStackGetMin(obj);
  minStackFree(obj);

  printf("%d %d %d", a, b, c);
  return 0;
}
