/*
 * @lc app=leetcode.cn id=354 lang=cpp
 *
 * [354] 俄罗斯套娃信封问题
 */

// @lc code=start
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int sz = envelopes.size();
        if(sz < 2)
            return sz;

        sort(envelopes.begin(), envelopes.end(), [](vector<int>& a, vector<int>& b){
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
        });

        vector<int> height(sz);
        for(int i = 0; i < sz; ++i)
            height[i] = envelopes[i][1];

        return lengthOfLIS(height);
    }

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

