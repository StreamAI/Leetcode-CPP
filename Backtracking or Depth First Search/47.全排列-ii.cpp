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
        int count = nums.size();
        if(count < 1)
            return {};

        vector<int> track;
        vector<bool> used(count, false);
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        backTrack(nums, count, track, 0, used, res);

        return res;
    }

    void backTrack(vector<int>& nums, const int& count, vector<int>& track, const int& index, vector<bool>& used, vector<vector<int>>& res){
        if(index == count){
            res.push_back(track);
            return;
        }

        for(int i = 0; i < count; ++i){
            if(used[i] == true || (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false))
                continue;

            track.push_back(nums[i]);
            used[i] = true;
            backTrack(nums, count, track, index + 1, used, res);
            used[i] = false;
            track.pop_back();
        }
    }
};
// @lc code=end

