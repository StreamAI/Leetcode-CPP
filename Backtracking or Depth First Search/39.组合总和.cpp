/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> track;

        backTrack(candidates, target, track, 0, res);

        return res;
    }

    void backTrack(vector<int>& candidates, int target, vector<int>& track, int begin, vector<vector<int>>& res){
        if(target <= 0){
            if(target == 0)
                res.push_back(track);
            return;
        }

        for(int i = begin; i < candidates.size(); ++i){
            track.push_back(candidates[i]);
            backTrack(candidates, target - candidates[i], track, i, res);
            track.pop_back();
        }
    }
};
// @lc code=end

