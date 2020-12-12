/*
 * @lc app=leetcode.cn id=518 lang=cpp
 *
 * [518] 零钱兑换 II
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if(amount < 0 || (coins.size() < 1 && amount > 0))
            return 0;
        if(amount == 0)
            return 1;

        vector<int> dp_res(amount + 1, 0);
        dp_res[0] = 1;

        // Iterative solution
        for(int coin : coins){
            for(int i = coin; i < dp_res.size(); i++)
                dp_res[i] += dp_res[i - coin];
        }

        return dp_res[amount];
    }
};
// @lc code=end

