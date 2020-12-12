/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {
private:
    vector<vector<int>> res = {};
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.size() < 1) 
            return {};
        
        vector<int> track = {};
        vector<bool> used(nums.size(), false);
        backtrack(nums, track, used);

        return res;
    }

    void backtrack(vector<int>& nums, vector<int>& track, vector<bool>& used){
        if(track.size() == nums.size()){
            res.push_back(track);
            return;
        }

        for (int i = 0; i < nums.size(); ++i)
        {
            if(used[i] == true)
                continue;
            used[i] = true;
            track.push_back(nums[i]);
            backtrack(nums, track, used);
            track.pop_back();
            used[i] = false;
        }  
    }
};
// @lc code=end

