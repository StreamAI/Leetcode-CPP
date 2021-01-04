/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

// @lc code=start
#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sz = nums.size();
        if(sz < 2)
            return sz == 0 ? 0 : nums.at(0);
        
        vector<int> dp(sz);
        dp[0] = nums[0];

        for(int i = 1; i < sz; ++i)
            dp[i] = max(nums[i], dp[i-1] + nums[i]);
        
        int maxsum = dp[0];
        for(int i = 0; i < sz; ++i)
            maxsum = max(maxsum, dp[i]);
        
        return maxsum;
    }
};
// @lc code=end

