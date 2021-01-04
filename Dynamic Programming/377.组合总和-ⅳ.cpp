/*
 * @lc app=leetcode.cn id=377 lang=cpp
 *
 * [377] 组合总和 Ⅳ
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        if(nums.empty() || target < 1)
            return 0;

        // memo[target] 表示和为target 的组合的个数，memo[0] = 1 类似于fibonacci(0) = 1 为方便计算引入的
        vector<size_t> memo(target + 1, 0);
        memo[0] = 1;

        for(int i = 1; i <= target; ++i){
            for(int j = 0; j < nums.size(); j++){
                if(i - nums[j] >= 0)
                    memo[i] += memo[i - nums[j]];
            }
        }

        return memo[target];
    }
/*
    // The call format: dfs(nums, target, memo);
    int dfs(vector<int>& nums, int target, vector<size_t>& memo){
        if(target < 0)
            return 0;
        else if(target == 0)
            return 1;
        else if(memo[target] != 0)
            return memo[target];
        else{
            size_t res = 0;
            for(int i = 0; i < nums.size(); ++i){
                if(target - nums[i] >= 0)
                    res += dfs(nums, target - nums[i], memo);
            }
            memo[target] = res;

            return memo[target];
        }
    }
*/
};
// @lc code=end

