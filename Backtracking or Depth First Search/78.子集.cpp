/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> track;
        backTrack(nums, track, 0, res);
        return res;
    }

    void backTrack(vector<int>& nums, vector<int>& track, int begin, vector<vector<int>>& res){
        res.push_back(track);

        for(int i = begin; i < nums.size(); ++i){
            track.push_back(nums[i]);
            backTrack(nums, track, i + 1, res);
            track.pop_back();
        }
    }
};
// @lc code=end

