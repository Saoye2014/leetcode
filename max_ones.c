#include<stdio.h>
int findMaxConsecutiveOnes(int* nums, int numsSize) {
  int max = 0, cur = 0;
  int i = 0;
  while(numsSize--){
    if(nums[numsSize]==1)
      ++cur;
    else{
      if(max < cur)
	max = cur;
      cur = 0;
    }
  }
  return max<cur?cur:max;
}

  
