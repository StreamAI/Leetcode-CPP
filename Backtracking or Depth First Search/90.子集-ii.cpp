/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> track;
        vector<bool> used(nums.size() + 1, false);
        sort(nums.begin(), nums.end());
        backTrack(nums, track, 0, used, res);
        return res;
    }

    void backTrack(vector<int>& nums, vector<int>& track, int begin, vector<bool>& used, vector<vector<int>>& res){
        res.push_back(track);

        for(int i = begin; i < nums.size(); ++i){
            if(i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false)
                continue;
            track.push_back(nums[i]);
            used[i] = true;
            backTrack(nums, track, i + 1, used, res);
            track.pop_back();
            used[i] = false;
        }
    }
};
// @lc code=end

