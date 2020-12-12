/*
 * @lc app=leetcode.cn id=1 lang=c
 *
 * [1] 两数之和
 */

// @lc code=start

#include<stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    *returnSize = 0;
    if(nums == NULL || numsSize < 2)
        return NULL;
    
    for (int i = 0; i < numsSize; ++i)
    {
        for (int j = i + 1; j < numsSize; ++j)
        {
            if(nums[i] + nums[j] == target)
            {
                int * ret = (int *)malloc(2 * sizeof(int));
                if(ret == NULL)
                    return NULL;

                ret[0] = i;
                ret[1] = j;
                *returnSize = 2;

                return ret;              
            }
        }
    }
    return NULL;
}
// @lc code=end

