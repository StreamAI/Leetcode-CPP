/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount < 0 || (amount > 0 && coins.empty()))
            return -1;
        if(amount == 0)
            return 0;

        /* 
        // 回溯算法，穷举所有解后挑出最优解
        int minCoins = INT_MAX;
        dfs_coins(coins, amount, 0, minCoins);
        minCoins = minCoins < INT_MAX ? minCoins : -1;
        return minCoins;
        
        // 贪心算法，每次选择最快逼近目标值的分支
        return greedy_coins(coins, amount);
        
        // 动态规划递归解法，使用备忘录解决重叠子问题
        vector<int> memo(amount + 1, INT_MAX);
        return dp_coins(coins, amount, memo);
        */
        // 动态规划迭代解法，也即状态转移表法
        vector<int> dp_table(amount + 1, amount + 1);
        dp_table[0] = 0;

        // Iterative solution
        for(int s = 1; s <= amount; s++){
            for (int i = 0; i < coins.size(); i++)
                if(s - coins[i] >= 0)
                    dp_table[s] = min(dp_table[s], dp_table[s - coins[i]] + 1);            
        }

        return dp_table[amount] > amount ? -1 : dp_table[amount];
    }

/*
    // 回溯算法，穷举所有解后挑出最优解
    void dfs_coins(vector<int>& coins, int amount, int idxCoin, int& minCoins)
    {
    	// 使用static 变量用于记录当前选择的组合
        static vector<int> path;
        // 遍历每种可能的组合，若满足目标总和则更新更少元素组合并返回
        if(amount == 0){
        	// 判断是否为更少的元素组合，遍历完所有组合后minCoins 保存的就是满足组合总和的最少元素数量
            if(path.size() < minCoins)
                minCoins = path.size();
            return;
        }
    	// 每个结点状态逐个遍历可能的选择分支，由于每个元素数量不限，循环内递归调用参数idxCoin 不增加，以便选择相同的元素
        for(int i = idxCoin; i < coins.size(); ++i){
            if(amount - coins[i] >= 0){
                path.push_back(coins[i]);
                dfs_coins(coins, amount - coins[i], i, minCoins);
                path.pop_back();
            }      
        }
    }

    // 贪心算法，每次选择最快逼近目标值的分支
    int greedy_coins(vector<int>& coins, int amount)
    {
        if(amount < 0 || (coins.empty() && amount > 0))
            return -1;
        if(amount == 0)
            return 0;
        // 对各种面额按递减顺序排序，方便依次取最大面额、次大面额硬币
        sort(coins.begin(), coins.end(), greater<int>());
        int minCoin = 0;	// 最少硬币数量
        for (int i = 0; i < coins.size(); i++) {
            if(amount - coins[i] >= 0){
                minCoin += amount / coins[i];	// 取尽可能多数量当前能取的最大面额coins[i]
                amount = amount % coins[i];		// 选择amount / coins[i] 个数量的硬币后，更新剩余的目标总和
            }
        }
        // 若最后正好凑够目标总和，且选择了至少一枚硬币，则返回最少硬币数minCoin，否则返回-1
        if(amount != 0 || minCoin == 0)
            return -1;
        else
            return minCoin;
    }

    // 动态规划，最优子结构，未使用备忘录处理重叠子问题
    int dp_coins(vector<int>& coins, int amount){
        if(amount < 0)
            return -1;
        else if(amount == 0)
            return 0;
        else{
            int minCoins = INT_MAX;
            for (int i = 0; i < coins.size(); i++) {
                if(amount - coins[i] >= 0){
                    int prevMin = dp_coins(coins, amount - coins[i]);
                    if(prevMin >= 0)
                        minCoins = min(minCoins, prevMin + 1);
                }
            }
            return minCoins == INT_MAX ? -1 : minCoins;
        }
    }


    // 动态规划，状态转移方程，使用备忘录处理了重叠子问题
    int dp_coins(vector<int>& coins, int amount, vector<int>& memo){
        if(amount < 0)
            return -1;
        else if(amount == 0)
            return 0;
        
        if(memo[amount] != INT_MAX)
            return memo[amount];
        else{
            int minCoins = INT_MAX;
            for (int i = 0; i < coins.size(); i++) {
                if(amount - coins[i] >= 0){
                    int prevMin = dp_coins(coins, amount - coins[i], memo);
                    if(prevMin >= 0)
                        minCoins = min(minCoins, prevMin + 1);
                }
            }
            memo[amount] = minCoins < INT_MAX ? minCoins : -1;
            return memo[amount];
        }
    }
*/
};
// @lc code=end

