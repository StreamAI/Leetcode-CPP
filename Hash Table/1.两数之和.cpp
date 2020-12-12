/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
#include<unordered_map>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> hashtable;
    for (int i = 0; i < nums.size(); i++)
    {
        auto index = hashtable.find(target - nums[i]);
        if (index != hashtable.end())
            return {i, index->second};
        
        hashtable[nums[i]] = i;
    }
    return {};
    }
};
// @lc code=end

