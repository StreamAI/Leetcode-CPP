/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
#include<vector>
#include<limits.h>
using namespace std;

class Solution {
private:
    vector<int> dp_res;
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount < 0)
            return -1;
        if(amount == 0)
            return 0;

        dp_res.resize(amount + 1, INT_MAX);
        dp_res[0] = 0;

        // Iterative solution
        for(int coin : coins){
            for (int i = coin; i < dp_res.size(); i++)
               if(dp_res[i - coin] < INT_MAX)
                    dp_res[i] = min(dp_res[i], dp_res[i - coin] + 1);            
        }

        return (dp_res[amount] != INT_MAX) ? dp_res[amount] : -1;

        //return dp_coin(coins, amount);    //Recursive method
    }

    /* 
    //Recursive method
    int dp_coin(vector<int>& coins, int amount){
        if(amount < 0)
            return -1;
        if(dp_res[amount] != INT_MAX)
            return dp_res[amount];

        int res = INT_MAX;
        for (int coin : coins){
            int subres = dp_coin(coins, amount - coin);
            if(subres >= 0 && subres < INT_MAX)
                res = min(res, subres + 1);
        }
        dp_res[amount] = (res != INT_MAX) ? res : -1;

        return dp_res[amount];
    }
    */
};
// @lc code=end

