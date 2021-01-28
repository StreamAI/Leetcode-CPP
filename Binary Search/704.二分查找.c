/*
 * @lc app=leetcode.cn id=704 lang=c
 *
 * [704] 二分查找
 */

// @lc code=start


int search(int* nums, int numsSize, int target){
    if(nums == NULL || numsSize < 1 || target < nums[0] || target > nums[numsSize - 1])
        return -1;

    int left = 0, right = numsSize - 1;
    while (left <= right)
    {
        int mid = left + (right - left)/2;
        if(nums[mid] == target)
            return mid;
        else if(nums[mid] > target)
            right = mid - 1;
        else if(nums[mid] < target)
            left = mid + 1;
    }
    
    return -1;
}


// @lc code=end

