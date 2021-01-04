/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sz = nums.size(), sum = 0, maxNum = 0;
        for(int i = 0; i < sz; ++i){
            sum += nums[i];
            maxNum = max(maxNum, nums[i]);
        }
        if(sz < 2 || sum % 2 != 0)
            return false;
        int target = sum / 2;
        if(maxNum > target)
            return false;

        vector<vector<bool>> dp(sz+1, vector<bool>(target+1, false));
        for(int i = 0; i <= sz; ++i)
            dp[i][0] = true;

        for(int i = 1; i <= sz; ++i){
            for(int t = 0; t <= target; ++t){
                if(t - nums[i - 1] >= 0)
                    dp[i][t] = dp[i-1][t] | dp[i-1][t-nums[i-1]];
                else
                    dp[i][t] = dp[i-1][t];
            }
        }

        return dp[sz][target];
    }
};
// @lc code=end

