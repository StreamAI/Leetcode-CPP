/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int count = nums.size();
        if(count < 1) 
            return {};
        
        vector<int> track;
        vector<bool> used(count, false);
        vector<vector<int>> res;
        backtrack(nums, count, track, 0, used, res);

        return res;
    }

    void backtrack(vector<int>& nums, const int& count, vector<int>& track, const int& index, vector<bool>& used, vector<vector<int>>& res){
        if(index == count){
            res.push_back(track);
            return;
        }

        for (int i = 0; i < count; ++i)
        {
            if(used[i] == true)
                continue;
            used[i] = true;
            track.push_back(nums[i]);
            backtrack(nums, count, track, index + 1, used, res);
            track.pop_back();
            used[i] = false;
        }  
    }
};
// @lc code=end

