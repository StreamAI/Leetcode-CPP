/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长上升子序列
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int sz = nums.size();
        vector<int> dp(sz, 1);

        for(int i = 1; i < sz; ++i){
            for(int j = 0; j < i; ++j){
                if(nums[j] < nums[i])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        int maxlen = 0;
        for(int i = 0; i < sz; ++i)
            maxlen = max(maxlen, dp[i]);

        return maxlen;
    }
};
// @lc code=end

