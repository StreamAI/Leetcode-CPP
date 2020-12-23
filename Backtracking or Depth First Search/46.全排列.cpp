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
        vector<vector<int>> res;             
        vector<int> track;
        vector<bool> used(nums.size(), false);       

        backtrack(nums, track, used, res);

        return res;
    }

    void backtrack(vector<int>& nums, vector<int>& track, vector<bool>& used, vector<vector<int>>& res){
        if(track.size() == nums.size()){
            res.push_back(track);
            return;
        }

        for (int i = 0; i < nums.size(); ++i)
        {
            if(used[i] == true)
                continue;
            
            track.push_back(nums[i]);
            used[i] = true;
            backtrack(nums, track, used, res);
            track.pop_back();
            used[i] = false;
        }  
    }
};
// @lc code=end

