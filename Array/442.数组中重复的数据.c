/*
 * @lc app=leetcode.cn id=442 lang=c
 *
 * [442] 数组中重复的数据
 */

// @lc code=start
#include<stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDuplicates(int* nums, int numsSize, int* returnSize){
    *returnSize = 0;
    if(nums == NULL || numsSize < 1)
        return NULL;
    
    int* temp = (int*)malloc((numsSize+1)*sizeof(int));
    for(int i = 0; i <= numsSize; ++i)
        temp[i] = 0;
    
    for(int i = 0; i < numsSize; ++i)
        temp[nums[i]]++;
    
    for(int i = 0; i <= numsSize; ++i){
        if(temp[i] == 2)
            temp[(*returnSize)++] = i;
    }

    return temp;
}


// @lc code=end

