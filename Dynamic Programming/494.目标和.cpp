/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

// @lc code=start
#include<vector>
using namespace std;
/**
 * sum(A) - sum(B) = target
 * 2 * sum(A) = target + sum(B) + sum(A)
 * sum(A) = (target + sum) / 2 
 */
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = 0, sz = nums.size();
        for(int i = 0; i < sz; ++i)
            sum += nums[i];
        if(sz < 1 || S > sum || S < -sum || (S + sum) % 2 != 0)
            return 0;

        int target = (S + sum) / 2;
        vector<vector<int>> dp(sz+1, vector<int>(target+1, 0));
        for(int i = 0; i <= sz; ++i)
            dp[i][0] = 1;

        for(int i = 1; i <= sz; ++i){
            for(int t = 0; t <= target; ++t){
                if(t - nums[i-1] >= 0)
                    dp[i][t] = dp[i-1][t] + dp[i-1][t-nums[i-1]];
                else
                    dp[i][t] = dp[i-1][t];
            }
        }
        return dp[sz][target];
    }
/*
    // The call format: backTrack(nums, 0, S, res, sum);
    void backTrack(vector<int>& nums, int index, int target, int& res, int sum){
        if(index == nums.size()){
            if(target == 0)
                res++;
            return;
        }

        if(target + nums[index] <= sum)
            backTrack(nums, index + 1, target + nums[index], res, sum);
        if(target - nums[index] >= -sum)
            backTrack(nums, index + 1, target - nums[index], res, sum);
    }
*/
};
// @lc code=end

