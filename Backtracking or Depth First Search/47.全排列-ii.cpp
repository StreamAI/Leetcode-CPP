/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> track;
        vector<bool> used(nums.size(), false);

        sort(nums.begin(), nums.end());
        backTrack(nums, track, used, res);

        return res;
    }

    void backTrack(vector<int>& nums, vector<int>& track, vector<bool>& used, vector<vector<int>>& res){
        if(track.size() == nums.size()){
            res.push_back(track);
            return;
        }

        for(int i = 0; i < nums.size(); ++i){
            if(used[i] == true || (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false))
                continue;

            track.push_back(nums[i]);
            used[i] = true;
            backTrack(nums, track, used, res);
            track.pop_back();
            used[i] = false;
        }
    }
};
// @lc code=end

