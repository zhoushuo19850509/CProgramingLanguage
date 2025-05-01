
#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize);

/**
  @1.两数之和
  这题是简单题，也做了半个多小时，也是醉了，暴露出很多问题：
  1.指针和数组的关系不太懂
  2.数组初始化不懂
  3.指针申请内存的函数malloc()不懂
  4.*returnSize这个参数的意思不懂
  最终还是在题解的提示下才做出来的
 */
int main(){
    int nums[4] = {2,7,11,15};
    int *result;
    int *returnSize = malloc(sizeof(int));

    result = twoSum(nums, 4, 9, returnSize);
    printf("[ %d, %d ] \n", result[0], result[1]);

}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int i, j;
    int result[2];
    int *p = malloc(sizeof(int) * 2);
    for(i = 0; i < numsSize -1; i++){
        for(j = i + 1; j< numsSize; j++){
            if((nums[i] + nums[j]) == target){
                p[0] = i;
                p[1] = j;
                *returnSize = 2;
                return p;
            }
        }
    }
    *returnSize = 0;
    return NULL;
}