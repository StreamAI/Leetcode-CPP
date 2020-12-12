/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = -1, end = -1;
        if(nums.empty())    
            return {start, end};

        int left = 0, right = nums.size() - 1, mid;
        while (left <= right)
        {
            mid = left + (right - left)/2;
            if(target <= nums[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }

        if(left < nums.size() && nums[left] == target)
        {
            start = left, end = left;
            right = nums.size() - 1;
            while (left <= right)
            {
                mid = left + (right - left)/2;
                if(target >= nums[mid])
                    left = mid + 1;
                else
                    right = mid - 1;
            }

            if(right >= start && nums[right] == target)
                end = right;
        }
            
        return {start, end};
    }
};
// @lc code=end

